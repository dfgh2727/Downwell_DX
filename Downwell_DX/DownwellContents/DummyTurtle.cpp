#include "PreCompile.h"
#include "DummyTurtle.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummyTurtle::DummyTurtle()
{
	DummyTypeValue = EDummyType::DTurtle;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummyTurtleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyTurtleRenderer->SetupAttachment(RootComponent);
	DummyTurtleRenderer->SetTexture("DTurtle.png", true, 2.0f);
}

DummyTurtle::~DummyTurtle()
{
}

void DummyTurtle::BeginPlay()
{
	AActor::BeginPlay();
}

void DummyTurtle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummyTurtle::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummyTurtle::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}