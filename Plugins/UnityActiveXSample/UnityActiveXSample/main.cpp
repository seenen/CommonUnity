#include <windows.h>
#include "CActiveXContainer.h"

int Run(HINSTANCE hinst, int nCmdShow);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

CActiveXContainer *g_pUnityPlayerAx = NULL;

int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hinstPrev, LPSTR lpszCmdLine, int nCmdShow)
{
	int nResult = 0;

	OleInitialize(NULL);
	g_pUnityPlayerAx = new CActiveXContainer();

	if (g_pUnityPlayerAx != NULL) {
		g_pUnityPlayerAx->disableFullscreen = "false";
		g_pUnityPlayerAx->disableContextMenu = "true";
		//g_pUnityPlayerAx->src = "http://unity3d.com/gallery/demos/demos/players/BedroomScene.unity3d";
		g_pUnityPlayerAx->src = "F:/Heros/CommonUnity/Resources/UnityWebAgent/UnityWebAgent.unity3d";
		nResult = Run(hinst, nCmdShow);
		g_pUnityPlayerAx->Release();
	}

	OleUninitialize();

	return nResult;
}

int Run(HINSTANCE hinst, int nCmdShow)
{
	TCHAR      szAppName[] = TEXT("sample");
	HWND       hwnd;
	MSG        msg;
	WNDCLASSEX wc;

	wc.cbSize        = sizeof(WNDCLASSEX);
	wc.style         = 0;
	wc.lpfnWndProc   = ::WindowProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = hinst;
	wc.hIcon         = (HICON)LoadImage(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_SHARED);
	wc.hCursor       = (HCURSOR)LoadImage(NULL, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_SHARED);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = szAppName;
	wc.hIconSm       = (HICON)LoadImage(NULL, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_SHARED);

	if (RegisterClassEx(&wc) == 0)
		return 0;

	hwnd = CreateWindowEx(0, szAppName, szAppName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hinst, g_pUnityPlayerAx);
	if (hwnd == NULL)
		return 0;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		if (! g_pUnityPlayerAx->Create(hwnd))
			return -1;

		break;
	case WM_DESTROY:
		g_pUnityPlayerAx->Destroy();

		PostQuitMessage(0);

		break;
	default:
		break;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
