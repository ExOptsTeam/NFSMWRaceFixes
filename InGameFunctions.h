#pragma once

#include "stdio.h"
#include <windows.h>

#define MSOption_vtable 0x8B75B0
#define cFEng_mInstance 0x91CADC
#define _FEDatabase 0x91CF90
#define nullString 0x890978

#define TrackDirection_vtable 0x8B78C8
#define NumLaps_vtable 0x8B788C
#define TrafficLevel_vtable 0x8B7850
#define CatchUp_vtable 0x8B7814
#define AISkill_vtable 0x8B77D8
#define NumOpponents_vtable 0x8B779C

void* (*j_malloc)(size_t) = (void* (*)(size_t))0x652AD0;
unsigned int(__thiscall* IconScrollerMenu_AddOption)(void* TheThis, void* IconOption) = (unsigned int(__thiscall*)(void*, void*))0x573960;
unsigned int(__thiscall* IconOption_Create)(void* MenuItemPtr, DWORD IconTextureHash, DWORD NameStringHash, DWORD unknown) = (unsigned int(__thiscall*)(void*, DWORD, DWORD, DWORD))0x586FA0;
unsigned int(__cdecl* FEngSetLanguageHash)(char const* FEngPackageName, unsigned int ObjectHash, unsigned int StringHash) = (unsigned int(__cdecl*)(char const*, unsigned int, unsigned int))0x525220;
unsigned int(__cdecl* FEngSetLanguageHash2)(DWORD FEString, unsigned int StringHash) = (unsigned int(__cdecl*)(DWORD, unsigned int))0x515C00;
int(__thiscall* GRaceParameters_GetRaceType)(void* TheThis) = (int(__thiscall*)(void*))0x5FAA20;
int(__cdecl* FEngFindObject)(const char* pkg_name, unsigned int obj_hash) = (int(__cdecl*)(const char*, unsigned int))0x524850;
int(__cdecl* FEngSetVisible)(void* FEObject) = (int(__cdecl*)(void*))0x514CC0;
int(__cdecl* FEPrintf)(const char* pkg_name, unsigned int obj_hash, const char* format, ...) = (int(__cdecl*)(const char*, unsigned int, const char*, ...))0x5252D0;
int(__cdecl* FEPrintf_FEString)(void* FEString, const char* format, ...) = (int(__cdecl*)(void*, const char*, ...))0x515D70;
int(__cdecl* FEngGetLastButton)(const char* pkg_name) = (int(__cdecl*)(const char*))0x571E80;
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
int(__cdecl* Game_GetRacerElement)(int Unk) = (int(__cdecl*)(int))0x60DB60;
int(__cdecl* Game_NotifyRaceFinished)(void* ISimable) = (int(__cdecl*)(void*))0x6119F0;
unsigned int(*FEHashUpper)(char* StringToHash) = (unsigned int(*)(char*))0x5AF1C0;
unsigned int(*bStringHash)(char* StringToHash) = (unsigned int(*)(char*))0x460BF0;
unsigned int(*bStringHash2)(char* StringToHash, unsigned int HashToStart) = (unsigned int(*)(char*, unsigned int))0x460C20;
int(__thiscall* cFEng_QueuePackageMessage)(void* TheThis, unsigned int Message, char const* PackageName, int FEObject) = (int(__thiscall*)(void*, unsigned int, char const*, int))0x516C90;
bool(*Game_IsOnlineGame)() = (bool(*)())0x605460;
bool(*Game_IsLANGame)() = (bool(*)())0x605480;
void(__thiscall* UIQRTrackOptions_LoadOnlineDefaults)(void* TheThis) = (void(__thiscall*)(void*))0x7A31D0;
void(__thiscall* UIQRTrackOptions_SetOnlineTogglesProperties)(void* TheThis) = (void(__thiscall*)(void*))0x7A3260;
int(__thiscall* UIWidgetMenu_SetInitialOption)(DWORD* UIWidgetMenu, int Option) = (int(__thiscall*)(DWORD*, int))0x5A5EA0;
unsigned int(__thiscall* UIQRTrackOptions_GetDisconnectPercentage)(DWORD* TheThis, int*) = (unsigned int(__thiscall*)(DWORD*, int*))0x7B4C50;
unsigned int(__cdecl* DialogInterface_DismissDialog)(int DialogNum) = (unsigned int(__cdecl*)(int))0x56C6E0;
int(__cdecl* GetDisconnectPercentageThreshold)(int* Unk) = (int(__cdecl*)(int*))0x512E40;
char* (*GetLocalizedString)(unsigned int StringHash) = (char* (*)(unsigned int))0x56BC10;
unsigned int(__cdecl* DialogInterface_ShowOneButton)(char const* Package, char const* String2, int eDialogTitle, unsigned int Button1Hash, unsigned int Button2Hash, unsigned int Button3Hash, char const* fmt, ...) = (unsigned int(__cdecl*)(char const*, char const*, int, unsigned int, unsigned int, unsigned int, char const*, ...))0x598970;
void(__thiscall* UIQRTrackOptions_BoilerPlateOnline)(DWORD* TheThis, bool*) = (void(__thiscall*)(DWORD*, bool*))0x7AC5F0;
int(__thiscall* GRaceParameters_GetCanBeReversed)(void* TheThis) = (int(__thiscall*)(void*))0x5FAC80;
unsigned int(__thiscall* FEToggleWidget_Create)(void* FEToggleWidget, bool IsEnabled) = (unsigned int(__thiscall*)(void*, bool))0x589300;
int(__thiscall* UIWidgetMenu_AddToggleOption)(void* UIWidgetMenu, void* FEToggleWidget, bool IsEnabled) = (int(__thiscall*)(void*, void*, bool))0x588570;
int(__thiscall* cFrontendDatabase_GetQuickRaceSettings)(DWORD*, signed int) = (int(__thiscall*)(DWORD*, signed int))0x0056DBE0;
int(__cdecl* cFrontendDatabase_GetDefaultCar)() = (int(__cdecl*)())0x57FB50;
int(__thiscall* GRaceCustom_SetAttribute)(DWORD* _this, unsigned int AttribHash, signed int* ValuePtr, int Unk) = (int(__thiscall*)(DWORD*, unsigned int, signed int*, int))0x5E74C0;
int(__thiscall* GRaceCustom_SetCatchUp)(DWORD* _this, bool CatchUp) = (int(__thiscall*)(DWORD*, bool))0x5E9B60;
int(__thiscall* GRaceCustom_SetCopsEnabled)(DWORD* _this, bool CopsEnabled) = (int(__thiscall*)(DWORD*, bool))0x5E9B80;
int(__thiscall* GRaceCustom_SetDifficulty)(DWORD* _this, BYTE Difficulty) = (int(__thiscall*)(DWORD*, BYTE))0x5E9AE0;
int(__thiscall* GRaceCustom_SetNumLaps)(DWORD* _this, BYTE NumLaps) = (int(__thiscall*)(DWORD*, BYTE))0x5E9A70;
int(__thiscall* GRaceCustom_SetNumOpponents)(DWORD* _this, BYTE NumOpponents) = (int(__thiscall*)(DWORD*, BYTE))0x5DCE60;
int(__thiscall* GRaceCustom_SetTrafficDensity)(DWORD* _this, BYTE TrafficDensity) = (int(__thiscall*)(DWORD*, BYTE))0x5E9A90;
int(__thiscall* GRaceCustom_SetReversed)(DWORD* _this, bool Reversed) = (int(__thiscall*)(DWORD*, bool))0x5DCE50;
int(__thiscall* FEToggleWidget_Disable)(void* FEToggleWidget) = (int(__thiscall*)(void*))0x589440;
