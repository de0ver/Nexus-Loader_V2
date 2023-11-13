#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"

namespace ui {
	void Init(LPDIRECT3DDEVICE9);
	void Render();
	void DownloadingMessage(bool button_active);
    
}

namespace ui {
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "                         Nexus-Loader";
}

namespace ui {
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 450, 450 };
	inline DWORD  window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
}