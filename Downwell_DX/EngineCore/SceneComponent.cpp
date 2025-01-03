#include "PreCompile.h"
#include "SceneComponent.h"

USceneComponent::USceneComponent()
{
}

USceneComponent::~USceneComponent()
{
}


void USceneComponent::SetupAttachment(std::shared_ptr<USceneComponent> _Parent)
{
	SetupAttachment(_Parent.get());
}

void USceneComponent::ParentMatrixCheck()
{
	if (nullptr != Parent)
	{
		Transform.ParentMat = Parent->Transform.World;
	}
}

void USceneComponent::SetupAttachment(USceneComponent* _Parent)
{
	Parent = _Parent;
	Parent->Childs.push_back(GetThis<USceneComponent>());

	TransformUpdate();
}

void USceneComponent::BeginPlay()
{
	UActorComponent::BeginPlay();

	for (std::shared_ptr<USceneComponent> Child : Childs)
	{
		Child->BeginPlay();
	}
}

void USceneComponent::TransformUpdate()
{
	ParentMatrixCheck();
	// 나의 트랜스폼 업데이트는 일단 한다.
	Transform.TransformUpdate(IsAbsolute);

	for (std::shared_ptr<USceneComponent> Child : Childs)
	{
		Child->TransformUpdate();
	}

	IsAbsolute = false;
}