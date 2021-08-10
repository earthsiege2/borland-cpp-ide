/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <except.h>
#include <cstring.h>

_RTLENTRY xmsg::xmsg(const string _FAR & msg)
{
    str = new string(msg);
};

_RTLENTRY xmsg::xmsg(const xmsg _FAR & msg)
{
    str = new string(msg.why());
}

_RTLENTRY xmsg::~xmsg()
{
    delete str;
}

void _RTLENTRY xmsg::raise() throw( xmsg )
{
    throw *this;
}

xmsg _FAR & _RTLENTRY xmsg::operator=(const xmsg _FAR & src)
{
   if(this!=&src)
   {
      delete str;
      str = new string(src.why());
   }
   return(*this);
}

