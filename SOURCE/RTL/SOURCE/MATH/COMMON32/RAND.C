/*-----------------------------------------------------------------------*
 * filename - rand.c
 *
 * function(s)
 *        srand - initializes random number generator
 *        rand  - random number generator
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 1.5
 *
 *      Copyright (c) 1987, 1994 by Borland International
 *      All Rights Reserved.
 *
 */

#pragma inline

#ifdef _MT
#include <_thread.h>
#endif
#include <stdlib.h>

#define MULTIPLIER      0x015a4e35L
#define INCREMENT       1

#if !defined(_SEED_T)
#define _SEED_T
typedef struct
{
	unsigned lo;
	unsigned hi;
} __seed_t;
#endif

#ifdef _MT
#define Seed _thread_data()->thread_seed
#else
static  __seed_t  Seed = { 1, 0 };
#endif

/*---------------------------------------------------------------------*

Name            srand - initializes random number generator

Usage           void srand(unsigned seed);

Prototype in    stdlib.h

Description     see rand below

Return value    Nothing

*---------------------------------------------------------------------*/

void _RTLENTRY _EXPFUNC srand(unsigned seed)
{
        Seed.lo = seed;
        Seed.hi = 0;
}

/*---------------------------------------------------------------------*

Name            rand - random number generator

Usage           int rand(void);

Related
functions usage void srand(unsigned seed);

Prototype in    stdlib.h

Description     rand uses a multiplicative congruential random number
                generator with period 2^32 to return successive pseudo-
                random numbers in the range from 0 to 2^15 - 1.

                The generator is reinitialized by calling srand with an
                argument value of 1. It can be set to a new starting point by
                calling srand with a given seed number.

*---------------------------------------------------------------------*/

int _RTLENTRY _EXPFUNC rand(void)
{
        Seed.lo = MULTIPLIER * Seed.lo + INCREMENT;
        return((int)(Seed.lo >> 16) & 0x7fff);
}

/*---------------------------------------------------------------------*

Name            _lrand - long random number generator

Usage           long _lrand(void);

Related
functions usage void srand(unsigned seed);
                int rand(void);

Prototype in    stdlib.h

Description     _rand uses a multiplicative congruential random number
                generator with period 2^64 to return successive pseudo-
                random numbers in the range from 0 to 2^31 - 1.

                The generator is reinitialized by calling srand with an
                argument value of 1. It can be set to a new starting point by
                calling srand with a given seed number.

*---------------------------------------------------------------------*/

long _RTLENTRY _EXPFUNC _lrand(void)
{
//      Seed = MULTIPLIER * Seed + INCREMENT;
//      return((int)(Seed & 0x7fffffffL));
	
	_EBX = Seed.hi;			/* use EBX so MT Seed call preserves */
	_ESI = Seed.lo;

	asm	mov	eax, ebx
	asm	mov	ecx, 015A4h
	asm	mov	ebx, 04E35h


	asm	test	eax, eax
	asm	jz	nohi1
	asm	mul	ebx		

nohi1:
	asm	xchg	ecx, eax		
	asm	mul	esi
	asm	add	eax, ecx
			
nohi2:
	asm	xchg	eax, esi
	asm	mul	ebx
	asm	add	edx, esi
			
	asm	add	eax, 1
	asm	adc	edx, 0
	asm	mov	ebx, eax	/* use EBX so MT Seed call preserves */
	asm	mov	esi, edx	/* use ESI so MT Seed call preserves */
			
	Seed.lo = _EBX;
	Seed.hi = _ESI;
	return _ESI & 0x7fffffff;
}
