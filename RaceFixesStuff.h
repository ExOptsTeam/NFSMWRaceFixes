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
#include "Game.h"

DWORD SetupRacerStats_JumpTable1[10] = { 0x59710B, 0x597112, 0x59710B, 0x597112, 0x597136, 0x597124, 0x59710B, (DWORD)RacerStats_Cashgrab_Footer, 0x59710B, 0x59714E };
DWORD SetupRacerStats_JumpTable2[10] = { 0x597176, 0x5971CD, 0x597210, 0x5971CD, 0x597278, 0x59725F, 0x597278, (DWORD)RacerStats_Cashgrab_Data, 0x597176, 0x59729F };
DWORD SetupLapStats_JumpTable1[10] = { 0x59732B, 0x597381, 0x59732B, 0x597381, 0x5974B3, 0x597414, 0x59732B, (DWORD)LapStats_Cashgrab_Header, 0x59732B, 0x59752C };
DWORD SetupLapStats_JumpTable2[10] = { 0x597558, 0x597702, 0x597558, 0x597702, 0x59795F, 0x597840, 0x597558, 0x597840, 0x597558, 0x597B25 };

int Init()
{
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");

	// Read settings
	bool QuickRaceModeSelectHook = RaceFixesSettings.ReadInteger("Main", "QuickRaceModeSelectHook", 1) != 0;
	bool QuickRaceTrackOptionsHook = RaceFixesSettings.ReadInteger("Main", "QuickRaceTrackOptionsHook", 1) != 0;
	bool ChallengeSeriesFixes = RaceFixesSettings.ReadInteger("Main", "ChallengeSeriesFixes", 1) != 0;
	bool LANFixes = RaceFixesSettings.ReadInteger("Main", "LANFixes", 1) != 0;

	bool OutroFix = RaceFixesSettings.ReadInteger("Fields", "OutroMovieFix", 1) != 0;

	bool ShowCashbagMessage = RaceFixesSettings.ReadInteger("Cashgrab", "ShowCashbagMessage", 1) != 0;

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
	injector::MakeJMP(0x58C325, CashgrabLeaderboardCodeCave, true); // LeaderBoard::Update
	injector::MakeJMP(0x7AB20C, CashgrabTrackSelectCodeCave, true); // UIQRTrackSelect::RefreshHeader

	// Flash cash icon and amount when a cashbag is grabbed
	if (ShowCashbagMessage)
	{
		injector::MakeJMP(0x60E098, AwardPointsCodeCave, true); // Game_AwardPoints
	}

	// Call NotifyRaceFinished to update score for CashGrab races
	injector::MakeJMP(0x58BDEE, CashgrabNotifyRaceFinishedCodeCave, true); // RaceOverMessage::RequestRaceOverMessage

	// Results - PostRaceResultsScreen::SetupResults
	injector::MakeJMP(0x596500, PostRaceResultsHeadingsCodeCave, true);
	injector::MakeJMP(0x5965C9, PostRaceResultsStandingsCodeCave, true);

	// Standings - PostRaceResultsScreen::SetupLapStats
	injector::WriteMemory<BYTE>(0x59731D, 9, true);
	injector::WriteMemory(0x597327, SetupLapStats_JumpTable1, true);
	injector::WriteMemory<BYTE>(0x597549, 9, true);
	injector::WriteMemory(0x597554, SetupLapStats_JumpTable2, true);

	// Stats - PostRaceResultsScreen::SetupRacerStats
	injector::WriteMemory<BYTE>(0x597101, 9, true);
	injector::WriteMemory(0x597107, SetupRacerStats_JumpTable1, true);
	injector::WriteMemory<BYTE>(0x597168, 9, true);
	injector::WriteMemory(0x597172, SetupRacerStats_JumpTable2, true);

	if (ChallengeSeriesFixes)
	{
		// Un-hardcode Challenge Series icon
		injector::MakeJMP(0x7AE8CA, AddRaceIconCodeCave, true); // UIQRChallengeSeries::AddRace
		injector::MakeJMP(0x7A42C4, RefreshHeaderIconCodeCave, true); // UIQRChallengeSeries::RefreshHeader

		// Fix custom gauges on pursuits
		injector::MakeNOP(0x58C7B4, 2, true); // HudResourceManager::GetCarPart
	}

	// Outro Movie Fix
	if (OutroFix)
	{
		injector::WriteMemory(0x61EA2C, Game_EnterPostRaceFlow, true); // LuaBindery::BindToGameCode
	}

	return 0;
}
