#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * search.cpp - Example program of search algorithm.
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
#include <list>
 
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
  // Initialize a list sequence and subsequence with characters.
  //
  char seq[40]    = "Here's a string with a substring in it";
  char subseq[10] = "substring";
  list<char,allocator<char> > sequence(seq, seq+38);
  list<char,allocator<char> > subseqnc(subseq, subseq+9);
  //
  // Print out the original sequence.
  //
  cout << endl << "The subsequence, " << subseq << ", was found at the ";
  cout << endl << "location identified by a '*'" << endl << "     ";
  //
  // Create an iterator to identify the location of 
  // subsequence within sequence.
  //
  list<char,allocator<char> >::iterator place;
  //
  // Do search.
  //
  place = search(sequence.begin(), sequence.end(),
                 subseqnc.begin(), subseqnc.end());
  //
  // Identify result by marking first character with a '*'.
  //
  *place = '*';
  //
  // Output sequence to display result.
  //
  for (list<char,allocator<char> >::iterator i = sequence.begin(); i != sequence.end(); i++)
    cout << *i;
  cout << endl;

  return 0;
}
