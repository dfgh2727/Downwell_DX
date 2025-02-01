#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Bat : public SpawnedActor
{
public:
	// constrcuter destructer
	Bat();
	~Bat();

	// delete Function
	Bat(const Bat& _Other) = delete;
	Bat(Bat&& _Other) noexcept = delete;
	Bat& operator=(const Bat& _Other) = delete;
	Bat& operator=(Bat&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> BatRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

