//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dialog.h>
#include <owl\static.h>
#include <dos.h>
#include "sysinfo.h"


struct SysInfo16Record {
  char InstanceNumber[31];
  char WindowsVersion[31];
  char OperationMode[31];
  char CPUType[31];
  char CoProcessor[31];
  char Global[31];
  char VersionDos[31];
};

struct SysInfo32Record {
  char WindowsVersion[31];
  char OemId[31];
  char PageSize[31];
  char MinAppAddress[31];
  char MaxAppAddress[31];
  char ActiveProcessorMask[31];
  char NumberOfProcessors[31];
  char ProcessorType[31];
  char AllocationGranularity[31];
  char Reserved[31];
};

#if defined(__WIN32__)
  typedef SysInfo32Record SysInfoRecord;
  #define IDD_SYSINFO "IDD_SysInfo32"
#else
  typedef SysInfo16Record SysInfoRecord;
  #define IDD_SYSINFO "IDD_SysInfo16"
#endif

class TSysInfoWindow : public TDialog {
  public:
    TSysInfoWindow(TWindow* parent, const char* title);
    void GetSysInformation();
    void InitChildren();

  private:
    SysInfoRecord TransferRecord;
};

TSysInfoWindow::TSysInfoWindow(TWindow* parent, const char* title)
  : TWindow(parent),
    TDialog(parent, title)
{
  InitChildren();
  GetSysInformation();
  TransferBuffer = &TransferRecord;
}

void
TSysInfoWindow::InitChildren()
{
  TStatic* ts;

#if defined(__WIN32__)
  ts = new TStatic(this, IDC_WINDOWSVERSION, sizeof TransferRecord.WindowsVersion);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_OEMID, sizeof TransferRecord.OemId);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_PAGESIZE, sizeof TransferRecord.PageSize);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_MINAPPADDRESS, sizeof TransferRecord.MinAppAddress);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_MAXAPPADDRESS, sizeof TransferRecord.MaxAppAddress);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_ACTIVEPROMASK, sizeof TransferRecord.ActiveProcessorMask);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_NUMPROS, sizeof TransferRecord.NumberOfProcessors);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_PROTYPE, sizeof TransferRecord.ProcessorType);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_ALLOCGRAN, sizeof TransferRecord.AllocationGranularity);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_RESERVED, sizeof TransferRecord.Reserved);
  ts->EnableTransfer();
#else
  ts = new TStatic(this, IDC_INSTANCENUMBER, sizeof TransferRecord.InstanceNumber);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_WINDOWSVERSION, sizeof TransferRecord.WindowsVersion);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_OPERATIONMODE, sizeof TransferRecord.OperationMode);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_CPUTYPE, sizeof TransferRecord.CPUType);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_COPROCESSOR, sizeof TransferRecord.CoProcessor);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_GLOBAL, sizeof TransferRecord.Global);
  ts->EnableTransfer();

  ts = new TStatic(this, IDC_VERSIONDOS, sizeof TransferRecord.VersionDos);
  ts->EnableTransfer();
#endif
}

void
TSysInfoWindow::GetSysInformation()
{
#if defined(__WIN32__)
  DWORD ver = ::GetVersion();
  wsprintf(TransferRecord.WindowsVersion, "%d.%d", (int)LOBYTE(ver), (int)HIBYTE(ver));

  SYSTEM_INFO systemInfo;
  ::GetSystemInfo(&systemInfo);
  
  wsprintf(TransferRecord.OemId, "%lX", systemInfo.dwOemId);
  wsprintf(TransferRecord.PageSize, "%lX", systemInfo.dwPageSize);
  wsprintf(TransferRecord.MinAppAddress, "%lX", systemInfo.lpMinimumApplicationAddress);
  wsprintf(TransferRecord.MaxAppAddress, "%lX", systemInfo.lpMaximumApplicationAddress);
  wsprintf(TransferRecord.ActiveProcessorMask, "%lX", systemInfo.dwActiveProcessorMask);
  wsprintf(TransferRecord.NumberOfProcessors, "%lX", systemInfo.dwNumberOfProcessors);
  wsprintf(TransferRecord.ProcessorType, "%ld", systemInfo.dwProcessorType);
  wsprintf(TransferRecord.AllocationGranularity, "%lX", systemInfo.dwAllocationGranularity);
  wsprintf(TransferRecord.Reserved, "%lX", systemInfo.dwReserved);
  
#else
  char  tempstr[31];
  UINT  strId;
  DWORD SysFlags = GetWinFlags();

  wsprintf(TransferRecord.InstanceNumber, "%d", GetApplication()->GetModuleUsage());

  DWORD ver = ::GetVersion();
  wsprintf(TransferRecord.WindowsVersion, "%d.%d", (int)LOBYTE(ver), (int)HIBYTE(ver));

  if (SysFlags & WF_ENHANCED)
    strId = IDS_ENHANCED;
  else if (SysFlags & WF_STANDARD)
    strId = IDS_STANDARD;
  else if (SysFlags & WF_PMODE)
    strId = IDS_REAL;
  else
    strId = IDS_UNKNOWN;
  GetApplication()->LoadString(strId, tempstr, sizeof(tempstr));
  strcpy(TransferRecord.OperationMode, tempstr);

  if (SysFlags & WF_CPU086)
    strId = IDS_CPU8086;
  else if (SysFlags & WF_CPU186)
    strId = IDS_CPU80186;
  else if (SysFlags & WF_CPU286)
    strId = IDS_CPU80286;
  else if (SysFlags & WF_CPU386)
    strId = IDS_CPU80386;
  else if (SysFlags & WF_CPU486)
    strId = IDS_CPU80486;
  else
    strId = IDS_UNKNOWN;
  GetApplication()->LoadString(strId, tempstr, sizeof(tempstr));
  strcpy(TransferRecord.CPUType, tempstr);

  strId = (SysFlags & WF_80x87) ? IDS_YES : IDS_NO;
  GetApplication()->LoadString(strId, tempstr, sizeof(tempstr));
  strcpy(TransferRecord.CoProcessor, tempstr);

  wsprintf(TransferRecord.Global, "%lu", GetFreeSpace(0)/1024);

  wsprintf(TransferRecord.VersionDos, "%d.%d", _osmajor, _osminor);
#endif
}

class TSysInfoApp : public TApplication {
  public:
    TSysInfoApp() : TApplication() {}
    void InitMainWindow() {
      EnableCtl3d();
      MainWindow = new TFrameWindow(0, "Windows System Information",
                              new TSysInfoWindow(0, IDD_SYSINFO), TRUE);
    }
};

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TSysInfoApp().Run();
}
