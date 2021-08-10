#ifndef __STD_MAP__
#define __STD_MAP__

/***************************************************************************
 *
 * map - declarations for the Standard Library map class
 *
 * $Id: map,v 1.31 1995/08/23 23:54:42 lijewski Exp $
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
// This is used in the implementation of map and multimap.
//

template <class T, class U>
struct select1st : public unary_function<T, U>
{
    const U& operator() (const T& x) const { return x.first; }
};

//
// First the map stuff.
//
  
#ifndef RWSTD_NO_DEFAULT_TEMPLATES
template<class Key, class T, class Compare = less<Key> >
#else
template<class Key, class T, class Compare>
#endif /* RWSTD_NO_DEFAULT_TEMPLATES */
class map
{
  public:
    //
    // types
    //
    typedef Key                key_type;
#ifndef RWSTD_NO_CONST_INST
    typedef pair<const Key, T> value_type;
#else
    typedef pair<Key, T>       value_type;
#endif
    typedef Compare            key_compare;
    
    class value_compare : public binary_function<value_type, value_type, bool>
    {
        friend class map<Key, T, Compare>;
      protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}
      public:
        bool operator() (const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
    };

  private:
    
    typedef rb_tree<key_type, value_type,
                    select1st<value_type, key_type>, key_compare> rep_type;
    rep_type t;

  public:
    //
    // types
    //
    typedef typename rep_type::reference                reference;
    typedef typename rep_type::const_reference          const_reference;
    typedef typename rep_type::iterator                 iterator;
    typedef typename rep_type::const_iterator           const_iterator;
    typedef typename rep_type::size_type                size_type;
    typedef typename rep_type::difference_type          difference_type;
    typedef typename rep_type::reverse_iterator         reverse_iterator;
    typedef typename rep_type::const_reverse_iterator   const_reverse_iterator;
    //
    // construct/copy/destroy
    //
    explicit map (const Compare& comp = Compare()) : t(comp, false) {}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    map (InputIterator first, InputIterator last, 
         const Compare& comp = Compare()) : t(first, last, comp, false) {}
#else
    map (const value_type* first, const value_type* last, 
         const Compare& comp = Compare()) : t(first, last, comp, false) {}
    map (iterator first, iterator last, 
         const Compare& comp = Compare()) : t(first, last, comp, false) {}
    map (const_iterator first, const_iterator last, 
         const Compare& comp = Compare()) : t(first, last, comp, false) {}
#endif

    map (const map<Key, T, Compare>& x) : t(x.t, false) {}
    map<Key, T, Compare>& operator= (const map<Key, T, Compare>& x)
    {
          t = x.t; return *this; 
    }
    //
    // iterators
    //

    iterator               begin  ()       { return t.begin();  }
    const_iterator         begin  () const { return t.begin();  }
    iterator               end    ()       { return t.end();    }
    const_iterator         end    () const { return t.end();    }
    reverse_iterator       rbegin ()       { return t.rbegin(); }
    const_reverse_iterator rbegin () const { return t.rbegin(); }
    reverse_iterator       rend   ()       { return t.rend();   }
    const_reverse_iterator rend   () const { return t.rend();   }
    //
    // capacity
    //
    bool      empty    () const { return t.empty();    }
    size_type size     () const { return t.size();     }
    size_type max_size () const { return t.max_size(); }
    //
    // element access
    //
    T& operator[] (const key_type& k)
    {
        value_type tmp(k,T()); return (*((insert(tmp)).first)).second;
    }
    //
    // TODO - fix this once required functionality is specified by WP!!!
    //
    //const T& operator[] (const key_type& k) const
    //{
    //    value_type tmp(k,T()); return (*((insert(tmp)).first)).second;
    //}
    //
    // modifiers
    //
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,bool> insert (const value_type& x) { return t.insert(x); }
#else
    typedef pair<iterator, bool> pair_iterator_bool; 
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_bool insert (const value_type& x) { return t.insert(x); }
#endif
    iterator insert (iterator position, const value_type& x)
    {
        return t.insert(position, x);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        t.insert(first, last);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
        t.insert(first, last);
    }
    void insert (iterator first, iterator last)
    {
        t.insert(first, last);
    }
    void insert (const_iterator first, const_iterator last)
    {
        t.insert(first, last);
    }
#endif

    void      erase (iterator position)             { t.erase(position);    }
    size_type erase (const key_type& x)             { return t.erase(x);    }
    void      erase (iterator first, iterator last) { t.erase(first, last); }
    void      swap  (map<Key, T, Compare>& x)       { t.swap(x.t);          }
    //
    // observers
    //
    key_compare key_comp () const { return t.key_comp(); }
    value_compare value_comp () const { return value_compare(t.key_comp()); }
    //
    // map operations
    //
    iterator       find (const key_type& x)        { return t.find(x);        }
    const_iterator find (const key_type& x)  const { return t.find(x);        }
    size_type      count (const key_type& x) const { return t.count(x);       }
    iterator       lower_bound (const key_type& x) { return t.lower_bound(x); }
    iterator       upper_bound (const key_type& x) { return t.upper_bound(x); }
    const_iterator lower_bound (const key_type& x) const
    {
        return t.lower_bound(x); 
    }
    const_iterator upper_bound (const key_type& x) const
    {
        return t.upper_bound(x); 
    }
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x)
#else
    typedef pair<iterator, iterator> pair_iterator_iterator; 
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_iterator equal_range (const key_type& x)
#endif
    {
        return t.equal_range(x);
    }
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<const_iterator, const_iterator> equal_range (const key_type& x) const
#else
    typedef pair<const_iterator, const_iterator> pair_citerator_citerator; 
    //
    // typedef done to get around compiler bug
    //
    pair_citerator_citerator equal_range (const key_type& x) const
#endif
    {
        return t.equal_range(x);
    }
};

template <class Key, class T, class Compare>
class multimap
{
  public:
    //
    // types
    //
    typedef Key                  key_type;
#ifndef RWSTD_NO_CONST_INST
    typedef pair<const Key, T>   value_type;
#else
    typedef pair<Key, T>         value_type;
#endif
    typedef Compare              key_compare;

    class value_compare : public binary_function<value_type, value_type, bool>
    {
        friend class multimap<Key, T, Compare>;
      protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}
      public:
        bool operator() (const value_type& x, const value_type& y) const
        {
            return comp(x.first, y.first);
        }
    };

  private:
    
    typedef rb_tree<key_type, value_type, 
                    select1st<value_type, key_type>, key_compare> rep_type;
    rep_type t;

  public:
    //
    // types
    //
    typedef typename rep_type::reference                reference;
    typedef typename rep_type::const_reference          const_reference;
    typedef typename rep_type::iterator                 iterator;
    typedef typename rep_type::const_iterator           const_iterator; 
    typedef typename rep_type::size_type                size_type;
    typedef typename rep_type::difference_type          difference_type;
    typedef typename rep_type::reverse_iterator         reverse_iterator;
    typedef typename rep_type::const_reverse_iterator   const_reverse_iterator;
    //
    // construct/copy/destroy
    //
    explicit multimap (const Compare& comp = Compare()) : t(comp, true) { }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    multimap (InputIterator first, InputIterator last, 
              const Compare& comp = Compare()) : t(first, last, comp, true) { }
#else
    multimap (const value_type* first, const value_type* last, 
              const Compare& comp = Compare()) : t(first, last, comp, true) { }
    multimap (iterator first, iterator last,
              const Compare& comp = Compare()) : t(first, last, comp, true) { }
    multimap (const_iterator first, const_iterator last,
              const Compare& comp = Compare()) : t(first, last, comp,true) { }
#endif

    multimap (const multimap<Key, T, Compare>& x) : t(x.t, true) { }
    multimap<Key, T, Compare>& operator= (const multimap<Key, T, Compare>& x)
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
    bool        empty   () const { return t.empty();    }
    size_type   size    () const { return t.size();     }
    size_type   max_size() const { return t.max_size(); }
    //
    // modifiers
    //
    iterator insert (const value_type& x) { return t.insert(x).first; }
    iterator insert (iterator position, const value_type& x)
    {
        return t.insert(position, x);
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    void insert (InputIterator first, InputIterator last)
    {
        t.insert(first, last);
    }
#else
    void insert (const value_type* first, const value_type* last)
    {
        t.insert(first, last);
    }
    void insert (iterator first, iterator last)
    {
        t.insert(first, last);
    }
    void insert (const_iterator first, const_iterator last)
    {
        t.insert(first, last);
    }
#endif

    void      erase (iterator position)             { t.erase(position);    }
    size_type erase (const key_type& x)             { return t.erase(x);    }
    void      erase (iterator first, iterator last) { t.erase(first, last); }
    void      swap  (multimap<Key, T, Compare>& x)  { t.swap(x.t);          }
    //
    // observers
    //
    key_compare   key_comp   () const { return t.key_comp();                }
    value_compare value_comp () const { return value_compare(t.key_comp()); }
    //
    // map operations
    //
    iterator        find (const key_type& x)        { return t.find(x);      }
    const_iterator  find (const key_type& x)  const { return t.find(x);      }
    size_type       count (const key_type& x) const { return t.count(x);     }
    iterator        lower_bound (const key_type& x) {return t.lower_bound(x);}
    iterator        upper_bound (const key_type& x) {return t.upper_bound(x);}
    const_iterator  lower_bound (const key_type& x) const
    {
        return t.lower_bound(x); 
    }
    const_iterator  upper_bound (const key_type& x) const
    {
        return t.upper_bound(x); 
    }
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x)
#else
    typedef  pair<iterator, iterator> pair_iterator_iterator; 
    //
    // typedef done to get around compiler bug
    //
    pair_iterator_iterator equal_range (const key_type& x)
#endif
    {
        return t.equal_range(x);
    }
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<const_iterator,const_iterator> equal_range (const key_type& x) const
#else
    typedef  pair<const_iterator, const_iterator> pair_citerator_citerator; 
    //
    // typedef done to get around compiler bug
    //
    pair_citerator_citerator equal_range (const key_type& x) const
#endif
    {
        return t.equal_range(x);
    }
};

template <class Key, class T, class Compare>
inline bool operator== (const map<Key, T, Compare>& x,
                        const map<Key, T, Compare>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class Key, class T, class Compare>
inline bool operator< (const map<Key, T, Compare>& x, 
                       const map<Key, T, Compare>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Key, class T, class Compare>
inline bool operator== (const multimap<Key, T, Compare>& x, 
                        const multimap<Key, T, Compare>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class Key, class T, class Compare>
inline bool operator< (const multimap<Key, T, Compare>& x, 
                       const multimap<Key, T, Compare>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#undef Allocator

#endif
