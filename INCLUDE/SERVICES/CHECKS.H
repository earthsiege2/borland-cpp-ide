//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//
//$Revision:   5.5  $
//
// Diagnostic macros for checking:
//
//   PRECONDITION[X]  Assert that a precondition is met
//   CHECK[X]         Check that a state meets assumptions
//   TRACE[X]         Output a tracing text stream
//   WARN[X]          Output a warning text stream
//
// Based on the following switches:
//   __DEBUG = 0   PRECONDITION and CHECK are nops
//   __DEBUG = 1   PRECONDITION is active
//   __DEBUG = 2   PRECONDITION and CHECK are active
//   __TRACE       When defined enables TRACE
//   __WARN        When defined enables WARN
//
//----------------------------------------------------------------------------
#if !defined(SERVICES_CHECKS_H)
#define SERVICES_CHECKS_H

#if !defined(SERVICES_DEFS_H)
# include <services/defs.h>
#endif


#if defined(BI_COMP_BORLANDC)
# if defined(BI_PLAT_MSW) && !defined(SERVICES_WSYSINC_H)
#   include <services/wsysinc.h>  // Let services get MSW headers, not RTL
# endif
# include <checks.h>
#else
# include <services/private/checks.h>
#endif  

#endif  
