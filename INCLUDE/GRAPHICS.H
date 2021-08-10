/*  graphics.h

    Definitions for Graphics Package.

*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.1  $ */

#if !defined(__GRAPHICS_H)
#define __GRAPHICS_H

#if defined( _Windows ) && !defined (__DPMI16__) && !defined(__DPMI32__)
#error BGI graphics not supported under Windows
#endif

#if defined(__STDC__)
#error BGI graphics not ANSI compatible
#endif

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#if !defined(_BGIENTRY)
    #if defined(__DPMI16__)
        #define _BGIENTRY __pascal
    #elif defined(__DPMI32__)
        #define _BGIENTRY _RTLENTRY __import
    #else
        #define _BGIENTRY _RTLENTRY
    #endif
#endif

#if defined(__DPMI32__)
#define far
#define huge
#endif

enum graphics_errors {      /* graphresult error return codes */
    grOk           =   0,
    grNoInitGraph      =  -1,
    grNotDetected      =  -2,
    grFileNotFound     =  -3,
    grInvalidDriver    =  -4,
    grNoLoadMem    =  -5,
    grNoScanMem    =  -6,
    grNoFloodMem       =  -7,
    grFontNotFound     =  -8,
    grNoFontMem    =  -9,
    grInvalidMode      = -10,
    grError        = -11,   /* generic error */
    grIOerror      = -12,
    grInvalidFont      = -13,
    grInvalidFontNum   = -14,
    grInvalidVersion   = -18
};

enum graphics_drivers {     /* define graphics drivers */
    DETECT,         /* requests autodetection */
    CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514,    /* 1 - 6 */
    HERCMONO, ATT400, VGA, PC3270,          /* 7 - 10 */
    CURRENT_DRIVER = -1
};

enum graphics_modes {       /* graphics modes for each driver */
    CGAC0      = 0,  /* 320x200 palette 0; 1 page   */
    CGAC1      = 1,  /* 320x200 palette 1; 1 page   */
    CGAC2      = 2,  /* 320x200 palette 2: 1 page   */
    CGAC3      = 3,  /* 320x200 palette 3; 1 page   */
    CGAHI      = 4,  /* 640x200 1 page          */
    MCGAC0     = 0,  /* 320x200 palette 0; 1 page   */
    MCGAC1     = 1,  /* 320x200 palette 1; 1 page   */
    MCGAC2     = 2,  /* 320x200 palette 2; 1 page   */
    MCGAC3     = 3,  /* 320x200 palette 3; 1 page   */
    MCGAMED    = 4,  /* 640x200 1 page          */
    MCGAHI     = 5,  /* 640x480 1 page          */
    EGALO      = 0,  /* 640x200 16 color 4 pages    */
    EGAHI      = 1,  /* 640x350 16 color 2 pages    */
    EGA64LO    = 0,  /* 640x200 16 color 1 page     */
    EGA64HI    = 1,  /* 640x350 4 color  1 page     */
    EGAMONOHI  = 0,  /* 640x350 64K on card, 1 page - 256K on card, 4 pages */
    HERCMONOHI = 0,  /* 720x348 2 pages         */
    ATT400C0   = 0,  /* 320x200 palette 0; 1 page   */
    ATT400C1   = 1,  /* 320x200 palette 1; 1 page   */
    ATT400C2   = 2,  /* 320x200 palette 2; 1 page   */
    ATT400C3   = 3,  /* 320x200 palette 3; 1 page   */
    ATT400MED  = 4,  /* 640x200 1 page          */
    ATT400HI   = 5,  /* 640x400 1 page          */
    VGALO      = 0,  /* 640x200 16 color 4 pages    */
    VGAMED     = 1,  /* 640x350 16 color 2 pages    */
    VGAHI      = 2,  /* 640x480 16 color 1 page     */
    PC3270HI   = 0,  /* 720x350 1 page          */
    IBM8514LO  = 0,  /* 640x480 256 colors      */
    IBM8514HI  = 1   /*1024x768 256 colors      */
};


#if defined(__DPMI32__)
/*  graphicx.h

    Extended Definitions for Graphics Package.

*/


enum Xgraphics_drivers {     /* define extended graphics drivers */
    DETECTX    = 256,
    VGA256     = 11,
    ATTDEB     = 12,
    TOSHIBA    = 13,

    SVGA16     = 14,
    SVGA256    = 15,
    SVGA32K    = 16,
    SVGA64K    = 17,

    VESA16     = 18,
    VESA256    = 19,
    VESA32K    = 20,
    VESA64K    = 21,
    VESA16M    = 22,

    ATI16      = 23,
    ATI256     = 24,
    ATI32K     = 25,
    COMPAQ     = 26,
    TSENG316   = 27,
    TSENG3256  = 28,
    TSENG416   = 29,
    TSENG4256  = 30,
    TSENG432K  = 31,
    GENOA5     = 32,
    GENOA6     = 33,
    OAK        = 34,
    PARADIS16  = 35,
    PARADIS256 = 36,
    TECMAR     = 37,
    TRIDENT16  = 38,
    TRIDENT256 = 39,
    VIDEO7     = 40,
    VIDEO7II   = 41,

    S3         = 42,
    ATIGUP     = 43

};

enum Xgraphics_modes {       /* graphics modes for each driver */
    RES640x350  = 0,
    RES640x480  = 1,
    RES800x600  = 2,
    RES1024x768 = 3,
    RES1280x1024 = 4,
};


#endif  /* !__DPMI32__ */


/* Colors for setpalette and setallpalette */

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
    DARKGRAY,           /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

enum CGA_COLORS {
    CGA_LIGHTGREEN     = 1,     /* Palette C0 Color Names   */
    CGA_LIGHTRED       = 2,
    CGA_YELLOW         = 3,

    CGA_LIGHTCYAN      = 1,     /* Palette C1 Color Names   */
    CGA_LIGHTMAGENTA   = 2,
    CGA_WHITE          = 3,

    CGA_GREEN          = 1,     /* Palette C2 Color Names   */
    CGA_RED        = 2,
    CGA_BROWN          = 3,

    CGA_CYAN           = 1,     /* Palette C3 Color Names   */
    CGA_MAGENTA        = 2,
    CGA_LIGHTGRAY      = 3
};


enum EGA_COLORS {
    EGA_BLACK        =  0,      /* dark colors */
    EGA_BLUE         =  1,
    EGA_GREEN        =  2,
    EGA_CYAN         =  3,
    EGA_RED      =  4,
    EGA_MAGENTA      =  5,
    EGA_BROWN        =  20,
    EGA_LIGHTGRAY    =  7,
    EGA_DARKGRAY     =  56,     /* light colors */
    EGA_LIGHTBLUE    =  57,
    EGA_LIGHTGREEN   =  58,
    EGA_LIGHTCYAN    =  59,
    EGA_LIGHTRED     =  60,
    EGA_LIGHTMAGENTA     =  61,
    EGA_YELLOW       =  62,
    EGA_WHITE        =  63
};

enum line_styles {      /* Line styles for get/setlinestyle */
    SOLID_LINE   = 0,
    DOTTED_LINE  = 1,
    CENTER_LINE  = 2,
    DASHED_LINE  = 3,
    USERBIT_LINE = 4,   /* User defined line style */
};

enum line_widths {      /* Line widths for get/setlinestyle */
    NORM_WIDTH  = 1,
    THICK_WIDTH = 3,
};

enum font_names {
    DEFAULT_FONT    = 0,    /* 8x8 bit mapped font */
    TRIPLEX_FONT    = 1,    /* "Stroked" fonts */
    SMALL_FONT  = 2,
    SANS_SERIF_FONT = 3,
    GOTHIC_FONT = 4,
    SCRIPT_FONT = 5,
    SIMPLEX_FONT = 6,
    TRIPLEX_SCR_FONT = 7,
    COMPLEX_FONT = 8,
    EUROPEAN_FONT = 9,
    BOLD_FONT = 10
};

#define HORIZ_DIR   0   /* left to right */
#define VERT_DIR    1   /* bottom to top */

#define USER_CHAR_SIZE  0   /* user-defined char size */

enum fill_patterns {        /* Fill patterns for get/setfillstyle */
    EMPTY_FILL,     /* fills area in background color */
    SOLID_FILL,     /* fills area in solid fill color */
    LINE_FILL,      /* --- fill */
    LTSLASH_FILL,       /* /// fill */
    SLASH_FILL,     /* /// fill with thick lines */
    BKSLASH_FILL,       /* \\\ fill with thick lines */
    LTBKSLASH_FILL,     /* \\\ fill */
    HATCH_FILL,     /* light hatch fill */
    XHATCH_FILL,        /* heavy cross hatch fill */
    INTERLEAVE_FILL,    /* interleaving line fill */
    WIDE_DOT_FILL,      /* Widely spaced dot fill */
    CLOSE_DOT_FILL,     /* Closely spaced dot fill */
    USER_FILL       /* user defined fill */
};

enum putimage_ops {     /* BitBlt operators for putimage */
    COPY_PUT,       /* MOV */
    XOR_PUT,        /* XOR */
    OR_PUT,         /* OR  */
    AND_PUT,        /* AND */
    NOT_PUT         /* NOT */
};

enum text_just {        /* Horizontal and vertical justification
                   for settextjustify */
    LEFT_TEXT   = 0,
    CENTER_TEXT = 1,
    RIGHT_TEXT  = 2,

    BOTTOM_TEXT = 0,
     /* CENTER_TEXT = 1,  already defined above */
    TOP_TEXT    = 2
};


#define MAXCOLORS 15

struct palettetype {
    unsigned char size;
    signed char colors[MAXCOLORS+1];
};

struct linesettingstype {
    int linestyle;
    unsigned upattern;
    int thickness;
};

struct textsettingstype {
    int font;
    int direction;
    int charsize;
    int horiz;
    int vert;
};

struct fillsettingstype {
    int pattern;
    int color;
};

struct pointtype {
    int x, y;
};

struct viewporttype {
    int left, top, right, bottom;
    int clip;
};

struct arccoordstype {
    int x, y;
    int xstart, ystart, xend, yend;
};

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__DPMI16__)
void       _bgilink (void);
#pragma    extref _bgilink
#endif

void       far _BGIENTRY arc(int __x, int __y, int __stangle, int __endangle,
                             int __radius);
void       far _BGIENTRY bar(int __left, int __top, int __right, int __bottom);
void       far _BGIENTRY bar3d(int __left, int __top, int __right, int __bottom,
                               int __depth, int __topflag);
void       far _BGIENTRY circle(int __x, int __y, int __radius);
void       far _BGIENTRY cleardevice(void);
void       far _BGIENTRY clearviewport(void);
void       far _BGIENTRY closegraph(void);
void       far _BGIENTRY detectgraph(int far *__graphdriver,int far *__graphmode);
void       far _BGIENTRY drawpoly(int __numpoints, const int far *__polypoints);
void       far _BGIENTRY ellipse(int __x, int __y, int __stangle, int __endangle,
                                 int __xradius, int __yradius);
void       far _BGIENTRY fillellipse( int __x, int __y, int __xradius, int __yradius );
void       far _BGIENTRY fillpoly(int __numpoints, const int far *__polypoints);
void       far _BGIENTRY floodfill(int __x, int __y, int __border);
void       far _BGIENTRY getarccoords(struct arccoordstype far *__arccoords);
void       far _BGIENTRY getaspectratio(int far *__xasp, int far *__yasp);
int        far _BGIENTRY getbkcolor(void);
int        far _BGIENTRY getcolor(void);
struct palettetype far * far _BGIENTRY getdefaultpalette( void );
char *     far _BGIENTRY getdrivername( void );
void       far _BGIENTRY getfillpattern(char far *__pattern);
void       far _BGIENTRY getfillsettings(struct fillsettingstype far *__fillinfo);
int        far _BGIENTRY getgraphmode(void);
void       far _BGIENTRY getimage(int __left, int __top, int __right, int __bottom,
                                  void far *__bitmap);
void       far _BGIENTRY getlinesettings(struct linesettingstype far *__lineinfo);
int        far _BGIENTRY getmaxcolor(void);
int        far _BGIENTRY getmaxmode(void);
int        far _BGIENTRY getmaxx(void);
int        far _BGIENTRY getmaxy(void);
char *     far _BGIENTRY getmodename( int __mode_number );
void       far _BGIENTRY getmoderange(int __graphdriver, int far *__lomode,
                   int far *__himode);
unsigned   far _BGIENTRY getpixel(int __x, int __y);
void       far _BGIENTRY getpalette(struct palettetype far *__palette);
int        far _BGIENTRY getpalettesize( void );
void       far _BGIENTRY gettextsettings(struct textsettingstype far *__texttypeinfo);
void       far _BGIENTRY getviewsettings(struct viewporttype far *__viewport);
int        far _BGIENTRY getx(void);
int        far _BGIENTRY gety(void);
void       far _BGIENTRY graphdefaults(void);
char *     far _BGIENTRY grapherrormsg(int __errorcode);
void       far _BGIENTRY _graphfreemem(void far *__ptr, unsigned __size);
void far * far _BGIENTRY _graphgetmem(unsigned __size);
int        far _BGIENTRY graphresult(void);
unsigned   far _BGIENTRY imagesize(int __left, int __top, int __right, int __bottom);
void       far _BGIENTRY initgraph(int  far *__graphdriver,
                                   int  far *__graphmode,
                                   const char far *__pathtodriver);
int        far _BGIENTRY installuserdriver(const char far *__name,
                                           int huge (*detect)(void));
int        far _BGIENTRY installuserfont(const char far *__name);
void       far _BGIENTRY line(int __x1, int __y1, int __x2, int __y2);
void       far _BGIENTRY linerel(int __dx, int __dy);
void       far _BGIENTRY lineto(int __x, int __y);
void       far _BGIENTRY moverel(int __dx, int __dy);
void       far _BGIENTRY moveto(int __x, int __y);
void       far _BGIENTRY outtext(const char far *__textstring);
void       far _BGIENTRY outtextxy(int __x, int __y, const char far *__textstring);
void       far _BGIENTRY pieslice(int __x, int __y, int __stangle, int __endangle,
                                  int __radius);
void       far _BGIENTRY putimage(int __left, int __top, const void far *__bitmap,
                                  int __op);
void       far _BGIENTRY putpixel(int __x, int __y, int __color);
void       far _BGIENTRY rectangle(int __left, int __top, int __right, int __bottom);
void       far _BGIENTRY restorecrtmode(void);
void       far _BGIENTRY sector(int __X, int __Y, int __StAngle, int __EndAngle,
                                int __XRadius, int __YRadius);
void       far _BGIENTRY setactivepage(int __page);
void       far _BGIENTRY setallpalette(const struct palettetype far *__palette);
void       far _BGIENTRY setaspectratio(int __xasp, int __yasp);
void       far _BGIENTRY setbkcolor(int __color);
void       far _BGIENTRY setcolor(int __color);
void       far _BGIENTRY setfillpattern(const char far *__upattern, int __color);
void       far _BGIENTRY setfillstyle(int __pattern, int __color);
unsigned   far _BGIENTRY setgraphbufsize(unsigned __bufsize);
void       far _BGIENTRY setgraphmode(int __mode);
void       far _BGIENTRY setlinestyle(int __linestyle, unsigned __upattern,
                                      int __thickness);
void       far _BGIENTRY setpalette(int __colornum, int __color);
void       far _BGIENTRY setrgbpalette(int __colornum,
                                       int __red, int __green, int __blue);
void       far _BGIENTRY settextjustify(int __horiz, int __vert);
void       far _BGIENTRY settextstyle(int __font, int __direction, int __charsize);
void       far _BGIENTRY setusercharsize(int __multx, int __divx,
                                         int __multy, int __divy);
void       far _BGIENTRY setviewport(int __left, int __top, int __right, int __bottom,
                                     int __clip);
void       far _BGIENTRY setvisualpage(int __page);
void       far _BGIENTRY setwritemode( int __mode );
int        far _BGIENTRY textheight(const char far *__textstring);
int        far _BGIENTRY textwidth(const char far *__textstring);

/***** graphics drivers *****/

int        _BGIENTRY registerbgidriver(void (*driver)(void));

#if defined(__DPMI16__) || defined(__DPMI32__)
#define registerfarbgidriver registerbgidriver
#else
int    far _BGIENTRY registerfarbgidriver(void far *__driver);
#endif

/* !!        These "functions" are NOT user-callable          !! */
/* !! They are there just so you can link in graphics drivers !! */

void           _RTLENTRY CGA_driver(void);
void           _RTLENTRY EGAVGA_driver(void);
void           _RTLENTRY IBM8514_driver(void);
void           _RTLENTRY Herc_driver(void);
void           _RTLENTRY ATT_driver(void);
void           _RTLENTRY PC3270_driver(void);

#if defined(__DPMI16__)
void           _RTLENTRY CGA_driver_far(void);
void           _RTLENTRY EGAVGA_driver_far(void);
void           _RTLENTRY IBM8514_driver_far(void);
void           _RTLENTRY Herc_driver_far(void);
void           _RTLENTRY ATT_driver_far(void);
void           _RTLENTRY PC3270_driver_far(void);
#else
extern int far _RTLENTRY CGA_driver_far[];
extern int far _RTLENTRY EGAVGA_driver_far[];
extern int far _RTLENTRY IBM8514_driver_far[];
extern int far _RTLENTRY Herc_driver_far[];
extern int far _RTLENTRY ATT_driver_far[];
extern int far _RTLENTRY PC3270_driver_far[];
#endif

/***** graphics fonts *****/

int        _BGIENTRY registerbgifont(void (*font)(void));

#if defined(__DPMI16__) || defined(__DPMI32__)
#define registerfarbgifont registerbgifont
#else
int    far _BGIENTRY registerfarbgifont(void far *__font);
#endif

/* !!   These "functions" are NOT user-callable,   !! */
/* !! they are there just so you can link in fonts !! */

void           _RTLENTRY   triplex_font(void);
void           _RTLENTRY     small_font(void);
void           _RTLENTRY sansserif_font(void);
void           _RTLENTRY    gothic_font(void);

extern int far _RTLENTRY   triplex_font_far[];
extern int far _RTLENTRY     small_font_far[];
extern int far _RTLENTRY sansserif_font_far[];
extern int far _RTLENTRY    gothic_font_far[];

#ifdef __cplusplus
}
#endif

#endif
