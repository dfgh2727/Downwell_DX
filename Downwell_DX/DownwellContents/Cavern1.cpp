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

#include "Block0.h"
#include "BulletChange.h"
#include "Debris.h"

#include "BasicUI.h"


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
	GetWorld()->CreateCollisionProfile("Block");
	GetWorld()->CreateCollisionProfile("Bullet");
	GetWorld()->CreateCollisionProfile("Debris");

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

			ESpawnType MonsterType = static_cast<ESpawnType>(MonsterTypeValue);
			FVector MonsterLocation;
			Ser >> MonsterLocation;

			switch (MonsterType)
			{
			case ESpawnType::MBat:
				TempBat = GetWorld()->SpawnActor<Bat>();
				TempBat->SetActorLocation(MonsterLocation);
				break;
			case ESpawnType::SBlock0:
				Block00 = GetWorld()->SpawnActor<Block0>();
				Block00->SetActorLocation(MonsterLocation);
				break;
			/*case ESpawnType::MCrawler:
				break;
			case ESpawnType::MFrog:
				break;
			case ESpawnType::MJelly:
				break;
			case ESpawnType::MSnail:
				break;
			case ESpawnType::MSnake:
				break;
			case ESpawnType::MTurtle:
				break;*/
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
		//CreateMap({ 0, 0 }, 0);
		CreateMap({ 0, 0 }, 2);
		CreateMap({ 0, -18 }, 3);
		CreateMap({ 0, -36 }, 4);
		CreateMap({ 0, -54 }, 5);
		CreateMap({ 0, -72 }, 6);

	}

	{
		MainPlayerInst = GetWorld()->SpawnActor<MainPlayer>();
		MainPlayerInst->SetActorLocation({ 0.0f, 0.0f, -10.0f });
		MainPlayerInst->SetTileMapRenderer(TileMap.get());
		
	}
}

void Cavern1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	PlayerPos = MainPlayerInst->GetActorLocation();
	GoToSelectScreen(_DeltaTime);

	{
		//CameraPos.X = PlayerPos.X;
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

	if (true == MainPlayerInst->IsShooting)
	{
		ShakeCamera(_DeltaTime);
	}
	else
	{
		ShakingTime = 1.0f;
	}

	PlayerBullet = MainPlayerInst->Pistol;

	FVector PlayerPos = MainPlayerInst->GetActorLocation();
	if (PlayerPos.Y <= -4000.0f)
	{
		UEngineCore::OpenLevel("Title");
		//UEngineCore::OpenLevel("Cavern1");
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
	if (PlayerPos.X <= -180.0f)
	{
		UEngineCore::OpenLevel("Cave");
	}
}

void Cavern1::ShakeCamera(float _DeltaTime)
{
	FVector ShakeDirU = FVector::UP * 1000.0f;
	FVector ShakeDirD = FVector::DOWN * 500.0f;
	FVector ShakeDirL = FVector::LEFT * 500.0f;
	FVector ShakeDirR = FVector::RIGHT* 500.0f;

	ShakingTime -= _DeltaTime;

	if (0.3< ShakingTime)
	{
		Camera->AddActorLocation(ShakeDirU * _DeltaTime);
	}
	if (0.4 < ShakingTime < 0.7f)
	{
		Camera->AddActorLocation(ShakeDirR * _DeltaTime);
	}
	if (0.2 < ShakingTime < 0.5f)
	{
		//Camera->AddActorLocation(ShakeDirD * _DeltaTime);
	}
	if (0.0 < ShakingTime < 0.3f)
	{
		Camera->AddActorLocation(ShakeDirL * _DeltaTime);
	}
}