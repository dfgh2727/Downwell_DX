#pragma once
#include "EngineResources.h"

// ���� :
class UVertexBuffer : public UEngineResources
{
public:
	// constrcuter destructer
	UVertexBuffer();
	~UVertexBuffer();

	// delete Function
	UVertexBuffer(const UVertexBuffer& _Other) = delete;
	UVertexBuffer(UVertexBuffer&& _Other) noexcept = delete;
	UVertexBuffer& operator=(const UVertexBuffer& _Other) = delete;
	UVertexBuffer& operator=(UVertexBuffer&& _Other) noexcept = delete;

	template<typename VertexType>
	static std::shared_ptr<UVertexBuffer> Create(std::string_view _Name, const std::vector<VertexType>& _VertexData)
	{
		return Create(_Name, reinterpret_cast<const void*>(& _VertexData[0]), sizeof(VertexType), _VertexData.size());
	}

	static std::shared_ptr<UVertexBuffer> Create(std::string_view _Name, const void* _InitData, size_t _VertexSize, size_t _VertexCount);

	void Setting();

protected:
	void ResCreate(const void* _InitData, size_t _VertexSize, size_t _VertexCount);

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> VertexBuffer = nullptr;
	D3D11_BUFFER_DESC BufferInfo = { 0 };
	UINT VertexSize = 0;
	UINT VertexCount = 0;
};

