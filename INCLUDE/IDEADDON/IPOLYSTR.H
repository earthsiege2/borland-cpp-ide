/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

	ipolystr.h
	Created: 09/29/95
	Copyright (c) 1995, Borland International
	$Header:   Y:\admin\bride\addon\deliver\interfac\ipolystr.h_v   1.20   18 Nov 1996 11:29:48   JDOUGLAS  $
	$Revision:   1.20  $

	IPolyString interface

	PolyString's represent a string that once set, never changes in content
	during its lifetime. Conversions are provided on demand between 'C'  
	and BSTR style strings. 
   
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
   
   
   Note: Originally, 32-bit Delphi string support was planned, but this turned
   out to be undesirable, since those strings are memory managed and ref-counted
   by the Delphi shared memory manager. It is also a trivial matter to do the 
   conversion to a 'C' string and back in Delphi. We didn't realize this until 
   after the IPolyString interface was frozen, so the GetPstr()/SetPstr() 
   methods are defined, but they have no effect.

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/	
#ifndef _IPOLYSTR_H_
#define _IPOLYSTR_H_

#include <objbase.h>
#include	<ideaddon\IPolyStr.uid>
#include <ideaddon\common.h>

class IPolyString : public IUnknown {
 public:
	//
	//	Use one of the following 'Set' methods to initialize a polystring.
	// Strings can only be 'set' once. If a function returns a polystring,
	// unless documented otherwise, it will already have been set. Calling
	// 'set' on a polystring that has already been set will silently fail.
	//
	virtual void BCWADDON_CMETHOD SetBstr( const BSTR bstr ) = 0;			// BSTR style string
	virtual void BCWADDON_CMETHOD SetCstr( const char * cstr ) = 0;		// null-terminated string
   
   // Note: SetPstr(), which has never been hooked up, is now obsolete! 
   // (See the comment in the overview at the top of this file.)
	virtual void BCWADDON_CMETHOD SetPstr( const char * pstr ) = 0;	

	//
	//	The 'get' methods return the string in various forms. Conversion is
	// performed on demand only. These all return a pointer to the string
	// owned by the polystring object. If you want the string to have a 
	// lifetime not tied to the polystring, you should copy it. Otherwise
	// just call Release on the polystring when you are finished with the 
	// string.
	// 
	//	Important: BSTR's returned from 'GetBstr' are 'owned' by the IPolyString
	// object and should not be freed using 'SysFreeStr'. When IPolyString's
	// ref count reaches zero, it will make the 'SysFreeStr' call. If you 
	// wish to hand off a BSTR to another interface or wish the BSTR to have
	// a lifetime not linked to the IPolyString object, use the OLE function
   // SysAllocString() to make a copy of the BSTR.
	// 
	virtual BSTR BCWADDON_CMETHOD GetBstr() = 0;
	virtual const char * BCWADDON_CMETHOD GetCstr() = 0;
   
   // Note: GetPstr(), which has never been hooked up, is now obsolete! 
   // (See the comment in the overview at the top of this file.)
	virtual const char * BCWADDON_CMETHOD GetPstr() = 0;
};

#endif

