#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * wstream.cpp - Source for the Standard Library wstream.  Defines
 *     several standard wide streams.
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

#include <iostream>   
#include <fstream>

#ifndef _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

int __Wide_Init::__initcnt = 0;

#ifdef __TURBOC__
template class basic_istream<wchar_t, char_traits<wchar_t> >;
#endif 

#ifndef _RWSTD_STRICT_ANSI
# define _RWSTD_STDIN  0
# define _RWSTD_STDOUT 1
# define _RWSTD_STDERR 2
#else
# define _RWSTD_STDIN  stdin
# define _RWSTD_STDOUT stdout
# define _RWSTD_STDERR stderr
#endif // _RWSTD_STRICT_ANSI

#ifndef _MSC_VER
static wfilebuf _RWSTDExport    __wstdin_filebuf(_RWSTD_STDIN);
static wfilebuf _RWSTDExport    __wstdout_filebuf(_RWSTD_STDOUT);
static wfilebuf _RWSTDExport    __wstderr_filebuf(_RWSTD_STDERR);
#else
wfilebuf _RWSTDExport    __wstdin_filebuf(_RWSTD_STDIN);
wfilebuf _RWSTDExport    __wstdout_filebuf(_RWSTD_STDOUT);
wfilebuf _RWSTDExport    __wstderr_filebuf(_RWSTD_STDERR);
#endif // _MSC_VER
wistream _RWSTDExport           wcin(&__wstdin_filebuf);
wostream _RWSTDExport           wcout(&__wstdout_filebuf);
wostream _RWSTDExport           wcerr(&__wstderr_filebuf);
wostream _RWSTDExport           wclog(&__wstderr_filebuf);

static __Wide_Init      __rwWCinInit;
#undef _RWSTD_STDIN 
#undef _RWSTD_STDOUT
#undef _RWSTD_STDERR

 /*
   * __Wide_Init::__Wide_Init()
   */

__Wide_Init::__Wide_Init()
{
  if(++__initcnt != 1)
    return;

  wcin.tie(&wcout);
  wcerr.tie(&wcout);
  wclog.tie(&wcout);

  wcerr.setf(basic_ios<wchar_t, char_traits<wchar_t> >::unitbuf);
}

  /*
   * __Wide_Init::~__Wide_Init()
   */

__Wide_Init::~__Wide_Init()
{
  if(!(--__initcnt))
  {
    wcout.flush();
    wcerr.flush();
    wclog.flush();
  }
}
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#endif // _RWSTD_NO_WIDE_CHAR

