#include "PreCompile.h"
#include "Health.h"

Health::Health()
{
}

Health::~Health()
{
}

void Health::BeginPlay()
{
	AActor::BeginPlay();
}

void Health::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}
