/*------------------------------------------------------------------------
 * filename - _process.h
 *
 *      definitions of internal routines for exec* and spawn*
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1987, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision$ */

#ifdef __cplusplus
extern "C" {
#endif
extern  void    cdecl (*_exitbuf)(void);
extern  void    cdecl (*_exitfopen)(void);
extern  void    cdecl (*_exitopen)(void);

void     cdecl       _abort    (void);
char    *pascal near __DOScmd   (char *__prog, char *__sep, char **__argV);
char    *pascal near __DOSenv   (char **__envV, char *__pathP, void **__envSave);

int      cdecl near _exec       (char *__path, char *__cmd, char *__env);
int                 _getswitchar(void);
int      cdecl near _spawn      (char *__path, char *__cmd, char *__env);
int      cdecl near _LoadProg   (int cdecl near (* __Func)(), char *__path,
                                 char *__argp[], char *__envV[], int __usepath);
#ifdef __cplusplus
}
#endif
