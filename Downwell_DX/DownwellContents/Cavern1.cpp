#include "PreCompile.h"
#include "Cavern1.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>

#include "DitherFullScreen.h"
#include "Well.h"
#include "NightSky.h"
#include "DownwellTitle.h"
#include "Land.h"
#include "Grass.h"

#include "MainPlayer.h"


Cavern1::Cavern1()
{
	/*std::shared_ptr<ACameraActor> */Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation(CameraPos);
	Camera->GetCameraComponent()->SetZSort(0, true);
}

Cavern1::~Cavern1()
{
}

void Cavern1::BeginPlay()
{
	AActor::BeginPlay();

	{
		MainPlayerRenderer = GetWorld()->SpawnActor<MainPlayer>();
		MainPlayerRenderer->SetActorLocation({ 0.0f, 0.0f, 10.0f });
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
