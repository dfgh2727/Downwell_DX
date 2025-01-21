#include "PreCompile.h"
#include "BasicBullet.h"

BasicBullet::BasicBullet()
{
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