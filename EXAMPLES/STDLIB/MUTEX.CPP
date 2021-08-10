//
// This is a code snippet illustrating how to use mutexes to
// synchronize resources in a multi-threaded program.
//

#include <stdmutex.h>

//
// An integer shared amongst multiple threads.
//
int I;

//
// A mutex used to synchronize updates to I.
//
RWSTDMutex I_mutex;

//
// Increment I by one.  Uses a RWSTDMutex directly.
//

void increment_I ()
{
   I_mutex.acquire();  // Lock the mutex.
   I++;
   I_mutex.release();  // Unlock the mutex.
}

//
// Decrement I by one.  Uses a RWSTDGuard.
//

void decrement_I ()
{
   RWSTDGuard guard(I_mutex);  // Acquire the lock on I_mutex.
   --I;
   //
   // The lock on I is released when destructor is called on guard.
   //
}
