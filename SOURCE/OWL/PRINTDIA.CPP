//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Implementation of class TPrintDialog, a Print and PrintSetup common Dialog
// encapsulation
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_PRINTDIA_H)
# include <owl/printdia.h>
#endif
#if !defined(OWL_DC_H)
# include <owl/dc.h>
#endif

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TPrintDialog, TCommonDialog)
END_RESPONSE_TABLE;

//
//
//
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
  memset(&Pd, 0, sizeof Pd);
  Pd.lStructSize = sizeof Pd;
  Pd.hwndOwner = Parent ? Parent->GetHandle() : 0;
  Pd.hInstance = *GetModule();
  Pd.Flags = PD_ENABLEPRINTHOOK | PD_ENABLESETUPHOOK | Data.Flags;
  Pd.Flags &= ~PD_RETURNDEFAULT;

  if (printTemplateName) {
    Pd.lpPrintTemplateName = printTemplateName;
    Pd.Flags |= PD_ENABLEPRINTTEMPLATE;
  }
  else
    Pd.Flags &= ~PD_ENABLEPRINTTEMPLATE;

  if (setupTemplateName) {
    Pd.lpSetupTemplateName = setupTemplateName;
    Pd.Flags |= PD_ENABLESETUPTEMPLATE;
  }
  else
    Pd.Flags &= ~PD_ENABLESETUPTEMPLATE;

  Pd.lpfnPrintHook = 0;
  Pd.lpfnSetupHook = 0;

  Pd.nFromPage = (uint16)Data.FromPage;
  Pd.nToPage = (uint16)Data.ToPage;
  Pd.nMinPage = (uint16)Data.MinPage;
  Pd.nMaxPage = (uint16)Data.MaxPage;
  Pd.nCopies = (uint16)Data.Copies;

#if defined(BI_PLAT_WIN32)  
  memset(&Psd, 0, sizeof Psd);
  Psd.lStructSize = sizeof Psd;
  Psd.hwndOwner = Parent ? Parent->GetHandle() : 0;
  Psd.hInstance = *GetModule();
  Psd.Flags = PSD_ENABLEPAGESETUPHOOK | PSD_ENABLEPAGEPAINTHOOK | Data.PageSetupFlags;

  if (setupTemplateName) {
    Psd.lpPageSetupTemplateName = setupTemplateName;
    Psd.Flags |= PSD_ENABLEPAGESETUPTEMPLATE;
  }
  else
    Psd.Flags &= ~PSD_ENABLEPAGESETUPTEMPLATE;

  Psd.lpfnPageSetupHook = 0;
  Psd.lpfnPagePaintHook = 0;

  Psd.ptPaperSize = Data.PaperSize;
  Psd.rtMinMargin = Data.MinMargin;
  Psd.rtMargin = Data.Margin;
#endif
}

//
//
//
bool
TPrintDialog::DialogFunction(uint msg, TParam1 param1, TParam2 param2)
{
  return TCommonDialog::DialogFunction(msg, param1, param2);
}

//
//
//
int
TPrintDialog::DoExecute()
{
#if defined(BI_PLAT_WIN32)  
  if (Data.DoPageSetup) {
    Psd.lpfnPageSetupHook = LPPAGESETUPHOOK(StdDlgProc);
    Psd.lpfnPagePaintHook = LPPAGEPAINTHOOK(StdDlgProc);

    Data.Unlock();

    Psd.hDevMode = Data.HDevMode;
    Psd.hDevNames = Data.HDevNames;

    int ret = ::PageSetupDlg(&Psd);
    if (ret) {
      Data.PageSetupFlags = Psd.Flags;
      Data.Error = 0;
      Data.PaperSize = Psd.ptPaperSize;
      Data.MinMargin = Psd.rtMinMargin;
      Data.Margin = Psd.rtMargin;
    }
    else {
      Data.Error = ::CommDlgExtendedError();
    }

    Data.HDevMode = Psd.hDevMode;
    Data.HDevNames = Psd.hDevNames;

    Data.Lock();

    return ret ? IDOK : IDCANCEL;
  }
#endif

  Pd.lpfnPrintHook = LPPRINTHOOKPROC(StdDlgProc);
  Pd.lpfnSetupHook = LPSETUPHOOKPROC(StdDlgProc);

  Data.Unlock();
  Pd.hDevMode = Data.HDevMode;
  Pd.hDevNames = Data.HDevNames;
  int ret = ::PrintDlg(&Pd);
  if (ret) {
    Data.Flags = Pd.Flags;
    Data.Error = 0;
    Data.HDc = Pd.hDC;
    Data.FromPage = Pd.nFromPage;
    Data.ToPage = Pd.nToPage;
    Data.Copies = Pd.nCopies;
  }
  else {
    Data.Error = ::CommDlgExtendedError();
  }
  Data.HDevMode = Pd.hDevMode;
  Data.HDevNames = Pd.hDevNames;
  Data.Lock();
  return ret ? IDOK : IDCANCEL;
}

//
//
//
bool
TPrintDialog::GetDefaultPrinter()
{
  Pd.Flags |= PD_RETURNDEFAULT;
  Data.ClearDevMode();
  Data.ClearDevNames();
  return DoExecute() == IDOK;
}

//----------------------------------------------------------------------------

//
//
//
TPrintDialog::TData::TData()
:
  Flags(PD_ALLPAGES|PD_COLLATE),
  Error(0),
  FromPage(-1), ToPage(-1),
  MinPage(-1), MaxPage(-1),
  Copies(1),
  HDevMode(0), DevMode(0),
  HDevNames(0), DevNames(0),
  HDc(0)
#if defined(BI_PLAT_WIN32)  
 ,PageSetupFlags(PSD_DEFAULTMINMARGINS),
  DoPageSetup(false)
#endif
{
}

//
//
//
TPrintDialog::TData::~TData()
{
  if (HDevMode) {
    ::GlobalUnlock(HDevMode);
    ::GlobalFree(HDevMode);
  }
  if (HDevNames) {
    ::GlobalUnlock(HDevNames);
    ::GlobalFree(HDevNames);
  }
  if (HDc)
    ::DeleteDC(HDc);
}

//
//
//
void
TPrintDialog::TData::Lock()
{
  if (HDevMode)
    DevMode = (DEVMODE far*)::GlobalLock(HDevMode);
  else
    DevMode = 0;
  if (HDevNames)
    DevNames = (DEVNAMES far*)::GlobalLock(HDevNames);
  else
    DevNames = 0;
}

//
//
//
void
TPrintDialog::TData::Unlock()
{
  if (HDevMode) {
    ::GlobalUnlock(HDevMode);
    DevMode = 0;
  }
  if (HDevNames) {
    ::GlobalUnlock(HDevNames);
    DevNames = 0;
  }
  if (HDc) {
    ::DeleteDC(HDc);
    HDc = 0;
  }
}

//
//
//
void
TPrintDialog::TData::ClearDevMode()
{
  if (HDevMode) {
    ::GlobalUnlock(HDevMode);
    ::GlobalFree(HDevMode);
    HDevMode = 0;
    DevMode = 0;
  }
}

//
//
//
void
TPrintDialog::TData::SetDevMode(const DEVMODE far* devMode)
{
  ClearDevMode();
  if (devMode) {

#if 0     
    int size = sizeof(DEVMODE) + devMode->dmDriverExtra;
#else
    int size = devMode->dmSize + devMode->dmDriverExtra;
#endif
    HDevMode = ::GlobalAlloc(GHND, size);
    DevMode = (DEVMODE far*)::GlobalLock(HDevMode);
    memcpy(DevMode, devMode, size);
  }
}

//
//
//
void
TPrintDialog::TData::ClearDevNames()
{
  if (HDevNames) {
    ::GlobalUnlock(HDevNames);
    ::GlobalFree(HDevNames);
    HDevNames = 0;
    DevNames = 0;
  }
}

//
//
//
const char far*
TPrintDialog::TData::GetDriverName() const
{
  return DevNames ? (char far*)DevNames + DevNames->wDriverOffset : 0;
}

//
//
//
const char far*
TPrintDialog::TData::GetDeviceName() const
{
  return DevNames ? (char far*)DevNames + DevNames->wDeviceOffset : 0;
}

//
//
//
const char far*
TPrintDialog::TData::GetOutputName() const
{
  return DevNames ? (char far*)DevNames + DevNames->wOutputOffset : 0;
}

//
//
//
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
  HDevNames = ::GlobalAlloc(GHND, sizeof(DEVNAMES)+size1+size2+size3);
  DevNames = (DEVNAMES far*)::GlobalLock(HDevNames);
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
  *p = 0;

  DevNames->wDefault = false;
}

//
// Pass ownership of our hDC to the caller thru a new's TPrintDC object
//
TPrintDC*
TPrintDialog::TData::TransferDC()
{
  if (!HDc)
    return 0;
  HDC hdc = HDc;
  HDc = 0;
  return new TPrintDC(hdc, AutoDelete);
}

#endif
#if !defined(SECTION) || SECTION == 2

//
// Read the persistent object from the stream.
//
void*
TPrintDialog::TData::Read(ipstream& is, uint32 version)
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
  delete[] driver;
  delete[] device;
  delete[] output;

  int16 size;
  is >> size;
  if (size) {
    DEVMODE far* devMode = (DEVMODE far*)new far char[size];
    is.freadBytes(devMode, size);
    SetDevMode(devMode);
    delete[] devMode;
  }
  else
    ClearDevMode();

#if defined(BI_PLAT_WIN32)  
  if (version > 1) {
    is >> PageSetupFlags;
    is >> PaperSize;
    is >> MinMargin;
    is >> Margin;
  }
#endif

  return this;
}

//
// Write the object to a peristent stream.
//
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

#if 0 
    int16 size = int16(sizeof(DEVMODE) + DevMode->dmDriverExtra);
#else
    int16 size = int16(DevMode->dmSize + DevMode->dmDriverExtra);
#endif
    os << size;
    os.fwriteBytes(DevMode, size);
  }
  else
    os << int16(0);

#if defined(BI_PLAT_WIN32)
  os << PageSetupFlags;
  os << PaperSize;
  os << MinMargin;
  os << Margin;
#endif
}

#endif
