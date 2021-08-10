//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999-2002 Borland Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and any
//   EXE projects that use the DLL.  This will change the DLL and its calling
//   EXE's to use the MEMMGR.DLL as their memory manager.  In these cases,
//   the file MEMMGR.DLL should be deployed along with your DLL.
//
//   To avoid using MEMMGR.DLL, pass string information using "char *" or
//   ShortString parameters.
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USERES("experts.res");
USEFORM("filters.cpp", FilterDlg);
USEFORM("dlg.cpp", DlgExpert);
USEFORM("app.cpp", AppExpert);
USERC("exptbmps.rc");
USERC("strings.rc");
USELIB("Memmgr.lib");
//---------------------------------------------------------------------------
#include <ShareMem.hpp>
#include <Forms.hpp>
#include <Windows.hpp>
#include <ExptIntf.hpp>
#include <ToolIntf.hpp>
#include <VirtIntf.hpp>
#include <SysUtils.hpp>

#include "Exconst.h"       // external constants
#include "Dlg.h"           // dialogbox expert
#include "App.h"           // application expert

#pragma resource "*.RES"

String       s;             // utilty String object
String       *ss;
TExpertState tx;
HINSTANCE    instance;

/////////////////////////////////////////// TDialogExpert ///////
class __declspec(delphiclass) TDialogExpert;
class TDialogExpert: public TIExpert {
     typedef TIExpert inherited;
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
    __fastcall TDialogExpert(void) {}
    __fastcall ~TDialogExpert(void) {}
};

/////////////////////////////////////////// TApplicationExpert //
class __declspec(delphiclass) TApplicationExpert;
class TApplicationExpert: public TIExpert {
     typedef TIExpert inherited;
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
    __fastcall TApplicationExpert(void) {}
    __fastcall ~TApplicationExpert(void) {}
};

String Author("Borland");
String DlgID("Borland.DlgExpertDemo");
String AppID("Borland.AppExpertDemo");

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
    icon = LoadIcon(HInstance, "DLGEXPT");
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
  return DlgID;
} // end of TDialogExpert::GetIDString()

//========================================= TDialogExpert =======
String __stdcall TDialogExpert::GetAuthor(void)
{
  return Author;
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
    glyph = LoadIcon(HInstance, "APPEXPT");
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
  return AppID;
} // end of TApplicationExpert::GetIDString()

//========================================= TApplicationExpert ==
String __stdcall TApplicationExpert::GetAuthor(void)
{
  return Author;
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
    ApplicationExpert(ToolServices);
  } catch(...)
  {
    HandleException();
  }
} // end of TApplicationExpert::Execute()

//---------------------------------------------------------------
extern "C" __declspec(dllexport) void __fastcall DoneExpert(void)
{
  // Put any general destruction code here.  Note that the
  // IDE will destroy any experts which have been registered.
}

//---------------------------------------------------------------
extern "C" __declspec(dllexport) bool _stdcall INITEXPERT0017(TIToolServices* ToolServices,
                                               TExpertRegisterProc RegisterProc,
                                               TExpertTerminateProc &Terminate)
{
  // make sure we"re the first and only instance
  int Result = Exptintf::ToolServices == NULL;
  if (!Result) return false;

  Exptintf::ToolServices = ToolServices;
  if (ToolServices != NULL)
    Application->Handle = ToolServices->GetParentHandle();
  else
    return false;

  Terminate = DoneExpert;

  // register the experts
  TDialogExpert *de = new TDialogExpert;
  TApplicationExpert *ae = new TApplicationExpert;
  (*RegisterProc)(de);
  (*RegisterProc)(ae);

  return true;
} // end of InitExpert()

//***************************************************************
extern "C" __declspec(dllexport) int WINAPI DllEntryPoint(HINSTANCE hinst,
                                               unsigned long reason,
                                               void*)
{
  instance = hinst;
  return 1;
}
//---------------------------------------------------------------


