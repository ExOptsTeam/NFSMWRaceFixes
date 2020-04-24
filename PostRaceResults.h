#include "stdio.h"
#include "InGameFunctions.h"

void __declspec(naked) PostRaceResultsHeadingsCodeCave()
{
	_asm
	{
		test eax,eax
		jl TollboothORInvalidMode
		cmp eax,3
		jle SprintCircuitDragORLapKO
		cmp eax,5
		je Speedtrap
		cmp eax,6
		je TollboothORInvalidMode
		cmp eax,7
		je Cashgrab
		cmp eax,8
		je TollboothORInvalidMode
		jmp TollboothORInvalidMode

		TollboothORInvalidMode:
			push 0x596577
			retn

		SprintCircuitDragORLapKO:
			push 0x59653B
			retn

		Speedtrap:
			push 0x59650E
			retn

		Cashgrab:
			mov eax, [esi + 0x10]
			push 0x96B05F47 // Position
			push 0x586AB4A6
			push eax
			call FEngSetLanguageHash

			mov eax, [esi + 0x10]
			push 0xCE678AD3 // Name
			push 0x44AC8987
			push eax
			call FEngSetLanguageHash

			push 0x3E602952 // Cash
			push 0x596566
			retn
	}
}

void __declspec(naked) PostRaceResultsStandingsCodeCave()
{
	_asm
	{
		test eax,eax
		jl InvalidMode
		cmp eax, 4
		jle SprintCircuitDragLapKOORTollbooth
		cmp eax, 5
		jz Speedtrap
		cmp eax, 6
		je InvalidMode
		cmp eax, 7
		je Cashgrab
		cmp eax, 8
		je InvalidMode
		jmp InvalidMode

		SprintCircuitDragLapKOORTollbooth:
			push 0x5965D4
			retn

		Speedtrap:
			push ebx
			push ebp
			push edi
			push 0x5965E6
			retn

		PopAndExit:
			push 0x5968CC
			retn

		InvalidMode:
			push 0x5968CF
			retn

		Cashgrab:
			push ebx
			push ebp
			push edi
			mov eax, [esi+0x1CC]
			test eax,eax
			jle PopAndExit
			lea ebp, [esi+0x1AC]
			mov dword ptr ds: [esp+0x10], 1

		GetRacerInfo:
			mov ecx, dword ptr ds : [0x91E000]
			xor edi,edi
			push edi
			call GRaceStatus_GetRacerInfo
			mov ecx, [esp + 0x10]
			mov ebx, eax
			cmp [ebx + 0x10], ecx
			je GetScore

		GetOtherRacersInfo:
			mov ecx, dword ptr ds : [0x91E000]
			push edi
			call GRaceStatus_GetRacerInfo
			mov edx, [esp + 0x10]
			mov ebx, eax
			mov eax, [ebx + 0x10]
			inc edi
			cmp eax, edx
			jnz GetOtherRacersInfo

		GetScore:
			mov eax, [ebx + 0x120]
			mov ecx, dword ptr ds: [0x91CF90]
			mov edx, [ecx + 0x10]
			mov [esp + 0x14], eax
			mov dword ptr ds: [esp + 0x18], 0x1D27DF // TEST - " "

			push 0x60
			call j_malloc
			mov edi,eax
			add esp,4
			mov [esp + 0x24], edi
			test edi,edi
			mov dword ptr ds: [esp+0x30], 1
			jz xorediedi
			mov eax, [ebp + 0x0C]
			push eax
			push 0x8A1C84 // "COLUMN3_DATA"
			push 0x8A0DAC // "%s%d"
			call FEngHashString
			mov ecx, [ebp + 0x14]
			push eax
			push ecx
			call FEngFindString
			mov edx, [ebp + 0x0C]
			push edx
			push 0x8A1CDC // "COLUMN2_DATA"
			push 0x8A0DAC // "%s%d"
			mov [esp + 0x3C], eax
			call FEngHashString
			push eax
			mov eax, [ebp + 0x14]
			push eax
			call FEngFindString
			mov ecx, [ebp + 0x0C]
			push ecx
			push 0x8A1C94 // "COLUMN1_DATA"
			push 0x8A0DAC // "%s%d"
			mov [esp + 0x54], eax
			call FEngHashString
			mov edx, [ebp + 0x14]
			push eax
			push edx
			call FEngFindString
			mov ecx, [esp + 0x5C]
			add esp, 0x3C
			push ebx
			push eax
			mov eax, [esp + 0x24]
			push eax
			push ecx
			mov ecx, edi
			call FEStatWidget_Create
			mov edx, [esp + 0x18]
			mov eax, [esp + 0x14]
			mov dword ptr ds: [edi], 0x8A1A50 // RaceStat::'vtbl'
			mov [edi+0x54], edx
			mov [edi+0x58], eax
			mov dword ptr ds: [edi + 0x5C], 0x89D89C // %$0.0f
			jmp addstat

		xorediedi:
			xor edi,edi

		addstat:
			push edi
			mov ecx, ebp
			mov dword ptr ds: [esp+0x34], 0xFFFFFFFF
			call StatsPanel_AddStat
			mov eax, [esp+0x10]
			mov ecx, [esi+0x1CC]
			inc eax
			mov [esp+0x10], eax
			dec eax
			cmp eax, ecx
			jl GetRacerInfo

			push 0x596744
			retn
	}
}