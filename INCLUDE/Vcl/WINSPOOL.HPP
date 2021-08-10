// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WinSpool.pas' rev: 5.00

#ifndef WinSpoolHPP
#define WinSpoolHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

#include <winspool.h>


namespace Winspool
{
//-- type declarations -------------------------------------------------------
typedef _PRINTER_INFO_1A *PPrinterInfo1A;

typedef _PRINTER_INFO_1W *PPrinterInfo1W;

typedef _PRINTER_INFO_1A *PPrinterInfo1;

typedef _PRINTER_INFO_1A  TPrinterInfo1A;

typedef _PRINTER_INFO_1W  TPrinterInfo1W;

typedef _PRINTER_INFO_1A  TPrinterInfo1;

typedef _PRINTER_INFO_2A *PPrinterInfo2A;

typedef _PRINTER_INFO_2W *PPrinterInfo2W;

typedef _PRINTER_INFO_2A *PPrinterInfo2;

typedef _PRINTER_INFO_2A  TPrinterInfo2A;

typedef _PRINTER_INFO_2W  TPrinterInfo2W;

typedef _PRINTER_INFO_2A  TPrinterInfo2;

typedef _PRINTER_INFO_3 *PPrinterInfo3;

typedef _PRINTER_INFO_3  TPrinterInfo3;

typedef _PRINTER_INFO_4A *PPrinterInfo4A;

typedef _PRINTER_INFO_4W *PPrinterInfo4W;

typedef _PRINTER_INFO_4A *PPrinterInfo4;

typedef _PRINTER_INFO_4A  TPrinterInfo4A;

typedef _PRINTER_INFO_4W  TPrinterInfo4W;

typedef _PRINTER_INFO_4A  TPrinterInfo4;

typedef _PRINTER_INFO_5A *PPrinterInfo5A;

typedef _PRINTER_INFO_5W *PPrinterInfo5W;

typedef _PRINTER_INFO_5A *PPrinterInfo5;

typedef _PRINTER_INFO_5A  TPrinterInfo5A;

typedef _PRINTER_INFO_5W  TPrinterInfo5W;

typedef _PRINTER_INFO_5A  TPrinterInfo5;

typedef _PRINTER_INFO_6 *PPrinterInfo6;

typedef _PRINTER_INFO_6  TPrinterInfo6;

typedef _JOB_INFO_1A *PJobInfo1A;

typedef _JOB_INFO_1W *PJobInfo1W;

typedef _JOB_INFO_1A *PJobInfo1;

typedef _JOB_INFO_1A  TJobInfo1A;

typedef _JOB_INFO_1W  TJobInfo1W;

typedef _JOB_INFO_1A  TJobInfo1;

typedef _JOB_INFO_2A *PJobInfo2A;

typedef _JOB_INFO_2W *PJobInfo2W;

typedef _JOB_INFO_2A *PJobInfo2;

typedef _JOB_INFO_2A  TJobInfo2A;

typedef _JOB_INFO_2W  TJobInfo2W;

typedef _JOB_INFO_2A  TJobInfo2;

typedef _JOB_INFO_3 *PJobInfo3;

typedef _JOB_INFO_3  TJobInfo3;

typedef _ADDJOB_INFO_1A *PAddJobInfo1A;

typedef _ADDJOB_INFO_1W *PAddJobInfo1W;

typedef _ADDJOB_INFO_1A *PAddJobInfo1;

typedef _ADDJOB_INFO_1A  TAddJobInfo1A;

typedef _ADDJOB_INFO_1W  TAddJobInfo1W;

typedef _ADDJOB_INFO_1A  TAddJobInfo1;

typedef _DRIVER_INFO_1A *PDriverInfo1A;

typedef _DRIVER_INFO_1W *PDriverInfo1W;

typedef _DRIVER_INFO_1A *PDriverInfo1;

typedef _DRIVER_INFO_1A  TDriverInfo1A;

typedef _DRIVER_INFO_1W  TDriverInfo1W;

typedef _DRIVER_INFO_1A  TDriverInfo1;

typedef _DRIVER_INFO_2A *PDriverInfo2A;

typedef _DRIVER_INFO_2W *PDriverInfo2W;

typedef _DRIVER_INFO_2A *PDriverInfo2;

typedef _DRIVER_INFO_2A  TDriverInfo2A;

typedef _DRIVER_INFO_2W  TDriverInfo2W;

typedef _DRIVER_INFO_2A  TDriverInfo2;

typedef _DRIVER_INFO_3A *PDriverInfo3A;

typedef _DRIVER_INFO_3W *PDriverInfo3W;

typedef _DRIVER_INFO_3A *PDriverInfo3;

typedef _DRIVER_INFO_3A  TDriverInfo3A;

typedef _DRIVER_INFO_3W  TDriverInfo3W;

typedef _DRIVER_INFO_3A  TDriverInfo3;

typedef _DOC_INFO_1A *PDocInfo1A;

typedef _DOC_INFO_1W *PDocInfo1W;

typedef _DOC_INFO_1A *PDocInfo1;

typedef _DOC_INFO_1A  TDocInfo1A;

typedef _DOC_INFO_1W  TDocInfo1W;

typedef _DOC_INFO_1A  TDocInfo1;

typedef _FORM_INFO_1A *PFormInfo1A;

typedef _FORM_INFO_1W *PFormInfo1W;

typedef _FORM_INFO_1A *PFormInfo1;

typedef _FORM_INFO_1A  TFormInfo1A;

typedef _FORM_INFO_1W  TFormInfo1W;

typedef _FORM_INFO_1A  TFormInfo1;

typedef _DOC_INFO_2A *PDocInfo2A;

typedef _DOC_INFO_2W *PDocInfo2W;

typedef _DOC_INFO_2A *PDocInfo2;

typedef _DOC_INFO_2A  TDocInfo2A;

typedef _DOC_INFO_2W  TDocInfo2W;

typedef _DOC_INFO_2A  TDocInfo2;

typedef _PRINTPROCESSOR_INFO_1A *PPrintProcessorInfo1A;

typedef _PRINTPROCESSOR_INFO_1W *PPrintProcessorInfo1W;

typedef _PRINTPROCESSOR_INFO_1A *PPrintProcessorInfo1;

typedef _PRINTPROCESSOR_INFO_1A  TPrintProcessorInfo1A;

typedef _PRINTPROCESSOR_INFO_1W  TPrintProcessorInfo1W;

typedef _PRINTPROCESSOR_INFO_1A  TPrintProcessorInfo1;

typedef _PORT_INFO_1A *PPortInfo1A;

typedef _PORT_INFO_1W *PPortInfo1W;

typedef _PORT_INFO_1A *PPortInfo1;

typedef _PORT_INFO_1A  TPortInfo1A;

typedef _PORT_INFO_1W  TPortInfo1W;

typedef _PORT_INFO_1A  TPortInfo1;

typedef _PORT_INFO_2A *PPortInfo2A;

typedef _PORT_INFO_2W *PPortInfo2W;

typedef _PORT_INFO_2A *PPortInfo2;

typedef _PORT_INFO_2A  TPortInfo2A;

typedef _PORT_INFO_2W  TPortInfo2W;

typedef _PORT_INFO_2A  TPortInfo2;

typedef _PORT_INFO_3A *PPortInfo3A;

typedef _PORT_INFO_3W *PPortInfo3W;

typedef _PORT_INFO_3A *PPortInfo3;

typedef _PORT_INFO_3A  TPortInfo3A;

typedef _PORT_INFO_3W  TPortInfo3W;

typedef _PORT_INFO_3A  TPortInfo3;

typedef _MONITOR_INFO_1A *PMonitorInfo1A;

typedef _MONITOR_INFO_1W *PMonitorInfo1W;

typedef _MONITOR_INFO_1A *PMonitorInfo1;

typedef _MONITOR_INFO_1A  TMonitorInfo1A;

typedef _MONITOR_INFO_1W  TMonitorInfo1W;

typedef _MONITOR_INFO_1A  TMonitorInfo1;

typedef _MONITOR_INFO_2A *PMonitorInfo2A;

typedef _MONITOR_INFO_2W *PMonitorInfo2W;

typedef _MONITOR_INFO_2A *PMonitorInfo2;

typedef _MONITOR_INFO_2A  TMonitorInfo2A;

typedef _MONITOR_INFO_2W  TMonitorInfo2W;

typedef _MONITOR_INFO_2A  TMonitorInfo2;

typedef _DATATYPES_INFO_1A *PDatatypesInfo1A;

typedef _DATATYPES_INFO_1W *PDatatypesInfo1W;

typedef _DATATYPES_INFO_1A *PDatatypesInfo1;

typedef _DATATYPES_INFO_1A  TDatatypesInfo1A;

typedef _DATATYPES_INFO_1W  TDatatypesInfo1W;

typedef _DATATYPES_INFO_1A  TDatatypesInfo1;

typedef _PRINTER_DEFAULTSA *PPrinterDefaultsA;

typedef _PRINTER_DEFAULTSW *PPrinterDefaultsW;

typedef _PRINTER_DEFAULTSA *PPrinterDefaults;

typedef _PRINTER_DEFAULTSA  TPrinterDefaultsA;

typedef _PRINTER_DEFAULTSW  TPrinterDefaultsW;

typedef _PRINTER_DEFAULTSA  TPrinterDefaults;

typedef _PRINTER_NOTIFY_OPTIONS_TYPE *PPrinterNotifyOptionsType;

typedef _PRINTER_NOTIFY_OPTIONS_TYPE  TPrinterNotifyOptionsType;

typedef _PRINTER_NOTIFY_OPTIONS *PPrinterNotifyOptions;

typedef _PRINTER_NOTIFY_OPTIONS  TPrinterNotifyOptions;

typedef _PRINTER_NOTIFY_INFO_DATA *PPrinterNotifyInfoData;

struct WinSpool__2
{
	unsigned cbBuf;
	void *pBuf;
} ;

struct WinSpool__1
{
	
	union
	{
		struct 
		{
			WinSpool__2 Data;
			
		};
		struct 
		{
			unsigned adwData[2];
			
		};
		
	};
} ;

typedef _PRINTER_NOTIFY_INFO_DATA  TPrinterNotifyInfoData;

typedef _PRINTER_NOTIFY_INFO *PPrinterNotifyInfo;

typedef _PRINTER_NOTIFY_INFO  TPrinterNotifyInfo;

typedef _PROVIDOR_INFO_1A *PProvidorInfo1A;

typedef _PROVIDOR_INFO_1W *PProvidorInfo1W;

typedef _PROVIDOR_INFO_1A *PProvidorInfo1;

typedef _PROVIDOR_INFO_1A  TProvidorInfo1A;

typedef _PROVIDOR_INFO_1W  TProvidorInfo1W;

typedef _PROVIDOR_INFO_1A  TProvidorInfo1;

//-- var, const, procedure ---------------------------------------------------
#define winspl "winspool.drv"

}	/* namespace Winspool */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Winspool;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WinSpool
