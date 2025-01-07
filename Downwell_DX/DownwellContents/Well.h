#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Well : public AActor
{
public:
	// constrcuter destructer
	Well();
	~Well();

	// delete Function
	Well(const Well& _Other) = delete;
	Well(Well&& _Other) noexcept = delete;
	Well& operator=(const Well& _Other) = delete;
	Well& operator=(Well&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> WellRenderer;
};

