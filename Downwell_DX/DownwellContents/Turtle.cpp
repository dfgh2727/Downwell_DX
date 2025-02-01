#include "PreCompile.h"
#include "Turtle.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Turtle::Turtle()
{
	SpawnTypeValue = ESpawnType::MTurtle;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	TurtleRenderer = CreateDefaultSubObject<USpriteRenderer>();
	TurtleRenderer->SetupAttachment(RootComponent);
	//TurtleRenderer->CreateAnimation("Turtle_Fly", "Turtle", 0, 3, 0.1f);
	//TurtleRenderer->ChangeAnimation("Turtle_Fly");
	TurtleRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
}

Turtle::~Turtle()
{
}

void Turtle::BeginPlay()
{
	AActor::BeginPlay();
}

void Turtle::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Turtle::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Turtle::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}