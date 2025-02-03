#include "PreCompile.h"
#include "Cartridge.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/TimeEventComponent.h>

Cartridge::Cartridge()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// 랜더러를 만든다.
	CartridgeRenderer = CreateDefaultSubObject<USpriteRenderer>();
	CartridgeRenderer->SetupAttachment(RootComponent);
	CartridgeRenderer->CreateAnimation("Cartridge", "Cartridge", 0, 7, 0.1f);
	CartridgeRenderer->ChangeAnimation("Cartridge");
	CartridgeRenderer->SetAutoScaleRatio(2.0f);

	TimeEventComponent = CreateDefaultSubObject<UTimeEventComponent>();
}

Cartridge::~Cartridge()
{
}

void Cartridge::BeginPlay()
{
	AActor::BeginPlay();
}

void Cartridge::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	AddActorLocation(FVector{ 20.0f, 10.0f, 0.0f } * _DeltaTime);

	Timer -= _DeltaTime;

	if (Timer < 0.0f)
	{
		Destroy(0);
	}
}