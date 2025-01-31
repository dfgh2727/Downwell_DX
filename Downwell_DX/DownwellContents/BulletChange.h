#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BulletChange : public AActor
{
public:
	// constrcuter destructer
	BulletChange();
	~BulletChange();

	// delete Function
	BulletChange(const BulletChange& _Other) = delete;
	BulletChange(BulletChange&& _Other) noexcept = delete;
	BulletChange& operator=(const BulletChange& _Other) = delete;
	BulletChange& operator=(BulletChange&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> BulletGauge;

};

