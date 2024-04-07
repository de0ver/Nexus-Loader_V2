#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include <Windows.h>

void ui::Render()
{
    if (!globals.active)
        return;

    int screen_x = GetSystemMetrics(0);
    int screen_y = GetSystemMetrics(1);

    int buttons_count = 20;

    //if (screen_x >= 1920 && screen_y >= 1080 && screen_x <= 2560 && screen_y <= 1440) //Мне нужно сделать адаптив, чтобы при добавлении новых кнопок размер увеличивался (можно задать кол-во строк, столбцов)
    //{
    //    globals.button_width = 100;
    //    globals.button_height = 50;
    //    window_size.x = (globals.button_width * (buttons_count / 6)) + globals.button_width / 2;
    //    window_size.y = (globals.button_height * (buttons_count / 4)) + globals.button_height * 3;

    //} else if (screen_x > 2560 && screen_y > 1440) //rework later
    //{
    //    window_size.x = 545;
    //    window_size.y = 465;
    //    globals.button_width = 125;
    //    globals.button_height = 65;
    //}

    globals.button_width = 100;
    globals.button_height = 50;
    window_size.x = (globals.button_width * (buttons_count / 5)) + globals.button_width / 2;
    window_size.y = (globals.button_height * (buttons_count / 4)) + globals.button_height * 3;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(window_alpha);
    //ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { window_padding });

    ImGui::Begin(window_title, &globals.active, window_flags);
    {   
         //первый ряд
        if (ImGui::Button(globals.onetapv3, ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 1;
            globals.link = "onetapv3.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.onetapv2), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 2;
            globals.link = "onetapv2.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.weavev1), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 3;
            globals.link = "weavev1.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.weavev2), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 4;
            globals.link = "weavev2.dll";
            globals.appdata += ("\\" + globals.link);
        }


        ImGui::NewLine(); //второй ряд
        if (ImGui::Button((globals.weavev25), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 5;
            globals.link = "weavev25.dll";
            globals.appdata += ("\\" + globals.link);
        }


        ImGui::SameLine();
        if (ImGui::Button((globals.airflow), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 6;
            globals.link = "airflow.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.legendware), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 7;
            globals.link = "legendware.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.fatality), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 8;
            globals.link = "fatality.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::NewLine(); //третий ряд
        if (ImGui::Button((globals.nemesis), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 9;
            globals.link = "nemesis.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.ryzextr), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 10;
            globals.link = "ryzextr.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.supremacy), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 11;
            globals.link = "supremacy.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.gamesense), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 12;
            globals.link = "gamesense.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::NewLine(); //четвертый ряд
        if (ImGui::Button((globals.pandora), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 13;
            globals.link = "pandora.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.magmaa), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 14;
            globals.link = "magmaa.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.blazehack), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 15;
            globals.link = "blazehack.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.mutiny), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 16;
            globals.link = "mutiny.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::NewLine(); //четвертый ряд
        if (ImGui::Button((globals.eternity), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 17;
            globals.link = "eternity.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.stickrpg), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 18;
            globals.link = "stickrpg.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.rifk), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 19;
            globals.link = "rifk.dll";
            globals.appdata += ("\\" + globals.link);
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.saphire), ImVec2(globals.button_width, globals.button_height)))
        {
            globals.get_number = 20;
            globals.link = "saphire.dll";
            globals.appdata += ("\\" + globals.link);
        }

        //ImGui::NewLine(); //пятый ряд
        //if (ImGui::Button((globals.otc_patch), ImVec2(globals.button_width, globals.button_height)))
        //{
        //    globals.get_number = 21;
        //    globals.link = "eternity.dll";
        //    globals.appdata += ("\\" + globals.link);
        //}

        //ImGui::SameLine();
        //if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height)))
        //{
        //    globals.get_number = 22;
        //    globals.link = "saphire.dll";
        //    globals.appdata += ("\\" + globals.link);
        //}

        //ImGui::SameLine();
        //if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height)))
        //{
        //    globals.get_number = 23;
        //    globals.link = "saphire.dll";
        //    globals.appdata += ("\\" + globals.link);
        //}

        //ImGui::SameLine();
        //if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height)))
        //{
        //    globals.get_number = 24;
        //    globals.link = "saphire.dll";
        //    globals.appdata += ("\\" + globals.link);
        //}

        if (globals.get_number > 0)
        {
            globals.button_active = true;
            ui::DownloadingMessage(globals.button_active);
        }
    }
    ImGui::End();
}

void ui::DownloadingMessage(bool button_active)
{
    if (button_active)
    {
        button_active = false;
        PlaySoundA("button.wav", NULL, SND_ASYNC);
        MessageBoxA(nullptr, "Downloading...", globals.message_title, MB_ICONINFORMATION);
        return;
    }
}

void ui::Init(LPDIRECT3DDEVICE9 device)
{
    dev = device;
	
    // colors
    ImGui::StyleColorsLight();

	if (window_pos.x == 0) {
		RECT screen_rect{};
		GetWindowRect(GetDesktopWindow(), &screen_rect);
		screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));
		window_pos = (screen_res - window_size) * 0.5f;
		// init images here
	}
}