#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummyBat : public Dummy
{
public:
	// constrcuter destructer
	DummyBat();
	~DummyBat();

	// delete Function
	DummyBat(const DummyBat& _Other) = delete;
	DummyBat(DummyBat&& _Other) noexcept = delete;
	DummyBat& operator=(const DummyBat& _Other) = delete;
	DummyBat& operator=(DummyBat&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummyBatRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

