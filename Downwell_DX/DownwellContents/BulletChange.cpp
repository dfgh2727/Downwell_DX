#include "PreCompile.h"
#include "BulletChange.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

BulletChange::BulletChange()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// �������� �����.
	BulletGauge = CreateDefaultSubObject<USpriteRenderer>();
	BulletGauge->SetupAttachment(RootComponent);
	BulletGauge->SetTexture("BulletStatusBar.png", true, 2.0f);
}

BulletChange::~BulletChange()
{
}

void BulletChange::BeginPlay()
{
	AActor::BeginPlay();
}

void BulletChange::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	FVector StautsBarScale = BulletGauge->GetWorldScale3D();
	//StautsBarScale.Y = 250.0f;
	//StautsBarScale.X = 100.0f;
	//BulletGauge->SetScale3D(StautsBarScale);

}
