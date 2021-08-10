#ifndef __IOS_CC
#define __IOS_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * ios.cc - Definition for the Standard Library iostreams
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

#include <streambuf>
#include <iosfwd>
#ifndef _RWSTD_NO_NAMESPACE
namespace std { 
#endif
  
  extern istream _RWSTDExport cin;

#ifndef _RWSTD_NO_WIDE_CHAR
  extern wistream _RWSTDExport wcin;
#endif
  /*
   * Class basic_ios  member functions   
   */

  /*
   * basic_ios(basic_streambuf *)
   */

  template<class charT, class traits>
  basic_ios<charT, traits>::
  basic_ios(basic_streambuf<charT, traits> *sb_arg)
  {
    init(sb_arg);
  }

  /*
   * ~basic_ios()
   */

  template<class charT, class traits>
  basic_ios<charT, traits>::~basic_ios()
  {

  }

  /*
   * ios_type& copyfmt(const ios_type& )
   */

  template<class charT, class traits>
  basic_ios<charT, traits>&
  basic_ios<charT, traits>::
  copyfmt(const basic_ios<charT, traits>& rhs)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    __tiestr = rhs.__tiestr;
    __fillch = rhs.__fillch;
    ios_base::_RW_UNSAFE_copyfmt( rhs );
    _Except = rhs._Except;

    return *this;
  }
  /*
   * basic_ostream *tie(basic_ostream *)
   */

  template<class charT, class traits>
  basic_ostream<charT, traits> *
  basic_ios<charT, traits>::
  tie(basic_ostream<charT, traits> *tie_arg)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    basic_ostream<charT, traits>   *temp = __tiestr;
    __tiestr = tie_arg;
    return temp;
  }

  /*
   * basic_streambuf *rdbuf(basic_streambuf *)
   */

  template<class charT, class traits>
  _TYPENAME basic_ios<charT, traits>::streambuf_type* 
  basic_ios<charT, traits>::                     
  rdbuf( basic_streambuf<charT, traits> *sb)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif

    basic_streambuf<charT, traits>   *temp = __sb;

    __sb = sb;

    if ( sb==0 ) 
      __state |= ios_base::badbit;
 
    _RW_UNSAFE_clear();

    return temp;
  }

  /*
   * basic_ios()
   */

  template<class charT, class traits>
  basic_ios<charT, traits>::basic_ios()
  {
    init(0);
  }

  /*
   * void imbue(const locale& )
   */

  template<class charT, class traits>
  locale basic_ios<charT, traits>::
  imbue(const locale& loc)
  {
    locale tmp = getloc();
   
    ((ios_base *)(this))->imbue(loc);
   
    if ( rdbuf() )
      rdbuf()->pubimbue(loc);

    return tmp;  
  }

  /*
   * void init(basic_streambuf *)
   */

  template<class charT, class traits>
  void basic_ios<charT, traits>::
  init(basic_streambuf<charT, traits> *sb)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    __sb = sb;
    __tiestr = 0;

    if(__sb)
      __state = goodbit;
    else
      __state = badbit;

    _Except = goodbit;
    __fmtfl  = skipws | dec;
    __wide   = 0;
    __prec   = 6;

    __fillch = widen(' ');

  }

  /*
   * lock the buffer
   */

#ifdef _RWSTD_MULTI_THREAD
  template <class charT, class traits>
  basic_ios<charT,traits>& __lock(basic_ios<charT,traits>& strm)
  {
    if ( strm.rdbuf() )
      strm.rdbuf()->_RW_lock_buffer();

    return strm;
  }

  template <class charT, class traits>
  basic_ios<charT,traits>& __unlock(basic_ios<charT,traits>& strm)
  {
    if ( strm.rdbuf() )
      strm.rdbuf()->_RW_unlock_buffer();

    return strm;
  }

#endif //  _RWSTD_MULTI_THREAD
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __IOS_CC */
