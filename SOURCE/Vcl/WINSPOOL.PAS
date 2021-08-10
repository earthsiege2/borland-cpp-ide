
{*******************************************************}
{                                                       }
{       Borland Delphi Run-time Library                 }
{       Win32 printer API Interface Unit                }
{                                                       }
{       Copyright (c) 1985-1999, Microsoft Corporation  }
{                                                       }
{       Translator: Inprise Corporation                 }
{                                                       }
{*******************************************************}

unit WinSpool;

{$WEAKPACKAGEUNIT}

interface

uses Windows;

(*$HPPEMIT '' *)
(*$HPPEMIT '#include <winspool.h>' *)
(*$HPPEMIT '' *)

type
  PPrinterInfo1A = ^TPrinterInfo1A;
  PPrinterInfo1W = ^TPrinterInfo1W;
  PPrinterInfo1 = PPrinterInfo1A;
  {$EXTERNALSYM _PRINTER_INFO_1A}
  _PRINTER_INFO_1A = record
    Flags: DWORD;
    pDescription: PAnsiChar;
    pName: PAnsiChar;
    pComment: PAnsiChar;
  end;
  {$EXTERNALSYM _PRINTER_INFO_1W}
  _PRINTER_INFO_1W = record
    Flags: DWORD;
    pDescription: PWideChar;
    pName: PWideChar;
    pComment: PWideChar;
  end;
  {$EXTERNALSYM _PRINTER_INFO_1}
  _PRINTER_INFO_1 = _PRINTER_INFO_1A;
  TPrinterInfo1A = _PRINTER_INFO_1A;
  TPrinterInfo1W = _PRINTER_INFO_1W;
  TPrinterInfo1 = TPrinterInfo1A;
  {$EXTERNALSYM PRINTER_INFO_1A}
  PRINTER_INFO_1A = _PRINTER_INFO_1A;
  {$EXTERNALSYM PRINTER_INFO_1W}
  PRINTER_INFO_1W = _PRINTER_INFO_1W;
  {$EXTERNALSYM PRINTER_INFO_1}
  PRINTER_INFO_1 = PRINTER_INFO_1A;

  PPrinterInfo2A = ^TPrinterInfo2A;
  PPrinterInfo2W = ^TPrinterInfo2W;
  PPrinterInfo2 = PPrinterInfo2A;
  {$EXTERNALSYM _PRINTER_INFO_2A}
  _PRINTER_INFO_2A = record
    pServerName: PAnsiChar;
    pPrinterName: PAnsiChar;
    pShareName: PAnsiChar;
    pPortName: PAnsiChar;
    pDriverName: PAnsiChar;
    pComment: PAnsiChar;
    pLocation: PAnsiChar;
    pDevMode: PDeviceModeA;
    pSepFile: PAnsiChar;
    pPrintProcessor: PAnsiChar;
    pDatatype: PAnsiChar;
    pParameters: PAnsiChar;
    pSecurityDescriptor: PSecurityDescriptor;
    Attributes: DWORD;
    Priority: DWORD;
    DefaultPriority: DWORD;
    StartTime: DWORD;
    UntilTime: DWORD;
    Status: DWORD;
    cJobs: DWORD;
    AveragePPM: DWORD;
  end;
  {$EXTERNALSYM _PRINTER_INFO_2W}
  _PRINTER_INFO_2W = record
    pServerName: PWideChar;
    pPrinterName: PWideChar;
    pShareName: PWideChar;
    pPortName: PWideChar;
    pDriverName: PWideChar;
    pComment: PWideChar;
    pLocation: PWideChar;
    pDevMode: PDeviceModeW;
    pSepFile: PWideChar;
    pPrintProcessor: PWideChar;
    pDatatype: PWideChar;
    pParameters: PWideChar;
    pSecurityDescriptor: PSecurityDescriptor;
    Attributes: DWORD;
    Priority: DWORD;
    DefaultPriority: DWORD;
    StartTime: DWORD;
    UntilTime: DWORD;
    Status: DWORD;
    cJobs: DWORD;
    AveragePPM: DWORD;
  end;
  {$EXTERNALSYM _PRINTER_INFO_2}
  _PRINTER_INFO_2 = _PRINTER_INFO_2A;
  TPrinterInfo2A = _PRINTER_INFO_2A;
  TPrinterInfo2W = _PRINTER_INFO_2W;
  TPrinterInfo2 = TPrinterInfo2A;
  {$EXTERNALSYM PRINTER_INFO_2A}
  PRINTER_INFO_2A = _PRINTER_INFO_2A;
  {$EXTERNALSYM PRINTER_INFO_2W}
  PRINTER_INFO_2W = _PRINTER_INFO_2W;
  {$EXTERNALSYM PRINTER_INFO_2}
  PRINTER_INFO_2 = PRINTER_INFO_2A;

  PPrinterInfo3 = ^TPrinterInfo3;
  {$EXTERNALSYM _PRINTER_INFO_3}
  _PRINTER_INFO_3 = record
    pSecurityDescriptor: PSecurityDescriptor;
  end;
  TPrinterInfo3 = _PRINTER_INFO_3;
  {$EXTERNALSYM PRINTER_INFO_3}
  PRINTER_INFO_3 = _PRINTER_INFO_3;

  PPrinterInfo4A = ^TPrinterInfo4A;
  PPrinterInfo4W = ^TPrinterInfo4W;
  PPrinterInfo4 = PPrinterInfo4A;
  {$EXTERNALSYM _PRINTER_INFO_4A}
  _PRINTER_INFO_4A = record
    pPrinterName: PAnsiChar;
    pServerName: PAnsiChar;
    Attributes: DWORD;
  end;
  {$EXTERNALSYM _PRINTER_INFO_4W}
  _PRINTER_INFO_4W = record
    pPrinterName: PWideChar;
    pServerName: PWideChar;
    Attributes: DWORD;
  end;
  {$EXTERNALSYM _PRINTER_INFO_4}
  _PRINTER_INFO_4 = _PRINTER_INFO_4A;
  TPrinterInfo4A = _PRINTER_INFO_4A;
  TPrinterInfo4W = _PRINTER_INFO_4W;
  TPrinterInfo4 = TPrinterInfo4A;
  {$EXTERNALSYM PRINTER_INFO_4A}
  PRINTER_INFO_4A = _PRINTER_INFO_4A;
  {$EXTERNALSYM PRINTER_INFO_4W}
  PRINTER_INFO_4W = _PRINTER_INFO_4W;
  {$EXTERNALSYM PRINTER_INFO_4}
  PRINTER_INFO_4 = PRINTER_INFO_4A;

  PPrinterInfo5A = ^TPrinterInfo5A;
  PPrinterInfo5W = ^TPrinterInfo5W;
  PPrinterInfo5 = PPrinterInfo5A;
  {$EXTERNALSYM _PRINTER_INFO_5A}
  _PRINTER_INFO_5A = record
    pPrinterName: PAnsiChar;
    pPortName: PAnsiChar;
    Attributes: DWORD;
    DeviceNotSelectedTimeout: DWORD;
    TransmissionRetryTimeout: DWORD;
  end;
  {$EXTERNALSYM _PRINTER_INFO_5W}
  _PRINTER_INFO_5W = record
    pPrinterName: PWideChar;
    pPortName: PWideChar;
    Attributes: DWORD;
    DeviceNotSelectedTimeout: DWORD;
    TransmissionRetryTimeout: DWORD;
  end;
  {$EXTERNALSYM _PRINTER_INFO_5}
  _PRINTER_INFO_5 = _PRINTER_INFO_5A;
  TPrinterInfo5A = _PRINTER_INFO_5A;
  TPrinterInfo5W = _PRINTER_INFO_5W;
  TPrinterInfo5 = TPrinterInfo5A;
  {$EXTERNALSYM PRINTER_INFO_5A}
  PRINTER_INFO_5A = _PRINTER_INFO_5A;
  {$EXTERNALSYM PRINTER_INFO_5W}
  PRINTER_INFO_5W = _PRINTER_INFO_5W;
  {$EXTERNALSYM PRINTER_INFO_5}
  PRINTER_INFO_5 = PRINTER_INFO_5A;

  PPrinterInfo6 = ^TPrinterInfo6;
  {$EXTERNALSYM _PRINTER_INFO_6}
  _PRINTER_INFO_6 = record
    dwStatus: DWORD;
  end;
  TPrinterInfo6 = _PRINTER_INFO_6;
  {$EXTERNALSYM PRINTER_INFO_6}
  PRINTER_INFO_6 = _PRINTER_INFO_6;

const
  {$EXTERNALSYM PRINTER_CONTROL_PAUSE}
  PRINTER_CONTROL_PAUSE            = 1;
  {$EXTERNALSYM PRINTER_CONTROL_RESUME}
  PRINTER_CONTROL_RESUME           = 2;
  {$EXTERNALSYM PRINTER_CONTROL_PURGE}
  PRINTER_CONTROL_PURGE            = 3;
  {$EXTERNALSYM PRINTER_CONTROL_SET_STATUS}
  PRINTER_CONTROL_SET_STATUS       = 4;

  {$EXTERNALSYM PRINTER_STATUS_PAUSED}
  PRINTER_STATUS_PAUSED            = $00000001;
  {$EXTERNALSYM PRINTER_STATUS_ERROR}
  PRINTER_STATUS_ERROR             = $00000002;
  {$EXTERNALSYM PRINTER_STATUS_PENDING_DELETION}
  PRINTER_STATUS_PENDING_DELETION  = $00000004;
  {$EXTERNALSYM PRINTER_STATUS_PAPER_JAM}
  PRINTER_STATUS_PAPER_JAM         = $00000008;
  {$EXTERNALSYM PRINTER_STATUS_PAPER_OUT}
  PRINTER_STATUS_PAPER_OUT         = $00000010;
  {$EXTERNALSYM PRINTER_STATUS_MANUAL_FEED}
  PRINTER_STATUS_MANUAL_FEED       = $00000020;
  {$EXTERNALSYM PRINTER_STATUS_PAPER_PROBLEM}
  PRINTER_STATUS_PAPER_PROBLEM     = $00000040;
  {$EXTERNALSYM PRINTER_STATUS_OFFLINE}
  PRINTER_STATUS_OFFLINE           = $00000080;
  {$EXTERNALSYM PRINTER_STATUS_IO_ACTIVE}
  PRINTER_STATUS_IO_ACTIVE         = $00000100;
  {$EXTERNALSYM PRINTER_STATUS_BUSY}
  PRINTER_STATUS_BUSY              = $00000200;
  {$EXTERNALSYM PRINTER_STATUS_PRINTING}
  PRINTER_STATUS_PRINTING          = $00000400;
  {$EXTERNALSYM PRINTER_STATUS_OUTPUT_BIN_FULL}
  PRINTER_STATUS_OUTPUT_BIN_FULL   = $00000800;
  {$EXTERNALSYM PRINTER_STATUS_NOT_AVAILABLE}
  PRINTER_STATUS_NOT_AVAILABLE     = $00001000;
  {$EXTERNALSYM PRINTER_STATUS_WAITING}
  PRINTER_STATUS_WAITING           = $00002000;
  {$EXTERNALSYM PRINTER_STATUS_PROCESSING}
  PRINTER_STATUS_PROCESSING        = $00004000;
  {$EXTERNALSYM PRINTER_STATUS_INITIALIZING}
  PRINTER_STATUS_INITIALIZING      = $00008000;
  {$EXTERNALSYM PRINTER_STATUS_WARMING_UP}
  PRINTER_STATUS_WARMING_UP        = $00010000;
  {$EXTERNALSYM PRINTER_STATUS_TONER_LOW}
  PRINTER_STATUS_TONER_LOW         = $00020000;
  {$EXTERNALSYM PRINTER_STATUS_NO_TONER}
  PRINTER_STATUS_NO_TONER          = $00040000;
  {$EXTERNALSYM PRINTER_STATUS_PAGE_PUNT}
  PRINTER_STATUS_PAGE_PUNT         = $00080000;
  {$EXTERNALSYM PRINTER_STATUS_USER_INTERVENTION}
  PRINTER_STATUS_USER_INTERVENTION = $00100000;
  {$EXTERNALSYM PRINTER_STATUS_OUT_OF_MEMORY}
  PRINTER_STATUS_OUT_OF_MEMORY     = $00200000;
  {$EXTERNALSYM PRINTER_STATUS_DOOR_OPEN}
  PRINTER_STATUS_DOOR_OPEN         = $00400000;
  {$EXTERNALSYM PRINTER_STATUS_SERVER_UNKNOWN}
  PRINTER_STATUS_SERVER_UNKNOWN    = $00800000;
  {$EXTERNALSYM PRINTER_STATUS_POWER_SAVE}
  PRINTER_STATUS_POWER_SAVE        = $01000000;

  {$EXTERNALSYM PRINTER_ATTRIBUTE_QUEUED}
  PRINTER_ATTRIBUTE_QUEUED         = $00000001;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_DIRECT}
  PRINTER_ATTRIBUTE_DIRECT         = $00000002;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_DEFAULT}
  PRINTER_ATTRIBUTE_DEFAULT        = $00000004;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_SHARED}
  PRINTER_ATTRIBUTE_SHARED         = $00000008;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_NETWORK}
  PRINTER_ATTRIBUTE_NETWORK        = $00000010;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_HIDDEN}
  PRINTER_ATTRIBUTE_HIDDEN         = $00000020;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_LOCAL}
  PRINTER_ATTRIBUTE_LOCAL          = $00000040;

  {$EXTERNALSYM PRINTER_ATTRIBUTE_ENABLE_DEVQ}
  PRINTER_ATTRIBUTE_ENABLE_DEVQ       = $00000080;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS}
  PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS   = $00000100;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST}
  PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST = $00000200;

  {$EXTERNALSYM PRINTER_ATTRIBUTE_WORK_OFFLINE}
  PRINTER_ATTRIBUTE_WORK_OFFLINE   = $00000400;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_ENABLE_BIDI}
  PRINTER_ATTRIBUTE_ENABLE_BIDI    = $00000800;
  {$EXTERNALSYM PRINTER_ATTRIBUTE_RAW_ONLY}
  PRINTER_ATTRIBUTE_RAW_ONLY       = $00001000;


  {$EXTERNALSYM NO_PRIORITY}
  NO_PRIORITY   = 0;
  {$EXTERNALSYM MAX_PRIORITY}
  MAX_PRIORITY = 99;
  {$EXTERNALSYM MIN_PRIORITY}
  MIN_PRIORITY  = 1;
  {$EXTERNALSYM DEF_PRIORITY}
  DEF_PRIORITY  = 1;

type
  PJobInfo1A = ^TJobInfo1A;
  PJobInfo1W = ^TJobInfo1W;
  PJobInfo1 = PJobInfo1A;
  {$EXTERNALSYM _JOB_INFO_1A}
  _JOB_INFO_1A = record
   JobId: DWORD;
   pPrinterName: PAnsiChar;
   pMachineName: PAnsiChar;
   pUserName: PAnsiChar;
   pDocument: PAnsiChar;
   pDatatype: PAnsiChar;
   pStatus: PAnsiChar;
   Status: DWORD;
   Priority: DWORD;
   Position: DWORD;
   TotalPages: DWORD;
   PagesPrinted: DWORD;
   Submitted: TSystemTime;
  end;
  {$EXTERNALSYM _JOB_INFO_1W}
  _JOB_INFO_1W = record
   JobId: DWORD;
   pPrinterName: PWideChar;
   pMachineName: PWideChar;
   pUserName: PWideChar;
   pDocument: PWideChar;
   pDatatype: PWideChar;
   pStatus: PWideChar;
   Status: DWORD;
   Priority: DWORD;
   Position: DWORD;
   TotalPages: DWORD;
   PagesPrinted: DWORD;
   Submitted: TSystemTime;
  end;
  {$EXTERNALSYM _JOB_INFO_1}
  _JOB_INFO_1 = _JOB_INFO_1A;
  TJobInfo1A = _JOB_INFO_1A;
  TJobInfo1W = _JOB_INFO_1W;
  TJobInfo1 = TJobInfo1A;
  {$EXTERNALSYM JOB_INFO_1A}
  JOB_INFO_1A = _JOB_INFO_1A;
  {$EXTERNALSYM JOB_INFO_1W}
  JOB_INFO_1W = _JOB_INFO_1W;
  {$EXTERNALSYM JOB_INFO_1}
  JOB_INFO_1 = JOB_INFO_1A;

  PJobInfo2A = ^TJobInfo2A;
  PJobInfo2W = ^TJobInfo2W;
  PJobInfo2 = PJobInfo2A;
  {$EXTERNALSYM _JOB_INFO_2A}
  _JOB_INFO_2A = record
   JobId: DWORD;
   pPrinterName: PAnsiChar;
   pMachineName: PAnsiChar;
   pUserName: PAnsiChar;
   pDocument: PAnsiChar;
   pNotifyName: PAnsiChar;
   pDatatype: PAnsiChar;
   pPrintProcessor: PAnsiChar;
   pParameters: PAnsiChar;
   pDriverName: PAnsiChar;
   pDevMode: PDeviceModeA;
   pStatus: PAnsiChar;
   pSecurityDescriptor: PSECURITY_DESCRIPTOR;
   Status: DWORD;
   Priority: DWORD;
   Position: DWORD;
   StartTime: DWORD;
   UntilTime: DWORD;
   TotalPages: DWORD;
   Size: DWORD;
   Submitted: TSystemTime;   { Time the job was spooled }
   Time: DWORD;              { How many seconds the job has been printing }
   PagesPrinted: DWORD;
  end;
  {$EXTERNALSYM _JOB_INFO_2W}
  _JOB_INFO_2W = record
   JobId: DWORD;
   pPrinterName: PWideChar;
   pMachineName: PWideChar;
   pUserName: PWideChar;
   pDocument: PWideChar;
   pNotifyName: PWideChar;
   pDatatype: PWideChar;
   pPrintProcessor: PWideChar;
   pParameters: PWideChar;
   pDriverName: PWideChar;
   pDevMode: PDeviceModeW;
   pStatus: PWideChar;
   pSecurityDescriptor: PSECURITY_DESCRIPTOR;
   Status: DWORD;
   Priority: DWORD;
   Position: DWORD;
   StartTime: DWORD;
   UntilTime: DWORD;
   TotalPages: DWORD;
   Size: DWORD;
   Submitted: TSystemTime;   { Time the job was spooled }
   Time: DWORD;              { How many seconds the job has been printing }
   PagesPrinted: DWORD;
  end;
  {$EXTERNALSYM _JOB_INFO_2}
  _JOB_INFO_2 = _JOB_INFO_2A;
  TJobInfo2A = _JOB_INFO_2A;
  TJobInfo2W = _JOB_INFO_2W;
  TJobInfo2 = TJobInfo2A;
  {$EXTERNALSYM JOB_INFO_2A}
  JOB_INFO_2A = _JOB_INFO_2A;
  {$EXTERNALSYM JOB_INFO_2W}
  JOB_INFO_2W = _JOB_INFO_2W;
  {$EXTERNALSYM JOB_INFO_2}
  JOB_INFO_2 = JOB_INFO_2A;

  PJobInfo3 = ^TJobInfo3;
  {$EXTERNALSYM _JOB_INFO_3}
  _JOB_INFO_3 = record
    JobId: DWORD;
    NextJobId: DWORD;
    Reserved: DWORD;
  end;
  TJobInfo3 = _JOB_INFO_3;
  {$EXTERNALSYM JOB_INFO_3}
  JOB_INFO_3 = _JOB_INFO_3;

const
  {$EXTERNALSYM JOB_CONTROL_PAUSE}
  JOB_CONTROL_PAUSE              = 1;
  {$EXTERNALSYM JOB_CONTROL_RESUME}
  JOB_CONTROL_RESUME             = 2;
  {$EXTERNALSYM JOB_CONTROL_CANCEL}
  JOB_CONTROL_CANCEL             = 3;
  {$EXTERNALSYM JOB_CONTROL_RESTART}
  JOB_CONTROL_RESTART            = 4;
  {$EXTERNALSYM JOB_CONTROL_DELETE}
  JOB_CONTROL_DELETE             = 5;
  {$EXTERNALSYM JOB_CONTROL_SENT_TO_PRINTER}
  JOB_CONTROL_SENT_TO_PRINTER    = 6;
  {$EXTERNALSYM JOB_CONTROL_LAST_PAGE_EJECTED}
  JOB_CONTROL_LAST_PAGE_EJECTED  = 7;

  {$EXTERNALSYM JOB_STATUS_PAUSED}
  JOB_STATUS_PAUSED                   = $00000001;
  {$EXTERNALSYM JOB_STATUS_ERROR}
  JOB_STATUS_ERROR                    = $00000002;
  {$EXTERNALSYM JOB_STATUS_DELETING}
  JOB_STATUS_DELETING                 = $00000004;
  {$EXTERNALSYM JOB_STATUS_SPOOLING}
  JOB_STATUS_SPOOLING                 = $00000008;
  {$EXTERNALSYM JOB_STATUS_PRINTING}
  JOB_STATUS_PRINTING                 = $00000010;
  {$EXTERNALSYM JOB_STATUS_OFFLINE}
  JOB_STATUS_OFFLINE                  = $00000020;
  {$EXTERNALSYM JOB_STATUS_PAPEROUT}
  JOB_STATUS_PAPEROUT                 = $00000040;
  {$EXTERNALSYM JOB_STATUS_PRINTED}
  JOB_STATUS_PRINTED                  = $00000080;
  {$EXTERNALSYM JOB_STATUS_DELETED}
  JOB_STATUS_DELETED                  = $00000100;
  {$EXTERNALSYM JOB_STATUS_BLOCKED_DEVQ}
  JOB_STATUS_BLOCKED_DEVQ             = $00000200;
  {$EXTERNALSYM JOB_STATUS_USER_INTERVENTION}
  JOB_STATUS_USER_INTERVENTION        = $00000400;
  {$EXTERNALSYM JOB_STATUS_RESTART}
  JOB_STATUS_RESTART                  = $00000800;

  {$EXTERNALSYM JOB_POSITION_UNSPECIFIED}
  JOB_POSITION_UNSPECIFIED       = 0;

type
  PAddJobInfo1A = ^TAddJobInfo1A;
  PAddJobInfo1W = ^TAddJobInfo1W;
  PAddJobInfo1 = PAddJobInfo1A;
  {$EXTERNALSYM _ADDJOB_INFO_1A}
  _ADDJOB_INFO_1A = record
    Path: PAnsiChar;
    JobId: DWORD;
  end;
  {$EXTERNALSYM _ADDJOB_INFO_1W}
  _ADDJOB_INFO_1W = record
    Path: PWideChar;
    JobId: DWORD;
  end;
  {$EXTERNALSYM _ADDJOB_INFO_1}
  _ADDJOB_INFO_1 = _ADDJOB_INFO_1A;
  TAddJobInfo1A = _ADDJOB_INFO_1A;
  TAddJobInfo1W = _ADDJOB_INFO_1W;
  TAddJobInfo1 = TAddJobInfo1A;
  {$EXTERNALSYM ADDJOB_INFO_1A}
  ADDJOB_INFO_1A = _ADDJOB_INFO_1A;
  {$EXTERNALSYM ADDJOB_INFO_1W}
  ADDJOB_INFO_1W = _ADDJOB_INFO_1W;
  {$EXTERNALSYM ADDJOB_INFO_1}
  ADDJOB_INFO_1 = ADDJOB_INFO_1A;

  PDriverInfo1A = ^TDriverInfo1A;
  PDriverInfo1W = ^TDriverInfo1W;
  PDriverInfo1 = PDriverInfo1A;
  {$EXTERNALSYM _DRIVER_INFO_1A}
  _DRIVER_INFO_1A = record
    pName: PAnsiChar;              { QMS 810 }
  end;
  {$EXTERNALSYM _DRIVER_INFO_1W}
  _DRIVER_INFO_1W = record
    pName: PWideChar;              { QMS 810 }
  end;
  {$EXTERNALSYM _DRIVER_INFO_1}
  _DRIVER_INFO_1 = _DRIVER_INFO_1A;
  TDriverInfo1A = _DRIVER_INFO_1A;
  TDriverInfo1W = _DRIVER_INFO_1W;
  TDriverInfo1 = TDriverInfo1A;
  {$EXTERNALSYM DRIVER_INFO_1A}
  DRIVER_INFO_1A = _DRIVER_INFO_1A;
  {$EXTERNALSYM DRIVER_INFO_1W}
  DRIVER_INFO_1W = _DRIVER_INFO_1W;
  {$EXTERNALSYM DRIVER_INFO_1}
  DRIVER_INFO_1 = DRIVER_INFO_1A;

  PDriverInfo2A = ^TDriverInfo2A;
  PDriverInfo2W = ^TDriverInfo2W;
  PDriverInfo2 = PDriverInfo2A;
  {$EXTERNALSYM _DRIVER_INFO_2A}
  _DRIVER_INFO_2A = record
    cVersion: DWORD;
    pName: PAnsiChar;              { QMS 810 }
    pEnvironment: PAnsiChar;       { Win32 x86 }
    pDriverPath: PAnsiChar;        { c:\drivers\pscript.dll }
    pDataFile: PAnsiChar;          { c:\drivers\QMS810.PPD }
    pConfigFile: PAnsiChar;        { c:\drivers\PSCRPTUI.DLL }
  end;
  {$EXTERNALSYM _DRIVER_INFO_2W}
  _DRIVER_INFO_2W = record
    cVersion: DWORD;
    pName: PWideChar;              { QMS 810 }
    pEnvironment: PWideChar;       { Win32 x86 }
    pDriverPath: PWideChar;        { c:\drivers\pscript.dll }
    pDataFile: PWideChar;          { c:\drivers\QMS810.PPD }
    pConfigFile: PWideChar;        { c:\drivers\PSCRPTUI.DLL }
  end;
  {$EXTERNALSYM _DRIVER_INFO_2}
  _DRIVER_INFO_2 = _DRIVER_INFO_2A;
  TDriverInfo2A = _DRIVER_INFO_2A;
  TDriverInfo2W = _DRIVER_INFO_2W;
  TDriverInfo2 = TDriverInfo2A;
  {$EXTERNALSYM DRIVER_INFO_2A}
  DRIVER_INFO_2A = _DRIVER_INFO_2A;
  {$EXTERNALSYM DRIVER_INFO_2W}
  DRIVER_INFO_2W = _DRIVER_INFO_2W;
  {$EXTERNALSYM DRIVER_INFO_2}
  DRIVER_INFO_2 = DRIVER_INFO_2A;

  PDriverInfo3A = ^TDriverInfo3A;
  PDriverInfo3W = ^TDriverInfo3W;
  PDriverInfo3 = PDriverInfo3A;
  {$EXTERNALSYM _DRIVER_INFO_3A}
  _DRIVER_INFO_3A = record
    cVersion: DWORD;
    pName: PAnsiChar;                    { QMS 810 }
    pEnvironment: PAnsiChar;             { Win32 x86 }
    pDriverPath: PAnsiChar;              { c:\drivers\pscript.dll }
    pDataFile: PAnsiChar;                { c:\drivers\QMS810.PPD }
    pConfigFile: PAnsiChar;              { c:\drivers\PSCRPTUI.DLL }
    pHelpFile: PAnsiChar;                { c:\drivers\PSCRPTUI.HLP }
    pDependentFiles: PAnsiChar;          { PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0 }
    pMonitorName: PAnsiChar;             { "PJL monitor" }
    pDefaultDataType: PAnsiChar;         { "EMF" }
  end;
  {$EXTERNALSYM _DRIVER_INFO_3W}
  _DRIVER_INFO_3W = record
    cVersion: DWORD;
    pName: PWideChar;                    { QMS 810 }
    pEnvironment: PWideChar;             { Win32 x86 }
    pDriverPath: PWideChar;              { c:\drivers\pscript.dll }
    pDataFile: PWideChar;                { c:\drivers\QMS810.PPD }
    pConfigFile: PWideChar;              { c:\drivers\PSCRPTUI.DLL }
    pHelpFile: PWideChar;                { c:\drivers\PSCRPTUI.HLP }
    pDependentFiles: PWideChar;          { PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0 }
    pMonitorName: PWideChar;             { "PJL monitor" }
    pDefaultDataType: PWideChar;         { "EMF" }
  end;
  {$EXTERNALSYM _DRIVER_INFO_3}
  _DRIVER_INFO_3 = _DRIVER_INFO_3A;
  TDriverInfo3A = _DRIVER_INFO_3A;
  TDriverInfo3W = _DRIVER_INFO_3W;
  TDriverInfo3 = TDriverInfo3A;
  {$EXTERNALSYM DRIVER_INFO_3A}
  DRIVER_INFO_3A = _DRIVER_INFO_3A;
  {$EXTERNALSYM DRIVER_INFO_3W}
  DRIVER_INFO_3W = _DRIVER_INFO_3W;
  {$EXTERNALSYM DRIVER_INFO_3}
  DRIVER_INFO_3 = DRIVER_INFO_3A;

  PDocInfo1A = ^TDocInfo1A;
  PDocInfo1W = ^TDocInfo1W;
  PDocInfo1 = PDocInfo1A;
  {$EXTERNALSYM _DOC_INFO_1A}
  _DOC_INFO_1A = record
    pDocName: PAnsiChar;
    pOutputFile: PAnsiChar;
    pDatatype: PAnsiChar;
  end;
  {$EXTERNALSYM _DOC_INFO_1W}
  _DOC_INFO_1W = record
    pDocName: PWideChar;
    pOutputFile: PWideChar;
    pDatatype: PWideChar;
  end;
  {$EXTERNALSYM _DOC_INFO_1}
  _DOC_INFO_1 = _DOC_INFO_1A;
  TDocInfo1A = _DOC_INFO_1A;
  TDocInfo1W = _DOC_INFO_1W;
  TDocInfo1 = TDocInfo1A;
  {$EXTERNALSYM DOC_INFO_1A}
  DOC_INFO_1A = _DOC_INFO_1A;
  {$EXTERNALSYM DOC_INFO_1W}
  DOC_INFO_1W = _DOC_INFO_1W;
  {$EXTERNALSYM DOC_INFO_1}
  DOC_INFO_1 = DOC_INFO_1A;

  PFormInfo1A = ^TFormInfo1A;
  PFormInfo1W = ^TFormInfo1W;
  PFormInfo1 = PFormInfo1A;
  {$EXTERNALSYM _FORM_INFO_1A}
  _FORM_INFO_1A = record
    Flags: DWORD;
    pName: PAnsiChar;
    Size: TSize;
    ImageableArea: TRect;
  end;
  {$EXTERNALSYM _FORM_INFO_1W}
  _FORM_INFO_1W = record
    Flags: DWORD;
    pName: PWideChar;
    Size: TSize;
    ImageableArea: TRect;
  end;
  {$EXTERNALSYM _FORM_INFO_1}
  _FORM_INFO_1 = _FORM_INFO_1A;
  TFormInfo1A = _FORM_INFO_1A;
  TFormInfo1W = _FORM_INFO_1W;
  TFormInfo1 = TFormInfo1A;
  {$EXTERNALSYM FORM_INFO_1A}
  FORM_INFO_1A = _FORM_INFO_1A;
  {$EXTERNALSYM FORM_INFO_1W}
  FORM_INFO_1W = _FORM_INFO_1W;
  {$EXTERNALSYM FORM_INFO_1}
  FORM_INFO_1 = FORM_INFO_1A;

  PDocInfo2A = ^TDocInfo2A;
  PDocInfo2W = ^TDocInfo2W;
  PDocInfo2 = PDocInfo2A;
  {$EXTERNALSYM _DOC_INFO_2A}
  _DOC_INFO_2A = record
    pDocName: PAnsiChar;
    pOutputFile: PAnsiChar;
    pDatatype: PAnsiChar;
    dwMode: DWORD;
    JobId: DWORD;
  end;
  {$EXTERNALSYM _DOC_INFO_2W}
  _DOC_INFO_2W = record
    pDocName: PWideChar;
    pOutputFile: PWideChar;
    pDatatype: PWideChar;
    dwMode: DWORD;
    JobId: DWORD;
  end;
  {$EXTERNALSYM _DOC_INFO_2}
  _DOC_INFO_2 = _DOC_INFO_2A;
  TDocInfo2A = _DOC_INFO_2A;
  TDocInfo2W = _DOC_INFO_2W;
  TDocInfo2 = TDocInfo2A;
  {$EXTERNALSYM DOC_INFO_2A}
  DOC_INFO_2A = _DOC_INFO_2A;
  {$EXTERNALSYM DOC_INFO_2W}
  DOC_INFO_2W = _DOC_INFO_2W;
  {$EXTERNALSYM DOC_INFO_2}
  DOC_INFO_2 = DOC_INFO_2A;

const
  {$EXTERNALSYM DI_CHANNEL}
  DI_CHANNEL              = 1;    { start direct read/write channel, }
  {$EXTERNALSYM DI_READ_SPOOL_JOB}
  DI_READ_SPOOL_JOB       = 3;

  {$EXTERNALSYM FORM_USER}
  FORM_USER           = $00000000;
  {$EXTERNALSYM FORM_BUILTIN}
  FORM_BUILTIN        = $00000001;
  {$EXTERNALSYM FORM_PRINTER}
  FORM_PRINTER        = $00000002;

type
  PPrintProcessorInfo1A = ^TPrintProcessorInfo1A;
  PPrintProcessorInfo1W = ^TPrintProcessorInfo1W;
  PPrintProcessorInfo1 = PPrintProcessorInfo1A;
  {$EXTERNALSYM _PRINTPROCESSOR_INFO_1A}
  _PRINTPROCESSOR_INFO_1A = record
    pName: PAnsiChar;
  end;
  {$EXTERNALSYM _PRINTPROCESSOR_INFO_1W}
  _PRINTPROCESSOR_INFO_1W = record
    pName: PWideChar;
  end;
  {$EXTERNALSYM _PRINTPROCESSOR_INFO_1}
  _PRINTPROCESSOR_INFO_1 = _PRINTPROCESSOR_INFO_1A;
  TPrintProcessorInfo1A = _PRINTPROCESSOR_INFO_1A;
  TPrintProcessorInfo1W = _PRINTPROCESSOR_INFO_1W;
  TPrintProcessorInfo1 = TPrintProcessorInfo1A;
  {$EXTERNALSYM PRINTPROCESSOR_INFO_1A}
  PRINTPROCESSOR_INFO_1A = _PRINTPROCESSOR_INFO_1A;
  {$EXTERNALSYM PRINTPROCESSOR_INFO_1W}
  PRINTPROCESSOR_INFO_1W = _PRINTPROCESSOR_INFO_1W;
  {$EXTERNALSYM PRINTPROCESSOR_INFO_1}
  PRINTPROCESSOR_INFO_1 = PRINTPROCESSOR_INFO_1A;

  PPortInfo1A = ^TPortInfo1A;
  PPortInfo1W = ^TPortInfo1W;
  PPortInfo1 = PPortInfo1A;
  {$EXTERNALSYM _PORT_INFO_1A}
  _PORT_INFO_1A = record
    pName: PAnsiChar;
  end;
  {$EXTERNALSYM _PORT_INFO_1W}
  _PORT_INFO_1W = record
    pName: PWideChar;
  end;
  {$EXTERNALSYM _PORT_INFO_1}
  _PORT_INFO_1 = _PORT_INFO_1A;
  TPortInfo1A = _PORT_INFO_1A;
  TPortInfo1W = _PORT_INFO_1W;
  TPortInfo1 = TPortInfo1A;
  {$EXTERNALSYM PORT_INFO_1A}
  PORT_INFO_1A = _PORT_INFO_1A;
  {$EXTERNALSYM PORT_INFO_1W}
  PORT_INFO_1W = _PORT_INFO_1W;
  {$EXTERNALSYM PORT_INFO_1}
  PORT_INFO_1 = PORT_INFO_1A;

  PPortInfo2A = ^TPortInfo2A;
  PPortInfo2W = ^TPortInfo2W;
  PPortInfo2 = PPortInfo2A;
  {$EXTERNALSYM _PORT_INFO_2A}
  _PORT_INFO_2A = record
    pPortName: PAnsiChar;
    pMonitorName: PAnsiChar;
    pDescription: PAnsiChar;
    fPortType: DWORD;
    Reserved: DWORD;
  end;
  {$EXTERNALSYM _PORT_INFO_2W}
  _PORT_INFO_2W = record
    pPortName: PWideChar;
    pMonitorName: PWideChar;
    pDescription: PWideChar;
    fPortType: DWORD;
    Reserved: DWORD;
  end;
  {$EXTERNALSYM _PORT_INFO_2}
  _PORT_INFO_2 = _PORT_INFO_2A;
  TPortInfo2A = _PORT_INFO_2A;
  TPortInfo2W = _PORT_INFO_2W;
  TPortInfo2 = TPortInfo2A;
  {$EXTERNALSYM PORT_INFO_2A}
  PORT_INFO_2A = _PORT_INFO_2A;
  {$EXTERNALSYM PORT_INFO_2W}
  PORT_INFO_2W = _PORT_INFO_2W;
  {$EXTERNALSYM PORT_INFO_2}
  PORT_INFO_2 = PORT_INFO_2A;

const
  {$EXTERNALSYM PORT_TYPE_WRITE}
  PORT_TYPE_WRITE         = $0001;
  {$EXTERNALSYM PORT_TYPE_READ}
  PORT_TYPE_READ          = $0002;
  {$EXTERNALSYM PORT_TYPE_REDIRECTED}
  PORT_TYPE_REDIRECTED    = $0004;
  {$EXTERNALSYM PORT_TYPE_NET_ATTACHED}
  PORT_TYPE_NET_ATTACHED  = $0008;

type
  PPortInfo3A = ^TPortInfo3A;
  PPortInfo3W = ^TPortInfo3W;
  PPortInfo3 = PPortInfo3A;
  {$EXTERNALSYM _PORT_INFO_3A}
  _PORT_INFO_3A = record
    dwStatus: DWORD;
    pszStatus: PAnsiChar;
    dwSeverity: DWORD;
  end;
  {$EXTERNALSYM _PORT_INFO_3W}
  _PORT_INFO_3W = record
    dwStatus: DWORD;
    pszStatus: PWideChar;
    dwSeverity: DWORD;
  end;
  {$EXTERNALSYM _PORT_INFO_3}
  _PORT_INFO_3 = _PORT_INFO_3A;
  TPortInfo3A = _PORT_INFO_3A;
  TPortInfo3W = _PORT_INFO_3W;
  TPortInfo3 = TPortInfo3A;
  {$EXTERNALSYM PORT_INFO_3A}
  PORT_INFO_3A = _PORT_INFO_3A;
  {$EXTERNALSYM PORT_INFO_3W}
  PORT_INFO_3W = _PORT_INFO_3W;
  {$EXTERNALSYM PORT_INFO_3}
  PORT_INFO_3 = PORT_INFO_3A;

const
  {$EXTERNALSYM PORT_STATUS_TYPE_ERROR}
  PORT_STATUS_TYPE_ERROR          = 1;
  {$EXTERNALSYM PORT_STATUS_TYPE_WARNING}
  PORT_STATUS_TYPE_WARNING        = 2;
  {$EXTERNALSYM PORT_STATUS_TYPE_INFO}
  PORT_STATUS_TYPE_INFO           = 3;

  {$EXTERNALSYM PORT_STATUS_OFFLINE}
  PORT_STATUS_OFFLINE             = 1;
  {$EXTERNALSYM PORT_STATUS_PAPER_JAM}
  PORT_STATUS_PAPER_JAM           = 2;
  {$EXTERNALSYM PORT_STATUS_PAPER_OUT}
  PORT_STATUS_PAPER_OUT           = 3;
  {$EXTERNALSYM PORT_STATUS_OUTPUT_BIN_FULL}
  PORT_STATUS_OUTPUT_BIN_FULL     = 4;
  {$EXTERNALSYM PORT_STATUS_PAPER_PROBLEM}
  PORT_STATUS_PAPER_PROBLEM       = 5;
  {$EXTERNALSYM PORT_STATUS_NO_TONER}
  PORT_STATUS_NO_TONER            = 6;
  {$EXTERNALSYM PORT_STATUS_DOOR_OPEN}
  PORT_STATUS_DOOR_OPEN           = 7;
  {$EXTERNALSYM PORT_STATUS_USER_INTERVENTION}
  PORT_STATUS_USER_INTERVENTION   = 8;
  {$EXTERNALSYM PORT_STATUS_OUT_OF_MEMORY}
  PORT_STATUS_OUT_OF_MEMORY       = 9;

  {$EXTERNALSYM PORT_STATUS_TONER_LOW}
  PORT_STATUS_TONER_LOW           = 10;

  {$EXTERNALSYM PORT_STATUS_WARMING_UP}
  PORT_STATUS_WARMING_UP          = 11;
  {$EXTERNALSYM PORT_STATUS_POWER_SAVE}
  PORT_STATUS_POWER_SAVE          = 12;

type
  PMonitorInfo1A = ^TMonitorInfo1A;
  PMonitorInfo1W = ^TMonitorInfo1W;
  PMonitorInfo1 = PMonitorInfo1A;
  {$EXTERNALSYM _MONITOR_INFO_1A}
  _MONITOR_INFO_1A = record
    pName: PAnsiChar;
  end;
  {$EXTERNALSYM _MONITOR_INFO_1W}
  _MONITOR_INFO_1W = record
    pName: PWideChar;
  end;
  {$EXTERNALSYM _MONITOR_INFO_1}
  _MONITOR_INFO_1 = _MONITOR_INFO_1A;
  TMonitorInfo1A = _MONITOR_INFO_1A;
  TMonitorInfo1W = _MONITOR_INFO_1W;
  TMonitorInfo1 = TMonitorInfo1A;
  {$EXTERNALSYM MONITOR_INFO_1A}
  MONITOR_INFO_1A = _MONITOR_INFO_1A;
  {$EXTERNALSYM MONITOR_INFO_1W}
  MONITOR_INFO_1W = _MONITOR_INFO_1W;
  {$EXTERNALSYM MONITOR_INFO_1}
  MONITOR_INFO_1 = MONITOR_INFO_1A;

  PMonitorInfo2A = ^TMonitorInfo2A;
  PMonitorInfo2W = ^TMonitorInfo2W;
  PMonitorInfo2 = PMonitorInfo2A;
  {$EXTERNALSYM _MONITOR_INFO_2A}
  _MONITOR_INFO_2A = record
    pName: PAnsiChar;
    pEnvironment: PAnsiChar;
    pDLLName: PAnsiChar;
  end;
  {$EXTERNALSYM _MONITOR_INFO_2W}
  _MONITOR_INFO_2W = record
    pName: PWideChar;
    pEnvironment: PWideChar;
    pDLLName: PWideChar;
  end;
  {$EXTERNALSYM _MONITOR_INFO_2}
  _MONITOR_INFO_2 = _MONITOR_INFO_2A;
  TMonitorInfo2A = _MONITOR_INFO_2A;
  TMonitorInfo2W = _MONITOR_INFO_2W;
  TMonitorInfo2 = TMonitorInfo2A;
  {$EXTERNALSYM MONITOR_INFO_2A}
  MONITOR_INFO_2A = _MONITOR_INFO_2A;
  {$EXTERNALSYM MONITOR_INFO_2W}
  MONITOR_INFO_2W = _MONITOR_INFO_2W;
  {$EXTERNALSYM MONITOR_INFO_2}
  MONITOR_INFO_2 = MONITOR_INFO_2A;

  PDatatypesInfo1A = ^TDatatypesInfo1A;
  PDatatypesInfo1W = ^TDatatypesInfo1W;
  PDatatypesInfo1 = PDatatypesInfo1A;
  {$EXTERNALSYM _DATATYPES_INFO_1A}
  _DATATYPES_INFO_1A = record
    pName: PAnsiChar;
  end;
  {$EXTERNALSYM _DATATYPES_INFO_1W}
  _DATATYPES_INFO_1W = record
    pName: PWideChar;
  end;
  {$EXTERNALSYM _DATATYPES_INFO_1}
  _DATATYPES_INFO_1 = _DATATYPES_INFO_1A;
  TDatatypesInfo1A = _DATATYPES_INFO_1A;
  TDatatypesInfo1W = _DATATYPES_INFO_1W;
  TDatatypesInfo1 = TDatatypesInfo1A;
  {$EXTERNALSYM DATATYPES_INFO_1A}
  DATATYPES_INFO_1A = _DATATYPES_INFO_1A;
  {$EXTERNALSYM DATATYPES_INFO_1W}
  DATATYPES_INFO_1W = _DATATYPES_INFO_1W;
  {$EXTERNALSYM DATATYPES_INFO_1}
  DATATYPES_INFO_1 = DATATYPES_INFO_1A;

  PPrinterDefaultsA = ^TPrinterDefaultsA;
  PPrinterDefaultsW = ^TPrinterDefaultsW;
  PPrinterDefaults = PPrinterDefaultsA;
  {$EXTERNALSYM _PRINTER_DEFAULTSA}
  _PRINTER_DEFAULTSA = record
    pDatatype: PAnsiChar;
    pDevMode: PDeviceModeA;
    DesiredAccess: ACCESS_MASK;
  end;
  {$EXTERNALSYM _PRINTER_DEFAULTSW}
  _PRINTER_DEFAULTSW = record
    pDatatype: PWideChar;
    pDevMode: PDeviceModeW;
    DesiredAccess: ACCESS_MASK;
  end;
  {$EXTERNALSYM _PRINTER_DEFAULTS}
  _PRINTER_DEFAULTS = _PRINTER_DEFAULTSA;
  TPrinterDefaultsA = _PRINTER_DEFAULTSA;
  TPrinterDefaultsW = _PRINTER_DEFAULTSW;
  TPrinterDefaults = TPrinterDefaultsA;
  {$EXTERNALSYM PRINTER_DEFAULTSA}
  PRINTER_DEFAULTSA = _PRINTER_DEFAULTSA;
  {$EXTERNALSYM PRINTER_DEFAULTSW}
  PRINTER_DEFAULTSW = _PRINTER_DEFAULTSW;
  {$EXTERNALSYM PRINTER_DEFAULTS}
  PRINTER_DEFAULTS = PRINTER_DEFAULTSA;

{$EXTERNALSYM EnumPrintersA}
function EnumPrintersA(Flags: DWORD; Name: PAnsiChar; Level: DWORD;
  pPrinterEnum: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrintersW}
function EnumPrintersW(Flags: DWORD; Name: PWideChar; Level: DWORD;
  pPrinterEnum: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrinters}
function EnumPrinters(Flags: DWORD; Name: PChar; Level: DWORD;
  pPrinterEnum: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;

const
  {$EXTERNALSYM PRINTER_ENUM_DEFAULT}
  PRINTER_ENUM_DEFAULT     = $00000001;
  {$EXTERNALSYM PRINTER_ENUM_LOCAL}
  PRINTER_ENUM_LOCAL       = $00000002;
  {$EXTERNALSYM PRINTER_ENUM_CONNECTIONS}
  PRINTER_ENUM_CONNECTIONS = $00000004;
  {$EXTERNALSYM PRINTER_ENUM_FAVORITE}
  PRINTER_ENUM_FAVORITE    = $00000004;
  {$EXTERNALSYM PRINTER_ENUM_NAME}
  PRINTER_ENUM_NAME        = $00000008;
  {$EXTERNALSYM PRINTER_ENUM_REMOTE}
  PRINTER_ENUM_REMOTE      = $00000010;
  {$EXTERNALSYM PRINTER_ENUM_SHARED}
  PRINTER_ENUM_SHARED      = $00000020;
  {$EXTERNALSYM PRINTER_ENUM_NETWORK}
  PRINTER_ENUM_NETWORK     = $00000040;

  {$EXTERNALSYM PRINTER_ENUM_EXPAND}
  PRINTER_ENUM_EXPAND      = $00004000;
  {$EXTERNALSYM PRINTER_ENUM_CONTAINER}
  PRINTER_ENUM_CONTAINER   = $00008000;

  {$EXTERNALSYM PRINTER_ENUM_ICONMASK}
  PRINTER_ENUM_ICONMASK    = $00ff0000;
  {$EXTERNALSYM PRINTER_ENUM_ICON1}
  PRINTER_ENUM_ICON1       = $00010000;
  {$EXTERNALSYM PRINTER_ENUM_ICON2}
  PRINTER_ENUM_ICON2       = $00020000;
  {$EXTERNALSYM PRINTER_ENUM_ICON3}
  PRINTER_ENUM_ICON3       = $00040000;
  {$EXTERNALSYM PRINTER_ENUM_ICON4}
  PRINTER_ENUM_ICON4       = $00080000;
  {$EXTERNALSYM PRINTER_ENUM_ICON5}
  PRINTER_ENUM_ICON5       = $00100000;
  {$EXTERNALSYM PRINTER_ENUM_ICON6}
  PRINTER_ENUM_ICON6       = $00200000;
  {$EXTERNALSYM PRINTER_ENUM_ICON7}
  PRINTER_ENUM_ICON7       = $00400000;
  {$EXTERNALSYM PRINTER_ENUM_ICON8}
  PRINTER_ENUM_ICON8       = $00800000;

{$EXTERNALSYM OpenPrinterA}
function OpenPrinterA(pPrinterName: PAnsiChar; var phPrinter: THandle; pDefault: PPrinterDefaultsA): BOOL; stdcall;
{$EXTERNALSYM OpenPrinterW}
function OpenPrinterW(pPrinterName: PWideChar; var phPrinter: THandle; pDefault: PPrinterDefaultsW): BOOL; stdcall;
{$EXTERNALSYM OpenPrinter}
function OpenPrinter(pPrinterName: PChar; var phPrinter: THandle; pDefault: PPrinterDefaults): BOOL; stdcall;
{$EXTERNALSYM ResetPrinterA}
function ResetPrinterA(hPrinter: THandle; pDefault: PPrinterDefaultsA): BOOL; stdcall;
{$EXTERNALSYM ResetPrinterW}
function ResetPrinterW(hPrinter: THandle; pDefault: PPrinterDefaultsW): BOOL; stdcall;
{$EXTERNALSYM ResetPrinter}
function ResetPrinter(hPrinter: THandle; pDefault: PPrinterDefaults): BOOL; stdcall;
{$EXTERNALSYM SetJobA}
function SetJobA(hPrinter: THandle; JobId: DWORD; Level: DWORD; pJob: Pointer; Command: DWORD): BOOL; stdcall;
{$EXTERNALSYM SetJobW}
function SetJobW(hPrinter: THandle; JobId: DWORD; Level: DWORD; pJob: Pointer; Command: DWORD): BOOL; stdcall;
{$EXTERNALSYM SetJob}
function SetJob(hPrinter: THandle; JobId: DWORD; Level: DWORD; pJob: Pointer; Command: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetJobA}
function GetJobA(hPrinter: THandle; JobId: DWORD; Level: DWORD; pJob: Pointer; cbBuf: DWORD; pcbNeeded: PDWORD): BOOL; stdcall;
{$EXTERNALSYM GetJobW}
function GetJobW(hPrinter: THandle; JobId: DWORD; Level: DWORD; pJob: Pointer; cbBuf: DWORD; pcbNeeded: PDWORD): BOOL; stdcall;
{$EXTERNALSYM GetJob}
function GetJob(hPrinter: THandle; JobId: DWORD; Level: DWORD; pJob: Pointer; cbBuf: DWORD; pcbNeeded: PDWORD): BOOL; stdcall;
{$EXTERNALSYM EnumJobsA}
function EnumJobsA(hPrinter: THandle; FirstJob, NoJobs, Level: DWORD; pJob: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumJobsW}
function EnumJobsW(hPrinter: THandle; FirstJob, NoJobs, Level: DWORD; pJob: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumJobs}
function EnumJobs(hPrinter: THandle; FirstJob, NoJobs, Level: DWORD; pJob: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM AddPrinterA}
function AddPrinterA(pName: PAnsiChar; Level: DWORD; pPrinter: Pointer): THandle; stdcall;
{$EXTERNALSYM AddPrinterW}
function AddPrinterW(pName: PWideChar; Level: DWORD; pPrinter: Pointer): THandle; stdcall;
{$EXTERNALSYM AddPrinter}
function AddPrinter(pName: PChar; Level: DWORD; pPrinter: Pointer): THandle; stdcall;
{$EXTERNALSYM DeletePrinter}
function DeletePrinter(hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM SetPrinterA}
function SetPrinterA(hPrinter: THandle; Level: DWORD; pPrinter: Pointer; Command: DWORD): BOOL; stdcall;
{$EXTERNALSYM SetPrinterW}
function SetPrinterW(hPrinter: THandle; Level: DWORD; pPrinter: Pointer; Command: DWORD): BOOL; stdcall;
{$EXTERNALSYM SetPrinter}
function SetPrinter(hPrinter: THandle; Level: DWORD; pPrinter: Pointer; Command: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterA}
function GetPrinterA(hPrinter: THandle; Level: DWORD; pPrinter: Pointer; cbBuf: DWORD; pcbNeeded: PDWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterW}
function GetPrinterW(hPrinter: THandle; Level: DWORD; pPrinter: Pointer; cbBuf: DWORD; pcbNeeded: PDWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinter}
function GetPrinter(hPrinter: THandle; Level: DWORD; pPrinter: Pointer; cbBuf: DWORD; pcbNeeded: PDWORD): BOOL; stdcall;
{$EXTERNALSYM AddPrinterDriverA}
function AddPrinterDriverA(pName: PAnsiChar; Level: DWORD; pDriverInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddPrinterDriverW}
function AddPrinterDriverW(pName: PWideChar; Level: DWORD; pDriverInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddPrinterDriver}
function AddPrinterDriver(pName: PChar; Level: DWORD; pDriverInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM EnumPrinterDriversA}
function EnumPrinterDriversA(pName, pEnvironment: PAnsiChar; Level: DWORD;
  pDriverInfo: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrinterDriversW}
function EnumPrinterDriversW(pName, pEnvironment: PWideChar; Level: DWORD;
  pDriverInfo: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrinterDrivers}
function EnumPrinterDrivers(pName, pEnvironment: PChar; Level: DWORD;
  pDriverInfo: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterDriverA}
function GetPrinterDriverA(hPrinter: THandle; pEnvironment: PAnsiChar; Level: DWORD;
  pDriverInfo: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterDriverW}
function GetPrinterDriverW(hPrinter: THandle; pEnvironment: PWideChar; Level: DWORD;
  pDriverInfo: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterDriver}
function GetPrinterDriver(hPrinter: THandle; pEnvironment: PChar; Level: DWORD;
  pDriverInfo: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterDriverDirectoryA}
function GetPrinterDriverDirectoryA(pName, pEnvironment: PAnsiChar; Level: DWORD;
  pDriverDirectory: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterDriverDirectoryW}
function GetPrinterDriverDirectoryW(pName, pEnvironment: PWideChar; Level: DWORD;
  pDriverDirectory: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrinterDriverDirectory}
function GetPrinterDriverDirectory(pName, pEnvironment: PChar; Level: DWORD;
  pDriverDirectory: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM DeletePrinterDriverA}
function DeletePrinterDriverA(pName, pEnvironment, pDriverName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrinterDriverW}
function DeletePrinterDriverW(pName, pEnvironment, pDriverName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrinterDriver}
function DeletePrinterDriver(pName, pEnvironment, pDriverName: PChar): BOOL; stdcall;
{$EXTERNALSYM AddPrintProcessorA}
function AddPrintProcessorA(pName, pEnvironment, pPathName, pPrintProcessorName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM AddPrintProcessorW}
function AddPrintProcessorW(pName, pEnvironment, pPathName, pPrintProcessorName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM AddPrintProcessor}
function AddPrintProcessor(pName, pEnvironment, pPathName, pPrintProcessorName: PChar): BOOL; stdcall;
{$EXTERNALSYM EnumPrintProcessorsA}
function EnumPrintProcessorsA(pName, pEnvironment: PAnsiChar; Level: DWORD; pPrintProcessorInfo: Pointer;
  cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrintProcessorsW}
function EnumPrintProcessorsW(pName, pEnvironment: PWideChar; Level: DWORD; pPrintProcessorInfo: Pointer;
  cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrintProcessors}
function EnumPrintProcessors(pName, pEnvironment: PChar; Level: DWORD; pPrintProcessorInfo: Pointer;
  cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrintProcessorDirectoryA}
function GetPrintProcessorDirectoryA(pName, pEnvironment: PAnsiChar; Level: DWORD;
  pPrintProcessorInfo: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrintProcessorDirectoryW}
function GetPrintProcessorDirectoryW(pName, pEnvironment: PWideChar; Level: DWORD;
  pPrintProcessorInfo: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetPrintProcessorDirectory}
function GetPrintProcessorDirectory(pName, pEnvironment: PChar; Level: DWORD;
  pPrintProcessorInfo: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrintProcessorDatatypesA}
function EnumPrintProcessorDatatypesA(pName, pPrintProcessorName: PAnsiChar; Level: DWORD;
  pDatatypes: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrintProcessorDatatypesW}
function EnumPrintProcessorDatatypesW(pName, pPrintProcessorName: PWideChar; Level: DWORD;
  pDatatypes: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPrintProcessorDatatypes}
function EnumPrintProcessorDatatypes(pName, pPrintProcessorName: PChar; Level: DWORD;
  pDatatypes: Pointer; cbBuf: DWORD; var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM DeletePrintProcessorA}
function DeletePrintProcessorA(pName, pEnvironment, pPrintProcessorName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrintProcessorW}
function DeletePrintProcessorW(pName, pEnvironment, pPrintProcessorName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrintProcessor}
function DeletePrintProcessor(pName, pEnvironment, pPrintProcessorName: PChar): BOOL; stdcall;
{$EXTERNALSYM StartDocPrinterA}
function StartDocPrinterA(hPrinter: THandle; Level: DWORD; pDocInfo: Pointer): DWORD; stdcall;
{$EXTERNALSYM StartDocPrinterW}
function StartDocPrinterW(hPrinter: THandle; Level: DWORD; pDocInfo: Pointer): DWORD; stdcall;
{$EXTERNALSYM StartDocPrinter}
function StartDocPrinter(hPrinter: THandle; Level: DWORD; pDocInfo: Pointer): DWORD; stdcall;
{$EXTERNALSYM StartPagePrinter}
function StartPagePrinter(hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM WritePrinter}
function WritePrinter(hPrinter: THandle; pBuf: Pointer; cbBuf: DWORD; var pcWritten: DWORD): BOOL; stdcall;
{$EXTERNALSYM EndPagePrinter}
function EndPagePrinter(hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM AbortPrinter}
function AbortPrinter(hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM ReadPrinter}
function ReadPrinter(hPrinter: THandle; pBuf: Pointer; cbBuf: DWORD; var pNoBytesRead: DWORD): BOOL; stdcall;
{$EXTERNALSYM EndDocPrinter}
function EndDocPrinter(hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM AddJobA}
function AddJobA(hPrinter: THandle; Level: DWORD; pData: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM AddJobW}
function AddJobW(hPrinter: THandle; Level: DWORD; pData: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM AddJob}
function AddJob(hPrinter: THandle; Level: DWORD; pData: Pointer; cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM ScheduleJob}
function ScheduleJob(hPrinter: THandle; JobId: DWORD): BOOL; stdcall;
{$EXTERNALSYM PrinterProperties}
function PrinterProperties(hWnd: HWND; hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM DocumentPropertiesA}
function DocumentPropertiesA(hWnd: HWND; hPrinter: THandle; pDeviceName: PAnsiChar;
  const pDevModeOutput: TDeviceModeA; var pDevModeInput: TDeviceModeA;
  fMode: DWORD): Longint; stdcall;
{$EXTERNALSYM DocumentPropertiesW}
function DocumentPropertiesW(hWnd: HWND; hPrinter: THandle; pDeviceName: PWideChar;
  const pDevModeOutput: TDeviceModeW; var pDevModeInput: TDeviceModeW;
  fMode: DWORD): Longint; stdcall;
{$EXTERNALSYM DocumentProperties}
function DocumentProperties(hWnd: HWND; hPrinter: THandle; pDeviceName: PChar;
  const pDevModeOutput: TDeviceMode; var pDevModeInput: TDeviceMode;
  fMode: DWORD): Longint; stdcall;
{$EXTERNALSYM AdvancedDocumentPropertiesA}
function AdvancedDocumentPropertiesA(hWnd: HWND; hPrinter: THandle; pDeviceName: PAnsiChar;
  pDevModeOutput, pDevModeInput: PDeviceModeA): Longint; stdcall;
{$EXTERNALSYM AdvancedDocumentPropertiesW}
function AdvancedDocumentPropertiesW(hWnd: HWND; hPrinter: THandle; pDeviceName: PWideChar;
  pDevModeOutput, pDevModeInput: PDeviceModeW): Longint; stdcall;
{$EXTERNALSYM AdvancedDocumentProperties}
function AdvancedDocumentProperties(hWnd: HWND; hPrinter: THandle; pDeviceName: PChar;
  pDevModeOutput, pDevModeInput: PDeviceMode): Longint; stdcall;
{$EXTERNALSYM GetPrinterDataA}
function GetPrinterDataA(hPrinter: THandle; pValueName: PAnsiChar; pType: PDWORD; pData: Pointer;
  nSize: DWORD; var pcbNeeded: DWORD): DWORD; stdcall;
{$EXTERNALSYM GetPrinterDataW}
function GetPrinterDataW(hPrinter: THandle; pValueName: PWideChar; pType: PDWORD; pData: Pointer;
  nSize: DWORD; var pcbNeeded: DWORD): DWORD; stdcall;
{$EXTERNALSYM GetPrinterData}
function GetPrinterData(hPrinter: THandle; pValueName: PChar; pType: PDWORD; pData: Pointer;
  nSize: DWORD; var pcbNeeded: DWORD): DWORD; stdcall;
function EnumPrinterDataA(hPrinter: THandle; dwIndex: DWORD; pValueName: PAnsiChar;
  cbValueName: DWORD; var pcbValueName, pType: DWORD; pData: PByte;
  cbData: DWORD; pcbData: PDWORD): DWORD; stdcall;
{$EXTERNALSYM EnumPrinterDataA}
function EnumPrinterDataW(hPrinter: THandle; dwIndex: DWORD; pValueName: PWideChar;
  cbValueName: DWORD; var pcbValueName, pType: DWORD; pData: PByte;
  cbData: DWORD; pcbData: PDWORD): DWORD; stdcall;
{$EXTERNALSYM EnumPrinterDataW}
function EnumPrinterData(hPrinter: THandle; dwIndex: DWORD; pValueName: PChar;
  cbValueName: DWORD; var pcbValueName, pType: DWORD; pData: PByte;
  cbData: DWORD; pcbData: PDWORD): DWORD; stdcall;
{$EXTERNALSYM EnumPrinterData}
{$EXTERNALSYM SetPrinterDataA}
function SetPrinterDataA(hPrinter: THandle; pValueName: PAnsiChar; dwType: DWORD; pData: Pointer; cbData: DWORD): DWORD; stdcall;
{$EXTERNALSYM SetPrinterDataW}
function SetPrinterDataW(hPrinter: THandle; pValueName: PWideChar; dwType: DWORD; pData: Pointer; cbData: DWORD): DWORD; stdcall;
{$EXTERNALSYM SetPrinterData}
function SetPrinterData(hPrinter: THandle; pValueName: PChar; dwType: DWORD; pData: Pointer; cbData: DWORD): DWORD; stdcall;
function DeletePrinterDataA(hPrinter: THandle; pValueName: PAnsiChar): DWORD; stdcall;
{$EXTERNALSYM DeletePrinterDataA}
function DeletePrinterDataW(hPrinter: THandle; pValueName: PWideChar): DWORD; stdcall;
{$EXTERNALSYM DeletePrinterDataW}
function DeletePrinterData(hPrinter: THandle; pValueName: PChar): DWORD; stdcall;
{$EXTERNALSYM DeletePrinterData}

const
  {$EXTERNALSYM PRINTER_NOTIFY_TYPE}
  PRINTER_NOTIFY_TYPE = $00;
  {$EXTERNALSYM JOB_NOTIFY_TYPE}
  JOB_NOTIFY_TYPE     = $01;

  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_SERVER_NAME}
  PRINTER_NOTIFY_FIELD_SERVER_NAME             = $00;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_PRINTER_NAME}
  PRINTER_NOTIFY_FIELD_PRINTER_NAME            = $01;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_SHARE_NAME}
  PRINTER_NOTIFY_FIELD_SHARE_NAME              = $02;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_PORT_NAME}
  PRINTER_NOTIFY_FIELD_PORT_NAME               = $03;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_DRIVER_NAME}
  PRINTER_NOTIFY_FIELD_DRIVER_NAME             = $04;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_COMMENT}
  PRINTER_NOTIFY_FIELD_COMMENT                 = $05;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_LOCATION}
  PRINTER_NOTIFY_FIELD_LOCATION                = $06;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_DEVMODE}
  PRINTER_NOTIFY_FIELD_DEVMODE                 = $07;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_SEPFILE}
  PRINTER_NOTIFY_FIELD_SEPFILE                 = $08;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR}
  PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR         = $09;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_PARAMETERS}
  PRINTER_NOTIFY_FIELD_PARAMETERS              = $0A;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_DATATYPE}
  PRINTER_NOTIFY_FIELD_DATATYPE                = $0B;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR}
  PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR     = $0C;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_ATTRIBUTES}
  PRINTER_NOTIFY_FIELD_ATTRIBUTES              = $0D;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_PRIORITY}
  PRINTER_NOTIFY_FIELD_PRIORITY                = $0E;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY}
  PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY        = $0F;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_START_TIME}
  PRINTER_NOTIFY_FIELD_START_TIME              = $10;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_UNTIL_TIME}
  PRINTER_NOTIFY_FIELD_UNTIL_TIME              = $11;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_STATUS}
  PRINTER_NOTIFY_FIELD_STATUS                  = $12;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_STATUS_STRING}
  PRINTER_NOTIFY_FIELD_STATUS_STRING           = $13;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_CJOBS}
  PRINTER_NOTIFY_FIELD_CJOBS                   = $14;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_AVERAGE_PPM}
  PRINTER_NOTIFY_FIELD_AVERAGE_PPM             = $15;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_TOTAL_PAGES}
  PRINTER_NOTIFY_FIELD_TOTAL_PAGES             = $16;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_PAGES_PRINTED}
  PRINTER_NOTIFY_FIELD_PAGES_PRINTED           = $17;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_TOTAL_BYTES}
  PRINTER_NOTIFY_FIELD_TOTAL_BYTES             = $18;
  {$EXTERNALSYM PRINTER_NOTIFY_FIELD_BYTES_PRINTED}
  PRINTER_NOTIFY_FIELD_BYTES_PRINTED           = $19;

  {$EXTERNALSYM JOB_NOTIFY_FIELD_PRINTER_NAME}
  JOB_NOTIFY_FIELD_PRINTER_NAME                = $00;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_MACHINE_NAME}
  JOB_NOTIFY_FIELD_MACHINE_NAME                = $01;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_PORT_NAME}
  JOB_NOTIFY_FIELD_PORT_NAME                   = $02;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_USER_NAME}
  JOB_NOTIFY_FIELD_USER_NAME                   = $03;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_NOTIFY_NAME}
  JOB_NOTIFY_FIELD_NOTIFY_NAME                 = $04;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_DATATYPE}
  JOB_NOTIFY_FIELD_DATATYPE                    = $05;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_PRINT_PROCESSOR}
  JOB_NOTIFY_FIELD_PRINT_PROCESSOR             = $06;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_PARAMETERS}
  JOB_NOTIFY_FIELD_PARAMETERS                  = $07;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_DRIVER_NAME}
  JOB_NOTIFY_FIELD_DRIVER_NAME                 = $08;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_DEVMODE}
  JOB_NOTIFY_FIELD_DEVMODE                     = $09;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_STATUS}
  JOB_NOTIFY_FIELD_STATUS                      = $0A;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_STATUS_STRING}
  JOB_NOTIFY_FIELD_STATUS_STRING               = $0B;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR}
  JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR         = $0C;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_DOCUMENT}
  JOB_NOTIFY_FIELD_DOCUMENT                    = $0D;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_PRIORITY}
  JOB_NOTIFY_FIELD_PRIORITY                    = $0E;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_POSITION}
  JOB_NOTIFY_FIELD_POSITION                    = $0F;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_SUBMITTED}
  JOB_NOTIFY_FIELD_SUBMITTED                   = $10;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_START_TIME}
  JOB_NOTIFY_FIELD_START_TIME                  = $11;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_UNTIL_TIME}
  JOB_NOTIFY_FIELD_UNTIL_TIME                  = $12;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_TIME}
  JOB_NOTIFY_FIELD_TIME                        = $13;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_TOTAL_PAGES}
  JOB_NOTIFY_FIELD_TOTAL_PAGES                 = $14;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_PAGES_PRINTED}
  JOB_NOTIFY_FIELD_PAGES_PRINTED               = $15;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_TOTAL_BYTES}
  JOB_NOTIFY_FIELD_TOTAL_BYTES                 = $16;
  {$EXTERNALSYM JOB_NOTIFY_FIELD_BYTES_PRINTED}
  JOB_NOTIFY_FIELD_BYTES_PRINTED               = $17;


type
  PPrinterNotifyOptionsType = ^TPrinterNotifyOptionsType;
  {$EXTERNALSYM _PRINTER_NOTIFY_OPTIONS_TYPE}
  _PRINTER_NOTIFY_OPTIONS_TYPE = record
    wType: Word;
    Reserved0: Word;
    Reserved1: DWORD;
    Reserved2: DWORD;
    Count: DWORD;
    pFields: PWord;
  end;
  TPrinterNotifyOptionsType = _PRINTER_NOTIFY_OPTIONS_TYPE;
  {$EXTERNALSYM PRINTER_NOTIFY_OPTIONS_TYPE}
  PRINTER_NOTIFY_OPTIONS_TYPE = _PRINTER_NOTIFY_OPTIONS_TYPE;

const
  {$EXTERNALSYM PRINTER_NOTIFY_OPTIONS_REFRESH}
  PRINTER_NOTIFY_OPTIONS_REFRESH  = $01;

type
  PPrinterNotifyOptions = ^TPrinterNotifyOptions;
  {$EXTERNALSYM _PRINTER_NOTIFY_OPTIONS}
  _PRINTER_NOTIFY_OPTIONS = record
    Version: DWORD;
    Flags: DWORD;
    Count: DWORD;
    pTypes: PPrinterNotifyOptionsType;
  end;
  TPrinterNotifyOptions = _PRINTER_NOTIFY_OPTIONS;
  {$EXTERNALSYM PRINTER_NOTIFY_OPTIONS}
  PRINTER_NOTIFY_OPTIONS = _PRINTER_NOTIFY_OPTIONS;

const
  {$EXTERNALSYM PRINTER_NOTIFY_INFO_DISCARDED}
  PRINTER_NOTIFY_INFO_DISCARDED       = $01;

type
  PPrinterNotifyInfoData = ^TPrinterNotifyInfoData;
  {$EXTERNALSYM _PRINTER_NOTIFY_INFO_DATA}
  _PRINTER_NOTIFY_INFO_DATA = record
    wType: Word;
    Field: Word;
    Reserved: DWORD;
    Id: DWORD;
    NotifyData: record
      case Integer of
        0: (adwData: array[0..1] of DWORD);
        1: (Data: record
              cbBuf: DWORD;
              pBuf: Pointer;
            end);
    end;
  end;
  TPrinterNotifyInfoData = _PRINTER_NOTIFY_INFO_DATA;
  {$EXTERNALSYM PRINTER_NOTIFY_INFO_DATA}
  PRINTER_NOTIFY_INFO_DATA = _PRINTER_NOTIFY_INFO_DATA;

  PPrinterNotifyInfo = ^TPrinterNotifyInfo;
  {$EXTERNALSYM _PRINTER_NOTIFY_INFO}
  _PRINTER_NOTIFY_INFO = record
    Version: DWORD;
    Flags: DWORD;
    Count: DWORD;
    aData: array[0..0] of TPrinterNotifyInfoData;
  end;
  TPrinterNotifyInfo = _PRINTER_NOTIFY_INFO;
  {$EXTERNALSYM PRINTER_NOTIFY_INFO}
  PRINTER_NOTIFY_INFO = _PRINTER_NOTIFY_INFO;

{$EXTERNALSYM WaitForPrinterChange}
function WaitForPrinterChange(hPrinter: THandle; Flags: DWORD): DWORD; stdcall;
{$EXTERNALSYM FindFirstPrinterChangeNotification}
function FindFirstPrinterChangeNotification(hPrinter: THandle; fdwFlags: DWORD;
  fdwOptions: DWORD; pPrinterNotifyOptions: Pointer): THandle; stdcall;
{$EXTERNALSYM FindNextPrinterChangeNotification}
function FindNextPrinterChangeNotification(hChange: THandle; var pdwChange: DWORD;
  pvReserved: Pointer; var ppPrinterNotifyInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM FreePrinterNotifyInfo}
function FreePrinterNotifyInfo(pPrinterNotifyInfo: PPrinterNotifyInfo): BOOL; stdcall;
{$EXTERNALSYM FindClosePrinterChangeNotification}
function FindClosePrinterChangeNotification(hChange: THandle): BOOL; stdcall;

const
  {$EXTERNALSYM PRINTER_CHANGE_ADD_PRINTER}
  PRINTER_CHANGE_ADD_PRINTER              = $00000001;
  {$EXTERNALSYM PRINTER_CHANGE_SET_PRINTER}
  PRINTER_CHANGE_SET_PRINTER              = $00000002;
  {$EXTERNALSYM PRINTER_CHANGE_DELETE_PRINTER}
  PRINTER_CHANGE_DELETE_PRINTER           = $00000004;
  {$EXTERNALSYM PRINTER_CHANGE_FAILED_CONNECTION_PRINTER}
  PRINTER_CHANGE_FAILED_CONNECTION_PRINTER    = $00000008;
  {$EXTERNALSYM PRINTER_CHANGE_PRINTER}
  PRINTER_CHANGE_PRINTER                  = $000000FF;
  {$EXTERNALSYM PRINTER_CHANGE_ADD_JOB}
  PRINTER_CHANGE_ADD_JOB                  = $00000100;
  {$EXTERNALSYM PRINTER_CHANGE_SET_JOB}
  PRINTER_CHANGE_SET_JOB                  = $00000200;
  {$EXTERNALSYM PRINTER_CHANGE_DELETE_JOB}
  PRINTER_CHANGE_DELETE_JOB               = $00000400;
  {$EXTERNALSYM PRINTER_CHANGE_WRITE_JOB}
  PRINTER_CHANGE_WRITE_JOB                = $00000800;
  {$EXTERNALSYM PRINTER_CHANGE_JOB}
  PRINTER_CHANGE_JOB                      = $0000FF00;
  {$EXTERNALSYM PRINTER_CHANGE_ADD_FORM}
  PRINTER_CHANGE_ADD_FORM                 = $00010000;
  {$EXTERNALSYM PRINTER_CHANGE_SET_FORM}
  PRINTER_CHANGE_SET_FORM                 = $00020000;
  {$EXTERNALSYM PRINTER_CHANGE_DELETE_FORM}
  PRINTER_CHANGE_DELETE_FORM              = $00040000;
  {$EXTERNALSYM PRINTER_CHANGE_FORM}
  PRINTER_CHANGE_FORM                     = $00070000;
  {$EXTERNALSYM PRINTER_CHANGE_ADD_PORT}
  PRINTER_CHANGE_ADD_PORT                 = $00100000;
  {$EXTERNALSYM PRINTER_CHANGE_CONFIGURE_PORT}
  PRINTER_CHANGE_CONFIGURE_PORT           = $00200000;
  {$EXTERNALSYM PRINTER_CHANGE_DELETE_PORT}
  PRINTER_CHANGE_DELETE_PORT              = $00400000;
  {$EXTERNALSYM PRINTER_CHANGE_PORT}
  PRINTER_CHANGE_PORT                     = $00700000;
  {$EXTERNALSYM PRINTER_CHANGE_ADD_PRINT_PROCESSOR}
  PRINTER_CHANGE_ADD_PRINT_PROCESSOR      = $01000000;
  {$EXTERNALSYM PRINTER_CHANGE_DELETE_PRINT_PROCESSOR}
  PRINTER_CHANGE_DELETE_PRINT_PROCESSOR   = $04000000;
  {$EXTERNALSYM PRINTER_CHANGE_PRINT_PROCESSOR}
  PRINTER_CHANGE_PRINT_PROCESSOR          = $07000000;
  {$EXTERNALSYM PRINTER_CHANGE_ADD_PRINTER_DRIVER}
  PRINTER_CHANGE_ADD_PRINTER_DRIVER       = $10000000;
  {$EXTERNALSYM PRINTER_CHANGE_SET_PRINTER_DRIVER}
  PRINTER_CHANGE_SET_PRINTER_DRIVER       = $20000000;
  {$EXTERNALSYM PRINTER_CHANGE_DELETE_PRINTER_DRIVER}
  PRINTER_CHANGE_DELETE_PRINTER_DRIVER    = $40000000;
  {$EXTERNALSYM PRINTER_CHANGE_PRINTER_DRIVER}
  PRINTER_CHANGE_PRINTER_DRIVER           = $70000000;
  {$EXTERNALSYM PRINTER_CHANGE_TIMEOUT}
  PRINTER_CHANGE_TIMEOUT                  = $80000000;
  {$EXTERNALSYM PRINTER_CHANGE_ALL}
  PRINTER_CHANGE_ALL                      = $7777FFFF;

{$EXTERNALSYM PrinterMessageBoxA}
function PrinterMessageBoxA(hPrinter: THandle; Error: DWORD; hWnd: HWND; pText, pCaption: PAnsiChar;
  dwType: DWORD): DWORD; stdcall;
{$EXTERNALSYM PrinterMessageBoxW}
function PrinterMessageBoxW(hPrinter: THandle; Error: DWORD; hWnd: HWND; pText, pCaption: PWideChar;
  dwType: DWORD): DWORD; stdcall;
{$EXTERNALSYM PrinterMessageBox}
function PrinterMessageBox(hPrinter: THandle; Error: DWORD; hWnd: HWND; pText, pCaption: PChar;
  dwType: DWORD): DWORD; stdcall;

const
  {$EXTERNALSYM PRINTER_ERROR_INFORMATION}
  PRINTER_ERROR_INFORMATION   = $80000000;
  {$EXTERNALSYM PRINTER_ERROR_WARNING}
  PRINTER_ERROR_WARNING       = $40000000;
  {$EXTERNALSYM PRINTER_ERROR_SEVERE}
  PRINTER_ERROR_SEVERE        = $20000000;

  {$EXTERNALSYM PRINTER_ERROR_OUTOFPAPER}
  PRINTER_ERROR_OUTOFPAPER    = $00000001;
  {$EXTERNALSYM PRINTER_ERROR_JAM}
  PRINTER_ERROR_JAM           = $00000002;
  {$EXTERNALSYM PRINTER_ERROR_OUTOFTONER}
  PRINTER_ERROR_OUTOFTONER    = $00000004;

{$EXTERNALSYM ClosePrinter}
function ClosePrinter(hPrinter: THandle): BOOL; stdcall;
{$EXTERNALSYM AddFormA}
function AddFormA(hPrinter: THandle; Level: DWORD; pForm: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddFormW}
function AddFormW(hPrinter: THandle; Level: DWORD; pForm: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddForm}
function AddForm(hPrinter: THandle; Level: DWORD; pForm: Pointer): BOOL; stdcall;
{$EXTERNALSYM DeleteFormA}
function DeleteFormA(hPrinter: THandle; pFormName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeleteFormW}
function DeleteFormW(hPrinter: THandle; pFormName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeleteForm}
function DeleteForm(hPrinter: THandle; pFormName: PChar): BOOL; stdcall;
{$EXTERNALSYM GetFormA}
function GetFormA(hPrinter: THandle; pFormName: PAnsiChar; Level: DWORD; pForm: Pointer;
  cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetFormW}
function GetFormW(hPrinter: THandle; pFormName: PWideChar; Level: DWORD; pForm: Pointer;
  cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM GetForm}
function GetForm(hPrinter: THandle; pFormName: PChar; Level: DWORD; pForm: Pointer;
  cbBuf: DWORD; var pcbNeeded: DWORD): BOOL; stdcall;
{$EXTERNALSYM SetFormA}
function SetFormA(hPrinter: THandle; pFormName: PAnsiChar; Level: DWORD; pForm: Pointer): BOOL; stdcall;
{$EXTERNALSYM SetFormW}
function SetFormW(hPrinter: THandle; pFormName: PWideChar; Level: DWORD; pForm: Pointer): BOOL; stdcall;
{$EXTERNALSYM SetForm}
function SetForm(hPrinter: THandle; pFormName: PChar; Level: DWORD; pForm: Pointer): BOOL; stdcall;
{$EXTERNALSYM EnumFormsA}
function EnumFormsA(hPrinter: THandle; Level: DWORD; pForm: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumFormsW}
function EnumFormsW(hPrinter: THandle; Level: DWORD; pForm: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumForms}
function EnumForms(hPrinter: THandle; Level: DWORD; pForm: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumMonitorsA}
function EnumMonitorsA(pName: PAnsiChar; Level: DWORD; pMonitors: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumMonitorsW}
function EnumMonitorsW(pName: PWideChar; Level: DWORD; pMonitors: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumMonitors}
function EnumMonitors(pName: PChar; Level: DWORD; pMonitors: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM AddMonitorA}
function AddMonitorA(pName: PAnsiChar; Level: DWORD; pMonitors: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddMonitorW}
function AddMonitorW(pName: PWideChar; Level: DWORD; pMonitors: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddMonitor}
function AddMonitor(pName: PChar; Level: DWORD; pMonitors: Pointer): BOOL; stdcall;
{$EXTERNALSYM DeleteMonitorA}
function DeleteMonitorA(pName, pEnvironment, pMonitorName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeleteMonitorW}
function DeleteMonitorW(pName, pEnvironment, pMonitorName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeleteMonitor}
function DeleteMonitor(pName, pEnvironment, pMonitorName: PChar): BOOL; stdcall;
{$EXTERNALSYM EnumPortsA}
function EnumPortsA(pName: PAnsiChar; Level: DWORD; pPorts: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPortsW}
function EnumPortsW(pName: PWideChar; Level: DWORD; pPorts: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM EnumPorts}
function EnumPorts(pName: PChar; Level: DWORD; pPorts: Pointer; cbBuf: DWORD;
  var pcbNeeded, pcReturned: DWORD): BOOL; stdcall;
{$EXTERNALSYM AddPortA}
function AddPortA(pName: PAnsiChar; hWnd: HWND; pMonitorName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM AddPortW}
function AddPortW(pName: PWideChar; hWnd: HWND; pMonitorName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM AddPort}
function AddPort(pName: PChar; hWnd: HWND; pMonitorName: PChar): BOOL; stdcall;
{$EXTERNALSYM ConfigurePortA}
function ConfigurePortA(pName: PAnsiChar; hWnd: HWND; pPortName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM ConfigurePortW}
function ConfigurePortW(pName: PWideChar; hWnd: HWND; pPortName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM ConfigurePort}
function ConfigurePort(pName: PChar; hWnd: HWND; pPortName: PChar): BOOL; stdcall;
{$EXTERNALSYM DeletePortA}
function DeletePortA(pName: PAnsiChar; hWnd: HWND; pPortName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeletePortW}
function DeletePortW(pName: PWideChar; hWnd: HWND; pPortName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeletePort}
function DeletePort(pName: PChar; hWnd: HWND; pPortName: PChar): BOOL; stdcall;
function SetPortA(pName, pPortName: PAnsiChar; dwLevel: DWORD; pPortInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM SetPortA}
function SetPortW(pName, pPortName: PWideChar; dwLevel: DWORD; pPortInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM SetPortW}
function SetPort(pName, pPortName: PChar; dwLevel: DWORD; pPortInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM SetPort}
{$EXTERNALSYM AddPrinterConnectionA}
function AddPrinterConnectionA(pName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM AddPrinterConnectionW}
function AddPrinterConnectionW(pName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM AddPrinterConnection}
function AddPrinterConnection(pName: PChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrinterConnectionA}
function DeletePrinterConnectionA(pName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrinterConnectionW}
function DeletePrinterConnectionW(pName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrinterConnection}
function DeletePrinterConnection(pName: PChar): BOOL; stdcall;
{$EXTERNALSYM ConnectToPrinterDlg}
function ConnectToPrinterDlg(hwnd: HWND; Flags: DWORD): THandle; stdcall;

type
  PProvidorInfo1A = ^TProvidorInfo1A;
  PProvidorInfo1W = ^TProvidorInfo1W;
  PProvidorInfo1 = PProvidorInfo1A;
  {$EXTERNALSYM _PROVIDOR_INFO_1A}
  _PROVIDOR_INFO_1A = record
    pName: PAnsiChar;
    pEnvironment: PAnsiChar;
    pDLLName: PAnsiChar;
  end;
  {$EXTERNALSYM _PROVIDOR_INFO_1W}
  _PROVIDOR_INFO_1W = record
    pName: PWideChar;
    pEnvironment: PWideChar;
    pDLLName: PWideChar;
  end;
  {$EXTERNALSYM _PROVIDOR_INFO_1}
  _PROVIDOR_INFO_1 = _PROVIDOR_INFO_1A;
  TProvidorInfo1A = _PROVIDOR_INFO_1A;
  TProvidorInfo1W = _PROVIDOR_INFO_1W;
  TProvidorInfo1 = TProvidorInfo1A;
  {$EXTERNALSYM PROVIDOR_INFO_1A}
  PROVIDOR_INFO_1A = _PROVIDOR_INFO_1A;
  {$EXTERNALSYM PROVIDOR_INFO_1W}
  PROVIDOR_INFO_1W = _PROVIDOR_INFO_1W;
  {$EXTERNALSYM PROVIDOR_INFO_1}
  PROVIDOR_INFO_1 = PROVIDOR_INFO_1A;

{$EXTERNALSYM AddPrintProvidorA}
function AddPrintProvidorA(pName: PAnsiChar; level: DWORD; pProvidorInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddPrintProvidorW}
function AddPrintProvidorW(pName: PWideChar; level: DWORD; pProvidorInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM AddPrintProvidor}
function AddPrintProvidor(pName: PChar; level: DWORD; pProvidorInfo: Pointer): BOOL; stdcall;
{$EXTERNALSYM DeletePrintProvidorA}
function DeletePrintProvidorA(pName, pEnvironment, pPrintProvidorName: PAnsiChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrintProvidorW}
function DeletePrintProvidorW(pName, pEnvironment, pPrintProvidorName: PWideChar): BOOL; stdcall;
{$EXTERNALSYM DeletePrintProvidor}
function DeletePrintProvidor(pName, pEnvironment, pPrintProvidorName: PChar): BOOL; stdcall;

{ SetPrinterData and GetPrinterData Server Handle Key values }

const
  {$EXTERNALSYM SPLREG_DEFAULT_SPOOL_DIRECTORY}
  SPLREG_DEFAULT_SPOOL_DIRECTORY                    = 'DefaultSpoolDirectory';
  {$EXTERNALSYM SPLREG_PORT_THREAD_PRIORITY_DEFAULT}
  SPLREG_PORT_THREAD_PRIORITY_DEFAULT               = 'PortThreadPriorityDefault';
  {$EXTERNALSYM SPLREG_PORT_THREAD_PRIORITY}
  SPLREG_PORT_THREAD_PRIORITY                       = 'PortThreadPriority';
  {$EXTERNALSYM SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT}
  SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT          = 'SchedulerThreadPriorityDefault';
  {$EXTERNALSYM SPLREG_SCHEDULER_THREAD_PRIORITY}
  SPLREG_SCHEDULER_THREAD_PRIORITY                  = 'SchedulerThreadPriority';
  {$EXTERNALSYM SPLREG_BEEP_ENABLED}
  SPLREG_BEEP_ENABLED                               = 'BeepEnabled';
  {$EXTERNALSYM SPLREG_NET_POPUP}
  SPLREG_NET_POPUP                                  = 'NetPopup';
  {$EXTERNALSYM SPLREG_EVENT_LOG}
  SPLREG_EVENT_LOG                                  = 'EventLog';
  {$EXTERNALSYM SPLREG_MAJOR_VERSION}
  SPLREG_MAJOR_VERSION                              = 'MajorVersion';
  {$EXTERNALSYM SPLREG_MINOR_VERSION}
  SPLREG_MINOR_VERSION                              = 'MinorVersion';
  {$EXTERNALSYM SPLREG_ARCHITECTURE}
  SPLREG_ARCHITECTURE                               = 'Architecture';


  {$EXTERNALSYM SERVER_ACCESS_ADMINISTER}
  SERVER_ACCESS_ADMINISTER    = $00000001;
  {$EXTERNALSYM SERVER_ACCESS_ENUMERATE}
  SERVER_ACCESS_ENUMERATE     = $00000002;
  {$EXTERNALSYM PRINTER_ACCESS_ADMINISTER}
  PRINTER_ACCESS_ADMINISTER   = $00000004;
  {$EXTERNALSYM PRINTER_ACCESS_USE}
  PRINTER_ACCESS_USE          = $00000008;
  {$EXTERNALSYM JOB_ACCESS_ADMINISTER}
  JOB_ACCESS_ADMINISTER       = $00000010;

{ Access rights for print servers }

  {$EXTERNALSYM SERVER_ALL_ACCESS}
  SERVER_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED or
    SERVER_ACCESS_ADMINISTER or SERVER_ACCESS_ENUMERATE);
  {$EXTERNALSYM SERVER_READ}
  SERVER_READ = (STANDARD_RIGHTS_READ or SERVER_ACCESS_ENUMERATE);
  {$EXTERNALSYM SERVER_WRITE}
  SERVER_WRITE = (STANDARD_RIGHTS_WRITE or
    SERVER_ACCESS_ADMINISTER or SERVER_ACCESS_ENUMERATE);
  {$EXTERNALSYM SERVER_EXECUTE}
  SERVER_EXECUTE = (STANDARD_RIGHTS_EXECUTE or SERVER_ACCESS_ENUMERATE);

{ Access rights for printers }

  {$EXTERNALSYM PRINTER_ALL_ACCESS}
  PRINTER_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED or
    PRINTER_ACCESS_ADMINISTER or PRINTER_ACCESS_USE);
  {$EXTERNALSYM PRINTER_READ}
  PRINTER_READ = (STANDARD_RIGHTS_READ or PRINTER_ACCESS_USE);
  {$EXTERNALSYM PRINTER_WRITE}
  PRINTER_WRITE = (STANDARD_RIGHTS_WRITE or PRINTER_ACCESS_USE);
  {$EXTERNALSYM PRINTER_EXECUTE}
  PRINTER_EXECUTE = (STANDARD_RIGHTS_EXECUTE or PRINTER_ACCESS_USE);

{ Access rights for jobs }

  {$EXTERNALSYM JOB_ALL_ACCESS}
  JOB_ALL_ACCESS = (STANDARD_RIGHTS_REQUIRED or JOB_ACCESS_ADMINISTER);
  {$EXTERNALSYM JOB_READ}
  JOB_READ = (STANDARD_RIGHTS_READ or JOB_ACCESS_ADMINISTER);
  {$EXTERNALSYM JOB_WRITE}
  JOB_WRITE = (STANDARD_RIGHTS_WRITE or JOB_ACCESS_ADMINISTER);
  {$EXTERNALSYM JOB_EXECUTE}
  JOB_EXECUTE = (STANDARD_RIGHTS_EXECUTE or JOB_ACCESS_ADMINISTER);

{$EXTERNALSYM DeviceCapabilitiesA}
function DeviceCapabilitiesA(pDevice, pPort: PAnsiChar; fwCapability: Word;
  pOutput: PAnsiChar; DevMode: PDeviceModeA): Integer; stdcall;
{$EXTERNALSYM DeviceCapabilitiesW}
function DeviceCapabilitiesW(pDevice, pPort: PWideChar; fwCapability: Word;
  pOutput: PWideChar; DevMode: PDeviceModeW): Integer; stdcall;
{$EXTERNALSYM DeviceCapabilities}
function DeviceCapabilities(pDevice, pPort: PChar; fwCapability: Word;
  pOutput: PChar; DevMode: PDeviceMode): Integer; stdcall;

const
  winspl = 'winspool.drv';

implementation

function AbortPrinter; external winspl name 'AbortPrinter';
function AddFormA; external winspl name 'AddFormA';
function AddFormW; external winspl name 'AddFormW';
function AddForm; external winspl name 'AddFormA';
function AddJobA; external winspl name 'AddJobA';
function AddJobW; external winspl name 'AddJobW';
function AddJob; external winspl name 'AddJobA';
function AddMonitorA; external winspl name 'AddMonitorA';
function AddMonitorW; external winspl name 'AddMonitorW';
function AddMonitor; external winspl name 'AddMonitorA';
function AddPortA; external winspl name 'AddPortA';
function AddPortW; external winspl name 'AddPortW';
function AddPort; external winspl name 'AddPortA';
function AddPrinterA; external winspl name 'AddPrinterA';
function AddPrinterW; external winspl name 'AddPrinterW';
function AddPrinter; external winspl name 'AddPrinterA';
function AddPrinterConnectionA; external winspl name 'AddPrinterConnectionA';
function AddPrinterConnectionW; external winspl name 'AddPrinterConnectionW';
function AddPrinterConnection; external winspl name 'AddPrinterConnectionA';
function AddPrinterDriverA; external winspl name 'AddPrinterDriverA';
function AddPrinterDriverW; external winspl name 'AddPrinterDriverW';
function AddPrinterDriver; external winspl name 'AddPrinterDriverA';
function AddPrintProcessorA; external winspl name 'AddPrintProcessorA';
function AddPrintProcessorW; external winspl name 'AddPrintProcessorW';
function AddPrintProcessor; external winspl name 'AddPrintProcessorA';
function AddPrintProvidorA; external winspl name 'AddPrintProvidorA';
function AddPrintProvidorW; external winspl name 'AddPrintProvidorW';
function AddPrintProvidor; external winspl name 'AddPrintProvidorA';
function AdvancedDocumentPropertiesA; external winspl name 'AdvancedDocumentPropertiesA';
function AdvancedDocumentPropertiesW; external winspl name 'AdvancedDocumentPropertiesW';
function AdvancedDocumentProperties; external winspl name 'AdvancedDocumentPropertiesA';
function ClosePrinter; external winspl name 'ClosePrinter';
function ConfigurePortA; external winspl name 'ConfigurePortA';
function ConfigurePortW; external winspl name 'ConfigurePortW';
function ConfigurePort; external winspl name 'ConfigurePortA';
function ConnectToPrinterDlg; external winspl name 'ConnectToPrinterDlg';
function DeleteFormA; external winspl name 'DeleteFormA';
function DeleteFormW; external winspl name 'DeleteFormW';
function DeleteForm; external winspl name 'DeleteFormA';
function DeleteMonitorA; external winspl name 'DeleteMonitorA';
function DeleteMonitorW; external winspl name 'DeleteMonitorW';
function DeleteMonitor; external winspl name 'DeleteMonitorA';
function DeletePortA; external winspl name 'DeletePortA';
function DeletePortW; external winspl name 'DeletePortW';
function DeletePort; external winspl name 'DeletePortA';
function DeletePrinter; external winspl name 'DeletePrinter';
function DeletePrinterConnectionA; external winspl name 'DeletePrinterConnectionA';
function DeletePrinterConnectionW; external winspl name 'DeletePrinterConnectionW';
function DeletePrinterConnection; external winspl name 'DeletePrinterConnectionA';
function DeletePrinterDataA; external winspl name 'DeletePrinterDataA';
function DeletePrinterDataW; external winspl name 'DeletePrinterDataW';
function DeletePrinterData; external winspl name 'DeletePrinterDataA';
function DeletePrinterDriverA; external winspl name 'DeletePrinterDriverA';
function DeletePrinterDriverW; external winspl name 'DeletePrinterDriverW';
function DeletePrinterDriver; external winspl name 'DeletePrinterDriverA';
function DeletePrintProcessorA; external winspl name 'DeletePrintProcessorA';
function DeletePrintProcessorW; external winspl name 'DeletePrintProcessorW';
function DeletePrintProcessor; external winspl name 'DeletePrintProcessorA';
function DeletePrintProvidorA; external winspl name 'DeletePrintProvidorA';
function DeletePrintProvidorW; external winspl name 'DeletePrintProvidorW';
function DeletePrintProvidor; external winspl name 'DeletePrintProvidorA';
function DeviceCapabilitiesA; external winspl name 'DeviceCapabilitiesA';
function DeviceCapabilitiesW; external winspl name 'DeviceCapabilitiesW';
function DeviceCapabilities; external winspl name 'DeviceCapabilitiesA';
function DocumentPropertiesA; external winspl name 'DocumentPropertiesA';
function DocumentPropertiesW; external winspl name 'DocumentPropertiesW';
function DocumentProperties; external winspl name 'DocumentPropertiesA';
function EndDocPrinter; external winspl name 'EndDocPrinter';
function EndPagePrinter; external winspl name 'EndPagePrinter';
function EnumFormsA; external winspl name 'EnumFormsA';
function EnumFormsW; external winspl name 'EnumFormsW';
function EnumForms; external winspl name 'EnumFormsA';
function EnumJobsA; external winspl name 'EnumJobsA';
function EnumJobsW; external winspl name 'EnumJobsW';
function EnumJobs; external winspl name 'EnumJobsA';
function EnumMonitorsA; external winspl name 'EnumMonitorsA';
function EnumMonitorsW; external winspl name 'EnumMonitorsW';
function EnumMonitors; external winspl name 'EnumMonitorsA';
function EnumPortsA; external winspl name 'EnumPortsA';
function EnumPortsW; external winspl name 'EnumPortsW';
function EnumPorts; external winspl name 'EnumPortsA';
function EnumPrinterDataA; external winspl name 'EnumPrinterDataA';
function EnumPrinterDataW; external winspl name 'EnumPrinterDataW';
function EnumPrinterData; external winspl name 'EnumPrinterDataA';
function EnumPrinterDriversA; external winspl name 'EnumPrinterDriversA';
function EnumPrinterDriversW; external winspl name 'EnumPrinterDriversW';
function EnumPrinterDrivers; external winspl name 'EnumPrinterDriversA';
function EnumPrintersA; external winspl name 'EnumPrintersA';
function EnumPrintersW; external winspl name 'EnumPrintersW';
function EnumPrinters; external winspl name 'EnumPrintersA';
function EnumPrintProcessorDatatypesA; external winspl name 'EnumPrintProcessorDatatypesA';
function EnumPrintProcessorDatatypesW; external winspl name 'EnumPrintProcessorDatatypesW';
function EnumPrintProcessorDatatypes; external winspl name 'EnumPrintProcessorDatatypesA';
function EnumPrintProcessorsA; external winspl name 'EnumPrintProcessorsA';
function EnumPrintProcessorsW; external winspl name 'EnumPrintProcessorsW';
function EnumPrintProcessors; external winspl name 'EnumPrintProcessorsA';
function FindClosePrinterChangeNotification; external winspl name 'FindClosePrinterChangeNotification';
function FindFirstPrinterChangeNotification; external winspl name 'FindFirstPrinterChangeNotification';
function FindNextPrinterChangeNotification; external winspl name 'FindNextPrinterChangeNotification';
function FreePrinterNotifyInfo; external winspl name 'FreePrinterNotifyInfo';
function GetFormA; external winspl name 'GetFormA';
function GetFormW; external winspl name 'GetFormW';
function GetForm; external winspl name 'GetFormA';
function GetJobA; external winspl name 'GetJobA';
function GetJobW; external winspl name 'GetJobW';
function GetJob; external winspl name 'GetJobA';
function GetPrinterA; external winspl name 'GetPrinterA';
function GetPrinterW; external winspl name 'GetPrinterW';
function GetPrinter; external winspl name 'GetPrinterA';
function GetPrinterDataA; external winspl name 'GetPrinterDataA';
function GetPrinterDataW; external winspl name 'GetPrinterDataW';
function GetPrinterData; external winspl name 'GetPrinterDataA';
function GetPrinterDriverA; external winspl name 'GetPrinterDriverA';
function GetPrinterDriverW; external winspl name 'GetPrinterDriverW';
function GetPrinterDriver; external winspl name 'GetPrinterDriverA';
function GetPrinterDriverDirectoryA; external winspl name 'GetPrinterDriverDirectoryA';
function GetPrinterDriverDirectoryW; external winspl name 'GetPrinterDriverDirectoryW';
function GetPrinterDriverDirectory; external winspl name 'GetPrinterDriverDirectoryA';
function GetPrintProcessorDirectoryA; external winspl name 'GetPrintProcessorDirectoryA';
function GetPrintProcessorDirectoryW; external winspl name 'GetPrintProcessorDirectoryW';
function GetPrintProcessorDirectory; external winspl name 'GetPrintProcessorDirectoryA';
function OpenPrinterA; external winspl name 'OpenPrinterA';
function OpenPrinterW; external winspl name 'OpenPrinterW';
function OpenPrinter; external winspl name 'OpenPrinterA';
function PrinterMessageBoxA; external winspl name 'PrinterMessageBoxA';
function PrinterMessageBoxW; external winspl name 'PrinterMessageBoxW';
function PrinterMessageBox; external winspl name 'PrinterMessageBoxA';
function PrinterProperties; external winspl name 'PrinterProperties';
function ReadPrinter; external winspl name 'ReadPrinter';
function ResetPrinterA; external winspl name 'ResetPrinterA';
function ResetPrinterW; external winspl name 'ResetPrinterW';
function ResetPrinter; external winspl name 'ResetPrinterA';
function ScheduleJob; external winspl name 'ScheduleJob';
function SetFormA; external winspl name 'SetFormA';
function SetFormW; external winspl name 'SetFormW';
function SetForm; external winspl name 'SetFormA';
function SetJobA; external winspl name 'SetJobA';
function SetJobW; external winspl name 'SetJobW';
function SetJob; external winspl name 'SetJobA';
function SetPortA; external winspl name 'SetPortA';
function SetPortW; external winspl name 'SetPortW';
function SetPort; external winspl name 'SetPortA';
function SetPrinterA; external winspl name 'SetPrinterA';
function SetPrinterW; external winspl name 'SetPrinterW';
function SetPrinter; external winspl name 'SetPrinterA';
function SetPrinterDataA; external winspl name 'SetPrinterDataA';
function SetPrinterDataW; external winspl name 'SetPrinterDataW';
function SetPrinterData; external winspl name 'SetPrinterDataA';
function StartDocPrinterA; external winspl name 'StartDocPrinterA';
function StartDocPrinterW; external winspl name 'StartDocPrinterW';
function StartDocPrinter; external winspl name 'StartDocPrinterA';
function StartPagePrinter; external winspl name 'StartPagePrinter';
function WaitForPrinterChange; external winspl name 'WaitForPrinterChange';
function WritePrinter; external winspl name 'WritePrinter';

end.
