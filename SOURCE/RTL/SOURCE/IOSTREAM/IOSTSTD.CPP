/*[]------------------------------------------------------------[]*/
/*|                                                              |*/
/*|     ioststd.cpp                                              |*/
/*|                                                              |*/
/*|     Class iostream                                           |*/
/*|          implements standard streams:                        |*/
/*|              cin                                             |*/
/*|              cout                                            |*/
/*|              cerr                                            |*/
/*|              clog                                            |*/
/*|                                                              |*/
/*[]------------------------------------------------------------[]*/

/*
 *      C/C++ Run Time Library - Version 7.0
 *
 *      Copyright (c) 1990, 1996 by Borland International
 *      All Rights Reserved.
 *
 */

#include <ioconfig.h>
#include <filesys.h>
#include <fstream.h>

// this allows calling a constructor for an existing object
inline void * operator new(size_t, void *p)
{
    return p;
}

istream_withassign _EXPDATA cin;
ostream_withassign _EXPDATA cout;
ostream_withassign _EXPDATA cerr;
ostream_withassign _EXPDATA clog;

streambuf *__stdin_streambuf;
streambuf *__stdout_streambuf;
streambuf *__stderr_streambuf;

#pragma warn -use
static void Iostream_init()
{
#pragma startup Iostream_init 16

    // initially filebufs for efficiency
    __stdin_streambuf  = new filebuf(F_stdin);
    __stdout_streambuf = new filebuf(F_stdout);
    __stderr_streambuf = new filebuf(F_stderr);

    // call constructors for standard streams
    new (&cin)  istream_withassign;
    new (&cout) ostream_withassign;
    new (&cerr) ostream_withassign;
    new (&clog) ostream_withassign;

    // attach the standard files to the standard streams
    cin  = __stdin_streambuf;
    cout = __stdout_streambuf;
    clog = __stderr_streambuf;
    cerr = __stderr_streambuf;

    // tie cin, cerr, and clog to cout
    cin.tie(&cout);
    clog.tie(&cout);
    cerr.tie(&cout);

    // initialize the secret x_delbuf members
    cin.delbuf(1);
    cout.delbuf(1);
    cerr.delbuf(1);
    clog.delbuf(1);

    // unit-buffer cerr
    cerr.setf(ios::unitbuf);

    // if cout is the screen, unit-buffer it too
    if( isatty(1) )
        cout.setf(ios::unitbuf);
}

void Iostream_delete()
{
#pragma exit Iostream_delete 16

    delete __stdin_streambuf;
    delete __stdout_streambuf;
    delete __stderr_streambuf;
}
