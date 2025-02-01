#include "PreCompile.h"
#include "GemBlock.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

GemBlock::GemBlock()
{
	SpawnTypeValue = ESpawnType::SBlock4;

	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	GemBlockRenderer = CreateDefaultSubObject<USpriteRenderer>();
	GemBlockRenderer->SetupAttachment(RootComponent);
	GemBlockRenderer->SetTexture("Block4.png", true, 2.0f);

	CollisionBox = CreateDefaultSubObject<UCollision>();
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetCollisionProfileName("Block");
	CollisionBox->SetScale3D({ 32.0f, 32.0f });
}

GemBlock::~GemBlock()
{
}

void GemBlock::BeginPlay()
{
	AActor::BeginPlay();
}

void GemBlock::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}