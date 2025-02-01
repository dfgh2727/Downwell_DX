#include "PreCompile.h"
#include "Block1.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Block1::Block1()
{
	SpawnTypeValue = ESpawnType::SBlock1;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Block1Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Block1Renderer->SetupAttachment(RootComponent);
	Block1Renderer->SetTexture("Block01.png", true, 2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetScale3D({ 32.0f, 32.0f });
}

Block1::~Block1()
{
}

void Block1::BeginPlay()
{
	AActor::BeginPlay();
}

void Block1::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}