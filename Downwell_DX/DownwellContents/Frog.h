#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Frog : public SpawnedActor
{
public:
	// constrcuter destructer
	Frog();
	~Frog();

	// delete Function
	Frog(const Frog& _Other) = delete;
	Frog(Frog&& _Other) noexcept = delete;
	Frog& operator=(const Frog& _Other) = delete;
	Frog& operator=(Frog&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> FrogRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

