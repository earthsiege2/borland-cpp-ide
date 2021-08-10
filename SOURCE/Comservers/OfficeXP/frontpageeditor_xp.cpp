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

// C++ TLBWRTR : $Revision:   1.0.1.0.1.0  $
// File generated on 1/29/2002 1:29:46 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\PROGRA~1\MICROS~4\Office10\FPEDITAX.DLL (1)
// LIBID: {7577AE81-4416-11CE-9C34-524153480000}
// LCID: 0
// Helpfile: C:\PROGRA~1\MICROS~4\Office10\VBAFPD10.CHM
// HelpString: Microsoft FrontPage 5.0 Page Object Reference Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
// Parent TypeLibrary:
//   (0) v5.0 FrontPage, (c:\program files\microsoft office\office10\frontpg.exe)
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "FrontPageEditor_XP.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Frontpageeditor_xp
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_FrontPageEditor = {0x7577AE81, 0x4416, 0x11CE,{ 0x9C, 0x34, 0x52,0x41, 0x53, 0x48,0x00, 0x00} };
const GUID DIID_IWPEDoc = {0x8BBD4A7A, 0x661D, 0x11CF,{ 0xA3, 0xC4, 0x00,0xA0, 0x24, 0x18,0x46, 0x92} };
const GUID CLSID_CWPEDoc = {0x31B4599A, 0xFFA3, 0x11CF,{ 0xB3, 0x5E, 0x00,0xA0, 0xC9, 0x0A,0x90, 0x44} };
const GUID IID_IPageEditorInternal = {0xD603F1EF, 0x2632, 0x11D2,{ 0xAD, 0x10, 0x00,0xC0, 0x4F, 0x79,0x52, 0x85} };
const GUID CLSID_CAutoJackInternal = {0x71AF875A, 0xD0D9, 0x4F84,{ 0xB6, 0xC0, 0x89,0x16, 0x77, 0xD7,0x79, 0xE8} };
const GUID IID_IURLPicker = {0x12428687, 0xA9D9, 0x11CF,{ 0x89, 0x04, 0x00,0xAA, 0x00, 0xBD,0xCB, 0x98} };
const GUID CLSID_URLPicker = {0xE2EA9C96, 0xF3F4, 0x4A6A,{ 0xB8, 0x70, 0x56,0x28, 0x7E, 0x76,0x1A, 0xFD} };
const GUID IID_IHTMLColorPicker = {0x533AC2A3, 0x1ACE, 0x11D1,{ 0xA7, 0x87, 0x00,0x00, 0xF8, 0x02,0x72, 0xEA} };
const GUID CLSID_HTMLColorPicker = {0xF7819961, 0xF148, 0x4468,{ 0x9D, 0x33, 0x76,0x9C, 0xF5, 0x71,0xF5, 0x59} };
const GUID CLSID_FPAxTagPage = {0x0085A8C6, 0x220B, 0x4AC2,{ 0x9B, 0x48, 0x88,0xCC, 0x17, 0xA0,0x82, 0x0D} };
const GUID CLSID_FPAxParamsPage = {0x017B0166, 0xA2AE, 0x4441,{ 0x9F, 0x48, 0xB0,0x8B, 0x23, 0xEF,0x3E, 0xB3} };
const GUID IID_IDTCExtendedServices = {0x6FF02AB1, 0x809B, 0x11D1,{ 0x9D, 0x27, 0x00,0x60, 0x08, 0x05,0x87, 0x31} };
const GUID IID_IIdleWorker = {0x3A82F170, 0x4C49, 0x11D2,{ 0xBE, 0x5D, 0x00,0x60, 0x08, 0xC3,0xFE, 0xBE} };
const GUID IID_IChServ = {0xE047F690, 0xD314, 0x11D1,{ 0xBD, 0xF8, 0x00,0x60, 0x08, 0xC3,0xFE, 0xBE} };
const GUID CLSID_ChServ = {0x01F48CD9, 0xC4F1, 0x4B84,{ 0x95, 0x8D, 0x31,0x5E, 0x6E, 0x8A,0x15, 0x4A} };
const GUID IID_IFPEditorControl = {0x0E5EDCEF, 0x9F3B, 0x11D1,{ 0xB3, 0xC3, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID__DFPEditorControlEvents = {0xF27C78D0, 0x9F63, 0x11D1,{ 0xB3, 0xC3, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPEditorControl = {0x35B08EF5, 0x9124, 0x4F34,{ 0xA7, 0xB3, 0x6F,0xF6, 0x9F, 0x16,0xDA, 0x5B} };
const GUID IID_IFPMarkupPointer = {0x3050F49F, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLDocument = {0x626FC520, 0xA41E, 0x11CF,{ 0xA7, 0x31, 0x00,0xA0, 0xC9, 0x08,0x26, 0x37} };
const GUID IID_IHTMLDocument2 = {0x332C4425, 0x26CB, 0x11D0,{ 0xB4, 0x83, 0x00,0xC0, 0x4F, 0xD9,0x01, 0x19} };
const GUID IID_IHTMLElementCollection = {0x3050F21F, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLElement = {0x3050F1FF, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLStyle = {0x3050F25E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFiltersCollection = {0x3050F3EE, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLSelectionObject = {0x3050F25A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFramesCollection2 = {0x332C4426, 0x26CB, 0x11D0,{ 0xB4, 0x83, 0x00,0xC0, 0x4F, 0xD9,0x01, 0x19} };
const GUID IID_IHTMLLocation = {0x163BB1E0, 0x6E00, 0x11CF,{ 0x83, 0x7A, 0x48,0xDC, 0x04, 0xC1,0x00, 0x00} };
const GUID IID_IHTMLWindow2 = {0x332C4427, 0x26CB, 0x11D0,{ 0xB4, 0x83, 0x00,0xC0, 0x4F, 0xD9,0x01, 0x19} };
const GUID IID_IHTMLImageElementFactory = {0x3050F38E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLImgElement = {0x3050F240, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IOmHistory = {0xFECEAAA2, 0x8405, 0x11CF,{ 0x8B, 0xA1, 0x00,0xAA, 0x00, 0x47,0x6D, 0xA6} };
const GUID IID_IOmNavigator = {0xFECEAAA5, 0x8405, 0x11CF,{ 0x8B, 0xA1, 0x00,0xAA, 0x00, 0x47,0x6D, 0xA6} };
const GUID IID_IHTMLMimeTypesCollection = {0x3050F3FC, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLPluginsCollection = {0x3050F3FD, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLOpsProfile = {0x3050F401, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLEventObj = {0x3050F32D, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLScreen = {0x3050F35C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLOptionElementFactory = {0x3050F38C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLOptionElement = {0x3050F211, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFormElement = {0x3050F1F7, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLStyleSheetsCollection = {0x3050F37E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLStyleSheet = {0x3050F2E3, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLStyleSheetRulesCollection = {0x3050F2E5, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLStyleSheetRule = {0x3050F357, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLRuleStyle = {0x3050F3CF, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IFPMarkupContainer = {0x3050F56E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IFPMarkupServices = {0x3050F4A0, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTxtRange = {0x3050F220, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IFPDocument = {0xC86A1A00, 0xFAA6, 0x11D1,{ 0xB3, 0xED, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID IID_IFPStyleState = {0xF0CAF799, 0xCD07, 0x11D3,{ 0x84, 0xA3, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID IID_IFPStyleLength = {0x0DDD0FFC, 0x6056, 0x4264,{ 0x86, 0x50, 0xC1,0x5A, 0x3D, 0x23,0x99, 0xE5} };
const GUID IID_IFPHTMLUndoTransaction = {0xC86A1A01, 0xFAA6, 0x11D1,{ 0xB3, 0xED, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLUndoTransaction = {0xC86A1A04, 0xFAA6, 0x11D1,{ 0xB3, 0xED, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID IID_IFrontPageHostedControl = {0x5497064A, 0x5CF4, 0x11D2,{ 0xAD, 0x3E, 0x00,0xC0, 0x4F, 0x79,0x52, 0x85} };
const GUID DIID_DispFPHTMLDocument = {0xCD6F2F18, 0x030B, 0x11D2,{ 0xB3, 0xF0, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLDocument = {0xAE464946, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLDocumentEvents = {0x3050F260, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLStyle = {0xAE464910, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLFiltersCollection = {0xAE464911, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLStyleSheet = {0xAE464912, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLStyleSheetsCollection = {0xAE464913, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLLinkElement = {0xAE464914, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLLinkElement = {0x3050F524, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLLinkElementEvents = {0x3050F3CC, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLLinkElement = {0x3050F205, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFrontPageBotElement = {0x83DB5580, 0xE05A, 0x11D1,{ 0xB3, 0xE1, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID IID_IHTMLFrontPageBotElement2 = {0x83DB5582, 0xE05A, 0x11D1,{ 0xB3, 0xE1, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLFrontPageBotElement = {0x83DB5581, 0xE05A, 0x11D1,{ 0xB3, 0xE1, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLFrontPageBotElement = {0x940CDFB0, 0xE059, 0x11D1,{ 0xB3, 0xE1, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLElementEvents = {0x3050F33C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLFormElement = {0xDA9FD6E0, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLFormElement = {0xAE464915, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLFormElementEvents = {0x3050F364, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTextElement = {0xAE464916, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTextElement = {0x3050F537, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTextElement = {0x3050F218, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLImgElement = {0x88DD98AA, 0x7C8C, 0x4AB7,{ 0xAC, 0xF3, 0xCF,0x9A, 0x37, 0xB4,0x93, 0xB8} };
const GUID CLSID_FPHTMLImg = {0xAE464917, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLImgEvents = {0x3050F25B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLControlElement = {0x04598FC6, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_IHTMLDatabinding = {0x3050F3F2, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLInputImage = {0xDA9FD6E1, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLInputImage = {0xAE464918, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLInputImageEvents = {0x3050F2C3, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLInputImage = {0x3050F2C2, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLImageElementFactory = {0xAE46491A, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLBody = {0xAE46491B, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLBodyElement = {0x3050F507, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLTextContainerEvents = {0x1FF6AA72, 0x5842, 0x11CF,{ 0xA7, 0x07, 0x00,0xAA, 0x00, 0xC0,0x09, 0x8D} };
const GUID IID_IHTMLBodyElement = {0x3050F1D8, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTextContainer = {0x3050F230, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLFontElement = {0xAE46491C, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLFontElement = {0x3050F512, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFontElement = {0x3050F1D9, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLAnchorElement = {0xAE46491D, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLAnchorElement = {0x3050F502, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLAnchorEvents = {0x3050F29D, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLAnchorElement = {0x3050F1DA, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLLabelElement = {0xAE46491E, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLLabelElement = {0x3050F522, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLLabelEvents = {0x3050F329, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLLabelElement = {0x3050F32A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLListElement = {0xAE46491F, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLListElement = {0x3050F525, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLListElement = {0x3050F20E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLUListElement = {0xAE464920, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLUListElement = {0x3050F538, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLUListElement = {0x3050F1DD, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLOListElement = {0xAE464921, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLOListElement = {0x3050F52A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLOListElement = {0x3050F1DE, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLLIElement = {0xAE464922, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLLIElement = {0x3050F523, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLLIElement = {0x3050F1E0, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLBlockElement = {0xAE464923, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLBlockElement = {0x3050F506, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLBlockElement = {0x3050F208, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLDivElement = {0xAE464924, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLDivElement = {0x3050F50C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLDivElement = {0x3050F200, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLDDElement = {0xAE464925, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLDDElement = {0x3050F50B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLDDElement = {0x3050F1F2, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLDTElement = {0xAE464926, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLDTElement = {0x3050F50D, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLDTElement = {0x3050F1F3, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLBRElement = {0xAE464927, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLBRElement = {0x3050F53A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLBRElement = {0x3050F1F0, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLDListElement = {0xAE464928, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLDListElement = {0x3050F53B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLDListElement = {0x3050F1F1, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLHRElement = {0xAE464929, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLHRElement = {0x3050F53D, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLHRElement = {0x3050F1F4, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLParaElement = {0xAE46492A, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLParaElement = {0x3050F52C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLParaElement = {0x3050F1F5, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLHeaderElement = {0xAE46492B, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLHeaderElement = {0x3050F515, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLHeaderElement = {0x3050F1F6, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLSelectElement = {0xDA9FD6E2, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLSelectElement = {0xAE46492C, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLSelectElementEvents = {0x3050F302, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLSelectElement = {0x3050F244, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLOptionElement = {0xAE46492D, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLOptionElement = {0x3050F52B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLOptionElementFactory = {0xAE46492E, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_FPDispIHTMLInputTextElement = {0xDA9FD6E3, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLInputTextElement = {0xAE46492F, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLInputTextElementEvents = {0x3050F2A7, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLInputTextElement = {0x3050F2A6, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLTextAreaElement = {0xDA9FD6E4, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLTextAreaElement = {0xAE464930, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID IID_IHTMLTextAreaElement = {0x3050F2AA, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLInputButtonElement = {0xDA9FD6EA, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLInputButtonElement = {0xAE464931, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLButtonElementEvents = {0x3050F2B3, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLInputButtonElement = {0x3050F2B2, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLInputHiddenElement = {0x05F1AF20, 0x4106, 0x11D2,{ 0xAD, 0x1E, 0x00,0xC0, 0x4F, 0x79,0x52, 0x85} };
const GUID IID_IHTMLInputHiddenElement = {0x3050F2A4, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLButtonElement = {0xAE464932, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLButtonElement = {0x3050F51F, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLButtonElement = {0x3050F2BB, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_FPDispIHTMLInputFileElement = {0xDA9FD6EB, 0x519D, 0x11D3,{ 0x84, 0x8A, 0x00,0x50, 0x04, 0xAE,0x68, 0x30} };
const GUID CLSID_FPHTMLInputFileElement = {0xAE464933, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLInputFileElementEvents = {0x3050F2AF, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLInputFileElement = {0x3050F2AD, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLMarqueeElement = {0xAE464934, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLMarqueeElement = {0x3050F527, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLMarqueeElementEvents = {0x3050F2B8, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLMarqueeElement = {0x3050F2B5, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLOptionButtonElement = {0xAE464935, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLOptionButtonElement = {0x3050F509, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLOptionButtonElementEvents = {0x3050F2BD, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLOptionButtonElement = {0x3050F2BC, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTitleElement = {0xAE464936, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTitleElement = {0x3050F516, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTitleElement = {0x3050F322, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLMetaElement = {0xAE464937, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLMetaElement = {0x3050F517, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLMetaElement = {0x3050F203, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLBaseElement = {0xAE464938, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLBaseElement = {0x3050F518, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLBaseElement = {0x3050F204, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLIsIndexElement = {0xAE464939, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLIsIndexElement = {0x3050F519, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLIsIndexElement = {0x3050F206, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLNextIdElement = {0xAE46493A, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLNextIdElement = {0x3050F51A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLNextIdElement = {0x3050F207, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLBaseFontElement = {0xAE46493B, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLBaseFontElement = {0x3050F504, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLBaseFontElement = {0x3050F202, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLUnknownElement = {0xAE46493C, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLUnknownElement = {0x3050F539, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLUnknownElement = {0x3050F209, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLHistory = {0xAE46493D, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLCMimeTypes = {0xAE46493E, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLCPlugins = {0xAE46493F, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLCOpsProfile = {0xAE464940, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLNavigator = {0xAE464941, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLLocation = {0xAE464942, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLScreen = {0xAE464943, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLWindow2 = {0xAE464944, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_HTMLWindowEvents = {0x96A0A4E0, 0xD062, 0x11CF,{ 0x94, 0xB6, 0x00,0xAA, 0x00, 0x60,0x27, 0x5C} };
const GUID CLSID_FPHTMLWindowProxy = {0xAE464945, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID CLSID_FPHTMLEmbed = {0xAE464947, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLEmbedElement = {0x3050F52E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLControlElementEvents = {0x9A4BBF53, 0x4E46, 0x101B,{ 0x8B, 0xBD, 0x00,0xAA, 0x00, 0x3E,0x3B, 0x29} };
const GUID IID_IHTMLEmbedElement = {0x3050F25F, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLMapElement = {0xAE464948, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLMapElement = {0x3050F526, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLAreasCollection = {0x3050F383, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLMapEvents = {0x3050F3BA, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLMapElement = {0x3050F266, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLAreaElement = {0xAE464949, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLAreaElement = {0x3050F503, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLAreaEvents = {0x3050F366, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLAreaElement = {0x3050F265, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTableCaption = {0xAE46494A, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTableCaption = {0x3050F508, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTableCaption = {0x3050F2EB, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLCommentElement = {0xAE46494B, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLCommentElement = {0x3050F50A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLCommentElement = {0x3050F20C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLPhraseElement = {0xAE46494C, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLPhraseElement = {0x3050F52D, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLPhraseElement = {0x3050F20A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLSpanElement = {0xAE46494D, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLSpanElement = {0x3050F548, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLSpanElement = {0x3050F3F3, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTable = {0xAE46494E, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTable = {0x3050F532, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTableSection = {0x3050F23B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLTableEvents = {0x3050F407, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTable = {0x3050F21E, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTableCol = {0xAE46494F, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTableCol = {0x3050F533, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTableCol = {0x3050F23A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTableSection = {0xAE464950, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTableSection = {0x3050F534, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTableRow = {0xAE464951, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTableRow = {0x3050F535, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTableRow = {0x3050F23C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTableRowMetrics = {0x3050F413, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLTableCell = {0xAE464952, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLTableCell = {0x3050F536, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLTableCell = {0x3050F23D, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLScriptElement = {0xAE464953, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLScriptElement = {0x3050F530, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLScriptEvents = {0x3050F3E2, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLScriptElement = {0x3050F28B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLNoShowElement = {0xAE464954, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLNoShowElement = {0x3050F528, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLNoShowElement = {0x3050F38A, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLObjectElement = {0xAE464955, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLObjectElement = {0x3050F529, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLObjectElementEvents = {0x3050F3C4, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLObjectElement = {0x3050F24F, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLFrameBase = {0xAE464956, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLFrameBase = {0x3050F541, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFrameBase = {0x3050F311, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLFrameElement = {0xAE464957, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLFrameElement = {0x3050F513, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFrameElement = {0x3050F313, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLIFrame = {0xAE464958, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLIFrameElement = {0x3050F51B, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLIFrameElement = {0x3050F315, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLDivPosition = {0xAE464959, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLDivPosition = {0x3050F50F, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLDivPosition = {0x3050F212, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLFieldSetElement = {0xAE46495A, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLFieldSetElement = {0x3050F545, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFieldSetElement = {0x3050F3E7, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLLegendElement = {0xAE46495B, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLLegendElement = {0x3050F546, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLLegendElement = {0x3050F3EA, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLSpanFlow = {0xAE46495C, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLSpanFlow = {0x3050F544, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLSpanFlow = {0x3050F3E5, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLFrameSetSite = {0xAE46495D, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLFrameSetElement = {0x3050F514, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLFrameSetElement = {0x3050F319, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLBGsound = {0xAE46495E, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLBGsound = {0x3050F53C, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLBGsound = {0x3050F369, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLStyleElement = {0xAE46495F, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID DIID_DispIHTMLStyleElement = {0x3050F511, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID DIID_HTMLStyleElementEvents = {0x3050F3CB, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IHTMLStyleElement = {0x3050F375, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLStyleFontFace = {0xAE464960, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID IID_IHTMLStyleFontFace = {0x3050F3D5, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID CLSID_FPHTMLDialog = {0xAE464961, 0x8B76, 0x11D1,{ 0xB3, 0xBD, 0x00,0x60, 0x97, 0x7B,0x46, 0x3D} };
const GUID IID_IHTMLDialog = {0x3050F216, 0x98B5, 0x11CF,{ 0xBB, 0x82, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x0B} };
const GUID IID_IFrontPageHostedControl2 = {0x61FE20E7, 0xB351, 0x11D3,{ 0x87, 0x45, 0x00,0xC0, 0x4F, 0x79,0xE8, 0x7D} };

};     // namespace Frontpageeditor_xp
