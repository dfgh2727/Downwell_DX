#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>
#include "FSMStateManager.h"

// Ό³Έν :
enum class MainPlayerState
{
	Idle,
	Run,
	Jump,
	Shoot,

};

class MainPlayer: public AActor//APawn
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

	void SetTileMapRenderer(class UTileMapRenderer* _Renderer)
	{
		TRenderer = _Renderer;
	}

	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Shoot(float _DeltaTime);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> PlayerRenderer = nullptr;
	std::shared_ptr<class UCollision> CollisionBox = nullptr;
	class UTileMapRenderer* TRenderer = nullptr;
	class FTileData* TData = nullptr;

	FVector GForce = FVector::DOWN * 200.0f;
	FVector Gravity = FVector::ZERO;

	FVector PrevLocation = FVector::ZERO;
	UFSMStateManager FSM;

	bool IsOnTheGround = false;
};

