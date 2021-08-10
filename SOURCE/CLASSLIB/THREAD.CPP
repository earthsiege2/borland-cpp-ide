//----------------------------------------------------------------------------
// Borland Class Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.8  $
//
// TThread class implementation
//----------------------------------------------------------------------------
#include <classlib/pch.h>
#include <classlib/thread.h>
#include <services/checks.h>
#include <classlib/pointer.h>
#include <process.h>
#include <stdlib.h>

DIAG_DEFINE_GROUP(Threads,1,0);

//----------------------------------------------------------------------------
// Semaphores Win32
//
#if defined(BI_PLAT_WIN32)

//----------------------------------------
// TMutex WIN32

void TMutex::Release()
{
  ::ReleaseMutex(*this);
}

//----------------------------------------
// TCountedSemaphore WIN32

void TCountedSemaphore::Release()
{
  ::ReleaseSemaphore(*this, 1, 0);  
}

//----------------------------------------
// TEventSemaphore WIN32

void TEventSemaphore::Release()
{
  // Events don't need to be released
}

//----------------------------------------
// TSemaphoreSet & its TLock for Win32

//
TSemaphoreSet::TSemaphoreSet(const TSemaphore* sems[], int size)
:
  Sems(0)
{
  int count = 0;
  if (sems)
    while (sems[count])
      count++;
  Count = count;
  Size = size >= 0 ? size : count;
  if (Size) {
    Sems = new TSemaphorePtr[Size];
    int i = 0;
    if (sems)
      for (; i < Count; i++)
        Sems[i] = sems[i];
    for (; i < Size; i++)
      Sems[i] = 0;
  }
}

//
TSemaphoreSet::~TSemaphoreSet()
{
  delete[] Sems;
}

//
void TSemaphoreSet::Add(const TSemaphore& sem)
{
  if (Count < Size)
    Sems[Count++] = &sem;
}

//
void TSemaphoreSet::Remove(const TSemaphore& sem)
{
  CHECK(Count <= Size);
  for (int i = 0; i < Count; i++)
    if (Sems[i] == &sem) {
      for (int j = i; j < Count-1; j++)  // Shift rest down to keep packed
        Sems[j] = Sems[j+1];
      Sems[Count-1] = 0;
      return;
    }
}

void TSemaphoreSet::Release(int index)
{
  if (index >= 0)
    CONST_CAST(TSemaphore*,Sems[index])->Release();
  else
    for (int i = 0; i < Count; i++)
      CONST_CAST(TSemaphore*,Sems[i])->Release();
}

static HANDLE* newHandles(const TSemaphoreSet& set)
{
  HANDLE* handles = new HANDLE[set.GetCount()];
  for (int i = 0; i < set.GetCount(); i++) {
    CHECK(set[i]);
    handles[i] = *set[i];  // Assumes non-0 since i is in set range
  }
  return handles;
}

//
TSemaphoreSet::TLock::TLock(const TSemaphoreSet& set, TWaitWhat wait,
                            ulong timeOut, bool alertable)
:
  Set(0)
{
  TAPointer<THandle> handles = newHandles(set);

  if (InitLock(set.Count, wait,
               ::WaitForMultipleObjectsEx(set.Count, handles, wait, timeOut, alertable)))
    Set = &set;
}

//
TSemaphoreSet::TLock::TLock(ulong msgMask, const TSemaphoreSet& set,
                            TWaitWhat wait, ulong timeOut)
{
  TAPointer<THandle> handles = newHandles(set);

  if (InitLock(set.Count, wait,
               ::MsgWaitForMultipleObjects(set.Count, handles, wait, timeOut, msgMask)))
    Set = &set;
}

//
// Init the Set and Locked members after a system wait call
//
bool TSemaphoreSet::TLock::InitLock(int count, TWaitWhat wait, int index)
{
  if (index >= WAIT_OBJECT_0 && index < WAIT_OBJECT_0+count ||
      index >= WAIT_ABANDONED_0 && index < WAIT_ABANDONED_0+count)
  {
    if (wait == WaitAny) {
      if (index >= WAIT_ABANDONED_0)
        index -= WAIT_ABANDONED_0;
      Locked = index;      // Just this one is locked
    }
    else
      Locked = AllAquired;         // They are all locked
    return true;
  }
  else if (index == WAIT_OBJECT_0+count)
    Locked = MsgWaiting;
  else if (index == WAIT_TIMEOUT)
    Locked = TimedOut;
  else if (index == WAIT_IO_COMPLETION)
    Locked = IoComplete;
  return false;
}

//
TSemaphoreSet::TLock::~TLock()
{
  Release();
}

//
void TSemaphoreSet::TLock::Release(bool relinquish)
{
  if (Set) {
    CONST_CAST(TSemaphoreSet*,Set)->Release(Locked);
    if (relinquish)
      Set = 0;
  }
}

//----------------------------------------------------------------------------
// Semaphores OS/2
//
#elif defined(BI_PLAT_OS2)

#endif

//----------------------------------------------------------------------------
// TThread Win32 & OS/2

//
// TThread constructors
//
TThread::TThread()
:
#if defined(BI_PLAT_WIN32)
  ThreadId(0),
#elif defined(BI_PLAT_OS2)
  Priority(0),
#endif
  Handle(0),
  Stat(Created),
  TerminationRequested(0),
  Attached(false)
{
}

//
// Attach to a running thread
//
TThread::TThread(TCurrent)
:
#if defined(BI_PLAT_WIN32)
  ThreadId(::GetCurrentThreadId()),
#elif defined(BI_PLAT_OS2)
  Priority(0),
#endif
  Handle(0),
  Stat(Running),
  TerminationRequested(0),
  Attached(true)
{
  ::DuplicateHandle(::GetCurrentProcess(), ::GetCurrentThread(),
                    ::GetCurrentProcess(), &Handle,
                    0, false, DUPLICATE_SAME_ACCESS);
}

//
//
//
TThread::TThread(const TThread&)
:
#if defined(BI_PLAT_WIN32)
  ThreadId(0),
#elif defined(BI_PLAT_OS2)
  Priority(0),
#endif
  Handle(0),
  Stat(Created),
  TerminationRequested(0),
  Attached(false)
{
}

//
// TThread assignment operator
//
// Used when assigning derived objects. Attempting to assign from a running
// object is an error, since the data fields in the running object can be
// changing asynchronously.
//
const TThread& TThread::operator =(const TThread& thread)
{
  switch (GetStatus()) {
    case Created:
    case Suspended:
    case Finished: {
      if (this != &thread) {
        Handle = 0;
#if defined(BI_PLAT_WIN32)
        ThreadId = 0;
#elif defined(BI_PLAT_OS2)
        Priority = 0;
#endif
        Stat = Created;
        TerminationRequested = false;
        Attached = false;
      }
      return *this;
    }
    default:
      throw TThreadError(TThreadError::AssignError);
  }
#if defined(BI_COMP_MSC)
  return *this;     // Bogus return to make MSVC happy
#endif
}

//
// TThread destructor
//
// If the thread hasn't finished, destroying its control object is an error.
//
TThread::~TThread()
{
  if (!Attached && GetStatus() != Finished)
    throw TThreadError(TThreadError::DestroyBeforeExit);
#if defined(BI_PLAT_WIN32)
  ::CloseHandle(Handle);
#elif defined(BI_PLAT_OS2)
#endif
}

//
// Starts the thread executing. The actual call depends on the operating system.
// After the system call we check status.
//
TThread::THandle TThread::Start()
{
  // If this thread is already started, just return the current handle
  //
  if (Handle)
    return Handle;

#if defined(BI_PLAT_WIN32)
# if defined(BI_MULTI_THREAD_RTL)
  Handle = (HANDLE)::_beginthreadNT(&TThread::Execute, 4096, this, 0, 0, &ThreadId);
# else
  Handle = ::CreateThread(0, 0, &TThread::Execute, this, 0, &ThreadId);
# endif

#elif defined(BI_PLAT_OS2)
# if defined(BI_MULTI_THREAD_RTL)
  Handle = ::_beginthread(&TThread::Execute, 4096, this);
# else
  APIRET res =
    ::DosCreateThread(&Handle,
                      (void (__syscall*)(ulong))&TThread::Execute,
                      REINTERPRET_CAST(ulong,this),
                      FALSE,
                      4000);
# endif
#endif

  if (Handle) {
    TRACEX(Threads, 1, "Thread started [id:" << Handle << ']');
    Stat = Running;
  }
  else {
    TRACEX(Threads, 2, "Thread failed to start");
    Stat = Invalid;
    throw TThreadError(TThreadError::CreationFailure);
  }

  return Handle;
}

//
// It's an error to try to suspend a thread that hasn't been started or that
// has already terminated.
//
ulong TThread::Suspend()
{
  switch (GetStatus()) {
    case Created:
      TRACEX(Threads, 2, "Illegal Created thread suspension [id:" << Handle << ']');
      throw TThreadError(TThreadError::SuspendBeforeRun);
    case Finished:
      TRACEX(Threads, 2, "Illegal Finished thread suspension [id:" << Handle << ']');
      throw TThreadError(TThreadError::SuspendAfterExit);
    default:
#if defined(BI_PLAT_WIN32)
      ulong res = ::SuspendThread(Handle);
      if (res < MAXIMUM_SUSPEND_COUNT)  // Else a problem
        Stat = Suspended;
#elif defined(BI_PLAT_OS2)
      ulong res = ::DosSuspendThread(Handle);
      Stat = Suspended;  
#endif
      TRACEX(Threads, 0, "Thread suspended [id:" << Handle << ", Count:" << res << ']');
      return res;
  }
}

//
// It's an error to try to resume a thread that isn't suspended.
//
ulong TThread::Resume()
{
  switch (GetStatus()) {
    case Created:
      TRACEX(Threads, 2, "Illegal Created thread resumption [id:" << Handle << ']');
      throw TThreadError(TThreadError::ResumeBeforeRun);
    case Running:
      TRACEX(Threads, 2, "Illegal Running thread resumption [id:" << Handle << ']');
      throw TThreadError(TThreadError::ResumeDuringRun);
    case Finished:
      TRACEX(Threads, 2, "Illegal Finished thread resumption [id:" << Handle << ']');
      throw TThreadError(TThreadError::ResumeAfterExit);
    default:
#if defined(BI_PLAT_WIN32)
      ulong res = ::ResumeThread(Handle);
#elif defined(BI_PLAT_OS2)
      ulong res = ::DosResumeThread(Handle);
#endif
      TRACEX(Threads, 0, "Thread resumed [id:" << Handle << ", Count:" << res << ']');
      if (res == 0)
        Stat = Running;
      return res;
    }
}

//
// Mark the thread for termination.
//
void TThread::Terminate()
{
  TRACEX(Threads, 1, "Thread termination requested [handle:" << Handle << ']');
  TerminationRequested = true;
}

//
// Block until the thread terminates.
//
// IMPORTANT: the meaning of the 'timeout' parameter is different for NT and
// OS/2. Under NT it specifies how long to wait for termination. Under OS/2 it
// specifies whether to wait or to return immediately if the thread hasn't
// terminated.
//
ulong TThread::WaitForExit(ulong timeout)
{
  TRACEX(Threads, 1, "Waiting for thread exit [id:" << Handle << ']');
  if (Stat == Running)
#if defined(BI_PLAT_WIN32)
    return ::WaitForSingleObject(Handle, timeout);
#elif defined(BI_PLAT_OS2)
    return ::DosWaitThread(&Handle, timeout);
#endif
  else
    return (ulong)-1;
}

//
// See note for WaitForExit().
//
ulong TThread::TerminateAndWait(ulong timeout)
{
  Terminate();
  return WaitForExit(timeout);
}

//
// Set the thread's priority.
//
int TThread::SetPriority(int pri)
{
  TRACEX(Threads, 1, "Thread priority changed to " << pri <<
                     " [id:" << Handle << ']');
#if defined(BI_PLAT_WIN32)
  return ::SetThreadPriority(Handle, pri);

#elif defined(BI_PLAT_OS2)
  APIRET res = ::DosSetPriority(PRTYS_THREAD, PRTYC_NOCHANGE, pri-Priority,
                                Handle);
  if (res != 0)
    Priority = pri;
  return res;
#endif
}

//
//
//
int
TThread::Run()
{
  TRACEX(Threads, 1, "Illegal Run() on base TThread [id:" << Handle << ']');
  return -1;
}

//
// Run the thread. This static function is given as the thread start address,
// with 'this' thread object passed as the param. Invoke the Run() method on
// the thread
//
#if defined(BI_MULTI_THREAD_RTL)
void _USERENTRY TThread::Execute(void* thread)
{
  STATIC_CAST(TThread*,thread)->Run();
  STATIC_CAST(TThread*,thread)->Stat = Finished;
}
#elif defined(BI_PLAT_WIN32)
ulong _stdcall TThread::Execute(void* thread)
{
  int code = STATIC_CAST(TThread*,thread)->Run();
  STATIC_CAST(TThread*,thread)->Stat = Finished;
  return code;
}
#elif defined(BI_PLAT_OS2)
void __stdcall TThread::Execute(ulong thread)
{
  REINTERPRET_CAST(TThread*,thread)->Run();
  REINTERPRET_CAST(TThread*,thread)->Stat = Finished;
}
#endif

//
// Alternative to returning from Run(). Called from within the thread that
// wants to exit early.
//
void
TThread::Exit(ulong code)
{
  Stat = Finished;
#if defined(BI_PLAT_WIN32)
  ::ExitThread(code);
#elif defined(BI_PLAT_OS2)
#endif
}

//
// Call only when Stat claims that the thread is Running.
//
TThread::TStatus
TThread::CheckStatus() const
{
#if defined(BI_PLAT_WIN32)
  uint32 code;
  ::GetExitCodeThread(Handle, &code);
  if (code == STILL_ACTIVE)
#elif defined(BI_PLAT_OS2)
  if (::DosWaitThread(CONST_CAST(THandle*,&Handle), DCWW_NOWAIT) == ERROR_THREAD_NOT_TERMINATED)
#endif
    return Running;
  else
    return Finished;
}

//----------------------------------------------------------------------------

//
// TThread::TThreadError constructor
//
TThread::TThreadError::TThreadError(TErrorType type)
:
  xmsg(MakeString(type)),
  Type(type)
{
}

//
// TThread::TThreadError::MakeString()
//
// Translates an error code into a string.
//
string TThread::TThreadError::MakeString(TErrorType type)
{
  static char* Names[] = {
    "Suspend() before Run()",
    "Resume() before Run()",
    "Resume() during Run()",
    "Suspend() after Exit()",
    "Resume() after Exit()",
    "creation failure",
    "destroyed before Exit()",
    "illegal assignment",
    "Multithreaded Runtime not selected",
  };
  string Msg;
  Msg.reserve(40);
  Msg = "Error[thread]: ";
  Msg += Names[type];
  return Msg;
}
