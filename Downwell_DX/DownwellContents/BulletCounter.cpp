#include "PreCompile.h"
#include "BulletCounter.h"
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/SpriteRenderer.h>
#include "DWInstance.h"
#include "Counter.h"
#include "Bat.h"


BulletCounter::BulletCounter()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	CountBullet = GetWorld()->SpawnActor<Counter>();
	CountBullet->SetTextSpriteName("BoldNum");
}

BulletCounter::~BulletCounter()
{
}

void BulletCounter::BeginPlay()
{
	AActor::BeginPlay();
}

void BulletCounter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Num = GetGameInstance<DWInstance>()->BulletCount;
	CountBullet->SetValue(Num);
	
	FVector CurPos = GetActorLocation();
	CountBullet->SetActorLocation(CurPos);
	int a = 0;
}