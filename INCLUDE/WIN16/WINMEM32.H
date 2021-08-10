/*****************************************************************************\
*                                                                             *
* winmem32.h -  Function prototypes and general defines                       *
*                                                                             *
\*****************************************************************************/

/* $Copyright: 1992$ */

#ifndef __WINMEM32_H    /* prevent multiple includes */
#define __WINMEM32_H

#ifndef __WINDOWS_H
#include <windows.h>    /* <windows.h> must be included */
#endif  /* __WINDOWS_H */

/*
 *
 * The functions
 *
 */
WORD    FAR PASCAL GetWinMem32Version(void);
WORD    FAR PASCAL Global32Alloc(DWORD, LPWORD, DWORD, WORD);
WORD    FAR PASCAL Global32Realloc(WORD, DWORD, WORD);
WORD    FAR PASCAL Global32Free(WORD, WORD);
WORD    FAR PASCAL Global16PointerAlloc(WORD, DWORD, LPDWORD, DWORD, WORD);
WORD    FAR PASCAL Global16PointerFree(WORD, DWORD, WORD);
WORD    FAR PASCAL Global32CodeAlias(WORD, LPWORD, WORD);
WORD    FAR PASCAL Global32CodeAliasFree(WORD, WORD, WORD);

/*
 *
 * Error Codes
 *
 */
#define WM32_Invalid_Func       0001
#define WM32_Invalid_Flags      0002
#define WM32_Invalid_Arg        0003
#define WM32_Insufficient_Sels  0004
#define WM32_Insufficient_Mem   0005

#endif  /* __WINMEM32_H */
