#pragma once
#include <EngineCore/GameMode.h>

// Ό³Έν :
class MapEditorMode : public AGameMode
{
public:
	// constrcuter destructer
	MapEditorMode();
	~MapEditorMode();

	// delete Function
	MapEditorMode(const MapEditorMode& _Other) = delete;
	MapEditorMode(MapEditorMode&& _Other) noexcept = delete;
	MapEditorMode& operator=(const MapEditorMode& _Other) = delete;
	MapEditorMode& operator=(MapEditorMode&& _Other) noexcept = delete;

	void Tick(float _DeltaTime);

protected:
	void LevelChangeStart() override;

private:
	std::shared_ptr<class UTileMapWindow> TileMapWindow;

	std::shared_ptr<class USpriteRenderer> PivotSpriteRenderer;

	std::shared_ptr<class UTileMapRenderer> TileMapRenderer;
};
