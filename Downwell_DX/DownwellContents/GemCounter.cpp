#include "PreCompile.h"
#include "GemCounter.h"
#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/SpriteRenderer.h>
#include "DWInstance.h"
#include "Counter.h"
#include "Bat.h"


GemCounter::GemCounter()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	CountGem = GetWorld()->SpawnActor<Counter>();
	CountGem->SetTextSpriteName("BoldNum");
	CountGem->Ratio = 1.15f;
}

GemCounter::~GemCounter()
{
}

void GemCounter::BeginPlay()
{
	AActor::BeginPlay();
}

void GemCounter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	Num = GetGameInstance<DWInstance>()->GemCount;
	CountGem->SetValue(Num);
	
	FVector CurPos = GetActorLocation();
	CountGem->SetActorLocation(CurPos);
	int a = 0;
}