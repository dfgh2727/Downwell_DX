#pragma once
#include "SpawnedActor.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class Crawler : public SpawnedActor
{
public:
	// constrcuter destructer
	Crawler();
	~Crawler();

	// delete Function
	Crawler(const Crawler& _Other) = delete;
	Crawler(Crawler&& _Other) noexcept = delete;
	Crawler& operator=(const Crawler& _Other) = delete;
	Crawler& operator=(Crawler&& _Other) noexcept = delete;
	
	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:
	std::shared_ptr<class USpriteRenderer> CrawlerRenderer;
	std::shared_ptr<class UCollision> CollisionBox;

	
};

