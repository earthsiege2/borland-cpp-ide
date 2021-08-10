/*------------------------------------------------------------------------*/
/*                                                                        */
/*  THREAD.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1993 Borland International                              */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif  // __STDLIB_H

#if !defined( __WINDOWS_H )
#define STRICT
#include <windows.h>
#endif  // __WINDOWS_H

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( __CLASSLIB_DEFS_H )
#include "classlib\defs.h"
#endif  // __CLASSLIB_DEFS_H

#if !defined( __CLASSLIB_THREAD_H )
#include "classlib\thread.h"
#endif  // __CLASSLIB_THREAD_H

DIAG_DEFINE_GROUP(Threads,1,0);

HANDLE TThread::Start()
{
#if defined( __MT__ )
    Handle = _beginthreadNT( &TThread::Execute, 0, this, 0, 0, &ThreadId );
#else
    Handle = ::CreateThread( 0, 0, &TThread::Execute, this, 0, &ThreadId );
#endif
    if( Handle != 0 )
        {
        TRACEX( Threads, 1, "Thread started [handle:" << Handle << ']' );
        Stat = Running;
        }        
    else
        {
        TRACEX(Threads, 2, "Thread failed to start" );
        Stat = Invalid;
        throw ThreadError(ThreadError::CreationFailure);
        }
    return Handle;
}

DWORD TThread::Suspend()
{
    switch( GetStatus() )
        {
        case Created:
            TRACEX( Threads, 2, "Illegal thread suspension [handle:" << Handle << ']' );
            throw ThreadError(ThreadError::SuspendBeforeRun);
        case Finished:
            TRACEX( Threads, 2, "Illegal thread suspension [handle:" << Handle << ']' );
            throw ThreadError(ThreadError::SuspendAfterExit);
        default:
            TRACEX( Threads, 0, "Thread suspended [handle:" << Handle << ']' );
            Stat = Suspended;
            return ::SuspendThread(Handle);
        }
}

DWORD TThread::Resume()
{
    switch( GetStatus() )
        {
        case Created:
            TRACEX( Threads, 2, "Illegal thread resumption [handle:" << Handle << ']' );
            throw ThreadError(ThreadError::ResumeBeforeRun);
        case Running:
            TRACEX( Threads, 2, "Illegal thread resumption [handle:" << Handle << ']' );
            throw ThreadError(ThreadError::ResumeDuringRun);
        case Finished:
            throw ThreadError(ThreadError::ResumeAfterExit);
        default:
            TRACEX( Threads, 0, "Thread resumed [handle:" << Handle << ']' );
            DWORD res = ::ResumeThread(Handle);
            if( res == 0 )
                Stat = Running;
            return res;
        }        
}

void TThread::Terminate()
{
    TRACEX( Threads, 1, "Thread termination requested [handle:" << Handle << ']' );
    TerminationRequested = 1;
}

unsigned long TThread::WaitForExit( unsigned long timeout )
{
    TRACEX( Threads, 1, "Waiting for thread exit [handle:" << Handle << ']' );
    if( Stat == Running )
        return ::WaitForSingleObject( Handle, timeout );
    else
        return -1;
}

unsigned long TThread::TerminateAndWait( unsigned long timeout )
{
    Terminate();
    return WaitForExit( timeout );
}

int TThread::SetPriority( int pri )
{
    TRACEX( Threads, 1, "Thread priority changed to " << pri << " [handle:" << Handle << ']' );
    return ::SetThreadPriority(Handle,pri);
}

TThread::ThreadError::ThreadError(ErrorType type) :
    xmsg(MakeString(type)),
    Type(type)
{
}

string TThread::ThreadError::MakeString(ErrorType type)
{
    static char *Names[] =
        {
        "Suspend() before Run()",
        "Resume() before Run()",
        "Resume() during Run()",
        "Suspend() after Exit()",
        "Resume() after Exit()",
        "creation failure",
        "destroyed before Exit()",
        "illegal assignment"
        };
    string Msg;
    Msg.reserve(40);
    Msg = "Error[thread]: ";
    Msg += Names[type];
    return Msg;
}

TThread::TThread() :
    Handle(0),
    ThreadId(0),
    Stat(Created),
    TerminationRequested(0)
{
}

TThread::TThread( const TThread& ) :
    Handle(0),
    ThreadId(0),
    Stat(Created),
    TerminationRequested(0)
{
}

TThread::~TThread()
{
    if( GetStatus() != Finished )
        throw ThreadError(ThreadError::DestroyBeforeExit);
    ::CloseHandle(Handle);
}

const TThread& TThread::operator = ( const TThread& thread )
{
    switch( GetStatus() )
        {
        case Created:
        case Finished:
            {
            if( this != &thread )
                {
                Handle = 0;
                ThreadId = 0;
                Stat = Created;
                TerminationRequested = 0;
                }
            return *this;
            }
        default:
            throw ThreadError(ThreadError::AssignError);
        }
}

unsigned long _stdcall TThread::Execute( void *thread )
{
    return STATIC_CAST(TThread*,thread)->Run();
}

//  Call only when Stat claims
//  that the thread is Running.
TThread::Status TThread::CheckStatus() const
{
    DWORD ExitCode;
    ::GetExitCodeThread( Handle, &ExitCode );
    if( ExitCode == STILL_ACTIVE )
        return Running;
    else
        return Finished;
}


