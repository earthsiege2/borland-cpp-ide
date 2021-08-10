/*-----------------------------------------------------------------------*
 * filename - scanner.c
 *
 * function(s)
 *        _scanner - reads formatted input
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.6  $        */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <_tchar.h>
#include <_scanf.h>

/*-----------------------------------------------------------------------*

Macros for manipulating sets of characters

*------------------------------------------------------------------------*/

#define BIT_SET(a,n) a[(n>>3)&0x1f] |= (1<<(n&7))
#define BIT_CLR(a,n) a[(n>>3)&0x1f] &= ~(1<<(n&7))
#define BIT_TST(a,n) ((a[(n>>3)&0x1f] & (1<<(n&7)))!=0)
#define BIT_CLRALL(a) memset(a,0,32);

#define false 0
#define true  1

typedef char bits_t[32];

/* Set up some UNICODE defines */
#define DEFWIDTH  (sizeof (_TCHAR) == sizeof (wchar_t))


/*-----------------------------------------------------------------------*

The scanner is a simple table-driven design, for speed and flexibility.
There are two tables.  The first table classifies all 7-bit ASCII chars
and then the second table is the switch table which points to the function
blocks which handle the various classes of characters.

All characters with the 8'th bit set are currently classed as don't cares,
which is the class of character also used for normal alphabetics.

Warning: If you reject gotos you will be allergic to this.  Normally
         I avoid gotos but for fast lexical analysis I make an exception.

*------------------------------------------------------------------------*/

typedef enum
{
    _zz,        /* terminator                           */
    _ws,        /* space                                */
    _dc,        /* dont care                            */
    _pc,        /* percent                              */
    _su,        /* suppress                             */
    _nu,        /* numeral                              */
    _ch,        /* character                            */
    _Ch,        /* character, opposite width            */
    _de,        /* decimal                              */
    _un,        /* unsigned decimal - same as decimal   */
    _in,        /* general int                          */
    _fl,        /* float                                */
    _ld,        /* long double, __int64                 */
    _ha,        /* half                                 */
    _lo,        /* long                                 */
    _oc,        /* octal                                */
    _st,        /* string                               */
    _St,        /* string, opposite width               */
    _sc,        /* scanset                              */
    _ct,        /* count of characters scanned          */
    _he,        /* hexadecimal                          */
    _pt,        /* pointer                              */
    _ne,        /* near                                 */
    _fa,        /* far                                  */
    _wi,        /* I64 ...                              */
}
    charClass;


static  const   char    scanCtype [128] =
{
/*  NUL SOH STX ETX EOT ENQ ACK BEL  BS  HT  LF  VT  FF  CR  SO  SI     */
    _zz,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_ws,_ws,_ws,_ws,_ws,_dc,_dc,

/*  DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN  EM SUB ESC  FS  GS  RS  US     */
    _dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,

/*  SP   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /      */
    _ws,_dc,_dc,_dc,_dc,_pc,_dc,_dc,_dc,_dc,_su,_dc,_dc,_dc,_dc,_dc,

/*   0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?      */
    _nu,_nu,_nu,_nu,_nu,_nu,_nu,_nu,_nu,_nu,_dc,_dc,_dc,_dc,_dc,_dc,

/*   @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O      */
    _dc,_dc,_dc,_Ch,_de,_fl,_fa,_fl,_ha,_wi,_dc,_dc,_ld,_dc,_ne,_oc,

/*   P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _      */
    _dc,_dc,_dc,_St,_dc,_un,_dc,_dc,_he,_dc,_dc,_sc,_dc,_sc,_dc,_dc,

/*   `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o      */
    _dc,_dc,_dc,_ch,_de,_fl,_fl,_fl,_ha,_in,_dc,_dc,_lo,_dc,_ct,_oc,

/*   p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~ DEL      */
    _pt,_dc,_dc,_st,_dc,_un,_dc,_dc,_he,_dc,_dc,_dc,_dc,_dc,_dc,_dc,
};

#define IS_WHITE(ch) ((ch & 0x80) == 0 && scanCtype[(ch & 0x7F)] == _ws)

/*-----------------------------------------------------------------------*

Name            _scanner - reads formatted input

Usage           int  _scanner ( int   (*Get)(void *srceP),
                                void  (*UnGet) (int ch, void *srceP),
                                void   *srceP,
                                const char   *formP,
                                va_list varPP )

Prototype in

Description     _scanner does all the work for the scanf family of
                functions.

                The "source" *srceP is scanned according to the rules found in the
                format string *formP and the results are put to the places pointed
                to by the array of pointers *varPP.

                The "Get" and "UnGet" functions allow the redefinition of the
                source to be a file or any other serial character stream.  They
                may be the fget()/ungetc() or any equivalent pair which operates
                on the srceP data stream/string.


                The syntax of the format string is:

                format ::= ([isspace] [literal | '%%' | '%' conversion])*

                conversion ::= ['*'] [width] ['l' | 'h'] [type]

                width ::= number;

                type ::= 'd'|'D'|'u'|'U'|'o'|'O'|'x'|'X'|'i'|'I'|'n'|
                         'e'|'E'|'f'|'F'|'g'|'G'|'p'|'N'|'F'|'s'|'c'|'['

Return value

*------------------------------------------------------------------------*/

int  _scannert( int   (*__Gett)   (void *srceP),
                    void  (*__UnGett) (int ch, void *srceP),
                    void       *srceP,
                    const _TCHAR *formP,
                    va_list     varPP )
{


    flagBits flags;
    int     count = 0;
    int     charCt = 0;
    int     status;
    int     width;
    int     base;
    bits_t  bitSet;    /* for scan sets */
    int     exclude;
    _TCHAR  a, b;
    __int64 lRes;
    unsigned short ldRes[5];    /* actually a long double */
    int     nscanned;
    charClass curClass;
    int     paramIsWide;
    union
    {
        char     *PtrA;
        wchar_t  *PtrW;
    } DualPtr;

#define cPA       (DualPtr.PtrA)
#define cPW       (DualPtr.PtrW)
#ifdef _UNICODE
#  define cP      (DualPtr.PtrW)
#else
#  define cP      (DualPtr.PtrA)
#endif

ssNEXT:
    if (_TEXT('\0') == (b = *(formP++)))
        return  count;  /* the normal end */

    if ((b != _TEXT('%'))  || (_TEXT('%') == (b = *formP++)))
    {
        charCt ++;
        if ((a = __Gett (srceP)) == _TEOF)
            goto ssEOF;
        if (IS_WHITE(b))                    /* white space ? */
        {
            while (IS_WHITE(a))
            {
                charCt ++;
                if ((a = __Gett (srceP)) == _TEOF)
                    goto ssEOF;
            }
            __UnGett (a, srceP);
            charCt --;
        }
        else    /* literal match required */
        {
            if (a != b)
            {
                __UnGett (a, srceP);
                goto  ssEND;
            }
#if defined(_MBCS)
            if (_istleadbyte (a) && *formP)
            {
                if ((b = __Gett (srceP)) == _TEOF)
                    goto ssEOF;
                if (b != *(formP++))
                {
                    __UnGett (b, srceP);
                    __UnGett (a, srceP);
                    goto  ssEND;
                }
                charCt ++;
            }
#endif
        }
        goto  ssNEXT;
    }

    /* If fall through to here then begin a conversion specification.
     */
    flags = isFarPtr;
    width  = -1;
    paramIsWide = DEFWIDTH;

ssSwitch:
    curClass = (b & 0x80) ? _dc : scanCtype [b & 0x7F];
    switch (curClass)
    {
        case (_su) :    flags |= isSuppressed;
                        b = *(formP++);
                        goto  ssSwitch;

        case (_ha) :    flags |= isHalf;
                        b = *(formP++);
                        goto  ssSwitch;

        case (_lo) :    flags |= isLong;
                        b = *(formP++);
                        goto  ssSwitch;

        case (_ld) :    flags |= isLongDouble;
                        b = *(formP++);
                        goto  ssSwitch;

        case (_nu) :    width = (width < 0) ? b - _TEXT('0') :
                                10 * width + b - _TEXT('0');
                        b = *(formP++);
                        goto  ssSwitch;

        case (_ne) :    flags &= ~isFarPtr;
                        b = *(formP++);
                        goto  ssSwitch;

        case (_fa) :    flags |= isFarPtr;
                        b = *(formP++);
                        goto  ssSwitch;

        case (_wi) :
                        if (formP[0] == _TEXT('6') && formP[1] == _TEXT('4'))
                        {
                                flags = isLongDouble | (flags & ~(isLong | isHalf));
                                formP += 2;
                        }
                        else
                        if (formP[0] == _TEXT('3') && formP[1] == _TEXT('2'))
                        {
                                flags = isLong | (flags & ~(isLongDouble | isHalf));
                                formP += 2;
                        }
                        else
                        if (formP[0] == _TEXT('1') && formP[1] == _TEXT('6'))
                        {
                                flags = isHalf | (flags & ~(isLongDouble | isLong));
                                formP += 2;
                        }
                        else
                        if (formP[0] == _TEXT('8'))
                        {
                                flags &= ~(isLongDouble | isLong | isHalf);
                                formP += 1;
                        }


                        b = *(formP++);
                        goto  ssSwitch;


        case (_pt) :    goto  ssPTR;

        case (_un) :
        case (_de) :    base = 10;
                        goto  ssINT;

        case (_oc) :    base = 8;
                        goto  ssINT;

        case (_he) :    base = 16;
                        goto  ssINT;

        case (_in) :    base = 0;
                        goto  ssINT;

        case (_ct) :    lRes = charCt;
                        goto  ssPUTINT;

        case (_fl) :    goto  ssFLOAT;

        case (_St) :
        case (_st) :    goto  ssTOKEN;

        case (_Ch) :
        case (_ch) :    goto  ssCHAR;

        case (_sc) :    goto  ssSCANSET;

        case (_dc) :    goto  ssEND;

        default: /*  never occurs.  */;
    }

ssINT:
    lRes = __scanttoint64 (__Gett, __UnGett, srceP, base, width & 0x7FFF,
                        &charCt, &status);
    if (status < 0)
        goto ssEOF;
    else if (status == 0)
        goto ssEND;

ssPUTINT:
    if ((_TEXT('A') <= b) && (b <= _TEXT('Z')) && (b != _TEXT('X')))
        flags |= isLong;

    if ((flags & isSuppressed) == 0)
    {
        if (flags & isLongDouble)
            *va_arg(varPP,__int64 *) = lRes;
        else
        if (flags & isLong)
            *va_arg(varPP,long *) = lRes;
        else if (flags & isHalf)
            *va_arg(varPP,short *) = (short)lRes;
        else *va_arg(varPP,int *) = (int)lRes;
        if (b != _TEXT('n'))
            count ++;
    }
    goto  ssNEXT;

ssPTR:
    lRes = __scanttoint64 (__Gett, __UnGett, srceP, 16, 8, &charCt, &status);
    if (status <= 0)
        goto ssEND;
    if ((flags & isSuppressed) == 0)
    {
        *va_arg(varPP,long *) = lRes;
        count ++;
    }
    goto  ssNEXT;


ssFLOAT:
    /* We don't actually reference any floating point values in this
     * code, so as to avoid linking in the floating point conversion
     * routines in integer-only programs.  We also assume that a
     * pointer to a floating point number is the same size as a pointer
     * to a void.
     */
    _scanttod (ldRes,__Gett, __UnGett, srceP, width & 0x7FFF, &charCt, &status);
    if (status < 0)
        goto ssEOF;
    else if (status == 0)
        goto ssEND;

    if ((flags & isSuppressed) == 0)
    {
        _scanrslt(ldRes, va_arg(varPP, void *), flags);
        count ++;
    }
    goto  ssNEXT;

ssTOKEN:
    /* Skip leading whitespace.
     */

    if (flags & isLong)
      paramIsWide = 1;    /* string width forced to wide */
    else
    if (flags & isHalf)  /* string width forced to narrow */
      paramIsWide = 0;
    else
    if (curClass == _St)  /* opposite width string */
      paramIsWide = !paramIsWide;

    do
    {
        charCt++;
        if ((a = __Gett(srceP)) == _TEOF)
            goto ssEOF;
    } while (IS_WHITE(a));

    if ((flags & isSuppressed) == 0)
    {
        if (paramIsWide)
          cPW = va_arg(varPP, wchar_t *);
        else
          cPA = va_arg(varPP, char *);
        count ++;
    }
    if (width == -1)                /* default width becomes 7fff */
        width = 0x7FFF;

    /* Copy until EOF, null, or whitespace character is seen, or field
     * width is exceeded.
     */
    do
    {
        if ((flags & isSuppressed) == 0)
        {
            if (paramIsWide == DEFWIDTH)
              *(cP++) = a;
            else
            {
#if defined (_UNICODE)
                /* convert from wide to narrow here */
                char mbBuf[MB_CUR_MAX];  /* maximum length for a MB char? */
                int ret;
                char *pt;
                ret = wctomb (mbBuf, a);
                pt = mbBuf;
                if (ret > 0 )  /* else skip this one */
                    while (ret--)
                        *(cP++) = *pt++;
                else
                  --charCt;
#else
                /* convert from narrow to wide here */
                int ret;
                wchar_t wch;
                ret = mbtowc (&wch, cP, MB_CUR_MAX);
                if (ret > 0 )  /* else skip this one */
                    *(cP++) = wch;
                else
                  --charCt;

#endif /* _UNICODE */
            }
        }
        ++charCt;
        a = __Gett(srceP);
    } while (a != _TEOF && (a != _TEXT('\0')) && (!IS_WHITE(a)) && (--width > 0));

    __UnGett(a, srceP);                /* push back the last character */
    --charCt;

    if ((flags & isSuppressed) == 0)
        if (paramIsWide)
            *cPW = L'\0';
        else
            *cPA = '\0';


    goto  ssNEXT;

ssCHAR:

    if (flags & isLong)
      paramIsWide = 1;    /* char width forced to wide */
    else
    if (flags & isHalf)  /* char width forced to narrow */
      paramIsWide = 0;
    else
    if (curClass == _Ch)  /* opposite width char */
      paramIsWide = !paramIsWide;



    if ((flags & isSuppressed) == 0)
        if (paramIsWide)
          cPW = va_arg(varPP, wchar_t *);
        else
          cPA = va_arg(varPP, char *);

    if (width < 0)
        width = 1;
    if (width)
    {
        do
        {
            charCt ++;
            if ((a = __Gett (srceP)) == _TEOF)
                goto ssEOF;
            if ((flags & isSuppressed) == 0)
            {
                if (paramIsWide == DEFWIDTH)
                  *(cP++) = a;
                else
                {
#if defined (_UNICODE)
                    /* convert from wide to narrow here */
                    char mbBuf[MB_CUR_MAX];  /* maximum length for a MB char? */
                    int ret;
                    char *pt;
                    ret = wctomb (mbBuf, a);
                    pt = mbBuf;
                    if (ret > 0 )  /* else skip this one */
                        while (ret--)
                            *(cP++) = *pt++;
#else
                    /* convert from narrow to wide here */
                    int ret;
                    wchar_t wch;
                    ret = mbtowc (&wch, cP, MB_CUR_MAX);
                    if (ret > 0 )  /* else skip this one */
                        *(cP++) = wch;

#endif /* _UNICODE */
                }

            }
        }
        while (--width > 0);
    }
    if ((flags & isSuppressed) == 0)
        count ++;
    goto  ssNEXT;


ssSCANSET:

/*      scanset ::= ['^'] [']'] [nonFinalSet] ']'       */

    BIT_CLRALL(bitSet);

    exclude = false;
    if (_TEXT('^') == (a = *(formP++)))
    {
        exclude = true;
        a = *(formP++);
    }

    /* Set a bit in the bitmap for each character in the set.
     */
    for (;;)
    {
        b = a;                  /* save potential first char in range */
        if (a == _TEXT('\0'))   /* unexpected end of format */
            goto ssEND;
        BIT_SET(bitSet,a);
        if (_TEXT(']') == (a = *(formP++)))
            break;
        if ((_TEXT('-') == a) && (b < *formP) && (_TEXT(']') != *formP))
        {
            a = *(formP++);     /* ending character in range */
            while ( ++b < a)
                BIT_SET(bitSet,b);
        }
    }

    if (width == -1)            /* default width is huge */
        width = 0x7FFF;

    if ((flags & isSuppressed) == 0)
        cP = va_arg(varPP,_TCHAR *);

    nscanned = 0;
    while (--width >= 0)
    {
        charCt ++;
        if ((a = __Gett (srceP)) == _TEOF)
            break;
        if (exclude == (BIT_TST(bitSet,a)))
            break;
        nscanned++;
        if ((flags & isSuppressed) == 0)
            *(cP++) = a;
    }
    if (width >= 0)
    {
        __UnGett (a, srceP);
        charCt --;
    }
    if (nscanned != 0 && (flags & isSuppressed) == 0)
    {
        *(cP++) = _TEXT('\0');
        count++;
    }
    if (a == _TEOF)
        goto ssEOF;
    else
        goto  ssNEXT;

ssEOF:
    __UnGett(EOF, srceP);
    if (count == 0)
        return (-1);
ssEND:
    return (count);
}
