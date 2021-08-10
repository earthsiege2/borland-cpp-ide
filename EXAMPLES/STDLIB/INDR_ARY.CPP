#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * indirect_array.cpp -- Indirect array examples 
 *                       See Class Reference Section
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
  size_t sbuf[6] = {0,2,3,4,7,8};

  // create a valarray of ints
  valarray<int>         vi(ibuf,10);

  // create a valarray of indices for a selector
  valarray<size_t> selector(sbuf,6);

  // print out the valarray<int>
  cout << vi << endl;

  // Get a indirect_array 
  // and assign that indirect to another valarray
  indirect_array<int> select = vi[selector];
  valarray<int> vi3 = select;

  // print out the selective array
  cout << vi3 << endl;
  
  // Double the selected values
  select += vi3;

  // print out vi1 again
  cout << vi << endl;

  return 0;
}

