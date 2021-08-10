#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * tele.cpp - telephone directory sample program, from section 9.3.1
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

# include <map>
# include <algorithm>
# include <vector>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif
   
# include <string>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

typedef map<string, long, less<string>,allocator<string>  > friendMap;
typedef map<long, string, less<long>,allocator<long>  >   sortedMap;

//
// Utility functions used in telephone directory.
//

typedef friendMap::value_type entry_type;
typedef sortedMap::value_type sorted_entry_type;

#ifndef HPPA_WA
void printEntry (const entry_type & entry)
#else
void printEntry (const entry_type entry)
#endif
{
    cout << entry.first << ":" << entry.second << endl;
}

#ifndef HPPA_WA
void printSortedEntry (const sorted_entry_type & entry)
#else
void printSortedEntry (const sorted_entry_type entry)
#endif 
{
    cout << entry.first << ":" << entry.second << endl;
}

int prefix (const entry_type& entry) { return entry.second / 10000; }

bool prefixCompare (const entry_type & a, const entry_type & b)
{
    return prefix(a) < prefix(b);
}
    
class checkPrefix
{
  public:
    checkPrefix (int p) : testPrefix(p) { }
    int testPrefix;
    bool operator () (const entry_type& entry)
    {
        return prefix(entry)==testPrefix;
    }
};
            
class telephoneDirectory
{
  public:
    void addEntry (string name, long number) { database[name] = number; }
        
    void remove (string name) { database.erase(name); }
    
    void update (string name, long number)
    {
        remove(name);addEntry(name,number);
    }
        
    void displayDatabase()
    {
        for_each(database.begin(), database.end(), printEntry);
    }
    
    void displayPrefix(int);
    
    void displayByPrefix(); 
    
private:
    friendMap database;
};

void telephoneDirectory::displayPrefix (int prefix)
{
    cout << "Listing for prefix " << prefix << endl;
    map<string, long, less<string>,allocator<string>  >::iterator where;
    where = find_if(database.begin(), database.end(), checkPrefix(prefix));
    while (where != database.end())
    {
        printEntry(*where);
        where = find_if(++where, database.end(), checkPrefix(prefix));
    }
    cout << "end of prefix listing" << endl;
}

void telephoneDirectory::displayByPrefix ()
{
    cout << "Display by prefix" << endl;

    sortedMap sortedData;
    for (friendMap::iterator i = database.begin(); i != database.end(); i++)
        sortedData.insert(sortedMap::value_type((*i).second, (*i).first));
    for_each(sortedData.begin(), sortedData.end(), printSortedEntry);

    cout << "end display by prefix" << endl;
}

int main ()
{
    cout << "Telephone Directory sample program" << endl;

    telephoneDirectory friends;
    friends.addEntry("Samantha", 6342343);
    friends.addEntry("Brenda", 5436546);
    friends.addEntry("Fred", 7435423);
    friends.addEntry("Allen", 6348723);
    friends.displayDatabase();
    friends.displayPrefix(634);
    friends.displayByPrefix();
    
    cout << "End of telephone directory sample program" << endl;

    return 0;
}
