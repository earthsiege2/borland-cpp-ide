#ifndef __STRSTREA_H
#define __STRSTREA_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * strstream - Declarations for the Standard Library string stream classes
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

#ifndef __STD_STRSTREAM__
#define __STD_STRSTREAM__

#include <streambuf>
#include <istream>
#include <ostream>

#ifndef _RWSTD_NO_NAMESPACE 
namespace std {
#endif
  

  class _RWSTDExport strstreambuf
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
    : public basic_streambuf<char>
#else
    : public basic_streambuf<char, char_traits<char> >
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  {

  public:
    //
    // Types:
    //
    typedef char                         char_type;
    typedef char_traits<char>            traits;
    typedef traits::int_type             int_type;
    typedef traits::pos_type             pos_type;
    typedef traits::off_type             off_type;
  
    _EXPLICIT strstreambuf(streamsize alsize = 0);
    strstreambuf(void *(*palloc)(size_t), void (*pfree)(void *));
    strstreambuf(char *gnext, streamsize n, char *pbeg = 0);

    strstreambuf(unsigned char *gnext, streamsize n,
                 unsigned char *pbeg = 0);
    strstreambuf(signed char *gnext, streamsize n,
                 signed char *pbeg = 0);

    strstreambuf(const char *gnext, streamsize n);
    strstreambuf(const unsigned char *gnext, streamsize n);
    strstreambuf(const signed char *gnext, streamsize n);
    virtual ~strstreambuf();

    void freeze(bool f = true);
    char *str();
    int pcount() const;

  protected:
    virtual int_type overflow(int_type c = traits::eof());
    virtual int_type pbackfail(int_type c = traits::eof());
    virtual int_type underflow();

    virtual pos_type seekoff(off_type, ios_base::seekdir way,
                             ios_base::openmode which =
                             ios_base::in | ios_base::out);

    virtual pos_type seekpos(pos_type sp, ios_base::openmode which =
                             ios_base::in | ios_base::out);

    virtual streambuf* setbuf(char *s, streamsize n);
    virtual streamsize xsputn(const char_type *s, streamsize n);

  private:
    typedef long strstate;

    enum str_state {
      allocated      = 0x01,
      constant       = 0x02,
      dynamic        = 0x04,
      frozen         = 0x08
    };

    int doallocate();
  
    strstate       __strmode;
    streamsize     __alsize;
    char          *__data;
    streamsize     __end_pos;

    void           *(*__palloc)(size_t);
    void           (*__pfree)(void *);
  };

  class _RWSTDExport istrstream
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
    : public basic_istream<char>
#else
    : public basic_istream<char, char_traits<char> >
#endif
  {

  public:
    //
    // Types:
    //
    typedef char                         char_type;
    typedef char_traits<char>            traits;
    typedef traits::int_type             int_type;
    typedef traits::pos_type             pos_type;
    typedef traits::off_type             off_type;
  
    _EXPLICIT istrstream(const char *s);
    istrstream(const char *s, streamsize n);
    _EXPLICIT istrstream(char *s);
    istrstream(char *s, streamsize n);

    virtual ~istrstream();

    strstreambuf *rdbuf() const;
    char *str();
  protected:

  private:
    strstreambuf              __sb;
  };
  class _RWSTDExport ostrstream
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
    : public basic_ostream<char>
#else
    : public basic_ostream<char, char_traits<char> >
#endif
  {

  public:
    //
    // Types:
    //
    typedef char                               char_type;
    typedef char_traits<char>                  traits;
    typedef traits::int_type                   int_type;
    typedef traits::pos_type                   pos_type;
    typedef traits::off_type                   off_type;
  
    ostrstream();
    ostrstream(char *s, int n,
               ios_base::openmode = ios_base::out);
    
    virtual ~ostrstream();
    strstreambuf *rdbuf() const;
    void freeze(bool freezefl = true);
    char *str();
    int pcount() const;

  protected:

  private:
    strstreambuf        __sb;
  };
/*
 *  Class strstream
 */

  class _RWSTDExport strstream
#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
    : public basic_iostream<char>
#else
    : public basic_iostream<char, char_traits<char> >
#endif
  {

  public:
    //
    // Types:
    //
    typedef char                         char_type;
    typedef char_traits<char>            traits;
    typedef traits::int_type             int_type;
    typedef traits::pos_type             pos_type;
    typedef traits::off_type             off_type;
  
    strstream();
    strstream(char *s, int n,
              ios_base::openmode = ios_base::out | ios_base::in);

    void freeze(bool freezefl = true);
    int pcount() const;

    virtual ~strstream();
    strstreambuf *rdbuf() const;

    char *str();
  protected:

  private:
    strstreambuf          __sb;
  };
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif //__STD_STRSTREAM__ 
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __STRSTREA_H */
