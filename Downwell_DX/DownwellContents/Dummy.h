#pragma once
#include <EngineCore/Actor.h>
#include "ContentsEnum.h"


class Dummy : public AActor
{
public:
	// constrcuter destructer
	Dummy();
	~Dummy();

	// delete Function
	Dummy(const Dummy& _Other) = delete;
	Dummy(Dummy&& _Other) noexcept = delete;
	Dummy& operator=(const Dummy& _Other) = delete;
	Dummy& operator=(Dummy&& _Other) noexcept = delete;

	EMonsterType MonsterTypeValue;
	void Serialize(UEngineSerializer& _Ser);
	void DeSerialize(UEngineSerializer& _Ser);

	std::shared_ptr<class USpriteRenderer> DummyRenderer;
protected:

private:


};

