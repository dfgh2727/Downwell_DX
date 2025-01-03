#pragma once
#include <EngineCore/Actor.h>

// ���� :
class OpeningScene : public AActor
{
public:
	// constrcuter destructer
	OpeningScene();
	~OpeningScene();

	// delete Function
	OpeningScene(const OpeningScene& _Other) = delete;
	OpeningScene(OpeningScene&& _Other) noexcept = delete;
	OpeningScene& operator=(const OpeningScene& _Other) = delete;
	OpeningScene& operator=(OpeningScene&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:

private:

};

