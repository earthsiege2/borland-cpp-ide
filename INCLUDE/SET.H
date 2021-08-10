#ifndef __SET_H
#define __SET_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_SET__
#define __STD_SET__

/***************************************************************************
 *
 * set - declarations for the Standard Library set class
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

#include <stdcomp.h>

#ifdef __BORLANDC__
#pragma option -w-inl
#endif

#include <memory>
#include <functional>
#include <rw/tree> 

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

//
// This is used in the implementation of set and multiset.
//

  template <class T, class U>
  struct __ident : public _RW_STD::unary_function<T, U>
  {
    const U& operator() (const T& x) const { return x; }
  };

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

//
// Note that _RWSTD_COMPLEX_DEFAULT(x)
// will expand to: ' = x', or nothing,
// depending on your compiler's capabilities and/or
// flag settings (see stdcomp.h).
//
  template <class Key, 
  class Compare _RWSTD_COMPLEX_DEFAULT(less<Key>), 
  class Allocator _RWSTD_COMPLEX_DEFAULT(allocator<Key>) >  
  class set
  {
  public:
    //
    // Types
    //
    typedef Key                key_type;
    typedef Key                value_type;
    typedef Compare            key_compare;
    typedef Compare            value_compare;
    typedef Allocator          allocator_type;

  private:
    
    typedef __RWSTD::__rb_tree<key_type, value_type, 
    __RWSTD::__ident<value_type, key_type>, 
    key_compare, allocator_type> __rep_type;
    __rep_type __t;

  public:
    //
    // Types
    //
    typedef _TYPENAME __rep_type::reference               reference;
    typedef _TYPENAME __rep_type::const_reference         const_reference;
    typedef _TYPENAME __rep_type::iterator                iterator;
    typedef _TYPENAME __rep_type::const_iterator          const_iterator;
    typedef _TYPENAME __rep_type::size_type               size_type;
    typedef _TYPENAME __rep_type::difference_type         difference_type;
    typedef _TYPENAME __rep_type::pointer                 pointer;
    typedef _TYPENAME __rep_type::const_pointer           const_pointer;
    typedef _TYPENAME __rep_type::reverse_iterator        reverse_iterator;
    typedef _TYPENAME __rep_type::const_reverse_iterator  const_reverse_iterator;

    //
    // construct/copy/destroy
    //
    _EXPLICIT set (const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
                   const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, false, alloc) {}

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    set () : __t(Compare(), false, Allocator()) {}

    _EXPLICIT set (const Compare& comp _RWSTD_DEFAULT_ARG(Compare())) : __t(comp, false, Allocator()) {}
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    set (InputIterator first, InputIterator last,
         const Compare& comp = Compare(),
         const Allocator& alloc = Allocator()) : __t(comp, false, alloc)
    {
      while (first != last) __t.insert(*first++);
    }
#else
    set (const value_type* first, const value_type* last,
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
         const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, false, alloc)
    {
      while (first != last) __t.insert(*first++);
    }
    
    set (const_iterator first, const_iterator last,
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
         const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, false, alloc)
    {
      while (first != last) __t.insert(*first++);
    }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    set (const value_type* first, const value_type* last) : __t(Compare(), false, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }
    
    set (const value_type* first, const value_type* last,
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare())) : __t(comp, false, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }
    
    set (const_iterator first, const_iterator last) : __t(Compare(), false, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }

    set (const_iterator first, const_iterator last,
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare())) : __t(comp, false, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }
#endif
#endif

    set (const set<Key, Compare, Allocator>& x) : __t(x.__t, false) {}
    set<Key, Compare, Allocator>& operator= (const set<Key, Compare, Allocator>& x)
    {
      __t = x.__t; return *this;
    }
    allocator_type get_allocator() const
    {
      return __t.get_allocator();
    }

    //
    // iterators
    //
    iterator                 begin  ()       { return __t.begin();  }
    const_iterator           begin  () const { return __t.begin();  }
    iterator                 end    ()       { return __t.end();    }
    const_iterator           end    () const { return __t.end();    }
    reverse_iterator         rbegin ()       { return __t.rbegin(); } 
    const_reverse_iterator   rbegin () const { return __t.rbegin(); } 
    reverse_iterator         rend   ()       { return __t.rend();   }
    const_reverse_iterator   rend   () const { return __t.rend();   }

    //
    // capacity
    //
    bool        empty    () const { return __t.empty();    }
    size_type   size     () const { return __t.size();     }
    size_type   max_size () const { return __t.max_size(); }

    //
    // modifiers
    //
#ifdef _RWSTD_NO_MEMBER_TYPE_TPARAM
    typedef _TYPENAME __rep_type::iterator t_iterator;
#endif
#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<iterator,bool> insert (const value_type& x)
#else
      typedef pair<iterator, bool> pair_iterator_bool;
      //
      // typedef done to get around compiler bug.
      //
      pair_iterator_bool insert (const value_type& x)
#endif
    {
#ifndef _RWSTD_NO_MEMBER_TYPE_TPARAM
      pair<_TYPENAME __rep_type::iterator, bool> p = __t.insert(x); 
#else
      pair<t_iterator,bool> p = __t.insert(x); 
#endif
      return pair<iterator, bool>(p.first, p.second);
    }
    iterator insert (iterator position, const value_type& x)
    {
      return __t.insert(_RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,position), x);
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      while (first != last) __t.insert(*first++);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
      while (first != last) __t.insert(*first++);
    }
    void insert (const_iterator first, const_iterator last)
    {
      while (first != last) __t.insert(*first++);
    }
#endif

    void erase (iterator position)
    {
      __t.erase(_RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,position));
    }
    size_type erase (const key_type& x)
    {
      return __t.erase(x); 
    }
    void erase (iterator first, iterator last)
    {
      __t.erase(_RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,first),
                       _RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,last));
    }
    void swap (set<Key, Compare, Allocator>& x) { __t.swap(x.__t); }
    void clear ()   { erase(begin(),end()); }

    //
    // observers
    //
    key_compare        key_comp   () const { return __t.key_comp(); }
    value_compare      value_comp () const { return __t.key_comp(); }

    //
    // set operations
    //
    iterator  find        (const key_type& x) const { return __t.find(x);       }
    size_type count       (const key_type& x) const { return __t.count(x);      }
    iterator  lower_bound (const key_type& x) const { return __t.lower_bound(x);}
    iterator  upper_bound (const key_type& x) const { return __t.upper_bound(x);}

#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range(const key_type& x) const
#else
      typedef  pair<iterator, iterator> pair_iterator_iterator;
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_iterator equal_range (const key_type& x) const
#endif
    {
      return __t.equal_range(x);
    }

#ifndef _RWSTD_STRICT_ANSI
    // Non-standard function for setting buffer allocation size
    size_type allocation_size() { return __t.allocation_size(); }
    size_type allocation_size(size_type new_size) 
    { 
      return __t.allocation_size(new_size);
    }
#endif  
  };

//
// Note that _RWSTD_COMPLEX_DEFAULT(x)
// will expand to: ' = x', or nothing,
// depending on your compiler's capabilities and/or
// flag settings (see stdcomp.h).
//
  template <class Key, 
  class Compare _RWSTD_COMPLEX_DEFAULT(less<Key>), 
  class Allocator _RWSTD_COMPLEX_DEFAULT(allocator<Key>) > 
  class multiset
  {
  public:
    //  
    // types
    //
    typedef Key       key_type;
    typedef Key       value_type;
    typedef Compare   key_compare;
    typedef Compare   value_compare;
    typedef Allocator allocator_type;
  private:
    
    typedef __RWSTD::__rb_tree<key_type, value_type, 
      __RWSTD::__ident<value_type, key_type>, 
      key_compare, allocator_type> __rep_type;
    __rep_type __t;

  public:
    //
    // types
    //
    typedef _TYPENAME __rep_type::reference               reference;
    typedef _TYPENAME __rep_type::const_reference         const_reference;
    typedef _TYPENAME __rep_type::iterator                iterator;
    typedef _TYPENAME __rep_type::const_iterator          const_iterator;
    typedef _TYPENAME __rep_type::size_type               size_type;
    typedef _TYPENAME __rep_type::difference_type         difference_type;
    typedef _TYPENAME __rep_type::pointer                 pointer;
    typedef _TYPENAME __rep_type::const_pointer           const_pointer;
    typedef _TYPENAME __rep_type::reverse_iterator        reverse_iterator;
    typedef _TYPENAME __rep_type::const_reverse_iterator  const_reverse_iterator;

    //
    // construct/copy/destroy
    //
    _EXPLICIT multiset (const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
                        const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, true, alloc) {}

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    _EXPLICIT multiset (void) : __t(Compare(), true, Allocator()) {}

    _EXPLICIT multiset (const Compare& comp _RWSTD_DEFAULT_ARG(Compare())) : __t(comp, true, Allocator()) {}
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    multiset (InputIterator first, InputIterator last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
              const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, true, alloc)
    {
      while (first != last) __t.insert(*first++);
    }
#else
    multiset (const value_type* first, const value_type* last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
              const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, true, alloc)
    {
      while (first != last) __t.insert(*first++);
    }
    multiset (const_iterator first, const_iterator last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
              const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) : __t(comp, true, alloc)
    {
      while (first != last) __t.insert(*first++);
    }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    multiset (const value_type* first, const value_type* last) : __t(Compare(), true, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }

    multiset (const value_type* first, const value_type* last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare())) : __t(comp, true, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }

    multiset (const_iterator first, const_iterator last) : __t(Compare(), true, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }

    multiset (const_iterator first, const_iterator last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare())) : __t(comp, true, Allocator())
    {
      while (first != last) __t.insert(*first++);
    }
#endif

#endif

    multiset (const multiset<Key, Compare, Allocator>& x) : __t(x.__t, true) {}
    multiset<Key, Compare, Allocator>& 
    operator= (const multiset<Key, Compare, Allocator>& x)
    {
      __t = x.__t; return *this;
    }
    allocator_type get_allocator() const
    {
      return __t.get_allocator();
    }

    //
    // iterators
    //
    iterator                 begin  ()       { return __t.begin();  }
    const_iterator           begin  () const { return __t.begin();  }
    iterator                 end    ()       { return __t.end();    }
    const_iterator           end    () const { return __t.end();    }
    reverse_iterator         rbegin ()       { return __t.rbegin(); } 
    const_reverse_iterator   rbegin () const { return __t.rbegin(); } 
    reverse_iterator         rend   ()       { return __t.rend();   }
    const_reverse_iterator   rend   () const { return __t.rend();   }

    //
    // capacity
    //
    bool       empty    () const { return __t.empty();    }
    size_type  size     () const { return __t.size();     }
    size_type  max_size () const { return __t.max_size(); }

    //
    // modifiers
    //
    iterator insert (const value_type& x) { return __t.insert(x).first; }
    iterator insert (iterator position, const value_type& x)
    {
      return __t.insert(_RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,position), x);
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      while (first != last) __t.insert(*first++);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
      while (first != last) __t.insert(*first++);
    }
    void insert (const_iterator first, const_iterator last)
    {
      while (first != last) __t.insert(*first++);
    }
#endif

    void erase (iterator position)
    {
      __t.erase(_RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,position));
    }
    size_type erase (const key_type& x) { return __t.erase(x); }
    void erase (iterator first, iterator last)
    {
      __t.erase(_RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,first),
                       _RWSTD_REINTERPRET_CAST(_TYPENAME __rep_type::iterator&,last)); 
    }
    void swap (multiset<Key, Compare, Allocator>& x) { __t.swap(x.__t); }
    void clear ()   { erase(begin(),end()); }

    //
    // observers
    //
    key_compare   key_comp   () const { return __t.key_comp(); }
    value_compare value_comp () const { return __t.key_comp(); }

    //
    // set operations
    //
    iterator  find        (const key_type& x) const { return __t.find(x);  }
    size_type count       (const key_type& x) const { return __t.count(x); }
    iterator  lower_bound (const key_type& x) const
    {
      return __t.lower_bound(x);
    }
    iterator  upper_bound (const key_type& x) const
    {
      return __t.upper_bound(x); 
    }
#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x) const
#else
      typedef  pair<iterator, iterator> pair_iterator_iterator; 
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_iterator equal_range (const key_type& x) const
#endif
    {
      return __t.equal_range(x);
    }

#ifndef _RWSTD_STRICT_ANSI
    // Non-standard function for setting buffer allocation size
    size_type allocation_size() { return __t.allocation_size(); }
    size_type allocation_size(size_type new_size) 
    { 
      return __t.allocation_size(new_size);
    }
#endif  
  };

  template <class Key, class Compare, class Allocator>
  inline bool operator== (const set<Key, Compare, Allocator>& x, 
                          const set<Key, Compare, Allocator>& y)
  {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator< (const set<Key, Compare, Allocator>& x, 
                         const set<Key, Compare, Allocator>& y)
  {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class Key, class Compare, class Allocator>
  inline bool operator!= (const set<Key,Compare,Allocator>& x, 
                          const set<Key,Compare,Allocator>& y)
  {
    return !(x == y);
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator> (const set<Key,Compare,Allocator>& x, 
                         const set<Key,Compare,Allocator>& y)
  {
    return y < x;
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator>= (const set<Key,Compare,Allocator>& x, 
                          const set<Key,Compare,Allocator>& y)
  {
    return !(x < y);
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator<= (const set<Key,Compare,Allocator>& x, 
                          const set<Key,Compare,Allocator>& y)
  {
    return !(y <  x);
  }

  template <class Key, class Compare, class Allocator>
  void swap(set<Key,Compare,Allocator>& a, 
            set<Key,Compare,Allocator>& b)
  {
    a.swap(b);
  }
#endif

  template <class Key, class Compare, class Allocator>
  inline bool operator== (const multiset<Key, Compare, Allocator>& x, 
                          const multiset<Key, Compare, Allocator>& y)
  {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator< (const multiset<Key, Compare, Allocator>& x, 
                         const multiset<Key, Compare, Allocator>& y)
  {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class Key, class Compare, class Allocator>
  inline bool operator!= (const multiset<Key,Compare,Allocator>& x, 
                          const multiset<Key,Compare,Allocator>& y)
  {
    return !(x == y);
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator> (const multiset<Key,Compare,Allocator>& x, 
                         const multiset<Key,Compare,Allocator>& y)
  {
    return y < x;
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator>= (const multiset<Key,Compare,Allocator>& x, 
                          const multiset<Key,Compare,Allocator>& y)
  {
    return !(x < y);
  }

  template <class Key, class Compare, class Allocator>
  inline bool operator<= (const multiset<Key,Compare,Allocator>& x, 
                          const multiset<Key,Compare,Allocator>& y)
  {
    return !(y <  x);
  }

  template <class Key, class Compare, class Allocator>
  void swap(multiset<Key,Compare,Allocator>& a, 
            multiset<Key,Compare,Allocator>& b)
  {
    a.swap(b);
  }
#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __SET_H */
