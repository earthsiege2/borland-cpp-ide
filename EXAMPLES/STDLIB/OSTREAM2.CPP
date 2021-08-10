#include "stlexam.h"
#pragma hdrstop
/***************************************************************************
 *
 * ostream2.cpp - ostream example
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
#include<sstream>

int main ( )
{
#ifndef _RWSTD_NO_NAMESPACE
   using namespace std;
#endif 
   
   float f= 3.14159;

#ifndef _RWSTD_NO_WIDE_CHAR
   wchar_t* s= L"Kenavo !";

   // create a read/write stringbuf object on wide char
   // and attach it to an wistringstream object
   wistringstream in( ios_base::in | ios_base::out );
      
   // tie the wostream object to the wistringstream object
   wostream out(in.rdbuf());

   out << L"test beginning !" << endl;

   // output f in scientific format
   out << scientific << f <<endl; 

   // store the current put-pointer position  
   wostream::pos_type pos = out.tellp();

   // output s 
   out << s << endl;   

   // output the all buffer to standard output
   wcout << in.rdbuf() << endl;

   // position the get-pointer
   in.seekg(pos);

   // output s
   wcout << in.rdbuf() << endl;         
#else

   char* s= "Kenavo !";

   // create a read/write stringbuf object on char
   // and attach it to an istringstream object
   istringstream in( ios_base::in | ios_base::out );
      
   // tie the wostream object to the istringstream object
   ostream out(in.rdbuf());

   out << "test beginning !" << endl;

   // output f in scientific format
   out << scientific << f <<endl; 

   // store the current put-pointer position  
   ostream::pos_type pos = out.tellp();

   // output s 
   out << s << endl;   

   // output the all buffer to standard output
   cout << in.rdbuf() << endl;

   // position the get-pointer
   in.seekg(pos);

   // output s
   cout << in.rdbuf() << endl; 
#endif

   return 0;
}
 


