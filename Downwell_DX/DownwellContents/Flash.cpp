#include "PreCompile.h"
#include "Flash.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Flash::Flash()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	FlashRenderer = CreateDefaultSubObject<USpriteRenderer>();
	FlashRenderer->SetupAttachment(RootComponent);
	FlashRenderer->SetTexture("Flash.png", true, 1.0f);
}

Flash::~Flash()
{
}

void Flash::BeginPlay()
{
	AActor::BeginPlay();
}

void Flash::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy();
	}
}