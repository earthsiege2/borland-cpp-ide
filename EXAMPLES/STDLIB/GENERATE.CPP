#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * generate.cpp - Example program for initializing a container with values 
 *                produced by a value-generator class. See Class Reference Section
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

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

//
// Value generator simply doubles the current value and returns it.
//
template <class T>
class generate_val
{
   private:
      T val_;
   public:
      generate_val(const T& val) : val_(val) {}
      T& operator()() { val_ += val_; return val_; }
};

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
   using namespace std;
#endif

   int d1[4] = {1,2,3,4};
   generate_val<int> gen(1);
   //
   // Set up two vectors.
   //
   vector<int,allocator<int> > v1(d1+0, d1+4), v2(d1+0, d1+4);
   //
   // Set up one empty vector.
   //
   vector<int,allocator<int> > v3;
   //
   // Generate values for all of v1.
   //
   generate(v1.begin(), v1.end(), gen);
   //
   // Generate values for first 3 of v2.
   //
   generate_n(v2.begin(), 3, gen);
   //
   // Use insert iterator to generate 5 values for v3.
   //
   generate_n(back_inserter(v3), 5, gen);
   //
   // Copy all three to cout.
   //
   ostream_iterator<int,char,char_traits<char> > out(cout," ");
   copy(v1.begin(), v1.end(), out);
   cout << endl;
   copy(v2.begin(), v2.end(), out);
   cout << endl;
   copy(v3.begin(), v3.end(), out);
   cout << endl;
   //
   // Generate 3 values for cout.
   //
   generate_n(ostream_iterator<int,char,char_traits<char> >(cout," "), 3, gen);
   cout << endl;

   return 0;
}
