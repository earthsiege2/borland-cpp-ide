#ifndef __STRING_CC
#define __STRING_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * string.cc - Definitions for the Standard Library string classes
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

//
// Members for class basic_string
//

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// basic_string<...>::__nullref
#ifndef _RWSTD_NO_STATIC_DEF3
  template <class charT, class traits, class Allocator >
  const _TYPENAME basic_string<charT, traits, Allocator>::__null_ref_type
  basic_string<charT, traits, Allocator>::__nullref;
#endif
// basic_string<...>::npos
#if defined(__BORLANDC__) && !defined(_RTLDLL)
#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
#define npos (size_type)-1
#else
  template <class charT, class traits, class Allocator >
  const _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::npos
#ifdef _RWSTD_NO_STATIC_CAST
  = (_TYPENAME basic_string<charT, traits, Allocator>::size_type) -1;
#else
  = static_cast</* _TYPENAME */ basic_string<charT, traits, Allocator>::size_type>(-1); // RW_BUG
#endif

#endif /* __BORLANDC__ && !_RTLDLL */
#endif /*_RWSTD_MSC22_STATIC_INIT_BUG*/

  template <class charT, class traits, class Allocator >
  _TYPENAME basic_string<charT, traits, Allocator>::__string_ref_type *
  basic_string<charT, traits, Allocator>::__getRep (size_type capac, 
                                                    size_type nchar)
                                              
  {                                                     
    if (capac < nchar)
       capac = nchar;

    if ((capac | nchar) == 0)
    {
      __getNullRep()->__addReference();
      return __getNullRep();
    }

    //
    // Allocate, then initialize the __string_ref, then
    // initialize each character in the buffer. 
    //
    __value_alloc_type va(__data_);
#ifdef _RWSTD_NO_STATIC_CAST
    __string_ref_type * ret = (__string_ref_type *)
    va.allocate(capac + sizeof(__rep_type)/sizeof(charT) + 2,0);
#else
    __string_ref_type * ret = 
    reinterpret_cast<__string_ref_type*>
    (va.allocate(capac + sizeof(__rep_type)/sizeof(charT) + 2,0));
#endif

    __ref_alloc_type(__data_).construct(ret, __string_ref_type());
    charT * d = ret->data();
    va.construct(d,charT());

    ret->__capacity_ = capac;
    ret->__setRefCount(1);
    ret->data()[ret->__nchars_ = nchar] = (charT)0; // Terminating null
    return ret;
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator>::basic_string (
      const basic_string<charT, traits, Allocator> & s,
      size_type pos, size_type  n,
      const Allocator& alloc)
    : __data_(0,alloc)
  {
   _RWSTD_THROW(pos > s.length(), out_of_range,
    __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
       "basic_string( const basic_string&,size_type,size_type)", pos,s.length()).msgstr());

    size_type slen = s.length() - pos;
    size_type rlen = n < slen ? n : slen;
    size_type nlen =  n == npos ? 0 : n;
    size_type maxlen = nlen > rlen ? nlen : rlen;
    __data_            = __getRep(maxlen, rlen)->data();

    traits::copy(__data_.data(), &s.__data_.data()[pos], rlen);
  }

  template <class charT, class traits, class Allocator >
  void basic_string<charT, traits, Allocator>::__initn (
      size_type        n,
      charT            c)
  {
   _RWSTD_THROW(n == npos, length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_InvalidSizeParam,
        "basic_string::__initn(size_t,char)", n,npos).msgstr());

    __data_  = __getRep(n, n)->data();

    while (n--) traits::assign(__data_.data()[n], c);
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator>::basic_string (
      const charT*     s,
      size_type        n,
      const Allocator& alloc)
  : __data_(0,alloc)
  {     
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
       "basic_string( const charT*,size_type,const Allocator&)").msgstr());

    _RWSTD_THROW(n == npos, length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_InvalidSizeParam,
        "basic_string( const charT*,size_type,const Allocator&)",n,npos).msgstr());

    __data_  = __getRep(n, n)->data();
    traits::copy(__data_.data(), s, n);
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator>::basic_string (
      const charT*     s,
      const Allocator& alloc)
  : __data_(0,alloc)
  {     
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
        "basic_string(const charT*,const Allocator&)").msgstr());

    size_type len = traits::length(s);
    __data_         = __getRep(len, len)->data();

    traits::copy(__data_.data(), s, len);
  }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator>::basic_string (
      const charT*     s,
      size_type        n)
  : __data_(0,Allocator())
  {     
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
         "basic_string( const charT*,size_type)").msgstr());

    _RWSTD_THROW(n == npos,  length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_InvalidSizeParam,
        "basic_string(const charT*,size_type)",n,npos).msgstr());

    __data_  = __getRep(n, n)->data();

    traits::copy(__data_.data(), s, n);
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator>::basic_string (
      const charT*     s)
  : __data_(0,Allocator())
  {     
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
        "basic_string(const charT*)").msgstr());

    size_type len = traits::length(s);
    __data_         = __getRep(len, len)->data();

    traits::copy(__data_.data(), s, len);
  }
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template <class charT, class traits , class Allocator >
  template <class InputIterator>
  basic_string<charT, traits, Allocator>::basic_string (InputIterator first,
                                                        InputIterator last,
                                                        const Allocator &alloc)
  : __data_(0,alloc)
  {
    __data_ = __getRep(1,0)->data();
    replace(__data_.data(),__data_.data(),first,last);
  }
#endif /* _RWSTD_NO_MEMBER_TEMPLATES */

  template <class charT, class traits , class Allocator  >
  basic_string<charT, traits, Allocator>::basic_string (const charT* first,
                                                        const charT* last,
                                                        const Allocator& alloc)
  : __data_(0,alloc)
  {
    __data_ = __getRep(last-first,0)->data();
    replace(0,0,first,last-first,0,last-first);
  }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
  template <class charT, class traits , class Allocator  >
  basic_string<charT, traits, Allocator>::basic_string (const charT* first,
                                                        const charT* last)
  : __data_(0,Allocator())
  {
    __data_ = __getRep(last-first,0)->data();
    replace(0,0,first,last-first,0,last-first);
  }
#endif /* _RWSTD_NO_DEFAULT_TEMPLATE_ARGS */
  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::operator= (
      const basic_string<charT, traits, Allocator>& str)
  {
    if (this != &str)
    {
      if (str.__pref()->__references() > 0)
      {
        str.__pref()->__addReference();
        __unLink();
        __data_ = str.__data_.data();
      }
      else
        this->operator=(str.c_str());
    }
    return *this;
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::operator= (const charT* s)
  {
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
         "basic_string::operator= (const charT*)").msgstr());

    if (traits::eq(*s, __eos()))
    {
      if (__pref()->__references() == 1)
      {
        __pref()->__nchars_ = 0;
        traits::assign(__data_.data()[0], __eos());
      }
      else
      {
        __unLink();
        __getNullRep()->__addReference();
        __data_ = __getNullRep()->data();
      }
      return *this;
    }

    return replace(0, length(), s, traits::length(s));
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::append (
      const basic_string<charT, traits, Allocator>& str,
      size_type                                     pos,
      size_type                                     n)
  {
     _RWSTD_THROW(pos > str.length(), out_of_range,
      __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
        "basic_string::append(basic_string&,size_type,size_type)", pos,str.length()).msgstr());

    size_type slen = str.length() - pos;
    size_type rlen = n < slen ? n : slen; 

    _RWSTD_THROW(length() >= npos - rlen, length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
          "basic_string::append(const basic_string&,size_type,size_type)",
            length(),npos-rlen).msgstr());

    replace(length(), 0, str.data(), str.length(), pos, n);

    return *this;
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::append (
      const basic_string<charT, traits, Allocator>& str)
  {
    _RWSTD_THROW(length() >= npos - str.length(), length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
          "basic_string::append(const basic_string&)",length(),str.length()).msgstr());

    replace(length(), 0, str.data(), str.length());

    return *this;
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::assign (
      const basic_string<charT, traits, Allocator>& str,
      size_type                                     pos,
      size_type                                     n)
  {
    _RWSTD_THROW(pos > str.length(), out_of_range,
      __RWSTD::except_msg_string(__RWSTD::__rwse_PosBeyondEndOfString,
        "basic_string::assign(basic_string&,size_type,size_type)", pos,str.length()).msgstr());

    size_type slen = str.length() - pos;
    size_type rlen = n < slen ? n : slen; 
    return replace(0, length(), str, pos, rlen);
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::assign (
      const basic_string<charT, traits, Allocator>& str)
  {
    return replace(0, length(), str);
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::insert (
      size_type                                     pos1,
      const basic_string<charT, traits, Allocator>& str,
      size_type                                     pos2,
      size_type                                     n)
  {
    _RWSTD_THROW(pos1 > length() || pos2 > str.length(), out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
        "basic_string::insert(size_t,const basic_string&,size_t,size_t)",
           pos1 > length() ? pos1:pos2,str.length()).msgstr());

    size_type slen = str.length() - pos2;
    size_type rlen = n < slen ? n : slen; 

    _RWSTD_THROW( length() >= npos - rlen, length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
        "basic_string::insert(size_t,const basic_string&,size_t,size_t)",
            length(),npos - rlen).msgstr());

    return replace(pos1, 0, str, pos2, n);
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::insert (
      size_type                                     pos1,
      const basic_string<charT, traits, Allocator>& str)
  {
    _RWSTD_THROW(pos1 > length(), out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
        "basic_string::insert(size_t,const basic_string&)",pos1,length()).msgstr());

    _RWSTD_THROW(length() >= npos - str.length(),  length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
        "basic_string::insert(size_t,const basic_string&)",
          length(), npos - str.length()).msgstr());

    return replace(pos1, 0, str);
  }

  template <class charT, class traits, class Allocator >
  _TYPENAME basic_string<charT, traits, Allocator>::iterator 
  basic_string<charT, traits, Allocator>::replace (
      size_type    pos1,
      size_type    n1,
      const charT* cs,
      size_type    cslen,
      size_type    pos2,
      size_type    n2)
  {
     _RWSTD_THROW(pos1 > length() || pos2 > cslen, out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
        "basic_string::replace(size_t,size_t,char*,size_t,size_t,size_t)",
           pos1 > length() ? pos1:pos2,length() > cslen ? length():cslen).msgstr());

    size_type slen = length() - pos1;
    size_type xlen = n1 < slen ? n1 : slen; 
    size_type clen = cslen - pos2;
    size_type rlen = n2 < clen ? n2 : clen; 

    _RWSTD_THROW(length() - xlen >= npos - rlen, length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
        "basic_string::replace(size_t,size_t,char*,size_t,size_t,size_t)",
          length()-xlen,npos - rlen).msgstr());

    size_type tot = length() - xlen + rlen;  // Final string length.

    if (!tot)
    {
      // Special case a substitution that leaves the string empty.
      __unLink();
      __getNullRep()->__addReference();
      __data_ = __getNullRep()->data();
    }
    else
    {
      size_type rem = length() - xlen - pos1;  // Length of bit at end of string
      // Check for shared representation, insufficient capacity, 
      //  or overlap copy.
      if ( (__pref()->__references() > 1)
           || (__getCapac() < tot)
           || (cs && (cs >= data() && cs < data()+length())))
      {
        // Need to allocate a new reference.
        __string_ref_type * temp = __getRep(tot,tot);
        if (pos1) traits::copy(temp->data(), __data_.data(), pos1);
        if (rlen) traits::copy(temp->data()+pos1, cs+pos2, rlen);
        if (rem ) traits::copy(temp->data()+pos1+rlen, __data_.data()+pos1+n1, rem);
        __unLink();
        __data_ = temp->data();
      }
      else
      {
        // Current reference has enough room.
        if (rem)  traits::move(__data_.data()+pos1+rlen, __data_.data()+pos1+n1, rem);
        if (rlen) traits::move(__data_.data()+pos1, cs+pos2, rlen);
        __data_.data()[__pref()->__nchars_ = tot] = __eos();   // Add terminating null
      }
    }
    return __data_.data() + pos1;
  }

  template <class charT, class traits , class Allocator  >
  basic_string<charT, traits, Allocator> &
  basic_string<charT, traits, Allocator>::replace (size_type pos,
                                                   size_type n,
                                                   size_type n2,
                                                   charT c)
  {
    _RWSTD_THROW(pos > length(), out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
        "basic_string:::replace(size_t,size_t,size_t,char)", pos,length()).msgstr());

    size_type slen = length() - pos;
    size_type xlen = n < slen ? n : slen; 

    _RWSTD_THROW(length() - xlen >= npos - n2, length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
          "basic_string::replace(size_t,size_t,size_t,char)",
            length()-xlen,npos - n2).msgstr());

    size_type tot = length() - xlen + n2;  // Final string length.

    if (!tot)
    {
      // Special case a substitution that leaves the string empty.
      __unLink();
      __getNullRep()->__addReference();
      __data_ = __getNullRep()->data();
    }
    else
    {
      size_type rem = length() - xlen - pos; // Length of bit at end of string
      // Check for shared representation, insufficient capacity, 
      if ( (__pref()->__references() > 1) || (__getCapac() < tot))
      {
        // Need to allocate a new reference.
        __string_ref_type * temp = __getRep(tot,tot);
        if (pos) traits::copy(temp->data(), __data_.data(), pos);
        if (n2) traits::assign(temp->data()+pos, n2,c);
        if (rem ) traits::copy(temp->data()+pos+n2, __data_.data()+pos+n, rem);
        __unLink();
        __data_ = temp->data();
      }
      else
      {
        // Current reference has enough room.
        if (rem)  traits::move(__data_.data()+pos+n2, __data_.data()+pos+n, rem);
        if (n2) traits::assign(__data_.data()+pos, n2, c);
        __data_.data()[__pref()->__nchars_ = tot] = __eos();   // Add terminating null
      }
    }
    return *this;
  }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES

  // Since we have no way of knowing how much is out there
  // between first2 and last2 we have to allocate some space
  // in chunks as needed and copy over characters in groups
  // until we reach the end of the range.  After that 
  // we can tidy things up.  We avoid this using replace_aux
  // any time we have an InputIterator capable of giving us
  // the distance information we need.  If InputIterator
  // is really a charT* then we should never even get here.
  template<class charT, class traits , class Allocator >
  template<class InputIterator>
  inline basic_string<charT, traits, Allocator>& 
  basic_string<charT, traits, Allocator>::replace (
      iterator first1, 
      iterator last1,
      InputIterator first2,
      InputIterator last2)
  {
     iterator first = first1;
     iterator last = last1;

     // Use a (probably)faster algorithm if possible
     if (__is_bidirectional_iterator(__iterator_category(first2)))
       return __replace_aux(first1,last1,first2,last2);

     _RWSTD_THROW((first > end() || last > end()),out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
          "basic_string::replace(iterator,iterator,InputIterato,InputIterato)"
           ,first > end() ? first : last,end()).msgstr());

     while (first2 != last2)
     {
     _RWSTD_THROW(first  - __data_.data() == (int)npos,length_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
          "basic_string::replace(iterator,iterator,InputIterator,InputIterator)"
           ,first-__data_.data(),npos).msgstr());
       if (first == last)
       {
         // Need to allocate a more room.
         // First get the amount to increase buffer size         
         size_type delta =  __RWSTD::__rw_allocation_size((value_type*)0,
                                                        (size_type)0,
                                                        (size_type)0);
         delta = delta > 0 ? delta : 1;
         size_type tot = delta + size();
         // Now get new buffer
         __string_ref_type * temp = __getRep(tot,tot);
         // Now copy data from old to new, leaving a hole for additions
         size_type current = last-begin();
         traits::copy(temp->data(),__data_.data(),current);
         traits::copy(temp->data()+current+delta,last,end()-last);
         __unLink();
         __data_ = temp->data();
         first = __data_.data() + current;
         last = first + delta;
       }
       // Copy data over
       *first++ = *first2++;
     }    
     if (first != last)
       replace(first-__data_.data(),last-first,0,(charT)' ');   // Clean up  

     return *this;
  }

  // Special function for random access and bi-directional iterators
  // Avoids the possibility of multiple allocations
  // We still have to copy characters over one at a time.
  template<class charT, class traits , class Allocator >
  template<class InputIterator>
  inline basic_string<charT, traits, Allocator>& 
  basic_string<charT, traits, Allocator>::__replace_aux (
      iterator first1, 
      iterator last1,
      InputIterator first2,
      InputIterator last2)
  {
    difference_type n2 = 0;
    distance(first2,last2,n2);
    size_type n = last1-first1;
    size_type pos = first1 - __data_.data();

    _RWSTD_THROW(pos > length(),out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_StringIndexOutOfRange,
          "basic_string::__replace_aux(iterator,iterator,InputIterator,InputIterator)"
           ,pos,length()).msgstr());

    size_type slen = length() - pos;
    size_type xlen = n < slen ? n : slen; 

   _RWSTD_THROW(length() - xlen >= npos - n2,length_error,
    __RWSTD::except_msg_string(__RWSTD::__rwse_ResultLenInvalid,
         "basic_string::__replace_aux(iterator,iterator,InputIterator,InputIterator)"
           ,length() - xlen, npos - n2).msgstr());

    size_type tot = length() - xlen + n2;  // Final string length.

    if (!tot)
    {
      // Special case a substitution that leaves the string empty.
      __unLink();
      __getNullRep()->__addReference();
      __data_ = __getNullRep()->data();
    }

    else
    {
      size_type d = 0;
      size_type rem = length() - xlen - pos; // Length of bit at end of string
      // Check for shared representation, insufficient capacity, 
      if ( (__pref()->__references() > 1) || (__getCapac() < tot))
      {
        // Need to allocate a new reference.
        __string_ref_type * temp = __getRep(tot,tot);
        if (pos) traits::copy(temp->data(), __data_.data(), pos);
        for (d = 0; d < (size_type)n2; d++)
          *(temp->data()+pos+d) = *first2++;
        if (rem ) 
          traits::copy(temp->data()+pos+n2, __data_.data()+pos+n, rem);
        __unLink();
        __data_ = temp->data();
      }
      else
      {
        // Current reference has enough room.
        if (rem)  
          traits::move(__data_.data()+pos+n2, __data_.data()+pos+n, rem);
        for (d = 0; d < (size_type)n2; d++)
          *(__data_.data()+pos+d) = *first2++;
        __data_.data()[__pref()->__nchars_ = tot] = __eos();   // Add terminating null
      }
    }
    return *this;
  }
#endif // _RWSTD_NO_MEMBER_TEMPLATES

  template <class charT, class traits, class Allocator >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::copy (charT* s,
                                                size_type n,
                                                size_type pos) const
  {
    _RWSTD_THROW(pos > length(), out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_PosBeyondEndOfString,
          "basic_string::copy(char*,size_t,size_t)",pos,length()).msgstr());

    size_type slen = length() - pos;
    size_type rlen = n < slen ? n : slen;
    traits::copy(s, __data_.data()+pos, rlen);
    return rlen;
  }
  template <class charT, class traits , class Allocator  >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::find (const charT* s,
                                                size_type pos,
                                                size_type n) const
  {
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
          "basic_string::find(char*,size_t,size_t) const").msgstr());

    for (size_type xpos = pos; (xpos + n) <= length() ; xpos++)
    {
      if (!traits::compare(__data_.data()+xpos,s,n))
        return xpos;
    }

    return npos;
  }

  template <class charT, class traits , class Allocator  >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::rfind (const charT* s,
                                                 size_type pos,
                                                 size_type n) const
  {

    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
          "basic_string::rfind(char*,size_t,size_t) const").msgstr());

    if (length() < n)
      return npos;
    
    size_type slen = length() -n;
    size_type xpos_start = slen < pos ? slen : pos; 

    for (size_type xpos = xpos_start+1; xpos != 0 ; xpos--)
    {
      if (!traits::compare(__data_.data()+xpos-1,s,n))
        return xpos-1;
    }

    return npos;
  }

  template <class charT, class traits , class Allocator  >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::find_first_of (const charT* s,
                                                         size_type pos,
                                                         size_type n) const
  {

    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
          "basic_string::find_first_of(char*,size_t,size_t) const").msgstr());

    for (size_type xpos = pos; xpos < length() ; xpos++)
    {
      for (size_type i = 0; i < n ; i++)
        if (traits::eq(__data_.data()[xpos], s[i]))
          return xpos;
    }

    return npos;
  }
  template <class charT, class traits , class Allocator  >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::find_last_of (const charT* s,
                                                        size_type pos,
                                                        size_type n) const
  {
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
          "basic_string::find_last_of(char*,size_t,size_t) const").msgstr());

    if (length())
    {
      size_type slen = length() -1;
      size_type xpos_start = pos < slen ? pos : slen; 
      for (size_type xpos = xpos_start+1; xpos != 0 ; xpos--)
      {
        for(size_type i = 0; i < n ; i++)
          if (traits::eq(__data_.data()[xpos-1], s[i]))
            return xpos-1;
      } 
    }
    return npos;
  }

  template <class charT, class traits , class Allocator  >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::find_first_not_of (const charT* s,
                                                             size_type pos,
                                                             size_type n) const
  {
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
          "basic_string::find_first_not_of(char*,size_t,size_t) const").msgstr());

    for (size_type xpos = pos; xpos < length() ; xpos++)
    {
      bool found = false;
      for (size_type i = 0; i < n ; i++)
      {
        if (traits::eq(__data_.data()[xpos], s[i]))
        {
          found = true;
          break;
        }
      }
      if (!found)
        return xpos;
    }

    return npos;
  }

  template <class charT, class traits , class Allocator  >
  _TYPENAME basic_string<charT, traits, Allocator>::size_type
  basic_string<charT, traits, Allocator>::find_last_not_of(const charT* s,
                                                           size_type pos,
                                                           size_type n) const
  {
    _RWSTD_THROW(s == 0, logic_error,
     __RWSTD::except_msg_string(__RWSTD::__rwse_UnexpectedNullPtr,
          "basic_string::find_last_not_of(char*,size_t,size_t) const").msgstr());

    if (length())
    {
      size_type slen = length() -1;
      size_type xpos_start = pos < slen ? pos : slen; 
      for (size_type xpos = xpos_start+1; xpos != 0 ; xpos--)
      {
        bool found = false;
        for (size_type i = 0; i < n ; i++)
        {
          if (traits::eq(__data_.data()[xpos-1], s[i]))
          {
            found = true;
            break;
          }
        }
        if (!found)
          return xpos-1;
      }
    }

    return npos;
  }

  template <class charT, class traits, class Allocator >
  basic_string<charT, traits, Allocator>
  basic_string<charT, traits, Allocator>::substr (size_type pos,
                                                  size_type n) const
  {
    _RWSTD_THROW(pos > length(), out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_PosBeyondEndOfString,
          "basic_string::substr(size_t,size_t) const",pos, length()).msgstr());

    size_type slen = length() -pos;
    size_type rlen = n < slen ? n : slen; 
    return basic_string<charT, traits, Allocator>(__data_.data()+pos, rlen);
  }

  template <class charT, class traits, class Allocator >
  int
  basic_string<charT, traits, Allocator>::compare (
      size_type pos1, size_type n1,
      const basic_string<charT, traits, Allocator>& str,
      size_type pos2, size_type n2) const
  {
    _RWSTD_THROW(pos1+n1 > length() || pos2+n2 > str.length(),out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_PosBeyondEndOfString,
       "basic_string::compare(size_t,size_t,const basic_string&,size_t,size_t) const",
         pos1+n1 > length() ?  (pos1+n1) : (pos2+n2),length() > str.length() ? length(): str.length()).msgstr());

    return compare(pos1,n1,str.c_str()+pos2,n2);
  }

  template <class charT, class traits, class Allocator >
  int
  basic_string<charT, traits, Allocator>::compare (
      size_type pos1, size_type n1,
      const basic_string<charT, traits, Allocator>& str) const
  {
    _RWSTD_THROW(pos1+n1 > length() ,out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_PosBeyondEndOfString,
       "basic_string::compare(size_t,size_t,const basic_string&) const",
         pos1+n1 ,length()).msgstr());

    return compare(pos1,n1,str.c_str(),str.length());
  }

  template <class charT, class traits , class Allocator  >
  int
  basic_string<charT, traits, Allocator>::compare (size_type pos,
                                                   size_type n1,
                                                   const charT* s,
                                                   size_type n2) const
  {
     _RWSTD_THROW(pos > length() ,out_of_range,
     __RWSTD::except_msg_string(__RWSTD::__rwse_PosBeyondEndOfString,
       "basic_string::compare(size_t,size_t,const const charT*,size_t) const",
         pos ,length()).msgstr());
    if(length() - pos < n1)
      n1 = length() - pos;
    size_type rlen = n1 < n2 ? n1 : n2; 
    int result = traits::compare(__data_.data()+pos, s, rlen);

    if (result == 0)
      result = (n1 < n2) ? -1 : (n1 != n2);

    return result;
  }

  template <class charT, class traits, class Allocator >
  void basic_string<charT, traits, Allocator>::__clobber (size_type nc)
  {
    if (__pref()->__references() > 1 || (__getCapac() < nc))
    {
      __unLink();
      __data_ = __getRep(nc, 0)->data();
    }
    else
      __data_.data()[__pref()->__nchars_ = 0] = 0;
  }

  template <class charT, class traits, class Allocator >
  void basic_string<charT, traits, Allocator>::__clone()
  {
    __string_ref_type * temp = __getRep(length(), length());
    traits::copy(temp->data(), data(), length());
    __unLink();
    __data_ = temp->data();
  }

  template <class charT, class traits, class Allocator >
  void basic_string<charT, traits, Allocator>::__clone (size_type nc)
  {
    size_type len = length();
    if (len > nc) len = nc;
    __string_ref_type * temp = __getRep(nc, len);
    traits::copy(temp->data(), data(), length());
    __unLink();
    __data_ = temp->data();
  }

#ifdef _RWSTD_MSC22_STATIC_INIT_BUG
#undef npos
#endif

//
// Inserters and Extractors
//

#ifndef _RW_STD_IOSTREAM

  template<class charT, class traits, class Allocator>
  istream & _RWSTDExportTemplate operator>> (istream & is,
                                             basic_string<charT, traits, Allocator > & s)
  {
    int c;

    if (!is.ipfx())
      return is;

    s.erase();
    c = is.rdbuf()->sbumpc();

#ifdef _RWSTD_MS40_ISTREAM_BUG
    _TYPENAME size_t i =0;
    _TYPENAME size_t end = s.max_size();
#else
    _TYPENAME Allocator::size_type i   = 0;
    _TYPENAME Allocator::size_type end = s.max_size();
#endif
    if (is.width())
      end =  (int)end < is.width() ? end : is.width(); 

    while (c != EOF && !isspace(c))
    {
      s.append(1,(charT)c);
      i++;
      if (i == end)
        break;
      c = is.rdbuf()->sbumpc();
    }
    if (c == EOF) 
      is.clear(ios::eofbit | is.rdstate());      
    if (!i)
      is.clear(ios::failbit | is.rdstate());      

    is.width(0);
    return is;
  }
  template<class charT, class traits, class Allocator>
  ostream & _RWSTDExportTemplate operator<< (ostream & os,
                                             const basic_string<charT, traits, Allocator > & s)
  {
    os << s.data();
    return os;
  }

  template<class Stream, class charT, class traits, class Allocator>
  Stream& _RWSTDExportTemplate
  getline (Stream& is, basic_string<charT, traits, Allocator>& str, charT delim)
  {
    int c;
    
    if (!is.ipfx(1))
      return is;

    str.erase();
    c = is.rdbuf()->sbumpc();

#ifdef _RWSTD_MS40_ISTREAM_BUG
    size_t i = 0;
    size_t end = str.max_size();
#else
    _TYPENAME Allocator::size_type i = 0;
    _TYPENAME Allocator::size_type end = str.max_size();
#endif

    while (c != EOF)
    {
      i++;
      if ((charT)c == delim)
        break;
      if (i == end)
      {
        is.clear(ios::failbit | is.rdstate());      
        break;
      }
        
      str.append(1,(charT)c);
      c = is.rdbuf()->sbumpc();
    }
    if (c == EOF) 
      is.clear(ios::eofbit | is.rdstate());      
    if (!i)
      is.clear(ios::failbit | is.rdstate());      

    is.isfx();
    return is;
  }  
#endif /* not defined _RW_STD_IOSTREAM */

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __STRING_CC */
