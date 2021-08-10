#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * list.cpp - Example program of list class. See Class Reference Section
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
// Print out a list of strings.
//
ostream& operator<< (ostream& out, const list<string,allocator<string> >& l)
{
  copy(l.begin(), l.end(), 
       ostream_iterator<string,char,char_traits<char> >(out," "));
  return out;
}

int main ()
{
  //
  // Create a list of critters.
  //
  list<string,allocator<string> > critters;
  int i;
  //
  // Insert several critters.
  //
  critters.insert(critters.begin(),"antelope");
  critters.insert(critters.begin(),"bear");
  critters.insert(critters.begin(),"cat");
  //
  // Print out the list.
  //
  cout << critters << endl;
  // 
  // Change cat to cougar.
  //
  *find(critters.begin(),critters.end(),"cat") = "cougar";
  cout << critters << endl;
  //
  // Put a zebra at the beginning, an ocelot ahead of antelope,
  // and a rat at the end.
  //
  critters.push_front("zebra");
  critters.insert(find(critters.begin(),critters.end(),"antelope"),"ocelot");
  critters.push_back("rat");
  cout << critters << endl;
  //
  // Sort the list (Use list's sort function since the 
  // generic algorithm requires a random access iterator 
  // and list only provides bidirectional)
  //
  critters.sort();
  cout << critters << endl;
  //
  // Now let's erase half of the critters.
  //
  int half = critters.size() / 2;
  for (i = 0; i < half; ++i)
    critters.erase(critters.begin());
  cout << critters << endl;
  
  return 0;
}




