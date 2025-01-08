#include "PreCompile.h"
#include "DitherFullScreen.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

DitherFullScreen::DitherFullScreen()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// �������� �����.
	DFSRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DFSRenderer->SetupAttachment(RootComponent);
	DFSRenderer->CreateAnimation("FullScreenFadeIn", "Dither", 0, 4, 0.15f, false);
	DFSRenderer->CreateAnimation("FullScreenFadeOut", "Dither", 5, 9, 0.15f, false);
	
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

void DitherFullScreen::FadeIn()
{
	DFSRenderer->ChangeAnimation("FullScreenFadeIn");
}

void DitherFullScreen::FadeOut()
{
	DFSRenderer->ChangeAnimation("FullScreenFadeOut");
}