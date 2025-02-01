#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"


class SpawnedActor : public AActor
{
public:
	// constrcuter destructer
	SpawnedActor();
	~SpawnedActor();

	// delete Function
	SpawnedActor(const SpawnedActor& _Other) = delete;
	SpawnedActor(SpawnedActor&& _Other) noexcept = delete;
	SpawnedActor& operator=(const SpawnedActor& _Other) = delete;
	SpawnedActor& operator=(SpawnedActor&& _Other) noexcept = delete;

	ESpawnType SpawnTypeValue;

protected:

private:


};

