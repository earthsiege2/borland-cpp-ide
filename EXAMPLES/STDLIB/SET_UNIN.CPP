#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * set_unin.cpp - Example program of set union algorithm.
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
#include <set>
 
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
  // Initialize some sets.
  //
  int a2[6]  = {2,4,6,8,10,12};
  int a3[4]  = {3,5,7,8};
  set<int, less<int>,allocator<int>  >  even(a2+0, a2+6), result, smalll(a3+0, a3+4);
  //
  // Create an insert_iterator for result.
  //
  insert_iterator<set<int, less<int>,allocator<int>  > > res_ins(result, result.begin());
  //
  // Demonstrate set_union.
  //
  cout << "The result of:" << endl << "{";
  copy(smalll.begin(),smalll.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << "} union {";
  copy(even.begin(),even.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << "} =" << endl << "{";
  set_union(smalll.begin(), smalll.end(), even.begin(), even.end(), res_ins);
  copy(result.begin(),result.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << "}" << endl << endl;

  return 0;
}

