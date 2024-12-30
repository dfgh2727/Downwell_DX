#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class DeveloperLogo : public AActor
{
public:
	// constrcuter destructer
	DeveloperLogo();
	~DeveloperLogo();

	// delete Function
	DeveloperLogo(const DeveloperLogo& _Other) = delete;
	DeveloperLogo(DeveloperLogo&& _Other) noexcept = delete;
	DeveloperLogo& operator=(const DeveloperLogo& _Other) = delete;
	DeveloperLogo& operator=(DeveloperLogo&& _Other) noexcept = delete;

	std::shared_ptr<class USpriteRenderer> GetRenderer()
	{
		return LogoRenderer;
	}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> LogoRenderer;
	std::shared_ptr<class USpriteRenderer> Child;

};

