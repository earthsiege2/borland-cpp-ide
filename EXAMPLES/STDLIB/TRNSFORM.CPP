#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * trnsform.cpp - Example program of transform algorithm. 
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
#include <algorithm>
 
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#include <iomanip>
#else
#include <iostream.h>
#include <iomanip.h>
#endif     

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  //
  // Initialize a deque with an array of integers.
  //
  int arr1[5] = {99, 264, 126, 330, 132};
  int arr2[5] = {280, 105, 220, 84, 210};
  deque<int,allocator<int> > d1(arr1+0, arr1+5), d2(arr2+0, arr2+5);
  //
  // Print the original values.
  //
  cout << "The following pairs of numbers: " << endl << "     ";
  deque<int,allocator<int> >::iterator i1;
  for (i1 = d1.begin(); i1 != d1.end(); i1++)
    cout << setw(6) << *i1 << " ";
  cout << endl << "     ";
  for (i1 = d2.begin(); i1 != d2.end(); i1++)
    cout << setw(6) << *i1 << " ";
  //
  // Transform the numbers in the deque to their 
  // factorials and store in the vector.
  //
  transform(d1.begin(), d1.end(), d2.begin(), d1.begin(), multiplies<int>());
  //
  // Display the results.
  //
  cout << endl << endl;
  cout << "Have the products: " << endl << "     ";
  for (i1 = d1.begin(); i1 != d1.end(); i1++)
    cout << setw(6) << *i1 << " ";
  cout << endl;

  return 0;
}
