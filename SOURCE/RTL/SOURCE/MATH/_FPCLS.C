/*------------------------------------------------------------------------
 * filename - _fpcls.c
 *
 * function(s)
 *
 *   _fpclass  - Returns the type (class) of an IEEE real for doubles
 *   _fpclassl - Returns the type (class) of an IEEE real for long doubles
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1998, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.4.2.1 $        */

#pragma inline
#include <float.h>


static int CallFXAM (void)
{
    int ret;

    asm fxam
    ret = (_status87() & 0x4700);  /* Mask off all bits but C0-C3 */
    asm ffree ST(0)                /* free the loaded fp reg.     */
    asm fincstp                    /* then bump the fp stack ptr  */

    ret = ret >> 8;
    ret = (ret & 0x0007) | ((ret & 0x0040) >> 3);
    return ret;
}


static int MapClass (void)
{
    int stat = CallFXAM();

    switch (stat)
    {
    /* CFlgs: C3 C2 C1 C0   (C1 = sign [0:positive, 1:negative]) */

        case 0x00:
        case 0x02:
            return _FPCLASS_UNSUP;

        case 0x01:
        case 0x03:
            /* +- NAN */
            return _FPCLASS_SNAN;  /* mark it as an SNAN for now, check for
                                      QNAN later */

        case 0x04:
            return _FPCLASS_PN;
        case 0x06:
            return _FPCLASS_NN;

        case 0x05:
            return _FPCLASS_PINF;
        case 0x07:
            return _FPCLASS_NINF;

        case 0x08:
            return _FPCLASS_PZ;
        case 0x0A:
            return _FPCLASS_NZ;

        case 0x0C:
            return _FPCLASS_PD;
        case 0x0E:
            return _FPCLASS_ND;

    }
    return 0; /* Unknown type */
}

int _RTLENTRY _EXPFUNC _fpclass(double __d)
{
    int ret;
    unsigned ctrl = _control87 (MCW_EM, MCW_EM);  /* Disable FP exceptions */

    asm fld [__d]
    ret = MapClass ();
    if (ret == _FPCLASS_SNAN)
        ret = _isnan(__d);
    _control87(MCW_EM, ctrl);
    return ret;
}

int _RTLENTRY _EXPFUNC _fpclassl(long double __ld)
{
    int ret;
    unsigned ctrl = _control87 (MCW_EM, MCW_EM);  /* Disable FP exceptions */

    asm fld [__ld]
    ret = MapClass ();
    if (ret == _FPCLASS_SNAN)
        ret = _isnanl(__ld);
    _control87(MCW_EM, ctrl);
    return ret;
}
