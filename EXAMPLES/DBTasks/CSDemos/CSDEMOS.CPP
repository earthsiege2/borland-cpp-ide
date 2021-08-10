//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//  CSDEMOS
//  Interbase Client Example
//
//  To run this app you need to create a BDE alias as follows,
//
//    1. Be sure Interbase Server and SQL Links are installed
//    2. Run the BDE Configuration utility, BDEADMIN.EXE
//    3. Create a new Alias by the name 'IBLOCAL' of type INTRBASE
//    4. Set the Server Name to <Interbase path>\EXAMPLES\EMPLOYEE.GDB
//
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <Db.hpp>
//---------------------------------------------------------------------------
USEFILE("readme.txt");
USEDATAMODULE("DMCSDEMO.CPP", DmEmployee);
USEFORM("FRMEXESP.CPP", FrmExecProc);
USEFORM("FRMMAIN.CPP", FrmLauncher);
USEFORM("FRMQRYSP.CPP", FrmQueryProc);
USEFORM("FRMTRANS.CPP", FrmTransDemo);
USEFORM("FRMTRIGG.CPP", FrmTriggerDemo);
USEFORM("FRMVIEWS.CPP", FrmViewDemo);
USERES("csdemos.res");
//---------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
    Application->Initialize();
    Application->CreateForm(__classid(TFrmLauncher), &FrmLauncher);
    Application->CreateForm(__classid(TFrmExecProc), &FrmExecProc);
    Application->CreateForm(__classid(TFrmQueryProc), &FrmQueryProc);
    Application->CreateForm(__classid(TFrmTransDemo), &FrmTransDemo);
    Application->CreateForm(__classid(TFrmTriggerDemo), &FrmTriggerDemo);
    Application->CreateForm(__classid(TFrmViewDemo), &FrmViewDemo);
    Application->CreateForm(__classid(TDmEmployee), &DmEmployee);
    Application->Run();
  }
  catch(EDatabaseError& e)
  {
    String buf =
           e.Message
           + "\n\n"
           +"1. Be sure Interbase Server and SQL Links are installed.\n"
           +"2. Run the BDE Configuration utility, BDEADMIN.EXE.\n"
           +"3. Create a new Alias by the name 'IBLOCAL' of type INTRBASE.\n"
           +"4. Set the Server Name to <Interbase path>\\EXAMPLES\\EMPLOYEE.GDB.\n";

    ShowMessage(buf);
  }
  catch(Exception& e)
  {
    ShowMessage(e.Message);
  }
    return 0;
}
//---------------------------------------------------------------------------
