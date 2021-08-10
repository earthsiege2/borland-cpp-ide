/*-----------------------------------------------------------------------*
 * MBYTE1.C
 *
 * single byte "multi-byte" locale only conversion functions
 *
 * function(s)
 *        mblen     - determines number of bytes in multibyte character
 *        mbtowc    - converts multibyte character to wide character
 *        wctomb    - converts wide character to multibyte character
 *        mbstowcs  - converts a multibyte string to a wide character string
 *        wcstombs  - converts a wide character string to a multibyte string
 *
 *-----------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */


#include <stdlib.h>
#include <mbctype.h>
#include <windows.h>
#include <_locale.h>

#if ( sizeof( wchar_t ) == 1 )
#error *** size of wchar_t is incorrect ***
#endif

// current maximum MBCS character length
#define MB_MAX_CHARLEN	2


/* Length of the MBCS Character in bytes		*/  

int _RTLENTRY _EXPFUNC mblen( const char *s, size_t n )
{

	if ( (s == NULL) || (*s == 0 ) || (n == 0) )
		return( 0 );

	if ( _ismbblead ((unsigned char)*s) ) 
	{
		// multibyte character
		if ( (int)n < MB_MAX_CHARLEN  ||
		MultiByteToWideChar( __locale->codepage, MB_PRECOMPOSED|MB_ERR_INVALID_CHARS, 
		s, MB_MAX_CHARLEN, NULL, 0 ) == 0 ) 
			return -1;
		else
			return 	MB_MAX_CHARLEN;
	}
	else
	{
		// single byte character
		if ( MultiByteToWideChar( __locale->codepage, MB_PRECOMPOSED|MB_ERR_INVALID_CHARS, 
			s, 1, NULL, 0 ) == 0 )
	
			return -1;
		else
			return sizeof ( char);
	}

}


/* Converts an MBCS char to Wide char		*/

int _RTLENTRY _EXPFUNC mbtowc( wchar_t *pwc, const char *s, size_t n )

{

	/* return "no state-dependent encodings" */
	if ( (s == NULL)  || (n == 0) )
		return( 0 );


	if ( *s == 0 )
	{
		/* Null character */
		if ( pwc )
			*pwc = 0;
		return( 0 );
	}


	if ( __locale->isCLocale )
	{
		if ( pwc != NULL )
			/* zero extend */
			*pwc = (wchar_t) (unsigned char) *s;
		return( sizeof( char ) );
	}

	if ( _ismbblead( (unsigned char)*s ) )
	{
		if ( (int)n < MB_MAX_CHARLEN || 
			MultiByteToWideChar( __locale->codepage, MB_PRECOMPOSED|MB_ERR_INVALID_CHARS, 
			s, MB_MAX_CHARLEN, pwc, (pwc) ? 1: 0) == 0 )
		{
			if ( (int)n < MB_MAX_CHARLEN || (*(s+1) == 0 ))
				return -1;
		}
		return MB_MAX_CHARLEN;
	}
	else
	{
		/* Single byte charactr */
		if ( MultiByteToWideChar( __locale->codepage, MB_PRECOMPOSED|MB_ERR_INVALID_CHARS, 
			s, 1, pwc, (pwc) ? 1: 0) == 0 )
				return -1;

		return sizeof ( char );
	}

}


/* Converts a wide char to MBCS char		*/

int _RTLENTRY _EXPFUNC wctomb( char *s, wchar_t wc )

{

	/* return "no state-dependent encodings" */
	if ( s == NULL )
		return( 0 );

	if ( __locale->isCLocale )
	{
		if ( wc > 255 )
			return -1;
		*s = (char)wc;
		return sizeof ( char );
	}
	else
	{
		int size;
		BOOL UsedDefault = 0;
	
		size = WideCharToMultiByte ( __locale->codepage, WC_COMPOSITECHECK|WC_SEPCHARS,
				&wc, 1, s, MB_MAX_CHARLEN, NULL, &UsedDefault); 
		if ( (size == 0) || (UsedDefault) )
			return -1;
		return size;
	}

}


/* Converts multibyte string to Wide char String		*/

size_t _RTLENTRY _EXPFUNC mbstowcs( wchar_t _FAR *pwcs, const char _FAR *s, size_t n )
{


	size_t count = 0;

	if ( pwcs  && n == 0 )
		return (size_t)0;

	if ( pwcs )
	{
		if ( __locale->isCLocale )
		{
			/* C Locale  */
			while ( count < n )
			{
				*pwcs = (wchar_t)((unsigned char)s[count]);
				if ( s[count] == 0 )
					return count;
				count++;
				pwcs++;
			}
			return count;
		}					
		else
		{
			
			int ByteCount, CharCount;
			unsigned char *p;

			if ((count=MultiByteToWideChar(__locale->codepage, 
			MB_PRECOMPOSED|MB_ERR_INVALID_CHARS, s, -1, pwcs, n)) != 0)
				return (count - 1); 

			if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
				return (size_t)-1;
			

			/* User-supplied buffer is not large enough. */

			/* Find no. of bytes in n characters of the string */
			CharCount = n;
			for (p = (unsigned char *)s; (CharCount-- && *p); p++)
			{
				if (_ismbblead(*p))
					p++;
			}
			ByteCount = ((int) ((char *)p - (char *)s));

			if ((count = MultiByteToWideChar (__locale->codepage, MB_PRECOMPOSED,
				s, ByteCount, pwcs, n)) == 0)
				return (size_t)-1;

			return count; 
		}
	}
	else
	{

		if (__locale->isCLocale )
			return strlen(s);

		else 
		{
			if ((count = MultiByteToWideChar(__locale->codepage,
			 MB_PRECOMPOSED|MB_ERR_INVALID_CHARS, s, -1, NULL, 0)) == 0)
				return (size_t)-1;

			return (count - 1);
		}
	}
	
}


/* Count the no. of characters in the Wide Char String	*/
static int __cdecl wcsncnt (const wchar_t *pwcs, int count )
{
        int n = count+1;
        wchar_t *p = (wchar_t *)pwcs;

        while (--n && *p)
            p++;

        if (n && !*p)
            return (p - pwcs) + 1;
        return count;
}


/* Converts wide char string to multibyte string		*/

size_t _RTLENTRY _EXPFUNC wcstombs(char _FAR *s, const wchar_t _FAR *pwcs, size_t n)
{

    size_t count = 0;
    int i, retval;
    char buffer[MB_MAX_CHARLEN];
    BOOL UsedDefault = 0;


    if (s && !n )
        return (size_t) 0;
	
	if (s)
    {
        if (__locale->isCLocale)
        {
            /* C locale */
            while(count < n)
            {
                if (*pwcs > 255)  
                    return (size_t)-1;  /* error */

                s[count] = (char) *pwcs;
                if (*pwcs++ == L'\0')
                    return count;
                count++;
            }
            return count;
        } 
		else 
		{
			/* Add code here if the maximum no.of chars for MBCS */
			/* can be anything other than 2						 */
			

            /* Assume that user supplied buffer is large enough */
            count=WideCharToMultiByte(__locale->codepage,WC_COMPOSITECHECK | WC_SEPCHARS,
			pwcs, -1, s, n, NULL, &UsedDefault);

			if ( count != 0 && !UsedDefault )
            {
                return count - 1; 
            }

            if (UsedDefault || GetLastError() != ERROR_INSUFFICIENT_BUFFER)
                return (size_t)-1;

            /* buffer not large enough */
            while (count < n)
            {
                retval = WideCharToMultiByte (__locale->codepage, 0,
                pwcs, 1, buffer, MB_MAX_CHARLEN, NULL, &UsedDefault);

                if ( retval == 0 || UsedDefault )
                    return (size_t)-1;

                if (count + retval > n)
                    return count;

                for (i = 0; i < retval; i++, count++) 
                    if((s[count] = buffer[i])=='\0')
                        return count;

                pwcs++;
            }

            return count;
        }
    
	}
    else 
	{ 
		/* s == NULL, get only size*/

		if (__locale->isCLocale)
			return wcslen(pwcs);
		else 
		{
			count=WideCharToMultiByte(__locale->codepage,
				WC_COMPOSITECHECK | WC_SEPCHARS,
				pwcs, -1, NULL, 0, NULL, &UsedDefault);

			if ( count == 0 || UsedDefault )
				return (size_t)-1;

			return (count - 1);
		}
	}
}

