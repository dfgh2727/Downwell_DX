#include "PreCompile.h"
#include "Block0.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Block0::Block0()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	Block0Renderer = CreateDefaultSubObject<USpriteRenderer>();
	Block0Renderer->SetupAttachment(RootComponent);
	Block0Renderer->SetTexture("Block00.png", true, 2.0f);

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
}

void Block0::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}