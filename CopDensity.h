#include "stdio.h"
#include "InGameFunctions.h"

int __fastcall CopDensity_Act(BYTE* _this, void* Unused, const char* unk, unsigned int msg)
{
	BYTE* v4; // esi
	__int8 val; // ebx
	int v6; // eax
	int FEDatabase = _FEDatabase;

	v4 = _this;
	val = *(__int8*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 9);

	BYTE RaceMode = *(unsigned char*)(*(DWORD*)FEDatabase + 0x18);

	if (RaceMode == 8) // Challenge
	{
		if (msg == 0x9120409E && --val < 1)
		{
			val = 3;
		}
		else if (msg == 0xB5971BF1 && ++val > 3)
		{
			val = 1;
		}
	}

	else
	{
		if (msg == 0x9120409E && --val < 0)
		{
			val = 3;
		}
		else if (msg == 0xB5971BF1 && ++val > 3)
		{
			val = 0;
		}
	}

	*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 9) = val;

	// Toggle cops option according to cop density
	if (val != 0)
	{
		*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 12) = 1; // Enable CopsInRace
	}
	else
	{
		*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 12) = 0; // Disable CopsInRace
		_CustomRaceOptions[RaceMode].ForceHeatLevel = 1; // Set condition to 1
		cFEng_QueueGameMessage(*(DWORD**)cFEng_mInstance, 0x92B703B5, unk, 0xFF); // refreshes option values
	}

	v6 = *(DWORD*)v4;
	v4[42] = 1;
	(*(void(__thiscall**)(BYTE*, unsigned int))(v6 + 56))(v4, msg); // FEToggleWidget_BlinkArrows
	return (*(int(__thiscall**)(BYTE*))(*(DWORD*)v4 + 12))(v4); // CopDensity_Draw
}

int __fastcall CopDensity_Draw(DWORD* _this, void* Unused)
{
	DWORD* v1; // edi
	unsigned int OptionDescriptorHash; // esi
	int FEDatabase = _FEDatabase;

	BYTE RaceMode = *(unsigned char*)(*(DWORD*)FEDatabase + 0x18);

	if (RaceMode == 8) // Challenge
	{
		*(unsigned char*)(*(DWORD*)FEDatabase + 0xE8) = 1;
	}
	
	v1 = _this;
	OptionDescriptorHash = 0;

	switch (*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 9))
	{
	case 0u:
		OptionDescriptorHash = 0x8CDC3937; // None
		*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 12) = 0; // Toggle cops option according to cop density
		break;
	case 1u:
		OptionDescriptorHash = 0x73C615A3; // Minimum
		*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 12) = 1; // Toggle cops option according to cop density
		break;
	case 2u:
		OptionDescriptorHash = 0xA2CCA838; // Moderate
		*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 12) = 1; // Toggle cops option according to cop density
		break;
	case 3u:
		OptionDescriptorHash = 0x61D1C5A5; // Maximum
		*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 12) = 1; // Toggle cops option according to cop density
		break;
	default:
		break;
	}
	FEngSetLanguageHash2(v1[12], OptionDescriptorHash);
	return FEngSetLanguageHash2(v1[11], bStringHash("HEAT_LEVEL"));
}

DWORD CopDensity_vtable[15] =
{
	0x7B4C20,			//Destroyer
	(DWORD)&CopDensity_Act,	// Act
	0x574540,			// FEToggleWidget::CheckMouse
	(DWORD)&CopDensity_Draw,	 // Draw
	0x589390,			// FEToggleWidget::Position
	0x5745B0,			// FEToggleWidget::Show
	0x5745F0,			// FEToggleWidget::Hide
	0x589410,			// FEToggleWidget::Enable
	0x589440,			// FEToggleWidget::Disable
	0x574630,			// FEToggleWidget::SetFocus
	0x574660,			// FEToggleWidget::UnsetFocus
	0x51A6C0,			// FEStatWidget::SetPos
	0x574480,			// FEStatWidget::SetPosX
	0x5744E0,			// FEStatWidget::SetPosY
	0x574670			// FEToggleWidget::BlinkArrows
};
