#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Gem : public AActor
{
public:
	// constrcuter destructer
	Gem();
	~Gem();

	// delete Function
	Gem(const Gem& _Other) = delete;
	Gem(Gem&& _Other) noexcept = delete;
	Gem& operator=(const Gem& _Other) = delete;
	Gem& operator=(Gem&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> GemRenderer;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;

	float Timer = 3.0f;
};

