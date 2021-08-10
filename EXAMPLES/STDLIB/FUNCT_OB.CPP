#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * funct_ob.cpp - Example program for function objects.
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
#include <functional>
#include <deque>
#include <vector>
#include <algorithm>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

//
// Create a new function object from unary_function.
//
template<class Arg>
class factorial : public unary_function<Arg, Arg>
{
public:
   Arg operator() (const Arg& arg)
   {
      Arg a = 1;
      for (Arg i = 2; i <= arg; i++)
         a *= i;
      return a;
   }
};

int main ()
{
   //
   // Initialize a deque with an array of integers.
   //
   int init[7] = {1,2,3,4,5,6,7};
   deque<int,allocator<int> > d(init+0, init+7);
   //
   // Create an empty vector to store the factorials.
   //
   vector<int,allocator<int> > v((size_t)7);
   //
   // Transform the numbers in the deque to their factorials and store
   // in the vector.
   //
   transform(d.begin(), d.end(), v.begin(), factorial<int>());
   //
   // Print the results.
   //
   cout << "The following numbers: " << endl << "     ";
   copy(d.begin(), d.end(), 
        ostream_iterator<int,char,char_traits<char> >(cout," "));

   cout << endl << endl;
   cout << "Have the factorials: " << endl << "     ";
   copy(v.begin(), v.end(), 
        ostream_iterator<int,char,char_traits<char> >(cout," "));
   cout << endl;

   return 0;
}
