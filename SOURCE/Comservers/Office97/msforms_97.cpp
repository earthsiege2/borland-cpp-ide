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

// C++ TLBWRTR : $Revision:   1.151.1.0.1.21  $
// File generated on 1/28/2002 7:55:37 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\WINNT\System32\FM20.DLL (1)
// LIBID: {0D452EE1-E08F-101A-852E-02608C4D0BB4}
// LCID: 0
// Helpfile: C:\WINNT\System32\fm20.hlp
// HelpString: Microsoft Forms 2.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
// Parent TypeLibrary:
//   (0) v8.0 Outlook, (c:\program files\microsoft office\office97\office\msoutl8.olb)
// Errors:
//   Hint: Symbol 'Controls' renamed to 'Controls_'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "MSForms_97.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Msforms_97
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_MSForms = {0x0D452EE1, 0xE08F, 0x101A,{ 0x85, 0x2E, 0x02,0x60, 0x8C, 0x4D,0x0B, 0xB4} };
const GUID IID_IFont = {0xBEF6E002, 0xA874, 0x101A,{ 0x8B, 0xBA, 0x00,0xAA, 0x00, 0x30,0x0C, 0xAB} };
const GUID DIID_Font = {0xBEF6E003, 0xA874, 0x101A,{ 0x8B, 0xBA, 0x00,0xAA, 0x00, 0x30,0x0C, 0xAB} };
const GUID IID_IDataAutoWrapper = {0xEC72F590, 0xF375, 0x11CE,{ 0xB9, 0xE8, 0x00,0xAA, 0x00, 0x6B,0x1A, 0x69} };
const GUID IID_IReturnInteger = {0x82B02370, 0xB5BC, 0x11CF,{ 0x81, 0x0F, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID IID_IReturnBoolean = {0x82B02371, 0xB5BC, 0x11CF,{ 0x81, 0x0F, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID IID_IReturnString = {0x82B02372, 0xB5BC, 0x11CF,{ 0x81, 0x0F, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID IID_IReturnSingle = {0x8A683C90, 0xBA84, 0x11CF,{ 0x81, 0x10, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID IID_IReturnEffect = {0x8A683C91, 0xBA84, 0x11CF,{ 0x81, 0x10, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID CLSID_ReturnInteger = {0x82B02373, 0xB5BC, 0x11CF,{ 0x81, 0x0F, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID CLSID_ReturnBoolean = {0x82B02374, 0xB5BC, 0x11CF,{ 0x81, 0x0F, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID CLSID_ReturnString = {0x82B02375, 0xB5BC, 0x11CF,{ 0x81, 0x0F, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID CLSID_ReturnSingle = {0x8A683C92, 0xBA84, 0x11CF,{ 0x81, 0x10, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID CLSID_ReturnEffect = {0x8A683C93, 0xBA84, 0x11CF,{ 0x81, 0x10, 0x00,0xA0, 0xC9, 0x03,0x00, 0x74} };
const GUID CLSID_DataObject = {0x1C3B4210, 0xF441, 0x11CE,{ 0xB9, 0xEA, 0x00,0xAA, 0x00, 0x6B,0x1A, 0x69} };
const GUID IID_IControl = {0x04598FC6, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_Controls_ = {0x04598FC7, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_IOptionFrame = {0x29B86A70, 0xF52E, 0x11CE,{ 0x9B, 0xCE, 0x00,0xAA, 0x00, 0x60,0x8E, 0x01} };
const GUID IID__UserForm = {0x04598FC8, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID DIID_ControlEvents = {0x9A4BBF53, 0x4E46, 0x101B,{ 0x8B, 0xBD, 0x00,0xAA, 0x00, 0x3E,0x3B, 0x29} };
const GUID CLSID_Control = {0x909E0AE0, 0x16DC, 0x11CE,{ 0x9E, 0x98, 0x00,0xAA, 0x00, 0x57,0x4A, 0x4F} };
const GUID DIID_FormEvents = {0x5B9D8FC8, 0x4A71, 0x101B,{ 0x97, 0xA6, 0x00,0x00, 0x0B, 0x65,0xC0, 0x8B} };
const GUID DIID_OptionFrameEvents = {0xCF3F94A0, 0xF546, 0x11CE,{ 0x9B, 0xCE, 0x00,0xAA, 0x00, 0x60,0x8E, 0x01} };
const GUID CLSID_UserForm = {0xC62A69F0, 0x16DC, 0x11CE,{ 0x9E, 0x98, 0x00,0xAA, 0x00, 0x57,0x4A, 0x4F} };
const GUID CLSID_Frame = {0x6E182020, 0xF460, 0x11CE,{ 0x9B, 0xCD, 0x00,0xAA, 0x00, 0x60,0x8E, 0x01} };
const GUID IID_ILabelControl = {0x04598FC1, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_ICommandButton = {0x04598FC4, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_IMdcText = {0x8BD21D13, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID IID_IMdcList = {0x8BD21D23, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID IID_IMdcCombo = {0x8BD21D33, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID IID_IMdcCheckBox = {0x8BD21D43, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID IID_IMdcOptionButton = {0x8BD21D53, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID IID_IMdcToggleButton = {0x8BD21D63, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID IID_IScrollbar = {0x04598FC3, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_Tab = {0xA38BFFC3, 0xA5A0, 0x11CE,{ 0x81, 0x07, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };
const GUID IID_Tabs = {0x944ACF93, 0xA1E6, 0x11CE,{ 0x81, 0x04, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };
const GUID IID_ITabStrip = {0x04598FC2, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID IID_ISpinbutton = {0x79176FB3, 0xB7F2, 0x11CE,{ 0x97, 0xEF, 0x00,0xAA, 0x00, 0x6D,0x27, 0x76} };
const GUID IID_IImage = {0x4C599243, 0x6926, 0x101B,{ 0x99, 0x92, 0x00,0x00, 0x0B, 0x65,0xC6, 0xF9} };
const GUID IID_IWHTMLSubmitButton = {0x5512D111, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLImage = {0x5512D113, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLReset = {0x5512D115, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLCheckbox = {0x5512D117, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLOption = {0x5512D119, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLText = {0x5512D11B, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLHidden = {0x5512D11D, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLPassword = {0x5512D11F, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLSelect = {0x5512D123, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IWHTMLTextArea = {0x5512D125, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID DIID_LabelControlEvents = {0x978C9E22, 0xD4B0, 0x11CE,{ 0xBF, 0x2D, 0x00,0xAA, 0x00, 0x3F,0x40, 0xD0} };
const GUID CLSID_Label = {0x978C9E23, 0xD4B0, 0x11CE,{ 0xBF, 0x2D, 0x00,0xAA, 0x00, 0x3F,0x40, 0xD0} };
const GUID DIID_CommandButtonEvents = {0x7B020EC1, 0xAF6C, 0x11CE,{ 0x9F, 0x46, 0x00,0xAA, 0x00, 0x57,0x4A, 0x4F} };
const GUID CLSID_CommandButton = {0xD7053240, 0xCE69, 0x11CD,{ 0xA7, 0x77, 0x00,0xDD, 0x01, 0x14,0x3C, 0x57} };
const GUID DIID_MdcTextEvents = {0x8BD21D12, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_TextBox = {0x8BD21D10, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID DIID_MdcListEvents = {0x8BD21D22, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_ListBox = {0x8BD21D20, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID DIID_MdcComboEvents = {0x8BD21D32, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_ComboBox = {0x8BD21D30, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID DIID_MdcCheckBoxEvents = {0x8BD21D42, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID DIID_MdcOptionButtonEvents = {0x8BD21D52, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID DIID_MdcToggleButtonEvents = {0x8BD21D62, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_CheckBox = {0x8BD21D40, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_OptionButton = {0x8BD21D50, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_ToggleButton = {0x8BD21D60, 0xEC42, 0x11CE,{ 0x9E, 0x0D, 0x00,0xAA, 0x00, 0x60,0x02, 0xF3} };
const GUID CLSID_NewFont = {0xAFC20920, 0xDA4E, 0x11CE,{ 0xB9, 0x43, 0x00,0xAA, 0x00, 0x68,0x87, 0xB4} };
const GUID DIID_ScrollbarEvents = {0x7B020EC2, 0xAF6C, 0x11CE,{ 0x9F, 0x46, 0x00,0xAA, 0x00, 0x57,0x4A, 0x4F} };
const GUID CLSID_ScrollBar = {0xDFD181E0, 0x5E2F, 0x11CE,{ 0xA4, 0x49, 0x00,0xAA, 0x00, 0x4A,0x80, 0x3D} };
const GUID DIID_TabStripEvents = {0x7B020EC7, 0xAF6C, 0x11CE,{ 0x9F, 0x46, 0x00,0xAA, 0x00, 0x57,0x4A, 0x4F} };
const GUID CLSID_TabStrip = {0xEAE50EB0, 0x4A62, 0x11CE,{ 0xBE, 0xD6, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };
const GUID DIID_SpinbuttonEvents = {0x79176FB2, 0xB7F2, 0x11CE,{ 0x97, 0xEF, 0x00,0xAA, 0x00, 0x6D,0x27, 0x76} };
const GUID CLSID_SpinButton = {0x79176FB0, 0xB7F2, 0x11CE,{ 0x97, 0xEF, 0x00,0xAA, 0x00, 0x6D,0x27, 0x76} };
const GUID DIID_ImageEvents = {0x4C5992A5, 0x6926, 0x101B,{ 0x99, 0x92, 0x00,0x00, 0x0B, 0x65,0xC6, 0xF9} };
const GUID CLSID_Image = {0x4C599241, 0x6926, 0x101B,{ 0x99, 0x92, 0x00,0x00, 0x0B, 0x65,0xC6, 0xF9} };
const GUID DIID_WHTMLControlEvents = {0x796ED650, 0x5FE9, 0x11CF,{ 0x8D, 0x68, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID DIID_WHTMLControlEvents1 = {0x47FF8FE0, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents2 = {0x47FF8FE1, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents3 = {0x47FF8FE2, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents4 = {0x47FF8FE3, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents5 = {0x47FF8FE4, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents6 = {0x47FF8FE5, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents7 = {0x47FF8FE6, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents9 = {0x47FF8FE8, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID DIID_WHTMLControlEvents10 = {0x47FF8FE9, 0x6198, 0x11CF,{ 0x8C, 0xE8, 0x00,0xAA, 0x00, 0x6C,0xB3, 0x89} };
const GUID CLSID_HTMLSubmit = {0x5512D110, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLImage = {0x5512D112, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLReset = {0x5512D114, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLCheckbox = {0x5512D116, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLOption = {0x5512D118, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLText = {0x5512D11A, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLHidden = {0x5512D11C, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLPassword = {0x5512D11E, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLSelect = {0x5512D122, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID CLSID_HTMLTextArea = {0x5512D124, 0x5CC6, 0x11CF,{ 0x8D, 0x67, 0x00,0xAA, 0x00, 0xBD,0xCE, 0x1D} };
const GUID IID_IPage = {0x5CEF5613, 0x713D, 0x11CE,{ 0x80, 0xC9, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };
const GUID IID_Pages = {0x92E11A03, 0x7358, 0x11CE,{ 0x80, 0xCB, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };
const GUID IID_IMultiPage = {0x04598FC9, 0x866C, 0x11CF,{ 0xAB, 0x7C, 0x00,0xAA, 0x00, 0xC0,0x8F, 0xCF} };
const GUID DIID_MultiPageEvents = {0x7B020EC8, 0xAF6C, 0x11CE,{ 0x9F, 0x46, 0x00,0xAA, 0x00, 0x57,0x4A, 0x4F} };
const GUID CLSID_MultiPage = {0x46E31370, 0x3F7A, 0x11CE,{ 0xBE, 0xD6, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };
const GUID CLSID_Page = {0x5CEF5610, 0x713D, 0x11CE,{ 0x80, 0xC9, 0x00,0xAA, 0x00, 0x61,0x10, 0x80} };

};     // namespace Msforms_97
