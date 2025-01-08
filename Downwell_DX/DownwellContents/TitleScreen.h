#pragma once
#include "BaseUI.h"

// Ό³Έν :
class TitleScreen : public BaseUI
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
	std::shared_ptr<class MainPlayer> MainPlayerRenderer;
};

