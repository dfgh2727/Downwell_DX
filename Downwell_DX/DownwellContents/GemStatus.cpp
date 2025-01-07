#include "PreCompile.h"
#include "GemStatus.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

GemStatus::GemStatus()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	GemStatusRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GemStatusRenderer->SetupAttachment(RootComponent);
	GemStatusRenderer->SetTexture("GemStatus.png", true, 2.0f);
}

GemStatus::~GemStatus()
{
}

void GemStatus::BeginPlay()
{
	AActor::BeginPlay();
}

void GemStatus::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}