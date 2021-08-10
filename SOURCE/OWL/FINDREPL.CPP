//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of FindReplace- abstract, Find-, Replace- common Dialog
//   classes
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/findrepl.h>
#if !defined(ctlFirst)
# include <dlgs.h>
#endif

#if !defined(SECTION) || SECTION == 1

TFindReplaceDialog::TData::TData(uint32 flags, int buffSize)
:
  Flags(flags), BuffSize(buffSize), Error(0)
{
  FindWhat = new char[BuffSize];
  ReplaceWith = new char[BuffSize];
  *FindWhat = *ReplaceWith = 0;
}

TFindReplaceDialog::TData::TData(const TData& src)
:
  Flags(src.Flags),
  BuffSize(src.BuffSize),
  Error(0)
{
  FindWhat = strnewdup(src.FindWhat, BuffSize);
  ReplaceWith = strnewdup(src.ReplaceWith, BuffSize);
}


TFindReplaceDialog::TData::~TData()
{
  delete [] FindWhat;
  delete [] ReplaceWith;
}

TFindReplaceDialog::TData&
TFindReplaceDialog::TData::operator =(const TData& src)
{
  Flags = src.Flags;
  BuffSize = src.BuffSize;
  Error = 0;

  delete [] FindWhat;
  FindWhat = strnewdup(src.FindWhat, BuffSize);

  delete [] ReplaceWith;
  ReplaceWith = strnewdup(src.ReplaceWith, BuffSize);

  return *this;
}


//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TFindReplaceDialog, TCommonDialog)
  EV_WM_NCDESTROY,
END_RESPONSE_TABLE;

IMPLEMENT_CASTABLE(TFindReplaceDialog);

void
TFindReplaceDialog::Init(TResId templateId)
{
  memset(&fr, 0, sizeof(FINDREPLACE));
  fr.lStructSize = sizeof(FINDREPLACE);
  fr.hwndOwner = Parent ? Parent->HWindow : 0;
  fr.hInstance = *GetModule();
  Data.Flags &= ~(FR_FINDNEXT|FR_REPLACE|FR_REPLACEALL|FR_DIALOGTERM);
  fr.Flags = FR_ENABLEHOOK | Data.Flags;
  if (templateId) {
    fr.lpTemplateName = templateId;
    fr.Flags |= FR_ENABLETEMPLATE;
  }
  else
    fr.Flags &= ~FR_ENABLETEMPLATE;

  fr.lpstrFindWhat = Data.FindWhat;
  fr.wFindWhatLen = (uint16)Data.BuffSize;
  fr.lpstrReplaceWith = Data.ReplaceWith;
  fr.wReplaceWithLen = (uint16)Data.BuffSize;
}

TFindReplaceDialog::TFindReplaceDialog(TWindow*        parent,
                                       TData&          data,
                                       TResId          templateId,
                                       const char far* title,
                                       TModule*        module)
:
  TCommonDialog(parent, title, module),
  Data(data)
{
  Init(templateId);
}

HWND
TFindReplaceDialog::DoCreate()
{
  return 0;
}

bool
TFindReplaceDialog::DialogFunction(uint msg, WPARAM wParam, LPARAM lParam)
{
  return TCommonDialog::DialogFunction(msg, wParam, lParam);
}

//
// Make sure flags get copied over before we go
//
void
TFindReplaceDialog::EvNCDestroy()
{
  Data.Flags = fr.Flags;
  TWindow::EvNCDestroy();
}

void
TFindReplaceDialog::UpdateData(LPARAM lParam)
{
  if (lParam)
    Data.Flags = ((LPFINDREPLACE)lParam)->Flags;
  else
    Data.Flags = fr.Flags;
}

//----------------------------------------------------------------------------

IMPLEMENT_CASTABLE(TFindDialog);

TFindDialog::TFindDialog(TWindow*        parent,
                         TData&          data,
                         TResId          templateId,
                         const char far* title,
                         TModule*        module)
  : TFindReplaceDialog(parent, data, templateId, title, module)
{
}

HWND
TFindDialog::DoCreate()
{
  (DLGPROC)fr.lpfnHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  return ::FindText(&fr);
}

//----------------------------------------------------------------------------

IMPLEMENT_CASTABLE(TReplaceDialog);

TReplaceDialog::TReplaceDialog(TWindow*        parent,
                               TData&          data,
                               TResId          templateId,
                               const char far* title,
                               TModule*        module)
  : TFindReplaceDialog(parent, data, templateId, title, module)
{
}

HWND
TReplaceDialog::DoCreate()
{
  (DLGPROC)fr.lpfnHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  return ::ReplaceText(&fr);
}

#endif
#if !defined(SECTION) || SECTION == 2
//Keep streaming out if not used

void
TFindReplaceDialog::TData::Read(ipstream& is)
{
  is >> Flags;
  is >> BuffSize;
  FindWhat = new char[BuffSize];
  ReplaceWith = new char[BuffSize];
  is.readBytes(FindWhat, BuffSize);
  is.readBytes(ReplaceWith, BuffSize);
}

void
TFindReplaceDialog::TData::Write(opstream& os)
{
  os << Flags;
  os << BuffSize;
  os.writeBytes(FindWhat, BuffSize);
  os.writeBytes(ReplaceWith, BuffSize);
}

#endif
