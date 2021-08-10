/*  values.h

    Symbolic names for important constants, including machine
    dependencies. A System V compatible header.

*/

/*
 *      C/C++ Run Time Library - Version 6.0
 *
 *      Copyright (c) 1987, 1993 by Borland International
 *      All Rights Reserved.
 *
 */

#if !defined(__VALUES_H)
#define __VALUES_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#define BITSPERBYTE 8
#define MAXSHORT    0x7FFF

#if !defined(__FLAT__)
#define MAXINT      0x7FFF
#else    /* defined __FLAT__ */
#define MAXINT      0x7FFFFFFF
#endif

#define MAXLONG     0x7FFFFFFFL
#define HIBITS      0x8000
#define HIBITI      0x8000
#define HIBITL      0x80000000

#define DMAXEXP     308
#define FMAXEXP     38
#define DMINEXP     -307
#define FMINEXP     -37

#define MAXDOUBLE   1.797693E+308
#define MAXFLOAT    3.37E+38F
#define MINDOUBLE   2.225074E-308
#define MINFLOAT    8.43E-37F

#define DSIGNIF     53
#define FSIGNIF     24

#define DMAXPOWTWO  0x3FF
#define FMAXPOWTWO  0x7F
#define DEXPLEN     11
#define FEXPLEN     8
#define EXPBASE     2
#define IEEE        1
#define LENBASE     1
#define HIDDENBIT   1
#define LN_MAXDOUBLE    7.0978E+2
#define LN_MINDOUBLE    -7.0840E+2

#endif  /* __VALUES_H */
