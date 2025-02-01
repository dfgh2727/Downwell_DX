#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Block3 : public SpawnedActor
{
public:
	// constrcuter destructer
	Block3();
	~Block3();

	// delete Function
	Block3(const Block3& _Other) = delete;
	Block3(Block3&& _Other) noexcept = delete;
	Block3& operator=(const Block3& _Other) = delete;
	Block3& operator=(Block3&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Block3Renderer;

	std::shared_ptr<class UCollision> CollisionBox;

};

