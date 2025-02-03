#include "PreCompile.h"
#include "Well.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Well::Well()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	WellRenderer = CreateDefaultSubObject<USpriteRenderer>();
	WellRenderer->SetupAttachment(RootComponent);
	WellRenderer->SetTexture("Well.png", true, 2.0f);

	CollisionBox1 = CreateDefaultSubObject<UCollision>();
	CollisionBox1->SetupAttachment(RootComponent);
	CollisionBox1->SetCollisionProfileName("Block");
	CollisionBox1->SetScale3D({ 96.0f, 160.0f });
	CollisionBox1->SetRelativeLocation({ -118.0f, 0.0f, 0.0f });

	CollisionBox2 = CreateDefaultSubObject<UCollision>();
	CollisionBox2->SetupAttachment(RootComponent);
	CollisionBox2->SetCollisionProfileName("Block");
	CollisionBox2->SetScale3D({ 96.0f, 160.0f });
	CollisionBox2->SetRelativeLocation({ 118.0f, 0.0f, 0.0f });

	CollisionBox3 = CreateDefaultSubObject<UCollision>();
	CollisionBox3->SetupAttachment(RootComponent);
	CollisionBox3->SetCollisionProfileName("Block");
	CollisionBox3->SetScale3D({ 54.0f, 48.0f });
	CollisionBox3->SetRelativeLocation({ -100.0f, 96.0f, 0.0f });

	CollisionBox4 = CreateDefaultSubObject<UCollision>();
	CollisionBox4->SetupAttachment(RootComponent);
	CollisionBox4->SetCollisionProfileName("Block");
	CollisionBox4->SetScale3D({ 54.0f, 48.0f });
	CollisionBox4->SetRelativeLocation({ 100.0f, 96.0f, 0.0f });
}

Well::~Well()
{
}

void Well::BeginPlay()
{
	AActor::BeginPlay();
}

void Well::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}