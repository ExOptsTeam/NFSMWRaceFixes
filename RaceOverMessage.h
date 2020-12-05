#include "stdio.h"
#include "InGameFunctions.h"

// 0x58BDEE
void __declspec(naked) CashgrabNotifyRaceFinishedCodeCave()
{
	_asm
	{
		call GRaceParameters_GetRaceType
		cmp eax, 7 //cashgrab
		je cashgrab
		jmp caveexit

		cashgrab :
			push 0
			call Game_GetRacerElement
			push eax
			call Game_NotifyRaceFinished
			add esp, 8
			push 0x58BE03
			retn

			caveexit :
		push 0x58BDF3
			retn
	}

}