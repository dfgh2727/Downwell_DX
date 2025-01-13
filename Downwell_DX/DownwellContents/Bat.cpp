#include "PreCompile.h"
#include "Bat.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/Collision.h>

Bat::Bat()
{
	MonsterTypeValue = EMonsterType::Bat1;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	BatRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BatRenderer->SetupAttachment(RootComponent);
	BatRenderer->SetTexture("Bat.png", true, 2.0f);
}

Bat::~Bat()
{
}

void Bat::BeginPlay()
{
	AActor::BeginPlay();
}

void Bat::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Bat::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Bat::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}