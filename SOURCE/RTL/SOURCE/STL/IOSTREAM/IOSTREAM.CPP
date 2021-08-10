#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * iostream.cpp - Source for the Standard Library iostream.  Defines
 *     several standard streams.
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

#ifdef __BORLANDC__
#pragma init_seg(compiler)  // This causes the global classes defined in this
                            // file to be initialized earlier than other
                            // global classes.
#endif // __BORLANDC__

#include <iostream>   
#include <fstream>

#ifndef __SUNPRO_CC
#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  int ios_base::Init::__initcnt;

#ifdef __TURBOC__
  template class _RWSTDExportTemplate basic_istream<char, char_traits<char> >;
#endif // __TURBOC__

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
  static filebuf _RWSTDExport     __stdin_filebuf(_RWSTD_STDIN);
  static filebuf _RWSTDExport     __stdout_filebuf(_RWSTD_STDOUT);
  static filebuf _RWSTDExport     __stderr_filebuf(_RWSTD_STDERR);
#else
  filebuf _RWSTDExport     __stdin_filebuf(_RWSTD_STDIN);
  filebuf _RWSTDExport     __stdout_filebuf(_RWSTD_STDOUT);
  filebuf _RWSTDExport     __stderr_filebuf(_RWSTD_STDERR);
#endif // _MSC_VER

  istream _RWSTDExport            cin(&__stdin_filebuf);
  ostream _RWSTDExport            cout(&__stdout_filebuf);
  ostream _RWSTDExport            cerr(&__stderr_filebuf);
  ostream                         clog(&__stderr_filebuf);

  static ios_base::Init      __rwCinInit;

#undef _RWSTD_STDIN 
#undef _RWSTD_STDOUT
#undef _RWSTD_STDERR

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#endif // __SUNPRO_CC
