/*-----------------------------------------------------------------------*
 * filename - mbbis.c
 *
 * function(s)     - replaces a macro of mbctype.h
 *        _ismbbkalpha
 *        _ismbbkpunct
 *        _ismbbkana
 *        _ismbbalpha
 *        _ismbbpunct
 *        _ismbbalnum
 *        _ismbbprint
 *        _ismbbgraph
 *        _ismbblead
 *        _ismbbtrail
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>

int (_RTLENTRY _EXPFUNC _ismbbkalpha)(unsigned int c)
{
    return _ismbbkalpha(c);
}

int (_RTLENTRY _EXPFUNC _ismbbkpunct)(unsigned int c)
{
    return _ismbbkpunct(c);
}

int (_RTLENTRY _EXPFUNC _ismbbkana)(unsigned int c)
{
    return _ismbbkana(c);
}

int (_RTLENTRY _EXPFUNC _ismbbalpha)(unsigned int c)
{
    return _ismbbalpha(c);
}

int (_RTLENTRY _EXPFUNC _ismbbpunct)(unsigned int c)
{
    return _ismbbpunct(c);
}

int (_RTLENTRY _EXPFUNC _ismbbalnum)(unsigned int c)
{
    return _ismbbalnum(c);
}

int (_RTLENTRY _EXPFUNC _ismbbprint)(unsigned int c)
{
    return _ismbbprint(c);
}

int (_RTLENTRY _EXPFUNC _ismbbgraph)(unsigned int c)
{
    return _ismbbgraph(c);
}

int (_RTLENTRY _EXPFUNC _ismbblead)(unsigned int c)
{
    return _ismbblead(c);
}

int (_RTLENTRY _EXPFUNC _ismbbtrail)(unsigned int c)
{
    return _ismbbtrail(c);
}
