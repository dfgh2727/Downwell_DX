#include "PreCompile.h"
#include "GunShotSmoke.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

GunShotSmoke::GunShotSmoke()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	GunShotSmokeRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GunShotSmokeRenderer->SetupAttachment(RootComponent);
	GunShotSmokeRenderer->SetTexture("GunShotSmoke.png", true, 2.0f);
}

GunShotSmoke::~GunShotSmoke()
{
}

void GunShotSmoke::BeginPlay()
{
	AActor::BeginPlay();
}

void GunShotSmoke::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy();
	}
}