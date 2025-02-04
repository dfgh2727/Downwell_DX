#pragma once
#include <EngineCore/Actor.h>
#include <EngineBase/EngineRandom.h>

// Ό³Έν :
class SmokeBall : public AActor
{
public:
	// constrcuter destructer
	SmokeBall();
	~SmokeBall();

	// delete Function
	SmokeBall(const SmokeBall& _Other) = delete;
	SmokeBall(SmokeBall&& _Other) noexcept = delete;
	SmokeBall& operator=(const SmokeBall& _Other) = delete;
	SmokeBall& operator=(SmokeBall&& _Other) noexcept = delete;
	
	class UEngineRandom* UEngineRandomPtr;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> SmokeBallRenderer;
	float Timer = 0.8f;

	FVector Velocity = FVector::ZERO;

};

