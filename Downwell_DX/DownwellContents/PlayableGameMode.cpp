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
		MSGASSERT("���ҽ� ������ ã�� ���߽��ϴ�.");
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
		MSGASSERT("���ڿ� Collision Map�� ���� �ʰ��Ͽ� �Է��߽��ϴ�.");
		return;
	}

	return ColMapImage[_ColMapIndex];
}
