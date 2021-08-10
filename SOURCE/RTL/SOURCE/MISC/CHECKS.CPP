/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CHECKS.CPP - Diagnostic stuff                                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1992, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.5  $ */

#if !defined(__FLAT__)
#error 16 bit targets not supported
#endif

#undef __DEBUG
#define __DEBUG 0

#pragma option -V?  // Enable virdefs for this module.

//
// Make sure __TRACE is defined so that we can provide
// run-time support in non-debug versions of the library.
//
#undef  __TRACE
#define __TRACE

#define _BUILD_CHECKS   // need this define so checks.h won't
                        // try to declare Def diag group.

#include <checks.h>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
//
// Definition of the default diagnostic group "Def" (expands to TDiagGroupDef)
//
DIAG_DEFINE_GROUP(Def,1,0);

//
// TDiagBase::Output - Sends the specified message to the debug output
// device. Under Windows, the OutputDebugString() function (which sends
// the string to the AUX: device) is used.  Under DOS, the message is
// streamed out to cout.
//

extern int _isWindows; /* from startup/globals.c */

TDiagGroup::TDiagGroup(uint8 enabled, uint8 level, const char *g)
	: Group(g)
{
    Flags.Enabled = enabled;
    Flags.Level = level;
}
void TDiagGroup::Output( const std::string &msg )
{
   if(_isWindows)
	   ::OutputDebugString(msg.c_str());
    else
		std::cerr << msg;
}

//
// TDiagGroup::Trace - Formats a trace message using the specified parameters
// and outputs it using the output() function.
//
//
void TDiagGroup::Message( const char *type,
                         std::ostringstream &os,
                         const char *fname, uint32 line )
{
    std::ostringstream out;
    out << type << ' ' << fname << ' ' << line
        << ": [" << Group << "] " << os.str() << "\r\n";
    Output( out.str() );
}


// static function here to avoid requiring <string> to compile <checks.h>
static std::string xerror_fmt( const char *type,
                           const char *txt,
                           const char *file,
                           uint32 line )
{
    std::ostringstream temp;
    temp << type << " failed " << file << ' ' << line << ": " << txt << std::ends;
    return temp.str();
}

xerror::xerror(const char *type, const char *txt, const char *file, uint32 line)
    : xmsg(xerror_fmt(type, txt, file, line))
{
}

