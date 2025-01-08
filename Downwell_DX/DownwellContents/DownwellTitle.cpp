#include "PreCompile.h"
#include "DownwellTitle.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

DownwellTitle::DownwellTitle()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DownwellTitleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DownwellTitleRenderer->SetupAttachment(RootComponent);
	DownwellTitleRenderer->CreateAnimation("TitleShowUp", "DownwellTitle", 0, 8, 0.1f, false);
	DownwellTitleRenderer->ChangeAnimation("TitleShowUp");

	DownwellTitleRenderer->SetAutoScaleRatio(2.0f);

}

DownwellTitle::~DownwellTitle()
{
}

void DownwellTitle::BeginPlay()
{
	AActor::BeginPlay();
}

void DownwellTitle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}