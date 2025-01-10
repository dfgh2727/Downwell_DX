#include "PreCompile.h"
#include "Tile002.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

Tile002::Tile002()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Tile002Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Tile002Renderer->SetupAttachment(RootComponent);
	Tile002Renderer->SetTexture("Tile002.png", true, 2.0f);
}

Tile002::~Tile002()
{
}

void Tile002::BeginPlay()
{
	AActor::BeginPlay();
}

void Tile002::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}