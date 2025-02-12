#include <EngineCore/Actor.h>
#pragma once

// Ό³Έν :
class BulletCounter : public AActor
{
public:
	// constrcuter destructer
	BulletCounter();
	~BulletCounter();

	// delete Function
	BulletCounter(const BulletCounter& _Other) = delete;
	BulletCounter(BulletCounter&& _Other) noexcept = delete;
	BulletCounter& operator=(const BulletCounter& _Other) = delete;
	BulletCounter& operator=(BulletCounter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class Counter> CountBullet;
	std::shared_ptr<class MainPlayer> PlayerPtr;

	int Num = 0;

};

