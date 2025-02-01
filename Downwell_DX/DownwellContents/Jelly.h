#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Jelly : public SpawnedActor
{
public:
	// constrcuter destructer
	Jelly();
	~Jelly();

	// delete Function
	Jelly(const Jelly& _Other) = delete;
	Jelly(Jelly&& _Other) noexcept = delete;
	Jelly& operator=(const Jelly& _Other) = delete;
	Jelly& operator=(Jelly&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> JellyRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

