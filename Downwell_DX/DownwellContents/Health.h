#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Health : public AActor
{
public:
	// constrcuter destructer
	Health();
	~Health();

	// delete Function
	Health(const Health& _Other) = delete;
	Health(Health&& _Other) noexcept = delete;
	Health& operator=(const Health& _Other) = delete;
	Health& operator=(Health&& _Other) noexcept = delete;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

