/*  conio.h

    Direct MSDOS console input/output.
*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__CONIO_H)
#define __CONIO_H

#if !defined(___DEFS_H)
#include <_defs.h>
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

#if !defined(__FLAT__)

enum text_modes {  LASTMODE=-1,
                   BW40=0,
                   C40,
                   BW80,
                   C80,
                   MONO=7,
                   C4350=64 };

#if defined(__DPMI16__) || !defined(_Windows)

#if !defined(__STDC__)  /*  NON-ANSI  */
#define directvideo  _directvideo
#endif

extern   int _RTLENTRY _directvideo;

#endif  /* __DPMI16__ || !_Windows */

extern   int _RTLENTRY _wscroll;

#ifdef __cplusplus
extern "C" {
#endif

void        _RTLENTRY clreol( void );
void        _RTLENTRY clrscr( void );
void        _RTLENTRY gotoxy( int __x, int __y );
int         _RTLENTRY getch( void );
int         _RTLENTRY getche( void );
int         _RTLENTRY kbhit( void );
int         _RTLENTRY putch( int __c );
int         _RTLENTRY wherex( void );
int         _RTLENTRY wherey( void );

#ifndef _PORT_DEFS
unsigned char   _RTLENTRY inportb( unsigned __portid );
unsigned        _RTLENTRY inport ( unsigned __portid );
int             _RTLENTRY inp( unsigned __portid );
unsigned        _RTLENTRY inpw( unsigned __portid );
void            _RTLENTRY outportb( unsigned __portid, unsigned char __value );
void            _RTLENTRY outport ( unsigned __portid, unsigned __value );
int             _RTLENTRY outp( unsigned __portid, int __value );
unsigned        _RTLENTRY outpw( unsigned __portid, unsigned __value );
#endif  /* !_PORT_DEFS */

#if defined(__DPMI16__) || !defined(_Windows)

void        _RTLENTRY delline( void );
int         _RTLENTRY gettext( int __left, int __top,
                           int __right, int __bottom,
                           void *__destin);
void        _RTLENTRY gettextinfo (struct text_info *__r );
void        _RTLENTRY highvideo( void );
void        _RTLENTRY insline( void );
void        _RTLENTRY lowvideo( void );
int         _RTLENTRY movetext( int __left, int __top,
                            int __right, int __bottom,
                            int __destleft, int __desttop );
void        _RTLENTRY normvideo( void );
int         _RTLENTRY puttext( int __left, int __top,
                           int __right, int __bottom,
                           void *__source );
void        _RTLENTRY textattr( int __newattr );
void        _RTLENTRY textbackground( int __newcolor );
void        _RTLENTRY textcolor( int __newcolor );
void        _RTLENTRY textmode( int __newmode );
void        _RTLENTRY window( int __left, int __top, int __right, int __bottom);

void        _RTLENTRY _setcursortype( int __cur_t );
char *      _RTLENTRY cgets( char *__str );
int         _RTLENTRY cprintf( const char *__format, ... );
int         _RTLENTRY cputs( const char *__str );
int         _RTLENTRY cscanf( const char *__format, ... );
char *      _RTLENTRY getpass( const char *__prompt );
int         _RTLENTRY ungetch( int __ch );

#endif /* __DPMI16__ || !_Windows */

#ifndef _PORT_DEFS
#define _PORT_DEFS

    /* These are in-line functions.  These prototypes just clean up
       some syntax checks and code generation.
     */
unsigned char   _RTLENTRY  __inportb__ (unsigned __portid);
unsigned        _RTLENTRY  __inportw__ (unsigned __portid);
unsigned char   _RTLENTRY  __outportb__(unsigned __portid, unsigned char __value);
unsigned        _RTLENTRY  __outportw__(unsigned __portid, unsigned __value);

#define inportb(__portid)           __inportb__(__portid)
#define outportb(__portid, __value) ((void) __outportb__(__portid, __value))
#define inport(__portid)            __inportw__(__portid)
#define outport(__portid, __value)  ((void) __outportw__(__portid, __value))

/* MSC-compatible macros for port I/O */
#define inp(__portid)               __inportb__ (__portid)
#define outp(__portid, __value)     __outportb__(__portid, (unsigned char)(__value))
#define inpw(__portid)              __inportw__ (__portid)
#define outpw(__portid, __value)    __outportw__(__portid, __value)

#endif  /* _PORT_DEFS */

#ifdef __cplusplus
}
#endif

#else  /* __FLAT__ */

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

#if !defined(__STDC__)  /*  NON-ANSI  */
#define directvideo  _directvideo
#define _getch       getch             /* for MSC compatibility */
#endif

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

#ifdef __cplusplus
}
#endif

#endif  /* __FLAT__  */


#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __CONIO_H */
