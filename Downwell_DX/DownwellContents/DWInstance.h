#pragma once
#include <EngineCore/GameInstance.h>

// ���� :
class DWInstance : public UGameInstance
{
public:
	// constrcuter destructer
	DWInstance();
	~DWInstance();

	// delete Function
	DWInstance(const DWInstance& _Other) = delete;
	DWInstance(DWInstance&& _Other) noexcept = delete;
	DWInstance& operator=(const DWInstance& _Other) = delete;
	DWInstance& operator=(DWInstance&& _Other) noexcept = delete;

	int BulletCount = 8;
	int GemCount = 0;

protected:

private:

};

