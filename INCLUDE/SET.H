#ifndef __STD_SET__
#define __STD_SET__

/***************************************************************************
 *
 * set - declarations for the Standard Library set class
 *
 * $Id: set,v 1.26 1995/09/15 20:48:58 smithey Exp $
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

#include <stdcomp.h>

#ifndef Allocator
#define Allocator allocator
#include <memory>
#endif

#ifdef __BORLANDC__
#pragma warn -inl
#endif

#include <tree>

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// This is used in the implementation of set and multiset.
//

template <class T, class U>
struct ident : public unary_function<T, U>
{
    const U& operator() (const T& x) const { return x; }
};
  
#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template<class Key, class Compare = less<Key> >
#else
template <class Key, class Compare>
#endif
class set
{
  public:
    //
    // Types
    //
    typedef Key                                        key_type;
    typedef Key                                        value_type;
    typedef Compare                                    key_compare;
    typedef Compare                                    value_compare;

  private:
    
    typedef rb_tree<key_type, value_type, 
                    ident<value_type, key_type>, key_compare> rep_type;
    rep_type t;

  public:
    //
    // Types
    //
    typedef typename rep_type::const_reference         reference;
    typedef typename rep_type::const_reference         const_reference;
    typedef typename rep_type::const_iterator          iterator;
    typedef typename rep_type::const_iterator          const_iterator;
    typedef typename rep_type::size_type               size_type;
    typedef typename rep_type::difference_type         difference_type;
    typedef typename rep_type::reverse_iterator        reverse_iterator;
    typedef typename rep_type::const_reverse_iterator  const_reverse_iterator;
    //
    // construct/copy/destroy
    //
    explicit set (const Compare& comp = Compare()) : t(comp, false) {}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    set (InputIterator first, InputIterator last,
         const Compare& comp = Compare()) : t(comp, false)
    {
        while (first != last) t.insert(*first++);
    }
#else
    set (const value_type* first, const value_type* last,
         const Compare& comp = Compare()) : t(comp, false)
    {
        while (first != last) t.insert(*first++);
    }
    set (const_iterator first, const_iterator last,
         const Compare& comp = Compare()) : t(comp, false)
    {
        while (first != last) t.insert(*first++);
    }
#endif

    set (const set<Key, Compare>& x) : t(x.t, false) {}
    set<Key, Compare>& operator= (const set<Key, Compare>& x)
    {
          t = x.t; return *this;
    }
    //
    // iterators
    //
    iterator                 begin  ()       { return t.begin();  }
    const_iterator           begin  () const { return t.begin();  }
    iterator                 end    ()       { return t.end();    }
    const_iterator           end    () const { return t.end();    }
    reverse_iterator         rbegin ()       { return t.rbegin(); } 
    const_reverse_iterator   rbegin () const { return t.rbegin(); } 
    reverse_iterator         rend   ()       { return t.rend();   }
    const_reverse_iterator   rend   () const { return t.rend();   }
    //
    // capacity
    //
    bool        empty    () const { return t.empty();    }
    size_type   size     () const { return t.size();     }
    size_type   max_size () const { return t.max_size(); }
    //
    // modifiers
    //
#ifdef RWSTD_NO_MEMBER_TYPE_TPARAM
    typedef typename rep_type::iterator t_iterator;
#endif
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,bool> insert (const value_type& x)
#else
    typedef pair<iterator, bool> pair_iterator_bool;
    //
    // typedef done to get around compiler bug.
    //
    pair_iterator_bool insert (const value_type& x)
#endif
    {
#ifndef RWSTD_NO_MEMBER_TYPE_TPARAM
        pair<typename rep_type::iterator, bool> p = t.insert(x); 
#else
        pair<t_iterator,bool> p = t.insert(x); 
#endif
        return pair<iterator, bool>(p.first, p.second);
    }
    iterator insert (iterator position, const value_type& x)
    {
        return t.insert((typename rep_type::iterator&)position, x);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        while (first != last) t.insert(*first++);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
        while (first != last) t.insert(*first++);
    }
    void insert (const_iterator first, const_iterator last)
    {
        while (first != last) t.insert(*first++);
    }
#endif

    void erase (iterator position)
    {
        t.erase((typename rep_type::iterator&)position);
    }
    size_type erase (const key_type& x)
    {
        return t.erase(x); 
    }
    void erase (iterator first, iterator last)
    {
        t.erase((typename rep_type::iterator&)first,
                (typename rep_type::iterator&)last);
    }
    void swap (set<Key, Compare>& x) { t.swap(x.t); }
    //
    // observers
    //
    key_compare        key_comp   () const { return t.key_comp(); }
    value_compare      value_comp () const { return t.key_comp(); }
    //
    // set operations
    //
    iterator  find        (const key_type& x) const { return t.find(x);       }
    size_type count       (const key_type& x) const { return t.count(x);      }
    iterator  lower_bound (const key_type& x) const { return t.lower_bound(x);}
    iterator  upper_bound (const key_type& x) const { return t.upper_bound(x);}

#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range(const key_type& x) const
#else
    typedef  pair<iterator, iterator> pair_iterator_iterator;
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_iterator equal_range (const key_type& x) const
#endif
    {
        return t.equal_range(x);
    }
};

#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template<class Key, class Compare = less<Key> >
#else
template <class Key, class Compare>
#endif
class multiset
{
  public:
    //  
    // types
    //
    typedef Key      key_type;
    typedef Key      value_type;
    typedef Compare  key_compare;
    typedef Compare  value_compare;

  private:
    
    typedef rb_tree<key_type, value_type, 
                    ident<value_type, key_type>, key_compare> rep_type;
    rep_type t;

  public:
    //
    // types
    //
    typedef typename rep_type::const_reference         reference;
    typedef typename rep_type::const_reference         const_reference;
    typedef typename rep_type::const_iterator          iterator;
    typedef typename rep_type::const_iterator          const_iterator;
    typedef typename rep_type::size_type               size_type;
    typedef typename rep_type::difference_type         difference_type;
    typedef typename rep_type::reverse_iterator        reverse_iterator;
    typedef typename rep_type::const_reverse_iterator  const_reverse_iterator;
    //
    // construct/copy/destroy
    //
    explicit multiset (const Compare& comp = Compare()) : t(comp, true) {}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    multiset (InputIterator first, InputIterator last, 
              const Compare& comp = Compare()) : t(comp, true)
    {
        while (first != last) t.insert(*first++);
    }
#else
    multiset (const value_type* first, const value_type* last, 
              const Compare& comp = Compare()) : t(comp, true)
    {
        while (first != last) t.insert(*first++);
    }
    multiset (const_iterator first, const_iterator last, 
              const Compare& comp = Compare()) : t(comp, true)
    {
        while (first != last) t.insert(*first++);
    }
#endif

    multiset (const multiset<Key, Compare>& x) : t(x.t, true) {}
    multiset<Key, Compare>& operator= (const multiset<Key, Compare>& x)
    {
        t = x.t; return *this;
    }
    //
    // iterators
    //
    iterator                 begin  ()       { return t.begin();  }
    const_iterator           begin  () const { return t.begin();  }
    iterator                 end    ()       { return t.end();    }
    const_iterator           end    () const { return t.end();    }
    reverse_iterator         rbegin ()       { return t.rbegin(); } 
    const_reverse_iterator   rbegin () const { return t.rbegin(); } 
    reverse_iterator         rend   ()       { return t.rend();   }
    const_reverse_iterator   rend   () const { return t.rend();   }

    //
    // capacity
    //
    bool       empty    () const { return t.empty();    }
    size_type  size     () const { return t.size();     }
    size_type  max_size () const { return t.max_size(); }
    //
    // modifiers
    //
    iterator insert (const value_type& x) { return t.insert(x).first; }
    iterator insert (iterator position, const value_type& x)
    {
        return t.insert((typename rep_type::iterator&)position, x);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        while (first != last) t.insert(*first++);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
        while (first != last) t.insert(*first++);
    }
    void insert (const_iterator first, const_iterator last)
    {
        while (first != last) t.insert(*first++);
    }
#endif

    void erase (iterator position)
    {
        t.erase((typename rep_type::iterator&)position);
    }
    size_type erase (const key_type& x) { return t.erase(x); }
    void erase (iterator first, iterator last)
    {
        t.erase((typename rep_type::iterator&)first,
                (typename rep_type::iterator&)last); 
    }
    void swap (multiset<Key, Compare>& x) { t.swap(x.t); }
    //
    // observers
    //
    key_compare   key_comp   () const { return t.key_comp(); }
    value_compare value_comp () const { return t.key_comp(); }
    //
    // set operations
    //
    iterator  find        (const key_type& x) const { return t.find(x);  }
    size_type count       (const key_type& x) const { return t.count(x); }
    iterator  lower_bound (const key_type& x) const
    {
        return t.lower_bound(x);
    }
    iterator  upper_bound (const key_type& x) const
    {
        return t.upper_bound(x); 
    }
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x) const
#else
    typedef  pair<iterator, iterator> pair_iterator_iterator; 
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_iterator equal_range (const key_type& x) const
#endif
    {
        return t.equal_range(x);
    }
};

template <class Key, class Compare>
inline bool operator== (const set<Key, Compare>& x, const set<Key, Compare>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class Key, class Compare>
inline bool operator< (const set<Key, Compare>& x, const set<Key, Compare>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Key, class Compare>
inline bool operator== (const multiset<Key, Compare>& x, 
                        const multiset<Key, Compare>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class Key, class Compare>
inline bool operator< (const multiset<Key, Compare>& x, 
                       const multiset<Key, Compare>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#undef Allocator

#endif
