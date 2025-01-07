#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Grass1 : public AActor
{
public:
	// constrcuter destructer
	Grass1();
	~Grass1();

	// delete Function
	Grass1(const Grass1& _Other) = delete;
	Grass1(Grass1&& _Other) noexcept = delete;
	Grass1& operator=(const Grass1& _Other) = delete;
	Grass1& operator=(Grass1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Grass1Renderer;
};

