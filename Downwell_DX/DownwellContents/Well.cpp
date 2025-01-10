#include "PreCompile.h"
#include "Well.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

Well::Well()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	WellRenderer = CreateDefaultSubObject<USpriteRenderer>();
	WellRenderer->SetupAttachment(RootComponent);
	WellRenderer->SetTexture("Well.png", true, 2.0f);
}

Well::~Well()
{
}

void Well::BeginPlay()
{
	AActor::BeginPlay();
}

void Well::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}