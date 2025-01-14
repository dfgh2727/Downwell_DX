#include "PreCompile.h"
#include "MapEditorMode.h"
#include <EngineCore/CameraActor.h>
#include <EngineCore/DefaultSceneComponent.h>
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/TileMapRenderer.h>
#include <EngineCore/EngineGUIWindow.h>
#include <EngineCore/EngineGUI.h>
#include <EngineCore/imgui.h>
#include <EngineCore/EngineCamera.h>
#include "ContentsEditorGUI.h"
#include <EnginePlatform/EngineInput.h>

enum class EditMode
{
	TileMapMode,
};

class TileMapEditor : public UEngineGUIWindow
{
public:
	/*int SelectItem = 0;
	int ObjectItem = -1;*/
	UTileMapRenderer* TileMapRenderer = nullptr;
	EditMode Mode = EditMode::TileMapMode;

	int TileCountX = 10;
	int TileCountY = 10;
	int SelectTileIndex = 0;
	FVector TileSize = { 32.0f, 32.0f };

	void TileMapMode()
	{
		{
			UEngineSprite* Sprite = TileMapRenderer->GetSprite();

			{
				FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();
				if (ScreenPos.X < 0.0f)
				{
					ScreenPos.X = ScreenPos.X -TileSize.X * 0.5f;
				}
		
				if (ScreenPos.Y < 0.0f)
				{
					ScreenPos.Y = ScreenPos.Y -TileSize.X * 0.5f;
				}

				FVector CScreenPos = ScreenPos / TileSize;
		
				if (ScreenPos.X < 0.0f)
				{
					CScreenPos.X = roundf(CScreenPos.X);
				}
		
				if (ScreenPos.Y < 0.0f)
				{
					CScreenPos.Y = roundf(CScreenPos.Y);
				}

				ImGui::Text("ScreenPos %s", ScreenPos.ToString().c_str());

				ImGui::Text("TilePos %s ", CScreenPos.ToString().c_str());

				ImGui::Text("Index %s %s", std::to_string(CScreenPos.iX()).c_str(), std::to_string(CScreenPos.iY()).c_str());
	
			}

			for (size_t i = 0; i < Sprite->GetSpriteCount(); i++)
			{
				UEngineTexture* Texture = Sprite->GetTexture(i);
				FSpriteData Data = Sprite->GetSpriteData(i);

				//SRV입니다
				ImTextureID SRV = reinterpret_cast<ImTextureID>(Texture->GetSRV());

				std::string Text = std::to_string(i);

				if (i != 0)
				{
					if (0 != (i % 10))
					{
						ImGui::SameLine();
					}
				}


				ImVec2 Pos = { Data.CuttingPos.X, Data.CuttingPos.Y };
				ImVec2 Size = { Data.CuttingPos.X + Data.CuttingSize.X, Data.CuttingPos.Y + Data.CuttingSize.Y };

				if (ImGui::ImageButton(Text.c_str(), SRV, { 60, 60 }, Pos, Size))
				{
					SelectTileIndex = static_cast<int>(i);
				}
				// 엔터를 치지 않는개념.
			}


			ImGui::InputInt("TileMapX", &TileCountX);
			ImGui::InputInt("TileMapY", &TileCountY);

			if (ImGui::Button("TileMap Create"))
			{
				for (int y = 0; y < TileCountY; y++)
				{
					for (int x = 0; x < TileCountX; x++)
					{
						TileMapRenderer->SetTile(x, y, SelectTileIndex);
					}
				}
			}


			if (true == UEngineInput::IsPress(VK_LBUTTON))
			{
				FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();

				TileMapRenderer->SetTile(ScreenPos, SelectTileIndex);
			}

			if (true == UEngineInput::IsPress(VK_RBUTTON))
			{
				FVector ScreenPos = GetWorld()->GetMainCamera()->ScreenMousePosToWorldPos();

				TileMapRenderer->RemoveTile(ScreenPos);
			}
		}
	}

	void SaveAndLoad()
	{

		if (true == ImGui::Button("Save"))
		{
			UEngineDirectory Dir;
			if (false == Dir.MoveParentToDirectory("ContentsResources"))
			{
				MSGASSERT("리소스 폴더를 찾지 못했습니다.");
				return;
			}
			Dir.Append("Data");
			std::string InitPath = Dir.GetPathToString();

			OPENFILENAME ofn;       // common dialog box structure
			char szFile[260] = { 0 };       // if using TCHAR macros
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = nullptr;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = ("All\0*.*\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrDefExt = "MapData";
			ofn.lpstrInitialDir = InitPath.c_str();
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetSaveFileNameA(&ofn) == TRUE)
			{
				UEngineSerializer Ser;

				TileMapRenderer->Serialize(Ser);

				UEngineFile NewFile = Dir.GetFile(ofn.lpstrFile);
				NewFile.FileOpen("wb");
				NewFile.Write(Ser);
			}
		}

		if (true == ImGui::Button("Load"))
		{
			UEngineDirectory Dir;
			if (false == Dir.MoveParentToDirectory("ContentsResources"))
			{
				MSGASSERT("리소스 폴더를 찾지 못했습니다.");
				return;
			}
			Dir.Append("Data");
			std::string InitPath = Dir.GetPathToString();

			OPENFILENAME ofn;       // common dialog box structure
			char szFile[260] = { 0 };       // if using TCHAR macros
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = nullptr;
			ofn.lpstrFile = szFile;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = ("All\0*.*\0Text\0*.MapData\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = InitPath.c_str();
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileNameA(&ofn) == TRUE)
			{
				UEngineFile NewFile = Dir.GetFile(ofn.lpstrFile);
				UEngineSerializer Ser;

				NewFile.FileOpen("rb");
				NewFile.Read(Ser);

				TileMapRenderer->DeSerialize(Ser);

			}
		}
	}

	void OnGUI() override
	{
		if (ImGui::Button("TileMapMode"))
		{
			Mode = EditMode::TileMapMode;
		}

		switch (Mode)
		{
		case EditMode::TileMapMode:
			TileMapMode();
			break;
		default:
			break;
		}

		SaveAndLoad();
	}
};

MapEditorMode::MapEditorMode()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;


	//PivotSpriteRenderer = CreateDefaultSubObject<USpriteRenderer>();
	//PivotSpriteRenderer->SetupAttachment(RootComponent);
	//PivotSpriteRenderer->SetRelativeScale3D({ 50.0f, 50.0f, 1.0f });

	RenderTileMap = CreateDefaultSubObject<UTileMapRenderer>();
	RenderTileMap->SetupAttachment(RootComponent);
	RenderTileMap->SetTileSetting(ETileMapType::Rect, "Tile", TileSize, TileSize, TilePivot);
	RenderTileMap->SetTile(0, 0, 0);

}

MapEditorMode::~MapEditorMode()
{
	
}

void MapEditorMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
}

void MapEditorMode::LevelChangeStart()
{
	UEngineGUI::AllWindowOff();

	{
		std::shared_ptr<UContentsEditorGUI> Window = UEngineGUI::FindGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");

		if (nullptr == Window)
		{
			Window = UEngineGUI::CreateGUIWindow<UContentsEditorGUI>("ContentsEditorGUI");
		}

		Window->SetActive(true);
	}

	{
		TileMapWindow = UEngineGUI::FindGUIWindow<TileMapEditor>("TileMapEditor");

		if (nullptr == TileMapWindow)
		{
			TileMapWindow = UEngineGUI::CreateGUIWindow<TileMapEditor>("TileMapEditor");
		}

		TileMapWindow->SetActive(true);
		TileMapWindow->TileMapRenderer = RenderTileMap.get();
	}

}