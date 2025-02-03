#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Block0 : public SpawnedActor
{
public:
	// constrcuter destructer
	Block0();
	~Block0();

	// delete Function
	Block0(const Block0& _Other) = delete;
	Block0(Block0&& _Other) noexcept = delete;
	Block0& operator=(const Block0& _Other) = delete;
	Block0& operator=(Block0&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void Break();

private:
	std::shared_ptr<class USpriteRenderer> Block0Renderer;
	std::shared_ptr<class Flash> FlashForBlock;
	std::shared_ptr<class Debris> Debris1;
	std::shared_ptr<class Debris> Debris2;
	std::shared_ptr<class SmokeBall> SmokeBall1;
	std::shared_ptr<class SmokeBall> SmokeBall2;

	std::shared_ptr<class UCollision> CollisionBox;

	FVector CurLocation = FVector::ZERO;

};

