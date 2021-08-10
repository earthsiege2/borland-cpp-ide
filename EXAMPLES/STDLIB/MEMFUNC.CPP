#include "stlexam.h"
#pragma hdrstop
/**************************************************************************
 *
 * memfunc.cpp - Example program for mem_fun and other member function
 *               pointer wrappers.  See Class Reference Section.
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

#include <vector>
#include <functional>
#include <algorithm>

#ifdef _RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif     

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif        

//
// Very large city class
//
class MegaPolis
{
public:

  MegaPolis(char*  s = 0 , float n = 0):cityName(s),population(n) {;}
  // The following function cannot return void due to limitations in 
  // some current C++ implementations. 
  virtual size_t byPopulation()
  {
    cout<<cityName<<"(MegaPolis)"<<"\t\t\t"<<population<<endl;
    return 0;
  }
  float population;
protected:
  char* cityName;
};

//
// City and surrounding area class
//
class MetroPolis : public MegaPolis
{
public:
  MetroPolis(char*  s = 0 , float n = 0):MegaPolis(s,n){;}
  virtual size_t byPopulation()
  {
    cout<<cityName<<"(MetroPolis)"<<"\t\t\t"<<population<<endl;
    return 0;
  }
};

//
// Functor compares the size of two MeagPolis classes
//
struct GreaterPopulation
{
  bool operator()(MegaPolis* m1, MegaPolis* m2)
  {
    return m1->population<m2->population;
  }
} greater_pop;


int main()
{
  // 
  // Create a vector of very lareg cities
  //
  vector<MegaPolis*, allocator<MegaPolis*> > cityList;

  cityList.push_back(new  MegaPolis ("Calcutta",35));
  cityList.push_back(new  MegaPolis ("Tokyo",20));
  cityList.push_back(new  MegaPolis ("Delhi",10)); 
  cityList.push_back(new  MegaPolis ("Bombay",15));
  
  cityList.push_back(new  MetroPolis ("Cairo",5));
  cityList.push_back(new  MetroPolis ("New York",2.5));
  cityList.push_back(new  MetroPolis ("Los Angeles",3)); 
  cityList.push_back(new  MetroPolis ("Jakarta",1.5));
  
   // 
   // Now use mem_fun to pass byPopulation member function
   // of MegaPolis to the for_each function.
   //
  cout<<"City                    "<<" Population (in millions)    "<<endl;
  cout<<"-----                   "<<" -----------------------"<<endl;  
  for_each(cityList.begin(),cityList.end(),mem_fun(&MegaPolis::byPopulation));
  cout<<"..............After sorting..........................."<<endl;
  stable_sort(cityList.begin(),cityList.end(),greater_pop);
  for_each(cityList.begin(),cityList.end(),mem_fun(&MegaPolis::byPopulation));

  return 0;
}




