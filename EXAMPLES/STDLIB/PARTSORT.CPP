#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * partsort.cpp - Example program of partial sort. See Class Reference Section
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

   int d1[20] = {17, 3,  5,  -4, 1, 12, -10, -1, 14, 7,
                 -6, 8, 15, -11, 2, -2,  18,  4, -3, 0};
   //
   // Set up a vector.
   //
   vector<int,allocator<int> > v1(d1+0, d1+20);
   //
   // Output original vector.
   //
   cout << "For the vector: ";
   copy(v1.begin(), v1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
   //
   // Partial sort the first seven elements.
   //
   partial_sort(v1.begin(), v1.begin()+7, v1.end());
   //
   // Output result.
   //
   cout << endl << endl << "A partial_sort of seven elements gives: " 
        << endl << "     ";
   copy(v1.begin(), v1.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
   cout << endl;
   //
   // A vector of ten elements.
   //
   vector<int,allocator<int> > v2(10, 0);
   //
   // Sort the last ten elements in v1 into v2.
   //
   partial_sort_copy(v1.begin()+10, v1.end(), v2.begin(), v2.end());
   //
   // Output result.
   //
   cout << endl << "A partial_sort_copy of the last ten elements gives: " 
        << endl << "     ";
   copy(v2.begin(), v2.end(), ostream_iterator<int,char,char_traits<char> >(cout," "));
   cout << endl;

   return 0;
}
