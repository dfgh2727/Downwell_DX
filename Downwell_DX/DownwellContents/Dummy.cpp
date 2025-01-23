#include "PreCompile.h"
#include "Dummy.h"
#include <EngineCore/SpriteRenderer.h>
#include <EngineCore/DefaultSceneComponent.h>

Dummy::Dummy()
{
	std::shared_ptr<UDefaultSceneComponent> Default = CreateDefaultSubObject<UDefaultSceneComponent>();
	RootComponent = Default;

	// �������� �����.
	DummyRenderer = CreateDefaultSubObject<USpriteRenderer>();
	DummyRenderer->SetupAttachment(RootComponent);
	//DummyRenderer->SetTexture("DBat.png", true, 2.0f);

}

Dummy::~Dummy()
{
}

