#ifndef __ISTREAM_CC
#define __ISTREAM_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * istream.cc - istream definitions
 *
 ***************************************************************************
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
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
#include <cctype>
#else
#include <ctype.h>
#endif

#include <ios>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  /*
   * basic_istream manipulators
   * skips the next available white spaces
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  _RWSTDExportTemplate ws(basic_istream<charT, traits>& is)
  {
    _TYPENAME traits::int_type        c;

#ifdef _RWSTD_MULTI_THREAD
    if ( is.rdbuf() )
      is.istream_sentry_guard = new _RWSTDGuard(is.rdbuf()->buffer_mutex_);
#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
#endif // _RWSTD_MULTI_THREAD

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
      const ctype<charT>& ct = use_facet< ctype<charT> >(is.getloc());
#else
      const ctype<charT>& ct = use_facet(is.getloc(),(ctype<charT>*)0);
#endif         
      while((c = is.rdbuf()->sgetc()),
            ( !traits::eq_int_type(c,traits::eof()) && ct.is(ct.space,c) )) 
        is.rdbuf()->snextc();
 
      if( traits::eq_int_type(c,traits::eof()) )
        is.setstate(ios_base::eofbit);

#if defined (_RWSTD_MULTI_THREAD) && !defined (_RWSTD_NO_EXCEPTIONS)
    } catch(...) 
    {
      if ( is.rdbuf() )
        delete is.istream_sentry_guard;
      throw;
    }          
#endif // _RWSTD_MULTI_THREAD etc.
       
#ifdef _RWSTD_MULTI_THREAD
    if ( is.rdbuf() )
      delete is.istream_sentry_guard;
#endif

    return is;
  }

  /*
   * basic_istream(basic_streambuf *)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>::
  basic_istream(basic_streambuf<charT, traits> *sb)
  : __chcount(0)
  {
    if ( sb )
    {
      if ( sb->which_open_mode() & ios_base::in )
        this->init(sb);
      else
        this->init(0);
    } 
    else
      this->init(0); 
  }

  /*
   * basic_istream( )
   */

  template<class charT, class traits>
  basic_istream<charT, traits>::
  basic_istream( )
  : __chcount(0)
  { 
  }

  /*
   * ~basic_istream();
   */

  template<class charT, class traits>
  basic_istream<charT, traits>::~basic_istream()
  {
  }

  /*
   * istream_type& operator>>(istream_type& (*pf)(istream_type&))
   * for functions relating to istreams
   */
  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::
  operator>>(basic_istream<charT,traits>& (*pf)(basic_istream<charT,traits>&))
  {
    (*pf)(*this);
    return *this;
  }

  /*
   * istream_type& operator>>(ios_base& (*pf)(ios_base&))
   * for manipulators relating to the ios_base class
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::
  operator>>(ios_base& (*pf)(ios_base&))
  {
    (*pf)(*this);
    return *this;
  }

  /*
   * istream_type& operator>>(ios_type& (*pf)(ios_type&))
   * used to set one of the ios states (ios manipulator)
   */
  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::
  operator>>(basic_ios<charT, traits>& (*pf)(basic_ios<charT, traits>&))
  {
    (*pf)(*this);
    return *this;
  }

  /*
   * basic_istream<charT,traits>& operator>>(basic_istream<charT,traits>, charT *)
   * read in a charT *. 
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  _RWSTDExportTemplate operator>>(basic_istream<charT, traits>& is, charT *p)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      if ( p!=0 )
      {
        _TYPENAME basic_istream<charT, traits>::sentry ipfx(is);

        if(ipfx)
        { 
          charT                      *op = p;
          _TYPENAME traits::int_type  c = 0;
          int                        len; 
          if ( is.width() == 0 ) len=0; 
          else len=is.width(); 

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
          const ctype<charT>& ct = use_facet< ctype<charT> >(is.getloc());
#else
          const ctype<charT>& ct = use_facet(is.getloc(), (ctype<charT>*)0);
#endif
          while(--len &&
                (c = is.rdbuf()->sgetc(),!( traits::eq_int_type(c,traits::eof()) ||
                                            ct.is(ct.space,c))))
          {
            *p++ = c;
            is.rdbuf()->sbumpc();
          }
        
          if( traits::eq_int_type(c,traits::eof()) )
            err = ((p == op) ? 
                   (ios_base::eofbit | ios_base::failbit) : ios_base::eofbit);
          *p = charT ('\0');  
          is.width(0); 
        }
      }
      else
        err = ios_base::failbit;

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        is.setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS
    if ( err ) is.setstate(err);
    return is;
  }

  /*
   * basic_istream<charT,traits>& operator>>(basic_istream<charT,traits>&, charT& )
   * read in a character
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  _RWSTDExportTemplate operator>>(basic_istream<charT,traits>& is, charT& c)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(is);
 
      if(ipfx)
      { 
        _TYPENAME traits::int_type tmp = is.rdbuf()->sbumpc();
        if ( traits::eq_int_type(traits::eof(),tmp) ) 
          err = ios_base::failbit | ios_base::eofbit;
        else
          c = traits::to_char_type(tmp);
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        is.setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS
    if ( err ) is.setstate(err);
    return is;
  }

#ifndef _RWSTD_NO_SIGNED_CHAR_IN_STREAMS
  /*
   * istream& operator>>(basic_istream<char,traits>&,unsigned char& )
   */

  template <class traits>
  basic_istream<char, traits>&
  _RWSTDExportTemplate operator>>(basic_istream<char, traits>& is, unsigned char& uc)
  {
    is >> (char &)uc;
    return is;
  }

  /*
   * istream& operator>>(basic_istream<char, traits>&, signed char& )
   */

  template <class traits>
  basic_istream<char, traits>&
  _RWSTDExportTemplate operator>>(basic_istream<char, traits>& is, signed char& sc)
  {
    is >> (char &)sc;
    return is;
  }

  /*
   * istream& operator>>(basic_istream<char, traits>&, unsigned char* )
   */

  template <class traits>
  basic_istream<char, traits>&
  _RWSTDExportTemplate operator>>(basic_istream<char, traits>& is,unsigned char* uc)
  {
    is >> (char *)uc;
    return is;
  }

  /*
   * istream& operator>>(basic_istream<char, traits>&,signed char* )
   */

  template <class traits>
  basic_istream<char, traits>&
  _RWSTDExportTemplate operator>>(basic_istream<char, traits>& is, signed char* sc)
  {
    is >> (char *)sc;
    return is;
  }
#endif // _RWSTD_NO_SIGNED_CHAR_IN_STREAMS

#ifndef _RWSTD_NO_BOOL
  /*
   * istream_type& operator>>(bool&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(bool& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);
      if(ipfx) 
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,n);
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS
    if ( err ) this->setstate(err);
    return *this;
  }

#endif // _RWSTD_NO_BOOL 

  /*
   * istream_type& operator>>(short&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(short& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx) 
      {
        long l;
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,l);
        n=(short)l;
        if ( (n!=l) && ((unsigned short)n != l) )
          err |= ios_base::failbit;
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS
    if ( err ) this->setstate(err);
    return *this;
  }
  /*
   * istream_type& operator>>(unsigned short&)
   */
  
  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(unsigned short& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);
      if(ipfx)
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,n);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif // _RWSTD_NO_EXCEPTIONS
    if ( err ) this->setstate(err);
    return *this;
  }
  /*
   * istream_type& operator>>(int&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(int& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      {
        long l;
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,l);
        n=(int)l;
        if ( (n!=l) && ((unsigned int)n!=(unsigned long)l) )
          err |= ios_base::failbit;
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(unsigned int&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(unsigned int& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,n);
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err); 
    return *this;
  }

  /*
   * istream_type& operator>>(long&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(long& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,n);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(unsigned long&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(unsigned long& n)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,n);
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } //  end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(float&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(float& f)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      { 
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,f);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(double&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(double& f)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,f);
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(long double&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(long double& f)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx)
      {  
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else   
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,f);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }
/*
 * istream_type& operator>>(_RWSTD_LONG_LONG&)
 */

#ifdef _RWSTD_LONG_LONG

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(_RWSTD_LONG_LONG& ll)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 

      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx) { 
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else  
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,ll);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif

    if ( err ) this->setstate(err);

    return *this;
  }

/*
 * istream_type& operator>>(unsigned _RWSTD_LONG_LONG&)
 */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(unsigned _RWSTD_LONG_LONG& ull)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 

      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx) { 
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else  
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,ull);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif

    if ( err ) this->setstate(err);

    return *this;
  }
#endif // _RWSTD_LONG_LONG
  /*
   * istream_type& operator>>(void*&)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(void*& p)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

      if(ipfx) 
      {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        use_facet<num_get<charT,istreambuf_iterator<charT,traits> > >(this->getloc())
#else
        use_facet(this->getloc(),(num_get<charT,istreambuf_iterator<charT,traits> >*)0)
#endif
        .get(istreambuf_iterator<charT,traits>(*this),istreambuf_iterator<charT,traits>(),*this,err,p);
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(basic_streambuf&)
   * reads characters from the stream and inserts them into 'sb'
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(streambuf_type& sb)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);
      if(ipfx)
      {
        int_type         c;

        if ( traits::eq_int_type(this->rdbuf()->sgetc(),traits::eof()) ) 
          err = ios_base::failbit; 
         
        while( !traits::eq_int_type( (c = this->rdbuf()->sgetc()),traits::eof()) ) {
          if( traits::eq_int_type(sb.sputc(c),traits::eof()) ) { 
            err = ios_base::failbit;
            break;
          }
          this->rdbuf()->sbumpc();  
        }
        if( traits::eq_int_type(c,traits::eof()) ) 
          err |= ios_base::eofbit;  
      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::failbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& operator>>(basic_streambuf *)
   * reads characters from the stream and inserts them into 'sb'
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::operator>>(streambuf_type *sb)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 
      if ( sb!=0 )
      {
        _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this);

        if(ipfx)
        {
          int_type         c;
    
          if ( traits::eq_int_type(this->rdbuf()->sgetc(),traits::eof()) ) 
            err = ios_base::failbit; 
     
          while( !traits::eq_int_type( (c = this->rdbuf()->sgetc()),traits::eof()) )
          {
            if( traits::eq_int_type(sb->sputc(c),traits::eof()) )
            { 
              err = ios_base::failbit;
              break;
            }
            this->rdbuf()->sbumpc(); 
          }
          if( traits::eq_int_type(c,traits::eof()) )
            err |= ios_base::eofbit;
        }
      }
      else
        err = ios_base::failbit;

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::failbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& get(char_type *, streamsize, char_type)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::
  get(char_type *s, streamsize n, char_type delim)
  {
    ios_base::iostate err = 0; 

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      __chcount = 0; 

      if (s!=0)
      {
        _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);
        if(ipfx)
        { 
          char_type  *op = s;
          int_type   c = 0;

          while(--n > 0 && (c = this->rdbuf()->sgetc()) != delim && 
                ( !traits::eq_int_type(c,traits::eof()) ))
          {
            *s++ = c; 
            ++__chcount;
            this->rdbuf()->snextc(); 
          }

          if( traits::eq_int_type(c,traits::eof()) )  
            err = ((s == op) ? (ios_base::eofbit | ios_base::failbit) :
                   ios_base::eofbit);
        }

        *s = 0;  //terminate with null
      }
      else
        err = ios_base::badbit;

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& get(char_type&)
   * gets a single character, first skipping white space.
   * see also: int_type get();
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::get(char_type& s)
  {
    ios_base::iostate err = 0;  

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);
      __chcount = 0;

      if(ipfx)
      { 
        int_type tmp = this->rdbuf()->sbumpc();
        if ( traits::eq_int_type(tmp,traits::eof()) ) 
        {
          err = ios_base::failbit | ios_base::eofbit;
        }
        else
        {
          s = traits::to_char_type(tmp);
          __chcount = 1;
        }
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif
 
#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& get(basic_streambuf&, char_type)
   * insert characters into sb upto delim
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::
  get(streambuf_type& sb, char_type delim)
  {
    ios_base::iostate err = 0;   

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);
      __chcount = 0;

      if(ipfx)
      { 
        int_type        c;

        while(((c = this->rdbuf()->sgetc()) != delim) && 
              ( !traits::eq_int_type(c,traits::eof()) ))
        {
          if( traits::eq_int_type(sb.sputc(c),traits::eof()) ) {  
            err = ios_base::failbit;  
            break;
          }
          ++__chcount;
          this->rdbuf()->sbumpc();  
        }

        if(c == traits::eof())  
          err |= ios_base::eofbit;
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& getline(char_type *, streamsize, char_type)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::
  getline(char_type *s, streamsize n, char_type delim)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
      __chcount = 0; 

      if (s!=0)
      {
        _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);

        if(ipfx) {  
          char_type    *op = s;
          int_type     c = 0;

          while( --n > 0 && !traits::eq_int_type( (c = this->rdbuf()->sgetc()),traits::eof()) ) 
          {
            ++__chcount;
            this->rdbuf()->sbumpc();
            if(c == delim)
              break;
            *s++ = c;          
          }
          *s = 0; 
          if( traits::eq_int_type(c,traits::eof()) )  {
             err = (s == op) ? (ios_base::eofbit | ios_base::failbit)
                      : ios_base::eofbit;
          }
          else if ( this->rdbuf()->sgetc() == delim )
             this->rdbuf()->sbumpc();          // eat the delimiter
          else if ( n == 0 )
             err |= ios_base::failbit;   // too much data
        }
  
        *s = 0; //terminate with null
      }
      else
        err = ios_base::badbit;

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif //  _RWSTD_NO_EXCEPTIONS
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& ignore(streamsize, int_type)
   * this ignores n characters or until delim
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::ignore(streamsize n, int_type delim)
  {
    _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);
    __chcount = 0;

    if(ipfx)
    {  
      int_type      c = 0;

      while(--n >= 0 && !traits::eq_int_type( (c = this->rdbuf()->sgetc()),traits::eof()) )
      {
        ++__chcount;
        this->rdbuf()->sbumpc();
        if(c == delim)   
          break;
      }
      if( traits::eq_int_type(c,traits::eof()) )
        this->setstate(ios_base::eofbit);
    }
    return *this;
  }

  /*
   * istream_type& read(char_type *, streamsize)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::read(char_type *s, streamsize n)
  {
    ios_base::iostate err = 0; 

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 
      __chcount = 0;

      if (s!=0)
      { 
        _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);

        if(ipfx)
        {  
          int_type       c = 0;

          while((--n >= 0) && !traits::eq_int_type( (c = this->rdbuf()->sgetc()),traits::eof()))
          {
            *s++ = c; 
            ++__chcount;
            this->rdbuf()->sbumpc();  
          }

          if( traits::eq_int_type(c,traits::eof()) )  
            err = (n >= 0) ? (ios_base::eofbit | ios_base::failbit) : ios_base::eofbit;
        }
      }
      else
        err = ios_base::badbit;  

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif //  _RWSTD_NO_EXCEPTIONS
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * streamsize readsome(char_type *, streamsize)
   */

  template<class charT, class traits>
  streamsize 
  basic_istream<charT, traits>::readsome(char_type *s, streamsize n)
  {
    int navail = this->rdbuf()->in_avail();

   
    if(navail == -1)
    {   
      this->setstate(ios_base::eofbit);
      return 0;
    }
    if(navail == 0 ) return 0;

    if ( this->good() )
    {
      if(n < navail) 
      { 
        read(s, n);
        return (n);
      }

      read(s, navail);
      return (streamsize)(navail);
    }
    else
    { 
      if ( !(this->rdstate() & ios_base::failbit) )
        this->setstate(ios_base::failbit);
    }
  
    return 0;
  }

  /*
   * int_type peek()
   */

  template<class charT, class traits>
  _TYPENAME basic_istream<charT, traits>::int_type
  basic_istream<charT, traits>::peek()
  {
    __chcount = 0;

    if(this->good())
    {
#ifdef _RWSTD_MULTI_THREAD
      if ( this->rdbuf() )
        _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif
      _TYPENAME traits::int_type tmp = this->rdbuf()->sgetc();
      if ( !traits::eq_int_type( tmp,traits::eof() ) )
        __chcount = 1;
      return tmp;
    }

    return traits::eof();
  }

  /*
   * pos_type tellg()
   */

  template<class charT, class traits>
  _TYPENAME basic_istream<charT, traits>::pos_type
  basic_istream<charT, traits>::tellg()
  {
    ios_base::iostate err = 0; 
    pos_type         p;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 

#ifdef _RWSTD_MULTI_THREAD
      if ( this->rdbuf() ) {
        _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif //  _RWSTD_MULTI_THREAD
      if ( this->fail() ) return pos_type(off_type(-1));   

      p = this->rdbuf()->pubseekoff(0, ios_base::cur, ios_base::in);

#ifdef _RWSTD_MULTI_THREAD
      }
#endif //  _RWSTD_MULTI_THREAD

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif

    return p;
  }
  /*
   * istream_type& putback(char_type)
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::putback(char_type c)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 
  
#ifdef _RWSTD_MULTI_THREAD
      if ( this->rdbuf() )
        _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif 
      if (this->good())
      {
        if( traits::eq_int_type(this->rdbuf()->sputbackc(c),traits::eof()) ) 
          err = ios_base::badbit;      
      }
      else
      { 
        if ( !(this->rdstate() & ios_base::failbit) )
          this->setstate(ios_base::failbit);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * istream_type& unget()
   */

  template<class charT, class traits>
  basic_istream<charT, traits>&
  basic_istream<charT, traits>::unget()
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 

#ifdef _RWSTD_MULTI_THREAD
      if ( this->rdbuf() )
        _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif
      if (this->good())
      {
        if( traits::eq_int_type(this->rdbuf()->sungetc(),traits::eof()) )
          err = ios_base::badbit;  
      }
      else
      { 
        if ( !(this->rdstate() & ios_base::failbit) )
          this->setstate(ios_base::failbit);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif //  _RWSTD_NO_EXCEPTIONS
    if ( err ) this->setstate(err);
    return *this;
  }

  /*
   * streamsize gcount() const
   */

  template<class charT, class traits>
  streamsize basic_istream<charT, traits>::gcount() const
  {
    return __chcount;
  }

  /*
   * int sync()
   */

  template<class charT, class traits>
  int basic_istream<charT, traits>::sync()
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif 
  
#ifdef _RWSTD_MULTI_THREAD
      if ( this->rdbuf() )
        _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif
      if(this->rdbuf()) 
      {  
        if(this->rdbuf()->pubsync() == -1)
          err = ios_base::badbit;  
        else
        {
          if ( this->rdstate() & ios_base::eofbit )
            clear( this->rdstate() & ~(ios_base::eofbit | ios_base::failbit));
          return 0;
        } 
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        this->setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) this->setstate(err);
    return -1;
  }

  // string extractor and getline

#ifndef _RWSTD_NO_NAMESPACE
}
namespace __rwstd {
#endif

  template <class streamT, class stringT, class traits>
  streamT& _RWSTDExportTemplate rw_extract_string(streamT& is, stringT& s, traits)
  {
    _TYPENAME streamT::int_type c;
    _RW_STD::ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      _TYPENAME streamT::sentry ipfx(is);

      if(ipfx)
      { 
        s.erase();
        c = is.rdbuf()->sbumpc();

        const _RW_STD::ctype<_TYPENAME streamT::char_type>& ctype_facet =
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        _RW_STD::use_facet<_RW_STD::ctype<_TYPENAME streamT::char_type> >(is.getloc());
#else
        _RW_STD::use_facet(is.getloc(),(_RW_STD::ctype<_TYPENAME streamT::char_type>*)0);
#endif //  _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE

        _TYPENAME stringT::size_type i = 0, len = 32;
        _TYPENAME stringT::value_type* buff = new _TYPENAME stringT::value_type[len+1];
        _TYPENAME stringT::value_type* ptr = buff;

        _TYPENAME stringT::size_type end = s.max_size();
        if (is.width())
          end = (end >  (_TYPENAME stringT::size_type)is.width()) ? is.width() : end;

        while ( !traits::eq_int_type(c,traits::eof()) &&  !ctype_facet.is(ctype_facet.space,c) )
        {
          if (i == len)
          {
            _TYPENAME stringT::size_type oldlen = len;             
            len *= 2;
            _TYPENAME stringT::value_type* tmp = new _TYPENAME stringT::value_type[len+1];
            traits::move(tmp,buff,oldlen);
            delete [] buff;
            buff = tmp;
            ptr = buff + i;
          }

          *ptr++ = traits::to_char_type(c);            
          i++;
          if ( i == end ) break;
          c = is.rdbuf()->sbumpc();
        }
        *ptr = traits::to_char_type(0);
        s.assign(buff,i);
        delete [] buff;

        if ( i == 0 ) err |= _RW_STD::ios_base::failbit;
        if ( traits::eq_int_type(c,traits::eof()) ) 
          err |= _RW_STD::ios_base::eofbit;

      }

      is.width(0);
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        is.setstate(_RW_STD::ios_base::badbit);
      }
      catch( _RW_STD::ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif

    if ( err ) is.setstate(err);
    return is;
  }
#ifndef _RWSTD_NO_NAMESPACE
}
namespace std {
#endif

  template<class charT, class traits, class Allocator>
  basic_istream<charT,traits>&
  _RWSTDExportTemplate getline (basic_istream<charT,traits>& is,
                        basic_string<charT,traits,Allocator>& str,
                        charT delim )
  {
    _TYPENAME traits::int_type c;
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif  
      _TYPENAME basic_istream<charT,traits>::sentry ipfx(is,1);

      if(ipfx)
      {
        c = is.rdbuf()->sbumpc();
        _TYPENAME Allocator::size_type i = 0, len = 32;

        charT* buff = new charT[len+1];
        charT* ptr =  buff;

        while ( !traits::eq_int_type(c,traits::eof()) )
        {
          if (i == len)
          {
            _TYPENAME Allocator::size_type oldlen = len;
            len *= 2;
            charT* tmp = new charT[len+1];
            traits::move(tmp,buff,oldlen);
            delete [] buff;
            buff = tmp;
            ptr = buff + i;
          }
          i++; // RW_BUG: <Regressed> i++ must happen before the break line (bts-43483)
          if ( traits::eq(traits::to_char_type(c),delim) )
            break;
          if (i == str.max_size())
          {
            err |= ios_base::failbit;
            break;
          }
          *ptr++ = traits::to_char_type(c);
          c = is.rdbuf()->sbumpc();
        }
        *ptr = traits::to_char_type(0);
        str.assign(buff,i);
        delete [] buff;

        if ( traits::eq_int_type(c,traits::eof()) )
          err |= ios_base::eofbit;

        if ( i==0 )
          err |= ios_base::failbit;

      }
#ifndef _RWSTD_NO_EXCEPTIONS
    } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        is.setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif
    if ( err ) is.setstate(err);
    return is;
  }  
  /*
   * class basic_iostream
   */

  /*
   * basic_iostream(basic_streambuf *)
   */

  template<class charT, class traits>
  basic_iostream<charT, traits>::
  basic_iostream(basic_streambuf<charT, traits> *sb)
  :basic_istream<charT, traits>(sb)
  ,basic_ostream<charT, traits>(sb)
  {
  }

  /*
   * basic_iostream( )
   */

  template<class charT, class traits>
  basic_iostream<charT, traits>::
  basic_iostream( )
  :basic_istream<charT, traits>()
  ,basic_ostream<charT, traits>()
  {
  }
  /*
   * ~basic_iostream()
   */

  template<class charT, class traits>
  basic_iostream<charT, traits>::
  ~basic_iostream()
  {
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __ISTREAM_CC */
