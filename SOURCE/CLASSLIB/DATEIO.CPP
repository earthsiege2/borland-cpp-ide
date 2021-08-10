/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DATEIO.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STDIO_H )
#include <stdio.h>
#endif

#if !defined( __CTYPE_H )
#include <ctype.h>
#endif

#if !defined( __STRSTREA_H )
#include <strstrea.h>
#endif

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif

#if !defined( CLASSLIB_DATE_H )
#include <classlib/date.h>
#endif

TDate::HowToPrint TDate::PrintOption = TDate::Normal;

string TDate::AsString() const
{
    char buf[80];
    ostrstream strtemp(buf, sizeof(buf));
    strtemp << (*this) << ends;
    string temp(buf);
    return temp;
}

TDate::HowToPrint TDate::SetPrintOption( HowToPrint h )
{
    HowToPrint oldoption = PrintOption;
    PrintOption = h;
    return oldoption;
}

// Skip any characters except alphanumeric characters
static void _BIDSNEARFUNC SkipDelim( istream _BIDSFAR & strm )
{
    char c;
    if( !strm.good() )
        return;

    do  {
        strm >> c;
        } while (strm.good() && !isalnum(c)) ;

    if (strm.good())
        strm.putback(c);
}

// Parse the name of a month from input stream.
static const char* _BIDSNEARFUNC ParseMonth( istream _BIDSFAR & s )
{
    static char month[12];
    register char* p = month;
    char c;
    SkipDelim(s);
    s.get(c);
    while (s.good() && isalpha(c) && (p != &month[10]))
        {
        *p++ = c;
        s.get(c);
        }
    if( s.good() )
        s.putback(c);
    *p = '\0';
    return month;
}

//  Parse a date from the specified input stream.  
//    The date must be in one of the following forms: 
//                dd-mmm-yy, mm/dd/yy, or mmm dd,yy
//        e.g.: 10-MAR-86,  3/10/86, or March 10, 1986.  
//  Any non-alphanumeric character may be used as a delimiter.


void TDate::ParseFrom( istream _BIDSFAR & s )
{
    unsigned d,m,y;
    Julnum = 0;                 // Assume failure

    if (s.good())
        {
        SkipDelim(s);
        s >> m;                 // try to parse day or month number 
        SkipDelim(s);
        if (s.eof())
            return;
        if( s.fail() )          // parse <monthName><day><year> 
            {
            s.clear();
            m = IndexOfMonth(ParseMonth(s)); // parse month name
            SkipDelim(s);
            s >> d;                 // parse day 
            }
        else                        // try to parse day number 
            {
            s >> d;
            if (s.eof()) return;
            if (s.fail())           // parse <day><monthName><year> 
                {
                d = m;
                s.clear();
                m = IndexOfMonth(ParseMonth(s)); // parse month name
                }
            }
        SkipDelim(s);
        s >> y;
        }
    Julnum = s.good() ? Jday(m, d, y) : 0;
    if(Julnum==0)
        s.clear(ios::badbit);
}

ostream _BIDSFAR & _BIDSFUNC operator << ( ostream _BIDSFAR & s, const TDate _BIDSFAR & d )
{
    char buf[80];

    // we use an ostrstream to format into buf so that
    // we don't affect the ostream's width setting.
    ostrstream out( buf, sizeof(buf) );
  
    switch ( TDate::PrintOption )
        {
        case TDate::Normal:
            out << d.NameOfMonth() << " " 
                << d.DayOfMonth()  << ", "
                << d.Year() << ends;
            break;
        case TDate::Terse:
            sprintf(buf,"%2u-%.3s-%.2u",
                    d.DayOfMonth(),
                    d.NameOfMonth(),
                    d.Year() % 100);
            break;
        case TDate::Numbers:
            out << d.Month() << "/"
                << d.DayOfMonth() << "/"
                << (d.Year() % 100) << ends;
            break;
        case TDate::EuropeanNumbers:
            out << d.DayOfMonth()   << "/"
                << d.Month() <<"/"
                << (d.Year() % 100) << ends;
            break;
        case TDate::European:
            out << d.DayOfMonth() << " "
                << d.NameOfMonth() << " " 
                << d.Year() << ends;
            break;
        };

    // now we write out the formatted buffer, and the ostream's
    // width setting will control the actual width of the field.
    s << buf;
    return s;
}

