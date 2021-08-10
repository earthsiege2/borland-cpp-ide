//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1992, 1994 by Borland International, All Rights Reserved
//
//   Implementation of Print and PrintDetup common Dialogs classes
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/printdia.h>
#include <owl/dc.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TPrintDialog, TCommonDialog)
END_RESPONSE_TABLE;

TPrintDialog::TPrintDialog(TWindow*        parent,
                           TData&          data,
                           const char far* printTemplateName,
                           const char far* setupTemplateName,
                           const char far* title,
                           TModule*        module)
:
  TCommonDialog(parent, title, module),
  Data(data)
{
  memset(&pd, 0, sizeof(PRINTDLG));
  pd.lStructSize = sizeof(PRINTDLG);
  pd.hwndOwner = Parent ? Parent->HWindow : 0;
  pd.hInstance = *GetModule();
  pd.Flags = PD_ENABLEPRINTHOOK | PD_ENABLESETUPHOOK | Data.Flags;
  pd.Flags &= ~PD_RETURNDEFAULT;

  if (printTemplateName) {
    (LPCSTR)pd.lpPrintTemplateName = printTemplateName;
    pd.Flags |= PD_ENABLEPRINTTEMPLATE;
  }
  else
    pd.Flags &= ~PD_ENABLEPRINTTEMPLATE;

  if (setupTemplateName) {
    (LPCSTR)pd.lpSetupTemplateName = setupTemplateName;
    pd.Flags |= PD_ENABLESETUPTEMPLATE;
  }
  else
    pd.Flags &= ~PD_ENABLESETUPTEMPLATE;

  pd.lpfnPrintHook = 0;
  pd.lpfnSetupHook = 0;

  pd.nFromPage = (uint16)Data.FromPage;
  pd.nToPage = (uint16)Data.ToPage;
  pd.nMinPage = (uint16)Data.MinPage;
  pd.nMaxPage = (uint16)Data.MaxPage;
  pd.nCopies = (uint16)Data.Copies;
}

bool
TPrintDialog::DialogFunction(uint msg, WPARAM wParam, LPARAM lParam)
{
  return TCommonDialog::DialogFunction(msg, wParam, lParam);
}

int
TPrintDialog::DoExecute()
{
  (DLGPROC)pd.lpfnPrintHook = (DLGPROC)(FARPROC)StdDlgProcInstance;
  (DLGPROC)pd.lpfnSetupHook = (DLGPROC)(FARPROC)StdDlgProcInstance;

  Data.Unlock();
  pd.hDevMode = Data.hDevMode;
  pd.hDevNames = Data.hDevNames;
  int ret = ::PrintDlg(&pd);
  if (ret) {
    Data.Flags = pd.Flags;
    Data.Error = 0;
    Data.hDC = pd.hDC;
    Data.FromPage = pd.nFromPage;
    Data.ToPage = pd.nToPage;
    Data.Copies = pd.nCopies;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  Data.hDevMode = pd.hDevMode;
  Data.hDevNames = pd.hDevNames;
  Data.Lock();
  return ret ? IDOK : IDCANCEL;
}

bool
TPrintDialog::GetDefaultPrinter()
{
  pd.Flags |= PD_RETURNDEFAULT;
  Data.ClearDevMode();
  Data.ClearDevNames();
  return DoExecute() == IDOK;
}

//----------------------------------------------------------------------------

TPrintDialog::TData::TData()
:
  Flags(PD_ALLPAGES|PD_COLLATE),
  Error(0),
  FromPage(-1), ToPage(-1),
  MinPage(-1), MaxPage(-1),
  Copies(1),
  hDevMode(0), DevMode(0), hDevNames(0), DevNames(0), hDC(0)
{
}

TPrintDialog::TData::~TData()
{
  if (hDevMode) {
    ::GlobalUnlock(hDevMode);
    ::GlobalFree(hDevMode);
  }
  if (hDevNames) {
    ::GlobalUnlock(hDevNames);
    ::GlobalFree(hDevNames);
  }
  if (hDC)
    ::DeleteDC(hDC);
}

void
TPrintDialog::TData::Lock()
{
  if (hDevMode)
    DevMode = (DEVMODE far*)::GlobalLock(hDevMode);
  else
    DevMode = 0;
  if (hDevNames)
    DevNames = (DEVNAMES far*)::GlobalLock(hDevNames);
  else
    DevNames = 0;
}

void
TPrintDialog::TData::Unlock()
{
  if (hDevMode) {
    ::GlobalUnlock(hDevMode);
    DevMode = 0;
  }
  if (hDevNames) {
    ::GlobalUnlock(hDevNames);
    DevNames = 0;
  }
  if (hDC) {
    ::DeleteDC(hDC);
    hDC = 0;
  }
}

void TPrintDialog::TData::ClearDevMode()
{
  if (hDevMode) {
    ::GlobalUnlock(hDevMode);
    ::GlobalFree(hDevMode);
    hDevMode = 0;
    DevMode = 0;
  }
}

void
TPrintDialog::TData::SetDevMode(const DEVMODE far* devMode)
{
  ClearDevMode();
  if (devMode) {
    int size = sizeof(DEVMODE) + devMode->dmDriverExtra;
    hDevMode = ::GlobalAlloc(GHND, size);
    DevMode = (DEVMODE far*)::GlobalLock(hDevMode);
    memcpy(DevMode, devMode, size);
  }
}

void
TPrintDialog::TData::ClearDevNames()
{
  if (hDevNames) {
    ::GlobalUnlock(hDevNames);
    ::GlobalFree(hDevNames);
    hDevNames = 0;
    DevNames = 0;
  }
}

const char far*
TPrintDialog::TData::GetDriverName() const
{
  return DevNames ? (char far*)DevNames + DevNames->wDriverOffset : 0;
}

const char far*
TPrintDialog::TData::GetDeviceName() const
{
  return DevNames ? (char far*)DevNames + DevNames->wDeviceOffset : 0;
}

const char far*
TPrintDialog::TData::GetOutputName() const
{
  return DevNames ? (char far*)DevNames + DevNames->wOutputOffset : 0;
}

void
TPrintDialog::TData::SetDevNames(const char far* driver,
                                 const char far* device,
                                 const char far* output)
{
  ClearDevNames();
  if (!driver || !device || !output)
    return;

  int size1 = strlen(driver)+1;
  int size2 = strlen(device)+1;
  int size3 = strlen(output)+1;
  hDevNames = ::GlobalAlloc(GHND, sizeof(DEVNAMES)+size1+size2+size3);
  DevNames = (DEVNAMES far*)::GlobalLock(hDevNames);
  char far* p = (char far*)(DevNames + 1);

  DevNames->wDriverOffset = uint16((char near*)p - (char near*)DevNames);
  if (driver)
    while (*driver)
      *p++ = *driver++;
  *p++ = 0;

  DevNames->wDeviceOffset = uint16((char near*)p - (char near*)DevNames);
  if (device)
    while (*device)
      *p++ = *device++;
  *p++ = 0;

  DevNames->wOutputOffset = uint16((char near*)p - (char near*)DevNames);
  if (output)
    while (*output)
      *p++ = *output++;
  *p++ = 0;

  DevNames->wDefault = false;
}

//
// Pass ownership of our hDC to the caller thru a new's TPrintDC object
//
TPrintDC*
TPrintDialog::TData::TransferDC()
{
  if (!hDC)
    return 0;
  HDC dc = hDC;
  hDC = 0;
  return new TPrintDC(dc, AutoDelete);
}

#endif
#if !defined(SECTION) || SECTION == 2

void*
TPrintDialog::TData::Read(ipstream& is, uint32 /*version*/)
{
  is >> Flags;
  is >> FromPage;
  is >> ToPage;
  is >> MinPage;
  is >> MaxPage;
  is >> Copies;
  char far* driver = is.freadString();
  char far* device = is.freadString();
  char far* output = is.freadString();
  uint16 deflt;
  is >> deflt;
  SetDevNames(driver, device, output);
  if (DevNames)
    DevNames->wDefault = deflt;
  delete driver;
  delete device;
  delete output;

  int16 size;
  is >> size;
  if (size) {
    DEVMODE far* devMode = (DEVMODE far*)new far char[size];
    is.freadBytes(devMode, size);
    SetDevMode(devMode);
    delete devMode;
  }
  else
    ClearDevMode();

  return this;
}

void
TPrintDialog::TData::Write(opstream& os)
{
  os << Flags;
  os << FromPage;
  os << ToPage;
  os << MinPage;
  os << MaxPage;
  os << Copies;
  os.fwriteString(GetDriverName());
  os.fwriteString(GetDeviceName());
  os.fwriteString(GetOutputName());
  os << (DevNames ? DevNames->wDefault : uint16(0));

  if (DevMode) {
    int16 size = int16(sizeof(DEVMODE) + DevMode->dmDriverExtra);
    os << size;
    os.fwriteBytes(DevMode, size);
  }
  else
    os << int16(0);
}

#endif
