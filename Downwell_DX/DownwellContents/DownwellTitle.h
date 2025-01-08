#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class DownwellTitle : public AActor
{
public:
	// constrcuter destructer
	DownwellTitle();
	~DownwellTitle();

	// delete Function
	DownwellTitle(const DownwellTitle& _Other) = delete;
	DownwellTitle(DownwellTitle&& _Other) noexcept = delete;
	DownwellTitle& operator=(const DownwellTitle& _Other) = delete;
	DownwellTitle& operator=(DownwellTitle&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DownwellTitleRenderer;
};

