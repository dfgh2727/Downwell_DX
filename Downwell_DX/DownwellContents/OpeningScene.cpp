#include "PreCompile.h"
#include "OpeningScene.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/EngineCamera.h>

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

//{
//	Control = GetWorld()->SpawnActor<HowToPlay>();
//	// Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
//}

}
