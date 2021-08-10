#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * alg6.cpp - STL generic algorithms that produce new sequences
 *    section 12.7
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
#include <list>
#include <algorithm>
#include <numeric>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
    
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

int square (int n) { return n * n; }

class iotaGen
{
  public:
    iotaGen (int iv) : current(iv) { }
    int operator () () { return current++; }
  private:
    int current;
};

//
// Illustrate the use of the transform algorithm.
//

void transform_example ()

{
    //
    // Generate a list of values from 1 to 6.
    //
    list<int,allocator<int> > aList;
    generate_n (inserter(aList, aList.begin()), 6, iotaGen(1));
    cout << "Original list: ";
    copy(aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Transform elements by squaring, copy into vector.
    //
    vector<int,allocator<int> > aVec(6);
    transform (aList.begin(), aList.end(), aVec.begin(), square);
    cout << "After squaring: ";
    copy(aVec.begin(), aVec.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Transform vector again, in place, yielding 4th powers.
    //
    transform (aVec.begin(), aVec.end(), aVec.begin(), square);
    cout << "After squaring again: ";
    copy(aVec.begin(), aVec.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Transform in parallel, yielding cubes.
    //
    vector<int,allocator<int> > cubes(6);
    transform (aVec.begin(), aVec.end(), aList.begin(), cubes.begin(),
               divides<int>());
    cout << "After division: ";
    copy(cubes.begin(), cubes.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
}

//
// Illustrate the use of the partial sum algorithm.
//

void partial_sum_example ()
{
    //
    // Generate values 1 to 5.
    //
    vector<int,allocator<int> > aVec(5);
    generate (aVec.begin(), aVec.end(), iotaGen(1));
    //
    // Output partial sums.
    //
    cout << "Partial sums examples" << endl;
    cout << "Partial sums : ";
    partial_sum (aVec.begin(), aVec.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //    
    // Output partial products.
    //
    cout << "Partial products: ";
    partial_sum (aVec.begin(), aVec.end(), 
                 ostream_iterator<int,char,char_traits<char> >(cout, " "),
                 multiplies<int>() );

    cout << endl;
}

//
// Illustrate the use of the adjacent difference algorithm.
//

void adjacent_difference_example ()
{
    //
    // Generate values 1 to 5.
    //
    vector<int,allocator<int> > aVec(5);
    generate (aVec.begin(), aVec.end(), iotaGen(1));
    //
    // Output partial sums.
    //
    cout << "Adjacent Differences examples" << endl;
    cout << "Adjacent Differences : ";
    adjacent_difference (aVec.begin(), aVec.end(),
                         ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Output partial products.
    //
    cout << "Adjacent sums: ";
    adjacent_difference (aVec.begin(), aVec.end(),
                         ostream_iterator<int,char,char_traits<char> >(cout, " "), plus<int>());
    cout << endl;
}


int main ()
 {
    cout << "STL generic algorithms -- that transform sequences"  << endl;
    
    transform_example();
    partial_sum_example();
    adjacent_difference_example ();
    
    cout << "End generic transform algorithms example" << endl;

    return 0;
}







