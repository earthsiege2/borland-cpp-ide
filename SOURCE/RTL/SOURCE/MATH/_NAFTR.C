/*------------------------------------------------------------------------
 * filename - _naftr.c
 *
 * function(s)
 *
 *   _nextafter - takes two doubles (a and b) and returns the closest
 *                representable neighbor of a in the direction toward b.
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
#include <_float.h>


double _RTLENTRY _nextafter(double __da, double __db)
{
   int ha = ((_rtl_double_t*)&__da)->i64.s.high32.value;
   int hb = ((_rtl_double_t*)&__db)->i64.s.high32.value;
   unsigned int la = ((_rtl_double_t*)&__da)->i64.s.low32.value;
   unsigned int lb = ((_rtl_double_t*)&__db)->i64.s.low32.value;
   int ia = ha & 0x7fffffff;    /* ia=|__da| */
   int ib = hb & 0x7fffffff;    /* ib=|__db| */


   if ((_isnan(__da) ==_FPCLASS_QNAN) || (_isnan(__db) == _FPCLASS_QNAN))
       return __da + __db;

   if (__da==__db)
       return __da;

   if ((ia|la) == 0)                    /* __da == 0 */
   {
       la = 1;                          /* return +-2Emin */
       ha = hb & 0x80000000;            /* give __da same sign as __db */
       __db = __da * __da;              /* force underflow flag */

       if (__db == __da)                /* return according to trap handler's return */
           return __db;
       else
           return __da;
   }

   if (ha >= 0)
   {
       if (ha>hb || ha==hb && la>lb)    /* __da > __db, __da -= ulp */
       {
           if (la == 0)
               ha -= 1;
           la -= 1;
       }
       else                             /* __da < __db, __da += ulp */
       {
           la += 1;
           if (la == 0)
               ha += 1;
       }
   }
   else                                 /* __da < 0 */
   {
        /*
           We know __da is negative by this point, so if __db is between __da
           and positive infinity, then we want to move __da closer toward
           zero. That means we need to subtract from __da's absolute value.

           ia>ib tells us if __da<__db since we know that by the time we reach
           the ia>ib conditional, both __da and __db are negative. So we
           are only comparing absolute values.

           Even if the exponent of __db is negative, and the exponent of __da
           is positive, (and both __da and __db are negative) the ia>ib
           conditional will be true. This is because in IEEE
           floating point formats for long doubles, the 'bias exponent'
           denotes a negative exponent using values from 0h-3fffh and a
           positive exponent using values 4000h-7fffh.

        */
       if (hb>=0 || ia > ib || ha==hb && la>lb)         /* __da<__db, __da -= ulp */
       {
           if(la == 0)
               ha -= 1;
           la -= 1;
       }
       else {                                           /* __da > __db, __da += ulp */
           la += 1;
           if(la == 0)
               ha += 1;
       }
   }

   /* In the two conditionals below, we check for overflow and underflow */

   hb = ha & 0x7ff00000;

   if (hb >= 0x7ff00000)        /* overflow  */
       return __da + __da;


   if (hb < 0x00100000) {               /* underflow */
       __db = __da * __da;
       if ( __db != __da) {             /* raise underflow flag */
           hb = ha;
           lb = la;
           return __db;
       }
   }

   ((_rtl_double_t*)&__da)->i64.s.high32.value = ha;
   ((_rtl_double_t*)&__da)->i64.s.low32.value = la;
   return __da;
}
