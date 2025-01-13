#pragma once
#include "Tile.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Tile001 : public Tile
{
public:
	// constrcuter destructer
	Tile001();
	~Tile001();

	// delete Function
	Tile001(const Tile001& _Other) = delete;
	Tile001(Tile001&& _Other) noexcept = delete;
	Tile001& operator=(const Tile001& _Other) = delete;
	Tile001& operator=(Tile001&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> Tile001Renderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

