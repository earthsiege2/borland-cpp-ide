#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * strstream.cpp - Source for the Standard Library string stream classes
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
#include <strstream>

#ifndef _RWSTD_NO_NEW_HEADER
#include <climits>
#else
#include <limits.h>
#endif // _RWSTD_NO_NEW_HEADER 

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif
  
  /*
   * class strstreambuf : public basic_streambuf
   */

  /*
   * strstreambuf(streamsize)
   */

  strstreambuf::strstreambuf(streamsize n)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  , __strmode(dynamic)
  , __alsize(n)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  , __end_pos(0)
  {
  }

  /*
   * strstreambuf(void *(*palloc)(size_t), void (*pfree)(void *))
   */

  strstreambuf::strstreambuf(void *(*palloc)(size_t), void (*pfree)(void *))
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif
  , __strmode(dynamic)
  , __alsize(0)
  , __palloc(palloc)
  , __pfree(pfree)
  , __data(0)
  , __end_pos(0)
  {
  }

  /*
   * strstreambuf(char_type *, streamsize, char_type *)
   */

  strstreambuf::strstreambuf(char_type *g, streamsize n, char_type *p)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  , __strmode(0)
  , __alsize(0)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  {
    int       N; 
    if(n > 0)
      N = n;
    else {
      if(n == 0)
        N = char_traits<char>::length(g);
      else
        N = INT_MAX;
    }

    if(p)
    {
      setg(g, g, p);
      setp(g, g+N);
      pbump(p-g);
    }
    else
    {
      setg(g, g, g+N);
    }

    __end_pos = pptr() - pbase();
  }

  /*
   * strstreambuf(unsigned char_type *, streamsize, unsigned char_type *)
   */

  strstreambuf::strstreambuf(unsigned char *g, streamsize n, unsigned char *p)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif
  , __strmode(0)
  , __alsize(0)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  {
    int          N;

    if(n > 0)
      N = n;
    else {
      if(n == 0)
        N = char_traits<char>::length((char *)g);
      else
        N = INT_MAX;
    }

    if(p)
    {
      setg((char *)g,(char *)g,(char *)p);
      setp((char *)g, (char *)g+N);
      pbump(p-g);
    }
    else
    {
      setg((char *)g, (char *)g, (char *)g+N);
    }

    __end_pos = pptr() - pbase();
  }

  /*
   * strstreambuf(signed char_type *, streamsize, signed char_type *)
   */

  strstreambuf::strstreambuf(signed char *g, streamsize n, signed char *p)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif
  , __strmode(0)
  , __alsize(0)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  {
    int          N;

    if(n > 0)
      N = n;
    else {
      if(n == 0)
        N = char_traits<char>::length((char *)g);
      else
        N = INT_MAX;
    }

    if(p)
    {
      setg((char *)g,(char *)g,(char *)p);
      setp((char *)g, (char *)g+N);
      pbump(p-g);
    }
    else
    {
      setg((char *)g, (char *)g, (char *)g+N);
    }
    __end_pos = pptr() - pbase();
  }

  /*
   * strstreambuf(const char_type *, streamsize)
   */

  strstreambuf::strstreambuf(const char_type *s, streamsize n)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif
  , __strmode(constant)
  , __alsize(0)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  {
    int            N;

    if(n > 0)
      N = n;
    else {
      if(n == 0)
        N = char_traits<char>::length((char *)s);
      else
        N = INT_MAX;
    }

    setg((char *)s, (char *)s, (char *)s+N);
    __end_pos = pptr() - pbase();
  }

  /*
   * strstreambuf(const unsigned char_type *, streamsize)
   */

  strstreambuf::strstreambuf(const unsigned char *s, streamsize n)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif
  , __strmode(constant)
  , __alsize(0)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  {
    int           N;

    if(n > 0)
      N = n;
    else {
      if(n == 0)
        N = char_traits<char>::length((char *)s);
      else
        N = INT_MAX;
    }

    setg((char *)s, (char *)s, (char *)s+N);
    __end_pos = pptr() - pbase();
  }

  /*
   * strstreambuf(const signed char_type *, streamsize)
   */

  strstreambuf::strstreambuf(const signed char *s, streamsize n)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_streambuf<char>()
#else
  : basic_streambuf<char, char_traits<char> >()
#endif
  , __strmode(constant)
  , __alsize(0)
  , __palloc(0)
  , __pfree(0)
  , __data(0)
  {
    int             N;

    if(n > 0)
      N = n;
    else {
      if(n == 0)
        N = char_traits<char>::length((char *)s);
      else
        N = INT_MAX;
    }
    setg((char *)s, (char *)s, (char *)s+N);
    __end_pos = pptr() - pbase();
  }

  /*
   * virtual ~strstreambuf()
   */

  strstreambuf::~strstreambuf()
  {
    if((__strmode & allocated) && (!(__strmode & frozen)) ) {
      if(__data)
        delete [] __data;
    }
  }

  /*
   * void freeze(bool)
   */

  void strstreambuf::freeze(bool f)
  {
    if(__strmode & dynamic)
    {
      if(f)
        __strmode |= frozen;     // set frozen
      else
        __strmode &= ~frozen;    // clear frozen
    }
  }

  /*
   * char_type *str()
   */

  char *strstreambuf::str()
  {
    freeze();
    return eback();
  }

  /*
   * int pcount()
   */

  int strstreambuf::pcount() const
  {
    if(pptr())
    {
      return pptr() - pbase();
    }
    return 0;
  }

  /*
   * int_type overflow(int_type)
   */
  strstreambuf::int_type  strstreambuf::overflow(int_type c)
  {
    char              *temp;
    size_t            old_numb_of_elements, new_numb_of_elements, old_read_pos;
    const size_t      increment=512;          
  
    if( traits::eq_int_type(c,traits::eof()) )
      return traits::not_eof(c);

    if(((__strmode & dynamic) == 0) || (__strmode & frozen))
    {
      return traits::eof();
    }

    old_numb_of_elements = pptr() - __data;
    old_read_pos = gptr()- __data;

    new_numb_of_elements = old_numb_of_elements;

    if(__alsize)
      new_numb_of_elements += __alsize;
    else
      new_numb_of_elements += increment;

    if(__palloc)
      temp = (char *)(*__palloc)(new_numb_of_elements);
    else
      temp = new char[new_numb_of_elements];

    memset(temp,0,new_numb_of_elements);
     

    if(!temp)
      return traits::eof();
   
    memcpy(temp,__data,old_numb_of_elements);

    setp(temp, temp+new_numb_of_elements);

    pbump(old_numb_of_elements);   
 
    setg(temp, temp+old_read_pos, pptr());

    if (__strmode & allocated)
    { 
      if(__pfree)
        (*__pfree)(__data);
      else
        delete [] __data;
    }

    __strmode |= allocated;
    __data = temp;
    return sputc(c);
  }

  /*
   * int_type pbackfail(int_type)
   */

  strstreambuf::int_type strstreambuf::pbackfail(int_type c)
  {

    if ( (c!= traits::eof()) && (gptr()>eback()) )
    {
      if ( (int_type)(*(gptr()-1))==c ) 
      {
        gbump(-1);
        return c;
      }
      else
      {
        if( !(__strmode & constant) )
        {
          gbump(-1);
          *gptr()=(char_type)c;
          return c;
        }
      }
    }       

    if ( (c== traits::eof()) && (gptr()>eback()) )
    { 
      gbump(-1);
      return traits::not_eof(c);
    }
    return traits::eof();
  }

  /*
   * int_type underflow()
   */
  strstreambuf::int_type strstreambuf::underflow()
  {
    if(gptr() && (gptr()<egptr()) ) return traits::not_eof(*gptr());

    if(((pptr() != 0) && (pptr() > egptr())) && (!gptr()))
    {
      setg(pbase(), pbase(), pptr());
      return traits::to_int_type(*gptr());
    }

    if((pptr() != 0) && (pptr() > egptr()))
    {
      setg(eback(), gptr(), pptr());
      return traits::to_int_type(*gptr());
    }
                                  
    return traits::eof();
  }

  /*
   * pos_type seekoff(off_type, ios_base::seekdir, ios_base::openmode)
   */

  streampos strstreambuf::seekoff(off_type off,
                                  ios_base::seekdir way,
                                  ios_base::openmode which)
  {
    streamsize       newoff;
  
    if((which & ios_base::in) && (which & ios_base::out))
    {
      if ( (way==ios_base::beg) || (way==ios_base::end) )
      {
        if ( seekoff(off,way,ios_base::out) == pos_type(-1) )
          return pos_type(-1);  
        return seekoff(off,way,ios_base::in);
      }
      else
        return pos_type(-1);  // invalid way
    }
  
    if((which & ios_base::in) && (gptr()!=0))
    {
      if(way == ios_base::beg)
        newoff = 0;
      if(way == ios_base::cur)
        newoff = gptr() - eback();
      if(way == ios_base::end)
        newoff = egptr() - eback();

      if ( ((eback()+long(newoff)+long(off))> egptr()) || ((newoff+off)< 0) )
        return pos_type(-1);

      setg(eback(), eback() + long(newoff) + long(off), egptr());

      return pos_type(newoff+off);
    }

    if((which & ios_base::in) && (gptr()==0) && (egptr()==0) && (eback()==0) ) 
      return pos_type(0);

    if((which & ios_base::out) && (pptr()!=0) && !(mode_ & ios_base::app) )
    {
      if(way == ios_base::beg)
        newoff = 0;
      if(way == ios_base::cur)
        newoff = pptr() - pbase();
      if(way == ios_base::end)
        newoff = __end_pos;

      if ( (pptr() - pbase()) > __end_pos ) __end_pos = pptr() - pbase();

      if ( ((newoff+off)<0) || ((pbase()+long(newoff)+long(off))> epptr()) )
        return pos_type(-1);  

      pbump( newoff+off-(pptr()-pbase())  );

      if ( egptr()>pptr() )
        if ( gptr() > pptr() )
          setg(eback(), pptr(), pptr());
        else
          setg(eback(),gptr(),pptr());
      return pos_type(newoff+off);
    }
    else 
    {
      if ( mode_ & ios_base::app )
        return pos_type(pptr()-pbase());

      if((which & ios_base::out) && (pptr()==0) && (epptr()==0) && (pbase()==0) )
        return pos_type(0);
    }
    return pos_type(-1);
  }

             
  /*
   * pos_type seekpos(pos_type, ios_base::openmode)
   */

  streampos strstreambuf::seekpos(pos_type sp, ios_base::openmode which)
  {
    streamsize    newoff = sp;

    if((which & ios_base::in) && (which & ios_base::out))
    {
      if ( seekpos(sp,ios_base::out) == pos_type(-1) )
        return pos_type(-1);  
      return seekpos(sp,ios_base::in);
    }
  
    if((which & ios_base::in) && (gptr()!=0))
    {
      if ( ((eback()+long(newoff))> egptr()) || (newoff< 0) )
        return pos_type(-1);

      setg(eback(), eback() + long(newoff), egptr());

      return pos_type(newoff);
    }
    if((which & ios_base::out) && (pptr()!=0) && !(mode_ & ios_base::app) )
    {
      if ( (newoff<0) || ((pbase()+long(newoff))> epptr()) )
        return pos_type(-1); 

      if ( (pptr() - pbase()) > __end_pos ) __end_pos = pptr() - pbase(); 
 
      pbump( newoff-(pptr()-pbase())  );
      if ( egptr()>pptr() )
        if ( gptr() > pptr() )
          setg(eback(), pptr(), pptr());
        else
          setg(eback(),gptr(),pptr());
      return pos_type(newoff);
        
    }
    else 
      if ( mode_ & ios_base::app )
        return pos_type(pptr()-pbase());

    return pos_type(-1);
  }

  /*
   * streamsize setbuf(char*, streamsize)
   */

  streambuf* strstreambuf::setbuf(char* s, streamsize n)
  {
    if(((__strmode & dynamic) == 0) || (__strmode & frozen))
    {
      return (streambuf*)(0);
    }

    if((mode_ & ios_base::out) != 0)
    {
      if ( n > ( pptr() - pbase() ) )
      {
        bool is_allocated = false;
        if ( s == 0 ) 
        {
          if(__palloc)
            s = (char *)(*__palloc)(n);
          else
            s = new char[n];
          is_allocated = true;
        }

        if ( s != __data)
          memset(s,0,n);

        if ( s )
        {
          int          old_numb_of_elements;

          if (pptr())
          {
            old_numb_of_elements = pptr() - __data;
                
            if ( s!=__data )
              memcpy(s,__data,old_numb_of_elements);
               
            setp (s,s+n-1);

            pbump(old_numb_of_elements);  

            char *tmp=s+(gptr()-eback()); 
            if ( tmp == 0 ) tmp = s; 
            setg(s, tmp, pptr()+1);

            if( s != __data && __strmode & allocated)
            {
              if(__pfree)
                (*__pfree)(__data);
              else
                delete [] __data;
            }
            __data = s;
          }
          else
          {
            setp(s,s+n-1);
            if((mode_ & ios_base::in) != 0)
              setg(s, s , s);
            __data =s; 
          }
        }
        else
          return (streambuf*)(0);
        
        if (is_allocated)
          __strmode |= allocated;
        else
          __strmode &= ~allocated;
      }
      else
        return (streambuf*)(0);
    }

    return (streambuf*)(this);
  }

  int strstreambuf::doallocate()
  {
    return 0;
  }

  /*
   * streamsize xsputn(const char_type *, streamsize)
   */

  streamsize strstreambuf::
  xsputn(const char *s, streamsize n)
  {
    if ( !s || (n == 0) ) return 0;

    if ( n > ( epptr()-pptr()+128 ) )
    { 
      if ( setbuf(0, pptr()-pbase()+n+128)== 0)
      {
        return 0;
      }

      char_traits<char>::copy(pptr(), s, n);
      pbump(n);
    }
    else
    {
      int         i=0;
      while((i < n) && ( !char_traits<char>::eq_int_type(sputc(*s++),traits::eof())))
        i++;
      return i;
    }
    return n;    
  }
  /*
   * class istrstream
   */

  /*
   * istrstream(const char_type *)
   */

  istrstream::istrstream(const char_type *s)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_istream<char>()
#else
  : basic_istream<char, char_traits<char> >()
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  , __sb(s, 0)
  {
    init(&__sb);
  }

  /*
   * istrstream(const char_type *, streamsize)
   */

  istrstream::istrstream(const char_type *s, streamsize n)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_istream<char>()
#else
  : basic_istream<char, char_traits<char> >()
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  , __sb(s, n)
  {
    init(&__sb);
  }

  /*
   * istrstream(char_type *)
   */

  istrstream::istrstream(char_type *s)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_istream<char>( )
#else
  : basic_istream<char, char_traits<char> >( )
#endif //_RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  , __sb((const char_type *)s, 0)
  {
    init(&__sb);
  }

  /*
   * istrstream(char_type *, streamsize)
   */

  istrstream::istrstream(char_type *s, streamsize n)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_istream<char>( )
#else
  : basic_istream<char, char_traits<char> >( )
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  , __sb((const char_type *)s, n)
  {
    init(&__sb);
  }

  /*
   * ~istrstream()
   */

  istrstream::~istrstream()
  {
  }

  /*
   * strstreambuf *rdbuf() const
   */

  strstreambuf *istrstream::rdbuf() const
  {
    return (strstreambuf *)&__sb;
  }

  /*
   * char_type *str()
   */

  char *istrstream::str()
  {
    return __sb.str();
  }

  /*
   * class ostrstream
   */

  /*
   * ostrstream()
   */

  ostrstream::ostrstream()
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_ostream<char>( )
#else
  : basic_ostream<char, char_traits<char> >( )
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  , __sb()
  {
    init(&__sb);
  }

  /*
   * ostrstream(char_type *, int, ios_base::openmode)
   */

  ostrstream::ostrstream(char_type *s, int n, ios_base::openmode mode)
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  : basic_ostream<char>( )
#else
  : basic_ostream<char, char_traits<char> >( )
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  , __sb(s, n, (mode & (ios_base::app|ios_base::ate))? s + traits::length(s) : s)
  {
    init(&__sb);
    s[n]=0;
  }

  /*
   * ~ostrstream()
   */

  ostrstream::~ostrstream()
  {
  }

  /*
   * strstreambuf *rdbuf() const
   */

  strstreambuf *ostrstream::rdbuf() const
  {
    return (strstreambuf *)&__sb;
  }

  /*
   * void freeze(bool)
   */

  void ostrstream::freeze(bool f)
  {
    __sb.freeze(f);
  }

  /*
   * char_type *str()
   */

  char *ostrstream::str()
  {
    return __sb.str();
  }

  /*
   * int pcount() const
   */

  int ostrstream::pcount() const
  {
    return __sb.pcount();
  }

  /*
   * class strstream
   */

  strstream::strstream()
#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
  : basic_iostream<char>( )
#else
  : basic_iostream<char, char_traits<char> >( )
#endif // _RWSTD_NO_DEFAULT_TEMPLATES
  , __sb()
  {
    init(&__sb);
  }

  /*
   * strstream(char_type *, int, ios_base::openmode)
   */

  strstream::strstream(char_type *s, int n, ios_base::openmode mode)
#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
  : basic_iostream<char>( )
#else
  : basic_iostream<char, char_traits<char> >( )
#endif // _RWSTD_NO_DEFAULT_TEMPLATES
  , __sb(s, n, (mode & (ios_base::app|ios_base::ate))? s + traits::length(s) : s)
  {
    init(&__sb);
//    s[n]=0;
  }

  /*
   * ~strstream()
   */

  strstream::~strstream()
  {
  }

  /*
   * strstreambuf *rdbuf() const
   */

  strstreambuf *strstream::rdbuf() const
  {
    return (strstreambuf *)&__sb;
  }

  /*
   * char_type *str()
   */

  char *strstream::str()
  {
    return __sb.str();
  }

  /*
   * void freeze(bool)
   */

  void strstream::freeze(bool f)
  {
    __sb.freeze(f);
  }

  /*
   * int pcount() const
   */

  int strstream::pcount() const
  {
    return __sb.pcount();
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
