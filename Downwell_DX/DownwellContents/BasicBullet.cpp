#include "PreCompile.h"
#include "BasicBullet.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>

BasicBullet::BasicBullet()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	BasicBulletRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BasicBulletRenderer->SetupAttachment(RootComponent);
	BasicBulletRenderer->CreateAnimation("FullScreenFadeOut", "Bullet", 0, 5, 0.1f);
	BasicBulletRenderer->ChangeAnimation("FullScreenFadeOut");
	BasicBulletRenderer->SetAutoScaleRatio(2.0f);

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

BasicBullet::~BasicBullet()
{
}

void BasicBullet::BeginPlay()
{
	AActor::BeginPlay();
}

void BasicBullet::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}