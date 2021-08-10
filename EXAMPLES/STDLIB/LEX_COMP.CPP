#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * lex_comp.cpp - Example program compares to ranges lexicographically.
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
#include <vector>
#include <functional>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

int main()
{							 
#ifndef _RWSTD_NO_NAMESPACE
   using namespace std;
#endif

   int d1[5] = {1,3,5,32,64}; 		
   int d2[5] = {1,3,2,43,56};
   // 
   // Set up vector.
   //
   vector<int,allocator<int> > v1(d1+0, d1+5), v2(d2+0, d2+5);	 
   // 
   // Is v1 less than v2 (I think not).
   //
   bool b1 = lexicographical_compare(v1.begin(),v1.end(),v2.begin(),v2.end());
   //
   // Is v2 less than v1 (yup, sure is).
   //
   bool b2 = lexicographical_compare(v2.begin(), v2.end(),
                                     v1.begin(), v1.end(), less<int>());
   cout << (b1 ? "TRUE" : "FALSE") << " " 
        << (b2 ? "TRUE" : "FALSE") << endl;

   return 0;
}

