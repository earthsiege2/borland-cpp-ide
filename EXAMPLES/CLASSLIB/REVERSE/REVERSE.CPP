/*------------------------------------------------------------------------*/
/*                                                                        */
/*  REVERSE.CPP                                                           */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved.                                                  */
/*                                                                        */
/*  TStack example file                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STACKS_H )
#include "classlib\stacks.h"
#endif  // __STACKS_H

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif  // __CSTRING_H

#ifndef __IOSTREAM_H
#include <iostream.h>       
#endif

int main()
{
    TStack<string> TheStack;
    string Reverse("reverse");

    cout << "\nEnter some strings.  Reverse will collect the strings\n";
    cout << "for you until you enter the string \"reverse\".  Reverse\n";
    cout << "will then print out the strings you have entered, but in\n";
    cout << "reverse order.  Begin entering strings now.\n";

    for(;;)
        {
        char InputString[255];
        cin >> InputString;
        string NewString( InputString );
        if( NewString != Reverse )
            {
            TheStack.Push( NewString );
            }
        else 
            {
            break;
            }
        }

    cout << "\nThe strings you entered (if any) are:\n";
    while( !(TheStack.IsEmpty()) )
        {
        cout << TheStack.Pop() << endl;
        }
    return 0;
}
