#pragma once
#include <EngineCore/Actor.h>

enum TileType
{
	T1,
	T2,
};

class Tile : public AActor
{
public:
	// constrcuter destructer
	Tile();
	~Tile();

	// delete Function
	Tile(const Tile& _Other) = delete;
	Tile(Tile&& _Other) noexcept = delete;
	Tile& operator=(const Tile& _Other) = delete;
	Tile& operator=(Tile&& _Other) noexcept = delete;

	TileType Tiles;

protected:

private:

};

