#define USE_XX_VARS
#include <xx.h>

/* This file is used in all static versions of the RTL since XPF_DEFAULT
   will expand to the right value based on whether or not MAGIC is defined.

   For the Unified RTLDLL (CC32xxMT.DLL) we must build both a W and a P
   flavor of the RTL import library so we build this file for the P version
   (since MAGIC is on now) and build xx_w.cpp for the W version.

*/

unsigned long __xxPersonality = XPF_DEFAULT;
