#include "stdio.h"
#include "InGameFunctions.h"

DWORD __fastcall cFrontendDatabase_FillCustomRace(DWORD* cFrontendDatabase, void* EDX_Unused, DWORD* GRaceCustom, BYTE* RaceSettings)
{
	int RaceType;
	int result; // eax
	BYTE TrafficDensity; // [esp-8h] [ebp-Ch]

	if (RaceSettings && GRaceCustom)
	{
		// Check race type
		RaceType = cFrontendDatabase[6];

		if (RaceType == 1 || RaceType == 3) // Circuit & Lap Knockout
		{
			GRaceCustom_SetNumLaps(GRaceCustom, *(RaceSettings + 4));
		}
		else
		{
			GRaceCustom_SetNumLaps(GRaceCustom, 1);
		}

		if (RaceType == 8) // Challenge
		{
			
			GRaceCustom_SetCopsEnabled(GRaceCustom, 1);
			GRaceCustom_SetCopDensity(GRaceCustom, EDX_Unused, 3);
		}
		else
		{
			GRaceCustom_SetCopsEnabled(GRaceCustom, *(RaceSettings + 12));
			if (*(RaceSettings + 12)) // if Cops are enabled
				GRaceCustom_SetCopDensity(GRaceCustom, EDX_Unused, *(RaceSettings + 9));
		}

		if (RaceType == 6 || RaceType == 8) // Token Pickup & Challenge
		{
			GRaceCustom_SetNumOpponents(GRaceCustom, 0);
		}
		else
		{
			GRaceCustom_SetNumOpponents(GRaceCustom, *(RaceSettings + 7));
		}

		GRaceCustom_SetCatchUp(GRaceCustom, *(RaceSettings + 11));
		GRaceCustom_SetDifficulty(GRaceCustom, *(RaceSettings + 8));
		
		if (*(RaceSettings + 10) == 1)
		{
			TrafficDensity = 10;
		}
		else
		{
			if (*(RaceSettings + 10) != 2)
			{
				if (*(RaceSettings + 10) == 3)
					GRaceCustom_SetTrafficDensity(GRaceCustom, 50);
				else
					GRaceCustom_SetTrafficDensity(GRaceCustom, 0);
				goto LABEL_13;
			}
			TrafficDensity = 30;
		}
		GRaceCustom_SetTrafficDensity(GRaceCustom, TrafficDensity);
	LABEL_13:
		result = GRaceCustom_SetReversed(GRaceCustom, *(RaceSettings + 5) == 1);
	}
	return result;
}

BYTE __fastcall cFrontendDatabase_DefaultRaceSettings(BYTE* cFrontendDatabase, void* _EDX_Unused)
{
	int DefaultCar; // eax
	int RaceTypeDataRef; // ecx
	int* RaceTypeCarRef; // edx
	char result; // al
	signed int RaceTypeCount; // [esp+10h] [ebp-4h]

	DefaultCar = cFrontendDatabase_GetDefaultCar();
	RaceTypeDataRef = (int)(cFrontendDatabase + 0x24);
	RaceTypeCount = 11;
	do
	{
		RaceTypeCarRef = (int*)(RaceTypeDataRef + 8);
		*(BYTE*)(RaceTypeDataRef - 1) = 3;        // Opponents
		*(BYTE*)RaceTypeDataRef = 1;              // Difficulty
		*(BYTE*)(RaceTypeDataRef + 1) = 1;        // Heat Level
		*(BYTE*)(RaceTypeDataRef + 2) = 1;        // Traffic Level
		*(BYTE*)(RaceTypeDataRef + 3) = 1;        // Catch Up
		*(BYTE*)(RaceTypeDataRef + 4) = 0;        // Cops in Race
		*(BYTE*)(RaceTypeDataRef - 3) = 0;        // Track Direction (broken)
		*(BYTE*)(RaceTypeDataRef - 4) = 1;        // Laps
		*(BYTE*)(RaceTypeDataRef - 2) = 0;        // Unused
		*RaceTypeCarRef = 0;
		RaceTypeCarRef[1] = 0;
		*RaceTypeCarRef = DefaultCar;
		*(BYTE*)(RaceTypeDataRef + 5) = 3;        // Lives Busted
		*(DWORD*)(RaceTypeDataRef + 12) = DefaultCar;
		RaceTypeDataRef += 0x18;
		--RaceTypeCount;
	} while (RaceTypeCount);
	result = cFrontendDatabase[0x6B];            // Knockout Opponents
	cFrontendDatabase[0x20] = 1;                 // Sprint Laps
	cFrontendDatabase[0x50] = 1;                 // Drag Laps
	cFrontendDatabase[0x98] = 1;                 // Speedtrap Laps
	cFrontendDatabase[0x80] = 1;                 // Tollbooth Laps
	cFrontendDatabase[0x68] = result;            // Knockout Laps
	cFrontendDatabase[0x83] = 0;                 // Tollbooth Opponents
	return result;
}

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
		result = 0x634BA8DA; // RACETYPES_TOKEN_PICKUP
		break;
	case 7:
		result = 0x0D0C9448; // RACETYPES_CASH_GRAB
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
		result = 0x97C5B6A0; // MODE_ICON_MULTIPOINT_TOKEN
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
