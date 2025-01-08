#include "PreCompile.h"
#include "SelectScreen.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EnginePlatform/EngineInput.h>

SelectScreen::SelectScreen()
{
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);
}

SelectScreen::~SelectScreen()
{
}

void SelectScreen::BeginPlay()
{
	AActor::BeginPlay();

}

void SelectScreen::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}