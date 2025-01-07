#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class GemStatus : public AActor
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
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> GemStatusRenderer;
};

