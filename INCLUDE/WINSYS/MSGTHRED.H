//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.12  $
//
// Definition of message queue oriented thread class support. Degenerates to a
// simple message queue owner under non-threaded environments
//----------------------------------------------------------------------------
#if !defined(WINSYS_MSGTHRED_H)
#define WINSYS_MSGTHRED_H

#if !defined(WINSYS_DEFS_H)
# include <winsys/defs.h>
#endif
#if defined(BI_MULTI_THREAD) && !defined(CLASSLIB_THREAD_H)
# include <classlib/thread.h>
#endif
#if !defined(WINSYS_WSYSINC_H)
#  include <winsys/wsysinc.h>
#endif

#if defined(BI_NAMESPACE)
namespace ClassLib {
#endif

//
// class TMsgThread
// ~~~~~ ~~~~~~~~~~
#if defined(BI_MULTI_THREAD_RTL)
class _WSYSCLASS TMsgThread :  public TThread
{
#else
class _WSYSCLASS TMsgThread
{
  public:
    enum TCurrent {Current};
#endif

  public:
    TMsgThread(TCurrent);

    // Message queue functions
    //
    virtual int      MessageLoop();
    virtual bool     IdleAction(long idleCount);
    virtual bool     ProcessMsg(MSG& msg);

    bool             PumpWaitingMessages();
    void             FlushQueue();

    // Is this queue thread running its message loop?
    //
    bool             IsRunning() const;

    // Message queue thread synchronization mechanism. Real multi-threading
    // requires compiler & RTL support (-MT)
    //
#if defined(BI_MULTI_THREAD_RTL)
    void    EnableMultiThreading(bool enable);
    TMutex* GetMutex();

    class _WSYSCLASS TQueueLock {
      public:
        TQueueLock(TMsgThread& app);
       ~TQueueLock();
        void Release(bool relinquish = false);
      private:
        _TCHAR Lock[sizeof(TMutex::TLock)];
        bool Locked;
    };
#endif

  protected:
#if defined(BI_MULTI_THREAD_RTL)  // No real threads without RTL support
    TMsgThread();
#endif

    // Override this for created threads, app thread is Run() from OwlMain
    //
    virtual int      Run();

    virtual void     InitInstance();
    virtual int      TermInstance(int status);

    bool          BreakMessageLoop;     // Message loop is broken via WM_QUIT
    int           MessageLoopResult;    // Return value from message loop

    bool          LoopRunning;          // Track if the loop is running

#if defined(BI_MULTI_THREAD_RTL)
    class _WSYSCLASS TAppMutex {
      public:
        TAppMutex();
       ~TAppMutex();
        TMutex* GetMutex();
      private:
        char* Mutex[sizeof(TMutex)];
    };

    TAppMutex     Mutex;                // Mutex to prevent multiple threads
                                        // from processing messages at the
                                        // same time.
  private:
    bool          UseMutex;
#endif
};

#if defined(BI_NAMESPACE)
}     // namespace ClassLib 
#endif

//----------------------------------------------------------------------------
// Inline implementations

//
// Return true if the thread is currently running.
//
inline bool TMsgThread::IsRunning() const
{
  return LoopRunning;
}

#if defined(BI_MULTI_THREAD_RTL)

# if !defined(WINSYS_SYSTEM_H)
#   include <winsys/system.h>  
# endif

//
// Enable/disable the use of the mutex to synchronize access to the msg queue.
// Only when enabled, will the TMsgThread lock its msg queue mutex.
//
inline void TMsgThread::EnableMultiThreading(bool enable)
{
  UseMutex = enable ? TSystem::SupportsThreads() : false;
}

//
// Get this msg thread's mutex. Return 0 if mutexes are not supported, or are
// not enabled for this thread.
//
inline TMutex* TMsgThread::GetMutex()
{
  return UseMutex ? Mutex.GetMutex() : 0;
}

//
// The mutex is always constructed/destructed if the system supports threads
//
inline TMsgThread::TAppMutex::TAppMutex()
{
  if (TSystem::SupportsThreads()) {
#if defined(BI_NAMESPACE)
    ClassLib::new(Mutex) TMutex;
#else
    new(Mutex) TMutex;
#endif
  }
}

//
inline TMsgThread::TAppMutex::~TAppMutex()
{
  if (TSystem::SupportsThreads())
#if defined(BI_COMP_MSC)  
    REINTERPRET_CAST(TMutex*,Mutex)->~TMutex();
//    ((TMutex*)Mutex)->TMutex::~TMutex();
#else
    REINTERPRET_CAST(TMutex*,Mutex)->TMutex::~TMutex();
#endif
}

//
// Get the apps mutex. Return 0 if mutexs are not supported, or are not enabled
// for this app.
//
inline TMutex* TMsgThread::TAppMutex::GetMutex()
{
  return REINTERPRET_CAST(TMutex*,Mutex);
}

//
// Only lock if the mutex is available. Do nothing otherwise. Use placement
// new to construct the real lock in place.
//
inline TMsgThread::TQueueLock::TQueueLock(TMsgThread& app)
{
  TMutex* appMutex = app.GetMutex();
  Locked = appMutex ? true : false;
  if (Locked)
#if defined(BI_NAMESPACE)
    ClassLib::new(Lock) TMutex::TLock(*appMutex);
#else
    new(Lock) TMutex::TLock(*appMutex);
#endif
}

//
// Destruct the real lock if it was constructed (locked)
//
inline TMsgThread::TQueueLock::~TQueueLock()
{
  if (Locked)
#if defined(BI_COMP_MSC)
    REINTERPRET_CAST(TMutex::TLock*,Lock)->~TLock();
#else
    REINTERPRET_CAST(TMutex::TLock*,Lock)->TMutex::Lock::~Lock();
#endif
}

//
// Release the real lock if it was locked
//
inline void TMsgThread::TQueueLock::Release(bool relinquish)
{
  if (Locked)
    REINTERPRET_CAST(TMutex::TLock*,Lock)->Release(relinquish);
}

#endif  // BI_MULTI_THREAD_RTL

#endif  // WINSYS_MSGTHRED_H
