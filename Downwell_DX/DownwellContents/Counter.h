#pragma once
#include <vector>
#include <EngineCore/Actor.h>

// Ό³Έν :
class Counter : public AActor
{
public:
	// constrcuter destructer
	Counter();
	~Counter();

	// delete Function
	Counter(const Counter& _Other) = delete;
	Counter(Counter&& _Other) noexcept = delete;
	Counter& operator=(const Counter& _Other) = delete;
	Counter& operator=(Counter&& _Other) noexcept = delete;

	void SetTextSpriteName(const std::string _Text);

	/*void SetTextScale(FVector _TextScale)
	{
		TextScale = _TextScale;
	}*/

	/*template<typename EnumType>
	void SetOrder(EnumType _Order)
	{
		SetOrder(static_cast<int>(_Order));
	}*/

	//void SetOrder(int _Order);

	void SetValue(int _Score);

	//void ShowMinus();


protected:

	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

	std::string TextSpriteName;
	//FVector TextScale;
	//std::shared_ptr<class USpriteRenderer> MinusRenderer;
	std::vector<std::shared_ptr<class USpriteRenderer>> NumRenderer;

};

