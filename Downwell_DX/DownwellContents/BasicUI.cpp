#include "PreCompile.h"
#include "BasicUI.h"
#include <EngineCore/ImageWidget.h>
#include <EngineCore/CameraActor.h>
#include <EngineCore/EngineCamera.h>

#include "Partition.h"
#include "MainPlayer.h"
#include "GemStatus.h"
#include "HealthStatus.h"
#include "BulletStatus.h"
#include "BulletChange.h"

BasicUI::BasicUI()
{
	
}

BasicUI::~BasicUI()
{
}

void BasicUI::BeginPlay()
{
	AHUD::BeginPlay();
	
	UIWidget = CreateWidget<UImageWidget>(-10);
	
	//Camera = GetWorld()->GetMainCamera();
	
	{
		PartitionImage1 = UIWidget->GetWorld()->SpawnActor<Partition>();
		//PartitionImage1 = GetWorld()->SpawnActor<Partition>();
		//PartitionImage1->SetActorLocation({ -252.0f, 0.0f, -100.0f });
		PartitionImage1->SetActorLocation(Partition1Pos);
	}
	{
		PartitionImage2 = UIWidget->GetWorld()->SpawnActor<Partition>();
		//PartitionImage2->SetActorLocation({ 284.0f, 0.0f, -100.0f });
		PartitionImage2->SetActorLocation(Partition2Pos);
		PartitionImage2->AddActorRotation(FVector{ 0.0f, 0.0f , 180.0f });
	}
	{
		GemStatusImage = UIWidget->GetWorld()->SpawnActor<GemStatus>();
		GemStatusImage->SetActorLocation(GemStatusPos);
		//GemStatusImage->SetActorLocation({ 316.0f, 249.0f, -200.0f });
	}
	{
		HealthStatusImage = UIWidget->GetWorld()->SpawnActor<HealthStatus>();
		HealthStatusImage->SetActorLocation(HealthStatusPos);
		//HealthStatusImage->SetActorLocation({ -258.0f, 251.0f, -200.0f });
	}
	{
		BulletStatusImage = UIWidget->GetWorld()->SpawnActor<BulletStatus>();
		BulletStatusImage->SetActorLocation(BulletStatusPos);
		//BulletStatusImage->SetActorLocation({ 225.0f, 0.0f, -200.0f });
	}

	/*{
		ShowBulletChange = UIWidget->GetWorld()->SpawnActor<BulletChange>();
		ShowBulletChange->SetActorLocation(BulletStatusPos);
	}*/
}

void BasicUI::Tick(float _DeltaTime)
{
	AHUD::Tick(_DeltaTime);

	SetUIPos();
}

void BasicUI::SetUIPos()
{
	ScreenPos = GetWorld()->GetMainCamera()->GetActorLocation();
	ScreenPos.Z = 0.0f;
	ScreenPos.X = 0.0f;


	PartitionImage1->SetActorLocation(Partition1Pos + ScreenPos);
	PartitionImage2->SetActorLocation(Partition2Pos + ScreenPos);
	GemStatusImage->SetActorLocation(GemStatusPos + ScreenPos);
	HealthStatusImage->SetActorLocation(HealthStatusPos + ScreenPos);
	BulletStatusImage->SetActorLocation(BulletStatusPos + ScreenPos);
	//ShowBulletChange->SetActorLocation(BulletStatusPos + ScreenPos);


}