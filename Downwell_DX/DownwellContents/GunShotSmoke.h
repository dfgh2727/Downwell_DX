#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GunShotSmoke : public AActor
{
public:
	// constrcuter destructer
	GunShotSmoke();
	~GunShotSmoke();

	// delete Function
	GunShotSmoke(const GunShotSmoke& _Other) = delete;
	GunShotSmoke(GunShotSmoke&& _Other) noexcept = delete;
	GunShotSmoke& operator=(const GunShotSmoke& _Other) = delete;
	GunShotSmoke& operator=(GunShotSmoke&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> GunShotSmokeRenderer;

	float Timer = 0.1f;

};

