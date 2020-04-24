#include "stdio.h"
#include "InGameFunctions.h"

void __declspec(naked) RacerStats_Cashgrab_Footer() // F27395FE - PRR_CASHBAGS_RESULTS_BUTTON_TEXT
{
	_asm
	{
		mov edx, [esi+0x1F0]
		mov eax, [esi+0x10]
		push 0xF27395FE // Cashbags
		push edx
		push eax
		push 0x597146
		retn
	}
}

void __declspec(naked) RacerStats_Cashgrab_Data()
{
	_asm
	{
		mov ecx, esi
		call SetupStat_AccumulatedCash
		mov ecx, esi
		call SetupStat_CashVariance
		mov ecx, esi
		call SetupStat_CashBehind
		pop esi
		retn 8
	}
}