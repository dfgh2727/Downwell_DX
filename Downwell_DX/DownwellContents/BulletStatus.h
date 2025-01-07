#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BulletStatus : public AActor
{
public:
	// constrcuter destructer
	BulletStatus();
	~BulletStatus();

	// delete Function
	BulletStatus(const BulletStatus& _Other) = delete;
	BulletStatus(BulletStatus&& _Other) noexcept = delete;
	BulletStatus& operator=(const BulletStatus& _Other) = delete;
	BulletStatus& operator=(BulletStatus&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> BulletStatusRenderer;
};

