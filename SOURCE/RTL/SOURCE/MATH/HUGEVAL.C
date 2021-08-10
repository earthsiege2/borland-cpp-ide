/*------------------------------------------------------------------------
 * filename - hugeval.c
 *
 * function(s)
 *        none
 *-----------------------------------------------------------------------*/

#include <_defs.h>

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $        */

/*--------------------------------------------------------------------------*

Constants for HUGE_VAL and related constants.

Some numbers are stored as global data items either because
it is difficult to represent them in ASCII form, or because
the program may wish to change them.

The rationale for the maximum numbers is that these are the
largest "representable" numbers in the format.  INF and NAN
are not considered representable.  It is perfectly valid to
consider these representable, just not traditional.  For some
applications it is indeed preferable, and it may be the default
for some future release of Turbo C.

Note that HUGE_VAL is now represented as +INF.  This allows for better
error detection and is compatible with most other platforms.  It is
explicitly allowed by ANSI on platforms that support it.

Approximate decimal values are:

    _huge_flt           3.40282347E+38F
    _huge_dble      1.7976931348623158E+308
    _huge_ldble     1.189731495357232E+4932L
    _tiny_ldble     3.362103143112094E-4932L

Declarations are in <math.h> and in <float.h>.

_indefinite is not used, and provided only for the convenience
of those using INFs and NANs.  Declare it with

    extern float cdecl _indefinite;

Its value is the NAN preferred by the 8087 chip.

*---------------------------------------------------------------------------*/

#define UsingINF    1

#if UsingINF

/* +INF in various formats */
unsigned short _RTLENTRY _EXPDATA _huge_flt[] = { 0, 0x7F80 };
unsigned short _RTLENTRY _EXPDATA _huge_dble[] = { 0, 0, 0, 0x7FF0 };
unsigned short _RTLENTRY _EXPDATA _huge_ldble[] = { 0, 0, 0, 0x8000, 0x7FFF };

unsigned short _RTLENTRY _EXPDATA _max_flt[] = { -1, 0x7F7F };
unsigned short _RTLENTRY _EXPDATA _max_dble[] = { -1, -1, -1, 0x7FEF };
unsigned short _RTLENTRY _EXPDATA _max_ldble[] = { -1, -1, -1, -1, 0x7FFE };

#else

unsigned short _RTLENTRY _EXPDATA _huge_flt[] = { -1, 0x7F7F };
unsigned short _RTLENTRY _EXPDATA _huge_dble[] = { -1, -1, -1, 0x7FEF };
unsigned short _RTLENTRY _EXPDATA _huge_ldble[] = { -1, -1, -1, -1, 0x7FFE };

#endif

unsigned short _RTLENTRY _EXPDATA _indefinite[] = { 0, 0x7FC0 }; /* float */
unsigned short _RTLENTRY _EXPDATA _tiny_ldble[] = { 0, 0, 0, 0x8000, 1 };


/*---------------------------------------------------------------------------*/

/* Various special IEEE double (64-bit) values */

/*
   p     = positive
   n     = negative
   inf   = infinity
   nan   = Not-A-Number
   q     = quiet
   s     = signaling
*/

unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_p_inf  = 0x7FF0000000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_n_inf  = 0xFFF0000000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_p_nanq = 0x7FF8F00000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_n_nanq = 0xFFF8F00000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_p_nans = 0x7FF0F00000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_n_nans = 0xFFF0F00000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_p_zero = 0x0000000000000000Ui64;
unsigned __int64 _RTLENTRY _EXPDATA __ieee_64_n_zero = 0x8000000000000000Ui64;

