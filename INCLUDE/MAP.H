#ifndef __MAP_H
#define __MAP_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_MAP__
#define __STD_MAP__

/***************************************************************************
 *
 * map - declarations for the Standard Library map class
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
// This is used in the implementation of map and multimap.
//

  template <class T, class U>
  struct __select1st : public _RW_STD::unary_function<T, U>
  {
    const U& operator() (const T& x) const { return x.first; }
  };

#ifndef _RWSTD_NO_NAMESPACE
}

namespace std {
#endif

//
// First the map stuff.
//
  
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES  
  template <class Key, class T, class Compare = less<Key>, 
#ifndef _RWSTD_NO_CONST_INST
  class Allocator = allocator<pair<const Key,T> > >
#else
  class Allocator = allocator<pair<Key,T> > >
#endif // _RWSTD_NO_CONST_INST
#else
  template <class Key, class T, class Compare, class Allocator>
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  class map
  {
  public:
    //
    // types
    //
    typedef Key                key_type;
    typedef T                  mapped_type;
#ifndef _RWSTD_NO_CONST_INST
    typedef pair<const Key, T> value_type;
#else
    typedef pair<Key, T>       value_type;
#endif
    typedef Compare            key_compare;
    typedef Allocator          allocator_type;
    
  private:
    
    typedef __RWSTD::__rb_tree<key_type, value_type,
      __RWSTD::__select1st<value_type, key_type>, 
      key_compare, allocator_type> __rep_type;
    __rep_type __t;

  public:
    //
    // types
    //
    typedef _TYPENAME __rep_type::reference                reference;
    typedef _TYPENAME __rep_type::const_reference          const_reference;
    typedef _TYPENAME __rep_type::iterator                 iterator;
    typedef _TYPENAME __rep_type::const_iterator           const_iterator;
    typedef _TYPENAME __rep_type::size_type                size_type;
    typedef _TYPENAME __rep_type::difference_type          difference_type;
    typedef _TYPENAME __rep_type::pointer                  pointer;
    typedef _TYPENAME __rep_type::const_pointer            const_pointer;
    typedef _TYPENAME __rep_type::reverse_iterator         reverse_iterator;
    typedef _TYPENAME __rep_type::const_reverse_iterator   const_reverse_iterator;

    class value_compare : public binary_function<value_type, value_type, bool>
    {
      friend class map<Key, T, Compare, Allocator>;
    protected:
      Compare comp;
      value_compare (Compare c) : comp(c) {}
    public:
      bool operator() (const value_type& x, const value_type& y) const
      {
        return comp(x.first, y.first);
      }
    };
    //
    // construct/copy/destroy
    //
    _EXPLICIT map (const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
                   const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) 
      : __t(comp, false, alloc) {}

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    map (void) 
      : __t(Compare(), false, Allocator()) {}

    _EXPLICIT map (const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(comp, false, Allocator()) {}
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    map (InputIterator first, InputIterator last, 
         const Compare& comp = Compare(),
         const Allocator& alloc = Allocator())
      : __t(first, last, comp, false, alloc) {}
#else
    map (const value_type* first, const value_type* last, 
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
         const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __t(first, last, comp, false, alloc) {}
    map (iterator first, iterator last, 
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
         const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __t(first, last, comp, false, alloc) {}
    map (const_iterator first, const_iterator last, 
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
         const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __t(first, last, comp, false, alloc) {}
#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    map (const value_type* first, const value_type* last)
      : __t(first, last, Compare(), false, Allocator()) {}
    map (const value_type* first, const value_type* last, 
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(first, last, comp, false, Allocator()) {}

    map (iterator first, iterator last)
      : __t(first, last, Compare(), false, Allocator()) {}
    map (iterator first, iterator last, 
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(first, last, comp, false, Allocator()) {}

    map (const_iterator first, const_iterator last) : __t(first, last, Compare(), false, Allocator()) {}
    map (const_iterator first, const_iterator last, 
         const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(first, last, comp, false, Allocator()) {}
#endif
#endif

    map (const map<Key, T, Compare, Allocator>& x) : __t(x.__t, false) {}
    map<Key, T, Compare, Allocator>& 
    operator= (const map<Key, T, Compare, Allocator>& x)
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

    iterator               begin  ()       { return __t.begin();  }
    const_iterator         begin  () const { return __t.begin();  }
    iterator               end    ()       { return __t.end();    }
    const_iterator         end    () const { return __t.end();    }
    reverse_iterator       rbegin ()       { return __t.rbegin(); }
    const_reverse_iterator rbegin () const { return __t.rbegin(); }
    reverse_iterator       rend   ()       { return __t.rend();   }
    const_reverse_iterator rend   () const { return __t.rend();   }

    //
    // capacity
    //
    bool      empty    () const { return __t.empty();    }
    size_type size     () const { return __t.size();     }
    size_type max_size () const { return __t.max_size(); }

    //
    // element access
    //
    mapped_type& operator[] (const key_type& k)
    {
      value_type tmp(k,T()); return (*((insert(tmp)).first)).second;
    }

#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<iterator,bool> insert (const value_type& x) { return __t.insert(x); }
#else
    typedef pair<iterator, bool> pair_iterator_bool; 
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_bool insert (const value_type& x) { return __t.insert(x); }
#endif
    iterator insert (iterator position, const value_type& x)
    {
      return __t.insert(position, x);
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      __t.insert(first, last);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
      __t.insert(first, last);
    }
    void insert (iterator first, iterator last)
    {
      __t.insert(first, last);
    }
    void insert (const_iterator first, const_iterator last)
    {
      __t.insert(first, last);
    }
#endif

    void  erase (iterator position)             { __t.erase(position);}
    size_type erase (const key_type& x)         { return __t.erase(x); }
    void  erase (iterator first, iterator last) { __t.erase(first,last);}
    void      swap  (map<Key, T, Compare, Allocator>& x)       
    { __t.swap(x.__t);          }
    void      clear ()                              { erase(begin(),end()); }

    //
    // observers
    //
    key_compare key_comp () const { return __t.key_comp(); }
    value_compare value_comp () const { return value_compare(__t.key_comp()); }

    //
    // map operations
    //
    iterator     find (const key_type& x)        { return __t.find(x);}
    const_iterator find (const key_type& x)  const { return __t.find(x); }
    size_type    count (const key_type& x) const { return __t.count(x); }
    iterator     lower_bound (const key_type& x) { return __t.lower_bound(x); }
    iterator     upper_bound (const key_type& x) { return __t.upper_bound(x); }
    const_iterator lower_bound (const key_type& x) const
    {
      return __t.lower_bound(x); 
    }
    const_iterator upper_bound (const key_type& x) const
    {
      return __t.upper_bound(x); 
    }
#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x)
#else
      typedef pair<iterator, iterator> pair_iterator_iterator; 
      //
      // typedef done to get around compiler bug
      //
      pair_iterator_iterator equal_range (const key_type& x)
#endif
    {
      return __t.equal_range(x);
    }
#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<const_iterator, const_iterator> equal_range (const key_type& x) const
#else
      typedef pair<const_iterator, const_iterator> pair_citerator_citerator; 
    //
    // typedef done to get around compiler bug
    //
    pair_citerator_citerator equal_range (const key_type& x) const
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

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES  
  template <class Key, class T, class Compare = less<Key>, 
#ifndef _RWSTD_NO_CONST_INST
  class Allocator = allocator<pair<const Key,T> > >
#else
  class Allocator = allocator<pair<Key,T> > >
#endif // _RWSTD_NO_CONST_INST
#else
  template <class Key, class T, class Compare, class Allocator>
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  class multimap
  {
  public:
    //
    // types
    //
    typedef Key                  key_type;
    typedef T                    mapped_type;
#ifndef _RWSTD_NO_CONST_INST
    typedef pair<const Key, T>   value_type;
#else
    typedef pair<Key, T>         value_type;
#endif
    typedef Compare              key_compare;
    typedef Allocator            allocator_type;

  private:
    
    typedef __RWSTD::__rb_tree<key_type, value_type, 
    __RWSTD::__select1st<value_type, key_type>, 
    key_compare, allocator_type> __rep_type;
    __rep_type __t;

  public:
    //
    // types
    //
    typedef _TYPENAME __rep_type::reference                reference;
    typedef _TYPENAME __rep_type::const_reference          const_reference;
    typedef _TYPENAME __rep_type::iterator                 iterator;
    typedef _TYPENAME __rep_type::const_iterator           const_iterator; 
    typedef _TYPENAME __rep_type::size_type                size_type;
    typedef _TYPENAME __rep_type::difference_type          difference_type;
    typedef _TYPENAME __rep_type::pointer                  pointer;
    typedef _TYPENAME __rep_type::const_pointer            const_pointer; 
    typedef _TYPENAME __rep_type::reverse_iterator         reverse_iterator;
    typedef _TYPENAME __rep_type::const_reverse_iterator   const_reverse_iterator;

    class value_compare : public binary_function<value_type, value_type, bool>
    {
      friend class multimap<Key, T, Compare, Allocator>;
    protected:
      Compare comp;
      value_compare (Compare c) : comp(c) {}
    public:
      bool operator() (const value_type& x, const value_type& y) const
      {
        return comp(x.first, y.first);
      }
    };

    //
    // construct/copy/destroy
    //
    _EXPLICIT multimap (const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
                        const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator())) 
      : __t(comp, true, alloc) { }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    multimap (void) 
      : t(Compare(), true, Allocator()) { }
    _EXPLICIT multimap (const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(comp, true, Allocator()) { }
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    multimap (InputIterator first, InputIterator last, 
              const Compare& comp = Compare(),
              const Allocator& alloc = Allocator()) 
      : __t(first, last, comp, true, alloc) { }
#else
    multimap (const value_type* first, const value_type* last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
              const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __t(first, last, comp, true, alloc) { }
    multimap (iterator first, iterator last,
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
              const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __t(first, last, comp, true, alloc) { }
    multimap (const_iterator first, const_iterator last,
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()),
              const Allocator& alloc _RWSTD_DEFAULT_ARG(Allocator()))
      : __t(first, last, comp, true, alloc) { }
#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    multimap (const value_type* first, const value_type* last)
      : __t(first, last, Compare(), true, Allocator()) { }
    multimap (const value_type* first, const value_type* last, 
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(first, last, comp, true, Allocator()) { }

    multimap (iterator first, iterator last)
      : __t(first, last, Compare(), true, Allocator()) { }
    multimap (iterator first, iterator last,
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(first, last, comp, true, Allocator()) { }

    multimap (const_iterator first, const_iterator last)
      : __t(first, last, Compare(), true, Allocator()) { }
    multimap (const_iterator first, const_iterator last,
              const Compare& comp _RWSTD_DEFAULT_ARG(Compare()))
      : __t(first, last, comp, true, Allocator()) { }
#endif
#endif

    multimap (const multimap<Key, T, Compare, Allocator>& x) : __t(x.__t, true) { }
    multimap<Key, T, Compare, Allocator>& 
    operator= (const multimap<Key, T, Compare, Allocator>& x)
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
    bool        empty   () const { return __t.empty();    }
    size_type   size    () const { return __t.size();     }
    size_type   max_size() const { return __t.max_size(); }

    //
    // modifiers
    //
    iterator insert (const value_type& x) { return __t.insert(x).first; }
    iterator insert (iterator position, const value_type& x)
    {
      return __t.insert(position, x);
    }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
      __t.insert(first, last);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
      __t.insert(first, last);
    }
    void insert (iterator first, iterator last)
    {
      __t.insert(first, last);
    }
    void insert (const_iterator first, const_iterator last)
    {
      __t.insert(first, last);
    }
#endif

    void  erase (iterator position)             { __t.erase(position); }
    size_type erase (const key_type& x)         { return __t.erase(x);    }
    void  erase (iterator first, iterator last) { __t.erase(first, last); }
    void      clear ()                          { erase(begin(),end()); }
    void      swap  (multimap<Key, T, Compare, Allocator>& x)  
    { __t.swap(x.__t);          }

    //
    // observers
    //
    key_compare   key_comp   () const { return __t.key_comp();                }
    value_compare value_comp () const { return value_compare(__t.key_comp()); }

    //
    // map operations
    //
    iterator    find (const key_type& x)        { return __t.find(x); }
    const_iterator  find (const key_type& x)  const { return __t.find(x); }
    size_type   count (const key_type& x) const { return __t.count(x); }
    iterator    lower_bound (const key_type& x) {return __t.lower_bound(x);}
    iterator    upper_bound (const key_type& x) {return __t.upper_bound(x);}
    const_iterator  lower_bound (const key_type& x) const
    {
      return __t.lower_bound(x); 
    }
    const_iterator  upper_bound (const key_type& x) const
    {
      return __t.upper_bound(x); 
    }
#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x)
#else
      typedef  pair<iterator, iterator> pair_iterator_iterator; 
      //
      // typedef done to get around compiler bug
      //
      pair_iterator_iterator equal_range (const key_type& x)
#endif
    {
      return __t.equal_range(x);
    }
#ifndef _RWSTD_NO_RET_TEMPLATE
    pair<const_iterator,const_iterator> equal_range (const key_type& x) const
#else
      typedef  pair<const_iterator, const_iterator> pair_citerator_citerator; 
    //
    // typedef done to get around compiler bug
    //
    pair_citerator_citerator equal_range (const key_type& x) const
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

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator== (const map<Key, T, Compare, Allocator>& x,
                          const map<Key, T, Compare, Allocator>& y)
  {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator< (const map<Key, T, Compare, Allocator>& x, 
                         const map<Key, T, Compare, Allocator>& y)
  {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class Key, class T, class Compare, class Allocator>
  inline bool operator!= (const map<Key,T,Compare,Allocator>& x, 
                          const map<Key,T,Compare,Allocator>& y)
  {
    return !(x == y);
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator> (const map<Key,T,Compare,Allocator>& x, 
                         const map<Key,T,Compare,Allocator>& y)
  {
    return y < x;
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator>= (const map<Key,T,Compare,Allocator>& x, 
                          const map<Key,T,Compare,Allocator>& y)
  {
    return !(x < y);
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator<= (const map<Key,T,Compare,Allocator>& x, 
                          const map<Key,T,Compare,Allocator>& y)
  {
    return !(y <  x);
  }

  template <class Key, class T, class Compare, class Allocator>
  void swap(map<Key,T,Compare,Allocator>& a, 
            map<Key,T,Compare,Allocator>& b)
  {
    a.swap(b);
  }
#endif

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator== (const multimap<Key, T, Compare, Allocator>& x, 
                          const multimap<Key, T, Compare, Allocator>& y)
  {
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator< (const multimap<Key, T, Compare, Allocator>& x, 
                         const multimap<Key, T, Compare, Allocator>& y)
  {
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class Key, class T, class Compare, class Allocator>
  inline bool operator!= (const multimap<Key,T,Compare,Allocator>& x, 
                          const multimap<Key,T,Compare,Allocator>& y)
  {
    return !(x == y);
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator> (const multimap<Key,T,Compare,Allocator>& x, 
                         const multimap<Key,T,Compare,Allocator>& y)
  {
    return y < x;
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator>= (const multimap<Key,T,Compare,Allocator>& x, 
                          const multimap<Key,T,Compare,Allocator>& y)
  {
    return !(x < y);
  }

  template <class Key, class T, class Compare, class Allocator>
  inline bool operator<= (const multimap<Key,T,Compare,Allocator>& x, 
                          const multimap<Key,T,Compare,Allocator>& y)
  {
    return !(y <  x);
  }

  template <class Key, class T, class Compare, class Allocator>
  void swap(multimap<Key,T,Compare,Allocator>& a, 
            multimap<Key,T,Compare,Allocator>& b)
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
#endif /* __MAP_H */
