#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class EmptyText : public AActor
{
public:
	// constrcuter destructer
	EmptyText();
	~EmptyText();

	// delete Function
	EmptyText(const EmptyText& _Other) = delete;
	EmptyText(EmptyText&& _Other) noexcept = delete;
	EmptyText& operator=(const EmptyText& _Other) = delete;
	EmptyText& operator=(EmptyText&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer>TextRenderer;

	float Timer = 0.1f;

};

