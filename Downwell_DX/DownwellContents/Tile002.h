#pragma once
#include "Tile.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Tile002 : public Tile
{
public:
	// constrcuter destructer
	Tile002();
	~Tile002();

	// delete Function
	Tile002(const Tile002& _Other) = delete;
	Tile002(Tile002&& _Other) noexcept = delete;
	Tile002& operator=(const Tile002& _Other) = delete;
	Tile002& operator=(Tile002&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Tile002Renderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

