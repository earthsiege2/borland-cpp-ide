/*  memory.h

    Memory manipulation functions

*/

/* $Copyright: 1991$ */

#if !defined(__USING_STD_NAMES__)

#include <mem.h>

#else   /* __USING_STD_NAMES__ */

#ifndef __STD_MEMORY
#define __STD_MEMORY

/***************************************************************************
 *
 * memory - declarations for the Standard Library memory implementation
 *
 * $Id: memory,v 1.38 1995/09/14 02:50:59 smithey Exp $
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

#ifndef RWSTD_NO_NEW_HEADER
#include <cstddef>
#include <cstdlib>
#include <new>
#else
#include <new.h>
#include <stddef.h>
#include <stdlib.h>
#endif

#include <limits>

#ifdef RW_STD_IOSTREAM
#include <iostream>
#else
#include <iostream.h>
#endif

#include <iterator>
#include <utility>

#ifdef RWSTD_MULTI_THREAD
#include <stdmutex.h>
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifdef RWSTD_NO_NEW_DECL
inline void* operator new (size_t, void* p) { return p; }
#endif

//
// Raw storage iterator.
//

template <class OutputIterator, class T>
class raw_storage_iterator : public output_iterator
{
  protected:
    OutputIterator iter;
  public:
    explicit raw_storage_iterator (OutputIterator x) : iter(x) {}
    raw_storage_iterator<OutputIterator, T>& operator* () { return *this; }
    raw_storage_iterator<OutputIterator, T>& operator= (const T& element)
    {
        construct(iter, element); return *this;
    }
    raw_storage_iterator<OutputIterator, T>& operator++ ()
    {
        ++iter; return *this;
    }
    raw_storage_iterator<OutputIterator, T> operator++ (int)
    {
        raw_storage_iterator<OutputIterator, T> tmp = *this;
        ++iter;
        return tmp;
    }
};

//
// Memory handling primitives.
//

template <class T>
inline T* allocate (int size, T*)
{
#ifndef RWSTD_NO_NAMESPACE
    T* tmp = (T*)(std::operator new((unsigned int)(size * sizeof(T))));
#else
    T* tmp = (T*)(::operator new((unsigned int)(size * sizeof(T))));
#endif
    if (tmp == 0)
    {
        cerr << "out of memory" << endl;
        exit(1);
    }
    return tmp;
}

#ifndef RWSTD_NO_ARG_MATCH
template <class T>
inline T* allocate (long size, T*)
{
#ifndef RWSTD_NO_NAMESPACE
    T* tmp = (T*)(std::operator new((unsigned long)(size * sizeof(T))));
#else
    T* tmp = (T*)(::operator new((unsigned long)(size * sizeof(T))));
#endif
    if (tmp == 0)
    {
        cerr << "out of memory" << endl;
        exit(1);
    }
    return tmp;
}
#endif

template <class T>
inline void deallocate (T* buffer)
{
#ifndef RWSTD_NO_NAMESPACE
    std::operator delete(buffer);
#else
    ::operator delete(buffer);
#endif
}

template <class T1, class T2>
inline void construct (T1* p, const T2& value)
{
    new (p) T1(value);
}

#if defined(RWSTD_NO_DESTROY_NONBUILTIN)
template <class T> struct __FS : public T
{
    //
    // Calls destructor, but does not free the space.
    //
    void operator delete (void*) {;}
};
#endif

template <class T>
inline void destroy (T* pointer)
{
#if defined(RWSTD_NO_DESTROY_NONBUILTIN)
    delete (__FS<T>*) (pointer);
#else
    pointer->~T();
#endif
}

template <class Pointer>
void destroy (Pointer first, Pointer last)
{
    while (first != last)
    {
        destroy(first);
        ++first;
    }
}

#ifdef RWSTD_FAST_TEMP_BUF

#ifndef __stl_buffer_size
#define __stl_buffer_size 16384  /* 16k */
#endif

extern char __stl_temp_buffer[__stl_buffer_size];

#ifdef RWSTD_MULTI_THREAD
extern RWSTDMutex __stl_temp_buffer_mutex;
extern bool       __stl_temp_buffer_being_used;
#endif

template <class T>
pair<T*, int> get_temporary_buffer (int len, T*)
{
    while (len > __stl_buffer_size / sizeof(T))
    {
#ifndef RWSTD_NO_NAMESPACE
        T* tmp = (T*)(std::operator new((unsigned int)len * sizeof(T)));
#else
        T* tmp = (T*)(   ::operator new((unsigned int)len * sizeof(T)));
#endif
        if (tmp)
        {
            pair<T*, int> result(tmp, len);
            return result;
        }
        len = len / 2;
    }

#ifdef RWSTD_MULTI_THREAD
    RWSTDGuard guard(__stl_temp_buffer_mutex);

    if (__stl_temp_buffer_being_used)
    {
#ifndef RWSTD_NO_NAMESPACE
        T* tmp = (T*)(std::operator new((unsigned int)len * sizeof(T)));
#else
        T* tmp = (T*)(   ::operator new((unsigned int)len * sizeof(T)));
#endif
        pair<T*,int> result(tmp, len);
        return result;
    }
    else
    {
        __stl_temp_buffer_being_used = true;
        pair<T*, int> result((T*) __stl_temp_buffer,
                             (int) (__stl_buffer_size / sizeof(T)));
        return result;
    }
#else
    pair<T*, int> result((T*) __stl_temp_buffer,
                         (int) (__stl_buffer_size / sizeof(T)));
    return result;
#endif /*RWSTD_MULTI_THREAD*/
}

template <class T>
inline void return_temporary_buffer (T* p)
{
#ifdef RWSTD_MULTI_THREAD
    RWSTDGuard guard(__stl_temp_buffer_mutex);

    if ((char*)(p) != __stl_temp_buffer)
        deallocate(p);
    else
        __stl_temp_buffer_being_used = false;
#else
    if ((char*)(p) != __stl_temp_buffer)
        deallocate(p);
#endif /*RWSTD_MULTI_THREAD*/
}

#else

template <class T>
pair<T*, int> get_temporary_buffer (int len, T*)
{
#ifndef RWSTD_NO_NAMESPACE
    T* tmp = (T*)(std::operator new((unsigned int)len * sizeof(T)));
#else
    T* tmp = (T*)(   ::operator new((unsigned int)len * sizeof(T)));
#endif
    pair<T*,int> result(tmp, len);
    return result;
}

template <class T>
inline void return_temporary_buffer (T* p)
{
    deallocate(p);
}

#endif /*RWSTD_FAST_TEMP_BUF*/

#ifndef RWSTD_NO_ARG_MATCH
template <class T>
pair<T*, long> get_temporary_buffer (long len, T* p)
{
    if (len > INT_MAX/sizeof(T))
        len = INT_MAX/sizeof(T);
    pair<T*, int> tmp = get_temporary_buffer((int)len, p);
    return pair<T*, long>(tmp.first, (long)(tmp.second));
}
#endif

#if defined(RWSTD_NO_DESTROY_BUILTIN) || defined(RWSTD_NO_DESTROY_NONBUILTIN)
//
// Some specializations of STL destroy for builtin types.
//
inline void destroy (void*)             {;}
inline void destroy (char*)             {;}
inline void destroy (unsigned char*)    {;}
inline void destroy (short*)            {;}
inline void destroy (unsigned short*)   {;}
inline void destroy (int*)              {;}
inline void destroy (unsigned int*)     {;}
inline void destroy (long*)             {;}
inline void destroy (unsigned long*)    {;}
inline void destroy (float*)            {;}
inline void destroy (double*)           {;}
inline void destroy (long double*)      {;}
inline void destroy (void**)            {;}
inline void destroy (char**)            {;}
inline void destroy (unsigned char**)   {;}
inline void destroy (short**)           {;}
inline void destroy (unsigned short**)  {;}
inline void destroy (int**)             {;}
inline void destroy (unsigned int**)    {;}
inline void destroy (long**)            {;}
inline void destroy (unsigned long**)   {;}
inline void destroy (float**)           {;}
inline void destroy (double**)          {;}
inline void destroy (long double**)     {;}
inline void destroy (void***)           {;}
inline void destroy (char***)           {;}
inline void destroy (unsigned char***)  {;}
inline void destroy (short***)          {;}
inline void destroy (unsigned short***) {;}
inline void destroy (int***)            {;}
inline void destroy (unsigned int***)   {;}
inline void destroy (long***)           {;}
inline void destroy (unsigned long***)  {;}
inline void destroy (float***)          {;}
inline void destroy (double***)         {;}
inline void destroy (long double***)    {;}
#ifndef RWSTD_NO_BOOL
inline void destroy (bool*)             {;}
inline void destroy (bool**)            {;}
inline void destroy (bool***)           {;}
#endif
#ifndef RWSTD_NO_OVERLOAD_WCHAR
inline void destroy (wchar_t*)          {;}
inline void destroy (wchar_t**)         {;}
inline void destroy (wchar_t***)        {;}
#endif
#endif /*RWSTD_NO_DESTROY_BUILTIN || RWSTD_NO_DESTROY_NONBUILTIN*/

//
// The default allocator.
//
// Note that this is the old allocator, not the one defined in the
// 28 April 1995 WP.  There aren't any compilers that implement member
// class templates, that we're aware of, yet.
//

template <class T>
class allocator
{
  public:
    typedef T         value_type;
    typedef T*        pointer;
    typedef const T*  const_pointer;
    typedef T&        reference;
    typedef const T&  const_reference;
    typedef size_t    size_type;
    typedef ptrdiff_t difference_type;

    pointer allocate (size_type n = 0)
    {
#ifndef RWSTD_NO_NAMESPACE
        return std::allocate((difference_type)n, (pointer)0);
#else
        return ::allocate((difference_type)n, (pointer)0);
#endif
    }
#ifndef RWSTD_NO_NAMESPACE
    void deallocate (pointer p) { std::deallocate(p); }
#else
    void deallocate (pointer p) { ::deallocate(p); }
#endif
    pointer address (reference x) { return (pointer)&x; }
    const_pointer const_address (const_reference x)
    {
        return (const_pointer)&x;
    }
    size_type init_page_size ()
    {
        return max(size_type(1), size_type(4096/sizeof(T)));
    }
    size_type max_size () const
    {
        return max(size_type(1), size_type(UINT_MAX/sizeof(T)));
    }
};

//
// A specialization.
//

class allocator<void>
{
public:
    typedef void* pointer;
};

//
// Specialized algorithms.
//

template <class InputIterator, class ForwardIterator>
ForwardIterator uninitialized_copy (InputIterator first, InputIterator last,
                                    ForwardIterator result)
{
    while (first != last) construct(&*result++, *first++);
    return result;
}

template <class ForwardIterator, class T>
void uninitialized_fill (ForwardIterator first, ForwardIterator last,
                         const T& x)
{
    while (first != last) construct(&*first++, x);
}

template <class ForwardIterator, class Size, class T>
ForwardIterator uninitialized_fill_n (ForwardIterator first, Size n, const T& x)
{
    while (n--) construct(&*first++, x);
    return first;
}

//
// Template auto_ptr holds onto a pointer obtained via new and deletes that
// object when it itself is destroyed (such as when leaving block scope).
//
// It can be used to make calls to new() exception safe.
//

template<class X> class auto_ptr
{
  public:
    //
    // construct/copy/destroy
    //
    explicit auto_ptr (X* p = 0) : the_p(p)           {}
    auto_ptr (auto_ptr<X>& a)    : the_p(a.release()) {}
    void operator= (auto_ptr<X>& rhs) { reset(rhs.release()); }
    ~auto_ptr () { delete the_p; }
    //
    // members
    //
    X& operator*  ()        const { return *the_p;   }
    X* operator-> ()        const { return the_p;    }
    X* get        ()        const { return the_p;    }
    X* release    ()              { return reset(0); }
    X* reset      (X* p = 0)      { X* tmp = the_p; the_p = p; return tmp; }

private:

    X* the_p;
};

#ifndef RWSTD_NO_NAMESPACE
}
#endif

#endif /*__STD_MEMORY*/

#endif /* __USING_STD_NAMES__ */
