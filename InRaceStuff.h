#include "stdio.h"
#include "InGameFunctions.h"

char AwardStringBuf[10];
float AwardScore;

//0060E098
void __declspec(naked) AwardPointsCodeCave()
{
	_asm
	{
		// [esp] = 0x61060A // in case of a crash

		call EAXSound_PlayUISoundFX

		mov eax, dword ptr ds : [0x91E000]
		test eax, eax
		jz cexit
		mov eax, [eax + 0x1968]
		test eax, eax
		jz cexit
		mov ecx, eax
		call GRaceParameters_GetRaceType
		cmp eax, 7 // check if cashgrab
		jnz cexit

		// Show message
		mov edx, [esi]
		mov ecx, esi
		call dword ptr[edx + 0x20] // physicsobject::getplayer / pvehicle::isimable
		test eax, eax
		jz cexit
		mov edx, [eax]
		mov ecx, eax
		call dword ptr[edx + 0x20]// localplayer::gethud // 0x1F6D1670 / fenghud eax
		mov ecx, [eax + 4]
		push 0x005650B0
		call UTL_COM_Object_IList_Find
		mov esi, eax
		test esi, esi
		jz cexit

		mov edx, [esp + 0x08]
		mov AwardScore, edx
		jmp awardscorecont
		/*
		lea edx, AwardString
		push AwardScore
		push 0x8A412C
		push edx
		call bSPrintf
		*/

		cexit:
			retn

		awardscorecont:
	}

	bSPrintf(AwardStringBuf, "+%0.0f", AwardScore);

	_asm
	{
		mov edi, [esi]
		//add esp, 0x0C
		push 3
		push 0x609F6B15
		push 0x87807869
		push 0x8AB83EDB
		push 0
		lea eax, AwardStringBuf
		push eax
		mov ecx, esi
		call dword ptr [edi + 4] // 568030 - GenericMessage::RequestGenericMessage
		retn
	}
}