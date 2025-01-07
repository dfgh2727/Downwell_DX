#include "PreCompile.h"
#include "TitleScreen.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include "Well.h"

TitleScreen::TitleScreen()
{
	//std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	//Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::BeginPlay()
{
	AActor::BeginPlay();

	{
		WellSprite = GetWorld()->SpawnActor<Well>();
		WellSprite->SetActorLocation({ 0.0f, -238.0f, 0.0f });
	}
}

void TitleScreen::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}