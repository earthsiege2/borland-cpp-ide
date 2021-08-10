#include "stlhdrs.h"
#pragma  hdrstop
/***************************************************************************
 *
 * locinst.cpp - Instantiations for the Standard Library locale classes
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

#include <compnent.h>
#ifdef _RW_STD_LOCALE

#include <locale>
#include <istream>
#include <ostream>
#include <rw/lochelp>

#ifndef _RWSTD_NO_NAMESPACE
using namespace std;
#endif

// Some useful typedefs, this module only.
typedef istreambuf_iterator<char,char_traits<char> > isit;
typedef ostreambuf_iterator<char,char_traits<char> > osit;

#ifndef _RWSTD_NO_WIDE_CHAR
typedef istreambuf_iterator<wchar_t,char_traits<wchar_t> > wisit;
typedef ostreambuf_iterator<wchar_t,char_traits<wchar_t> > wosit;
#endif

typedef ctype<char>                         f_ctype;
typedef numpunct<char>                      f_npunc;
typedef num_get<char,isit>                  f_nget;
typedef num_put<char,osit>                  f_nput;
typedef collate<char>                       f_coll;
typedef codecvt<char,char,mbstate_t>        f_cvtcc;
typedef messages<char>                      f_mess;

#ifndef _RWSTD_NO_WIDE_CHAR
typedef ctype<wchar_t>                      w_ctype;
typedef numpunct<wchar_t>                   w_npunc;
typedef num_get<wchar_t,wisit>              w_nget;
typedef num_put<wchar_t,wosit>              w_nput;
typedef collate<wchar_t>                    w_coll;
typedef codecvt<wchar_t,char,mbstate_t>     w_cvtwc;
typedef messages<wchar_t>                   w_mess;
#endif
#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION
template class _RWSTDExportTemplate num_get<char,isit>;
template class _RWSTDExportTemplate num_put<char,osit>;
template class _RWSTDExportTemplate numpunct<char>;
template class _RWSTDExportTemplate collate<char>;
template class _RWSTDExportTemplate messages<char>;

#ifndef _RWSTD_NO_WIDE_CHAR
template class _RWSTDExportTemplate num_get<wchar_t,wisit>;
template class _RWSTDExportTemplate num_put<wchar_t,wosit>;
template class _RWSTDExportTemplate numpunct<wchar_t>;
template class _RWSTDExportTemplate collate<wchar_t>;
template class _RWSTDExportTemplate messages<wchar_t>;
#endif // _RWSTD_NO_WIDE_CHAR

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate num_get<char,isit>
#pragma instantiate num_put<char,osit>
#pragma instantiate numpunct<char>
#pragma instantiate collate<char>
#pragma instantiate messages<char>

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate num_get<wchar_t,wisit>
#pragma instantiate num_put<wchar_t,wosit>
#pragma instantiate numpunct<wchar_t>
#pragma instantiate collate<wchar_t>
#pragma instantiate messages<wchar_t>
#endif // _RWSTD_NO_WIDE_CHAR

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd { // Leave std, enter implementation private namespace
#endif

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

template class _RWSTDExportTemplate numpunct_data<char>;
template class _RWSTDExportTemplate digit_handler_base_1<char>;
template class _RWSTDExportTemplate digit_reader_base_1<char>;
template class _RWSTDExportTemplate digit_reader<char,isit>;
template class _RWSTDExportTemplate digit_writer_base_1<char>;
template class _RWSTDExportTemplate digit_writer<char,osit>;

template class _RWSTDExportTemplate facet_maker<f_ctype>;
template class _RWSTDExportTemplate facet_maker<f_npunc>;
template class _RWSTDExportTemplate facet_maker<f_nget>;
template class _RWSTDExportTemplate facet_maker<f_nput>;
template class _RWSTDExportTemplate facet_maker<f_coll>;
template class _RWSTDExportTemplate facet_maker<f_cvtcc>;
template class _RWSTDExportTemplate facet_maker<f_mess>;

#ifndef _RWSTD_NO_WIDE_CHAR
template class _RWSTDExportTemplate numpunct_data<wchar_t>;
template class _RWSTDExportTemplate digit_handler_base_1<wchar_t>;
template class _RWSTDExportTemplate digit_reader_base_1<wchar_t>;
template class _RWSTDExportTemplate digit_reader<wchar_t,wisit>;
template class _RWSTDExportTemplate digit_writer_base_1<wchar_t>;
template class _RWSTDExportTemplate digit_writer<wchar_t,wosit>;
template class _RWSTDExportTemplate digit_map<wchar_t>;

template class _RWSTDExportTemplate facet_maker<w_ctype>;
template class _RWSTDExportTemplate facet_maker<w_npunc>;
template class _RWSTDExportTemplate facet_maker<w_nget>;
template class _RWSTDExportTemplate facet_maker<w_nput>;
template class _RWSTDExportTemplate facet_maker<w_coll>;
template class _RWSTDExportTemplate facet_maker<w_cvtwc>;
template class _RWSTDExportTemplate facet_maker<w_mess>;

#ifndef _RWSTD_NO_EXPLICIT_FUNC_INSTANTIATE
template numpunct_init<wchar_t>*
    fixup_numpunct_init
    (numpunct_init<char>*,wchar_t*);
#endif

#endif // _RWSTD_NO_WIDE_CHAR

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate numpunct_data<char>
#pragma instantiate digit_handler_base_1<char>
#pragma instantiate digit_reader_base_1<char>
#pragma instantiate digit_reader<char,isit>
#pragma instantiate digit_writer_base_1<char>
#pragma instantiate digit_writer<char,osit>

#pragma instantiate facet_maker<f_ctype>
#pragma instantiate facet_maker<f_npunc>
#pragma instantiate facet_maker<f_nget>
#pragma instantiate facet_maker<f_nput>
#pragma instantiate facet_maker<f_coll>
#pragma instantiate facet_maker<f_cvtcc>
#pragma instantiate facet_maker<f_mess>

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate numpunct_data<wchar_t>
#pragma instantiate digit_handler_base_1<wchar_t>
#pragma instantiate digit_reader_base_1<wchar_t>
#pragma instantiate digit_reader<wchar_t,wisit>
#pragma instantiate digit_writer_base_1<wchar_t>
#pragma instantiate digit_writer<wchar_t,wosit>

#pragma instantiate facet_maker<w_ctype>
#pragma instantiate facet_maker<w_npunc>
#pragma instantiate facet_maker<w_nget>
#pragma instantiate facet_maker<w_nput>
#pragma instantiate facet_maker<w_coll>
#pragma instantiate facet_maker<w_cvtwc>
#pragma instantiate facet_maker<w_mess>

#pragma instantiate numpunct_init<wchar_t>* \
    fixup_numpunct_init                     \
      (numpunct_init<char>*,wchar_t*)

#endif // _RWSTD_NO_WIDE_CHAR
#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION
#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

#ifndef _RWSTD_NO_INSTANTIATE_BYNAME_FACETS
#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

template class _RWSTDExport numpunct_byname<char>;
template class _RWSTDExport codecvt_byname<char,char,mbstate_t>;
template class _RWSTDExport moneypunct_byname<char,false>;
template class _RWSTDExport moneypunct_byname<char,true>;
template class _RWSTDExport time_get_byname<char,isit>;
template class _RWSTDExport time_put_byname<char,osit>;
template class _RWSTDExport messages_byname<char>;

#ifndef _RWSTD_NO_WIDE_CHAR
template class _RWSTDExport numpunct_byname<wchar_t>;
template class _RWSTDExport codecvt_byname<wchar_t,char,mbstate_t>;
template class _RWSTDExport collate_byname<wchar_t>;
template class _RWSTDExport moneypunct_byname<wchar_t,false>;
template class _RWSTDExport moneypunct_byname<wchar_t,true>;
template class _RWSTDExport time_get_byname<wchar_t,wisit>;
template class _RWSTDExport time_put_byname<wchar_t,wosit>;
template class _RWSTDExport messages_byname<wchar_t>;
#endif // _RWSTD_NO_WIDE_CHAR

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE
#pragma instantiate numpunct_byname<char>
#pragma instantiate codecvt_byname<char,char,mbstate_t>
#pragma instantiate moneypunct_byname<char,false>
#pragma instantiate moneypunct_byname<char,true>
#pragma instantiate time_get_byname<char,isit>
#pragma instantiate time_put_byname<char,osit>
#pragma instantiate messages_byname<char>

#ifndef _RWSTD_NO_WIDE_CHAR
#pragma instantiate numpunct_byname<wchar_t>
#pragma instantiate codecvt_byname<wchar_t,char,mbstate_t>
#pragma instantiate collate_byname<wchar_t>
#pragma instantiate moneypunct_byname<wchar_t,false>
#pragma instantiate moneypunct_byname<wchar_t,true>
#pragma instantiate time_get_byname<wchar_t,wisit>
#pragma instantiate time_put_byname<wchar_t,wosit>
#pragma instantiate messages_byname<wchar_t>
#endif // _RWSTD_NO_WIDE_CHAR

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION
#endif // _RWSTD_NO_INSTANTIATE_BYNAME_FACETS

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes into library (new C++ style)
template class _RWSTDExport moneypunct<char,false>;
template class _RWSTDExport moneypunct<char,true>;
template class _RWSTDExport money_get<char,isit>;
template class _RWSTDExport money_put<char,osit>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes into library (old Cfront/EDG style)
#pragma instantiate moneypunct<char,false>
#pragma instantiate moneypunct<char,true>
#pragma instantiate money_get<char,isit>
#pragma instantiate money_put<char,osit>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes into library (new C++ style)
template class _RWSTDExport moneypunct<wchar_t,false>;
template class _RWSTDExport moneypunct<wchar_t,true>;
template class _RWSTDExport money_get<wchar_t,wisit>;
template class _RWSTDExport money_put<wchar_t,wosit>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes into library (old Cfront style)
#pragma instantiate moneypunct<wchar_t,false>
#pragma instantiate moneypunct<wchar_t,true>
#pragma instantiate money_get<wchar_t,wisit>
#pragma instantiate money_put<wchar_t,wosit>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION
#endif // _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes into library (new C++ style)
template class _RWSTDExport time_get<char,isit>;
template class _RWSTDExport time_put<char,osit>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes into library (old Cfront/EDG style)
#pragma instantiate time_get<char,isit>
#pragma instantiate time_put<char,osit>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes into library (new C++ style)
template class _RWSTDExport time_get<wchar_t,wisit>;
template class _RWSTDExport time_put<wchar_t,wosit>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes into library (old Cfront/EDG style)
#pragma instantiate time_get<wchar_t,wisit>
#pragma instantiate time_put<wchar_t,wosit>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION
#endif // _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd { // Leave std, enter implementation namespace
#endif

#define timepunct       timepunct
#define timepunct_data  timepunct_data
#define time_reader     time_reader
#define facet_maker     facet_maker

#ifndef _RWSTD_NO_WIDE_CHAR
typedef timepunct<wchar_t>       tpw_facet;
typedef time_get<wchar_t,wisit>  tiw_facet;
typedef time_put<wchar_t,wosit>  tow_facet;

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes & functions into library (new C++ style)
template class _RWSTDExport timepunct_data<wchar_t>;
template class _RWSTDExport timepunct<wchar_t>;
template class _RWSTDExport time_reader<wchar_t,wisit>;

template class _RWSTDExport facet_maker<tpw_facet>;
template class _RWSTDExport facet_maker<tiw_facet>;
template class _RWSTDExport facet_maker<tow_facet>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes & functions into library (old Cfront style)
#pragma instantiate timepunct_data<wchar_t>
#pragma instantiate timepunct<wchar_t>
#pragma instantiate time_reader<wchar_t,wisit>

#pragma instantiate facet_maker<tpw_facet>
#pragma instantiate facet_maker<tiw_facet>
#pragma instantiate facet_maker<tow_facet>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION
#endif // _RWSTD_NO_WIDE_CHAR

#define moneypunct_data     moneypunct_data
#define money_reader_base_1 money_reader_base_1
#define money_reader_base_2 money_reader_base_2
#define money_reader        money_reader
#define money_writer_base_1 money_writer_base_1
#define money_writer_base_2 money_writer_base_2
#define money_writer        money_writer
#define facet_maker         facet_maker

#ifndef _RWSTD_NO_WIDE_CHAR
typedef moneypunct<wchar_t,false>       mpfw_facet;
typedef moneypunct<wchar_t,true>        mptw_facet;
typedef money_get<wchar_t,wisit>        miw_facet;
typedef money_put<wchar_t,wosit>        mow_facet;

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes & functions into library (new C++ style)
template class _RWSTDExport moneypunct_data<wchar_t>;
template class _RWSTDExport money_reader_base_1<wchar_t>;
template class _RWSTDExport money_reader_base_2<wchar_t,wisit>;
template class _RWSTDExport money_reader<wchar_t,wisit>;
template class _RWSTDExport money_writer_base_1<wchar_t>;
template class _RWSTDExport money_writer_base_2<wchar_t,wosit>;
template class _RWSTDExport money_writer<wchar_t,wosit>;

template class _RWSTDExport facet_maker<mpfw_facet>;
template class _RWSTDExport facet_maker<mptw_facet>;
template class _RWSTDExport facet_maker<miw_facet>;
template class _RWSTDExport facet_maker<mow_facet>;

template moneypunct_init<wchar_t>*
    _RWSTDExport fixup_moneypunct_init
    (moneypunct_init<char>*,wchar_t*);

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes & functions into library (old Cfront style)
#pragma instantiate moneypunct_init<wchar_t>* \
    fixup_moneypunct_init                     \
      (moneypunct_init<char>*,wchar_t*)

#pragma instantiate moneypunct_data<wchar_t>
#pragma instantiate money_reader_base_1<wchar_t>
#pragma instantiate money_reader_base_2<wchar_t,wisit>
#pragma instantiate money_reader<wchar_t,wisit>
#pragma instantiate money_writer_base_1<wchar_t>
#pragma instantiate money_writer_base_2<wchar_t,wosit>
#pragma instantiate money_writer<wchar_t,wosit>

#pragma instantiate facet_maker<mpfw_facet>
#pragma instantiate facet_maker<mptw_facet>
#pragma instantiate facet_maker<miw_facet>
#pragma instantiate facet_maker<mow_facet>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION
#endif // _RWSTD_NO_WIDE_CHAR

#define moneypunct_data     moneypunct_data
#define money_reader_base_1 money_reader_base_1
#define money_reader_base_2 money_reader_base_2
#define money_reader        money_reader
#define money_writer_base_1 money_writer_base_1
#define money_writer_base_2 money_writer_base_2
#define money_writer        money_writer
#define facet_maker         facet_maker

typedef moneypunct<char,false>      mpf_facet;
typedef moneypunct<char,true>       mpt_facet;
typedef money_get<char,isit>        mi_facet;
typedef money_put<char,osit>        mo_facet;
#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes & functions into library (new C++ style)
template class _RWSTDExport moneypunct_data<char>;
template class _RWSTDExport money_reader_base_1<char>;
template class _RWSTDExport money_reader_base_2<char,isit>;
template class _RWSTDExport money_reader<char,isit>;
template class _RWSTDExport money_writer_base_1<char>;
template class _RWSTDExport money_writer_base_2<char,osit>;
template class _RWSTDExport money_writer<char,osit>;

template class _RWSTDExport facet_maker<mpf_facet>;
template class _RWSTDExport facet_maker<mpt_facet>;
template class _RWSTDExport facet_maker<mi_facet>;
template class _RWSTDExport facet_maker<mo_facet>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes & functions into library (old Cfront style)
#pragma instantiate moneypunct_data<char>
#pragma instantiate money_reader_base_1<char>
#pragma instantiate money_reader_base_2<char,isit>
#pragma instantiate money_reader<char,isit>
#pragma instantiate money_writer_base_1<char>
#pragma instantiate money_writer_base_2<char,osit>
#pragma instantiate money_writer<char,osit>

#pragma instantiate facet_maker<mpf_facet>
#pragma instantiate facet_maker<mpt_facet>
#pragma instantiate facet_maker<mi_facet>
#pragma instantiate facet_maker<mo_facet>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION

#define timepunct       timepunct
#define timepunct_data  timepunct_data
#define time_reader     time_reader
#define facet_maker     facet_maker

typedef timepunct<char>      tp_facet;
typedef time_get<char,isit>  ti_facet;
typedef time_put<char,osit>  to_facet;

#ifndef _RWSTD_NO_EXPLICIT_INSTANTIATION

// Explicitly instantiate classes & functions into library (new C++ style)
template class _RWSTDExport timepunct_data<char>;
template class _RWSTDExport timepunct<char>;
template class _RWSTDExport time_reader<char,isit>;

template class _RWSTDExport facet_maker<tp_facet>;
template class _RWSTDExport facet_maker<ti_facet>;
template class _RWSTDExport facet_maker<to_facet>;

#else // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_INSTANTIATE

// Explicitly instantiate classes & functions into library (old Cfront style)
#pragma instantiate timepunct<char>
#pragma instantiate timepunct_data<char>
#pragma instantiate time_reader<char,isit>

#pragma instantiate facet_maker<tp_facet>
#pragma instantiate facet_maker<ti_facet>
#pragma instantiate facet_maker<to_facet>

#endif // _RWSTD_NO_INSTANTIATE
#endif // _RWSTD_NO_EXPLICIT_INSTANTIATION

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // _RW_STD_LOCALE

