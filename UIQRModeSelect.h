#include "stdio.h"
#include "InGameFunctions.h"
#include "includes\IniReader.h"

int __fastcall UIQRModeSelect_Setup(DWORD* UIQRModeSelect, void* EDX_Unused)
{
	DWORD* TheIconOption;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");

	if (RaceFixesSettings.ReadInteger("Circuit", "ShowInMenu", 1) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_CIRCUIT"), bStringHash("RACETYPES_CIRCUIT"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 1;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("Sprint", "ShowInMenu", 1) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_SPRINT"), bStringHash("RACETYPES_SPRINT"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 0;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("Drag", "ShowInMenu", 1) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_DRAG"), bStringHash("RACETYPES_DRAG"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 2;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("Tollbooth", "ShowInMenu", 1) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MILESTONE_TOLLBOOTH"), bStringHash("RACETYPES_TOLLBOOTH"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 4;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("Challenge", "ShowInMenu", 0) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_CHALLENGE_SERIES"), bStringHash("RACETYPES_CHALLENGE"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 8;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("LapKnockout", "ShowInMenu", 1) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_LAP_KNOCKOUT"), bStringHash("RACETYPES_KNOCKOUT"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 3;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("Speedtrap", "ShowInMenu", 1) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MILESTONE_SPEEDTRAP"), bStringHash("RACETYPES_SPEEDTRAP"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 5;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("Cashgrab", "ShowInMenu", 0) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_MULTIPOINT_CASHGRAB"), bStringHash("RACETYPES_CASH_GRAB"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 7;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	if (RaceFixesSettings.ReadInteger("TokenPickup", "ShowInMenu", 0) != 0)
	{
		TheIconOption = (DWORD*)j_malloc(80);
		if (TheIconOption)
		{
			IconOption_Create(TheIconOption, bStringHash("MODE_ICON_MULTIPOINT_TOKEN"), bStringHash("RACETYPES_TOKEN_PICKUP"), 0);
			TheIconOption[0] = MSOption_vtable;
			TheIconOption[19] = 6;
		}
		else
		{
			TheIconOption = 0;
		}
		IconScrollerMenu_AddOption(UIQRModeSelect, TheIconOption);
	}

	int InitialPosition = FEngGetLastButton((char*)(UIQRModeSelect[4]));
	if (*((BYTE*)UIQRModeSelect + 0x129))
	{
		*((BYTE*)UIQRModeSelect + 0x11C) = 0;
		*((BYTE*)UIQRModeSelect + 0x119) = 1;
		*((BYTE*)UIQRModeSelect + 0x11A) = 0;
		UIQRModeSelect[68] = 0;
	}
	(*(int(__thiscall**)(DWORD*, unsigned int))(UIQRModeSelect[11] + 0x40))( // IconScroller::SetInitialPos(int)
		UIQRModeSelect + 0xB,
		InitialPosition);
	void *cFEng = (void*)*(DWORD*)cFEng_mInstance;
	return cFEng_QueuePackageMessage(cFEng, 0x21828323, (char*)(UIQRModeSelect[4]), 0);
}