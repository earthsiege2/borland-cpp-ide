#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * nthelem.cpp - Example program for rearranging a collection based on nth
 *               element. See Class Reference Section
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
 
#include<algorithm>
#include<vector>
 
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     


template<class RandomAccessIterator>
void quik_sort(RandomAccessIterator start, RandomAccessIterator end)
{
#ifndef _RWSTD_NO_NAMESPACE
  using std::distance;
  using std::nth_element;
  using std::swap;
#endif

  size_t dist = 0;
  distance(start, end, dist);
  //
  // Stop condition for recursion.
  //
  if(dist > 2)
  {
    //
    // Use nth_element to do all the work for quik_sort.
    //
    nth_element(start, start+(dist/2), end);
    //
    // Recursive calls to each remaining unsorted portion.
    //
    quik_sort(start, start+(dist/2-1));
    quik_sort(start+(dist/2+1), end);
  }

  if(dist == 2 && *end < *start)
    swap(start, end);
}

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  //
  // Initialize a vector using an array of integers.
  //
  int arr[10] = {37, 12, 2, -5, 14, 1, 0, -1, 14, 32};
  vector<int,allocator<int> > v(arr+0, arr+10);
  //
  // Print the initial vector.
  //
  cout << "The unsorted values are: " << endl << "     ";
  vector<int,allocator<int> >::iterator i; 
  for(i = v.begin(); i != v.end(); i++)
    cout << *i << ", ";
  cout << endl << endl;
  //
  // Use the new sort algorithm.
  //
  quik_sort(v.begin(), v.end());
  //
  // Output the sorted vector.
  //
  cout << "The sorted values are: " << endl << "     ";
  for(i = v.begin(); i != v.end(); i++)
    cout << *i << ", ";
  cout << endl << endl;

  return 0;
}
