#include "PreCompile.h"
#include "Block0.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

#include "Debris.h"
#include "Flash.h"
#include "SmokeBall.h"

Block0::Block0()
{
	SpawnTypeValue = ESpawnType::SBlock0;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Block0Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Block0Renderer->SetupAttachment(RootComponent);
	Block0Renderer->SetTexture("Block0.png", true, 2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Block");
	CollisionBox->SetScale3D({ 32.0f, 32.0f });
}

Block0::~Block0()
{
}

void Block0::BeginPlay()
{
	AActor::BeginPlay();
	CurLocation = GetActorLocation();
}

void Block0::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	Break();
}

void Block0::Break()
{
	std::vector<UCollision*> BulletCollision;
	if (true == CollisionBox->CollisionCheck("Bullet", BulletCollision))
	{
		
		FlashForBlock = GetWorld()->SpawnActor<Flash>();
		FlashForBlock->SetActorLocation(CurLocation);

		Debris1 = GetWorld()->SpawnActor<Debris>();
		Debris1->SetActorLocation(CurLocation);

		Debris2 = GetWorld()->SpawnActor<Debris>();
		Debris2->SetActorLocation(CurLocation);

		SmokeBall1 = GetWorld()->SpawnActor<SmokeBall>();
		SmokeBall1->SetActorLocation(CurLocation);

		SmokeBall2 = GetWorld()->SpawnActor<SmokeBall>();
		SmokeBall2->SetActorLocation(CurLocation);

		Destroy();
	}
}