#include "PreCompile.h"
#include "Cavern1.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TileMapRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

#include "DitherFullScreen.h"
#include "Bat.h"
#include "MainPlayer.h"


Cavern1::Cavern1()
{
	Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(CameraPos);
	Camera->GetCameraComponent()->SetZSort(0, true);
	
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	TileMap = CreateDefaultSubObject<UTileMapRenderer>();
	TileMap->SetupAttachment(RootComponent);
	TileMap->SetTileSetting(ETileMapType::Rect, "Tile", TileSize, TileSize, { 0.5f, 0.5f });

	
	
	
}

Cavern1::~Cavern1()
{
}

void Cavern1::BeginPlay()
{
	AActor::BeginPlay();

	{
		UEngineDirectory Dir;
		if (false == Dir.MoveParentToDirectory("ContentsResources"))
		{
			MSGASSERT("리소스 폴더를 찾지 못했습니다.");
			return;
		}
		Dir.Append("MapDataFolder");
		MapDataFiles = Dir.GetAllFile(true, { ".MapData" });
		ReadDatas.resize(MapDataFiles.size());

		for (size_t i = 0; i < MapDataFiles.size(); i++)
		{
			// std::string FilePath = MapDataFiles[i].GetPathToString();

			MapDataFiles[i].FileOpen("rb");
			MapDataFiles[i].Read(ReadDatas[i]);
		}


	}

	{
		//TileMap1->DeSerialize(ReadDatas[0]);
		TileMap->DataSetting({ 0, 0 }, ReadDatas[2]);
		//TileMap->DataSetting({ 0, -18 }, ReadDatas[2]);

	}

	{
		MainPlayerRenderer = GetWorld()->SpawnActor<MainPlayer>();
		MainPlayerRenderer->SetActorLocation({ 0.0f, 0.0f, -10.0f });
		UColor = UEngineWinImage::GetColor
	}

}

void Cavern1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	PlayerPos = MainPlayerRenderer->GetActorLocation();

	{
		CameraPos.X = PlayerPos.X;
		CameraPos.Y = PlayerPos.Y;
		Camera->SetActorLocation(CameraPos);
	}

	if (PrevPos.Y > PlayerPos.Y)
	{
		//MapManager();
		PrevPos = PlayerPos;
	}

	if (UEngineInput::IsDown(VK_ESCAPE))
	{
		UEngineCore::OpenLevel("Paused");
	}

}

void Cavern1::MapManager()
{
	//STileIndex_Y = static_cast<int>(floorf((PlayerPos.Y - TileSize.Y * (5.0f)) / TileSize.Y));
	RTileIndex_Y = static_cast<int>(floorf((PlayerPos.Y + TileSize.Y * (5.0f)) / TileSize.Y));

	for (int x = -5; x < 6; x++)
	{
		//TileMap->SetTile(x, STileIndex_Y, 1);
		TileMap->RemoveTile(x, RTileIndex_Y);
	}
}