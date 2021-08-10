#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * inr_prod.cpp - Example program computes the inner product A X B of two
 *                ranges A and B. See Class Reference Section
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
#include <numeric>       // For inner_product.
#include <list>          // For list.
#include <vector>        // For vectors.
#include <functional>    // For plus and minus.

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
   // Initialize a list and an int using arrays of ints.
   //
   int a1[3] = {6, -3, -2};
   int a2[3] = {-2, -3, -2};

   list<int,allocator<int> >   l(a1+0, a1+3);
   vector<int,allocator<int> > v(a2+0, a2+3);
   //
   // Calculate the inner product of the two sets of values.
   //
   int inner_prod = inner_product(l.begin(), l.end(), v.begin(), 0);
   //
   // Calculate a wacky inner product using the same values.
   //
   int wacky = inner_product(l.begin(), l.end(), v.begin(), 0,
                             plus<int>(), minus<int>());
   //
   // Print the output.
   //
   cout << "For the two sets of numbers: " << endl << "     ";
   copy(v.begin(),v.end(),
        ostream_iterator<int,char,char_traits<char> >(cout," "));
   cout << endl << " and  ";
   copy(l.begin(),l.end(),
        ostream_iterator<int,char,char_traits<char> >(cout," "));

   cout << "," << endl << endl;
   cout << "The inner product is: " << inner_prod << endl;
   cout << "The wacky result is: " << wacky << endl;

   return 0;
}
