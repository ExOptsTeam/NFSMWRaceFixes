#include "stdafx.h"
#include "stdio.h"
#include "SetupStat.h"
#include "InRaceStuff.h"
#include "PostRaceResults.h"
#include "PostRaceLapStats.h"
#include "PostRaceRacerStats.h"
#include <string>
#include <windows.h>
#include "includes\injector\injector.hpp"


DWORD __fastcall cFrontendDatabase_GetRaceNameHash(void* _This, void* _EDX_Unused, int RaceType)
{
	DWORD result; // eax

	switch (RaceType)
	{
	case 0:
		result = 0xB94FD70E; // RACETYPES_SPRINT
		break;
	case 1:
		result = 0x34FA2C1; // RACETYPES_CIRCUIT
		break;
	case 2:
		result = 0x6F547E4C; // RACETYPES_DRAG
		break;
	case 3:
		result = 0x4930F5FC; // RACETYPES_KNOCKOUT
		break;
	case 4:
		result = 0xA15E4505; // RACETYPES_TOLLBOOTH
		break;
	case 5:
		result = 0xEE1EDC76; // RACETYPES_SPEEDTRAP
		break;
	case 6:
		result = 0x1E5F2565; // RACETYPES_MULTIPOINT_TO
		break;
	case 7:
		result = 0x93EDCC7D; // RACETYPES_MULTIPOINT_CASHGRAB
		break;
	case 8:
		result = 0x213CC8D1; // RACETYPES_CHALLENGE
		break;
	default:
		result = 0x7818F85E; // RACETYPES_UNKNOWN
		break;
	}
	return result;
}

DWORD __fastcall cFrontendDatabase_GetRaceIconHash(void* _This, void* _EDX_Unused, int RaceType)
{
	DWORD result; // eax

	switch (RaceType)
	{
	case 0:
		result = 0x2521E5EB; // MODE_ICON_SPRINT
		break;
	case 1:
		result = 0xE9638D3E; // MODE_ICON_CIRCUIT
		break;
	case 2:
		result = 0xAAAB31E9; // MODE_ICON_DRAG
		break;
	case 3:
		result = 0x3A015595; // MODE_ICON_LAP_KNOCKOUT
		break;
	case 4:
	case 10:
		result = 0x1A091045; // MILESTONE_TOLLBOOTH
		break;
	case 5:
	case 9:
		result = 0x66C9A7B6; // MILESTONE_SPEEDTRAP
		break;
	case 6:
		result = 0x586A39A2; // MODE_ICON_MULTIPOINT_TO
		break;
	case 7:
		result = 0xCE985A7A; // MODE_ICON_MULTIPOINT_CASHGRAB
		break;
	case 8:
		result = 0x9A962438; // MODE_ICON_CHALLENGE_SERIES
		break;
	default:
		result = 0;
		break;
	}
	return result;
}

void __declspec(naked) CashgrabCodeCave()
{
	_asm
	{
		addpreviousoption:
			call IconScrollerMenu_AddOption

		cashgrab :
			push 0x50
			call j_malloc // malloc
			mov esi, eax
			add esp, 0x04
			mov dword ptr ds : [esp + 0x0C] , esi
			test esi, esi
			mov dword ptr ds : [esp + 0x18] , 9
			je xoresithing
			push 0
			push 0x93EDCC7D // RACETYPES_MULTIPOINT_CASHGRAB
			push 0xCE985A7A // MODE_ICON_MULTIPOINT_CASHGRAB
			mov ecx, esi
			call IconOption_Create
			mov dword ptr ds : [esi] , 0x8B75B0
			mov dword ptr ds : [esi + 0x4C] , 7 // Cashgrab
			jmp addoptionthing

		xoresithing :
			xor esi, esi

		addoptionthing :
			mov ecx, edi
			push esi
			mov dword ptr ds : [esp + 0x1C] , ebp
			call IconScrollerMenu_AddOption
			push 0x007AAC01
			retn
	}
}

void __declspec(naked) CashgrabLeaderboardCodeCave()
{
	_asm
	{
		originalcode:
			call GRaceParameters_GetRaceType
			cmp eax, 07
			jz doCashGrabLeaderboard
			push 0x58C32A
			retn

		doCashGrabLeaderboard :
			fld dword ptr ds : [edi + 0x5C] // get points
			mov edx, [ebx]
			sub esp, 8
			fstp qword ptr ds : [esp] // points
			push 0x0089D89C //"%$0.0f"
			push edx // leaderboard string
			call FEPrintf_FEString
			add esp, 0x10

			jump_58C46E :
			push 0x58C46E
			retn
	}
}

void __declspec(naked) CashgrabTrackSelectCodeCave()
{
	_asm
	{
		call GRaceParameters_GetRaceType
		cmp eax, 07
		je cashgrab

		mov ecx, [esi + 0x108]
		call GRaceParameters_GetRaceType
		push 0x7AB211
		retn

		cashgrab :
		fld dword ptr ds : [edi + 8]
			fmul ds : 0x8A0294
			fstp dword ptr ds : [esp + 0x0C]

			mov ecx, [esi + 0x10]
			push 0xCF2BDD31 // HIGHEST_CASH_HEADER
			push 0x28462C64 // Text object
			push ecx
			call FEngSetLanguageHash
			fld dword ptr ds : [esp + 0x18]
			mov edx, [esi + 0x10]
			add esp, 0x0C
			push ebx
			sub esp, 0x8
			fstp qword ptr ds : [esp]
			push 0x89D89C // "%$0.0f"
			push 0xB515499C // Text object
			push edx
			call FEPrintf
			add esp, 0x18
			push 0x7AB2E0
			retn
	}

}

DWORD LANRaceSelectFixCodeCaveExit = 0x7aa8ed;
DWORD LANRaceModeFixCodeCaveExit = 0x5395a3;
DWORD LANRaceModeFixCodeCave2Exit = 0x535ecb;

void __declspec(naked) LANRaceSelectFixCodeCave()
{
	_asm
	{
		cmp ecx, 0x04 //Tollbooth
		je fixassprint
		cmp ecx, 0x05 //Speedtrap
		je fixassprint
		cmp ecx, 0x06 //Multipoint
		je fixassprint
		cmp ecx, 0x07 //Cashgrab
		je fixassprint
		cmp ecx, 0x08 //Challenge
		je fixassprint
		cmp ecx, 0x03 //Knockout
		je fixascircuit
		jmp originalcode

		fixassprint :
		mov ecx, 0x00
			jmp originalcode

			fixascircuit :
		mov ecx, 0x01
			jmp originalcode

			originalcode :
		mov dword ptr ds : [edx + 0x168] , ecx
			jmp LANRaceSelectFixCodeCaveExit

	}
}

void __declspec(naked) LANRaceModeFixCodeCave()
{
	_asm
	{
		cmp eax, 0x00
		je sprint
		cmp eax, 0x01
		je circuit
		cmp eax, 0x02
		je drag
		cmp eax, 0x03
		je knockout
		cmp eax, 0x04
		je tollbooth
		cmp eax, 0x05
		je speedtrap
		cmp eax, 0x06
		je multipoint
		cmp eax, 0x07
		je cashgrab
		cmp eax, 0x08
		je challenge
		mov ebx, 0x7818F85E // RACETYPES_UNKNOWN
		mov ebp, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES

		jmp LANRaceModeFixCodeCaveExit

		circuit :
		mov ebx, 0x034FA2C1 // RACETYPES_CIRCUIT
			mov ebp, 0xE9638D3E // MODE_ICON_CIRCUIT
			jmp LANRaceModeFixCodeCaveExit

			sprint :
		mov ebx, 0xB94FD70E // RACETYPES_SPRINT
			mov ebp, 0x2521E5EB // MODE_ICON_SPRINT
			jmp LANRaceModeFixCodeCaveExit

			drag :
		mov ebx, 0x6F547E4C // RACETYPES_DRAG
			mov ebp, 0xAAAB31E9 // MODE_ICON_DRAG
			jmp LANRaceModeFixCodeCaveExit

			knockout :
		mov ebx, 0x4930F5FC // RACETYPES_KNOCKOUT
			mov ebp, 0x3A015595 // MODE_ICON_LAP_KNOCKOUT
			jmp LANRaceModeFixCodeCaveExit

			tollbooth :
		mov ebx, 0xA15E4505 // RACETYPES_TOLLBOOTH
			mov ebp, 0x1A091045 // MILESTONE_TOLLBOOTH
			jmp LANRaceModeFixCodeCaveExit

			speedtrap :
		mov ebx, 0xEE1EDC76 // RACETYPES_SPEEDTRAP
			mov ebp, 0x66C9A7B6 // MILESTONE_SPEEDTRAP
			jmp LANRaceModeFixCodeCaveExit

			multipoint :
		mov ebx, 0x1E5F2565 // RACETYPES_MULTIPOINT_TO
			mov ebp, 0x586A39A2 // MODE_ICON_MULTIPOINT_TO
			jmp LANRaceModeFixCodeCaveExit

			cashgrab :
		mov ebx, 0x93EDCC7D // RACETYPES_MULTIPOINT_CASHGRAB
			mov ebp, 0xCE985A7A // MODE_ICON_MULTIPOINT_CASHGRAB
			jmp LANRaceModeFixCodeCaveExit

			challenge :
		mov ebx, 0x213CC8D1 // RACETYPES_CHALLENGE
			mov ebp, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES
			jmp LANRaceModeFixCodeCaveExit

	}
}

void __declspec(naked) LANRaceModeFixCodeCave2()
{
	_asm
	{

		cmp eax, 0x00
		je sprint
		cmp eax, 0x01
		je circuit
		cmp eax, 0x02
		je drag
		cmp eax, 0x03
		je knockout
		cmp eax, 0x04
		je tollbooth
		cmp eax, 0x05
		je speedtrap
		cmp eax, 0x06
		je multipoint
		cmp eax, 0x07
		je cashgrab
		cmp eax, 0x08
		je challenge
		mov ebp, 0x7818F85E // RACETYPES_UNKNOWN
		mov eax, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES
		jmp LANRaceModeFixCodeCave2Exit

		circuit :
		mov ebp, 0x034FA2C1 // RACETYPES_CIRCUIT
			mov eax, 0xE9638D3E // MODE_ICON_CIRCUIT
			jmp LANRaceModeFixCodeCave2Exit

			sprint :
		mov ebp, 0xB94FD70E // RACETYPES_SPRINT
			mov eax, 0x2521E5EB // MODE_ICON_SPRINT
			jmp LANRaceModeFixCodeCave2Exit

			drag :
		mov ebp, 0x6F547E4C // RACETYPES_DRAG
			mov eax, 0xAAAB31E9 // MODE_ICON_DRAG
			jmp LANRaceModeFixCodeCave2Exit

			knockout :
		mov ebp, 0x4930F5FC // RACETYPES_KNOCKOUT
			mov eax, 0x3A015595 // MODE_ICON_LAP_KNOCKOUT
			jmp LANRaceModeFixCodeCave2Exit

			tollbooth :
		mov ebp, 0xA15E4505 // RACETYPES_TOLLBOOTH
			mov eax, 0x1A091045 // MILESTONE_TOLLBOOTH
			jmp LANRaceModeFixCodeCave2Exit

			speedtrap :
		mov ebp, 0xEE1EDC76 // RACETYPES_SPEEDTRAP
			mov eax, 0x66C9A7B6 // MILESTONE_SPEEDTRAP
			jmp LANRaceModeFixCodeCave2Exit

			multipoint :
		mov ebp, 0x1E5F2565 // RACETYPES_MULTIPOINT_TO
			mov eax, 0x586A39A2 // MODE_ICON_MULTIPOINT_TO
			jmp LANRaceModeFixCodeCave2Exit

			cashgrab :
		mov ebp, 0x93EDCC7D // RACETYPES_MULTIPOINT_CASHGRAB
			mov eax, 0xCE985A7A // MODE_ICON_MULTIPOINT_CASHGRAB
			jmp LANRaceModeFixCodeCave2Exit

			challenge :
		mov ebp, 0x213CC8D1 // RACETYPES_CHALLENGE
			mov eax, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES
			jmp LANRaceModeFixCodeCave2Exit

	}
}

DWORD SetupRacerStats_JumpTable1[10] = { 0x59710B, 0x597112, 0x59710B, 0x597112, 0x597136, 0x597124, 0x59710B, (DWORD)RacerStats_Cashgrab_Footer, 0x59710B, 0x59714E };
DWORD SetupRacerStats_JumpTable2[10] = { 0x597176, 0x5971CD, 0x597210, 0x5971CD, 0x597278, 0x59725F, 0x597278, (DWORD)RacerStats_Cashgrab_Data, 0x597176, 0x59729F };
DWORD SetupLapStats_JumpTable1[10] = { 0x59732B, 0x597381, 0x59732B, 0x597381, 0x5974B3, 0x597414, 0x59732B, (DWORD)LapStats_Cashgrab_Header, 0x59732B, 0x59752C };
DWORD SetupLapStats_JumpTable2[10] = { 0x597558, 0x597702, 0x597558, 0x597702, 0x59795F, 0x597840, 0x597558, 0x597840, 0x597558, 0x597B25 };

int Init()
{
	// Bring Back Cashgrab
	injector::MakeJMP(0x7AABFC, CashgrabCodeCave, true);
	injector::MakeJMP(0x58C325, CashgrabLeaderboardCodeCave, true);
	injector::MakeJMP(0x7AB20C, CashgrabTrackSelectCodeCave, true);

	// Fix Crash
	injector::MakeRangedNOP(0x7AA8E7, LANRaceSelectFixCodeCaveExit, true);
	injector::MakeJMP(0x7AA8E7, LANRaceSelectFixCodeCave, true);

	// Fix Icons and Strings - 1
	injector::MakeRangedNOP(0x539562, LANRaceModeFixCodeCaveExit, true);
	injector::MakeJMP(0x539562, LANRaceModeFixCodeCave, true);

	// Fix Icons and Strings - 2
	injector::MakeRangedNOP(0x535E8A, LANRaceModeFixCodeCave2Exit, true);
	injector::MakeJMP(0x535E8A, LANRaceModeFixCodeCave2, true);

	injector::MakeJMP(0x56E090, cFrontendDatabase_GetRaceIconHash, true); // Icon Fixes
	injector::MakeJMP(0x56E010, cFrontendDatabase_GetRaceNameHash, true); // Name Fixes

	// Flash cash icon and amount when a cashbag is grabbed
	injector::MakeJMP(0x60E098, AwardPointsCodeCave, true);

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
