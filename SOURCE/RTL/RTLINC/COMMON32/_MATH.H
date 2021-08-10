/*------------------------------------------------------------------------
 * filename - _math.h
 *
 *  Access to the Floating Point Support Library.
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 6.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

/* Functions from f87*.asm.  Should never be called from C code.
 */
void _RTLENTRY _f87_Sine(void);
void _RTLENTRY _f87_Cosine(void);
void _RTLENTRY _f87_Tangent(void);
void _RTLENTRY _f87_ArcTan(void);

void _RTLENTRY _f87_Log(void);
void _RTLENTRY _f87_Log2(void);
void _RTLENTRY _f87_Log10(void);

void _RTLENTRY _f87_Exp(void);
void _RTLENTRY _f87_Exp2(void);
void _RTLENTRY _f87_Exp10(void);

/* helper functions and variables for math library */

void           _RTLENTRY _fbstp  (long double *__valP);
unsigned short _RTLENTRY _fxam   (long double *__valP);
long double    _RTLENTRY _fildq  (long *__quadint);
void           _RTLENTRY _fistq  (long *__quadint, long double *__valP);
long double    _RTLENTRY _fuildq (long *__quadint);
void           _RTLENTRY _fuistq (long *__quadint, long double *__valP);
long double    _RTLENTRY _pow10  (int __exp);
int            _RTLENTRY _qdiv10 (long *__quadint);
int            _RTLENTRY _qmul10 (long *__quadint, int __digit);


void           _RTLENTRY _expld  (void);
void           _RTLENTRY _round  (void);

extern char *_mathwhy[];

typedef int  (*matherrptr)  (struct exception  *);
typedef int  (*matherrptrl) (struct _exceptionl *);
extern matherrptr  _pmatherr;
extern matherrptrl _pmatherrl;

#ifdef __cplusplus
}
#endif
