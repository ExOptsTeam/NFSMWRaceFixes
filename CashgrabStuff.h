#include "stdio.h"
#include "InGameFunctions.h"

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
			//fmul ds : 0x8A0294
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
