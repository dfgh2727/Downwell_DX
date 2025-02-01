#include "PreCompile.h"
#include "Crawler.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Crawler::Crawler()
{
	SpawnTypeValue = ESpawnType::MCrawler;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	CrawlerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	CrawlerRenderer->SetupAttachment(RootComponent);
	//CrawlerRenderer->CreateAnimation("Crawler_Fly", "Crawler", 0, 3, 0.1f);
	//CrawlerRenderer->ChangeAnimation("Crawler_Fly");
	CrawlerRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
}

Crawler::~Crawler()
{
}

void Crawler::BeginPlay()
{
	AActor::BeginPlay();
}

void Crawler::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Crawler::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Crawler::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}