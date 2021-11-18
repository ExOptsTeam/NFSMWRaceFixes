#pragma once

void Game_EnterPostRaceFlow()
{
    DWORD* RaceParameters; // esi
    DWORD* MessageKind; // eax
    DWORD* RaceDatabase; // edi
    unsigned int EventHash; // eax
    DWORD* ScoreInfo; // eax
    int MessageHash[4]; // [esp-4h] [ebp-20h] BYREF
    BYTE v6[16]; // [esp+Ch] [ebp-10h] BYREF

    DWORD* GRaceStatusfObj = *(DWORD**)GRaceStatus_fObj;

    GRaceStatus_FinalizeRaceStats(GRaceStatusfObj);
    Game_AbandonRace();

    RaceParameters = (DWORD*)GRaceStatusfObj[1626];
    DWORD* WinningPlayerInfo = GRaceStatus_GetWinningPlayerInfo(GRaceStatusfObj); // unused??

    if (!RaceParameters)
    {
        goto ShowPostRaceScr;
    }

    // Play Outro Movie
    MessageHash[3] = (int)MessageHash;
    MessageHash[0] = 0x20D60DBF;
    MessageKind = (DWORD*)MFlowReadyForOutro_GetKind(v6);
    Hermes_Message_Post(MessageKind, MessageHash[0]);

    // If not career mode
    if (GRaceStatusfObj[1625] != 2)
    {
        goto ShowPostRaceScr;
    }

    // If the race shouldn't have a post race screen
    if (GRaceParameters_GetNoPostRaceScreen(RaceParameters)) 
    {
        // score stuff
        RaceDatabase = *(DWORD**)GRaceDatabase_mObj;
        EventHash = GRaceParameters_GetEventHash(RaceParameters);
        ScoreInfo = GRaceDatabase_GetScoreInfo(RaceDatabase, EventHash);
        *(DWORD*)(ScoreInfo + 4) |= 2u;
    }
    else
    {
        ShowPostRaceScr:
            FE_ShowPostRaceScreen(1);
            return;
    }
}