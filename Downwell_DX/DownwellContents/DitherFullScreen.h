#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class DitherFullScreen : public AActor
{
public:
	// constrcuter destructer
	DitherFullScreen();
	~DitherFullScreen();

	// delete Function
	DitherFullScreen(const DitherFullScreen& _Other) = delete;
	DitherFullScreen(DitherFullScreen&& _Other) noexcept = delete;
	DitherFullScreen& operator=(const DitherFullScreen& _Other) = delete;
	DitherFullScreen& operator=(DitherFullScreen&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return DFSRenderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DFSRenderer;
};

