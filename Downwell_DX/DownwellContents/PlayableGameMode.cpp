#include "PreCompile.h"
#include "PlayableGameMode.h"

#include <EngineCore/SpriteRenderer.h>
#include <EnginePlatform/EngineWinImage.h>




APlayableGameMode::APlayableGameMode()
{	
	
}

APlayableGameMode::~APlayableGameMode()
{
}

void APlayableGameMode::LoadColImage(std::string_view _ColMapName)
{
	UEngineDirectory Dir;
	if (false == Dir.MoveParentToDirectory("ContentsResources"))
	{
		MSGASSERT("리소스 폴더를 찾지 못했습니다.");
		return;
	}
	Dir.Append("ColMapFolder");
	ColMapFile = Dir.GetAllFile(true, { ".png" });
	ColMapImage.resize(ColMapFile.size());

	for (int i = 0; i < ColMapFile.size(); i++)
	{
		ColMapImage[i].Load(nullptr, ColMapFile[i].GetPathToString());
	}
}

UEngineWinImage APlayableGameMode::GetColImage(int _ColMapIndex)
{
	if (ColMapImage.size() < _ColMapIndex)
	{
		MSGASSERT("인자에 Collision Map의 수를 초과하여 입력했습니다.");
		return;
	}

	return ColMapImage[_ColMapIndex];
}
