#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * mask_array.cpp -- Mask array examples 
 *                   See Class Reference Section
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
  bool mbuf[10] = {1,0,1,1,1,0,0,1,1,0};

  // create a valarray of ints
  valarray<int>         vi(ibuf,10);

  // create a valarray of bools for a mask
  valarray<bool> mask(mbuf,10);

  // print out the valarray<int>
  cout << vi << endl;

  // Get a mask array and assign that mask to another array
  mask_array<int> msk = vi[mask];
  valarray<int> vi3 = msk;

  // print out the masked_array
  cout << vi3 << endl;
  
  // Double the masked values
  msk += vi3;

  // print out vi1 again
  cout << vi << endl;

  return 0;
}
