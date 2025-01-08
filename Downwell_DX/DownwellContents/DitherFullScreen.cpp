#include "PreCompile.h"
#include "DitherFullScreen.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

DitherFullScreen::DitherFullScreen()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DFSRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DFSRenderer->SetupAttachment(RootComponent);
	DFSRenderer->CreateAnimation("FullScreenFadeIn", "Dither", 0, 6, 0.1f, false);
	DFSRenderer->CreateAnimation("FullScreenFadeOut", "Dither", 7, 13, 0.1f, false);

}

DitherFullScreen::~DitherFullScreen()
{
}

void DitherFullScreen::BeginPlay()
{
	AActor::BeginPlay();
}

void DitherFullScreen::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DitherFullScreen::FadeIn()
{
	DFSRenderer->ChangeAnimation("FullScreenFadeIn");
}

void DitherFullScreen::FadeOut()
{
	DFSRenderer->ChangeAnimation("FullScreenFadeOut");
}