#include "PreCompile.h"
#include "DummyBat.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummyBat::DummyBat()
{
	DummyTypeValue = EDummyType::DBat;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummyBatRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyBatRenderer->SetupAttachment(RootComponent);
	DummyBatRenderer->SetTexture("DBat.png", true, 2.0f);
}

DummyBat::~DummyBat()
{
}

void DummyBat::BeginPlay()
{
	AActor::BeginPlay();
}

void DummyBat::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummyBat::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummyBat::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}