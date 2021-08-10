//----------------------------------------------------------------------------
// Borland WinSys Library
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.4  $
//
// Implementation of class TMsgThread. This implements basic behavior for
// threads that own message queues, including mutex locking for the queue
//----------------------------------------------------------------------------
#include <winsys/pch.h>
#if !defined(WINSYS_MSGTHRED_H)
# include <winsys/msgthred.h>
#endif

DIAG_DEFINE_GROUP(MsgThreads,1,0);

//
// Attach to the current running thread. This is often the initial process
// thread, or even the only thread for non-threaded systems.
//
#if defined(BI_MULTI_THREAD_RTL)  // No threads without RTL support
TMsgThread::TMsgThread(TCurrent c)
:
  TThread(c),
  UseMutex(false),  // Default for primary thread is single-threaded
#else
TMsgThread::TMsgThread(TCurrent /*c*/)
:
#endif
  MessageLoopResult(0),
  BreakMessageLoop(false),
  LoopRunning(false)
{
}

#if defined(BI_MULTI_THREAD_RTL)  // No real threads without RTL support
//
// Create a thread.
// The thread is in a paused-state.
//
TMsgThread::TMsgThread()
:
  TThread(),
  MessageLoopResult(0),
  BreakMessageLoop(false),
  LoopRunning(false),
  UseMutex(true)  // Default for created thread is multi-threaded
{
}
#endif

//
// General message loop: retrieve and process messages from the thread's
// message queue using PumpWaitingMessages() until BreakMessageLoop becomes
// true. Catch exceptions to post a quit message and cleanup before resuming.
//
// Call IdleAction() when there are no messages
//
int
TMsgThread::MessageLoop()
{
  long idleCount = 0;
  MessageLoopResult = 0;
  try {
    while (!BreakMessageLoop) {      
      if (!IdleAction(idleCount++))
        ::WaitMessage();             // allow system to go idle
      if (PumpWaitingMessages())     // pumps any waiting messages
        idleCount = 0;
    }
  }
  catch (...) {
    ::PostQuitMessage(-1);
    BreakMessageLoop = false;
    throw;
  }
  BreakMessageLoop = false;
  return MessageLoopResult;
}

//
// Called each time there are no messages in the queue. Idle count is
// incremented each time, & zeroed when messages are pumped. Return
// whether or not more processing needs to be done.
//
bool
#if defined(__TRACE)
TMsgThread::IdleAction(long idleCount)
#else
TMsgThread::IdleAction(long /*idleCount*/)
#endif
{
  TRACEX(MsgThreads, 1, "TMsgThread::IdleAction() called @" << (void*)this <<
                        " idleCount " << idleCount);
  return false;
}

//
// Called for each message that is pulled from the queue, to perform all
// translation & dispatching.
//
// Return true to drop out of pump
//
bool
TMsgThread::ProcessMsg(MSG& msg)
{
  // Translate the message & dispatch it.TMsgThread
  //
  ::TranslateMessage(&msg);
  ::DispatchMessage(&msg);
//  ResumeThrow();

  return false;
}

//
// Inner message loop: retrieve and processe messages from the OWL
// application's message queue until it is empty. Set BreakMessageLoop if a
// WM_QUIT passes thru.
//
// Call ProcessAppMsg() for each message to allow special pre-handling of the
// message
//
bool
TMsgThread::PumpWaitingMessages()
{
  MSG  msg;
  bool foundOne = false;

  while (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
    foundOne = true;
    if (msg.message == WM_QUIT) {
      BreakMessageLoop = true;
      MessageLoopResult = msg.wParam;
      ::PostQuitMessage(msg.wParam);  // make sure all loops exit
      break;
    }
    if (ProcessMsg(msg))
      return true;
  }
  return foundOne;
}

//
// Flush all real messages from the message queue
//
void
TMsgThread::FlushQueue()
{
  MSG msg;
  while (::PeekMessage(&msg,0,0,0,PM_NOYIELD|PM_REMOVE)
         && msg.message != WM_PAINT)
    ;
}

//
// Run this message thread, return when the message queue quits
//
// Initialize instances. Run the thread's message loop. Each of the virtual
// functions called are expected to throw an exception if there is an error.
//
// Exceptions that are not handled, i.e. status remains non-zero, are
// propagated out of this function. Msg queue is still flushed & TermInstance
// called.
//
int
TMsgThread::Run()
{
  int status;
  try {
    InitInstance();
    LoopRunning = true;
    status = MessageLoop();
  }
  catch (...) {
    LoopRunning = false;
    FlushQueue();
    TermInstance(status);
    throw;
  }

  LoopRunning = false;
  FlushQueue();
  return TermInstance(status);
}

//
// Handle initialization for each executing instance of the msg thread
// Derived classes can override this to perform initialization for each
// instance.
//
void
TMsgThread::InitInstance()
{
  TRACEX(MsgThreads, 1, "TMsgThread::InitInstance() called @" << (void*)this);

  // Override to perform initialization prior to running
  // Call TMsgThread::InitInstance() before body
}

//
// Handle termination for each executing instance of the msg thread. Called
// at the end of a Run() with the final return status.
//
int
TMsgThread::TermInstance(int status)
{
  TRACEX(MsgThreads, 1, "TMsgThread::TermInstance() called @" << (void*)this);

  // Override to perform termination cleanup after running
  // Call TMsgThread::TermInstance(status) after body

  return status;
}
