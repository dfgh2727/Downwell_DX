#include "PreCompile.h"
#include "DummySnake.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

DummySnake::DummySnake()
{
	DummyTypeValue = EDummyType::DSnake;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummySnakeRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummySnakeRenderer->SetupAttachment(RootComponent);
	DummySnakeRenderer->SetTexture("DummySnake.png", true, 2.0f);
}

DummySnake::~DummySnake()
{
}

void DummySnake::BeginPlay()
{
	AActor::BeginPlay();
}

void DummySnake::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void DummySnake::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
}


void DummySnake::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}