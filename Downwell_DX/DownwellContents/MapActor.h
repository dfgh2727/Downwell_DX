#include "PreCompile.h"
#pragma once

#include <EngineCore/Actor.h>

// Ό³Έν :
class AMapActor : public AActor
{
public:
	// constrcuter destructer
	AMapActor();
	~AMapActor();

	// delete Function
	AMapActor(const AMapActor& _Other) = delete;
	AMapActor(AMapActor&& _Other) noexcept = delete;
	AMapActor& operator=(const AMapActor& _Other) = delete;
	AMapActor& operator=(AMapActor&& _Other) noexcept = delete;

	void LoadColImage();
	// void SetMapImage(std::string_view _MapImageName);
	class UEngineWinImage* GetColImage(std::string_view _ColImageName);
	
	class UEngineWinImage* ColImage = nullptr;

protected:
	class UEngineWinImage* MapImage = nullptr;

private:
};

