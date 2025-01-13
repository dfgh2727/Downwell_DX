#include "PreCompile.h"
#include "Cavern1.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TileMapRenderer.h>

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
	TileSize = { 32.0f, 32.0f };
	TileMap->SetTileSetting(ETileMapType::Rect, "Tile", TileSize, TileSize, { 0.5f, 0.5f });
}

Cavern1::~Cavern1()
{
}

void Cavern1::BeginPlay()
{
	AActor::BeginPlay();

	{
		for (int y = -10; y < 10; y++)
		{
			for (int x = -5; x < 6; x++)
			{
				TileMap->SetTile(x, y, 1);	
			}
		}
	}

	{
		MainPlayerRenderer = GetWorld()->SpawnActor<MainPlayer>();
		MainPlayerRenderer->SetActorLocation({ 0.0f, 0.0f, -10.0f });
	}

}

void Cavern1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_ESCAPE))
	{
		UEngineCore::OpenLevel("Paused");
	}

	{
		PlayerPos = MainPlayerRenderer->GetActorLocation();
		CameraPos.X = PlayerPos.X;
		CameraPos.Y = PlayerPos.Y;
		Camera->SetActorLocation(CameraPos);
	}

}

void Cavern1::MakeMap()
{
	//if(PlayerPos.Y >= TileSize.Y)
}