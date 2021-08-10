#ifndef __RWSTDWIND_H__
#define __RWSTDWIND_H__

/***************************************************************************
 *
 * stdwind.h - Microsoft Windows related directives.
 *
 * $Id: stdwind.h,v 1.8 1995/09/29 22:11:45 smithey Exp $
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

/*
 * Special stuff for 16-bit Windows (__WIN16__)
 * and Windows NT / Win32s (__WIN32__).
 *
 * Under Windows, these header files can be used in two different modes:
 * as part of a DLL, or as part of a regular (static) library.
 * For each of these two ways, we can either be COMPILING the library,
 * or USING the library.  This makes a matrix of four possible situations.
 *
 *************************************************************************
 ******************************  DLL *************************************
 *************************************************************************
 *
 *                         Creating a DLL
 *
 * The macro __DLL__ should be define when compiling to create a DLL.
 *
 *     The Borland compilers automatically do this if either the -WD or
 *     -WDE switch is being used.  In this situation, the macros
 *     RWExport and rwexport expand to _export.
 *
 *     For other compilers, we must define __DLL__ where appropriate
 *     if the compiler doesn't.  See the example for Microsoft below.
 *
 *     RWExport and rwexport expand to _export by default.  Massage as
 *     necessary for your compiler; again see below for the Microsoft
 *     specific directives.
 *
 *                       Using the resultant DLL
 *
 * In order to use the resultant DLL, you must define the macro _RWSTDDLL
 * when compiling.  This will communicate to the Rogue Wave header files
 * your intention to use a DLL version of the Rogue Wave library.
 *
 * If you intend to use a DLL version of the Borland RTL as well, then you
 * should also define the macro _RTLDLL, as per Borland's instructions.
 *
 * You must also specify the -WS switch ("smart callbacks") for the 
 * Borland Compiler.
 *
 *
 *************************************************************************
 ***********************  Static Windows Library **************************
 *************************************************************************
 *
 *
 *                Creating a RW static Windows library
 *
 * If your intention is to create a Rogue Wave library to be used as 
 * as a static Windows library, then one of the macros __WIN16__ or __WIN32__
 * must have been defined in compiler.h (or by the compiler directly).
 *
 * Borland:	__WIN16__ will be defined if both _Windows and __MSDOS__ 
 *              is defined.  _Windows will be defined automatically if 
 *              any -W switch is used.  Borland defines __WIN32__ automatically
 *              in their 32-bit compiler for Windows NT / Win32s.
 *
 * Microsoft:	Microsoft automatically defines _WINDOWS if you use the
 *		/GA (preferred) or /GW switch. 
 *              __WIN32__ will only be defined if either it, or WIN32,
 *              is explicitly defined on the cl command line.
 *
 * 
 *                 Using a RW static Windows library
 *
 * Nothing special needs to be done.  Just link compile with the appropriate
 * compile switches and link in the RW static Windows library.
 *
 */


/*
 * Check for Microsoft C/C++ and massage as necessary.
 */
#if defined(_MSC_VER)
#  if defined(_WINDLL) && !defined(__DLL__)
#    define __DLL__ 1
#  endif
#  if !defined(_export)
#    define _export __export
#  endif
#endif

#ifdef  __TURBOC__
#  if __TURBOC__ > 0x468
#    define RWSTD_EXPORT_TEMPLATE
#  endif
#endif


/* For backwards compatibility: */
#if defined(_RWSTDCLASSDLL) && !defined(_RWSTDDLL)
# define _RWSTDDLL 1
#endif

#if defined(_RWSTDDLL)
#  if !defined(__LARGE__) && !defined(__WIN32__)
#    error   Must use large or flat memory model when compiling or using the Standard Library DLL!
#  endif
#  if defined(_RWSTDBUILDDLL)
     // Compiling the DLL.
#    ifndef _MSC_VER
#      define RWSTDExport _export	        /* Mark classes as exported */
#      ifdef RWSTD_EXPORT_TEMPLATE
#        define RWSTDExportTemplate _export	/* Mark template insts as exported */
#      else
#        define RWSTDExportTemplate 
#      endif
#      define rwexport _export	                /*    & functions as well   */
#    else /* Microsoft: */
#      define RWSTDExport __declspec(dllexport)
#      define RWSTDExportTemplate              
#      define rwexport __declspec(dllexport)
#    endif
#  else
     // Using the DLL.
#    if defined(__WIN16__)
#      define RWSTDExport huge	/* Mark classes as huge  */
#      define rwexport far	/*    & functions as far */
#    elif defined(__WIN32__)
#      ifndef _MSC_VER
#        define RWSTDExport _import     
#        ifdef RWSTD_EXPORT_TEMPLATE
#          define RWSTDExportTemplate _import
#        else
#          define RWSTDExportTemplate 
#        endif
#        define rwexport
#      else
#        define RWSTDExport  __declspec(dllimport)
#        define RWSTDExportTemplate 
#        define rwexport
#      endif  
#    endif
#  endif
#else
   // Neither compiling, nor using the  DLL.
#  define RWSTDExport
#  define RWSTDExportTemplate 
#  define rwexport
#endif

#endif // __RWSTDWIND_H__


