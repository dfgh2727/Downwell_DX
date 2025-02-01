#include "PreCompile.h"
#include "Block2.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Block2::Block2()
{
	SpawnTypeValue = ESpawnType::SBlock2;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Block2Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Block2Renderer->SetupAttachment(RootComponent);
	Block2Renderer->SetTexture("Block2.png", true, 2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Block");
	CollisionBox->SetScale3D({ 32.0f, 32.0f });
}

Block2::~Block2()
{
}

void Block2::BeginPlay()
{
	AActor::BeginPlay();
}

void Block2::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}