#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class GemBlock : public SpawnedActor
{
public:
	// constrcuter destructer
	GemBlock();
	~GemBlock();

	// delete Function
	GemBlock(const GemBlock& _Other) = delete;
	GemBlock(GemBlock&& _Other) noexcept = delete;
	GemBlock& operator=(const GemBlock& _Other) = delete;
	GemBlock& operator=(GemBlock&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> GemBlockRenderer;

	std::shared_ptr<class UCollision> CollisionBox;

};

