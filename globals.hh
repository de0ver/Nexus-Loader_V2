#pragma once
#include <unordered_map>
#include <string>
#include <iostream>

class c_globals
{
public:

	bool active = true;
	bool button_active = false;

	int get_number = 0;
	float button_width = 100;
	float button_height = 50;

	HRESULT hr;
	HRESULT sound;
	HRESULT error;

	TCHAR current_path[MAX_PATH];

	HINSTANCE result;

	std::string appdata = getenv("APPDATA"); //����� �� ����� ��������� ��� �����, %appdata%
	std::string appdata_gor = getenv("APPDATA");
	std::string github = "https://raw.githubusercontent.com/de0ver/For-NexusLoader/main/";
	std::string link = "";
	std::string sound_name = "\\button.wav";
	std::string error_name = "\\error.wav";
	char custom_path[MAX_PATH];
	char message_title[MAX_PATH] = "Nexus-Loader";

	enum dll_id
	{
		onetapv3_ = 1,
		onetapv2_,
		weavev1_,
		weavev2_,
		weavev25_,
		airflow_,
		legendware_,
		fatality_,
		nemesis_,
		ryzextr_,
		supremacy_,
		gamesense_,
		pandora_,
		magmaa_,
		blazehack_,
		mutiny_,
		eternity_,
		stickrpg_,
		rifk_,
		saphire_,
		onetapv3ex_,
		gor_,
		example_
	} dll_id;

	const char* title_message = "";
	const char* onetapv3 = "Onetap V3";
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
	const char* eternity = "Eternity";
	const char* stickrpg = "StickRPG";
	const char* rifk = "Rifk7";
	const char* saphire = "Saphire";
	const char* otc_patch = "OTC3 Ex";
	const char* example = "Example";
	//const char* error_bypass = "\\account_error_bypass.dll";
	
	void Steam(std::string path);
};

inline c_globals globals;