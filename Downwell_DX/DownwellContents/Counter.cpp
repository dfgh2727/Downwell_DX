#include "PreCompile.h"
#include "Counter.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>


Counter::Counter()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	TempRenderer= CreateDefaultSubObject<USpriteRenderer>();
	TempRenderer->SetupAttachment(RootComponent);
	TempRenderer->SetTexture("Test.png", true, 10.0f);
	TempRenderer->SetWorldLocation(FVector::ZERO);

	for (size_t i = 0; i < 11; i++)
	{
		std::shared_ptr<class USpriteRenderer> Sprite = CreateDefaultSubObject<USpriteRenderer>();
		NumRenderer.push_back(Sprite);
		NumRenderer[i]->SetupAttachment(RootComponent);
	}
}

Counter::~Counter()
{
}

void Counter::BeginPlay()
{
}

void Counter::Tick(float _DeltaTime)
{

}

void Counter::SetTextSpriteName(const std::string _Text)
{
	TextSpriteName = _Text;

	for (size_t i = 0; i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetSprite(TextSpriteName);

		//NumRenderer[i]->SetAutoScaleRatio(2.0f);
	}
}

//void Counter::SetOrder(int _Order)
//{
//	for (size_t i = 0; i < NumRenderer.size(); i++)
//	{
//		NumRenderer[i]->SetOrder(_Order);
//	}
//
//}

void Counter::SetValue(int _Score)
{
	std::string Number = std::to_string(_Score);

	if (NumRenderer.size() <= Number.size())
	{
		MSGASSERT("자리수를 넘겼습니다.");
		return;
	}

	for (size_t i = 0; i < Number.size(); i++)
	{
		char Value = Number[i] - '0';
		NumRenderer[i]->SetSprite(TextSpriteName, Value);
		NumRenderer[i]->SetAutoScaleRatio(1.0f);
		NumRenderer[i]->SetActive(true);
	}

	for (size_t i = Number.size(); i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetActive(false);
	}

}



