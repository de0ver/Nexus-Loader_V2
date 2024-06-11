#pragma once
#include <d3d9.h>
#include "../imgui/imgui.h"

namespace ui
{
	void Init(LPDIRECT3DDEVICE9);
	void Render();
}

namespace ui
{
	inline LPDIRECT3DDEVICE9 dev;
	inline const char* window_title = "Nexus-Loader";
}

namespace ui
{
	inline bool open_input = false;
	inline ImVec2 screen_res{ 000, 000 };
	inline ImVec2 window_pos{ 0, 0 };
	inline ImVec2 window_size{ 500, 500 };
	inline DWORD  window_flags = ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus;
	inline float window_alpha = 1.f;
	inline ImVec2 window_padding = { 25.f, 25.f };
}