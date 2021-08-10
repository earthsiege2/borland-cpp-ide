/*------------------------------------------------------------------------
 * filename - _video.h
 *
 *  Private definitions for Turbo Pascal style video functions on
 *  OS/2 and Win32/NT. External interfaces in VIDEO.H.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 2.0
 *
 *      Copyright (c) 1987, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

typedef unsigned char uchar;

/* WARNING: this structure must have exactly the same layout in the
 * first 9 members (windowx1 through screenwidth) as the text_info
 * structure in conio.h.  It must also be larger than text_info.
 */
typedef struct
{
    uchar windowx1;
    uchar windowy1;
    uchar windowx2;
    uchar windowy2;
    uchar attribute;
    uchar normattr;
    uchar currmode;
    uchar screenheight;
    uchar screenwidth;
    uchar graphicsmode;
    uchar snow;
    char *displayptr;
} VIDEOREC;

extern VIDEOREC _video;

#ifdef __cplusplus
extern "C" {
#endif

unsigned    __cputn     (const void *__s, unsigned __n, void *__dontCare);
void        _crtinit    (int __newmode);
void        __scroll    (uchar __dir, uchar __x1, uchar __y1, uchar __x2,
                            uchar __y2, uchar __lines);
unsigned    _wherex     (void);
unsigned    _wherey     (void);
void        __movecursor(int __x, int __y);
int         __validatexy(int __x1, int __y1, int __x2, int __y2);
void        __moveline  (int __dx, int __dy, int __sx, int __sy, int __len);
void        __getline   (void *__buffer, int __sx, int __sy, int __len);
void        __putline   (int __dx, int __dy, void *__buffer, int __len);

#ifdef __cplusplus
}
#endif

#define UP      0
#define DOWN    1

#define DEFAULT_ROWS    25
#define DEFAULT_COLS    80
#define DEFAULT_ATTRIB  7

#ifdef __OS2__
/*
  We use a shortened form of the VIOMODEINFO structure for the text mode
  work because we really don't care about pixel resolutions.  The OS/2
  supplied defaults will work just fine there.
*/
typedef struct AbbreviatedModeData
{
    unsigned short  length;
    unsigned char   type;
    unsigned char   color;
    unsigned short  col;
    unsigned short  row;
} AMD, *PAMD;
#endif

#define iTYPE   3   /* Color, B&W, Monochrome   */
#define iROWS   7   /* 14, 21, 25, 28, 43, 50, 60   */
#define iCOLS   2   /* 40, 80           */

/* Handles for console output and input on WIN32/NT,
 * initialized in crtinit.c.
 */
#if defined(__WIN32__) && defined(_NTBC_H)
extern HANDLE _hout, _hin;
#endif
