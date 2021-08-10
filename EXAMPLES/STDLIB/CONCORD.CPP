#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * concord.cpp - Concordance sample program. Section 9.3.3
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


#include <map>
#include <list>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
    
#include <string>
#include <ctype.h>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

//
// Split a line of text into words.
//

void split (const string& text, const string& separators, list<string,allocator<string> > & words)
{
    int n     = text.length();
    int start = text.find_first_not_of(separators);

    while ((start >= 0) && (start < n))
    {
        int stop = text.find_first_of(separators, start);
        if ((stop < 0) || (stop > n)) stop = n;
        words.push_back (text.substr(start, stop-start));
        start = text.find_first_not_of(separators, stop+1);
    }
}

class concordance
{
    typedef multimap<string, int, less<string>,allocator<string>  > wordDictType;
  public:
    void addWord (string, int);
    void readText (istream &);
    void printConcordance (ostream &);
  private:
    wordDictType wordMap;
};

void concordance::addWord (string word, int line)
{
    //
    // First get range of entries with same key.
    //
    wordDictType::iterator low = wordMap.lower_bound(word);
    wordDictType::iterator high = wordMap.upper_bound(word);
    //
    // Loop over entires, see if any match current line.
    //
    for ( ; low != high; ++low)
        if ((*low).second == line)
            return;
    //
    // Didn't occur, add now.
    //
    wordMap.insert(wordDictType::value_type(word, line));
}

void allLower (string & s)
{
    for (int i = 0; i < s.size(); i++)
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
}

void concordance::readText (istream & in)
{
    string line;
    for (int i = 1; getline(in, line, '\n'); i++)
    {
        allLower(line);
        list<string,allocator<string> > words;
        split(line, " ,.;:", words);
        list<string,allocator<string> >::iterator wptr;
        for (wptr = words.begin(); wptr != words.end(); ++wptr)
            addWord(*wptr, i);
    }
}

void concordance::printConcordance (ostream & out)
{
    string lastword("");
    wordDictType::iterator pairPtr;
    wordDictType::iterator stop = wordMap.end();
    for (pairPtr = wordMap.begin(); pairPtr != stop; ++pairPtr)
        //
        // If word is same as previous, just print line number.
        //
        if (lastword == (*pairPtr).first)
            out << " " << (*pairPtr).second;
        else
        {
            //
            // First entry of word.
            //
            lastword = (*pairPtr).first;
            cout << endl << lastword << ": " << (*pairPtr).second;
        }
    cout << endl;
}

int main ()
{
    cout << "Concordance sample program, from Chapter 7" << endl;

    cout << "Enter text, then end-of-file:" << endl;
    concordance words;
    words.readText(cin);    
    words.printConcordance(cout);

    cout << "End of concordance sample program" << endl;

    return 0;
}
