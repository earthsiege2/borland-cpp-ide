#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * alg4.cpp - Example programs for STL generic algorithms removal 
 *    algorithms. Section 12.5
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

#include <list>
#include <set>
#include <algorithm>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif
    
bool isEven (int n) { return 0 == (n % 2); }

//
// Illustrate the use of the remove algorithm.
//

void remove_example ()
{
    cout << "Remove Algorithm examples" << endl;
    //
    // Create a list of numbers.
    //
    int data[] = { 1, 2, 4, 3, 1, 4, 2 };
    list<int,allocator<int> > aList;
    copy (data, data+7, inserter(aList, aList.begin()));
    cout << "Original list: ";
    copy (aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Remove 2's, copy into a new list.
    //
    list<int,allocator<int> > newList;
    remove_copy (aList.begin(), aList.end(), back_inserter(newList), 2);
    cout << "After removing 2's: ";
    copy (newList.begin(), newList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Remove 2's in place.
    //
    list<int,allocator<int> >::iterator where;
    where = remove(aList.begin(), aList.end(), 2);
    cout << "List after removal, before erase: ";
    copy (aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    aList.erase(where, aList.end());
    cout << "List after erase: ";
    copy (aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Remove all even values.
    //
    where = remove_if (aList.begin(), aList.end(), isEven);
    aList.erase(where, aList.end());
    cout << "List after removing even values: ";
    copy (aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
}

//
// Illustrate use of the unqiue algorithm.
//
void unique_example ()
{
    //
    // First make a list of values.
    //
    int data[] = { 1, 3, 3, 2, 2, 4 };
    list<int,allocator<int> > aList;
    copy(data, data+6, inserter(aList, aList.begin()));
    cout << "Origianal List: ";
    copy(aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Copy unique elements into a set.
    //
    set<int, less<int>,allocator<int>  > aSet;
//    unique_copy(aList.begin(), aList.end(), inserter(aSet, aSet.begin()));
    cout << "Set after unique_copy: ";
    copy(aSet.begin(), aSet.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Copy unique elements in place.
    //
    list<int,allocator<int> >::iterator where;
    where = unique(aList.begin(), aList.end());
    cout << "List after calling unique: ";
    copy(aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Remove trailing values.
    //
    aList.erase(where, aList.end());
    cout << "List after erase: ";
    copy(aList.begin(), aList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
}

int main ()
{
    cout << "STL generic algorithms -- Removal Algorithms" << endl;

    remove_example();
    unique_example();
    
    cout << "End of removal algorithms sample program" << endl;

    return 0;
}
