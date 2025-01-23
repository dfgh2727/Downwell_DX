#include "PreCompile.h"
#include "DummyCrawler.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummyCrawler::DummyCrawler()
{
	DummyTypeValue = EDummyType::DCrawler;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummyCrawlerRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyCrawlerRenderer->SetupAttachment(RootComponent);
	DummyCrawlerRenderer->SetTexture("DummyCrawler.png", true, 2.0f);
}

DummyCrawler::~DummyCrawler()
{
}

void DummyCrawler::BeginPlay()
{
	AActor::BeginPlay();
}

void DummyCrawler::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummyCrawler::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummyCrawler::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}