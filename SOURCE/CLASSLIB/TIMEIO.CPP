/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TIMEIO.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STDIO_H )
#include <stdio.h>
#endif

#if !defined( __STRSTREA_H )
#include <strstrea.h>
#endif

#if !defined( __IOMANIP_H )
#include <iomanip.h>
#endif

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif

#if !defined( CLASSLIB_TIME_H )
#include <classlib/time.h>
#endif

#if !defined( CLASSLIB_FILE_H )
#include <classlib/file.h>
#endif

// Static variable intialization:
int TTime::PrintDateFlag = 1;

string TTime::AsString() const
{
    char buf[80];
    ostrstream strtemp(buf, sizeof(buf));
    strtemp << (*this) << ends;
    string temp(buf);
    return temp;
}

ostream _BIDSFAR & _BIDSFUNC operator << ( ostream _BIDSFAR & s, const TTime _BIDSFAR & t )
{
    char buf[80];

    // We use an ostrstream to format into buf so that
    // we don't affect the ostream's width setting.
    ostrstream out( buf, sizeof(buf) );
  
    // First print the date if requested:
    if(TTime::PrintDateFlag) 
        out << TDate(t) << " ";

    unsigned hh = t.Hour();
    out << (hh <= 12 ? hh : hh-12) << ':' 
        << setfill('0') << setw(2) << t.Minute() << ':'
        << setw(2) << t.Second() << ' ' << setfill(' ');
    out << ( hh<12 ? "am" : "pm") << ends;

    // now we write out the formatted buffer, and the ostream's
    // width setting will control the actual width of the field.
    s << buf;
    return s;
}

int TTime::PrintDate( int f )
{
    int temp = PrintDateFlag;
    PrintDateFlag = f;
    return temp;
}

ostream _BIDSFAR & _BIDSFUNC operator << ( ostream _BIDSFAR & os, const TFileStatus _BIDSFAR & status )
{
    os << "File Status: " << status.fullName << '\n';
    os << "    created: " << status.createTime << '\n';
    os << "   modified: " << status.modifyTime << '\n';
    os << "   accessed: " << status.accessTime << '\n';
    os << "       size: " << status.size << '\n';
    os << " attributes: " << (int)status.attribute << '\n';
    return os;
}


