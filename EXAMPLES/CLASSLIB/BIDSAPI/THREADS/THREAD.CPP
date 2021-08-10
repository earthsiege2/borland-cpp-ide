// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
// thread.cpp
//    Demonstrates the container class libraries' implementation
//    of TThread and TCriticalSection.                          
//    It also uses the WINNT's signalling of events to handle   
//    synchronization.                                          
// ---------------------------------------------------------------------------

#include <windows.h>
#include <iostream.h>
#include <classlib/thread.h>

// prevent cout from being interrupted
TCriticalSection CS;                

// prevent process thread from ending too soon
const int NumThreads = 2;
HANDLE Events[NumThreads];

// 
// class Thread
// 
class Thread : public TThread
{
  public:
    Thread( int id) : Id(id), Count(0) {}

  private:
    unsigned long Run();
    int Id;
    int Count;
};

unsigned long Thread::Run()
{
    while (Count++ < 10)
        {
        Sleep(100);         // let other thread have some time
        // don't let cout be interrupted
        TCriticalSection::Lock lock(CS);
        cout << "[Thread" << Id << "] Iteration " << Count << endl;
        }
    SetEvent(Events[Id]);   // Tell main thread I'm done
    return 0;
}

int main()
{
    try {
        int i;
        DWORD ErrCode;

        for (i=0; i<NumThreads; i++)
            {
            Events[i] = CreateEvent(NULL, FALSE, FALSE, NULL);
            if( Events[i] == NULL )
                throw(GetLastError());
            }

        // create threads
        Thread a(0);
        Thread b(1);

        // start the threads
        a.Start();
        b.Start();

        // change priority of threads
        a.SetPriority(THREAD_PRIORITY_NORMAL);
        b.SetPriority(THREAD_PRIORITY_ABOVE_NORMAL);
  
        // threads have now started, wait until they're done.
        ErrCode = WaitForMultipleObjects(NumThreads, Events, TRUE, INFINITE);
        if( ErrCode == DWORD(-1) )
            throw(GetLastError());
  
        // here if done.
        for( i=0; i<NumThreads; i++ )
            CloseHandle(Events[i]);

        cout << "Finished!" << endl;
        }
    catch (DWORD ErrCode)
        {
        // if any error
        cout << "Errcode = " << ErrCode << endl;
        }
    return 0;
}
