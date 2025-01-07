#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class NightSky : public AActor
{
public:
	// constrcuter destructer
	NightSky();
	~NightSky();

	// delete Function
	NightSky(const NightSky& _Other) = delete;
	NightSky(NightSky&& _Other) noexcept = delete;
	NightSky& operator=(const NightSky& _Other) = delete;
	NightSky& operator=(NightSky&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> NightSkyRenderer;
};

