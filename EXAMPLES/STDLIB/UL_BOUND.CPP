#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * ul_bound.cpp - Example program of upper bound algorithm.
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

#include <vector>
#include <algorithm>
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

  typedef vector<int,allocator<int> >::iterator iterator;
  int d1[11] = {0,1,2,2,3,4,2,2,2,6,7};
  //
  // Set up a vector.
  //
  vector<int,allocator<int> > v1(d1+0, d1+11);
  //
  // Try lower_bound variants.
  //
  iterator it1 = lower_bound(v1.begin(),v1.end(),3);
  iterator it2 = lower_bound(v1.begin(),v1.end(),2,less<int>());
  //
  // Try upper_bound variants.
  //
  iterator it3 = upper_bound(v1.begin(),v1.end(),3);
  iterator it4 = upper_bound(v1.begin(),v1.end(),2,less<int>());

  cout << endl << endl
       << "The upper and lower bounds of 3: ( "
       << *it1 << " , " << *it3 << " ]" << endl;

  cout << endl << endl
       << "The upper and lower bounds of 2: ( "
       << *it2 << " , " << *it4 << " ]" << endl;

  return 0;
}
