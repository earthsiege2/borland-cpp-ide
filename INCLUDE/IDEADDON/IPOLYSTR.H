/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  ipolystr.h
  Created: 09/29/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

  IPolyString interface

  PolyString's represent a string that once set, never changes in content
  during its lifetime. Conversions are provided on demand between 'C', Pascal, 
  and BSTR style strings. 

  !!!!  
  NOTE: CONVERSIONS NOT YET IMPLEMENTED, CURRENTLY, ONLY 'C' STRING SUPPORT
  IS HOOKED UP!
  
  THERE WILL PROBABLY BE A PATCH TO FIX THIS SOON.
  !!!!
    
  Conversions of a particular string are never performed more than once, 
  since they are kept in memory until the PolyString is released by all 
  clients.

  If a function returns a PolyString, the caller of the function is responsible
  for releasing the PolyString when finished with it.

  If you are passing a PolyString as an argument to a function, the receiver
  of the PolyString is responsible for Releasing it sometime after receiving
  it. 

  If you return a PolyString from your function or pass a PolyString to a 
  function and aren't finished with the string, remember to bump up the 
  reference count and release it when you are finished with it.

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef _IPOLYSTR_H_
#define _IPOLYSTR_H_

#include <objbase.h>
#include <ideaddon\IPolyStr.uid>

class IPolyString : public IUnknown {
 public:
  //
  // Use one of the following 'Set' methods to initialize a polystring.
  // Strings can only be 'set' once. If a function returns a polystring,
  // unless documented otherwise, it will already have been set. Calling
  // 'set' on a polystring that has already been set will silently fail.
  //
  virtual void SetBstr( const BSTR bstr ) = 0;     // BSTR style string
  virtual void SetCstr( const char * cstr ) = 0;    // null-terminated string
  virtual void SetPstr( const char * pstr ) = 0;    // pascal style string

  //
  // The 'get' methods return the string in various forms. Conversion is
  // performed on demand only. These all return a pointer to the string
  // owned by the polystring object. If you want the string to have a 
  // lifetime not tied to the polystring, you should copy it. Otherwise
  // just call Release on the polystring when you are finished with the 
  // string.
  // 
  // NEVER RELEASE A POLYSTRING UNTIL YOU ARE THROUGH WITH THE POINTER
  // OR BSTR RETURNED BY ANY GET METHOD!
  //
  virtual BSTR GetBstr() = 0;
  virtual const char * GetCstr() = 0;
  virtual const char * GetPstr() = 0;
};

#endif
