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

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> NormalBulletRenderer = nullptr;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
};

