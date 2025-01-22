#pragma once
#include "EngineCore/Actor.h"

// Ό³Έν :
class BasicBullet : public AActor
{
public:
	// constrcuter destructer
	BasicBullet();
	~BasicBullet();

	// delete Function
	BasicBullet(const BasicBullet& _Other) = delete;
	BasicBullet(BasicBullet&& _Other) noexcept = delete;
	BasicBullet& operator=(const BasicBullet& _Other) = delete;
	BasicBullet& operator=(BasicBullet&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
private:
	std::shared_ptr<class USpriteRenderer> BasicBulletRenderer = nullptr;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
};

