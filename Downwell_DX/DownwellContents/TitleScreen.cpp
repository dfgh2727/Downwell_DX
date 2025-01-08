#include "PreCompile.h"
#include "TitleScreen.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>

#include "DitherFullScreen.h"
#include "Well.h"
#include "NightSky.h"
#include "DownwellTitle.h"


TitleScreen::TitleScreen()
{
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::BeginPlay()
{
	AActor::BeginPlay();

	{
		Dither = GetWorld()->SpawnActor<DitherFullScreen>();
		Dither->SetActorLocation({ 0.0f, -285.0f, -500.0f });
		Dither->FadeIn();
	}

	{
		WellSprite = GetWorld()->SpawnActor<Well>();
		WellSprite->SetActorLocation({ 0.0f, -238.0f, 10.0f });
	}
	{
		NightSkySprite = GetWorld()->SpawnActor<NightSky>();
		NightSkySprite->SetActorLocation({ -9.0f, 170.0f, 10.0f });
	}
	{
		DownwellTitleSprite = GetWorld()->SpawnActor<DownwellTitle>();
		DownwellTitleSprite->SetActorLocation({ 0.0f, 170.0f, 10.0f });
	}
}

void TitleScreen::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}