#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * fstream.cpp -- Source file for the Standard Library filestreams
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

#include <fstream>
#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#if defined(__TURBOC__)
#define _BINARY O_BINARY
#elif  defined(_MSC_VER)
#define _BINARY _O_BINARY
#else
#define _BINARY 0
#endif

#ifndef _RWSTD_STRICT_ANSI
extern const int _RWSTDExport  __rwOpenTable[32] = {
  -1,                                                   // no flags error            0
  O_WRONLY | O_APPEND | O_CREAT,                        // app                       1
  -1       | _BINARY,                                   // binary                    2
  O_WRONLY | _BINARY  |  O_APPEND | O_CREAT,            // binary|app                3
  O_RDONLY,                                             // in                        4
  O_RDONLY | O_APPEND,                                  // in|app                    5
  O_RDONLY | _BINARY,                                   // in|binary                 6
  O_RDONLY | _BINARY  | O_APPEND  | O_CREAT,            // in|binary|app             7
  O_TRUNC  | O_WRONLY | O_CREAT,                        // out                       8
  O_WRONLY | O_APPEND | O_CREAT,                        // out|app                   9
  O_TRUNC  | O_WRONLY | O_CREAT   | _BINARY,            // out|binary                10
  O_WRONLY | _BINARY  | O_APPEND  | O_CREAT,            // out|binary|app            11
  O_RDWR   | O_CREAT,                                   // out|in                    12
  O_RDWR   | O_APPEND | O_CREAT,                        // out|in|app                13
  O_RDWR   | O_BINARY | O_CREAT,                        // out|in|binary             14
  O_RDWR   | _BINARY  | O_APPEND  | O_CREAT,            // out|in|binary|app         15
  O_TRUNC,                                              // trunc                     16
  O_TRUNC  | O_APPEND,                                  // trunc|app                 17
  O_TRUNC  | _BINARY,                                   // trunc|binary              18
  O_TRUNC  | O_APPEND | _BINARY,                        // trunc|binary|app          19
  O_TRUNC  | O_RDONLY,                                  // trunc|in                  20
  O_TRUNC  | O_RDONLY | O_APPEND,                       // trunc|in|app              21
  O_TRUNC  | O_RDONLY | _BINARY,                        // trunc|in|binary           22
  O_TRUNC  | O_RDONLY | _BINARY  | O_APPEND,            // trunc|in|binary|app       23
  O_TRUNC  | O_WRONLY | O_CREAT,                        // trunc|out                 24
  O_TRUNC  | O_WRONLY | O_APPEND | O_CREAT,             // trunc|out|app             25
  O_TRUNC  | O_WRONLY | _BINARY  | O_CREAT,             // trunc|out|binary          26
  O_TRUNC  | O_WRONLY | _BINARY  | O_APPEND | O_CREAT,  // trunc|out|binary|app      27
  O_TRUNC  | O_RDWR   | O_CREAT,                        // trunc|out|in              28
  O_TRUNC  | O_RDWR   | O_APPEND | O_CREAT,             // trunc|out|in|app          29
  O_TRUNC  | O_RDWR   | O_CREAT  | _BINARY,             // trunc|out|in|binary       30
  O_TRUNC  | O_RDWR   | _BINARY  | O_APPEND | O_CREAT   // trunc|out|in|binary|app   31
};
#else
extern const char _RWSTDExportFunc(*)  __rwOpenTable[32] = {
  0,              // no flags error            0
  "a",            // app                       1
  0,              // binary                    2
  "ab",           // binary|app                3
  "r",            // in                        4
  "a",            // in|app                    5
  "rb",           // in|binary                 6
  "ab",           // in|binary|app             7
  "w",            // out                       8
  "a",            // out|app                   9
  "wb",           // out|binary                10
  "ab",           // out|binary|app            11
  "r+",           // out|in                    12
  "a+",           // out|in|app                13
  "r+b",          // out|in|binary             14
  "a+b",          // out|in|binary|app         15
  "w",            // trunc                     16
  "w",            // trunc|app                 17
  "wb",           // trunc|binary              18
  "wb",           // trunc|binary|app          19
  0,              // trunc|in                  20
  0,              // trunc|in|app              21
  0,              // trunc|in|binary           22
  0,              // trunc|in|binary|app       23
  "w",            // trunc|out                 24
  "w",            // trunc|out|app             25
  "wb",           // trunc|out|binary          26
  "wb",           // trunc|out|binary|app      27  
  "w+",           // trunc|out|in              28
  "w+",           // trunc|out|in|app          29
  "w+b",          // trunc|out|in|binary       30
  "w+b"           // trunc|out|in|binary|app   31
};
#endif // _RWSTD_STRICT_ANSI
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
