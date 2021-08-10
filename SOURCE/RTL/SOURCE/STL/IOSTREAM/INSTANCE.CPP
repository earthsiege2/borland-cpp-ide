#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * instance.cpp - Instantiations of the Standard Library iostream. 
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

#include <iostream>   
#include <fstream>
#include <sstream>
#include <iomanip>
#include <complex>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION
  template class _RWSTDExportTemplate basic_istream<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_ostream<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_streambuf<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_ios<char, char_traits<char> >;
  template class _RWSTDExportTemplate istreambuf_iterator<char, char_traits<char> >;
  template class _RWSTDExportTemplate ostreambuf_iterator<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_iostream<char, char_traits<char> >; 

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION

  template basic_istream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&, char* );

  template basic_istream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&, char& );

#ifndef _RWSTD_NO_SIGNED_CHAR_IN_STREAMS

  template basic_ostream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator << ( basic_ostream< char, char_traits<char> >&, signed char );

  template basic_ostream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator << ( basic_ostream< char, char_traits<char> >&, const signed char* );

  template basic_ostream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator << ( basic_ostream< char, char_traits<char> >&, unsigned char );

  template basic_ostream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator << ( basic_ostream< char, char_traits<char> >&, const unsigned char* );

  template basic_istream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&, signed char& );

  template basic_istream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&, unsigned char& );

#if !defined(HPPA_WA) && !defined(_RWSTD_NO_FUNC_PARTIAL_SPEC)
  template basic_ostream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator << ( basic_ostream< char, char_traits<char> >&, const char* );

  template basic_ostream< char, char_traits<char> >& 
    operator << ( basic_ostream< char, char_traits<char> >&, char );
#endif // _RWSTD_NO_FUNC_PARTIAL_SPEC 

  template basic_istream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&, signed char* );

  template basic_istream< char, char_traits<char> >& 
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&, unsigned char* );

#endif // _RWSTD_NO_SIGNED_CHAR_IN_STREAMS 

#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION 

#ifndef _RWSTD_NO_WIDE_CHAR
  template class basic_istream<wchar_t, char_traits<wchar_t> >;
  template class basic_ostream<wchar_t, char_traits<wchar_t> >;
  template class basic_streambuf<wchar_t, char_traits<wchar_t> >;
  template class basic_ios<wchar_t, char_traits<wchar_t> >;
  template class istreambuf_iterator<wchar_t, char_traits<wchar_t> >;
  template class ostreambuf_iterator<wchar_t, char_traits<wchar_t> >;
  template class basic_iostream<wchar_t, char_traits<wchar_t> >;

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION
  template basic_ostream< wchar_t, char_traits<wchar_t> >& 
    operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, wchar_t );

  template basic_ostream< wchar_t, char_traits<wchar_t> >& 
    operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, const wchar_t* );

  template basic_istream< wchar_t, char_traits<wchar_t> >& 
    operator >> ( basic_istream< wchar_t, char_traits<wchar_t> >&, wchar_t& );

  template basic_istream< wchar_t, char_traits<wchar_t> >& 
    operator >> ( basic_istream< wchar_t, char_traits<wchar_t> >&, wchar_t* );

#ifndef _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION
  template basic_ostream< wchar_t, char_traits<wchar_t> >& 
    operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, char );

  template basic_ostream< wchar_t, char_traits<wchar_t> >& 
    operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, const char* );
#endif // _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION
#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION 
#endif // _RWSTD_NO_WIDE_CHAR

#else

#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate basic_istream<char, char_traits<char> >
#pragma instantiate basic_ostream<char, char_traits<char> >
#pragma instantiate basic_streambuf<char, char_traits<char> >
#pragma instantiate basic_ios<char, char_traits<char> >
#pragma instantiate istreambuf_iterator<char, char_traits<char> >
#pragma instantiate ostreambuf_iterator<char, char_traits<char> >
#pragma instantiate basic_iostream<char, char_traits<char> >

#pragma instantiate basic_ostream< char, char_traits<char> >& operator <<  ( basic_ostream< char, char_traits<char> >&, unsigned char )

#pragma instantiate basic_ostream< char, char_traits<char> >& operator << ( basic_ostream< char, char_traits<char> >&, signed char )

#pragma instantiate basic_ostream< char, char_traits<char> >& operator << ( basic_ostream< char, char_traits<char> >&, const unsigned char* )

#pragma instantiate basic_ostream< char, char_traits<char> >& operator << ( basic_ostream< char, char_traits<char> >&, const signed char* )

#pragma instantiate basic_istream< char, char_traits<char> >& operator >>  ( basic_istream< char, char_traits<char> >&, unsigned char& )

#pragma instantiate basic_istream< char, char_traits<char> >& operator >> ( basic_istream< char, char_traits<char> >&, signed char& )

#pragma instantiate basic_istream< char, char_traits<char> >& operator >> ( basic_istream< char, char_traits<char> >&, unsigned char* )

#pragma instantiate basic_istream< char, char_traits<char> >& operator >> ( basic_istream< char, char_traits<char> >&, signed char* )

#pragma instantiate basic_istream< char, char_traits<char> >& operator >> ( basic_istream< char, char_traits<char> >&, char* )

#pragma instantiate basic_istream< char, char_traits<char> >& operator >> ( basic_istream< char, char_traits<char> >&, char& )

#ifdef _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION
#pragma instantiate basic_ostream< char, char_traits<char> >& operator << ( basic_ostream< char, char_traits<char> >&, const char* )

#pragma instantiate basic_ostream< char, char_traits<char> >& operator << ( basic_ostream< char, char_traits<char> >&, char )
#endif // _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate basic_istream<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_ostream<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_streambuf<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_ios<wchar_t, char_traits<wchar_t> >
#pragma instantiate istreambuf_iterator<wchar_t, char_traits<wchar_t> >
#pragma instantiate ostreambuf_iterator<wchar_t, char_traits<wchar_t> > 
#pragma instantiate basic_iostream<wchar_t, char_traits<wchar_t> >

#pragma instantiate basic_istream< wchar_t, char_traits<wchar_t> >& operator >> ( basic_istream< wchar_t, char_traits<wchar_t> >&, wchar_t& )

#pragma instantiate basic_istream< wchar_t, char_traits<wchar_t> >& operator >> ( basic_istream< wchar_t, char_traits<wchar_t> >&, wchar_t* )

#pragma instantiate basic_ostream< wchar_t, char_traits<wchar_t> >& operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, wchar_t )

#pragma instantiate basic_ostream< wchar_t, char_traits<wchar_t> >& operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, const wchar_t* )

#ifndef _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION
#pragma instantiate basic_ostream< wchar_t, char_traits<wchar_t> >& operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, char )

#pragma instantiate basic_ostream< wchar_t, char_traits<wchar_t> >& operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&, const char* )
#endif
#endif  // _RWSTD_NO_WIDE_CHAR
#endif  // _RWSTD_NO_INSTANTIATE
#endif  // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION
  template class _RWSTDExportTemplate basic_filebuf<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_ifstream<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_ofstream<char, char_traits<char> >;
  template class _RWSTDExportTemplate basic_fstream<char, char_traits<char> >;

#ifndef _RWSTD_NO_WIDE_CHAR
  template class _RWSTDExportTemplate basic_filebuf<wchar_t, char_traits<wchar_t> >;
  template class _RWSTDExportTemplate basic_ifstream<wchar_t, char_traits<wchar_t> >;
  template class _RWSTDExportTemplate basic_ofstream<wchar_t, char_traits<wchar_t> >;
  template class _RWSTDExportTemplate basic_fstream<wchar_t, char_traits<wchar_t> >;

#endif // _RWSTD_NO_WIDE_CHAR
#else

#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate basic_filebuf<char, char_traits<char> >
#pragma instantiate basic_ifstream<char, char_traits<char> >
#pragma instantiate basic_ofstream<char, char_traits<char> >
#pragma instantiate basic_fstream<char, char_traits<char> >

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate basic_filebuf<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_ifstream<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_ofstream<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_fstream<wchar_t, char_traits<wchar_t> >

#endif // _RWSTD_NO_WIDE_CHAR
#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

  template class smanip<int>;
  template class smanip_fill<char, char_traits<char> >;

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION
  template basic_istream<char, char_traits<char> >& 
   _RWSTDExportTemplate ws(basic_istream<char, char_traits<char> >&);
#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION

#ifndef _RWSTD_NO_WIDE_CHAR

  template class smanip_fill<wchar_t, char_traits<wchar_t> >;

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION
  template basic_istream<wchar_t, char_traits<wchar_t> >& 
   _RWSTDExportTemplate ws(basic_istream<wchar_t, char_traits<wchar_t> >&);
#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION

#endif // _RWSTD_NO_WIDE_CHAR 
#else  // _RWSTD_NO_EXPLICIT_INSTANTIATION 

#ifndef _RWSTD_NO_INSTANTIATE

#pragma instantiate smanip<int>
#pragma instantiate smanip_fill<char, char_traits<char> >
#pragma instantiate basic_istream<char, char_traits<char> >& ws(basic_istream<char, char_traits<char> >&)

#ifndef _RWSTD_NO_WIDE_CHAR

#pragma instantiate smanip_fill<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_istream<wchar_t, char_traits<wchar_t> >& ws(basic_istream<wchar_t, char_traits<wchar_t> >&)
 
#endif // _RWSTD_NO_WIDE_CHAR 
#endif // _RWSTD_NO_INSTANTIATE 
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION 

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION
  template class _RWSTDExportTemplate basic_stringbuf<char, char_traits<char>, allocator<char> >;
  template class _RWSTDExportTemplate basic_istringstream<char, char_traits<char>, allocator<char> >;
  template class _RWSTDExportTemplate basic_ostringstream<char, char_traits<char>, allocator<char> >;
  template class _RWSTDExportTemplate basic_stringstream<char, char_traits<char>, allocator<char> >;

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION
  template basic_istream< char, char_traits<char> >&
    _RWSTDExportTemplate operator >> ( basic_istream< char, char_traits<char> >&,
                                       basic_string< char, char_traits<char>, allocator<char> >& );

  template basic_ostream< char, char_traits<char> >&
    _RWSTDExportTemplate operator << ( basic_ostream< char, char_traits<char> >&,
                                       const basic_string< char, char_traits<char>, allocator<char> >& );
  template basic_istream< char, char_traits<char> >&
    _RWSTDExportTemplate getline( basic_istream< char, char_traits<char> >&,
                                  basic_string< char, char_traits<char>, allocator<char> >&, char );
#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION

#ifndef _RWSTD_NO_WIDE_CHAR
  template class _RWSTDExportTemplate basic_stringbuf<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >;
  template class _RWSTDExportTemplate basic_istringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >;
  template class _RWSTDExportTemplate basic_ostringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >;
  template class _RWSTDExportTemplate basic_stringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >;

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION
  template basic_istream< wchar_t, char_traits<wchar_t> >&
    _RWSTDExportTemplate operator >> ( basic_istream< wchar_t, char_traits<wchar_t> >&,
                                       basic_string< wchar_t, char_traits<wchar_t>, allocator<wchar_t> >& );

  template basic_ostream< wchar_t, char_traits<wchar_t> >&
    _RWSTDExportTemplate operator << ( basic_ostream< wchar_t, char_traits<wchar_t> >&,
                                       const basic_string< wchar_t, char_traits<wchar_t>, allocator<wchar_t> >& );
  template basic_istream< wchar_t, char_traits<wchar_t> >&
    _RWSTDExportTemplate getline( basic_istream< wchar_t, char_traits<wchar_t> >&,
                                  basic_string< wchar_t, char_traits<wchar_t>, allocator<wchar_t> >&, wchar_t );
#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION 
#endif // _RWSTD_NO_WIDE_CHAR
#else

#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate basic_stringbuf<char, char_traits<char>, allocator<char> >
#pragma instantiate basic_istringstream<char, char_traits<char>, allocator<char> >
#pragma instantiate basic_ostringstream<char, char_traits<char>, allocator<char> >
#pragma instantiate basic_stringstream<char, char_traits<char>, allocator<char> >

#pragma instantiate basic_istream< char, char_traits<char> >& getline( basic_istream< char, char_traits<char> >&, basic_string< char, char_traits<char>, allocator<char> >&, char  )

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate basic_stringbuf<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_istringstream<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_ostringstream<wchar_t, char_traits<wchar_t> >
#pragma instantiate basic_stringstream<wchar_t, char_traits<wchar_t> >

#pragma instantiate basic_istream< wchar_t, char_traits<wchar_t> >& getline( basic_istream< wchar_t, char_traits<wchar_t> >&, basic_string< wchar_t, char_traits<wchar_t>, allocator<wchar_t> >&, wchar_t  )

#endif // _RWSTD_NO_WIDE_CHAR 
#endif // _RWSTD_NO_INSTANTIATE 
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION 
#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

  // _EXPLICIT Instantiations
#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION
  template istream& _RWSTDExportTemplate 
    operator>> (istream& is, complex<float>& x);
  template istream&  _RWSTDExportTemplate 
    operator>> (istream& is, complex<double>& x);
  template istream&  _RWSTDExportTemplate 
    operator>> (istream& is, complex<long double>& x);
  template ostream&  _RWSTDExportTemplate 
    operator<< (ostream& os, const complex<float>& x);
  template ostream&  _RWSTDExportTemplate 
    operator<< (ostream& os, const complex<double>& x);
  template ostream&  _RWSTDExportTemplate 
    operator<< (ostream& os, const complex<long double>& x);
#endif // _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATION 
#else
#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate istream& operator>>(istream& is, complex<float>& x)
#pragma instantiate istream& operator>>(istream& is, complex<double>& x)
#pragma instantiate ostream& operator<<(ostream& os, const complex<float>& x)
#pragma instantiate ostream& operator<<(ostream& os, const complex<double>& x)
#ifdef _RW_STD_IOSTREAM
#pragma instantiate istream& operator>>(istream& is, complex<long double>& x)
#pragma instantiate ostream& operator<<(ostream& os, const complex<long double>& x)
#endif // _RW_STD_IOSTREAM
#endif // _RWSTD_NO_INSTANTIATE 
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION 
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
