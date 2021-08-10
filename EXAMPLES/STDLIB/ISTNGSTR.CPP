#include "stlexam.h"
#pragma hdrstop
/***************************************************************************
 *
 * istringstream.cpp - basic_istringstream example
 *                     See Class Reference Section
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
 
#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>

int main ( )
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif 

  long   l= 20;

#ifndef _RWSTD_NO_WIDE_CHAR
  wchar_t *ntbs=L"Il avait l'air heureux";
  wchar_t c;
  wchar_t buf[50];

  // create a read/write string-stream object on wide char
  // and attach it to an wistringstream object
  wistringstream in(ios_base::in | ios_base::out);

  // tie the ostream object to the wistringstream object
  wostream out(in.rdbuf());   

  // output ntbs in out
  out << ntbs;

  // output each word on a separate line
  while ( in.get(c) )
   {
     if ( wistringstream::traits_type::eq(c,L' ') ) 
      wcout << endl;
     else
      wcout << c;
   }
  wcout << endl << endl;

  // move back the input sequence to the beginning
  in.seekg(0); 

  // clear the state flags
  in.clear();

  // does the same thing as the previous code
  // output each word on a separate line
  while ( in >> buf )
   wcout << buf << endl; 
    
  wcout << endl << endl;
#endif

  // create a tiny string object
  string test_string("Il dormait pour l'eternite");

  // create a read/write string-stream object on char
  // and attach it to an istringstream object
  istringstream in_bis(ios_base:: in | ios_base::out |
                       ios_base::app );

  // create an ostream object
  ostream out_bis(in_bis.rdbuf());  

  // initialize the string-buffer with test_string
  in_bis.str(test_string);

  out_bis << endl;

  // output the base info before each integer
  out_bis << showbase;

  ostream::pos_type pos= out_bis.tellp();

  // output l in hex with a field with of 20 
  out_bis << hex << setw(20) << l << endl;

  // output l in oct with a field with of 20
  out_bis << oct << setw(20) << l << endl;

  // output l in dec with a field with of 20
  out_bis << dec << setw(20) << l << endl;

  // output the all buffer
  cout << in_bis.rdbuf();

  // seek the input sequence to pos  
  in_bis.seekg(pos);

  int a,b,d;

  in_bis.unsetf(ios_base::basefield);

  // read the previous outputted integer
  in_bis >> a >> b >> d;

  // output 3 times 20
  cout << a << endl << b << endl << d << endl;

  return 0;
 }



