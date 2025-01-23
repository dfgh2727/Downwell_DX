#include "PreCompile.h"
#include "DummySnail.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummySnail::DummySnail()
{
	DummyTypeValue = EDummyType::DSnail;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummySnailRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummySnailRenderer->SetupAttachment(RootComponent);
	DummySnailRenderer->SetTexture("DummySnail.png", true, 2.0f);
}

DummySnail::~DummySnail()
{
}

void DummySnail::BeginPlay()
{
	AActor::BeginPlay();
}

void DummySnail::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummySnail::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummySnail::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}