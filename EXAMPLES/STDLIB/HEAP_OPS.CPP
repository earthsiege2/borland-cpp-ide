#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * heap_ops.cpp - Example program for heap operations. 
 *                See Class Reference Section
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
#include <algorithm>
#include <vector>
#include <functional>

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

   int d1[4] = {1,2,3,4};
   int d2[4] = {1,3,2,4};				   
   //
   // Set up two vectors.
   //
   vector<int,allocator<int> > v1(d1+0, d1+4), v2(d2+0, d2+4);
   //
   // Make heaps.
   //
   make_heap(v1.begin(), v1.end());
   make_heap(v2.begin(), v2.end(), less<int>());
   //
   // v1 = (4,x,y,z)  and  v2 = (4,x,y,z)
   //
   // Note that x, y and z represent the remaining values in the
   // container (other than 4).  The definition of the heap and heap
   // operations  does not require any particular ordering
   // of these values.
   //
   // Copy both vectors to cout.
   //
   ostream_iterator<int,char,char_traits<char> > out(cout," ");
   copy(v1.begin(), v1.end(), out);
   cout << endl;
   copy(v2.begin(), v2.end(), out);
   cout << endl;
   //
   // Now let's pop.
   //
   pop_heap(v1.begin(), v1.end());
   pop_heap(v2.begin(), v2.end(), less<int>());
   //
   // Copy both vectors to cout.
   //
   copy(v1.begin(), v1.end(), out);
   cout << endl;
   copy(v2.begin(), v2.end(), out);
   cout << endl;
   // 
   // And push.
   //
   push_heap(v1.begin(), v1.end());
   push_heap(v2.begin(), v2.end(), less<int>());
   //
   // Copy both vectors to cout.
   //
   copy(v1.begin(),v1.end(),out);
   cout << endl;
   copy(v2.begin(),v2.end(),out);
   cout << endl;
   //
   // Now sort those heaps.
   //
   sort_heap(v1.begin(), v1.end());
   sort_heap(v2.begin(), v2.end(), less<int>());
   // 
   // Copy both vectors to cout.
   //
   copy(v1.begin(), v1.end(), out);
   cout << endl;
   copy(v2.begin(), v2.end(), out);
   cout << endl;

   return 0;
}
   
