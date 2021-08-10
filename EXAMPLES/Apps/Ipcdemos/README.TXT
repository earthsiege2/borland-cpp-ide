//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------

TITLE:
  IPCDEMOS

DESCRIPTION:
  Demonstrates interprocess communication in Win32.

DEMONSTRATES:
  + TThread
  + TObject derived classes: TEvent, TMutex, TSharedMem, TSemaphore
  + Exception derived classes
  + Shared memory between 32-bit processes
  + Thread synchronization
  + Exception handling

COMMENTS:
  
  This program along with the Client.pof project, demonstrate a number
  of topics in Win32 programming. Threads, Events, Mutexes, and Shared
  memory are all used to provide communication between this monitor and
  it's clients, see IPCThrd.cpp.

  To Run, compile this project and the Client.cpp project.  Run one
  instance of the monitor and then run several instances of the client.
  You can switch between clients by clicking on the Client's window or
  by selecting it from the Client menu in the monitor.

  Topics Covered:

    Interprocess Communication
    Threads
    Events
    Mutexes
    Shared Memory
    Single instance EXE.

