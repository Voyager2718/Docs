#include<Windows.h>

LPCWSTR g_szClassName = L"MainWindowsClass";



LRESULT CALLBACK WndProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam){
	switch (Msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);break;
	case WM_DESTROY:
		PostQuitMessage(0);	break;
	default:
		return DefWindowProc(hwnd,Msg,wParam,lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	WNDCLASSEX wc;
	MSG msg;
	HWND hwnd;
	ZeroMemory(&wc, sizeof(wc));
	wc.style = 0;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = hInstance;
	wc.hIconSm = LoadIcon(NULL,IDC_ICON);
	wc.hIcon = LoadIcon(NULL,IDC_ICON);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW +1);
	wc.cbWndExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;

	if(!RegisterClassEx(&wc)){
		LPCWSTR Error01 = L"Could not register class";
		LPCWSTR Error01_Caption = L"Error";
		MessageBox(NULL,Error01 ,Error01_Caption, MB_OK|MB_ICONERROR);
	}

	LPCWSTR WindowTitle = L"My First Win32 Proc";
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, WindowTitle, WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION, CW_USEDEFAULT, CW_USEDEFAULT, 500, 300, NULL, NULL, hInstance, NULL);
	if(hwnd == NULL){
		LPCWSTR Error02 = L"Could not create winodw";
		LPCWSTR Error02_Caption = L"Error";
		MessageBox(NULL,Error02 ,Error02_Caption, MB_OK|MB_ICONERROR);
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}