#include "PreCompile.h"
#include "Renderer.h"
#include <EngineBase/EngineString.h>
#include <EngineCore/EngineCamera.h>
#include <EngineCore/EngineTexture.h>
#include <EngineCore/Mesh.h>
#include "EngineVertex.h"
#include "EngineBlend.h"

URenderer::URenderer()
{
}

URenderer::~URenderer()
{

}

void URenderer::SetSprite(UEngineSprite* _Sprite)
{
	Sprite = _Sprite;

	if (nullptr == Sprite)
	{
		MSGASSERT("존재하지 않는 스프라이트를 사용하려고 했습니다.");
	}
}

void URenderer::SetSprite(std::string_view _Value)
{
	std::string UpperName = UEngineString::ToUpper(_Value);

	Sprite = UEngineSprite::Find<UEngineSprite>(UpperName).get();

	if (nullptr == Sprite)
	{
		MSGASSERT("존재하지 않는 스프라이트를 사용하려고 했습니다.");
	}
}

void URenderer::SetOrder(int _Order)
{
	int PrevOrder = GetOrder();
	UObject::SetOrder(_Order);
	ULevel* Level = GetActor()->GetWorld();

	std::shared_ptr<URenderer> RendererPtr = GetThis<URenderer>();
	Level->ChangeRenderGroup(0, PrevOrder, RendererPtr);
}


ENGINEAPI void URenderer::BeginPlay()
{
	USceneComponent::BeginPlay();
	SetOrder(0);

	// 기본적인 랜더링 파이프라인을 익히기 위한 
	// 모든 기본 코드들을 다 쳐볼 생각입니다.

	//InputAssembler1Init();
	VertexShaderInit();
	// InputAssembler2Init();
	RasterizerInit();
	PixelShaderInit();
	ShaderResInit();

}

void URenderer::ShaderResInit()
{
	{
		D3D11_BUFFER_DESC BufferInfo = { 0 };
		BufferInfo.ByteWidth = sizeof(FTransform);
		BufferInfo.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;
		BufferInfo.Usage = D3D11_USAGE_DYNAMIC;

		if (S_OK != UEngineCore::GetDevice().GetDevice()->CreateBuffer(&BufferInfo, nullptr, &TransformConstBuffer))
		{
			MSGASSERT("상수버퍼 생성에 실패했습니다..");
			return;
		}
	}

	{
		D3D11_BUFFER_DESC BufferInfo = { 0 };
		BufferInfo.ByteWidth = sizeof(FSpriteData);
		BufferInfo.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;
		BufferInfo.Usage = D3D11_USAGE_DYNAMIC;

		if (S_OK != UEngineCore::GetDevice().GetDevice()->CreateBuffer(&BufferInfo, nullptr, &SpriteConstBuffer))
		{
			MSGASSERT("상수버퍼 생성에 실패했습니다..");
			return;
		}
	}

	D3D11_SAMPLER_DESC SampInfo = { D3D11_FILTER::D3D11_FILTER_MIN_MAG_MIP_POINT};
	SampInfo.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_BORDER; // 0~1사이만 유효
	SampInfo.AddressV = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_BORDER; // y
	SampInfo.AddressW = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_CLAMP; // z // 3중 

	SampInfo.BorderColor[0] = 0.0f;
	SampInfo.BorderColor[1] = 0.0f;
	SampInfo.BorderColor[2] = 0.0f;
	SampInfo.BorderColor[3] = 0.0f;

	// SampInfo.ComparisonFunc = D3D11_COMPARISON_NEVER;
	// Lod라고 불리는 것은 z값이 얼마나 멀어지면 얼마나 대충 색깔 빼올거냐. 
	// SampInfo.MaxLOD = 0.0f;
	// SampInfo.MinLOD = 0.0f;

	UEngineCore::GetDevice().GetDevice()->CreateSamplerState(&SampInfo, &SamplerState);
}

void URenderer::ShaderResSetting()
{
	{
		FTransform& RendererTrans = GetTransformRef();
		D3D11_MAPPED_SUBRESOURCE Data = {};
		// 이 데이터를 사용하는 랜더링 랜더링 잠깐 정지
		// 잠깐 그래픽카드야 멈 그래픽카드에 있는 상수버퍼 수정해야 해.
		UEngineCore::GetDevice().GetContext()->Map(TransformConstBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &Data);

		// Data.pData 그래픽카드와 연결된 주소값.
		if (nullptr == Data.pData)
		{
			MSGASSERT("그래픽카드가 수정을 거부했습니다.");
		}
		memcpy_s(Data.pData, sizeof(FTransform), &RendererTrans, sizeof(FTransform));
		UEngineCore::GetDevice().GetContext()->Unmap(TransformConstBuffer.Get(), 0);

		// 같은 상수버퍼를 
		ID3D11Buffer* ArrPtr[16] = { TransformConstBuffer.Get() };
		UEngineCore::GetDevice().GetContext()->VSSetConstantBuffers(0, 1, ArrPtr);
	}

	{
		D3D11_MAPPED_SUBRESOURCE Data = {};
		// 이 데이터를 사용하는 랜더링 랜더링 잠깐 정지
		// 잠깐 그래픽카드야 멈 그래픽카드에 있는 상수버퍼 수정해야 해.
		UEngineCore::GetDevice().GetContext()->Map(SpriteConstBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &Data);

		// Data.pData 그래픽카드와 연결된 주소값.
		if (nullptr == Data.pData)
		{
			MSGASSERT("그래픽카드가 수정을 거부했습니다.");
		}
		memcpy_s(Data.pData, sizeof(FSpriteData), &SpriteData, sizeof(FSpriteData));
		UEngineCore::GetDevice().GetContext()->Unmap(SpriteConstBuffer.Get(), 0);

		// 같은 상수버퍼를 
		ID3D11Buffer* ArrPtr[16] = { SpriteConstBuffer.Get() };
		UEngineCore::GetDevice().GetContext()->VSSetConstantBuffers(1, 1, ArrPtr);
	}


	

	ID3D11ShaderResourceView* ArrSRV[16] = { Sprite->GetSRV() };
	UEngineCore::GetDevice().GetContext()->PSSetShaderResources(0, 1, ArrSRV);

	ID3D11SamplerState* ArrSMP[16] = { SamplerState.Get() };
	UEngineCore::GetDevice().GetContext()->PSSetSamplers(0, 1, ArrSMP);
}

void URenderer::Render(UEngineCamera* _Camera, float _DeltaTime)
{
	FTransform& CameraTrans = _Camera->GetTransformRef();

	FTransform& RendererTrans = GetTransformRef();

	// 랜더러는 월드 뷰 프로젝트를 다 세팅받았고
	RendererTrans.View = CameraTrans.View;
	RendererTrans.Projection = CameraTrans.Projection;

	RendererTrans.WVP = RendererTrans.World * RendererTrans.View * RendererTrans.Projection;

	
	if (nullptr == Mesh)
	{
		MSGASSERT("매쉬가 세팅되지 않아서 랜더링을 할수 없습니다.");
		return;
	}
	


	ShaderResSetting();
	InputAssembler1Setting();
	VertexShaderSetting();
	InputAssembler2Setting();
	RasterizerSetting();
	PixelShaderSetting();
	OutPutMergeSetting();

	// 인덱스 버퍼를 통해서 그리겠다.
	UEngineCore::GetDevice().GetContext()->DrawIndexed(6, 0, 0);

}


//
//void URenderer::InputAssembler1Init()
//{
//	std::vector<EngineVertex> Vertexs;
//	Vertexs.resize(4);
//
//	Vertexs[0] = EngineVertex{ FVector(-0.5f, 0.5f, -0.0f), {0.0f , 0.0f }, {1.0f, 0.0f, 0.0f, 1.0f} };
//	Vertexs[1] = EngineVertex{ FVector(0.5f, 0.5f, -0.0f), {1.0f , 0.0f } , {0.0f, 1.0f, 0.0f, 1.0f} };
//	Vertexs[2] = EngineVertex{ FVector(-0.5f, -0.5f, -0.0f), {0.0f , 1.0f } , {0.0f, 0.0f, 1.0f, 1.0f} };
//	Vertexs[3] = EngineVertex{ FVector(0.5f, -0.5f, -0.0f), {1.0f , 1.0f } , {1.0f, 1.0f, 1.0f, 1.0f} };
//
//	D3D11_BUFFER_DESC BufferInfo = {0};
//
//	BufferInfo.ByteWidth = sizeof(EngineVertex) * static_cast<int>(Vertexs.size());
//	BufferInfo.BindFlags = D3D11_BIND_VERTEX_BUFFER;
//	BufferInfo.CPUAccessFlags = 0;
//	BufferInfo.Usage = D3D11_USAGE_DEFAULT;
//
//	D3D11_SUBRESOURCE_DATA Data; // 초기값 넣어주는 용도의 구조체
//	Data.pSysMem = &Vertexs[0];
//
//	if (S_OK != UEngineCore::GetDevice().GetDevice()->CreateBuffer(&BufferInfo, &Data, VertexBuffer.GetAddressOf()))
//	{
//		MSGASSERT("버텍스 버퍼 생성에 실패했습니다.");
//		return;
//	}
//}

void URenderer::InputAssembler1Setting()
{
	Mesh->GetVertexBuffer()->Setting();
	UEngineCore::GetDevice().GetContext()->IASetInputLayout(InputLayOut.Get());
	//UINT VertexSize = sizeof(EngineVertex);
	//// 이 버텍스 버퍼가 10개짜리인데 3번째 버텍스 부터 세팅해줘.
	//UINT Offset = 0;
	//ID3D11Buffer* ArrBuffer[1];
	//ArrBuffer[0] = VertexBuffer.Get();
	//UEngineCore::GetDevice().GetContext()->IASetVertexBuffers(0, 1, ArrBuffer, &VertexSize, &Offset);
}

void URenderer::InputAssembler1LayOut()
{
	std::vector<D3D11_INPUT_ELEMENT_DESC> InputLayOutData;

	{
		D3D11_INPUT_ELEMENT_DESC Desc;
		Desc.SemanticName = "POSITION";
		Desc.InputSlot = 0;
		Desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		Desc.AlignedByteOffset = 0;
		Desc.InputSlotClass = D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA;

		// 인스턴싱을 설명할때 이야기 하겠습니다.
		Desc.SemanticIndex = 0;
		Desc.InstanceDataStepRate = 0;
		InputLayOutData.push_back(Desc);
	}


	{
		D3D11_INPUT_ELEMENT_DESC Desc;
		Desc.SemanticName = "TEXCOORD";
		Desc.InputSlot = 0;
		Desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		Desc.AlignedByteOffset = 16;
		Desc.InputSlotClass = D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA;

		Desc.SemanticIndex = 0;
		Desc.InstanceDataStepRate = 0;
		InputLayOutData.push_back(Desc);
	}




	{
		D3D11_INPUT_ELEMENT_DESC Desc;
		Desc.SemanticName = "COLOR";
		Desc.InputSlot = 0;
		Desc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
		Desc.AlignedByteOffset = 32;
		Desc.InputSlotClass = D3D11_INPUT_CLASSIFICATION::D3D11_INPUT_PER_VERTEX_DATA;

		Desc.SemanticIndex = 0;
		Desc.InstanceDataStepRate = 0;
		InputLayOutData.push_back(Desc);
	}



	// 쉐이더에서 어떤 인풋레이아웃을 사용하는지 알려줘.
	HRESULT Result = UEngineCore::GetDevice().GetDevice()->CreateInputLayout(
		&InputLayOutData[0],
		static_cast<unsigned int>(InputLayOutData.size()),
		VSShaderCodeBlob->GetBufferPointer(),
		VSShaderCodeBlob->GetBufferSize(),
		&InputLayOut);

	if (S_OK != Result)
	{
		MSGASSERT("인풋 레이아웃 생성에 실패했습니다");
	}
}


void URenderer::VertexShaderInit()
{
	UEngineDirectory CurDir;
	CurDir.MoveParentToDirectory("EngineShader");
	UEngineFile File = CurDir.GetFile("EngineSpriteShader.fx");

	std::string Path = File.GetPathToString();
	std::wstring WPath = UEngineString::AnsiToUnicode(Path);

	std::string version = "vs_5_0";
	int Flag0 = 0;
	int Flag1 = 0;

#ifdef _DEBUG
	Flag0 = D3D10_SHADER_DEBUG;
#endif

	// 행렬을 집어넣게 될것이다.
	// 조금 느려진다고하는 하는데 느낀적은 없습니다.
	Flag0 |= D3DCOMPILE_PACK_MATRIX_ROW_MAJOR;

	D3DCompileFromFile(
		WPath.c_str(),
		nullptr, // Define TEST 등으로 전처리기를 넣을수.
		nullptr,
		"VertexToWorld",
		version.c_str(),
		Flag0,
		Flag1,
		&VSShaderCodeBlob,
		&VSErrorCodeBlob
	);

	if (nullptr == VSShaderCodeBlob)
	{
		std::string ErrString = reinterpret_cast<char*>(VSErrorCodeBlob->GetBufferPointer());
		MSGASSERT("쉐이더 코드 중간빌드에서 실패했습니다\n" + ErrString);
		return;
	}

	HRESULT Result = UEngineCore::GetDevice().GetDevice()->CreateVertexShader(
		VSShaderCodeBlob->GetBufferPointer(),
		VSShaderCodeBlob->GetBufferSize(),
		nullptr,
		&VertexShader
		);

	if (S_OK != Result)
	{
		MSGASSERT("버텍스 쉐이더 생성에 실패했습니다.");
	}

	InputAssembler1LayOut();
}

void URenderer::VertexShaderSetting()
{
	UEngineCore::GetDevice().GetContext()->VSSetShader(VertexShader.Get(), nullptr, 0);
}

void URenderer::RasterizerInit()
{
	D3D11_RASTERIZER_DESC Desc = {};
	Desc.CullMode = D3D11_CULL_MODE::D3D11_CULL_NONE;
	Desc.FillMode = D3D11_FILL_MODE::D3D11_FILL_SOLID;
	UEngineCore::GetDevice().GetDevice()->CreateRasterizerState(&Desc, &RasterizerState);

	ViewPortInfo.Width = 1280.0f;
	ViewPortInfo.Height = 720.0f;
	ViewPortInfo.TopLeftX = 0.0f;
	ViewPortInfo.TopLeftY = 0.0f;
	ViewPortInfo.MinDepth = 0.0f;
	ViewPortInfo.MaxDepth = 1.0f;
}


void URenderer::RasterizerSetting()
{
	UEngineCore::GetDevice().GetContext()->RSSetViewports(1, &ViewPortInfo);
	UEngineCore::GetDevice().GetContext()->RSSetState(RasterizerState.Get());
}

//void URenderer::InputAssembler2Init()
//{
//	std::vector<unsigned int> Indexs;
//
//	Indexs.push_back(0);
//	Indexs.push_back(1);
//	Indexs.push_back(2);
//
//	Indexs.push_back(1);
//	Indexs.push_back(3);
//	Indexs.push_back(2);
//
//
//	D3D11_BUFFER_DESC BufferInfo = { 0 };
//	BufferInfo.ByteWidth = sizeof(unsigned int) * static_cast<int>(Indexs.size());
//	BufferInfo.BindFlags = D3D11_BIND_INDEX_BUFFER;
//	BufferInfo.CPUAccessFlags = 0;
//	BufferInfo.Usage = D3D11_USAGE_DEFAULT;
//	D3D11_SUBRESOURCE_DATA Data;
//	Data.pSysMem = &Indexs[0];
//	if (S_OK != UEngineCore::GetDevice().GetDevice()->CreateBuffer(&BufferInfo, &Data, &IndexBuffer))
//	{
//		MSGASSERT("인덱스 버퍼 생성에 실패했습니다.");
//		return;
//	}
//}

void URenderer::InputAssembler2Setting()
{

	Mesh->GetIndexBuffer()->Setting();

	// int Offset = 0;
	//// DXGI_FORMAT_R8_UINT; <= 옛날에는 아꼈다.
	//// DXGI_FORMAT_R16_UINT; <= 옛날에는 아꼈다.
	//UEngineCore::GetDevice().GetContext()->IASetIndexBuffer(IndexBuffer.Get(), DXGI_FORMAT_R32_UINT, Offset);

	UEngineCore::GetDevice().GetContext()->IASetPrimitiveTopology(Topology);
}





void URenderer::PixelShaderInit()
{
	UEngineDirectory CurDir;
	CurDir.MoveParentToDirectory("EngineShader");
	UEngineFile File = CurDir.GetFile("EngineSpriteShader.fx");

	std::string Path = File.GetPathToString();
	std::wstring WPath = UEngineString::AnsiToUnicode(Path);
	std::string version = "ps_5_0";

	int Flag0 = 0;
	int Flag1 = 0;

#ifdef _DEBUG
	Flag0 = D3D10_SHADER_DEBUG;
#endif

	Flag0 |= D3DCOMPILE_PACK_MATRIX_ROW_MAJOR;

	D3DCompileFromFile(
		WPath.c_str(),
		nullptr, // Define TEST 등으로 전처리기를 넣을수.
		nullptr,
		"PixelToWorld",
		version.c_str(),
		Flag0,
		Flag1,
		&PSShaderCodeBlob,
		&PSErrorCodeBlob
	);

	if (nullptr == PSShaderCodeBlob)
	{
		std::string ErrString = reinterpret_cast<char*>(PSErrorCodeBlob->GetBufferPointer());
		MSGASSERT("쉐이더 코드 중간빌드에서 실패했습니다\n" + ErrString);
		return;
	}

	HRESULT Result = UEngineCore::GetDevice().GetDevice()->CreatePixelShader(
		PSShaderCodeBlob->GetBufferPointer(),
		PSShaderCodeBlob->GetBufferSize(),
		nullptr,
		&PixelShader
	);

	if (S_OK != Result)
	{
		MSGASSERT("픽셀 쉐이더 생성에 실패했습니다.");
	}
}

void URenderer::PixelShaderSetting()
{
	UEngineCore::GetDevice().GetContext()->PSSetShader(PixelShader.Get(), nullptr, 0);
}

void URenderer::OutPutMergeSetting()
{
	if (nullptr != Blend)
	{
		Blend->Setting();
	}

	// 배열 넣어줄수 있다. 
	// 0번이면 sv_target0
	ID3D11RenderTargetView* RTV = UEngineCore::GetDevice().GetRTV();

	ID3D11RenderTargetView* ArrRtv[16] = { 0 };
	ArrRtv[0] = RTV; // SV_Target0

	UEngineCore::GetDevice().GetContext()->OMSetRenderTargets(1, &ArrRtv[0], nullptr);
}

void URenderer::SetSpriteData(size_t _Index)
{
	SpriteData = Sprite->GetSpriteData(_Index);
}

void URenderer::SetMesh(std::string_view _Name)
{
	std::shared_ptr<UMesh> FindMesh = UMesh::Find<UMesh>(_Name);

	Mesh = FindMesh.get();

	if (nullptr == Mesh)
	{
		MSGASSERT("존재하지 않는 매쉬를 세팅할수 없습니다.\n");
	}
}

void URenderer::SetBlend(std::string_view _Name)
{
	std::shared_ptr<UEngineBlend> FindBlend = UEngineBlend::Find<UEngineBlend>(_Name);

	Blend = FindBlend.get();

	if (nullptr == Blend)
	{
		MSGASSERT("존재하지 않는 Blend를 세팅할수 없습니다.\n");
	}
}