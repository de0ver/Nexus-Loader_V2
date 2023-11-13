#include "ui.hh"
#include "../globals.hh"
#include "../imgui/imgui.h"
#include "../imgui/imgui_internal.h"
#include <Windows.h>

void ui::Render() {

    if (!globals.active) return;

    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(0.5f);

    ImGui::Begin(window_title, &globals.active, window_flags);
    {   
        ImGui::Spacing(); //первый ряд
        if (ImGui::Button(globals.onetapv3, ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 1;
            globals.title_message = globals.onetapv3;
            globals.appdata += "\\onetapv3.dll";
            globals.link = "onetapv3.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.onetapv2), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 2;
            globals.title_message = globals.onetapv2;
            globals.appdata += "\\onetapv2.dll";
            globals.link = "onetapv2.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.weavev1), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 3;
            globals.title_message = globals.weavev1;
            globals.appdata += "\\weavev1.dll";
            globals.link = "weavev1.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.weavev2), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 4;
            globals.title_message = globals.weavev2;
            globals.appdata += "\\weavev2.dll";
            globals.link = "weavev2.dll";
        }


        ImGui::NewLine(); //второй ряд
        if (ImGui::Button((globals.weavev25), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 5;
            globals.title_message = globals.weavev25;
            globals.appdata += "\\weave25.dll";
            globals.link = "weavev25.dll";
        }


        ImGui::SameLine();
        if (ImGui::Button((globals.airflow), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 6;
            globals.title_message = globals.airflow;
            globals.appdata += "\\airflow.dll";
            globals.link = "airflow.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.legendware), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 7;
            globals.title_message = globals.legendware;
            globals.appdata += "\\legendware.dll";
            globals.link = "legendware.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.fatality), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 8;
            globals.title_message = globals.fatality;
            globals.appdata += "\\fatality.dll";
            globals.link = "fatality.dll";
        }

        ImGui::NewLine(); //третий ряд
        if (ImGui::Button((globals.nemesis), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 9;
            globals.title_message = globals.nemesis;
            globals.appdata += "\\nemesis.dll";
            globals.link = "nemesis.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.ryzextr), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 10;
            globals.title_message = globals.ryzextr;
            globals.appdata += "\\ryzextr.dll";
            globals.link = "ryzextr.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.supremacy), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 11;
            globals.title_message = globals.supremacy;
            globals.appdata += "\\supremacy.dll";
            globals.link = "supremacy.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.gamesense), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 12;
            globals.title_message = globals.gamesense;
            globals.appdata += "\\gamesense.dll";
            globals.link = "gamesense.dll";
        }

        ImGui::NewLine(); //четвертый ряд
        if (ImGui::Button((globals.pandora), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 13;
            globals.title_message = globals.pandora;
            globals.appdata += "\\pandora.dll";
            globals.link = "pandora.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.magmaa), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 14;
            globals.title_message = globals.magmaa;
            globals.appdata += "\\magmaa.dll";
            globals.link = "magmaa.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.blazehack), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 15;
            globals.title_message = globals.blazehack;
            globals.appdata += "\\blazehack.dll";
            globals.link = "blazehack.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.mutiny), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.mutiny;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        ImGui::NewLine(); //четвертый ряд
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 13;
            globals.title_message = globals.example;
            globals.appdata += "\\pandora.dll";
            globals.link = "pandora.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.example;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.example;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.example;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        ImGui::NewLine(); //четвертый ряд
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 13;
            globals.title_message = globals.example;
            globals.appdata += "\\pandora.dll";
            globals.link = "pandora.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.example;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.example;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        ImGui::SameLine();
        if (ImGui::Button((globals.example), ImVec2(globals.button_width, globals.button_height))) {
            globals.button_active = true;
            globals.get_number = 16;
            globals.title_message = globals.example;
            globals.appdata += "\\mutiny.dll";
            globals.link = "mutiny.dll";
        }

        if (globals.get_number > 0) {
            ui::DownloadingMessage(globals.button_active);
        }

    }
    ImGui::End();
}

void ui::DownloadingMessage(bool button_active) {

    if (button_active) {
        MessageBoxA(nullptr, "Downloading...", "Nexus-Loader", MB_ICONINFORMATION);
        return;
    }
}

void ui::Init(LPDIRECT3DDEVICE9 device) {
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