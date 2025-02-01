#include "PreCompile.h"
#include "Jelly.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Jelly::Jelly()
{
	SpawnTypeValue = ESpawnType::MJelly;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	JellyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	JellyRenderer->SetupAttachment(RootComponent);
	//JellyRenderer->CreateAnimation("Jelly_Fly", "Jelly", 0, 3, 0.1f);
	//JellyRenderer->ChangeAnimation("Jelly_Fly");
	JellyRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
}

Jelly::~Jelly()
{
}

void Jelly::BeginPlay()
{
	AActor::BeginPlay();
}

void Jelly::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Jelly::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Jelly::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}