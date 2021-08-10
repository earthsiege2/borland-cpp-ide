/* $Copyright: 1995$ */
/* $Revision:   8.2  $        */
/***************************************************************************
 *
 * tempbuf.cpp - Source for the Standard Library temp buffer
 *
 * $Id: tempbuf.cpp,v 1.11 1995/09/27 21:15:43 smithey Exp $
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
#include <memory>

#ifdef RWSTD_MULTI_THREAD
#include <stdmutex.h>
#endif

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifdef RWSTD_FAST_TEMP_BUF
#if defined(RWSTD_SHARED_LIB) && !defined(RWSTD_MULTI_THREAD)
#error Cannot use fast temporary buffer in this configuration
#endif
#endif

#ifdef RWSTD_FAST_TEMP_BUF

char RWSTDExport __stl_temp_buffer[__stl_buffer_size];

#ifdef RWSTD_MULTI_THREAD
RWSTDMutex RWSTDExport __stl_temp_buffer_mutex;
bool RWSTDExport  __stl_temp_buffer_being_used = false;
#endif

#else

//
// We compile a dummy object into this file, just so it's not empty.
// Some archive utilities don't like to archive empty files :-)
//
int RWSTDExport __stl_temp_buffer_dummy;

#endif /*RWSTD_FAST_TEMP_BUF*/

#ifndef RWSTD_NO_NAMESPACE
}
#endif
