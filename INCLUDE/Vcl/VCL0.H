/////////////////////////////////////////////////////////////////////////////////
// VCL0.H - Borland C++ Builder pre-compiled header file
// $Revision:   1.7  $
// Copyright (c) 1997, 1999 Borland International
//
// VCL0.H is the core header that includes VCL headers. The headers included by
// VCL0.H are governed by the following macros:
//
//  MACRO                   DESCRIPTION                                 DEFAULT
// =======                 =============                                =======
//
//  NO_WIN32_LEAN_AND_MEAN  When this macro is defined, VCL.H does not    OFF
//                          define WIN32_LEAN_AND_MEAN.
//
//  VCL_FULL                Same as NO_WIN32_LEAN_AND_MEAN                OFF
//                          (NOTE: This macro is for BCB v1.0 backward
//                          compatibility)
//
//  INC_VCLDB_HEADERS       When this macro is defined, VCL.H includes
//                          the core Database headers of VCL.             OFF
//                          (Defining this macro is functionally
//                          equivalent to including VCLDB.H)
//
//  INC_ALLVCL_HEADERS      When this macro is defined, VCL.H includes
//                          all VCL headers.                              OFF
//                          (Defining this macro is functionally
//                          equivalent to including VCLMAX.H)
/////////////////////////////////////////////////////////////////////////////////
#ifndef __VCL0_H__
#define __VCL0_H__

// v1.0 of BCB checked for VCL_FULL to avoid LEAN_AND_MEAN support
//
#if defined(VCL_FULL)                 // BCB v1.0 compatible
#define NO_WIN32_LEAN_AND_MEAN
#endif

#if !defined(_WINDOWS_)               // Don't optimize if WINDOWS.H has already been included
#if !defined(NO_WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN           // Enable LEAN_AND_MEAN support
#define  _VCL_LEAN_AND_MEAN           // BCB v1.0 compatible
#endif                                // NO_WIN32_LEAN_AND_MEAN
#endif                                // _WINDOWS_

#if !defined(COM_NO_WINDOWS_H)        // Make sure COM Headers don't include WINDOWS.H/OLE2.H
#define COM_NO_WINDOWS_H
#define UNDEF_COM_NO_WINDOWS_H
#endif

#if !defined(RPC_NO_WINDOWS_H)        // Make sure RPC Headers don't include WINDOWS.H
#define RPC_NO_WINDOWS_H
#define UNDEF_RPC_NO_WINDOWS_H
#endif

// Core (minimal) VCL headers
//
#include <system.hpp>
#include <windows.hpp>
#include <messages.hpp>
#include <sysutils.hpp>
#include <classes.hpp>
#include <graphics.hpp>
#include <controls.hpp>
#include <forms.hpp>
#include <dialogs.hpp>
#include <stdctrls.hpp>
#include <extctrls.hpp>

// Database related headers
//
#if defined(INC_VCLDB_HEADERS)
#include <dbctrls.hpp>
#include <mask.hpp>
#include <db.hpp>
#include <dbtables.hpp>
#endif  //  INC_VCLDB_HEADERS


#if defined(INC_VCLEXT_HEADERS)
#include <Buttons.hpp>
#include <ChartFX.hpp>
#include <ComCtrls.hpp>
#include <DBCGrids.hpp>
#include <DBGrids.hpp>
#include <DBLookup.hpp>
#include <DdeMan.hpp>
#include <FileCtrl.hpp>
#include <GraphSvr.hpp>
#include <Grids.hpp>
//!#include <ISP3.hpp>
#include <MPlayer.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
#include <OleCtnrs.hpp>
#include <OleCtrls.hpp>
#include <Outline.hpp>
#include <Quickrpt.hpp>
#include <Tabnotbk.hpp>
#include <Tabs.hpp>
#include <VCFImprs.hpp>
#include <VCFrmla1.hpp>
#include <VCSpell3.hpp>
#endif  // INC_ALLVCL_HEADERS

#if defined(INC_OLE_HEADERS)
#include <cguid.h>
#include <dir.h>
#include <malloc.h>
#include <objbase.h>
#include <ole2.h>
#include <shellapi.h>
#include <stddef.h>
#include <tchar.h>
#include <urlmon.h>
#include <AxCtrls.hpp>
#include <databkr.hpp>
#include <OleCtnrs.hpp>
#include <OleCtrls.hpp>
#include <mtx.hpp>
#endif

// Using ATLVCL.H
//
#if defined(INC_ATL_HEADERS)
#include <atl\atlvcl.h>
#endif

#if defined(INC_CORBA_HEADERS)
#include <corbapch.h>
#endif

#if defined(UNDEF_COM_NO_WINDOWS_H)   // Clean up MACRO to prevent inclusion of WINDOWS.H/OLE2.H
#undef COM_NO_WINDOWS_H
#undef UNDEF_COM_NO_WINDOWS_H
#endif

#if defined(UNDEF_RPC_NO_WINDOWS_H)   // Clean up MACRO to prevent inclusion of WINDOWS.H
#undef RPC_NO_WINDOWS_H
#undef UNDEF_RPC_NO_WINDOWS_H
#endif

#endif  // __VCL0_H__
