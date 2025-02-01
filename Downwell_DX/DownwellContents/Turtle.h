#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Turtle : public SpawnedActor
{
public:
	// constrcuter destructer
	Turtle();
	~Turtle();

	// delete Function
	Turtle(const Turtle& _Other) = delete;
	Turtle(Turtle&& _Other) noexcept = delete;
	Turtle& operator=(const Turtle& _Other) = delete;
	Turtle& operator=(Turtle&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> TurtleRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

