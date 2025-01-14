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

protected:

private:

};

