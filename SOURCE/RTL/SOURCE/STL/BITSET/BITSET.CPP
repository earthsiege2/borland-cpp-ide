#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * bitset.cpp - Source for the Standard Library string classes
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
#include <bitset>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifdef _RWSTD_LOCALIZED_ERRORS
 extern const unsigned int _RWSTDExport __rw_bitset_InvalidPosition     = _RWSTD_ERROR_BITSET_INVALID_POSITION;
 extern const unsigned int _RWSTDExport __rw_bitset_InvalidCtorArgument = _RWSTD_ERROR_BITSET_INVALID_CTOR_ARGUMENT;
 extern const unsigned int _RWSTDExport __rw_bitset_ConversionOverflow  = _RWSTD_ERROR_BITSET_CONVERSION_OVERFLOW;
#else
  extern const char _RWSTDExportFunc(*) __rw_bitset_InvalidPosition     = "invalid bitset position in function: %s position: %d is greater than max_length: %";
  extern const char _RWSTDExportFunc(*) __rw_bitset_InvalidCtorArgument = "invalid argument to bitset constructor: %s ";
  extern const char _RWSTDExportFunc(*) __rw_bitset_ConversionOverflow  = "overflow of bitset conversion to unsigned long in function: %s";
#endif //_RWSTD_LOCALIZED_ERRORS

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
