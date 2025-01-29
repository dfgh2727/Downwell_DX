#include "PreCompile.h"
#include "NormalBullet.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>

NormalBullet::NormalBullet()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	NormalBulletRenderer = CreateDefaultSubObject<USpriteRenderer>();
	NormalBulletRenderer->SetupAttachment(RootComponent);
	NormalBulletRenderer->CreateAnimation("Bullet", "Bullet", 0, 5, 0.08f, false);
	NormalBulletRenderer->ChangeAnimation("Bullet");
	NormalBulletRenderer->SetAutoScaleRatio(2.0f);

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

NormalBullet::~NormalBullet()
{
}

void NormalBullet::BeginPlay()
{
	AActor::BeginPlay();
}

void NormalBullet::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy();
	}
}