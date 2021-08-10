/*
 *      C/C++ Run Time Library - Version 11.0
 *
 *      Copyright (c) 1993, 2002 by Borland Software Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision: 9.7.2.1 $ */

#define _USE_OLD_XMSG
#include <string>
#include <except.h>

_RTLENTRY xmsg::xmsg(const std::string &s)
{
    str = new std::string(s);
}

_RTLENTRY xmsg::xmsg(const xmsg &c)
{
    str = new std::string(c.why());
}

_RTLENTRY xmsg::~xmsg() throw()
{
    delete str;
}

xmsg & _RTLENTRY xmsg::operator=(const xmsg &c)
{
    if (this != &c) {
        std::exception::operator=(c);
        delete str;
        str = new std::string(c.why());
    }
    
    return *this;
}

const char * xmsg::what() const throw()
{
    return str->c_str();
}


void _RTLENTRY xmsg::raise() throw( xmsg )
{
    throw *this;
}
