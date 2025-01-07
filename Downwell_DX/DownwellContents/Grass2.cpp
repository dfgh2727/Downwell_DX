#include "PreCompile.h"
#include "Grass2.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Grass2::Grass2()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Grass2Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Grass2Renderer->SetupAttachment(RootComponent);
	//Grass2Renderer->SetTexture("Grass2.png", true, 2.0f);
}

Grass2::~Grass2()
{
}

void Grass2::BeginPlay()
{
	AActor::BeginPlay();
}

void Grass2::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}