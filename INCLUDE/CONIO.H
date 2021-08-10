/*  conio.h

    Direct MSDOS console input/output.
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $ */

#if !defined(__CONIO_H)
#define __CONIO_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2

struct text_info {
    unsigned char winleft;
    unsigned char wintop;
    unsigned char winright;
    unsigned char winbottom;
    unsigned char attribute;
    unsigned char normattr;
    unsigned char currmode;
    unsigned char screenheight;
    unsigned char screenwidth;
    unsigned char curx;
    unsigned char cury;
};

#if !defined(__COLORS)
#define __COLORS

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

#define BLINK       128 /* blink bit */

enum text_modes
{
    /* DOS-compatible modes */

    LASTMODE = -1,
    BW40     = 0,
    C40,
    BW80,
    C80,
    MONO     = 7,
    C4350    = 64,

    /* New Color modes */

    C40X14   = 8,
    C40X21,
    C40X28,
    C40X43,
    C40X50,
    C40X60,

    C80X14,
    C80X21,
    C80X28,
    C80X43,
    C80X50,
    C80X60,

    /* New Black & White modes */

    BW40X14,
    BW40X21,
    BW40X28,
    BW40X43,
    BW40X50,
    BW40X60,

    BW80X14,
    BW80X21,
    BW80X28,
    BW80X43,
    BW80X50,
    BW80X60,

    /* New Monochrome modes */

    MONO14,             /* Invalid VGA mode */
    MONO21,
    MONO28,
    MONO43,
    MONO50,
    MONO60,

    _ORIGMODE = 65      /* original mode at program startup */
};


#define PASS_MAX    8   /* max. no. of chars returned by getpass */


extern   int _RTLENTRY _EXPDATA _directvideo;

extern   int _RTLENTRY _EXPDATA _wscroll;

#ifdef __cplusplus
extern "C" {
#endif

void        _RTLENTRY _EXPFUNC clreol( void );
void        _RTLENTRY _EXPFUNC clrscr( void );
void        _RTLENTRY _EXPFUNC delline( void );
int         _RTLENTRY _EXPFUNC gettext( int __left, int __top,
                            int __right, int __bottom,
                            void *__destin);
void        _RTLENTRY _EXPFUNC gettextinfo (struct text_info *__r );
void        _RTLENTRY _EXPFUNC gotoxy( int __x, int __y );
void        _RTLENTRY _EXPFUNC highvideo( void );
void        _RTLENTRY _EXPFUNC insline( void );
void        _RTLENTRY _EXPFUNC lowvideo( void );
int         _RTLENTRY _EXPFUNC movetext( int __left, int __top,
                             int __right, int __bottom,
                             int __destleft, int __desttop );
void        _RTLENTRY _EXPFUNC normvideo( void );
int         _RTLENTRY _EXPFUNC puttext( int __left, int __top,
                            int __right, int __bottom,
                            void *__source );
void        _RTLENTRY _EXPFUNC textattr( int __newattr );
void        _RTLENTRY _EXPFUNC textbackground( int __newcolor );
void        _RTLENTRY _EXPFUNC textcolor( int __newcolor );
void        _RTLENTRY _EXPFUNC textmode( int __newmode );
void        _RTLENTRY _EXPFUNC window( int __left, int __top, int __right, int __bottom);

void        _RTLENTRY _EXPFUNC _setcursortype( int __cur_t );
char *      _RTLENTRY _EXPFUNC cgets( char *__str );
int         _RTLENTRY _EXPFUNC cprintf( const char *__format, ... );
int         _RTLENTRY _EXPFUNC cputs( const char *__str );
int         _RTLENTRY _EXPFUNC cscanf( const char *__format, ... );
int         _RTLENTRY _EXPFUNC getch( void );
int         _RTLENTRY _EXPFUNC getche( void );
char *      _RTLENTRY _EXPFUNC getpass( const char *__prompt );
int         _RTLENTRY _EXPFUNC kbhit( void );
int         _RTLENTRY _EXPFUNC putch( int __c );
int         _RTLENTRY _EXPFUNC ungetch( int __ch );
int         _RTLENTRY _EXPFUNC wherex( void );
int         _RTLENTRY _EXPFUNC wherey( void );

__inline int _getch( void ) { return getch(); } /* for MSC compatibility */

/*
  This function will remove from the console event queue, any key-up events
  that are pending. under Win95 key-up events will incorrectly be translated
  into real key presses by the OS ReadFile() API call, which scanf() uses.
  The WinNT version of ReadFile() correctly ignores them, of course. The
  problem can occur when getch() is called to get a key, then scanf() is
  called to obtain more input from stdin.  On Win95 the key-up event that is
  still left in the event queue will cause ReadFile() to think that the same
  key was pressed again.  Although, good programming practice dictates that
  one shouldn't use both getch() and scanf() near each other in the same
  program, the following function could help alleviate this key-up problem.
  cscanf() does NOT suffer from this problem since it gets its input via
  getch() and not ReadFile().  __flush_win95_keyup_events() should be called
  before scanf() is called. Keep in mind that you must allow sufficient time
  for the user to release the key so that the key-up event is inserted
  before flushing the key-up events.  Otherwise, the key-up event will occur
  after scanf() is blocked and waiting inside ReadFile().

  __flush_win95_keyup_events() returns the number of key-up events that it
  removed from the queue.

*/
int         _RTLENTRY _EXPFUNC __flush_win95_keyup_events (void);


#ifdef __cplusplus
}
#endif

#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __CONIO_H */
