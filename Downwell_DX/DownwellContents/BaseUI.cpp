#include "PreCompile.h"
#include "BaseUI.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/SpriteRenderer.h>

#include "Partition.h"
#include "MainPlayer.h"
#include "GemStatus.h"
#include "HealthStatus.h"
#include "BulletStatus.h"

BaseUI::BaseUI()
{
	// 카메라를 일정거리 뒤로 가서 
	// 카메라 위치조정을 무조건 해줘야 할것이다.
	//std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	//Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });

	{
		PartitionImage1 = GetWorld()->SpawnActor<Partition>();
		PartitionImage1->SetActorLocation({ -268.0f, 0.0f, -100.0f, 1.0f });
	}
	{
		PartitionImage2 = GetWorld()->SpawnActor<Partition>();
		PartitionImage2->SetActorLocation({ 268.0f, 0.0f, -100.0f, 1.0f });
		PartitionImage2->AddActorRotation(FVector{ 0.0f, 0.0f , 180.0f});
	}
	{
		GemStatusImage = GetWorld()->SpawnActor<GemStatus>();
		GemStatusImage->SetActorLocation({ 300.0f, 249.0f, -200.0f, 1.0f });
	}
	{
		HealthStatusImage = GetWorld()->SpawnActor<HealthStatus>();
		HealthStatusImage->SetActorLocation({ -274.0f, 251.0f, -200.0f, 1.0f });
	}
	{
		BulletStatusImage = GetWorld()->SpawnActor<BulletStatus>();
		BulletStatusImage->SetActorLocation({ 209.0f, 0.0f, -200.0f, 1.0f });
	}
}

BaseUI::~BaseUI()
{
}

void BaseUI::BeginPlay()
{
	AActor::BeginPlay();
}

void BaseUI::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}