#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class HowToPlay : public AActor
{
public:
	// constrcuter destructer
	HowToPlay();
	~HowToPlay();

	// delete Function
	HowToPlay(const HowToPlay& _Other) = delete;
	HowToPlay(HowToPlay&& _Other) noexcept = delete;
	HowToPlay& operator=(const HowToPlay& _Other) = delete;
	HowToPlay& operator=(HowToPlay&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return ControlRenderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> ControlRenderer;

};

