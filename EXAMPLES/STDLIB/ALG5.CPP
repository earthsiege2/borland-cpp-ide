#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * alg5.cpp - Example programs for STL generic algorithms those producing 
 *    scalar values. Section 12.6
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
#include <string.h>
#include <string>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
   
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

//
// Forward declarations.
//
bool isVowel (char);
void count_example();
void accumulate_example();
template<class T>
list<T,allocator<void> > & listadd(list<T,allocator<void> > & base, T & newValue);
void inner_product_example();
void equal_example();

bool isVowel (char c)
{
    switch (c)
    {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
            return true;
    }
    return false;
}

//
// Illustrate the use of the count function.
//

void count_example ()

{
    int ecount     = 0;
    int vowelCount = 0;
    
    char * text = "Now is the time to begin";
    
    count (text, text + strlen(text), 'e', ecount);
    count_if (text, text + strlen(text), isVowel, vowelCount);
    
    cout << "There are " << ecount << " letter e's " << endl << "and "
        << vowelCount << " vowels in the text:" << text << endl;
}

//
// Add n to 1 to list.
//
list<int,allocator<int> >& intReplicate (list<int,allocator<int> >& nums, int n)
{
    while (n) nums.push_back(n--);
    return nums;
}

//
// Illustrate the use of the accumulate function.
//

void accumulate_example ()
{
    int numbers[] = { 1, 2, 3, 4, 5 };
    
    int sum     = accumulate(numbers, numbers+5, 0);
    int product = accumulate(numbers, numbers+5, 1, multiplies<int>());

    cout << "The sum of the first five numbers is "     << sum     << endl;
    cout << "The product of the first five numbers is " << product << endl;
    //
    // Example with different types for init.
    //
    list<int,allocator<int> > nums;
    nums = accumulate(numbers, numbers+5, nums, intReplicate);
    copy (nums.begin(), nums.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
}

//
// Illustrate the use of the inner_product function.
//

void inner_product_example ()
{
    int a[] = { 4, 3, -2 };
    int b[] = { 7, 3, 2  };
    //
    // Example 1, simple inner product.
    //
    int in1 = inner_product(a, a+3, b, 0);
    cout << "Inner product is " << in1 << endl;
    //
    // Example 2, using different operations.
    //
    bool anyequal = inner_product(a, a+3, b, true, logical_or<bool>(),
                                  equal_to<int>());
    cout << "any equal? " << anyequal << endl;  
}

//
// Illustrate the use of the equal function.
//

void equal_example ()
{
    int a[] = { 4, 5, 3 };
    int b[] = { 4, 3, 3 };
    int c[] = { 4, 5, 3 };
    
    cout << "a = b is:" << equal(a, a+3, b) << endl;
    cout << "a = c is:" << equal(a, a+3, c) << endl;
    cout << "a pair-wise-greater_equal b is"
         << equal(a, a+3, b, greater_equal<int>()) << endl;
}

//
// Illustrate the use of the lexical_comparison function.
//

void lexical_comparison_example ()
{
    char * wordOne = "everything";
    char * wordTwo = "everybody";
    
    cout << "compare everybody to everything "
         << lexicographical_compare(wordTwo, wordTwo+strlen(wordTwo), wordOne,
                                    wordOne+strlen(wordOne))
         << endl;
            
    int a[] = { 3, 4, 5, 2 };
    int b[] = { 3, 4, 5 };
    int c[] = { 3, 5 };
    
    cout << "compare a to b: " << lexicographical_compare(a,a+4,b,b+3) << endl;
    cout << "compare a to c: " << lexicographical_compare(a,a+4,c,c+2) << endl;
}

int main ()
 {
    cout << "STL generic algorithms -- algorithms that produce scalar results" << endl;

    count_example();
    accumulate_example();
    inner_product_example();
    equal_example();
    lexical_comparison_example();
    
    cout << "End of scalar algorithms test"  << endl;

    return 0;
}
