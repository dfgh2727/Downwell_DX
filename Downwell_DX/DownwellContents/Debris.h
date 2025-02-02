#pragma once
#include "EngineCore/Actor.h"

// Ό³Έν :
class Debris : public AActor
{
public:
	// constrcuter destructer
	Debris();
	~Debris();

	// delete Function
	Debris(const Debris& _Other) = delete;
	Debris(Debris&& _Other) noexcept = delete;
	Debris& operator=(const Debris& _Other) = delete;
	Debris& operator=(Debris&& _Other) noexcept = delete;

	void SetTileMapRenderer(class UTileMapRenderer* _Renderer)
	{
		TRenderer = _Renderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	bool TileCheck(FVector _AddPos);
	void GravityManager(float _DeltaTime);
	//void BlockCheck();


private:
	class UTileMapRenderer* TRenderer = nullptr;
	struct FTileData* TData = nullptr;

	std::shared_ptr<class USpriteRenderer> DebrisRenderer = nullptr;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;

	std::shared_ptr<class UCollision> CollisionBox;
	bool IsTile = false;
	bool IsOnTheGround = false;
	
	float Timer = 1.0f;

	FVector GForce = FVector::DOWN * 300.0f;
	FVector Gravity = FVector::ZERO;

	FVector PrevLocation = FVector::ZERO;
};

