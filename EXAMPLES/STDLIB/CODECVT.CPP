#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * codecvt.cpp - Example program of codecvt facet. 
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
 
#include <sstream>
#include "codecvte.h"

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  mbstate_t state;

  // three strings to use as buffers
  string ins("\xfc \xcc \xcd \x61 \xe1 \xd9 \xc6 \xe6 \xf5");
  string ins2(ins.size(),'.');
  string outs(ins.size()/ex_codecvt().encoding(),'.');

  // Print initial contents of buffers
  cout << "Before:\n" << ins << endl;
  cout << ins2 << endl;
  cout << outs << endl << endl;

  // Initialize buffers
  string::iterator in_it = ins.begin();
  string::iterator out_it = outs.begin();
  string::const_iterator const_in_it = ins.begin();
  string::const_iterator const_out_it = outs.begin();

  // Create a user defined codecvt fact
  // This facet converst from ISO Latin 
  // Alphabet No. 1 (ISO 8859-1) to 
  // U.S. ASCII code page 437
  // This facet replaces the default for
  // codecvt<char,char,mbstate_t>
  locale loc(locale(),new ex_codecvt);

  // Now get the facet from the locale 
  const codecvt<char,char,mbstate_t>& cdcvt = 
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    use_facet<codecvt<char,char,mbstate_t> >(loc);
#else
    use_facet(loc,(codecvt<char,char,mbstate_t>*)0);
#endif

  // convert the buffer
  cdcvt.in(state,ins.begin(),ins.end(),const_in_it,
           outs.begin(),outs.end(),out_it);
	
  cout << "After in:\n" << ins << endl;
  cout << ins2 << endl;
  cout << outs << endl << endl;

  // Lastly, convert back to the original codeset
  in_it = ins.begin();
  out_it = outs.begin();
  cdcvt.out(state, outs.begin(),outs.end(),const_out_it,
            ins2.begin(),ins2.end(),in_it);
	
  cout << "After out:\n" << ins << endl;
  cout << ins2 << endl;
  cout << outs << endl;

  return 0;
}






