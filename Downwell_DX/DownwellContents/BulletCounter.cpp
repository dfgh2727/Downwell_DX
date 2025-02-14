#include "PreCompile.h"
#include "BulletCounter.h"
//#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/SpriteRenderer.h>
#include "DWInstance.h"
#include "Counter.h"
#include "Bat.h"


BulletCounter::BulletCounter()
{
	CountBullet = GetWorld()->SpawnActor<Counter>();
	CountBullet->SetTextSpriteName("BoldNum");
}

BulletCounter::~BulletCounter()
{
}

void BulletCounter::BeginPlay()
{
	AActor::BeginPlay();
	Num = GetGameInstance<DWInstance>()->BulletCount;
}

void BulletCounter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	CountBullet->SetValue(Num);

	int a = 0;
}