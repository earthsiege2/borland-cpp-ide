//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management: ShareMem must be the
//   first include file in your library and in your project (select:
//   View / Project Source) if your DLL exports any functions that pass
//   String objects as parameters or function results. This applies to all
//   String objects passed to and from your DLL--even those that
//   are nested in records and classes. ShareMem is the interface unit to
//   the DELPHIMM.DLL shared memory manager, which must be deployed along
//   with your DLL. To avoid using DELPHIMM.DLL, pass string information
//   using PChar or ShortString parameters.
//---------------------------------------------------------------------------
USERES("exptdemo.res");
USEFORM("dlg.cpp", DlgExpert);
USEFORM("app.cpp", AppExpert);
USEFORM("filters.cpp", FilterDlg);
//---------------------------------------------------------------------
#include <ShareMem.hpp>
#include <Forms.hpp>
#include <Windows.hpp>
#include <ExptIntf.hpp>
#include <ToolIntf.hpp>
#include <VirtIntf.hpp>
#include <SysUtils.hpp>
#include "Dlg.h"           // dialogbox expert
#include "Exconst.h"       // external constants
#include "App.h"           // application expert

#pragma resource "*.RES"

String       s;             // utilty String object
TExpertState tx;

/////////////////////////////////////////// TDialogExpert ///////
class TDialogExpert: public TIExpert {
  public:
    String __stdcall GetName(void);
    String __stdcall GetComment(void);
    HICON __stdcall GetGlyph(void);
    TExpertStyle __stdcall GetStyle(void);
    TExpertState __stdcall GetState(void);
    String __stdcall GetIDString(void);
    String __stdcall GetAuthor(void);
    String __stdcall GetPage(void);
    String __stdcall GetMenuText(void) { return NULL; }
    void __stdcall Execute(void);

    // This is required to realize the linkage; without it we
    // don't get a virtual table. This has something to do with
    // the implicit derivation of TIExpert from VCL's TObject. 
    TDialogExpert(void) {}
};

/////////////////////////////////////////// TApplicationExpert //
class TApplicationExpert: public TIExpert {
  public:
    String __stdcall GetName(void);
    String __stdcall GetComment(void);
    HICON __stdcall GetGlyph(void);
    TExpertStyle __stdcall GetStyle(void);
    TExpertState __stdcall GetState(void);
    String __stdcall GetIDString(void);
    String __stdcall GetAuthor(void);
    String __stdcall GetPage(void);
    String __stdcall GetMenuText(void) { return NULL; }
    void __stdcall Execute(void);

    // This is required to realize the linkage; without it we
    // don't get a virtual table
    TApplicationExpert(void) {}
};

//---------------------------------------------------------------
void HandleException(void)
{
  ToolServices->RaiseException(ReleaseException());
} // end of HandleException()

//========================================= TDialogExpert =======
String __stdcall TDialogExpert::GetName(void)
{
  try
  {
    s = LoadStr(sDlgExpertName);
  } catch(...)
  {
    HandleException();
  }
  return s;
} // end of TDialogExpert::GetName()

//========================================= TDialogExpert =======
String __stdcall TDialogExpert::GetComment(void)
{
  try
  {
    s = LoadStr(sDlgExpertDesc);
  } catch(...)
  {
    HandleException();
  }
  return s;
} // end of TDialogExpert::GetComment()

//========================================= TDialogExpert =======
HICON __stdcall TDialogExpert::GetGlyph(void)
{
  HICON icon;
  try
  {
    icon = LoadIcon((void*)HInstance, "DLGEXPT");
  } catch(...)
  {
    HandleException();
  }
  return icon;
} // end of TDialogExpert::GetGlyph()

//========================================= TDialogExpert =======
TExpertStyle __stdcall TDialogExpert::GetStyle(void)
{
  return esForm;
} // end of TDialogExpert::GetStyle()

//========================================= TDialogExpert =======
TExpertState __stdcall TDialogExpert::GetState(void)
{
  tx << esEnabled;
  return tx;
} // end of TDialogExpert::GetState()

//========================================= TDialogExpert =======
String __stdcall TDialogExpert::GetIDString(void)
{
  return "Borland.DlgExpertDemo";
} // end of TDialogExpert::GetIDString()

//========================================= TDialogExpert =======
String __stdcall TDialogExpert::GetAuthor(void)
{
  return "Borland";
} // end of TDialogExpert::GetAuthor()

//========================================= TDialogExpert =======
String __stdcall TDialogExpert::GetPage(void)
{
  try
  {
    s = LoadStr(sDialogsPage);
  } catch(...)
  {
    HandleException();
  }
  return s;
} // end of TDialogExpert::GetPage()

//========================================= TDialogExpert =======
void __stdcall TDialogExpert::Execute(void)
{
  try
  {
    DialogExpert(ToolServices);
  } catch(...)
  {
    HandleException();
  }
} // end of TDialogExpert::Execute()

//========================================= TApplicationExpert ==
String __stdcall TApplicationExpert::GetName(void)
{
  try
  {
    s = LoadStr(sAppExpertName);
  } catch(...)
  {
    HandleException();
  }
  return s;
} // end of TApplicationExpert::GetName()

//========================================= TApplicationExpert ==
String __stdcall TApplicationExpert::GetComment(void)
{
  try
  {
    s = LoadStr(sAppExpertDesc);
  } catch(...)
  {
    HandleException();
  }
  return s;
} // end of TApplicationExpert::GetComment()

//========================================= TApplicationExpert ==
HICON __stdcall TApplicationExpert::GetGlyph(void)
{
  HICON glyph;
  try
  {
    glyph = LoadIcon((void*)HInstance, "APPEXPT");
  } catch(...)
  {
    HandleException();
  }
  return glyph;
} // end of TApplicationExpert::GetGlyph()

//========================================= TApplicationExpert ==
TExpertStyle __stdcall TApplicationExpert::GetStyle(void)
{
  return esProject;
} // end of TApplicationExpert::GetStyle()

//========================================= TApplicationExpert ==
TExpertState __stdcall TApplicationExpert::GetState(void)
{
  tx << esEnabled;
  return tx;
} // end of TApplicationExpert::GetState()

//========================================= TApplicationExpert ==
String __stdcall TApplicationExpert::GetIDString(void)
{
  return "Borland.AppExpertDemo";
} // end of TApplicationExpert::GetIDString()

//========================================= TApplicationExpert ==
String __stdcall TApplicationExpert::GetAuthor(void)
{
  return "Borland";
} // end of TApplicationExpert::GetAuthor()

//========================================= TApplicationExpert ==
String __stdcall TApplicationExpert::GetPage(void)
{
  try
  {
    s = LoadStr(sProjectsPage);
  } catch(...)
  {
    HandleException();
  }
  return s;
} // end of TApplicationExpert::GetPage()

//========================================= TApplicationExpert ==
void __stdcall TApplicationExpert::Execute(void)
{
  try
  {
//    ApplicationExpert(ToolServices);
  } catch(...)
  {
    HandleException();
  }
} // end of TApplicationExpert::Execute()

//---------------------------------------------------------------
void __fastcall DoneExpert(void)
{
  // Put any general destruction code here.  Note that the
  // IDE will destroy any experts which have been registered.
}
typedef void __fastcall (*termproc)(void);
termproc tp = DoneExpert;

//---------------------------------------------------------------
bool _stdcall InitExpert(TIToolServices* ToolServices,
                         TExpertRegisterProc *RegisterProc,
                         TExpertTerminateProc *Terminate)
{
  // make sure we"re the first and only instance
  int Result = Exptintf::ToolServices == NULL;
  if (!Result) return false;

  Exptintf::ToolServices = ToolServices;
  if (ToolServices != NULL)
    Application->Handle = ToolServices->GetParentHandle();

  Terminate = &tp;

  // register the experts
  (*RegisterProc)(new TDialogExpert);
  (*RegisterProc)(new TApplicationExpert);
  return true;
} // end of InitExpert()

//***************************************************************
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  return 1;
}
//---------------------------------------------------------------
