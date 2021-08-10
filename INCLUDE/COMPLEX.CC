#ifndef __COMPLEX_CC
#define __COMPLEX_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig

/***************************************************************************
 *
 * complex - Declaration for the Standard Library complex class
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

#include <stdcomp.h>

#ifdef _RW_STD_IOSTREAM
  #include <sstream>
#endif

#ifndef _RWSTD_NO_NAMESPACE 
namespace std {
#endif

  template <class T>
  complex<T> log10 (const complex<T>& a)
  {
#ifndef _RWSTD_MULTI_THREAD
    static 
#endif
    const T log10e = _RWSTD_C_SCOPE_LOG10(_RWSTD_C_SCOPE_EXP(T(1)));
    return log10e * log(a);
  }

#ifdef _RW_STD_IOSTREAM
  template <class T,class charT, class traits>
  basic_istream<charT, traits >&  
  _RWSTDExportTemplate operator>> (basic_istream<charT, traits >& is,complex<T>& x)
#else
  template <class T>
  istream& _RWSTDExportTemplate operator>> (istream& is, complex<T>& x)
#endif
  {
    //
    // operator >> reads a complex number x in the form
    // u
    // (u)
    // (u, v)
    //
    T u = 0, v = 0;
    char c;

    is >> c;
    if (c == '(')
    {
      is >> u >> c;
      if (c == ',') { is >> v  >> c;}
      if (c != ')' )
      {
#ifdef _RW_STD_IOSTREAM
        is.setstate(ios::failbit);
#else
        is.clear(ios::failbit);
#endif
      }
    } 
    else
    {
      is.putback(c);
      is >> u;
    }

    if (is)
      x = complex<T>(u,v);

    return is;
  }

#ifdef _RW_STD_IOSTREAM
  #include <sstream>
  template <class T,class charT,class traits>
  basic_ostream<charT,traits >& _RWSTDExportTemplate operator<< (basic_ostream<charT, traits >& os,const complex<T>& x)
  {
    basic_ostringstream<charT, traits, allocator<charT> > s;
    s.flags(os.flags());
    s.imbue(os.getloc());
    s.precision(os.precision());
    s << '(' << x.real() << "," << x.imag() << ')';
    return os << s.str();
  }
#else
  template <class T>
  ostream& _RWSTDExportTemplate operator<< (ostream& os, const complex<T>& x)
  {
    os << '(' << x.real() << "," << x.imag() << ')';
    return os;
  }
#endif
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __COMPLEX_CC */
