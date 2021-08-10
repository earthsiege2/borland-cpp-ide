//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//
// Base window classes for the multi-thread GDI demo windows
//----------------------------------------------------------------------------
#if !defined(DEMOBASE_H)
#define DEMOBASE_H

#include <owl/mdichild.h>
#include <classlib/thread.h>

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

//
// class TWorkerThread
// ~~~~~ ~~~~~~~~~~~~~
// Provides the fundamental control mechanism for running worker threads
// and synchronizing them with OWL applications. It uses TThread for its basic
// thread management, but uses a different mechanism for terminating threads,
// going through an event semaphore rather than a simple flag. This is needed
// so that the worker thread can check both the event semaphore and OWL's
// internal message queue synchronization semaphore.
// 
// The worker thread should call Sync() which will block until the OWL
// synchronization semaphore is available or until the event semaphore is
// triggered. If the thread was unblocked by the event semaphore Sync()
// returns a non-zero value, and the thread should exit. If the thread was
// unblocked by the synchronization semaphore the thread owns a lock on that
// semaphore.
//
class TWorkerThread : public TThread
{
  public:
    TWorkerThread();

    void Terminate();
    ulong TerminateAndWait(ulong timeout = NoLimit);

  protected:
    TEventSemaphore Done;  // Event that signals this thread to exit
};

//----------------------------------------------------------------------------

//
inline TWorkerThread::TWorkerThread()
:
  Done(false, false)  //Done event:  not manual-reset, not initally triggered
{
}

//
// Terminate this thread by settting its done event to signal it to exit
//
inline void TWorkerThread::Terminate()
{
  Done.Set();
}

//
// Need to override this non-virtual to use our Terminate()
//
inline ulong TWorkerThread::TerminateAndWait(ulong timeout)
{
  Terminate();
  return WaitForExit(timeout);
}

//----------------------------------------------------------------------------

//
// class TBaseDemoWindow
// ~~~~~ ~~~~~~~~~~~~~~~
// has been modified from the version in the GDIDEMO example. It now has
// TWorkerThread as a base class. It overrides TWorkerThread::Run() (which is
// pure virtual and inherited from TThread) to implement a worker loop which
// calls TBaseDemoWindow::ClockTick() periodically. Derived classes should
// override ClockTick() to perform their data acquisition and logging.
//
// In this case, the modifications to the GDIDEMO example are trivial:
// The constructor for the derived class should call Start() after the object
// has been fully constructed.
//
class TBaseDemoWindow : public TWindow, private TWorkerThread {
  public:
    TBaseDemoWindow();

    virtual TApplication* GetApplication() const;

    bool CanClose();

    TThread::THandle Start();

  private:
    int Run();
    virtual void ClockTick() = 0;

    TSemaphoreSet Sync;  // Set of semaphore objects to sync this with app

  DECLARE_CASTABLE;
};

#endif
