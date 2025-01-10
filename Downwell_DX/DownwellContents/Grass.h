#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Grass : public AActor
{
public:
	// constrcuter destructer
	Grass();
	~Grass();

	// delete Function
	Grass(const Grass& _Other) = delete;
	Grass(Grass&& _Other) noexcept = delete;
	Grass& operator=(const Grass& _Other) = delete;
	Grass& operator=(Grass&& _Other) noexcept = delete;

	void SetGrass1();
	void SetGrass2();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> GrassRenderer;
};

