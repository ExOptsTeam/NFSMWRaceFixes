#include "stdio.h"
#include "InGameFunctions.h"

void __declspec(naked) SetupStat_AccumulatedCash() // 34FACD79 - PRS_ACCUMULATED_CASH
{
	_asm
	{
		push ecx
		push esi
		mov esi, ecx
		mov eax, [esi + 0x1D4]
		mov ecx, dword ptr ds : [0x91E000]
		push edi
		push eax
		call GRaceStatus_GetRacerInfo
		mov ecx, [eax + 0x120]
		mov [esp + 8], ecx
		
		mov ecx, dword ptr ds : [0x91E000]
		call GRaceStatus_GetRaceTimeElapsed
		fcomp ds:0x890968
		fnstsw ax
		test ah, 0x41
		mov eax, [esi + 0x1D4]
		jnz NoData

		mov ecx, [esp + 8]
		push 0x89D89C // "%$0.0f"
		push 0
		push 0x34FACD79 // Accumulated Cash
		lea edx, [eax + eax * 2]
		push ecx
		lea ecx, [esi + edx * 8 + 0x2C]
		call StatsPanel_AddGenericStat
		pop edi
		pop esi
		pop ecx
		retn


		NoData:
			push 0xFC1BF40 // --
			lea eax, [eax + eax*2]
			push 0x34FACD79  // Accumulated Cash
			lea ecx, [esi + eax*8 + 0x2C]
			call StatsPanel_AddInfoStat
			pop edi
			pop esi
			pop ecx
			retn
	}
}

void __declspec(naked) SetupStat_CashVariance() // 482039FA - PRS_CASH_VARIANCE
{
	_asm
	{
		sub esp,8
		push esi
		mov esi, ecx
		mov eax, [esi + 0x1D4]
		mov ecx, dword ptr ds : [0x91E000]
		push eax
		call GRaceStatus_GetRacerInfo
		mov ecx, [esi + 0x1D4]
		push ecx
		mov ecx, dword ptr ds : [0x91E000]
		call GRaceStatus_GetBestSpeedTrapSpeed
		fstp dword ptr ds: [esp+8]
		mov edx, [esi + 0x1D4]
		mov ecx, dword ptr ds : [0x91E000]
		push edx
		call GRaceStatus_GetWorstSpeedTrapSpeed
		fstp dword ptr ds : [esp + 4]

		fld dword ptr ds : [esp + 8]
		fcomp ds : 0x890968
		fnstsw ax
		test ah, 0x41
		jnz NoData

		fld dword ptr ds : [esp + 4]
		fcomp ds : 0x890968
		fnstsw ax
		test ah, 0x41
		jnz NoData

		fld dword ptr ds : [esp + 4]
		fsub dword ptr ds : [esp + 8]
		fstp dword ptr ds : [esp + 4]

		push 0x89D89C // "%$0.0f"
		push 0
		mov eax, [esp + 0x0C]
		push 0x482039FA // Cash Variance
		push eax
		mov eax, [esi + 0x1D4]
		lea ecx, [eax + eax * 2]
		lea ecx, [esi + ecx * 8 + 0x2C]
		call StatsPanel_AddGenericStat
		pop esi
		add esp, 8
		retn


		NoData :
			mov eax, [esi+0x1D4]
			push 0xFC1BF40 // --
			lea edx, [eax + eax * 2]
			push 0x482039FA // Cash Variance
			lea ecx, [esi + edx * 8 + 0x2C]
			call StatsPanel_AddInfoStat
			pop esi
			add esp,8
			retn
	}
}

void __declspec(naked) SetupStat_CashBehind() // 2F787FDB - PRS_CASH_BEHIND
{
	_asm
	{
		push ecx
		push ebx
		push esi
		mov esi, ecx
		mov eax, [esi + 0x1D4]
		mov ecx, dword ptr ds : [0x91E000]
		push eax
		call GRaceStatus_GetRacerInfo
		mov ebx, eax
		mov eax, [esi + 0x1D0]
		test eax, eax
		jl NoData

		mov ecx, dword ptr ds : [0x91E000]
		push edi
		push eax
		call GRaceStatus_GetRacerInfo
		fld dword ptr ds: [eax + 0x120]
		fsub dword ptr ds: [ebx + 0x120]
		fabs
		fstp dword ptr ds: [esp + 0x0C]


		mov eax, [esp + 0x0C]
		push 0x89D89C // "%$0.0f"
		push 0
		push 0x2F787FDB // Cash Behind
		push eax
		mov eax, [esi + 0x1D4]
		lea ecx, [eax + eax * 2]
		lea ecx, [esi + ecx * 8 + 0x2C]
		call StatsPanel_AddGenericStat
		pop edi
		pop esi
		pop ebx
		pop ecx
		retn


		NoData :
			mov eax, [esi + 0x1D4]
			push 0xFC1BF40 // --
			lea edx, [eax + eax * 2]
			push 0x2F787FDB // Cash Behind
			lea ecx, [esi + edx * 8 + 0x2C]
			call StatsPanel_AddInfoStat
			pop esi
			pop ebx
			pop ecx
			retn
	}
}