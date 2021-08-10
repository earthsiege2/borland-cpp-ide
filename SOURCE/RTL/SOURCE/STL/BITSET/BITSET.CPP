/***************************************************************************
 *
 * bitset.cpp - Source for the Standard Library string classes
 *
 * $Id: bitset.cpp,v 1.4 1995/09/29 23:53:51 smithey Exp $
 *
 * $$RW_INSERT_HEADER "slyrs.cpp"
 *
 **************************************************************************/

/* $Copyright: 1995$ */
/* $Revision:   8.2  $        */

#include <stdcomp.h>
#include <stddefs.h>

#ifndef RWSTD_NO_NAMESPACE
namespace std {
#endif

char RWSTDExport __rw_bitset_InvalidPosition[]     = "invalid bitset position";
char RWSTDExport __rw_bitset_InvalidCtorArgument[] = "invalid argument to bitset constructor";
char RWSTDExport  __rw_bitset_ConversionOverflow[]  = "overflow of bitset conversion to unsigned long";

#ifndef RWSTD_NO_NAMESPACE
}
#endif
