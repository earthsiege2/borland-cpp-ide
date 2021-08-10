/*---------------------------------------------------------------------------
 * filename - crtinit.c
 *
 * function(s)
 *        _VideoInt    - generates video interrupt
 *        _c0crtinit   - initializes crt
 *        _crtinit     - initializes _video variable
 *        turboCrt     -
 *--------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

#define INCL_CON
#include <ntbc.h>

#include <_video.h>
#include <conio.h>

HANDLE         _hin, _hout;      /* Console input and output handles */
VIDEOREC       _video = {0};
int            _LastMode;        /* Most recent TEXT mode      */
int            _C4350Mode;       /* The mode that C4350 maps to */
int _EXPDATA   _directvideo = 1;

static COORD   orig_c;           /* x and y dimensions of startup screen */

/*+------------------------------------------------------------------------+
  | This mode table will be used in determining what a mode is, and in     |
  | constructing new mode information when a new mode is to be set.        |
  +------------------------------------------------------------------------+
  |                                                                        |
  |             Color           Black & White          Monochrome          |
  |        +----------------+------------------+----------------------+    |
  |        |  40      80    |  40      80      |    40          80    |    |
  |     ---+----------------+------------------+----------------------+    |
  |     14 |  C40X14 C80X14 |  BW40X14 BW80X14 |(*) MONO14 (*) MONO14 |    |
  |     21 |  C40X21 C80X21 |  BW40X21 BW80X21 |(*) MONO21     MONO21 |    |
  |     25 |  C40    C80    |  BW40    BW80    |(*) MONO       MONO   |    |
  |     28 |  C40X28 C80X28 |  BW40X28 BW80X28 |(*) MONO28     MONO28 |    |
  |     43 |  C40X43 C80X43 |  BW40X43 BW80X43 |(*) MONO43     MONO43 |    |
  |     50 |  C40X50 C80X50 |  BW40X50 BW80X50 |(*) MONO50     MONO50 |    |
  |     60 |  C40X60 C80X60 |  BW40X60 BW80X60 |(*) MONO60     MONO60 |    |
  |     ---+----------------+------------------+----------------------+    |
  |                                                                        |
  |     (*) This isn't a valid mode on a VGA.  We include it here for      |
  |         completeness.  Something like a Herc Ramfont could probably    |
  |         do modes like these.                                           |
  +------------------------------------------------------------------------+*/

/*  BEWARE:  Code depends on the initialization orderings in this table!
 */
char _ModeTable[iTYPE][iROWS][iCOLS] =
        {
        {{C40X14,  C80X14},
         {C40X21,  C80X21},
         {C40,     C80},
         {C40X28,  C80X28},
         {C40X43,  C80X43},
         {C40X50,  C80X50},
         {C40X60,  C80X60}},

        {{BW40X14, BW80X14},
         {BW40X21, BW80X21},
         {BW40,    BW80},
         {BW40X28, BW80X28},
         {BW40X43, BW80X43},
         {BW40X50, BW80X50},
         {BW40X60, BW80X60}},

        {{MONO14, MONO14},
         {MONO21, MONO21},
         {MONO,   MONO},
         {MONO28, MONO28},
         {MONO43, MONO43},
         {MONO50, MONO50},
         {MONO50, MONO60}}
        };

static char RowLookUp[iROWS]  = {14, 21, 25, 28, 43, 50, 60};
static char ColLookUp[iROWS]  = {40, 80};

/*--------------------------------------------------------------------------*
        Determine which mode a set of parameters actually specifies.
*---------------------------------------------------------------------------*/

static int WhichMode(UCHAR type, unsigned rows, unsigned cols)
{
        int T, R, C;

        T = type;

        /* Look up the number of rows in the table.
         */
        for (R = 0; R < sizeof(RowLookUp) && RowLookUp[R] != (char)rows; R++)
            ;
        if (R == sizeof(RowLookUp))
            return -1;      /* not found */

        /* Columns must be 40 or 80.
         */
        if (cols == 40)
            C = 0;
        else if (cols == 80)
            C = 1;
        else
            return -1;

        return _ModeTable[T][R][C];
}


/*--------------------------------------------------------------------------*
Name            _init_video - crt initialization routine called by startup

Usage           void _init_video(void);

Description     _init_video is called  by the  startup code  to initialize
                the VIDEO structure. This module is linked if and only if
                there is at least  one of the video functions called  by
                the user program (they'll reference the _video structure
                at some point causing this to be dragged in).
*---------------------------------------------------------------------------*/

static void _init_video(void)
{
#pragma startup _init_video 1 /* Initializes the console video system */

    CONSOLE_SCREEN_BUFFER_INFO info;
    COORD c;

    /* Create handles for console input and output.  This should
     * work even if stdin and stdout are redirected, or we're detached.
     */
    _hin = CreateFile("CONIN$", GENERIC_READ | GENERIC_WRITE,
                    FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
                       OPEN_EXISTING, 0, NULL);
    _hout = CreateFile("CONOUT$", GENERIC_READ | GENERIC_WRITE,
                       FILE_SHARE_WRITE | FILE_SHARE_READ, NULL,
                       OPEN_EXISTING, 0, NULL);

    /* Take a look at the character attribute at the current
     * cursor position. This is what we'll use for the default.
     * We mask off the blink bit though; blinking defaults are
     * just too extreme!
     */
    if (GetConsoleScreenBufferInfo(_hout, &info) == TRUE)
    {
        orig_c = info.dwSize;       /* save original screen size */

        _video.normattr         = (uchar)info.wAttributes;
        _video.attribute        = (uchar)info.wAttributes;
        _video.screenwidth      = (uchar)info.dwSize.X;
        _video.screenheight     = (uchar)info.dwSize.Y;
    }

    /* Figure out which mode C4350 (EGA 43 or VGA 50 line) should map to.
     */
    c = GetLargestConsoleWindowSize(_hout);
    if (c.Y <= 43)
        _C4350Mode = C80X43;        /* EGA can handle only 43 lines */
    else
        _C4350Mode = C80X50;        /* VGA can handle 50 lines */

    _LastMode = WhichMode(0, _video.screenheight, _video.screenwidth);
    if (_LastMode == _C4350Mode)
        _LastMode = C4350;
    else if (_LastMode == -1)       /* unknown mode? */
        _LastMode = _ORIGMODE;

    _video.currmode = _LastMode;
    _video.snow             = 0;    /* NT never snows         */
    _video.graphicsmode     = 0;    /* We've forced text by now     */

    /* NT doesn't let you directly access the video buffer.  If
     * any attempt is made to do so, an access violation will result.
     */
    _video.displayptr = NULL;

    /* Set up the "text window" dimentions for this screen.
     */
    _video.windowx1 = 0;
    _video.windowy1 = 0;
    _video.windowx2 = _video.screenwidth  - 1;
    _video.windowy2 = _video.screenheight - 1;
}


/*--------------------------------------------------------------------------*
Name            _exit_video - crt shutdown routine

Usage           void _exit_video(void);

Description     _init_video is called by the startup code to cleanup CONIO
*---------------------------------------------------------------------------*/

static void _exit_video(void)
{
#pragma exit _exit_video 1 /* Finalizes the console video system */

    CloseHandle(_hin);
    CloseHandle(_hout);
}


/*--------------------------------------------------------------------------*
Name            _crtinit - initializes the _video variable, set new mode

Usage           void _crtinit(int newmode)

Prototype in    _video.h

Description     Initializes the _video variable
*---------------------------------------------------------------------------*/

void _crtinit(int newmode)
{
    int i, j, k;
    int actual_mode;
    COORD c;
    SMALL_RECT r;

    /* Are we being asked to restore the LAST text mode set?
     */
    if (newmode == LASTMODE)
        newmode = _LastMode;

    /* Are we being asked to use the EGA 43 or VGA 50 line mode?
     * If so, use the actual mode number for this display card.
     */
    actual_mode = newmode == C4350 ? _C4350Mode : newmode;

    /* The first thing to do is see if the mode we're being asked
     * to set is available.  We'll search the mode table to find
     * out.  *IF* its a valid mode then the table indices at the
     * point it was found can be used to construct a proper
     *'AMD' (Abbreviated Mode) structure to set that mode.
     */
    for (i=0; i<iTYPE; i++)
    for (j=0; j<iROWS; j++)
    for (k=0; k<iCOLS; k++)
    {
        if ((_ModeTable[i][j][k]) == actual_mode || newmode == _ORIGMODE)
        {
            /* OK, we found something.  First try to set the screen
             * buffer size.  This will fail if we're shrinking the
             * buffer smaller than the window, but we'll try again later.
             */
            if (newmode == _ORIGMODE)
                c = orig_c;
            else
            {
                c.X = ColLookUp[k];
                c.Y = RowLookUp[j];
            }
            SetConsoleScreenBufferSize(_hout,c);     /* ignore error */

            /* Set the window size.  This should always work.
             */
            r.Left = r.Top = 0;
            r.Right = c.X - 1;
            r.Bottom = c.Y -1;
            if (SetConsoleWindowInfo(_hout,TRUE,&r) != TRUE)
                return;

            /* Set the buffer size again.  This should always work,
             * and has no effect if it succeeded above.
             */
            if (SetConsoleScreenBufferSize(_hout,c) == TRUE)
            {
                _video.currmode = newmode;
                _video.screenwidth = c.X;
                _video.graphicsmode = 0;
                _video.screenheight = c.Y;
                _video.snow = 0;
                _video.windowx1 = _video.windowy1 = 0;
                _video.windowx2 = _video.screenwidth - 1;
                _video.windowy2 = _video.screenheight - 1;
                _LastMode = newmode;
            }
            return;
        }
    }
    return;
}
