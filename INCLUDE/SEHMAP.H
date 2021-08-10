/*

  SEHMAP.H - Map old-style structured exception handling to correct names.

  The mapping of structured exception handling statements from {try, except,
  finally, leave} to their proper names (prefaced by "__") has been removed
  from win32.mak.  This header is provided solely for compatibility with
  source code that used the older convention.

*/


#ifndef __cplusplus
#pragma option push -b -a8 -pc -A- /*P_O_Push*/
#undef try
#undef except
#undef finally
#undef leave
#define try     __try
#define except  __except
#define finally __finally
#define leave   __leave
#define abnormal_termination()    __abnormal_termination
#define exception_code()          __exception_code
#define exception_info()          ((PEXCEPTION_POINTERS)__exception_info)

#pragma option pop /*P_O_Pop*/
#endif
