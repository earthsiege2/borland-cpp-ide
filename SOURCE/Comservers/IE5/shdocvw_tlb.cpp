// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// C++ TLBWRTR : $Revision:   1.0.1.2  $
// File generated on 1/24/2000 10:20:00 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: \winnt\system32\shdocvw.dll (1)
// IID\LCID: {EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}\0
// Helpfile: 
// DepndLst: 
//   (1) v2.0 stdole, (D:\WINNT\System32\stdole2.tlb)
//   (2) v4.0 StdVCL, (D:\tlbgen\rampage\typelib\typelibraries\testing\stdvcl40.tlb)
// Errors:
//   Hint: Symbol 'WebBrowser_V1' renamed to 'CppWebBrowser_V1'
//   Hint: Symbol 'WebBrowser' renamed to 'CppWebBrowser'
//   Hint: Symbol 'InternetExplorer' renamed to 'CppInternetExplorer'
//   Hint: Symbol 'ShellBrowserWindow' renamed to 'CppShellBrowserWindow'
//   Hint: Symbol 'ShellWindows' renamed to 'CppShellWindows'
//   Hint: Symbol 'ShellUIHelper' renamed to 'CppShellUIHelper'
//   Hint: Symbol 'SearchAssistantOC' renamed to 'CppSearchAssistantOC'
//   Hint: Symbol 'WebBrowser_V1' renamed to 'CppWebBrowser_V1'
//   Hint: Symbol 'WebBrowser' renamed to 'CppWebBrowser'
//   Hint: Symbol 'InternetExplorer' renamed to 'CppInternetExplorer'
//   Hint: Symbol 'ShellBrowserWindow' renamed to 'CppShellBrowserWindow'
//   Hint: Symbol 'ShellWindows' renamed to 'CppShellWindows'
//   Hint: Symbol 'ShellUIHelper' renamed to 'CppShellUIHelper'
//   Hint: Symbol 'SearchAssistantOC' renamed to 'CppSearchAssistantOC'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "SHDocVw_TLB.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Shdocvw_tlb
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_SHDocVw = {0xEAB22AC0, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B} };
const GUID IID_IWebBrowser = {0xEAB22AC1, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B} };
const GUID DIID_DWebBrowserEvents = {0xEAB22AC2, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B} };
const GUID IID_IWebBrowserApp = {0x0002DF05, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46} };
const GUID IID_IWebBrowser2 = {0xD30C1661, 0xCDAF, 0x11D0,{ 0x8A, 0x3E, 0x00, 0xC0, 0x4F, 0xC9, 0xE2, 0x6E} };
const GUID DIID_DWebBrowserEvents2 = {0x34A715A0, 0x6587, 0x11D0,{ 0x92, 0x4A, 0x00, 0x20, 0xAF, 0xC7, 0xAC, 0x4D} };
const GUID CLSID_CppWebBrowser_V1 = {0xEAB22AC3, 0x30C1, 0x11CF,{ 0xA7, 0xEB, 0x00, 0x00, 0xC0, 0x5B, 0xAE, 0x0B} };
const GUID CLSID_CppWebBrowser = {0x8856F961, 0x340A, 0x11D0,{ 0xA9, 0x6B, 0x00, 0xC0, 0x4F, 0xD7, 0x05, 0xA2} };
const GUID CLSID_CppInternetExplorer = {0x0002DF01, 0x0000, 0x0000,{ 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46} };
const GUID CLSID_CppShellBrowserWindow = {0xC08AFD90, 0xF2A1, 0x11D1,{ 0x84, 0x55, 0x00, 0xA0, 0xC9, 0x1F, 0x38, 0x80} };
const GUID DIID_DShellWindowsEvents = {0xFE4106E0, 0x399A, 0x11D0,{ 0xA4, 0x8C, 0x00, 0xA0, 0xC9, 0x0A, 0x8F, 0x39} };
const GUID IID_IShellWindows = {0x85CB6900, 0x4D95, 0x11CF,{ 0x96, 0x0C, 0x00, 0x80, 0xC7, 0xF4, 0xEE, 0x85} };
const GUID CLSID_CppShellWindows = {0x9BA05972, 0xF6A8, 0x11CF,{ 0xA4, 0x42, 0x00, 0xA0, 0xC9, 0x0A, 0x8F, 0x39} };
const GUID IID_IShellUIHelper = {0x729FE2F8, 0x1EA8, 0x11D1,{ 0x8F, 0x85, 0x00, 0xC0, 0x4F, 0xC2, 0xFB, 0xE1} };
const GUID CLSID_CppShellUIHelper = {0x64AB4BB7, 0x111E, 0x11D1,{ 0x8F, 0x79, 0x00, 0xC0, 0x4F, 0xC2, 0xFB, 0xE1} };
const GUID DIID__ShellFavoritesNameSpaceEvents = {0x55136806, 0xB2DE, 0x11D1,{ 0xB9, 0xF2, 0x00, 0xA0, 0xC9, 0x8B, 0xC5, 0x47} };
const GUID IID_IShellFavoritesNameSpace = {0x55136804, 0xB2DE, 0x11D1,{ 0xB9, 0xF2, 0x00, 0xA0, 0xC9, 0x8B, 0xC5, 0x47} };
const GUID CLSID_ShellFavoritesNameSpace = {0x55136805, 0xB2DE, 0x11D1,{ 0xB9, 0xF2, 0x00, 0xA0, 0xC9, 0x8B, 0xC5, 0x47} };
const GUID IID_IScriptErrorList = {0xF3470F24, 0x15FD, 0x11D2,{ 0xBB, 0x2E, 0x00, 0x80, 0x5F, 0xF7, 0xEF, 0xCA} };
const GUID CLSID_CScriptErrorList = {0xEFD01300, 0x160F, 0x11D2,{ 0xBB, 0x2E, 0x00, 0x80, 0x5F, 0xF7, 0xEF, 0xCA} };
const GUID IID_ISearch = {0xBA9239A4, 0x3DD5, 0x11D2,{ 0xBF, 0x8B, 0x00, 0xC0, 0x4F, 0xB9, 0x36, 0x61} };
const GUID IID_ISearches = {0x47C922A2, 0x3DD5, 0x11D2,{ 0xBF, 0x8B, 0x00, 0xC0, 0x4F, 0xB9, 0x36, 0x61} };
const GUID IID_ISearchAssistantOC = {0x72423E8F, 0x8011, 0x11D2,{ 0xBE, 0x79, 0x00, 0xA0, 0xC9, 0xA8, 0x3D, 0xA1} };
const GUID IID_ISearchAssistantOC2 = {0x72423E8F, 0x8011, 0x11D2,{ 0xBE, 0x79, 0x00, 0xA0, 0xC9, 0xA8, 0x3D, 0xA2} };
const GUID DIID__SearchAssistantEvents = {0x1611FDDA, 0x445B, 0x11D2,{ 0x85, 0xDE, 0x00, 0xC0, 0x4F, 0xA3, 0x5C, 0x89} };
const GUID CLSID_CppSearchAssistantOC = {0xB45FF030, 0x4447, 0x11D2,{ 0x85, 0xDE, 0x00, 0xC0, 0x4F, 0xA3, 0x5C, 0x89} };

};     // namespace Shdocvw_tlb
