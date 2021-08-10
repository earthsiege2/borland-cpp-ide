/*------------------------------------------------------------------------
 * filename - mathptr2.c
 *
 * function(s)
 *        _set_matherr_handler  - get/set pointer to matherr handler
 *        _set_matherrl_handler - get/set pointer to matherrl handler
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1999, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <math.h>
#include <_math.h>

/*------------------------------------------------------------------------*

Name            _set_matherr_handler - get/set pointer to matherr handler

Usage           matherrptr _set_matherr_handler(matherrptr matherr)

Prototype in    math.h

Description     This function initializes the internal _pmatherr pointer to
                point to the users _matherr error handling routine.  This is
                usefull for moving the matherr handling from the EXE into a
                DLL.

NOTES:          If NULL is passed in, then the RTL's default internal handler
                is used.

Return value    The previous address of the handler.

*-------------------------------------------------------------------------*/

matherrptr _RTLENTRY _EXPFUNC _set_matherr_handler(matherrptr matherr)
{
    matherrptr tmp = _pmatherr;

    if (!matherr)
      matherr = _matherr;

    _pmatherr = matherr;

    return tmp;
}

/*------------------------------------------------------------------------*

Name            _set_matherrl_handler - get/set pointer to matherrl handler

Usage           matherrptrl _set_matherrl_handler(matherrptrl matherrl)

Prototype in    math.h

Description     This function initializes the internal _pmatherrl pointer to
                point to the users _matherrl error handling routine.  This is
                usefull for moving the matherrl handling from the EXE into a
                DLL.

NOTES:          If NULL is passed in, then the RTL's default internal handler
                is used.

Return value    The previous address of the handler.

*-------------------------------------------------------------------------*/

matherrptrl _RTLENTRY _EXPFUNC _set_matherrl_handler(matherrptrl matherrl)
{
    matherrptrl tmp = _pmatherrl;

    if (!matherrl)
      matherrl = _matherrl;

    _pmatherrl = matherrl;

    return tmp;
}
