#include "PreCompile.h"
#include "StepsB.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

StepsB::StepsB()
{
	SpawnTypeValue = ESpawnType::SStepB;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	StepsBRenderer = CreateDefaultSubObject<USpriteRenderer>();
	StepsBRenderer->SetupAttachment(RootComponent);
	StepsBRenderer->SetTexture("Steps_Big.png", true, 2.0f);
}

StepsB::~StepsB()
{
}

void StepsB::BeginPlay()
{
	AActor::BeginPlay();
}

void StepsB::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}