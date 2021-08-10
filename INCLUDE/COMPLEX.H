#ifndef __COMPLEX_H
#define __COMPLEX_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_COMPLEX
#define __STD_COMPLEX

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
#include <rw/stddefs.h>
#include <rw/math.h>

#include <utility>

#ifndef _RW_STD_IOSTREAM
#include <iostream.h>
#else
#include <iostream>
#endif

#ifndef _RWSTD_NO_NAMESPACE 
namespace std {
#endif

#ifdef _RWSTD_NO_FORWARD_SPECIALIZATIONS
  template <class T>
  class _RWSTDExportTemplate complex
  {
  public:
    typedef T value_type;

    complex (const T& re_arg=0, const T& imag_arg=0) 
      : __re(re_arg), __im(imag_arg)
    { ; } 

    T imag () const { return __im; }
    T real () const { return __re; }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES

    template <class X> complex<T>& operator=  (const complex<X>& rhs) {__re=rhs.real(); __im=rhs.imag(); return *this;}
    template <class X> complex<T>& operator+= (const complex<X>& rhs) {__re+=rhs.real(); __im+=rhs.imag(); return *this;}
    template <class X> complex<T>& operator-= (const complex<X>& rhs) {__re-=rhs.real(); __im-=rhs.imag(); return *this;}
    template <class X> complex<T>& operator*= (const complex<X>& rhs) {T tmp=__re*rhs.real()-__im*rhs.imag(); __im=__im*rhs.real()+__re*rhs.imag(); __re=tmp; return *this;}
    template <class X> complex<T>& operator/= (const complex<X>&); 
#endif
    
    complex<T>& operator=  (const T&); 
    complex<T>& operator+= (const T&); 
    complex<T>& operator-= (const T&); 
    complex<T>& operator*= (const T&); 
    complex<T>& operator/= (const T&); 

  private:
    T __re, __im;
  };
#else

//
// The complex template definition must be placed after specializations to 
// satisfy several compilers' rather bizarre preference.
//
  template <class T>
  class _RWSTDExportTemplate complex;
#endif

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS 
  _RWSTD_TEMPLATE class _RWSTDExport complex<float>;
  _RWSTD_TEMPLATE class _RWSTDExport complex<double>;
#ifndef _RWSTD_NO_LONGDOUBLE
  _RWSTD_TEMPLATE class _RWSTDExport complex<long double>;
#endif
#endif

  _RWSTD_TEMPLATE
  class _RWSTDExport complex<float>
  {
  public:
    typedef float value_type;

    complex (const float& re_arg=0.0f, const float& imag_arg=0.0f) 
      : __re(re_arg), __im(imag_arg)
    { ; }
#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
    _EXPLICIT complex (const complex<double>&); 
#ifndef _RWSTD_NO_LONGDOUBLE
    _EXPLICIT complex (const complex<long double>&);
#endif
#endif // _RWSTD_NO_FORWARD_SPECIALIZATIONS

    float imag () const { return __im; }
    float real () const { return __re; }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex<float>& operator=  (const complex<X>& rhs) {__re=rhs.real(); __im=rhs.imag(); return *this;}
    template <class X> complex<float>& operator+= (const complex<X>& rhs) {__re+=rhs.real(); __im+=rhs.imag(); return *this;}
    template <class X> complex<float>& operator-= (const complex<X>& rhs) {__re-=rhs.real(); __im-=rhs.imag(); return *this;}
    template <class X> complex<float>& operator*= (const complex<X>& rhs) {float tmp=__re*rhs.real()-__im*rhs.imag(); __im=__im*rhs.real()+__re*rhs.imag(); __re=tmp; return *this;}
    template <class X> complex<float>& operator/= (const complex<X>&); 
#else /* Have to specialize each one :-( */

    complex<float>& operator=  (const complex<float>&); 
    complex<float>& operator+= (const complex<float>&); 
    complex<float>& operator-= (const complex<float>&); 
    complex<float>& operator*= (const complex<float>&); 
    complex<float>& operator/= (const complex<float>&); 

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
    complex<float>& operator=  (const complex<double>&); 
    complex<float>& operator+= (const complex<double>&); 
    complex<float>& operator-= (const complex<double>&); 
    complex<float>& operator*= (const complex<double>&); 
    complex<float>& operator/= (const complex<double>&); 

#ifndef _RWSTD_NO_LONGDOUBLE
    complex<float>& operator=  (const complex<long double>&); 
    complex<float>& operator+= (const complex<long double>&); 
    complex<float>& operator-= (const complex<long double>&); 
    complex<float>& operator*= (const complex<long double>&); 
    complex<float>& operator/= (const complex<long double>&);
#endif
#endif  
#endif

    complex<float>& operator=  (float); 
    complex<float>& operator+= (float); 
    complex<float>& operator-= (float); 
    complex<float>& operator*= (float); 
    complex<float>& operator/= (float); 

  private:
    float __re, __im;
  };

  _RWSTD_TEMPLATE
  class  _RWSTDExport complex<double>
  {
  public:
    typedef double value_type;

    complex (const double& re_arg=0.0, const double& imag_arg=0.0) 
      : __re(re_arg), __im(imag_arg)
    { ; } 
    complex (const complex<float>&); 
#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
#ifndef _RWSTD_NO_LONGDOUBLE  
    _EXPLICIT complex (const complex<long double>&); 
#endif
#endif // _RWSTD_NO_FORWARD_SPECIALIZATIONS

    double imag () const { return __im; }
    double real () const { return __re; }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex<double>& operator=  (const complex<X>& rhs) {__re=rhs.real(); __im=rhs.imag(); return *this;}
    template <class X> complex<double>& operator+= (const complex<X>& rhs) {__re+=rhs.real(); __im+=rhs.imag(); return *this;}
    template <class X> complex<double>& operator-= (const complex<X>& rhs) {__re-=rhs.real(); __im-=rhs.imag(); return *this;}
    template <class X> complex<double>& operator*= (const complex<X>& rhs) {double tmp=__re*rhs.real()-__im*rhs.imag(); __im=__im*rhs.real()+__re*rhs.imag(); __re=tmp; return *this;}
    template <class X> complex<double>& operator/= (const complex<X>&);

#else /* Have to specialize each one :-( */

    complex<double>& operator=  (const complex<float>&); 
    complex<double>& operator+= (const complex<float>&); 
    complex<double>& operator-= (const complex<float>&);
    complex<double>& operator*= (const complex<float>& rhs); 
    complex<double>& operator/= (const complex<float>&); 

    complex<double>& operator=  (const complex<double>& rhs); 
    complex<double>& operator+= (const complex<double>& rhs); 
    complex<double>& operator-= (const complex<double>& rhs); 
    complex<double>& operator*= (const complex<double>& rhs); 
    complex<double>& operator/= (const complex<double>&); 

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
#ifndef _RWSTD_NO_LONGDOUBLE  
    complex<double>& operator=  (const complex<long double>&); 
    complex<double>& operator+= (const complex<long double>&); 
    complex<double>& operator-= (const complex<long double>&); 
    complex<double>& operator*= (const complex<long double>&); 
    complex<double>& operator/= (const complex<long double>&);
#endif
#endif 
#endif

    complex<double>& operator=  (double); 
    complex<double>& operator+= (double); 
    complex<double>& operator-= (double); 
    complex<double>& operator*= (double); 
    complex<double>& operator/= (double); 
  private:
    double __re, __im;
  };

#ifndef _RWSTD_NO_LONGDOUBLE  

  _RWSTD_TEMPLATE
  class _RWSTDExport complex<long double>
  {
  public:
    typedef long double value_type;

    complex (const long double& re_arg=0.0L, const long double& imag_arg=0.0L)
      : __re(re_arg), __im(imag_arg)
    { ; } 
    complex (const complex<float>&);
    complex (const complex<double>&);

    long double imag () const { return __im; }
    long double real () const { return __re; }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex<long double>& operator=  (const complex<X>& rhs) {__re=rhs.real(); __im=rhs.imag(); return *this;}
    template <class X> complex<long double>& operator+= (const complex<X>& rhs) {__re+=rhs.real(); __im+=rhs.imag(); return *this;}
    template <class X> complex<long double>& operator-= (const complex<X>& rhs) {__re-=rhs.real(); __im-=rhs.imag(); return *this;}
    template <class X> complex<long double>& operator*= (const complex<X>& rhs) {long double tmp=__re*rhs.real()-__im*rhs.imag(); __im=__im*rhs.real()+__re*rhs.imag(); __re=tmp; return *this;}
    template <class X> complex<long double>& operator/= (const complex<X>&); 

#else /* Have to specialize each one :-( */

    complex<long double>& operator=  (const complex<float>&); 
    complex<long double>& operator+= (const complex<float>&); 
    complex<long double>& operator-= (const complex<float>&); 
    complex<long double>& operator*= (const complex<float>&); 
    complex<long double>& operator/= (const complex<float>&); 

    complex<long double>& operator=  (const complex<double>&); 
    complex<long double>& operator+= (const complex<double>&); 
    complex<long double>& operator-= (const complex<double>&); 
    complex<long double>& operator*= (const complex<double>&); 
    complex<long double>& operator/= (const complex<double>&); 

    complex<long double>& operator=  (const complex<long double>&); 
    complex<long double>& operator+= (const complex<long double>&); 
    complex<long double>& operator-= (const complex<long double>&); 
    complex<long double>& operator*= (const complex<long double>&); 
    complex<long double>& operator/= (const complex<long double>&); 
#endif

    complex<long double>& operator=  (long double); 
    complex<long double>& operator+= (long double); 
    complex<long double>& operator-= (long double); 
    complex<long double>& operator*= (long double); 
    complex<long double>& operator/= (long double); 
  private:
    long double __re, __im;
  };
#endif

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
  template <class T>
  class _RWSTDExportTemplate complex
  {
  public:
    typedef T value_type;

    complex (const T& re_arg=0, const T& imag_arg=0) 
      : __re(re_arg), __im(imag_arg)
    { ; } 

    T imag () const { return __im; }
    T real () const { return __re; }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class X> complex (const complex<X>& rhs) {__re=rhs.real(); __im=rhs.imag();}

    template <class X> complex<T>& operator=  (const complex<X>& rhs) {__re=rhs.real(); __im=rhs.imag(); return *this;}
    template <class X> complex<T>& operator+= (const complex<X>& rhs) {__re+=rhs.real(); __im+=rhs.imag(); return *this;}
    template <class X> complex<T>& operator-= (const complex<X>& rhs) {__re-=rhs.real(); __im-=rhs.imag(); return *this;}
    template <class X> complex<T>& operator*= (const complex<X>& rhs) {T tmp=__re*rhs.real()-__im*rhs.imag(); __im=__im*rhs.real()+__re*rhs.imag(); __re=tmp; return *this;}
    template <class X> complex<T>& operator/= (const complex<X>&); 
#endif
    
    complex<T>& operator=  (const T&); 
    complex<T>& operator+= (const T&); 
    complex<T>& operator-= (const T&); 
    complex<T>& operator*= (const T&); 
    complex<T>& operator/= (const T&); 

  private:
    T __re, __im;
  };
#endif

//
// Temporarily turn off the warnings under the Borland compiler that
// say 'Functions containing ... cannot be inlined'
//
#if defined(__BORLANDC__)
#pragma option -w-inl
#endif

  template <class T>
  inline complex<T>&
  complex<T>::operator= (const T& rhs) 
  {
    __re = rhs; __im = 0.0; return *this;
  }

  template <class T>
  inline complex<T>&
  complex<T>::operator+= (const T& rhs) 
  {
    __re += rhs; return *this;
  }

  template <class T>
  inline complex<T>&
  complex<T>::operator-= (const T& rhs) 
  {
    __re -= rhs;  return *this;
  }

  template <class T>
  inline complex<T>&
  complex<T>::operator*= (const T& rhs) 
  {     
    T tmp = __re*rhs; 
    __im       = __im*rhs; 
    __re       = tmp;
    return *this;
  }

  template <class T>
  inline complex<T>& 
  complex<T>::operator/= (const T& rhs)  
  {
    T denom = rhs*rhs;
    T re    = (__re*rhs)/denom;
    T im    = (rhs*__im)/denom;
    __re               = re;
    __im               = im;
    return *this;
  }
//
// complex<float> specializations.
//

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS 
  inline
  complex<float>::complex (const complex<double>& cd)
  {
    __re = _RWSTD_STATIC_CAST(float,cd.real()); 
    __im = _RWSTD_STATIC_CAST(float,cd.imag());
  }

#ifndef _RWSTD_NO_LONGDOUBLE
  inline
  complex<float>::complex (const complex<long double>& cld)
  {
    __re = _RWSTD_STATIC_CAST(float,cld.real()); 
    __im = _RWSTD_STATIC_CAST(float,cld.imag());
  }
#endif
#endif

  inline complex<float>&
  complex<float>::operator= (float rhs) 
  {
    __re = rhs; __im = 0.0; return *this;
  }

  inline complex<float>&
  complex<float>::operator+= (float rhs) 
  {
    __re += rhs; return *this;
  }

  inline complex<float>&
  complex<float>::operator-= (float rhs) 
  {
    __re -= rhs;  return *this;
  }

  inline complex<float>&
  complex<float>::operator*= (float rhs) 
  {     
    float tmp = __re*rhs; 
    __im       = __im*rhs; 
    __re       = tmp;
    return *this;
  }
#ifdef _RWSTD_NO_MEMBER_TEMPLATES 
  inline complex<float>&
  complex<float>::operator= (const complex<float>& rhs) 
  {
    __re = rhs.real(); __im = rhs.imag(); return *this;
  }

  inline complex<float>&
  complex<float>::operator+= (const complex<float>& rhs) 
  {
    __re += rhs.real(); __im += rhs.imag(); return *this;
  }

  inline complex<float>&
  complex<float>::operator-= (const complex<float>& rhs) 
  {
    __re -= rhs.real(); __im -= rhs.imag(); return *this;
  }

  inline complex<float>&
  complex<float>::operator*= (const complex<float>& rhs) 
  {     
    float tmp = __re*rhs.real()-__im*rhs.imag(); 
    __im       = __im*rhs.real()+__re*rhs.imag(); 
    __re       = tmp;
    return *this;
  }

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS 
  inline complex<float>&
  complex<float>::operator= (const complex<double>& rhs) 
  {
    __re = _RWSTD_STATIC_CAST(float,rhs.real()); 
    __im = _RWSTD_STATIC_CAST(float,rhs.imag()); 
    return *this;
  }

  inline complex<float>&
  complex<float>::operator+= (const complex<double>& rhs) 
  {
    __re += _RWSTD_STATIC_CAST(float,rhs.real()); 
    __im += _RWSTD_STATIC_CAST(float,rhs.imag()); 
    return *this;
  }

  inline complex<float>&
  complex<float>::operator-= (const complex<double>& rhs) 
  {     
    __re -= _RWSTD_STATIC_CAST(float,rhs.real()); 
    __im -= _RWSTD_STATIC_CAST(float,rhs.imag()); 
    return *this;
  }

  inline complex<float>&
  complex<float>::operator*= (const complex<double>& rhs) 
  {     
    float tmp = __re*_RWSTD_STATIC_CAST(float,rhs.real())-
    __im*_RWSTD_STATIC_CAST(float,rhs.imag()); 
    __im       = __im*_RWSTD_STATIC_CAST(float,rhs.real())+
    __re*_RWSTD_STATIC_CAST(float,rhs.imag()); 
    __re       = tmp;
    return *this;
  }

#ifndef _RWSTD_NO_LONGDOUBLE
  inline complex<float>&
  complex<float>::operator= (const complex<long double>& rhs) 
  {     
    __re = _RWSTD_STATIC_CAST(float,rhs.real()); 
    __im = _RWSTD_STATIC_CAST(float,rhs.imag()); 
    return *this;
  }

  inline complex<float>&
  complex<float>::operator+= (const complex<long double>& rhs) 
  {     
    __re += _RWSTD_STATIC_CAST(float,rhs.real()); 
    __im += _RWSTD_STATIC_CAST(float,rhs.imag()); 
    return *this;
  }

  inline complex<float>&
  complex<float>::operator-= (const complex<long double>& rhs) 
  {
    __re -= _RWSTD_STATIC_CAST(float,rhs.real()); 
    __im -= _RWSTD_STATIC_CAST(float,rhs.imag()); 
    return *this;
  }

  inline complex<float>&
  complex<float>::operator*= (const complex<long double>& rhs) 
  {     
    float tmp = __re*_RWSTD_STATIC_CAST(float,rhs.real())-
    __im*_RWSTD_STATIC_CAST(float,rhs.imag()); 
    __im      = __im*_RWSTD_STATIC_CAST(float,rhs.real())+
    __re*_RWSTD_STATIC_CAST(float,rhs.imag()); 
    __re      = tmp; 
    return *this;
  }
#endif
#endif
#endif /* _RWSTD_NO_MEMBER_TEMPLATES */
//
// complex<double> specializations.
//
  inline
  complex<double>::complex (const complex<float>& cf)
  : __re(cf.real()), __im(cf.imag()) {}

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS 
#ifndef _RWSTD_NO_LONGDOUBLE
  inline 
  complex<double>::complex (const complex<long double>& cld)
  : __re(_RWSTD_STATIC_CAST(double,cld.real())), 
  __im(_RWSTD_STATIC_CAST(double,cld.imag())) {}
#endif
#endif

  inline complex<double>&
  complex<double>::operator= (double rhs) 
  {
    __re = rhs; __im = 0.0; return *this;
  }

  inline complex<double>&
  complex<double>::operator+= (double rhs) 
  {
    __re += rhs; return *this;
  }

  inline complex<double>&
  complex<double>::operator-= (double rhs) 
  {
    __re -= rhs;  return *this;
  }

  inline complex<double>&
  complex<double>::operator*= (double rhs) 
  {     
    double tmp = __re*rhs; 
    __im       = __im*rhs; 
    __re       = tmp;
    return *this;
  }
#ifdef _RWSTD_NO_MEMBER_TEMPLATES 
  inline complex<double>&
  complex<double>::operator= (const complex<float>& rhs) 
  {
    __re = rhs.real(); __im = rhs.imag(); return *this;
  }

  inline complex<double>&
  complex<double>::operator+= (const complex<float>& rhs) 
  {
    __re += rhs.real(); __im += rhs.imag(); return *this;
  }

  inline complex<double>&
  complex<double>::operator-= (const complex<float>& rhs) 
  {
    __re -= rhs.real(); __im -= rhs.imag(); return *this;
  }

  inline complex<double>&
  complex<double>::operator*= (const complex<float>& rhs) 
  {     
    double tmp = __re*rhs.real()-__im*rhs.imag(); 
    __im        = __im*rhs.real()+__re*rhs.imag(); 
    __re        = tmp;
    return *this;
  }

  inline complex<double>&
  complex<double>::operator= (const complex<double>& rhs) 
  {
    __re = rhs.real(); __im = rhs.imag(); return *this;
  }

  inline complex<double>&
  complex<double>::operator+= (const complex<double>& rhs) 
  {
    __re += rhs.real(); __im += rhs.imag(); return *this;
  }

  inline complex<double>&
  complex<double>::operator-= (const complex<double>& rhs) 
  {     
    __re -= rhs.real(); __im -= rhs.imag(); return *this;
  }

  inline complex<double>& 
  complex<double>::operator*= (const complex<double>& rhs) 
  {     
    double tmp = __re*rhs.real()-__im*rhs.imag(); 
    __im       = __im*rhs.real()+__re*rhs.imag(); 
    __re       = tmp;
    return *this;
  }
#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS 
#ifndef _RWSTD_NO_LONGDOUBLE
  inline complex<double>&
  complex<double>::operator= (const complex<long double>& rhs) 
  {     
    __re = _RWSTD_STATIC_CAST(double,rhs.real()); 
    __im = _RWSTD_STATIC_CAST(double,rhs.imag()); 
    return *this;
  }

  inline complex<double>&
  complex<double>::operator+= (const complex<long double>& rhs) 
  {     
    __re += _RWSTD_STATIC_CAST(double,rhs.real()); 
    __im += _RWSTD_STATIC_CAST(double,rhs.imag()); 
    return *this;
  }

  inline complex<double>& 
  complex<double>::operator-= (const complex<long double>& rhs) 
  {
    __re -= _RWSTD_STATIC_CAST(double,rhs.real()); 
    __im -= _RWSTD_STATIC_CAST(double,rhs.imag()); 
    return *this;
  }

  inline complex<double>& 
  complex<double>::operator*= (const complex<long double>& rhs) 
  {     
    double tmp = __re*_RWSTD_STATIC_CAST(double,rhs.real())-
    __im*_RWSTD_STATIC_CAST(double,rhs.imag()); 
    __im       = __im*_RWSTD_STATIC_CAST(double,rhs.real())+
    __re*_RWSTD_STATIC_CAST(double,rhs.imag()); 
    __re       = tmp; 
    return *this;
  }
#endif
#endif
#endif /* _RWSTD_NO_MEMBER_TEMPLATES */

//
// complex<long double> specializations.
//

#ifndef _RWSTD_NO_LONGDOUBLE
  inline 
  complex<long double>::complex (const complex<float>& cf)
  : __re(cf.real()), __im(cf.imag()) {}

  inline 
  complex<long double>::complex (const complex<double>& cd)
  : __re(cd.real()), __im(cd.imag()) {}

  inline complex<long double>&
  complex<long double>::operator+= (long double rhs) 
  {
    __re += rhs; return *this;
  }

  inline complex<long double>&
  complex<long double>::operator= (long double rhs) 
  {
    __re = rhs; __im = 0.0; return *this;
  }

  inline complex<long double>&
  complex<long double>::operator-= (long double rhs) 
  {
    __re -= rhs;  return *this;
  }

  inline complex<long double>&
  complex<long double>::operator*= (long double rhs) 
  {     
    long double tmp = __re*rhs; 
    __im       = __im*rhs; 
    __re       = tmp;
    return *this;
  }
#ifdef _RWSTD_NO_MEMBER_TEMPLATES
  inline complex<long double>& 
  complex<long double>::operator= (const complex<float>& rhs) 
  {
    __re = rhs.real(); __im = rhs.imag(); return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator+= (const complex<float>& rhs) 
  {
    __re += rhs.real(); __im += rhs.imag(); return *this;
  }

  inline complex<long double>&
  complex<long double>::operator-= (const complex<float>& rhs) 
  {
    __re -= rhs.real(); __im -= rhs.imag(); return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator*= (const complex<float>& rhs) 
  {     
    long double tmp = __re*rhs.real()-__im*rhs.imag(); 
    __im             = __im*rhs.real()+__re*rhs.imag(); 
    __re             = tmp;
    return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator= (const complex<double>& rhs) 
  {
    __re = rhs.real(); __im = rhs.imag(); return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator+= (const complex<double>& rhs) 
  {
    __re += rhs.real(); __im += rhs.imag(); return *this;
  }

  inline complex<long double>&
  complex<long double>::operator-= (const complex<double>& rhs) 
  {     
    __re -= rhs.real(); __im -= rhs.imag(); return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator*= (const complex<double>& rhs) 
  {     
    long double tmp = __re*rhs.real()-__im*rhs.imag(); 
    __im             = __im*rhs.real()+__re*rhs.imag(); 
    __re             = tmp;
    return *this;
  }

  inline complex<long double>&
  complex<long double>::operator= (const complex<long double>& rhs) 
  {     
    __re = rhs.real(); __im = rhs.imag(); return *this;
  }

  inline complex<long double>&
  complex<long double>::operator+= (const complex<long double>& rhs) 
  {     
    __re += rhs.real(); __im += rhs.imag(); return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator-= (const complex<long double>& rhs) 
  {
    __re -= rhs.real(); __im -= rhs.imag(); return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator*= (const complex<long double>& rhs) 
  {     
    long double tmp = __re*rhs.real()-__im*rhs.imag(); 
    __im            = __im*rhs.real()+__re*rhs.imag(); 
    __re            = tmp; 
    return *this;
  }
#endif
#endif /* _RWSTD_NO_MEMBER_TEMPLATES */

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template <class T>
  template <class X>
  complex<T>&
  complex<T>::operator/= (const complex<X>& rhs)
  {
    T denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    T re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    T im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re    = re;
    __im    = im;
    return *this;
  }

  template <class X>
  inline complex<float>& 
  complex<float>::operator/= (const complex<X>& rhs)  
  {
    float denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    float re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    float im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re        = re;
    __im        = im;
    return *this;
  }

  template <class X>
  inline complex<double>& 
  complex<double>::operator/= (const complex<X>& rhs)  
  {
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re        = re;
    __im        = im;
    return *this;
  }

#ifndef _RWSTD_NO_LONGDOUBLE
  template <class X>
  inline complex<long double>& 
  complex<long double>::operator/= (const complex<X>& rhs)  
  {
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    long double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re        = re;
    __im        = im;
    return *this;
  }
#endif
#else /* No member function templates, have to specialize :-( */

  inline complex<float>& 
  complex<float>::operator/= (const complex<float>& rhs)  
  {
    float denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    float re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    float im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re         = re;
    __im         = im;
    return *this;
  }

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
  inline complex<float>& 
  complex<float>::operator/= (const complex<double>& rhs)  
  {
    float denom = _RWSTD_STATIC_CAST(float,rhs.real())*
    _RWSTD_STATIC_CAST(float,rhs.real()) + 
    _RWSTD_STATIC_CAST(float,rhs.imag())*
    _RWSTD_STATIC_CAST(float,rhs.imag());
    float re    = (__re*_RWSTD_STATIC_CAST(float,rhs.real())+
                   __im*_RWSTD_STATIC_CAST(float,rhs.imag()))/denom;
    float im    = (_RWSTD_STATIC_CAST(float,rhs.real())*__im-__re*
                   _RWSTD_STATIC_CAST(float,rhs.imag()))/denom;
    __re        = re;
    __im        = im;
    return *this;
  }

#ifndef _RWSTD_NO_LONGDOUBLE
  inline complex<float>& 
  complex<float>::operator/= (const complex<long double>& rhs)  
  {
    float denom = _RWSTD_STATIC_CAST(float,rhs.real())*
    _RWSTD_STATIC_CAST(float,rhs.real()) + 
    _RWSTD_STATIC_CAST(float,rhs.imag())*
    _RWSTD_STATIC_CAST(float,rhs.imag());
    float re    = (__re*_RWSTD_STATIC_CAST(float,rhs.real())+
                   __im*_RWSTD_STATIC_CAST(float,rhs.imag()))/denom;
    float im    = (_RWSTD_STATIC_CAST(float,rhs.real())*__im-
                   __re*_RWSTD_STATIC_CAST(float,rhs.imag()))/denom;
    __re        = re;
    __im        = im;
    return *this;
  }
#endif 
#endif

  inline complex<double>& 
  complex<double>::operator/= (const complex<float>& rhs)  
  {
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re         = re;
    __im         = im;
    return *this;
  }

  inline complex<double>&
  complex<double>::operator/= (const complex<double>& rhs)
  {
    double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re         = re;
    __im         = im;
    return *this;
  }

#ifndef _RWSTD_NO_FORWARD_SPECIALIZATIONS
#ifndef _RWSTD_NO_LONGDOUBLE
  inline complex<double>& 
  complex<double>::operator/= (const complex<long double>& rhs)  
  {
    double denom = _RWSTD_STATIC_CAST(double,rhs.real())*
    _RWSTD_STATIC_CAST(double,rhs.real()) + 
    _RWSTD_STATIC_CAST(double,rhs.imag())*
    _RWSTD_STATIC_CAST(double,rhs.imag());
    double re    = (__re*_RWSTD_STATIC_CAST(double,rhs.real())+
                    __im*_RWSTD_STATIC_CAST(double,rhs.imag()))/denom;
    double im    = (_RWSTD_STATIC_CAST(double,rhs.real())*__im-
                    __re*_RWSTD_STATIC_CAST(double,rhs.imag()))/denom;
    __re         = re;
    __im         = im;
    return *this;
  }
#endif
#endif

#ifndef _RWSTD_NO_LONGDOUBLE
  inline complex<long double>& 
  complex<long double>::operator/= (const complex<float>& rhs)  
  {
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    long double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re              = re;
    __im              = im;
    return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator/= (const complex<double>& rhs)  
  {
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    long double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re              = re;
    __im              = im;
    return *this;
  }

  inline complex<long double>& 
  complex<long double>::operator/= (const complex<long double>& rhs)  
  {
    long double denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    long double re    = (__re*rhs.real()+__im*rhs.imag())/denom;
    long double im    = (rhs.real()*__im-__re*rhs.imag())/denom;
    __re              = re;
    __im              = im;
    return *this;
  }
#endif
#endif

  inline complex<float>& 
  complex<float>::operator/= (float rhs)  
  {
    float denom = rhs*rhs;
    float re    = (__re*rhs)/denom;
    float im    = (rhs*__im)/denom;
    __re        = re;
    __im        = im;
    return *this;
  }

  inline complex<double>& 
  complex<double>::operator/= (double rhs)  
  {
    double denom = rhs*rhs;
    double re    = (__re*rhs)/denom;
    double im    = (rhs*__im)/denom;
    __re         = re;
    __im         = im;
    return *this;
  }
#ifndef _RWSTD_NO_LONGDOUBLE
  inline complex<long double>& 
  complex<long double>::operator/= (long double rhs)  
  {
    long double denom = rhs*rhs;
    long double re    = (__re*rhs)/denom;
    long double im    = (rhs*__im)/denom;
    __re              = re;
    __im              = im;
    return *this;
  }
#endif
//
// complex non-member operations
//

  template <class T>
  inline complex<T> operator+ (const complex<T>& lhs, const complex<T>& rhs)
  {
    complex<T> tmp = lhs; return tmp += rhs;
  }

  template <class T>
  inline complex<T> operator+ (const complex<T>& lhs, const T& rhs)
  {
    return complex<T>(rhs+lhs.real(), lhs.imag());
  }

  template <class T>
  inline complex<T> operator+ (const T& lhs, const complex<T>& rhs)
  {
    return complex<T>(lhs+rhs.real(), rhs.imag());
  }

  template <class T>
  inline complex<T> operator- (const complex<T>& lhs, const complex<T>& rhs)
  {
    complex<T> tmp = lhs; return tmp -= rhs;
  }

  template <class T>
  inline complex<T> operator- (const complex<T>& lhs, const T& rhs)
  {
    return complex<T>(lhs.real()-rhs, lhs.imag());
  }

  template <class T>
  inline complex<T> operator- (const T& lhs, const complex<T>& rhs)
  {
    return complex<T>(lhs-rhs.real(), -rhs.imag());
  }

  template <class T>
  inline complex<T> operator* (const complex<T>& lhs, const complex<T>& rhs)
  {
    complex<T> tmp = lhs; return tmp *= rhs;
  }

  template <class T>
  inline complex<T> operator* (const complex<T>& lhs, const T& rhs)
  {
    return complex<T>(rhs*lhs.real(), rhs*lhs.imag());
  }

  template <class T>
  inline complex<T> operator* (const T& lhs, const complex<T>& rhs)
  {
    return complex<T>(lhs*rhs.real(), lhs*rhs.imag());
  }

  template <class T>
  inline complex<T> operator/ (const complex<T>& lhs, const complex<T>& rhs)
  {
    complex<T> tmp = lhs; return tmp /= rhs;
  }

  template <class T>
  inline complex<T> operator/ (const complex<T>& lhs, const T& rhs)
  {
    return complex<T>(lhs.real()/rhs, lhs.imag()/rhs);
  }

  template <class T>
  inline complex<T> operator/ (const T& lhs, const complex<T>& rhs)
  {
    register T denom = rhs.real()*rhs.real() + rhs.imag()*rhs.imag();
    return complex<T>(lhs*rhs.real()/denom,(-lhs*rhs.imag())/denom);
  }

  template <class T>
  inline complex<T> operator+ (const complex<T>& lhs) { return lhs; }

  template <class T>
  inline complex<T> operator- (const complex<T>& lhs)
  {
    return complex<T>(-lhs.real(), -lhs.imag());
  } 

  template <class T>
  inline bool operator== (const complex<T>& lhs, const complex<T>& rhs)
  {
    return lhs.real() == rhs.real() && lhs.imag() == rhs.imag();
  } 

  template <class T>
  inline bool operator== (const T& lhs, const complex<T>& rhs)
  {
    return lhs == rhs.real() && rhs.imag() == 0;
  } 

  template <class T>
  inline bool operator== (const complex<T>& lhs, const T& rhs)
  {
    return lhs.real() == rhs && lhs.imag() == 0;
  } 

#ifndef _RWSTD_NO_NAMESPACE
  template <class T>
  inline bool operator!= (const complex<T>& lhs, const complex<T>& rhs)
  {
    return lhs.real() != rhs.real() || lhs.imag() != rhs.imag();
  } 
#endif

  template <class T>
  inline bool operator!= (const T& lhs, const complex<T>& rhs)
  {
    return lhs != rhs.real() || rhs.imag() != 0;
  } 

  template <class T>
  inline bool operator!= (const complex<T>& lhs, const T& rhs)
  {
    return lhs.real() != rhs || lhs.imag() != 0;
  } 

//
// complex value operations
//

// Cope with namespace problems
#if defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE) 
#define _RWSTD_C_SCOPE_SIN ::sin
#define _RWSTD_C_SCOPE_SINH ::sinh
#define _RWSTD_C_SCOPE_COS ::cos
#define _RWSTD_C_SCOPE_COSH ::cosh
#define _RWSTD_C_SCOPE_ATAN2 ::atan2
#define _RWSTD_C_SCOPE_ATAN ::atan
#define _RWSTD_C_SCOPE_EXP ::exp
#define _RWSTD_C_SCOPE_POW ::pow
#define _RWSTD_C_SCOPE_SQRT ::sqrt
#define _RWSTD_C_SCOPE_LOG ::log
#define _RWSTD_C_SCOPE_LOG10 ::log10
#else
#define _RWSTD_C_SCOPE_SIN sin
#define _RWSTD_C_SCOPE_SINH sinh
#define _RWSTD_C_SCOPE_COS cos
#define _RWSTD_C_SCOPE_COSH cosh
#define _RWSTD_C_SCOPE_ATAN2 atan2
#define _RWSTD_C_SCOPE_ATAN atan
#define _RWSTD_C_SCOPE_EXP exp
#define _RWSTD_C_SCOPE_POW pow
#define _RWSTD_C_SCOPE_SQRT sqrt
#define _RWSTD_C_SCOPE_LOG log
#define _RWSTD_C_SCOPE_LOG10 log10
#endif

  template<class T>
  inline T real (const complex<T>& a) { return a.real(); }

  template<class T>
  inline T imag (const complex<T>& a) { return a.imag(); }

  template <class T>
  inline T norm (const complex<T>& a)
  {
    return a.real()*a.real() + a.imag()*a.imag();
  }

  template <class T>
  inline T abs (const complex<T>& a) { return (_RWSTD_C_SCOPE_SQRT(norm(a))); }

//
// We guarantee that arg(complex<T>(0,0)) == 0.
//

  template <class T>
  inline T arg (const complex<T>& a)
  {
    return a == complex<T>(0,0) ? T(0) : _RWSTD_C_SCOPE_ATAN2(a.imag(), a.real());
  }

  template <class T>
  complex<T> conj (const complex<T>& a)
  {
    return complex<T>(a.real(), -a.imag());
  }

#if defined(_MSC_VER) &&  _MSC_VER < 901
//
// A very bizarre Microsoft problem.
//
  _RWSTD_TEMPLATE 
  inline complex<float> conj (const complex<float>& a)
  {
    return complex<float>(a.real(), -a.imag());
  }
  _RWSTD_TEMPLATE 
  inline complex<double> conj (const complex<double>& a)
  {
    return complex<double>(a.real(), -a.imag());
  }

#ifndef _RWSTD_NO_LONGDOUBLE
  _RWSTD_TEMPLATE 
  inline complex<long double> conj (const complex<long double>& a)
  {
    return complex<long double>(a.real(), -a.imag());
  }
#endif
#endif

  template <class T>
#ifndef _RWSTD_NO_INIT_CONST_TEMPLATE_REF_ARG
  inline complex<T> polar (const T& r, const T& theta = 0)
#else
  inline complex<T> polar (const T& r, const T& theta)
#endif
  {
    return complex<T>(r*_RWSTD_C_SCOPE_COS(theta), r*_RWSTD_C_SCOPE_SIN(theta));
  }

//
// transcendentals
//

//
// complex<T> cosine of complex<T> number a
//      cos (a) = cos u * cosh v - i * sin u * sinh v
//

  template <class T>
  inline complex<T> cos (const complex<T>& a)
  {
    return complex<T>(_RWSTD_C_SCOPE_COS(a.real())*_RWSTD_C_SCOPE_COSH(a.imag()),
                      -_RWSTD_C_SCOPE_SIN(a.real())*_RWSTD_C_SCOPE_SINH(a.imag()));
  }

//
// complex<T> hyperbolic cosine of complex<T> number a
//      cosh (a) = cosh u * cosv + i * sinh u * sin v
//

  template <class T>
  inline complex<T> cosh (const complex<T>& a)
  {
    return complex<T>(_RWSTD_C_SCOPE_COSH(a.real())*_RWSTD_C_SCOPE_COS(a.imag()),
                      _RWSTD_C_SCOPE_SINH(a.real())*_RWSTD_C_SCOPE_SIN(a.imag()));
  }

//
// complex<T> exponential of  complex<T> number a
//      exp (a) = exp(u) * (cos v + i * sin v)
//

  template <class T>
  inline complex<T> exp (const complex<T>& a)
  {
    register T e = _RWSTD_C_SCOPE_EXP(a.real());
    return complex<T>(e*_RWSTD_C_SCOPE_COS(a.imag()), e*_RWSTD_C_SCOPE_SIN(a.imag()));
  }

//
// complex<T> natural log of complex<T> number a
//      log(a) = log(r) + i * theta
//

  template <class T>
  inline complex<T> log (const complex<T>& a)
  {
    return complex<T>(_RWSTD_C_SCOPE_LOG(abs(a)), arg(a));
  }

  template <class T>
  complex<T> log10 (const complex<T>& a);

//
// For all the power functions:
//
//   0**0 == 1
//   0**x == 0 for x != 0
//

//
// complex<T> number a raised to an integer power n
//
// a**n = r**n * (cos(n theta) + i sin (n theta))
//

  template <class T>
  inline complex<T> pow (const complex<T>& a, int n)
  {
    if (a == complex<T>(0,0))
    {
      if (n == 0) 
        return complex<T>(1,0);
      else
        return complex<T>(0,0);
    }

    if (a.imag() == 0)
    {
      if (a.real() < 0)
        return pow(a, complex<T>(n,0));
      else
#ifndef _RWSTD_NO_OVERLOAD_C_POW
        return complex<T>(_RWSTD_C_SCOPE_POW(a.real(),T(n)), 0);
#else
      return complex<T>(_RWSTD_C_SCOPE_POW(double(a.real()),double(n)), 0);
#endif /* _RWSTD_NO_OVERLOAD_C_POW */
    }

#ifndef _RWSTD_NO_OVERLOAD_C_POW
    register T r  = _RWSTD_C_SCOPE_POW(T(abs(a)), T(n));
#else
    register T r  = _RWSTD_C_SCOPE_POW(double(abs(a)), double(n));
#endif

    register T th = T(n) * arg(a);

    return complex<T>(r*_RWSTD_C_SCOPE_COS(th), r*_RWSTD_C_SCOPE_SIN(th));
  }
//
// complex<T> number a raised to a real power s
//
// a**s = exp(s * log(a))
//

  template <class T>
  inline complex<T> pow (const complex<T>& a, const T& s)
  {
    if (a == complex<T>(0,0))
    {
      if (s == T(0))
        return complex<T>(1,0);
      else
        return complex<T>(0,0);
    }
    if (a.imag() == 0)
    {
      if (a.real() < 0)
        return pow(a, complex<T>(s,0));
      else
#ifndef _RWSTD_NO_OVERLOAD_C_POW
        return complex<T>(_RWSTD_C_SCOPE_POW(a.real(),s), 0);
#else
      return complex<T>(_RWSTD_C_SCOPE_POW(double(a.real()),double(s)), 0);
#endif /* _RWSTD_NO_OVERLOAD_C_POW */
    }
    return exp(s*log(a));
  }   
//
// real number s raised to a complex<T> power a
//
//  s**a = exp(a * log (s))
//

  template <class T>
  inline complex<T> pow (const T& s, const complex<T>& a)
  {
    if (s == T(0))
    {
      if (a == complex<T>(0,0)) 
        return complex<T>(1,0);
      else
        return complex<T>(0,0);
    }
    if (s < 0)
      return pow(complex<T>(s,0), a);

    if (a.imag() == 0)
#ifndef _RWSTD_NO_OVERLOAD_C_POW
      return complex<T>(_RWSTD_C_SCOPE_POW(s, a.real()), 0);
#else
    return complex<T>(_RWSTD_C_SCOPE_POW(double(s), double(a.real())), 0);
#endif /* _RWSTD_NO_OVERLOAD_C_POW */

    return complex<T>(exp(a * (T) _RWSTD_C_SCOPE_LOG(s)));
  }
//
// complex<T> number a1 raised to a complex<T> power a2
//
// a1**a2 = rho * (cos(phi) + i sin(phi))
//      rho = r1 **u2   *  exp (-v2* theta1)
//      phi = v2 * log(r1) + u2 * theta1
//

  template <class T>
  inline complex<T> pow (const complex<T>& a1, const complex<T>& a2)
  {
    if (a1 == complex<T>(0,0))
    {
      if (a2 == complex<T>(0,0))
        return complex<T>(1,0);
      else
        return complex<T>(0,0);
    }

    T r1   = abs(a1);
    T u2   = real(a2);
    T v2   = imag(a2);
    T th1  = arg(a1);
#ifndef _RWSTD_NO_OVERLOAD_C_POW
    T rho  = _RWSTD_C_SCOPE_POW(r1, u2) * _RWSTD_C_SCOPE_EXP(-v2 *th1);
#else
    T rho  = _RWSTD_C_SCOPE_POW(double(r1), double(u2)) * _RWSTD_C_SCOPE_EXP(-v2 *th1);
#endif /* _RWSTD_NO_OVERLOAD_C_POW */
    T phi  = v2 * _RWSTD_C_SCOPE_LOG(r1) + u2 * th1;

    return complex<T>(rho*_RWSTD_C_SCOPE_COS(phi), rho*_RWSTD_C_SCOPE_SIN(phi));
  }      
//
// complex<T> sine of complex<T> number a
//      sin (a) = sin u * cosh v + i * cos u * sinh v
//
  template <class T>
  inline complex<T> sin (const complex<T>& a)
  {
    return complex<T>(_RWSTD_C_SCOPE_SIN(a.real())*_RWSTD_C_SCOPE_COSH(a.imag()),
                      _RWSTD_C_SCOPE_COS(a.real())*_RWSTD_C_SCOPE_SINH(a.imag()));
  }

//
// complex<T> hyperbolic sine of complex<T> number a
//      sinh (a) = sinh u cos v + i cosh u sin v
//
  template <class T>
  inline complex<T> sinh (const complex<T>& a)
  {
    return complex<T>(_RWSTD_C_SCOPE_SINH(a.real())*_RWSTD_C_SCOPE_COS(a.imag()),
                      _RWSTD_C_SCOPE_COSH(a.real())*_RWSTD_C_SCOPE_SIN(a.imag()));
  }

//
// complex<T> square root of complex<T> number a
//      sqrt(a) = sqrt(r) * ( cos (theta/2) + i sin (theta/2) )
//
  template <class T>
  inline complex<T> sqrt (const complex<T>& a)
  {
    register T r  = _RWSTD_C_SCOPE_SQRT(abs(a));
    register T th = arg(a)/2.;
    return complex<T>(r*_RWSTD_C_SCOPE_COS(th), r*_RWSTD_C_SCOPE_SIN(th));
  }

  template <class T>
  inline complex<T> tan (const complex<T>& a) { return sin(a)/cos(a); }

  template <class T>
  inline complex<T> tanh (const complex<T>& a) { return sinh(a)/cosh(a);
  }
#ifdef _RW_STD_IOSTREAM

  template <class T,class charT, class traits>
  basic_istream<charT, traits >& _RWSTDExportTemplate 
  operator>> (basic_istream<charT, traits >& is,complex<T>& x);
  template <class T,class charT,class traits>

  basic_ostream<charT,traits >& _RWSTDExportTemplate 
  operator<< (basic_ostream<charT, traits >& os,const complex<T>& x);

#else

  template <class T>
  istream& _RWSTDExportTemplate operator>> (istream& is, complex<T>& x);
  template <class T>
  ostream& _RWSTDExportTemplate operator<< (ostream& os, const complex<T>& x);

#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#if defined(_RWSTD_NO_DESTROY_BUILTIN) || defined(_RWSTD_NO_DESTROY_NONBUILTIN)

#ifndef _RWSTD_NO_NAMESPACE
namespace __rogue_wave_std {
#endif
//
// Specializations of STL destroy for complex.
//
  inline void __destroy (complex<float>**)         {}
  inline void __destroy (complex<float>***)        {}
  inline void __destroy (complex<float>****)       {}
  inline void __destroy (complex<double>**)        {}
  inline void __destroy (complex<double>***)       {}
  inline void __destroy (complex<double>****)      {}
#ifndef _RWSTD_NO_LONGDOUBLE
  inline void __destroy (complex<long double>**)   {}
  inline void __destroy (complex<long double>***)  {}
  inline void __destroy (complex<long double>****) {}
#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#endif

#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <complex.cc>
#endif
#endif /* __STD_COMPLEX */

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __COMPLEX_H */
