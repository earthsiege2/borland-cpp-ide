#ifndef __STD_TREE__
#define __STD_TREE__
/* $Revision:   8.1  $ */

/***************************************************************************
 *
 * tree - Declarations for the Standard Library tree classes
 *
 * $Id: tree,v 1.43 1995/09/18 23:41:41 lijewski Exp $
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

/*
**
** Red-black tree class, designed for use in implementing STL
** associative containers (set, multiset, map, and multimap). The
** insertion and deletion algorithms are based on those in Cormen,
** Leiserson, and Rivest, Introduction to Algorithms (MIT Press, 1990),
** except that:
**
** (1) the header cell is maintained with links not only to the root
** but also to the leftmost node of the tree, to enable constant time
** begin(), and to the rightmost node of the tree, to enable linear time
** performance when used with the generic set algorithms (set_union,
** etc.);
**
** (2) when a node being deleted has two children its successor node is
** relinked into its place, rather than copied, so that the only
** iterators invalidated are those referring to the deleted node.
**
*/

#include <stdcomp.h>

#include <algorith>
#include <iterator>
#include <function>

#ifdef RWSTD_MULTI_THREAD
#include <stdmutex.h>
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef rb_tree
#define rb_tree rb_tree
#endif


//
// And a mutex to ensure NIL gets set properly for each type of tree.
//
#ifdef RWSTD_MULTI_THREAD
extern RWSTDMutex __stl_tree_mutex;
#endif

template <class Key, class Value, class KeyOfValue, class Compare>
class rb_tree
{
  protected:

    enum color_type { RED, BLACK };
    typedef Allocator<void>::pointer void_pointer;

    struct rb_tree_node;
    friend struct rb_tree_node;

    struct rb_tree_node
    {
        color_type   color_field;
        void_pointer parent_link;
        void_pointer left_link;
        void_pointer right_link;
        Value        value_field;
    };

    Allocator<rb_tree_node> rb_tree_node_allocator;
    Allocator<Value>        value_allocator;

  public:

    typedef Key                                      key_type;
    typedef Value                                    value_type;
    typedef Allocator<Value>::pointer                pointer;
    typedef Allocator<Value>::reference              reference;
    typedef Allocator<Value>::const_reference        const_reference;
    typedef Allocator<rb_tree_node>                  rb_tree_node_allocator_type;
    typedef Allocator<rb_tree_node>::pointer         link_type;
    typedef Allocator<rb_tree_node>::size_type       size_type;
    typedef Allocator<rb_tree_node>::difference_type difference_type;

  protected:

    static size_type buffer_size ()
    {
        //
        // Each time we allocate memory for nodes we reserve space for
        // a chunk of rb_tree_nodes.  This is currently tuned to
        // allocate memory in 1K chunks, except for very large nodes.
        //
        return sizeof(rb_tree_node) >= 1024 ? 1 : 1024 / sizeof(rb_tree_node);
    }

    struct rb_tree_node_buffer;
    friend struct rb_tree_node_buffer;

    struct rb_tree_node_buffer
    {
        void_pointer next_buffer;
        link_type buffer;
    };

  public:

    typedef Allocator<rb_tree_node_buffer>          buffer_allocator_type;
    typedef Allocator<rb_tree_node_buffer>::pointer buffer_pointer;

  protected:

    Allocator<rb_tree_node_buffer> buffer_allocator;
    buffer_pointer                 buffer_list;
    link_type                      free_list;
    link_type                      next_avail;
    link_type                      last;

    void add_new_buffer ()
    {
        buffer_pointer tmp = buffer_allocator.allocate((size_type)1);
        tmp->buffer        = rb_tree_node_allocator.allocate(buffer_size());
        tmp->next_buffer   = buffer_list;
        buffer_list        = tmp;
        next_avail         = buffer_list->buffer;
        last               = next_avail + buffer_size();
    }
    void deallocate_buffers ();
    link_type get_node ()
    {
        link_type tmp = free_list;
        return free_list ?
            (free_list = (link_type)(free_list->right_link), tmp)
                : (next_avail == last ? (add_new_buffer(), next_avail++)
                   : next_avail++);
    }
    void put_node (link_type p) { p->right_link = free_list; free_list = p; }

  protected:

    link_type  header;
    link_type& root      ()       { return parent(header); }
    link_type& root      () const { return parent(header); }
    link_type& leftmost  ()       { return left(header);   }
    link_type& leftmost  () const { return left(header);   }
    link_type& rightmost ()       { return right(header);  }
    link_type& rightmost () const { return right(header);  }

    size_type  node_count;    // Keeps track of size of tree.
    bool       insert_always; // Controls whether an element already in the
                              // tree is inserted again.
    Compare   key_compare;

    static link_type NIL;
    static size_type number_of_trees;

    static link_type& left (link_type x)
    {
        return (link_type&)((*x).left_link);
    }
    static link_type& right (link_type x)
    {
        return (link_type&)((*x).right_link);
    }
    static link_type& parent (link_type x)
    {
        return (link_type&)((*x).parent_link);
    }
    static reference value (link_type x) { return (*x).value_field; }
    static Allocator<Key>::const_reference key (link_type x)
    {
        return KeyOfValue()(value(x));
    }
    static color_type& color (link_type x)
    {
        return (color_type&)(*x).color_field;
    }
    static link_type minimum (link_type x)
    {
        while (left(x) != NIL) x = left(x);
        return x;
    }
    static link_type maximum (link_type x)
    {
        while (right(x) != NIL) x = right(x);
        return x;
    }

  public:

    class  iterator;
    friend class iterator;
    class  const_iterator;
    friend class const_iterator;

    class iterator : public bidirectional_iterator<Value, difference_type>
    {
        friend class rb_tree<Key, Value, KeyOfValue, Compare>;
        friend class const_iterator;

      protected:

        link_type node;
        iterator (link_type x) : node(x) {}

      public:

        iterator () {}
        bool operator== (const iterator& y) const { return node == y.node; }
        reference operator* () const { return value(node); }
        iterator& operator++ ()
        {
            if (right(node) != NIL)
            {
                node = right(node);
                while (left(node) != NIL) node = left(node);
            }
            else
            {
                link_type y = parent(node);
                while (node == right(y))
                {
                    node = y; y = parent(y);
                }
                if (right(node) != y) // Necessary because of rightmost.
                    node = y;
            }
            return *this;
        }
        iterator operator++ (int)
        {
            iterator tmp = *this; ++*this; return tmp;
        }
        iterator& operator-- ()
        {
            if (color(node) == RED && parent(parent(node)) == node)
                //
                // Check for header.
                //
                node = right(node);   // Return rightmost.
            else if (left(node) != NIL)
            {
                link_type y = left(node);
                while (right(y) != NIL) y = right(y);
                node = y;
            }
            else
            {
                link_type y = parent(node);
                while (node == left(y))
                {
                    node = y; y = parent(y);
                }
                node = y;
            }
            return *this;
        }
        iterator operator-- (int)
        {
            iterator tmp = *this; --*this; return tmp;
        }
    };  // End of definition of iterator.

    class const_iterator
        : public bidirectional_iterator<Value,difference_type>
    {
        friend class rb_tree<Key, Value, KeyOfValue, Compare>;
        friend class iterator;

      protected:

        link_type node;
        const_iterator (link_type x) : node(x) {}

      public:

        const_iterator () {}
        const_iterator (const iterator& x) : node(x.node) {}
        bool operator== (const const_iterator& y) const
        {
            return node == y.node;
        }
        bool operator!= (const const_iterator& y) const
        {
            return node != y.node;
        }
        const_reference operator* () const { return value(node); }
        const_iterator& operator++ ()
        {
            if (right(node) != NIL)
            {
                node = right(node);
                while (left(node) != NIL) node = left(node);
            }
            else
            {
                link_type y = parent(node);
                while (node == right(y))
                {
                    node = y; y = parent(y);
                }
                if (right(node) != y) // Necessary because of rightmost.
                    node = y;
            }
            return *this;
        }
        const_iterator operator++ (int)
        {
            const_iterator tmp = *this; ++*this; return tmp;
        }
        const_iterator& operator-- ()
        {
            if (color(node) == RED && parent(parent(node)) == node)
                //
                // Check for header.
                //
                node = right(node);   // return rightmost
            else if (left(node) != NIL)
            {
                link_type y = left(node);
                while (right(y) != NIL) y = right(y);
                node = y;
            }
            else
            {
                link_type y = parent(node);
                while (node == left(y))
                {
                    node = y; y = parent(y);
                }
                node = y;
            }
            return *this;
        }
        const_iterator operator-- (int)
        {
            const_iterator tmp = *this; --*this; return tmp;
        }
    };  // End of definition of const_iterator.

    typedef reverse_bidirectional_iterator<iterator, value_type, reference,
                                           difference_type>
            reverse_iterator;
    typedef reverse_bidirectional_iterator<const_iterator, value_type,
                                           const_reference, difference_type>
            const_reverse_iterator;

  private:

    iterator  __insert (link_type x, link_type y, const value_type& v);
    link_type __copy   (link_type x, link_type p);
    void      __erase  (link_type x);
    void init ()
    {
        buffer_list = 0;
        free_list = next_avail = last = 0;

        {
#ifdef RWSTD_MULTI_THREAD
            RWSTDGuard guard(__stl_tree_mutex);
#endif
            ++number_of_trees;

            if (NIL == 0)
            {
                NIL         = rb_tree_node_allocator.allocate((size_type)1);
                color(NIL)  = BLACK;
                parent(NIL) = 0;
                left(NIL)   = 0;
                right(NIL)  = 0;
            }
        }
        header        = get_node();
        color(header) = RED;  // Used to distinguish header from root
                              // in iterator.operator++.
        root()      = NIL;
        leftmost()  = header;
        rightmost() = header;
    }
  public:

    rb_tree (const Compare& comp = Compare(), bool always = true)
           : node_count(0), key_compare(comp), insert_always(always)
    {
        init();
    }

#ifndef RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    rb_tree (InputIterator first, InputIterator last,
             const Compare& comp = Compare(), bool always = true)
          : node_count(0), key_compare(comp), insert_always(always)
    {
        init(); insert(first, last);
    }
#else
    rb_tree (const value_type* first, const value_type* last,
             const Compare& comp = Compare(), bool always = true)
          : node_count(0), key_compare(comp), insert_always(always)
    {
        init(); insert(first, last);
    }
    rb_tree (const_iterator first, const_iterator last,
             const Compare& comp = Compare(), bool always = true)
          : node_count(0), key_compare(comp), insert_always(always)
    {
        init(); insert(first, last);
    }
#endif

    rb_tree (const rb_tree<Key,Value,KeyOfValue,Compare>& x, bool always = true)
        : node_count(x.node_count), key_compare(x.key_compare),
          insert_always(always)
    {
        {
#ifdef RWSTD_MULTI_THREAD
            RWSTDGuard guard(__stl_tree_mutex);
#endif
            ++number_of_trees;
        }
        buffer_list   = 0;
        free_list     = next_avail = last = 0;
        header        = get_node();
        color(header) = RED;
        root()        = __copy(x.root(), header);
        if (root() == NIL)
        {
            leftmost() = header; rightmost() = header;
        }
        else
        {
            leftmost() = minimum(root()); rightmost() = maximum(root());
        }
    }
    ~rb_tree ()
     {
        erase(begin(), end());
        put_node(header);
        deallocate_buffers();

#ifdef RWSTD_MULTI_THREAD
        RWSTDGuard guard(__stl_tree_mutex);
#endif
        if (--number_of_trees == 0)
        {
            rb_tree_node_allocator.deallocate(NIL);
            NIL = 0;
        }
    }
    rb_tree<Key, Value, KeyOfValue, Compare>&
        operator= (const rb_tree<Key, Value, KeyOfValue, Compare>& x);

    Compare     key_comp () const { return key_compare; }

    iterator       begin ()       { return leftmost(); }
    const_iterator begin () const { return leftmost(); }
    iterator       end   ()       { return header;     }
    const_iterator end   () const { return header;     }

    reverse_iterator rbegin ()
    {
      reverse_iterator tmp(end()); return tmp;
    }
    const_reverse_iterator rbegin () const
    {
      const_reverse_iterator tmp(end()); return tmp;
    }
    reverse_iterator rend ()
    {
      reverse_iterator tmp(begin()); return tmp;
    }
    const_reverse_iterator rend () const
    {
      const_reverse_iterator tmp(begin()); return tmp;
    }

    bool      empty    () const { return node_count == 0; }
    size_type size     () const { return node_count;      }
    size_type max_size () const
    {
        return rb_tree_node_allocator.max_size();
    }
    void swap (rb_tree<Key, Value, KeyOfValue, Compare>& t)
    {
#ifndef RWSTD_NO_NAMESPACE
        std::swap(buffer_allocator, t.buffer_allocator);
        std::swap(buffer_list, t.buffer_list);
        std::swap(free_list, t.free_list);
        std::swap(next_avail, t.next_avail);
        std::swap(last, t.last);
        std::swap(header, t.header);
        std::swap(node_count, t.node_count);
        std::swap(insert_always, t.insert_always);
        std::swap(key_compare, t.key_compare);
        std::swap(rb_tree_node_allocator, t.rb_tree_node_allocator);
        std::swap(value_allocator, t.value_allocator);
#else
        ::swap(buffer_allocator, t.buffer_allocator);
        ::swap(buffer_list, t.buffer_list);
        ::swap(free_list, t.free_list);
        ::swap(next_avail, t.next_avail);
        ::swap(last, t.last);
        ::swap(header, t.header);
        ::swap(node_count, t.node_count);
        ::swap(insert_always, t.insert_always);
        ::swap(key_compare, t.key_compare);
        ::swap(rb_tree_node_allocator, t.rb_tree_node_allocator);
        ::swap(value_allocator, t.value_allocator);
#endif
    }

    typedef  pair<iterator, bool> pair_iterator_bool;
    //
    // typedef done to get around compiler bug.
    //

#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,bool> insert (const value_type& x);
#else
    pair_iterator_bool  insert (const value_type& x);
#endif

    iterator  insert (iterator position, const value_type& x);

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template<class Iterator>
    void      insert (Iterator first, Iterator last);
#else
    void      insert (const_iterator first, const_iterator last);
    void      insert (const value_type* first, const value_type* last);
#endif

    void      erase  (iterator position);
    size_type erase  (const key_type& x);
    void      erase  (iterator first, iterator last);
    void      erase  (const key_type* first, const key_type* last);

    iterator       find        (const key_type& x);
    const_iterator find        (const key_type& x) const;
    size_type      count       (const key_type& x) const;
    iterator       lower_bound (const key_type& x);
    const_iterator lower_bound (const key_type& x) const;
    iterator       upper_bound (const key_type& x);
    const_iterator upper_bound (const key_type& x) const;

    typedef  pair<iterator, iterator> pair_iterator_iterator;
    //
    // typedef done to get around compiler bug.
    //
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<iterator,iterator> equal_range (const key_type& x);
#else
    pair_iterator_iterator equal_range (const key_type& x);
#endif

    typedef  pair<const_iterator, const_iterator> pair_citerator_citerator;
#ifndef RWSTD_NO_RET_TEMPLATE
    pair<const_iterator, const_iterator> equal_range (const key_type& x) const;
#else
    pair_citerator_citerator equal_range (const key_type& x) const;
#endif
    inline void rotate_left  (link_type x);
    inline void rotate_right (link_type x);
};

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::link_type
rb_tree<Key, Value, KeyOfValue, Compare>::NIL = 0;

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::size_type
rb_tree<Key, Value, KeyOfValue, Compare>::number_of_trees = 0;

template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::deallocate_buffers ()
{
    while (buffer_list)
    {
        buffer_pointer tmp = buffer_list;
        buffer_list        = (buffer_pointer)(buffer_list->next_buffer);
        rb_tree_node_allocator.deallocate(tmp->buffer);
        buffer_allocator.deallocate(tmp);
    }
}

template <class Key, class Value, class KeyOfValue, class Compare>
inline bool operator== (const rb_tree<Key, Value, KeyOfValue, Compare>& x,
                        const rb_tree<Key, Value, KeyOfValue, Compare>& y)
{
    return x.size() == y.size() && equal(x.begin(), x.end(), y.begin());
}

template <class Key, class Value, class KeyOfValue, class Compare>
inline bool operator< (const rb_tree<Key, Value, KeyOfValue, Compare>& x,
                       const rb_tree<Key, Value, KeyOfValue, Compare>& y)
{
    return lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>&
rb_tree<Key, Value, KeyOfValue, Compare>::
operator= (const rb_tree<Key, Value, KeyOfValue, Compare>& x)
{
    if (!(this == &x))
    {
        //
        // Can't be done as in list because Key may be a constant type.
        //
        erase(begin(), end());
        root() = __copy(x.root(), header);
        if (root() == NIL)
        {
            leftmost()  = header; rightmost() = header;
        }
        else
        {
            leftmost()  = minimum(root()); rightmost() = maximum(root());
        }
        node_count = x.node_count;
    }
    return *this;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::iterator
rb_tree<Key, Value, KeyOfValue, Compare>::
__insert (link_type x, link_type y, const Value& v)
{
    ++node_count;
    link_type z = get_node();
    construct(value_allocator.address(value(z)), v);
    if (y == header || x != NIL || key_compare(KeyOfValue()(v), key(y)))
    {
        left(y) = z;  // Also makes leftmost() = z when y == header.
        if (y == header)
        {
            root() = z; rightmost() = z;
        }
        else if (y == leftmost())
            leftmost() = z;   // Maintain leftmost() pointing to minimum node.
    }
    else
    {
        right(y) = z;
        if (y == rightmost())
            rightmost() = z;  // Maintain rightmost() pointing to maximum node.
    }
    parent(z) = y;
    left(z) = NIL;
    right(z) = NIL;
    x = z;  // Recolor and rebalance the tree.
    color(x) = RED;
    while (x != root() && color(parent(x)) == RED)
        if (parent(x) == left(parent(parent(x))))
        {
            y = right(parent(parent(x)));
            if (color(y) == RED)
            {
                color(parent(x))         = BLACK;
                color(y)                 = BLACK;
                color(parent(parent(x))) = RED;
                x                        = parent(parent(x));
            }
            else
            {
                if (x == right(parent(x)))
                {
                    x = parent(x); rotate_left(x);
                }
                color(parent(x)) = BLACK;
                color(parent(parent(x))) = RED;
                rotate_right(parent(parent(x)));
            }
        }
        else
        {
            y = left(parent(parent(x)));
            if (color(y) == RED)
            {
                color(parent(x))         = BLACK;
                color(y)                 = BLACK;
                color(parent(parent(x))) = RED;
                x                        = parent(parent(x));
            }
            else
            {
                if (x == left(parent(x)))
                {
                    x = parent(x); rotate_right(x);
                }
                color(parent(x))         = BLACK;
                color(parent(parent(x))) = RED;
                rotate_left(parent(parent(x)));
            }
        }
    color(root()) = BLACK;
    return iterator(z);
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::pair_iterator_bool
rb_tree<Key, Value, KeyOfValue, Compare>::insert (const Value& v)
{
    link_type y = header;
    link_type x = root();
    bool comp   = true;
    while (x != NIL)
    {
        y    = x;
        comp = key_compare(KeyOfValue()(v), key(x));
        x    = comp ? left(x) : right(x);
    }
    if (insert_always)
    {
        pair_iterator_bool tmp(__insert(x, y, v), true); return tmp;
    }
    iterator j = iterator(y);
    if (comp)
        if (j == begin())
        {
            pair_iterator_bool tmp(__insert(x, y, v), true); return tmp;
        }
        else
            --j;
    if (key_compare(key(j.node), KeyOfValue()(v)))
    {
        pair_iterator_bool tmp(__insert(x, y, v), true); return tmp;
    }
    pair_iterator_bool tmp(j, false);
    return tmp;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::iterator
rb_tree<Key, Value, KeyOfValue, Compare>::insert (iterator position,
                                                  const Value& v)
{
    if (position == iterator(begin()))
        if (size() > 0 && key_compare(KeyOfValue()(v), key(position.node)))
            return __insert(position.node, position.node, v);
            //
            // First argument just needs to be non-NIL.
            //
        else
            return insert(v).first;
    else if (position == iterator(end()))
        if (key_compare(key(rightmost()), KeyOfValue()(v)))
            return __insert(NIL, rightmost(), v);
        else
            return insert(v).first;
    else
    {
        iterator before = --position;
        if (key_compare(key(before.node), KeyOfValue()(v))
            && key_compare(KeyOfValue()(v), key(position.node)))
            if (right(before.node) == NIL)
                return __insert(NIL, before.node, v);
            else
                return __insert(position.node, position.node, v);
                //
                // First argument just needs to be non-NIL.
                //
        else
            return insert(v).first;
    }
}

#ifndef RWSTD_NO_MEMBER_TEMPLATES
template <class Key, class Value, class KeyOfValue, class Compare>
template<class Iterator>
void rb_tree<Key, Value, KeyOfValue, Compare>::insert (Iterator first,
                                                       Iterator last)
{
    while (first != last) insert(*first++);
}
#else
template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::insert (const_iterator first,
                                                       const_iterator last)
{
    while (first != last) insert(*first++);
}

template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::insert (const Value* first,
                                                       const Value* last)
{
    while (first != last) insert(*first++);
}
#endif

template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::erase (iterator position)
{
    link_type z;
    __initialize(z, link_type(position.node));
    link_type y = z;
    link_type x;
    if (left(y) == NIL)
        x = right(y);
    else
        if (right(y) == NIL)
            x = left(y);
        else
        {
            y = right(y);
            while (left(y) != NIL) y = left(y);
            x = right(y);
        }
    if (y != z)
    {
        //
        // Relink y in place of z.
        //
        parent(left(z)) = y;
        left(y) = left(z);
        if (y != right(z))
        {
            parent(x)        = parent(y); // Possibly x == NIL.
            left(parent(y))  = x;         // Y must be a left child.
            right(y)         = right(z);
            parent(right(z)) = y;
        }
        else
            parent(x) = y;  // Needed in case x == NIL.
        if (root() == z)
            root() = y;
        else if (left(parent(z)) == z)
            left(parent(z)) = y;
        else
            right(parent(z)) = y;
        parent(y) = parent(z);
#ifndef RWSTD_NO_NAMESPACE
        std::swap(color(y), color(z));
#else
        ::swap(color(y), color(z));
#endif
        y = z; // y points to node to be actually deleted.
    }
    else
    {
        //
        // y == z
        //
        parent(x) = parent(y);   // Possibly x == NIL.
        if (root() == z)
            root() = x;
        else
            if (left(parent(z)) == z)
                left(parent(z)) = x;
            else
                right(parent(z)) = x;
        if (leftmost() == z)
            if (right(z) == NIL)  // left(z) must be NIL also.
                leftmost() = parent(z);
                //
                // makes leftmost() == header if z == root()
                //
        else
            leftmost() = minimum(x);
        if (rightmost() == z)
            if (left(z) == NIL) // right(z) must be NIL also.
                rightmost() = parent(z);
                //
                // makes rightmost() == header if z == root().
                //
        else
            //
            // x == left(z)
            //
            rightmost() = maximum(x);
    }
    if (color(y) != RED)
    {
        while (x != root() && color(x) == BLACK)
            if (x == left(parent(x)))
            {
                link_type w = right(parent(x));
                if (color(w) == RED)
                {
                    color(w)         = BLACK;
                    color(parent(x)) = RED;
                    rotate_left(parent(x));
                    w = right(parent(x));
                }
                if (color(left(w)) == BLACK && color(right(w)) == BLACK)
                {
                    color(w) = RED;
                    x = parent(x);
                }
                else
                {
                    if (color(right(w)) == BLACK)
                    {
                        color(left(w)) = BLACK;
                        color(w)       = RED;
                        rotate_right(w);
                        w = right(parent(x));
                    }
                    color(w) = color(parent(x));
                    color(parent(x)) = BLACK;
                    color(right(w))  = BLACK;
                    rotate_left(parent(x));
                    break;
                }
            }
            else
            {
                //
                // Same as then clause with "right" and "left" exchanged.
                //
                link_type w = left(parent(x));
                if (color(w) == RED)
                {
                    color(w)         = BLACK;
                    color(parent(x)) = RED;
                    rotate_right(parent(x));
                    w = left(parent(x));
                }
                if (color(right(w)) == BLACK && color(left(w)) == BLACK)
                {
                    color(w) = RED; x = parent(x);
                }
                else
                {
                    if (color(left(w)) == BLACK)
                    {
                        color(right(w)) = BLACK;
                        color(w)        = RED;
                        rotate_left(w);
                        w = left(parent(x));
                    }
                    color(w) = color(parent(x));
                    color(parent(x)) = BLACK;
                    color(left(w))   = BLACK;
                    rotate_right(parent(x));
                    break;
                }
            }
        color(x) = BLACK;
    }
    destroy(value_allocator.address(value(y)));
    put_node(y);
    --node_count;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::size_type
rb_tree<Key, Value, KeyOfValue, Compare>::erase (const Key& x)
{
    pair_iterator_iterator p = equal_range(x);
    size_type n;
    __initialize(n, size_type(0));
    distance(p.first, p.second, n);
    erase(p.first, p.second);
    return n;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::link_type
rb_tree<Key, Value, KeyOfValue, Compare>::__copy (link_type x, link_type p)
{
   //
   // Structural copy.
   //
   link_type r = x;
   while (x != NIL)
   {
      link_type y = get_node();
      if (r == x) r = y;  // Save for return value.
      construct(value_allocator.address(value(y)), value(x));
      left(p)   = y;
      parent(y) = p;
      color(y)  = color(x);
      right(y)  = __copy(right(x), y);
      p         = y;
      x         = left(x);
   }
   left(p) = NIL;
   return r;
}

template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::__erase (link_type x)
{
    //
    // Erase without rebalancing.
    //
    while (x != NIL)
    {
       __erase(right(x));
       link_type y = left(x);
       destroy(value_allocator.address(value(x)));
       put_node(x);
       x = y;
    }
}

template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::erase (iterator first,
                                                      iterator locallast)
{
    if (first == begin() && locallast == end() && node_count != 0)
    {
        __erase(root());
        leftmost()  = header;
        root()      = NIL;
        rightmost() = header;
        node_count  = 0;
    } else
        while (first != locallast) erase(first++);
}

template <class Key, class Value, class KeyOfValue, class Compare>
void rb_tree<Key, Value, KeyOfValue, Compare>::erase (const Key* first,
                                                      const Key* last)
{
    while (first != last) erase(*first++);
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::iterator
rb_tree<Key, Value, KeyOfValue, Compare>::find (const Key& k)
{
    link_type y = header;  // Last node that is not less than k.
    link_type x = root();  // Current node.

    while (x != NIL)
    {
        if (!key_compare(key(x), k))
            y = x, x = left(x);
        else
            x = right(x);
    }
    iterator j = iterator(y);
    return (j == end() || key_compare(k, key(j.node))) ? end() : j;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::const_iterator
rb_tree<Key, Value, KeyOfValue, Compare>::find (const Key& k) const
{
    link_type y = header;  // Last node that is not less than k.
    link_type x = root();  // Current node.

    while (x != NIL)
    {
        if (!key_compare(key(x), k))
            y = x, x = left(x);
        else
            x = right(x);
    }
    const_iterator j = const_iterator(y);
    return (j == end() || key_compare(k, key(j.node))) ? end() : j;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::size_type
rb_tree<Key, Value, KeyOfValue, Compare>::count (const Key& k) const
{
    pair<const_iterator, const_iterator> p = equal_range(k);
    size_type n;
    __initialize(n, size_type(0));
    distance(p.first, p.second, n);
    return n;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::iterator
rb_tree<Key, Value, KeyOfValue, Compare>::lower_bound (const Key& k)
{
    link_type y = header;  // Last node that is not less than k.
    link_type x = root();  // Current node.

    while (x != NIL)
    {
        if (!key_compare(key(x), k))
            y = x, x = left(x);
        else
            x = right(x);
    }

    return iterator(y);
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::const_iterator
rb_tree<Key, Value, KeyOfValue, Compare>::lower_bound (const Key& k) const
{
    link_type y = header;  // Last node that is not less than k.
    link_type x = root();  // Current node.

    while (x != NIL)
    {
        if (!key_compare(key(x), k))
            y = x, x = left(x);
        else
            x = right(x);
    }

    return const_iterator(y);
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::iterator
rb_tree<Key, Value, KeyOfValue, Compare>::upper_bound (const Key& k)
{
    link_type y = header;  // Last node that is greater than k.
    link_type x = root();  // Current node.

    while (x != NIL)
    {
        if (key_compare(k, key(x)))
            y = x, x = left(x);
        else
            x = right(x);
    }

    return iterator(y);
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::const_iterator
rb_tree<Key, Value, KeyOfValue, Compare>::upper_bound (const Key& k) const
{
    link_type y = header;  // Last node that is greater than k.
    link_type x = root();  // Current node.

    while (x != NIL)
    {
        if (key_compare(k, key(x)))
            y = x, x = left(x);
        else
            x = right(x);
    }

    return const_iterator(y);
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::pair_iterator_iterator
rb_tree<Key, Value, KeyOfValue, Compare>::equal_range (const Key& k)
{
    pair_iterator_iterator tmp(lower_bound(k), upper_bound(k));
    return tmp;
}

template <class Key, class Value, class KeyOfValue, class Compare>
rb_tree<Key, Value, KeyOfValue, Compare>::pair_citerator_citerator
rb_tree<Key, Value, KeyOfValue, Compare>::equal_range (const Key& k) const
{
    pair_citerator_citerator tmp(lower_bound(k), upper_bound(k));
    return tmp;
}

template <class Key, class Value, class KeyOfValue, class Compare>
inline void
rb_tree<Key, Value, KeyOfValue, Compare>::rotate_left (link_type x)
{
    link_type y = right(x);
    right(x) = left(y);
    if (left(y) != NIL)
        parent(left(y)) = x;
    parent(y) = parent(x);
    if (x == root())
        root() = y;
    else if (x == left(parent(x)))
        left(parent(x)) = y;
    else
        right(parent(x)) = y;
    left(y) = x;
    parent(x) = y;
}

template <class Key, class Value, class KeyOfValue, class Compare>
inline void
rb_tree<Key, Value, KeyOfValue, Compare>::rotate_right (link_type x)
{
    link_type y = left(x);
    left(x) = right(y);
    if (right(y) != NIL)
        parent(right(y)) = x;
    parent(y) = parent(x);
    if (x == root())
        root() = y;
    else if (x == right(parent(x)))
        right(parent(x)) = y;
    else
        left(parent(x)) = y;
    right(y) = x;
    parent(x) = y;
}

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif

