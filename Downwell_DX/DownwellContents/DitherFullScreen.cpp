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
	//DFSRenderer->CreateAnimation("FullScreenFadeIn", "Dither", 0, 9, 0.1f, false);
	//DFSRenderer->ChangeAnimation("FullScreenFadeIn");
	DFSRenderer->CreateAnimation("FullScreenFadeOut", "Dither", 10, 19, 1.0f, false);
	DFSRenderer->ChangeAnimation("FullScreenFadeOut");


	//DFSRenderer->SetTexture("DitherFullScreen.png", true, 2.0f);
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