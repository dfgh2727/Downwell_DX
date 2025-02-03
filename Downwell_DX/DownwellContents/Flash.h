#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Flash : public AActor
{
public:
	// constrcuter destructer
	Flash();
	~Flash();

	// delete Function
	Flash(const Flash& _Other) = delete;
	Flash(Flash&& _Other) noexcept = delete;
	Flash& operator=(const Flash& _Other) = delete;
	Flash& operator=(Flash&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> FlashRenderer;

	float Timer = 0.08f;

};

