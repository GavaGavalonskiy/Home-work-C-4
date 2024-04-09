#include "WindowsProject1.h";
#include "module_1.cpp"; 
#include "module_2.cpp"; 

HWND hWnd;
HWND button_work_1;
HWND button_work_2;
HWND g_static;

HINSTANCE g_hInstance;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == button_work_1)
        {
            SetWindowText(g_static, showDgl(g_hInstance, hWnd).c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == button_work_2)
        {
            int result = showDgl_2(g_hInstance, hWnd); 
            while (result != 0)
            {
                if (result == 1)
                {
                    result = showDgl_3(g_hInstance, hWnd); 
                }
                else if (result == -1)
                {
                    result = showDgl_2(g_hInstance, hWnd);
                }
                else
                {
                    result = 0; 
                }
            }
        }
        break; 
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    g_hInstance = hInstance;

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"mainMenu";

    RegisterClass(&wc);

    hWnd = CreateWindowEx(WS_EX_LEFT, L"mainMenu", L"homework_C++", WS_OVERLAPPEDWINDOW, 500, 500, 250, 120, NULL, NULL, hInstance, NULL);
    button_work_1 = CreateWindowEx(0, L"BUTTON", L"Work 1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 50, 20, hWnd, NULL, hInstance, NULL);
    button_work_2 = CreateWindowEx(0, L"BUTTON", L"Work 2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 170, 10, 50, 20, hWnd, NULL, hInstance, NULL);
    g_static = CreateWindowEx(0, L"Static", L"", WS_CHILD | WS_VISIBLE, 10, 35, 30, 20, hWnd, NULL, hInstance, NULL); 

    ShowWindow(hWnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
