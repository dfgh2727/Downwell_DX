#include "PreCompile.h"
#include "Snake.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Snake::Snake()
{
	SpawnTypeValue = ESpawnType::MSnake;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	SnakeRenderer = CreateDefaultSubObject<USpriteRenderer>();
	SnakeRenderer->SetupAttachment(RootComponent);
	//SnakeRenderer->CreateAnimation("Snake_Fly", "Snake", 0, 3, 0.1f);
	//SnakeRenderer->ChangeAnimation("Snake_Fly");
	SnakeRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject< UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Monster");
	CollisionBox->SetScale3D({ 25.0f, 20.0f });
}

Snake::~Snake()
{
}

void Snake::BeginPlay()
{
	AActor::BeginPlay();
}

void Snake::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void Snake::Serialize(UEngineSerializer& _Ser)
{
	_Ser << GetActorLocation();
	//_Ser << std::string("Test.png");
	//_Ser << FVector(50.0f, 50.0f);
}


void Snake::DeSerialize(UEngineSerializer& _Ser)
{
	FVector SavePos;
	_Ser >> SavePos;
	SetActorLocation(SavePos);

}