//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#ifndef EXTERNS_H
#define EXTERNS_H

#ifndef WCDEFS_H
# include "wcdefs.h"
#endif
#ifndef WINSYS_COLOR_H
# include <winsys/color.h>
#endif

class _WSYSCLASS TPoint;
class _WSYSCLASS TRect;

extern COLORTYPE Opponent;
extern PIECETAB  PieceTab[][16];
extern BOARDTYPE Board[0x78];
extern TColor    WhiteSquareColor;
extern TColor    BlackSquareColor;
extern char      buf[];

extern class TInfoWindow* TInfo;
extern HBRUSH hBlackBrush;
extern HBRUSH hWhiteBrush;
extern BOOL ShowBestLine;
extern BOOL Turned;
extern HWND hWndMain;
extern HBITMAP PieceBmpArray[][2];
extern HBITMAP MaskArray[];
extern LEVELTYPE Level;
extern double AverageTime;
extern COLORTYPE RunColor;
extern BOOL MaxLevel;
extern COLORTYPE ComputerColor;
extern int BORDERSIZE;
extern short CHARSIZE;
extern short LINESIZE;
extern BOOL Editing;
extern COLORTYPE Player;
extern COLORTYPE ProgramColor;
extern MAXTYPE MainEvalu;
extern int PVTable[2][7][0x78];
extern int DirTab[];
extern int KnightDir[];
extern int PawnDir[];
extern DEPTHTYPE Depth;
extern short INFOXSIZE, INFOYSIZE;
extern int OfficerNo[];
extern int PawnNo[];
extern MOVETYPE *MovTab;
extern MOVETYPE ZeroMove;
extern int PieceValue[];
extern CLOCKTYPE ChessTime[];
extern BOOL MultiMove, AutoPlay, SingleStep;
extern int MoveNo;
extern CLOCKTYPE ChessClock;
extern BOOL Analysis, Opan;
extern NODEVAL Nodes;
extern CASTMOVETYPE CastMove[2][2];
extern MAXTYPE RootValue;
extern MOVETYPE KeyMove;
extern BOARDIDTYPE Display[];
extern LINETYPE HintLine;
extern MAXTYPE HintEvalu;
extern MOVETYPE Next;
extern MOVETYPE PlayerMove;
extern BOOL ComputerThinking;
extern LINETYPE MainLine;
extern int MaxDepth;
extern HCURSOR hWaitCursor;
extern HMENU ThinkMenu;
extern HMENU MainMenu;
extern BOOL Running;
extern BOOL GotValidMove;
extern BOOL GameOver;
extern char EndGameMessage[];
extern BOOL NoComputerMove;
extern BOOL SoundOn;
extern WORD MessageToPost;

void   DragStart(SQUARETYPE, TPoint&);
void   DragEnd(BOOL);
void   Drag(TPoint&);
short  Attacks(COLORTYPE acolor, SQUARETYPE square);
TPoint GetSquareXY(SQUARETYPE);
void   ClearSquare(SQUARETYPE square);
void   DrawFrame(HDC, TRect&, BOOL=false);
void   GenCastSquare(SQUARETYPE new1, SQUARETYPE* castsquare,
                    SQUARETYPE* cornersquare);
void   CalcCastling(COLORTYPE incolor,  CASTDIRTYPE *cast);
void   ClearBoard();
void   ResetNewPos();
void   Error(char*);
void   ColorToPlay(COLORTYPE);
void   InitDisplay();
void   ClearDisplay();
void   ClearInfoWindow();
void   NewGame();
void   InsertPiece(PIECETYPE p, COLORTYPE c, SQUARETYPE sq);
void   PrintCurLevel();
void   InitNode(NODEVAL*);
void   InitTime(CLOCKTYPE* clock);
void   StartTime(CLOCKTYPE*);
void   StopTime(CLOCKTYPE*);
void   PrintNodes(NODEVAL*, double);
void   Perform(MOVETYPE*, BOOL);
void   TakeBackMove(MOVETYPE* move);
void   MakeMove(MOVETYPE *);
BOOL   EqMove(MOVETYPE* a, MOVETYPE* b);
void   IncNode(NODEVAL* nodes);
short  PieceAttacks(PIECETYPE, COLORTYPE, SQUARETYPE, SQUARETYPE);
FIFTYTYPE FiftyMoveCnt(void);
REPEATTYPE Repetition(short immediate);
void   PrintBestMove(MOVETYPE* mainline, MAXTYPE mainevalu);
void   DisplayMove(bool* singlestep, DEPTHTYPE maxdepth, MAXTYPE evaluation, bool);
int    StatEvalu(MOVETYPE *move);
short  KillMovGen(MOVETYPE *move);
void   CalcPVTable();
void   EnterKeyMove();
void   StartAnalysis();
void   Warning(char*);
void   PrintMove(int, COLORTYPE, MOVETYPE*, double);
void   UpdateBoard();
void   InitMovGen();
void   MovGen();
void   Message(char*);
void   CalcPieceTab();
void   ClearBestLine();
void   ResetMoves();
void   InitChessTime();
void   ClearHint();
void   ClearPVTable();
void   AdjustMoves();
void   FindMove(int maxlevel);
void   OpeningLibMsg();
char*  MoveStr(MOVETYPE*);
void   ClearMessage();
void   EnterMove(MOVETYPE* move);
void   FlashMove(MOVETYPE* move);
void   StoreMoves();
void   CalcAttackTab();
void   SaveGame(char* savefile);
void   RestoreGame(char*);
BOOL   Undo();
BOOL   Redo();
void   PrintBoard();
void   FindHintMove();
void   ShowHint();
void   Talk();
SQUARETYPE GetValidSquare(TPoint, COLORTYPE, BOOL);
void   DrawInvertedBitmap(SQUARETYPE);
void   DrawNormalBitmap(SQUARETYPE);
void   InitCommStuff();
BOOL   MoveCheck(SQUARETYPE, SQUARETYPE);
void   ProgramMove();
void   QuitProgram();
void   HideAttacks();
void   DisplayTime();

void   DoSlideMove(MOVETYPE&);
void   SlidePiece(SQUARETYPE, SQUARETYPE);
void   GenCastSquare(SQUARETYPE, SQUARETYPE*, SQUARETYPE*);
void   SetClassWindowCursor(HWND hWnd, HCURSOR hCursor);

#endif  // EXTERNS_H
