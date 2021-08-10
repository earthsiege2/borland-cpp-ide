/*-----------------------------------------------------------------------*
 * filename - vprinter.c
 *
 * function(s)
 *        Hex8       - converts int to 8 hex digits
 *        __vprinter - sends formatted output
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#include <stdio.h>
#include <_printf.h>
#include <string.h>

static  char    NullString[] = "(null)";

#define Ssize 80
typedef struct
{
    char    S[Ssize];
    int     Scount;
    putnF   *putter;
    void    *outP;
    int     totalSent;
    int     eof_error;
} PutRec;

/*-----------------------------------------------------------------------*

Name            PutFlush - flush PutRec buffer to putter function

Usage           int PutFlush( PutRec *p )

Description     Flushes the PutRec buffer to the putter function.
                If an error occurs, p->eof_error is set to 1.

*------------------------------------------------------------------------*/

static void PutFlush( PutRec *p )
{
    if (p->Scount != 0)
    {
        if (!(*(p->putter))(p->S, p->Scount, p->outP))
            p->eof_error = 1;
        p->Scount = 0;
    }
}

/*-----------------------------------------------------------------------*

Name            PutToS - output a character to putter function

Usage           static void PutToS( char c, PutRec *p )

Description     Output one character to the _putrec buffer, and flush
                the buffer when full to the putter function.
                If an error occurs, p->eof_error is set to 1.

*------------------------------------------------------------------------*/

static void PutToS( char c, PutRec *p )
{
    if (p->Scount >= Ssize)
        PutFlush(p);
    p->S[p->Scount] = c;
    p->Scount++;
    p->totalSent++;
}

/*-----------------------------------------------------------------------*

Name            Hex8 - converts int to 8 hex digits

Usage           static void Hex8( unsigned n, char *buf )

Description     Convert 32 bit parameter (n) to 8 hex digits at buf.

*------------------------------------------------------------------------*/

static void Hex8 (unsigned long n, char *buf)
{
    int i, c;

    for (i = 7; i >= 0; i--)
    {
        if ((c = (int)n & 0x0f) < 10)
            buf[i] = c + '0';
        else
            buf[i] = c - 10 + 'A';
        n >>= 4;
    }
}

/*-----------------------------------------------------------------------*

__vprinter is a table-driven design, for speed and flexibility. There are
two tables.  The first table classifies all 7-bit ASCII chars and then the
second table is the switch table which points to the function blocks which
handle the various classes of characters.

All characters with the 8th bit set are currently classed as don't cares,
which is the class of character also used for normal alphabetics.  All
characters less than ' ' (0x20) are also classed as don't cares.

*------------------------------------------------------------------------*/

typedef
        enum
        {
                _si,    /* sign fill +/-        */
                _af,    /* alternate form       */
                _ar,    /* format (width or precision) by argument */
                _lj,    /* left justify         */

                _pr,    /* precision            */
                _nu,    /* numeral              */
                _lo,    /* long                 */
                _ld,    /* long double          */
                _sh,    /* short                */
                _fz,    /* fill zeros           */

                _de,    /* decimal              */
                _oc,    /* octal                */
                _un,    /* unsigned decimal     */
                _he,    /* hexadecimal          */

                _pt,    /* pointer              */
                _fl,    /* float                */
                _ch,    /* char                 */
                _st,    /* string               */

                _ns,    /* number sent          */
                _zz,    /* terminator           */
                _dc,    /* don't care           */
                _pc,    /* percent              */

                _ne,    /* near pointer         */
                _fa,    /* far pointer          */
        } characterClass;

        /*  Here is the table of classes, indexed by character. */

static unsigned char printCtype [96] =
{
/*       SP   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /  */
        _si,_dc,_dc,_af,_dc,_pc,_dc,_dc,_dc,_dc,_ar,_si,_dc,_lj,_pr,_dc,

/*        0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?  */
        _fz,_nu,_nu,_nu,_nu,_nu,_nu,_nu,_nu,_nu,_dc,_dc,_dc,_dc,_dc,_dc,

/*        _   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O  */
        _dc,_dc,_dc,_dc,_dc,_fl,_fa,_fl,_sh,_dc,_dc,_dc,_ld,_dc,_ne,_dc,

/*        P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _  */
        _dc,_dc,_dc,_dc,_dc,_dc,_dc,_dc,_he,_dc,_dc,_dc,_dc,_dc,_dc,_dc,

/*        `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o  */
        _dc,_dc,_dc,_ch,_de,_fl,_fl,_fl,_sh,_de,_dc,_dc,_lo,_dc,_ns,_oc,

/*        p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~ DEL  */
        _pt,_dc,_dc,_st,_dc,_un,_dc,_dc,_he,_dc,_dc,_dc,_dc,_dc,_dc,_dc,
};


/*---------------------------------------------------------------------*

Name            __vprinter - sends formatted output

Usage           int   __vprinter (putnF  *putter,
                                         void   *outP,
                                         const char   *formP,
                                         va_list *argP)

Prototype in    _printf.h

Description     The list of arguments *argP is combined with literal text in
                the format string *formP according to format specifications
                inside the format string.

                The supplied procedure *putter is used to generate the output.
                It is required to take the string S, which has been
                constructed by __vprinter, and copy it to the destination
                outP.  The destination may be a string, a FILE, or whatever
                other class of construct the caller requires.  It is possible
                for several calls to be made to *putter since the buffer S
                is of limited size.

                *putter is required to preserve  SI, DI.

                The only purpose of the outP argument is to be passed through
                to putter.

                The object at *argP is a record of unknown structure, which
                structure is interpreted with the aid of the format string.
                Each field of the structure may be an integer, long, double,
                or string (char *).  Chars may appear but occupy integer-sized
                cells.  Floats, character arrays, and structures may not
                appear.

Return value    The result of the function is a count of the characters sent to
                *outP.

                There is no error indication.  When an incorrect conversion
                spec is encountered __vprinter copies the format as a literal
                (since it is assumed that alignment with the argument list has
                been lost), beginning with the '%' which introduced the bad
                format.

                If the destination outP is of limited size, for example a
                string or a full disk, __vprinter does not know.  Overflowing
                the destination causes undefined results.  In some cases
                *putter is able to handle overflows safely, but that is not
                the concern of __vprinter.

                The syntax of the format string is:

                format ::=      ([literal] ['%' conversion ])* ;

                conversion ::=  '%' | [flag]* [width] ['.' precision]
                                      ['l'] type ;

                flag ::=        '-' | '+' | ' ' | '#' | '0' ;

                width ::=       '*' | number ;
                precision ::=   '.' ('*' | number) ;

                type ::=        'd'|'i'|'o'|'u'|'x'|'n'|'X'|'f'|'e'|'E'|
                                'g'|'G'|'c'|'s'|'p'|'N'|'F'

*---------------------------------------------------------------------*/
int __vprinter (putnF      *putter,
                void       *outP,
                const char *formP,
                va_list    argP)
{


    typedef
            enum
            {
            flagStage, fillzStage, wideStage, dotStage, precStage,
            ellStage, typeStage,
            } syntaxStages;

     typedef
            enum
            {
            altFormatBit = 1,       /* the '#' flag                 */
            leftJustBit  = 2,       /* the '-' flag                 */
            notZeroBit   = 4,       /* 0 (octal) or 0x (hex) prefix */
            fillZerosBit = 8,       /* zero fill width              */
            isLongBit    = 16,      /* long-type argument           */
            farPtrBit    = 32,      /* far pointers                 */
            alt0xBit     = 64,      /* '#' confirmed for %x format  */
            floatBit     = 128,     /* float arg 4 bytes not 8!     */
            LongDoubleBit= 256,     /* signal a long double argument*/
            isShortBit   = 512      /* long-type argument           */
            } flagBits;

    flagBits flagSet;

    char     fc;                    /* format char, from fmt string */
    char     isSigned;              /* chooses signed/unsigned ints */
    int      width;
    int      precision;
    char     plusSign;
    int      leadZ;
    char     *abandonP;             /* posn of bad syntax in fmt str*/
    char     tempStr [__CVTMAX__];  /* longest _realcvt or longtoa string*/
    PutRec   put;                   /* characters sent to putter    */

    char     hexCase;               /* upper/lower Hex alphabet     */
    unsigned long     tempL;
    unsigned          tempI;
    unsigned short    tempS;
    syntaxStages    stage;          /* was CH */
    char     c;
    char     *cP;
    int      radix;
    int      ndigits;
    int      len;

/*
General outline of the method:

First the string is scanned, and conversion specifications detected.

The preliminary fields of a conversion (flags, width, precision, long)
are detected and noted.

The argument is fetched and converted, under the optional guidance of
the values of the preliminary fields.  With the sole exception of the
's' conversion, the converted strings are first placed in the tempStr
buffer.

The contents of the tempStr (or the argument string for 's') are copied
to the output, following the guidance of the preliminary fields in
matters such as zero fill, field width, and justification.
*/

    put.Scount = put.totalSent = put.eof_error = 0;
    put.putter = putter;
    put.outP   = outP;

    for (;;)
    {


NEXT:
        for (;;)
        {
            /* This code is arranged to give in-line flow to the most frequent
             * case, literal transcription from *formP to *outP.
             */
            if ((fc = *formP++) == '\0')
                goto respond;           /* end of format string */
            if (fc == '%')              /* '%' char begins a conversion */
            {
                if ((fc = *formP) == '%')
                    formP++;            /* but "%%" is just a literal '%'. */
                else
                    break;
            }
            PutToS(fc,&put);            /* copy literal character */
        }

        /* If arrived here then a conversion specification has been
         * encountered.
         */
        abandonP = (char *)formP - 1;   /* abandon will print from '%' */
        stage = flagStage;
        leadZ = plusSign = 0;
        flagSet = farPtrBit;
        width = precision = -1;

                /*==================================*/
                /* loop to here when scanning flags */
                /*==================================*/

        for (;;)
        {
            fc = *formP++;              /* get next format character */
            if (fc < ' ')               /* filter out controls or highs */
                goto abandon;

/**************************************************************************
 *                 Main character classification switch                   *
 **************************************************************************/

            switch (printCtype[fc - ' '])
            {
            case (_af):                 /* when '#' was seen            */
                if (stage > flagStage)
                    goto abandon;
                flagSet |= altFormatBit;
                continue;

            case (_lj):                 /* when '-' was seen            */
                if (stage > flagStage)
                    goto abandon;
                flagSet |= leftJustBit;
                continue;

            case (_si):                 /* when ' ' or '+' was seen     */
                if (stage > flagStage)
                    goto abandon;
                if (plusSign != '+')
                    plusSign = fc;      /* ' ' ignored if '+' already   */
                continue;

            case (_ne):                 /* near pointer                 */
                flagSet &= ~farPtrBit;
                stage = ellStage;
                continue;

            case (_fa):                 /* far pointer                  */
                flagSet |= farPtrBit;
                stage = ellStage;
                continue;

            case (_fz):                 /* leading width '0' is a flag  */
                if (stage > flagStage)
                    goto case_nu;       /*   else it is just a digit    */
                if ((flagSet & leftJustBit) == 0)
                {
                    flagSet |= fillZerosBit;
                    stage = fillzStage; /*   but it must be part of width */
                }
                continue;

            case (_ar):
                /* When '*' is seen it causes the next argument to be
                 * taken, depending on the stage, as the width or
                 * precision.
                 */
                tempI = va_arg(argP,int);
                if (stage < wideStage)
                {
                    if ((int)tempI < 0)      /* is the width negative?       */
                    {
                        width = -tempI;
                        flagSet |= leftJustBit;
                    }
                    else
                        width = tempI;
                    stage = wideStage + 1;
                }
                else
                {
                    if (stage != precStage)
                        goto abandon;
                    precision = tempI;
                    stage++;
                }
                continue;

            case (_pr):                 /* when '.' is seen, precision  */
                if (stage >= precStage) /* should follow                */
                    goto abandon;
                stage = precStage;
                precision++;            /* if no digits, ANSI says zero */
                continue;
/*
        When a numeral is seen, it may be either part of a width, or
        part of the precision, depending on the stage.
*/
            case (_nu):                     /* when 0..9 seen               */
case_nu:
                fc -= '0';                  /* turn '0'-'9' to 0-9          */
                if (stage <= wideStage)     /* is it part of a width spec?  */
                {
                    stage = wideStage;
                    if (width == -1)        /* first width digit ?          */
                        width = (int)fc;    /*   default width was -1       */
                    else
                        width = (width * 10) + (int)fc;
                }
                else                        /* no, see if it's a precision  */
                {
                    if (stage != precStage) /* is it part of precision spec */
                        goto abandon;       /* no, it's just a literal      */

                    /* At this point we know that the precision specifier
                     * '.' has been seen, so we know that the precision
                     * is zero (set at '.') or greater.
                     */
                    precision = (precision * 10) + (int)fc;
                }
                continue;

            case (_lo):                     /* 'l' was seen (long)          */
                flagSet |= isLongBit;
                stage = ellStage;
                continue;

            case (_ld):                     /* 'L' was seen (long double)   */
                flagSet = (flagSet | LongDoubleBit) & ~isLongBit;
                stage = ellStage;
                continue;

            case (_sh):                     /* 'h' or 'H' was seen (short)  */
                flagSet = (flagSet | isShortBit) & ~isLongBit;
                stage = ellStage;
                continue;

/*--------------------------------------------------------------------------
The previous cases covered all the possible flags.  Now the following
cases deal with the different argument types.

Remember fc contains a copy of the original character.
--------------------------------------------------------------------------*/

        /*==========================================================*/
        /* The first group of cases is for the integer conversions. */
        /*==========================================================*/

            case (_oc):                 /* octal                        */
                radix = 8;
                goto NoSign;
            case (_un):                 /* unsigned                     */
                radix = 10;
                goto NoSign;
            case (_he):                 /* hex                          */
                radix = 16;
                hexCase = fc - 'X' + 'A'; /* Adjust for aAbBcC etc later  */
NoSign:
                plusSign = 0;           /* It's an unsigned operand     */
                isSigned = 0;
                goto toAscii;

            case (_de):                 /* decimal                      */
                radix = 10;
                isSigned = 1;
toAscii:
                if (flagSet & isLongBit)
                    tempL = va_arg(argP,unsigned long);
                else if (flagSet & isShortBit)
                {
                    tempS = va_arg(argP,short);
                    if (isSigned)       /* check for sign extension     */
                        tempL = (unsigned long)(short)tempS;
                    else
                        tempL = (unsigned long)tempS;
                }
                else
                {
                    tempI = va_arg(argP,int);
                    if (isSigned)       /* check for sign extension     */
                        tempL = (unsigned long)(int)tempI;
                    else
                        tempL = (unsigned long)tempI;
                }

                cP = &tempStr[1];
                if (tempL == 0)
                {
                    /* ANSI special case where the value is zero and
                     * the precision is zero: don't print anything.
                     */
                    if (precision == 0)
                    {
                        *cP = '\0';
                        goto converted;
                    }
                }
                else
                    flagSet |= notZeroBit;  /* flag non-zeroness           */

/*-------------------------------------------------------------------------
        "Normal" integer output cases wind up down here somewhere.
-------------------------------------------------------------------------*/

                __longtoa(tempL, cP, radix, isSigned, hexCase);
converted:
                if (precision >= 0)
                {
                    len = ndigits = strlen(cP);
                    if (*cP == '-')         /* Is the number negative? */
                        ndigits--;          /* decrement no. of digits */
                    else if (plusSign != '\0')
                    {                       /* It's positive and needs sign */
                        len++;              /* Increase length of string */
                        *--cP = plusSign;   /* Insert a '+' */
                    }

                    /* Calculate no. of leading zeros based on precision
                     * and the number of digits, NOT on the field width
                     * and the length of the converted number.
                     */
                    if (precision > ndigits)
                        leadZ = precision - ndigits;
                    goto CopyLen;
                }
                else
                    goto testFillZeros;

            case (_pt):                 /* pointer      */
                cP = va_arg(argP,char *);
                Hex8((unsigned long)cP,tempStr);
                tempStr[8] = '\0';
                isSigned = 0;
                flagSet &= ~notZeroBit;
                cP = tempStr;
                goto testFillZeros;

            case (_ch):                 /* char         */

                /* The 'c' conversion takes a character as parameter.
                 * Note, however, that the character occupies an
                 * (int) sized cell in the argument list.
                 */
                tempStr[0] = (char)va_arg(argP,int);
                tempStr[1] = '\0';
                cP = tempStr;
                len = 1;
                goto CopyLen;

            case (_st):                 /* string       */

                /* The 's' conversion takes a string (char *) as
                 * argument and copies the string to the output
                 * buffer.
                 */
                cP = va_arg(argP,char *);
                if (cP == NULL)
                    cP = NullString;
                if ((len = strlen(cP)) > precision && precision >= 0)
                    len = precision;    /* precision may truncate string. */
                goto CopyLen;

            case (_fl):                 /* float        */

                /* All real-number conversions are done by __realcvt.
                 */
                __realcvt(
                    argP,
                    precision < 0 ? 6 : precision,  /* default prec. is 6 */
                    cP = &tempStr[1],
                    fc,
                    flagSet & altFormatBit,
                    flagSet & LongDoubleBit ? F_10byteFloat : F_8byteFloat);

#if 1
                /* Avoid generating reference to __fltused or __turboFloat
                 * by using external function to advance arg pointer.
                 */
                argP = __nextreal(argP,flagSet & LongDoubleBit);
#else
                if (flagSet & LongDoubleBit)
                    va_arg(argP,long double);
                else
                    va_arg(argP,double);
#endif

testFillZeros:
                if ((flagSet & fillZerosBit) && width > 0)
                {
                    len = strlen(cP);
                    if (*cP == '-')
                        len--;          /* Length too long because '-'  */
                    if (width > len)    /* leadZ defaulted to 0 before  */
                        leadZ = width - len;
                }

/*
If arrived here, then tempStr contains the result of a numeric
conversion.  It may be necessary the prefix the number with
a mandatory sign or space.
*/

                /* If we need a sign and it's not there already,
                 * back up 1 in the string and insert the sign.
                 * Adjust number of leading zeros down by one
                 * if precision not specified.
                 */
                if (*cP == '-' || plusSign != '\0')
                {
                    if (*cP != '-')
                        *--cP = plusSign;
                    if (leadZ > 0 && precision < 0)
                        leadZ--;
                }

/*
If arrived here then cP points to the converted string,
which must now be padded, aligned, and copied to the output.
*/

                len = strlen(cP);
CopyLen:                                /* comes from %c or %s section  */

                if ((flagSet & (notZeroBit | altFormatBit))
                            == (notZeroBit | altFormatBit))
                {
                    if (fc == 'o')      /* Is it alternate octal form?  */
                    {
                        if (leadZ <= 0) /* Yes, alternate mode w/octal  */
                            leadZ = 1;  /*     one leading zero.        */
                     }
                    else if (fc == 'x' || fc == 'X')
                    {
                        /* Alternate hex form: send 0x or 0X prefix.
                         */
                        flagSet |= alt0xBit;
                        width -= 2;
                        if ((leadZ -= 2) < 0)   /* Still leading 0's?   */
                            leadZ = 0;          /* No more leading 0's  */
                    }
                }
                len += leadZ;

                /* If result is NOT left justified, insert leading spaces.
                 */
                if ((flagSet & leftJustBit) == 0)
                {                               /* (! leftJust) == leftFill */
                    while (width > len)
                    {
                        PutToS(' ',&put);
                        width--;
                    }
                }

                /* Need alternate hex form?
                 */
                if (flagSet & alt0xBit)
                {                       /* Yes, Send "0x" or "0X"       */
                    PutToS('0',&put);
                    PutToS(fc,&put);    /* fc is 'x' or 'X'             */
                }

                /* Leading zero fill required?
                 */
                if (leadZ > 0)
                {
                    len -= leadZ;
                    width -= leadZ;

                    /* Any leading sign must be copied before
                     * the leading zeroes.
                     */
                    if (*cP == '-' || *cP == ' ' || *cP == '+')
                    {
                        PutToS(*cP++,&put);
                        len--;
                        width--;
                    }

                    while (leadZ--)
                        PutToS('0',&put);
                }

                /* Now we copy the actual converted string from tempStr
                 * to output.
                 */
                if (len != 0)
                {
                    width -= len;
                    while (len--)
                        PutToS(*cP++,&put);
                }

                /* Is the field to be right-filled?
                 */
                while (width-- > 0)         /* while any remaining width */
                    PutToS(' ',&put);

                /* If arrive here, the conversion has been done and copied
                 * to output.
                 */
                goto NEXT;

            case (_ns) :                 /* number sent */
                cP = va_arg(argP,char *);
                if (flagSet & isLongBit)
                    *((long *)cP) = put.totalSent;
                else if (flagSet & isShortBit)
                    *((short *)cP) = put.totalSent;
                else
                    *((int *)cP) = put.totalSent;
                goto NEXT;


            case (_zz):
            case (_dc):
            case (_pc):
                /* \0 characters, unexpected end of format string,
                 * ordinary "don't care" chars in the wrong position,
                 * '%' percent characters in the wrong position
                 */
                goto abandon;

            }               /* end switch */
        }
    }

    /* If the format goes badly wrong, then copy it literally to the output
     * and abandon the conversion.
     */

abandon:

    while ((c = *abandonP++) != '\0')
        PutToS(c,&put);


    /* If arrived here then the function has finished
     * (either correctly or not).
     */

respond:

    PutFlush(&put);
    if (put.eof_error)
        return (EOF);
    else
        return (put.totalSent);
}
