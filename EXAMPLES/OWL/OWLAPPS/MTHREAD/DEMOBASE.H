//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
// Base window classes for the multi-thread GDI demo windows
//----------------------------------------------------------------------------
#ifndef __DEMOBASE_H
#define __DEMOBASE_H

#include <owl\mdichild.h>
#include <classlib\thread.h>

#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))

//----------------------------------------------------------------------------

// class TOWLThread provides the fundamental control mechanism for
// running data logging threads and synchronizing them with OWL
// applications. It uses TThread for its basic thread management,
// but uses a different mechanism for terminating threads, going
// through an event semaphore rather than a simple flag. This is
// needed so that the data logging thread can check both the event
// semaphore and OWL's internal synchronization semaphore.
// 
// The data logging thread should call Synch() which will block
// until the OWL synchronization semaphore is available or until
// the event semaphore is triggered. If the thread was unblocked
// by the event semaphore Synch() returns a non-zero value, and
// the thread should exit. If the thread was unblocked by the
// synchronization semaphore the thread owns a lock on that
// semaphore.

class TOWLThread : public TThread
{
  public:
    TOWLThread();
    ~TOWLThread();

    void Terminate();
    unsigned long WaitForExit( unsigned long timeout = NoLimit );
    unsigned long TerminateAndWait( unsigned long timeout = NoLimit );

    virtual TApplication *GetApplication() const = 0;

  protected:

    int Synch();

  private:

    HANDLE Done;
};

//----------------------------------------------------------------------------

inline TOWLThread::TOWLThread()
{
  Done = ::CreateEvent( 0, FALSE, FALSE, 0 );
}

inline TOWLThread::~TOWLThread()
{
  ::CloseHandle(Done);
}

inline void
TOWLThread::Terminate()
{
  ::SetEvent(Done);
}

inline unsigned long
TOWLThread::WaitForExit( unsigned long timeout )
{
  return TThread::WaitForExit(timeout);
}

inline unsigned long
TOWLThread::TerminateAndWait( unsigned long timeout )
{
  Terminate();
  return WaitForExit(timeout);
}

//----------------------------------------------------------------------------

// class TBaseDemoWindow has been modified from the version in
// the GDIDEMO example. It now has TOWLThread as a base class.
// It overrides TOWLThread::Run() (which is pure virtual and
// inherited from TThread) to implement a data logging loop
// which calls TBaseDemoWindow::DoRun() periodically. Derived
// classes should override DoRun() to perform their data
// acquisition and logging.

// In this case, the modifications to the GDIDEMO example are
// trivial: simply rename the TimerTick() function to DoRun().
// The constructor for the derived class should call Start()
// after the object has been fully constructed.

class TBaseDemoWindow : public TWindow, private TOWLThread {
  public:
    TBaseDemoWindow() : TWindow(0, 0, 0) {}

    virtual TApplication *GetApplication() const;

    BOOL CanClose();

    HANDLE Start();

  private:
    unsigned long Run();
    virtual void DoRun() = 0;

  DECLARE_CASTABLE;
};

#endif
