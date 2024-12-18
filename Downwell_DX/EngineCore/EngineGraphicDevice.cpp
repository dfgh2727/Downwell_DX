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
    // 이걸 통해서 만든 애는 그래픽카드에 메모리가 잡힙니다.
    IDXGIFactory* Factory = nullptr;
    unsigned __int64 MaxVideoMemory = 0;
    IDXGIAdapter* ResultAdapter = nullptr;


    // Factory는 다이렉트 x에서 지원하는 그래픽카드 메모리에 생성을 담당해주는 인터페이스 입니다.
    // #pragma comment(lib, "dxguid")
    // 다이렉트x와 같은 라이브러리들은 클래스를 인지하는게 아니고
    // GUID라는 것으로 코드 덩어리를 그때그때마다 로드하는 방식을 취하는데.

    //MIDL_INTERFACE("7b7166ec-21c7-44ae-b21a-c9ae321ae369") => GUID라고 한다.
    //   IDXGIFactory : public IDXGIObject


    HRESULT HR = CreateDXGIFactory(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&Factory));

    if (nullptr == Factory)
    {
        MSGASSERT("그래픽카드 조사용 팩토리 생성에 실패했습니다.");
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

        // 정보구조체가 있고
        DXGI_ADAPTER_DESC Desc;

        // 장치 핸들에서 빼오는 식입니다.
        CurAdapter->GetDesc(&Desc);

        // 램 크기가 크면 성능도 좋겠지.
        // 100메가 짜리를      200
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
        MSGASSERT("그래픽카드가 달려있지 않은 컴퓨터입니다.");
        return nullptr;
    }

    // int Test = MaxVideoMemory / (1024 * 1024 * 1024);

    return ResultAdapter;
}

void UEngineGraphicDevice::CreateDeviceAndContext()
{
	// 디바이스를 만들려면
	// 디바이스 버전부터 정해줘야 합니다.
	// 디바이스의 모드를 정해줘야 합니다
    
    //IDXGIAdapter* pAdapter,
    // 그래픽장지 사양정보를 알려주세요.
    // nullptr 넣어주면 알아서 찾아.
    // 그래픽카드 2개 달려있는 사람들이 있다.

    // 가장 성능 좋은 그래픽 카드를 찾았다.
    IDXGIAdapter* Adapter = GetHighPerFormanceAdapter();

    int iFlag = 0;

#ifdef _DEBUG
    // 디버그 모드일때만
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
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN 내가 넣어줬으니 그걸로 해
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_HARDWARE 니가 알아서 그래픽 카드 찾아줘.
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_SOFTWARE 그래픽카드 안쓸께.
    // 그래픽카드를 안쓰겠다.
    
    //HMODULE Software, // 특정 단계용(랜더링 파이프라인의 일부를 내가 만든 코드로 교체하기 위한 dll 핸들)
    
    //UINT Flags, // 옵션
    
    //_In_reads_opt_(FeatureLevels) CONST D3D_FEATURE_LEVEL* pFeatureLevels,
    //UINT FeatureLevels,
    //UINT SDKVersion,
    //_COM_Outptr_opt_ ID3D11Device** ppDevice,
    //_Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    // D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN 내가 준 어뎁터로 해라.

    D3D_FEATURE_LEVEL ResultLevel;

    // _COM_Outptr_opt_ ID3D11Device** ppDevice,
    // _Out_opt_ D3D_FEATURE_LEVEL* pFeatureLevel,
    // _COM_Outptr_opt_ ID3D11DeviceContext** ppImmediateContext

    D3D11CreateDevice(
        Adapter, 
        D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_UNKNOWN,
        nullptr, // 특정 단계를 내가 짠 코드로 대체하겠다.
        iFlag,
        nullptr, // 강제레벨 지정 11로 만들거니까. 배열을 넣어줄수
        0, // 내가 지정한 팩처레벨 개수
        D3D11_SDK_VERSION, // 현재 다이렉트x sdk 버전
        &Device,
        &ResultLevel, 
        &Context);

    if (nullptr == Device)
    {
        MSGASSERT("그래픽 디바이스 생성에 실패했습니다.");
        return;
    }

    if (nullptr == Context)
    {
        MSGASSERT("그래픽 컨텍스트 생성에 실패했습니다.");
        return;
    }

    Adapter->Release();
}

void UEngineGraphicDevice::CreateBackBuffer(const UEngineWindow& _Window)
{
	int a = 0;
}