#include "PreCompile.h"
#include "StepsS.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

StepsS::StepsS()
{
	SpawnTypeValue = ESpawnType::SStepS;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	StepsSRenderer = CreateDefaultSubObject<USpriteRenderer>();
	StepsSRenderer->SetupAttachment(RootComponent);
	StepsSRenderer->SetTexture("Steps_Small.png", true, 2.0f);
}

StepsS::~StepsS()
{
}

void StepsS::BeginPlay()
{
	AActor::BeginPlay();
}

void StepsS::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}