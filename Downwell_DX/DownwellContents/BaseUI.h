#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class BaseUI : public AActor
{
public:
	// constrcuter destructer
	BaseUI();
	~BaseUI();

	// delete Function
	BaseUI(const BaseUI& _Other) = delete;
	BaseUI(BaseUI&& _Other) noexcept = delete;
	BaseUI& operator=(const BaseUI& _Other) = delete;
	BaseUI& operator=(BaseUI&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	std::shared_ptr<class MainPlayer> Player;
	std::shared_ptr<class Partition> PartitionImage1;
	std::shared_ptr<class Partition> PartitionImage2;
	std::shared_ptr<class GemStatus> GemStatusImage;
	std::shared_ptr<class HealthStatus> HealthStatusImage;
	std::shared_ptr<class BulletStatus> BulletStatusImage;
};

