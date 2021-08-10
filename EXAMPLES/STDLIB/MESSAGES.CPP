#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * messages.cpp - Example program for the messages facet.
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

#include <string>

#include <locale>
#include <iostream>
#include "rwstdmsg.h"

int main ()
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

  locale loc;

  // Get a reference to the messages<char> facet
  const messages<char>& mess =
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    use_facet<messages<char> >(loc);
#else
    use_facet(loc,(messages<char>*)0);
#endif

  // Open a catalog and try to grab
  // both some valid messages, and an invalid message
  string def("Message Not Found");
  messages<char>::catalog cat =
#ifdef __WIN32__
          mess.open("rwstdmsg.dll",loc);
#else
          mess.open("./rwstdmsg.cat",loc);
#endif
  if (cat != -1)
  {
    string msg0 = mess.get(cat,1,_RW_MSG_HELLO,def);
    string msg1 = mess.get(cat,1,_RW_MSG_GOODBYE,def);
    string msg2 = mess.get(cat,1,_RW_MSG_NOGOOD,def);  // invalid msg #
    string msg3 = mess.get(cat,2,_RW_MSG_TREES,def);

    mess.close(cat);
    cout << msg0 << endl << msg1 << endl
         << msg2 << endl << msg3 << endl;
  }
  else
    cout << "Unable to open message catalog" << endl;

  return 0;
}

