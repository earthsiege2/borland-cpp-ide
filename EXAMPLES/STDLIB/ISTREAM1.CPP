#include "stlexam.h"
#pragma hdrstop
/***************************************************************************
 *
 * istream1.cpp - istream example
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
 
#include<iostream>
#include<istream>
#include<fstream>

int main ( )
{
#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif 
 
  float f= 3.14159;
  int   i= 3;
  char  s[200];

  // open a file for read and write operations 
  ofstream out("example", ios_base::in | ios_base::out
               | ios_base::trunc);

  // tie the istream object to the ofstream filebuf 
  istream  in (out.rdbuf());

  // output to the file
  out << "He lifted his head and pondered." << endl;
  out << f << endl;
  out << i << endl;
  
  // seek to the beginning of the file
  in.seekg(0);
  
  f = i = 0;

  // read from the file using formatted functions
  in >> s >> f >> i;

  // seek to the beginning of the file
  in.seekg(0,ios_base::beg);

  // output the all file to the standard output
  cout << in.rdbuf();

  // seek to the beginning of the file
  in.seekg(0);
 
  // read the first line in the file
  // "He lifted his head and pondered."
  in.getline(s,100);

  cout << s << endl;

  // read the second line in the file
  // 3.14159
  in.getline(s,100);

  cout << s << endl;

  // seek to the beginning of the file
  in.seekg(0);

  // read the first line in the file
  // "He lifted his head and pondered."
  in.get(s,100);

  // remove the newline character
  in.ignore();

  cout << s << endl;

  // read the second line in the file
  // 3.14159
  in.get(s,100);

  cout << s << endl;

  // remove the newline character
  in.ignore();

  // store the current file position   
  istream::pos_type position = in.tellg();
 
  out << "replace the int" << endl;

  // move back to the previous saved position
  in.seekg(position);   

  // output the remain of the file
  // "replace the int"
  // this is equivalent of
  // cout << in.rdbuf();
  while( !ifstream::traits_type::eq_int_type( in.peek(),
                                              ifstream::traits_type::eof()) )
   cout << ifstream::traits_type::to_char_type(in.get()); 
 
  cout << "\n\n\n" << flush;

  return 0;
}




