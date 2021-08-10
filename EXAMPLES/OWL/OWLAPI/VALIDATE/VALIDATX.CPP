//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\dialog.h>
#include <owl\framewin.h>
#include <owl\edit.h>
#include <owl\checkbox.h>
#include <owl\validate.h>
#include <string.h>  // for strcpy and strcat
#include <stdlib.h>  // for atoi
#include <ctype.h>   // for isdigit and isalpha


#define CM_EMPINPUT 201

#define MAXNAMELEN  35
#define MAXSSLEN    12
#define MAXIDLEN    4
#define MAXDEPTLEN  7
#define MAXSECLEN   3

struct TEmployeeStruct {
  char NameEdit[MAXNAMELEN];
  char SSEdit[MAXSSLEN];
  char IDEdit[MAXIDLEN];
  char DeptEdit[MAXDEPTLEN];
  char SecEdit[MAXSECLEN];
  BOOL FullTime;
  BOOL Perm;
  BOOL Exempt;
};

//----------------------------------------------------------------------------

class TEmployeeDlg : public TDialog {
  public:
    TEmployeeDlg(TWindow* parent, const char* name, TEmployeeStruct& transfer);
};

TEmployeeDlg::TEmployeeDlg(TWindow* parent, const char* name, TEmployeeStruct& transfer)
  : TDialog(parent, name),
    TWindow(parent)
{
  TEdit* edit;
  edit = new TEdit(this, 101, sizeof(transfer.NameEdit));
  edit->SetValidator(new TFilterValidator("A-Za-z. "));
  edit = new TEdit(this, 102, sizeof(transfer.SSEdit));
  edit->SetValidator(new TPXPictureValidator("###-##-####"));
  edit = new TEdit(this, 103, sizeof(transfer.IDEdit));
  edit->SetValidator(new TRangeValidator(1, 999));
  edit = new TEdit(this, 104, sizeof(transfer.DeptEdit));
  edit->SetValidator(new TPXPictureValidator("Sales,Dev,Mfg"));
  edit = new TEdit(this, 105, sizeof(transfer.SecEdit));
  edit->SetValidator(new TPXPictureValidator("11,12,13,14,15"));
  new TCheckBox(this, 106, 0);
  new TCheckBox(this, 107, 0);
  new TCheckBox(this, 108, 0);

  TransferBuffer = (void far*)&transfer;
}

//----------------------------------------------------------------------------

class TTestWindow : public TFrameWindow {
  public:
    TTestWindow(TWindow* parent, const char* title);
    void CmEmpInput();

  private:
    TEmployeeStruct EmployeeStruct;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TFrameWindow)
  EV_COMMAND(CM_EMPINPUT, CmEmpInput),
END_RESPONSE_TABLE;


TTestWindow::TTestWindow(TWindow* parent, const char* title)
  : TFrameWindow(parent, title),
    TWindow(parent, title)
{
  AssignMenu(200);
  memset(&EmployeeStruct, 0, sizeof EmployeeStruct);
}

void
TTestWindow::CmEmpInput()
{
  char empInfo[sizeof(TEmployeeStruct)+5+1];

  if (TEmployeeDlg(this,"EMPLOYEEINFO", EmployeeStruct).Execute() == IDOK) {
    strcpy(empInfo, EmployeeStruct.NameEdit);
    strcat(empInfo, "\n");
    strcat(empInfo, EmployeeStruct.SSEdit);
    strcat(empInfo, "\n");
    strcat(empInfo, EmployeeStruct.IDEdit);
    strcat(empInfo, "\n");
    strcat(empInfo, EmployeeStruct.DeptEdit);
    strcat(empInfo, "\n");
    strcat(empInfo, EmployeeStruct.SecEdit);
    strcat(empInfo, "\n");
    strcat(empInfo, EmployeeStruct.FullTime ? "FullTime " : "PartTime ");
    strcat(empInfo, EmployeeStruct.Perm ? "Permanent " : "Temporary ");
    strcat(empInfo, EmployeeStruct.Exempt ? "Exempt " : "NonExempt ");
    MessageBox(empInfo, "Information Stored", MB_OK);
  }
}

//----------------------------------------------------------------------------

class TValidateApp : public TApplication {
  public:
    TValidateApp() : TApplication("ValidateApp") {}
    void InitMainWindow() {
      EnableCtl3d();
      MainWindow = new TTestWindow(0, "Validate Dialog Input");
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TValidateApp().Run();
}
