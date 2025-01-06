#include "PreCompile.h"
#include "TitleScreen.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

#include "Partition.h"
#include "MainPlayer.h"

TitleScreen::TitleScreen()
{
	// ī�޶� �����Ÿ� �ڷ� ���� 
	// ī�޶� ��ġ������ ������ ����� �Ұ��̴�.
	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	{
		PartitionImage1 = GetWorld()->SpawnActor<Partition>();
		PartitionImage1->SetActorLocation({ -164.0f, 0.0f, 0.0f, 1.0f });
	}
	{
		PartitionImage2 = GetWorld()->SpawnActor<Partition>();
		PartitionImage2->SetActorLocation({ 164.0f, 0.0f, 0.0f, 1.0f });
	}
}

TitleScreen::~TitleScreen()
{
}

void TitleScreen::Tick(float _DeltaTime)
{
	// �θ� ȣ��
	AActor::Tick(_DeltaTime);
}