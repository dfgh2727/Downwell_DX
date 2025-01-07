#include "PreCompile.h"
#include "BulletStatus.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

BulletStatus::BulletStatus()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	BulletStatusRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BulletStatusRenderer->SetupAttachment(RootComponent);
	BulletStatusRenderer->SetTexture("BulletStatus.png", true, 2.0f);
}

BulletStatus::~BulletStatus()
{
}

void BulletStatus::BeginPlay()
{
	AActor::BeginPlay();
}

void BulletStatus::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}