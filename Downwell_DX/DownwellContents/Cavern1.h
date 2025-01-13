#pragma once
#include "BaseUI.h"

// Ό³Έν :
class Cavern1 : public BaseUI
{
public:
	// constrcuter destructer
	Cavern1();
	~Cavern1();

	// delete Function
	Cavern1(const Cavern1& _Other) = delete;
	Cavern1(Cavern1&& _Other) noexcept = delete;
	Cavern1& operator=(const Cavern1& _Other) = delete;
	Cavern1& operator=(Cavern1&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MakeMap();

protected:

private:
	std::shared_ptr<class MainPlayer> MainPlayerRenderer;
	std::shared_ptr<class ACameraActor> Camera;
	std::shared_ptr<class UTileMapRenderer> TileMap;

	FVector CameraPos = { 0.0f, 0.0f, -1000.0f, 1.0f };
	FVector PlayerPos = FVector::ZERO;
	FVector TileSize = FVector::ZERO;
};

