#include "WindowsProject1.h"
#include "module_2.h" 



static INT_PTR CALLBACK DialogProc_2(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hwndDlg, 1);
            break;

        case IDCANCEL: 
            EndDialog(hwndDlg, 0);
            break;
        }
        break;
    }

    return FALSE;
}

static INT_PTR CALLBACK DialogProc_3(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            EndDialog(hwndDlg, -1);
            break;

        case IDOK2:
            EndDialog(hwndDlg, 1);
            break;

        case IDCANCEL:
            EndDialog(hwndDlg, 0);
            break;
        }
        break;
    }

    return FALSE;
}

int showDgl_2(HINSTANCE g_hInstance, HWND hWnd)
{
    int res = DialogBoxW(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, DialogProc_2); 
    return res;  
}

int showDgl_3(HINSTANCE g_hInstance, HWND hWnd)
{
    int res = DialogBoxW(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DialogProc_3);
    return res;
}