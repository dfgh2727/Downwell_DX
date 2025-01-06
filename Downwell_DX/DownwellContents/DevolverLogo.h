#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class DevolverLogo : public AActor
{
public:
	// constrcuter destructer
	DevolverLogo();
	~DevolverLogo();

	// delete Function
	DevolverLogo(const DevolverLogo& _Other) = delete;
	DevolverLogo(DevolverLogo&& _Other) noexcept = delete;
	DevolverLogo& operator=(const DevolverLogo& _Other) = delete;
	DevolverLogo& operator=(DevolverLogo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> LogoRenderer;
};

