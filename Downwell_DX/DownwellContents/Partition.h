#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class Partition : public AActor
{
public:
	// constrcuter destructer
	Partition();
	~Partition();

	// delete Function
	Partition(const Partition& _Other) = delete;
	Partition(Partition&& _Other) noexcept = delete;
	Partition& operator=(const Partition& _Other) = delete;
	Partition& operator=(Partition&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	std::shared_ptr<class USpriteRenderer> PartitionRenderer;

};

