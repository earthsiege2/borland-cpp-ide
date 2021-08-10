#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * merge.cpp - Example program of merging sequences. 
 *             See Class Reference Section
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

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
   using namespace std;
#endif

   int d1[4] = {1,2,3,4};
   int d2[8] = {11,13,15,17,12,14,16,18};
   //
   // Set up two vectors.
   //
   vector<int,allocator<int> > v1(d1+0, d1+4), v2(d1+0, d1+4);
   //
   // Set up four destination vectors.
   //
   vector<int,allocator<int> > v3(d2+0, d2+8), v4(d2+0, d2+8), v5(d2+0, d2+8), v6(d2+0, d2+8);
   //
   // Set up one empty vector.
   //
   vector<int,allocator<int> > v7;
   //
   // Merge v1 with v2.
   //
   merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
   //
   // Now use comparator.
   //
   merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin(), less<int>());
   //
   // In place merge v5.
   //
   vector<int,allocator<int> >::iterator mid = v5.begin();
   advance(mid,4);
   inplace_merge(v5.begin(),mid,v5.end());
   //
   // Now use a comparator on v6.
   //
   mid = v6.begin();
   advance(mid,4);
   inplace_merge(v6.begin(), mid, v6.end(), less<int>());	  
   // 
   // Merge v1 and v2 to empty vector using insert iterator.
   //
   merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v7));
   //
   // Copy all cout.
   //
   ostream_iterator<int,char,char_traits<char> > out(cout," ");
   copy(v1.begin(),v1.end(),out);
   cout << endl;
   copy(v2.begin(),v2.end(),out);
   cout << endl;
   copy(v3.begin(),v3.end(),out);
   cout << endl;
   copy(v4.begin(),v4.end(),out);
   cout << endl;
   copy(v5.begin(),v5.end(),out);
   cout << endl;
   copy(v6.begin(),v6.end(),out);
   cout << endl;
   copy(v7.begin(),v7.end(),out);
   cout << endl;
   // 
   // Merge v1 and v2 to cout.
   //
   merge(v1.begin(),v1.end(),v2.begin(),v2.end(),
         ostream_iterator<int,char,char_traits<char> >(cout," "));

   return 0;
}
