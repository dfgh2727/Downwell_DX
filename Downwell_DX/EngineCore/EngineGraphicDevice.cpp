#include "PreCompile.h"
#include "EngineGraphicDevice.h"

UEngineGraphicDevice::UEngineGraphicDevice()
{
}

UEngineGraphicDevice::~UEngineGraphicDevice()
{
    Release();
}

void UEngineGraphicDevice::Release()
{
    if (nullptr != Context)
    {
        Context->Release();
        Context = nullptr;
    }

    if (nullptr != Device)
    {
        Device->Release();
        Context = nullptr;
    }
}

IDXGIAdapter* UEngineGraphicDevice::GetHighPerFormanceAdapter()
{
    // �̰� ���ؼ� ���� �ִ� �׷���ī�忡 �޸𸮰� �����ϴ�.
    IDXGIFactory* Factory = nullptr;
    unsigned __int64 MaxVideoMemory = 0;
    IDXGIAdapter* ResultAdapter = nullptr;


    // Factory�� ���̷�Ʈ x���� �����ϴ� �׷���ī�� �޸𸮿� ������ ������ִ� �������̽� �Դϴ�.
    // #pragma comment(lib, "dxguid")
    // ���̷�Ʈx�� ���� ���̺귯������ Ŭ������ �����ϴ°� �ƴϰ�
    // GUID��� ������ �ڵ� ����� �׶��׶����� �ε��ϴ� ����� ���ϴµ�.

    //MIDL_INTERFACE("7b7166ec-21c7-44ae-b21a-c9ae321ae369") => GUID��� �Ѵ�.
    //   IDXGIFactory : public IDXGIObject


    HRESULT HR = CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&Factory));

    if (nullptr == Factory)
    {
        MSGASSERT("�׷���ī�� ����� ���丮 ������ �����߽��ϴ�.");
        return nullptr;
    }



    for (int Index = 0;; ++Index)
    {
        IDXGIAdapter* CurAdapter = nullptr;
        Factory->EnumAdapters(Index, &CurAdapter);

        if (nullptr == CurAdapter)
        {
            break;
        }

        // ��������ü�� �ְ�
        DXGI_ADAPTER_DESC Desc;

        // ��ġ �ڵ鿡�� ������ ���Դϴ�.
        CurAdapter->GetDesc(&Desc);

        // �� ũ�Ⱑ ũ�� ���ɵ� ������.
        // 100�ް� ¥����      200
        if (MaxVideoMemory <= Desc.DedicatedVideoMemory)
        {
            MaxVideoMemory = Desc.DedicatedVideoMemory;
            //            100 
            if (nullptr != ResultAdapter)
            {
                ResultAdapter->Release();
            }

            // 100          200
            ResultAdapter = CurAdapter;
            continue;
        }

        CurAdapter->Release();
    }

    if (nullptr != Factory)
    {
        Factory->Release();
    }

    if (nullptr == ResultAdapter)
    {
        MSGASSERT("�׷���ī�尡 �޷����� ���� ��ǻ���Դϴ�.");
        return nullptr;
    }

    // int Test = MaxVideoMemory / (1024 * 1024 * 1024);

    return ResultAdapter;
}

void UEngineGraphicDevice::CreateDeviceAndContext()
{
	// ����̽��� �������
	// ����̽� �������� ������� �մϴ�.
	// ����̽��� ��带 ������� �մϴ�
    
    //IDXGIAdapter* pAdapter,
    // �׷������� ��������� �˷��ּ���.
    // nullptr �־��ָ� �˾Ƽ� ã��.
    // �׷���ī�� 2�� �޷��ִ� ������� �ִ�.

    // ���� ���� ���� �׷��� ī�带 ã�Ҵ�.
    IDXGIAdapter* Adapter = GetHighPerFormanceAdapter();

    int iFlag = 0;

#ifdef _DEBUG
    // ����� ����϶���
//  D3D11_CREATE_DEVICE_SINGLETHREADED = 0x1,
//	D3D11_CREATE_DEVICE_DEBUG = 0x2,
//	D3D11_CREATE_DEVICE_SWITCH_TO_REF = 0x4,
//	D3D11_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS = 0x8,
//	D3D11_CREATE_DEVICE_BGRA_SUPPORT = 0x20,
//	D3D11_CREATE_DEVICE_DEBUGGABLE = 0x40,
//	D3D11_CREATE_DEVICE_PREVENT_ALTERING_LAYER_SETTINGS_FROM_REGISTRY = 0x80,
//	D3D11_CREATE_DEVICE_DISABLE_GPU_TIMEOUT = 0x100,
//	D3D11_CREATE_DEVICE_VIDEO_SUPPORT = 0x800
    iFlag = D3D11_CREATE_DEVICE_DEBUG;
#endif

    
    //D3D_DRIVER_TYPE DriverType,
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN ���� �־������� �װɷ� ��
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE �ϰ� �˾Ƽ� �׷��� ī�� ã����.
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_SOFTWARE �׷���ī�� �Ⱦ���.
    // �׷���ī�带 �Ⱦ��ڴ�.
    
    //HMODULE Software, // Ư�� �ܰ��(������ ������������ �Ϻθ� ���� ���� �ڵ�� ��ü�ϱ� ���� dll �ڵ�)
    
    //UINT Flags, // �ɼ�
    
    //_In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    //UINT FeatureLevels,
    //UINT SDKVersion,
    //_COM_Outptr_opt_ ID3D11Device** ppDevice,
    //_Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN ���� �� ��ͷ� �ض�.

    D3D_FEATURE_LEVEL ResultLevel;

    // _COM_Outptr_opt_ ID3D11Device** ppDevice,
    // _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    // _COM_Outptr_opt_ ID3D11DeviceContext** ppImmediateContext

    D3D11CreateDevice(
        Adapter, 
        D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN,
        nullptr, // Ư�� �ܰ踦 ���� § �ڵ�� ��ü�ϰڴ�.
        iFlag,
        nullptr, // �������� ���� 11�� ����Ŵϱ�. �迭�� �־��ټ�
        0, // ���� ������ ��ó���� ����
        D3D11_SDK_VERSION, // ���� ���̷�Ʈx sdk ����
        &Device,
        &ResultLevel, 
        &Context);

    if (nullptr == Device)
    {
        MSGASSERT("�׷��� ����̽� ������ �����߽��ϴ�.");
        return;
    }

    if (nullptr == Context)
    {
        MSGASSERT("�׷��� ���ؽ�Ʈ ������ �����߽��ϴ�.");
        return;
    }

    Adapter->Release();
}

void UEngineGraphicDevice::CreateBackBuffer(const UEngineWindow& _Window)
{
	int a = 0;
}