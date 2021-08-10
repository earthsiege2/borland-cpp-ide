/*------------------------------------------------------------------------*/
/*                                                                        */
/*  THREAD.CPP                                                            */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __PROCESS_H )
#include <process.h>
#endif

#if !defined( __STDLIB_H )
#include <stdlib.h>
#endif

#if !defined( __CHECKS_H )
#include <checks.h>
#endif

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined( CLASSLIB_THREAD_H )
#include <classlib/thread.h>
#endif

DIAG_DEFINE_GROUP(Threads,1,0);

#if defined( BI_PLAT_WIN32 )

//------------------------------------------------
//
//  WIN32
//
//  Use OS call to close thread handle.
//

inline void InternalCloseHandle( TThread::THandle Handle )
{
    ::CloseHandle(Handle);
}

//------------------------------------------------
//
//  WIN32
//
//  Use OS call to suspend thread.
//

inline DWORD InternalSuspendThread( TThread::THandle Handle )
{
    return ::SuspendThread(Handle);
}

//------------------------------------------------
//
//  WIN32
//
//  Use OS call to suspend thread.
//

inline DWORD InternalResumeThread( TThread::THandle Handle )
{
    return ::ResumeThread(Handle);
}

//------------------------------------------------
//
//  WIN32
//
//  Use OS call to wait for thread termination.
//

inline unsigned long InternalWaitForThread( TThread::THandle Handle,
                                            unsigned long timeout )
{
    return ::WaitForSingleObject( Handle, timeout );
}

//------------------------------------------------
//
//  WIN32
//
//  Use OS call to get thread priority.
//

inline int InternalGetThreadPriority( TThread::THandle Handle )
{
    return ::GetThreadPriority( Handle );
}

//------------------------------------------------
//
//  WIN32
//
//  Use OS call to set thread priority.
//

inline int InternalSetThreadPriority( TThread::THandle Handle, int pri )
{
    return ::SetThreadPriority( Handle, pri );
}

#endif

#if defined( BI_PLAT_OS2 )

//------------------------------------------------
//
//  OS/2
//
//  Don't need to close the handle.
//
inline void InternalCloseHandle( TThread::THandle )
{
}

//------------------------------------------------
//
//  OS/2
//
//  Use OS call to suspend thread.
//

inline ULONG InternalSuspendThread( TThread::THandle Handle )
{
    return ::DosSuspendThread(Handle);
}

//------------------------------------------------
//
//  OS/2
//
//  Use OS call to suspend thread.
//

inline ULONG InternalResumeThread( TThread::THandle Handle )
{
    return ::DosResumeThread(Handle);
}

//------------------------------------------------
//
//  OS/2
//
//  Use OS call to wait for thread termination.
//

inline ULONG InternalWaitForThread( TThread::THandle &Handle,
     							                        unsigned long timeout )
{
    return ::DosWaitThread( &Handle, timeout );
}

#endif

//------------------------------------------------
//
//  TThread constructors
//

TThread::TThread() :
#if defined( BI_PLAT_WIN32 )
    ThreadId(0),
#elif defined( BI_PLAT_OS2 )
    Priority(0),
#endif
    Handle(0),
    Stat(Created),
    TerminationRequested(0)
{
}

TThread::TThread( const TThread& ) :
#if defined( BI_PLAT_WIN32 )
    ThreadId(0),
#elif defined( BI_PLAT_OS2 )
    Priority(0),
#endif
    Handle(0),
    Stat(Created),
    TerminationRequested(0)
{
}

//------------------------------------------------
//
//  TThread assignment operator
//
//  Used when assigning derived objects. Attempting to
//  assign from a running object is an error, since the
//  data fields in the running object can be changing
//  asynchronously.
//

const TThread& TThread::operator = ( const TThread& thread )
{
    switch( GetStatus() )
        {
        case Created:
        case Suspended:
        case Finished:
            {
            if( this != &thread )
                {
                Handle = 0;
#if defined( BI_PLAT_WIN32 )
                ThreadId = 0;
#elif defined( BI_PLAT_OS2 )
                Priority = 0;
#endif
                Stat = Created;
                TerminationRequested = 0;
                }
            return *this;
            }
        default:
            throw ThreadError(ThreadError::AssignError);
        }
}

//------------------------------------------------
//
//  TThread destructor
//
//  If the thread hasn't finished, destroying its control
//  object is an error.
//

TThread::~TThread()
{
    if( GetStatus() != Finished )
        throw ThreadError(ThreadError::DestroyBeforeExit);
    InternalCloseHandle(Handle);
}

//------------------------------------------------
//
//  TThread::Start()
//
//  Starts the thread executing. The actual call depends on the
//  operating system. After the system call we check status.
//

TThread::THandle TThread::Start()
{
#if defined( BI_PLAT_WIN32 )
#if defined( __MT__ )
    Handle = (HANDLE)::_beginthreadNT( &TThread::Execute, 4096, this, 0, 0, &ThreadId );
#else
    Handle = ::CreateThread( 0, 0, &TThread::Execute, this, 0, &ThreadId );
#endif
#else
#if defined( __MT__ )
    Handle = ::_beginthread( &TThread::Execute, 4096, this );
#else
    APIRET res =
        ::DosCreateThread( &Handle,
		                   (void (__syscall*)(unsigned long))&TThread::Execute,
                           REINTERPRET_CAST(unsigned long,this),
                           FALSE,
                           4000 );
#endif
#endif

    if( Handle != 0 )
        {
        TRACEX( Threads, 1, "Thread started [id:" << Handle << ']' );
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

//------------------------------------------------
//
//  TThread::Suspend()
//
//  It's an error to try to suspend a thread that
//  hasn't been started or that has already terminated.
//

unsigned long TThread::Suspend()
{
    switch( GetStatus() )
        {
        case Created:
            TRACEX( Threads, 2, "Illegal thread suspension [id:" << Handle << ']' );
            throw ThreadError(ThreadError::SuspendBeforeRun);
        case Finished:
            TRACEX( Threads, 2, "Illegal thread suspension [id:" << Handle << ']' );
            throw ThreadError(ThreadError::SuspendAfterExit);
        default:
            TRACEX( Threads, 0, "Thread suspended [id:" << Handle << ']' );
            Stat = Suspended;
            return InternalSuspendThread(Handle);
        }
}

//------------------------------------------------
//
//  TThread::Resume()
//
//  It's an error to try to resume a thread that hasn't
//  been suspended.
//

unsigned long TThread::Resume()
{
    switch( GetStatus() )
        {
        case Created:
            TRACEX( Threads, 2, "Illegal thread resumption [id:" << Handle << ']' );
            throw ThreadError(ThreadError::ResumeBeforeRun);
        case Running:
            TRACEX( Threads, 2, "Illegal thread resumption [id:" << Handle << ']' );
            throw ThreadError(ThreadError::ResumeDuringRun);
        case Finished:
            throw ThreadError(ThreadError::ResumeAfterExit);
        default:
            TRACEX( Threads, 0, "Thread resumed [id:" << Handle << ']' );
            unsigned long res = InternalResumeThread(Handle);
            if( res == 0 )
                Stat = Running;
            return res;
        }        
}

//------------------------------------------------
//
//  TThread::Terminate()
//
//  Mark the thread for termination.
//

void TThread::Terminate()
{
    TRACEX( Threads, 1, "Thread termination requested [handle:" << Handle << ']' );
    TerminationRequested = 1;
}

//------------------------------------------------
//
//  TThread::WaitForExit()
//
//  Block until the thread terminates.
//
//  IMPORTANT: the meaning of the 'timeout' parameter is
//  different for NT and OS/2. Under NT it specifies how long
//  to wait for termination. Under OS/2 it specifies whether
//  to wait or to return immediately if the thread hasn't
//  terminated.
//

unsigned long TThread::WaitForExit( unsigned long timeout )
{
    TRACEX( Threads, 1, "Waiting for thread exit [id:" << Handle << ']' );
    if( Stat == Running )
        return ::InternalWaitForThread( Handle, timeout );
    else
        return -1;
}

//------------------------------------------------
//
//  TThread::TerminateAndWait()
//
//  See note for WaitForExit().
//

unsigned long TThread::TerminateAndWait( unsigned long timeout )
{
    Terminate();
    return WaitForExit( timeout );
}

//------------------------------------------------
//
//  TThread::SetPriority()
//
//  Set the thread's priority.
//

int TThread::SetPriority( int pri )
{
    TRACEX( Threads, 1, "Thread priority changed to " << pri << " [id:" << Handle << ']' );
#if defined( BI_PLAT_WIN32 )
    return ::SetThreadPriority(Handle,pri);
#else
    
    APIRET res = DosSetPriority( PRTYS_THREAD,
                                 PRTYC_NOCHANGE,
                                 pri-Priority,
                                 Handle );
    if( res != 0 )
        Priority = pri;
    return res;
#endif
}

//------------------------------------------------
//
//  TThread::Execute()
//
//  Run the thread.
//

#if defined( __MT__ )
void _USERENTRY TThread::Execute( void *thread )
{
    STATIC_CAST(TThread*,thread)->Run();
}
#elif defined( BI_PLAT_WIN32 )
unsigned long _stdcall TThread::Execute( void *thread )
{
    return STATIC_CAST(TThread*,thread)->Run();
}
#else
void __stdcall TThread::Execute( unsigned long thread )
{
    REINTERPRET_CAST(TThread*,thread)->Run();
}
#endif

//------------------------------------------------
//
//  TThread::CheckStatus()
//
//  Call only when Stat claims that the thread is Running.
//

#if defined( BI_PLAT_WIN32 )
TThread::Status TThread::CheckStatus() const
{
    DWORD ExitCode;
    ::GetExitCodeThread( Handle, &ExitCode );
    if( ExitCode == STILL_ACTIVE )
        return Running;
    else
        return Finished;
}
#elif defined( BI_PLAT_OS2 )
TThread::Status TThread::CheckStatus() const
{
    if( ::DosWaitThread( CONST_CAST(THandle *,&Handle), DCWW_NOWAIT ) == ERROR_THREAD_NOT_TERMINATED )
        return Running;
    else
        return Finished;
}
#endif

//------------------------------------------------
//
//  TThread::ThreadError constructor
//

TThread::ThreadError::ThreadError(ErrorType type) :
    xmsg(MakeString(type)),
    Type(type)
{
}

//------------------------------------------------
//
//  TThread::ThreadError::MakeString()
//
//  Translates an error code into a string.
//

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


