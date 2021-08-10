#ifndef __SSTREAM_CC
#define __SSTREAM_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * sstream.cc - Declarations for the Standard Library basic strings
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
   * basic_stringbuf(basic_ios::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_stringbuf<charT, traits, Allocator>::
  basic_stringbuf( ios_base::openmode which)
  : basic_streambuf<charT, traits>()
  , __data(0)
  , __length(0)
  , __end_pos(0)
  {
    this->setp(0,0);
    this->setg(0,0,0);
    basic_streambuf<charT,traits>::mode_ = which;
  }

  /*
   * basic_stringbuf(const basic_string, ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_stringbuf<charT, traits, Allocator>::
  basic_stringbuf(const string_type& s, ios_base::openmode which)
  : basic_streambuf<charT, traits>()
  , __length(s.length())
  {
    basic_streambuf<charT,traits>::mode_ = which;

    __data = new charT[__length];

    if(s.data())
      traits::copy(__data, s.data(), __length);

    if(which & ios_base::in)
      this->setg(__data, __data, __data+__length);

    if(which & ios_base::out)
      this->setp(__data, __data+__length);

    if(which & ( ios_base::app | ios_base::ate ) )
      pbump(__length);

    __end_pos = __length;

  }

  /*
   * virtual ~basic_stringbuf()
   */

  template<class charT, class traits, class Allocator>
  basic_stringbuf<charT, traits, Allocator>::~basic_stringbuf()
  {
    if ( __data )
      delete [] __data;
  }

  /*
   * basic_string str() const
   */

  template<class charT, class traits, class Allocator>
  basic_string<charT, traits, Allocator>
  basic_stringbuf<charT, traits, Allocator>::str() const
  {

    if ( __end_pos == 0 )  return string_type();

    if ( (__end_pos > ( this->pptr() - this->pbase() )) && (__end_pos > ( this->egptr() - this->eback() )) )
      return string_type(__data, __end_pos);
    else 
    {
      if ( ( this->pptr() - this->pbase() ) > ( this->egptr() - this->eback() ) )
        return string_type(__data, this->pptr() - this->pbase() );
      else
        return string_type(__data, this->egptr() - this->eback() );
    }
   
  }

  /*
   * void str(const basic_string&)
   */

  template<class charT, class traits, class Allocator>
  void 
  basic_stringbuf<charT, traits, Allocator>::
  str(const string_type& s)
  {
    if ( __data )
      delete [] __data;

    __length = s.length();

    if(__length == 0)
    {
      this->setg(0,0,0);
      this->setp(0,0);
      __data = 0;
      return;
    }

    __data = new charT[__length];

    if(s.data())
      traits::copy(__data, s.data(), __length);
    
    if(basic_streambuf<charT,traits>::mode_ & ios_base::in)
      this->setg(__data, __data, __data+__length);

    if(basic_streambuf<charT,traits>::mode_ & ios_base::out)
    {
      this->setp(__data, __data+__length);
      if( (basic_streambuf<charT,traits>::mode_ & ios_base::app) || (basic_streambuf<charT,traits>::mode_ & ios_base::ate ) )
        this->pbump(__length); 
    } 

    __end_pos = __length;
  }
  /*
   * int_type overflow(int_type)
   */

  template<class charT, class traits, class Allocator>
  _TYPENAME basic_stringbuf<charT, traits, Allocator>::int_type
  basic_stringbuf<charT, traits, Allocator>::overflow(int_type c)
  {
    if((basic_streambuf<charT,traits>::mode_ & ios_base::out) == 0) {
      return traits::eof();
    }
  
    charT        *temp;
    int          old_numb_of_elements,new_numb_of_elements;
    const int    increment=128;
    int_type     var;

    if (this->pptr())
    {
      old_numb_of_elements = this->pptr() - __data;
      new_numb_of_elements = old_numb_of_elements + increment;
      temp = new charT[new_numb_of_elements];

      traits::copy(temp, __data, old_numb_of_elements);   
      this->setp (temp,temp+new_numb_of_elements);
      this->pbump(old_numb_of_elements);  
     
      charT *tmp=temp+(this->gptr()-this->eback()); 
      this->setg(temp, tmp, this->pptr()+1);

      delete [] __data;
      __data = temp;
    }
    else
    {
      new_numb_of_elements=increment;
      temp = new charT[new_numb_of_elements];
      this->setp(temp,temp+new_numb_of_elements);

      if((basic_streambuf<charT,traits>::mode_ & ios_base::in) != 0)
        this->setg(temp, temp , temp);

      __data =temp; 
    }
  
    if ( traits::eq_int_type(c,traits::eof()) ) var = traits::not_eof(c);
    else
      var = sputc(c);

    if ( (this->pptr() - this->pbase()) > __end_pos )
      __end_pos = this->pptr() - this->pbase(); 

    return var;
  }

  /*
   * int_type pbackfail(int_type)
   */

  template<class charT, class traits, class Allocator>
  _TYPENAME basic_stringbuf<charT, traits, Allocator>::int_type
  basic_stringbuf<charT, traits, Allocator>::pbackfail(int_type c)
  {
  
    if ( (!traits::eq_int_type(c,traits::eof())) && (this->gptr()>this->eback()) )
    {

      if ( traits::eq(*(this->gptr()-1),traits::to_char_type(c)) ) 
      {
        this->gbump(-1);
        return c;
      }
      else
      {
        if( basic_streambuf<charT,traits>::mode_ & ios_base::out )
        {
          this->gbump(-1);
          *this->gptr()=traits::to_char_type(c);
          return c;
        }
      }
    }       

    if ( (traits::eq_int_type(c,traits::eof())) && (this->gptr()>this->eback()) )
    { 
      this->gbump(-1);
      return traits::not_eof(c);
    }
    return traits::eof();
  }
  /*
   * basic_streambuf<charT,traits>* setbuf(char_type* s, streamsize n)
   */

  template<class charT, class traits, class Allocator>
  basic_streambuf<charT, traits>*
  basic_stringbuf<charT, traits, Allocator>::setbuf(char_type* s, streamsize n)
  {
    if((basic_streambuf<charT,traits>::mode_ & ios_base::out) != 0)
    {
      if ( n > ( this->pptr() - this->pbase() ) )
      {
        if ( s == 0 ) s = new charT[n];

        if ( s )
        {
          int          old_numb_of_elements;

          if (this->pptr())
          {
            old_numb_of_elements = this->pptr() - __data;
            traits::copy(s, __data, old_numb_of_elements);   
            this->setp (s,s+n-1);
            this->pbump(old_numb_of_elements);  

            charT *tmp=s+(this->gptr()-this->eback()); 
            this->setg(s, tmp, this->pptr()+1);

            delete [] __data;
            __data = s;
          }
          else
          {
            this->setp(s,s+n-1);
            if((basic_streambuf<charT,traits>::mode_ & ios_base::in) != 0)
              this->setg(s, s , s);
            __data =s; 
          }
        }
        else
          return (basic_streambuf<charT,traits>*)(0);
      }
      else
        return (basic_streambuf<charT,traits>*)(0);
    }
    return (basic_streambuf<charT,traits>*)(this);
  }

  /*
   * int_type underflow()
   */

  template<class charT, class traits, class Allocator>
  _TYPENAME basic_stringbuf<charT, traits, Allocator>::int_type
  basic_stringbuf<charT, traits, Allocator>::underflow()
  {
    if(this->gptr() && (this->gptr()<this->egptr()) ) return traits::to_int_type(*this->gptr());

    if(((this->pptr() != 0) && ( (this->pptr() > this->egptr()) || ( __end_pos > (this->egptr() - this->eback()) ) ) ) && (!this->gptr())) 
    {
      if ( __end_pos > ( this->pptr() - this->pbase() ) )
        this->setg(this->pbase(), this->pbase(), this->pbase()+__end_pos );
      else     
        this->setg(this->pbase(), this->pbase(), this->pptr());
      return traits::to_int_type(*this->gptr());
    }

    if((this->pptr() != 0) && ( (this->pptr() > this->egptr()) || ( __end_pos > ( this->egptr() - this->eback() )) ) ) 
    {
      if ( __end_pos > ( this->pptr() - this->pbase() ) )
        this->setg(this->eback(),this->gptr(),this->eback()+__end_pos);
      else
        this->setg(this->eback(), this->gptr(), this->pptr());
      return traits::to_int_type(*this->gptr());
    }
    return traits::eof();
  }

  /*
   * pos_type seekoff(off_type, ios_base::seekdir, ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  _TYPENAME basic_stringbuf<charT, traits, Allocator>::pos_type
  basic_stringbuf<charT, traits, Allocator>::
  seekoff(off_type off, ios_base::seekdir way, ios_base::openmode which)
  {
    streamsize       newoff;
  
    if((which & ios_base::in) && (which & ios_base::out))
    {
      if ( (way==ios_base::beg) || (way==ios_base::end) )
      {
        if ( seekoff(off,way,ios_base::out) == pos_type(off_type(-1)) )
          return pos_type(off_type(-1));
        return seekoff(off,way,ios_base::in);
      }
      else
        return pos_type(off_type(-1)); 
    }
  
    if((which & ios_base::in) && (this->gptr()!=0))
    {
      if ( (this->egptr() - this->eback()) > __end_pos )
        __end_pos = this->egptr() - this->eback(); 

      if ( (this->pptr() - this->pbase()) > __end_pos )
        __end_pos = this->pptr() - this->pbase(); 

      if(way == ios_base::beg)
        newoff = 0;
      if(way == ios_base::cur)
        newoff = this->gptr() - this->eback();
      if(way == ios_base::end)
        newoff = __end_pos;

      if ( newoff<0 )  return pos_type(off_type(-1)); 

      if ( ((this->eback()+long(newoff)+long(off))> this->egptr()) || ((newoff+off)< 0) )
        return pos_type(-1);

      this->setg(this->eback(), this->eback() + long(newoff) + long(off), this->egptr());
      return pos_type(newoff+off);
    }

    if((which & ios_base::in) && (this->gptr()==0) && (this->egptr()==0) && (this->eback()==0) ) 
      return pos_type(0);

    if((which & ios_base::out) && (this->pptr()!=0) && !(basic_streambuf<charT,traits>::mode_ & ios_base::app) )
    {

      if ( (this->egptr() - this->eback()) > __end_pos )
        __end_pos = this->egptr() - this->eback(); 

      if ( (this->pptr() - this->pbase()) > __end_pos )
        __end_pos = this->pptr() - this->pbase(); 

      if(way == ios_base::beg)
        newoff = 0;
      if(way == ios_base::cur)
        newoff = this->pptr() - this->pbase();
      if(way == ios_base::end)
        newoff = __end_pos;

      if ( (this->pptr() - this->pbase()) > __end_pos ) __end_pos = this->pptr() - this->pbase();

      if ( ((newoff+off)<0) || ((this->pbase()+long(newoff)+long(off))> this->epptr()) )
        return pos_type(off_type(-1));   

      this->pbump( newoff+off-(this->pptr()-this->pbase())  );

      if (this->eback() !=0 && this->gptr()<=this->pptr() )
        this->setg(this->eback(),this->gptr(),this->pptr());
      else
      {
        if ( (basic_streambuf<charT,traits>::mode_ & ios_base::out  ) &&
             !(basic_streambuf<charT,traits>::mode_ & ios_base::in ) )
          this->setg(this->pbase(),this->pptr(),this->pptr());
      } 
      return pos_type(newoff+off);
    }
    else 
    {
      if ( basic_streambuf<charT,traits>::mode_ & ios_base::app )
        return pos_type(this->pptr()-this->pbase());

      if((which & ios_base::out) && (this->pptr()==0) && (this->epptr()==0) && (this->pbase()==0) )
        return pos_type(0);
    }
    return pos_type(off_type(-1));
  }

  /*
   * pos_type seekpos(pos_type, ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  _TYPENAME basic_stringbuf<charT, traits, Allocator>::pos_type
  basic_stringbuf<charT, traits, Allocator>::
  seekpos(pos_type sp, ios_base::openmode which)
  {
    streamsize    newoff = sp;

    if((which & ios_base::in) && (which & ios_base::out))
    {
      if ( seekpos(sp,ios_base::out) == pos_type(off_type(-1)) )
        return pos_type(off_type(-1));
      return seekpos(sp,ios_base::in);
    }

    if((which & ios_base::in) && (this->gptr()!=0))
    {
    
      if ( newoff<0 )  return pos_type(off_type(-1));
      if ( (this->eback()+long(newoff))> this->egptr() ) return pos_type(off_type(-1));

      this->setg(this->eback(), this->eback() + long(newoff), this->egptr());
      return pos_type(newoff);
    }
    if((which & ios_base::out) && (this->pptr()!=0) && !(basic_streambuf<charT,traits>::mode_ & ios_base::app) )
    {
      if ( (newoff<0) || ((this->pbase()+long(newoff))> this->epptr()) )
        return pos_type(off_type(-1)); 

      if ( (this->pptr() - this->pbase()) > __end_pos ) __end_pos = this->pptr() - this->pbase();
      this->pbump( newoff-(this->pptr()-this->pbase())  );

      if (this->eback() !=0 && this->gptr()<=this->pptr() )
        this->setg(this->eback(),this->gptr(),this->pptr());
      else
      {
        if ( (basic_streambuf<charT,traits>::mode_ & ios_base::out  ) &&
             !(basic_streambuf<charT,traits>::mode_ & ios_base::in ) )
          this->setg(this->pbase(),this->pptr(),this->epptr());
      }
      return pos_type(newoff);
    }
    else 
      if ( basic_streambuf<charT,traits>::mode_ & ios_base::app )
        return pos_type(this->pptr()-this->pbase());
    return pos_type(off_type(-1));
  }

  /*
   * streamsize xsputn(const char_type *, streamsize)
   */

  template<class charT, class traits, class Allocator>
  streamsize basic_stringbuf<charT, traits, Allocator>::
  xsputn(const char_type *s, streamsize n)
  {
    if ( !s || (n == 0) ) return 0;

    if ( n > ( this->epptr()-this->pptr()+128 ) )
    {
      if ( setbuf(0, this->pptr()-this->pbase()+n+128)== 0)
      {
        return 0;
      }

      traits::copy(this->pptr(), s, n);
      this->pbump(n);
      __end_pos =  (this->pptr() - this->pbase());
    }
    else
    {
      int         i=0;
      while((i < n) && ( !traits::eq_int_type(sputc(*s++),traits::eof())))
        i++;
      return i;
    }
    return n;    
  }

  /*
   * class basic_istringstream
   */

  /*
   * basic_istringstream(ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_istringstream<charT, traits, Allocator>::
  basic_istringstream(ios_base::openmode m)
  : basic_istream<charT, traits>( )
  , __sb(m | ios_base::in)
  {
    init(&__sb);
  }

  /*
   * basic_istringstream(const basic_string<charT>&, ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_istringstream<charT, traits, Allocator>::
  basic_istringstream(const string_type& s, ios_base::openmode which)
  : basic_istream<charT, traits>( )
  , __sb(s, which | ios_base::in)
  {
    init(&__sb);
  }

  /*
   * virtual ~basic_istringstream()
   */

  template<class charT, class traits, class Allocator>
  basic_istringstream<charT, traits, Allocator>::~basic_istringstream()
  {
  }

  /*
   * basic_stringbuf *rdbuf() const
   */

  template<class charT, class traits, class Allocator>
  basic_stringbuf<charT, traits, Allocator> *
  basic_istringstream<charT, traits, Allocator>::rdbuf() const
  {
    return (basic_stringbuf<charT, traits, Allocator> *)&__sb;
  }

  /*
   * basic_string<charT> str() const
   */

  template<class charT, class traits, class Allocator>
  basic_string<charT, traits, Allocator>
  basic_istringstream<charT, traits, Allocator>::str() const
  {
    return __sb.str();
  }

  /*
   * void str(const basic_string<charT>& )
   */

  template<class charT, class traits, class Allocator>
  void basic_istringstream<charT, traits, Allocator>::str(const string_type& s)
  {
    __sb.str(s);
  }

  /*
   * class basic_ostringstring
   */

  /*
   * basic_ostringstream(ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_ostringstream<charT, traits, Allocator>::
  basic_ostringstream(ios_base::openmode w)
  : basic_ostream<charT, traits>( )           
  , __sb(w | ios_base::out )
  {
    init(&__sb);
  }

  /*
   * basic_ostringstream(const basic_string&, ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_ostringstream<charT, traits, Allocator>::
  basic_ostringstream(const string_type& s, ios_base::openmode which)
  : basic_ostream<charT, traits>( )
  , __sb(s, which | ios_base::out )
  {
    init(&__sb);
  }

  /*
   * virtual ~basic_ostringstream()
   */

  template<class charT, class traits, class Allocator>
  basic_ostringstream<charT, traits, Allocator>::~basic_ostringstream()
  {
  }

  /*
   * basic_stringbuf *rdbuf() const
   */

  template<class charT, class traits, class Allocator>
  basic_stringbuf<charT, traits, Allocator> *
  basic_ostringstream<charT, traits, Allocator>::rdbuf() const
  {
    return (basic_stringbuf<charT, traits, Allocator> *)&__sb;
  }

  /*
   * basic_string str() const
   */

  template<class charT, class traits, class Allocator>
  basic_string<charT, traits, Allocator>
  basic_ostringstream<charT, traits, Allocator>::str() const
  {
    return __sb.str();
  }

  /*
   * void str(const basic_string& s)
   */

  template<class charT, class traits, class Allocator>
  void basic_ostringstream<charT, traits, Allocator>::
  str(const string_type& s)
  {
    __sb.str(s);
  }

  /*
   * class basic_stringstream
   */

  /*
   * basic_stringstream(ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_stringstream<charT, traits, Allocator>::
  basic_stringstream(ios_base::openmode w)
  : basic_iostream<charT, traits>( )          
  , __sb(w)
  {
    init(&__sb);
  }

  /*
   * basic_stringstream(const basic_string&, ios_base::openmode)
   */

  template<class charT, class traits, class Allocator>
  basic_stringstream<charT, traits, Allocator>::
  basic_stringstream(const string_type& s, ios_base::openmode which)
  : basic_iostream<charT, traits>( )
  , __sb(s, which)
  {
    init(&__sb);
  }

  /*
   * virtual ~basic_stringstream()
   */

  template<class charT, class traits, class Allocator>
  basic_stringstream<charT, traits, Allocator>::~basic_stringstream()
  {
  }

  /*
   * basic_stringbuf *rdbuf() const
   */

  template<class charT, class traits, class Allocator>
  basic_stringbuf<charT, traits, Allocator> *
  basic_stringstream<charT, traits, Allocator>::rdbuf() const
  {
    return (basic_stringbuf<charT, traits, Allocator> *)&__sb;
  }

  /*
   * basic_string str() const
   */

  template<class charT, class traits, class Allocator>
  basic_string<charT, traits, Allocator>
  basic_stringstream<charT, traits, Allocator>::str() const
  {
    return __sb.str();
  }

  /*
   * void str(const basic_string& s)
   */

  template<class charT, class traits, class Allocator>
  void basic_stringstream<charT, traits, Allocator>::
  str(const string_type& s)
  {
    __sb.str(s);
  }
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __SSTREAM_CC */
