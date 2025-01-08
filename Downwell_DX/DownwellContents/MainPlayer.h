#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class MainPlayer: public AActor
{
public:
	// constrcuter destructer
	MainPlayer();
	~MainPlayer();

	// delete Function
	MainPlayer(const MainPlayer& _Other) = delete;
	MainPlayer(MainPlayer&& _Other) noexcept = delete;
	MainPlayer& operator=(const MainPlayer& _Other) = delete;
	MainPlayer& operator=(MainPlayer&& _Other) noexcept = delete;

	//std::shared_ptr<class USpriteRenderer> GetRenderer()
	//{
	//	return PlayerRenderer;
	//}

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> PlayerRenderer;
};

