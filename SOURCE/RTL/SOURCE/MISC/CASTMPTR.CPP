/*-----------------------------------------------------------------------*
 * filename - castmptr.cpp
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1990, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_defs.h>

typedef unsigned    addr_t;

typedef struct
{
    addr_t      thisAdj;
    addr_t      VBPoffs;
} mptr;

/******************************************************************************
 *
 *  This routine is used for casts of member pointers that may
 *  point to members of virtual base classes. The parameters
 *  are as follows:
 *  
 *      mp  -   address of the "thisAdj" member
 *              of the member pointer being cast
 *  
 *      tp  -   address of the compiler-generated
 *              conversion table
 *  
 *       mptrSize   -   size of the member pointer type
 *  
 *       ThisAdj    -   change in "thisAdj" due to the cast
 *  
 *       VBPoffs    -   new value for "VBPoffs" or 0
 *  
 *  The result of calling this routine is that either the member
 *  pointer value is converted to the new type, or it is set to
 *  0 if the cast cannot be carried out (see the -Vv compiler
 *  switch for details).
 */

void _RTLENTRY _EXPFUNC _cast_memptr(void * mp,
                          void * tp,
                          addr_t mptrSize,
                          addr_t thisAdj,
                          addr_t VBPoffs)
{
    mptr * mpp = (mptr *)mp;

    if  (VBPoffs)
    {
        /* Does the current value point to a vbase member? */

        if  (mpp->VBPoffs)
        {
            addr_t *   tbl = (addr_t *)tp;
            char   *   pp;

            /* Look for a matching virtual base in the table */

            for (;;)
            {
                addr_t      srcOffs;

                srcOffs = *tbl++;
                if  (srcOffs == 0)
                    break;

                if  (srcOffs == mpp->VBPoffs)
                {
                    /* Found a match, update value */

                    mpp->VBPoffs  = *tbl;
                    return;
                }

                /* Skip the 'new' offset value and continue */

                tbl++;
            }

            /* Here we have an illegal cast: set mptr to NULL */

            pp = (char *)mp + 2 * sizeof(addr_t) - mptrSize;

            /* Note: the following might better be done through memset.
             */

            do
            {
                *pp++ = 0;
            }
            while   (--mptrSize);
        }
        else
        {
            mpp->thisAdj += thisAdj;
            mpp->VBPoffs  = VBPoffs;
        }
    }
    else
    {
        /* This part might be generated inline by the compiler */

        if  (mpp->VBPoffs)
            mpp->VBPoffs += thisAdj;
        else
            mpp->thisAdj += thisAdj;
    }
}   
