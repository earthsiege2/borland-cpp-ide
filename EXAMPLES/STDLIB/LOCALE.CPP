#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * locale.cpp - Example program for the  locale class. 
 *               See Class Reference Section
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

#include <string>
#include <vector>

#include <iostream>
#include "codecvte.h"


int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  locale loc;  // Default locale

  // Construct new locale using default locale plus
  // user defined codecvt facet
  // This facet converts from ISO Latin 
  // Alphabet No. 1 (ISO 8859-1) to 
  // U.S. ASCII code page 437
  // This facet replaces the default for
  // codecvt<char,char,mbstate_t>
  locale my_loc(loc,new ex_codecvt);

  // imbue modified locale onto cout
  locale old = cout.imbue(my_loc);
  cout << "A \x93 jolly time was had by all" << endl;

  cout.imbue(old);
  cout << "A jolly time was had by all" << endl;

  // Create a vector of strings 
  vector<string,allocator<string> > v;
  v.insert(v.begin(),"antelope");
  v.insert(v.begin(),"bison");
  v.insert(v.begin(),"elk");

  copy(v.begin(),v.end(),
       ostream_iterator<string,char,char_traits<char> >(cout," "));
  cout << endl;

  // Sort the strings using the locale as a comparitor
  sort(v.begin(),v.end(),loc);

  copy(v.begin(),v.end(),
       ostream_iterator<string,char,char_traits<char> >(cout," "));

  cout << endl;
  return 0;
}

