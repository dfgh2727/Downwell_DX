#pragma once
#include <EngineCore/Actor.h>

enum EMonsterType
{
	Bat1,
	Turtle,
};

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

	EMonsterType MonsterTypeValue;

protected:

private:

};

