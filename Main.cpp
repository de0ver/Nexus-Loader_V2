#define _CRT_SECURE_NO_WARNINGS

#include "Main.h"
#include "ui/ui.hh"
#include "globals.hh"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <TlHelp32.h>
#include <functions.h>
#include <urlmon.h>
#include <tchar.h>
#include <fstream>
#include <string>
#include <filesystem>
#include <intrin.h>
#include <shlobj.h>
#include <cstdlib>
#include <vector>

void Inject() {
    DWORD Process = Functions::GetProcessId("csgo.exe");
    if (!Process) {
        MessageBoxA(nullptr, "Open CS:GO and press OK!", "Nexus-Loader", MB_ICONINFORMATION);
        Process = Functions::GetProcessId("csgo.exe");
    }
        HANDLE Game = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Process);
        uintptr_t ModuleBase = Functions::GetModuleBaseAddress(Process, "client.dll");

    if (Process) {
        if (Functions::LoadLibraryInject(Process, globals.appdata.c_str())) {
            Functions::Internal::Backup(Game);
            MessageBoxA(nullptr, "Injected!", "Nexus-Loader", MB_ICONINFORMATION);
            ExitProcess(0);
        }
        else {
            Functions::Internal::Backup(Game);
            MessageBoxA(nullptr, "Inject failed!", "Nexus-Loader", MB_ICONINFORMATION);
        }
    }
    else {
        MessageBoxA(nullptr, "Process not founded!", "Nexus-Loader", MB_ICONINFORMATION);
        exit(-1);
    }
}

void ChooseDll() {
    
    if (globals.get_number > 0) {
        if (!Functions::DoesFileExist(globals.appdata.c_str())) {
            globals.hr = URLDownloadToFile(NULL, (globals.github + globals.link).c_str(), globals.appdata.c_str(), 0, 0);
        }
        else
        {
            Inject();
        }
    }
}

// Main code
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    //globals.result = ShellExecute(NULL, NULL, "C:\music.mp3", NULL, NULL, SW_SHOWDEFAULT);
    // Create application window
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, ui::window_title, NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, ui::window_title, WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    // Show the window
    ShowWindow(main_hwnd, SW_HIDE);
    UpdateWindow(main_hwnd);

    // Setup Dear ImGui context
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; //crutial for not leaving the imgui.ini file
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; // Enable Multi-Viewport / Platform Windows

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.5f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {   
            static int init = false;
            if (!init) {
                ui::Init(g_pd3dDevice); 
                init = true;

                GetCurrentDirectory(MAX_PATH, globals.current_path);

                if (!Functions::DoesFileExist((globals.current_path + globals.music_name).c_str())) {
                    globals.music = URLDownloadToFile(NULL, "https://raw.githubusercontent.com/de0ver/For-NexusLoader/main/music.wav", (globals.current_path + globals.music_name).c_str(), 0, NULL);
                    PlaySound("music.wav", NULL, SND_ASYNC);
                }
                else 
                {
                    PlaySound("music.wav", NULL, SND_ASYNC);
                }
            }
            else {
                ui::Render();
            }
        }
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
            ChooseDll();
        }

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!globals.active) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}