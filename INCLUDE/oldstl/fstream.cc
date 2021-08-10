#ifndef __FSTREAM_CC
#define __FSTREAM_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * fstream.cc - Definition for the Standard Library file streams
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

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstdio>
#else
#include <stdio.h>
#endif // _RWSTD_NO_NEW_HEADER

#ifndef _RWSTD_STRICT_ANSI
#include <fcntl.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifdef __BORLANDC__
  template <class T>
  void __io_initialize (T& t, T val) { t = val; }
#pragma option -w-par
#endif

  /*
   * class basic_filebuf
   */

  /*
   * basic_filebuf()
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits>::basic_filebuf()
  : basic_streambuf<charT, traits>()
  , __file(__closed())
  , __data(0)
  , __read_buff(false)
  , __write_buff(false)
  , __last_numb_read(0)
  , __rwBufferSize(512)
  , __absolute_pos(0)
  {
    __state_beg = new state_t;
    __state_end = new state_t;
  }

  /*
   * basic_filebuf(__file_type)
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits>::basic_filebuf(__file_type fd)
  : basic_streambuf<charT, traits>()
  , __file(fd)
  , __read_buff(false)
  , __write_buff(false)
  , __last_numb_read(0)
  , __rwBufferSize(512)
  , __absolute_pos(0)
  {
    __data = new char_type[__rwBufferSize+1];
    __state_beg = new state_t;
    __state_end = new state_t;

#ifndef _RWSTD_STRICT_ANSI
    if ( fd == 0 )
      basic_streambuf<charT,traits>::mode_ = ios_base::in;
    else
    {
      if ( fd < 3 )
        basic_streambuf<charT,traits>::mode_ = ios_base::out;
    }
#else
    if ( fd == stdin )
      basic_streambuf<charT,traits>::mode_ = ios_base::in;
    else
    {
      if ( __file_is_std(fd) )
        basic_streambuf<charT,traits>::mode_ = ios_base::out;
    }
#endif // _RWSTD_STRICT_ANSI

  }
  /*
   * ~basic_filebuf()
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits>::~basic_filebuf()
  {
    close();
    delete __state_beg;
    delete __state_end;
  }

  /*
   * bool is_open() const
   */

  template<class charT, class traits>
  bool basic_filebuf<charT, traits>::is_open() const
  {
#ifndef _RWSTD_STRICT_ANSI
    return !(__file == -1);
#else
    return !(__file == 0);
#endif
  }

  /*
   * basic_filebuf *open(int fd)
   * fstream compatibility
   */

#ifndef _RWSTD_NO_EXTENSION

  template<class charT, class traits>
  basic_filebuf<charT, traits> *
  basic_filebuf<charT, traits>::
  open(int fd )
  {   
    if(__file != __closed())
      return 0;

    this->streambuf_init(false); 

    __file           = fd;
    __read_buff      = false;
    __write_buff     = false;
    __last_numb_read = 0; 

    delete [] __data;
    __data = new char_type[__rwBufferSize+1];

    if ( fd == 0 )
      basic_streambuf<charT,traits>::mode_ = ios_base::in;
    else
    {
      if ( fd < 3 )
        basic_streambuf<charT,traits>::mode_ = ios_base::out;
    }
    return this;
  }
#endif // _RWSTD_NO_EXTENSION
  /*
   * basic_filebuf *open(const char *, ios_base::openmode, long )
   * opens a file and allocates a buffer
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits> *
  basic_filebuf<charT, traits>::
  open(const char *s, ios_base::openmode mode, long protection)
  {
    long    m;
    if ( mode & ios_base::ate )
//      m = mode & (~ios_base::ate);  // RW_BUG
      m = mode & (~ios_base::ate) | ios_base::app; // RW_BUG: fix for bts-46733
    else
      m = mode;
#ifndef _RWSTD_STRICT_ANSI
    // Unset the nocreate/noreplace flags in case they exist,
    // these flags are not in the __RWSTD::__rwOpenTable table
    m = m & (~ios_base::nocreate);
    m = m & (~ios_base::noreplace);
#endif
    if(__file != __closed())
      return 0;

    basic_streambuf<charT,traits>::mode_ = mode;
    this->streambuf_init(false);

#ifndef _RWSTD_STRICT_ANSI
    if(__RWSTD::__rwOpenTable[m] == -1)
      return 0;
    int mm = __RWSTD::__rwOpenTable[m];
    // now do the right thing for nocreate/noreplace
    if ( mode & ios_base::out ) {
   	  if ( mode & ios_base::nocreate )
 	    mm &= ~O_CREAT;
 	  if ( mode & ios_base::noreplace )
 	    mm |= O_EXCL;
    }
    if((__file = ::open(s, mm, protection)) == __closed())
      return 0;
#else
    if(__RWSTD::__rwOpenTable[m] == 0)
      return 0;
    if((__file = fopen(s, __RWSTD::__rwOpenTable[m])) == __closed())
      return 0;
    setvbuf(__file,0,_IONBF,0);
#endif // _RWSTD_STRICT_ANSI

    delete [] __data;
    __data = new char_type[__rwBufferSize+1];

    if(mode & ios_base::ate)
    {
      if( (__absolute_pos = __file_seek(__file, 0, SEEK_END))== -1  )
      {
        close();
        delete [] __data;  
        __data = 0;
        __file = __closed();
        return 0;
      }
    }
    return this;
  }

  /*
   * basic_filebuf *close()
   * closes a file if one was already open.  Also deletes the
   * data, if it was allocated
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits> *
  basic_filebuf<charT, traits>::close()
  {
    delete __state_beg;
    delete __state_end;
    __state_beg = new state_t;
    __state_end = new state_t;

    __absolute_pos = 0;

    if ( (__file_is_std(__file))  && (__file != __closed()) )
    {
      if ( __write_buff )
        overflow( traits::eof() );
      __read_buff=false;
      __write_buff=false;
      __last_numb_read=0;
      return this;
    }
   
    if(__file != __closed())
    {          
      if ( __write_buff )
        overflow( traits::eof() );
      delete [] __data;
      __data = 0;
      __read_buff=false;
      __write_buff=false;
      __last_numb_read=0;
 

      if(__file_close(__file) == -1)
        return 0;

      __file = __closed();

      return this;
    }
    return 0;          
  }

  /*
   * streamsize showmanyc()
   */

  template<class charT, class traits>
  streamsize
  basic_filebuf<charT, traits>::showmanyc()
  { 
    if ( this->gptr() )
      return (int)(this->egptr()-this->gptr());
   
    if ( this->pptr() && __read_buff )
      return (streamsize)(this->epptr()-this->pptr());   

    return 0;

  }

  /*
   * int_type overflow(int_type)
   * this is called when the put pointer overruns the buffer.
   * it should flush what was in the put buffer, and move the pointer
   * back to the beginning
   */

  template<class charT, class traits>
  _TYPENAME basic_filebuf<charT, traits>::int_type
  basic_filebuf<charT, traits>::overflow(int_type c)
  {
    long  count = this->pptr() - this->pbase();
    bool   do_noconv;

    if(__file == __closed())        
      return traits::eof();

    if ( (this->pptr()==0) && this->gptr() )
    {
      this->setp(this->eback(),this->eback()+__rwBufferSize);
      pbump((int)(this->gptr()-this->eback()));
      this->setg(0,0,0);
      if ( this->pptr()<this->epptr() )
      { 
        if( !traits::eq_int_type(c,traits::eof()) ) 
        {
          sputc( traits::to_char_type(c) );
          this->gbump(1);
          __write_buff=true;
          return traits::to_int_type(*this->pptr());
        }
      } 
      count=  this->pptr() - this->pbase();
    }

    if ( (this->pptr()==0) && (this->gptr()==0) )
      this->setp(__data,__data+ __rwBufferSize);  

    __write_buff= false;

    if(count)
    {        
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
      do_noconv = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
      do_noconv = use_facet( this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
      .always_noconv();

      if ( do_noconv )
      {
        if ( __read_buff ) 
        {
          if ( __file_seek(__file, -__last_numb_read, SEEK_CUR) == -1 )
            return traits::eof();
        }
        if(!__file_write(__file,(char *)this->pbase(),sizeof(charT),count))
          return traits::eof();
      }
      else
      {
        long size_to = count*sizeof(charT);
        const charT *from_next =0;
        char *to= new char[size_to];
        char *to_next = 0;
        codecvt_base::result conv_result;

        if ( __read_buff )
        {
          if ( __file_seek(__file, -__last_numb_read, SEEK_CUR) == -1 )
            return traits::eof();
          else
          {
            state_t *tmp = __state_beg;
            __state_beg = __state_end;
            __state_end = tmp;
          }
        }
 
        *__state_beg = *__state_end;

        do {

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
          conv_result = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
          conv_result = use_facet( this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
          .out(*__state_end,this->pbase(),this->pptr(),from_next,
               to,to+size_to,to_next); 

          if ( conv_result == codecvt_base::noconv ) break;

          if (  (conv_result == codecvt_base::partial) || ( from_next != this->pptr() ) )
          {
            size_to *= 2;
            char *to_bis = new char[size_to];
            long diff_to = to_next - to;
            memcpy(to_bis,to,diff_to);
            delete [] to;
            to = to_bis;
            to_next = to + diff_to;
          }

        }while( (conv_result == codecvt_base::partial) || ( from_next != this->pptr()));

        if ( conv_result==codecvt_base::error )
        {
          delete [] to;
          return traits::eof();
        }

        if (conv_result == codecvt_base::noconv) 
        {
          if(!__file_write(__file, (char*)this->pbase(), sizeof(charT), count))
          {
            delete [] to;
            return traits::eof();              
          }
        } 
        else 
        {
          if(!__file_write(__file, to, sizeof(char),to_next-to))
          {
            delete [] to;
            return traits::eof();                
          }
        }
        delete [] to;
      }
    }

    this->setp(__data, __data+__rwBufferSize);    
    this->setg(0,0,0);                       
    __read_buff = false;              
    __write_buff= false; 

    __absolute_pos = __file_seek(__file,0,SEEK_CUR);

    if( !traits::eq_int_type(c,traits::eof()) ) 
    {
      sputc(traits::to_char_type(c));
      this->gbump(1);
      __write_buff = true;
    }
    else
      this->setp(0,0);

    return traits::not_eof(c);
  }

  /*
   * int_type pbackfail(int_type)
   */

  template<class charT, class traits>
  _TYPENAME basic_filebuf<charT, traits>::int_type
  basic_filebuf<charT, traits>::pbackfail(int_type c)
  {
    if(__file == __closed())
      return traits::eof();

    if ( (this->gptr()==0) && this->pptr() )
    {
      if ( __read_buff )
        this->setg(this->pbase(),this->pptr(),this->epptr());
      else
        this->setg(this->pbase(),this->pptr(),this->pptr()); 
    }

    if ( (!traits::eq_int_type(c,traits::eof())) && (this->gptr()>this->eback()) )
    {
      if ( traits::eq(*(this->gptr()-1),traits::to_char_type(c)) ) 
      {
        this->gbump(-1);
        return c;
      }
      else
      {
        this->gbump(-1);
        *this->gptr()=traits::to_char_type(c);
        return c;
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
   * basic_streambuf<charT,traits>* setbuf(char_type*,streamsize)
   */

  template<class charT, class traits>
  basic_streambuf<charT, traits>*
  basic_filebuf<charT, traits>::setbuf(char_type *s, streamsize n)
  {

    if (n>0)
    { 
      if ( __file != __closed() )
      {
        if ( !traits::eq_int_type(overflow( traits::eof() ),traits::eof()) )
        {
          if ( s )
          { 
            delete [] __data;
            __rwBufferSize = n-1; 
            __data=s;
          }
          else
          {
            charT *tmp;
            __rwBufferSize = n;  
            tmp = new char_type[__rwBufferSize+1];
            delete [] __data;
            __data = tmp;
          }
          this->setp(0,0);    
          this->setg(0,0,0);                         
          __read_buff=false;
          __write_buff=false;
        }
      }
      else
      {
        if ( s )
        {
          __rwBufferSize = n-1;
          __data =s;
          this->setp(0,0);    
          this->setg(0,0,0);                        
          __write_buff= false;
          __read_buff = false; 
        }
        else
          __rwBufferSize = n;
      }  
    } 
    return (basic_streambuf<charT,traits>*)(this); 
  }
  /*
   * int_type underflow()
   * this is called when the get pointer "underflows" the buffer,
   * or when there are no more "get" characters.
   */

  template<class charT, class traits>
  _TYPENAME basic_filebuf<charT, traits>::int_type
  basic_filebuf<charT, traits>::underflow()
  {
    bool do_noconv;
    long offset;
#ifndef __BORLANDC__
    offset = 0;
#else
    __io_initialize(offset,0L);
#endif

    if(__file == __closed())
      return traits::eof();
 
    if ( (this->gptr()==0) && this->pptr() )
    {
      if ( __read_buff )
        this->setg(this->pbase(),this->pptr(),this->epptr());
      else
        this->setg(this->pbase(),this->pptr(),this->pptr());

      this->setp(0,0);
    }

    if(this->gptr() && (this->gptr()<this->egptr()) ) return traits::to_int_type(*this->gptr());     

    if( ((__write_buff) && this->gptr() ) || ((__write_buff) && this->pptr() ) )
    {
      if ( traits::eq_int_type(overflow( traits::eof() ),traits::eof()) ) 
        return traits::eof();
      this->setg(this->pbase(),this->pptr(),this->epptr());
      this->setp(0,0);
      __write_buff = false; 
    }                 

    __absolute_pos = __file_seek(__file,0,SEEK_CUR);

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    do_noconv = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
    do_noconv = use_facet( this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
      .always_noconv();

    if ( do_noconv )
    {
      streamoff last_numb_read = __file_read(__file, (char *)__data,sizeof(charT),__rwBufferSize);
      if( last_numb_read <= 0 ) 
        return traits::eof();
      offset = last_numb_read/sizeof(charT);
      __last_numb_read = __get_chars(__data,__data + last_numb_read);
    }
    else
    {
      long from_size = __rwBufferSize*sizeof(charT);
      const char *from_next =0;
      char *from= new char[from_size];
      charT *to_next = 0;
      codecvt_base::result conv_result;

      streamoff last_numb_read = 0;
      long new_numb_read;

      do {
        new_numb_read = __file_read(__file, from+last_numb_read
                             ,sizeof(char),__rwBufferSize);

        if( new_numb_read <= 0 ) 
          break;

        last_numb_read += new_numb_read;
        *__state_beg = *__state_end;

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        conv_result = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
        conv_result = use_facet(this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
        .in(*__state_end,from,from+last_numb_read,from_next,__data,
            __data+__rwBufferSize,to_next); 
 
        if ( (conv_result == codecvt_base::error) ||
             (conv_result == codecvt_base::noconv) ) break;

        if (  (to_next != (__data + __rwBufferSize) ) &&
              ( (size_t)new_numb_read == __rwBufferSize*sizeof(charT) ) )
        {
          from_size *= 2;
          char *from_bis = new char[from_size];
          long diff_from = from_next - from;
          memcpy(from_bis,from,last_numb_read);
          delete [] from;
          from = from_bis;
          from_next = from + diff_from;
        }

      } while ( (to_next != (__data + __rwBufferSize) ) &&
                ( (size_t)new_numb_read == __rwBufferSize*sizeof(charT) ) ); 

      if( last_numb_read <= 0 ) 
        return traits::eof();
      __last_numb_read = last_numb_read;
               
      if ( (conv_result==codecvt_base::error) ||
           (conv_result==codecvt_base::partial) )
      {
        delete [] from;
        return traits::eof();
      } 
      else 
      {
        if (conv_result==codecvt_base::noconv)
        {
          memcpy((char*)__data,from,__last_numb_read);
          offset = __last_numb_read;
        }
        else
        {
          long diff_minus = new_numb_read - (from_next - from);
          if ( __file_seek(__file, -diff_minus, SEEK_CUR) == -1 )
            return traits::eof();
          __last_numb_read -= diff_minus;
          offset = to_next - __data;
        }
      }

      delete [] from;
    }
        
    if(__last_numb_read) 
    {   
      this->setg(__data, __data, __data+offset); 
      this->setp(0, 0);
      __read_buff=true;
      return traits::to_int_type(*this->gptr());
    }

    return traits::eof();
  }

  /*
   * pos_type seekoff(off_type, ios_base::seekdir, ios_base::openmode)
   */

  template<class charT, class traits>
  _TYPENAME basic_filebuf<charT, traits>::pos_type
  basic_filebuf<charT, traits>::seekoff(off_type off,
                                        ios_base::seekdir way,
                                        ios_base::openmode which)
  {
    off_type            loff = off;
    pos_type            newoff;

    if(__file == __closed())
      return pos_type(off_type(-1));

    if ( (off == off_type(-1)) && (way==ios_base::beg) )
      return pos_type(off_type(-1));

    if ( (way==ios_base::cur) )
    {
      streamsize remain_in_buffer=0;
      charT * remain_start=0;
      charT * remain_end=0;
     
      if ( __read_buff )
      {
        if ( this->gptr() )  
        {
          if (!this->eback())
            remain_in_buffer= this->egptr()-this->gptr();
          else
            remain_in_buffer= __get_chars(this->gptr(),this->egptr());
          remain_start = this->gptr();
          remain_end = this->egptr();
        }
        else
        {
          if ( this->pbase() )  
          {
            remain_in_buffer= __get_chars(this->pptr(),this->epptr());
            remain_start = this->pptr();
            remain_end = this->epptr();
          }
        }
      }
      else 
      {
        if ( __write_buff )
        {
          if ( this->pbase() )  
          {
            remain_in_buffer= -(__get_chars(this->pbase(),this->pptr()));
            remain_start = this->pbase();
            remain_end = this->pptr();
          }

          else
          { 
            if ( this->eback() )  
            {
              remain_in_buffer= -(__get_chars(this->eback(),this->gptr()));
              remain_start = this->eback();
              remain_end = this->gptr();
            }
          }
        }     
      }

      int const_conv;

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
      const_conv = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
      const_conv = use_facet( this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
      .encoding(); 

	  // If characters are not a constant size can't seek from current position
	  if ( (off != off_type(0)) && (const_conv <= 0) ) {
	    return pos_type(off_type(-1));
      }

      if ( const_conv > 0 )
      {
	    if (off !=off_type(0)) {
		  if (__write_buff ) {
		    overflow( traits::eof() );
			__write_buff = false;
			return ( __file_seek(__file, loff*const_conv,SEEK_CUR)/const_conv);
          }
		  this->setp(0,0);
		  this->setg(0,0,0);
          return ( __file_seek(__file, -((remain_in_buffer-loff)*const_conv), SEEK_CUR)/const_conv);
        }
        return ( (__file_seek(__file,0,SEEK_CUR)-remain_in_buffer*const_conv)/const_conv);
      }
	  else
      {
        // First find current position in file
        newoff = __file_seek(__file, 0, SEEK_CUR);

        // If necessary convert characters in buffer to 
        // find offset from file position
        if (remain_in_buffer != 0 && this->eback())
        {
          long to_size = __rwBufferSize;
          const charT *from = remain_start;
          const charT *from_next = from;
          const charT *from_end = remain_end;
          char *to_base = new char[to_size];
          char *to = to_base;
          char *to_next = to;
          char *to_end = to + to_size;
          codecvt_base::result conv_result;

          do {
            *__state_beg = *__state_end;

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
            conv_result = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
            conv_result = use_facet(this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
             .out(*__state_end,from,from_end,from_next,to,to_end,to_next); 
 
            if ( (conv_result == codecvt_base::error) ||
               (conv_result == codecvt_base::noconv) ) break;

            if ( to_next == to_end && from_next != from_end )
            {
              long diff_to = to_next - to_base;
              to_size *= 2;
              to = new char[to_size];
              memcpy(to,to_base,diff_to);
              delete [] to_base;
              to_base = to;
              to = to_base + diff_to;
              to_next = to;
              from = from_next;
              to_end = to_base + to_size;
            }

          } while ( from_next != from_end );
          
          // Calculate new file position
          // The  + remain_in_buffer - ... stuff is used to deal
          // with WIN32 CR/LF translations (see __get_chars())
          if (remain_in_buffer > 0)
            newoff -= (to_next - to_base) 
                      + (remain_in_buffer - (remain_end-remain_start));
          else
            newoff += (to_next - to_base)
                      + (-remain_in_buffer - (remain_end-remain_start));

          delete [] to;
        }
        return newoff;
      }
    } 

    int const_conv;

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    const_conv = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
    const_conv = use_facet( this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
    .encoding(); 

    if ( const_conv < 1 )
    {
      if ( (way==ios_base::beg) && (off==off_type(0)) )
      {
        seekpos(0);
      }
      else 
        return pos_type(off_type(-1));
    }

    if ( __write_buff)
    {  
      overflow( traits::eof() );
      __write_buff =false;  
    }

    int w = (way == ios_base::beg) ?
          SEEK_SET : ((way == ios_base::cur) ? SEEK_CUR : SEEK_END);  
    newoff = __file_seek(__file, loff*const_conv, w);

    this->setp(0,0);
    this->setg(0,0,0);

    return newoff;
  }

  /*
   * pos_type seekpos(pos_type, ios_base::openmode)
   */

  template<class charT, class traits>
  _TYPENAME basic_filebuf<charT, traits>::pos_type
  basic_filebuf<charT, traits>::
  seekpos(pos_type sp, ios_base::openmode which)
  { 
    if(__file == __closed())
      return pos_type(off_type(-1));

    if( sp == pos_type(off_type(-1)) )
      return pos_type(off_type(-1)); 

    int const_conv;

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    const_conv = use_facet< codecvt<charT,char,state_t> >(this->getloc())
#else
    const_conv = use_facet( this->getloc(), (codecvt<charT,char,state_t>* )0)
#endif
    .encoding();

    if ( const_conv > 0 )
      return seekoff(off_type(sp), ios_base::beg, which);

    _TYPENAME traits::off_type end_pos = __file_seek(__file,0,SEEK_END);
   
    if ( __file_seek(__file, sp, SEEK_SET) == -1 )
      return pos_type(off_type(-1));

    this->setp(0,0);
    this->setg(0,0,0); 

    *__state_beg = *__state_end = sp.state();

    if ( traits::eq_int_type(underflow(),traits::eof()) && (end_pos > sp))
      return pos_type(off_type(-1));

    return sp;   
  }

  /*
   * int sync()
   * this synchronizes the buffers and their streams
   */

  template<class charT, class traits>
  int basic_filebuf<charT, traits>::sync()
  {
    if ( this->which_open_mode( ) & ios_base::out )
    {
#ifndef _RWSTD_STRICT_ANSI
      if ( __file == 1 || __file == 2)
#else
      if ( __file == stdout || __file == stderr )
#endif
      {
        if( traits::eq_int_type(overflow(traits::eof()),traits::eof()) ) 
          return -1;
      }
      else
      { 
        pos_type p_out = seekoff(0,ios_base::cur,ios_base::out);
        pos_type tmp_out = __file_seek(__file,0,SEEK_CUR);
        pos_type end_out = __file_seek(__file,0,SEEK_END);
        __file_seek(__file,tmp_out,SEEK_SET);
        if ( end_out > p_out )
        {
          if( seekpos(p_out) == pos_type(off_type(-1)))
            return -1;
        }
        else if (__write_buff)
        {
          if( traits::eq_int_type(overflow(traits::eof()),traits::eof()) )
            return -1;
        }
      }
    }

    if ( this->which_open_mode( ) & ios_base::in )
    {
#ifndef _RWSTD_STRICT_ANSI
      if ( __file != 0 )
#else
      if ( __file != stdin )
#endif
      {
        pos_type p_in = seekoff(0,ios_base::cur,ios_base::in);
        pos_type tmp_in = __file_seek(__file,0,SEEK_CUR);
        pos_type end_in = __file_seek(__file,0,SEEK_END);
        __file_seek(__file,tmp_in,SEEK_SET);
        if ( end_in > p_in )
        {
          if( seekpos(p_in) == pos_type(off_type(-1)))
            return -1;
        }
      }
    }

    return 0;
  }
  /*
   * streamsize xsputn(const char_type *, streamsize)
   */

  template<class charT, class traits>
  streamsize basic_filebuf<charT, traits>::
  xsputn(const char_type *s, streamsize n)
  {
    if ( !s || (n == 0) ) return 0;

    if ( n >  __rwBufferSize )
    {

      if ( traits::eq_int_type(overflow( traits::eof() ),traits::eof()) )
        return 0;

      char_type   *eback_s = this->eback();
      char_type   *gptr_s  = this->gptr();
      char_type   *egptr_s = this->egptr();

      char_type   *pbase_s = this->pbase();
      char_type   *pptr_s  = this->pptr();
      char_type   *epptr_s = this->epptr();

      this->setg(0,0,0);
      this->setp((char_type *)s,(char_type *)(s+n));
      basic_streambuf<charT, traits>::pbump(n);

      if ( traits::eq_int_type(overflow( traits::eof() ),traits::eof()) )
        return 0; 
  
      this->setg(eback_s,gptr_s,egptr_s);
      this->setp(pbase_s,epptr_s);

      pbump(pptr_s-pbase_s); 

      return n;
    }
    else
    {
      int         i=0;
      while((i < n) && ( !traits::eq_int_type(sputc(*s++),traits::eof())))
        i++;
      return i;
    }

  }

 
  /*
   * class basic_ifstream : public basic_istream
   */

  /*
   * basic_ifstream()
   */

  template<class charT, class traits>
  basic_ifstream<charT, traits>::basic_ifstream()
  : basic_istream<charT, traits>( )
  {
    init(&__fb);
  }

  /*
   * basic_ifstream(const char *, ios_base::openmode, long)
   * opens a filebuf for (most likely) reading
   */

  template<class charT, class traits>
  basic_ifstream<charT, traits>::basic_ifstream(const char *s,
                                                ios_base::openmode mode,
                                                long protection )
  : basic_istream<charT, traits>( )
  {
    init(&__fb);
    open(s, mode, protection);
  }

  /*
   * basic_ifstream(int fd)
   * opens a filebuf for reading
   */
#ifndef _RWSTD_NO_EXTENSION

  template<class charT, class traits>
  basic_ifstream<charT, traits>::
  basic_ifstream(int fd)
  : basic_istream<charT, traits>( )
  {

    init(&__fb);

    if ( !__fb.open(fd) ) 
      this->setstate(ios_base::failbit);
  }

  /*
   * basic_ifstream(int fd, char_type *buf, int len)
   * opens a filebuf for reading
   */

  template<class charT, class traits>
  basic_ifstream<charT, traits>::
  basic_ifstream(int fd, char_type *buf, int len)
  : basic_istream<charT, traits>( )
  {

    init(&__fb);

    if ( ( buf!=0 ) && ( len>0 ) )
      __fb.pubsetbuf(buf,len);

    if ( !__fb.open(fd) ) 
      this->setstate(ios_base::failbit);
  }
#endif // _RWSTD_NO_EXTENSION

  /*
   * ~basic_ifstream()
   */

  template<class charT, class traits>
  basic_ifstream<charT, traits>::~basic_ifstream()
  {
  }

  /*
   * basic_filebuf *rdbuf() const
   * returns the streambuf associated with this stream
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits> *
  basic_ifstream<charT, traits>::rdbuf() const
  {
    return (basic_filebuf<charT, traits> *)&__fb;
  }

  /*
   * bool is_open()
   */

  template<class charT, class traits>
  bool basic_ifstream<charT, traits>::is_open()
  {
    return __fb.is_open();
  }

  /*
   * void open(const char *, ios_base::openmode, long )
   * opens up a file
   */

  template<class charT, class traits>
  void basic_ifstream<charT, traits>::open(const char *s,
                                           ios_base::openmode mode,
                                           long protection )
  {
    this->clear();
    mode |= ios_base::in; 

    if ( !__fb.open(s, mode, protection) )  
      this->setstate(ios_base::failbit);
  }

  /* 
   * void close()
   */

  template<class charT, class traits>
  void basic_ifstream<charT, traits>::close()
  {
    if(!is_open())
      return;
  
    if(!__fb.close())
      this->setstate(ios_base::failbit);
    else
      this->clear();
  }
  /*
   * class basic_ofstream : public basic_ostream
   */

  /*
   * basic_ofstream()
   */

  template<class charT, class traits>
  basic_ofstream<charT, traits>::basic_ofstream()
  : basic_ostream<charT, traits>( )
  {
    init(&__fb);
  }

  /*
   * basic_ofstream(const char *, ios_base::openmode, long )
   */

  template<class charT, class traits>
  basic_ofstream<charT, traits>::
  basic_ofstream(const char *s, ios_base::openmode mode, long protection)
  : basic_ostream<charT, traits>()
  {
       
    init(&__fb);
    open(s, mode, protection);
  }

  /*
   * basic_ofstream(int fd)
   * opens a filebuf for writing
   */
#ifndef _RWSTD_NO_EXTENSION

  template<class charT, class traits>
  basic_ofstream<charT, traits>::
  basic_ofstream(int fd)
  : basic_ostream<charT, traits>( )
  {

    init(&__fb);

    if ( !__fb.open(fd) ) 
      this->setstate(ios_base::failbit);
  }

  /*
   * basic_ofstream(int fd, char_type *buf, int len)
   * opens a filebuf for writing
   */

  template<class charT, class traits>
  basic_ofstream<charT, traits>::
  basic_ofstream(int fd, char_type *buf, int len)
  : basic_ostream<charT, traits>( )
  {

    init(&__fb);

    if ( ( buf!=0 ) && ( len>0 ) )
      __fb.pubsetbuf(buf,len);

    if ( !__fb.open(fd) ) 
      this->setstate(ios_base::failbit);
  }
#endif // _RWSTD_NO_EXTENSION

  /*
   * ~basic_ofstream()
   */

  template<class charT, class traits>
  basic_ofstream<charT, traits>::~basic_ofstream()
  {
  }

  /*
   * basic_filebuf *rdbuf() const
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits> *
  basic_ofstream<charT, traits>::rdbuf() const
  {
    return (basic_filebuf<charT, traits> *)&__fb;
  }

  /*
   * bool is_open()
   */

  template<class charT, class traits>
  bool basic_ofstream<charT, traits>::is_open()
  {
    return __fb.is_open();
  }

  /*
   * void open(const char *, ios_base::openmode)
   */

  template<class charT, class traits>
  void basic_ofstream<charT, traits>::open(const char *s,
                                           ios_base::openmode mode,
                                           long protection )
  {
    this->clear();
    mode |= ios_base::out;

    if ( !__fb.open(s, mode, protection) )
      this->setstate(ios_base::failbit);
  }

  /*
   * void close()
   */

  template<class charT, class traits>
  void basic_ofstream<charT, traits>::close()
  {
    if(!is_open())
      return;

    if(!__fb.close())
      this->setstate(ios_base::failbit);
    else
      this->clear();
  }

  /*
   * class basic_fstream : public basic_iostream
   */

  /*
   * basic_fstream()
   */

  template<class charT, class traits>
  basic_fstream<charT, traits>::basic_fstream()
  : basic_iostream<charT, traits>( )
  {
    init(&__fb);
  }

  /*
   * basic_fstream(const char *, ios_base::openmode, long)
   *
   * opens a filebuf for reading and writing
   */

  template<class charT, class traits>
  basic_fstream<charT, traits>::
  basic_fstream(const char *s, ios_base::openmode mode, long protection)
  : basic_iostream<charT, traits>( )
  {
    init(&__fb);
    open(s, mode, protection);
  }

  /*
   * basic_fstream(int fd)
   * opens a filebuf for reading and writing
   */
#ifndef _RWSTD_NO_EXTENSION

  template<class charT, class traits>
  basic_fstream<charT, traits>::
  basic_fstream(int fd)
  : basic_iostream<charT, traits>( )
  {

    init(&__fb);

    if ( !__fb.open(fd) ) 
      this->setstate(ios_base::failbit);
  }

  /*
   * basic_fstream(int fd, char_type *buf, int len)
   * opens a filebuf for reading and writing
   */

  template<class charT, class traits>
  basic_fstream<charT, traits>::
  basic_fstream(int fd, char_type *buf, int len)
  : basic_iostream<charT, traits>( )
  {

    init(&__fb);

    if ( ( buf!=0 ) && ( len>0 ) )
      __fb.pubsetbuf(buf,len);

    if ( !__fb.open(fd) ) 
      this->setstate(ios_base::failbit);
  }
#endif // _RWSTD_NO_EXTENSION
  /*
   * ~basic_fstream()
   */

  template<class charT, class traits>
  basic_fstream<charT, traits>::~basic_fstream()
  {
  }

  /*
   * basic_filebuf *rdbuf() const
   * returns the streambuf associated with this stream
   */

  template<class charT, class traits>
  basic_filebuf<charT, traits> *
  basic_fstream<charT, traits>::rdbuf() const
  {
    return (basic_filebuf<charT, traits> *)&__fb;
  }

  /*
   * bool is_open()
   */

  template<class charT, class traits>
  bool basic_fstream<charT, traits>::is_open()
  {
    return __fb.is_open();
  }

  /*
   * void open(const char *, ios_base::openmode, long)
   * opens up a file
   */

  template<class charT, class traits>
  void basic_fstream<charT, traits>::
  open(const char *s, ios_base::openmode mode, long protection)
  {
    this->clear();
    if ( !__fb.open(s, mode, protection) ) 
      this->setstate(ios_base::failbit);
  }

  /* 
   * void close()
   */

  template<class charT, class traits>
  void basic_fstream<charT, traits>::close()
  {
    if(!is_open())
      return;
  
    if(!__fb.close())
      this->setstate(ios_base::failbit);
    else
      this->clear();
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __FSTREAM_CC */
