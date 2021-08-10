/***************************************************************************
 *
 * string.cc - Definitions for the Standard Library string classes
 *
 * $Id: string.cc,v 1.76 1995/09/29 22:28:50 smithey Exp $
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED
 *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Members for class string_ref
//
#ifndef RWSTD_NO_STATIC_DEF3
template <class charT, class traits, class Allocator >
const null_string_ref_rep<charT, traits, Allocator>
basic_string<charT, traits, Allocator>::nullref 
  = null_string_ref_rep<charT, traits, Allocator>();
#endif

//
// Members for class basic_string
//


template <class charT, class traits, class Allocator >
const basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::npos
  = (basic_string<charT, traits, Allocator>::size_type) -1;


template <class charT, class traits, class Allocator >
string_ref<charT, traits, Allocator> *
basic_string<charT, traits, Allocator>::getRep (size_type capac, 
                                                size_type nchar,
                                                Allocator& alloc)
{ 							
  if ((capac | nchar) == 0)
  {
    getNullRep()->addReference();
    return getNullRep();
  }

  string_ref<charT, traits, Allocator> * ret = 
    (string_ref<charT, traits, Allocator> *) alloc.allocate(
      (capac+1)*sizeof(charT) + sizeof(string_ref_rep<Allocator>));
  //
  // Initialize the string_ref, then
  // initialize each character in the buffer.  Allocator had better
  // provide a placement new for this purpose, if appropriate.
  //
  new (ret) string_ref<charT,traits,Allocator>;
  charT * d = ret->data();
  for (size_type i = 0; i <= capac; i++, d++)
    new (d) charT;

  ret->capacity_ = capac;
  ret->setRefCount(1);
  ret->data()[ret->nchars_ = nchar] = traits::eos(); // Terminating null

  return ret;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::basic_string (
  const basic_string<charT, traits, Allocator> & s,
  size_type                                      pos, 
  size_type                                      n,
  const Allocator&                               alloc)
{							 
    RWSTD_THROW(pos > s.length(), out_of_range, rwse_PosBeyondEndOfString);

    size_type rlen   = min(n, s.length() - pos);
    size_type maxlen = max(n == npos ? 0 : n, rlen);
    alloc_           = alloc;
    data_            = getRep(maxlen, rlen, alloc_)->data();

    traits::copy(data_, &s.data_[pos], rlen);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::basic_string (
  const charT*     s,
  size_type        n,
  const Allocator& alloc)
{				  			 
    RWSTD_THROW(s == 0, logic_error, rwse_UnexpectedNullPtr);

    alloc_ = alloc;
    data_  = getRep(n, n, alloc_)->data();

    traits::copy(data_, s, n);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::basic_string (
  const charT*     s,
  const Allocator& alloc)
{							 
    RWSTD_THROW(s == 0, logic_error, rwse_UnexpectedNullPtr);

    size_type len = traits::length(s);
    alloc_        = alloc;
    data_         = getRep(len, len, alloc_)->data();

    traits::copy(data_, s, len);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::basic_string (
  size_type        n,
  charT            c,
  const Allocator& alloc)
{
    RWSTD_THROW(n == npos, length_error, rwse_InvalidSizeParam);

    alloc_ = alloc;
    data_  = getRep(n, n, alloc_)->data();

    while (n--) traits::assign(data_[n], c);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::operator= (
  const basic_string<charT, traits, Allocator>& str)
{
    str.pref()->addReference();
    pref()->unLink(alloc_);
    data_ = str.data_;
    return *this;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::operator= (const charT* s)
{
    RWSTD_THROW(s == 0, logic_error, rwse_UnexpectedNullPtr);

    if (traits::eq(*s, eos()))
    {
        if (pref()->references() == 1)
        {
            pref()->nchars_ = 0;
            traits::assign(data_[0], eos());
        }
        else
        {
            pref()->unLink(alloc_);
            getNullRep()->addReference();
            data_ = getNullRep()->data();
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
    RWSTD_THROW(pos > str.length(), out_of_range, rwse_PosBeyondEndOfString);

    size_type rlen = min(n, str.length() - pos);

    RWSTD_THROW(length() >= npos - rlen,
                length_error,
                rwse_ResultLenInvalid);

    replace(length(), 0, str.data(), str.length(), pos, n);

    return *this;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::assign (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos,
  size_type                                     n)
{
    RWSTD_THROW(pos > str.length(), out_of_range, rwse_PosBeyondEndOfString);
    size_type rlen = min(n, str.length() - pos);
    return replace(0, length(), str, pos, rlen);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator> &
basic_string<charT, traits, Allocator>::insert (
  size_type                                     pos1,
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos2,
  size_type                                     n)
{
  RWSTD_THROW(pos1 > length() || pos2 > str.length(),
              out_of_range,
              rwse_StringIndexOutOfRange);
  size_type rlen = min(n, str.length() - pos2);
  RWSTD_THROW(length() >= npos - rlen, length_error, rwse_ResultLenInvalid);
  return replace(pos1, 0, str, pos2, n);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::iterator 
basic_string<charT, traits, Allocator>::replace (
  size_type    pos1,
  size_type    n1,
  const charT* cs,
  size_type    cslen,
  size_type    pos2,
  size_type    n2)
{
  RWSTD_THROW(pos1 > length() || pos2 > cslen,
              out_of_range,
              rwse_StringIndexOutOfRange);

  size_type xlen = min(n1, length() - pos1);
  size_type rlen = min(n2, cslen - pos2);

  RWSTD_THROW(length() - xlen >= (size_type)npos - rlen,
              length_error,
              rwse_ResultLenInvalid );

  size_type tot = length() - xlen + rlen;  // Final string length

  if (!tot)
  {
    //
    // Special case a substitution that leaves the string empty.
    //
    pref()->unLink(alloc_);
    getNullRep()->addReference();
    data_ = getNullRep()->data();
  }
  else
  {
    size_type rem = length() - xlen - pos1;  // Length of bit at end of string
    //
    // Check for shared representation, insufficient capacity, or overlap copy.
    //
#ifdef RWSTD_MULTI_THREAD
    RWSTDGuard guard(pref()->mutex_);
#endif
    if ( (pref()->references() > 1)
      || (getCapac() < tot)
      || (cs && (cs >= data() && cs < data()+length())))
    {
        //
        // Need to allocate a new reference.
        //
        string_ref<charT, traits, Allocator> * temp
          = getRep(tot, tot, alloc_);
        if (pos1) traits::copy(temp->data(), data_, pos1);
        if (rlen) traits::copy(temp->data()+pos1, cs+pos2, rlen);
        if (rem ) traits::copy(temp->data()+pos1+rlen, data_+pos1+n1, rem);
        pref()->unSafeunLink(alloc_);
        data_ = temp->data();
      }
      else
      {
        //
        // Current reference has enough room.
        //
        if (rem)  traits::move(data_+pos1+rlen, data_+pos1+n1, rem);
        if (rlen) traits::move(data_+pos1, cs+pos2, rlen);
        data_[pref()->nchars_ = tot] = eos();	// Add terminating null
      }
  }
  return data_ + pos1;
}

template <class charT, class traits, class Allocator >
void
basic_string<charT, traits, Allocator>::resize (size_type n, charT c)
{
    RWSTD_THROW(n == npos, length_error, rwse_InvalidSizeParam);

    if (n < length())
        remove(n);
    else if (n > length())
        append(n - length(), c);
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::copy (charT* s,
                                              size_type n,
                                              size_type pos)
{
    RWSTD_THROW(pos > length(), out_of_range, rwse_PosBeyondEndOfString);
    size_type rlen = min(n, length() - pos);
    traits::copy(s, data_+pos, rlen);
    return rlen;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos) const
{
    //  
    // Should be implemented in traits (strpbrk function)
    //
    for (size_type xpos = pos; (xpos + str.length()) <= length() ; xpos++)
    {
        bool found = true;
        for (size_type i = 0; i < str.length() ; i++)
        {
            if (!traits::eq(data_[xpos + i], str.data_[i]))
            {
                found = false;
                break;
            }
        }
        if (found)
            return xpos;
    }

    return npos;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::rfind (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos) const
{
    size_type xpos_start = length() < str.length() ?
                           npos :
                           min(length() - str.length(), pos);

    for (size_type xpos = xpos_start; xpos != npos ; xpos--)
    {
        bool found = true;
        for (size_type i = 0; i < str.length() ; i++)
        {
            if (!traits::eq(data_[xpos + i], str.data_[i]))
            {
                found = false;
                break;
            }
        }
        if (found)
            return xpos;
    }

    return npos;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_of (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos) const
{
    for (size_type xpos = pos; xpos < length() ; xpos++)
    {
        for (size_type i = 0; i < str.length() ; i++)
            if (traits::eq(data_[xpos], str.data_[i]))
                return xpos;
    }

    return npos;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_of (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos) const
{
    size_type xpos_start = length() ? min(pos, length() - 1) : npos;

    for (size_type xpos = xpos_start; xpos != npos ; xpos--)
    {
        for(size_type i = 0; i < str.length() ; i++)
            if (traits::eq(data_[xpos], str.data_[i]))
                return xpos;
    }

    return npos;
}

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_first_not_of (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos) const
{
    for (size_type xpos = pos; xpos < length() ; xpos++)
    {
        bool found = false;
        for (size_type i = 0; i < str.length() ; i++)
        {
            if (traits::eq(data_[xpos], str.data_[i]))
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

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>::size_type
basic_string<charT, traits, Allocator>::find_last_not_of (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos) const
{
    size_type xpos_start = length() ? min(pos, length() - 1) : npos;

    for (size_type xpos = xpos_start; xpos != npos ; xpos--)
    {
        bool found = false;
        for (size_type i = 0; i < str.length() ; i++)
        {
            if (traits::eq(data_[xpos], str.data_[i]))
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

template <class charT, class traits, class Allocator >
basic_string<charT, traits, Allocator>
basic_string<charT, traits, Allocator>::substr (size_type pos,
                                                size_type n) const
{
    RWSTD_THROW(pos > length(), out_of_range, rwse_PosBeyondEndOfString);
    size_type rlen = min(n, length() - pos);
    return basic_string<charT, traits, Allocator>(data_+pos, rlen);
}

template <class charT, class traits, class Allocator >
int
basic_string<charT, traits, Allocator>::compare (
  const basic_string<charT, traits, Allocator>& str,
  size_type                                     pos,
  size_type                                     n) const
{
    RWSTD_THROW(pos > length(), out_of_range, rwse_PosBeyondEndOfString);

    size_type llen = min(n, length() - pos);
    size_type slen = str.length();
    size_type rlen = min(llen, slen);

    int result = traits::compare(data_+pos, str.data_, rlen);

    if (result == 0)
        result = (llen < slen) ? -1 : (llen != slen);

    return result;
}

template <class charT, class traits, class Allocator >
void basic_string<charT, traits, Allocator>::clobber (size_type nc)
{
    if (pref()->references() > 1 || (getCapac() < nc))
    {
        pref()->unLink(alloc_);
        data_ = getRep(nc, 0, alloc_)->data();
    }
    else
        data_[pref()->nchars_ = 0] = 0;
}

template <class charT, class traits, class Allocator >
void basic_string<charT, traits, Allocator>::unSafeClone ()
{
    string_ref<charT, traits, Allocator> * temp =
        getRep(length(), length(), alloc_);

    traits::copy(temp->data(), data(), length());
    pref()->unSafeunLink(alloc_);
    data_ = temp->data();
}

template <class charT, class traits, class Allocator >
void basic_string<charT, traits, Allocator>::unSafeClone (size_type nc)
{
    size_type len = length();
    if (len > nc) len = nc;
    string_ref<charT, traits, Allocator> * temp = getRep(nc, len, alloc_);
    traits::copy(temp->data(), data(), length());
    pref()->unSafeunLink(alloc_);
    data_ = temp->data();
}

//
// Inserters and Extractors
//

#ifdef RW_STD_IOSTREAM

template<class charT, class traits, class IS_traits, class Allocator>
basic_istream<charT, IS_traits > &
operator>> (basic_istream<charT, IS_traits >& is,
            basic_string<charT, traits, Allocator >& s)
{
    charT c;
    traits::char_in(is, c);
    while (is.good() && traits::is_del(c))
        traits::char_in(is, c);

    typename Allocator::size_type i = 0;
    while (is.good() && i < npos && !traits::is_del(c))
    {
        str[i] = c;
        traits::char_in(is, c);
        i++;
    }

    s = str;

    return is;
}

template<class charT, class traits, class IS_traits, class Allocator>
basic_ostream<charT, IS_traits > &
operator<< (basic_ostream<charT, IS_traits > & os,
            const basic_string<charT, traits, Allocator >& a)
{
    typename Allocator::size_type x;
    if ((os.flags() & ios::adjustfield) == ios::right)
       for (x = 0; x < os.width() - s.length(); x++)
          traits::char_out(os, os.fill());
    for (x = 0; x < s.length() ; x++)
        traits::char_out(os, s[x]);
    if ((os.flags() & ios::adjustfield) == ios::left)
       for (x = s.length(); x < os.width(); x++)
          traits::char_out(os, os.fill());
    return os;
}

template<class charT, class IS_traits, class STR_traits, class STR_Alloc>
basic_istream<charT, IS_traits>&
getline (basic_istream<charT, IS_traits>& is,
         basic_string<charT, STR_traits, STR_Alloc>& str,
         charT delim)
{
    charT c;

    str.remove();
    STR_traits::char_in(is,c);

    typename STR_Alloc::size_type i = 0;
    while (is.good())
    {
        if (i == str.npos)
        {
            is.setstate(IS_traits::failbit);
            break;
        }
        if (c == delim)
            break;
        str.append(1,c);
        STR_traits::char_in(is,c);
        i++;
    }
    if (!i)
        is.setf(IS_traits::failbit);
    return is;
}  

#else

template<class charT, class traits, class Allocator>
istream & operator>> (istream & is,
                      basic_string<charT, traits, Allocator > & s)
{
    charT c;

    s.remove();
    traits::char_in(is,c);
    while (is.good() && traits::is_del(c))
        traits::char_in(is,c);

    typename Allocator::size_type i = 0;
    while (is.good() && i < s.npos && !traits::is_del(c))
    {
        s.append(1,c);
        traits::char_in(is,c);
        i++;
    }

    return is;
}


template<class charT, class traits, class Allocator>
ostream & operator<< (ostream & os,
                      const basic_string<charT, traits, Allocator > & s)
{
    typename Allocator::size_type x;
    if ((os.flags() & ios::adjustfield) == ios::right)
       for (x = 0; x < os.width() - s.length(); x++)
          traits::char_out(os, os.fill());
    for (x = 0; x < s.length() ; x++)
        traits::char_out(os, s[x]);
    if ((os.flags() & ios::adjustfield) == ios::left)
       for (x = s.length(); x < os.width(); x++)
          traits::char_out(os, os.fill());
    return os;
}

#ifdef RWSTD_NO_SPEC_OVERLOAD
istream & RWSTDExport operator>> (istream & is, string & s)
{
    char c;

    s.remove();
    string::traits_type::char_in(is,c);
    while (is.good() && string::traits_type::is_del(c))
        string::traits_type::char_in(is,c);

    typename string::size_type i = 0;
    while (is.good() && i < s.npos && !string::traits_type::is_del(c))
    {
        s.append(1,c);
        string::traits_type::char_in(is,c);
        i++;
    }

    return is;
}

ostream& RWSTDExport operator<< (ostream & os, const string& s)
{
    typename string::size_type x;
    if ((os.flags() & ios::adjustfield) == ios::right)
       for (x = 0; x < os.width() - s.length(); x++)
          string::traits_type::char_out(os, os.fill());
    for (x = 0; x < s.length() ; x++)
        string::traits_type::char_out(os, s[x]);
    if ((os.flags() & ios::adjustfield) == ios::left)
       for (x = s.length(); x < os.width(); x++)
          string::traits_type::char_out(os, os.fill());
    return os;
}

#ifndef RWSTD_NO_WSTR
ostream & RWSTDExport operator<< (ostream & os, wstring& s)
{
    typename wstring::size_type x;
    if ((os.flags() & ios::adjustfield) == ios::right)
       for (x = 0; x < os.width() - s.length(); x++)
          wstring::traits_type::char_out(os, os.fill());
    for (x = 0; x < s.length() ; x++)
        wstring::traits_type::char_out(os, s[x]);
    if ((os.flags() & ios::adjustfield) == ios::left)
       for (x = s.length(); x < os.width(); x++)
          wstring::traits_type::char_out(os, os.fill());
    return os;
}
#endif
#endif

template<class charT, class traits, class Allocator>
istream&
getline (istream& is, basic_string<charT, traits, Allocator>& str, charT delim)
{
    charT c;

    str.remove();
    traits::char_in(is, c);

    typename Allocator::size_type i = 0;
    while (is.good())
    {
        if (i == str.npos)
        {
            is.setf(istream::failbit);
            break;
        }
        if (c == delim)
            break;
        str.append(1,c);
        traits::char_in(is,c);
        i++;
    }
    if (!i)
        is.setf(istream::failbit);
    return is;
}  

#endif /* not defined RW_STD_IOSTREAM */

#ifndef RWSTD_NO_NAMESPACE
}
#endif

