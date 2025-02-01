#include "PreCompile.h"
#include "Bat.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Bat::Bat()
{
	SpawnTypeValue = ESpawnType::MBat;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	BatRenderer = CreateDefaultSubObject<USpriteRenderer>();
	BatRenderer->SetupAttachment(RootComponent);
	BatRenderer->CreateAnimation("Bat_Fly", "Bat", 0, 3, 0.1f);
	BatRenderer->ChangeAnimation("Bat_Fly");
	BatRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
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