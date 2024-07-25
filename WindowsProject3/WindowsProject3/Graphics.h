#pragma once

#include "Framework.h"
#include <d3d11.h>

class Graphics {
public:
	Graphics(HWND hWnd);
	~Graphics();
	void EndFrame();
	void ClearBuffer(float red, float green, float blue);
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwapChain = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	//ID3D11RenderTargetView* pTarget = nullptr;
};