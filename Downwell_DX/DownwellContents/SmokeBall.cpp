#include "PreCompile.h"
#include "SmokeBall.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineBase/EngineRandom.h>

SmokeBall::SmokeBall()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	SmokeBallRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SmokeBallRenderer->SetupAttachment(RootComponent);
	SmokeBallRenderer->CreateAnimation("SmokeBall", "SmokeBall", 0, 5, 0.1, false);
	SmokeBallRenderer->ChangeAnimation("SmokeBall");
}

SmokeBall::~SmokeBall()
{
}

void SmokeBall::BeginPlay()
{
	AActor::BeginPlay();

	Velocity.X = UEngineRandomInst.Randomfloat(-20.0f, 20.0f);
	Velocity.Y = UEngineRandomInst.Randomfloat(-20.0f, 20.0f);
}

void SmokeBall::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Timer -= _DeltaTime;

	AddActorLocation(Velocity * _DeltaTime);

	if (Timer < 0.0f)
	{
		Destroy();
	}
}