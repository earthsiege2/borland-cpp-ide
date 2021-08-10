#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * timeget.cpp - Example program for the time_get facet. 
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

#include <locale>
#include <sstream>
#include <time.h>

#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif

// Print out a tm struct
ostream& operator<< (ostream& os, const struct tm& t)
{
  os << "Daylight Savings = " << t.tm_isdst << endl;
  os << "Day of year      = " << t.tm_yday << endl;
  os << "Day of week      = " << t.tm_wday << endl;
  os << "Year             = " << t.tm_year << endl;
  os << "Month            = " << t.tm_mon << endl;
  os << "Day of month     = " << t.tm_mday << endl;
  os << "Hour             = " << t.tm_hour << endl;
  os << "Minute           = " << t.tm_min << endl;
  os << "Second           = " << t.tm_sec << endl;
  return os;
}

int main ()
{
  typedef istreambuf_iterator<char,char_traits<char> > iter_type;
  
  locale loc;
  time_t tm = time(NULL);
  struct tm* tmb = localtime(&tm);
  struct tm timeb;
  memcpy(&timeb,tmb,sizeof(struct tm));
  ios_base::iostate state;
  iter_type end;

  // Get a time_get facet
  const time_get<char,iter_type>& tg = 
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    use_facet<time_get<char,iter_type> >(loc);
#else
    use_facet(loc,(time_get<char,iter_type>*)0);
#endif

  cout << timeb << endl;
  {
    // Build an istringstream from the buffer and construct
    // beginning and ending iterators on it.
    istringstream ins("12:46:32");
    iter_type begin(ins);

    // Get the time
    tg.get_time(begin,end,ins,state,&timeb);
  }
  cout << timeb << endl;
  {
    // Get the date
    istringstream ins("Dec 6 1996");
    iter_type begin(ins);
    tg.get_date(begin,end,ins,state,&timeb);
  }
  cout << timeb << endl;
  {
    // Get the weekday
    istringstream ins("Tuesday");
    iter_type begin(ins);
    tg.get_weekday(begin,end,ins,state,&timeb);
  }
  cout << timeb << endl;
  return 0;
}

