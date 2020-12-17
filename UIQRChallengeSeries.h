#include "stdio.h"
#include "InGameFunctions.h"

DWORD AddRaceIconCodeCaveExit = 0x007AE8E1;
DWORD RefreshHeaderIconCodeCaveExit = 0x007A42F0;

void __declspec(naked) AddRaceIconCodeCave()
{
	__asm
	{
		call GRaceParameters_GetRaceType
		mov ecx, [_FEDatabase]
		push eax
		call cFrontendDatabase_GetRaceIconHash
		mov ebx, eax
		jmp AddRaceIconCodeCaveExit
	}
}

void __declspec(naked) RefreshHeaderIconCodeCave()
{
	__asm
	{
		mov ecx, ebx
		call GRaceParameters_GetRaceType
		mov ecx, [_FEDatabase]
		push eax
		call cFrontendDatabase_GetRaceIconHash
		mov edx, [esi - 0x1C]
		push 0
		push edx
		mov edi, eax
		push 0xB295482E
		jmp RefreshHeaderIconCodeCaveExit
	}
}
