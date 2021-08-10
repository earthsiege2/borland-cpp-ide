#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * exceptn.cpp - Illustrate the use of Standard exceptions.
 *    Section 13
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

#include <string>
#include <stdexcept>
 
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
    
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

#ifdef _RWSTD_NO_EXCEPTIONS
int main ()
{
    cout << "Your compiler doesn't support exceptions!" << endl;
    return 0;
}
#else

// A simple class to demonstrate throwing an exception
static void f() { throw runtime_error("a runtime error"); }

int main ()
{
  string s;
  
  // First we'll try to incite and catch an exception from
  // the standard library string class.
  // We'll try to replace at a position that is non-existant.
  //
  // By wrapping the body of main in a try-catch block we can be
  // assured that we'll catch all exceptions in the exception hierarchy.
  // You can simply catch exception as is done below, or you can catch
  // each of the exceptions in which you have an interest.
  try
  {
    s.replace(100,1,1,'c');
  }
  catch (const exception& e)
  {
    cout << "Got an exception: " << e.what() << endl;
  }

  // Now we'll throw our own exception using the function 
  // defined above.
  try
  {
    f();
  }
  catch (const exception& e)
  {
    cout << "Got an exception: " << e.what() << endl;
  }
 
 return 0;
}
#endif /*_RWSTD_NO_EXCEPTIONS*/
