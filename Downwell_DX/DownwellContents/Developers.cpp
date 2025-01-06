#include "PreCompile.h"
#include "Developers.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Developers::Developers()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	DevelopersRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DevelopersRenderer->SetupAttachment(RootComponent);
	DevelopersRenderer->SetTexture("Developers.png", true, 2.0f);
}

Developers::~Developers()
{
}

void Developers::BeginPlay()
{
	AActor::BeginPlay();
}

void Developers::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}