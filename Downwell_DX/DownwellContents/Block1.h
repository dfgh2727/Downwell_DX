#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Block1 : public AActor
{
public:
	// constrcuter destructer
	Block1();
	~Block1();

	// delete Function
	Block1(const Block1& _Other) = delete;
	Block1(Block1&& _Other) noexcept = delete;
	Block1& operator=(const Block1& _Other) = delete;
	Block1& operator=(Block1&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Block1Renderer;

	std::shared_ptr<class UCollision> CollisionBox;

};

