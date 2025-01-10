#include "PreCompile.h"
#include "OpeningScene.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/TimeEventComponent.h>
#include <EnginePlatform/EngineInput.h>

#include "DevolverLogo.h"
#include "Developers.h"
#include "HowToPlay.h"
#include "DitherFullScreen.h"

OpeningScene::OpeningScene()
{
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);

	{
		Logo = GetWorld()->SpawnActor<DevolverLogo>();
	}
}

OpeningScene::~OpeningScene()
{
}

void OpeningScene::BeginPlay()
{
	AActor::BeginPlay();

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();

	TimeEventComponent->AddEndEvent(2.5f,
		[this]()
		{
			OpeningScene::ShowDevelopers();
		},
		false);

	TimeEventComponent->AddEndEvent(5.0f,
		[this]()
		{
			OpeningScene::ShowControl();
		},
		false);

	TimeEventComponent->AddEndEvent(7.5f,
		[this]()
		{
			OpeningScene::FadeOut();
		},
		false);

	TimeEventComponent->AddEndEvent(8.5f,
		[]()
		{
			UEngineCore::OpenLevel("Title");
		},
		false);
}

void OpeningScene::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsDown('P'))
	{
		UEngineCore::OpenLevel("Title");
	}
}

void OpeningScene::ShowDevelopers()
{
	Logo->Destroy();
	DevelopersName = GetWorld()->SpawnActor<Developers>();
	DevelopersName->SetActorLocation({ 0.0f, -61.0f, 0.0f });
	//Logo = nullptr;
}

void OpeningScene::ShowControl()
{
	DevelopersName->Destroy();
	//DevelopersName = nullptr;
	Control = GetWorld()->SpawnActor<HowToPlay>();
}

void OpeningScene::FadeOut()
{
	Dither = GetWorld()->SpawnActor<DitherFullScreen>();
	Dither->SetActorLocation({ 0.0f, 0.0f, -50.0f });
	Dither->FadeOut();
}