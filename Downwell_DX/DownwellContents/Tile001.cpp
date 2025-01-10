#include "PreCompile.h"
#include "Tile001.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

Tile001::Tile001()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Tile001Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Tile001Renderer->SetupAttachment(RootComponent);
	Tile001Renderer->SetTexture("Tile001.png", true, 2.0f);
}

Tile001::~Tile001()
{
}

void Tile001::BeginPlay()
{
	AActor::BeginPlay();
}

void Tile001::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}