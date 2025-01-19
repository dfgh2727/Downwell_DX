#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class APlayableGameMode : public AGameMode
{
public:
	// constrcuter destructer
	APlayableGameMode();
	~APlayableGameMode();

	// delete Function
	APlayableGameMode(const APlayableGameMode& _Other) = delete;
	APlayableGameMode(APlayableGameMode&& _Other) noexcept = delete;
	APlayableGameMode& operator=(const APlayableGameMode& _Other) = delete;
	APlayableGameMode& operator=(APlayableGameMode&& _Other) noexcept = delete;
	
	void LoadColImage(std::string_view _ColMapName);

	//void SetColImages(std::string_view _ColMapName);

	UEngineWinImage GetColImage(int _ColMapIndex);

protected:

private:
	
	std::vector<UEngineWinImage> ColMapImage;

	std::vector<UEngineFile> ColMapFile;

};

