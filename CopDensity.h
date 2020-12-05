#include "stdio.h"
#include "InGameFunctions.h"

int __fastcall CopDensity_Act(BYTE* _this, void* Unused, const char* unk, unsigned int a3)
{
	BYTE* v4; // esi
	__int8 v5; // ebx
	int v6; // eax
	int FEDatabase = 0x91cf90;

	v4 = _this;
	v5 = *(__int8*)(cFrontendDatabase_GetQuickRaceSettings((DWORD*)*(DWORD*)FEDatabase, 11) + 9);

	if (*(unsigned char*)(*(DWORD*)FEDatabase + 0x18) == 8) // Challenge
	{
		if (a3 == 0x9120409E && --v5 < 1)
		{
			v5 = 3;
		}
		else if (a3 == 0xB5971BF1 && ++v5 > 3)
		{
			v5 = 1;
		}
	}

	else
	{
		if (a3 == 0x9120409E && --v5 < 0)
		{
			v5 = 3;
		}
		else if (a3 == 0xB5971BF1 && ++v5 > 3)
		{
			v5 = 0;
		}
	}

	*(BYTE*)(cFrontendDatabase_GetQuickRaceSettings((DWORD*)*(DWORD*)FEDatabase, 11) + 9) = v5;

	// Toggle cops option according to cop density
	if (v5 != 0) *(BYTE*)(cFrontendDatabase_GetQuickRaceSettings((DWORD*)*(DWORD*)FEDatabase, 11) + 12) = 1;
	else *(BYTE*)(cFrontendDatabase_GetQuickRaceSettings((DWORD*)*(DWORD*)FEDatabase, 11) + 12) = 0;

	v6 = *(DWORD*)v4;
	v4[42] = 1;
	(*(void(__thiscall**)(BYTE*, unsigned int))(v6 + 56))(v4, a3); // FEToggleWidget_BlinkArrows
	return (*(int(__thiscall**)(BYTE*))(*(DWORD*)v4 + 12))(v4); // CopDensity_Draw
}

int __fastcall CopDensity_Draw(DWORD* _this, void* Unused)
{
	DWORD* v1; // edi
	signed int v2; // esi
	int FEDatabase = 0x91cf90;

	if (*(unsigned char*)(*(DWORD*)FEDatabase + 0x18) == 8) // Challenge
	{
		*(unsigned char*)(*(DWORD*)FEDatabase + 0xE8) = 1;
	}
	
	v1 = _this;
	v2 = 0;
	switch (*(unsigned __int8*)(cFrontendDatabase_GetQuickRaceSettings((DWORD*)*(DWORD*)FEDatabase, 11) + 9))
	{
	case 0u:
		v2 = 0x8CDC3937; // None
		break;
	case 1u:
		v2 = 0x73C615A3; // Minimum
		break;
	case 2u:
		v2 = 0xA2CCA838; // Moderate
		break;
	case 3u:
		v2 = 0x61D1C5A5; // Maximum
		break;
	default:
		break;
	}
	FEngSetLanguageHash2(v1[12], v2);
	return FEngSetLanguageHash2(v1[11], 0x251A34F8);
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
