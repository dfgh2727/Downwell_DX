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
	Fall,
	Spin,

};

class MainPlayer : public AActor//APawn
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

	void SetTileMapRenderer(class UTileMapRenderer* _Renderer)
	{
		TRenderer = _Renderer;
	}

	UTileMapRenderer* GetTileMapRenderer()
	{
		return TRenderer;
	}


	bool TileCheck(FVector _AddPos);
	void GravityManager(float _DeltaTime);

	bool IsShooting = false;

	void Idle(float _DeltaTime);
	void Run(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Shoot(float _DeltaTime);
	void Fall(float _DeltaTime);

	void CollisionLR(float _DeltaTime);
	void BulletManager();

	void SynchBullet();
	void CheckDirection();


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> PlayerRenderer = nullptr;

	std::shared_ptr<class UCollision> CollisionBox = nullptr;
	std::shared_ptr<class NormalBullet> NBullet = nullptr;
	std::shared_ptr<class GunShotSmoke> Smoke = nullptr;
	std::shared_ptr<class EmptyText> TXT1 = nullptr;
	
	//std::shared_ptr<class BulletCounter> BulletNum = nullptr;

	class UTileMapRenderer* TRenderer = nullptr;
	struct FTileData* TData = nullptr;
	std::shared_ptr<class UTimeEventComponent> TimeEventComponent;

	std::shared_ptr<class Cartridge> TempCart = nullptr;

	FVector GForce = FVector::DOWN * 300.0f;
	FVector Gravity = FVector::ZERO;

	FVector PrevLocation = FVector::ZERO;
	UFSMStateManager FSM;

	bool IsTile = false;
	bool IsOnTheGround = false;
	//bool IsOnTheBlock = false;

	bool ShowOnce = true;

	float LRVelocity = 100.0f;
	float MoveDir = 1.0f;

	float Timer = 0.2f;
	FVector MoveVect = FVector::ZERO;

	std::string DirString = "R";

	int Pistol = 0;
};

