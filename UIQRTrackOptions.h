#include "stdio.h"
#include "InGameFunctions.h"
#include "includes\IniReader.h"

int __fastcall UIQRTrackOptions_SetupCircuit(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 1;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		*((BYTE*)FEDatabase + 400) = 3;
	}
	else
	{
		/*
		if (RaceFixesSettings.ReadInteger("Circuit", "TrackDirection", 0) == 1)
		{ // Track Direction (broken)
			if (GRaceParameters_GetCanBeReversed((DWORD*)UIQRTrackOptions[74]))
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = TrackDirection_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
		*/

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = NumLaps_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = NumOpponents_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = AISkill_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = CatchUp_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			if (RaceFixesSettings.ReadInteger("Circuit", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupLapKnockout(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		//*((BYTE*)FEDatabase + 400) = 3;
	}
	else
	{
		/*
		if (RaceFixesSettings.ReadInteger("LapKnockout", "TrackDirection", 0) == 1)
		{ // Track Direction (broken)
			if (GRaceParameters_GetCanBeReversed((DWORD*)UIQRTrackOptions[74]))
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = TrackDirection_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
		*/

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = NumLaps_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

		// Freeze lap widget if ExOpts doesn't allow us to unfreeze it
		CIniReader ExOptsSettings("NFSMWExtraOptionsSettings.ini");
		if (TheToggleWidget && (ExOptsSettings.ReadInteger("LapControllers", "UnfreezeKO", 0) != 1))
		{
			TheToggleWidget[88] = FEHashUpper("GREY");
			FEToggleWidget_Disable(TheToggleWidget);
		}

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = NumOpponents_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = AISkill_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = CatchUp_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			if (RaceFixesSettings.ReadInteger("LapKnockout", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupSprint(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		/*
		if (RaceFixesSettings.ReadInteger("Sprint", "TrackDirection", 0) == 1)
		{ // Track Direction (broken)
			if (GRaceParameters_GetCanBeReversed((DWORD*)UIQRTrackOptions[74]))
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = TrackDirection_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
		*/

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = NumOpponents_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = AISkill_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = CatchUp_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			if (RaceFixesSettings.ReadInteger("Sprint", "CopDensity", 1) == 1)
			{ 
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}

	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupDrag(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		/*
		if (RaceFixesSettings.ReadInteger("Drag", "TrackDirection", 0) == 1)
		{ // Track Direction (broken)
			if (GRaceParameters_GetCanBeReversed((DWORD*)UIQRTrackOptions[74]))
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = TrackDirection_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
		*/

		if (RaceFixesSettings.ReadInteger("Drag", "TrafficLevel", 0) == 1)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = TrafficLevel_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		}
		
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = NumOpponents_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = AISkill_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = CatchUp_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			if (RaceFixesSettings.ReadInteger("Drag", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}

	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupTollbooth(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		//*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		/*
		if (RaceFixesSettings.ReadInteger("Tollbooth", "TrackDirection", 0) == 1)
		{ // Track Direction (broken)
			if (GRaceParameters_GetCanBeReversed((DWORD*)UIQRTrackOptions[74]))
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = TrackDirection_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
		*/

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if ((!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2))
		{
			if (RaceFixesSettings.ReadInteger("Tollbooth", "NumOpponents", 0) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = NumOpponents_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = AISkill_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = CatchUp_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}

			if (RaceFixesSettings.ReadInteger("Tollbooth", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupSpeedtrap(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		//*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		/*
		if (RaceFixesSettings.ReadInteger("Speedtrap", "TrackDirection", 0) == 1)
		{ // Track Direction (broken)
			if (GRaceParameters_GetCanBeReversed((DWORD*)UIQRTrackOptions[74]))
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = TrackDirection_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}
		*/

		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = NumOpponents_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = AISkill_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = CatchUp_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			if (RaceFixesSettings.ReadInteger("Speedtrap", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}

	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupTokenPickup(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		//*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			if (RaceFixesSettings.ReadInteger("TokenPickup", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}

	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupCashgrab(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		//*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
		if (!(*((BYTE*)FEDatabase + 300) & 4) || *(BYTE*)FEDatabase != 2)
		{
			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = NumOpponents_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = AISkill_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			TheToggleWidget = (DWORD*)j_malloc(92);
			if (TheToggleWidget)
			{
				FEToggleWidget_Create(TheToggleWidget, 1);
				TheToggleWidget[0] = CatchUp_vtable;
			}
			else
			{
				TheToggleWidget = 0;
			}
			result = UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);

			if (RaceFixesSettings.ReadInteger("Cashgrab", "CopDensity", 1) == 1)
			{
				TheToggleWidget = (DWORD*)j_malloc(92);
				if (TheToggleWidget)
				{
					FEToggleWidget_Create(TheToggleWidget, 1);
					TheToggleWidget[0] = (DWORD)CopDensity_vtable;
				}
				else
				{
					TheToggleWidget = 0;
				}
				UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
			}
		}

	}
	return result;
}

int __fastcall UIQRTrackOptions_SetupChallenge(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;
	DWORD* TheToggleWidget;
	CIniReader RaceFixesSettings("NFSMWRaceFixesSettings.ini");
	int result;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		bool Somethingb = 0;
		UIQRTrackOptions_BoilerPlateOnline(UIQRTrackOptions, &Somethingb);
		result = (int)FEDatabase;
		//*((BYTE*)FEDatabase + 400) = 1;
	}
	else
	{
		TheToggleWidget = (DWORD*)j_malloc(92);
		if (TheToggleWidget)
		{
			FEToggleWidget_Create(TheToggleWidget, 1);
			TheToggleWidget[0] = TrafficLevel_vtable;
		}
		else
		{
			TheToggleWidget = 0;
		}
		UIWidgetMenu_AddToggleOption(UIQRTrackOptions, TheToggleWidget, 1);
		result = (int)FEDatabase;
	}
	return result;
}

int __fastcall UIQRTrackOptions_Setup(DWORD* UIQRTrackOptions, void* EDX_Unused)
{
	int RaceMode;
	DWORD* FEDatabase = (DWORD*)*(DWORD*)_FEDatabase;

	if (Game_IsLANGame() || Game_IsOnlineGame())
	{
		FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("OL_RACE_TRACK_OPTIONS"));
	}
	else
	{
		switch (GRaceParameters_GetRaceType((DWORD*)UIQRTrackOptions[74]))
		{
		case 0:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("SPRINT_OPTIONS"));
			break;
		case 1:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("CIRCUIT_OPTIONS"));
			break;
		case 2:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("DRAG_OPTIONS"));
			break;
		case 3:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("KNOCKOUT_OPTIONS"));
			break;
		case 4:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("TOLLBOOTH_OPTIONS"));
			break;
		case 5:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("SPEEDTRAP_OPTIONS"));
			break;
		case 6:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("TOKEN_PICKUP_OPTIONS"));
			break;
		case 7:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("CASHGRAB_OPTIONS"));
			break;
		case 8:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("CHALLENGE_OPTIONS"));
			break;
		default:
			FEngSetLanguageHash((char*)(UIQRTrackOptions[4]), 0x42ADB44C, bStringHash("OL_RACE_TRACK_OPTIONS"));
			break;
		}
	}

	if (!Game_IsLANGame() && !Game_IsOnlineGame())
	{
		RaceMode = FEDatabase[6];
		LABEL_15:
		switch (RaceMode)
		{
		case 0:
			UIQRTrackOptions_SetupSprint(UIQRTrackOptions, EDX_Unused);
			break;
		case 2:
			UIQRTrackOptions_SetupDrag(UIQRTrackOptions, EDX_Unused);
			break;
		case 4:
			UIQRTrackOptions_SetupTollbooth(UIQRTrackOptions, EDX_Unused);
			break;
		case 5:
			UIQRTrackOptions_SetupSpeedtrap(UIQRTrackOptions, EDX_Unused);
			break;
		case 6:
			UIQRTrackOptions_SetupTokenPickup(UIQRTrackOptions, EDX_Unused);
			break;
		case 7:
			UIQRTrackOptions_SetupCashgrab(UIQRTrackOptions, EDX_Unused);
			break;
		case 8:
			UIQRTrackOptions_SetupChallenge(UIQRTrackOptions, EDX_Unused);
			break;
		case 1:
			UIQRTrackOptions_SetupCircuit(UIQRTrackOptions, EDX_Unused);
			break;
		case 3:
			UIQRTrackOptions_SetupLapKnockout(UIQRTrackOptions, EDX_Unused);
			break;
		default:
			UIQRTrackOptions_SetupCircuit(UIQRTrackOptions, EDX_Unused);
			break;
		}
	
	if (Game_IsLANGame() || Game_IsOnlineGame())
		UIQRTrackOptions_SetOnlineTogglesProperties(UIQRTrackOptions);
	return UIWidgetMenu_SetInitialOption(UIQRTrackOptions, 0);
	}

	RaceMode = FEDatabase[90];
	UIQRTrackOptions_LoadOnlineDefaults(UIQRTrackOptions);
	int DisconnectPercentage[4] = { 0 };
	FEDatabase[89] = 6;
	if (Game_IsLANGame())
	{
		*(BYTE*)(UIQRTrackOptions + 80) = 1;
		goto LABEL_15;
	}
	if (*(BYTE*)(UIQRTrackOptions + 80))
		goto LABEL_15;

	if (!UIQRTrackOptions_GetDisconnectPercentage(UIQRTrackOptions, DisconnectPercentage))
	{
		*(BYTE*)(UIQRTrackOptions + 80) = 1;
		if (UIQRTrackOptions[79])
			DialogInterface_DismissDialog(UIQRTrackOptions[79]);
		char* Something = (char*)FEDatabase + 308;
		*((DWORD*)Something + 12) = GetDisconnectPercentageThreshold(DisconnectPercentage);
		goto LABEL_15;
	}

	int result = UIQRTrackOptions[79];
	if (!result)
	{
		result = DialogInterface_ShowOneButton((char*)(UIQRTrackOptions[4]), (char*)nullString, 2, bStringHash("COMMON_CANCEL"), 0x1FAB5998, 0x1FAB5998, GetLocalizedString(bStringHash("OL_MSG_DOWNLOADING_DICONNECT_PERC")));
		UIQRTrackOptions[79] = result;
	}
	return result;
}
