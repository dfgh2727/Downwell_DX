#include "PreCompile.h"
#include "OpeningScene.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/TimeEventComponent.h>

#include "DevolverLogo.h"
#include "Developers.h"
#include "HowToPlay.h"

OpeningScene::OpeningScene()
{
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);

	{
		Logo = GetWorld()->SpawnActor<DevolverLogo>();
		// Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
	}
}

OpeningScene::~OpeningScene()
{
}

void OpeningScene::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

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
}

void OpeningScene::ShowDevelopers()
{
	//Logo->Destroy();
	DevelopersName = GetWorld()->SpawnActor<Developers>();
}

void OpeningScene::ShowControl()
{
	DevelopersName->Destroy();
	Control = GetWorld()->SpawnActor<HowToPlay>();
}