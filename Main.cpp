#define _CRT_SECURE_NO_WARNINGS

#include "Main.h"
#include "ui/ui.hh"
#include "globals.hh"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <TlHelp32.h>
#include <functions.h>
#include <urlmon.h>
#include <vector>
#include "gor_segment.h"

void Inject()
{
    DWORD Process = Functions::GetProcessId("csgo.exe");

    if (!Process)
    {
        MessageBox(nullptr, "EN: Open CS:GO and press OK!\nRU: Запусти CS:GO и нажми OK", globals.message_title, MB_ICONINFORMATION);
        Process = Functions::GetProcessId("csgo.exe");
    }

    HANDLE Game = OpenProcess(PROCESS_ALL_ACCESS, FALSE, Process);
    uintptr_t ModuleBase = Functions::GetModuleBaseAddress(Process, "client.dll");

    if (Process)
    {
            if (Functions::LoadLibraryInject(Process, (globals.appdata).c_str()))
            {
                Functions::Internal::Backup(Game);
                MessageBox(nullptr, "EN: Injected!\nRU: Модуль загружен!", globals.message_title, MB_ICONINFORMATION);
                ExitProcess(0);
            } else {
                Functions::Internal::Backup(Game);
                PlaySound("error.wav", NULL, SND_ASYNC);
                MessageBox(nullptr, "EN: Inject failed!\nRU: Не удалось загрузить модуль!", globals.message_title, MB_ICONINFORMATION);
                ExitProcess(0);
            }
    } else {
        PlaySoundA("error.wav", NULL, SND_ASYNC);
        MessageBox(nullptr, "EN: Process csgo.exe not founded!\nRU: Процесс csgo.exe не найден!", globals.message_title, MB_ICONINFORMATION);
        return;
    }
}

void c_globals::Steam(std::string path)
{
    if (MessageBox(nullptr, "EN: You launched any thing through Steam?\nRU: Ты запускал что нибудь через Steam?", globals.message_title, MB_YESNO) == IDYES)
    {
        system("taskkill /f /im steam.exe");
        std::string prepare_command = "cd " + (path) + "&&" + " start steam.exe";
        const char* full_command = prepare_command.data();
        system(full_command);

        Sleep(500); //trash
        DWORD Process = Functions::GetProcessId("steam.exe");

        if (!Process)
        {
            MessageBox(nullptr, "EN: Steam not started automatically, start it manual\nRU: Steam не запустился автоматически, сделай это сам", globals.message_title, MB_ICONINFORMATION);
        }

        MessageBox(nullptr, "EN: After Steam full launch press OK\nRU: После полного запуска Steam нажми ОК", globals.message_title, MB_ICONINFORMATION);
    }
    
    std::ofstream out(path + "\\GameOverlayRenderer.dll", std::ios::binary);
    out.write(reinterpret_cast<const char*>(GameOverlayRender), sizeof(GameOverlayRender) / sizeof(GameOverlayRender[0]));
    out.close();

    Inject();

    return;
}

void ChooseDll()
{
    if (!ui::open_input)
    {
        if (!Functions::DoesFileExist(globals.appdata.c_str()))
        {
            globals.hr = URLDownloadToFile(NULL, (globals.github + globals.link).c_str(), globals.appdata.c_str(), NULL, NULL);

            if (globals.hr != S_OK)
            {
                MessageBox(NULL, ("EN: Error downloading " + globals.link + "\nRU: Ошибка во время скачивания " + globals.link).c_str(), "Error", MB_ICONERROR | MB_SYSTEMMODAL);
            }

            if (globals.hr == S_OK)
            {
                MessageBox(NULL, ("EN: Start downloading " + globals.link + "\nRU: Начало загрузки модуля " + globals.link).c_str(), globals.message_title, MB_SYSTEMMODAL);
            }
        }

        if (globals.get_number == globals.dll_id::airflow_ || globals.get_number == globals.dll_id::pandora_)
        {
            if (std::string(globals.custom_path).empty())
            {
                char steam_path[MAX_PATH];
                DWORD buffer_size = sizeof(steam_path);
#ifndef _DEBUG
                RegGetValue(HKEY_LOCAL_MACHINE, "SOFTWARE\\Valve\\Steam", "InstallPath", RRF_RT_ANY, NULL, (LPVOID)&steam_path, &buffer_size);
                std::memcpy(globals.custom_path, steam_path, MAX_PATH); //создание новой строки из dword
#endif
            } 
            
            int value = MessageBox(NULL, ("EN: This is your Steam path?\n" + std::string(globals.custom_path) + "\nRU: Это правильный путь до Steam?\n" + std::string(globals.custom_path)).c_str(), globals.message_title, MB_YESNO);
            if (value == 7)
            {
                ui::open_input = true;
            }

            if (!ui::open_input && !std::string(globals.custom_path).empty())
                globals.Steam(std::string(globals.custom_path));

        } else {
            Inject();
        }
    }

    return;
}

// Main code
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    // Create application window
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, ui::window_title, NULL };
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, ui::window_title, WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    // Initialize Direct3D
    if (!CreateDeviceD3D(main_hwnd))
    {
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
        style.WindowRounding = 1.f;
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

                if (!Functions::DoesFileExist((globals.current_path + globals.sound_name).c_str()))
                {
                    globals.sound = URLDownloadToFile(NULL, "https://raw.githubusercontent.com/de0ver/For-NexusLoader/main/button.wav", (globals.current_path + globals.sound_name).c_str(), 0, NULL);
                }
                if (!Functions::DoesFileExist((globals.current_path + globals.error_name).c_str()))
                {
                    globals.error = URLDownloadToFile(NULL, "https://raw.githubusercontent.com/de0ver/For-NexusLoader/main/error.wav", (globals.current_path + globals.error_name).c_str(), 0, NULL);
                }
            } else {
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

            if (globals.get_number > 0)
            {
                ChooseDll();
                globals.get_number = 0;
            }
        }

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
        {
            ResetDevice();
        }
        if (!globals.active)
        {
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

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
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