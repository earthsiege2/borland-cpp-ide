/*------------------------------------------------------------------------*/
/*                                                                        */
/*  RESOURCE.H                                                            */
/*                                                                        */
/*  Copyright (c) 1991, 1993 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CLASSLIB_RESOURCE_H )
#define __CLASSLIB_RESOURCE_H

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Compiler-specific flags.                                              */
/*                                                                        */
/*------------------------------------------------------------------------*/

//------------------------------------------------
//
//  When compiling with a compiler that doesn't support various new
//  language features, remove the // from the appropriate 
//  #define below and rebuild the libraries.
//

//  #define BI_NO_RTTI          // runtime type information
//  #define BI_NO_NEW_CASTS     // new style casts

//------------------------------------------------
//
//  To restore the old naming convention of data and function
//  names beginning with lowercase letters, in addition to the
//  new convention of uppercase letters, remove the // from the
//  #define below. The libraries do not need to be rebuilt.
//

//  #define BI_OLDNAMES         // add names with initial lowercase

//------------------------------------------------
//
//  To use register calling conventions in the class library,
//  remove the // from the #define below and rebuild the libraries
//  with the -po command line switch.
//

//  #define _CLASSLIB_ALLOW_po  // use register calling convention
//                              // (must also use -po on command line)

//------------------------------------------------
//
//  -po is only available for the 16-bit optimizing compiler.
//
#if defined(__BCOPT__) && !defined(__FLAT__) && !defined(_CLASSLIB_ALLOW_po)
#define BI_CLASSLIB_NO_po
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  OS-specific flags.                                                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

//
//  Only enable multi-thread classes when the OS supports them.
//
#if defined(__WIN32__) || defined(__OS2__)
#define BI_MULTI_THREAD
#endif

//
//  Need to do some special stuff when the OS doesn't support
//  per-instance data in DLLs.
//
#if defined(_Windows) && !defined(__FLAT__)
#define BI_NO_PER_INSTANCE_DATA
#endif

//
//  Windows 3.1 provides functions to read and write huge buffers.
//
#if defined(_Windows) && WINVER >= 0x030A && !defined(__FLAT__)
#define BI_HAS_HREADWRITE
#endif

//
//  Under Windows 3.0 WEPs are seriously broken.
//
#if defined(__DLL__) && defined(_Windows) && WINVER < 0x030A
#define BI_WINDOWS_WEP_BUG      // no destructors for static objects in a DLL
#endif

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  Set up some default sizes for containers.                             */
/*                                                                        */
/*------------------------------------------------------------------------*/

const DEFAULT_HASH_TABLE_SIZE   = 111;
const DEFAULT_BAG_SIZE          =  29;
const DEFAULT_SET_SIZE          =  29;
const DEFAULT_DEQUE_SIZE        =  20;
const DEFAULT_QUEUE_SIZE        =  20;
const DEFAULT_STACK_SIZE        =  20;
const DEFAULT_ARRAY_SIZE        =  20;
const DEFAULT_DICT_SIZE         =  20;

#endif  // __CLASSLIB_RESOURCE_H

