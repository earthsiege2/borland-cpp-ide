/*------------------------------------------------------------------------*/
/*                                                                        */
/*  THREAD.H                                                              */
/*                                                                        */
/*  Copyright (c) 1993, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Defines the class TMutex and its nested class Lock.                   */
/*  Defines the class TCriticalSection and its nested class Lock.         */
/*  Defines the class TSync and its nested class Lock.                    */
/*  Defines the template TStaticSync and its nested class Lock.           */
/*  Defines the class TThread.                                            */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_THREAD_H )
#define CLASSLIB_THREAD_H

#if !defined( __CSTRING_H )
#include <cstring.h>
#endif

#if defined( _Windows )
# if defined( __WINDOWS_H )
#   if !defined( STRICT )
#     error #define <windows.h> must be preceded by #define STRICT
#   endif
# else
#   define STRICT   
#   include <windows.h>
# endif
#elif defined( __OS2__ )
# if defined( __OS2_H )
#   if !defined( INCL_BASE )
#     error #include <os2.h> must be preceded by #define INCL_PM
#   endif
# else
#   define INCL_BASE
#   include <os2.h>
# endif
#endif

#if !defined( __CHECKS_H )
#include <checks.h>
#endif  // __CHECKS_H

#if !defined( CLASSLIB_DEFS_H )
#include <classlib/defs.h>
#endif

#if !defined(BI_MULTI_THREAD)
#error Thread classes require multi-threaded operating system.
#endif

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po-
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TMutex;                                                         */
/*  class TMutex::Lock;                                                   */
/*                                                                        */
/*  TMutex provides a system-independent interface to critical            */
/*  sections in threads. With suitable underlying implementations the     */
/*  same code can be used under OS/2 and Windows NT.                      */
/*                                                                        */
/*  An object of type TMutex can be used in conjunction with              */
/*  objects of type TMutex::Lock to guarantee that only one               */
/*  thread can be executing any of the code sections protected by the     */
/*  lock at any given time.                                               */
/*                                                                        */
/*  The differences between the classes TCriticalSection and TMutex are   */
/*  that a timeout can be specified when creating a Lock on a TMutex      */
/*  object, and that a TMutex object has a HANDLE which can be used       */
/*  outside the class. This mirrors the distinction made in Windows NT    */
/*  between a CRITICALSECTION and a Mutex. Under NT a TCriticalSection    */
/*  object is much faster than a TMutex object. Under operating systems   */
/*  that don't make this distinction a TCriticalSection object can use    */
/*  the same underlying implementation as a TMutex, losing the speed      */
/*  advantage that it has under NT.                                       */
/*                                                                        */
/*  TMutex Public Interface                                               */
/*  ---------------------------------                                     */
/*                                                                        */
/*      TMutex();               Constructor. Takes no parameters.         */
/*                                                                        */
/*      ~TMutex();              Destructor.                               */
/*                                                                        */
/*      operator HANDLE() const; (NT)                                     */
/*      operator HMTX() const;   (OS/2)                                   */
/*                              Returns a handle to the TMutex object,    */
/*                              for use in OS calls that require it.      */
/*                                                                        */
/*      class Lock;             Handles locking and unlocking of          */
/*                              critical sections.                        */
/*                                                                        */
/*                                                                        */
/*  TMutex::Lock Public Interface                                         */
/*  ---------------------------------------                               */
/*                                                                        */
/*      Lock( const TMutex&,                                              */
/*            unsigned long timeOut = NoLimit );                          */
/*                                                                        */
/*                              Request a lock on the TCriticalSection    */
/*                              object. If no Lock object in a different  */
/*                              thread from the calling thread holds      */
/*                              a lock on that object the lock is         */
/*                              allowed and execution continues. If       */
/*                              another thread holds a lock on that       */
/*                              object the requesting thread is blocked   */
/*                              until the owning thread has released all  */
/*                              of its locks.                             */
/*                                                                        */
/*      ~Lock();                Releases the lock.                        */
/*                                                                        */
/*  Example                                                               */
/*  -------                                                               */
/*                                                                        */
/*      TMutex LockF;                                                     */
/*                                                                        */
/*      void f()                                                          */
/*      {                                                                 */
/*      TMutex::Lock lock(LockF);                                         */
/*      // critical processing goes here                                  */
/*      }                                                                 */
/*                                                                        */
/*  Only one thread of execution will be allowed to execute the critical  */
/*  code inside f() at any one time.                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TMutex
{

public:

#if defined( __WIN32__ )
    // Windows NT
    enum { NoLimit = -1 };
    typedef HANDLE THandle;
#elif defined( __OS2__ )
    // OS/2
    enum { NoLimit = SEM_INDEFINITE_WAIT };
    typedef HMTX THandle;
#endif

    TMutex();
    ~TMutex();

    operator THandle() const;   // HANDLE() under NT
                                // HMTX() under OS/2

    class Lock
    {
    public:
        Lock( const TMutex&, unsigned long timeOut = NoLimit );
        ~Lock();

        void Release();

    private:
        const TMutex& MutexObj;

    };

    friend Lock;

private:

    THandle Handle;

    TMutex( const TMutex& );
    const TMutex& operator = ( const TMutex& );

};


#if defined( __WIN32__ )

//------------------------------------------------
//
//  TMutex constructor
//
//  WIN32
//

inline TMutex::TMutex()
{
    Handle = ::CreateMutex( 0, FALSE, 0 );
}

//------------------------------------------------
//
//  TMutex destructor
//
//  WIN32
//

inline TMutex::~TMutex()
{
    ::CloseHandle(Handle);
}

//------------------------------------------------
//
//  TMutex::operator THandle()
//
//  WIN32
//

inline TMutex::operator TMutex::THandle() const
{
    return Handle;
}

//------------------------------------------------
//
//  TMutex::Lock constructor
//
//  WIN32
//

inline TMutex::Lock::Lock( const TMutex& mutex, unsigned long timeOut ) :
    MutexObj(mutex)
{
    ::WaitForSingleObject( MutexObj, timeOut );
}

//------------------------------------------------
//
//  TMutex::Lock destructor
//
//  WIN32
//

inline TMutex::Lock::~Lock()
{
    Release();
}

//------------------------------------------------
//
//  TMutex::Lock::Release()
//
//  WIN32
//

inline void TMutex::Lock::Release()
{
    ::ReleaseMutex(MutexObj);
}

#elif defined( __OS2__ )

//------------------------------------------------
//
//  TMutex constructor
//
//  OS/2
//

inline TMutex::TMutex()
{
    ::DosCreateMutexSem( 0, &Handle, 0, FALSE );
}

//------------------------------------------------
//
//  TMutex destructor
//
//  OS/2
//

inline TMutex::~TMutex()
{
    ::DosCloseMutexSem(Handle);
}

//------------------------------------------------
//
//  TMutex::operator THandle()
//
//  OS/2
//

inline TMutex::operator TMutex::THandle() const
{
    return Handle;
}

//------------------------------------------------
//
//  TMutex::Lock constructor
//
//  OS/2
//

inline TMutex::Lock::Lock( const TMutex& mutex, unsigned long timeOut ) :
    MutexObj(mutex)
{
    ::DosRequestMutexSem( MutexObj, timeOut );
}

//------------------------------------------------
//
//  TMutex::Lock destructor
//
//  OS/2
//

inline TMutex::Lock::~Lock()
{
    Release();
}

//------------------------------------------------
//
//  TMutex::Lock::Release()
//
//  OS/2
//

inline void TMutex::Lock::Release()
{
    ::DosReleaseMutexSem(MutexObj);
}

#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TCriticalSection;                                               */
/*  class TCriticalSection::Lock;                                         */
/*                                                                        */
/*  TCriticalSection provides a system-independent interface to critical  */
/*  sections in threads. With suitable underlying implementations the     */
/*  same code can be used under OS/2 and Windows NT.                      */
/*                                                                        */
/*  An object of type TCriticalSection can be used in conjunction with    */
/*  objects of type TCriticalSection::Lock to guarantee that only one     */
/*  thread can be executing any of the code sections protected by the     */
/*  lock at any given time.                                               */
/*                                                                        */
/*  The differences between the classes TCriticalSection and TMutex are   */
/*  that a timeout can be specified when creating a Lock on a TMutex      */
/*  object, and that a TMutex object has a HANDLE which can be used       */
/*  outside the class. This mirrors the distinction made in Windows NT    */
/*  between a CRITICALSECTION and a Mutex. Under NT a TCriticalSection    */
/*  object is much faster than a TMutex object. Under operating systems   */
/*  that don't make this distinction a TCriticalSection object can use    */
/*  the same underlying implementation as a TMutex, losing the speed      */
/*  advantage that it has under NT.                                       */
/*                                                                        */
/*  TCriticalSection Public Interface                                     */
/*  ---------------------------------                                     */
/*                                                                        */
/*      TCriticalSection();     Constructor. Takes no parameters.         */
/*                                                                        */
/*      ~TCriticalSection();    Destructor.                               */
/*                                                                        */
/*      class Lock;             Handles locking and unlocking of          */
/*                              critical sections.                        */
/*                                                                        */
/*  TCriticalSection::Lock Public Interface                               */
/*  ---------------------------------------                               */
/*                                                                        */
/*      Lock( const TCriticalSection& );                                  */
/*                                                                        */
/*                              Request a lock on the TCriticalSection    */
/*                              object. If no Lock object in a different  */
/*                              thread from the calling thread holds      */
/*                              a lock on that object the lock is         */
/*                              allowed and execution continues. If       */
/*                              another thread holds a lock on that       */
/*                              object the requesting thread is blocked   */
/*                              until the owning thread has released all  */
/*                              of its locks.                             */
/*                                                                        */
/*      ~Lock();                Releases the lock.                        */
/*                                                                        */
/*  Example                                                               */
/*  -------                                                               */
/*                                                                        */
/*      TCriticalSection LockF;                                           */
/*                                                                        */
/*      void f()                                                          */
/*      {                                                                 */
/*      TCriticalSection::Lock lock(LockF);                               */
/*      // critical processing goes here                                  */
/*      }                                                                 */
/*                                                                        */
/*  Only one thread of execution will be allowed to execute the critical  */
/*  code inside f() at any one time.                                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TCriticalSection
{

public:

    TCriticalSection();
    ~TCriticalSection();

    class Lock
    {
    public:
        Lock( const TCriticalSection& );
        ~Lock();
    private:
#if defined( __WIN32__ )
        const TCriticalSection& CritSecObj;
#elif defined( __OS2__ )
        TMutex::Lock Lck;
#endif
    };

    friend Lock;

private:

#if defined( __WIN32__ )
    CRITICAL_SECTION CritSec;
#elif defined( __OS2__ )
    TMutex CritSec;
#endif

    TCriticalSection( const TCriticalSection& );
    const TCriticalSection& operator = ( const TCriticalSection& );

};


#if defined( __WIN32__ )

//------------------------------------------------
//
//  TCriticalSection constructor
//
//  WIN32
//
//  Use system call to initialize the CRITICAL_SECTION object.
//

inline TCriticalSection::TCriticalSection()
{
    ::InitializeCriticalSection(CONST_CAST(CRITICAL_SECTION *,&CritSec));
}

//------------------------------------------------
//
//  TCriticalSection destructor
//
//  WIN32
//
//  Use system call to destroy the CRITICAL_SECTION object.
//

inline TCriticalSection::~TCriticalSection()
{
    ::DeleteCriticalSection(CONST_CAST(CRITICAL_SECTION *,&CritSec));
}

//------------------------------------------------
//
//  TCriticalSection::Lock constructor
//
//  WIN32
//
//  Use system call to lock the CRITICAL_SECTION object.
//

inline TCriticalSection::Lock::Lock( const TCriticalSection& sec ) :
    CritSecObj(sec)
{
    ::EnterCriticalSection(CONST_CAST(CRITICAL_SECTION *,&CritSecObj.CritSec));
}

//------------------------------------------------
//
//  TCriticalSection::Lock destructor
//
//  WIN32
//
//  Use system call to unlock the CRITICAL_SECTION object.
//

inline TCriticalSection::Lock::~Lock()
{
    ::LeaveCriticalSection(CONST_CAST(CRITICAL_SECTION *,&CritSecObj.CritSec));
}

#elif defined( __OS2__ )

//------------------------------------------------
//
//  TCriticalSection constructor
//
//  OS2
//
//  Compiler takes care of constructing the TMutex data object.
//

inline TCriticalSection::TCriticalSection()
{
}

//------------------------------------------------
//
//  TCriticalSection destructor
//
//  OS2
//
//  Compiler takes care of destroying the TMutex data object.
//

inline TCriticalSection::~TCriticalSection()
{
}

//------------------------------------------------
//
//  TCriticalSection::Lock constructor
//
//  OS2
//
//  Construct the TMutex::Lock object to lock the
//  specified TCriticalSection object.
//

inline TCriticalSection::Lock::Lock( const TCriticalSection& sec ) :
    Lck(sec.CritSec)
{
}

//------------------------------------------------
//
//  TCriticalSection::Lock destructor
//
//  OS2
//
//  Compiler takes care of destroying the TMutex::Lock data
//  object, which releases the lock.
//

inline TCriticalSection::Lock::~Lock()
{
}

#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TSync;                                                          */
/*  class TSync::Lock;                                                    */
/*                                                                        */
/*  TSync provides a system-independent interface to build classes        */
/*  that act like monitors, i.e., classes in which only one member        */
/*  can execute on a particular instance at any one time. TSync uses      */
/*  TCriticalSection, so it is portable to all platforms that             */
/*  TCriticalSection has been ported to.                                  */
/*                                                                        */
/*  TSync Public Interface                                                */
/*  -------------------------                                             */
/*                                                                        */
/*  None. TSync can only be a base class.                                 */
/*                                                                        */
/*  TSync Protected Interface                                             */
/*  ----------------------------                                          */
/*                                                                        */
/*      TSync( const TSync& );                                            */
/*                              Copy constructor. Does not copy the       */
/*                              TCriticalSection object.                  */
/*                                                                        */
/*      const TSync& operator = ( const TSync& );                         */
/*                              Assignment operator. Does not copy the    */
/*                              TCriticalSection object.                  */
/*                                                                        */
/*      class Lock;             Handles locking and unlocking of member   */
/*                              functions.                                */
/*                                                                        */
/*  Example                                                               */
/*  -------                                                               */
/*                                                                        */
/*                                                                        */
/*      class ThreadSafe : private TSync                                  */
/*      {                                                                 */
/*      public:                                                           */
/*          void f();                                                     */
/*          void g();                                                     */
/*      private:                                                          */
/*          int i;                                                        */
/*      };                                                                */
/*                                                                        */
/*      void ThreadSafe::f()                                              */
/*      {                                                                 */
/*      Lock lock(this);                                                       */
/*      if( i == 2 )                                                      */
/*          i = 3;                                                        */
/*      }                                                                 */
/*                                                                        */
/*      void ThreadSafe::g()                                              */
/*      {                                                                 */
/*      Lock lock(this);                                                       */
/*      if( i == 3 )                                                      */
/*          i = 2;                                                        */
/*      }                                                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

class TSync
{

protected:

    TSync();
    TSync( const TSync& );
    const TSync& operator = ( const TSync& );

    class Lock : private TCriticalSection::Lock
    {
    public:
        Lock( const TSync * );
    private:
        static const TCriticalSection& GetRef( const TSync * );
    };

    friend Lock;

private:

    TCriticalSection CritSec;

};

//------------------------------------------------
//
//  TSync constructors
//
//  Copy constructor does not copy the TCriticalSection object,
//  since the new object is not being used in any of its own
//  member functions. This means that the new object must start
//  in an unlocked state.
//

inline TSync::TSync()
{
}

inline TSync::TSync( const TSync& )
{
}

//------------------------------------------------
//
//  TSync assignment operator
//
//  Does not copy the TCriticalSection object, since the new
//  object is not being used in any of its own member functions.
//  This means that the new object must start in an unlocked state.
//

inline const TSync& TSync::operator = ( const TSync& )
{
    return *this;
}

//------------------------------------------------
//
//  TSync::Lock constructor
//
//  Locks the TCriticalSection object in the TSync object.
//

inline TSync::Lock::Lock( const TSync *sync ) :
    TCriticalSection::Lock(GetRef(sync))
{
}

//------------------------------------------------
//
//  TSync::Lock::GetRef()
//
//  Returns a reference to the TCriticalSection object contained
//  in the TSync object.
//
//  In the diagnostic version, checks for a null pointer.
//

inline const TCriticalSection& TSync::Lock::GetRef( const TSync *sync )
{
    CHECK( sync != 0 );
    return sync->CritSec;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class TStaticSync;                                 */
/*  template <class T> class TStaticSync::Lock;                           */
/*                                                                        */
/*  TStaticSync provides a system-independent interface to build sets     */
/*  of classes that act somewhat like monitors, i.e., classes in which    */
/*  only one member function can execute at any one time regardless of    */
/*  which instance it is being called on. TStaticSync uses                */
/*  TCriticalSection, so it is portable to all platforms that             */
/*  TCriticalSection has been ported to.                                  */
/*                                                                        */
/*  TStaticSync Public Interface                                          */
/*  -------------------------                                             */
/*                                                                        */
/*  None. TStaticSync can only be a base class.                           */
/*                                                                        */
/*  TStaticSync Protected Interface                                       */
/*  ----------------------------                                          */
/*                                                                        */
/*      TStaticSync<T>( const TStaticSync<T>& );                          */
/*                              Copy constructor. Does not copy the       */
/*                              TCriticalSection object.                  */
/*                                                                        */
/*      const TStaticSync<T>& operator = ( const TStaticSync<T>& );       */
/*                              Assignment operator. Does not copy the    */
/*                              TCriticalSection object.                  */
/*                                                                        */
/*      class Lock;             Handles locking and unlocking of member   */
/*                              functions.                                */
/*                                                                        */
/*  Example                                                               */
/*  -------                                                               */
/*                                                                        */
/*                                                                        */
/*      class ThreadSafe : private TStaticSync<ThreadSafe>                */
/*      {                                                                 */
/*      public:                                                           */
/*          void f();                                                     */
/*          void g();                                                     */
/*      private:                                                          */
/*          static int i;                                                 */
/*      };                                                                */
/*                                                                        */
/*      void ThreadSafe::f()                                              */
/*      {                                                                 */
/*      Lock lock;                                                        */
/*      if( i == 2 )                                                      */
/*          i = 3;                                                        */
/*      }                                                                 */
/*                                                                        */
/*      void ThreadSafe::g()                                              */
/*      {                                                                 */
/*      Lock lock;                                                        */
/*      if( i == 3 )                                                      */
/*          i = 2;                                                        */
/*      }                                                                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class TStaticSync
{

protected:

    TStaticSync();
    TStaticSync( const TStaticSync<T>& );
    const TStaticSync<T>& operator = ( const TStaticSync<T>& );
    ~TStaticSync();

    class Lock : private TCriticalSection::Lock
    {
    public:
        Lock() : TCriticalSection::Lock(*TStaticSync<T>::CritSec) {}
    };

    friend Lock;

private:

    static TCriticalSection *CritSec;
    static unsigned long Count;

};

//------------------------------------------------
//
//  TStaticSync<T>::CritSec
//  TStaticSync<T>::Count
//
//  Instantiate the data members.
//

template <class T> TCriticalSection *TStaticSync<T>::CritSec;
template <class T> unsigned long TStaticSync<T>::Count;

//------------------------------------------------
//
//  TStaticSync<T> constructor
//
//  If this is the first TStaticSync<T> object to be constructed,
//  create the semaphore.
//
//  The copy constructor only has to increment the count, since
//  there will already be at least one TStaticSync<T> object,
//  namely, the one being copied.
//

template <class T> inline TStaticSync<T>::TStaticSync()
{
    if( Count++ == 0 )
        CritSec = new TCriticalSection;
}

template <class T>
inline TStaticSync<T>::TStaticSync( const TStaticSync<T>& )
{
    Count++;
}

//------------------------------------------------
//
//  TStaticSync<T> assignment operator
//

template <class T>
inline const TStaticSync<T>& TStaticSync<T>::operator = ( const TStaticSync<T>& )
{
    return *this;
}

//------------------------------------------------
//
//  TStaticSync<T> destructor
//
//  If this is the only remaining TStaticSync<T> object,
//  destroy the semaphore.
//

template <class T> inline TStaticSync<T>::~TStaticSync()
{
    if( --Count == 0 )
        delete CritSec;
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class TThread;                                                        */
/*                                                                        */
/*  TThread provides a system-independent interface to threads. With      */
/*  suitable underlying implementations the same code can be used under   */
/*  OS/2 and Windows NT.                                                  */
/*                                                                        */
/*  TThread Public Interface                                              */
/*  ------------------------                                              */
/*                                                                        */
/*      Start();                Begins execution of the thread. Returns   */
/*                              the handle of the thread.                 */
/*                                                                        */
/*      Suspend();              Suspends execution of the thread.         */
/*      Resume();               Resumes execution of a suspended thread.  */
/*                                                                        */
/*      Terminate();            Sets an internal flag that indicates      */
/*                              that the thread should exit. The          */
/*                              derived class can check the state of      */
/*                              this flag by calling ShouldTerminate().   */
/*                                                                        */
/*      WaitForExit( unsigned long timeout = NoLimit );                   */
/*                              Blocks the calling thread until the       */
/*                              internal thread exits or until the time   */
/*                              specified by timeout, in milliseconds,    */
/*                              expires. A timeout of NoLimit says to     */
/*                              wait indefinitely.                        */
/*                                                                        */
/*      TerminateAndWait( unsigned long timeout = NoLimit );              */
/*                              Combines the behavior of Terminate() and  */
/*                              WaitForExit(). Sets an internal flag that */
/*                              indicates that the thread should exit     */
/*                              and blocks the calling thread until the   */
/*                              internal thread exits or until the time   */
/*                              specified by timeout, in milliseconds,    */
/*                              expires. A timeout of NoLimit says to     */
/*                              wait indefinitely.                        */
/*                                                                        */
/*      GetStatus();            Gets the current status of the thread.    */
/*                              See TThread::Status for possible values.  */
/*                                                                        */
/*      GetPriority();          Gets the priority of the thread.          */
/*      SetPriority();          Sets the priority of the thread.          */
/*                                                                        */
/*      enum Status;            Identifies the states that the class      */
/*                              can be in.                                */
/*                                                                        */
/*          Created             The class has been created but the        */
/*                              thread has not been started.              */
/*          Running             The thread is running.                    */
/*                                                                        */
/*          Suspended           The thread has been suspended.            */
/*                                                                        */
/*          Finished            The thread has finished execution.        */
/*                                                                        */
/*          Invalid             The object is invalid. Currently this     */
/*                              happens only when the operating system    */
/*                              is unable to start the thread.            */
/*                                                                        */
/*      class ThreadError;      The error class that defines the objects  */
/*                              that are thrown when an error occurs.     */
/*                                                                        */
/*  TThread::ThreadError Public Interface                                 */
/*  -------------------------------------                                 */
/*                                                                        */
/*      enum ErrorType;         Identifies the type of error that         */
/*                              occurred.                                 */
/*                                                                        */
/*          SuspendBeforeRun    The user called Suspend() on an object    */
/*                              before calling Start().                   */
/*                                                                        */
/*          ResumeBeforeRun     The user called Resume() on an object     */
/*                              before calling Start().                   */
/*                                                                        */
/*          ResumeDuringRun     The user called Resume() on a thread that */
/*                              was not Suspended.                        */
/*                                                                        */
/*          SuspendAfterExit    The user called Suspend() on an object    */
/*                              whose thread had already exited.          */
/*                                                                        */
/*          ResumeAfterExit     The user called Resume() on an object     */
/*                              whose thread had already exited.          */
/*                                                                        */
/*          CreationFailure     The operating system was unable to create */
/*                              the thread.                               */
/*                                                                        */
/*          DestroyBeforeExit   The object's destructor was invoked       */
/*                              its thread had exited.                    */
/*                                                                        */
/*          AssignError         An attempt was made to assign to an       */
/*                              object that was not in either the         */
/*                              Created or the Finished state.            */
/*                                                                        */
/*      ErrorType GetErrorType() const;                                   */
/*                              Returns a code indicating the type of     */
/*                              error that occurred.                      */
/*                                                                        */
/*      string why();           Returns a string that describes the       */
/*                              error. Inherited from xmsg.               */
/*                                                                        */
/*  TThread Protected Interface                                           */
/*  ---------------------------                                           */
/*                                                                        */
/*      TThread();              Creates an object of type TThread.        */
/*      virtual ~TThread();     Destroys the object.                      */
/*                                                                        */
/*      const TThread& operator = ( const TThread& );                     */
/*                              The target object must be in either the   */
/*                              Created state or the Finished state. If   */
/*                              so, puts the object into the Created      */
/*                              state. If the object is not in either the */
/*                              Created state or the Finished state it    */
/*                              is an error and an exception will be      */
/*                              thrown.                                   */
/*                                                                        */
/*      TThread( const TThread& );                                        */
/*                              Pts the object into the Created           */
/*                              state, just like the default constructor. */
/*                              Does not copy any of the internal details */
/*                              of the thread being copied.               */
/*                                                                        */
/*      virtual unsigned long Run() = 0;                                  */
/*                              The function that does the work. Calling  */
/*                              Start() creates a thread that begins      */
/*                              executing Run() with the 'this' pointer   */
/*                              pointing to the TThread-based object.     */
/*                                                                        */
/*      int ShouldTerminate() const;                                      */
/*                              Returns a non-zero value to indicate      */
/*                              that Terminate() or TerminateAndWait()    */
/*                              has been called. If this capability is    */
/*                              being used, the thread should call        */
/*                              ShouldTerminate() regularly, and if it    */
/*                              returns a non-zero value the thread       */
/*                              finish its processing and exit.           */
/*                                                                        */
/*  Example                                                               */
/*  -------                                                               */
/*                                                                        */
/*      class TimerThread : public TThread                                */
/*      {                                                                 */
/*      public:                                                           */
/*          TimerThread() : Count(0) {}                                   */
/*      private:                                                          */
/*          unsigned long Run();                                          */
/*          int Count;                                                    */
/*      };                                                                */
/*                                                                        */
/*      unsigned long TimerThread::Run()                                  */
/*      {                                                                 */
/*      // loop 10 times                                                  */
/*      while( Count++ < 10 )                                             */
/*          {                                                             */
/*          Sleep(1000);    // delay 1 second                             */
/*          cout << "Iteration " << Count << endl;                        */
/*          }                                                             */
/*      return 0L;                                                        */
/*      }                                                                 */
/*                                                                        */
/*      int main()                                                        */
/*      {                                                                 */
/*      TimerThread timer;                                                */
/*      timer.Start();                                                    */
/*      Sleep( 20000 );     // delay 20 seconds                           */
/*      return 0;                                                         */
/*      }                                                                 */
/*                                                                        */
/*  Internal States                                                       */
/*  ---------------                                                       */
/*                                                                        */
/*  Created :   the object has been created but its thread has not been   */
/*              started. The only valid transition from this state is     */
/*              to Running, which happens on a call to Start(). In        */
/*              particular, a call to Suspend() or Resume() when the      */
/*              object is in this state is an error and will throw an     */
/*              exception.                                                */
/*                                                                        */
/*  Running:    the thread has been started successfully. There are two   */
/*              transitions from this state:                              */
/*                                                                        */
/*                  When the user calls Suspend() the object moves into   */
/*                  the Suspended state.                                  */
/*                                                                        */
/*                  When the thread exits the object moves into the       */
/*                  Finished state.                                       */
/*                                                                        */
/*              Calling Resume() on an object that is in the Running      */
/*              state is an error and will throw an exception.            */
/*                                                                        */
/*  Suspended:  the thread has been suspended by the user. Subsequent     */
/*              calls to Suspend() nest, so there must be as many calls   */
/*              to Resume() as there were to Suspend() before the thread  */
/*              actually resumes execution.                               */
/*                                                                        */
/*  Finished:   the thread has finished executing. There are no valid     */
/*              transitions out of this state. This is the only state     */
/*              from which it is legal to invoke the destructor for the   */
/*              object. Invoking the destructor when the object is in     */
/*              any other state is an error and will throw an exception.  */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _BIDSCLASS TThread
{

public:

#if defined( __WIN32__ )
    // Windows NT
    enum { NoLimit = -1 };
    typedef HANDLE THandle;
#elif defined( __OS2__ )
    // OS/2
    enum { NoLimit = DCWW_WAIT };
    typedef TID THandle;
#endif

    enum Status { Created, Running, Suspended, Finished, Invalid };

    THandle Start();
    unsigned long Suspend();
    unsigned long Resume();
    void Terminate();
    unsigned long WaitForExit( unsigned long timeout = NoLimit );
    unsigned long TerminateAndWait( unsigned long timeout = NoLimit );

    Status GetStatus() const;

    int GetPriority() const;
    int SetPriority(int);

    class ThreadError : public xmsg
        {
        friend TThread;
        public:
            enum ErrorType
                {
                SuspendBeforeRun,
                ResumeBeforeRun,
                ResumeDuringRun,
                SuspendAfterExit,
                ResumeAfterExit,
                CreationFailure,
                DestroyBeforeExit,
                AssignError
                };
            ErrorType GetErrorType() const;
        private:
            ThreadError(ErrorType type);
            static string MakeString(ErrorType type );
            ErrorType Type;
        };

protected:

    TThread();

    // Copying a thread puts the target into the Created state
    TThread( const TThread& );
    const TThread& operator = ( const TThread& );

    virtual ~TThread();

    int ShouldTerminate() const;

private:

    virtual unsigned long Run() = 0;

    Status CheckStatus() const;

    THandle Handle;
#if defined( __MT__ )
    static void _USERENTRY Execute( void *thread );
#elif defined( __WIN32__ )
    static unsigned long _stdcall Execute( void *thread );
#else
    static void __stdcall Execute( unsigned long );
#endif
#if defined( __WIN32__ )
    DWORD ThreadId;
#else
    ULONG Priority;
#endif
    mutable Status Stat;

    int TerminationRequested;

};

//------------------------------------------------
//
//  TThread::GetStatus()
//
//  If the thread is marked as Running it may have terminated
//  without our knowing it, so we have to check.
//

#if defined( BI_NO_MUTABLE )
inline TThread::Status TThread::GetStatus() const
{
    if( Stat == Running )
        CONST_CAST(TThread *,this)->Stat = CheckStatus();
    return Stat;
}
#else
inline TThread::Status TThread::GetStatus() const
{
    if( Stat == Running )
        Stat = CheckStatus();
    return Stat;
}
#endif

//------------------------------------------------
//
//  TThread::GetPriority()
//
//  Direct OS call under WIN32. Return stored value under OS/2.
//

inline int TThread::GetPriority() const
{
#if defined( __WIN32__ )
    return ::GetThreadPriority(Handle);
#else
    return Priority;
#endif
}

//------------------------------------------------
//
//  TThread::ShouldTerminate()
//
inline int TThread::ShouldTerminate() const
{
    return TerminationRequested;
}

//------------------------------------------------
//
//  TThread::ThreadError::GetErrorType()
//

inline TThread::ThreadError::ErrorType TThread::ThreadError::GetErrorType() const
{
    return Type;
}

#if defined( BI_CLASSLIB_NO_po )
#pragma option -po.
#endif

#endif  // __THREAD_H


