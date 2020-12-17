#include "stdafx.h"
#include "stdio.h"
#include <string>
#include <windows.h>
#include "includes\IniReader.h"
#include "includes\injector\injector.hpp"

#include "InGameFunctions.h"
#include "GRaceCustom.h"
#include "cFrontendDatabase.h"
#include "SetupStat.h"
#include "LANStuff.h"
#include "CashgrabStuff.h"
#include "InRaceStuff.h"
#include "PostRaceResults.h"
#include "PostRaceLapStats.h"
#include "PostRaceRacerStats.h"
#include "RaceOverMessage.h"
#include "CopDensity.h"
#include "UIQRChallengeSeries.h"
#include "UIQRModeSelect.h"
#include "UIQRTrackOptions.h"

DWORD SetupRacerStats_JumpTable1[10] = { 0x59710B, 0x597112, 0x59710B, 0x597112, 0x597136, 0x597124, 0x59710B, (DWORD)RacerStats_Cashgrab_Footer, 0x59710B, 0x59714E };
DWORD SetupRacerStats_JumpTable2[10] = { 0x597176, 0x5971CD, 0x597210, 0x5971CD, 0x597278, 0x59725F, 0x597278, (DWORD)RacerStats_Cashgrab_Data, 0x597176, 0x59729F };
DWORD SetupLapStats_JumpTable1[10] = { 0x59732B, 0x597381, 0x59732B, 0x597381, 0x5974B3, 0x597414, 0x59732B, (DWORD)LapStats_Cashgrab_Header, 0x59732B, 0x59752C };
DWORD SetupLapStats_JumpTable2[10] = { 0x597558, 0x597702, 0x597558, 0x597702, 0x59795F, 0x597840, 0x597558, 0x597840, 0x597558, 0x597B25 };

int Init()
{
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");

	// Read settings
	bool QuickRaceModeSelectHook = RaceFixesSettings.ReadInteger("Main", "QuickRaceModeSelectHook", 1) == 1;
	bool QuickRaceTrackOptionsHook = RaceFixesSettings.ReadInteger("Main", "QuickRaceTrackOptionsHook", 1) == 1;
	bool LANFixes = RaceFixesSettings.ReadInteger("Main", "LANFixes", 1) == 1;

	bool ShowCashbagMessage = RaceFixesSettings.ReadInteger("Cashgrab", "ShowCashbagMessage", 1) == 1;

	// Hook Quick Race Mode Select Menu to allow customization of it
	if (QuickRaceModeSelectHook)
	{
		injector::MakeCALL(0x7BA4D7, UIQRModeSelect_Setup, true);
		injector::WriteMemory(0x8B7E28, &UIQRModeSelect_Setup, true);
	}

	// Hook Track Options to allow customization of it
	if (QuickRaceTrackOptionsHook)
	{
		injector::MakeCALL(0x7BF73D, UIQRTrackOptions_Setup, true);
		injector::WriteMemory(0x8B7FB8, &UIQRTrackOptions_Setup, true);

		// Disable forced 0 AI Opponents in tollbooth
		injector::MakeNOP(0x61DC9D, 6, true); // Game_InitRacers()

		// Default race settings
		injector::MakeJMP(0x58FEA0, cFrontendDatabase_DefaultRaceSettings, true); // 4 references

		// Custom race options
		injector::MakeJMP(0x56DD20, cFrontendDatabase_FillCustomRace, true); // 2 references
	}
	
	if (LANFixes)
	{
		// Fix Crash
		injector::MakeRangedNOP(0x7AA8E7, LANRaceSelectFixCodeCaveExit, true);
		injector::MakeJMP(0x7AA8E7, LANRaceSelectFixCodeCave, true);

		// Fix Icons and Strings - 1
		injector::MakeRangedNOP(0x539562, LANRaceModeFixCodeCaveExit, true);
		injector::MakeJMP(0x539562, LANRaceModeFixCodeCave, true);

		// Fix Icons and Strings - 2
		injector::MakeRangedNOP(0x535E8A, LANRaceModeFixCodeCave2Exit, true);
		injector::MakeJMP(0x535E8A, LANRaceModeFixCodeCave2, true);
	}
	
	injector::MakeJMP(0x56E090, cFrontendDatabase_GetRaceIconHash, true); // Icon Fixes
	injector::MakeJMP(0x56E010, cFrontendDatabase_GetRaceNameHash, true); // Name Fixes

	// Bring Back Cashgrab
	injector::MakeJMP(0x58C325, CashgrabLeaderboardCodeCave, true);
	injector::MakeJMP(0x7AB20C, CashgrabTrackSelectCodeCave, true);

	// Flash cash icon and amount when a cashbag is grabbed
	if (ShowCashbagMessage)
	{
		injector::MakeJMP(0x60E098, AwardPointsCodeCave, true);
	}

	// Call NotifyRaceFinished to update score for CashGrab races
	injector::MakeJMP(0x58BDEE, CashgrabNotifyRaceFinishedCodeCave, true);

	// Results
	injector::MakeJMP(0x596500, PostRaceResultsHeadingsCodeCave, true);
	injector::MakeJMP(0x5965C9, PostRaceResultsStandingsCodeCave, true);

	// Standings
	injector::WriteMemory<BYTE>(0x59731D, 9, true);
	injector::WriteMemory(0x597327, SetupLapStats_JumpTable1, true);
	injector::WriteMemory<BYTE>(0x597549, 9, true);
	injector::WriteMemory(0x597554, SetupLapStats_JumpTable2, true);

	// Stats
	injector::WriteMemory<BYTE>(0x597101, 9, true);
	injector::WriteMemory(0x597107, SetupRacerStats_JumpTable1, true);
	injector::WriteMemory<BYTE>(0x597168, 9, true);
	injector::WriteMemory(0x597172, SetupRacerStats_JumpTable2, true);

	// Un-hardcode Challenge Series icon
	injector::MakeJMP(0x007AE8CA, AddRaceIconCodeCave, true);
	injector::MakeJMP(0x007A42C4, RefreshHeaderIconCodeCave, true);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
		IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
		IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);

		if ((base + nt->OptionalHeader.AddressOfEntryPoint + (0x400000 - base)) == 0x7C4040) // Check if .exe file is compatible - Thanks to thelink2012 and MWisBest
		{
			Init();
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}
