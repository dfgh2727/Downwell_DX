#include "PreCompile.h"
#include "NightSky.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

NightSky::NightSky()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	NightSkyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	NightSkyRenderer->SetupAttachment(RootComponent);
	NightSkyRenderer->SetTexture("NightSky.png", true, 2.0f);
}

NightSky::~NightSky()
{
}

void NightSky::BeginPlay()
{
	AActor::BeginPlay();
}

void NightSky::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}