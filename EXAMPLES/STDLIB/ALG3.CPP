#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * alg3.cpp - Sample programs for STL generic algorihtms that modify 
 *   their arguments in place.  Section 12.4
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
#include <functional>
#include <ctype.h>
#include <string>
#include <string.h>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
  
#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

class iotaGenerator
{
  public:
    iotaGenerator (int iv) : current(iv) { }
    int operator () () { return current++; }
  private:
    int current;
};

bool isEven (int n) { return 0 == (n % 2); }

//
// Illustrate the use of the reverse function.
//

void reverse_example ()
{
    cout << "Illustrate reverse algorithm" << endl;
    //
    // Example 1, reversing a string.
    //
    char ctext[30] = "Rats live on no evil star";
    char text[30];
    strcpy(text,ctext);
    reverse (text, text + strlen(text));
    cout << text << endl;
    //
    // Example 2, reversing a list.
    //
    list<int,allocator<int> > iList;
    generate_n(inserter(iList, iList.begin()), 10, iotaGenerator(2));
    reverse (iList.begin(), iList.end());
    copy (iList.begin(), iList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;    
}

//
// Illustrate the use of the replace function.
//

void replace_example ()
{
    cout << "Illustrate replace algorithm" << endl;
    //
    // Make vector 0 1 2 3 4.
    //
    vector<int,allocator<int> > numbers(11);    
    for (int i = 0; i < 11; i++)
        numbers[i] = i < 5 ? i : 10 - i;
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Replace 0 by 2.
    //
    replace (numbers.begin(), numbers.end(), 3, 7);
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Replace even numbers by 9.
    //
    replace_if (numbers.begin(), numbers.end(), isEven, 9);
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //    
    // Copy into a list, replacing 9 by 3.
    //
    int aList[] = { 2, 1, 4, 3, 2, 5 };
    int bList[6];
    int cList[6];
    replace_copy (aList, aList+6, &bList[0], 2, 7);
    replace_copy_if (bList, bList+6, &cList[0], bind2nd(greater<int>(), 3), 8);
    copy (bList, bList + 6, ostream_iterator<int,char,char_traits<char> >(cout, " ")); cout << endl;
    copy (cList, cList + 6, ostream_iterator<int,char,char_traits<char> >(cout, " ")); cout << endl;
}

//
// Illustrate the use of the rotate function.
//

void rotate_example ()
{
    cout << "Illustrate rotate algorithm" << endl;
    //
    // Create the list 1 2 3 ... 10
    //
    list<int,allocator<int> > iList;
    generate_n(inserter(iList, iList.begin()), 10, iotaGenerator(1));
    //
    // Find the location of the seven.
    //
    list<int,allocator<int> >::iterator  middle = find(iList.begin(), iList.end(), 7);
    //
    // Now rotate around that location.
    //
    rotate(iList.begin(), middle, iList.end());
    copy (iList.begin(), iList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //    
    // Rotate again around the same location.
    //
    list<int,allocator<int> > cList;
    rotate_copy(iList.begin(), middle,iList.end(),
                inserter(cList, cList.begin()));
    copy (cList.begin(), cList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl; 
}

//
// Illustrate the use of the paration function.
//

void partition_example ()
{
    cout << "Illustrate partition algorithm" << endl;
    //
    // First make the vector 1 2 3 ... 10.
    //
    vector<int,allocator<int> > numbers(10);
    generate(numbers.begin(), numbers.end(), iotaGenerator(1));
    //
    // Now put the odd values low, even values high.
    //
    vector<int,allocator<int> >::iterator result = partition(numbers.begin(),numbers.end(),
                                             isEven);
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    cout << "middle location " << result - numbers.begin() << endl; 
    //
    // Now do a stable partition.
    //
    generate(numbers.begin(), numbers.end(), iotaGenerator(1));
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
}

bool nameCompare (char * a, char * b) { return strcmp(a, b) <= 0; }

//
// Illustrate the use of the next_permutation function.
//

void permutation_example ()
{
    //
    // Start with the values 1 2 3 in sequence.
    //
    int start [] = {1, 2, 3 };
    
    do
    {
        copy (start, start + 3, ostream_iterator<int,char,char_traits<char> >(cout, " "));
        cout << endl;
    }
    while (next_permutation(start, start + 3));
        
    char * names[] = { "Alpha", "Beta", "Gamma" };

    do
    {
        copy (names, names + 3, ostream_iterator<char *,char,char_traits<char> >(cout, " "));
        cout << endl;
    }
    while (next_permutation(names, names + 3, nameCompare));
    
    char * cword = "bela";
    char word[4];
    strcpy(word,cword);

    do
        cout << word << ' ';
    while (prev_permutation(word, &word[4]));

    cout << endl;   
}

//
// Illustrate the use of the inplace_merge function.
//

void inplace_merge_example ()
{
    cout << "Illustrate inplace merge algorithm" << endl;
    //
    // First generate the numbers 0 2 4 6 8 1 3 5 7 9.
    //
    vector<int,allocator<int> > numbers(10);
    for (int i = 0; i < 10; i++)
        numbers[i] = i < 5 ? 2 * i : 2 * (i - 5) + 1;
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl; 
    vector<int,allocator<int> >::iterator midvec = find(numbers.begin(), numbers.end(), 1);
    //
    // Copy them into a list.
    //
    list<int,allocator<int> > numList;
    copy(numbers.begin(), numbers.end(), inserter(numList, numList.begin()));
    list<int,allocator<int> >::iterator midList = find(numList.begin(), numList.end(), 1);
    copy (numList.begin(), numList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl; 
    //
    // Now put them back together.
    //
    inplace_merge(numbers.begin(), midvec, numbers.end());
    inplace_merge(numList.begin(), midList, numList.end());
    copy (numList.begin(), numList.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl; 
}

struct RandomInteger
{
    int operator() (int m) { return rand() % m; }
};

//
// Illustrate the use of the random_shuffle function.
//

void random_shuffle_example ()
{
    //
    // First make the vector 1 2 3 ... 10.
    //
    vector<int,allocator<int> > numbers(10);
    generate(numbers.begin(), numbers.end(), iotaGenerator(1));

    RandomInteger random;

    //
    // Randomly shuffle the elements.
    //
    random_shuffle(numbers.begin(), numbers.end(), random);
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
    //
    // Do it again.
    //
    random_shuffle(numbers.begin(), numbers.end(), random);
    copy (numbers.begin(), numbers.end(), ostream_iterator<int,char,char_traits<char> >(cout, " "));
    cout << endl;
}

int main ()
{
    cout << "STL generic algorithms -- in-place algorithms" << endl;

    reverse_example();
    replace_example();
    rotate_example();
    partition_example();
    permutation_example();
    inplace_merge_example();
    random_shuffle_example();
    
    cout << "End of in-place algorithm sample program"  << endl;

    return 0;
}







