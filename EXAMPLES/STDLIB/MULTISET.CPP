#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * multiset.cpp - Example program for multiset class.
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
#include <set>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

typedef multiset<int,less<int>,allocator<int>  > set_type;

ostream& operator<< (ostream& out, const set_type& s)
{
  copy(s.begin(),s.end(),ostream_iterator<set_type::value_type,char,char_traits<char> >(cout," "));
  return out;
}

int main ()
{
  //
  // Create a multiset of integers.
  //
  set_type  si;
  int       i;
  
  for (int j = 0; j < 2; j++)
  {
    for (i = 0; i < 10; ++i)
      //
      // Insert values with a hint.
      //
      si.insert(si.begin(), i);
  }
  //
  // Print out the multiset.
  //
  cout << si << endl;
  //
  // Make another int multiset and an empty multiset.
  //
  set_type si2, siResult;
  for (i = 0; i < 10; i++)
    si2.insert(i+5);
  cout << si2 << endl;
  //
  // Try a couple of set algorithms.
  //
  set_union(si.begin(),si.end(),si2.begin(),si2.end(),
            inserter(siResult,siResult.begin()));
  cout << "Union:" << endl << siResult << endl;
  
  siResult.erase(siResult.begin(),siResult.end());
  set_intersection(si.begin(),si.end(),si2.begin(),si2.end(),
                   inserter(siResult,siResult.begin()));
  cout << "Intersection:" << endl << siResult << endl;
  
  return 0;
}
