#pragma once
#include "EngineShaderResources.h"
#include "Mesh.h"
#include "EngineMaterial.h"
#include "EngineEnums.h"

// 설명 : 랜더링의 최소단위
//        Draw를 하는 애는 이녀석을 기반으로 할것이다.
// 이녀석이 이제 랜더링의 기반이 된 이유는 나중에 3D 매쉬까지 랜더링을 한다면
// 3D매쉬가 매쉬 n개로 이루어져 있다는 것을 알수가 있다.
// 주인공이라면 
// 주인공의 머리  RenderUnit
// 주인공의 몸  RenderUnit
// 주인공의 팔  RenderUnit
// 주인공의 갑옷 RenderUnit
class URenderUnit
{
public:
	// constrcuter destructer
	URenderUnit();
	~URenderUnit();

	UTransformObject* TransformObject = nullptr;

	URenderer* ParentRenderer = nullptr;

	// 매쉬(육체) 
	std::shared_ptr<UMesh> Mesh;
	// 머티리얼(피부)
	std::shared_ptr<UEngineMaterial> Material;

	Microsoft::WRL::ComPtr<ID3D11InputLayout> InputLayOut;

	ENGINEAPI void SetMesh(std::string_view _Name);
	ENGINEAPI void SetMaterial(std::string_view _Name);

	//void SetInputAssembler1();
	//void SetInputAssembler1();

	ENGINEAPI virtual void Render(class UEngineCamera* _Camera, float _DeltaTime);

	ENGINEAPI void MaterialResourcesCheck();

	template<typename Data>
	ENGINEAPI void ConstantBufferLinkData(std::string_view _Name, Data& _Data)
	{
		ConstantBufferLinkData(_Name, reinterpret_cast<void*>(&_Data));
	}

	ENGINEAPI void ConstantBufferLinkData(std::string_view Name, void* _Data);

	ENGINEAPI void SetTexture(std::string_view _Name, std::string_view _ResName);
	ENGINEAPI void SetTexture(std::string_view _Name, std::shared_ptr<UEngineTexture> _Texture);
	ENGINEAPI void SetSampler(std::string_view Name, std::string_view _ResName);


	ENGINEAPI void SetTexture(std::string_view _Name, UEngineTexture* _Texture);

	ENGINEAPI void Reset();

	std::map<EShaderType, UEngineShaderResources> Resources;

private:
	void InputLayOutCreate();
};

