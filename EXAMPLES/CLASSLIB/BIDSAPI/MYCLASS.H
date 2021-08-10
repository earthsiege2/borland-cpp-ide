// ---------------------------------------------------------------------------
// Copyright (C) 1994 Borland International
//  myclass.h
//                                                              
// Description:                                                 
//    This header file is provided to demonstrate the container 
//       class libraries.                                       
//    This implements the user-defined class.                   
//    It defines the following member functions:                
//       (required for the direct containers)                   
//     - Copy constructor                                       
//     - Assignment operator                                    
//     - comparison operators ( ==, < )                         
//     - HashValue (only needed for the HashTable containers)   
//                                                              
//    Define DEBUG to see when the constructors and destructors 
//       are called. This is useful to track down memory leaks. 
// ---------------------------------------------------------------------------
#ifndef MYCLASS_H          // prevent header from
#define MYCLASS_H 1        // being included twice

#include <cstring.h>
#include <iostream.h>
#include <checks.h>

class MyClass
{
  public:
    MyClass();
    MyClass(const string& s);
    MyClass(const MyClass& mc);

    ~MyClass();
    
    MyClass& operator=(const MyClass& mc);
    int operator==(const MyClass& mc) const;
    int operator<(const MyClass& mc) const;
    unsigned HashValue() const;
    
    friend ostream& operator << (ostream&, const MyClass);

  private:

    string Str;
};

// 
// MyValue is to be used with TAssociation or TDictionary.
// 
class MyValue
{
  public:
    MyValue();
    MyValue(const string& s);
    MyValue(const MyValue& mv);
    
    ~MyValue();
  
    MyValue& operator=(const MyValue& mv);
    int operator==(const MyValue& mv) const;
    int operator<(const MyValue& mv) const;
    unsigned HashValue() const;

    friend ostream& operator << (ostream&, const MyValue);

  private:

    string Str;
};

#endif
