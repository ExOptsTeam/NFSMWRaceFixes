#include "stdio.h"
#include "InGameFunctions.h"

int __fastcall GRaceCustom_SetCopDensity(DWORD* _this, void* EDX_Unused, int CopDensity)
{
	int result; // eax

	switch (CopDensity)
	{
	case 3:
		CopDensity = 100;
		break;
	case 2:
		CopDensity = 66;
		break;
	case 1:
		CopDensity = 33;
		break;
	case 0:
	default:
		CopDensity = 0;
		break;
	}

	result = GRaceCustom_SetAttribute(_this, 0xDBC08D32, &CopDensity, 0);

	return result;
}

int __fastcall GRaceCustom_SetForceHeatLevel(DWORD* _this, void* EDX_Unused, int ForceHeatLevel)
{
	_this[8] = ForceHeatLevel; // In-Game thing which sets starting heat level for qr events

	int result = GRaceCustom_SetAttribute(_this, 0xE4211F4F, &ForceHeatLevel, 0);

	return result;
}