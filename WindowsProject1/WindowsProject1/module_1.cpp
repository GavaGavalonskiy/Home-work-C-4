#include "WindowsProject1.h"
#include "module_1.h" 

static HWND hScrollBar; 
static int nPos; 

static INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        hScrollBar = CreateWindowEx(0, L"SCROLLBAR", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ, 90, 10, 100, 20, hwndDlg, NULL, NULL, NULL);
        SetScrollRange(hScrollBar, SB_CTL, 0, 100, TRUE);

        return TRUE;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
            nPos = GetScrollPos(hScrollBar, SB_CTL); 
            EndDialog(hwndDlg, IDOK);
            break;

        case IDCANCEL:
            EndDialog(hwndDlg, IDCANCEL);
            break;
        }
        break;
    case WM_HSCROLL:
        if ((HWND)lParam == hScrollBar) {
            switch (LOWORD(wParam))
            {
            case SB_LINELEFT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) - 1, TRUE);
                break;

            case SB_LINERIGHT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) + 1, TRUE);
                break;

            case SB_PAGELEFT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) - 10, TRUE);
                break;

            case SB_PAGERIGHT:
                SetScrollPos(hScrollBar, SB_CTL, GetScrollPos(hScrollBar, SB_CTL) + 10, TRUE);
                break;

            case SB_THUMBPOSITION:
            {
                SetScrollPos(hScrollBar, SB_CTL, HIWORD(wParam), TRUE);
            }
            break;
            }
        }
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, IDCANCEL);
        break;
    }

    return FALSE;
}

std::wstring showDgl(HINSTANCE g_hInstance, HWND hWnd)
{
    DialogBoxW(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DialogProc); 
    return std::to_wstring(nPos).c_str(); 
}