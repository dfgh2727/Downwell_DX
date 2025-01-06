#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Developers : public AActor
{
public:
	// constrcuter destructer
	Developers();
	~Developers();

	// delete Function
	Developers(const Developers& _Other) = delete;
	Developers(Developers&& _Other) noexcept = delete;
	Developers& operator=(const Developers& _Other) = delete;
	Developers& operator=(Developers&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DevelopersRenderer;
};

