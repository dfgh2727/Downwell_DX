#include "PreCompile.h"
#include "HealthStatus.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

HealthStatus::HealthStatus()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	HealthStatusRenderer = CreateDefaultSubObject<USpriteRenderer>();
	HealthStatusRenderer->SetupAttachment(RootComponent);
	HealthStatusRenderer->SetTexture("HealthStatus.png", true, 2.0f);
}

HealthStatus::~HealthStatus()
{
}

void HealthStatus::BeginPlay()
{
	AActor::BeginPlay();
}

void HealthStatus::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}