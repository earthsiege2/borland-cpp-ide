#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * setex.cpp - Example program of sets. See Class Reference Section
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

typedef set<double,less<double>,allocator<double>  > set_type;

ostream& operator<<(ostream& out, const set_type& s)
{
  copy(s.begin(), s.end(), ostream_iterator<set_type::value_type,char,char_traits<char> >(cout," "));
  return out;
}

int main ()
{
  //
  // Create a set of double's, and one of integers.
  //
  set_type   sd;
  int         i;

  for (i = 0; i < 10; ++i)
    //
    // Insert values.
    //
    sd.insert(i);
  //
  // Print out the set.
  //
  cout << sd << endl << endl;
  //
  // Now let's erase half of the elements in the set.
  //
  int half = sd.size() / 2;
  set_type::iterator sdi = sd.begin();
  advance(sdi,half);
  sd.erase(sd.begin(),sdi);
  //
  // Print it out again.
  //
  cout << sd << endl << endl;
  //
  // Make another set and an empty result set.
  //
  set_type sd2, sdResult;
  for (i = 1; i < 9; i++)
    sd2.insert(i+5);
  cout << sd2 << endl;
  //
  // Try a couple of set algorithms.
  //
  set_union(sd.begin(),sd.end(),sd2.begin(),sd2.end(),
            inserter(sdResult,sdResult.begin()));
  cout << "Union:" << endl << sdResult << endl;

  sdResult.erase(sdResult.begin(),sdResult.end());
  set_intersection(sd.begin(),sd.end(), sd2.begin(),sd2.end(),
                   inserter(sdResult,sdResult.begin()));
  cout << "Intersection:" << endl << sdResult << endl;
  
  return 0;
}
