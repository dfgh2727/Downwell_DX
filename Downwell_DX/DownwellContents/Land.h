#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Land : public AActor
{
public:
	// constrcuter destructer
	Land();
	~Land();

	// delete Function
	Land(const Land& _Other) = delete;
	Land(Land&& _Other) noexcept = delete;
	Land& operator=(const Land& _Other) = delete;
	Land& operator=(Land&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> LandRenderer;
};

