#include "stlexam.h"
#pragma hdrstop
/***************************************************************************
 *
 * ifstream.cpp - basic_ifstream example
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
 
//
// stdlib/examples/manual/ifstream.cpp
//
#include<iostream>
#include<fstream>
#include<iomanip>

int main ( )
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif 

  long   l= 20;
  const char   *ntbs="Le minot passait la piece a frotter";
  char   c;
  char   buf[50];

#ifndef _RWSTD_NO_EXCEPTIONS
  try {
#endif

    // create a read/write file-stream object on char
    // and attach it to an ifstream object
    ifstream in("ifstream.results.out",ios_base::in | ios_base::out |
		ios_base::trunc);

    if ( !in.is_open() ) 
#ifndef _RWSTD_NO_EXCEPTIONS
      throw(ios_base::failure("Open error"));
#else
    abort();
#endif

    // tie the ostream object to the ifstream object
    ostream out(in.rdbuf());   

    // output ntbs in out
    out << ntbs << endl;

    // seek to the beginning of the file
    in.seekg(0);

    // output each word on a separate line
    while ( in.get(c) )
    {
      if ( ifstream::traits_type::eq(c,' ') ) 
        cout << endl;
      else
        cout << c;
    }
    cout << endl << endl;

    // move back to the beginning of the file
    in.seekg(0); 

    // clear the state flags
    in.clear();

    // does the same thing as the previous code
    // output each word on a separate line
    while ( in >> buf )
      cout << buf << endl; 
    
    cout << endl << endl;

    // output the base info before each integer
    out << showbase;

    ostream::pos_type pos= out.tellp();

    // output l in hex with a field with of 20 
    out << hex << setw(20) << l << endl;

    // output l in oct with a field with of 20
    out << oct << setw(20) << l << endl;

    // output l in dec with a field with of 20
    out << dec << setw(20) << l << endl;

    // move back to the beginning of the file
    in.seekg(0);

    // output the all file
    cout << in.rdbuf();

    // clear the flags 
    in.clear(); 

    // seek the input sequence to pos  
    in.seekg(pos);
  
    int a,b,d;

    in.unsetf(ios_base::basefield);

    // read the previous outputted integer
    in >> a >> b >> d;

    // output 3 times 20
    cout << a << endl << b << endl << d << endl;

#ifndef _RWSTD_NO_EXCEPTIONS
  }
  catch( ios_base::failure var )
  {
    cout << var.what();
  }
#endif   
 
  return 0;
}




