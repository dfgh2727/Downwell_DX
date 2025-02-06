#include "PreCompile.h"
#include "BulletCounter.h"

#include "Counter.h"
#include "MainPlayer.h"

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

}

void BulletCounter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	CountBullet->SetValue(Num);
}