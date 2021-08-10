//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/defs.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "wcdefs.h"
#include "externs.h"


struct SAVERESTORE {
  COLORTYPE Player, Opponent, ProgramColor;
  BOOL Turned;
  BOOL MultiMove, AutoPlay, SingleStep;
  LEVELTYPE Level;
  double AverageTime;
  BOOL MaxLevel;
  int MoveNo;
  double ChessClockTotalTime, BlackTotalTime, WhiteTotalTime;
  int PieceValue[7];
};

static BOOL
SaveBoard(char* savefile)
{
  FILE*        gameboard;
  SAVERESTORE* save;

  save = new SAVERESTORE;
  if (!save) {
    MessageBox(hWndMain, "Not enough memory to perform operation",
      "OWL Chess", MB_OK | MB_ICONHAND);
    return 0;
  }
  if ((gameboard = fopen(savefile, "wb")) == 0) {
    sprintf(buf, "Cannot open %s for writing", savefile);
    MessageBox(hWndMain, buf, "OWL Chess", MB_OK | MB_ICONHAND);
    delete save;
    return 0;
  }

  save->Player = Player;
  save->Opponent = Opponent;
  save->ProgramColor = ProgramColor;
  save->Turned = Turned;
  save->MultiMove = MultiMove;
  save->AutoPlay = AutoPlay;
  save->SingleStep = SingleStep;
  save->Level = Level;
  save->AverageTime = AverageTime;
  save->MaxLevel = MaxLevel;
  save->MoveNo = MoveNo;
  save->ChessClockTotalTime = ChessClock.totaltime;
  save->BlackTotalTime = ChessTime[black].totaltime;
  save->WhiteTotalTime = ChessTime[white].totaltime;
  memcpy(save->PieceValue, PieceValue, 7 * sizeof(int));
  fwrite(save, sizeof(*save), 1, gameboard);
  fwrite(Board, sizeof(Board), 1, gameboard);
  fclose(gameboard);
  delete save;
  return 1;
}

void
SaveGame(char* savefile)
{
  if (strlen(savefile) > 0)
    if (!SaveBoard(savefile))
      Error("Error during Save");
}

void
LoadBoard(char* loadfile)
{
  FILE*        load;
  SAVERESTORE* restore;

  restore = new SAVERESTORE;

  if (!restore) {
    MessageBox(hWndMain, "Not enough memory to perform operation",
      "OWL Chess", MB_OK | MB_ICONHAND);
    return;
  }

  if ((load = fopen(loadfile, "rb")) == 0)
      Error("File not found");

  else {
    fread(restore, sizeof(SAVERESTORE), 1, load);
    fread(Board, sizeof(Board), 1, load);
    fclose(load);
    Player = restore->Player;
    Opponent = restore->Opponent;
    ProgramColor = restore->ProgramColor;
    Turned = restore->Turned;
    MultiMove = restore->MultiMove;
    AutoPlay = restore->AutoPlay;
    SingleStep = restore->SingleStep;
    Level = restore->Level;
    AverageTime = restore->AverageTime;
    MaxLevel = restore->MaxLevel;
    MoveNo = restore->MoveNo;
    ChessClock.totaltime = restore->ChessClockTotalTime;
    ChessTime[black].totaltime = restore->BlackTotalTime ;
    ChessTime[white].totaltime = restore->WhiteTotalTime;
    memcpy(PieceValue, restore->PieceValue, 7 * sizeof(int));
    ClearDisplay();
    InitDisplay();
    InvalidateRect(hWndMain, 0, TRUE);
    PrintCurLevel();
    ResetNewPos();
  }
  delete restore;
}

//----------------------------------------------------------------------------

void
RestoreGame(char* loadfile)
{
  if (strlen(loadfile))
    LoadBoard(loadfile);
  else
    Error("Game not loaded");
}

