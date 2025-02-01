#include "PreCompile.h"
#include "Frog.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Frog::Frog()
{
	SpawnTypeValue = ESpawnType::MFrog;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	FrogRenderer = CreateDefaultSubObject<USpriteRenderer>();
	FrogRenderer->SetupAttachment(RootComponent);
	//FrogRenderer->CreateAnimation("Frog_Fly", "Frog", 0, 3, 0.1f);
	//FrogRenderer->ChangeAnimation("Frog_Fly");
	FrogRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
}

Frog::~Frog()
{
}

void Frog::BeginPlay()
{
	AActor::BeginPlay();
}

void Frog::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Frog::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Frog::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}