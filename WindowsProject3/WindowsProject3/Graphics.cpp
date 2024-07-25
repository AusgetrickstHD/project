#include "Graphics.h"
#include <dxgi.h>
#include <iostream>

#pragma comment(lib, "d3d11.lib")

Graphics::Graphics(HWND hWnd)
{
    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory(&sd, sizeof(sd));
    sd.BufferDesc.Width = 800;
    sd.BufferDesc.Height = 600;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 0;
    sd.BufferDesc.RefreshRate.Denominator = 0;
    sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.BufferCount = 1;
    sd.OutputWindow = hWnd;
    sd.Windowed = TRUE;
    sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    sd.Flags = 0;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr,
        D3D_DRIVER_TYPE_HARDWARE,
        nullptr,
        D3D11_CREATE_DEVICE_DEBUG,
        nullptr,
        0,
        D3D11_SDK_VERSION,
        &sd,
        &pSwapChain,
        &pDevice,
        nullptr,
        &pContext
    );
    std::cout << "test" << hr;
}

Graphics::~Graphics()
{
	if (pDevice != nullptr) {
		pDevice->Release();
	}
	if (pContext != nullptr) {
		pContext->Release();
	}
	//if (pTarget != nullptr) {
		//pTarget->Release();
	//}
	if (pSwapChain != nullptr) {
		pSwapChain->Release();
	}
}


void Graphics::EndFrame() {
	pSwapChain->Present( 1u, 0u);
}
