#include "PreCompile.h"
#include "PauseScreen.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>

#include "PausedText.h"

PauseScreen::PauseScreen()
{
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);
}

PauseScreen::~PauseScreen()
{
}

void PauseScreen::BeginPlay()
{
	AActor::BeginPlay();

	{
		Paused = GetWorld()->SpawnActor<PausedText>();
		Paused->SetActorLocation({ 0.0f, 149.0f, -150.0f });
	}

}

void PauseScreen::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown(VK_ESCAPE))
	{
		UEngineCore::OpenLevel("Title");
	}
}