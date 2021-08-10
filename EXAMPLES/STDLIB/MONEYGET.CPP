#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * moneyget.cpp - Example program for the money_get facet. 
 *                See Class Reference Section
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

#include <locale>
#include <sstream>

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  typedef istreambuf_iterator<char,char_traits<char> > iter_type;
  
  locale loc;
  string buffer("$100.02");
  string dest;
  long double ldest;
  ios_base::iostate state;
  iter_type end;

  // Get a money_get facet
  const money_get<char,iter_type>& mgf = 
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    use_facet<money_get<char,iter_type> >(loc);
#else
    use_facet(loc,(money_get<char,iter_type>*)0);
#endif

  {
    // Build an istringstream from the buffer and construct
    // a beginning iterator on it.
    istringstream ins(buffer);
    iter_type begin(ins);

    // Get a a string representation of the monetary value
    mgf.get(begin,end,false,ins,state,dest);
  }
  {
    // Build another istringstream from the buffer, etc.
    // so we have an iterator pointing to the beginning
    istringstream ins(buffer);
    iter_type begin(ins);

    // Get a a long double representation of the monetary value
    mgf.get(begin,end,false,ins,state,ldest);
  }
  cout << buffer << " --> " << dest << " --> " << ldest << endl;

  return 0;
}



