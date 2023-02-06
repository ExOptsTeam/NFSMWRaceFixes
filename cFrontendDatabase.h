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
			{
				GRaceCustom_SetCopDensity(GRaceCustom, EDX_Unused, *(RaceSettings + 9));
				GRaceCustom_SetForceHeatLevel(GRaceCustom, EDX_Unused, _CustomRaceOptions[RaceType].ForceHeatLevel);
			}
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
		
		CIniReader ExOpts("NFSMWExtraOptionsSettings.ini");
		switch (RaceSettings[10])
		{
		case 1:
			GRaceCustom_SetTrafficDensity(GRaceCustom, ExOpts.ReadInteger("TrafficControllers", "Low", 10));
			break;
		case 2:
			GRaceCustom_SetTrafficDensity(GRaceCustom, ExOpts.ReadInteger("TrafficControllers", "Medium", 30));
			break;
		case 3:
			GRaceCustom_SetTrafficDensity(GRaceCustom, ExOpts.ReadInteger("TrafficControllers", "High", 50));
			break;
		default:
			GRaceCustom_SetTrafficDensity(GRaceCustom, 0);
			break;
		}

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
		*(BYTE*)(RaceTypeDataRef - 4) = 1;        // Laps
		*(BYTE*)(RaceTypeDataRef - 3) = 0;        // Track Direction (broken)
		*(BYTE*)(RaceTypeDataRef - 2) = 0;        // Unused??
		*(BYTE*)(RaceTypeDataRef - 1) = 3;        // Opponents
		*(BYTE*)RaceTypeDataRef = 1;              // Difficulty
		*(BYTE*)(RaceTypeDataRef + 1) = 0;        // Heat Level
		*(BYTE*)(RaceTypeDataRef + 2) = 1;        // Traffic Level
		*(BYTE*)(RaceTypeDataRef + 3) = 1;        // Catch Up
		*(BYTE*)(RaceTypeDataRef + 4) = 0;        // Cops in Race
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
		result = 0x2521E5EB; // MODE_ICON_SPRINT (Global\GlobalB.lzc, GlobalTextures.tpk)
		break;
	case 1:
		result = 0xE9638D3E; // MODE_ICON_CIRCUIT (Global\GlobalB.lzc, GlobalTextures.tpk)
		break;
	case 2:
		result = 0xAAAB31E9; // MODE_ICON_DRAG (Global\GlobalB.lzc, GlobalTextures.tpk)
		break;
	case 3:
		result = 0x3A015595; // MODE_ICON_LAP_KNOCKOUT (Global\GlobalB.lzc, GlobalTextures.tpk)
		break;
	case 4:
	case 10:
		result = 0x1A091045; // MILESTONE_TOLLBOOTH (Global\GlobalB.lzc, GlobalTextures.tpk)
		break;
	case 5:
	case 9:
		result = 0x66C9A7B6; // MILESTONE_SPEEDTRAP (Global\GlobalB.lzc, GlobalTextures.tpk)
		break;
	case 6:
		result = 0x97C5B6A0; // * MODE_ICON_MULTIPOINT_TOKEN
		break;
	case 7:
		result = 0xCE985A7A; // * MODE_ICON_MULTIPOINT_CASHGRAB
		break;
	case 8:
		result = 0x9A962438; // MODE_ICON_CHALLENGE_SERIES
		break;
	default:
		result = 0x4E6FBB02; // MAIN_ICON_QUICK_RACE
		break;
	}
	return result;
}

DWORD __fastcall cFrontendDatabase_GetMilestoneIconHash(void* _This, void* _EDX_Unused, unsigned int MilestoneTypeVltHash, bool UseAltIcon)
{
	switch (MilestoneTypeVltHash)
	{
	case 0x254230f5:				// 911_calls
		return 0xE4D7989; // * MILESTONE_911

	case 0x2377e50d:				// bounty_in_pursuit
		return 0xB4E6456B; // MILESTONE_PURSUITBOUNTY (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x850a64bc:				// cops_damaged
		return 0x88E8DE9E; // COPS_DAMAGED_ICON (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x4fc942ca:				// cops_destroyed
	case 0x3fd1884d:				// cops_destroyed_in_pursuit
		return 0xFE608E6; // COPS_TAKENOUT_ICON (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x9f8e56ce:				// cops_in_pursuit
	case 0xca9afdf0:				// total_cops_in_pursuit
		return 0x3787231C; // COPS_ICON (Global\HUDTexRace.bin, HUDTexturesSingleRace.tpk)

	case 0xdcfc0710:				// cost_to_state
	case 0xfd989a3a:				// cost_to_state_in_pursuit
		return 0x87807869; // MILESTONE_COST_TO_STATE (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x1bf724e1:				// damage_property_ticket
		return 0x45FF871; // * MILESTONE_PROPERTY_DAMAGE

	case 0x755f7845:				// driving_sidewalk_ticket
		return 0xD438F62F; // * MILESTONE_OFFROAD

	case 0x4d9777f1:				// fleeing_ticket
		return 0xA2680BB6; // * MILESTONE_RESISTING_ARREST

	case 0xe9a4423c:				// heat_meter
		return 0xD8053BD0; // * MILESTONE_HEAT

	case 0x20f1aef3:				// helis_in_pursuit
		return 0xF66AC1B6; // HELICOPTER_ICON (Global\HUDTexRace.bin, HUDTexturesSingleRace.tpk)

	case 0x15e88693:				// hit_and_run_ticket
	case 0x23b1bf0e:				// insurance_claims
		return 0xC15BFBB6; // * MILESTONE_HITNRUN

	case 0x1334dae6:				// margin_of_victory
		return 0xC7280BAF; // * MILESTONE_MARGIN_OF_VICTORY

	case 0xc8993341:				// opponents_damaged
		return 0xB3804556; // * MILESTONE_OPPONENTS_DAMAGED

	case 0x411b084e:				// outrun_pursuits_won
		return 0xD0C4EABC; // * MILESTONE_OUTRUN_PURSUITS_WON

	case 0x7457eed4:				// outrun_races_won
		return 0x38F042FB; // * MILESTONE_OUTRUN_RACES_WON

	case 0x5392e4fd:				// pursuit_evasion_time
		return 0x831B7EBE; // MILESTONE_PURSUIT_MAXTIME (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x33fa23a:					// pursuit_length
		return UseAltIcon
			? 0x950FCEBC // MILESTONE_PURSUIT_MINTIME (Global\GlobalB.lzc, GlobalTextures.tpk)
			: 0x8C76CD0F; // MILESTONE_PURSUIT_DURATION (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x2cb7caf4:				// pursuits_in_a_row
		return 0x450a616a; // MILESTONE_PURSUIT (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x8ed622ad:				// racing_ticket
		return 0x54f9862; // MILESTONE_RACING (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0xabdf316e:				// reckless_ticket
		return 0x3B2DD3C; // * MILESTONE_RECKLESS_DRIVING

	case 0xeb45f99d:				// roadblocks_dodged
		return 0xC43959D2; // MILESTONE_ROADBLOCKS (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0x9201e1f4:				// speeding_ticket
		return 0x54f9862; // * MILESTONE_SPEEDING

	case 0x9e3ebb78:				// speedtrap_speed
		return 0x66c9a7b6; // MILESTONE_SPEEDTRAP (Global\GlobalB.lzc, GlobalTextures.tpk); originally 0x3FFE9EC9 = MILESTONE_SPEEDTRAPS 

	case 0xcdf36fc2:				// tire_spikes_dodged
		return 0xE621B2EF; // MILESTONE_SPIKESTRIPS (Global\GlobalB.lzc, GlobalTextures.tpk)

	case 0xa61cac24:				// total_infractions
		return 0x6784A80E; // MILESTONE_INFRACTIONS (Global\GlobalB.lzc, GlobalTextures.tpk)
	}

	return 0xd807e9b3; // MILESTONE_MAIN (FrontEnd\FrontB.lzc, FrontEndTextures.tpk + Global\InGameA.bun, InGameTextures.tpk)
}