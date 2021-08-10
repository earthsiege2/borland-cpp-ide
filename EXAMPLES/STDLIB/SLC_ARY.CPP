#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * slice_array.cpp -- Valarray slice array examples 
 *                    See Class Reference Section
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

#include "valarray.h"  // Contains a valarray stream inserter

int main(void)
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  int ibuf[10] = {0,1,2,3,4,5,6,7,8,9};
  int ibuf2[5] = {1,3,5,7,9};

  // create a valarray of ints
  valarray<int>         vi(ibuf,10);
  valarray<int>         vi2(ibuf2,5);

  // print it out
  cout << vi << endl << vi2 << endl;

  // Get a slice and assign that slice to another array
  slice_array<int> sl = vi[slice(1,5,2)];
  valarray<int> vi3 = sl;

  // print out the slice
  cout << vi3 << endl;
  
  // Add slice from vi2 to slice of vi1
  sl += vi2;

  // print out vi1 again
  cout << vi << endl;

  return 0;
}
