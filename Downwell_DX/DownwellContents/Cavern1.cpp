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
#include "Dummy.h"


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

	GetWorld()->CreateCollisionProfile("MainPlayer");
	GetWorld()->CreateCollisionProfile("Monster");
}

Cavern1::~Cavern1()
{
}

void Cavern1::CreateMap(FIntPoint StartPos, int _MapIndex)
{
	{
		UEngineSerializer& Ser = ReadDatas[_MapIndex];

		Ser.ResetOffset();
		int MonsterCount = 0;

		Ser >> MonsterCount;

		std::shared_ptr<Dummy> NewMon = GetWorld()->SpawnActor<Dummy>();

		for (size_t i = 0; i < MonsterCount; i++)
		{
			int MonsterTypeValue = 0;
			Ser >> MonsterTypeValue;

			EMonsterType MonsterType = static_cast<EMonsterType>(MonsterTypeValue);
			FVector MonsterLocation;
			Ser >> MonsterLocation;

			switch (MonsterType)
			{
			case EMonsterType::Bat:
				TempBat = GetWorld()->SpawnActor<Bat>();
				TempBat->SetActorLocation(MonsterLocation);
				break;
			case EMonsterType::Crawler:
				break;
			case EMonsterType::Frog:
				break;
			case EMonsterType::Jelly:
				break;
			case EMonsterType::Snail:
				break;
			case EMonsterType::Snake:
				break;
			case EMonsterType::Turtle:
				break;
			default:
				break;
			}

		}

		TileMap->DataSetting(StartPos, Ser);
	}
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
		//int Index = 0;
		CreateMap({ 0, 0 }, 1);
		//CreateMap({ 0, -18 }, 0);

		//TileMap->DataSetting({ 0, -18 }, ReadDatas[1]);
	}

	{
		MainPlayerInst = GetWorld()->SpawnActor<MainPlayer>();
		MainPlayerInst->SetActorLocation({ 0.0f, 0.0f, -10.0f });
		MainPlayerInst->SetTileMapRenderer(TileMap.get());
		//UColor = UEngineWinImage::GetColor
	}

	/*{
		TempBat = GetWorld()->SpawnActor<Bat>();
		TempBat->SetActorLocation({ 0.0f, 0.0f, -10.0f });
	}*/

}

void Cavern1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	PlayerPos = MainPlayerInst->GetActorLocation();
	GoToSelectScreen(_DeltaTime);

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

void Cavern1::GoToSelectScreen(float _DeltaTime)
{
	FVector PlayerPos = MainPlayerInst->GetActorLocation();
	if (PlayerPos.X <= -150.0f)
	{
		UEngineCore::OpenLevel("Cave");
	}
}