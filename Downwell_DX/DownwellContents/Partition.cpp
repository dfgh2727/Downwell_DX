#include "PreCompile.h"
#include "Partition.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/Collision.h>

Partition::Partition()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// �������� �����.
	PartitionRenderer = CreateDefaultSubObject<USpriteRenderer>();
	PartitionRenderer->SetupAttachment(RootComponent);
	PartitionRenderer->SetTexture("Partition.png", true, 2.0f);
}

Partition::~Partition()
{
}

void Partition::BeginPlay()
{
	AActor::BeginPlay();
}

void Partition::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

}