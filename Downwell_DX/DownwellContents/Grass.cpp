#include "PreCompile.h"
#include "Grass.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Grass::Grass()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	GrassRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GrassRenderer->SetupAttachment(RootComponent);
	GrassRenderer->CreateAnimation("Grass1", "Grass", 0, 3, 0.1f);
	GrassRenderer->CreateAnimation("Grass2", "Grass", 4, 7, 0.1f);
	GrassRenderer->SetAutoScaleRatio(2.0f);
}

Grass::~Grass()
{
}

void Grass::BeginPlay()
{
	AActor::BeginPlay();
}

void Grass::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Grass::SetGrass1()
{
	GrassRenderer->ChangeAnimation("Grass1");
}

void Grass::SetGrass2()
{
	GrassRenderer->ChangeAnimation("Grass2");
}