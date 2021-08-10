/*
*
*    CONVT.C
*
*    Converts Win32 date/Time format to posix
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1996, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $        */

#include <_locale.h>
#include <mem.h>
#include <string.h>

char* _win32DateTimeToPOSIX(char* DateTime, char* replace, int size)
{
    char* q = replace;
    char* p = DateTime;
    char* ptr;
    int   letter = 0;

    memset(replace, 0, size);

    while (*p)
    {
        switch (*p)
        {
        case 'g' :
            if (*(p + 1) == 'g')
            {
                strcat(q, "%g");
                p++;
            }
            break;
        case 'h' :
            if (*(p + 1) == 'h')
            {
                strcat(q, "%+0I");
                p++;
            }
            else
                strcat(q, "%I");
            break;
        case 'm' :
            if (*(p + 1) == 'm')
            {
                strcat(q, "%+0M");
                p++;
            }
            else
                strcat(q, "%M");
            break;
        case 's' :
            if (*(p + 1) == 's')
            {
                strcat(q, "%+0S");
                p++;
            }
            else
                strcat(q, "%S");
            break;
        case 'H' :
            if (*(p + 1) == 'H')
            {
                strcat(q, "%+0H");
                p++;
            }
            else
                strcat(q, "%H");
            break;
        case 't' :
            if (*(p + 1) == 't')
                p++;
            else
                strcat(q, "%p");
            break;
        case 'd' :
            ptr = p;
            while (*ptr++ == 'd')
                letter++;
            switch (letter)
            {
            case 1 : strcat(q, "%d"); break;
            case 2 : p++; strcat(q, "%+0d"); break;
            case 3 : p+=2; strcat(q, "%a"); break;
            case 4 : p+=3; strcat(q, "%A"); break;
            }
            break;
        case 'M' :
            ptr = p;
            while (*ptr++ == 'M')
                letter++;
            switch (letter)
            {
            case 1 : strcat(q, "%m"); break;
            case 2 : p++; strcat(q, "%+0m"); break;
            case 3 : p+=2; strcat(q, "%b"); break;
            case 4 : p+=3; strcat(q, "%B"); break;
            }
            break;
        case 'y' :
            ptr = p;
            while (*ptr++ == 'y')
                letter++;
            switch (letter)
            {
            case 1 : strcat(q, "%y"); break;
            case 2 : p++; strcat(q, "%+0y"); break;
            case 4 : p+=3; strcat(q, "%Y"); break;
            }
            break;

        case 0x27: break;
        default: strncat(q, p, 1);
        }
        letter = 0;
        p++;
    }
    return replace;
}
