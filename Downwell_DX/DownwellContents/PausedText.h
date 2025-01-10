#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class PausedText : public AActor
{
public:
	// constrcuter destructer
	PausedText();
	~PausedText();

	// delete Function
	PausedText(const PausedText& _Other) = delete;
	PausedText(PausedText&& _Other) noexcept = delete;
	PausedText& operator=(const PausedText& _Other) = delete;
	PausedText& operator=(PausedText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> PausedTextRenderer;
};

