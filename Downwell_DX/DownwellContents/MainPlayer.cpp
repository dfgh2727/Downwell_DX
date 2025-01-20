#include "PreCompile.h"
#include "MainPlayer.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TileMapRenderer.h>

MainPlayer::MainPlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PlayerRenderer->SetupAttachment(RootComponent);

	PlayerRenderer->CreateAnimation("Idle", "Player_Idle.png", 0, 3, 0.2f);
	PlayerRenderer->CreateAnimation("Balancing", "Player_Balancing.png", 0, 23, 0.09f);
	PlayerRenderer->CreateAnimation("Run", "Player_Run.png", 0, 7, 0.08f);
	PlayerRenderer->ChangeAnimation("Idle");

	PlayerRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("MainPlayer");
	CollisionBox->SetScale3D({ 20.0f, 30.0f });
	CollisionBox->SetRelativeLocation({ 0.0f, 15.0f });

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
}

void MainPlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	//AddActorLocation(GoDown * _DeltaTime);

	if (UEngineInput::IsPress('A'))
	{
		AddRelativeLocation(FVector{ -100.0f * _DeltaTime, 0.0f, 0.0f });
	}
	if (UEngineInput::IsPress('D'))
	{
		AddRelativeLocation(FVector{ 100.0f * _DeltaTime, 0.0f, 0.0f });
	}

	if (UEngineInput::IsPress('W'))
	{
		AddRelativeLocation(FVector{ 0.0f, 100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('S'))
	{
		AddRelativeLocation(FVector{ 0.0f, -100.0f * _DeltaTime, 0.0f });
	}

	if (UEngineInput::IsPress('Q'))
	{
		PlayerRenderer->ChangeAnimation("Run");
	}

	if (UEngineInput::IsPress('E'))
	{
		PlayerRenderer->ChangeAnimation("Balancing");
	}

	if (nullptr != TRenderer)
	{
		TData = TRenderer->GetTile(GetActorLocation());

		if (nullptr != TData)
		{
			SetActorLocation(PrevLocation);
		}
		else
		{
			PrevLocation = GetActorLocation();
		}
		int a = 0;
	}

}

