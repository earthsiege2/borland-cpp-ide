#include "stlexam.h"
#pragma hdrstop
/***************************************************************************
 *
 * ostreambuf_iterator.cpp - ostreambuf_iterator example
 *                           See Class Reference Section
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
#include<fstream>

int main ( )
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif 

  // create a filebuf object
  filebuf buf;

  // open the file iter_out and link it to the filebuf object
  buf.open("iter_out", ios_base::in | ios_base::out | ios_base::trunc );

  // create an ostreambuf_iterator and link it to 
  // the filebuf object
  ostreambuf_iterator<char,char_traits<char> > out_iter(&buf);

  // output into the file using the ostreambuf_iterator
  for(char i=64; i<127; i++ )
   out_iter = i;

  // seek to the beginning of the file
  buf.pubseekpos(0);
  
  // create an istreambuf_iterator and link it to 
  // the filebuf object
  istreambuf_iterator<char,char_traits<char> > in_iter(&buf);

  // construct an end of stream iterator
  istreambuf_iterator<char,char_traits<char> > end_of_stream_iterator;

  cout << endl;

  // output the content of the file
  while( !in_iter.equal(end_of_stream_iterator) )

  // use both operator++ and operator*
  cout << *in_iter++;

  cout << endl;

  return 0;
}

 


