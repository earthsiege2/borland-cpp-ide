#include "stlhdrs.h"
#pragma  hdrstop
/**************************************************************************
 *
 * ios.cpp - Source for the Standard Library ios classes
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
#include <rw/rwstderr.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif
#ifdef _RWSTD_LOCALIZED_ERRORS
  extern const unsigned int  _RWSTDExport rwse_failbit_set = _RWSTD_ERROR_FAILBIT_SET;
  extern const unsigned int  _RWSTDExport rwse_badbit_set = _RWSTD_ERROR_BADBIT_SET;
  extern const unsigned int  _RWSTDExport rwse_eofbit_set = _RWSTD_ERROR_EOFBIT_SET;  
#else
  extern const char _RWSTDExportFunc(*) rwse_failbit_set = "iostream object has failbit set";
  extern const char _RWSTDExportFunc(*) rwse_badbit_set = "iostream object has badbit set";
  extern const char _RWSTDExportFunc(*) rwse_eofbit_set = "iostream object has eofbit set";
#endif // _RWSTD_LOCALIZED_ERRORS
#ifndef _RWSTD_NO_NAMESPACE
}
namespace std {
#endif

  int  ios_base::__index = 0;
  bool ios_base::__sync_with_stdio = true;
    
  /*
   *    class ios_base::failure member functions  
   */
 
#ifdef _RW_STD_EXCEPT
#ifndef _RWSTD_NO_EXCEPTIONS

  /*
   * ios_base::failure::failure(const string& )
   */

  ios_base::failure::failure(const string& msg) 
  : __str(msg)
  {
  }

  /*
   * ios_base::failure::~failure()
   */

  ios_base::failure::~failure() _RWSTD_THROW_SPEC_NULL
  {
  }

  /*
   * const char* ios_base::failure::what() const
   */

  const char*
  ios_base::failure::what( ) const _RWSTD_THROW_SPEC_NULL
  {

	  return __str.data();
  }

#endif // _RWSTD_NO_EXCEPTIONS 
#endif // _RW_STD_EXCEPT

#if defined ( __SUNPRO_CC )
int ios_base::Init::__initcnt;

#ifndef _RWSTD_STRICT_ANSI
# define _RWSTD_STDIN  0
# define _RWSTD_STDOUT 1
# define _RWSTD_STDERR 2
#else
# define _RWSTD_STDIN  stdin
# define _RWSTD_STDOUT stdout
# define _RWSTD_STDERR stderr
#endif // _RWSTD_STRICT_ANSI

  filebuf _RWSTDExport     __stdin_filebuf(_RWSTD_STDIN);
  filebuf _RWSTDExport     __stdout_filebuf(_RWSTD_STDOUT);
  filebuf _RWSTDExport     __stderr_filebuf(_RWSTD_STDERR);

  istream _RWSTDExport            cin(ios_base::emptyctor);
  ostream _RWSTDExport            cout(ios_base::emptyctor);
  ostream _RWSTDExport            cerr(ios_base::emptyctor);
  ostream                         clog(ios_base::emptyctor);

#endif  
  
  /*
   * ios_base::Init::Init()
   */

  ios_base::Init::Init()
  {
    if(++__initcnt != 1)
      return;
#if defined ( __SUNPRO_CC )
	new (&__stdin_filebuf) filebuf(_RWSTD_STDIN);
	new (&__stdout_filebuf) filebuf(_RWSTD_STDOUT);
	new (&__stderr_filebuf) filebuf(_RWSTD_STDERR);

	new (&cin) istream(&__stdin_filebuf);
	new (&cout) ostream(&__stdout_filebuf);
	new (&cerr) ostream(&__stderr_filebuf);
	new (&clog) ostream(&__stderr_filebuf);
#endif
	
    cin.tie(&cout);
    cerr.tie(&cout);
    clog.tie(&cout);

    cerr.setf(basic_ios<char, char_traits<char> >::unitbuf);
  }

#if defined ( __SUNPRO_CC )
#undef _RWSTD_STDIN 
#undef _RWSTD_STDOUT
#undef _RWSTD_STDERR
#endif

  /*
   * ios_base::Init::~Init()
   */

  ios_base::Init::~Init()
  {
    if(!(--__initcnt))
    {
      cout.flush();
      cerr.flush();
      clog.flush();
    }
  }

  /*
   * ios_base& copyfmt(const ios_base& )
   */

  ios_base&
  ios_base::copyfmt(const ios_base& rhs)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    return _RW_UNSAFE_copyfmt(rhs);
  }

  ios_base&
  ios_base::_RW_UNSAFE_copyfmt(const ios_base& rhs)
  {
    while ( __index_callback )
    {
      __index_callback--;
      (*(__registered_call[__index_callback].__fn)) ( erase_event, *this,
                                                      __registered_call[__index_callback].__index );     
    }

    __fmtfl = rhs.__fmtfl;
    __prec  = rhs.__prec;
    __wide  = rhs.__wide;
    __loc   = rhs.__loc;
       
    delete []__userwords;
    __userwords=0;
    __index_cp = 0;

    usersize(rhs.__index_cp);

    memcpy(__userwords, rhs.__userwords,rhs.__index_cp*sizeof(ios_user_union));

    delete []__registered_call;
    __registered_call =0;
    __index_callback =0; 

    if ( rhs.__index_callback )
    {
      __registered_call = new register_call[rhs.__index_callback];
      __index_callback = rhs.__index_callback;
      for(int loop_bis = 0; loop_bis < __index_callback; loop_bis++)
      {
        __registered_call[loop_bis].__index = rhs.__registered_call[loop_bis].__index;
        __registered_call[loop_bis].__fn = rhs.__registered_call[loop_bis].__fn;
      } 

    }

    int tmp_call = __index_callback;

    while ( tmp_call )
    {
      tmp_call--;
      (*(__registered_call[tmp_call].__fn)) ( copyfmt_event, *this,
                                              __registered_call[tmp_call].__index );     
    }

    return *this;
  }

  /*
   * static int xalloc()
   */

  int ios_base::xalloc()
  {
#ifdef _RWSTD_MULTI_THREAD
    static _RWSTDMutex guard_me;
    _RWSTDGuard guard(guard_me);
#endif
    __index++;
    return (__index-1); 
  }

  /*
   * void usersize(int)
   */

  void ios_base::usersize(int i)
  {

    if ( i>0 )
    {
      ios_user_union *p = new ios_user_union[i];
      memset(p,0,i*sizeof(ios_user_union));
             
      if(__userwords) 
      {
        int size_ = ( i > __index_cp ) ? __index_cp : i;
        memcpy(p, __userwords,size_ * sizeof(ios_user_union));
        delete []__userwords;
      }

      __userwords = p;
      __index_cp = i;
    }
        
    if ( __index_cp > __index ) __index = __index_cp;
  }
  /*
   * long& iword(int)
   */
  long& ios_base::iword(int index)
  {  
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif

    if( (!__userwords) || (index >= __index_cp) )    
      usersize(index+1);
       
    if ( index >= 0 )
      return __userwords[index].__lword;
    else
      return __userwords[0].__lword;
  }

  /*
   * void*& __pword(int)
   */

  void*& ios_base::pword(int index)
  { 
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif

    if( (!__userwords) || (index >= __index_cp) ) 
      usersize(index+1);

    if ( index >= 0 )
      return __userwords[index].__pword;
    else
      return __userwords[0].__pword;
  }

  /*
   * void register_callback( event_callback fn, int index);
   */

  void ios_base::register_callback( ios_base::event_callback fn, int index)
  { 
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    if ( fn )
    {
      if ( __index_callback )
      {
        struct register_call *tmp;

        __index_callback++;
        tmp = new register_call[__index_callback];

        memcpy(tmp, __registered_call , 
               (__index_callback - 1) * sizeof(register_call));

        delete []__registered_call;
        __registered_call = tmp; 
      }
      else
      {
        __registered_call = new register_call;
        __index_callback++;
      }
      __registered_call[__index_callback-1].__index = index;
      __registered_call[__index_callback-1].__fn = fn;
    }
  }

  /*
   * ios_base()
   */

  ios_base::ios_base(): __userwords(0)
  ,__index_cp(0)
  ,__registered_call(0)
  ,__index_callback(0) 
  {
  }

  ios_base::~ios_base()
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    while ( __index_callback )
    {
      __index_callback--;
      (*(__registered_call[__index_callback].__fn)) ( erase_event, *this,
                                                      __registered_call[__index_callback].__index );     
    }
 
    delete []__userwords;
    delete []__registered_call;
  }

  /*
   * void imbue(const locale& )
   */

  locale ios_base::
  imbue(const locale& loc)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    locale tmp = __loc;
    __loc=loc;
    int tmp_call = __index_callback;

    while ( tmp_call )
    {
      tmp_call--;
      (*(__registered_call[tmp_call].__fn)) ( imbue_event, *this,
                                              __registered_call[tmp_call].__index );     
    }

    return tmp;  
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#if defined(__BORLANDC__) && defined(_RWSTD_MULTI_THREAD)
#   ifndef _RWSTD_NO_NAMESPACE
      namespace std {
#   endif
  // Generate instantiations for __lock & __unlock stream functions.
  template basic_ios<char, char_traits<char> >&       __lock   (basic_ios<char, char_traits<char> >& __strm);
  template basic_ios<wchar_t, char_traits<wchar_t> >& __lock   (basic_ios<wchar_t, char_traits<wchar_t> >& __strm);
  template basic_ios<char, char_traits<char> >&       __unlock (basic_ios<char, char_traits<char> >& __strm);
  template basic_ios<wchar_t, char_traits<wchar_t> >& __unlock (basic_ios<wchar_t, char_traits<wchar_t> >& __strm);
#   ifndef _RWSTD_NO_NAMESPACE
}     // namespace std
#   endif
#endif
