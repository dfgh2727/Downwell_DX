#include "PreCompile.h"
#include "Counter.h"
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>


Counter::Counter()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	MinusRenderer = CreateDefaultSubObject<USpriteRenderer>();
	MinusRenderer->SetupAttachment(RootComponent);
	MinusRenderer->SetSprite("CMnumMinus.png");

	for (size_t i = 0; i < 12; i++)
	{
		// 카메라가 움직여도 이녀석은 움직이지 않는다.
		/*USpriteRenderer* Sprite = CreateDefaultSubObject<USpriteRenderer>();
		Sprite->SetCameraEffect(false);*/
		//NumRenderer.push_back(Sprite);
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
	}
}

void Counter::SetOrder(int _Order)
{
	for (size_t i = 0; i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetOrder(_Order);
	}

}

void Counter::SetValue(int _Score)
{
	std::string Number = std::to_string(_Score);

	if (NumRenderer.size() <= Number.size())
	{
		MSGASSERT("자리수를 넘겼습니다.");
		return;
	}


	FVector Pos = FVector::ZERO;

	for (size_t i = 0; i < Number.size(); i++)
	{
		char Value = Number[i] - '0';
		NumRenderer[i]->SetSprite(TextSpriteName, Value);
		NumRenderer[i]->SetComponentScale(TextScale);
		NumRenderer[i]->SetComponentLocation(Pos);
		Pos.X += TextScale.X;
		NumRenderer[i]->SetActive(true);
	}

	MinusRenderer->SetComponentLocation({ -TextScale.X, 0.0f});

	for (size_t i = Number.size(); i < NumRenderer.size(); i++)
	{
		NumRenderer[i]->SetActive(false);
	}

}

void Counter::ShowMinus()
{
	MinusRenderer->SetOrder(ERenderOrder::UI);
	MinusRenderer->SetComponentScale({ 25, 50 });
}

