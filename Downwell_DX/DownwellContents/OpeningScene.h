#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class OpeningScene : public AActor
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
	void FadeIn();

protected:

private:
	std::shared_ptr<class HowToPlay> Control;
	std::shared_ptr<class Developers> DevelopersName;
	std::shared_ptr<class DevolverLogo> Logo;
	std::shared_ptr<class DitherFullScreen> Dither;

	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;

};

