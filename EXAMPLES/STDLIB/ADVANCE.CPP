#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * advance.cpp - Example program for advancing iterators. 
 *               See Class Reference Section
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
#include <iterator>
#include <list>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
   using namespace std;
#endif 
   //
   // Initialize a list using an array.
   //
   int arr[6] = {3,4,5,6,7,8};
   list<int,allocator<int> > l(arr+0, arr+6);
   //
   // Declare a list iterator, s.b. a ForwardIterator.
   //
   list<int,allocator<int> >::iterator itr = l.begin();
   //
   // Output the original list.
   //
   cout << "For the list: ";
   copy(l.begin(),l.end(),ostream_iterator<int,char,char_traits<char> >(cout," "));
   cout << endl << endl;
   cout << "When the iterator is initialized to l.begin()," 
        << endl << "it points to " << *itr << endl << endl;
   //
   // operator+ is not available for a ForwardIterator, so use advance.
   //
   advance(itr, 4);
   cout << "After advance(itr,4), the iterator points to " << *itr << endl;

   return 0;
}
