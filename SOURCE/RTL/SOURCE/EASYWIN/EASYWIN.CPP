/*------------------------------------------------------------------------
 * filename - easywin.cpp
 *
 * Easy Windows functions
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1991, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#define STRICT
#include <windows.h>
#include <windowsx.h>
#include <commdlg.h>

#if !defined(__FLAT__)
#include <print.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>
#include <dir.h>

// These are dummy variables that are used because this module is
//   always linked in.

#pragma option -w-par

HINSTANCE __hInstance;
HINSTANCE __hPrev;
int      __cmdShow;

extern WORD  (*__ReadBufFPtr)(char *Buffer, WORD Count);
extern void  (*__WriteBufFPtr)(char *Buffer, WORD Count);

extern "C"
{
POINT _WindowOrg  = { CW_USEDEFAULT, CW_USEDEFAULT};
POINT _WindowSize = { CW_USEDEFAULT, CW_USEDEFAULT};

POINT _ScreenSize = { 80, 25 };            // Max display screen dimensions

#if defined(__SMALL__) || defined(__MEDIUM__)
POINT _BufferSize = { 80, 100 };           // Limit memory usage in small/medium model.
#else
POINT _BufferSize = { 80, 400 };           // Uses 32000 bytes including 25 lines visible.
#endif

POINT _Cursor = { 0, 0 };                  // Cursor location
POINT _Origin = { 0, 0 };                  // Current Scroll position.
BOOL  _EasyWinActive = TRUE;               // Active flag
char *_InactiveTitle = "(Inactive %s)";    // Inactive window title
BOOL  _AutoTracking = TRUE;                // Track cursor on Write?
BOOL  _CheckEOF = TRUE;                    // Allow Ctrl-Z for EOF?
BOOL  _CheckBreak = TRUE;                  // Allow Ctrl-C for break?
BOOL  _UseDefaultPrinterFont = FALSE;      // Use default printer font.

char  _WindowTitle[80];                    // Window title
char *_OutputFileName = 0;                 // Output file to scroll into;

void  _DoneEasyWin(void);

void  _WriteBuf(char *Buffer, WORD Count);
void  _WriteChar(char Ch);

BOOL  _KeyPressed(void);
int   _ReadKey(void);
WORD  _ReadBuf(char *Buffer, WORD Count);

void   gotoxy(int X, int Y);
int    wherex(void);
int    wherey(void);
void   clrscr(void);
void   clreol(void);

void  _CursorTo(int X, int Y);
void  _ScrollTo(int X, int Y);
void  _TrackCursor(void);

HWND _GetEasyWinWindow();
}

void __InitEasyWin(void);

// MinMaxInfo array

typedef POINT TMinMaxInfo[5];

// Scroll key definition record

typedef struct
{
    BYTE Key;
    BOOL Ctrl;
    BYTE SBar;
    BYTE Action;
} TScrollKey;

// Mark key definition record

typedef struct
{
    BYTE Key;
    BYTE SBar;
    BYTE Action;
    POINT Delta;
} TMarkKey;

// big point for large calculations.

typedef struct
{
    unsigned long x, y;
} BIGPOINT;

// Easy window procedure

long FAR PASCAL _export _EasyWinProc(HWND Window, UINT Message, WPARAM WParam, LONG LParam);

// CRT window class

static WNDCLASS CrtClass =
{
    CS_HREDRAW | CS_VREDRAW, ::_EasyWinProc, 0, 0, 0, 0, 0, 0,
    NULL, "BCEasyWin"
};

static int FirstLine  = 0;                  // First line in circular buffer
static int LastLine = 0;                     // Last line in buffer written to
static int KeyCount   = 0;                  // Count of keys in KeyBuffer
static BOOL Created = FALSE;                // Window created?
static BOOL Focused = FALSE;                // Window focused?
static BOOL Reading = FALSE;                // Reading from window?
static BOOL Painting = FALSE;               // Handling wm_Paint?

static HWND CrtWindow = 0;                  // CRT window handle
static char *ScreenBuffer;                  // Screen buffer pointer
static POINT ClientSize;                    // Client area dimensions
static POINT Range;                         // Scroll bar ranges
static POINT CharSize;                      // Character cell size
static int CharAscent;                      // Character ascent
static HDC DC;                              // Global device context
static PAINTSTRUCT PS;                      // Global paint structure
static HFONT SaveFont;                      // Saved device context font
static char KeyBuffer[64];                  // Keyboard type-ahead buffer

static HFILE OutputFile;                    // Output file handle.

// Clipboard support prototypes and variables
static void EndMarkMode (BOOL copy);

static HMENU EditMenu = 0;                  // For InitMenuPopup message
static BOOL MarkMode = FALSE;               // In marking mode
static BOOL MouseMarkMode = FALSE;          // Using the mouse for text marking
static BOOL MouseCapture = FALSE;           // Draging mouse to select text
static POINT BlockStart = { 0, 0 };         // Initial corner of marked block
static POINT BlockEnd = { 0, 0 };           // Final corner of marked block

static char far *PasteBlock;                // Pointer to block of pasted text
static unsigned PasteIndex;                 // Index into pasted text
static unsigned PasteMax;                   // Max valid index for pasted text
static unsigned PastePoint;                 // Index of keyboard buffer when
                                            //  text was pasted into app.

// Error messages

static const char *PrinterErrorText = "Print error: %s";
static const char *PrinterErrorCaption = "EasyWin Print Error";
static const char *PrinterDocumentName = "EasyWin Document";
static const char *FontSizeErrorMsg = "Unable to pick desired font size.  Use default?";
static const char *PrError_StartDoc = "StartDoc failed";

// Mark keys table

const MarkKeyCount = 8;
const TMarkKey MarkKeys[MarkKeyCount]  =
    {
        { VK_LEFT,  SB_HORZ, SB_LINEUP,   {0, 1} },
        { VK_RIGHT, SB_HORZ, SB_LINEDOWN, {1, 1} },
        { VK_HOME,  SB_HORZ, SB_TOP,      {0, 1} },
        { VK_END,   SB_HORZ, SB_BOTTOM,   {0, 1} },
        { VK_UP,    SB_VERT, SB_LINEUP,   {1, 0} },
        { VK_DOWN,  SB_VERT, SB_LINEDOWN, {1, 1} },
        { VK_PRIOR, SB_VERT, SB_PAGEUP,   {1, 0} },
        { VK_NEXT,  SB_VERT, SB_PAGEDOWN, {1, 0} },
    };


// Scroll keys table

const int ScrollKeyCount = 12;
const TScrollKey ScrollKeys[ScrollKeyCount]  =
    {
        { VK_LEFT,  FALSE, SB_HORZ, SB_LINEUP },
        { VK_RIGHT, FALSE, SB_HORZ, SB_LINEDOWN },
        { VK_LEFT,  TRUE,  SB_HORZ, SB_PAGEUP },
        { VK_RIGHT, TRUE,  SB_HORZ, SB_PAGEDOWN },
        { VK_HOME,  FALSE, SB_HORZ, SB_TOP },
        { VK_END,   FALSE, SB_HORZ, SB_BOTTOM },
        { VK_UP,    FALSE, SB_VERT, SB_LINEUP },
        { VK_DOWN,  FALSE, SB_VERT, SB_LINEDOWN },
        { VK_PRIOR, FALSE, SB_VERT, SB_PAGEUP },
        { VK_NEXT,  FALSE, SB_VERT, SB_PAGEDOWN },
        { VK_HOME,  TRUE,  SB_VERT, SB_TOP },
        { VK_END,   TRUE,  SB_VERT, SB_BOTTOM }
    };


/* Menu definitions.
 */
#define IDM_BASE            200
#define IDM_MARK            IDM_BASE + 0
#define IDM_COPY            IDM_BASE + 1
#define IDM_PASTE           IDM_BASE + 2
#define IDM_SELECT_ALL      IDM_BASE + 3
#define IDM_PRINT           IDM_BASE + 4

// Menu structures.
struct MENU_ITEM
{
    char *text;
    unsigned flags;
    unsigned id;
};

static MENU_ITEM edit_menu[] =
    {
        { "&Edit", MF_POPUP, 0 },
        { "&Mark", MF_STRING, IDM_MARK },
        { "&Copy\tEnter", MF_STRING | MF_GRAYED, IDM_COPY },
        { "&Paste", MF_STRING, IDM_PASTE },
        { "&Select All", MF_STRING, IDM_SELECT_ALL },
    };
const unsigned items_in_edit_menu = sizeof( edit_menu ) / sizeof( MENU_ITEM );

static MENU_ITEM print_menu[] =
    {
        { "&Print", MF_STRING, IDM_PRINT },
    };
const unsigned items_in_print_menu = sizeof( print_menu ) / sizeof( MENU_ITEM );

static MENU_ITEM *easywin_menu[] =
    {
        edit_menu,
        print_menu,
        0
    };

static unsigned easywin_items[] =
    {
        items_in_edit_menu,
        items_in_print_menu,
    };


// Swap function

template <class T> inline void Swap (T& x, T& y)
{
    T t = x;
    x = y;
    y = t;
}

// Return the smaller of two integer values

inline int Min(int X, int Y)
{
    return((X < Y)? X : Y);
}

//Return the larger of two integer values

inline int Max(int X, int Y)
{
    return((X > Y)? X: Y);
}

// Allocate device context

static void InitDeviceContext (void)
{
    if (Painting)
        DC = BeginPaint (CrtWindow, &PS);
    else
    {
        DC = GetDC (CrtWindow);
        SaveFont = SelectFont (DC, GetStockObject(SYSTEM_FIXED_FONT));
    }
}

// Release device context

static void DoneDeviceContext (void)
{
    if (Painting)
        EndPaint (CrtWindow, &PS);
    else
    {
        SelectObject (DC, SaveFont);
        ReleaseDC (CrtWindow, DC);
    }
}

// Determine if there is a default printer.

static BOOL GetDefaultPrinter()
{
/*
    // Use PringDlg function to query for default printer rather than read
    //   INI file directly.  This is supposed to be more portable... it is
    //   definitely slower.
    PRINTDLG pdlg;
    BOOL print_flag;

    memset (&pdlg, 0, sizeof (pdlg));
    pdlg.lStructSize = sizeof (pdlg);
    pdlg.hDevMode = pdlg.hDevNames = 0;
    pdlg.Flags = PD_RETURNDEFAULT;
    PrintDlg (&pdlg);

    if (pdlg.hDevNames == 0)
        print_flag = FALSE;
    else
        print_flag = TRUE;

    // Free memory allocated for us by PrintDlg.
    if (pdlg.hDevNames)
        ::GlobalFree (pdlg.hDevNames);
    if (pdlg.hDevMode)
        ::GlobalFree (pdlg.hDevMode);

    return print_flag;
*/
    // Old style method of reading the INI file directly.
    char print_profile[256];

    if (GetProfileString ("windows", "device", ",,,", print_profile, sizeof (print_profile)) == 0)
        return FALSE;

    if (!strtok (print_profile, ","))
        return FALSE;

    char *device = strtok (0, ",");
    if (!device || !strlen (device))
        return FALSE;

    char *port = strtok (0, ",");
    if (!port || !strlen (port))
        return FALSE;

    return TRUE;
}

// Show caret

static void ShowCursor (void)
{
    if (MarkMode)
    {
        POINT delta;

        if (BlockEnd.x - BlockStart.x > 0)
            delta.x = -1;
        else
            delta.x = 0;

        if (BlockEnd.y - BlockStart.y > 0)
            delta.y = -1;
        else
            delta.y = 0;

        CreateCaret (CrtWindow, 0, CharSize.x, CharSize.y);
        SetCaretPos ((BlockEnd.x-_Origin.x+delta.x) * CharSize.x,
                     (BlockEnd.y-_Origin.y+delta.y) * CharSize.y);
    }
    else
    {
        CreateCaret (CrtWindow, 0, CharSize.x, 2);
        SetCaretPos ((_Cursor.x-_Origin.x) * CharSize.x,
                     (_Cursor.y-_Origin.y) * CharSize.y + CharAscent);
    }
    ShowCaret (CrtWindow);
}

// Hide caret

static void HideCursor (void)
{
    DestroyCaret ();
}

// Update scroll bars

static void SetScrollBars (void)
{
    if (Range.x > 0)
    {
        ShowScrollBar (CrtWindow, SB_HORZ, TRUE);
        SetScrollRange (CrtWindow, SB_HORZ, 0, Max (1, Range.x), FALSE);
    }
    else
        ShowScrollBar (CrtWindow, SB_HORZ, FALSE);

    SetScrollPos (CrtWindow, SB_HORZ, _Origin.x, TRUE);
    SetScrollRange (CrtWindow, SB_VERT, 0, Max (1, Range.y), FALSE);
    SetScrollPos (CrtWindow, SB_VERT, _Origin.y, TRUE);
}

// Terminate window

static void Terminate (void)
{
    if (Focused && Reading)
        HideCursor ();
    exit (-1);
}

// Get EasyWin window handle

HWND _GetEasyWinWindow()
{
    return CrtWindow;
}

// Set cursor position

void _CursorTo(int X, int Y)
{
    _Cursor.x = Max( 0, Min(X, _BufferSize.x - 1));
    _Cursor.y = Max( 0, Min(Y, _BufferSize.y - 1));
}

// Scroll window to given origin

void _ScrollTo(int X, int Y)
{
    if (Created)
    {
        X = Max (0, Min (X, Range.x));
        Y = Max (0, Min (Y, Range.y));
        if ((X != _Origin.x) || (Y != _Origin.y))
        {
            if (X != _Origin.x)
                SetScrollPos (CrtWindow, SB_HORZ, X, TRUE);
            if (Y != _Origin.y)
                SetScrollPos (CrtWindow, SB_VERT, Y, TRUE);
            ScrollWindow (CrtWindow,
                          (_Origin.x - X) * CharSize.x,
                          (_Origin.y - Y) * CharSize.y, NULL, NULL);
            _Origin.x = X;
            _Origin.y = Y;
            UpdateWindow (CrtWindow);
        }
    }
}

// Scroll to make cursor visible

void _TrackCursor (void)
{
    _ScrollTo (Max (_Cursor.x - ClientSize.x + 1,
                    Min (_Origin.x, _Cursor.x)),
               Max (_Cursor.y - ClientSize.y + 1,
                    Min (_Origin.y, _Cursor.y))
              );
}

// Return pointer to location in buffer, regardless of screen portion.

static char *BufferPtr (int X, int Y)
{
    Y += FirstLine;
    if (Y >= _BufferSize.y)
        Y -= _BufferSize.y;
    return (ScreenBuffer + (Y * _BufferSize.x + X));
}


// Open output file.

static void OpenOutputFile()
{
    if( _OutputFileName )
    {
        OFSTRUCT ofs;
        OutputFile = OpenFile( _OutputFileName, &ofs, OF_CREATE | OF_WRITE );
        if( OutputFile == HFILE_ERROR )
        {
            char buf[80];
            wsprintf (buf, "OpenFile returned error code %d.  Output file will not be used.", ofs.nErrCode);
            ::MessageBox (CrtWindow, buf, "EasyWin", MB_TASKMODAL | MB_OK );
            _OutputFileName = 0;
            OutputFile = 0;
        }
    }
}

// Write a line into the output file, assuming that 'line' is already
// normalized.

static void WriteLine (int line)
{
    if (_OutputFileName)
    {
        int L, R;
        char *data = BufferPtr (0, line);

        for (L = 0, R = _BufferSize.x-1; R >= L && data[R] == ' '; R--  )
            ;

        _lwrite (OutputFile, data, R+1);
        _lwrite (OutputFile, "\r\n", 2);
    }
}

// Write out what's left of buffer.

static void WriteRemainingBuffer()
{
    int l = FirstLine;

    while (1)
    {
        WriteLine (l);

        if (l == LastLine)
            break;

        if (++l >= _BufferSize.y)
            l -= _BufferSize.y;
    }

    if (OutputFile)
	_lclose (OutputFile);
}

// Update text on cursor line

static void ShowText (int L, int R)
{
    if (L < R)
    {
        InitDeviceContext ();
        TextOut (DC, (L - _Origin.x) * CharSize.x,
                 (_Cursor.y - _Origin.y) * CharSize.y,
                 BufferPtr(L, _Cursor.y), R - L);
        DoneDeviceContext ();
    }
}

// Write text buffer to window

static void NewLine(int& L, int& R)
{
    BOOL scrollFlag = FALSE;

    ShowText(L, R);
    L = 0;
    R = 0;
    _Cursor.x = 0;
    ++_Cursor.y;

    if (_Cursor.y > LastLine)
        LastLine = _Cursor.y;

    if (_Cursor.y - _Origin.y >= ClientSize.y)
    {
        // We need to scroll the screen, but cannot actually do it yet.
        scrollFlag = TRUE;
    }

    if (_Cursor.y >= _BufferSize.y )
    {
        // FirstLine needs to be incremented and other indexes need adjustment.
        LastLine = _Cursor.y = _BufferSize.y-1;

        WriteLine (0);
        if (++FirstLine == _BufferSize.y)
            FirstLine = 0;

        memset (BufferPtr (0, _Cursor.y), ' ', _BufferSize.x);
    }
    else
    {
        Range.y = Max (0, LastLine-ClientSize.y+1);
        if (scrollFlag)
            _Origin.y++;

        SetScrollBars();
    }

    if (scrollFlag)
    {
        ::ScrollWindow (CrtWindow, 0, -CharSize.y, NULL, NULL);
        ::UpdateWindow (CrtWindow);
    }
}

void _WriteBuf(char *Buffer, WORD Count)
{
    int L, R;

    __InitEasyWin();
    L = _Cursor.x;
    R = _Cursor.x;
    while (Count > 0)
    {
        if (Buffer[0] == -1)
            Buffer[0] = ' ';

        switch (Buffer[0])
        {
        case 10:
            NewLine(L, R);
            break;

        case 13:
            _Cursor.x = 0;
            L = 0;
            break;

        case  9:
            do
            {
                *(BufferPtr(_Cursor.x, _Cursor.y)) = ' ';
                ++_Cursor.x;
                if (_Cursor.x > R)
                    R = _Cursor.x;
                if (_Cursor.x == _BufferSize.x)
                {
                    NewLine(L, R);
                    break;
                }
            } while (_Cursor.x % 8);
            break;

        case  8:
            if (_Cursor.x > 0)
            {
                --_Cursor.x;
                *(BufferPtr(_Cursor.x, _Cursor.y)) = ' ';
                if (_Cursor.x < L )
                    L = _Cursor.x;
            }
            break;

        case  7:
            MessageBeep(0);
            break;

        default:
            *(BufferPtr(_Cursor.x, _Cursor.y)) = Buffer[0];
            ++_Cursor.x;
            if (_Cursor.x > R)
                R = _Cursor.x;
            if (_Cursor.x == _BufferSize.x)
                NewLine(L, R);
        }
        ++Buffer;
        --Count;
    }

    ShowText(L, R);
    if (_AutoTracking)
        _TrackCursor();
}

// Write character to window

void _WriteChar(char Ch)
{
    _WriteBuf(&Ch, 1);
}

// Return keyboard status

BOOL _KeyPressed(void)
{
    MSG M;

    __InitEasyWin();
    while (PeekMessage(&M, 0, 0, 0, PM_REMOVE))
    {
        if (M.message == WM_QUIT)
            Terminate();

        TranslateMessage(&M);
        DispatchMessage(&M);
    }
    return (BOOL)(KeyCount > 0  || PasteBlock != 0);
}

// Read key from window

int _ReadKey(void)
{
    int readkey;

    _TrackCursor();
    if (!_KeyPressed())
    {
        Reading = TRUE;
        if (Focused)
            ShowCursor();
        do
        {
        } while (!_KeyPressed());
        if (Focused)
            HideCursor();
        Reading = FALSE;
    }

    // Read character out of pasted block, if there is one.
    if (PasteBlock)
    {
        if (PastePoint == 1)
        {
            if (PasteIndex < PasteMax-1)
                return PasteBlock[PasteIndex++];
            else
            {
                char last = PasteBlock[PasteIndex];

                GlobalFreePtr (PasteBlock);
                PastePoint = 0;
                PasteBlock = 0;

                return last;
            }
        }
        else
            PastePoint--;
    }

    readkey = KeyBuffer[0];
    --KeyCount;
    memmove(KeyBuffer, KeyBuffer+1, KeyCount);
    return readkey;
}

// Read text buffer from window

WORD _ReadBuf(char *Buffer, WORD Count)
{
    unsigned char Ch;
    WORD I;

    I = 0;
    do
    {
        Ch = _ReadKey();
        if (Ch == 8)
        {
            if (I > 0)
            {
                --I;
                _WriteChar(8);
            }
        }
        else if (Ch >= 32)
        {
            if (I < Count)
            {
                Buffer[I++] = Ch;
                _WriteChar(Ch);
            }
        }
    } while (!((Ch == 13) || (_CheckEOF && (Ch == 26))));

    if (I < Count - 2)
    {
        Buffer[I++] = Ch;
        if (Ch == 13)
        {
            Buffer[I++] = 10;
            _WriteChar(10);
        }
    }
    _TrackCursor();
    return I;
}

// Set cursor position }

void gotoxy(int X, int Y)
{
    _CursorTo(_Origin.x + X - 1, _Origin.y + Y - 1);
}

// Return cursor X position

int wherex(void)
{
    return (_Cursor.x - _Origin.x + 1);
}

// Return cursor Y position

int wherey(void)
{
    return(_Cursor.y - _Origin.y + 1);
}

// Clear screen

void clrscr(void)
{
    __InitEasyWin();
    memset(ScreenBuffer, ' ', _BufferSize.x * _BufferSize.y);
    FirstLine = LastLine = 0;
    _Cursor.x = _Cursor.y = 0;
    _Origin.x = _Origin.y = 0;
    Range.x = Range.y = 0;
    SetScrollBars();
    InvalidateRect(CrtWindow, NULL, TRUE);
    UpdateWindow(CrtWindow);
}

// Clear to end of line

void clreol(void)
{
    __InitEasyWin();
    memset(BufferPtr(_Cursor.x, _Cursor.y), ' ',_BufferSize.x - _Cursor.x);
    ShowText(_Cursor.x, _BufferSize.x);
}

inline int LoVal(LONG LVal)
{
    return (((unsigned *)&LVal)[0]);
}

inline int HiVal(LONG LVal)
{
    return (((unsigned *)&LVal)[1]);
}


// WM_CREATE message handler

static BOOL EasyWnd_OnCreate( HWND hwnd, CREATESTRUCT FAR* lpCreateStruct )
{
    Created = TRUE;
    ScreenBuffer = (char *) malloc(_BufferSize.x * _BufferSize.y );
    memset(ScreenBuffer, ' ', _BufferSize.x * _BufferSize.y );

    // Add main menu to easywin window.
    int mx, max_top_level;
    HMENU system_menu = ::GetSystemMenu (CrtWindow, FALSE);

    for( mx = 0; easywin_menu[mx] != 0; mx++ )
        ;
    max_top_level = mx;

    for( mx = 0; mx < max_top_level; mx++ )
    {
        MENU_ITEM *popup = &easywin_menu[mx][0];
        HMENU child;

        if (popup->flags & MF_POPUP)
        {
            child = CreateMenu ();

            // Save menu handle of Edit menu.
            if (easywin_menu[mx][1].id == IDM_MARK)
                EditMenu = child;

            for (unsigned i = 1; i < easywin_items[mx]; i++)
            {
                MENU_ITEM *mi = &easywin_menu[mx][i];
                ::AppendMenu (child, mi->flags, mi->id, mi->text);
            }
        }
        else
            child = (HMENU) popup->id;

        ::AppendMenu (system_menu, popup->flags, (UINT) child, popup->text);
    }

    // Disable 'close' on system menu if _CheckBreak is not set.
    if (!_CheckBreak)
        ::EnableMenuItem (system_menu, SC_CLOSE, MF_DISABLED | MF_GRAYED);

    return TRUE;
}


// WM_PAINT message handler

static void EasyWnd_OnPaint (HWND hwnd)
{
    int X1, X2, Y1, Y2;
    RECT ur;

    if (GetUpdateRect (hwnd, &ur, FALSE) )
    {
        RECT cr, dummy;
        HDC mem_dc;
        HBITMAP mem_bitmap, save_bitmap;
        HFONT save_font;

        Painting = TRUE;
        InitDeviceContext ();

        ::GetClientRect (hwnd, &cr);
        mem_dc = ::CreateCompatibleDC (DC);
        mem_bitmap = ::CreateCompatibleBitmap (DC, cr.right, cr.bottom);
        save_font = SelectFont (mem_dc, GetStockFont (SYSTEM_FIXED_FONT));
        save_bitmap = SelectBitmap (mem_dc, mem_bitmap);

        HBRUSH bkgnd = ::CreateSolidBrush( GetSysColor (COLOR_WINDOW));
        ::FillRect (mem_dc, &ur, bkgnd);
        DeleteBrush (bkgnd);

        X1 = Max (0, ur.left / CharSize.x + _Origin.x);
        X2 = Min (_BufferSize.x, (ur.right + CharSize.x - 1) / CharSize.x + _Origin.x);
        Y1 = Max (0, ur.top / CharSize.y + _Origin.y);
        Y2 = Min (_BufferSize.y, (ur.bottom + CharSize.y - 1) / CharSize.y + _Origin.y);

        while (Y1 < Y2)
        {
            TextOut (mem_dc, (X1 - _Origin.x) * CharSize.x, (Y1 - _Origin.y) * CharSize.y, BufferPtr(X1, Y1), X2 - X1);
            ++Y1;
        }

        if (MarkMode)
        {
            cr.left = (Min (BlockStart.x, BlockEnd.x) - _Origin.x) * CharSize.x;
            cr.right = (Max (BlockStart.x, BlockEnd.x) - _Origin.x) * CharSize.x;
            cr.top = (Min (BlockStart.y, BlockEnd.y) - _Origin.y) * CharSize.y;
            cr.bottom = (Max (BlockStart.y, BlockEnd.y) - _Origin.y) * CharSize.y;

            if (::IntersectRect (&dummy, &ur, &cr))
                ::InvertRect (mem_dc, &cr);
        }

        ::BitBlt (DC, ur.left, ur.top, ur.right-ur.left, ur.bottom-ur.top, mem_dc, ur.left, ur.top, SRCCOPY);

        SelectBitmap (mem_dc, save_bitmap);
        SelectFont (mem_dc, save_font);
        ::DeleteBitmap (mem_bitmap);
        ::DeleteDC (mem_dc);

        DoneDeviceContext ();
        Painting = FALSE;
    }
}


// WM_ERASEBKGND message

static BOOL EasyWnd_OnEraseBkgnd(HWND hwnd, HDC hdc)
{
    return TRUE;
}


// WM_VSCROLL and WM_HSCROLL message handler }

static int GetNewPos (int Pos, int Page, int Range, int Action, int Thumb)
{
    switch (Action)
    {
    case SB_LINEUP:
        return (Pos - 1);

    case SB_LINEDOWN:
        return (Pos + 1);

    case SB_PAGEUP:
        return (Pos - Page);

    case SB_PAGEDOWN:
        return (Pos + Page);

    case SB_TOP:
        return (0);

    case SB_BOTTOM:
        return (Range);

    case SB_THUMBPOSITION:
    case SB_THUMBTRACK:
        return (Thumb);

    default:
        return (Pos);
    }
}

static void WindowScroll (int Which, int Action, int Thumb)
{
    int X, Y;

    X = _Origin.x;
    Y = _Origin.y;
    switch (Which)
    {
    case SB_HORZ:
        X = GetNewPos (X, ClientSize.x / 2, Range.x, Action, Thumb);
        break;

    case SB_VERT:
        Y = GetNewPos (Y, ClientSize.y, Range.y, Action, Thumb);
        break;
    }
    _ScrollTo (X, Y);
}

inline void EasyWnd_OnHScroll (HWND hwnd, HWND hwndCtl, UINT code, int pos)
{
    WindowScroll (SB_HORZ, code, pos);
}

inline void EasyWnd_OnVScroll (HWND hwnd, HWND hwndCtl, UINT code, int pos)
{
    WindowScroll (SB_VERT, code, pos);
}


// WM_SIZE message handler

static void EasyWnd_OnSize ( HWND hwnd, UINT state, int X, int Y )
{
    if (Focused && Reading)
        HideCursor();
    ClientSize.x = X / CharSize.x;
    ClientSize.y = Y / CharSize.y;

    Range.x = Max (0, _BufferSize.x - ClientSize.x);
    Range.y = Max (0, LastLine - ClientSize.y + 1);

    if (Range.x == 0)
    {
        RECT r;

        GetClientRect (CrtWindow, &r);
        if (r.bottom > _ScreenSize.y * CharSize.y)
        {
            GetWindowRect (CrtWindow, &r);
            r.bottom -= GetSystemMetrics(SM_CYHSCROLL)-1;
            SetWindowPos (CrtWindow, 0, r.left, r.top, r.right - r.left, r.bottom - r.top, SWP_NOMOVE | SWP_NOZORDER);
        }
    }

    _Origin.x = Min (_Origin.x, Range.x);
    _Origin.y = Min (_Origin.y, Range.y);
    SetScrollBars ();
    if (Focused && Reading)
        ShowCursor ();
}


// WM_GETMINMAXINFO message handler

static void EasyWnd_OnGetMinMaxInfo( HWND hwnd, MINMAXINFO FAR *lpMinMaxInfo )
{
    int X, Y;
    TEXTMETRIC Metrics;

    InitDeviceContext();
    GetTextMetrics(DC, &Metrics);
    CharSize.x = Metrics.tmMaxCharWidth;
    CharSize.y = Metrics.tmHeight + Metrics.tmExternalLeading;
    CharAscent = Metrics.tmAscent;
    X = Min (_ScreenSize.x * CharSize.x + GetSystemMetrics(SM_CXVSCROLL) - 1,
             GetSystemMetrics(SM_CXSCREEN)) +
        GetSystemMetrics(SM_CXFRAME) * 2;
    Y = Min (_ScreenSize.y * CharSize.y + GetSystemMetrics(SM_CYHSCROLL) + GetSystemMetrics(SM_CYCAPTION) - 2,
             GetSystemMetrics(SM_CYSCREEN)) +
        GetSystemMetrics(SM_CYFRAME) * 2;
    lpMinMaxInfo->ptMaxSize.x = X;
    lpMinMaxInfo->ptMaxSize.y = Y;
    lpMinMaxInfo->ptMinTrackSize.x = CharSize.x * 16 +
                                     GetSystemMetrics(SM_CXVSCROLL) +
                                     GetSystemMetrics(SM_CXFRAME) * 2;
    lpMinMaxInfo->ptMinTrackSize.y = CharSize.y * 4 +
                                     GetSystemMetrics(SM_CYHSCROLL) +
                                     GetSystemMetrics(SM_CYCAPTION) +
                                     GetSystemMetrics(SM_CYFRAME) * 2;
    lpMinMaxInfo->ptMaxTrackSize.x = X;
    lpMinMaxInfo->ptMaxTrackSize.y = Y;
    DoneDeviceContext();
}


// WM_CHAR message handler

static void EasyWnd_OnChar( HWND hwnd, wchar_t Ch, int cRepeat )
{
    if (_CheckBreak  && (Ch == 3))
        Terminate();

    if (MarkMode)
    {
        switch (Ch)
        {
        case VK_RETURN:
            EndMarkMode (TRUE);
            break;

        case VK_ESCAPE:
            EndMarkMode (FALSE);
            break;

        default:
            ::MessageBeep (-1);
            break;
        }
    }
    else if (KeyCount < sizeof(KeyBuffer))
    {
        KeyBuffer[KeyCount] = Ch;
        ++KeyCount;
    }
}


// WM_KEYDOWN message handler

inline static void InvalidateBlock (POINT s, POINT e)
{
    // Invalidate the rectangle determined by the pionts passed in here.
    RECT r;

    r.left = (Min (s.x, e.x) - _Origin.x) * CharSize.x;
    r.right = (Max (s.x, e.x) - _Origin.x) * CharSize.x + 1;
    r.top = (Min (s.y, e.y) - _Origin.y) * CharSize.y;
    r.bottom = (Max (s.y, e.y) - _Origin.y) * CharSize.y + 1;

    ::InvalidateRect (CrtWindow, &r, FALSE);
}


static void MarkScroll (int direction, int action, POINT delta, int shiftState)
{
    // Alter marked region according to key inputs, scrolling screen if necessary.
    int X, Y;
    RECT mr;
    POINT op, os, oe;

    os.x = BlockStart.x;
    os.y = BlockStart.y;

    X = op.x = oe.x = BlockEnd.x;
    Y = op.y = oe.y = BlockEnd.y;

    switch (direction)
    {
    case SB_HORZ:
        X = GetNewPos (BlockEnd.x, ClientSize.x / 2, Range.x+ClientSize.x, action, 0);
        op.y = BlockStart.y;
        break;

    case SB_VERT:
        Y = GetNewPos (BlockEnd.y, ClientSize.y, Range.y+ClientSize.y, action, 0);
        op.x = BlockStart.x;
        break;

    default:        // Should never get here.
        return;
    }

    if (shiftState >= 0)
    {
        BlockEnd.x = Max (0, Min (X, _BufferSize.x+1));
        BlockEnd.y = Max (0, Min (Y, LastLine+1));

        if (BlockEnd.x != oe.x || BlockEnd.y != oe.y)
        {
            BlockStart.x = BlockEnd.x;
            BlockStart.y = BlockEnd.y;

            // Invalidate old marked rectangle if there is one.
            if (os.x != oe.x && os.y != oe.y)
                InvalidateBlock (os, oe);
        }
    }
    else
    {
        // If first movement w/ shift key down, then we need special logic to
        // determine where the cursor goes.
        if (os.x == oe.x && os.y == oe.y)
        {
            X += delta.x;
            Y += delta.y;
        }

        if (direction == SB_HORZ && X == os.x)
        {
            if (oe.x < os.x)
                X++;
            else
                X--;
        }
        else if (Y == os.y)   // SB_VERT
        {
            if (oe.y < os.y)
                Y++;
            else
                Y--;
        }

        BlockEnd.x = Max (0, Min (X, _BufferSize.x));
        BlockEnd.y = Max (0, Min (Y, LastLine+1));

        // Invalidate new marked/unmarked region if there is one.
        InvalidateBlock (op, BlockEnd);
    }

    // Scroll screen if needed to keep caret visible.
    mr.left = _Origin.x;
    mr.right = _Origin.x + ClientSize.x;
    mr.top = _Origin.y;
    mr.bottom = _Origin.y + ClientSize.y;

    if (!PtInRect (&mr, BlockEnd))
        _ScrollTo (BlockEnd.x, BlockEnd.y);

    // Move caret to new position if necessary.
    if (BlockEnd.x != BlockStart.x && BlockEnd.y != BlockStart.y)
        HideCursor();
    else
        ShowCursor();
}

static void EasyWnd_OnKey( HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags )
{
    BYTE KeyDown = LOBYTE( vk );
    int I;

    if (_CheckBreak && (KeyDown == VK_CANCEL))
    {
        Terminate();
        return;
    }

    if (MarkMode && !MouseMarkMode)
    {
        // In mark mode, we do things differently.
        for (I = 0; I < MarkKeyCount; ++I)
        {
            if (MarkKeys[I].Key == KeyDown)
            {
                MarkScroll (MarkKeys[I].SBar, MarkKeys[I].Action, MarkKeys[I].Delta, GetKeyState (VK_SHIFT));
                return;
            }
        }

        // Ctrl-Ins copies selected text.
        if (KeyDown == VK_INSERT && GetKeyState (VK_CONTROL) < 0 )
        {
            EndMarkMode (TRUE);
            return;
        }
    }
    else
    {
        BOOL CtrlDown = (BOOL) (GetKeyState(VK_CONTROL) < 0);
        for (I = 0; I < ScrollKeyCount; ++I)
        {
            if (ScrollKeys[I].Key == KeyDown && ScrollKeys[I].Ctrl == CtrlDown)
            {
                WindowScroll(ScrollKeys[I].SBar, ScrollKeys[I].Action, 0);
                return;
            }
        }

        // Shift-Ins pastes text into input buffer.
        if (KeyDown == VK_INSERT && GetKeyState(VK_SHIFT) < 0 && !(GetMenuState (EditMenu, IDM_PASTE, MF_BYCOMMAND) & MF_DISABLED))
        {
            PostMessage (CrtWindow, WM_SYSCOMMAND, (WPARAM) IDM_PASTE, 0L);
        }
    }
}


// WM_SETFOCUS message handler

static void EasyWnd_OnSetFocus( HWND hwnd, HWND hwndOldFocus )
{
    Focused = TRUE;
    if (Reading)
        ShowCursor();
}


// WM_KILLFOCUS message handler

static void EasyWnd_OnKillFocus( HWND hwnd, HWND hwndNewFocus )
{
    if (Reading)
        HideCursor();
    Focused = FALSE;
}


// WM_DESTROY message handler

static void EasyWnd_OnDestroy( HWND hwnd )
{
    WriteRemainingBuffer();
    if (PasteBlock)
        GlobalFreePtr (PasteBlock);
    free(ScreenBuffer);
    _Cursor.x = 0;
    _Cursor.y = 0;
    _Origin.x = 0;
    _Origin.y = 0;
    GetSystemMenu (CrtWindow, TRUE);  // Destroy changes we made to system menu
    PostQuitMessage(0);
    Created = FALSE;
}


// Clipboard support functions

static void CopyTextToClipboard()
{
    // Is there a block selected?
    if (BlockStart.x == BlockEnd.x || BlockStart.y == BlockEnd.y)
        return;

    // Force BlockStart to be the Upper Left corner and BlockEnd to be the
    //   Lower Right corner of the selected block.
    if (BlockStart.x > BlockEnd.x)
    {
        Swap (BlockStart.x, BlockEnd.x);
    }

    if (BlockStart.y > BlockEnd.y)
    {
        Swap (BlockStart.y, BlockEnd.y);
    }

    // Calculate memory size needed for copy + 2 bytes extra for each line.
    int block_size = (BlockEnd.x - BlockStart.x + 2) * (BlockEnd.y - BlockStart.y) + 1;
    HGLOBAL block = ::GlobalAlloc (GMEM_MOVEABLE, block_size);

    if (block)
    {
        char far *ptr = (char far *) ::GlobalLock (block);

        int y;
        char far *dest = ptr;

        for (y = BlockStart.y; y < BlockEnd.y; y++)
        {
            int xlen = BlockEnd.x - BlockStart.x;
            char *src = BufferPtr (BlockStart.x,y);

            // strip trailing spaces.
            for ( ; xlen > 0 && src[xlen-1] == ' '; xlen-- )
                ;

            _fmemcpy (dest, src, xlen );

            dest += xlen;
            *dest++ = '\r';
            *dest++ = '\n';
        }
        *dest = 0;

        ::GlobalUnlock (block);
        ::GlobalReAlloc (block, dest - ptr + 1, GMEM_MOVEABLE);

        // Put data on clipboard, free block if _unsuccessful_
        if (::OpenClipboard (CrtWindow))
        {
            ::SetClipboardData (CF_TEXT, block);
            ::CloseClipboard ();
        }
        else
            ::GlobalFree (block);
    }
}

static void EndMarkMode (BOOL copy)
{
    if (copy)
        CopyTextToClipboard();

    MarkMode = FALSE;
    ::InvalidateRect (CrtWindow, 0, FALSE);
    ShowCursor();
}


// Print contents out EasyWin buffer.

static void PrintError (const char *error)
{
    char errorstr[128];

    ::wsprintf (errorstr, PrinterErrorText, error);
    ::MessageBox (CrtWindow, errorstr, PrinterErrorCaption, MB_TASKMODAL | MB_OK);
}

static void PrintPage (HDC hDC, int line, int lppage, int fontheight, POINT index)
{
    // Print data
    for (int i = 0; i < lppage; i++)
    {
        int current_line = line + i;

        if (current_line > LastLine)
            break;

        char *data = BufferPtr (0, current_line);

	int n;
        for (n = _BufferSize.x-1; n >= 0 && data[n] == ' '; n--)
            ;

        ::TextOut (hDC, index.x, -1 * (fontheight*i + index.y), data, n+1);
    }
}

static void PrintDocument (PRINTDLG& pdlg)
{
    DOCINFO doc_info;
    LOGFONT logfont;
    DEVMODE far *devmode;
    HFONT printer_font, old_font;
    unsigned lppage, total_pages, current_page, width;
    char doc_name[32];

    if (!::GetWindowText (CrtWindow, doc_name, sizeof (doc_name)))
        strcpy (doc_name, PrinterDocumentName);

    doc_info.cbSize = sizeof (doc_info);
    doc_info.lpszDocName = doc_name;
    doc_info.lpszOutput = 0;

    devmode = (DEVMODE far *) ::GlobalLock (pdlg.hDevMode);

    // Calculate necessary indentations to get 1" margins all around
    // and 80 characters per line.

    POINT phys, image, dpi, index, size;

    Escape (pdlg.hDC, GETPHYSPAGESIZE, 0, 0, &phys);
    image.x = GetDeviceCaps (pdlg.hDC, HORZRES);
    image.y = GetDeviceCaps (pdlg.hDC, VERTRES);
    dpi.x = GetDeviceCaps (pdlg.hDC, LOGPIXELSX);
    dpi.y = GetDeviceCaps (pdlg.hDC, LOGPIXELSY);

    index.x = (int) (((unsigned long)dpi.x*2 - phys.x + image.x) * 50 / dpi.x);
    index.y = (int) (((unsigned long)dpi.y*2 - phys.y + image.y) * 50 / dpi.y);
    size.x =  (int) ((unsigned long)image.x * 100 / dpi.x - 2 * index.x);
    size.y =  (int) ((unsigned long)image.y * 100 / dpi.y - 2 * index.y);

    width = size.x / _BufferSize.x;

    if (!_UseDefaultPrinterFont)
    {
        memset (&logfont, 0, sizeof (logfont));
        logfont.lfWidth = width;
        logfont.lfWeight = FW_NORMAL;
        logfont.lfPitchAndFamily = FIXED_PITCH | FF_MODERN;
        strcpy (logfont.lfFaceName, "Courier");

        printer_font = CreateFontIndirect (&logfont);
    }
    else
    {
        // If we use the default font, assume default X margins.
        index.x = 0;
        printer_font = 0;
    }

    // Get textmetrics on printer font we are going to use.
    if (printer_font)
        old_font = SelectFont (pdlg.hDC, printer_font);

    TEXTMETRIC tm;
    GetTextMetrics (pdlg.hDC, &tm);

    if (tm.tmAveCharWidth > width+1 &&
        ::MessageBox (CrtWindow, FontSizeErrorMsg, PrinterDocumentName, MB_TASKMODAL | MB_YESNO) == IDYES)
    {
        SelectFont (pdlg.hDC, old_font);
        DeleteFont (printer_font);
        printer_font = 0;
        index.x = 0;
    }

    int height = (tm.tmHeight + tm.tmExternalLeading) * 100 / dpi.y;

    if (printer_font)
        SelectFont (pdlg.hDC, old_font);

    // If in landscape mode, we must use the Size.X to do the lines.
    if (devmode->dmOrientation == DMORIENT_PORTRAIT)
        lppage = size.y / height;
    else
        lppage = size.x / height;

    total_pages = LastLine / lppage + 1;
    ::GlobalUnlock (pdlg.hDevMode);

    if (StartDoc (pdlg.hDC, &doc_info) == SP_ERROR)
    {
        PrintError (PrError_StartDoc);
        return;
    }

    for (current_page = 0; current_page < total_pages; current_page++)
    {
        StartPage (pdlg.hDC);

        // Set up DC
        int save_dc = ::SaveDC (pdlg.hDC);
        ::SetMapMode (pdlg.hDC, MM_LOENGLISH);

        // If we get the font we want, use it.  Otherwise, hope the printer default
        // will be ok (because there is little else we can do...
        if (printer_font)
            old_font = SelectFont (pdlg.hDC, printer_font);

        PrintPage (pdlg.hDC, current_page*lppage, lppage, height, index);

        // Clean up DC
        ::RestoreDC (pdlg.hDC, save_dc);

        EndPage (pdlg.hDC);
    }

    EndDoc (pdlg.hDC);

    if (printer_font)
        SelectFont (pdlg.hDC, old_font);

    DeleteFont (printer_font);
}

static void PrintOutput ()
{
    // Get printer & DC, using printer common dialog.
    PRINTDLG pdlg;

    memset (&pdlg, 0, sizeof (pdlg));
    pdlg.lStructSize = sizeof (pdlg);
    pdlg.hwndOwner = CrtWindow;
    pdlg.Flags = PD_NOSELECTION | PD_NOPAGENUMS | PD_RETURNDC | PD_USEDEVMODECOPIES;
    pdlg.nCopies = 1;

    if (!::PrintDlg (&pdlg))
        return;

    PrintDocument (pdlg);

    ::DeleteDC (pdlg.hDC);
    ::GlobalFree (pdlg.hDevNames);
    ::GlobalFree (pdlg.hDevMode);
}


// WM_SYSCOMMAND message handler

static void EasyWnd_OnSysCommand (HWND hwnd, UINT cmd, int x, int y)
{
    switch (cmd)
    {
    case IDM_MARK:
        MarkMode = TRUE;
        MouseMarkMode = FALSE;
        BlockStart.x = BlockEnd.x = _Origin.x;
        BlockStart.y = BlockEnd.y = _Origin.y;
        ShowCursor ();
        break;

    case IDM_COPY:
        EndMarkMode (TRUE);
        break;

    case IDM_PASTE:
        // We only support pasting up to 65534 bytes of text.
        if (OpenClipboard (hwnd))
        {
            HGLOBAL text_handle = GetClipboardData (CF_TEXT);

            if (text_handle)
            {
                char far *text = (char far *) GlobalLock (text_handle);

                if (PasteBlock)
                    GlobalFreePtr (PasteBlock);

                if (GlobalSize (text_handle) <= 65534U)
                    PasteMax = _fstrlen (text);
                else
                    PasteMax = 65534U;

                PasteBlock = (char far *) GlobalAllocPtr (GMEM_MOVEABLE, PasteMax+1);
                _fstrncpy (PasteBlock, text, PasteMax);
                PasteBlock[PasteMax] = '\0';
                PasteIndex = 0;
                PastePoint = KeyCount+1;

                GlobalUnlock (text_handle);
            }

            CloseClipboard ();
        }
        break;

    case IDM_SELECT_ALL:
        BlockStart.x = BlockStart.y = 0;
        BlockEnd.x = _BufferSize.x;
        BlockEnd.y = LastLine;

        InvalidateRect (hwnd, 0, FALSE);

        if (!MarkMode)
        {
            MarkMode = TRUE;
            ShowCursor ();
        }
        break;

    case IDM_PRINT:
        PrintOutput();
        break;

    default:
        FORWARD_WM_SYSCOMMAND (hwnd, cmd, x, y, DefWindowProc);
        break;
    }
}


// WM_INITMENUPOPUP message handler

static void EasyWnd_OnInitMenuPopup(HWND hwnd, HMENU hMenu, int item, BOOL fSystemMenu)
{
    if (hMenu == EditMenu)
    {
        BOOL flag = (::IsClipboardFormatAvailable (CF_TEXT) && _EasyWinActive) ? MF_ENABLED : MF_GRAYED;
        ::EnableMenuItem (hMenu, IDM_PASTE, flag | MF_BYCOMMAND);

        flag = (MarkMode && BlockStart.x != BlockEnd.x && BlockStart.y != BlockEnd.y) ? MF_ENABLED : MF_GRAYED;
        ::EnableMenuItem (hMenu, IDM_COPY, flag | MF_BYCOMMAND);
    }

    if (fSystemMenu)
    {
        BOOL flag = GetDefaultPrinter() ? MF_ENABLED : MF_GRAYED;
        ::EnableMenuItem (hMenu, IDM_PRINT, flag | MF_BYCOMMAND);
    }

    FORWARD_WM_INITMENUPOPUP(hwnd, hMenu, item, fSystemMenu, DefWindowProc);
}


// WM_MOUSEMOVE message handler

#define sgn(x)  ((x<0) ? -1 : ((x>0) ? 1 : 0))

static void EasyWnd_OnMouseMove (HWND hwnd, int x, int y, UINT keyFlags)
{
    if (MarkMode && MouseCapture)
    {
        POINT e, s;
        int delta;

        e.x = x / CharSize.x + _Origin.x;
        e.y = y / CharSize.y + _Origin.y;

        if ((BlockStart.x-_Origin.x)*CharSize.x < x)
            e.x++;
        if ((BlockStart.y-_Origin.y)*CharSize.y < y)
            e.y++;

        s.x = _Origin.x;
        s.y = _Origin.y;

        if ( ((delta = e.x - _Origin.x) < 0) || ((delta = e.x - (_Origin.x + ClientSize.x)) > 0))
        {
            delta = (abs (delta) > 5) ? 8 * sgn(delta) : 1 * sgn(delta);
            s.x = _Origin.x + delta;
        }

        if ( ((delta = e.y - _Origin.y) < 0) || ((delta = e.y - (_Origin.y + ClientSize.y)) > 0))
        {
            delta = (abs (delta) > 3) ? ClientSize.y * sgn(delta) : 1 * sgn(delta);
            s.y = _Origin.y + delta;
        }

        if( e.x != BlockEnd.x || e.y != BlockEnd.y )
        {
            BlockEnd.x = Max (0, Min (e.x, _BufferSize.x));
            BlockEnd.y = Max (0, Min (e.y, LastLine+1));
            ::InvalidateRect (hwnd, 0, FALSE);
        }

        _ScrollTo (s.x, s.y);
    }
    else
        FORWARD_WM_MOUSEMOVE (hwnd, x, y, keyFlags, DefWindowProc);
}


// WM_LBUTTONDOWN message handler

static void EasyWnd_OnLButtonDown (HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    if (MarkMode && !MouseCapture)
    {
        if (!fDoubleClick)
        {
            MouseCapture = MouseMarkMode = TRUE;
            ::SetCapture (hwnd);

            if (GetAsyncKeyState (VK_SHIFT) >= 0)
            {
                if (BlockStart.x != BlockEnd.x && BlockStart.y != BlockEnd.y)
                    InvalidateBlock (BlockStart, BlockEnd);
                BlockEnd.x = BlockStart.x = x / CharSize.x + _Origin.x;
                BlockEnd.y = BlockStart.y = Min (y / CharSize.y + _Origin.y, LastLine);
            }
            else
            {
                InvalidateRect (CrtWindow, 0, FALSE);
                BlockEnd.x = x / CharSize.x + _Origin.x;
                BlockEnd.y = y / CharSize.y + _Origin.y;
            }

            HideCursor();
        }
    }
    else
    {
        MouseCapture = FALSE;
        FORWARD_WM_LBUTTONDOWN (hwnd, fDoubleClick, x, y, keyFlags, DefWindowProc);
    }
}


// WM_LBUTTONUP message handler

static void EasyWnd_OnLButtonUp (HWND hwnd, int x, int y, UINT keyFlags)
{
    if (MarkMode && MouseCapture)
    {
        MouseCapture = FALSE;
        ::ReleaseCapture ();
    }
    else
        FORWARD_WM_LBUTTONUP (hwnd, x, y, keyFlags, DefWindowProc);
}


// WM_RBUTTONDOWN message handler

static void EasyWnd_OnRButtonDown (HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags)
{
    if (MarkMode && !MouseCapture)
    {
        EndMarkMode (TRUE);
    }
    else
        FORWARD_WM_RBUTTONDOWN (hwnd, fDoubleClick, x, y, keyFlags, DefWindowProc);
}


// Easy window procedure

long FAR PASCAL _export _EasyWinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    CrtWindow = hwnd;

    switch (msg)
    {
        HANDLE_MSG (hwnd, WM_CREATE, EasyWnd_OnCreate);
        HANDLE_MSG (hwnd, WM_PAINT, EasyWnd_OnPaint);
        HANDLE_MSG (hwnd, WM_ERASEBKGND, EasyWnd_OnEraseBkgnd);
        HANDLE_MSG (hwnd, WM_VSCROLL, EasyWnd_OnVScroll);
        HANDLE_MSG (hwnd, WM_HSCROLL, EasyWnd_OnHScroll);
        HANDLE_MSG (hwnd, WM_SIZE, EasyWnd_OnSize);
        HANDLE_MSG (hwnd, WM_GETMINMAXINFO, EasyWnd_OnGetMinMaxInfo);
        HANDLE_MSG (hwnd, WM_CHAR, EasyWnd_OnChar);
        HANDLE_MSG (hwnd, WM_KEYDOWN, EasyWnd_OnKey);
        HANDLE_MSG (hwnd, WM_SETFOCUS, EasyWnd_OnSetFocus);
        HANDLE_MSG (hwnd, WM_KILLFOCUS, EasyWnd_OnKillFocus);
        HANDLE_MSG (hwnd, WM_DESTROY, EasyWnd_OnDestroy);
        HANDLE_MSG (hwnd, WM_SYSCOMMAND, EasyWnd_OnSysCommand);
        HANDLE_MSG (hwnd, WM_INITMENUPOPUP, EasyWnd_OnInitMenuPopup);
        HANDLE_MSG (hwnd, WM_MOUSEMOVE, EasyWnd_OnMouseMove);
        HANDLE_MSG (hwnd, WM_LBUTTONDOWN, EasyWnd_OnLButtonDown);
        HANDLE_MSG (hwnd, WM_LBUTTONUP, EasyWnd_OnLButtonUp);
        HANDLE_MSG (hwnd, WM_RBUTTONDOWN, EasyWnd_OnRButtonDown);

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

// Create window if required

void __InitEasyWin(void)
{
    if (!Created)
    {
        // Open output file, if any.
        OpenOutputFile();

        // Create and display EasyWin window
        CrtWindow = CreateWindow(
                       CrtClass.lpszClassName,
                       _WindowTitle,
                       WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,
                       _WindowOrg.x, _WindowOrg.y,
                       _WindowSize.x, _WindowSize.y,
                       0,
                       0,
                       __hInstance,
                       NULL);
        ShowWindow(CrtWindow, __cmdShow);
        UpdateWindow(CrtWindow);
    }
}

// Destroy window if required

void _DoneEasyWin(void)
{
    if (Created)
    {
        if (CrtWindow)
            DestroyWindow (CrtWindow);
    }
    exit(0);
}

// EasyWin unit exit procedure

void far __ExitEasyWin(void)
{
    char *P;
    MSG Message;
    char Title[128];

    if (Created) // && (ErrorAddr = NULL))
    {
        _EasyWinActive = FALSE;
        P = _WindowTitle;
        wsprintf(Title, _InactiveTitle, (char far *) P);
        SetWindowText(CrtWindow, Title);
        EnableMenuItem (GetSystemMenu (CrtWindow, FALSE), SC_CLOSE, MF_BYCOMMAND | MF_ENABLED);
        _CheckBreak = FALSE;
        while (GetMessage(&Message, 0, 0, 0))
        {
            TranslateMessage(&Message);
            DispatchMessage(&Message);
        }
    }
}

void __CreateEasyWin(void)
{
    if (__hPrev == 0)
    {
        CrtClass.hInstance = __hInstance;
        CrtClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        CrtClass.hCursor = LoadCursor(NULL, IDC_ARROW);
        CrtClass.hbrBackground = GetStockBrush(WHITE_BRUSH);
        RegisterClass(&CrtClass);
    }
    GetModuleFileName(__hInstance, _WindowTitle, sizeof(_WindowTitle));
    OemToAnsi(_WindowTitle, _WindowTitle);
    __ReadBufFPtr  = _ReadBuf;
    __WriteBufFPtr = _WriteBuf;
}
