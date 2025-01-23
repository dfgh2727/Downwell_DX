#include "PreCompile.h"
#include "DummyFrog.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummyFrog::DummyFrog()
{
	DummyTypeValue = EDummyType::DFrog;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummyFrogRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyFrogRenderer->SetupAttachment(RootComponent);
	DummyFrogRenderer->SetTexture("DummyFrog.png", true, 2.0f);
}

DummyFrog::~DummyFrog()
{
}

void DummyFrog::BeginPlay()
{
	AActor::BeginPlay();
}

void DummyFrog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummyFrog::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummyFrog::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}