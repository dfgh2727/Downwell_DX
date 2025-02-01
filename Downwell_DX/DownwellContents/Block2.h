#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Block2 : public SpawnedActor
{
public:
	// constrcuter destructer
	Block2();
	~Block2();

	// delete Function
	Block2(const Block2& _Other) = delete;
	Block2(Block2&& _Other) noexcept = delete;
	Block2& operator=(const Block2& _Other) = delete;
	Block2& operator=(Block2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Block2Renderer;

	std::shared_ptr<class UCollision> CollisionBox;

};

