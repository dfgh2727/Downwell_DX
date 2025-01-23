#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummyFrog : public Dummy
{
public:
	// constrcuter destructer
	DummyFrog();
	~DummyFrog();

	// delete Function
	DummyFrog(const DummyFrog& _Other) = delete;
	DummyFrog(DummyFrog&& _Other) noexcept = delete;
	DummyFrog& operator=(const DummyFrog& _Other) = delete;
	DummyFrog& operator=(DummyFrog&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummyFrogRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

