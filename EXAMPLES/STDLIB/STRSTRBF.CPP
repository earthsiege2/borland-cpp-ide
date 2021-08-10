#include "stlexam.h"
#pragma hdrstop
/***************************************************************************
 *
 * strstreambuf.cpp - strstreambuf example.  See Class Reference Section.
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
#include<strstream>
#include<iomanip>

int main ( )
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif 

  // create a read/write strstreambuf object
  // and attach it to an ostrstream object
  ostrstream out;

  // tie the istream object to the ostrstream object
  istream in(out.rdbuf());   

  // output to out_1
  out << "anticonstitutionellement is a big word !!!";

  // create a NTBS 
  char *p ="Le rat des villes et le rat des champs";

  // output the NTBS
  out << p << endl;   

  // resize the buffer
  if ( out.rdbuf()->pubsetbuf(0,5000) )
   cout << endl << "Success in allocating the buffer" << endl;

  // output the all buffer to stdout
  cout << in.rdbuf( );

  // output the decimal conversion of 100 in hex
  // with right padding and a width field of 200
  out << dec << setfill('!') << setw(200) << 0x100 << endl;  
  
  // output the content of the input sequence to stdout
  cout << in.rdbuf( ) << endl;

  // number of elements in the output sequence
  cout << out.rdbuf()->pcount() << endl;

  // resize the buffer to a minimum size
  if ( out.rdbuf()->pubsetbuf(0,out.rdbuf()->pcount()+1) )
   cout << endl << "Success in resizing the buffer" << endl;

  // output the content of the all array object
  cout << out.rdbuf()->str() << endl;

  return 0;
 }



