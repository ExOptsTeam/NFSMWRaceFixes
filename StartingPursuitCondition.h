#include "stdio.h"
#include "InGameFunctions.h"

int __fastcall StartingPursuitCondition_Act(BYTE* _this, void* Unused, const char* unk, unsigned int msg)
{
	BYTE* v4; // esi
	__int8 val; // ebx
	int v6; // eax
	int FEDatabase = _FEDatabase;

	v4 = _this;
	__int8 HeatLevel = *(__int8*)(cFrontendDatabase_GetQuickRaceSettings(*(DWORD**)FEDatabase, 11) + 9);

	BYTE RaceMode = *(unsigned char*)(*(DWORD*)FEDatabase + 0x18);
	val = _CustomRaceOptions[RaceMode].ForceHeatLevel;
	if (HeatLevel)
	{
		if (msg == 0x9120409E && --val < MinHeat)
		{
			val = MaxHeat;
		}
		else if (msg == 0xB5971BF1 && ++val > MaxHeat)
		{
			val = MinHeat;
		}
	}
	else
	{
		val = 1;
	}

	_CustomRaceOptions[RaceMode].ForceHeatLevel = val;

	v6 = *(DWORD*)v4;
	v4[42] = 1;
	(*(void(__thiscall**)(BYTE*, unsigned int))(v6 + 56))(v4, msg); // FEToggleWidget_BlinkArrows
	return (*(int(__thiscall**)(BYTE*))(*(DWORD*)v4 + 12))(v4); // StartingPursuitCondition_Draw
}

int __fastcall StartingPursuitCondition_Draw(DWORD* _this, void* Unused)
{
	DWORD* v1; // edi
	int FEDatabase = _FEDatabase;

	// Re-enable option if disabled by ExOpts
	injector::WriteMemory<unsigned char>(0x56DD55, 0x74, true);

	v1 = _this;

	BYTE RaceMode = *(unsigned char*)(*(DWORD*)FEDatabase + 0x18);
	int val = _CustomRaceOptions[RaceMode].ForceHeatLevel;
	
	FEPrintf_FEString((void*)_this[12], "%d", val);
	return FEngSetLanguageHash2(v1[11], bStringHash("QR_OPT_CONDITION")); // todo: change this
}

DWORD StartingPursuitCondition_vtable[15] =
{
	0x7B4C20,			//Destroyer
	(DWORD)&StartingPursuitCondition_Act,	// Act
	0x574540,			// FEToggleWidget::CheckMouse
	(DWORD)&StartingPursuitCondition_Draw,	 // Draw
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
