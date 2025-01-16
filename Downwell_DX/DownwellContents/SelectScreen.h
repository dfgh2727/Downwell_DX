#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class SelectScreen : public AGameMode
{
public:
	// constrcuter destructer
	SelectScreen();
	~SelectScreen();

	// delete Function
	SelectScreen(const SelectScreen& _Other) = delete;
	SelectScreen(SelectScreen&& _Other) noexcept = delete;
	SelectScreen& operator=(const SelectScreen& _Other) = delete;
	SelectScreen& operator=(SelectScreen&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

protected:

private:

};

