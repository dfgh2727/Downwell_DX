#include "PreCompile.h"
#include "NormalBullet.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TileMapRenderer.h>

NormalBullet::NormalBullet()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	NormalBulletRenderer = CreateDefaultSubObject<USpriteRenderer>();
	NormalBulletRenderer->SetupAttachment(RootComponent);
	NormalBulletRenderer->CreateAnimation("Bullet", "Bullet", 0, 5, 0.08f, false);
	NormalBulletRenderer->CreateAnimation("BulletHitTheWall", "BulletHitTheWall", 0, 7, 0.08f, false);
	NormalBulletRenderer->ChangeAnimation("Bullet");
	NormalBulletRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Bullet");
	CollisionBox->SetScale3D({ 8.0f, 12.0f });

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

NormalBullet::~NormalBullet()
{
}

void NormalBullet::BeginPlay()
{
	AActor::BeginPlay();
}

void NormalBullet::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	AddActorLocation(Velocity * _DeltaTime);
	//Break();

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy();
	}

	if (nullptr != TRenderer)
	{
		TData = TRenderer->GetTile(GetActorLocation() + FVector::DOWN * 500.0f * _DeltaTime);
		
		if (nullptr != TData)
		{
			Velocity = FVector::ZERO;
			NormalBulletRenderer->ChangeAnimation("BulletHitTheWall");
		}
	}
}

void NormalBullet::Break()
{
	std::vector<UCollision*> BlockCollision;
	if (true == CollisionBox->CollisionCheck("Block",BlockCollision))
	{
		Destroy();
	}
}