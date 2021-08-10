#ifndef __STREAMBU_CC
#define __STREAMBU_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * streambuf.cc - Definitions for the Standard Library stream buffers
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

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  /*
   * class basic_streambuf<charT, traits>
   */

  /*
   * ~basic_streambuf()
   */

  template<class charT, class traits>
  basic_streambuf<charT, traits>::~basic_streambuf()
  {

  }

  /*
   * basic_streambuf()
   */

  template<class charT, class traits>
  basic_streambuf<charT, traits>::basic_streambuf()
  {
    streambuf_init();
  }

  /*
   * void streambuf_init()
   */

  template<class charT, class traits>
  void basic_streambuf<charT, traits>::streambuf_init(bool set_mode)
  {
    if ( set_mode )
      mode_ = ( ios_base::in | ios_base::out );

    __gbeg  = 0;
    __gnext = 0;
    __gend  = 0;

    __pbeg  = 0;
    __pnext = 0;
    __pend  = 0;
  }
  /*
   * int_type overflow(int_type)
   */

  template<class charT, class traits>
  _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::overflow(int_type )
  {
    return traits::eof();  
  }

  /*
   * int_type pbackfail(int_type)
   */

  template<class charT, class traits>
  _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::pbackfail(int_type )
  {
    return traits::eof();
  }

  /*
   * streamsize showmanyc()
   */

  template<class charT, class traits>
  streamsize basic_streambuf<charT, traits>::showmanyc()
  {
    if ( gptr() )
    {
      if ( pptr()>egptr() ) setg(eback(),gptr(),pptr());
    }
    else
      if ( pptr() ) setg(pbase(),pbase(),pptr());

    return (streamsize)(egptr()-gptr());
  }

  /*
   * int_type underflow()
   */

  template<class charT, class traits>
  _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::underflow()
  {
    return traits::eof();
  }

  /*
   * int_type uflow()
   */

  template<class charT, class traits>
  _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::uflow()
  {
    if( traits::eq_int_type(underflow(),traits::eof()) )
      return traits::eof();
    return sbumpc();
  }

  /*
   * streamsize xsgetn(char_type *, streamsize)
   */

  template<class charT, class traits>
  streamsize basic_streambuf<charT, traits>::
  xsgetn(char_type *s, streamsize n)
  {
    if ( !s || (n==0) ) return 0;

    streamsize i = ( in_avail() > n ) ? n : in_avail();
    int_type   c;

    if(i > 0) {
      s = traits::copy(s, gptr(), i);
      s += i;
      gbump(i);
    }

    while((i < n) && ( !traits::eq_int_type( (c = sbumpc()),traits::eof()))) {
      *s++ = traits::to_char_type(c);
      ++i;
    }

    return i;
  }

  /*
   * streamsize xsputn(const char_type *, streamsize)
   */

  template<class charT, class traits>
  streamsize basic_streambuf<charT, traits>::
  xsputn(const char_type *s, streamsize n)
  {
    if ( !s || (n == 0) ) return 0;

    int         i=0;

    while((i < n) && ( !traits::eq_int_type(sputc(*s++),traits::eof()))) {
      i++;
    }

    return i;
  }

  /*
   * pos_type seekoff(off_type, ios_base::seekdir, ios_base::openmode)
   */

  template<class charT, class traits>
  _TYPENAME basic_streambuf<charT, traits>::pos_type
  basic_streambuf<charT, traits>::
  seekoff(off_type , ios_base::seekdir , ios_base::openmode )
  {
    return pos_type(off_type(-1));
  }

  /*
   * pos_type seekpos(pos_type, ios_base::openmode)
   */

  template<class charT, class traits>
  _TYPENAME basic_streambuf<charT, traits>::pos_type
  basic_streambuf<charT, traits>::
  seekpos(pos_type , ios_base::openmode )
  {
    return pos_type(off_type(-1));
  }

  /*
   * basic_streambuf *setbuf(char_type *, streamsize)
   */

  template<class charT, class traits>
  basic_streambuf<charT, traits> *
  basic_streambuf<charT, traits>::setbuf(char_type*, streamsize )
  {
    return this;
  }

  /*
   * int sync()
   */

  template<class charT, class traits>
  int basic_streambuf<charT, traits>::sync()
  {
    return 0;
  }
  /*
   * locale pubimbue(const locale& loc)
   */

  template<class charT, class traits>
  locale basic_streambuf<charT, traits>::pubimbue(const locale& loc)
  {
    locale tmp = getloc();
    imbue(loc);
    return tmp; 
  }

  /*
   * locale getloc() const
   */

  template<class charT, class traits>
  locale basic_streambuf<charT, traits>::getloc() const
  {
    return __loc_buf;
  }

  /*
   * virtual void imbue(const locale& loc)
   */

  template<class charT, class traits>
  void basic_streambuf<charT, traits>::imbue(const locale& loc)
  {
    __loc_buf = loc;

  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __STREAMBU_CC */
