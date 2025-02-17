#include <EngineCore/Actor.h>
#pragma once

// Ό³Έν :
class GemCounter : public AActor
{
public:
	// constrcuter destructer
	GemCounter();
	~GemCounter();

	// delete Function
	GemCounter(const GemCounter& _Other) = delete;
	GemCounter(GemCounter&& _Other) noexcept = delete;
	GemCounter& operator=(const GemCounter& _Other) = delete;
	GemCounter& operator=(GemCounter&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class Counter> CountGem;
	std::shared_ptr<class Bat> TestBat;
	//std::shared_ptr<class USpriteRenderer> TempRenderer;

	//FVector CurPos = FVector::ZERO;
	int Num = 10;
};

