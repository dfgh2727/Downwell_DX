#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummySnail : public Dummy
{
public:
	// constrcuter destructer
	DummySnail();
	~DummySnail();

	// delete Function
	DummySnail(const DummySnail& _Other) = delete;
	DummySnail(DummySnail&& _Other) noexcept = delete;
	DummySnail& operator=(const DummySnail& _Other) = delete;
	DummySnail& operator=(DummySnail&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummySnailRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

