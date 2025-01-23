#pragma once
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>

// Ό³Έν :
class DummyCrawler : public Dummy
{
public:
	// constrcuter destructer
	DummyCrawler();
	~DummyCrawler();

	// delete Function
	DummyCrawler(const DummyCrawler& _Other) = delete;
	DummyCrawler(DummyCrawler&& _Other) noexcept = delete;
	DummyCrawler& operator=(const DummyCrawler& _Other) = delete;
	DummyCrawler& operator=(DummyCrawler&& _Other) noexcept = delete;

	void Serialize(UEngineSerializer& _Ser) override;
	void DeSerialize(UEngineSerializer& _Ser) override;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> DummyCrawlerRenderer;

	//std::shared_ptr<class UCollision> CollisionBox1;
    //std::shared_ptr<class UCollision> CollisionBox2;
    //std::shared_ptr<class UCollision> CollisionBox3;
    //std::shared_ptr<class UCollision> CollisionBox4;

};

