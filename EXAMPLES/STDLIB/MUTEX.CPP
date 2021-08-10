#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
*
* mutex.cpp - Example program for mutex. See Class Reference Section
*
 ***************************************************************************
 *
 * (c) Copyright 1994, 1998 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
* 
**************************************************************************/
//
// This is a code snippet illustrating how to use mutexes to
// synchronize resources in a multi-threaded program.
//

#include <rw/stdmutex.h>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

#ifdef _RWSTD_MULTI_THREAD
//
// An integer shared amongst multiple threads.
//
int I;

//
// A mutex used to synchronize updates to I.
//
_RWSTDMutex I_mutex;

//
// Increment I by one.  Uses a _RWSTDMutex directly.
//

void increment_I ()
{
   I_mutex.acquire();  // Lock the mutex.
   I++;
   I_mutex.release();  // Unlock the mutex.
}

//
// Decrement I by one.  Uses a _RWSTDGuard.
//

void decrement_I ()
{
   _RWSTDGuard guard(I_mutex);  // Acquire the lock on I_mutex.
   --I;
   //
   // The lock on I is released when destructor is called on guard.
   //
}
#endif


int main()
{
#ifdef _RWSTD_MULTI_THREAD
  increment_I();
  decrement_I();
  cout << "Multi Threading enabled" << endl;
#else
  cout << "Multi Threading not enabled" << endl;
#endif
  return 0;
}


