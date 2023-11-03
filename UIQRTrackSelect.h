#pragma once

#include "stdio.h"
#include "InGameFunctions.h"

void __fastcall UIQRTrackSelect_Setup(DWORD* _UIQRTrackSelect, void* EDX_Unused)
{
    int TitleHash; // eax
    const char* FEPackage = (const char*)_UIQRTrackSelect[4];

    DWORD* FEDatabase = *(DWORD**)_FEDatabase;

    if (!cFEng_IsPackagePushed(*(DWORD**)cFEng_mInstance, "UI_OLViewTrack.fng"))
    {
        switch (FEDatabase[6]) // Race Mode
        {
        case 0:
            TitleHash = 0xC2D85652; // TRACK_SELECT_SPRINT
            break;
        case 1:
            TitleHash = 0x3DE80A85; // TRACK_SELECT_CIRCUIT
            break;
        case 2:
            TitleHash = 0x136C5C90; // TRACK_SELECT_DRAG
            break;
        case 3:
            TitleHash = 0xD6D65640; // TRACK_SELECT_KNOCKOUT
            break;
        case 4:
            TitleHash = 0xE3AFADC9; // TRACK_SELECT_TOLLBOOTH
            break;
        case 5:
            TitleHash = 0x3070453A; // TRACK_SELECT_SPEEDTRAP
            break;
        case 6:
            TitleHash = 0x096F8B1E; // TRACK_SELECT_TOKEN_PICKUP
            break;
        case 7:
            TitleHash = 0x4F5DFD0C; // TRACK_SELECT_CASH_GRAB
            break;
        case 8:
            TitleHash = 0x638E3195; // TRACK_SELECT_CHALLENGE
            break;
        default:
            TitleHash = 0;
            break;
        }

        FEngSetLanguageHash(FEPackage, 0xB71B576D, TitleHash);
        _UIQRTrackSelect[67] = FEngFindObject(FEPackage, FEngHashString("TRACK_MAP"));

        UIQRTrackSelect_BuildPresetTrackList(_UIQRTrackSelect);
        UIQRTrackSelect_RefreshHeader(_UIQRTrackSelect);
    }
}