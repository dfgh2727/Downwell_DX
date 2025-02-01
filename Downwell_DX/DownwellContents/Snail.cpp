#include "PreCompile.h"
#include "Snail.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Snail::Snail()
{
	SpawnTypeValue = ESpawnType::MSnail;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	SnailRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SnailRenderer->SetupAttachment(RootComponent);
	//SnailRenderer->CreateAnimation("Snail_Fly", "Snail", 0, 3, 0.1f);
	//SnailRenderer->ChangeAnimation("Snail_Fly");
	SnailRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
}

Snail::~Snail()
{
}

void Snail::BeginPlay()
{
	AActor::BeginPlay();
}

void Snail::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Snail::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Snail::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}