#include "PreCompile.h"
#include "ContentsEditorGUI.h"
#include "EngineCore/EngineCore.h"
#include "EngineCore/EngineGUI.h"
#include "EngineCore/CameraActor.h"

UContentsEditorGUI::UContentsEditorGUI()
{
}

UContentsEditorGUI::~UContentsEditorGUI()
{
}

void UContentsEditorGUI::OnGUI()
{
	std::map<std::string, std::shared_ptr<class ULevel>> Map = UEngineCore::GetAllLevelMap();

	for (std::pair<const std::string, std::shared_ptr<class ULevel>>& Pair : Map)
	{

		if (ImGui::Button(Pair.first.c_str()))
		{
			UEngineCore::OpenLevel(Pair.first);
		}
	}

	{
		FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
		if (ScreenPos.X < 0.0f)
		{
			ScreenPos.X = ScreenPos.X + -50.0f;
		}
		if (ScreenPos.Y < 0.0f)
		{
			ScreenPos.Y = ScreenPos.Y + -50.0f;
		}

		/*FVector CScreenPos = ScreenPos / 100.0f;

		if (ScreenPos.X < 0.0f)
		{
			CScreenPos.X = roundf(CScreenPos.X);
		}
		if (ScreenPos.Y < 0.0f)
		{
			CScreenPos.Y = roundf(CScreenPos.Y);
		}*/


		ImGui::Text("ScreenPos %s", ScreenPos.ToString().c_str());

		//ImGui::Text("TilePos %s ", CScreenPos.ToString().c_str());

		//ImGui::Text("Index %s %s", std::to_string(CScreenPos.iX()).c_str(), std::to_string(CScreenPos.iY()).c_str());

	}
}




