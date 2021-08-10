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
// File generated on 1/28/2002 7:55:43 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office97\office\msppt8.olb (1)
// LIBID: {91493440-5A91-11CF-8700-00AA0060263B}
// LCID: 0
// Helpfile: C:\Program Files\Microsoft Office\office97\Office\VBAPPT8.HLP
// HelpString: Microsoft PowerPoint 8.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.0 Office, (C:\Program Files\Microsoft Office\office97\Office\MSO97.DLL)
//   (3) v5.0 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBEEXT1.OLB)
// ************************************************************************ //
#ifndef   PowerPoint_97_SRVRH
#define   PowerPoint_97_SRVRH

#pragma option push -b -w-inl

#include <oleserver.hpp>
#include <utilcls.h>
#if !defined(__UTILCLS_H_VERSION) || (__UTILCLS_H_VERSION < 0x0600)
//
// The code generated by the TLIBIMP utility or the Import|TypeLibrary 
// and Import|ActiveX feature of C++Builder rely on specific versions of
// the header file UTILCLS.H found in the INCLUDE\VCL directory. If an 
// older version of the file is detected, you probably need an update/patch.
//
#error "This file requires a newer version of the header UTILCLS.H" \
       "You need to apply an update/patch to your copy of C++Builder"
#endif
#include <olectl.h>
#include <ocidl.h>
#if !defined(_NO_VCL)
#include <stdvcl.hpp>
#endif  //   _NO_VCL
#include <ocxproxy.h>
#include "Office_97.h"
#include "VBIDE_97.h"

#include "PowerPoint_97.h"
namespace Powerpoint_97
{

// *********************************************************************//
// HelpString: Microsoft PowerPoint 8.0 Object Library
// Version:    2.5
// *********************************************************************//


// *********************************************************************//
// COM Component Proxy Class Declaration
// Component Name   : TPowerPointApplication
// Help String      : 
// Default Interface: _Application
// Def. Intf. Object: _ApplicationPtr
// Def. Intf. DISP? : No
// Event   Interface: 
// TypeFlags        : (2) CanCreate
// *********************************************************************//
class PACKAGE TPowerPointApplication : public Oleserver::TOleServer
{
  _ApplicationPtr m_DefaultIntf;
  _di_IUnknown __fastcall GetDunk();
public:
  __fastcall TPowerPointApplication(TComponent* owner) : Oleserver::TOleServer(owner)
  {}

  _ApplicationPtr& GetDefaultInterface();
  void __fastcall InitServerData();
  void __fastcall Connect();
  void __fastcall Disconnect();
  void __fastcall BeforeDestruction();
  void __fastcall ConnectTo(_ApplicationPtr intf);


  /*CoClassWriteArrayPropMethods*/
// StdProp:
  Powerpoint_97::PresentationsPtr __fastcall get_Presentations(void)
  {
    return GetDefaultInterface()->get_Presentations();
  }

// StdProp:
  Powerpoint_97::DocumentWindowsPtr __fastcall get_Windows(void)
  {
    return GetDefaultInterface()->get_Windows();
  }

// StdProp:
  Powerpoint_97::PPDialogsPtr __fastcall get_Dialogs(void)
  {
    return GetDefaultInterface()->get_Dialogs();
  }

// StdProp:
  Powerpoint_97::DocumentWindowPtr __fastcall get_ActiveWindow(void)
  {
    return GetDefaultInterface()->get_ActiveWindow();
  }

// StdProp:
  Powerpoint_97::PowerPointPresentationPtr __fastcall get_ActivePresentation(void)
  {
    return GetDefaultInterface()->get_ActivePresentation();
  }

// StdProp:
  Powerpoint_97::SlideShowWindowsPtr __fastcall get_SlideShowWindows(void)
  {
    return GetDefaultInterface()->get_SlideShowWindows();
  }

// StdProp:
  Office_97::CommandBarsPtr __fastcall get_CommandBars(void)
  {
    return GetDefaultInterface()->get_CommandBars();
  }

// StdProp:WideString
  BSTR __fastcall get_Path(void)
  {
    return GetDefaultInterface()->get_Path();
  }

// StdProp:WideString
  BSTR __fastcall get_Name(void)
  {
    return GetDefaultInterface()->get_Name();
  }

// StdProp:WideString
  BSTR __fastcall get_Caption(void)
  {
    return GetDefaultInterface()->get_Caption();
  }

// StdProp:WideString
  void __fastcall set_Caption(BSTR Caption/*[in]*/)
  {
    GetDefaultInterface()->set_Caption(Caption/*[in]*/);
  }

// StdProp:
  Office_97::AssistantPtr __fastcall get_Assistant(void)
  {
    return GetDefaultInterface()->get_Assistant();
  }

// StdProp:
  Office_97::FileSearchPtr __fastcall get_FileSearch(void)
  {
    return GetDefaultInterface()->get_FileSearch();
  }

// StdProp:
  Office_97::IFindPtr __fastcall get_FileFind(void)
  {
    return GetDefaultInterface()->get_FileFind();
  }

// StdProp:WideString
  BSTR __fastcall get_Build(void)
  {
    return GetDefaultInterface()->get_Build();
  }

// StdProp:WideString
  BSTR __fastcall get_Version(void)
  {
    return GetDefaultInterface()->get_Version();
  }

// StdProp:WideString
  BSTR __fastcall get_OperatingSystem(void)
  {
    return GetDefaultInterface()->get_OperatingSystem();
  }

// StdProp:WideString
  BSTR __fastcall get_ActivePrinter(void)
  {
    return GetDefaultInterface()->get_ActivePrinter();
  }

// StdProp:Integer
  long __fastcall get_Creator(void)
  {
    return GetDefaultInterface()->get_Creator();
  }

// StdProp:
  Powerpoint_97::AddInsPtr __fastcall get_AddIns(void)
  {
    return GetDefaultInterface()->get_AddIns();
  }

// StdProp:
  Vbide_97::VBEPtr __fastcall get_VBE(void)
  {
    return GetDefaultInterface()->get_VBE();
  }

// StdProp:Single
  float __fastcall get_Left(void)
  {
    return GetDefaultInterface()->get_Left();
  }

// StdProp:Single
  void __fastcall set_Left(float Left/*[in]*/)
  {
    GetDefaultInterface()->set_Left(Left/*[in]*/);
  }

// StdProp:Single
  float __fastcall get_Top(void)
  {
    return GetDefaultInterface()->get_Top();
  }

// StdProp:Single
  void __fastcall set_Top(float Top/*[in]*/)
  {
    GetDefaultInterface()->set_Top(Top/*[in]*/);
  }

// StdProp:Single
  float __fastcall get_Width(void)
  {
    return GetDefaultInterface()->get_Width();
  }

// StdProp:Single
  void __fastcall set_Width(float Width/*[in]*/)
  {
    GetDefaultInterface()->set_Width(Width/*[in]*/);
  }

// StdProp:Single
  float __fastcall get_Height(void)
  {
    return GetDefaultInterface()->get_Height();
  }

// StdProp:Single
  void __fastcall set_Height(float Height/*[in]*/)
  {
    GetDefaultInterface()->set_Height(Height/*[in]*/);
  }

// StdProp:TOleEnum
  Powerpoint_97::PpWindowState __fastcall get_WindowState(void)
  {
    return GetDefaultInterface()->get_WindowState();
  }

// StdProp:TOleEnum
  void __fastcall set_WindowState(Powerpoint_97::PpWindowState WindowState/*[in]*/)
  {
    GetDefaultInterface()->set_WindowState(WindowState/*[in]*/);
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_Visible(void)
  {
    return GetDefaultInterface()->get_Visible();
  }

// StdProp:TOleEnum
  void __fastcall set_Visible(Office_97::MsoTriState Visible/*[in]*/)
  {
    GetDefaultInterface()->set_Visible(Visible/*[in]*/);
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_Active(void)
  {
    return GetDefaultInterface()->get_Active();
  }

  /*CoClassWriteMethods*/
  void __fastcall Help(BSTR HelpFile/*[in,def,opt]*/, int ContextID/*[in,def,opt]*/)
  {
    GetDefaultInterface()->Help(HelpFile/*[in,def,opt]*/, ContextID/*[in,def,opt]*/);
  }

  void __fastcall Quit(void)
  {
    GetDefaultInterface()->Quit();
  }

  TVariant __fastcall Run(BSTR MacroName/*[in]*/, LPSAFEARRAY* safeArrayOfParams/*[in]*/)
  {
    return GetDefaultInterface()->Run(MacroName/*[in]*/, safeArrayOfParams/*[in]*/);
  }

  Powerpoint_97::FileDialogPtr __fastcall FileDialog(Powerpoint_97::PpFileDialogType Type/*[in]*/)
  {
    return GetDefaultInterface()->FileDialog(Type/*[in]*/);
  }

  void __fastcall Activate(void)
  {
    GetDefaultInterface()->Activate();
  }

  /*CoClassWriteProperties*/
  __property Powerpoint_97::PresentationsPtr Presentations={ read=get_Presentations }; // 0, Yes
  __property Powerpoint_97::DocumentWindowsPtr Windows={ read=get_Windows }; // 0, Yes
  __property Powerpoint_97::PPDialogsPtr Dialogs={ read=get_Dialogs }; // 0, Yes
  __property Powerpoint_97::DocumentWindowPtr ActiveWindow={ read=get_ActiveWindow }; // 0, Yes
  __property Powerpoint_97::PowerPointPresentationPtr ActivePresentation={ read=get_ActivePresentation }; // 0, Yes
  __property Powerpoint_97::SlideShowWindowsPtr SlideShowWindows={ read=get_SlideShowWindows }; // 0, Yes
  __property Office_97::CommandBarsPtr CommandBars={ read=get_CommandBars }; // 0, Yes
  __property BSTR Path={ read=get_Path }; // 0, No
  __property BSTR Name={ read=get_Name }; // 0, No
  __property Office_97::AssistantPtr Assistant={ read=get_Assistant }; // 0, Yes
  __property Office_97::FileSearchPtr FileSearch={ read=get_FileSearch }; // 0, Yes
  __property Office_97::IFindPtr FileFind={ read=get_FileFind }; // 0, Yes
  __property BSTR Build={ read=get_Build }; // 0, No
  __property BSTR Version={ read=get_Version }; // 0, No
  __property BSTR OperatingSystem={ read=get_OperatingSystem }; // 0, No
  __property BSTR ActivePrinter={ read=get_ActivePrinter }; // 0, No
  __property long Creator={ read=get_Creator }; // 0, No
  __property Powerpoint_97::AddInsPtr AddIns={ read=get_AddIns }; // 0, Yes
  __property Vbide_97::VBEPtr VBE={ read=get_VBE }; // 0, Yes
  __property Office_97::MsoTriState Active={ read=get_Active }; // 0, No
  /*CoClassWriteProperties*/
  __property BSTR Caption={ read=get_Caption, stored=false }; // 0, No
  __property float Left={ read=get_Left, stored=false }; // 0, No
  __property float Top={ read=get_Top, stored=false }; // 0, No
  __property float Width={ read=get_Width, stored=false }; // 0, No
  __property float Height={ read=get_Height, stored=false }; // 0, No
  __property Powerpoint_97::PpWindowState WindowState={ read=get_WindowState, stored=false }; // 0, No
  __property Office_97::MsoTriState Visible={ read=get_Visible, stored=false }; // 0, No
private:
  bool     FAutoQuit;
__published:
  __property bool AutoQuit = {read=FAutoQuit, write=FAutoQuit};
};


// *********************************************************************//
// COM Component Proxy Class Declaration
// Component Name   : TPowerPointSlide
// Help String      : 
// Default Interface: _Slide
// Def. Intf. Object: _SlidePtr
// Def. Intf. DISP? : No
// Event   Interface: SldEvents
// TypeFlags        : (2) CanCreate
// *********************************************************************//
class PACKAGE TPowerPointSlide : public Oleserver::TOleServer
{
  _SlidePtr m_DefaultIntf;
  _di_IUnknown __fastcall GetDunk();
public:
  __fastcall TPowerPointSlide(TComponent* owner) : Oleserver::TOleServer(owner)
  {}

  _SlidePtr& GetDefaultInterface();
  void __fastcall InitServerData();
  void __fastcall Connect();
  void __fastcall Disconnect();
  void __fastcall BeforeDestruction();
  void __fastcall ConnectTo(_SlidePtr intf);

  virtual void __fastcall InvokeEvent(int DispID, Oleserver::TVariantArray& params);

  /*CoClassWriteArrayPropMethods*/
// StdProp:IDispatch
  LPDISPATCH __fastcall get_Application(void)
  {
    return GetDefaultInterface()->get_Application();
  }

// StdProp:IDispatch
  LPDISPATCH __fastcall get_Parent(void)
  {
    return GetDefaultInterface()->get_Parent();
  }

// StdProp:
  Powerpoint_97::ShapesPtr __fastcall get_Shapes(void)
  {
    return GetDefaultInterface()->get_Shapes();
  }

// StdProp:
  Powerpoint_97::HeadersFootersPtr __fastcall get_HeadersFooters(void)
  {
    return GetDefaultInterface()->get_HeadersFooters();
  }

// StdProp:
  Powerpoint_97::SlideShowTransitionPtr __fastcall get_SlideShowTransition(void)
  {
    return GetDefaultInterface()->get_SlideShowTransition();
  }

// StdProp:
  Powerpoint_97::ColorSchemePtr __fastcall get_ColorScheme(void)
  {
    return GetDefaultInterface()->get_ColorScheme();
  }

// StdProp:
  void __fastcall set_ColorScheme(Powerpoint_97::ColorScheme* ColorScheme/*[in]*/)
  {
    GetDefaultInterface()->set_ColorScheme(ColorScheme/*[in]*/);
  }

// StdProp:
  Powerpoint_97::ShapeRangePtr __fastcall get_Background(void)
  {
    return GetDefaultInterface()->get_Background();
  }

// StdProp:WideString
  BSTR __fastcall get_Name(void)
  {
    return GetDefaultInterface()->get_Name();
  }

// StdProp:WideString
  void __fastcall set_Name(BSTR Name/*[in]*/)
  {
    GetDefaultInterface()->set_Name(Name/*[in]*/);
  }

// StdProp:Integer
  long __fastcall get_SlideID(void)
  {
    return GetDefaultInterface()->get_SlideID();
  }

// StdProp:Integer
  int __fastcall get_PrintSteps(void)
  {
    return GetDefaultInterface()->get_PrintSteps();
  }

// StdProp:TOleEnum
  Powerpoint_97::PpSlideLayout __fastcall get_Layout(void)
  {
    return GetDefaultInterface()->get_Layout();
  }

// StdProp:TOleEnum
  void __fastcall set_Layout(Powerpoint_97::PpSlideLayout Layout/*[in]*/)
  {
    GetDefaultInterface()->set_Layout(Layout/*[in]*/);
  }

// StdProp:
  Powerpoint_97::TagsPtr __fastcall get_Tags(void)
  {
    return GetDefaultInterface()->get_Tags();
  }

// StdProp:Integer
  int __fastcall get_SlideIndex(void)
  {
    return GetDefaultInterface()->get_SlideIndex();
  }

// StdProp:Integer
  int __fastcall get_SlideNumber(void)
  {
    return GetDefaultInterface()->get_SlideNumber();
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_DisplayMasterShapes(void)
  {
    return GetDefaultInterface()->get_DisplayMasterShapes();
  }

// StdProp:TOleEnum
  void __fastcall set_DisplayMasterShapes(Office_97::MsoTriState DisplayMasterShapes/*[in]*/)
  {
    GetDefaultInterface()->set_DisplayMasterShapes(DisplayMasterShapes/*[in]*/);
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_FollowMasterBackground(void)
  {
    return GetDefaultInterface()->get_FollowMasterBackground();
  }

// StdProp:TOleEnum
  void __fastcall set_FollowMasterBackground(Office_97::MsoTriState FollowMasterBackground/*[in]*/)
  {
    GetDefaultInterface()->set_FollowMasterBackground(FollowMasterBackground/*[in]*/);
  }

// StdProp:
  Powerpoint_97::SlideRangePtr __fastcall get_NotesPage(void)
  {
    return GetDefaultInterface()->get_NotesPage();
  }

// StdProp:
  Powerpoint_97::MasterPtr __fastcall get_Master(void)
  {
    return GetDefaultInterface()->get_Master();
  }

// StdProp:
  Powerpoint_97::HyperlinksPtr __fastcall get_Hyperlinks(void)
  {
    return GetDefaultInterface()->get_Hyperlinks();
  }

  /*CoClassWriteMethods*/
  void __fastcall Select(void)
  {
    GetDefaultInterface()->Select();
  }

  void __fastcall Cut(void)
  {
    GetDefaultInterface()->Cut();
  }

  void __fastcall Copy(void)
  {
    GetDefaultInterface()->Copy();
  }

  Powerpoint_97::SlideRangePtr __fastcall Duplicate(void)
  {
    return GetDefaultInterface()->Duplicate();
  }

  void __fastcall Delete(void)
  {
    GetDefaultInterface()->Delete();
  }

  void __fastcall Export(BSTR FileName/*[in]*/, BSTR FilterName/*[in]*/, 
                         int ScaleWidth/*[in,def,opt]*/, int ScaleHeight/*[in,def,opt]*/)
  {
    GetDefaultInterface()->Export(FileName/*[in]*/, FilterName/*[in]*/, ScaleWidth/*[in,def,opt]*/, 
                                  ScaleHeight/*[in,def,opt]*/);
  }

  /*CoClassWriteProperties*/
  __property LPDISPATCH Application={ read=get_Application }; // 0, No
  __property LPDISPATCH Parent={ read=get_Parent }; // 0, No
  __property Powerpoint_97::ShapesPtr Shapes={ read=get_Shapes }; // 0, Yes
  __property Powerpoint_97::HeadersFootersPtr HeadersFooters={ read=get_HeadersFooters }; // 0, Yes
  __property Powerpoint_97::SlideShowTransitionPtr SlideShowTransition={ read=get_SlideShowTransition }; // 0, Yes
  __property Powerpoint_97::ShapeRangePtr Background={ read=get_Background }; // 0, Yes
  __property long SlideID={ read=get_SlideID }; // 0, No
  __property int PrintSteps={ read=get_PrintSteps }; // 0, No
  __property Powerpoint_97::TagsPtr Tags={ read=get_Tags }; // 0, Yes
  __property int SlideIndex={ read=get_SlideIndex }; // 0, No
  __property int SlideNumber={ read=get_SlideNumber }; // 0, No
  __property Powerpoint_97::SlideRangePtr NotesPage={ read=get_NotesPage }; // 0, Yes
  __property Powerpoint_97::MasterPtr Master={ read=get_Master }; // 0, Yes
  __property Powerpoint_97::HyperlinksPtr Hyperlinks={ read=get_Hyperlinks }; // 0, Yes
  /*CoClassWriteProperties*/
  __property Powerpoint_97::ColorSchemePtr ColorScheme={ read=get_ColorScheme, stored=false }; // 0, Yes
  __property BSTR Name={ read=get_Name, stored=false }; // 0, No
  __property Powerpoint_97::PpSlideLayout Layout={ read=get_Layout, stored=false }; // 0, No
  __property Office_97::MsoTriState DisplayMasterShapes={ read=get_DisplayMasterShapes, stored=false }; // 0, No
  __property Office_97::MsoTriState FollowMasterBackground={ read=get_FollowMasterBackground, stored=false }; // 0, No
  /*CoClassWriteEventDecls*/
private:
__published:
};


// *********************************************************************//
// COM Component Proxy Class Declaration
// Component Name   : TPowerPointPresentation
// Help String      : 
// Default Interface: _Presentation
// Def. Intf. Object: _PresentationPtr
// Def. Intf. DISP? : No
// Event   Interface: PresEvents
// TypeFlags        : (2) CanCreate
// *********************************************************************//
class PACKAGE TPowerPointPresentation : public Oleserver::TOleServer
{
  _PresentationPtr m_DefaultIntf;
  _di_IUnknown __fastcall GetDunk();
public:
  __fastcall TPowerPointPresentation(TComponent* owner) : Oleserver::TOleServer(owner)
  {}

  _PresentationPtr& GetDefaultInterface();
  void __fastcall InitServerData();
  void __fastcall Connect();
  void __fastcall Disconnect();
  void __fastcall BeforeDestruction();
  void __fastcall ConnectTo(_PresentationPtr intf);

  virtual void __fastcall InvokeEvent(int DispID, Oleserver::TVariantArray& params);

  /*CoClassWriteArrayPropMethods*/
// StdProp:IDispatch
  LPDISPATCH __fastcall get_Application(void)
  {
    return GetDefaultInterface()->get_Application();
  }

// StdProp:IDispatch
  LPDISPATCH __fastcall get_Parent(void)
  {
    return GetDefaultInterface()->get_Parent();
  }

// StdProp:
  Powerpoint_97::MasterPtr __fastcall get_SlideMaster(void)
  {
    return GetDefaultInterface()->get_SlideMaster();
  }

// StdProp:
  Powerpoint_97::MasterPtr __fastcall get_TitleMaster(void)
  {
    return GetDefaultInterface()->get_TitleMaster();
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_HasTitleMaster(void)
  {
    return GetDefaultInterface()->get_HasTitleMaster();
  }

// StdProp:WideString
  BSTR __fastcall get_TemplateName(void)
  {
    return GetDefaultInterface()->get_TemplateName();
  }

// StdProp:
  Powerpoint_97::MasterPtr __fastcall get_NotesMaster(void)
  {
    return GetDefaultInterface()->get_NotesMaster();
  }

// StdProp:
  Powerpoint_97::MasterPtr __fastcall get_HandoutMaster(void)
  {
    return GetDefaultInterface()->get_HandoutMaster();
  }

// StdProp:
  Powerpoint_97::SlidesPtr __fastcall get_Slides(void)
  {
    return GetDefaultInterface()->get_Slides();
  }

// StdProp:
  Powerpoint_97::PageSetupPtr __fastcall get_PageSetup(void)
  {
    return GetDefaultInterface()->get_PageSetup();
  }

// StdProp:
  Powerpoint_97::ColorSchemesPtr __fastcall get_ColorSchemes(void)
  {
    return GetDefaultInterface()->get_ColorSchemes();
  }

// StdProp:
  Powerpoint_97::ExtraColorsPtr __fastcall get_ExtraColors(void)
  {
    return GetDefaultInterface()->get_ExtraColors();
  }

// StdProp:
  Powerpoint_97::SlideShowSettingsPtr __fastcall get_SlideShowSettings(void)
  {
    return GetDefaultInterface()->get_SlideShowSettings();
  }

// StdProp:
  Powerpoint_97::FontsPtr __fastcall get_Fonts(void)
  {
    return GetDefaultInterface()->get_Fonts();
  }

// StdProp:
  Powerpoint_97::DocumentWindowsPtr __fastcall get_Windows(void)
  {
    return GetDefaultInterface()->get_Windows();
  }

// StdProp:
  Powerpoint_97::TagsPtr __fastcall get_Tags(void)
  {
    return GetDefaultInterface()->get_Tags();
  }

// StdProp:
  Powerpoint_97::ShapePtr __fastcall get_DefaultShape(void)
  {
    return GetDefaultInterface()->get_DefaultShape();
  }

// StdProp:IDispatch
  LPDISPATCH __fastcall get_BuiltInDocumentProperties(void)
  {
    return GetDefaultInterface()->get_BuiltInDocumentProperties();
  }

// StdProp:IDispatch
  LPDISPATCH __fastcall get_CustomDocumentProperties(void)
  {
    return GetDefaultInterface()->get_CustomDocumentProperties();
  }

// StdProp:
  Vbide_97::VBProjectPtr __fastcall get_VBProject(void)
  {
    return GetDefaultInterface()->get_VBProject();
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_ReadOnly(void)
  {
    return GetDefaultInterface()->get_ReadOnly();
  }

// StdProp:WideString
  BSTR __fastcall get_FullName(void)
  {
    return GetDefaultInterface()->get_FullName();
  }

// StdProp:WideString
  BSTR __fastcall get_Name(void)
  {
    return GetDefaultInterface()->get_Name();
  }

// StdProp:WideString
  BSTR __fastcall get_Path(void)
  {
    return GetDefaultInterface()->get_Path();
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_Saved(void)
  {
    return GetDefaultInterface()->get_Saved();
  }

// StdProp:TOleEnum
  void __fastcall set_Saved(Office_97::MsoTriState Saved/*[in]*/)
  {
    GetDefaultInterface()->set_Saved(Saved/*[in]*/);
  }

// StdProp:TOleEnum
  Powerpoint_97::PpDirection __fastcall get_LayoutDirection(void)
  {
    return GetDefaultInterface()->get_LayoutDirection();
  }

// StdProp:TOleEnum
  void __fastcall set_LayoutDirection(Powerpoint_97::PpDirection LayoutDirection/*[in]*/)
  {
    GetDefaultInterface()->set_LayoutDirection(LayoutDirection/*[in]*/);
  }

// StdProp:
  Powerpoint_97::PrintOptionsPtr __fastcall get_PrintOptions(void)
  {
    return GetDefaultInterface()->get_PrintOptions();
  }

// StdProp:IDispatch
  LPDISPATCH __fastcall get_Container(void)
  {
    return GetDefaultInterface()->get_Container();
  }

// StdProp:TOleEnum
  Office_97::MsoTriState __fastcall get_DisplayComments(void)
  {
    return GetDefaultInterface()->get_DisplayComments();
  }

// StdProp:TOleEnum
  void __fastcall set_DisplayComments(Office_97::MsoTriState DisplayComments/*[in]*/)
  {
    GetDefaultInterface()->set_DisplayComments(DisplayComments/*[in]*/);
  }

// StdProp:TOleEnum
  Powerpoint_97::PpFarEastLineBreakLevel __fastcall get_FarEastLineBreakLevel(void)
  {
    return GetDefaultInterface()->get_FarEastLineBreakLevel();
  }

// StdProp:TOleEnum
  void __fastcall set_FarEastLineBreakLevel(Powerpoint_97::PpFarEastLineBreakLevel FarEastLineBreakLevel/*[in]*/)
  {
    GetDefaultInterface()->set_FarEastLineBreakLevel(FarEastLineBreakLevel/*[in]*/);
  }

// StdProp:WideString
  BSTR __fastcall get_NoLineBreakBefore(void)
  {
    return GetDefaultInterface()->get_NoLineBreakBefore();
  }

// StdProp:WideString
  void __fastcall set_NoLineBreakBefore(BSTR NoLineBreakBefore/*[in]*/)
  {
    GetDefaultInterface()->set_NoLineBreakBefore(NoLineBreakBefore/*[in]*/);
  }

// StdProp:WideString
  BSTR __fastcall get_NoLineBreakAfter(void)
  {
    return GetDefaultInterface()->get_NoLineBreakAfter();
  }

// StdProp:WideString
  void __fastcall set_NoLineBreakAfter(BSTR NoLineBreakAfter/*[in]*/)
  {
    GetDefaultInterface()->set_NoLineBreakAfter(NoLineBreakAfter/*[in]*/);
  }

// StdProp:
  Powerpoint_97::SlideShowWindowPtr __fastcall get_SlideShowWindow(void)
  {
    return GetDefaultInterface()->get_SlideShowWindow();
  }

  /*CoClassWriteMethods*/
  Powerpoint_97::MasterPtr __fastcall AddTitleMaster(void)
  {
    return GetDefaultInterface()->AddTitleMaster();
  }

  void __fastcall ApplyTemplate(BSTR FileName/*[in]*/)
  {
    GetDefaultInterface()->ApplyTemplate(FileName/*[in]*/);
  }

  Powerpoint_97::DocumentWindowPtr __fastcall NewWindow(void)
  {
    return GetDefaultInterface()->NewWindow();
  }

  void __fastcall FollowHyperlink(BSTR Address/*[in]*/, BSTR SubAddress/*[in,def,opt]*/, 
                                  VARIANT_BOOL NewWindow/*[in,def,opt]*/, 
                                  VARIANT_BOOL AddHistory/*[in,def,opt]*/, 
                                  BSTR ExtraInfo/*[in,def,opt]*/, 
                                  Office_97::MsoExtraInfoMethod Method/*[in,def,opt]*/, 
                                  BSTR HeaderInfo/*[in,def,opt]*/)
  {
    GetDefaultInterface()->FollowHyperlink(Address/*[in]*/, SubAddress/*[in,def,opt]*/, 
                                           NewWindow/*[in,def,opt]*/, AddHistory/*[in,def,opt]*/, 
                                           ExtraInfo/*[in,def,opt]*/, Method/*[in,def,opt]*/, 
                                           HeaderInfo/*[in,def,opt]*/);
  }

  void __fastcall AddToFavorites(void)
  {
    GetDefaultInterface()->AddToFavorites();
  }

  void __fastcall PrintOut(int From/*[in,def,opt]*/, int To/*[in,def,opt]*/, 
                           BSTR PrintToFile/*[in,def,opt]*/, int Copies/*[in,def,opt]*/, 
                           Office_97::MsoTriState Collate/*[in,def,opt]*/)
  {
    GetDefaultInterface()->PrintOut(From/*[in,def,opt]*/, To/*[in,def,opt]*/, 
                                    PrintToFile/*[in,def,opt]*/, Copies/*[in,def,opt]*/, 
                                    Collate/*[in,def,opt]*/);
  }

  void __fastcall Save(void)
  {
    GetDefaultInterface()->Save();
  }

  void __fastcall SaveAs(BSTR FileName/*[in]*/, 
                         Powerpoint_97::PpSaveAsFileType FileFormat/*[in,def,opt]*/, 
                         Office_97::MsoTriState EmbedTrueTypeFonts/*[in,def,opt]*/)
  {
    GetDefaultInterface()->SaveAs(FileName/*[in]*/, FileFormat/*[in,def,opt]*/, 
                                  EmbedTrueTypeFonts/*[in,def,opt]*/);
  }

  void __fastcall SaveCopyAs(BSTR FileName/*[in]*/, 
                             Powerpoint_97::PpSaveAsFileType FileFormat/*[in,def,opt]*/, 
                             Office_97::MsoTriState EmbedTrueTypeFonts/*[in,def,opt]*/)
  {
    GetDefaultInterface()->SaveCopyAs(FileName/*[in]*/, FileFormat/*[in,def,opt]*/, 
                                      EmbedTrueTypeFonts/*[in,def,opt]*/);
  }

  void __fastcall Export(BSTR Path/*[in]*/, BSTR FilterName/*[in]*/, int ScaleWidth/*[in,def,opt]*/, 
                         int ScaleHeight/*[in,def,opt]*/)
  {
    GetDefaultInterface()->Export(Path/*[in]*/, FilterName/*[in]*/, ScaleWidth/*[in,def,opt]*/, 
                                  ScaleHeight/*[in,def,opt]*/);
  }

  void __fastcall Close(void)
  {
    GetDefaultInterface()->Close();
  }

  void __fastcall SetUndoText(BSTR Text/*[in]*/)
  {
    GetDefaultInterface()->SetUndoText(Text/*[in]*/);
  }

  void __fastcall UpdateLinks(void)
  {
    GetDefaultInterface()->UpdateLinks();
  }

  /*CoClassWriteProperties*/
  __property LPDISPATCH Application={ read=get_Application }; // 0, No
  __property LPDISPATCH Parent={ read=get_Parent }; // 0, No
  __property Powerpoint_97::MasterPtr SlideMaster={ read=get_SlideMaster }; // 0, Yes
  __property Powerpoint_97::MasterPtr TitleMaster={ read=get_TitleMaster }; // 0, Yes
  __property Office_97::MsoTriState HasTitleMaster={ read=get_HasTitleMaster }; // 0, No
  __property BSTR TemplateName={ read=get_TemplateName }; // 0, No
  __property Powerpoint_97::MasterPtr NotesMaster={ read=get_NotesMaster }; // 0, Yes
  __property Powerpoint_97::MasterPtr HandoutMaster={ read=get_HandoutMaster }; // 0, Yes
  __property Powerpoint_97::SlidesPtr Slides={ read=get_Slides }; // 0, Yes
  __property Powerpoint_97::PageSetupPtr PageSetup={ read=get_PageSetup }; // 0, Yes
  __property Powerpoint_97::ColorSchemesPtr ColorSchemes={ read=get_ColorSchemes }; // 0, Yes
  __property Powerpoint_97::ExtraColorsPtr ExtraColors={ read=get_ExtraColors }; // 0, Yes
  __property Powerpoint_97::SlideShowSettingsPtr SlideShowSettings={ read=get_SlideShowSettings }; // 0, Yes
  __property Powerpoint_97::FontsPtr Fonts={ read=get_Fonts }; // 0, Yes
  __property Powerpoint_97::DocumentWindowsPtr Windows={ read=get_Windows }; // 0, Yes
  __property Powerpoint_97::TagsPtr Tags={ read=get_Tags }; // 0, Yes
  __property Powerpoint_97::ShapePtr DefaultShape={ read=get_DefaultShape }; // 0, Yes
  __property LPDISPATCH BuiltInDocumentProperties={ read=get_BuiltInDocumentProperties }; // 0, No
  __property LPDISPATCH CustomDocumentProperties={ read=get_CustomDocumentProperties }; // 0, No
  __property Vbide_97::VBProjectPtr VBProject={ read=get_VBProject }; // 0, Yes
  __property Office_97::MsoTriState ReadOnly={ read=get_ReadOnly }; // 0, No
  __property BSTR FullName={ read=get_FullName }; // 0, No
  __property BSTR Name={ read=get_Name }; // 0, No
  __property BSTR Path={ read=get_Path }; // 0, No
  __property Powerpoint_97::PrintOptionsPtr PrintOptions={ read=get_PrintOptions }; // 0, Yes
  __property LPDISPATCH Container={ read=get_Container }; // 0, No
  __property Powerpoint_97::SlideShowWindowPtr SlideShowWindow={ read=get_SlideShowWindow }; // 0, Yes
  /*CoClassWriteProperties*/
  __property Office_97::MsoTriState Saved={ read=get_Saved, stored=false }; // 0, No
  __property Powerpoint_97::PpDirection LayoutDirection={ read=get_LayoutDirection, stored=false }; // 0, No
  __property Office_97::MsoTriState DisplayComments={ read=get_DisplayComments, stored=false }; // 0, No
  __property Powerpoint_97::PpFarEastLineBreakLevel FarEastLineBreakLevel={ read=get_FarEastLineBreakLevel, stored=false }; // 0, No
  __property BSTR NoLineBreakBefore={ read=get_NoLineBreakBefore, stored=false }; // 0, No
  __property BSTR NoLineBreakAfter={ read=get_NoLineBreakAfter, stored=false }; // 0, No
  /*CoClassWriteEventDecls*/
private:
__published:
};

};     // namespace Powerpoint_97

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Powerpoint_97;
#endif

#pragma option pop

#endif // PowerPoint_97_SRVRH
