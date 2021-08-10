#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * prtition.cpp - Example program for partition. See Class Reference Section
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
#include<functional>
#include<deque>
#include<algorithm>
 
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

//
// Create a new predicate from unary_function.
//
template<class Arg>
class is_even : public unary_function<Arg, bool>
{
public:
  bool operator()(const Arg& arg1) { return (arg1 % 2) == 0; } 
};

int main ()
{
  //
  // Initialize a deque with an array of integers.
  //
  int init[10] = { 1,2,3,4,5,6,7,8,9,10 };
  deque<int,allocator<int> > d1(init+0, init+10);
  deque<int,allocator<int> > d2(init+0, init+10);
  //
  // Print out the original values.
  //
  cout << "Unpartitioned values: " << "\t\t";
  copy(d1.begin(), d1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl;
  //
  // A partition of the deque according to even/oddness.
  //
  partition(d2.begin(), d2.end(), is_even<int>());
  //
  // Output result of partition.
  //
  cout << "Partitioned values: " << "\t\t";
  copy(d2.begin(), d2.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl;
  //
  // A stable partition of the deque according to even/oddness.
  //
  stable_partition(d1.begin(), d1.end(), is_even<int>());
  //
  // Output result of partition.
  //
  cout << "Stable partitioned values: " << "\t";
  copy(d1.begin(), d1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl;

  return 0;
}
