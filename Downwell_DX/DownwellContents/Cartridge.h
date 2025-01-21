#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Cartridge : public AActor
{
public:
	// constrcuter destructer
	Cartridge();
	~Cartridge();

	// delete Function
	Cartridge(const Cartridge& _Other) = delete;
	Cartridge(Cartridge&& _Other) noexcept = delete;
	Cartridge& operator=(const Cartridge& _Other) = delete;
	Cartridge& operator=(Cartridge&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> CartridgeRenderer;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;
};

