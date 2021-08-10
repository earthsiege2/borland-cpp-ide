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
// ************************************************************************ //
#ifndef   __PowerPoint_97_SRVR_h__
#define   __PowerPoint_97_SRVR_h__

#pragma option push -b -w-inl

#include <utilcls.h>
#if !defined(__UTILCLS_H_VERSION) || (__UTILCLS_H_VERSION < 0x0500)
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
  Powerpoint_97::PresentationsPtr __fastcall Get_Presentations(void)
  {
    return GetDefaultInterface()->get_Presentations();
  }

  Powerpoint_97::DocumentWindowsPtr __fastcall Get_Windoz(void)
  {
    return GetDefaultInterface()->get_Windoz();
  }

  Powerpoint_97::PPDialogsPtr __fastcall Get_Dialogs(void)
  {
    return GetDefaultInterface()->get_Dialogs();
  }

  Powerpoint_97::DocumentWindowPtr __fastcall Get_ActiveWindow(void)
  {
    return GetDefaultInterface()->get_ActiveWindow();
  }

  Powerpoint_97::PowerPointPresentationPtr __fastcall Get_ActivePresentation(void)
  {
    return GetDefaultInterface()->get_ActivePresentation();
  }

  Powerpoint_97::SlideShowWindowsPtr __fastcall Get_SlideShowWindows(void)
  {
    return GetDefaultInterface()->get_SlideShowWindows();
  }

  Office_97::CommandBarsPtr __fastcall Get_CommandBars(void)
  {
    return GetDefaultInterface()->get_CommandBars();
  }

  BSTR __fastcall Get_Path(void)
  {
    return GetDefaultInterface()->get_Path();
  }

  BSTR __fastcall Get_Name(void)
  {
    return GetDefaultInterface()->get_Name();
  }

  BSTR __fastcall Get_Caption(void)
  {
    return GetDefaultInterface()->get_Caption();
  }

  void __fastcall Set_Caption(BSTR Caption/*[in]*/)
  {
    GetDefaultInterface()->set_Caption(Caption/*[in]*/);
  }

  Office_97::AssistantPtr __fastcall Get_Assistant(void)
  {
    return GetDefaultInterface()->get_Assistant();
  }

  Office_97::FileSearchPtr __fastcall Get_FileSearch(void)
  {
    return GetDefaultInterface()->get_FileSearch();
  }

  Office_97::IFindPtr __fastcall Get_FileFind(void)
  {
    return GetDefaultInterface()->get_FileFind();
  }

  BSTR __fastcall Get_Build(void)
  {
    return GetDefaultInterface()->get_Build();
  }

  BSTR __fastcall Get_Version(void)
  {
    return GetDefaultInterface()->get_Version();
  }

  BSTR __fastcall Get_OperatingSystem(void)
  {
    return GetDefaultInterface()->get_OperatingSystem();
  }

  BSTR __fastcall Get_ActivePrinter(void)
  {
    return GetDefaultInterface()->get_ActivePrinter();
  }

  long __fastcall Get_Creator(void)
  {
    return GetDefaultInterface()->get_Creator();
  }

  Powerpoint_97::AddInsPtr __fastcall Get_AddIns(void)
  {
    return GetDefaultInterface()->get_AddIns();
  }

  Vbide_97::VBEPtr __fastcall Get_VBE(void)
  {
    return GetDefaultInterface()->get_VBE();
  }

  float __fastcall Get_Left(void)
  {
    return GetDefaultInterface()->get_Left();
  }

  void __fastcall Set_Left(float Left/*[in]*/)
  {
    GetDefaultInterface()->set_Left(Left/*[in]*/);
  }

  float __fastcall Get_Top(void)
  {
    return GetDefaultInterface()->get_Top();
  }

  void __fastcall Set_Top(float Top/*[in]*/)
  {
    GetDefaultInterface()->set_Top(Top/*[in]*/);
  }

  float __fastcall Get_Width(void)
  {
    return GetDefaultInterface()->get_Width();
  }

  void __fastcall Set_Width(float Width/*[in]*/)
  {
    GetDefaultInterface()->set_Width(Width/*[in]*/);
  }

  float __fastcall Get_Height(void)
  {
    return GetDefaultInterface()->get_Height();
  }

  void __fastcall Set_Height(float Height/*[in]*/)
  {
    GetDefaultInterface()->set_Height(Height/*[in]*/);
  }

  Powerpoint_97::PpWindowState __fastcall Get_WindowState(void)
  {
    return GetDefaultInterface()->get_WindowState();
  }

  void __fastcall Set_WindowState(Powerpoint_97::PpWindowState WindowState/*[in]*/)
  {
    GetDefaultInterface()->set_WindowState(WindowState/*[in]*/);
  }

  Office_97::MsoTriState __fastcall Get_Visible(void)
  {
    return GetDefaultInterface()->get_Visible();
  }

  void __fastcall Set_Visible(Office_97::MsoTriState Visible/*[in]*/)
  {
    GetDefaultInterface()->set_Visible(Visible/*[in]*/);
  }

  Office_97::MsoTriState __fastcall Get_Active(void)
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
  __property Powerpoint_97::PresentationsPtr Presentations={ read=Get_Presentations }; // 0, Yes
  __property Powerpoint_97::DocumentWindowsPtr Windoz={ read=Get_Windoz }; // 0, Yes
  __property Powerpoint_97::PPDialogsPtr Dialogs={ read=Get_Dialogs }; // 0, Yes
  __property Powerpoint_97::DocumentWindowPtr ActiveWindow={ read=Get_ActiveWindow }; // 0, Yes
  __property Powerpoint_97::PowerPointPresentationPtr ActivePresentation={ read=Get_ActivePresentation }; // 0, Yes
  __property Powerpoint_97::SlideShowWindowsPtr SlideShowWindows={ read=Get_SlideShowWindows }; // 0, Yes
  __property Office_97::CommandBarsPtr CommandBars={ read=Get_CommandBars }; // 0, Yes
  __property BSTR Path={ read=Get_Path }; // 0, No
  __property BSTR Name={ read=Get_Name }; // 0, No
  __property Office_97::AssistantPtr Assistant={ read=Get_Assistant }; // 0, Yes
  __property Office_97::FileSearchPtr FileSearch={ read=Get_FileSearch }; // 0, Yes
  __property Office_97::IFindPtr FileFind={ read=Get_FileFind }; // 0, Yes
  __property BSTR Build={ read=Get_Build }; // 0, No
  __property BSTR Version={ read=Get_Version }; // 0, No
  __property BSTR OperatingSystem={ read=Get_OperatingSystem }; // 0, No
  __property BSTR ActivePrinter={ read=Get_ActivePrinter }; // 0, No
  __property long Creator={ read=Get_Creator }; // 0, No
  __property Powerpoint_97::AddInsPtr AddIns={ read=Get_AddIns }; // 0, Yes
  __property Vbide_97::VBEPtr VBE={ read=Get_VBE }; // 0, Yes
  __property Office_97::MsoTriState Active={ read=Get_Active }; // 0, No
  /*CoClassWriteProperties*/
  __property BSTR Caption={ read=Get_Caption, write=Set_Caption, stored=false }; // 0, No
  __property float Left={ read=Get_Left, write=Set_Left, stored=false }; // 0, No
  __property float Top={ read=Get_Top, write=Set_Top, stored=false }; // 0, No
  __property float Width={ read=Get_Width, write=Set_Width, stored=false }; // 0, No
  __property float Height={ read=Get_Height, write=Set_Height, stored=false }; // 0, No
  __property Powerpoint_97::PpWindowState WindowState={ read=Get_WindowState, write=Set_WindowState, stored=false }; // 0, No
  __property Office_97::MsoTriState Visible={ read=Get_Visible, write=Set_Visible, stored=false }; // 0, No
private:
  bool     FAutoQuit;
__published:
  __property bool AutoQuit = {read=FAutoQuit, write=FAutoQuit};
};


// *********************************************************************//
// COM Component Proxy Class Declaration
// Component Name   : TPowerPointGlobal
// Help String      : 
// Default Interface: _Global
// Def. Intf. Object: _GlobalPtr
// Def. Intf. DISP? : No
// Event   Interface: 
// TypeFlags        : (27) AppObject CanCreate Predeclid Hidden
// *********************************************************************//
class PACKAGE TPowerPointGlobal : public Oleserver::TOleServer
{
  _GlobalPtr m_DefaultIntf;
  _di_IUnknown __fastcall GetDunk();
public:
  __fastcall TPowerPointGlobal(TComponent* owner) : Oleserver::TOleServer(owner)
  {}

  _GlobalPtr& GetDefaultInterface();
  void __fastcall InitServerData();
  void __fastcall Connect();
  void __fastcall Disconnect();
  void __fastcall BeforeDestruction();
  void __fastcall ConnectTo(_GlobalPtr intf);


  /*CoClassWriteArrayPropMethods*/
  Powerpoint_97::PowerPointPresentationPtr __fastcall Get_ActivePresentation(void)
  {
    return GetDefaultInterface()->get_ActivePresentation();
  }

  Powerpoint_97::DocumentWindowPtr __fastcall Get_ActiveWindow(void)
  {
    return GetDefaultInterface()->get_ActiveWindow();
  }

  Powerpoint_97::AddInsPtr __fastcall Get_AddIns(void)
  {
    return GetDefaultInterface()->get_AddIns();
  }

  LPDISPATCH __fastcall Get_Application(void)
  {
    return GetDefaultInterface()->get_Application();
  }

  Office_97::AssistantPtr __fastcall Get_Assistant(void)
  {
    return GetDefaultInterface()->get_Assistant();
  }

  Powerpoint_97::PPDialogsPtr __fastcall Get_Dialogs(void)
  {
    return GetDefaultInterface()->get_Dialogs();
  }

  Powerpoint_97::PresentationsPtr __fastcall Get_Presentations(void)
  {
    return GetDefaultInterface()->get_Presentations();
  }

  Powerpoint_97::SlideShowWindowsPtr __fastcall Get_SlideShowWindows(void)
  {
    return GetDefaultInterface()->get_SlideShowWindows();
  }

  Powerpoint_97::DocumentWindowsPtr __fastcall Get_Windoz(void)
  {
    return GetDefaultInterface()->get_Windoz();
  }

  Office_97::CommandBarsPtr __fastcall Get_CommandBars(void)
  {
    return GetDefaultInterface()->get_CommandBars();
  }

  /*CoClassWriteMethods*/
  /*CoClassWriteProperties*/
  __property Powerpoint_97::PowerPointPresentationPtr ActivePresentation={ read=Get_ActivePresentation }; // 0, Yes
  __property Powerpoint_97::DocumentWindowPtr ActiveWindow={ read=Get_ActiveWindow }; // 0, Yes
  __property Powerpoint_97::AddInsPtr AddIns={ read=Get_AddIns }; // 0, Yes
  __property LPDISPATCH Application={ read=Get_Application }; // 0, No
  __property Office_97::AssistantPtr Assistant={ read=Get_Assistant }; // 0, Yes
  __property Powerpoint_97::PPDialogsPtr Dialogs={ read=Get_Dialogs }; // 0, Yes
  __property Powerpoint_97::PresentationsPtr Presentations={ read=Get_Presentations }; // 0, Yes
  __property Powerpoint_97::SlideShowWindowsPtr SlideShowWindows={ read=Get_SlideShowWindows }; // 0, Yes
  __property Powerpoint_97::DocumentWindowsPtr Windoz={ read=Get_Windoz }; // 0, Yes
  __property Office_97::CommandBarsPtr CommandBars={ read=Get_CommandBars }; // 0, Yes
  /*CoClassWriteProperties*/
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

  virtual void __fastcall InvokeEvent(int DispID, TVariantArray& params);

  /*CoClassWriteArrayPropMethods*/
  LPDISPATCH __fastcall Get_Application(void)
  {
    return GetDefaultInterface()->get_Application();
  }

  LPDISPATCH __fastcall Get_Parent(void)
  {
    return GetDefaultInterface()->get_Parent();
  }

  Powerpoint_97::ShapesPtr __fastcall Get_Shapes(void)
  {
    return GetDefaultInterface()->get_Shapes();
  }

  Powerpoint_97::HeadersFootersPtr __fastcall Get_HeadersFooters(void)
  {
    return GetDefaultInterface()->get_HeadersFooters();
  }

  Powerpoint_97::SlideShowTransitionPtr __fastcall Get_SlideShowTransition(void)
  {
    return GetDefaultInterface()->get_SlideShowTransition();
  }

  Powerpoint_97::ColorSchemePtr __fastcall Get_ColorScheme(void)
  {
    return GetDefaultInterface()->get_ColorScheme();
  }

  void __fastcall Set_ColorScheme(Powerpoint_97::ColorSchemePtr ColorScheme/*[in]*/)
  {
    GetDefaultInterface()->set_ColorScheme(ColorScheme/*[in]*/);
  }

  Powerpoint_97::ShapeRangePtr __fastcall Get_Background(void)
  {
    return GetDefaultInterface()->get_Background();
  }

  BSTR __fastcall Get_Name(void)
  {
    return GetDefaultInterface()->get_Name();
  }

  void __fastcall Set_Name(BSTR Name/*[in]*/)
  {
    GetDefaultInterface()->set_Name(Name/*[in]*/);
  }

  long __fastcall Get_SlideID(void)
  {
    return GetDefaultInterface()->get_SlideID();
  }

  int __fastcall Get_PrintSteps(void)
  {
    return GetDefaultInterface()->get_PrintSteps();
  }

  Powerpoint_97::PpSlideLayout __fastcall Get_Layout(void)
  {
    return GetDefaultInterface()->get_Layout();
  }

  void __fastcall Set_Layout(Powerpoint_97::PpSlideLayout Layout/*[in]*/)
  {
    GetDefaultInterface()->set_Layout(Layout/*[in]*/);
  }

  Powerpoint_97::TagsPtr __fastcall Get_Tags(void)
  {
    return GetDefaultInterface()->get_Tags();
  }

  int __fastcall Get_SlideIndex(void)
  {
    return GetDefaultInterface()->get_SlideIndex();
  }

  int __fastcall Get_SlideNumber(void)
  {
    return GetDefaultInterface()->get_SlideNumber();
  }

  Office_97::MsoTriState __fastcall Get_DisplayMasterShapes(void)
  {
    return GetDefaultInterface()->get_DisplayMasterShapes();
  }

  void __fastcall Set_DisplayMasterShapes(Office_97::MsoTriState DisplayMasterShapes/*[in]*/)
  {
    GetDefaultInterface()->set_DisplayMasterShapes(DisplayMasterShapes/*[in]*/);
  }

  Office_97::MsoTriState __fastcall Get_FollowMasterBackground(void)
  {
    return GetDefaultInterface()->get_FollowMasterBackground();
  }

  void __fastcall Set_FollowMasterBackground(Office_97::MsoTriState FollowMasterBackground/*[in]*/)
  {
    GetDefaultInterface()->set_FollowMasterBackground(FollowMasterBackground/*[in]*/);
  }

  Powerpoint_97::SlideRangePtr __fastcall Get_NotesPage(void)
  {
    return GetDefaultInterface()->get_NotesPage();
  }

  Powerpoint_97::MasterPtr __fastcall Get_Master(void)
  {
    return GetDefaultInterface()->get_Master();
  }

  Powerpoint_97::HyperlinksPtr __fastcall Get_Hyperlinks(void)
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
  __property LPDISPATCH Application={ read=Get_Application }; // 0, No
  __property LPDISPATCH Parent={ read=Get_Parent }; // 0, No
  __property Powerpoint_97::ShapesPtr Shapes={ read=Get_Shapes }; // 0, Yes
  __property Powerpoint_97::HeadersFootersPtr HeadersFooters={ read=Get_HeadersFooters }; // 0, Yes
  __property Powerpoint_97::SlideShowTransitionPtr SlideShowTransition={ read=Get_SlideShowTransition }; // 0, Yes
  __property Powerpoint_97::ShapeRangePtr Background={ read=Get_Background }; // 0, Yes
  __property long SlideID={ read=Get_SlideID }; // 0, No
  __property int PrintSteps={ read=Get_PrintSteps }; // 0, No
  __property Powerpoint_97::TagsPtr Tags={ read=Get_Tags }; // 0, Yes
  __property int SlideIndex={ read=Get_SlideIndex }; // 0, No
  __property int SlideNumber={ read=Get_SlideNumber }; // 0, No
  __property Powerpoint_97::SlideRangePtr NotesPage={ read=Get_NotesPage }; // 0, Yes
  __property Powerpoint_97::MasterPtr Master={ read=Get_Master }; // 0, Yes
  __property Powerpoint_97::HyperlinksPtr Hyperlinks={ read=Get_Hyperlinks }; // 0, Yes
  /*CoClassWriteProperties*/
  __property Powerpoint_97::ColorSchemePtr ColorScheme={ read=Get_ColorScheme, write=Set_ColorScheme, stored=false }; // 0, Yes
  __property BSTR Name={ read=Get_Name, write=Set_Name, stored=false }; // 0, No
  __property Powerpoint_97::PpSlideLayout Layout={ read=Get_Layout, write=Set_Layout, stored=false }; // 0, No
  __property Office_97::MsoTriState DisplayMasterShapes={ read=Get_DisplayMasterShapes, write=Set_DisplayMasterShapes, stored=false }; // 0, No
  __property Office_97::MsoTriState FollowMasterBackground={ read=Get_FollowMasterBackground, write=Set_FollowMasterBackground, stored=false }; // 0, No
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

  virtual void __fastcall InvokeEvent(int DispID, TVariantArray& params);

  /*CoClassWriteArrayPropMethods*/
  LPDISPATCH __fastcall Get_Application(void)
  {
    return GetDefaultInterface()->get_Application();
  }

  LPDISPATCH __fastcall Get_Parent(void)
  {
    return GetDefaultInterface()->get_Parent();
  }

  Powerpoint_97::MasterPtr __fastcall Get_SlideMaster(void)
  {
    return GetDefaultInterface()->get_SlideMaster();
  }

  Powerpoint_97::MasterPtr __fastcall Get_TitleMaster(void)
  {
    return GetDefaultInterface()->get_TitleMaster();
  }

  Office_97::MsoTriState __fastcall Get_HasTitleMaster(void)
  {
    return GetDefaultInterface()->get_HasTitleMaster();
  }

  BSTR __fastcall Get_TemplateName(void)
  {
    return GetDefaultInterface()->get_TemplateName();
  }

  Powerpoint_97::MasterPtr __fastcall Get_NotesMaster(void)
  {
    return GetDefaultInterface()->get_NotesMaster();
  }

  Powerpoint_97::MasterPtr __fastcall Get_HandoutMaster(void)
  {
    return GetDefaultInterface()->get_HandoutMaster();
  }

  Powerpoint_97::SlidesPtr __fastcall Get_Slides(void)
  {
    return GetDefaultInterface()->get_Slides();
  }

  Powerpoint_97::PageSetupPtr __fastcall Get_PageSetup(void)
  {
    return GetDefaultInterface()->get_PageSetup();
  }

  Powerpoint_97::ColorSchemesPtr __fastcall Get_ColorSchemes(void)
  {
    return GetDefaultInterface()->get_ColorSchemes();
  }

  Powerpoint_97::ExtraColorsPtr __fastcall Get_ExtraColors(void)
  {
    return GetDefaultInterface()->get_ExtraColors();
  }

  Powerpoint_97::SlideShowSettingsPtr __fastcall Get_SlideShowSettings(void)
  {
    return GetDefaultInterface()->get_SlideShowSettings();
  }

  Powerpoint_97::FontsPtr __fastcall Get_Fonts(void)
  {
    return GetDefaultInterface()->get_Fonts();
  }

  Powerpoint_97::DocumentWindowsPtr __fastcall Get_Windoz(void)
  {
    return GetDefaultInterface()->get_Windoz();
  }

  Powerpoint_97::TagsPtr __fastcall Get_Tags(void)
  {
    return GetDefaultInterface()->get_Tags();
  }

  Powerpoint_97::ShapePtr __fastcall Get_DefaultShape(void)
  {
    return GetDefaultInterface()->get_DefaultShape();
  }

  LPDISPATCH __fastcall Get_BuiltInDocumentProperties(void)
  {
    return GetDefaultInterface()->get_BuiltInDocumentProperties();
  }

  LPDISPATCH __fastcall Get_CustomDocumentProperties(void)
  {
    return GetDefaultInterface()->get_CustomDocumentProperties();
  }

  Vbide_97::VBProjectPtr __fastcall Get_VBProject(void)
  {
    return GetDefaultInterface()->get_VBProject();
  }

  Office_97::MsoTriState __fastcall Get_ReadOnly(void)
  {
    return GetDefaultInterface()->get_ReadOnly();
  }

  BSTR __fastcall Get_FullName(void)
  {
    return GetDefaultInterface()->get_FullName();
  }

  BSTR __fastcall Get_Name(void)
  {
    return GetDefaultInterface()->get_Name();
  }

  BSTR __fastcall Get_Path(void)
  {
    return GetDefaultInterface()->get_Path();
  }

  Office_97::MsoTriState __fastcall Get_Saved(void)
  {
    return GetDefaultInterface()->get_Saved();
  }

  void __fastcall Set_Saved(Office_97::MsoTriState Saved/*[in]*/)
  {
    GetDefaultInterface()->set_Saved(Saved/*[in]*/);
  }

  Powerpoint_97::PpDirection __fastcall Get_LayoutDirection(void)
  {
    return GetDefaultInterface()->get_LayoutDirection();
  }

  void __fastcall Set_LayoutDirection(Powerpoint_97::PpDirection LayoutDirection/*[in]*/)
  {
    GetDefaultInterface()->set_LayoutDirection(LayoutDirection/*[in]*/);
  }

  Powerpoint_97::PrintOptionsPtr __fastcall Get_PrintOptions(void)
  {
    return GetDefaultInterface()->get_PrintOptions();
  }

  LPDISPATCH __fastcall Get_Container(void)
  {
    return GetDefaultInterface()->get_Container();
  }

  Office_97::MsoTriState __fastcall Get_DisplayComments(void)
  {
    return GetDefaultInterface()->get_DisplayComments();
  }

  void __fastcall Set_DisplayComments(Office_97::MsoTriState DisplayComments/*[in]*/)
  {
    GetDefaultInterface()->set_DisplayComments(DisplayComments/*[in]*/);
  }

  Powerpoint_97::PpFarEastLineBreakLevel __fastcall Get_FarEastLineBreakLevel(void)
  {
    return GetDefaultInterface()->get_FarEastLineBreakLevel();
  }

  void __fastcall Set_FarEastLineBreakLevel(Powerpoint_97::PpFarEastLineBreakLevel FarEastLineBreakLevel/*[in]*/)
  {
    GetDefaultInterface()->set_FarEastLineBreakLevel(FarEastLineBreakLevel/*[in]*/);
  }

  BSTR __fastcall Get_NoLineBreakBefore(void)
  {
    return GetDefaultInterface()->get_NoLineBreakBefore();
  }

  void __fastcall Set_NoLineBreakBefore(BSTR NoLineBreakBefore/*[in]*/)
  {
    GetDefaultInterface()->set_NoLineBreakBefore(NoLineBreakBefore/*[in]*/);
  }

  BSTR __fastcall Get_NoLineBreakAfter(void)
  {
    return GetDefaultInterface()->get_NoLineBreakAfter();
  }

  void __fastcall Set_NoLineBreakAfter(BSTR NoLineBreakAfter/*[in]*/)
  {
    GetDefaultInterface()->set_NoLineBreakAfter(NoLineBreakAfter/*[in]*/);
  }

  Powerpoint_97::SlideShowWindowPtr __fastcall Get_SlideShowWindow(void)
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
                                  TOLEBOOL NewWindow/*[in,def,opt]*/, 
                                  TOLEBOOL AddHistory/*[in,def,opt]*/, 
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
  __property LPDISPATCH Application={ read=Get_Application }; // 0, No
  __property LPDISPATCH Parent={ read=Get_Parent }; // 0, No
  __property Powerpoint_97::MasterPtr SlideMaster={ read=Get_SlideMaster }; // 0, Yes
  __property Powerpoint_97::MasterPtr TitleMaster={ read=Get_TitleMaster }; // 0, Yes
  __property Office_97::MsoTriState HasTitleMaster={ read=Get_HasTitleMaster }; // 0, No
  __property BSTR TemplateName={ read=Get_TemplateName }; // 0, No
  __property Powerpoint_97::MasterPtr NotesMaster={ read=Get_NotesMaster }; // 0, Yes
  __property Powerpoint_97::MasterPtr HandoutMaster={ read=Get_HandoutMaster }; // 0, Yes
  __property Powerpoint_97::SlidesPtr Slides={ read=Get_Slides }; // 0, Yes
  __property Powerpoint_97::PageSetupPtr PageSetup={ read=Get_PageSetup }; // 0, Yes
  __property Powerpoint_97::ColorSchemesPtr ColorSchemes={ read=Get_ColorSchemes }; // 0, Yes
  __property Powerpoint_97::ExtraColorsPtr ExtraColors={ read=Get_ExtraColors }; // 0, Yes
  __property Powerpoint_97::SlideShowSettingsPtr SlideShowSettings={ read=Get_SlideShowSettings }; // 0, Yes
  __property Powerpoint_97::FontsPtr Fonts={ read=Get_Fonts }; // 0, Yes
  __property Powerpoint_97::DocumentWindowsPtr Windoz={ read=Get_Windoz }; // 0, Yes
  __property Powerpoint_97::TagsPtr Tags={ read=Get_Tags }; // 0, Yes
  __property Powerpoint_97::ShapePtr DefaultShape={ read=Get_DefaultShape }; // 0, Yes
  __property LPDISPATCH BuiltInDocumentProperties={ read=Get_BuiltInDocumentProperties }; // 0, No
  __property LPDISPATCH CustomDocumentProperties={ read=Get_CustomDocumentProperties }; // 0, No
  __property Vbide_97::VBProjectPtr VBProject={ read=Get_VBProject }; // 0, Yes
  __property Office_97::MsoTriState ReadOnly={ read=Get_ReadOnly }; // 0, No
  __property BSTR FullName={ read=Get_FullName }; // 0, No
  __property BSTR Name={ read=Get_Name }; // 0, No
  __property BSTR Path={ read=Get_Path }; // 0, No
  __property Powerpoint_97::PrintOptionsPtr PrintOptions={ read=Get_PrintOptions }; // 0, Yes
  __property LPDISPATCH Container={ read=Get_Container }; // 0, No
  __property Powerpoint_97::SlideShowWindowPtr SlideShowWindow={ read=Get_SlideShowWindow }; // 0, Yes
  /*CoClassWriteProperties*/
  __property Office_97::MsoTriState Saved={ read=Get_Saved, write=Set_Saved, stored=false }; // 0, No
  __property Powerpoint_97::PpDirection LayoutDirection={ read=Get_LayoutDirection, write=Set_LayoutDirection, stored=false }; // 0, No
  __property Office_97::MsoTriState DisplayComments={ read=Get_DisplayComments, write=Set_DisplayComments, stored=false }; // 0, No
  __property Powerpoint_97::PpFarEastLineBreakLevel FarEastLineBreakLevel={ read=Get_FarEastLineBreakLevel, write=Set_FarEastLineBreakLevel, stored=false }; // 0, No
  __property BSTR NoLineBreakBefore={ read=Get_NoLineBreakBefore, write=Set_NoLineBreakBefore, stored=false }; // 0, No
  __property BSTR NoLineBreakAfter={ read=Get_NoLineBreakAfter, write=Set_NoLineBreakAfter, stored=false }; // 0, No
  /*CoClassWriteEventDecls*/
private:
__published:
};

};     // namespace Powerpoint_97

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Powerpoint_97;
#endif

#pragma option pop

#endif // __PowerPoint_97_SRVR_h__
