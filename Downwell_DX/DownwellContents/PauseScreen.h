#pragma once
#include <EngineCore/GameMode.h>

// ���� :
class PauseScreen : public AGameMode
{
public:
	// constrcuter destructer
	PauseScreen();
	~PauseScreen();

	// delete Function
	PauseScreen(const PauseScreen& _Other) = delete;
	PauseScreen(PauseScreen&& _Other) noexcept = delete;
	PauseScreen& operator=(const PauseScreen& _Other) = delete;
	PauseScreen& operator=(PauseScreen&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:
	std::shared_ptr<class PausedText> Paused;

};

