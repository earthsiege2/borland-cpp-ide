#include "stlhdrs.h"
#pragma  hdrstop

/***************************************************************************
 *
 * stdexcept.cpp - Source for the Standard Library exception classes
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
#include <rw/rwstderr.h>
#include <string.h>

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstdlib>
#include <cstdio>
#else
#include <stdlib.h>
#include <stdio.h>
#endif // _RWSTD_NO_NEW_HEADER

#include <stdexcept>
#include <stdio.h>     // needed for vsprintf (RW-BUG)

#ifndef _RWSTD_NO_CATOPEN_CATGETS
#include <nl_types.h>
#else
#include <rw/rwcats.h>
#endif

#ifndef _RWSTD_NL_CAT_LOCALE
#define _RWSTD_NL_CAT_LOCALE 0
#endif

#ifdef HPPA_WA
#include <exception>
#include <new>
#endif // HPPA_WA 

#ifdef _RWSTD_MULTI_THREAD
#include <rw/stdmutex.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

  extern const char _RWSTDExportFunc(*)  __rw_stdexcept_NoNamedException = "no named exception thrown";
  extern const char _RWSTDExportFunc(*)  __rw_stdexcept_BadException = "bad exception thrown";
  extern const char _RWSTDExportFunc(*)  __rw_stdexcept_BadAllocException = "bad alloc exception thrown";
  extern const char _RWSTDExportFunc(*)  __rw_stdexcept_Error = "Error";

#ifdef _RWSTD_MULTI_THREAD
  _RWSTDMutex __rw_error_msg_mutex;
#endif

  static nl_catd except_cat_id = 0;

  except_msg_string::except_msg_string(const char* msg ...)
  {
    va_list arglist;
    va_start(arglist, msg);
#if !defined (_RWSTD_NO_NAMESPACE) && !defined (_RWSTD_NO_NEW_HEADER)
    std::vsprintf(__msg, msg, arglist);
#else
    vsprintf(__msg, msg, arglist);
#endif
    va_end(arglist);
  }

  except_msg_string::except_msg_string(unsigned int msg ...)
  {
    va_list arglist;
    va_start(arglist, msg);
    char * buf = NULL;
    const char * _Error = __rw_stdexcept_Error;
    
    {
#ifdef _RWSTD_MULTI_THREAD
      _RWSTDGuard mut(__rw_error_msg_mutex);
#endif
      if (!except_cat_id)
        except_cat_id = catopen(_RWSTD_ERROR_MSG_FILE,_RWSTD_NL_CAT_LOCALE);

      if (except_cat_id)
        buf = catgets(except_cat_id,_RWSTD_ERROR_SET,msg,_Error);
    }

    if (buf)
#if !defined (_RWSTD_NO_NAMESPACE) && !defined (_RWSTD_NO_NEW_HEADER)
      std::vsprintf(__msg,buf , arglist);
#else
      vsprintf(__msg, buf, arglist);
#endif
    else 
      strcpy(__msg,_Error);

    va_end(arglist);
  }

#ifdef __OS2__ 
#ifdef _RWSTD_MULTI_THREAD
  const char* __rw_mutex_exception = "Thread synchronization exception.";
#endif
#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _RWSTD_EXCEPTION_DEFINED
  exception::~exception() _RWSTD_THROW_SPEC_NULL { ; }
#endif
#ifndef _RWSTD_BAD_EXCEPTION_DEFINED
  bad_exception::~bad_exception() _RWSTD_THROW_SPEC_NULL { ; }
#endif
#if !defined(_RWSTD_BAD_ALLOC_DEFINED) || defined(__TURBOC__)
  bad_alloc::~bad_alloc() _RWSTD_THROW_SPEC_NULL { ; }
#endif
#ifndef _RWSTD_LOGIC_ERROR_DEFINED
  logic_error::~logic_error() _RWSTD_THROW_SPEC_NULL { ; }
#endif
  domain_error::~domain_error() _RWSTD_THROW_SPEC_NULL { ; }
  invalid_argument::~invalid_argument() _RWSTD_THROW_SPEC_NULL { ; }
  length_error::~length_error() _RWSTD_THROW_SPEC_NULL { ; }
  out_of_range::~out_of_range() _RWSTD_THROW_SPEC_NULL { ; }
  runtime_error::~runtime_error() _RWSTD_THROW_SPEC_NULL { ; }
  range_error::~range_error() _RWSTD_THROW_SPEC_NULL { ; }
  overflow_error::~overflow_error() _RWSTD_THROW_SPEC_NULL { ; }
  underflow_error::~underflow_error() _RWSTD_THROW_SPEC_NULL { ; }
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

