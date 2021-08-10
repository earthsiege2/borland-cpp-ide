/*------------------------------------------------------------------------*/
/*                                                                        */
/*  RESOURCE.H                                                            */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( CLASSLIB_RESOURCE_H )
#define CLASSLIB_RESOURCE_H

#if !defined( CLASSLIB_COMPILER_H )
#include <classlib/compiler.h>
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

#endif  // CLASSLIB_RESOURCE_H

