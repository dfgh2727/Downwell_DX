#include "PreCompile.h"
#include "Grass1.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Grass1::Grass1()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Grass1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Grass1Renderer->SetupAttachment(RootComponent);
	//Grass1Renderer->SetTexture("Grass1.png", true, 2.0f);
}

Grass1::~Grass1()
{
}

void Grass1::BeginPlay()
{
	AActor::BeginPlay();
}

void Grass1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}