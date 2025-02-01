#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Snail : public SpawnedActor
{
public:
	// constrcuter destructer
	Snail();
	~Snail();

	// delete Function
	Snail(const Snail& _Other) = delete;
	Snail(Snail&& _Other) noexcept = delete;
	Snail& operator=(const Snail& _Other) = delete;
	Snail& operator=(Snail&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> SnailRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

