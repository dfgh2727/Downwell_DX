#include "PreCompile.h"
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Dummy::Dummy()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DummyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyRenderer->SetupAttachment(RootComponent);
	DummyRenderer->SetAutoScaleRatio(2.0f);

}

Dummy::~Dummy()
{
}

void Dummy::Serialize(UEngineSerializer& _Ser)
{
	_Ser << static_cast<int>(MonsterTypeValue);
	_Ser << GetActorLocation();
}


void Dummy::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	int MonsterType = -1;
	_Ser >> MonsterType;
	_Ser >> SavePos;
	MonsterTypeValue = static_cast<EMonsterType>(MonsterType);
	SetActorLocation(SavePos);

}