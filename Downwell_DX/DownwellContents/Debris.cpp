#include "PreCompile.h"
#include "Debris.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>
#include <EngineCore/Collision.h>
#include <EngineCore/TileMapRenderer.h>

Debris::Debris()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	DebrisRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DebrisRenderer->SetupAttachment(RootComponent);
	DebrisRenderer->CreateAnimation("Debris", "Debris", 0, 3, 0.08f, false);
	DebrisRenderer->ChangeAnimation("Debris");
	DebrisRenderer->SetAutoScaleRatio(2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Debris");
	CollisionBox->SetScale3D({ 15.0f, 15.0f });

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

Debris::~Debris()
{
}

void Debris::BeginPlay()
{
	AActor::BeginPlay();

	Velocity.X = UEngineRandomInst.Randomfloat(-100.0f, 100.0f);
	Velocity.Y = UEngineRandomInst.Randomfloat(-50.0f, 0.0f);
}

void Debris::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	GravityManager(_DeltaTime);
	//BlockCheck();

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy();
	}

	AddActorLocation(Velocity * _DeltaTime);
}

bool Debris::TileCheck(FVector _AddPos)
{
	if (nullptr != TRenderer)
	{
		TData = TRenderer->GetTile(GetActorLocation() + _AddPos);

		if (nullptr != TData)
		{
			IsTile = true;
		}
		else
		{
			IsTile = false;
		}
		return IsTile;
	}
}

void Debris::GravityManager(float _DeltaTime)
{
	IsOnTheGround = TileCheck(Gravity * _DeltaTime);
	bool IsOnTheBlock = false;

	std::vector<UCollision*> BlockCollision;
	if (true == CollisionBox->CollisionCheck("Block", Gravity * _DeltaTime, BlockCollision))
	{
		IsOnTheBlock = true;
		//IsOnTheGround = true;
	}

	if (true == IsOnTheBlock)
	{
		IsOnTheGround = true;
	}

	if (true == IsOnTheGround)
	{
		Gravity = FVector::ZERO;
		SetActorLocation(PrevLocation);
	}
	else
	{
		AddActorLocation(Gravity * _DeltaTime);
		PrevLocation = GetActorLocation();
		Gravity += GForce * _DeltaTime;
	}
}
