#include "PreCompile.h"
#include "HowToPlay.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

HowToPlay::HowToPlay()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	ControlRenderer = CreateDefaultSubObject<USpriteRenderer>();
	ControlRenderer->SetupAttachment(RootComponent);
	ControlRenderer->SetTexture("Controls.png", true, 2.0f);
	/*ControlRenderer->SetSprite("Controls.png");
	ControlRenderer->SetRelativeScale3D({ 50, 50, 1.0f });*/
}

HowToPlay::~HowToPlay()
{
}

void HowToPlay::BeginPlay()
{
	AActor::BeginPlay();
}

void HowToPlay::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}