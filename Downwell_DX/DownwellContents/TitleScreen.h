#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class TitleScreen : public AActor
{
public:
	// constrcuter destructer
	TitleScreen();
	~TitleScreen();

	// delete Function
	TitleScreen(const TitleScreen& _Other) = delete;
	TitleScreen(TitleScreen&& _Other) noexcept = delete;
	TitleScreen& operator=(const TitleScreen& _Other) = delete;
	TitleScreen& operator=(TitleScreen&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:
	std::shared_ptr<class MainPlayer> Player;
	std::shared_ptr<class Partition> PartitionImage1;
	std::shared_ptr<class Partition> PartitionImage2;
	std::shared_ptr<class GemStatus> GemStatusImage;
	std::shared_ptr<class HealthStatus> HealthStatusImage;
	std::shared_ptr<class BulletStatus> BulletStatusImage;


};

