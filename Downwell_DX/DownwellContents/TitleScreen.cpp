#include "PreCompile.h"
#include "TitleScreen.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

#include "MainPlayer.h"

TitleScreen::TitleScreen()
{
	{
		Player = GetWorld()->SpawnActor<MainPlayer>();
		// Logo->SetActorLocation({ 300.0f, 0.0f, 0.0f });
		Player->GetRenderer()->SetSpriteData(4);
	}

	// ī�޶� �����Ÿ� �ڷ� ���� 
	// ī�޶� ��ġ������ ������ ����� �Ұ��̴�.
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::Tick(float _DeltaTime)
{
	// �θ� ȣ��
	AActor::Tick(_DeltaTime);
}