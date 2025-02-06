// WindowsAPI.cpp : Defines the entry point for the application.
//
#include "pch.h"
#include "Game.h"
#include "framework.h"
#include "WindowsAPI.h"
#include "TimeManager.h"

#define MAX_LOADSTRING 100

// Global Variables:
HWND g_hwnd;

HINSTANCE hInst;                                // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{    
    // 1) 윈도우 창 정보 등록
    MyRegisterClass(hInstance);

    // 2) 윈도우 창 생성
    if (!InitInstance (hInstance, nCmdShow))
        return FALSE;

    Game game;
    game.Init(g_hwnd);

    MSG msg = {};
    uint64 prevTick = 0;

    // 3) 메인 루프
    while (msg.message != WM_QUIT)
    {
        //메세지(어떤 이벤트)가 발생하면 실행
        if (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
        }
        //게임 로직
        uint64 now = ::GetTickCount64();

/*        if (now - prevTick >= 10)
        {
            game.Update();
            game.Render();
            
            prevTick = now;
        }*/    
        game.Update();
        game.Render();
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSAPI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr; //MAKEINTRESOURCEW(IDC_WINDOWSAPI);
    wcex.lpszClassName  = L"GameCoding";//szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   RECT windowRect = { 0, 0, 800, 600 };
   ::AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, false);

   HWND hWnd = CreateWindowW(L"GameCoding"/*szWindowClass*/, L"GameCoding", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

   g_hwnd = hWnd;

   if (!hWnd)
   {
      return FALSE;
   }

   ::ShowWindow(hWnd, nCmdShow);
   ::UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
#pragma region RenderByWM_PAINT
            //RECT rect;
            //GetClientRect(hWnd, &rect);
            //FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));

            //// FPS 텍스트 다시 그리기
            //uint32 fps = GET_SINGLE(TimeManager)->GetFps();
            //float deltaTime = GET_SINGLE(TimeManager)->GetDeltaTime();
            //wstring str = std::format(L"FPS({0}), DT({1}ms)", fps, static_cast<int32>(deltaTime * 1000));

            //SetBkMode(hdc, TRANSPARENT);
            //SetTextColor(hdc, RGB(0, 0, 0));
            //TextOut(hdc, 650, 10, str.c_str(), static_cast<int32>(str.size()));

            //// 사각형 다시 그리기
            //Rectangle(hdc, 200, 200, 400, 400);
#pragma endregion
         
#pragma region DrawingPractice
            ////문자 그리기
            //WCHAR buffer[100];
            //::wsprintf(buffer, L"(%d, %d)", mousePosX, mousePosY);

            //::TextOut(hdc, 100, 100, buffer, ::wcslen(buffer));

            ////사각형 그리기
            //::Rectangle(hdc, 200, 200, 400, 400);

            ////원 그리기
            //::Ellipse(hdc, 200, 200, 400, 400);

            ////선 그리기
            //::MoveToEx(hdc, 300, 300, nullptr);
            //::LineTo(hdc, 400, 400);
#pragma endregion
       
            EndPaint(hWnd, &ps);
        }
        break;

    //case WM_MOUSEMOVE:
    //          
    //    mousePosX = LOWORD(lParam);
    //    mousePosY = HIWORD(lParam);
    //    ::InvalidateRect(hWnd, nullptr, TRUE);
    //    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
