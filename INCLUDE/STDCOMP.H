#ifndef __STDRWCOMPILER_H__
#define __STDRWCOMPILER_H__ 1
/* $Revision:   8.3  $ */

/***************************************************************************
 *
 * Compiler and system related foibles and directives
 *
 * $Id: stdcomp.in,v 1.114 1995/10/03 17:26:32 smithey Exp $
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

/****************************************************************
 ****************************************************************
 *                                                              *
 *              U S E R   T U N A B L E   S E C T I O N         *
 *                                                              *
 ****************************************************************
 ****************************************************************/


/*
 * This section has various preprocessor constants that can
 * be set to reflect the properties of your compiler.  For most
 * compilers (particularly, MS-DOS compilers) there is no need
 * to do anything --- most settings can be autodetected.
 *
 * For many Unix compilers you may have to tune the settings below.
 * This is most easily done by running the "config" shell script
 * which will try various test programs to discover the properties
 * of your compiler.
 *
 *       THIS IS FAR EASIER THAN SETTING THESE BY HAND!
 */

/*
 *                   AT&T "CFRONT" USERS
 */


/*
 * Most compilers have a built in "manifest constant".
 * For the following compilers you must supply one by uncommenting
 * an appropriate line:
 *
 *   AT&T cfront V2.X:       __ATT2__
 *   AT&T cfront V3.0:       __ATT3__
 */

/* #define __ATT2__ 1 */
/* #define __ATT3__ 1 */

/**
 **                     *** ALL USERS ***
 **/


#define RWSTD_NOMSG    0x00
#define RWSTD_CATGETS  0x01
#define RWSTD_GETTEXT  0x02
#define RWSTD_DGETTEXT 0x03

/*
 * Set RWSTD_MESSAGE to the type of messaging facility you want:
 *   RWSTD_NOMSG         No messaging facility
 *   RWSTD_CATGETS  Use catgets()
 *   RWSTD_GETTEXT  Use gettext()
 *   RWSTD_DGETTEXT Use dgettext()
 */

#define RWSTD_MESSAGE RWSTD_NOMSG


#if !defined( __TURBOC__) && !defined(_MSC_VER)

/******************** COMPILER WORD SIZES, ETC ********************/

/*
 * Uncomment the following and set to the number of decimal digits
 * of precision for type double.
 * If you do nothing, the default will be 16.
 */

/* #define RWSTD_DEFAULT_PRECISION 16 */


/*************** COMPILER QUIRKS AND LIMITATIONS ******************/

/*
 * Uncomment the following if your compiler does not support
 * exceptions.
 */

/* #define RWSTD_NO_EXCEPTIONS 1 */

/*
 * Uncomment the following if your compiler does not support
 * exceptions specifications.
 */

/* #define RWSTD_NO_EX_SPEC 1 */


/*
 * Uncomment the following if your compiler does not support
 * throwing of exceptions from a shared library.
 */

/* #define RWSTD_NO_THROW_WITH_SHARED 1 */

/*************************** TEMPLATES **********************************/

/*
 * Uncomment the following if your compiler does not instantiates only those
 * functions, member functions, classes or member classes that are
 * required; i.e. your compiler instantiates things that your program
 * doesn't actually use.
 */

/* #define RWSTD_NO_STRICT_TEMPLATE_INSTANTIATE 1 */


/*
 * Uncomment the following if your compiler does template
 * instantiation at compile time.
 */

/* #define RWSTD_COMPILE_INSTANTIATE 1 */


/*************************** STRINGS ****************************/

/*
 * Uncomment the following if your sprintf() does not
 * return the size of the buffer as an int, as ANSI C requires.
 */

/* #define RWSTD_NO_ANSI_SPRINTF 1 */


/*
 * Uncomment the following if your compiler does not have the
 * ANSI C function memmove().
 */

/* #define RWSTD_NO_MEMMOVE 1 */


/****************** INTERNATIONALIZATION ************************/

/*
 * Uncomment the following if your compiler does not support
 * wide characters strings (e.g., functions wslen(), etc.).
 */

/* #define RWSTD_NO_WSTR 1 */


/*
 * Uncomment the following if the type wchar_t is just a typedef,
 * instead of a distinct type.
 */

/* #define RWSTD_NO_OVERLOAD_WCHAR 1 */


/*
 * Uncomment the following if your compiler does not support
 * the ANSI C locale facility fully, or if it does not support
 * it at all (in particular, uncomment if setlocale(), strxform(),
 * or strcoll() are not present or don't work).
 */

/* #define RWSTD_NO_LOCALE 1 */


/*
 * Uncomment the following if your compiler does not have
 * the %C directive to strftime().
 */

/* #define RWSTD_NO_STRFTIME_CAPC 1 */


/************************** TIME ********************************/

/*
 * Uncomment the following if your compiler does not have global
 * variables "_daylight", "_timezone", and "_tzname", or corresponding
 * variables without a leading underscore (generally
 * this is true only for pure Berkeley systems).
 */

/* #define RWSTD_NO_GLOBAL_TZ 1 */


/*
 * Uncomment the following if your system supplies a global variable
 * named "daylight" instead of the nominally more correct "_daylight".
 */

/* #define RWSTD_NO_LEADING_UNDERSCORE 1 */


/*
 * If your system does not have global variables "daylight" and
 * "timezone" (see directive immediately above) and does not have
 * the Berkeley function gettimeofday() either, then uncomment
 * the following:
 */

/* #define RWSTD_NO_GETTIMEOFDAY 1 */


/*
 * If the struct tm defined in your <time.h> has extra member data
 * "tm_zone" and "tm_gmtoff" (this is true for SunOs 4.X), then you
 * should uncomment the following:
 */

/* #define RWSTD_STRUCT_TM_TZ 1 */

/************************** STANDARD LIBRARY ****************************/

/*
 * Uncomment the following if your compiler does not support the bool type.
 * This means that bool is not a unique type.
 */

/* #define RWSTD_NO_BOOL 1 */

/*
 * Uncomment the following if your compiler does not support default
 * templates. e.g:
 * template<class T = int> ...
 */

/* #define RWSTD_NO_DEFAULT_TEMPLATES 1 */

/*
 * Uncomment the following if your compiler doesn't support ~T()
 * where T is a builtin.
 */

/* #define RWSTD_NO_DESTROY_BUILTIN 1 */

/*
 * Uncomment the following if your compiler doesn't support ~T()
 * where T is a non-builtin.
 */

/* #define RWSTD_NO_DESTROY_NONBUILTIN 1 */

/*
 * If your compiler does not support complicated exceptions, such as
 * throwing a domain_error exception, then uncomment the following:
 */

/* #define RWSTD_NO_COMPLICATED_EXCEPTIONS 1 */

/*
 * Uncomment the following if your compiler cannot handle nested
 * templates, or if you have to define the body of a class within
 * the template (mostly sun compilers!)
 */

/* #define RWSTD_NO_NESTING_TEMPLATES 1 */

/*
 * If your compiler does not support long double operators in iostreams, then
 * uncomment the following:
 */

/* #define RWSTD_NO_STREAM_LONG_DOUBLE 1 */

/*
 * Uncomment the following if your compiler does not support the
 * mutable keyword
 */

/* #define RWSTD_NO_MUTABLE 1 */

/*
 * If your compiler does not support namespaces, uncomment the following
 */

/* #define RWSTD_NO_NAMESPACE 1 */

/*
 * Uncomment the following if your compiler does not support
 * member template functions:
 * template<class T> class C {
 *  template<class F> void foo();
 * };
 */

/* #define RWSTD_NO_MEMBER_TEMPLATES 1 */


/*
 * Uncomment the following if your compiler does not support
 * member template classes:
 * class C {
 *  template <class F> class N {};
 * };
 */

/* #define RWSTD_NO_MEM_CLASS_TEMPLATES 1 */

/*
 * If nontype-args are not allowed in function declarations, then uncomment
 * the following.  template<int i> void foo(char f[10][i])
 */

/* #define RWSTD_NO_NONTYPE_ARGS 1 */

/*
 * If simple static initialization of const member variables is not allowed,
 * uncomment the following
 */

/* #define RWSTD_NO_STI_SIMPLE 1 */

/*
 * If complex static initialization of const member variables is not allowed,
 * uncomment the following
 */

/* #define RWSTD_NO_STI_COMPLEX 1 */


/*
 * If access to private types as return types outside the class
 * is allowed, uncomment the following.
 */

/* #define RWSTD_NO_PRIV_RET 1 */


/*
 * If nested static template variables cannot be defined outside the
 * class, uncomment this.
*/

/* #define RWSTD_NO_STATIC_DEF 1 */

/*
 * If static template variable definitions do not require initializers,
 * uncomment this.
 */

/* #define RWSTD_NO_STATIC_DEF2 1 */


/*
 * If templatized static data members do not work correctly, uncomment this.
 */

/* #define RWSTD_NO_STATIC_DEF3 1 */


/*
 * If declaration of a non-member op such as | is not allowed with user
 * defined types such as enums, uncomment the following
 */

/* #define RWSTD_NO_ENUM_OP 1 */

/*
 * Are long mangled names handled correctly by your compiler/linker?
 * If not, uncomment the following
 */

/* #define RWSTD_NO_LONG_NAME 1 */

/*
 * Are complicated typedefs handled by your compiler?
 * If not, uncomment the following
 */

/* #define RWSTD_NO_COMPLICATED_TYPEDEF 1 */

/*
 * If your compiler does not support template template classes, then
 * uncomment the following:
 * template<class T, template<class U> allocator>
 */

/* #define RWSTD_NO_TEMPLATE_TEMPLATE 1 */

/* If your compiler does not treat wide chars as a distinct
   type, uncomment the following */

/* #define RWSTD_NO_WIDE_CHAR 1 */

/*
 * If your compiler does not handle typedef scoping correctly,
 * then uncomment the following.
 */

/* #define RWSTD_NO_TYPEDEF_OVERLOAD 1 */

/*
 * If your compiler does not function match on template base classes
 * correctly, then uncomment the following.
 */

/* #define RWSTD_NO_BASE_CLASS_MATCH 1 */

/*
 * If your compiler does not handle forward specializations
 * correctly, then uncomment the following.
 */

/* #define RWSTD_NO_FORWARD_SPECIALIZATIONS 1 */

/*
 * If your compiler does not handle template types as return types
 * uncomment the following.
 */

/* #define RWSTD_NO_RET_TEMPLATE 1 */

/*
 * If your compiler does not understand explicit constructors, uncomment
 * the following.
 */

/* #define RWSTD_NO_EXPLICIT 1 */

/*
 * If your compiler does not understand explicit argument qualification,
 * uncomment the following.
 */

/* #define RWSTD_NO_EXPLICIT_ARG 1 */


/*
 * If your compiler does not understand the typename keyword, uncomment
 * the following.
 */

/* #define RWSTD_NO_TYPENAME 1 */

/*
 * Does your compiler instantiate templates correctly?  If not, uncomment
 * the following
 */

/* #define RWSTD_NO_INSTANTIATION 1 */

/*
 * Does your compiler instantiate typedefs of itself correctly?
 * If not, uncomment the following
 */

/* #define RWSTD_NO_TYPEDEF_INST 1 */

/*
 * Does your compiler instantiate templates with const types correctly?
 * If not, uncomment the following
 */

/* #define RWSTD_NO_CONST_INST 1 */

/*
 * Does your compiler assume trait typedefs are int? If not, uncomment
 * the following
 */

/* #define RWSTD_NO_INT_TYPEDEF 1 */

/*
 * Does your compiler give an ambiguity error on allocate()? If so, uncomment
 * the following
 */

/* #define RWSTD_NO_ARG_MATCH 1 */

/*
 * Does your compiler supply the new C++-style C headers?  If not,
 * uncomment the following
 */

/* #define RWSTD_NO_NEW_HEADER 1 */


/*
 * does your compiler provide a placement new definition?  If no,
 * uncomment the following
 */

/* #define RWSTD_NO_NEW_DECL 1 */

/*
 * does your compiler inherit typedefs in templates correctly?  If no,
 * uncomment the following
 */

/* #define RWSTD_NO_INHERITED_TYPEDEFS 1 */

/*
 * Does your compiler have difficulty with constructors in a return
 * statement?  If so then uncomment the following.
 */

/* #define RWSTD_NO_CTOR_RETURN 1 */

/*
 * Does your compiler have difficulty with undeclared friends?  If so
 * then uncomment the following.
 */

/* #define RWSTD_NO_UNDECLARED_FRIEND 1 */

/*
 * Does your compiler have trouble with structures that lack a default
 * constructor even when their instantiation is indirect?  If so
 * then uncomment the following.
 */

/* #define RWSTD_NO_MEMBER_WO_DEF_CTOR 1 */

/*
 * Does your compiler allow un-initialized static members?  If not
 * then uncomment the following.
 */

/* #define RWSTD_NO_UNINITIALIZED_STATIC_DEF 1*/

/*
 * Does your compiler allow member types as template parameters?  If not
 * then uncomment the following.
 */

/* #define RWSTD_NO_MEMBER_TYPE_TPARAM 1 */

/*
 * Does your compiler dis-allow the use of 'static' in the out of line
 * initialization of a static const member?  If so then uncomment the
 * following.
 */

/* #define RWSTD_NO_STATIC_MEM_DEF 1 */

/*
 * Does your compiler not allow default constructor syntax on built in
 * types. (e.g. int i = int();).  If so then uncomment the following.
 */

/* #define RWSTD_NO_BUILTIN_CTOR 1 */

/* Does your compiler not allow defaults for parameters in function
 * templates when the function parameter is a template parameter type.
 * If so then uncomment the following.
 */

/* #define RWSTD_NO_DEFAULT_FOR_TPARAM 1 */

/* Does your compiler not allow name injection.  For instance, does it
 * allow member function specializations to be declared but not defined,
 * so that the template versions of these functions will be used.
 * If not, then uncomment the following.
 */

/* #define RWSTD_NO_NAME_INJECTION 1 */

/* Does your compiler have problems overloading on function template
 * arguments that are partial specializations?
 * If so, then uncomment the following.
 */

/* #define RWSTD_NO_PART_SPEC_OVERLOAD 1 */

/* Does your compiler vendor supply wctype.h?
 * If not, then uncomment the following.
 */

/* #define RWSTD_NO_WCTYPE_H 1 */

/* Can your compiler handle explicit instantiations?
 * If so, then uncomment the following.
 */

/* #define RWSTD_NO_EXPLICIT_INSTANTIATION 1 */



/*************************************************************************
**************************************************************************
**                                                                      **
**              From here on, it's pretty much boilerplate              **
**              and rarely requires any tuning.                         **
**                                                                      **
**************************************************************************
**************************************************************************/


/************************ Cfront derivatives ******************************/

/* Any of these defines a cfront style compiler: */
#if defined(__ATT1__) || defined(__ATT2__) || defined(__ATT3__)
#  define __ATT__ 1
#endif

#endif // !(__TURBOC__) && !(_MSC_VER)

#define STARTWRAP
#define ENDWRAP


/*************************** Symantec *******************************/

/*
 * No longer supports Zortech.  Must have Symantec V6.0 or greater.
 */
#if defined(__SC__)
/*************************** For Macs *******************************/
#  if defined(macintosh)
#    define RWSTD_CRLF_CONVENTION       1
#    define RWSTD_NO_EXCEPTIONS         1
#    define RWSTD_NO_GETTIMEOFDAY       1
#    define RWSTD_NO_FRIEND_INLINE_DECL 1
#    define RWSTD_NO_GLOBAL_TZ          1
#    define RWSTD_NO_LOCALE             1
#    define RWSTD_NO_OVERLOAD_WCHAR     1
#    define RWSTD_NO_WSTR               1
/*************************** For PC's *******************************/
#  else
#    define __MSDOS__                1
#    define RWSTD_COMPILE_INSTANTIATE   1

#    if (__SC__ <= 0x610)
#      define RWSTD_NO_EXCEPTIONS       1
#      define RWSTD_NO_GETTIMEOFDAY     1
#      define RWSTD_NO_GLOBAL_TZ        1
#      define RWSTD_NO_OVERLOAD_WCHAR   1
#      define RWSTD_NO_WSTR             1
#    endif
#  endif
#endif

/********************** Borland's Turbo C++ **************************/

#if defined(__TURBOC__)

#define RWSTD_NO_LONG_HEADER_NAME          1

#  if defined(__MSDOS__) && defined(_Windows)
#    define __WIN16__ 1
#  endif

/*
 * For Borland, the __export keyword in a function declaration must
 * come after the return type:
 */
#  define RWSTD_TRAILING_RWEXPORT 1
   /*
    * Turbo and Borland won't inline code that contains
    * "while" or "for" loops or that generates temporaries
    * requiring destructors:
    */
#  define RWSTD_NO_INLINED_WHILES           1
#  define RWSTD_NO_INLINED_FORS             1
#  define RWSTD_NO_INLINED_TEMP_DESTRUCTORS 1

   /* The Borland compilers left out this definition: */
#  define name2 _Paste2

   /* Turbo C++ V1.00 forgets the segment address when passing
      a class as a far reference if the class has not been defined. */
#  if __TURBOC__ <= 0x0295
#    define RWSTD_UNDEFINED_REFERENCE_BUG       1
#  endif

#  if __TURBOC__ >=0x200

/*
 *  In Borland C++ versions previous to 4.0, wchar_t is not a
 *  built-in type and there are no exceptions
 */
#    if __TURBOC__ < 0x449
#      define RWSTD_NO_EXCEPTIONS         1
#      define RWSTD_NO_FRIEND_INLINE_DECL 1
#      define RWSTD_NO_OVERLOAD_WCHAR     1
#    endif
#    if __TURBOC__ < 0x469
#      define RWSTD_NO_BOOL                         1
#      define RWSTD_NO_DEFAULT_TEMPLATES            1
#      define RWSTD_NO_FORWARD_DEFAULT_TEMPLATES    1
#      define RWSTD_NO_LOCALE                       1
#      define RWSTD_NO_MUTABLE                      1
#      define RWSTD_NO_NAMESPACE                    1
#      define RWSTD_NO_EXPLICIT                     1
#      define RWSTD_NO_EXPLICIT_ARG                 1
#      define RWSTD_NO_MEMBER_TEMPLATES             1
#      define RWSTD_NO_MEM_CLASS_TEMPLATES          1
#      define RWSTD_NO_NESTING_TEMPLATES            1
#      define RWSTD_NO_NEW_HEADER                   1
#      define RWSTD_NO_NONTYPE_ARGS                 1
#      define RWSTD_NO_STATIC_DEF3                  1
#      define RWSTD_NO_STI_COMPLEX                  1
#      define RWSTD_NO_STI_SIMPLE                   1
#      define RWSTD_NO_PRIV_RET                     1
#      define RWSTD_NO_TEMPLATE_TEMPLATE            1
#      define RWSTD_NO_DESTROY_BUILTIN              1
#      define RWSTD_NO_TYPENAME                     1
#      define RWSTD_NO_CONST_INST                   1
#      define RWSTD_NO_LONG_NAME                    1
#      define RWSTD_NO_FORWARD_SPECIALIZATIONS      1
#      define RWSTD_NO_PART_SPEC_OVERLOAD           1
#      define RWSTD_NO_EXPLICIT_INSTANTIATION       1

#elif __TURBOC__ <= 0x520
/*
 *   Borland 5.0:
 *   implements namespaces, bool and mutable
 */
#      define RWSTD_NO_DEFAULT_TEMPLATES            1
#      define RWSTD_NO_FORWARD_DEFAULT_TEMPLATES    1
#      define RWSTD_NO_LOCALE                       1
#      define RWSTD_NO_EXPLICIT                     1
#      define RWSTD_NO_EXPLICIT_ARG                 1
#      define RWSTD_NO_MEMBER_TEMPLATES             1
#      define RWSTD_NO_MEM_CLASS_TEMPLATES          1
#      define RWSTD_NO_NESTING_TEMPLATES            1
#      define RWSTD_NO_NEW_HEADER                   1
#      define RWSTD_NO_NONTYPE_ARGS                 1
#      define RWSTD_NO_STATIC_DEF3                  1
#      define RWSTD_NO_STI_COMPLEX                  1
#      define RWSTD_NO_STI_SIMPLE                   1
#      define RWSTD_NO_PRIV_RET                     1
#      define RWSTD_NO_TEMPLATE_TEMPLATE            1
#      define RWSTD_NO_DESTROY_BUILTIN              1
#      define RWSTD_NO_TYPENAME                     1
#      define RWSTD_NO_CONST_INST                   1
#      define RWSTD_NO_LONG_NAME                    1
#      define RWSTD_NO_COMPLICATED_TYPEDEF          1
#      define RWSTD_NO_PART_SPEC_OVERLOAD           1
#      define RWSTD_NO_SPEC_OVERLOAD                1
#      define RWSTD_NO_EX_SPEC                      1
#      define RWSTD_BC5_ENUM_BUG                    1

#    endif
/*
 *   If the win32 API is available we can supply the WC string stuff
 *   for Borland (except for wcsxfrm for now)
 */
#    ifdef __WIN32__
/*   This is temporarily commented out until stdlib support this
          partial wide string implementation */
/* #      define RWSTD_SUPPLY_WSTR 1
        #      define RWSTD_NO_WCSXFRM  1    */
#      define RWSTD_NO_WSTR     1
#    else
#      define RWSTD_NO_WSTR     1
#    endif

#    ifdef __MT__
#      define RWSTD_MULTI_THREAD 1
#    endif

#  endif        /* end post Turbo C++ V1.01 section */
#endif  /* __TURBOC__ */

/************************ Microsoft C/C++ *****************************/

#if defined(_MSC_VER)


#  define RWSTD_MSC_BACKEND       1


/* MSVC version 2.1 */
#if _MSC_VER < 901
#      define RWSTD_NO_BASE_CLASS_MATCH             1
#      define RWSTD_NO_CTOR_RETURN                  1
#      define RWSTD_NO_UNDECLARED_FRIEND            1
#      define RWSTD_NO_MEMBER_WO_DEF_CTOR           1
#      define RWSTD_NO_UNINITIALIZED_STATIC_DEF     1
#      define RWSTD_NO_DEFAULT_FOR_TPARAM           1
#      define RWSTD_NO_FORWARD_SPECIALIZATIONS      1
#      define RWSTD_NO_MEMBER_TYPE_TPARAM           1
#      define RWSTD_NO_NAME_INJECTION               1
#      define RWSTD_NO_LONG_HEADER_NAME             1
#      define RWSTD_NO_OVERLOAD_WCHAR               1
#      define RWSTD_NO_WCTYPE_H                     1
#      define RWSTD_NO_PART_SPEC_OVERLOAD           1
#      define RWSTD_NO_BOOL                         1
#      define RWSTD_NO_DEFAULT_TEMPLATES            1
#      define RWSTD_NO_FORWARD_DEFAULT_TEMPLATES    1
#      define RWSTD_NO_LOCALE                       1
#      define RWSTD_NO_MUTABLE                      1
#      define RWSTD_NO_NAMESPACE                    1
#      define RWSTD_NO_EXPLICIT                     1
#      define RWSTD_NO_EXPLICIT_ARG                 1
#      define RWSTD_NO_MEMBER_TEMPLATES             1
#      define RWSTD_NO_MEM_CLASS_TEMPLATES          1
#      define RWSTD_NO_NESTING_TEMPLATES            1
#      define RWSTD_NO_NEW_HEADER                   1
#      define RWSTD_NO_NONTYPE_ARGS                 1
#      define RWSTD_NO_STATIC_DEF                   1
#ifdef _RWSTDDLL
#      define RWSTD_NO_STATIC_DEF3                  1
#endif
#      define RWSTD_NO_STI_COMPLEX                  1
#      define RWSTD_NO_STI_SIMPLE                   1
#      define RWSTD_NO_PRIV_RET                     1
#      define RWSTD_NO_TEMPLATE_TEMPLATE            1
#      define RWSTD_NO_TYPENAME                     1
#      define RWSTD_NO_BUILT_IN_CTOR                1
#      define RWSTD_NO_NEW_DECL                     1
#      define RWSTD_COMPILE_INSTANTIATE             1
#      define RWSTD_NO_DESTROY_NONBUILTIN           1
#      define RWSTD_NO_STATIC_MEM_DEF               1
#      define RWSTD_NO_TEMPLATE_SPECIALIZATION      1
#      define RWSTD_NO_EXCEPTIONS                   1

/* MSVC version 3.0 */
#elif _MSC_VER < 1001
#      define RWSTD_NO_BOOL                         1
#      define RWSTD_NO_DEFAULT_TEMPLATES            1
#      define RWSTD_NO_FORWARD_DEFAULT_TEMPLATES    1
#      define RWSTD_NO_LOCALE                       1
#      define RWSTD_NO_MUTABLE                      1
#      define RWSTD_NO_NAMESPACE                    1
#      define RWSTD_NO_EXPLICIT                     1
#      define RWSTD_NO_EXPLICIT_ARG                 1
#      define RWSTD_NO_MEMBER_TEMPLATES             1
#      define RWSTD_NO_MEM_CLASS_TEMPLATES          1
#      define RWSTD_NO_LONG_HEADER_NAME             1
#      define RWSTD_NO_NEW_HEADER                   1
#      define RWSTD_NO_NONTYPE_ARGS                 1
#      define RWSTD_NO_STATIC_DEF                   1
#ifdef _RWSTDDLL
#      define RWSTD_NO_STATIC_DEF3                  1
#endif
#      define RWSTD_NO_STI_COMPLEX                  1
#      define RWSTD_NO_STI_SIMPLE                   1
#      define RWSTD_NO_PRIV_RET                     1
#      define RWSTD_NO_TEMPLATE_TEMPLATE            1
#      define RWSTD_NO_TYPENAME                     1
#      define RWSTD_NO_BUILT_IN_CTOR                1
#      define RWSTD_COMPILE_INSTANTIATE             1
#      define RWSTD_NO_DESTROY_NONBUILTIN           1
#      define RWSTD_NO_STATIC_MEM_DEF               1
#      define RWSTD_NO_OVERLOAD_WCHAR               1
#      define RWSTD_NO_WCTYPE_H                     1
#      define RWSTD_NO_OVERLOAD_FUNC_PTR            1
#      define RWSTD_NO_TEMPLATE_SPECIALIZATION      1
#      define RWSTD_NO_PART_SPEC_OVERLOAD           1
#      define RWSTD_NO_CONST_INST                   1
#      define RWSTD_NO_EX_SPEC                      1

#endif

#  if defined(_MSDOS) && !defined(WIN32) && !defined(_WIN32)
#    define __MSDOS__   1
#    if defined(_WINDOWS)
#      define __WIN16__ 1
#    endif
#  endif
#  if defined(WIN32) || defined(_WIN32)
#    define __WIN32__
#    define RWSTD_TOLOWER_SIGN_EXTENDS_RESULT_BUG 1
#  else
#    define RWSTD_NO_WSTR 1
#  endif

#  ifdef _RWBUILDDLL
#    define __DLL__ 1
#  endif

#  ifdef _M_I86SM
#    define __SMALL__ 1
#  endif
#  ifdef _M_I86CM
#    define __COMPACT__ 1
#  endif
#  ifdef _M_I86MM
#    define __MEDIUM__ 1
#  endif
#  ifdef _M_I86LM
#    define __LARGE__ 1
#  endif
#  ifdef _MT
#    define RWSTD_MULTI_THREAD 1
#  endif
#endif


/********************** Metaware High C/C++ ***************************/

#if defined(__HIGHC__)
#  define RWSTD_NO_OVERLOAD_WCHAR 1
#  if defined(_MSDOS)
#    define __MSDOS__ 1
#    define RWSTD_HIGHC_INLINE_BUG  1
#    define RWSTD_NO_EXCEPTIONS     1
#    define RWSTD_NO_WSTR 1
#  endif

#  if defined(_OS2)
#    undef __OS2__
#    define __OS2__ 1
#    define RWSTD_SUPPLY_WSTR 1
#    define RWSTD_NO_WCSXFRM  1
#    ifdef _REENTRANT
#      define RWSTD_MULTI_THREAD 1
#    endif
#  endif

#  if defined(_MSNT)
#    undef __WIN32__
#    define __WIN32__ 1
#    define RWSTD_NO_WSTR 1
#    if defined(_REENTRANT) || defined(_MT)
#      define RWSTD_MULTI_THREAD 1
#    endif
#  endif

#endif  /* __HIGHC__ */

/************************** MPW *************************************/

#if defined(applec)
#  define RWSTD_BROKEN_TOKEN_PASTE    1
#  define RWSTD_REVERSED_CR_AND_LF    1
#  define RWSTD_NATIVE_EXTENDED       1
#  define RWSTD_NO_ACCESS_ADJUSTMENT  1
#  define RWSTD_NO_EXCEPTIONS         1
#  define RWSTD_NO_GETTIMEOFDAY       1
#  define RWSTD_NO_GLOBAL_TZ          1
#  define RWSTD_NO_LEADING_UNDERSCORE 1
#  define RWSTD_NO_OSTR_REF_CAST      1
#  define RWSTD_NO_OVERLOAD_WCHAR     1
#  define RWSTD_NO_WSTR               1
#endif

/********************** IBM C/Set++   *********************************/

#ifdef __IBMCPP__
#  define RWSTD_NO_WSTR           1
#  ifdef __MULTI__
#    define RWSTD_MULTI_THREAD 1
#  endif
#endif

/********************** IBM xlC   *********************************/

#if defined(_AIX) && !defined(unix)
#define unix 1
#endif

/********************** Miscellaneous *********************************/

/*
 * These compilers instantiate templates at compile-time;
 * others at link-time.
 */
#if defined(__TURBOC__) || defined(__HIGHC__) || defined(__xlC__) || defined(__GNUG__) || defined(__WATCOMC__) || defined(__IBMCPP__) || defined(__os_cplusplus)
# define RWSTD_COMPILE_INSTANTIATE 1
#endif

/* No Pi for these compilers: */
#if defined(RWSTD_MSC_BACKEND) || defined(__OREGON__) || defined(__HIGHC__) || defined(applec) || defined(CII) || defined(__WATCOMC__)
#  ifndef M_PI
#    define M_PI 3.14159265358979323846
#  endif
#endif

/*
 * Only Sun defines strftime("%C", ...)
 */
#if !defined(RWSTD_NO_STRFTIME_CAPC) && !defined(sun)
#define RWSTD_NO_STRFTIME_CAPC 1
#endif

/********************** Environment *********************************/
/*
 * This is the section for setting things which depend on the properties
 * of the operating systems rather than specific compilers.  It follows
 * the compiler section so we have the chance to rationalize the different
 * preprocessor constants (e.g. _MSDOS vs. __MSDOS__,  _M_I86LM vs. __LARGE__)
 */

#ifndef RWSTD_DEFAULT_PRECISION
#   define RWSTD_DEFAULT_PRECISION 16   /* Assume standard IEEE format */
#endif

/*
 * Most (but not all) non-unix systems convert new line to carriage
 * return / line feed on output:
 */
#if defined(__MSDOS__) || defined(__OS2__) || defined(__WIN32__) || defined(__NT__) || defined(__WINDOWS__)
#  define RWSTD_CRLF_CONVENTION 1
#endif

/*
** Miscellaneous workarounds.
*/

#ifdef RWSTD_NO_BOOL
typedef int     bool;
#define true    1
#define false   0
#endif

#ifdef RWSTD_NO_TYPENAME
#define typename
#endif

#ifdef RWSTD_NO_EXPLICIT
#define explicit
#endif

#ifndef RWSTD_NO_INLINED_WHILES
#define RWSTD_WHILE_INLINE inline
#endif

#ifndef RWSTD_NO_INLINED_FORS
#define RWSTD_FOR_INLINE inline
#endif

#ifndef RWSTD_NO_INLINED_TEMP_DESTRUCTORS
#define RWSTD_TEMP_DTOR_INLINE inline
#endif

#ifdef RWSTD_NO_MEMBER_WO_DEF_CTOR
#define RWSTD_NO_CONST_INST
#endif

#define RWSTD_MB_CUR_MAX 16  //???  Need to find absolute maximum for this

#include <compnent.h>

//
// Define a generic macro for throw.  To be used as in the following:
//
//    RWSTD_THROW(i < j && j < k, out_of_range, "j is out of range!");
//
//                ^ predicate     ^ exception   ^ message
//
// literally, if (predicate) throw exception(message)
//
#ifdef RWSTD_NO_EXCEPTIONS
//
// If we don't have exceptions, then we'll use assert.
// We don't allow them to turn off the assert() in which such
// a thrown exception would result.
//

#ifdef  NDEBUG
#define __RW_NDEBUG
#undef  NDEBUG
#endif
#ifndef RWSTD_NO_NEW_HEADER
#include <cassert>
#else
#include <assert.h>
#endif
#define RWSTD_THROW(PRED,EXC,MESG) assert(!(PRED))
//
// We must also turn off expansion of assert() if that's what the user expects.
//
#ifdef  __RW_NDEBUG
#define NDEBUG
#undef  __RW_NDEBUG
#endif
#else /*!RWSTD_NO_EXCEPTIONS*/
//
// We must check to see if we can use <stdexcept> or just a string.
//
#ifdef RW_STD_EXCEPT
#define RWSTD_THROW(PRED,EXC,MESG) (PRED) ? throw EXC(MESG) : 0
#else
#define RWSTD_THROW(PRED,EXC,MESG) (PRED) ? throw (MESG)    : 0
#endif
#endif /*RWSTD_NO_EXCEPTIONS*/

//
// Define two generic throw specification macros.  One to illustrate
// the exceptions that a function can throw and the other to indicate
// that a function doesn't throw any exceptions.
//
//   RWSTD_THROW_SPEC(ExceptionList)
//
//   RWSTD_THROW_SPEC_NULL
//
// Owing to the face that the first macro must be able to take a
// variable number of arguments, we must simulate this by always
// passing the exceptions in parentheses; i.e.
//
//  void f () RWSTD_THROW_SPEC((out_of_range));
//  void g () RWSTD_THROW_SPEC((domain_error, invalid_argument));
//  void h () RWSTD_THROW_SPEC((out_of_range, invalid_argument, length_error));
//

#if defined(RWSTD_NO_EXCEPTIONS) || defined(RWSTD_NO_EX_SPEC)
#define RWSTD_THROW_SPEC(EXCEPTIONS) /**/
#define RWSTD_THROW_SPEC_NULL        /**/
#else
#ifdef RW_STD_EXCEPT
//
// RWSTD_THROW will use the exceptions in <stdexcept>
//
#define RWSTD_THROW_SPEC(ExceptionList) throw ExceptionList
#define RWSTD_THROW_SPEC_NULL           throw()
#else
//
// RWSTD_THROW will only throw const char *
//
#define RWSTD_THROW_SPEC(ExceptionList) throw(const char *)
#define RWSTD_THROW_SPEC_NULL           throw()
#endif
#endif /*RWSTD_NO_EXCEPTIONS||RWSTD_NO_EX_SPEC*/

#endif /*__RWSTDCOMPILER_H__*/
