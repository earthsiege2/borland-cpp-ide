//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1996 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(OWL_DIALOG_H)
# include <owl/dialog.h>
#endif
#if !defined(OWL_FRAMEWIN_H)
# include <owl/framewin.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#include <string.h>               // For strcpy and strcat
#include <stdlib.h>               // For atoi
#include <ctype.h>                // For isdigit and isalpha
#include "validate.rc"               

#define MAXNAMELEN     35
#define MAXSSLEN       12
#define MAXIDLEN       4
#define MAXDEPTLEN     7
#define MAXSECLEN      3
#define MAXCUSTOMLEN   20

struct TEmployeeStruct {
  char NameEdit[MAXNAMELEN];
  char SSEdit[MAXSSLEN];
  char IDEdit[MAXIDLEN];
  char DeptEdit[MAXDEPTLEN];
  char SecEdit[MAXSECLEN];
  bool FullTime;
  bool Perm;
  bool Exempt;
  char CustomEdit[MAXCUSTOMLEN];
};

//
// class TEmployeeDlg
// ~~~~~ ~~~~~~~~~~~~
class TEmployeeDlg : public TDialog {
  public:
    TEmployeeDlg(TWindow* parent, TResId resId, TEmployeeStruct& transfer);

  private:
    void    CmSetCustom();
    TEdit*  CustomEdit;

  DECLARE_RESPONSE_TABLE(TEmployeeDlg);
};


DEFINE_RESPONSE_TABLE1(TEmployeeDlg, TDialog)
  EV_COMMAND(IDC_CUSTOM, CmSetCustom),
END_RESPONSE_TABLE;


//
//
//
TEmployeeDlg::TEmployeeDlg(TWindow* parent, TResId resid,
  TEmployeeStruct& transfer)
:
  TDialog(parent, resid)
{
  TEdit* edit;
  edit = new TEdit(this, IDC_NAME, sizeof(transfer.NameEdit));
  edit->SetValidator(new TFilterValidator("A-Za-z. "));
  edit = new TEdit(this, IDC_SS, sizeof(transfer.SSEdit));
  edit->SetValidator(new TPXPictureValidator("###-##-####"));
  edit = new TEdit(this, IDC_EMPID, sizeof(transfer.IDEdit));
  edit->SetValidator(new TRangeValidator(1, 999));
  edit = new TEdit(this, IDC_DEPT, sizeof(transfer.DeptEdit));
  edit->SetValidator(new TPXPictureValidator("Sales,Dev,Mfg"));
  edit = new TEdit(this, IDC_SECURITY, sizeof(transfer.SecEdit));
  edit->SetValidator(new TPXPictureValidator("11,12,13,14,15"));
  new TCheckBox(this, IDC_FTIME, 0);
  new TCheckBox(this, IDC_PERMANENT, 0);
  new TCheckBox(this, IDC_EXEMPT, 0);
  CustomEdit = new TEdit(this, IDC_EDIT2, sizeof(transfer.CustomEdit));
  TValidator* v = new TPXPictureValidator("------", true);
  v->UnsetOption(voOnAppend);
  CustomEdit->SetValidator(v);

  TransferBuffer = (void far*)&transfer;
}

void
TEmployeeDlg::CmSetCustom()
{
  char buff[40];
  GetDlgItemText(IDC_EDIT1, buff, sizeof(buff));
  TValidator* v = new TPXPictureValidator(buff, true);
  v->UnsetOption(voOnAppend);
  CustomEdit->SetValidator(v);
  CustomEdit->SetFocus();
}


//
// class TTestWindow
// ~~~~~ ~~~~~~~~~~~
class TTestWindow : public TWindow {
  public:
    TTestWindow(TWindow* parent = 0);
    void CmEmpInput();

  private:
    TEmployeeStruct EmployeeStruct;

  DECLARE_RESPONSE_TABLE(TTestWindow);
};

DEFINE_RESPONSE_TABLE1(TTestWindow, TWindow)
  EV_COMMAND(CM_EMPINPUT, CmEmpInput),
END_RESPONSE_TABLE;


//
//
//
TTestWindow::TTestWindow(TWindow* parent)
:
  TWindow(parent)
{
  memset(&EmployeeStruct, 0, sizeof EmployeeStruct);
}

void
TTestWindow::CmEmpInput()
{
  char empInfo[sizeof(TEmployeeStruct)+ 10 + 11 + 11];

  if (TEmployeeDlg(this, IDD_EMPLOYEEINFO, EmployeeStruct).Execute() == IDOK) {
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

//
// class TValidateApp
// ~~~~~ ~~~~~~~~~~~~
class TValidateApp : public TApplication {
  public:
    TValidateApp() : TApplication("ValidateApp") {}
    void InitMainWindow() {
      EnableCtl3d();
      TFrameWindow* frame = new TFrameWindow(0, "Validate Dialog Input",
        new TTestWindow);
      frame->AssignMenu(200);
      SetMainWindow(frame);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TValidateApp().Run();
}
