#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Snake : public SpawnedActor
{
public:
	// constrcuter destructer
	Snake();
	~Snake();

	// delete Function
	Snake(const Snake& _Other) = delete;
	Snake(Snake&& _Other) noexcept = delete;
	Snake& operator=(const Snake& _Other) = delete;
	Snake& operator=(Snake&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> SnakeRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

