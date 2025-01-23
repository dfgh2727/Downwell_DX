#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class Cave : public AGameMode
{
public:
	// constrcuter destructer
	Cave();
	~Cave();

	// delete Function
	Cave(const Cave& _Other) = delete;
	Cave(Cave&& _Other) noexcept = delete;
	Cave& operator=(const Cave& _Other) = delete;
	Cave& operator=(Cave&& _Other) noexcept = delete;

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MapManager();

	void CreateMap(FIntPoint StartPos, int _MapIndex);


protected:

private:
	std::shared_ptr<class MainPlayer> MainPlayerInst;
	std::shared_ptr<class ACameraActor> Camera;
	std::shared_ptr<class UTileMapRenderer> TileMap;
	std::shared_ptr<class UEngineWinImage> ColMap;
	std::shared_ptr<class Bat> TempBat;

	class UEngineFile ColMapFile;

	std::vector<UEngineFile> MapDataFiles;
	std::vector<UEngineSerializer> ReadDatas;

	FVector CameraPos = { 0.0f, 0.0f, -1000.0f, 1.0f };
	FVector PlayerPos = FVector::ZERO;
	FVector PrevPos = FVector::ZERO;
	FVector TileSize = { 32.0f, 32.0f };

	int STileIndex_Y = 0;
	int RTileIndex_Y = 0;

};

