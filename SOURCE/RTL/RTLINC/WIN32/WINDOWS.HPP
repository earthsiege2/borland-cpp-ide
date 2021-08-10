//----------------------------------------------------------------------------
// Windows.hpp - bcbdcc32 generated hdr (DO NOT EDIT) rev: 0
// From: Windows.pas
//----------------------------------------------------------------------------
#ifndef WindowsHPP
#define WindowsHPP

#if !defined(WIN32_LEAN_AND_MEAN) && !defined(_WINDOWS_)
#ifndef VCL_FULL
#define WIN32_LEAN_AND_MEAN
#define _VCL_LEAN_AND_MEAN
#endif
#include <windows.h>
// Permit windows.h to be #include'd after windows.hpp, if only the
// lean and mean portion was included
#ifdef WIN32_LEAN_AND_MEAN
#undef WIN32_LEAN_AND_MEAN
#undef _INC_WINDOWS
#undef _WINDOWS_
#endif
#elif !defined(_WINDOWS_)
// If the user manually #define'd WIN32_LEAN_AND_MEAN, then the
// symbol should remain visible.
#ifdef WIN32_LEAN_AND_MEAN
#define _VCL_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

//----------------------------------------------------------------------------
#include <System.hpp>
#pragma warn -par
#pragma warn -hid 
#pragma warn -inl

namespace Windows
{
//-- type declarations -------------------------------------------------------

typedef wchar_t *PWChar;

typedef unsigned char *PByte;

typedef float *PSingle;

typedef long *PLongint;

typedef int *PInteger;

typedef int THandle;

typedef int *PHandle;

typedef _LARGE_INTEGER *PLargeInteger;

typedef _LARGE_INTEGER  TLargeInteger;

typedef _LIST_ENTRY *PListEntry;

typedef _LIST_ENTRY  TListEntry;

typedef _FLOATING_SAVE_AREA *PFloatingSaveArea;

typedef _FLOATING_SAVE_AREA  TFloatingSaveArea;

typedef _CONTEXT *PContext;

typedef _CONTEXT  TContext;

typedef _LDT_ENTRY *PLDTEntry;

typedef _LDT_ENTRY  TLDTEntry;

typedef _EXCEPTION_RECORD *PExceptionRecord;

typedef _EXCEPTION_RECORD  TExceptionRecord;

typedef _EXCEPTION_POINTERS  TExceptionPointers;

typedef _MEMORY_BASIC_INFORMATION *PMemoryBasicInformation;

typedef _MEMORY_BASIC_INFORMATION  TMemoryBasicInformation;

typedef _GENERIC_MAPPING *PGenericMapping;

typedef _GENERIC_MAPPING  TGenericMapping;

typedef _LUID_AND_ATTRIBUTES *PLUIDAndAttributes;

typedef _LUID_AND_ATTRIBUTES  TLUIDAndAttributes;

typedef _SID_IDENTIFIER_AUTHORITY *PSIDIdentifierAuthority;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _SID_IDENTIFIER_AUTHORITY  TSIDIdentifierAuthority;

typedef _SID_AND_ATTRIBUTES *PSIDAndAttributes;

typedef _SID_AND_ATTRIBUTES  TSIDAndAttributes;

typedef _ACL  TACL;

typedef _SECURITY_DESCRIPTOR *PSecurityDescriptor;

typedef _SECURITY_DESCRIPTOR  TSecurityDescriptor;

typedef _PRIVILEGE_SET *PPrivilegeSet;

typedef _PRIVILEGE_SET  TPrivilegeSet;

enum TSecurityImpersonationLevel { SecurityAnonymous, SecurityIdentification, SecurityImpersonation, 
	SecurityDelegation };

#pragma pack(push, 1)
#pragma pack(pop)

typedef _SECURITY_QUALITY_OF_SERVICE *PSecurityQualityOfService;

typedef _SECURITY_QUALITY_OF_SERVICE  TSecurityQualityOfService;

typedef _TOKEN_GROUPS *PTokenGroups;

typedef _TOKEN_GROUPS  TTokenGroups;

typedef _TOKEN_PRIVILEGES *PTokenPrivileges;

typedef _TOKEN_PRIVILEGES  TTokenPrivileges;

typedef int __stdcall (*TThreadStartRoutine)(void * lpThreadParameter);

typedef _RTL_CRITICAL_SECTION *PRTLCriticalSection;

typedef _RTL_CRITICAL_SECTION_DEBUG *PRTLCriticalSectionDebug;

typedef _RTL_CRITICAL_SECTION_DEBUG  TRTLCriticalSectionDebug;

typedef _RTL_CRITICAL_SECTION  TRTLCriticalSection;

typedef unsigned short TAtom;

typedef void *TFarProc;

typedef void *PROC_22;

typedef int HINST;

typedef long TColorRef;

typedef tagPOINT *PPoint;

typedef tagPOINT  TPoint;

struct TRect
{
	TRect() { }
	TRect(RECT& r) {
		Left = r.left;
		Top = r.top;
		Right = r.right;
		Bottom = r.bottom;
	}
	operator RECT() {
		RECT r;
		r.left = Left;
		r.top = Top;
		r.right = Right;
		r.bottom = Bottom;
		return r;
	}
	
	union
	{
		struct 
		{
			POINT TopLeft;
			POINT BottomRight;
			
		};
		struct 
		{
			int Left;
			int Top;
			int Right;
			int Bottom;
			
		};
		
	};
} ;

typedef TRect *PRect;

typedef tagSIZE *PSize;

typedef tagSIZE  TSize;

struct TSmallPoint
{
	short x;
	short y;
} ;

typedef TSmallPoint *PSmallPoint;

typedef _OVERLAPPED *POverlapped;

typedef _OVERLAPPED  TOverlapped;

typedef _SECURITY_ATTRIBUTES *PSecurityAttributes;

typedef _SECURITY_ATTRIBUTES  TSecurityAttributes;

typedef _PROCESS_INFORMATION *PProcessInformation;

typedef _PROCESS_INFORMATION  TProcessInformation;

typedef _FILETIME *PFileTime;

typedef _FILETIME  TFileTime;

typedef _SYSTEMTIME *PSystemTime;

typedef _SYSTEMTIME  TSystemTime;

typedef void *TFNThreadStartRoutine;

typedef _COMMPROP *PCommProp;

typedef _COMMPROP  TCommProp;

enum TComStateFlag { fCtlHold, fDsrHold, fRlsHold, fXoffHold, fXOffSent, fEof, fTxim };

typedef Set<TComStateFlag, fCtlHold, fTxim>  TComStateFlags;

typedef _COMSTAT  TComStat;

typedef _COMSTAT *PComStat;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _DCB  TDCB;

typedef _DCB *PDCB;

typedef _COMMTIMEOUTS *PCommTimeouts;

typedef _COMMTIMEOUTS  TCommTimeouts;

typedef _COMMCONFIG *PCommConfig;

typedef _COMMCONFIG  TCommConfig;

typedef _SYSTEM_INFO *PSystemInfo;

typedef _SYSTEM_INFO  TSystemInfo;

typedef _MEMORYSTATUS *PMemoryStatus;

typedef _MEMORYSTATUS  TMemoryStatus;

typedef _EXCEPTION_DEBUG_INFO *PExceptionDebugInfo;

typedef _EXCEPTION_DEBUG_INFO  TExceptionDebugInfo;

typedef _CREATE_THREAD_DEBUG_INFO *PCreateThreadDebugInfo;

typedef _CREATE_THREAD_DEBUG_INFO  TCreateThreadDebugInfo;

typedef _CREATE_PROCESS_DEBUG_INFO *PCreateProcessDebugInfo;

typedef _CREATE_PROCESS_DEBUG_INFO  TCreateProcessDebugInfo;

typedef _EXIT_THREAD_DEBUG_INFO *PExitThreadDebugInfo;

typedef _EXIT_THREAD_DEBUG_INFO  TExitThreadDebugInfo;

typedef _EXIT_PROCESS_DEBUG_INFO *PExitProcessDebugInfo;

typedef _EXIT_PROCESS_DEBUG_INFO  TExitProcessDebugInfo;

typedef _LOAD_DLL_DEBUG_INFO *PLoadDLLDebugInfo;

typedef _LOAD_DLL_DEBUG_INFO  TLoadDLLDebugInfo;

typedef _UNLOAD_DLL_DEBUG_INFO *PUnloadDLLDebugInfo;

typedef _UNLOAD_DLL_DEBUG_INFO  TUnloadDLLDebugInfo;

typedef _OUTPUT_DEBUG_STRING_INFO *POutputDebugStringInfo;

typedef _OUTPUT_DEBUG_STRING_INFO  TOutputDebugStringInfo;

typedef _RIP_INFO *PRIPInfo;

typedef _RIP_INFO  TRIPInfo;

typedef _DEBUG_EVENT *PDebugEvent;

typedef _DEBUG_EVENT  TDebugEvent;

typedef _OFSTRUCT *POFStruct;

typedef _OFSTRUCT  TOFStruct;

typedef char *MakeIntAtomA;

typedef wchar_t *MakeIntAtomW;

typedef char *MakeIntAtom;

typedef _PROCESS_HEAP_ENTRY *PProcessHeapEntry;

typedef _PROCESS_HEAP_ENTRY  TProcessHeapEntry;

typedef void *TFNTopLevelExceptionFilter;

typedef int TWOHandleArray[64];

typedef TWOHandleArray *PWOHandleArray;

typedef _BY_HANDLE_FILE_INFORMATION *PByHandleFileInformation;

typedef _BY_HANDLE_FILE_INFORMATION  TByHandleFileInformation;

typedef _TIME_ZONE_INFORMATION *PTimeZoneInformation;

typedef _TIME_ZONE_INFORMATION  TTimeZoneInformation;

typedef _WIN32_STREAM_ID *PWIN32StreamID;

typedef _WIN32_STREAM_ID  TWIN32StreamID;

typedef _STARTUPINFOA *PStartupInfo;

typedef _STARTUPINFOA  TStartupInfo;

typedef _WIN32_FIND_DATAA *PWin32FindDataA;

typedef _WIN32_FIND_DATAW *PWin32FindDataW;

typedef _WIN32_FIND_DATAA *PWin32FindData;

typedef _WIN32_FIND_DATAA  TWin32FindDataA;

typedef _WIN32_FIND_DATAW  TWin32FindDataW;

typedef _WIN32_FIND_DATAA  TWin32FindData;

typedef _OSVERSIONINFOA *POSVersionInfoA;

typedef _OSVERSIONINFOW *POSVersionInfoW;

typedef _OSVERSIONINFOA *POSVersionInfo;

typedef _OSVERSIONINFOA  TOSVersionInfoA;

typedef _OSVERSIONINFOW  TOSVersionInfoW;

typedef _OSVERSIONINFOA  TOSVersionInfo;

typedef _SYSTEM_POWER_STATUS *PSystemPowerStatus;

typedef _SYSTEM_POWER_STATUS  TSystemPowerStatus;

typedef tagXFORM *PXForm;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagXFORM  TXForm;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBITMAP *PBitmap;

typedef tagBITMAP  TBitmap;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagRGBTRIPLE  TRGBTriple;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagRGBQUAD *PRGBQuad;

typedef tagRGBQUAD  TRGBQuad;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCIEXYZ *PCIEXYZ;

typedef tagCIEXYZ  TCIEXYZ;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagICEXYZTRIPLE *PCIEXYZTriple;

typedef tagICEXYZTRIPLE  TCIEXYZTriple;

typedef tagLOGCOLORSPACEA *PLogColorSpaceA;

typedef tagLOGCOLORSPACEW *PLogColorSpaceW;

typedef tagLOGCOLORSPACEA *PLogColorSpace;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGCOLORSPACEA  TLogColorSpaceA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGCOLORSPACEW  TLogColorSpaceW;

typedef tagLOGCOLORSPACEA  TLogColorSpace;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBITMAPCOREHEADER *PBitmapCoreHeader;

typedef tagBITMAPCOREHEADER  TBitmapCoreHeader;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBITMAPINFOHEADER *PBitmapInfoHeader;

typedef tagBITMAPINFOHEADER  TBitmapInfoHeader;

#pragma pack(push, 1)
#pragma pack(pop)

typedef BITMAPV4HEADER *PBitmapV4Header;

typedef BITMAPV4HEADER  TBitmapV4Header;

typedef tagBITMAPINFO *PBitmapInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBITMAPINFO  TBitmapInfo;

typedef tagBITMAPCOREINFO *PBitmapCoreInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBITMAPCOREINFO  TBitmapCoreInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBITMAPFILEHEADER *PBitmapFileHeader;

typedef tagBITMAPFILEHEADER  TBitmapFileHeader;

typedef tagFONTSIGNATURE *PFontSignature;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagFONTSIGNATURE  TFontSignature;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCHARSETINFO *PCharsetInfo;

typedef tagCHARSETINFO  TCharsetInfo;

typedef tagLOCALESIGNATURE *PLocaleSignature;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOCALESIGNATURE  TLocaleSignature;

typedef tagHANDLETABLE *PHandleTable;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHANDLETABLE  THandleTable;

typedef tagMETARECORD *PMetaRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMETARECORD  TMetaRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMETAFILEPICT *PMetafilePict;

typedef tagMETAFILEPICT  TMetafilePict;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMETAHEADER *PMetaHeader;

typedef tagMETAHEADER  TMetaHeader;

typedef tagENHMETARECORD *PEnhMetaRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagENHMETARECORD  TEnhMetaRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagENHMETAHEADER *PEnhMetaHeader;

typedef tagENHMETAHEADER  TEnhMetaHeader;

typedef tagTEXTMETRICA *PTextMetricA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagTEXTMETRICW *PTextMetricW;

typedef tagTEXTMETRICA *PTextMetric;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagTEXTMETRICA  TTextMetricA;

typedef tagTEXTMETRICW  TTextMetricW;

typedef tagTEXTMETRICA  TTextMetric;

typedef tagNEWTEXTMETRICA *PNewTextMetricA;

typedef tagNEWTEXTMETRICW *PNewTextMetricW;

typedef tagNEWTEXTMETRICA *PNewTextMetric;

typedef tagNEWTEXTMETRICA  TNewTextMetricA;

typedef tagNEWTEXTMETRICW  TNewTextMetricW;

typedef tagNEWTEXTMETRICA  TNewTextMetric;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagNEWTEXTMETRICEXA *PNewTextMetricEx;

typedef tagNEWTEXTMETRICEXA  TNewTextMetricEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPELARRAY *PPelArray;

typedef tagPELARRAY  TPelArray;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGBRUSH *PLogBrush;

typedef tagLOGBRUSH  TLogBrush;

typedef tagLOGBRUSH *PPattern;

typedef tagLOGBRUSH  TPattern;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGPEN *PLogPen;

typedef tagLOGPEN  TLogPen;

typedef tagLOGPEN *PExtLogPen;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEXTLOGPEN  TExtLogPen;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPALETTEENTRY *PPaletteEntry;

typedef tagPALETTEENTRY  TPaletteEntry;

typedef tagLOGPALETTE *PLogPalette;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGPALETTE  TLogPalette;

typedef tagLOGFONTA *PLogFontA;

typedef tagLOGFONTW *PLogFontW;

typedef tagLOGFONTA *PLogFont;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGFONTA  TLogFontA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagLOGFONTW  TLogFontW;

typedef tagLOGFONTA  TLogFont;

typedef tagENUMLOGFONTA *PEnumLogFontA;

typedef tagENUMLOGFONTW *PEnumLogFontW;

typedef tagENUMLOGFONTA *PEnumLogFont;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagENUMLOGFONTA  TEnumLogFontA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagENUMLOGFONTW  TEnumLogFontW;

typedef tagENUMLOGFONTA  TEnumLogFont;

typedef tagENUMLOGFONTEXA *PEnumLogFontEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagENUMLOGFONTEXA  TEnumLogFontEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPANOSE *PPanose;

typedef tagPANOSE  TPanose;

typedef tagEXTLOGFONTA *PExtLogFontA;

typedef tagEXTLOGFONTW *PExtLogFontW;

typedef tagEXTLOGFONTA *PExtLogFont;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEXTLOGFONTA  TExtLogFontA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEXTLOGFONTW  TExtLogFontW;

typedef tagEXTLOGFONTA  TExtLogFont;

typedef _devicemodeA *PDeviceModeA;

typedef _devicemodeW *PDeviceModeW;

typedef _devicemodeA *PDeviceMode;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _devicemodeA  TDeviceModeA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _devicemodeW  TDeviceModeW;

typedef _devicemodeA  TDeviceMode;

typedef _devicemodeA *PDevMode;

typedef _devicemodeA  TDevMode;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _RGNDATAHEADER *PRgnDataHeader;

typedef _RGNDATAHEADER  TRgnDataHeader;

typedef _RGNDATA *PRgnData;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _RGNDATA  TRgnData;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _ABC  TABC;

typedef _ABCFLOAT *PABCFloat;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _ABCFLOAT  TABCFloat;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _OUTLINETEXTMETRICA *POutlineTextmetricA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _OUTLINETEXTMETRICW *POutlineTextmetricW;

typedef _OUTLINETEXTMETRICA *POutlineTextmetric;

typedef _OUTLINETEXTMETRICA  TOutlineTextmetricA;

typedef _OUTLINETEXTMETRICW  TOutlineTextmetricW;

typedef _OUTLINETEXTMETRICA  TOutlineTextmetric;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPOLYTEXTA *PPolyTextA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPOLYTEXTW *PPolyTextW;

typedef tagPOLYTEXTA *PPolyText;

typedef tagPOLYTEXTA  TPolyTextA;

typedef tagPOLYTEXTW  TPolyTextW;

typedef tagPOLYTEXTA  TPolyText;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _FIXED  TFixed;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _MAT2 *PMat2;

typedef _MAT2  TMat2;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _GLYPHMETRICS *PGlyphMetrics;

typedef _GLYPHMETRICS  TGlyphMetrics;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPOINTFX *PPointfx;

typedef tagPOINTFX  TPointfx;

typedef tagTTPOLYCURVE *PTTPolyCurve;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagTTPOLYCURVE  TTTPolyCurve;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagTTPOLYGONHEADER *PTTPolygonHeader;

typedef tagTTPOLYGONHEADER  TTTPolygonHeader;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagGCP_RESULTSA *PGCPResultsA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagGCP_RESULTSW *PGCPResultsW;

typedef tagGCP_RESULTSA *PGCPResults;

typedef tagGCP_RESULTSA  TGCPResultsA;

typedef tagGCP_RESULTSW  TGCPResultsW;

typedef tagGCP_RESULTSA  TGCPResults;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _RASTERIZER_STATUS *PRasterizerStatus;

typedef _RASTERIZER_STATUS  TRasterizerStatus;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPIXELFORMATDESCRIPTOR *PPixelFormatDescriptor;

typedef tagPIXELFORMATDESCRIPTOR  TPixelFormatDescriptor;

typedef void *TFNOldFontEnumProcA;

typedef void *TFNOldFontEnumProcW;

typedef void *TFNOldFontEnumProc;

typedef void *TFNGObjEnumProc;

typedef void *TFNLineDDAProc;

typedef void *TFNFontEnumProcA;

typedef void *TFNFontEnumProcW;

typedef void *TFNFontEnumProc;

typedef int __stdcall (*TFNDevMode)(HWND Wnd, HINST Driver, DEVMODEA &DevModeOutput, char * DeciveName
	, char * Port, DEVMODEA &DevModeInput, char * Profile, int Mode);

typedef int __stdcall (*TFNDevCaps)(char * DeviceName, char * Port, int Index, char * Output, DEVMODEA 
	&DevMode);

typedef void *TFNMFEnumProc;

typedef void *TFNEnhMFEnumProc;

typedef tagDIBSECTION *PDIBSection;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagDIBSECTION  TDIBSection;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCOLORADJUSTMENT *PColorAdjustment;

typedef tagCOLORADJUSTMENT  TColorAdjustment;

typedef DWORD __stdcall (*TFNAbortProc)(HDC DC, int p2);

#pragma pack(push, 1)
#pragma pack(pop)

typedef _DOCINFOA *PDocInfoA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _DOCINFOW *PDocInfoW;

typedef _DOCINFOA *PDocInfo;

typedef _DOCINFOA  TDocInfoA;

typedef _DOCINFOW  TDocInfoW;

typedef _DOCINFOA  TDocInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagKERNINGPAIR *PKerningPair;

typedef tagKERNINGPAIR  TKerningPair;

typedef void *TFNICMEnumProc;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMR  TEMR;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRTEXT *PEMRText;

typedef tagEMRTEXT  TEMRText;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagABORTPATH *PAbortPath;

typedef tagABORTPATH  TAbortPath;

typedef tagABORTPATH  TEMRAbortPath;

typedef tagABORTPATH *PEMRAbortPath;

typedef tagABORTPATH  TEMRBeginPath;

typedef tagABORTPATH *PEMRBeginPath;

typedef tagABORTPATH  TEMREndPath;

typedef tagABORTPATH *PEMREndPath;

typedef tagABORTPATH  TEMRCloseFigure;

typedef tagABORTPATH *PEMRCloseFigure;

typedef tagABORTPATH  TEMRFlattenPath;

typedef tagABORTPATH *PEMRFlattenPath;

typedef tagABORTPATH  TEMRWidenPath;

typedef tagABORTPATH *PEMRWidenPath;

typedef tagABORTPATH  TEMRSetMetaRgn;

typedef tagABORTPATH *PEMRSetMetaRgn;

typedef tagABORTPATH  TEMRSaveDC;

typedef tagABORTPATH *PEMRSaveDC;

typedef tagABORTPATH  TEMRRealizePalette;

typedef tagABORTPATH *PEMRRealizePalette;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSELECTCLIPPATH *PEMRSelectclippath;

typedef tagEMRSELECTCLIPPATH  TEMRSelectClipPath;

typedef tagEMRSELECTCLIPPATH  TEMRSetBkMode;

typedef tagEMRSELECTCLIPPATH *PEMRSetBkMode;

typedef tagEMRSELECTCLIPPATH  TEMRSetMapMode;

typedef tagEMRSELECTCLIPPATH *PEMRSetMapMode;

typedef tagEMRSELECTCLIPPATH  TEMRSetPolyFillMode;

typedef tagEMRSELECTCLIPPATH *PEMRSetPolyFillMode;

typedef tagEMRSELECTCLIPPATH  TEMRSetRop2;

typedef tagEMRSELECTCLIPPATH *PEMRSetRop2;

typedef tagEMRSELECTCLIPPATH  TEMRSetStretchBltMode;

typedef tagEMRSELECTCLIPPATH *PEMRSetStretchBltMode;

typedef tagEMRSELECTCLIPPATH  TEMRSetICMMode;

typedef tagEMRSELECTCLIPPATH *PEMRSetICMMode;

typedef tagEMRSELECTCLIPPATH  TEMRSetTextAlign;

typedef tagEMRSELECTCLIPPATH *PEMRSetTextAlign;

typedef tagEMRSETMITERLIMIT *PEMRSetMiterLimit;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETMITERLIMIT  TEMRSetMiterLimit;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRRESTOREDC *PEMRRestoreDC;

typedef tagEMRRESTOREDC  TEMRRestoreDC;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETARCDIRECTION *PEMRSetArcDirection;

typedef tagEMRSETARCDIRECTION  TEMRSetArcDirection;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETMAPPERFLAGS *PEMRSetMapperFlags;

typedef tagEMRSETMAPPERFLAGS  TEMRSetMapperFlags;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETTEXTCOLOR *PEMRSetTextColor;

typedef tagEMRSETTEXTCOLOR  TEMRSetTextColor;

typedef tagEMRSETTEXTCOLOR  TEMRSetBkColor;

typedef tagEMRSETTEXTCOLOR *PEMRSetBkColor;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSELECTOBJECT *PEMRSelectObject;

typedef tagEMRSELECTOBJECT  TEMRSelectObject;

typedef tagEMRSELECTOBJECT  EMRDeleteObject;

typedef tagEMRSELECTOBJECT *PEMRDeleteObject;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSELECTCOLORSPACE *PEMRSelectColorSpace;

typedef tagEMRSELECTCOLORSPACE  TEMRSelectColorSpace;

typedef tagEMRSELECTCOLORSPACE  EMRDeleteColorSpace;

typedef tagEMRSELECTCOLORSPACE *PEMRDeleteColorSpace;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSELECTPALETTE *PEMRSelectPalette;

typedef tagEMRSELECTPALETTE  TEMRSelectPalette;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRRESIZEPALETTE *PEMRResizePalette;

typedef tagEMRRESIZEPALETTE  TEMRResizePalette;

typedef tagEMRSETPALETTEENTRIES *PEMRSetPaletteEntries;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETPALETTEENTRIES  TEMRSetPaletteEntries;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETCOLORADJUSTMENT *PEMRSetColorAdjustment;

typedef tagEMRSETCOLORADJUSTMENT  TEMRSetColorAdjustment;

typedef tagEMRGDICOMMENT *PEMRGDIComment;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRGDICOMMENT  TEMRGDIComment;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREOF  TEMREOF;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRLINETO *PEMRLineTo;

typedef tagEMRLINETO  TEMRLineTo;

typedef tagEMRLINETO  EMRMoveToEx;

typedef tagEMRLINETO *PEMRMoveToEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMROFFSETCLIPRGN *PEMROffsetClipRgn;

typedef tagEMROFFSETCLIPRGN  TEMROffsetClipRgn;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRFILLPATH *PEMRFillPath;

typedef tagEMRFILLPATH  TEMRFillPath;

typedef tagEMRFILLPATH  EMRStrokeAndFillPath;

typedef tagEMRFILLPATH *PEMRStrokeAndFillPath;

typedef tagEMRFILLPATH  EMRStrokePath;

typedef tagEMRFILLPATH *PEMRStrokePath;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREXCLUDECLIPRECT *PEMRExcludeClipRect;

typedef tagEMREXCLUDECLIPRECT  TEMRExcludeClipRect;

typedef tagEMREXCLUDECLIPRECT  EMRIntersectClipRect;

typedef tagEMREXCLUDECLIPRECT *PEMRIntersectClipRect;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETVIEWPORTORGEX *PEMRSetViewportOrgEx;

typedef tagEMRSETVIEWPORTORGEX  TEMRSetViewportOrgEx;

typedef tagEMRSETVIEWPORTORGEX  EMRSetWindowOrgEx;

typedef tagEMRSETVIEWPORTORGEX *PEMRSetWindowOrgEx;

typedef tagEMRSETVIEWPORTORGEX  EMRSetBrushOrgEx;

typedef tagEMRSETVIEWPORTORGEX *PEMRSetBrushOrgEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETVIEWPORTEXTEX *PEMRSetViewportExtEx;

typedef tagEMRSETVIEWPORTEXTEX  TEMRSetViewportExtEx;

typedef tagEMRSETVIEWPORTEXTEX  EMRSetWindowExtEx;

typedef tagEMRSETVIEWPORTEXTEX *PEMRSetWindowExtEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSCALEVIEWPORTEXTEX *PEMRScaleViewportExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX  TEMRScaleViewportExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX  EMRScaleWindowExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX *PEMRScaleWindowExtEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETWORLDTRANSFORM *PEMRSetWorldTransform;

typedef tagEMRSETWORLDTRANSFORM  TEMRSetWorldTransform;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRMODIFYWORLDTRANSFORM *PEMRModifyWorldTransform;

typedef tagEMRMODIFYWORLDTRANSFORM  TEMRModifyWorldTransform;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETPIXELV *PEMRSetPixelV;

typedef tagEMRSETPIXELV  TEMRSetPixelV;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREXTFLOODFILL *PEMRExtFloodFill;

typedef tagEMREXTFLOODFILL  TEMRExtFloodFill;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRELLIPSE *PEMREllipse;

typedef tagEMRELLIPSE  TEMREllipse;

typedef tagEMRELLIPSE  EMRRectangle;

typedef tagEMRELLIPSE *PEMRRectangle;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRROUNDRECT *PEMRRoundRect;

typedef tagEMRROUNDRECT  TEMRRoundRect;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRARC *PEMRArc;

typedef tagEMRARC  TEMRArc;

typedef tagEMRARC  EMRArcTo;

typedef tagEMRARC *PEMRArcTo;

typedef tagEMRARC  EMRChord;

typedef tagEMRARC *PEMRChord;

typedef tagEMRARC  EMRPie;

typedef tagEMRARC *PEMRPie;

typedef tagEMRANGLEARC *PEMRAngleArc;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRANGLEARC  TEMRAngleArc;

typedef tagEMRPOLYLINE *PEMRPolyline;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYLINE  TEMRPolyline;

typedef tagEMRPOLYLINE  EMRPolyBezier;

typedef tagEMRPOLYLINE *PEMRPolyBezier;

typedef tagEMRPOLYLINE  EMRPolyGON;

typedef tagEMRPOLYLINE *PEMRPolyGON;

typedef tagEMRPOLYLINE  EMRPolyBezierTo;

typedef tagEMRPOLYLINE *PEMRPolyBezierTo;

typedef tagEMRPOLYLINE  EMRPolyLineTo;

typedef tagEMRPOLYLINE *PEMRPolyLineTo;

typedef tagEMRPOLYLINE16 *PEMRPolyline16;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYLINE16  TEMRPolyline16;

typedef tagEMRPOLYLINE16  EMRPolyBezier16;

typedef tagEMRPOLYLINE16 *PEMRPolyBezier16;

typedef tagEMRPOLYLINE16  EMRPolygon16;

typedef tagEMRPOLYLINE16 *PEMRPolygon16;

typedef tagEMRPOLYLINE16  EMRPolyBezierTo16;

typedef tagEMRPOLYLINE16 *PEMRPolyBezierTo16;

typedef tagEMRPOLYLINE16  EMRPolyLineTo16;

typedef tagEMRPOLYLINE16 *PEMRPolyLineTo16;

typedef tagEMRPOLYDRAW *PEMRPolyDraw;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYDRAW  TEMRPolyDraw;

typedef tagEMRPOLYDRAW16 *PEMRPolyDraw16;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYDRAW16  TEMRPolyDraw16;

typedef tagEMRPOLYPOLYLINE *PEMRPolyPolyline;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYPOLYLINE  TEMRPolyPolyline;

typedef tagEMRPOLYPOLYLINE  EMRPolyPolygon;

typedef tagEMRPOLYPOLYLINE *PEMRPolyPolygon;

typedef tagEMRPOLYPOLYLINE16 *PEMRPolyPolyline16;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYPOLYLINE16  TEMRPolyPolyline16;

typedef tagEMRPOLYPOLYLINE16  EMRPolyPolygon16;

typedef tagEMRPOLYPOLYLINE16 *PEMRPolyPolygon16;

typedef tagEMRINVERTRGN *PEMRInvertRgn;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRINVERTRGN  TEMRInvertRgn;

typedef tagEMRINVERTRGN  EMRPaintRgn;

typedef tagEMRINVERTRGN *PEMRPaintRgn;

typedef tagEMRFILLRGN *PEMRFillRgn;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRFILLRGN  TEMRFillRgn;

typedef tagEMRFRAMERGN *PEMRFrameRgn;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRFRAMERGN  TEMRFrameRgn;

typedef tagEMREXTSELECTCLIPRGN *PEMRExtSelectClipRgn;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREXTSELECTCLIPRGN  TEMRExtSelectClipRgn;

typedef tagEMREXTTEXTOUTA *PEMRExtTextOut;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREXTTEXTOUTA  TEMRExtTextOut;

typedef tagEMRPOLYTEXTOUTA *PEMRPolyTextOut;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPOLYTEXTOUTA  TEMRPolyTextOut;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRBITBLT *PEMRBitBlt;

typedef tagEMRBITBLT  TEMRBitBlt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSTRETCHBLT *PEMRStretchBlt;

typedef tagEMRSTRETCHBLT  TEMRStretchBlt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRMASKBLT *PEMRMaskBlt;

typedef tagEMRMASKBLT  TEMRMaskBlt;

typedef tagEMRPLGBLT *PEMRPLGBlt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRPLGBLT  TEMRPLGBlt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSETDIBITSTODEVICE *PEMRSetDIBitsToDevice;

typedef tagEMRSETDIBITSTODEVICE  TEMRSetDIBitsToDevice;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRSTRETCHDIBITS *PEMRStretchDIBits;

typedef tagEMRSTRETCHDIBITS  TEMRStretchDIBits;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREXTCREATEFONTINDIRECTW *PEMRExtCreateFontIndirect;

typedef tagEMREXTCREATEFONTINDIRECTW  TEMRExtCreateFontIndirect;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRCREATEPALETTE *PEMRCreatePalette;

typedef tagEMRCREATEPALETTE  TEMRCreatePalette;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRCREATECOLORSPACE *PEMRCreateColorSpace;

typedef tagEMRCREATECOLORSPACE  TEMRCreateColorSpace;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRCREATEPEN *PEMRCreatePen;

typedef tagEMRCREATEPEN  TEMRCreatePen;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMREXTCREATEPEN *PEMRExtCreatePen;

typedef tagEMREXTCREATEPEN  TEMRExtCreatePen;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRCREATEBRUSHINDIRECT *PEMRCreateBrushIndirect;

typedef tagEMRCREATEBRUSHINDIRECT  TEMRCreateBrushIndirect;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRCREATEMONOBRUSH *PEMRCreateMonoBrush;

typedef tagEMRCREATEMONOBRUSH  TEMRCreateMonoBrush;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRCREATEDIBPATTERNBRUSHPT *PEMRCreateDIBPatternBrushPt;

typedef tagEMRCREATEDIBPATTERNBRUSHPT  TEMRCreateDIBPatternBrushPt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEMRFORMAT *PEMRFormat;

typedef tagEMRFORMAT  TEMRFormat;

typedef _POINTFLOAT *PPointFloat;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _POINTFLOAT  TPointFloat;

typedef _GLYPHMETRICSFLOAT *PGlyphMetricsFloat;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _GLYPHMETRICSFLOAT  TGlyphMetricsFloat;

typedef void *PMENUTEMPLATE;

typedef void *TFNWndProc;

typedef void *TFNDlgProc;

typedef void *TFNTimerProc;

typedef void *TFNGrayStringProc;

typedef void *TFNWndEnumProc;

typedef void *TFNSendAsyncProc;

typedef void *TFNDrawStateProc;

typedef long __stdcall (*TFNHookProc)(int code, long wparam, long lparam);

typedef void *TFNPropEnumProc;

typedef void *TFNPropEnumProcEx;

typedef void *TFNEditWordBreakProc;

typedef void *TFNNameEnumProc;

typedef void *TFNWinStaEnumProc;

typedef void *TFNDeskTopEnumProc;

typedef char *MakeIntResourceA;

typedef wchar_t *MakeIntResourceW;

typedef char *MakeIntResource;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCREATESTRUCTA *PCreateStructA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCREATESTRUCTW *PCreateStructW;

typedef tagCREATESTRUCTA *PCreateStruct;

typedef tagCREATESTRUCTA  TCreateStructA;

typedef tagCREATESTRUCTW  TCreateStructW;

typedef tagCREATESTRUCTA  TCreateStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCBT_CREATEWNDA *PCBTCreateWnd;

typedef tagCBT_CREATEWNDA  TCBTCreateWnd;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCBTACTIVATESTRUCT *PCBTActivateStruct;

typedef tagCBTACTIVATESTRUCT  TCBTActivateStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagEVENTMSG *PEventMsg;

typedef tagEVENTMSG  TEventMsg;

typedef tagEVENTMSG *PEventMsgMsg;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCWPSTRUCT *PCWPStruct;

typedef tagCWPSTRUCT  TCWPStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCWPRETSTRUCT *PCWPRetStruct;

typedef tagCWPRETSTRUCT  TCWPRetStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagDEBUGHOOKINFO *PDebugHookInfo;

typedef tagDEBUGHOOKINFO  TDebugHookInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMOUSEHOOKSTRUCT *PMouseHookStruct;

typedef tagMOUSEHOOKSTRUCT  TMouseHookStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHARDWAREHOOKSTRUCT *PHardwareHookStruct;

typedef tagHARDWAREHOOKSTRUCT  THardwareHookStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagUSEROBJECTFLAGS *PUserObjectFlags;

typedef tagUSEROBJECTFLAGS  TUserObjectFlags;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagWNDCLASSEXA *PWndClassExA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagWNDCLASSEXW *PWndClassExW;

typedef tagWNDCLASSEXA *PWndClassEx;

typedef tagWNDCLASSEXA  TWndClassExA;

typedef tagWNDCLASSEXW  TWndClassExW;

typedef tagWNDCLASSEXA  TWndClassEx;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagWNDCLASSA *PWndClassA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagWNDCLASSW *PWndClassW;

typedef tagWNDCLASSA *PWndClass;

typedef tagWNDCLASSA  TWndClassA;

typedef tagWNDCLASSW  TWndClassW;

typedef tagWNDCLASSA  TWndClass;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMSG *PMsg;

typedef tagMSG  TMsg;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMINMAXINFO *PMinMaxInfo;

typedef tagMINMAXINFO  TMinMaxInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCOPYDATASTRUCT *PCopyDataStruct;

typedef tagCOPYDATASTRUCT  TCopyDataStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMDINEXTMENU *PMDINextMenu;

typedef tagMDINEXTMENU  TMDINextMenu;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagWINDOWPOS *PWindowPos;

typedef tagWINDOWPOS  TWindowPos;

typedef tagNCCALCSIZE_PARAMS *PNCCalcSizeParams;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagNCCALCSIZE_PARAMS  TNCCalcSizeParams;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagACCEL *PAccel;

typedef tagACCEL  TAccel;

typedef tagPAINTSTRUCT *PPaintStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagPAINTSTRUCT  TPaintStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagWINDOWPLACEMENT *PWindowPlacement;

typedef tagWINDOWPLACEMENT  TWindowPlacement;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagNMHDR *PNMHdr;

typedef tagNMHDR  TNMHdr;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSTYLESTRUCT *PStyleStruct;

typedef tagSTYLESTRUCT  TStyleStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMEASUREITEMSTRUCT *PMeasureItemStruct;

typedef tagMEASUREITEMSTRUCT  TMeasureItemStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagDRAWITEMSTRUCT *PDrawItemStruct;

typedef tagDRAWITEMSTRUCT  TDrawItemStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagDELETEITEMSTRUCT *PDeleteItemStruct;

typedef tagDELETEITEMSTRUCT  TDeleteItemStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCOMPAREITEMSTRUCT *PCompareItemStruct;

typedef tagCOMPAREITEMSTRUCT  TCompareItemStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagBROADCASTSYSMSG *PBroadcastSysMsg;

typedef tagBROADCASTSYSMSG  TBroadcastSysMsg;

#pragma pack(push, 1)
#pragma pack(pop)

typedef DLGTEMPLATE *PDlgTemplate;

typedef DLGTEMPLATE  TDlgTemplate;

#pragma pack(push, 1)
#pragma pack(pop)

typedef DLGITEMTEMPLATE *PDlgItemTemplate;

typedef DLGITEMTEMPLATE  TDlgItemTemplate;

typedef unsigned char TKeyboardState[256];

typedef TKeyboardState *PKeyboardState;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagTPMPARAMS *PTPMParams;

typedef tagTPMPARAMS  TTPMParams;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMENUITEMINFOA *PMenuItemInfoA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMENUITEMINFOW *PMenuItemInfoW;

typedef tagMENUITEMINFOA *PMenuItemInfo;

typedef tagMENUITEMINFOA  TMenuItemInfoA;

typedef tagMENUITEMINFOW  TMenuItemInfoW;

typedef tagMENUITEMINFOA  TMenuItemInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagDROPSTRUCT *PDropStruct;

typedef tagDROPSTRUCT  TDropStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagDRAWTEXTPARAMS *PDrawTextParams;

typedef tagDRAWTEXTPARAMS  TDrawTextParams;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHELPINFO *PHelpInfo;

typedef tagHELPINFO  THelpInfo;

typedef void __fastcall (*TPRMsgBoxCallback)(tagHELPINFO &lpHelpInfo);

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMSGBOXPARAMSA *PMsgBoxParamsA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMSGBOXPARAMSW *PMsgBoxParamsW;

typedef tagMSGBOXPARAMSA *PMsgBoxParams;

typedef tagMSGBOXPARAMSA  TMsgBoxParamsA;

typedef tagMSGBOXPARAMSW  TMsgBoxParamsW;

typedef tagMSGBOXPARAMSA  TMsgBoxParams;

#pragma pack(push, 1)
#pragma pack(pop)

typedef MENUITEMTEMPLATEHEADER *PMenuItemTemplateHeader;

typedef MENUITEMTEMPLATEHEADER  TMenuItemTemplateHeader;

typedef MENUITEMTEMPLATE *PMenuItemTemplate;

#pragma pack(push, 1)
#pragma pack(pop)

typedef MENUITEMTEMPLATE  TMenuItemTemplate;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _ICONINFO *PIconInfo;

typedef _ICONINFO  TIconInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCURSORSHAPE *PCursorShape;

typedef tagCURSORSHAPE  TCursorShape;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSCROLLINFO  TScrollInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMDICREATESTRUCTA *PMDICreateStructA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMDICREATESTRUCTW *PMDICreateStructW;

typedef tagMDICREATESTRUCTA *PMDICreateStruct;

typedef tagMDICREATESTRUCTA  TMDICreateStructA;

typedef tagMDICREATESTRUCTW  TMDICreateStructW;

typedef tagMDICREATESTRUCTA  TMDICreateStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagCLIENTCREATESTRUCT *PClientCreateStruct;

typedef tagCLIENTCREATESTRUCT  TClientCreateStruct;

typedef tagMULTIKEYHELPA *PMultiKeyHelpA;

typedef tagMULTIKEYHELPW *PMultiKeyHelpW;

typedef tagMULTIKEYHELPA *PMultiKeyHelp;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMULTIKEYHELPA  TMultiKeyHelpA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMULTIKEYHELPW  TMultiKeyHelpW;

typedef tagMULTIKEYHELPA  TMultiKeyHelp;

typedef tagHELPWININFOA *PHelpWinInfoA;

typedef tagHELPWININFOW *PHelpWinInfoW;

typedef tagHELPWININFOA *PHelpWinInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHELPWININFOA  THelpWinInfoA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHELPWININFOW  THelpWinInfoW;

typedef tagHELPWININFOA  THelpWinInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagNONCLIENTMETRICSA *PNonClientMetrics;

typedef tagNONCLIENTMETRICSA  TNonClientMetrics;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMINIMIZEDMETRICS *PMinimizedMetrics;

typedef tagMINIMIZEDMETRICS  TMinimizedMetrics;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagICONMETRICSA *PIconMetrics;

typedef tagICONMETRICSA  TIconMetrics;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagANIMATIONINFO *PAnimationInfo;

typedef tagANIMATIONINFO  TAnimationInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSERIALKEYSA *PSerialKeysA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSERIALKEYSW *PSerialKeysW;

typedef tagSERIALKEYSA *PSerialKeys;

typedef tagSERIALKEYSA  TSerialKeysA;

typedef tagSERIALKEYSW  TSerialKeysW;

typedef tagSERIALKEYSA  TSerialKeys;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHIGHCONTRASTA *PHighContrastA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagHIGHCONTRASTW *PHighContrastW;

typedef tagHIGHCONTRASTA *PHighContrast;

typedef tagHIGHCONTRASTA  THighContrastA;

typedef tagHIGHCONTRASTW  THighContrastW;

typedef tagHIGHCONTRASTA  THighContrast;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagFILTERKEYS *PFilterKeys;

typedef tagFILTERKEYS  TFilterKeys;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSTICKYKEYS *PStickyKeys;

typedef tagSTICKYKEYS  TStickyKeys;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagMOUSEKEYS *PMouseKeys;

typedef tagMOUSEKEYS  TMouseKeys;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagACCESSTIMEOUT *PAccessTimeout;

typedef tagACCESSTIMEOUT  TAccessTimeout;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSOUNDSENTRYA *PSoundsEntryA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagSOUNDSENTRYW *PSoundsEntryW;

typedef tagSOUNDSENTRYA *PSoundsEntry;

typedef tagSOUNDSENTRYA  TSoundsEntryA;

typedef tagSOUNDSENTRYW  TSoundsEntryW;

typedef tagSOUNDSENTRYA  TSoundsEntry;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagTOGGLEKEYS *PToggleKeys;

typedef tagTOGGLEKEYS  TToggleKeys;

typedef _cpinfo *PCPInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _cpinfo  TCPInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _numberfmtA *PNumberFmtA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _numberfmtW *PNumberFmtW;

typedef _numberfmtA *PNumberFmt;

typedef _numberfmtA  TNumberFmtA;

typedef _numberfmtW  TNumberFmtW;

typedef _numberfmtA  TNumberFmt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _currencyfmtA *PCurrencyFmtA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _currencyfmtW *PCurrencyFmtW;

typedef _currencyfmtA *PCurrencyFmt;

typedef _currencyfmtA  TCurrencyFmtA;

typedef _currencyfmtW  TCurrencyFmtW;

typedef _currencyfmtA  TCurrencyFmt;

typedef void *TFNLocaleEnumProc;

typedef void *TFNCodepageEnumProc;

typedef void *TFNDateFmtEnumProc;

typedef void *TFNTimeFmtEnumProc;

typedef void *TFNCalInfoEnumProc;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _COORD *PCoord;

typedef _COORD  TCoord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _SMALL_RECT *PSmallRect;

typedef _SMALL_RECT  TSmallRect;

typedef _KEY_EVENT_RECORD *PKeyEventRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _KEY_EVENT_RECORD  TKeyEventRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _MOUSE_EVENT_RECORD *PMouseEventRecord;

typedef _MOUSE_EVENT_RECORD  TMouseEventRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _WINDOW_BUFFER_SIZE_RECORD *PWindowBufferSizeRecord;

typedef _WINDOW_BUFFER_SIZE_RECORD  TWindowBufferSizeRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _MENU_EVENT_RECORD *PMenuEventRecord;

typedef _MENU_EVENT_RECORD  TMenuEventRecord;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _FOCUS_EVENT_RECORD *PFocusEventRecord;

typedef _FOCUS_EVENT_RECORD  TFocusEventRecord;

typedef _INPUT_RECORD *PInputRecord;

typedef _INPUT_RECORD  TInputRecord;

typedef _CHAR_INFO *PCharInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _CHAR_INFO  TCharInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _CONSOLE_SCREEN_BUFFER_INFO *PConsoleScreenBufferInfo;

typedef _CONSOLE_SCREEN_BUFFER_INFO  TConsoleScreenBufferInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _CONSOLE_CURSOR_INFO *PConsoleCursorInfo;

typedef _CONSOLE_CURSOR_INFO  TConsoleCursorInfo;

typedef void *TFNHandlerRoutine;

#pragma pack(push, 1)
#pragma pack(pop)

typedef tagVS_FIXEDFILEINFO *PVSFixedFileInfo;

typedef tagVS_FIXEDFILEINFO  TVSFixedFileInfo;

#pragma pack(push, 1)
struct TValContext
{
	int valuelen;
	void *value_context;
	void *val_buff_ptr;
} ;
#pragma pack(pop)

typedef TValContext *PValContext;

#pragma pack(push, 1)
#pragma pack(pop)

typedef pvalueA *PPValueA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef pvalueW *PPValueW;

typedef pvalueA *PPValue;

typedef pvalueA  TPValueA;

typedef pvalueW  TPValueW;

typedef pvalueA  TPValue;

typedef void *TFNQueryHandler;

typedef void * *PFNQueryHandler;

#pragma pack(push, 1)
#pragma pack(pop)

typedef provider_info *PProviderInfo;

typedef provider_info  TProviderInfo;

typedef provider_info  TRegProvider;

typedef provider_info *PProvider;

#pragma pack(push, 1)
struct TValueEntA
{
	char *ve_valuename;
	int ve_valuelen;
	int ve_valueptr;
	int ve_type;
} ;
#pragma pack(pop)

typedef TValueEntA *PValueEntA;

#pragma pack(push, 1)
struct TValueEntW
{
	wchar_t *ve_valuename;
	int ve_valuelen;
	int ve_valueptr;
	int ve_type;
} ;
#pragma pack(pop)

typedef TValueEntW *PValueEntW;

typedef TValueEntA *PValueEnt;

typedef TValueEntA  TValueEnt;

typedef TValueEntA  TValEnt;

typedef TValueEntA *PValEnt;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _NETRESOURCEA *PNetResourceA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _NETRESOURCEW *PNetResourceW;

typedef _NETRESOURCEA *PNetResource;

typedef _NETRESOURCEA  TNetResourceA;

typedef _NETRESOURCEW  TNetResourceW;

typedef _NETRESOURCEA  TNetResource;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _CONNECTDLGSTRUCTA *PConnectDlgStruct;

typedef _CONNECTDLGSTRUCTA  TConnectDlgStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _DISCDLGSTRUCTA *PDiscDlgStructA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _DISCDLGSTRUCTW *PDiscDlgStructW;

typedef _DISCDLGSTRUCTA *PDiscDlgStruct;

typedef _DISCDLGSTRUCTA  TDiscDlgStructA;

typedef _DISCDLGSTRUCTW  TDiscDlgStructW;

typedef _DISCDLGSTRUCTA  TDiscDlgStruct;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _UNIVERSAL_NAME_INFOA *PUniversalNameInfoA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _UNIVERSAL_NAME_INFOW *PUniversalNameInfoW;

typedef _UNIVERSAL_NAME_INFOA *PUniversalNameInfo;

typedef _UNIVERSAL_NAME_INFOA  TUniversalNameInfoA;

typedef _UNIVERSAL_NAME_INFOW  TUniversalNameInfoW;

typedef _UNIVERSAL_NAME_INFOA  TUniversalNameInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _REMOTE_NAME_INFOA *PRemoteNameInfoA;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _REMOTE_NAME_INFOW *PRemoteNameInfoW;

typedef _REMOTE_NAME_INFOA *PRemoteNameInfo;

typedef _REMOTE_NAME_INFOA  TRemoteNameInfoA;

typedef _REMOTE_NAME_INFOW  TRemoteNameInfoW;

typedef _REMOTE_NAME_INFOA  TRemoteNameInfo;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _NETINFOSTRUCT *PNetInfoStruct;

typedef _NETINFOSTRUCT  TNetInfoStruct;

typedef void *TFNGetProfilePath;

typedef void *TFNReconcileProfile;

typedef void *TFNProcessPolicies;

#pragma pack(push, 1)
#pragma pack(pop)

typedef _NETCONNECTINFOSTRUCT *PNetConnectInfoStruct;

typedef _NETCONNECTINFOSTRUCT  TNetConnectInfoStruct;

#pragma pack(push, 1)
#pragma pack(pop)

#ifndef _VCL_LEAN_AND_MEAN
typedef DDEACK *PDDEAck;

typedef DDEACK  TDDEAck;

#pragma pack(push, 1)
#pragma pack(pop)

typedef DDEADVISE *PDDEAdvise;

typedef DDEADVISE  TDDEAdvise;

typedef DDEDATA *PDDEData;

#pragma pack(push, 1)
#pragma pack(pop)

typedef DDEDATA  TDDEData;

typedef DDEPOKE *PDDEPoke;

#pragma pack(push, 1)
#pragma pack(pop)

typedef DDEPOKE  TDDEPoke;
#endif

//-- var, const, procedure ---------------------------------------------------
#define LDTF_BASEMID (int)(-16777216)
#define LDTF_TYPE_8 (int)(16252928)
#define LDTF_DPL (int)(393216)
#define LDTF_PRES (int)(65536)
#define LDTF_LIMITHI (int)(61440)
#define LDTF_SYS (unsigned short)(2048)
#define LDTF_RESERVED_0 (unsigned short)(1024)
#define LDTF_DEFAULT_BIG (unsigned short)(512)
#define LDTF_GRANULARITY (unsigned short)(256)
#define LDTF_BASEHI (unsigned char)(255)
#define FILE_ATTRIBUTE_ATOMICWRITE (unsigned short)(512)
#define FILE_ATTRIBUTE_XACTIONWRITE (unsigned short)(1024)
#define _DELETE (int)(65536)
#define ERROR_FAILED_SERVICE_CONTROLLER_ (unsigned short)(1063)
#define ERROR_SESSION_CREDENTIAL_CONFLIC (unsigned short)(1219)
#define ERROR_REMOTE_SESSION_LIMIT_EXCEE (unsigned short)(1220)
#define ERROR_NT_CROSS_ENCRYPTION_REQUIR (unsigned short)(1386)
#define ERROR_LM_CROSS_ENCRYPTION_REQUIR (unsigned short)(1390)
#define ERROR_DESTROY_OBJECT_OF_OTHER_TH (unsigned short)(1435)
#define ERROR_TRUSTED_RELATIONSHIP_FAILU (unsigned short)(1789)
#define ERROR_REDIRECTOR_HAS_OPEN_HANDLE (unsigned short)(1794)
#define ERROR_PRINTER_DRIVER_ALREADY_INS (unsigned short)(1795)
#define ERROR_NOLOGON_INTERDOMAIN_TRUST_ (unsigned short)(1807)
#define ERROR_NOLOGON_WORKSTATION_TRUST_ (unsigned short)(1808)
#define ERROR_NOLOGON_SERVER_TRUST_ACCOU (unsigned short)(1809)
#define ERROR_DOMAIN_CONTROLLER_NOT_FOUN (unsigned short)(1908)
#define ERROR_PRINT_PROCESSOR_ALREADY_IN (unsigned short)(3005)
#define ERROR_PRINT_MONITOR_ALREADY_INST (unsigned short)(3006)
#define CO_E_INIT_TLS_SET_CHANNEL_CONTRO (int)(-2147467253)
#define CO_E_INIT_UNACCEPTED_USER_ALLOCA (int)(-2147467251)
#define CO_E_INIT_SCM_FILE_MAPPING_EXIST (int)(-2147467249)
#define CONVERT10_E_OLESTREAM_BITMAP_TO_ (int)(-2147221053)
#define MK_E_INTERMEDIATEINTERFACENOTSUP (int)(-2147221017)
#define RPC_E_CANTCALLOUT_ININPUTSYNCCAL (int)(-2147417843)
#define _ABORTDOC (unsigned char)(2)
#define _SETABORTPROC (unsigned char)(9)
#define _STARTDOC (unsigned char)(10)
#define _ENDDOC (unsigned char)(11)
#define _SETMITERLIMIT (unsigned char)(23)
#define _EXTTEXTOUT (unsigned short)(512)
#define _STRETCHBLT (unsigned short)(2048)
#define DM_RESERVED1 (int)(8388608)
#define DM_RESERVED2 (int)(16777216)
#define GCP_GLYPHINDEXING (unsigned char)(128)
#define GCP_NODIACRITICS (int)(131072)
#define wnd_Broadcast (int)(65535)
#define COLOR_ENDCOLORS (unsigned char)(24)
#define LR_LOADREALSIZE (unsigned char)(128)
#define ID_OK (unsigned char)(1)
#define ID_CANCEL (unsigned char)(2)
#define ID_ABORT (unsigned char)(3)
#define ID_RETRY (unsigned char)(4)
#define ID_IGNORE (unsigned char)(5)
#define ID_YES (unsigned char)(6)
#define ID_NO (unsigned char)(7)
#define ID_CLOSE (unsigned char)(8)
#define ID_HELP (unsigned char)(9)
#define _MOUSE_EVENT (unsigned char)(2)
#define dde_AppReturnCode (unsigned char)(255)
#define dde_Busy (unsigned short)(16384)
#define dde_Ack (int)(32768)
#define dde_DeferUpd (unsigned short)(16384)
#define dde_AckReq (int)(32768)
#define dde_Response (unsigned short)(4096)
#define dde_Release (unsigned short)(8192)
#define advapi32 "advapi32.dll"
#define kernel32 "kernel32.dll"
#define mpr "mpr.dll"
#define comctl32 "comctl32.dll"
#define gdi32 "gdi32.dll"
#define opengl32 "opengl32.dll"
#define user32 "user32.dll"
	
extern unsigned short __fastcall MakeWord(unsigned char a, unsigned char b);
extern long __fastcall MakeLong(unsigned short a, unsigned short b);
extern unsigned short __fastcall HiWord(int l);
extern unsigned char __fastcall HiByte(unsigned short W);
extern DWORD __fastcall Succeeded(long Status);
extern DWORD __fastcall Failed(long Status);
extern DWORD __fastcall IsError(long Status);
extern int __fastcall HResultCode(long hr);
extern int __fastcall HResultFacility(long hr);
extern int __fastcall HResultSeverity(long hr);
extern long __fastcall HResultFromWin32(int x);
extern long __fastcall HResultFromNT(int x);
extern int __fastcall MakeROP4(int fore, int back);
extern int __fastcall PaletteRGB(unsigned char r, unsigned char g, unsigned char b);
extern int __fastcall PaletteIndex(unsigned short i);
extern POINT __fastcall SmallPointToPoint(const TSmallPoint P);
extern TSmallPoint __fastcall PointToSmallPoint(const POINT &P);
extern long __fastcall MakeWParam(unsigned short l, unsigned short h);
extern long __fastcall MakeLParam(unsigned short l, unsigned short h);
extern long __fastcall MakeLResult(unsigned short l, unsigned short h);

//-- template instantiations -------------------------------------------------
template class TComStateFlags ;

}	/* namespace Windows */

#pragma warn .par
#pragma warn .hid 
#pragma warn .inl

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Windows;
#endif
//-- end unit ----------------------------------------------------------------
#endif	// Windows
