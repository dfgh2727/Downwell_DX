#pragma once
#include <EngineCore/GameMode.h>

// ���� :
class TitleScreen : public AGameMode
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

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void GoToSelectScreen(float _DeltaTime);

protected:

private:
	std::shared_ptr<class DitherFullScreen> Dither;
	std::shared_ptr<class Well> WellSprite;
	std::shared_ptr<class NightSky> NightSkySprite;
	std::shared_ptr<class DownwellTitle> DownwellTitleSprite;
	std::shared_ptr<class Land> LandSprite;
	std::shared_ptr<class Grass> GrassSprite1;
	std::shared_ptr<class Grass> GrassSprite2;
	//std::shared_ptr<class Grass> GrassSprite3;
	
	//std::shared_ptr<class UCollision> Collision;
	std::shared_ptr<class MainPlayer> MainPlayerRenderer;
};

