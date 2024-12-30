#pragma once
#include <EngineCore/Actor.h>

// ���� :
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

};

