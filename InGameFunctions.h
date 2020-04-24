#pragma once

#include "stdio.h"
#include <windows.h>

void* (*j_malloc)(size_t) = (void* (*)(size_t))0x652AD0;
unsigned int(__thiscall* IconScrollerMenu_AddOption)(void* TheThis, void* IconOption) = (unsigned int(__thiscall*)(void*, void*))0x573960;
unsigned int(__thiscall* IconOption_Create)(void* MenuItemPtr, DWORD IconTextureHash, DWORD NameStringHash, DWORD unknown) = (unsigned int(__thiscall*)(void*, DWORD, DWORD, DWORD))0x586FA0;
unsigned int(__cdecl* FEngSetLanguageHash)(char const* FEngPackageName, unsigned int ObjectHash, unsigned int StringHash) = (unsigned int(__cdecl*)(char const*, unsigned int, unsigned int))0x525220;
int(__thiscall* GRaceParameters_GetRaceType)(void* TheThis) = (int(__thiscall*)(void*))0x5FAA20;
int(__cdecl* FEngFindObject)(const char* pkg_name, unsigned int obj_hash) = (int(__cdecl*)(const char*, unsigned int))0x524850;
int(__cdecl* FEngSetVisible)(void* FEObject) = (int(__cdecl*)(void*))0x514CC0;
int(__cdecl* FEPrintf)(const char* pkg_name, unsigned int obj_hash, const char* format, ...) = (int(__cdecl*)(const char*, unsigned int, const char*, ...))0x5252D0;
int(__cdecl* FEPrintf_FEString)(void* FEString, const char* format, ...) = (int(__cdecl*)(void*, const char*, ...))0x515D70;
unsigned int(__thiscall* GRaceStatus_GetRacerInfo)(void* TheThis, int Racer) = (unsigned int(__thiscall*)(void*, int))0x5DBED0;
unsigned int(__thiscall* GRaceStatus_GetBestSpeedTrapSpeed)(void* TheThis, int Racer) = (unsigned int(__thiscall*)(void*, int))0x5DC3E0;
unsigned int(__thiscall* GRaceStatus_GetWorstSpeedTrapSpeed)(void* TheThis, int Racer) = (unsigned int(__thiscall*)(void*, int))0x5DC530;
unsigned int(__thiscall* GRaceStatus_GetRaceTimeElapsed)(void* TheThis) = (unsigned int(__thiscall*)(void*))0x5E3060;
unsigned int(__thiscall* UTL_COM_Object_IList_Find)(void* TheThis, void* Handler) = (unsigned int(__thiscall*)(void*, void*))0x5D59F0;
unsigned int(__thiscall* StatsPanel_AddStat)(void* TheThis, void* TheStat) = (unsigned int(__thiscall*)(void*, void*))0x57D6A0;
unsigned int(__thiscall* StatsPanel_AddInfoStat)(void* TheThis, DWORD StatStringHash, DWORD StatValueHash) = (unsigned int(__thiscall*)(void*, DWORD, DWORD))0x5961D0;
unsigned int(__thiscall* StatsPanel_AddGenericStat)(void* TheThis, float StatValue, DWORD StatStringHash, DWORD StatValueHash, char const* StatFormat) = (unsigned int(__thiscall*)(void*, float, DWORD, DWORD, char const*))0x5962B0;
unsigned int(__cdecl* FEngHashString)(char const* Format, ...) = (unsigned int(__cdecl*)(char const*, ...))0x573140;
int(__cdecl* FEngFindString)(const char* pkg_name, unsigned int obj_hash) = (int(__cdecl*)(const char*, unsigned int))0x5251E0;
unsigned int(__thiscall* FEStatWidget_Create)(void*, bool) = (unsigned int(__thiscall*)(void*, bool))0x5951E0;
unsigned int(__thiscall* EAXSound_PlayUISoundFX)(void*, int eMenuSoundTriggers) = (unsigned int(__thiscall*)(void*, int))0x4AE8F0;
int(__cdecl* bSPrintf)(const char* buf, const char* format, ...) = (int(__cdecl*)(const char*, const char*, ...))0x4647C0;
