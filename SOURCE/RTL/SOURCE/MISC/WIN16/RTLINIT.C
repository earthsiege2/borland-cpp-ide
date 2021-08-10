/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1994, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

/*
  This is a function that allows the startup code to catch some
  incorrect linking errors before it's fatal (see C0W.ASM)
*/

int OkToInitWindowsRTL (void)
{
#ifdef __DPMI16__
  return 0;
#else
  return 1;
#endif
}
