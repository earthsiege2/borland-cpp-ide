#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * ostream.cpp - Source for the Standard Library output streams.
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-1999 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software – Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/

#include <ostream>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  /*
   * ostream& operator<< (ostream& os, const char *)
   */
  
#ifndef _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION
#ifdef _RWSTD_NO_FUNC_PARTIAL_SPEC
  ostream&
  _RWSTDExport operator<< ( ostream& os, const char *s)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      if ( s )
      {   
	ostream::sentry opfx(os);
	if (opfx)
	{
	  int   dlen = char_traits<char>::length(s);
	  int   pad = os.width() - dlen;

	  // place right padding
	  if(!(os.flags() & ios_base::adjustfield) || ( os.flags() & ios_base::right) )
	  {
	    while(--pad >= 0)
	    {
	      if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(os.fill()),
						 char_traits<char>::eof())) {
		err = ios_base::badbit;
		break;
	      }
	    }
	  }
         
	  // output internal padding
	  if(os.good() && (os.flags() & ios_base::internal))
	  {
	    while(--pad >= 0)
	    {
	      if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(os.fill()),
						 char_traits<char>::eof())) {
		err = ios_base::badbit;
		break;
	      }
	    }
	  }

	  if(os.good() && dlen)
	  {
	    if(os.rdbuf() && (os.rdbuf()->sputn(s, dlen) != dlen))
	      err = ios_base::badbit;
	  }

	  // output left padding. 
	  if(os.good() && (os.flags() & ios_base::left))
	  {
	    while(--pad >= 0)
	    {
	      if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(os.fill()),
						 char_traits<char>::eof())) {
		err = ios_base::badbit;
		break;
	      }
	    }
	  }

	  os.width(0);
	}
      }
      else
	err = ios_base::badbit;

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
	os.setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS

    if ( err ) os.setstate(err);  
    return os;
  }
#endif  // _RWSTD_NO_FUNC_PARTIAL_SPEC 

  /*
   * ostream& operator<<( ostream<char, traits>&, char )
   *
   */

#ifdef _RWSTD_NO_FUNC_PARTIAL_SPEC
  ostream&
  _RWSTDExport operator<< (ostream& os, char c)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      ostream::sentry opfx(os); 

      if(opfx) 
      {
	int   pad = os.width() - 1;

	// place right padding
        if(!(os.flags() & ios_base::adjustfield) || ( os.flags() & ios_base::right) )
	{
	  while(--pad >= 0)
	  {
	    if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(os.fill()),
					       char_traits<char>::eof())) {
	      err = ios_base::badbit;
	      break;
	    }
	  }
	}
         
	// output internal padding
	if(os.good() && (os.flags() & ios_base::internal))
	{
	  while(--pad >= 0)
	  {
	    if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(os.fill()),
					       char_traits<char>::eof())) {
	      err = ios_base::badbit;
	      break;
	    }
	  }
	}

	if(os.good())
	{
	  if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(c),
					     char_traits<char>::eof())) 
	    err = ios_base::badbit;      
	}
 
	// output left padding. 
	if(os.good() && (os.flags() & ios_base::left))
	{
	  while(--pad >= 0)
	  {
	    if( char_traits<char>::eq_int_type(os.rdbuf()->sputc(os.fill()),
					       char_traits<char>::eof())) {
	      err = ios_base::badbit;
	      break;
	    }
	  }
	}

	os.width(0);      
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
	os.setstate(ios_base::failbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS 

    if ( err ) os.setstate(err); 
    return os;
  }
#endif // _RWSTD_NO_FUNC_PARTIAL_SPEC 
#endif // _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION 
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

