/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STRNGMAX.H                                                            */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  String example file                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif  // __CSTRING_H

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

//
// Determines the maximum string using the ASCII collating sequence to 
// define rank.  A string is defined to be greater than another if the
// ASCII values of its characters are greater than the values of the other
// string.  For example,
//
// strngmax Alpha Beta Charlie
//
// would print Charlie to stdout and return 3.
//

int main( int argc, char *argv[] )
{
    if( argc < 2 )
        {
        cerr << "Usage:  strngmax string1 [string2 ...]\n";
        return 1;
        }

    string TheGreatestString( argv[1] );
    int PositionOfTheGreatestString = 1;
    int NextArg = 2;

    while( NextArg < argc )
        {
        string ArgListString ( argv[NextArg++] );
        if ( ArgListString > TheGreatestString )
            {
            TheGreatestString = ArgListString;
            PositionOfTheGreatestString = NextArg - 1;
            }
        }

    cout << TheGreatestString << endl;
    return PositionOfTheGreatestString;
}
