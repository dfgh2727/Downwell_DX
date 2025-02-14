#include "PreCompile.h"
#include "Gem.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>

Gem::Gem()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	GemRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GemRenderer->SetupAttachment(RootComponent);
	GemRenderer->CreateAnimation("Gem", "Gem", 0, 7, 0.1f);
	GemRenderer->ChangeAnimation("Gem");
	GemRenderer->SetAutoScaleRatio(2.0f);

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

Gem::~Gem()
{
}

void Gem::BeginPlay()
{
	AActor::BeginPlay();
}

void Gem::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	AddActorLocation(FVector{ 20.0f, 10.0f, 0.0f } * _DeltaTime);

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy(0);
	}
}