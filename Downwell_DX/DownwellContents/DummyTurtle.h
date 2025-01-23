#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummyTurtle : public Dummy
{
public:
	// constrcuter destructer
	DummyTurtle();
	~DummyTurtle();

	// delete Function
	DummyTurtle(const DummyTurtle& _Other) = delete;
	DummyTurtle(DummyTurtle&& _Other) noexcept = delete;
	DummyTurtle& operator=(const DummyTurtle& _Other) = delete;
	DummyTurtle& operator=(DummyTurtle&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummyTurtleRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

