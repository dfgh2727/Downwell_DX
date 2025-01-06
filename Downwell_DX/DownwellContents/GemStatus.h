#pragma once

// Ό³Έν :
class GemStatus
{
public:
	// constrcuter destructer
	GemStatus();
	~GemStatus();

	// delete Function
	GemStatus(const GemStatus& _Other) = delete;
	GemStatus(GemStatus&& _Other) noexcept = delete;
	GemStatus& operator=(const GemStatus& _Other) = delete;
	GemStatus& operator=(GemStatus&& _Other) noexcept = delete;

protected:

private:

};

