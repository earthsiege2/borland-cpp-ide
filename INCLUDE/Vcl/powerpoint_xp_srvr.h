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

// C++ TLBWRTR : $Revision:   1.0.1.0.1.2  $
// File generated on 1/29/2002 1:28:12 PM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\program files\microsoft office\office10\msppt.olb (1)
// LIBID: {91493440-5A91-11CF-8700-00AA0060263B}
// LCID: 0
// Helpfile: c:\program files\microsoft office\office10\VBAPP10.CHM
// HelpString: Microsoft PowerPoint 10.0 Object Library
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v2.2 Office, (C:\Program Files\Common Files\Microsoft Shared\Office10\MSO.DLL)
//   (3) v5.3 VBIDE, (C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.OLB)
// ************************************************************************ //
#ifndef   PowerPoint_XP_srvrH
#define   PowerPoint_XP_srvrH

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
#include "Office_XP.h"
#include "VBIDE_XP.h"

#include "PowerPoint_XP.h"
namespace Powerpoint_xp
{

// *********************************************************************//
// HelpString: Microsoft PowerPoint 10.0 Object Library
// Version:    2.7
// *********************************************************************//


// *********************************************************************//
// COM Component Proxy Class Declaration
// Component Name   : TPowerPointApplication
// Help String      : 
// Default Interface: _Application
// Def. Intf. Object: _ApplicationPtr
// Def. Intf. DISP? : No
// Event   Interface: EApplication
// TypeFlags        : (2) CanCreate
// *********************************************************************//
typedef void __fastcall (__closure * TPowerPointApplicationWindowSelectionChange)(System::TObject * Sender, 
                                                                                  Powerpoint_xp::Selection* Sel/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationWindowBeforeRightClick)(System::TObject * Sender, 
                                                                                   Powerpoint_xp::Selection* Sel/*[in]*/, 
                                                                                   VARIANT_BOOL* Cancel/*[in,out]*/);
typedef void __fastcall (__closure * TPowerPointApplicationWindowBeforeDoubleClick)(System::TObject * Sender, 
                                                                                    Powerpoint_xp::Selection* Sel/*[in]*/, 
                                                                                    VARIANT_BOOL* Cancel/*[in,out]*/);
typedef void __fastcall (__closure * TPowerPointApplicationPresentationClose)(System::TObject * Sender, 
                                                                              Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationPresentationSave)(System::TObject * Sender, 
                                                                             Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationPresentationOpen)(System::TObject * Sender, 
                                                                             Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationNewPresentation)(System::TObject * Sender, 
                                                                            Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationPresentationNewSlide)(System::TObject * Sender, 
                                                                                 Powerpoint_xp::PowerPointSlide* Sld/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationWindowActivate)(System::TObject * Sender, 
                                                                           Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/, 
                                                                           Powerpoint_xp::DocumentWindow* Wn/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationWindowDeactivate)(System::TObject * Sender, 
                                                                             Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/, 
                                                                             Powerpoint_xp::DocumentWindow* Wn/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationSlideShowBegin)(System::TObject * Sender, 
                                                                           Powerpoint_xp::SlideShowWindow* Wn/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationSlideShowNextBuild)(System::TObject * Sender, 
                                                                               Powerpoint_xp::SlideShowWindow* Wn/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationSlideShowNextSlide)(System::TObject * Sender, 
                                                                               Powerpoint_xp::SlideShowWindow* Wn/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationSlideShowEnd)(System::TObject * Sender, 
                                                                         Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationPresentationPrint)(System::TObject * Sender, 
                                                                              Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationSlideSelectionChanged)(System::TObject * Sender, 
                                                                                  Powerpoint_xp::SlideRange* SldRange/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationColorSchemeChanged)(System::TObject * Sender, 
                                                                               Powerpoint_xp::SlideRange* SldRange/*[in]*/);
typedef void __fastcall (__closure * TPowerPointApplicationPresentationBeforeSave)(System::TObject * Sender, 
                                                                                   Powerpoint_xp::PowerPointPresentation* Pres/*[in]*/, 
                                                                                   VARIANT_BOOL* Cancel/*[in,out]*/);
typedef void __fastcall (__closure * TPowerPointApplicationSlideShowNextClick)(System::TObject * Sender, 
                                                                               Powerpoint_xp::SlideShowWindow* Wn/*[in]*/, 
                                                                               Powerpoint_xp::Effect* nEffect/*[in]*/);

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

  virtual void __fastcall InvokeEvent(int DispID, Oleserver::TVariantArray& params);

  /*CoClassWriteArrayPropMethods*/
// StdProp:
  Powerpoint_xp::PresentationsPtr __fastcall get_Presentations(void)
  {
    return GetDefaultInterface()->get_Presentations();
  }

// StdProp:
  Powerpoint_xp::DocumentWindowsPtr __fastcall get_Windows(void)
  {
    return GetDefaultInterface()->get_Windows();
  }

// StdProp:IUnknown
  LPUNKNOWN __fastcall get_Dialogs(void)
  {
    return GetDefaultInterface()->get_Dialogs();
  }

// StdProp:
  Powerpoint_xp::DocumentWindowPtr __fastcall get_ActiveWindow(void)
  {
    return GetDefaultInterface()->get_ActiveWindow();
  }

// StdProp:
  Powerpoint_xp::PowerPointPresentationPtr __fastcall get_ActivePresentation(void)
  {
    return GetDefaultInterface()->get_ActivePresentation();
  }

// StdProp:
  Powerpoint_xp::SlideShowWindowsPtr __fastcall get_SlideShowWindows(void)
  {
    return GetDefaultInterface()->get_SlideShowWindows();
  }

// StdProp:
  Office_xp::CommandBarsPtr __fastcall get_CommandBars(void)
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
  Office_xp::AssistantPtr __fastcall get_Assistant(void)
  {
    return GetDefaultInterface()->get_Assistant();
  }

// StdProp:
  Office_xp::FileSearchPtr __fastcall get_FileSearch(void)
  {
    return GetDefaultInterface()->get_FileSearch();
  }

// StdProp:
  Office_xp::IFindPtr __fastcall get_FileFind(void)
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
  Powerpoint_xp::AddInsPtr __fastcall get_AddIns(void)
  {
    return GetDefaultInterface()->get_AddIns();
  }

// StdProp:
  Vbide_xp::VBEPtr __fastcall get_VBE(void)
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
  Powerpoint_xp::PpWindowState __fastcall get_WindowState(void)
  {
    return GetDefaultInterface()->get_WindowState();
  }

// StdProp:TOleEnum
  void __fastcall set_WindowState(Powerpoint_xp::PpWindowState WindowState/*[in]*/)
  {
    GetDefaultInterface()->set_WindowState(WindowState/*[in]*/);
  }

// StdProp:TOleEnum
  Office_xp::MsoTriState __fastcall get_Visible(void)
  {
    return GetDefaultInterface()->get_Visible();
  }

// StdProp:TOleEnum
  void __fastcall set_Visible(Office_xp::MsoTriState Visible/*[in]*/)
  {
    GetDefaultInterface()->set_Visible(Visible/*[in]*/);
  }

// StdProp:TOleEnum
  Office_xp::MsoTriState __fastcall get_Active(void)
  {
    return GetDefaultInterface()->get_Active();
  }

// StdProp:
  Office_xp::AnswerWizardPtr __fastcall get_AnswerWizard(void)
  {
    return GetDefaultInterface()->get_AnswerWizard();
  }

// StdProp:
  Office_xp::COMAddInsPtr __fastcall get_COMAddIns(void)
  {
    return GetDefaultInterface()->get_COMAddIns();
  }

// StdProp:WideString
  BSTR __fastcall get_ProductCode(void)
  {
    return GetDefaultInterface()->get_ProductCode();
  }

// StdProp:
  Powerpoint_xp::DefaultWebOptionsPtr __fastcall get_DefaultWebOptions(void)
  {
    return GetDefaultInterface()->get_DefaultWebOptions();
  }

// StdProp:
  Office_xp::LanguageSettingsPtr __fastcall get_LanguageSettings(void)
  {
    return GetDefaultInterface()->get_LanguageSettings();
  }

// StdProp:
  Office_xp::MsoDebugOptionsPtr __fastcall get_MsoDebugOptions(void)
  {
    return GetDefaultInterface()->get_MsoDebugOptions();
  }

// StdProp:TOleEnum
  Office_xp::MsoTriState __fastcall get_ShowWindowsInTaskbar(void)
  {
    return GetDefaultInterface()->get_ShowWindowsInTaskbar();
  }

// StdProp:TOleEnum
  void __fastcall set_ShowWindowsInTaskbar(Office_xp::MsoTriState ShowWindowsInTaskbar/*[in]*/)
  {
    GetDefaultInterface()->set_ShowWindowsInTaskbar(ShowWindowsInTaskbar/*[in]*/);
  }

// StdProp:IUnknown
  LPUNKNOWN __fastcall get_Marker(void)
  {
    return GetDefaultInterface()->get_Marker();
  }

// StdProp:TOleEnum
  Office_xp::MsoFeatureInstall __fastcall get_FeatureInstall(void)
  {
    return GetDefaultInterface()->get_FeatureInstall();
  }

// StdProp:TOleEnum
  void __fastcall set_FeatureInstall(Office_xp::MsoFeatureInstall FeatureInstall/*[in]*/)
  {
    GetDefaultInterface()->set_FeatureInstall(FeatureInstall/*[in]*/);
  }

// StdProp:
  Office_xp::FileDialogPtr __fastcall get_FileDialog(Office_xp::MsoFileDialogType Type/*[in]*/)
  {
    return GetDefaultInterface()->get_FileDialog(Type/*[in]*/);
  }

// StdProp:TOleEnum
  Office_xp::MsoTriState __fastcall get_DisplayGridLines(void)
  {
    return GetDefaultInterface()->get_DisplayGridLines();
  }

// StdProp:TOleEnum
  void __fastcall set_DisplayGridLines(Office_xp::MsoTriState DisplayGridLines/*[in]*/)
  {
    GetDefaultInterface()->set_DisplayGridLines(DisplayGridLines/*[in]*/);
  }

// StdProp:TOleEnum
  Office_xp::MsoAutomationSecurity __fastcall get_AutomationSecurity(void)
  {
    return GetDefaultInterface()->get_AutomationSecurity();
  }

// StdProp:TOleEnum
  void __fastcall set_AutomationSecurity(Office_xp::MsoAutomationSecurity AutomationSecurity/*[in]*/)
  {
    GetDefaultInterface()->set_AutomationSecurity(AutomationSecurity/*[in]*/);
  }

// StdProp:
  Office_xp::NewFilePtr __fastcall get_NewPresentation(void)
  {
    return GetDefaultInterface()->get_NewPresentation();
  }

// StdProp:TOleEnum
  Powerpoint_xp::PpAlertLevel __fastcall get_DisplayAlerts(void)
  {
    return GetDefaultInterface()->get_DisplayAlerts();
  }

// StdProp:TOleEnum
  void __fastcall set_DisplayAlerts(Powerpoint_xp::PpAlertLevel DisplayAlerts/*[in]*/)
  {
    GetDefaultInterface()->set_DisplayAlerts(DisplayAlerts/*[in]*/);
  }

// StdProp:TOleEnum
  Office_xp::MsoTriState __fastcall get_ShowStartupDialog(void)
  {
    return GetDefaultInterface()->get_ShowStartupDialog();
  }

// StdProp:TOleEnum
  void __fastcall set_ShowStartupDialog(Office_xp::MsoTriState ShowStartupDialog/*[in]*/)
  {
    GetDefaultInterface()->set_ShowStartupDialog(ShowStartupDialog/*[in]*/);
  }

// StdProp:
  Powerpoint_xp::AutoCorrectPtr __fastcall get_AutoCorrect(void)
  {
    return GetDefaultInterface()->get_AutoCorrect();
  }

// StdProp:
  Powerpoint_xp::OptionsPtr __fastcall get_Options(void)
  {
    return GetDefaultInterface()->get_Options();
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

  LPUNKNOWN __fastcall PPFileDialog(Powerpoint_xp::PpFileDialogType Type/*[in]*/)
  {
    return GetDefaultInterface()->PPFileDialog(Type/*[in]*/);
  }

  void __fastcall Activate(void)
  {
    GetDefaultInterface()->Activate();
  }

  TOLEBOOL __fastcall GetOptionFlag(long Option/*[in]*/, VARIANT_BOOL Persist/*[in,def,opt]*/)
  {
    return GetDefaultInterface()->GetOptionFlag(Option/*[in]*/, Persist/*[in,def,opt]*/);
  }

  void __fastcall SetOptionFlag(long Option/*[in]*/, VARIANT_BOOL State/*[in]*/, 
                                VARIANT_BOOL Persist/*[in,def,opt]*/)
  {
    GetDefaultInterface()->SetOptionFlag(Option/*[in]*/, State/*[in]*/, Persist/*[in,def,opt]*/);
  }

  void __fastcall SetPerfMarker(int Marker/*[in]*/)
  {
    GetDefaultInterface()->SetPerfMarker(Marker/*[in]*/);
  }

  /*CoClassWriteProperties*/
  __property Powerpoint_xp::PresentationsPtr Presentations={ read=get_Presentations }; // 0, Yes
  __property Powerpoint_xp::DocumentWindowsPtr Windows={ read=get_Windows }; // 0, Yes
  __property LPUNKNOWN Dialogs={ read=get_Dialogs }; // 0, No
  __property Powerpoint_xp::DocumentWindowPtr ActiveWindow={ read=get_ActiveWindow }; // 0, Yes
  __property Powerpoint_xp::PowerPointPresentationPtr ActivePresentation={ read=get_ActivePresentation }; // 0, Yes
  __property Powerpoint_xp::SlideShowWindowsPtr SlideShowWindows={ read=get_SlideShowWindows }; // 0, Yes
  __property Office_xp::CommandBarsPtr CommandBars={ read=get_CommandBars }; // 0, Yes
  __property BSTR Path={ read=get_Path }; // 0, No
  __property BSTR Name={ read=get_Name }; // 0, No
  __property Office_xp::AssistantPtr Assistant={ read=get_Assistant }; // 0, Yes
  __property Office_xp::FileSearchPtr FileSearch={ read=get_FileSearch }; // 0, Yes
  __property Office_xp::IFindPtr FileFind={ read=get_FileFind }; // 0, Yes
  __property BSTR Build={ read=get_Build }; // 0, No
  __property BSTR Version={ read=get_Version }; // 0, No
  __property BSTR OperatingSystem={ read=get_OperatingSystem }; // 0, No
  __property BSTR ActivePrinter={ read=get_ActivePrinter }; // 0, No
  __property long Creator={ read=get_Creator }; // 0, No
  __property Powerpoint_xp::AddInsPtr AddIns={ read=get_AddIns }; // 0, Yes
  __property Vbide_xp::VBEPtr VBE={ read=get_VBE }; // 0, Yes
  __property Office_xp::MsoTriState Active={ read=get_Active }; // 0, No
  __property Office_xp::AnswerWizardPtr AnswerWizard={ read=get_AnswerWizard }; // 0, Yes
  __property Office_xp::COMAddInsPtr COMAddIns={ read=get_COMAddIns }; // 0, Yes
  __property BSTR ProductCode={ read=get_ProductCode }; // 0, No
  __property Powerpoint_xp::DefaultWebOptionsPtr DefaultWebOptions={ read=get_DefaultWebOptions }; // 0, Yes
  __property Office_xp::LanguageSettingsPtr LanguageSettings={ read=get_LanguageSettings }; // 0, Yes
  __property Office_xp::MsoDebugOptionsPtr MsoDebugOptions={ read=get_MsoDebugOptions }; // 0, Yes
  __property LPUNKNOWN Marker={ read=get_Marker }; // 0, No
  __property Office_xp::FileDialogPtr FileDialog[Office_xp::MsoFileDialogType Type]={ read=get_FileDialog }; // 0, Yes
  __property Office_xp::NewFilePtr NewPresentation={ read=get_NewPresentation }; // 0, Yes
  __property Powerpoint_xp::AutoCorrectPtr AutoCorrect={ read=get_AutoCorrect }; // 0, Yes
  __property Powerpoint_xp::OptionsPtr Options={ read=get_Options }; // 0, Yes
  /*CoClassWriteProperties*/
  __property BSTR Caption={ read=get_Caption, stored=false }; // 0, No
  __property float Left={ read=get_Left, stored=false }; // 0, No
  __property float Top={ read=get_Top, stored=false }; // 0, No
  __property float Width={ read=get_Width, stored=false }; // 0, No
  __property float Height={ read=get_Height, stored=false }; // 0, No
  __property Powerpoint_xp::PpWindowState WindowState={ read=get_WindowState, stored=false }; // 0, No
  __property Office_xp::MsoTriState Visible={ read=get_Visible, stored=false }; // 0, No
  __property Office_xp::MsoTriState ShowWindowsInTaskbar={ read=get_ShowWindowsInTaskbar, stored=false }; // 0, No
  __property Office_xp::MsoFeatureInstall FeatureInstall={ read=get_FeatureInstall, stored=false }; // 0, No
  __property Office_xp::MsoTriState DisplayGridLines={ read=get_DisplayGridLines, stored=false }; // 0, No
  __property Office_xp::MsoAutomationSecurity AutomationSecurity={ read=get_AutomationSecurity, stored=false }; // 0, No
  __property Powerpoint_xp::PpAlertLevel DisplayAlerts={ read=get_DisplayAlerts, stored=false }; // 0, No
  __property Office_xp::MsoTriState ShowStartupDialog={ read=get_ShowStartupDialog, stored=false }; // 0, No
  /*CoClassWriteEventDecls*/
private:
  TPowerPointApplicationWindowSelectionChange FOnWindowSelectionChange;
  TPowerPointApplicationWindowBeforeRightClick FOnWindowBeforeRightClick;
  TPowerPointApplicationWindowBeforeDoubleClick FOnWindowBeforeDoubleClick;
  TPowerPointApplicationPresentationClose FOnPresentationClose;
  TPowerPointApplicationPresentationSave FOnPresentationSave;
  TPowerPointApplicationPresentationOpen FOnPresentationOpen;
  TPowerPointApplicationNewPresentation FOnNewPresentation;
  TPowerPointApplicationPresentationNewSlide FOnPresentationNewSlide;
  TPowerPointApplicationWindowActivate FOnWindowActivate;
  TPowerPointApplicationWindowDeactivate FOnWindowDeactivate;
  TPowerPointApplicationSlideShowBegin FOnSlideShowBegin;
  TPowerPointApplicationSlideShowNextBuild FOnSlideShowNextBuild;
  TPowerPointApplicationSlideShowNextSlide FOnSlideShowNextSlide;
  TPowerPointApplicationSlideShowEnd FOnSlideShowEnd;
  TPowerPointApplicationPresentationPrint FOnPresentationPrint;
  TPowerPointApplicationSlideSelectionChanged FOnSlideSelectionChanged;
  TPowerPointApplicationColorSchemeChanged FOnColorSchemeChanged;
  TPowerPointApplicationPresentationBeforeSave FOnPresentationBeforeSave;
  TPowerPointApplicationSlideShowNextClick FOnSlideShowNextClick;
__published:
  __property TPowerPointApplicationWindowSelectionChange OnWindowSelectionChange={ read=FOnWindowSelectionChange, write=FOnWindowSelectionChange };
  __property TPowerPointApplicationWindowBeforeRightClick OnWindowBeforeRightClick={ read=FOnWindowBeforeRightClick, write=FOnWindowBeforeRightClick };
  __property TPowerPointApplicationWindowBeforeDoubleClick OnWindowBeforeDoubleClick={ read=FOnWindowBeforeDoubleClick, write=FOnWindowBeforeDoubleClick };
  __property TPowerPointApplicationPresentationClose OnPresentationClose={ read=FOnPresentationClose, write=FOnPresentationClose };
  __property TPowerPointApplicationPresentationSave OnPresentationSave={ read=FOnPresentationSave, write=FOnPresentationSave };
  __property TPowerPointApplicationPresentationOpen OnPresentationOpen={ read=FOnPresentationOpen, write=FOnPresentationOpen };
  __property TPowerPointApplicationNewPresentation OnNewPresentation={ read=FOnNewPresentation, write=FOnNewPresentation };
  __property TPowerPointApplicationPresentationNewSlide OnPresentationNewSlide={ read=FOnPresentationNewSlide, write=FOnPresentationNewSlide };
  __property TPowerPointApplicationWindowActivate OnWindowActivate={ read=FOnWindowActivate, write=FOnWindowActivate };
  __property TPowerPointApplicationWindowDeactivate OnWindowDeactivate={ read=FOnWindowDeactivate, write=FOnWindowDeactivate };
  __property TPowerPointApplicationSlideShowBegin OnSlideShowBegin={ read=FOnSlideShowBegin, write=FOnSlideShowBegin };
  __property TPowerPointApplicationSlideShowNextBuild OnSlideShowNextBuild={ read=FOnSlideShowNextBuild, write=FOnSlideShowNextBuild };
  __property TPowerPointApplicationSlideShowNextSlide OnSlideShowNextSlide={ read=FOnSlideShowNextSlide, write=FOnSlideShowNextSlide };
  __property TPowerPointApplicationSlideShowEnd OnSlideShowEnd={ read=FOnSlideShowEnd, write=FOnSlideShowEnd };
  __property TPowerPointApplicationPresentationPrint OnPresentationPrint={ read=FOnPresentationPrint, write=FOnPresentationPrint };
  __property TPowerPointApplicationSlideSelectionChanged OnSlideSelectionChanged={ read=FOnSlideSelectionChanged, write=FOnSlideSelectionChanged };
  __property TPowerPointApplicationColorSchemeChanged OnColorSchemeChanged={ read=FOnColorSchemeChanged, write=FOnColorSchemeChanged };
  __property TPowerPointApplicationPresentationBeforeSave OnPresentationBeforeSave={ read=FOnPresentationBeforeSave, write=FOnPresentationBeforeSave };
  __property TPowerPointApplicationSlideShowNextClick OnSlideShowNextClick={ read=FOnSlideShowNextClick, write=FOnSlideShowNextClick };
private:
  bool     FAutoQuit;
__published:
  __property bool AutoQuit = {read=FAutoQuit, write=FAutoQuit};
};

};     // namespace Powerpoint_xp

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Powerpoint_xp;
#endif

#pragma option pop

#endif // PowerPoint_XP_srvrH
