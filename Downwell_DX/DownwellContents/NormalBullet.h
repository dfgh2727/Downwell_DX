#pragma once
#include "EngineCore/Actor.h"

// Ό³Έν :
class NormalBullet : public AActor
{
public:
	// constrcuter destructer
	NormalBullet();
	~NormalBullet();

	// delete Function
	NormalBullet(const NormalBullet& _Other) = delete;
	NormalBullet(NormalBullet&& _Other) noexcept = delete;
	NormalBullet& operator=(const NormalBullet& _Other) = delete;
	NormalBullet& operator=(NormalBullet&& _Other) noexcept = delete;

	void SetTileMapRenderer(class UTileMapRenderer* _Renderer)
	{
		TRenderer = _Renderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void Break();

private:
	std::shared_ptr<class USpriteRenderer> NormalBulletRenderer = nullptr;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
	class UTileMapRenderer* TRenderer = nullptr;
	struct FTileData* TData = nullptr;

	std::shared_ptr<class UCollision> CollisionBox;
	float Timer = 0.5f;
	FVector Velocity = FVector::DOWN * 500.0f;

	//std::vector<UCollision*> BlockCollision;
};

