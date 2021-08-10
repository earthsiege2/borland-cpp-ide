#pragma option push -b -a8 -pc -A- /*P_O_Push_S*/
/*****************************************************************************\
*                                                                             *
*  PLAN32.H   - Portability mapping header file                               *
*                                                                             *
*               Version 4.0                                                   *
*                                                                             *
*               Copyright (c) 1993-1995, Microsoft Corp.  All rights reserved.*
*                                                                             *
\*****************************************************************************/

/*----------------------------------LANMAN----------------------------------*/

/* LANMAN MACROS: */

#define COPYTOARRAY(pDest, pSource)     pDest = pSource

/* LANMAN API: */
#pragma option pop /*P_O_Pop*/
