//
//**************************************************************************
//
// BOle.h -- Common private header file for BOle modules.
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#ifndef _BOLE_H
#define _BOLE_H 1

#pragma warn -par	// Turn off warning "Parameter is never used"

#include <BOle32.h>


#if !defined(__DEFS_H)
  #include <_defs.h>
#endif

#if !defined(__WINDOWS_H)
//  #undef NULL
  #define STRICT
  #include <windows.h>
#endif


#include <Ole2.h>
#include <BOleintf.h>		// ole2 must come before boleintf.h
#if defined(WIN32)
  #include <oleauto.h>
#else
  #include <Dispatch.h>
#endif

#define OLE    /* use OLE::func to disambiguate OLEAPI global functions */
#define WIN    /* use WIN::func to disambiguate WINAPI global functions */
#define OUI    /* use OUI::func to identify helper funcs not part of OLE.DLL */
//#undef NOERROR  /* OLE defines as simply 0 */
//#define NOERROR ((void FAR*)0L)

#if defined(INITGUID)
  #if defined(WIN32)
  #include <cguid.h>
  #else
  #include <oleguid.h>
  #endif
#endif

PREDECLARE_INTERFACE(IClassFactory)
PREDECLARE_INTERFACE(IDropSource)
PREDECLARE_INTERFACE(IDropTarget)
PREDECLARE_INTERFACE(IPersist)
PREDECLARE_INTERFACE(IPersistFile)
PREDECLARE_INTERFACE(IPersistStream)
PREDECLARE_INTERFACE(IOleClientSite)
PREDECLARE_INTERFACE(IAdviseSink)
PREDECLARE_INTERFACE(IDataObject)
PREDECLARE_INTERFACE(IOleObject)
PREDECLARE_INTERFACE(IViewObject)
PREDECLARE_INTERFACE(IViewObject2)
PREDECLARE_INTERFACE(IPersistStorage)
PREDECLARE_INTERFACE(IMalloc)

PREDECLARE_INTERFACE(IParseDisplayName)
PREDECLARE_INTERFACE(IOleContainer)
PREDECLARE_INTERFACE(IOleItemContainer)

// In-place interfaces
PREDECLARE_INTERFACE(IOleWindow)
PREDECLARE_INTERFACE(IOleInPlaceActiveObject)
PREDECLARE_INTERFACE(IOleInPlaceObject)
PREDECLARE_INTERFACE(IOleInPlaceSite)
PREDECLARE_INTERFACE(IOleInPlaceUIWindow)
PREDECLARE_INTERFACE(IOleInPlaceFrame)

// Automation interfaces

PREDECLARE_INTERFACE(IDispatch)

// assorted hookables
PREDECLARE_INTERFACE(IMarshal)
PREDECLARE_INTERFACE(IEnumUnknown)
PREDECLARE_INTERFACE(IEnumString)
PREDECLARE_INTERFACE(IEnumSTATDATA)
PREDECLARE_INTERFACE(IEnumFORMATETC)
PREDECLARE_INTERFACE(IEnumOLEVERB)
PREDECLARE_INTERFACE(IEnumMoniker)
PREDECLARE_INTERFACE(IRunningObjectTable)
PREDECLARE_INTERFACE(IMoniker)
PREDECLARE_INTERFACE(IBindCtx)
PREDECLARE_INTERFACE(IRootStorage)
PREDECLARE_INTERFACE(IStorage)
PREDECLARE_INTERFACE(IStream)
PREDECLARE_INTERFACE(ILockBytes)
PREDECLARE_INTERFACE(IEnumSTATSTG)
PREDECLARE_INTERFACE(IOleLink)
PREDECLARE_INTERFACE(IDataAdviseHolder)
PREDECLARE_INTERFACE(IAdviseSink2)
PREDECLARE_INTERFACE(IOleAdviseHolder)
PREDECLARE_INTERFACE(IOleCache)
PREDECLARE_INTERFACE(IExternalConnection)
PREDECLARE_INTERFACE(IRunnableObject)

//DEFINE_INLINE_QI(IClassFactory,IUnknown)		// moved to boledefs.h
DEFINE_INLINE_QI(IDropSource,IUnknown)
DEFINE_INLINE_QI(IDropTarget,IUnknown)
DEFINE_INLINE_QI(IPersist,IUnknown)
DEFINE_INLINE_QI(IPersistFile,IPersist)
DEFINE_INLINE_QI(IPersistStream,IPersist)
DEFINE_INLINE_QI(IOleClientSite,IUnknown)
DEFINE_INLINE_QI(IAdviseSink,IUnknown)
DEFINE_INLINE_QI(IDataObject,IUnknown)
DEFINE_INLINE_QI(IOleObject,IUnknown)
DEFINE_INLINE_QI(IViewObject,IUnknown)
DEFINE_INLINE_QI(IViewObject2,IViewObject)
DEFINE_INLINE_QI(IPersistStorage,IPersist)
DEFINE_INLINE_QI(IMalloc,IUnknown)

DEFINE_INLINE_QI(IParseDisplayName,IUnknown)
DEFINE_INLINE_QI(IOleContainer,IParseDisplayName)
DEFINE_INLINE_QI(IOleItemContainer,IOleContainer)

// In-place interfaces
DEFINE_INLINE_QI(IOleWindow,IUnknown)
DEFINE_INLINE_QI(IOleInPlaceActiveObject,IOleWindow)
DEFINE_INLINE_QI(IOleInPlaceObject,IOleWindow)
DEFINE_INLINE_QI(IOleInPlaceSite,IOleWindow)
DEFINE_INLINE_QI(IOleInPlaceUIWindow,IOleWindow)
DEFINE_INLINE_QI(IOleInPlaceFrame,IOleInPlaceUIWindow)

// Automation interfaces

DEFINE_INLINE_QI(IDispatch,  IUnknown)

// assorted hookables
DEFINE_INLINE_QI(IMarshal,IUnknown)
DEFINE_INLINE_QI(IEnumUnknown,IUnknown)
DEFINE_INLINE_QI(IEnumString,IUnknown)
DEFINE_INLINE_QI(IEnumSTATDATA,IUnknown)
DEFINE_INLINE_QI(IEnumFORMATETC,IUnknown)
DEFINE_INLINE_QI(IEnumOLEVERB,  IUnknown)
DEFINE_INLINE_QI(IEnumMoniker,  IUnknown)
DEFINE_INLINE_QI(IRunningObjectTable,  IUnknown)
DEFINE_INLINE_QI(IMoniker,  IPersistStream)
DEFINE_INLINE_QI(IBindCtx,  IUnknown)
DEFINE_INLINE_QI(IRootStorage,  IUnknown)
DEFINE_INLINE_QI(IStorage,  IUnknown)
DEFINE_INLINE_QI(IStream,  IUnknown)
DEFINE_INLINE_QI(ILockBytes,  IUnknown)
DEFINE_INLINE_QI(IEnumSTATSTG,  IUnknown)
DEFINE_INLINE_QI(IOleLink,  IUnknown)
DEFINE_INLINE_QI(IDataAdviseHolder,  IUnknown)
DEFINE_INLINE_QI(IAdviseSink2,  IAdviseSink)
DEFINE_INLINE_QI(IOleAdviseHolder,  IUnknown)
DEFINE_INLINE_QI(IOleCache,  IUnknown)
DEFINE_INLINE_QI(IExternalConnection,  IUnknown)
DEFINE_INLINE_QI(IRunnableObject,  IUnknown)

#include "oledebug.h"

extern HINSTANCE boleInst;


#ifdef ANSI
  #include "Utils.h"
#endif

#endif




