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

// C++ TLBWRTR : $Revision:   1.0.2.1  $
// File generated on 1/24/2000 9:50:10 AM from Type Library described below.

// ************************************************************************ //
// Type Lib: g:\rampage\typelib\TypeLibraries\MSPPT8.olb (1)
// IID\LCID: {91493440-5A91-11CF-8700-00AA0060263B}\0
// Helpfile: D:\Program Files\Microsoft Office\Office\VBAPPT8.HLP
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.0 Office, (D:\Program Files\Microsoft Office\Office\MSO97.DLL)
//   (3) v5.0 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBEEXT1.OLB)
//   (4) v4.0 StdVCL, (C:\WINNT\System32\STDVCL40.DLL)
// Errors:
//   Hint: Symbol 'Application' renamed to 'PowerPointApplication'
//   Hint: Symbol 'Global' renamed to 'PowerPointGlobal'
//   Hint: Symbol 'Presentation' renamed to 'PowerPointPresentation'
//   Hint: Symbol 'Slide' renamed to 'PowerPointSlide'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Application' renamed to 'PowerPointApplication'
//   Hint: Symbol 'Global' renamed to 'PowerPointGlobal'
//   Hint: Symbol 'Presentation' renamed to 'PowerPointPresentation'
//   Hint: Symbol 'Slide' renamed to 'PowerPointSlide'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'RGB' renamed to 'rgb'
//   Hint: Symbol 'Update' renamed to '_Update'
//   Hint: Symbol 'Windows' renamed to 'Windoz'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
//   Hint: Symbol 'Click' renamed to '_Click'
// ************************************************************************ //

#include <vcl.h>
#pragma hdrstop

#include "PowerPoint_97.h"

#if !defined(__PRAGMA_PACKAGE_SMART_INIT)
#define      __PRAGMA_PACKAGE_SMART_INIT
#pragma package(smart_init)
#endif

namespace Powerpoint_97
{


// *********************************************************************//
// GUIDS declared in the TypeLibrary                                      
// *********************************************************************//
const GUID LIBID_PowerPoint = {0x91493440, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Collection = {0x91493450, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID__Application = {0x91493442, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID__Global = {0x91493451, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID CLSID_PowerPointApplication = {0x91493441, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID CLSID_PowerPointGlobal = {0x91493443, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ColorFormat = {0x91493452, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SlideShowWindow = {0x91493453, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Selection = {0x91493454, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_DocumentWindows = {0x91493455, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SlideShowWindows = {0x91493456, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_DocumentWindow = {0x91493457, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_View = {0x91493458, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SlideShowView = {0x91493459, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SlideShowSettings = {0x9149345A, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_NamedSlideShows = {0x9149345B, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_NamedSlideShow = {0x9149345C, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PrintOptions = {0x9149345D, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PrintRanges = {0x9149345E, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PrintRange = {0x9149345F, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_AddIns = {0x91493460, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_AddIn = {0x91493461, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Presentations = {0x91493462, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PresEvents = {0x91493463, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID CLSID_PowerPointPresentation = {0x91493444, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Hyperlinks = {0x91493464, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Hyperlink = {0x91493465, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PageSetup = {0x91493466, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Fonts = {0x91493467, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ExtraColors = {0x91493468, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Slides = {0x91493469, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID__Slide = {0x9149346A, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SlideRange = {0x9149346B, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Master = {0x9149346C, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SldEvents = {0x9149346D, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID CLSID_PowerPointSlide = {0x91493445, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ColorSchemes = {0x9149346E, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ColorScheme = {0x9149346F, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_RGBColor = {0x91493470, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SlideShowTransition = {0x91493471, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SoundEffect = {0x91493472, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_SoundFormat = {0x91493473, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_HeadersFooters = {0x91493474, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Shapes = {0x91493475, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Placeholders = {0x91493476, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PlaceholderFormat = {0x91493477, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_FreeformBuilder = {0x91493478, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Shape = {0x91493479, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ShapeRange = {0x9149347A, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_GroupShapes = {0x9149347B, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Adjustments = {0x9149347C, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PictureFormat = {0x9149347D, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_FillFormat = {0x9149347E, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_LineFormat = {0x9149347F, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ShadowFormat = {0x91493480, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ConnectorFormat = {0x91493481, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextEffectFormat = {0x91493482, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ThreeDFormat = {0x91493483, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextFrame = {0x91493484, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_CalloutFormat = {0x91493485, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ShapeNodes = {0x91493486, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ShapeNode = {0x91493487, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_OLEFormat = {0x91493488, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_LinkFormat = {0x91493489, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ObjectVerbs = {0x9149348A, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_AnimationSettings = {0x9149348B, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ActionSettings = {0x9149348C, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ActionSetting = {0x9149348D, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PlaySettings = {0x9149348E, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextRange = {0x9149348F, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Ruler = {0x91493490, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_RulerLevels = {0x91493491, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_RulerLevel = {0x91493492, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TabStops = {0x91493493, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TabStop = {0x91493494, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Font = {0x91493495, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_ParagraphFormat = {0x91493496, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_BulletFormat = {0x91493497, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextStyles = {0x91493498, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextStyle = {0x91493499, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextStyleLevels = {0x9149349A, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_TextStyleLevel = {0x9149349B, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_HeaderFooter = {0x9149349C, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID__Presentation = {0x9149349D, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPDialogs = {0x9149349E, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPAlert = {0x9149349F, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPDialog = {0x914934A0, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPTabSheet = {0x914934A1, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPControls = {0x914934A2, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPTabSheets = {0x914934A3, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPControl = {0x914934A4, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPPushButton = {0x914934A5, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPToggleButton = {0x914934A6, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPBitmapButton = {0x914934A7, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPListBox = {0x914934A8, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPStrings = {0x914934A9, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPCheckBox = {0x914934AA, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPRadioCluster = {0x914934AB, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPStaticText = {0x914934AC, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPEditText = {0x914934AD, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPIcon = {0x914934AE, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPBitmap = {0x914934AF, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPSpinner = {0x914934B0, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPScrollBar = {0x914934B1, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPGroupBox = {0x914934B2, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPFrame = {0x914934B3, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPTabControl = {0x914934B4, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPDropDown = {0x914934B5, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPDropDownEdit = {0x914934B6, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPSlideMiniature = {0x914934B7, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_PPRadioButton = {0x914934B8, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_Tags = {0x914934B9, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_FileDialogFileList = {0x914934BA, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_FileDialogExtension = {0x914934BB, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_FileDialogExtensionList = {0x914934BC, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_FileDialog = {0x914934BD, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_MouseTracker = {0x914934BE, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_MouseDownHandler = {0x914934BF, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_OCXExtender = {0x914934C0, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID IID_OCXExtenderEvents = {0x914934C1, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };
const GUID CLSID_OLEControl = {0x91493446, 0x5A91, 0x11CF,{ 0x87, 0x00, 0x00, 0xAA, 0x00, 0x60, 0x26, 0x3B} };

};     // namespace Powerpoint_97
