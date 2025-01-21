#include "PreCompile.h"
#include "MainPlayer.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TileMapRenderer.h>
#include <EngineCore/TimeEventComponent.h>

MainPlayer::MainPlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PlayerRenderer->SetupAttachment(RootComponent);

	PlayerRenderer->CreateAnimation("Idle", "Player_Idle.png", 0, 3, 0.2f);
	//PlayerRenderer->CreateAnimation("Balancing", "Player_Balancing.png", 0, 23, 0.09f);
	PlayerRenderer->CreateAnimation("Run", "Player_Run.png", 0, 7, 0.08f);
	PlayerRenderer->CreateAnimation("Jump", "Player_Jump.png", 0, 4, 0.5f);
	PlayerRenderer->CreateAnimation("Shoot", "Player_Shoot.png", 0, 3, 0.15f);

	PlayerRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("MainPlayer");

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	/*{
		FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
		if (ScreenPos.X < 0.0f)
		{
			ScreenPos.X = ScreenPos.X + -50.0f;
		}
		if (ScreenPos.Y < 0.0f)
		{
			ScreenPos.Y = ScreenPos.Y + -50.0f;
		}

		FVector CScreenPos = ScreenPos / 100.0f;

		if (ScreenPos.X < 0.0f)
		{
			CScreenPos.X = roundf(CScreenPos.X);
		}
		if (ScreenPos.Y < 0.0f)
		{
			CScreenPos.Y = roundf(CScreenPos.Y);
		}


		ImGui::Text("ScreenPos %s", ScreenPos.ToString().c_str());

		ImGui::Text("TilePos %s ", CScreenPos.ToString().c_str());

		ImGui::Text("Index %s %s", std::to_string(CScreenPos.iX()).c_str(), std::to_string(CScreenPos.iY()).c_str());

	}*/
}

MainPlayer::~MainPlayer()
{
}

void MainPlayer::BeginPlay()
{
	AActor::BeginPlay();

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
		});
	FSM.CreateState(MainPlayerState::Shoot, std::bind(&MainPlayer::Shoot, this, std::placeholders::_1),
		[this]()
		{
			PlayerRenderer->ChangeAnimation("Shoot");
		});

		FSM.ChangeState(MainPlayerState::Idle);
}

void MainPlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	GravityManager(_DeltaTime);

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

	if (false == IsOnTheGround)
	{
		Gravity += GForce * _DeltaTime;
		AddActorLocation(Gravity * _DeltaTime);
		PrevLocation = GetActorLocation();
	}
	else
	{
		Gravity = FVector::ZERO;
		SetActorLocation(PrevLocation);
	}
}

void MainPlayer::Idle(float _DeltaTime)
{
	if (UEngineInput::IsPress('A')|| UEngineInput::IsPress('D'))
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
	if (UEngineInput::IsPress('A'))
	{
		FVector GoLeft = FVector::LEFT * 100.0f * _DeltaTime;
		if (false == TileCheck(GoLeft))
		{
			AddActorLocation(GoLeft);
		}
	}
	else if (UEngineInput::IsPress('D'))
	{
		FVector GoRight = FVector::RIGHT * 100.0f * _DeltaTime;
		if (false == TileCheck(GoRight))
		{
			AddActorLocation(GoRight);
		}
	}
	else if (UEngineInput::IsPress(VK_SPACE))
	{
		FSM.ChangeState(MainPlayerState::Jump);
	}
	else
	{
		FSM.ChangeState(MainPlayerState::Idle);
	}
}

void MainPlayer::Jump(float _DeltaTime)
{
	AddActorLocation(FVector::UP * 200.0f * _DeltaTime);

	if (UEngineInput::IsDown(VK_SPACE))
	{
		FSM.ChangeState(MainPlayerState::Shoot);
	}

	if (UEngineInput::IsPress('A'))
	{
		AddActorLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('D'))
	{
		AddActorLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (true == IsOnTheGround)
	{
		FSM.ChangeState(MainPlayerState::Idle);
	}
}

void MainPlayer::Shoot(float _DeltaTime)
{
	TimeEventComponent->AddEndEvent(0.5f,
		[this]()
		{
			FSM.ChangeState(MainPlayerState::Idle);
		},
		false);
}
