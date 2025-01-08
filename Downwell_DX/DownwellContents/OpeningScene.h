#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class OpeningScene : public AGameMode
{
public:
	// constrcuter destructer
	OpeningScene();
	~OpeningScene();

	// delete Function
	OpeningScene(const OpeningScene& _Other) = delete;
	OpeningScene(OpeningScene&& _Other) noexcept = delete;
	OpeningScene& operator=(const OpeningScene& _Other) = delete;
	OpeningScene& operator=(OpeningScene&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void ShowDevelopers();
	void ShowControl();
	void FadeOut();

protected:

private:
	std::shared_ptr<class HowToPlay> Control;
	std::shared_ptr<class Developers> DevelopersName;
	std::shared_ptr<class DevolverLogo> Logo;
	std::shared_ptr<class DitherFullScreen> Dither;

	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;

};

