#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class PauseScreen : public AActor
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

protected:

private:

};

