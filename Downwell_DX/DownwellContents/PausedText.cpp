#include "PreCompile.h"
#include "PausedText.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

PausedText::PausedText()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	PausedTextRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PausedTextRenderer->SetupAttachment(RootComponent);
	PausedTextRenderer->SetTexture("PST_PAUSED.png", true, 1.0f);
}

PausedText::~PausedText()
{
}

void PausedText::BeginPlay()
{
	AActor::BeginPlay();
}

void PausedText::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}