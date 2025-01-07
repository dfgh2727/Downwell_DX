#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Grass2 : public AActor
{
public:
	// constrcuter destructer
	Grass2();
	~Grass2();

	// delete Function
	Grass2(const Grass2& _Other) = delete;
	Grass2(Grass2&& _Other) noexcept = delete;
	Grass2& operator=(const Grass2& _Other) = delete;
	Grass2& operator=(Grass2&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Grass2Renderer;
};

