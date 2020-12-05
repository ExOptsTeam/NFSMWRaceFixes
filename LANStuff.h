#include "stdio.h"
#include "InGameFunctions.h"

DWORD LANRaceSelectFixCodeCaveExit = 0x7aa8ed;
DWORD LANRaceModeFixCodeCaveExit = 0x5395a3;
DWORD LANRaceModeFixCodeCave2Exit = 0x535ecb;

void __declspec(naked) LANRaceSelectFixCodeCave()
{
	_asm
	{
		cmp ecx, 0x04 //Tollbooth
		je fixassprint
		cmp ecx, 0x05 //Speedtrap
		je fixassprint
		cmp ecx, 0x06 //Multipoint
		je fixassprint
		cmp ecx, 0x07 //Cashgrab
		je fixassprint
		cmp ecx, 0x08 //Challenge
		je fixassprint
		cmp ecx, 0x03 //Knockout
		je fixascircuit
		jmp originalcode

		fixassprint :
		mov ecx, 0x00
			jmp originalcode

			fixascircuit :
		mov ecx, 0x01
			jmp originalcode

			originalcode :
		mov dword ptr ds : [edx + 0x168] , ecx
			jmp LANRaceSelectFixCodeCaveExit

	}
}

void __declspec(naked) LANRaceModeFixCodeCave()
{
	_asm
	{
		cmp eax, 0x00
		je sprint
		cmp eax, 0x01
		je circuit
		cmp eax, 0x02
		je drag
		cmp eax, 0x03
		je knockout
		cmp eax, 0x04
		je tollbooth
		cmp eax, 0x05
		je speedtrap
		cmp eax, 0x06
		je multipoint
		cmp eax, 0x07
		je cashgrab
		cmp eax, 0x08
		je challenge
		mov ebx, 0x7818F85E // RACETYPES_UNKNOWN
		mov ebp, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES

		jmp LANRaceModeFixCodeCaveExit

		circuit :
		mov ebx, 0x034FA2C1 // RACETYPES_CIRCUIT
			mov ebp, 0xE9638D3E // MODE_ICON_CIRCUIT
			jmp LANRaceModeFixCodeCaveExit

			sprint :
		mov ebx, 0xB94FD70E // RACETYPES_SPRINT
			mov ebp, 0x2521E5EB // MODE_ICON_SPRINT
			jmp LANRaceModeFixCodeCaveExit

			drag :
		mov ebx, 0x6F547E4C // RACETYPES_DRAG
			mov ebp, 0xAAAB31E9 // MODE_ICON_DRAG
			jmp LANRaceModeFixCodeCaveExit

			knockout :
		mov ebx, 0x4930F5FC // RACETYPES_KNOCKOUT
			mov ebp, 0x3A015595 // MODE_ICON_LAP_KNOCKOUT
			jmp LANRaceModeFixCodeCaveExit

			tollbooth :
		mov ebx, 0xA15E4505 // RACETYPES_TOLLBOOTH
			mov ebp, 0x1A091045 // MILESTONE_TOLLBOOTH
			jmp LANRaceModeFixCodeCaveExit

			speedtrap :
		mov ebx, 0xEE1EDC76 // RACETYPES_SPEEDTRAP
			mov ebp, 0x66C9A7B6 // MILESTONE_SPEEDTRAP
			jmp LANRaceModeFixCodeCaveExit

			multipoint :
		mov ebx, 0x634BA8DA // RACETYPES_TOKEN_PICKUP
			mov ebp, 0x97C5B6A0 // MODE_ICON_MULTIPOINT_TOKEN
			jmp LANRaceModeFixCodeCaveExit

			cashgrab :
		mov ebx, 0x0D0C9448 // RACETYPES_CASH_GRAB
			mov ebp, 0xCE985A7A // MODE_ICON_MULTIPOINT_CASHGRAB
			jmp LANRaceModeFixCodeCaveExit

			challenge :
		mov ebx, 0x213CC8D1 // RACETYPES_CHALLENGE
			mov ebp, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES
			jmp LANRaceModeFixCodeCaveExit

	}
}

void __declspec(naked) LANRaceModeFixCodeCave2()
{
	_asm
	{

		cmp eax, 0x00
		je sprint
		cmp eax, 0x01
		je circuit
		cmp eax, 0x02
		je drag
		cmp eax, 0x03
		je knockout
		cmp eax, 0x04
		je tollbooth
		cmp eax, 0x05
		je speedtrap
		cmp eax, 0x06
		je multipoint
		cmp eax, 0x07
		je cashgrab
		cmp eax, 0x08
		je challenge
		mov ebp, 0x7818F85E // RACETYPES_UNKNOWN
		mov eax, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES
		jmp LANRaceModeFixCodeCave2Exit

		circuit :
		mov ebp, 0x034FA2C1 // RACETYPES_CIRCUIT
			mov eax, 0xE9638D3E // MODE_ICON_CIRCUIT
			jmp LANRaceModeFixCodeCave2Exit

			sprint :
		mov ebp, 0xB94FD70E // RACETYPES_SPRINT
			mov eax, 0x2521E5EB // MODE_ICON_SPRINT
			jmp LANRaceModeFixCodeCave2Exit

			drag :
		mov ebp, 0x6F547E4C // RACETYPES_DRAG
			mov eax, 0xAAAB31E9 // MODE_ICON_DRAG
			jmp LANRaceModeFixCodeCave2Exit

			knockout :
		mov ebp, 0x4930F5FC // RACETYPES_KNOCKOUT
			mov eax, 0x3A015595 // MODE_ICON_LAP_KNOCKOUT
			jmp LANRaceModeFixCodeCave2Exit

			tollbooth :
		mov ebp, 0xA15E4505 // RACETYPES_TOLLBOOTH
			mov eax, 0x1A091045 // MILESTONE_TOLLBOOTH
			jmp LANRaceModeFixCodeCave2Exit

			speedtrap :
		mov ebp, 0xEE1EDC76 // RACETYPES_SPEEDTRAP
			mov eax, 0x66C9A7B6 // MILESTONE_SPEEDTRAP
			jmp LANRaceModeFixCodeCave2Exit

			multipoint :
		mov ebp, 0x634BA8DA // RACETYPES_TOKEN_PICKUP
			mov eax, 0x97C5B6A0 // MODE_ICON_MULTIPOINT_TOKEN
			jmp LANRaceModeFixCodeCave2Exit

			cashgrab :
		mov ebp, 0x0D0C9448 // RACETYPES_CASH_GRAB
			mov eax, 0xCE985A7A // MODE_ICON_MULTIPOINT_CASHGRAB
			jmp LANRaceModeFixCodeCave2Exit

			challenge :
		mov ebp, 0x213CC8D1 // RACETYPES_CHALLENGE
			mov eax, 0x9A962438 // MODE_ICON_CHALLENGE_SERIES
			jmp LANRaceModeFixCodeCave2Exit

	}
}

