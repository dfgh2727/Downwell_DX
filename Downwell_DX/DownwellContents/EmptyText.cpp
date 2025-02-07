#include "PreCompile.h"
#include "EmptyText.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

EmptyText::EmptyText()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	TextRenderer = CreateDefaultSubObject<USpriteRenderer>();
	TextRenderer->SetupAttachment(RootComponent);
	TextRenderer->SetTexture("Empty.png", true, 1.0f);
}

EmptyText::~EmptyText()
{
}

void EmptyText::BeginPlay()
{
	AActor::BeginPlay();
}

void EmptyText::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy();
	}
}