#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class StepsB : public SpawnedActor
{
public:
	// constrcuter destructer
	StepsB();
	~StepsB();

	// delete Function
	StepsB(const StepsB& _Other) = delete;
	StepsB(StepsB&& _Other) noexcept = delete;
	StepsB& operator=(const StepsB& _Other) = delete;
	StepsB& operator=(StepsB&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> StepsBRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

