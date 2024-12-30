#include "PreCompile.h"
#include "MainPlayer.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>

MainPlayer::MainPlayer()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	PlayerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	// PlayerRenderer->SetSprite("Player.png", 0);

	PlayerRenderer->CreateAnimation("Idle", "Player_Idle.png", 0, 3, 0.3f);
	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Idle");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 2.0f;
	}

	PlayerRenderer->CreateAnimation("Move", "Player_Move.png", 0, 7, 0.1f);

	{
		USpriteRenderer::FrameAnimation* Animation = PlayerRenderer->FindAnimation("Move");
		Animation->IsAutoScale = true;
		Animation->AutoScaleRatio = 2.0f;
	}

	PlayerRenderer->ChangeAnimation("Idle");

	PlayerRenderer->SetRelativeScale3D({ 50, 50, 1.0f });
	PlayerRenderer->SetupAttachment(RootComponent);
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
		AddActorRotation(FVector{ 0.0f, 0.0f , 360.0f * _DeltaTime });
	}

	if (UEngineInput::IsPress('E'))
	{
		PlayerRenderer->ChangeAnimation("Move");
	}

}