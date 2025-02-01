#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"


class Monster : public AActor
{
public:
	// constrcuter destructer
	Monster();
	~Monster();

	// delete Function
	Monster(const Monster& _Other) = delete;
	Monster(Monster&& _Other) noexcept = delete;
	Monster& operator=(const Monster& _Other) = delete;
	Monster& operator=(Monster&& _Other) noexcept = delete;

	ESpawnType SpawnTypeValue;

protected:

private:


};

