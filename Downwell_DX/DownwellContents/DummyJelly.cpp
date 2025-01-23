#include "PreCompile.h"
#include "DummyJelly.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummyJelly::DummyJelly()
{
	DummyTypeValue = EDummyType::DJelly;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummyJellyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyJellyRenderer->SetupAttachment(RootComponent);
	DummyJellyRenderer->SetTexture("DummyJelly.png", true, 2.0f);
}

DummyJelly::~DummyJelly()
{
}

void DummyJelly::BeginPlay()
{
	AActor::BeginPlay();
}

void DummyJelly::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummyJelly::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummyJelly::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}