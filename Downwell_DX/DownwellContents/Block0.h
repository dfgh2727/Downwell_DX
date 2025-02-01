#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Block0 : public AActor
{
public:
	// constrcuter destructer
	Block0();
	~Block0();

	// delete Function
	Block0(const Block0& _Other) = delete;
	Block0(Block0&& _Other) noexcept = delete;
	Block0& operator=(const Block0& _Other) = delete;
	Block0& operator=(Block0&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Block0Renderer;

	std::shared_ptr<class UCollision> CollisionBox;

};

