#include "PreCompile.h"
#include "BulletCounter.h"
//#include <EngineCore/DefaultSceneComponent.h>
//#include <EngineCore/SpriteRenderer.h>
#include "DWInstance.h"
#include "Counter.h"
#include "Bat.h"


BulletCounter::BulletCounter()
{

	/*std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;*/

	CountBullet = GetWorld()->SpawnActor<Counter>();
	CountBullet->SetTextSpriteName("BoldNum");

	//TestBat = GetWorld()->SpawnActor<Bat>();

	/*TempRenderer = CreateDefaultSubObject<USpriteRenderer>();
	TempRenderer->SetupAttachment(RootComponent);
	TempRenderer->SetTexture("Test.png", true, 1.0f);
	TempRenderer->SetWorldLocation({ 0.0f, 0.0f, 0.0f });*/
}

BulletCounter::~BulletCounter()
{
}

void BulletCounter::BeginPlay()
{
	AActor::BeginPlay();
	Num = GetGameInstance<DWInstance>()->BulletCount;
}

void BulletCounter::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	CountBullet->SetValue(Num);

	int a = 0;
}