#include "PreCompile.h"
#include "SmokeBall.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

SmokeBall::SmokeBall()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	SmokeBallRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SmokeBallRenderer->SetupAttachment(RootComponent);
	SmokeBallRenderer->CreateAnimation("SmokeBall", "SmokeBall", 0, 5, 0.1, false);
	SmokeBallRenderer->ChangeAnimation("SmokeBall");
}

SmokeBall::~SmokeBall()
{
}

void SmokeBall::BeginPlay()
{
	AActor::BeginPlay();
}

void SmokeBall::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Timer -= _DeltaTime;

	AddActorLocation((FVector::RIGHT + FVector::DOWN) * 50.0f * _DeltaTime);

	if (Timer < 0.0f)
	{
		Destroy();
	}
}