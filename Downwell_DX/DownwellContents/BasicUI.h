#pragma once
#include <EngineCore/HUD.h>

// Ό³Έν :
class BasicUI : public AHUD
{
public:
	// constrcuter destructer
	BasicUI();
	~BasicUI();

	// delete Function
	BasicUI(const BasicUI& _Other) = delete;
	BasicUI(BasicUI&& _Other) noexcept = delete;
	BasicUI& operator=(const BasicUI& _Other) = delete;
	BasicUI& operator=(BasicUI&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	//std::shared_ptr<class UImageWidget> UIWidget;

	std::shared_ptr<class MainPlayer> Player;
	std::shared_ptr<class Partition> PartitionImage1;
	std::shared_ptr<class Partition> PartitionImage2;
	std::shared_ptr<class GemStatus> GemStatusImage;
	std::shared_ptr<class HealthStatus> HealthStatusImage;
	std::shared_ptr<class BulletStatus> BulletStatusImage;
};

