#pragma once

// Ό³Έν :
class SelectScreen
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

protected:

private:

};

