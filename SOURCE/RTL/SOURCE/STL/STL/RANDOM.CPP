#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * random.cpp - Source for the Standard Library random generator
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
#include <rw/stddefs.h> 
#include <rw/random.h> 
#if defined (__WIN16__) && defined (_RWSTDDLL)
#include <rw/instmngr.h> 
#endif

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstddef>
#else
#include <stddef.h>
#endif

#ifdef _RWSTD_MULTI_THREAD
#include <rw/stdmutex.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

  void __random_generator::seed (unsigned long j)
  {
    unsigned long k = 1;
    table[54]       = j;

    for (size_t i = 0; i < LENGTH - 1; i++)
    {
      size_t ii = 21 * i % LENGTH;
      table[ii] = k;
      k = j - k;
      j = table[ii];
    }
    for (int loop = 0; loop < 4; loop++)
    {
      for (size_t i = 0; i < LENGTH; i++)
	table[i] = table[i] - table[(1 + i + 30) % LENGTH];
    }

    index1 = 0;
    index2 = 31;
  }
/*
 * Seed for STL random number generator
 */
  unsigned long __SEED = 161803398;

#if !defined (__WIN16__) || !defined (_RWSTDDLL)
  static __random_generator __rw_rd(__SEED);
#endif
	
  unsigned long _RWSTDExport __long_random (unsigned long limit)
  {
#if !defined (__WIN16__) || !defined (_RWSTDDLL)
    return __rw_rd(limit);
#else
    return getDLLRandom(limit);
#endif
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

