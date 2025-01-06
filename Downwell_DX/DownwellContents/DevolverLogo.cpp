#include "PreCompile.h"
#include "DevolverLogo.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

DevolverLogo::DevolverLogo()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	LogoRenderer = CreateDefaultSubObject<USpriteRenderer>();
	LogoRenderer->SetupAttachment(RootComponent);
	LogoRenderer->SetTexture("DevolverLogo.png", true, 2.0f);
}

DevolverLogo::~DevolverLogo()
{
}

void DevolverLogo::BeginPlay()
{
	AActor::BeginPlay();
}

void DevolverLogo::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}