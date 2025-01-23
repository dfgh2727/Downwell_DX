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

#include "ContentsEnum.h"
#include "Dummy.h"


enum class EditMode
{
	TileMapMode,
	ObjectMode,
};


class MapEditor : public UEngineGUIWindow
{
public:
	int SelectItem = 0;
	int ObjectItem = -1;
	UTileMapRenderer* TileMapRenderer = nullptr;
	EditMode Mode = EditMode::TileMapMode;

	int TileCountX = 10;
	int TileCountY = 10;
	int SelectTileIndex = 0;
	FVector TileSize = { 32.0f, 32.0f };

	void TileMapMode()
	{
		{

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

			UEngineSprite* Sprite = TileMapRenderer->GetSprite();
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
	int SelectMonsterIndex = 0;

	void ObjectMode()
	{

		std::shared_ptr<UEngineSprite> Sprite = UEngineSprite::Find<UEngineSprite>("Dummy");
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
				SelectMonsterIndex = static_cast<int>(i);
			}
		}

		{

			if (true == UEngineInput::IsDown(VK_LBUTTON))
			{
				ESpawnList SelectDummy = static_cast<ESpawnList>(SelectItem);
				std::shared_ptr<class ACameraActor> Camera = GetWorld()->GetMainCamera();
				FVector Pos = Camera->ScreenMousePosToWorldPos();
				Pos.Z = 0.0f;

				std::shared_ptr<Dummy> NewDummy = GetWorld()->SpawnActor<Dummy>("Monster");;
				NewDummy->DummyRenderer->SetSprite("Dummy", SelectMonsterIndex);
				NewDummy->MonsterTypeValue = static_cast<EMonsterType>(SelectMonsterIndex);

				//ESpawnList::SpawnBat;
				//switch (SelectDummy)
				//{
				//case ESpawnList::SpawnBat:
				//	NewDummy = GetWorld()->SpawnActor<DummyBat>("Bat");
				//	break;
				//case ESpawnList::SpawnCrawler:			
				//	NewDummy = GetWorld()->SpawnActor<DummyCrawler>("Crawler");
				//	break;
				//case ESpawnList::SpawnFrog:				
				//	NewDummy = GetWorld()->SpawnActor<DummyFrog>("Frog");
				//	break;
				//case ESpawnList::SpawnJelly:			
				//	NewDummy = GetWorld()->SpawnActor<DummyJelly>("Jelly");
				//	break;
				//case ESpawnList::SpawnSnail:			
				//	NewDummy = GetWorld()->SpawnActor<DummySnail>("Snail");
				//	break;								
				//case ESpawnList::SpawnSnake:			
				//	NewDummy = GetWorld()->SpawnActor<DummySnake>("Snake");
				//	break;								
				//case ESpawnList::SpawnTurtle:			
				//	NewDummy = GetWorld()->SpawnActor<DummyTurtle>("Turtle");
				//	break;
				//default:
				//	break;
				//}

				NewDummy->SetActorLocation(Pos);
			}
		}

		{
			if (ImGui::Button("EditObjectDelete"))
			{
				std::list<std::shared_ptr<Dummy>> AllDummyList = GetWorld()->GetAllActorListByClass<Dummy>();
				for (std::shared_ptr<Dummy> DummySpawned : AllDummyList)
				{
					DummySpawned->Destroy();
				}

			}
		}

		{
			std::vector<std::shared_ptr<Dummy>> AllDummyList = GetWorld()->GetAllActorArrayByClass<Dummy>();

			std::vector<std::string> ArrString;
			for (std::shared_ptr<class AActor> Actor : AllDummyList)
			{
				ArrString.push_back(Actor->GetName());
			}

			std::vector<const char*> Arr;
			for (size_t i = 0; i < ArrString.size(); i++)
			{
				Arr.push_back(ArrString[i].c_str());
			}


			if (0 < Arr.size())
			{
				ImGui::ListBox("AllActorList", &ObjectItem, &Arr[0], static_cast<int>(Arr.size()));

				if (ObjectItem != -1)
				{

				}

				if (true == ImGui::Button("Delete"))
				{
					AllDummyList[ObjectItem]->Destroy();
					ObjectItem = -1;
				}

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
				std::list<std::shared_ptr<Dummy>> AllDummyList = GetWorld()->GetAllActorListByClass<Dummy>();

				UEngineSerializer Ser;

				Ser << static_cast<int>(AllDummyList.size());

				for (std::shared_ptr<Dummy> Actor : AllDummyList)
				{

					Ser << static_cast<int>(Actor->MonsterTypeValue);
					Ser << Actor->GetActorLocation();
					// 여기 저장된다는 이야기
					// Actor->Serialize(Ser);
				}

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

				int DummyCount = 0;

				Ser >> DummyCount;

				for (size_t i = 0; i < DummyCount; i++)
				{
					int DummyTypeValue = 0;
					Ser >> DummyTypeValue;
					FVector Pos;
					Ser >> Pos;

					EMonsterType MonsterType = static_cast<EMonsterType>(DummyTypeValue);

					std::shared_ptr<Dummy> NewDummy = GetWorld()->SpawnActor<Dummy>();
					NewDummy->SetActorLocation(Pos);
					NewDummy->DummyRenderer->SetSprite("Dummy", DummyTypeValue);

					//NewDummy->DeSerialize(Ser);
				}
				TileMapRenderer->DeSerialize(Ser);

			}
		}
	}

	void OnGUI() override
	{
		{
			if (Mode == EditMode::ObjectMode)
			{
				if (ImGui::Button("TileMapMode"))
				{
					Mode = EditMode::TileMapMode;
				}
			}
			else
			{
				if (ImGui::Button("ObjectMode"))
				{
					Mode = EditMode::ObjectMode;
				}
			}
		}

		switch (Mode)
		{
		case EditMode::TileMapMode:
			TileMapMode();
			break;
		case EditMode::ObjectMode:
			ObjectMode();
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


	RenderTileMap = CreateDefaultSubObject<UTileMapRenderer>();
	RenderTileMap->SetupAttachment(RootComponent);
	RenderTileMap->SetTileSetting(ETileMapType::Rect, "Tile", TileSize, TileSize, TilePivot);	

	std::shared_ptr<ACameraActor> Camera = GetWorld()->GetMainCamera();
	Camera->SetActorLocation({ 0.0f, 0.0f, -1000.0f, 1.0f });
	Camera->GetCameraComponent()->SetZSort(0, true);

	//GetWorld()->CreateCollisionProfile("Monster");
}

MapEditorMode::~MapEditorMode()
{
	
}

void MapEditorMode::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (UEngineInput::IsPress('W'))
	{
		GetWorld()->GetMainCamera()->AddActorLocation(FVector::UP * 300.0f * _DeltaTime);
	}
	if (UEngineInput::IsPress('A'))
	{
		GetWorld()->GetMainCamera()->AddActorLocation(FVector::LEFT * 300.0f * _DeltaTime);
	}
	if (UEngineInput::IsPress('S'))
	{
		GetWorld()->GetMainCamera()->AddActorLocation(FVector::DOWN * 300.0f * _DeltaTime);
	}
	if (UEngineInput::IsPress('D'))
	{
		GetWorld()->GetMainCamera()->AddActorLocation(FVector::RIGHT * 300.0f * _DeltaTime);
	}
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
		MapEditorWindow = UEngineGUI::FindGUIWindow<MapEditor>("MapEditor");

		if (nullptr == MapEditorWindow)
		{
			MapEditorWindow = UEngineGUI::CreateGUIWindow<MapEditor>("MapEditor");
		}

		MapEditorWindow->SetActive(true);
		MapEditorWindow->TileMapRenderer = RenderTileMap.get();
	}

}