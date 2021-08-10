/*------------------------------------------------------------------------*/
/*                                                                        */
/*  TMPLINST.CPP                                                          */
/*                                                                        */
/*  Copyright (c) 1991, 1994 Borland International                        */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*  Provides instantiations of the various Object containers,             */
/*  for use in the class library DLLs.                                    */
/*                                                                        */
/*------------------------------------------------------------------------*/

#pragma option -Jgd

#if !defined( __HASHTBL_H )
#include <classlib\obsolete\hashtbl.h>
#endif

#if !defined( CLASSLIB_OBJSTRM_H )
#include <classlib/objstrm.h>
#endif

// needed for HashTable
typedef TIVectorImp<Object> dummy1;

// needed for Object Streaming
typedef TSVectorImp<TPWrittenObjects::TPWObj> dummy2;
typedef TCVectorImp<const void *> dummy3;
typedef TISVectorImp<TStreamableClass> dummy4;

#if !defined( CLASSLIB_VECTIMP_H )
#include <classlib/vectimp.h>
#endif

#if !defined( CLASSLIB_STACKS_H )
#include <classlib/stacks.h>
#endif

#if !defined( CLASSLIB_QUEUES_H )
#include <classlib/queues.h>
#endif

#if !defined( CLASSLIB_LISTIMP_H )
#include <classlib/listimp.h>
#endif

#if !defined( CLASSLIB_DLISTIMP_H )
#include <classlib/dlistimp.h>
#endif

#if !defined( CLASSLIB_DEQUES_H )
#include <classlib/deques.h>
#endif

#if !defined( CLASSLIB_SETS_H )
#include <classlib/sets.h>
#endif

typedef TSDoubleListImp<void _FAR *> dummy6;
typedef TDoubleListIteratorImp<void _FAR *> dummy7;

typedef TIDequeAsVector<Object> dummy8;
typedef TIDequeAsVectorIterator<Object> dummy9;

typedef TIDequeAsDoubleList<Object> dummy10;
typedef TIDequeAsDoubleListIterator<Object> dummy11;

typedef TSListImp<void _FAR *> dummy12;
typedef TListIteratorImp<void _FAR *> dummy13;

typedef TIQueueAsVector<Object> dummy14;
typedef TIQueueAsVectorIterator<Object> dummy15;

typedef TIQueueAsDoubleList<Object> dummy16;
typedef TIQueueAsDoubleListIterator<Object> dummy17;

typedef TIStackAsVector<Object> dummy18;
typedef TIStackAsVectorIterator<Object> dummy19;

typedef TIStackAsList<Object> dummy20;
typedef TIStackAsListIterator<Object> dummy21;

typedef TVectorImp<void _FAR *> dummy22;
typedef TCVectorImp<void _FAR *> dummy23;
typedef TSVectorImp<void _FAR *> dummy24;
typedef TMVectorIteratorImp<void _FAR *,TStandardAllocator> dummy25;

typedef TISetAsVector<Object> dummy26;
typedef TISetAsVectorIterator<Object> dummy27;

typedef TICVectorImp<Object> dummy28;
