/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CHECKS.CPP                                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1993, 1996 by Borland International
 *      All Rights Reserved.
 *
 */


#if !defined(__FLAT__)
#if defined(__MEDIUM__) || defined(__LARGE__) || defined(__HUGE__)
#pragma codeseg _TEXTC
#endif
#endif

#undef __DEBUG
#define __DEBUG 0

//
// Make sure __TRACE is defined so that we can provide
// run-time support in non-debug versions of the library.
//
#undef  __TRACE
#define __TRACE

#define _BUILD_CHECKS   // need this define so checks.h won't
                        // try to declare Def diag group.

#include <checks.h>
#include <strstrea.h>
#include <cstring.h>

//
// Buffer size for diagnostic messages
//
#define DIAG_MAXBUFFER              256

//
// Definition of the default diagnostic group "Def" (expands to TDiagGroupDef)
//
DIAG_DEFINE_GROUP(Def,1,0);

//
// Global stream for diagnostic messages
//
// BUG: doesn't always get constructed before use in
// constructors for static objects. Need to guarantee
// construction, probably with the same sort of mechanism as
// in the standard iostreams.
//

// Use dynamically allocated buffer so that we can clean up.
static char *buffer;

static void initbuffer()
{
    buffer = new char[DIAG_MAXBUFFER];
}
#pragma startup initbuffer 31

static void freebuffer()
{
    delete [] buffer;
}
#pragma exit freebuffer 31

ostrstream TDiagBase::Out(buffer, DIAG_MAXBUFFER);

//
// TDiagBase::Output - Sends the specified message to the debug output
// device. Under Windows, the OutputDebugString() function (which sends
// the string to the AUX: device) is used.  Under DOS, the message is
// streamed out to cout.
//
#if defined(__FLAT__)
extern unsigned char __isGUI;   /* defined in c0nt.asm, to determine at runtime
                                   if we're a GUI or Console mode application */
#endif
void TDiagBase::Output( const char *msg )
{
#if defined(__FLAT__)
   if(__isGUI)
	   ::OutputDebugString(msg);
    else	
		cout << msg;
#else
#if defined(_Windows)
	::OutputDebugString(msg);
#else
    cout << msg;
#endif
#endif	
}

//
// TDiagBase::Trace - Formats a trace message using the specified parameters
// and outputs it using the output() function.
//
// Note that the formatted message is limited to DIAG_MAXBUFFER characters.
//
void TDiagBase::Message( const char *type,
                         const char *group, const char *msg,
                         const char *fname, uint32 line )
{
    char buf[DIAG_MAXBUFFER];
    ostrstream out(buf,sizeof(buf));
    out << type << ' ' << fname << ' ' << line
        << ": [" << group << "] " << msg
        << "\n\r" << ends;
    Output( buf );
}


//
// TDiagBase::Trace - Formats a trace message using the specified parameters
// and outputs it using the output() function.
//
void TDiagBase::Trace( const char *group, const char *msg,
                       const char *fname, uint32 line )
{
    Message( "Trace", group, msg, fname, line );
}

//
// TDiagBase::Warn - Formats a warning message using the specified parameters
// and outputs it using the output() function.
//
void TDiagBase::Warn( const char *group, const char *msg,
                      const char *fname, uint32 line )
{
    Message( "Warning", group, msg, fname, line );
}

string xerror::MakeString( const char *type,
                           const char *txt,
                           const char *file,
                           uint32 line )
{
    char buf[256];
    ostrstream temp(buf,sizeof(buf));
    temp << type << " failed " << file << ' ' << line << ": " << txt << ends;
    return string( (const char *)buf );
}


