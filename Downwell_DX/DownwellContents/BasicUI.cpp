#include "PreCompile.h"
#include "BasicUI.h"
#include <EngineCore/ImageWidget.h>

#include "Partition.h"
#include "MainPlayer.h"
#include "GemStatus.h"
#include "HealthStatus.h"
#include "BulletStatus.h"

BasicUI::BasicUI()
{
	
}

BasicUI::~BasicUI()
{
}

void BasicUI::BeginPlay()
{
	AHUD::BeginPlay();

	//UIWidget = CreateWidget<UImageWidget>(-1);

	{
		//PartitionImage1 = UIWidget->GetWorld()->SpawnActor<Partition>();
		PartitionImage1 = GetWorld()->SpawnActor<Partition>();
		PartitionImage1->SetActorLocation({ -268.0f, 0.0f, -100.0f });
	}
	{
		PartitionImage2 = GetWorld()->SpawnActor<Partition>();
		PartitionImage2->SetActorLocation({ 268.0f, 0.0f, -100.0f });
		PartitionImage2->AddActorRotation(FVector{ 0.0f, 0.0f , 180.0f });
	}
	{
		GemStatusImage = GetWorld()->SpawnActor<GemStatus>();
		GemStatusImage->SetActorLocation({ 300.0f, 249.0f, -200.0f });
	}
	{
		HealthStatusImage = GetWorld()->SpawnActor<HealthStatus>();
		HealthStatusImage->SetActorLocation({ -274.0f, 251.0f, -200.0f });
	}
	{
		BulletStatusImage = GetWorld()->SpawnActor<BulletStatus>();
		BulletStatusImage->SetActorLocation({ 209.0f, 0.0f, -200.0f });
	}
}

void BasicUI::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);
}