#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class StepsS : public AActor
{
public:
	// constrcuter destructer
	StepsS();
	~StepsS();

	// delete Function
	StepsS(const StepsS& _Other) = delete;
	StepsS(StepsS&& _Other) noexcept = delete;
	StepsS& operator=(const StepsS& _Other) = delete;
	StepsS& operator=(StepsS&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> StepsSRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

