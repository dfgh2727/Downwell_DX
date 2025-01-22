#pragma once
#include "Monster.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Bat : public Monster
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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

private:
	std::shared_ptr<class USpriteRenderer> BatRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

