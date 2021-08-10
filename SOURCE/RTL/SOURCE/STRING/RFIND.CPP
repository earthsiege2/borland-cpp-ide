/*------------------------------------------------------------------------*/
/*                                                                        */
/*  RFIND.CPP                                                             */
/*                                                                        */
/*  size_t string::rfind( const string& s, size_t startindex ) const;     */
/*  size_t string::rfind_index( const char *pattern,                      */
/*                              size_t startindex,                        */
/*                              size_t& patl ) const;                     */
/*  size_t string::rfind_case_index( const char *pattern,                 */
/*                                   size_t startindex,                   */
/*                                   size_t& patl ) const;                */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 8.0
 *
 *      Copyright (c) 1992, 1997 by Borland International
 *      All Rights Reserved.
 *
 */
/* $Revision:   8.2  $        */

#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
static void __debug(void){}
#pragma codeseg _TEXTC
#endif
#endif



#include <string.h>
#include <cstring.h>

size_t string::rfind( const string _FAR &s, size_t startindex ) const throw()
{
    unsigned patl;
    return rfind_index( s.c_str(), startindex, patl ); // Throws away "patl"
}

size_t string::rfind_index( const char _FAR * pattern,
                            size_t startindex,
                            size_t _FAR & patl ) const
{
    if( get_case_sensitive_flag() )
        return rfind_case_index( pattern, startindex, patl );
    else
        return ::to_upper(*this).rfind_case_index(::to_upper(string(pattern)).c_str(), startindex, patl);
}

size_t string::rfind_case_index( const char _FAR *cp,
                                 size_t startindex,
                                 size_t _FAR &patl ) const
{

    const long q = 33554393L;
    const long q32 = q<<5;

    size_t testlength = startindex;
    size_t patternlength = patl = strlen(cp);
    if( testlength < patternlength )
        return NPOS;
    if( patternlength == 0 )
        return 0;

    long patternHash = 0;
    long testHash = 0;

    const char _FAR *testP = c_str()+startindex-1;
    const char _FAR *patP = cp+patternlength-1;
    long x = 1;
    size_t i = patternlength-1;

    while( i-- )
        x = (x<<5)%q;

    for( i=0; i<patternlength; i++ )
        {
        patternHash = ( (patternHash<<5) + *patP--  ) % q;
        testHash    = ( (testHash   <<5) + *testP-- ) % q;
        }

    testP = c_str()+startindex-1;
    const char _FAR *end = c_str() + patternlength - 1;

    while (1)
        {

        if(testHash == patternHash)
            if( !get_paranoid_check_flag() ||
                !strncmp( testP, cp, patternlength) )
              return (size_t)(testP-c_str()-patternlength+1);

        if( testP == end )
            break;

        // Advance & calculate the new hash value:
        testHash = ( testHash + q32 - *testP * x                  ) % q;
        testHash = ( (testHash<<5)  + *(-patternlength + testP--) ) % q;
        }
    return NPOS;          // Not found.
}

