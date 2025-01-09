#include "PreCompile.h"
#include "Land.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Land::Land()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	LandRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LandRenderer->SetupAttachment(RootComponent);
	LandRenderer->SetTexture("Land.png", true, 1.0f);
}

Land::~Land()
{
}

void Land::BeginPlay()
{
	AActor::BeginPlay();
}

void Land::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}