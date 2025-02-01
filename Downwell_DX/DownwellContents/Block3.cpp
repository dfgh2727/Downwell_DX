#include "PreCompile.h"
#include "Block3.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Block3::Block3()
{
	SpawnTypeValue = ESpawnType::SBlock3;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Block3Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Block3Renderer->SetupAttachment(RootComponent);
	Block3Renderer->SetTexture("Block3.png", true, 2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Block");
	CollisionBox->SetScale3D({ 32.0f, 32.0f });
}

Block3::~Block3()
{
}

void Block3::BeginPlay()
{
	AActor::BeginPlay();
}

void Block3::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}