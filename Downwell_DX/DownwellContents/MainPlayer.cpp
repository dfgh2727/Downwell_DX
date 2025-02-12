#include "PreCompile.h"
#include "MainPlayer.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TileMapRenderer.h>
#include <EngineCore/TimeEventComponent.h>
//#include <EngineCore/EngineCore.h>

#include "DWInstance.h"
#include "Cartridge.h"
#include "NormalBullet.h"
#include "GunShotSmoke.h"
#include "EmptyText.h"
#include "BulletCounter.h"

MainPlayer::MainPlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PlayerRenderer->SetupAttachment(RootComponent);

	PlayerRenderer->CreateAnimation("Idle", "Player_Idle.png", 0, 3, 0.2f);
	PlayerRenderer->CreateAnimation("Fall", "Player_Fall.png", 0, 2, 0.1f, false);
	PlayerRenderer->CreateAnimation("Run", "Player_Run.png", 0, 7, 0.08f);
	PlayerRenderer->CreateAnimation("Jump", "Player_Jump.png", 0, 4, 0.5f, false);
	PlayerRenderer->CreateAnimation("Shoot", "Player_Shoot.png", 0, 3, 0.1f, false);

	PlayerRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("MainPlayer");

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

MainPlayer::~MainPlayer()
{
}

void MainPlayer::BeginPlay()
{
	AActor::BeginPlay();

	Pistol = GetGameInstance<DWInstance>()->BulletCount;

	FSM.CreateState(MainPlayerState::Idle, std::bind(&MainPlayer::Idle, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Idle");
			CollisionBox->SetScale3D({ 20.0f, 30.0f });
			CollisionBox->SetRelativeLocation({ 0.0f, 15.0f });
		});

	FSM.CreateState(MainPlayerState::Run, std::bind(&MainPlayer::Run, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Run");
			CollisionBox->SetScale3D({ 25.0f, 20.0f });
			CollisionBox->SetRelativeLocation({ 15.0f, 15.0f });
		});

	FSM.CreateState(MainPlayerState::Jump, std::bind(&MainPlayer::Jump, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Jump");
			CollisionBox->SetScale3D({ 25.0f, 20.0f });
			CollisionBox->SetRelativeLocation({ 15.0f, 15.0f });
		});
	FSM.CreateState(MainPlayerState::Shoot, std::bind(&MainPlayer::Shoot, this, std::placeholders::_1),
		[this]()
		{
			IsShooting = true;

			PlayerRenderer->ChangeAnimation("Shoot");
			FVector PlayerPos = GetActorLocation();
			FVector Direction = FVector::ZERO;
			Direction.X = MoveDir;

			NBullet = GetWorld()->SpawnActor<NormalBullet>();
			NBullet->SetActorLocation(PlayerPos + Direction * 15.0f);
			NBullet->SetTileMapRenderer(TRenderer);

			TempCart = GetWorld()->SpawnActor<Cartridge>();
			TempCart->SetActorLocation(PlayerPos + Direction * 15.0f);

			Smoke = GetWorld()->SpawnActor<GunShotSmoke>();
			Smoke->SetActorLocation(PlayerPos + Direction * 15.0f + FVector::DOWN * 35.0f);
		});

	FSM.ChangeState(MainPlayerState::Idle);
}

void MainPlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	GravityManager(_DeltaTime);
	BulletManager();
	//CollisionLR(_DeltaTime);

	FSM.Update(_DeltaTime);


}

bool MainPlayer::TileCheck(FVector _AddPos)
{
	if (nullptr != TRenderer)
	{
		TData = TRenderer->GetTile(GetActorLocation() + _AddPos);

		if (nullptr != TData)
		{
			IsTile = true;
		}
		else
		{
			IsTile = false;
		}
		return IsTile;
	}
}

void MainPlayer::GravityManager(float _DeltaTime)
{
	IsOnTheGround = TileCheck(Gravity * _DeltaTime);
	bool IsOnTheBlock = false;

	std::vector<UCollision*> BlockCollision;
	if (true == CollisionBox->CollisionCheck("Block", Gravity * _DeltaTime, BlockCollision))
	{
		IsOnTheBlock = true;
	}

	if (true == IsOnTheBlock)
	{
		IsOnTheGround = true;
	}

	if (true == IsOnTheGround)
	{
		Gravity = FVector::ZERO;
	}
	else
	{
		AddActorLocation(Gravity * _DeltaTime);
		PrevLocation = GetActorLocation();
		Gravity += GForce * _DeltaTime;
	}
}

void MainPlayer::BulletManager()
{
	if (true == IsOnTheGround)
	{
		Pistol = 8;
		SynchBullet();
	}
}

void MainPlayer::Idle(float _DeltaTime)
{
	SetActorLocation(PrevLocation);

	if (UEngineInput::IsPress('A') || UEngineInput::IsPress('D'))
	{
		FSM.ChangeState(MainPlayerState::Run);
	}

	if (UEngineInput::IsPress(VK_SPACE))
	{
		FSM.ChangeState(MainPlayerState::Jump);
	}
}

void MainPlayer::Run(float _DeltaTime)
{
	MoveVect.X = LRVelocity * MoveDir;

	if (UEngineInput::IsPress('A'))
	{
		if (MoveDir > 0.0f)
		{
			AddActorRotation({ 0.0f, 180.0f, 0.0f });
		}

		MoveDir = -1.0f;

		FVector GoLeft = MoveVect * _DeltaTime;
		if (false == TileCheck(GoLeft))
		{
			AddActorLocation(GoLeft);
		}
	}
	else if (UEngineInput::IsPress('D'))
	{
		if (MoveDir < 0.0f)
		{
			AddActorRotation({ 0.0f, 180.0f, 0.0f });
		}
		MoveDir = 1.0f;

		FVector GoRight = MoveVect * _DeltaTime;
		if (false == TileCheck(GoRight))
		{
			AddActorLocation(GoRight);
		}
	}
	else
	{
		FSM.ChangeState(MainPlayerState::Idle);
	}

	if (UEngineInput::IsPress(VK_SPACE))
	{
		FSM.ChangeState(MainPlayerState::Jump);
	}

}

void MainPlayer::Jump(float _DeltaTime)
{
	AddActorLocation(FVector::UP * 250.0f * _DeltaTime);

	if (UEngineInput::IsDown(VK_SPACE))
	{
		if (Pistol > 0)
		{
			FSM.ChangeState(MainPlayerState::Shoot);
			Pistol--;
			SynchBullet();
		}
		else
		{
			FVector TXT1Pos = GetActorLocation();
			TXT1Pos += FVector::UP * 50.0f + FVector::RIGHT * MoveDir* 15.0f;

			TXT1 = GetWorld()->SpawnActor<EmptyText>();
			TXT1->SetActorLocation(TXT1Pos);
		}
	}
	

	MoveVect.X = LRVelocity * MoveDir;

	if (UEngineInput::IsPress('A'))
	{
		if (MoveDir > 0.0f)
		{
			AddActorRotation({ 0.0f, 180.0f, 0.0f });
		}

		MoveDir = -1.0f;
		AddActorLocation(MoveVect * _DeltaTime);
	}

	if (UEngineInput::IsPress('D'))
	{
		if (MoveDir < 0.0f)
		{
			AddActorRotation({ 0.0f, 180.0f, 0.0f });
		}

		MoveDir = 1.0f;
		AddActorLocation(MoveVect * _DeltaTime);
	}

	if (true == IsOnTheGround)
	{
		FSM.ChangeState(MainPlayerState::Idle);
	}
}

void MainPlayer::Shoot(float _DeltaTime)
{
	// 방향전환 추가 필요

	if (UEngineInput::IsPress(VK_SPACE))
	{
		if (Pistol > 0)
		{
			Timer -= _DeltaTime;

			if (Timer < 0.0f)
			{
				FSM.ChangeState(MainPlayerState::Shoot);
				Pistol--;
				SynchBullet();
				Timer = 0.2f;
			}
		}
		else
		{
			FVector TXT1Pos = GetActorLocation();
			TXT1Pos += FVector::UP * 50.0f + FVector::RIGHT * MoveDir * 15.0f;

			TXT1 = GetWorld()->SpawnActor<EmptyText>();
			TXT1->SetActorLocation(TXT1Pos);
		}
	}

	/*TimeEventComponent->AddEndEvent(0.5f,
		[this]()
		{
			FSM.ChangeState(MainPlayerState::Idle);
		},
		false);*/

	if (true == IsOnTheGround)
	{
		FSM.ChangeState(MainPlayerState::Idle);
		IsShooting = false;
	}
}

void MainPlayer::CollisionLR(float _DeltaTime)
{
	FVector CurLocation = CollisionBox->GetWorldLocation();
	FVector GoLeftVect = FVector::LEFT * 100.0f * _DeltaTime;
	//GoLeftVect.Y -= 15.0f;
	FVector GoRightVect = FVector::RIGHT * 100.0f * _DeltaTime;
	//GoRightVect.Y -= 15.0f;

	std::vector<UCollision*> BlockCollisionLR;
	if (true == CollisionBox->CollisionCheck("Block", GoLeftVect, BlockCollisionLR))
	{
		SetActorLocation(CurLocation);
	}
	if (true == CollisionBox->CollisionCheck("Block", GoRightVect, BlockCollisionLR))
	{
		SetActorLocation(CurLocation);
	}
}

void MainPlayer::SynchBullet()
{
	GetGameInstance<DWInstance>()->BulletCount = Pistol;
}