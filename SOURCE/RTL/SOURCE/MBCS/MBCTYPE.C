/*-----------------------------------------------------------------------*
 * filename - mbctype.c
 *
 * variables(s)
 *        _mbctype -  //todo
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */

#include <mbctype.h>
#include <windows.h>
#include <_io.h>
/*---------------------------------------------------------------------*

Name            _mbctype

Usage           unsigned char _mbctype[257];

Prototype in    mbctype.h

Description     _mbctype  stores the character type information
*---------------------------------------------------------------------*/

#define NUM_OF_CHARS	257    /* -1 to 255  */
unsigned char _mbctype[NUM_OF_CHARS];

int _mbcsCodePage; // to store the current code page

/* Hard coded Japanese specific ranges  */
unsigned char _kalpha[] = { 0xA6, 0xDF };   /* single byte ranges */
unsigned char _kpunct[] = { 0xA1, 0xA5 };	/* punctuation ranges */

/*---------------------------------------------------------------------*

Name            _setmbcp

Usage           _setmbcp ( int codepage )

Prototype in    mbctype.h

Description     _setmbcp() initializes the MBCS table with values for
                the new code page. It prints an error message if it cannot
                retrive the code page information from the operating system
*---------------------------------------------------------------------*/
int _RTLENTRY _EXPFUNC _setmbcp ( int newCodePage )
{
    int i;
    BYTE *leadBytes;
    CPINFO cpinfo;

    if ( !GetCPInfo (newCodePage, &cpinfo ) )
    {
	_ErrorMessage ("Error: system code page access failure; MBCS table not initialized");
	return -1;
    }

    for ( i = 0; i < NUM_OF_CHARS; i++ )
    	_mbctype[i] = 0;

	if ( cpinfo.MaxCharSize > 1 )
    {
        /* set leadbytes */
    	for ( leadBytes = cpinfo.LeadByte; (*leadBytes && *(leadBytes+1 )); leadBytes += 2)
        {
        	for ( i = *leadBytes; i <= *(leadBytes+1); i++ )
            	_mbctype[i+1] = __MBB1;
		}

		/* set trail bytes */
        for ( i = 1; i < 255; i++ )
        	_mbctype[i+1] |= __MBB2;

		/* Japanese specific ranges  */

		if ( newCodePage == _KANJI_CP )
		{
			for ( i = _kalpha[0]; i <= _kalpha[1]; i++ )
        		_mbctype[i+1] |= __MBBS;

			for ( i = _kpunct[0]; i <= _kpunct[1]; i++ )
        		_mbctype[i+1] |= __MBBP;

		}

		_mbcsCodePage = newCodePage;
    }
    else
	_mbcsCodePage = 0;

    return 0;
}

void _initMBCSTable(void)
{
	#pragma startup _initMBCSTable 1

	_setmbcp( GetACP() );
}

