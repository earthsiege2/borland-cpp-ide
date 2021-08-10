#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * remove.cpp - Example program of remove algorithm.
 *              See Class Reference Section
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
#include <iterator>
#include <functional>
 
#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

template<class Arg>
struct not_zero : public unary_function<Arg, bool>
{
  bool operator() (const Arg& a) { return a != 0; }
};

int main ()
{
  int arr[10] = {1,2,3,4,5,6,7,8,9,10};
  vector<int,allocator<int> > v(arr+0, arr+10);

  copy(v.begin(),v.end(),ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl << endl;
  //
  // Remove the 7.
  //
  vector<int,allocator<int> >::iterator result = remove(v.begin(), v.end(), 7);
  //
  // Delete dangling elements from the vector.
  //
  v.erase(result, v.end());

  copy(v.begin(),v.end(),ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl << endl;
  //
  // Remove everything beyond the fourth element.
  //
  result = remove_if(v.begin()+4, v.begin()+8, not_zero<int>());
  //
  // Delete dangling elements.
  //
  v.erase(result, v.end());

  copy(v.begin(),v.end(),ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl << endl;
  //
  // Now remove all 3s on output.
  // 
  remove_copy(v.begin(), v.end(), ostream_iterator<int,char,char_traits<char> >(cout," "), 3);
  cout << endl << endl;
  //
  // Now remove everything satisfying predicate on output.
  // Should yield a NULL vector.
  //
  remove_copy_if(v.begin(), v.end(), ostream_iterator<int,char,char_traits<char> >(cout," "),
                 not_zero<int>());
 
  return 0;
}
