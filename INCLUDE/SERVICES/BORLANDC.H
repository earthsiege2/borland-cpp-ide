//----------------------------------------------------------------------------
// Borland Services Library
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   5.14  $
//
// Compiler-specific defines for Borland C/C++. Included only by compiler.h
//----------------------------------------------------------------------------
#if !defined(SERVICES_BORLANDC_H)
#define SERVICES_BORLANDC_H

//----------------------------------------------------------------------------
//  OS-specific flags defined here for DOS, Win16, Win32 & OS/2
//----------------------------------------------------------------------------

//
//  Define a platform flag.
//
//      BI_PLAT_MSW         Microsoft Windows, all versions including console
//      BI_PLAT_OS2         IBM OS/2
//      BI_PLAT_DOS         DOS
//
#if defined(_Windows) || defined(_WINDOWS) || defined(_WIN32)
# define BI_PLAT_MSW
#elif defined(__OS2__)
# define BI_PLAT_OS2
#else
# define BI_PLAT_DOS
#endif

//
//  Specify the Windows API if we're compiling for Windows. Must
//  define one of:
//
//      BI_PLAT_WIN16       Microsoft Windows 16
//      BI_PLAT_WIN32       Microsoft Win32
//
#if defined(BI_PLAT_MSW)
# if defined(_WIN32) || defined(__FLAT__)
#   define BI_PLAT_WIN32
# else
#   define BI_PLAT_WIN16
# endif
#endif

//
//  Define the memory model when compiling for Windows 16 or DOS. Must
//  define one of:
//
//      BI_MODEL_TINY       DOS/Windows tiny model
//      BI_MODEL_SMALL      DOS/Windows small model
//      BI_MODEL_COMPACT    DOS/Windows compact model
//      BI_MODEL_MEDIUM     DOS/Windows medium model
//      BI_MODEL_LARGE      DOS/Windows large model
//      BI_MODEL_HUGE       DOS/Windows huge model
//
#if defined( BI_PLAT_WIN16 ) || defined( BI_PLAT_DOS )
# if defined( __TINY__ )
#   define BI_MODEL_TINY
# elif defined( __SMALL__ )
#   define BI_MODEL_SMALL
# elif defined( __COMPACT__ )
#   define BI_MODEL_COMPACT
# elif defined( __MEDIUM__ )
#   define BI_MODEL_MEDIUM
# elif defined( __LARGE__ )
#   define BI_MODEL_LARGE
# elif defined( __HUGE__ )
#   define BI_MODEL_HUGE
# endif
#endif

//
//  Define the pointer size. Must define one of:
//
//      BI_PTR_16_16        Intel 16:16 pointer
//      BI_PTR_0_32         32-bit flat pointer (including Intel 0:32)
//
#if defined(__FLAT__) || defined(BI_PLAT_WIN32) || defined(BI_PLAT_OS2)
# define BI_PTR_0_32
#else
# define BI_PTR_16_16
#endif

//  Specify the size of data pointers and code
//  pointers if applicable. Must define one of:
//
//      BI_DATA_NEAR        16-bit pointer in 16:16 models
//      BI_DATA_FAR         32-bit pointer in 16:16 models
//      BI_DATA_HUGE        32-bit huge pointer in 16:16 models
//
//  Must also define one of:
//
//      BI_CODE_NEAR        16-bit pointer in 16:16 models
//      BI_CODE_FAR         32-bit pointer in 16:16 models
//
#if defined(BI_PTR_16_16)
# if defined(BI_MODEL_TINY) || defined(BI_MODEL_SMALL) || defined(BI_MODEL_MEDIUM)
#   define BI_DATA_NEAR
# elif defined(BI_MODEL_COMPACT) || defined(BI_MODEL_LARGE)
#   define BI_DATA_FAR
# else
#   define BI_DATA_HUGE
# endif
# if defined(BI_MODEL_TINY) || defined(BI_MODEL_SMALL) || defined(BI_MODEL_COMPACT)
#   define BI_CODE_NEAR
# else
#   define BI_CODE_FAR
# endif
#endif

//
//  Define the type of application being built. Must be one of:
//
//      BI_APP_EXECUTABLE
//      BI_APP_DLL
//
#if defined(__DLL__) || defined(_DLL)
# define BI_APP_DLL
#else
# define BI_APP_EXECUTABLE
#endif

//
//  Only enable multi-thread classes when the OS supports them, and/or when the
//  runtime library support them
//
#if defined(BI_PLAT_WIN32) || defined(BI_PLAT_OS2)
# define BI_MULTI_THREAD
#endif
#if defined(__MT__)
# define BI_MULTI_THREAD_RTL
#endif

//----------------------------------------------------------------------------
//  Compiler-specific flags.
//----------------------------------------------------------------------------

//
// Specific name of compiler, BI_COMP_xxxx
//
#define BI_COMP_BORLANDC

//
//  C++ language features
//
//  When compiling with a compiler that doesn't support these
//  features directly, remove the // from the appropriate
//  #define below or define the macro in the build environment.
//

// BC v5.0 introduces the ability to import/export templates
//
#if (__BORLANDC__ >= 0x500)
# define BI_IMPEXP_TEMPLATES // Import and export template instances
#endif

// BC has had these since 4.0
//
#if (__BORLANDC__ < 0x400)
# define BI_NO_ARRAYNEW      // operators new[] & delete[]   -
# define BI_NO_COVAR_RET     // Covariant returns in overrides -
# define BI_NO_RTTI          // RTTI and __rtti keyword      DEFS.H
# define BI_NO_THROWSPEC     // Function throw specifiers    EXCEPT.H
# define BI_NO_LVAL_CASTS    // Can cast lvalues
#endif

// These were not available previous to BC 5.0
//
#if (__BORLANDC__ < 0x500)
# define BI_NO_BOOL          // Standard bool type           DEFS.H
# define BI_NO_MUTABLE       // Mutable keyword              DEFS.H
# define BI_NO_NAMESPACE     // Namespaces
#endif

#if (__BORLANDC__ < 0x400)
# define BI_NO_NEW_CASTS     // New style casts              CASTABLE.H
#endif

//
// Hand define macros for BC 4.x to be compatible with win SDK headers
//
#if (__BORLANDC__ < 0x500)
# if !defined(_WCHAR_T_DEFINED)
#   define _WCHAR_T_DEFINED  // done already in win32/windows.h ?
# endif
# if defined(BI_PLAT_WIN32) && !defined(_WIN32)
#   define _WIN32
# endif
#endif

//
//  To use Borland's register calling conventions in the class library,
//  remove the // from the #define below and rebuild the libraries
//  with the -po command line switch.
//  Note: -po is only available for Borland's 16-bit optimizing compiler.
//
//#define _CLASSLIB_ALLOW_po  // use register calling convention
//                            // (must also use -po on command line)

#if defined(__BCOPT__) && !defined(__FLAT__) && !defined(_CLASSLIB_ALLOW_po)
# define BI_CLASSLIB_NO_po
#endif

#endif  // SERVICES_BORLANDC_H
