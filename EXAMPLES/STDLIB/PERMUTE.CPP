#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * permute.cpp - Example program of permutations. See Class Reference Section
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

#include <numeric>    // For accumulate.
#include <vector>     // For vector.
#include <functional> // For less.

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
  // Initialize a vector using an array of integers.
  //
  int  a1[] = {0,0,0,0,1,0,0,0,0,0};
  char a2[] = "abcdefghji";
  //
  // Create the initial set and copies for permuting.
  //
  vector<int,allocator<int> >  m1(a1+0, a1+10); 
  vector<int,allocator<int> >  prev_m1((size_t)10), next_m1((size_t)10);
  vector<char,allocator<char> > m2(a2+0, a2+10);
  vector<char,allocator<char> > prev_m2((size_t)10), next_m2((size_t)10);

  copy(m1.begin(), m1.end(), prev_m1.begin());
  copy(m1.begin(), m1.end(), next_m1.begin());
  copy(m2.begin(), m2.end(), prev_m2.begin());
  copy(m2.begin(), m2.end(), next_m2.begin());
  //
  // Create permutations.
  //
  prev_permutation(prev_m1.begin(), prev_m1.end(), less<int>());
  next_permutation(next_m1.begin(), next_m1.end(), less<int>());
  prev_permutation(prev_m2.begin(), prev_m2.end(), less<int>());
  next_permutation(next_m2.begin(), next_m2.end(), less<int>());
  //
  // Output results.
  //
  cout << "Example 1: " << endl << "     ";
  cout << "Original values:      ";
  copy(m1.begin(), m1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl << "     ";
  cout << "Previous permutation: ";
  copy(prev_m1.begin(), prev_m1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));

  cout << endl<< "     ";
  cout << "Next Permutation:     ";
  copy(next_m1.begin(), next_m1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
  cout << endl << endl;

  cout << "Example 2: " << endl << "     ";
  cout << "Original values: ";
  copy(m2.begin(), m2.end(), ostream_iterator<char,char,char_traits<char> >(cout," "));     
  cout << endl << "     ";
  cout << "Previous Permutation: ";
  copy(prev_m2.begin(), prev_m2.end(), ostream_iterator<char,char,char_traits<char> >(cout," "));
  cout << endl << "     ";

  cout << "Next Permutation:     ";
  copy(next_m2.begin(), next_m2.end(), ostream_iterator<char,char,char_traits<char> >(cout," "));  
  cout << endl << endl;

  return 0;
}
