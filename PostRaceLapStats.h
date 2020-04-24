#include "stdio.h"
#include "InGameFunctions.h"

void __declspec(naked) LapStats_Cashgrab_Header()
{
	_asm
	{
		mov eax, [esi + 0x10]
		push 0x34BA50FF // STAGES
		push 0x2D691760
		push eax
		call FEngSetLanguageHash

		mov eax, [esi + 0x10]
		push 0x586AB4A6
		push eax
		call FEngFindObject
		push eax
		call FEngSetVisible

		mov eax, [esi + 0x10]
		push 0x44AC8987
		push eax
		call FEngFindObject
		push eax
		call FEngSetVisible

		mov eax, [esi + 0x10]
		push 0x30EE5E68
		push eax
		call FEngFindObject
		push eax
		call FEngSetVisible

		mov eax, [esi + 0x10]
		push 0xE8B7D527 // Stage
		push 0x586AB4A6
		push eax
		call FEngSetLanguageHash

		mov eax, [esi + 0x10]
		push 0x96B05F47 // Position
		push 0x44AC8987
		push eax
		call FEngSetLanguageHash

		mov eax, [esi + 0x10]
		add esp, 0x48
		push 0x3E602952 // Cash
		push 0x30EE5E68
		push eax
		call FEngSetLanguageHash

		add esp, 0x0C

		push 0x59752C
		retn
	}
}