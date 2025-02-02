#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class Cavern1 : public AGameMode
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

	void MapManager();

	void CreateMap(FIntPoint StartPos, int _MapIndex);
	void GoToSelectScreen(float _DeltaTime);

protected:

private:
	std::shared_ptr<class MainPlayer> MainPlayerInst;
	std::shared_ptr<class ACameraActor> Camera;
	std::shared_ptr<class UTileMapRenderer> TileMap;
	std::shared_ptr<class UEngineWinImage> ColMap;
	std::shared_ptr<class Bat> TempBat;
	std::shared_ptr<class BulletChange> ShowBullet;

	std::shared_ptr<class Block0> Block00;

	std::shared_ptr<class Debris> Debris0;




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

