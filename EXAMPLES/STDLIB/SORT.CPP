#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * sort.cpp - Example program of sort algorithm. See Class Reference Section
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

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

struct associate
{
  int num;
  char chr;
  associate(int n, char c) : num(n), chr(c){};
  associate() : num(0), chr('\0'){};
};

bool operator< (const associate &x, const associate &y)
{
  return x.num < y.num;
}

ostream& operator<< (ostream &s, const associate &x)
{
  return s << "<" << x.num << ";" << x.chr << ">";
}

int main ()
{
  vector<associate,allocator<associate> >::iterator i, j, k;

  associate arr[20] = 
  {associate(-4, ' '), associate(16, ' '),
   associate(17, ' '), associate(-3, 's'),
   associate(14, ' '), associate(-6, ' '),
   associate(-1, ' '), associate(-3, 't'),
   associate(23, ' '), associate(-3, 'a'),
   associate(-2, ' '), associate(-7, ' '),
   associate(-3, 'b'), associate(-8, ' '),
   associate(11, ' '), associate(-3, 'l'),
   associate(15, ' '), associate(-5, ' '),
   associate(-3, 'e'), associate(15, ' ')};
  //
  // Set up vectors.
  //
  vector<associate,allocator<associate> > v(arr+0, arr+20), v1((size_t)20), v2((size_t)20);
  //
  // Copy original vector to vectors #1 and #2.
  //
  copy(v.begin(), v.end(), v1.begin());
  copy(v.begin(), v.end(), v2.begin());
  //
  // Sort vector #1.
  //
  sort(v1.begin(), v1.end());
  //
  // Stable sort vector #2.
  //
  stable_sort(v2.begin(), v2.end());
  //
  // Display the results.
  //
  cout << "Original    sort      stable_sort" << endl;
  for(i = v.begin(), j = v1.begin(), k = v2.begin();
      i != v.end(); i++, j++, k++)
    cout << *i << "     " << *j << "     " << *k << endl;

  return 0;
}
