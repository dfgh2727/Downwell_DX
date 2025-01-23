#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummySnake : public Dummy
{
public:
	// constrcuter destructer
	DummySnake();
	~DummySnake();

	// delete Function
	DummySnake(const DummySnake& _Other) = delete;
	DummySnake(DummySnake&& _Other) noexcept = delete;
	DummySnake& operator=(const DummySnake& _Other) = delete;
	DummySnake& operator=(DummySnake&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummySnakeRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

