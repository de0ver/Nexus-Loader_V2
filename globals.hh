#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

class c_globals {
public:

	bool active = true;
	bool button_active = false;

	int get_number = 0;
	int button_width = 100;
	int button_height = 50;

	HRESULT hr;
	HRESULT music;

	TCHAR current_path[MAX_PATH];

	HINSTANCE result;

	std::string appdata = getenv("APPDATA"); //здесь мы будем сохранять все дллки, %appdata%
	std::string github = "https://raw.githubusercontent.com/de0ver/For-NexusLoader/main/";
	std::string link;
	std::string music_name = "\\music.wav";

	const char* title_message = "";
	const char* onetapv3 = "Onetap V3"; //лучше решения я не придумал, да и за то как будто легче будет
	const char* onetapv2 = "Onetap V2";
	const char* weavev1 = "Weave V1";
	const char* weavev2 = "Weave V2";
	const char* weavev25 = "Weave V2.5";
	const char* airflow = "Airflow";
	const char* legendware = "Legendware";
	const char* fatality = "Fatality";
	const char* nemesis = "Nemesis";
	const char* ryzextr = "RyzeXTR";
	const char* supremacy = "Supremacy";
	const char* gamesense = "Gamesense";
	const char* pandora = "Pandora";
	const char* magmaa = "Magmaa";
	const char* blazehack = "BlazeHack";
	const char* mutiny = "Mutiny.pw";
	const char* example = "Example";
	
};

inline c_globals globals;