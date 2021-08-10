//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of OpenSave abstract, FileOpen, FileSave Common Dialog
//   classes
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/opensave.h>
#include <dir.h>

#if !defined(SECTION) || SECTION == 1

TOpenSaveDialog::TData::TData(uint32      flags,
                              const char* filter,
                              char*       customFilter,
                              char*       initialDir,
                              char*       defExt,
                              int         maxPath)
:
  Flags(flags), Error(0), FileName(0), Filter(0),
  CustomFilter(customFilter), FilterIndex(0),
  InitialDir(initialDir), DefExt(defExt),
  MaxPath(maxPath ? maxPath : MAXPATH)
{
  FileName = new char[MaxPath];
  *FileName = 0;
  SetFilter(filter);
}

TOpenSaveDialog::TData::TData(const TData& src)
:
  Flags(src.Flags), Error(0), FileName(0), Filter(0),
  CustomFilter(src.CustomFilter), FilterIndex(src.FilterIndex),
  InitialDir(src.InitialDir), DefExt(src.DefExt),
  MaxPath(src.MaxPath)
{
  FileName = strnewdup(src.FileName, MaxPath);
  SetFilter(src.Filter);
}

TOpenSaveDialog::TData::~TData()
{
  delete [] FileName;
  delete [] Filter;
}

TOpenSaveDialog::TData&
TOpenSaveDialog::TData::operator =(const TData& src)
{
  Flags = src.Flags;
  Error = 0;
  CustomFilter = src.CustomFilter;
  FilterIndex = src.FilterIndex;
  InitialDir = src.InitialDir;
  DefExt = src.DefExt;
  MaxPath = src.MaxPath;

  delete [] FileName;
  FileName = strnewdup(src.FileName, MaxPath);

  SetFilter(src.Filter);

  return *this;
}

//
// Set the file list box filter strings. Translates '|'s into 0s so that the
// string can be kept as a resource with imbeded '|'s like:
// "Text Files(*.txt)|*.TXT|All Files(*.*)|*.*|"
// Can also handle already processed filter strings.
//
void
TOpenSaveDialog::TData::SetFilter(const char* filter)
{
  // Copy filter string
  //
  if (filter) {
    delete [] Filter;
    if (strchr(filter, '|')) {
      uint len = strlen(filter) + 2; // one for each terminating 0
      Filter = strcpy(new char[len], filter);
      Filter[len-1] = 0;             // in case trailing '|' is missing
    }
    else {
      const char* p = filter;
      while (*p)
        p += strlen(p) + 1;             // scan for 00 at end
      uint len = uint(p - filter) + 1;  // one more for last 0
      Filter = new char[len];
      memcpy(Filter, filter, len);
    }
  }
  // Stomp |s with 0s
  //
  if (Filter)
    for (char* p = Filter; *p; p++)
      if (*p == '|')
        *p = 0;
}


//----------------------------------------------------------------------------

DEFINE_RESPONSE_TABLE1(TOpenSaveDialog, TCommonDialog)
END_RESPONSE_TABLE;

uint TOpenSaveDialog::ShareViMsgId = 0;

void
TOpenSaveDialog::Init(TResId templateId)
{
  if (!ShareViMsgId)
    ShareViMsgId = ::RegisterWindowMessage(SHAREVISTRING);

  memset(&ofn, 0, sizeof(OPENFILENAME));
  ofn.lStructSize = sizeof(OPENFILENAME);
  ofn.hwndOwner = Parent ? Parent->HWindow : 0;
  ofn.hInstance = *GetModule();
  ofn.Flags = OFN_ENABLEHOOK | Data.Flags;
  if (templateId) {
    ofn.lpTemplateName = templateId;
    ofn.Flags |= OFN_ENABLETEMPLATE;
  }
  else
    ofn.Flags &= ~OFN_ENABLETEMPLATE;
  ofn.lpfnHook = 0;

  ofn.lpstrFilter = Data.Filter;
  ofn.nFilterIndex = Data.FilterIndex;
  ofn.lpstrFile = Data.FileName;
  ofn.nMaxFile = Data.MaxPath;
  ofn.lpstrInitialDir = Data.InitialDir;
  ofn.lpstrDefExt = Data.DefExt;
}

TOpenSaveDialog::TOpenSaveDialog(TWindow* parent, TData& data, TModule*   module)
:
  TCommonDialog(parent, 0, module),
  Data(data)
{
}

TOpenSaveDialog::TOpenSaveDialog(TWindow*        parent,
                                 TData&          data,
                                 TResId          templateId,
                                 const char far* title,
                                 TModule*        module)
:
  TCommonDialog(parent, 0, module),
  Data(data)
{
  Init(templateId);
  (LPCSTR)ofn.lpstrTitle = title;
}

bool
TOpenSaveDialog::DialogFunction(uint msg, WPARAM wParam, LPARAM lParam)
{
  if (TCommonDialog::DialogFunction(msg, wParam, lParam))
    return true;

  if (msg == TOpenSaveDialog::ShareViMsgId)
    return (bool)ShareViolation();

  return false;
}

int
TOpenSaveDialog::ShareViolation()
{
  return OFN_SHAREWARN;
}

//----------------------------------------------------------------------------

TFileOpenDialog::TFileOpenDialog(TWindow*        parent,
                                 TData&          data,
                                 TResId          templateId,
                                 const char far* title,
                                 TModule*        module)
:
  TOpenSaveDialog(parent, data, templateId, title, module)
{
}

int
TFileOpenDialog::DoExecute()
{
  (DLGPROC)ofn.lpfnHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  int ret = ::GetOpenFileName(&ofn);
  if (ret) {
    Data.Flags = ofn.Flags;
    Data.Error = 0;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  return ret ? IDOK : IDCANCEL;
}


//----------------------------------------------------------------------------

TFileSaveDialog::TFileSaveDialog(TWindow*        parent,
                                 TData&          data,
                                 TResId          templateId,
                                 const char far* title,
                                 TModule*        module)
:
  TOpenSaveDialog(parent, data, templateId, title, module)
{
}

int
TFileSaveDialog::DoExecute()
{
  (DLGPROC)ofn.lpfnHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  int ret = ::GetSaveFileName(&ofn);
  if (ret) {
    Data.Flags = ofn.Flags;
    Data.Error = 0;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  return ret ? IDOK : IDCANCEL;
}

#endif
#if !defined(SECTION) || SECTION == 2

void
TOpenSaveDialog::TData::Read(ipstream& is)
{
  is >> Flags;
  delete FileName;
  FileName = is.readString();
  delete Filter;
  Filter = is.readString();
  CustomFilter = is.readString();
  is >> FilterIndex;
  InitialDir = is.readString();
  DefExt = is.readString();
}

void
TOpenSaveDialog::TData::Write(opstream& os)
{
  os << Flags;
  os.writeString(FileName);
  os.writeString(Filter);
  os.writeString(CustomFilter);
  os << FilterIndex;
  os.writeString(InitialDir);
  os.writeString(DefExt);
}

#endif
