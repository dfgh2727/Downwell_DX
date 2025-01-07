#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class HealthStatus : public AActor
{
public:
	// constrcuter destructer
	HealthStatus();
	~HealthStatus();

	// delete Function
	HealthStatus(const HealthStatus& _Other) = delete;
	HealthStatus(HealthStatus&& _Other) noexcept = delete;
	HealthStatus& operator=(const HealthStatus& _Other) = delete;
	HealthStatus& operator=(HealthStatus&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> HealthStatusRenderer;
};

