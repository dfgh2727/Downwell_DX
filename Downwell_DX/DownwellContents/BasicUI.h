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

	void SetUIPos();


protected:

private:
	std::shared_ptr<class UImageWidget> UIWidget;

	std::shared_ptr<class MainPlayer> Player;
	std::shared_ptr<class Partition> PartitionImage1;
	std::shared_ptr<class Partition> PartitionImage2;
	std::shared_ptr<class GemStatus> GemStatusImage;
	std::shared_ptr<class HealthStatus> HealthStatusImage;
	std::shared_ptr<class BulletStatus> BulletStatusImage;
	std::shared_ptr<class BulletChange> ShowBulletChange;

	std::shared_ptr<class ACameraActor> Camera;
	FVector ScreenPos = FVector::ZERO;
	FVector Partition1Pos= { -252.0f, 0.0f, -100.0f };
	FVector Partition2Pos = { 284.0f, 0.0f, -100.0f };
	FVector GemStatusPos = { 316.0f, 249.0f, -200.0f };
	FVector HealthStatusPos = { -258.0f, 251.0f, -200.0f };
	FVector BulletStatusPos = { 225.0f, 0.0f, -200.0f };

};

