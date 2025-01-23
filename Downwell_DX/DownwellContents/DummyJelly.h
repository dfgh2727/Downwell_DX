#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummyJelly : public Dummy
{
public:
	// constrcuter destructer
	DummyJelly();
	~DummyJelly();

	// delete Function
	DummyJelly(const DummyJelly& _Other) = delete;
	DummyJelly(DummyJelly&& _Other) noexcept = delete;
	DummyJelly& operator=(const DummyJelly& _Other) = delete;
	DummyJelly& operator=(DummyJelly&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummyJellyRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

