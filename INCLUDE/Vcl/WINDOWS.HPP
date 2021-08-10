// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Windows.pas' rev: 6.00

#ifndef WindowsHPP
#define WindowsHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Types.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
// WINVER check BEGIN 
#if (WINVER < 0x0400)
#error WINVER < 0x0400
#endif
// WINVER check END. 

// WIN2K SDK fixes BEGIN 
#ifndef WINTRUST_H
#include<wintrust.h>
#endif
// WIN2K SDK fixes END. 
//
// WINDOWS provides two definitions of BLOB: wtypes.h defines a
// BLOB as a tagBLOB struct whereas nspapi.h defines a BLOB as a _BLOB
// struct. Unfortunately, VCL does not use the portable BLOB type but
// rather relies on tagBLOB. So here we use a kludge to try to determine
// which flavour of BLOB we have (which is determined by the order of header
// inclusion by the compilation unit). If it is the _BLOB, we expose the
// tagBLOB type for VCL.
//
#if sizeof(_BLOB) == 8      // We know that BLOB is 8 bytes 
typedef _BLOB tagBLOB;      // If unknown, _BLOB would be 4 
#endif                      // tagBLOB Kludge
#if sizeof(tagBLOB) == 4    // tagBLOB has probably not been defined yet
#ifndef _tagBLOB_DEFINED
#define _tagBLOB_DEFINED
#define _BLOB_DEFINED
#define _LPBLOB_DEFINED
typedef struct  tagBLOB
    {
    ULONG cbSize;
    /* [size_is] */ BYTE __RPC_FAR *pBlobData;
    }       BLOB;

typedef struct tagBLOB __RPC_FAR *LPBLOB;
#endif      //      _tagBLOB_DEFINED
#endif      //      sizeof(tagBLOB) == 4

#if defined(WIN32_LEAN_AND_MEAN) && !defined(_DDEHEADER_INCLUDED_)
#include <dde.h>
#endif      // WIN32_LEAN_AND_MEAN & _DDEHEADER_INCLUDED_

namespace Windows {
typedef _LARGE_INTEGER TLargeInteger;

#if (WINVER >= 0x0500)
typedef BITMAPV5HEADER *PBitmapV5Header;
typedef BITMAPV5HEADER  TBitmapV5Header;
typedef tagEMRGRADIENTFILL *PEMGradientFill;
typedef tagEMRGRADIENTFILL  TEMGradientFill;
typedef tagEMRALPHABLEND *PEMRAlphaBlend;
typedef tagEMRALPHABLEND  TEMRAlphaBlend;
typedef tagEMRTRANSPARENTBLT *PEMRTransparentBLT;
typedef tagEMRTRANSPARENTBLT  TEMRTransparentBLT;
typedef _WGLSWAP *PWGLSwap;
typedef _WGLSWAP  TWGLSwap;
typedef tagMOUSEMOVEPOINT *PMouseMovePoint;
typedef tagMOUSEMOVEPOINT  TMouseMovePoint;
typedef FLASHWINFO  TFlashWInfo;
typedef tagMENUINFO *PMenuInfo;
typedef tagMENUINFO  TMenuInfo;
typedef tagMENUGETOBJECTINFO *PMenuGetObjectInfo;
typedef tagMENUGETOBJECTINFO  TMenuGetObjectInfo;
typedef tagGUITHREADINFO *PGUIThreadInfo;
typedef tagGUITHREADINFO  TGUIThreadInfo;
typedef tagCURSORINFO *PCursorInfo;
typedef tagCURSORINFO  TCursorInfo;
typedef tagWINDOWINFO *PWindowInfo;
typedef tagWINDOWINFO  TWindowInfo;
typedef tagTITLEBARINFO *PTitleBarInfo;
typedef tagTITLEBARINFO  TTitleBarInfo;
typedef tagMENUBARINFO *PMenuBarInfo;
typedef tagMENUBARINFO  TMenuBarInfo;
typedef tagSCROLLBARINFO *PScrollBarInfo;
typedef tagSCROLLBARINFO  TScrollBarInfo;
typedef tagCOMBOBOXINFO *PComboBoxInfo;
typedef tagCOMBOBOXINFO  TComboBoxInfo;
typedef tagALTTABINFO *PAltTabInfo;
typedef tagALTTABINFO  TAltTabInfo;
#endif

} // namespace Windows


namespace Windows
{
//-- type declarations -------------------------------------------------------
typedef wchar_t *PWChar;

typedef Byte *PByte;

typedef float *PSingle;

typedef unsigned THandle;

typedef unsigned *PHandle;

typedef __int64 *PLargeInteger;

typedef ULARGE_INTEGER *PULargeInteger;

typedef ULARGE_INTEGER  TULargeInteger;

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

typedef unsigned *PACCESS_MASK;

typedef _GENERIC_MAPPING *PGenericMapping;

typedef _GENERIC_MAPPING  TGenericMapping;

typedef _LUID_AND_ATTRIBUTES *PLUIDAndAttributes;

typedef _LUID_AND_ATTRIBUTES  TLUIDAndAttributes;

typedef _SID_IDENTIFIER_AUTHORITY *PSIDIdentifierAuthority;

typedef _SID_IDENTIFIER_AUTHORITY  TSIDIdentifierAuthority;

typedef _SID_AND_ATTRIBUTES *PSIDAndAttributes;

typedef _SID_AND_ATTRIBUTES  TSIDAndAttributes;

typedef _ACL  TACL;

typedef _SECURITY_DESCRIPTOR *PSecurityDescriptor;

typedef _SECURITY_DESCRIPTOR  TSecurityDescriptor;

typedef _OBJECT_TYPE_LIST *PObjectTypeList;

typedef _OBJECT_TYPE_LIST  TObjectTypeList;

typedef _PRIVILEGE_SET *PPrivilegeSet;

typedef _PRIVILEGE_SET  TPrivilegeSet;

typedef _TOKEN_GROUPS *PTokenGroups;

typedef _TOKEN_GROUPS  TTokenGroups;

typedef _TOKEN_PRIVILEGES *PTokenPrivileges;

typedef _TOKEN_PRIVILEGES  TTokenPrivileges;

typedef _SECURITY_QUALITY_OF_SERVICE *PSecurityQualityOfService;

typedef _SECURITY_QUALITY_OF_SERVICE  TSecurityQualityOfService;

typedef unsigned *PSECURITY_INFORMATION;

typedef int __stdcall (*TThreadStartRoutine)(void * lpThreadParameter);

struct _IMAGE_DOS_HEADER;
typedef _IMAGE_DOS_HEADER *PImageDosHeader;

#pragma pack(push, 1)
struct _IMAGE_DOS_HEADER
{
	Word e_magic;
	Word e_cblp;
	Word e_cp;
	Word e_crlc;
	Word e_cparhdr;
	Word e_minalloc;
	Word e_maxalloc;
	Word e_ss;
	Word e_sp;
	Word e_csum;
	Word e_ip;
	Word e_cs;
	Word e_lfarlc;
	Word e_ovno;
	Word e_res[4];
	Word e_oemid;
	Word e_oeminfo;
	Word e_res2[10];
	int _lfanew;
} ;
#pragma pack(pop)

typedef _IMAGE_DOS_HEADER  TImageDosHeader;

typedef _IMAGE_FILE_HEADER *PImageFileHeader;

typedef _IMAGE_FILE_HEADER  TImageFileHeader;

typedef _IMAGE_EXPORT_DIRECTORY *PImageExportDirectory;

typedef _IMAGE_EXPORT_DIRECTORY  TImageExportDirectory;

typedef _IMAGE_DATA_DIRECTORY *PImageDataDirectory;

typedef _IMAGE_DATA_DIRECTORY  TImageDataDirectory;

typedef _IMAGE_OPTIONAL_HEADER *PImageOptionalHeader;

typedef _IMAGE_OPTIONAL_HEADER  TImageOptionalHeader;

typedef _IMAGE_ROM_OPTIONAL_HEADER *PImageRomOptionalHeader;

typedef _IMAGE_ROM_OPTIONAL_HEADER  TImageRomOptionalHeader;

typedef _IMAGE_NT_HEADERS *PImageNtHeaders;

typedef _IMAGE_NT_HEADERS  TImageNtHeaders;

typedef _IMAGE_ROM_HEADERS *PImageRomHeaders;

typedef _IMAGE_ROM_HEADERS  TImageRomHeaders;

#pragma pack(push, 1)
struct TISHMisc
{
	
	union
	{
		struct 
		{
			unsigned VirtualSize;
			
		};
		struct 
		{
			unsigned PhysicalAddress;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef _IMAGE_SECTION_HEADER *PImageSectionHeader;

typedef _IMAGE_SECTION_HEADER  TImageSectionHeader;

typedef IMAGE_LOAD_CONFIG_DIRECTORY *PImageLoadConfigDirectory;

typedef IMAGE_LOAD_CONFIG_DIRECTORY  TImageLoadConfigDirectory;

typedef IMAGE_RUNTIME_FUNCTION_ENTRY *PImageRuntimeFunctionEntry;

typedef IMAGE_RUNTIME_FUNCTION_ENTRY  TImageRuntimeFunctionEntry;

typedef _IMAGE_DEBUG_DIRECTORY *PImageDebugDirectory;

typedef _IMAGE_DEBUG_DIRECTORY  TImageDebugDirectory;

typedef _IMAGE_COFF_SYMBOLS_HEADER *PImageCOFFSymbolsHeader;

typedef _IMAGE_COFF_SYMBOLS_HEADER  TImageCOFFSymbolsHeader;

typedef _FPO_DATA *PFpoData;

typedef _FPO_DATA  TFpoData;

typedef _IMAGE_DEBUG_MISC *PImageDebugMisc;

typedef _IMAGE_DEBUG_MISC  TImageDebugMisc;

typedef _IMAGE_FUNCTION_ENTRY *PImageFunctionEntry;

typedef _IMAGE_FUNCTION_ENTRY  TImageFunctionEntry;

typedef _RTL_CRITICAL_SECTION *PRTLCriticalSection;

typedef _RTL_CRITICAL_SECTION_DEBUG *PRTLCriticalSectionDebug;

typedef _RTL_CRITICAL_SECTION_DEBUG  TRTLCriticalSectionDebug;

typedef _RTL_CRITICAL_SECTION  TRTLCriticalSection;

typedef Word TAtom;

typedef void *TFarProc;

typedef void *PROC_22;

typedef unsigned HINST;

typedef unsigned TColorRef;

typedef _POINTL *PPointL;

typedef _POINTL  TPointL;

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

typedef void *TFNFiberStartRoutine;

typedef _COMMPROP *PCommProp;

typedef _COMMPROP  TCommProp;

#pragma option push -b
enum TComStateFlag { fCtlHold, fDsrHold, fRlsHold, fXoffHold, fXOffSent, fEof, fTxim };
#pragma option pop

typedef Set<TComStateFlag, fCtlHold, fTxim>  TComStateFlags;

typedef _COMSTAT  TComStat;

typedef _COMSTAT *PComStat;

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

typedef void *TFNAPCProc;

typedef unsigned TWOHandleArray[64];

typedef unsigned *PWOHandleArray;

typedef _BY_HANDLE_FILE_INFORMATION *PByHandleFileInformation;

typedef _BY_HANDLE_FILE_INFORMATION  TByHandleFileInformation;

typedef _TIME_ZONE_INFORMATION *PTimeZoneInformation;

typedef _TIME_ZONE_INFORMATION  TTimeZoneInformation;

typedef unsigned __stdcall (*TFNExportFunc)(void * pbData, void * pvCallbackContext, unsigned ulLength);

typedef unsigned __stdcall (*TFNImportFunc)(void * pbData, void * pvCallbackContext, unsigned ulLength);

struct _RECOVERY_AGENT_INFORMATIONA;
typedef _RECOVERY_AGENT_INFORMATIONA *PRecoveryAgentInformationA;

struct _RECOVERY_AGENT_INFORMATIONW;
typedef _RECOVERY_AGENT_INFORMATIONW *PRecoveryAgentInformationW;

typedef _RECOVERY_AGENT_INFORMATIONA *PRecoveryAgentInformation;

#pragma pack(push, 4)
struct _RECOVERY_AGENT_INFORMATIONA
{
	unsigned NextEntryOffset;
	unsigned AgentNameLength;
	char AgentInformation[1];
} ;
#pragma pack(pop)

#pragma pack(push, 4)
struct _RECOVERY_AGENT_INFORMATIONW
{
	unsigned NextEntryOffset;
	unsigned AgentNameLength;
	char AgentInformation[1];
} ;
#pragma pack(pop)

typedef _RECOVERY_AGENT_INFORMATIONA  _RECOVERY_AGENT_INFORMATION;

typedef _RECOVERY_AGENT_INFORMATIONA  TRecoveryAgentInformationA;

typedef _RECOVERY_AGENT_INFORMATIONW  TRecoveryAgentInformationW;

typedef _RECOVERY_AGENT_INFORMATIONA  TRecoveryAgentInformation;

typedef _RECOVERY_AGENT_INFORMATIONA  RECOVERY_AGENT_INFORMATIONA;

typedef _RECOVERY_AGENT_INFORMATIONW  RECOVERY_AGENT_INFORMATIONW;

typedef _RECOVERY_AGENT_INFORMATIONA  RECOVERY_AGENT_INFORMATION;

typedef void *TPROverlappedCompletionRoutine;

typedef _WIN32_STREAM_ID *PWIN32StreamID;

typedef _WIN32_STREAM_ID  TWIN32StreamID;

typedef _STARTUPINFOA *PStartupInfo;

typedef _STARTUPINFOA  TStartupInfo;

typedef _WIN32_FIND_DATAA *PWin32FindDataA;

typedef _WIN32_FIND_DATAW *PWin32FindDataW;

typedef _WIN32_FIND_DATAA *PWin32FindData;

typedef _WIN32_FIND_DATAA  _WIN32_FIND_DATA;

typedef _WIN32_FIND_DATAA  TWin32FindDataA;

typedef _WIN32_FIND_DATAW  TWin32FindDataW;

typedef _WIN32_FIND_DATAA  TWin32FindData;

typedef _WIN32_FILE_ATTRIBUTE_DATA *PWin32FileAttributeData;

typedef _WIN32_FILE_ATTRIBUTE_DATA  TWin32FileAttributeData;

typedef void *TFNTimerAPCRoutine;

typedef _GET_FILEEX_INFO_LEVELS TGetFileExInfoLevels;

typedef _FINDEX_INFO_LEVELS TFindexInfoLevels;

typedef _FINDEX_SEARCH_OPS TFindexSearchOps;

typedef void *TFNProgressRoutine;

typedef tagHW_PROFILE_INFOA *PHWProfileInfoA;

typedef tagHW_PROFILE_INFOW *PHWProfileInfoW;

typedef tagHW_PROFILE_INFOA *PHWProfileInfo;

typedef tagHW_PROFILE_INFOA  tagHW_PROFILE_INFO;

typedef tagHW_PROFILE_INFOA  THWProfileInfoA;

typedef tagHW_PROFILE_INFOW  THWProfileInfoW;

typedef tagHW_PROFILE_INFOA  THWProfileInfo;

typedef tagHW_PROFILE_INFOA  HW_PROFILE_INFO;

typedef _OSVERSIONINFOA *POSVersionInfoA;

typedef _OSVERSIONINFOW *POSVersionInfoW;

typedef _OSVERSIONINFOA *POSVersionInfo;

typedef _OSVERSIONINFOA  _OSVERSIONINFO;

typedef _OSVERSIONINFOA  TOSVersionInfoA;

typedef _OSVERSIONINFOW  TOSVersionInfoW;

typedef _OSVERSIONINFOA  TOSVersionInfo;

typedef _SYSTEM_POWER_STATUS *PSystemPowerStatus;

typedef _SYSTEM_POWER_STATUS  TSystemPowerStatus;

typedef _WIN_CERTIFICATE *PWinCertificate;

typedef _WIN_CERTIFICATE  TWinCertificate;

typedef void *TWinTrustSubject;

typedef _WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT *PWinTrustActdataContextWithSubject;

typedef _WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT  TWinTrustActdataContextWithSubject;

typedef _WIN_TRUST_ACTDATA_SUBJECT_ONLY *PWinTrustActdataSubjectOnly;

typedef _WIN_TRUST_ACTDATA_SUBJECT_ONLY  TWinTrustActdataSubjectOnly;

typedef _WIN_TRUST_SUBJECT_FILE *PWinTrustSubjectFile;

typedef _WIN_TRUST_SUBJECT_FILE  TWinTrustSubjectFile;

typedef _WIN_TRUST_SUBJECT_FILE_AND_DISPLAY *PWinTrustSubjectFileAndDisplay;

typedef _WIN_TRUST_SUBJECT_FILE_AND_DISPLAY  TWinTrustSubjectFileAndDisplay;

typedef _WIN_SPUB_TRUSTED_PUBLISHER_DATA *PWinSpubTrustedPublisherData;

typedef _WIN_SPUB_TRUSTED_PUBLISHER_DATA  TWinSpubTrustedPublisherData;

typedef tagXFORM *PXForm;

typedef tagXFORM  TXForm;

typedef tagBITMAP *PBitmap;

typedef tagBITMAP  TBitmap;

typedef tagRGBTRIPLE *PRGBTriple;

typedef tagRGBTRIPLE  TRGBTriple;

typedef tagRGBQUAD *PRGBQuad;

typedef tagRGBQUAD  TRGBQuad;

typedef tagCIEXYZ *PCIEXYZ;

typedef tagCIEXYZ  TCIEXYZ;

typedef tagICEXYZTRIPLE *PCIEXYZTriple;

typedef tagICEXYZTRIPLE  TCIEXYZTriple;

typedef tagLOGCOLORSPACEA *PLogColorSpaceA;

typedef tagLOGCOLORSPACEW *PLogColorSpaceW;

typedef tagLOGCOLORSPACEA *PLogColorSpace;

typedef tagLOGCOLORSPACEA  TLogColorSpaceA;

typedef tagLOGCOLORSPACEW  TLogColorSpaceW;

typedef tagLOGCOLORSPACEA  TLogColorSpace;

typedef tagBITMAPCOREHEADER *PBitmapCoreHeader;

typedef tagBITMAPCOREHEADER  TBitmapCoreHeader;

typedef tagBITMAPINFOHEADER *PBitmapInfoHeader;

typedef tagBITMAPINFOHEADER  TBitmapInfoHeader;

typedef BITMAPV4HEADER *PBitmapV4Header;

typedef BITMAPV4HEADER  TBitmapV4Header;

typedef tagBITMAPINFO *PBitmapInfo;

typedef tagBITMAPINFO  TBitmapInfo;

typedef tagBITMAPCOREINFO *PBitmapCoreInfo;

typedef tagBITMAPCOREINFO  TBitmapCoreInfo;

typedef tagBITMAPFILEHEADER *PBitmapFileHeader;

typedef tagBITMAPFILEHEADER  TBitmapFileHeader;

typedef tagFONTSIGNATURE *PFontSignature;

typedef tagFONTSIGNATURE  TFontSignature;

typedef tagCHARSETINFO *PCharsetInfo;

typedef tagCHARSETINFO  TCharsetInfo;

typedef tagLOCALESIGNATURE *PLocaleSignature;

typedef tagLOCALESIGNATURE  TLocaleSignature;

typedef tagHANDLETABLE *PHandleTable;

typedef tagHANDLETABLE  THandleTable;

typedef tagMETARECORD *PMetaRecord;

typedef tagMETARECORD  TMetaRecord;

typedef tagMETAFILEPICT *PMetafilePict;

typedef tagMETAFILEPICT  TMetafilePict;

typedef tagMETAHEADER *PMetaHeader;

typedef tagMETAHEADER  TMetaHeader;

typedef tagENHMETARECORD *PEnhMetaRecord;

typedef tagENHMETARECORD  TEnhMetaRecord;

typedef tagENHMETAHEADER *PEnhMetaHeader;

typedef tagENHMETAHEADER  TEnhMetaHeader;

typedef tagTEXTMETRICA *PTextMetricA;

typedef tagTEXTMETRICW *PTextMetricW;

typedef tagTEXTMETRICA *PTextMetric;

typedef tagTEXTMETRICA  TTextMetricA;

typedef tagTEXTMETRICW  TTextMetricW;

typedef tagTEXTMETRICA  TTextMetric;

typedef tagNEWTEXTMETRICA *PNewTextMetricA;

typedef tagNEWTEXTMETRICW *PNewTextMetricW;

typedef tagNEWTEXTMETRICA *PNewTextMetric;

typedef tagNEWTEXTMETRICA  TNewTextMetricA;

typedef tagNEWTEXTMETRICW  TNewTextMetricW;

typedef tagNEWTEXTMETRICA  TNewTextMetric;

typedef tagNEWTEXTMETRICEXA *PNewTextMetricExA;

typedef tagNEWTEXTMETRICEXA  TNewTextMetricExA;

typedef tagNEWTEXTMETRICEXW *PNewTextMetricExW;

typedef tagNEWTEXTMETRICEXW  TNewTextMetricExW;

typedef tagNEWTEXTMETRICEXA *PNewTextMetricEx;

typedef tagPELARRAY *PPelArray;

typedef tagPELARRAY  TPelArray;

typedef tagLOGBRUSH *PLogBrush;

typedef tagLOGBRUSH  TLogBrush;

typedef tagLOGBRUSH *PPattern;

typedef tagLOGBRUSH  TPattern;

typedef tagLOGPEN *PLogPen;

typedef tagLOGPEN  TLogPen;

typedef tagLOGPEN *PExtLogPen;

typedef tagEXTLOGPEN  TExtLogPen;

typedef tagPALETTEENTRY *PPaletteEntry;

typedef tagPALETTEENTRY  TPaletteEntry;

typedef tagLOGPALETTE *PLogPalette;

typedef tagLOGPALETTE  TLogPalette;

struct TMaxLogPalette;
typedef TMaxLogPalette *PMaxLogPalette;

#pragma pack(push, 1)
struct TMaxLogPalette
{
	Word palVersion;
	Word palNumEntries;
	tagPALETTEENTRY palPalEntry[256];
} ;
#pragma pack(pop)

typedef tagLOGFONTA *PLogFontA;

typedef tagLOGFONTW *PLogFontW;

typedef tagLOGFONTA *PLogFont;

typedef tagLOGFONTA  TLogFontA;

typedef tagLOGFONTW  TLogFontW;

typedef tagLOGFONTA  TLogFont;

typedef tagENUMLOGFONTA *PEnumLogFontA;

typedef tagENUMLOGFONTW *PEnumLogFontW;

typedef tagENUMLOGFONTA *PEnumLogFont;

typedef tagENUMLOGFONTA  TEnumLogFontA;

typedef tagENUMLOGFONTW  TEnumLogFontW;

typedef tagENUMLOGFONTA  TEnumLogFont;

typedef tagENUMLOGFONTEXA *PEnumLogFontExA;

typedef tagENUMLOGFONTEXW *PEnumLogFontExW;

typedef tagENUMLOGFONTEXA *PEnumLogFontEx;

typedef tagENUMLOGFONTEXA  TEnumLogFontExA;

typedef tagENUMLOGFONTEXW  TEnumLogFontExW;

typedef tagENUMLOGFONTEXA  TEnumLogFontEx;

typedef tagPANOSE *PPanose;

typedef tagPANOSE  TPanose;

typedef tagEXTLOGFONTA *PExtLogFontA;

typedef tagEXTLOGFONTW *PExtLogFontW;

typedef tagEXTLOGFONTA *PExtLogFont;

typedef tagEXTLOGFONTA  TExtLogFontA;

typedef tagEXTLOGFONTW  TExtLogFontW;

typedef tagEXTLOGFONTA  TExtLogFont;

typedef _devicemodeA *PDeviceModeA;

typedef _devicemodeW *PDeviceModeW;

typedef _devicemodeA *PDeviceMode;

typedef _devicemodeA  TDeviceModeA;

typedef _devicemodeW  TDeviceModeW;

typedef _devicemodeA  TDeviceMode;

typedef _devicemodeA *PDevMode;

typedef _devicemodeA  TDevMode;

typedef _DISPLAY_DEVICEA *PDisplayDeviceA;

typedef _DISPLAY_DEVICEW *PDisplayDeviceW;

typedef _DISPLAY_DEVICEA *PDisplayDevice;

typedef _DISPLAY_DEVICEA  TDisplayDeviceA;

typedef _DISPLAY_DEVICEW  TDisplayDeviceW;

typedef _DISPLAY_DEVICEA  TDisplayDevice;

typedef _RGNDATAHEADER *PRgnDataHeader;

typedef _RGNDATAHEADER  TRgnDataHeader;

typedef _RGNDATA *PRgnData;

typedef _RGNDATA  TRgnData;

typedef _ABC  TABC;

typedef _ABCFLOAT *PABCFloat;

typedef _ABCFLOAT  TABCFloat;

typedef _OUTLINETEXTMETRICA *POutlineTextmetricA;

typedef _OUTLINETEXTMETRICW *POutlineTextmetricW;

typedef _OUTLINETEXTMETRICA *POutlineTextmetric;

typedef _OUTLINETEXTMETRICA  TOutlineTextmetricA;

typedef _OUTLINETEXTMETRICW  TOutlineTextmetricW;

typedef _OUTLINETEXTMETRICA  TOutlineTextmetric;

typedef tagPOLYTEXTA *PPolyTextA;

typedef tagPOLYTEXTW *PPolyTextW;

typedef tagPOLYTEXTA *PPolyText;

typedef tagPOLYTEXTA  TPolyTextA;

typedef tagPOLYTEXTW  TPolyTextW;

typedef tagPOLYTEXTA  TPolyText;

typedef _FIXED  TFixed;

typedef _MAT2 *PMat2;

typedef _MAT2  TMat2;

typedef _GLYPHMETRICS *PGlyphMetrics;

typedef _GLYPHMETRICS  TGlyphMetrics;

typedef tagPOINTFX *PPointfx;

typedef tagPOINTFX  TPointfx;

typedef tagTTPOLYCURVE *PTTPolyCurve;

typedef tagTTPOLYCURVE  TTTPolyCurve;

typedef tagTTPOLYGONHEADER *PTTPolygonHeader;

typedef tagTTPOLYGONHEADER  TTTPolygonHeader;

typedef tagGCP_RESULTSA *PGCPResultsA;

typedef tagGCP_RESULTSW *PGCPResultsW;

typedef tagGCP_RESULTSA *PGCPResults;

typedef tagGCP_RESULTSA  TGCPResultsA;

typedef tagGCP_RESULTSW  TGCPResultsW;

typedef tagGCP_RESULTSA  TGCPResults;

typedef _RASTERIZER_STATUS *PRasterizerStatus;

typedef _RASTERIZER_STATUS  TRasterizerStatus;

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

typedef void *TFNDevMode;

typedef void *TFNDevCaps;

typedef tagWCRANGE *PWCRange;

typedef tagWCRANGE  TWCRange;

typedef tagGLYPHSET *PGlyphSet;

typedef tagGLYPHSET  TGlyphSet;

typedef tagDESIGNVECTOR *PDesignVector;

typedef tagDESIGNVECTOR  TDesignVector;

typedef tagAXISINFOA *PAxisInfoA;

typedef tagAXISINFOA  TAxisInfoA;

typedef tagAXISINFOW *PAxisInfoW;

typedef tagAXISINFOW  TAxisInfoW;

typedef tagAXISINFOA *PAxisInfo;

typedef tagAXESLISTA *PAxesListA;

typedef tagAXESLISTA  TAxesListA;

typedef tagAXESLISTW *PAxesListW;

typedef tagAXESLISTW  TAxesListW;

typedef tagAXESLISTA *PAxesList;

typedef tagENUMLOGFONTEXDVA *PEnumLogFontExDVA;

typedef tagENUMLOGFONTEXDVA  TEnumLogFontExDVA;

typedef tagENUMLOGFONTEXDVW *PEnumLogFontExDVW;

typedef tagENUMLOGFONTEXDVW  TEnumLogFontExDVW;

typedef tagENUMLOGFONTEXDVA *PEnumLogFontExDV;

typedef tagENUMTEXTMETRICA *PEnumTextMetricA;

typedef tagENUMTEXTMETRICA  TEnumTextMetricA;

typedef tagENUMTEXTMETRICW *PEnumTextMetricW;

typedef tagENUMTEXTMETRICW  TEnumTextMetricW;

typedef tagENUMTEXTMETRICA *PEnumTextMetric;

typedef _TRIVERTEX *PTriVertex;

typedef _TRIVERTEX  TTriVertex;

typedef _GRADIENT_TRIANGLE *PGradientTriangle;

typedef _GRADIENT_TRIANGLE  TGradientTriangle;

typedef _GRADIENT_RECT *PGradientRect;

typedef _GRADIENT_RECT  TGradientRect;

typedef _BLENDFUNCTION *PBlendFunction;

typedef _BLENDFUNCTION  TBlendFunction;

typedef void *TFNMFEnumProc;

typedef void *TFNEnhMFEnumProc;

typedef tagDIBSECTION *PDIBSection;

typedef tagDIBSECTION  TDIBSection;

typedef tagCOLORADJUSTMENT *PColorAdjustment;

typedef tagCOLORADJUSTMENT  TColorAdjustment;

typedef BOOL __stdcall (*TFNAbortProc)(HDC DC, int p2);

typedef _DOCINFOA *PDocInfoA;

typedef _DOCINFOW *PDocInfoW;

typedef _DOCINFOA *PDocInfo;

typedef _DOCINFOA  TDocInfoA;

typedef _DOCINFOW  TDocInfoW;

typedef _DOCINFOA  TDocInfo;

typedef tagKERNINGPAIR *PKerningPair;

typedef tagKERNINGPAIR  TKerningPair;

typedef void *TFNICMEnumProc;

typedef tagEMR  TEMR;

typedef tagEMRTEXT *PEMRText;

typedef tagEMRTEXT  TEMRText;

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

typedef tagEMRSETMITERLIMIT  TEMRSetMiterLimit;

typedef tagEMRRESTOREDC *PEMRRestoreDC;

typedef tagEMRRESTOREDC  TEMRRestoreDC;

typedef tagEMRSETARCDIRECTION *PEMRSetArcDirection;

typedef tagEMRSETARCDIRECTION  TEMRSetArcDirection;

typedef tagEMRSETMAPPERFLAGS *PEMRSetMapperFlags;

typedef tagEMRSETMAPPERFLAGS  TEMRSetMapperFlags;

typedef tagEMRSETTEXTCOLOR *PEMRSetTextColor;

typedef tagEMRSETTEXTCOLOR  TEMRSetTextColor;

typedef tagEMRSETTEXTCOLOR  TEMRSetBkColor;

typedef tagEMRSETTEXTCOLOR *PEMRSetBkColor;

typedef tagEMRSELECTOBJECT *PEMRSelectObject;

typedef tagEMRSELECTOBJECT  TEMRSelectObject;

typedef tagEMRSELECTOBJECT  EMRDeleteObject;

typedef tagEMRSELECTOBJECT *PEMRDeleteObject;

typedef tagEMRSETCOLORSPACE *PEMRSelectColorSpace;

typedef tagEMRSETCOLORSPACE  TEMRSelectColorSpace;

typedef tagEMRSETCOLORSPACE  EMRDeleteColorSpace;

typedef tagEMRSETCOLORSPACE *PEMRDeleteColorSpace;

typedef tagEMRSELECTPALETTE *PEMRSelectPalette;

typedef tagEMRSELECTPALETTE  TEMRSelectPalette;

typedef tagEMRRESIZEPALETTE *PEMRResizePalette;

typedef tagEMRRESIZEPALETTE  TEMRResizePalette;

typedef tagEMRSETPALETTEENTRIES *PEMRSetPaletteEntries;

typedef tagEMRSETPALETTEENTRIES  TEMRSetPaletteEntries;

typedef tagEMRSETCOLORADJUSTMENT *PEMRSetColorAdjustment;

typedef tagEMRSETCOLORADJUSTMENT  TEMRSetColorAdjustment;

typedef tagEMRGDICOMMENT *PEMRGDIComment;

typedef tagEMRGDICOMMENT  TEMRGDIComment;

typedef tagEMREOF  TEMREOF;

typedef tagEMRLINETO *PEMRLineTo;

typedef tagEMRLINETO  TEMRLineTo;

typedef tagEMRLINETO  EMRMoveToEx;

typedef tagEMRLINETO *PEMRMoveToEx;

typedef tagEMROFFSETCLIPRGN *PEMROffsetClipRgn;

typedef tagEMROFFSETCLIPRGN  TEMROffsetClipRgn;

typedef tagEMRFILLPATH *PEMRFillPath;

typedef tagEMRFILLPATH  TEMRFillPath;

typedef tagEMRFILLPATH  EMRStrokeAndFillPath;

typedef tagEMRFILLPATH *PEMRStrokeAndFillPath;

typedef tagEMRFILLPATH  EMRStrokePath;

typedef tagEMRFILLPATH *PEMRStrokePath;

typedef tagEMREXCLUDECLIPRECT *PEMRExcludeClipRect;

typedef tagEMREXCLUDECLIPRECT  TEMRExcludeClipRect;

typedef tagEMREXCLUDECLIPRECT  EMRIntersectClipRect;

typedef tagEMREXCLUDECLIPRECT *PEMRIntersectClipRect;

typedef tagEMRSETVIEWPORTORGEX *PEMRSetViewportOrgEx;

typedef tagEMRSETVIEWPORTORGEX  TEMRSetViewportOrgEx;

typedef tagEMRSETVIEWPORTORGEX  EMRSetWindowOrgEx;

typedef tagEMRSETVIEWPORTORGEX *PEMRSetWindowOrgEx;

typedef tagEMRSETVIEWPORTORGEX  EMRSetBrushOrgEx;

typedef tagEMRSETVIEWPORTORGEX *PEMRSetBrushOrgEx;

typedef tagEMRSETVIEWPORTEXTEX *PEMRSetViewportExtEx;

typedef tagEMRSETVIEWPORTEXTEX  TEMRSetViewportExtEx;

typedef tagEMRSETVIEWPORTEXTEX  EMRSetWindowExtEx;

typedef tagEMRSETVIEWPORTEXTEX *PEMRSetWindowExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX *PEMRScaleViewportExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX  TEMRScaleViewportExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX  EMRScaleWindowExtEx;

typedef tagEMRSCALEVIEWPORTEXTEX *PEMRScaleWindowExtEx;

typedef tagEMRSETWORLDTRANSFORM *PEMRSetWorldTransform;

typedef tagEMRSETWORLDTRANSFORM  TEMRSetWorldTransform;

typedef tagEMRMODIFYWORLDTRANSFORM *PEMRModifyWorldTransform;

typedef tagEMRMODIFYWORLDTRANSFORM  TEMRModifyWorldTransform;

typedef tagEMRSETPIXELV *PEMRSetPixelV;

typedef tagEMRSETPIXELV  TEMRSetPixelV;

typedef tagEMREXTFLOODFILL *PEMRExtFloodFill;

typedef tagEMREXTFLOODFILL  TEMRExtFloodFill;

typedef tagEMRELLIPSE *PEMREllipse;

typedef tagEMRELLIPSE  TEMREllipse;

typedef tagEMRELLIPSE  EMRRectangle;

typedef tagEMRELLIPSE *PEMRRectangle;

typedef tagEMRROUNDRECT *PEMRRoundRect;

typedef tagEMRROUNDRECT  TEMRRoundRect;

typedef tagEMRARC *PEMRArc;

typedef tagEMRARC  TEMRArc;

typedef tagEMRARC  EMRArcTo;

typedef tagEMRARC *PEMRArcTo;

typedef tagEMRARC  EMRChord;

typedef tagEMRARC *PEMRChord;

typedef tagEMRARC  EMRPie;

typedef tagEMRARC *PEMRPie;

typedef tagEMRANGLEARC *PEMRAngleArc;

typedef tagEMRANGLEARC  TEMRAngleArc;

typedef tagEMRPOLYLINE *PEMRPolyline;

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

typedef tagEMRPOLYDRAW  TEMRPolyDraw;

typedef tagEMRPOLYDRAW16 *PEMRPolyDraw16;

typedef tagEMRPOLYDRAW16  TEMRPolyDraw16;

typedef tagEMRPOLYPOLYLINE *PEMRPolyPolyline;

typedef tagEMRPOLYPOLYLINE  TEMRPolyPolyline;

typedef tagEMRPOLYPOLYLINE  EMRPolyPolygon;

typedef tagEMRPOLYPOLYLINE *PEMRPolyPolygon;

typedef tagEMRPOLYPOLYLINE16 *PEMRPolyPolyline16;

typedef tagEMRPOLYPOLYLINE16  TEMRPolyPolyline16;

typedef tagEMRPOLYPOLYLINE16  EMRPolyPolygon16;

typedef tagEMRPOLYPOLYLINE16 *PEMRPolyPolygon16;

typedef tagEMRINVERTRGN *PEMRInvertRgn;

typedef tagEMRINVERTRGN  TEMRInvertRgn;

typedef tagEMRINVERTRGN  EMRPaintRgn;

typedef tagEMRINVERTRGN *PEMRPaintRgn;

typedef tagEMRFILLRGN *PEMRFillRgn;

typedef tagEMRFILLRGN  TEMRFillRgn;

typedef tagEMRFRAMERGN *PEMRFrameRgn;

typedef tagEMRFRAMERGN  TEMRFrameRgn;

typedef tagEMREXTSELECTCLIPRGN *PEMRExtSelectClipRgn;

typedef tagEMREXTSELECTCLIPRGN  TEMRExtSelectClipRgn;

typedef tagEMREXTTEXTOUTA *PEMRExtTextOut;

typedef tagEMREXTTEXTOUTA  TEMRExtTextOut;

typedef tagEMRPOLYTEXTOUTA *PEMRPolyTextOut;

typedef tagEMRPOLYTEXTOUTA  TEMRPolyTextOut;

typedef tagEMRBITBLT *PEMRBitBlt;

typedef tagEMRBITBLT  TEMRBitBlt;

typedef tagEMRSTRETCHBLT *PEMRStretchBlt;

typedef tagEMRSTRETCHBLT  TEMRStretchBlt;

typedef tagEMRMASKBLT *PEMRMaskBlt;

typedef tagEMRMASKBLT  TEMRMaskBlt;

typedef tagEMRPLGBLT *PEMRPLGBlt;

typedef tagEMRPLGBLT  TEMRPLGBlt;

typedef tagEMRSETDIBITSTODEVICE *PEMRSetDIBitsToDevice;

typedef tagEMRSETDIBITSTODEVICE  TEMRSetDIBitsToDevice;

typedef tagEMRSTRETCHDIBITS *PEMRStretchDIBits;

typedef tagEMRSTRETCHDIBITS  TEMRStretchDIBits;

typedef tagEMRTRANSPARENTBLT *PEMRTransparentBLT;

typedef tagEMRTRANSPARENTBLT  TEMRTransparentBLT;

typedef tagEMREXTCREATEFONTINDIRECTW *PEMRExtCreateFontIndirect;

typedef tagEMREXTCREATEFONTINDIRECTW  TEMRExtCreateFontIndirect;

typedef tagEMRCREATEPALETTE *PEMRCreatePalette;

typedef tagEMRCREATEPALETTE  TEMRCreatePalette;

typedef tagEMRCREATECOLORSPACE *PEMRCreateColorSpace;

typedef tagEMRCREATECOLORSPACE  TEMRCreateColorSpace;

typedef tagEMRCREATEPEN *PEMRCreatePen;

typedef tagEMRCREATEPEN  TEMRCreatePen;

typedef tagEMREXTCREATEPEN *PEMRExtCreatePen;

typedef tagEMREXTCREATEPEN  TEMRExtCreatePen;

typedef tagEMRCREATEBRUSHINDIRECT *PEMRCreateBrushIndirect;

typedef tagEMRCREATEBRUSHINDIRECT  TEMRCreateBrushIndirect;

typedef tagEMRCREATEMONOBRUSH *PEMRCreateMonoBrush;

typedef tagEMRCREATEMONOBRUSH  TEMRCreateMonoBrush;

typedef tagEMRCREATEDIBPATTERNBRUSHPT *PEMRCreateDIBPatternBrushPt;

typedef tagEMRCREATEDIBPATTERNBRUSHPT  TEMRCreateDIBPatternBrushPt;

typedef tagEMRFORMAT *PEMRFormat;

typedef tagEMRFORMAT  TEMRFormat;

typedef tagEMRGLSRECORD *PEMRGLSRecord;

typedef tagEMRGLSRECORD  TEMRGLSRecord;

typedef tagEMRGLSBOUNDEDRECORD *PEMRGLSBoundedRecord;

typedef tagEMRGLSBOUNDEDRECORD  TEMRGLSBoundedRecord;

typedef tagEMRPIXELFORMAT *PEMRPixelFormat;

typedef tagEMRPIXELFORMAT  TEMRPixelFormat;

typedef _POINTFLOAT *PPointFloat;

typedef _POINTFLOAT  TPointFloat;

typedef _GLYPHMETRICSFLOAT *PGlyphMetricsFloat;

typedef _GLYPHMETRICSFLOAT  TGlyphMetricsFloat;

typedef tagLAYERPLANEDESCRIPTOR *PLayerPlaneDescriptor;

typedef tagLAYERPLANEDESCRIPTOR  TLayerPlaneDescriptor;

typedef void *TFNWndProc;

typedef void *TFNDlgProc;

typedef void *TFNTimerProc;

typedef void *TFNGrayStringProc;

typedef void *TFNWndEnumProc;

typedef void *TFNSendAsyncProc;

typedef void *TFNDrawStateProc;

typedef int __stdcall (*TFNHookProc)(int code, int wparam, int lparam);

typedef void *TFNPropEnumProc;

typedef void *TFNPropEnumProcEx;

typedef void *TFNEditWordBreakProc;

typedef void *TFNNameEnumProc;

typedef void *TFNWinStaEnumProc;

typedef void *TFNDeskTopEnumProc;

typedef char *MakeIntResourceA;

typedef wchar_t *MakeIntResourceW;

typedef char *MakeIntResource;

typedef tagCREATESTRUCTA *PCreateStructA;

typedef tagCREATESTRUCTW *PCreateStructW;

typedef tagCREATESTRUCTA *PCreateStruct;

typedef tagCREATESTRUCTA  TCreateStructA;

typedef tagCREATESTRUCTW  TCreateStructW;

typedef tagCREATESTRUCTA  TCreateStruct;

typedef tagCBT_CREATEWNDA *PCBTCreateWnd;

typedef tagCBT_CREATEWNDA  TCBTCreateWnd;

typedef tagCBTACTIVATESTRUCT *PCBTActivateStruct;

typedef tagCBTACTIVATESTRUCT  TCBTActivateStruct;

typedef tagEVENTMSG *PEventMsg;

typedef tagEVENTMSG  TEventMsg;

typedef tagCWPSTRUCT *PCWPStruct;

typedef tagCWPSTRUCT  TCWPStruct;

typedef tagCWPRETSTRUCT *PCWPRetStruct;

typedef tagCWPRETSTRUCT  TCWPRetStruct;

typedef tagDEBUGHOOKINFO *PDebugHookInfo;

typedef tagDEBUGHOOKINFO  TDebugHookInfo;

typedef tagMOUSEHOOKSTRUCT *PMouseHookStruct;

typedef tagMOUSEHOOKSTRUCT  TMouseHookStruct;

typedef tagHARDWAREHOOKSTRUCT *PHardwareHookStruct;

typedef tagHARDWAREHOOKSTRUCT  THardwareHookStruct;

typedef tagUSEROBJECTFLAGS *PUserObjectFlags;

typedef tagUSEROBJECTFLAGS  TUserObjectFlags;

typedef tagWNDCLASSEXA *PWndClassExA;

typedef tagWNDCLASSEXW *PWndClassExW;

typedef tagWNDCLASSEXA *PWndClassEx;

typedef tagWNDCLASSEXA  TWndClassExA;

typedef tagWNDCLASSEXW  TWndClassExW;

typedef tagWNDCLASSEXA  TWndClassEx;

typedef tagWNDCLASSA *PWndClassA;

typedef tagWNDCLASSW *PWndClassW;

typedef tagWNDCLASSA *PWndClass;

typedef tagWNDCLASSA  TWndClassA;

typedef tagWNDCLASSW  TWndClassW;

typedef tagWNDCLASSA  TWndClass;

typedef tagMSG *PMsg;

typedef tagMSG  TMsg;

typedef tagMINMAXINFO *PMinMaxInfo;

typedef tagMINMAXINFO  TMinMaxInfo;

typedef tagCOPYDATASTRUCT *PCopyDataStruct;

typedef tagCOPYDATASTRUCT  TCopyDataStruct;

typedef tagMDINEXTMENU *PMDINextMenu;

typedef tagMDINEXTMENU  TMDINextMenu;

typedef tagWINDOWPOS *PWindowPos;

typedef tagWINDOWPOS  TWindowPos;

typedef tagNCCALCSIZE_PARAMS *PNCCalcSizeParams;

typedef tagNCCALCSIZE_PARAMS  TNCCalcSizeParams;

typedef tagACCEL *PAccel;

typedef tagACCEL  TAccel;

typedef tagPAINTSTRUCT *PPaintStruct;

typedef tagPAINTSTRUCT  TPaintStruct;

typedef tagWINDOWPLACEMENT *PWindowPlacement;

typedef tagWINDOWPLACEMENT  TWindowPlacement;

typedef tagNMHDR *PNMHdr;

typedef tagNMHDR  TNMHdr;

typedef tagSTYLESTRUCT *PStyleStruct;

typedef tagSTYLESTRUCT  TStyleStruct;

#pragma option push -b
enum Windows__1 { odSelected, odGrayed, odDisabled, odChecked, odFocused, odDefault, odHotLight, odInactive, odNoAccel, odNoFocusRect, odReserved1, odReserved2, odComboBoxEdit };
#pragma option pop

typedef Set<Windows__1, odSelected, odComboBoxEdit>  TOwnerDrawState;

typedef tagMEASUREITEMSTRUCT *PMeasureItemStruct;

typedef tagMEASUREITEMSTRUCT  TMeasureItemStruct;

typedef tagDRAWITEMSTRUCT *PDrawItemStruct;

typedef tagDRAWITEMSTRUCT  TDrawItemStruct;

typedef tagDELETEITEMSTRUCT *PDeleteItemStruct;

typedef tagDELETEITEMSTRUCT  TDeleteItemStruct;

typedef tagCOMPAREITEMSTRUCT *PCompareItemStruct;

typedef tagCOMPAREITEMSTRUCT  TCompareItemStruct;

#pragma pack(push, 1)
struct tagBROADCASTSYSMSG
{
	unsigned uiMessage;
	int wParam;
	int lParam;
} ;
#pragma pack(pop)

typedef tagBROADCASTSYSMSG *PBroadcastSysMsg;

typedef tagBROADCASTSYSMSG  TBroadcastSysMsg;

typedef tagBROADCASTSYSMSG  BROADCASTSYSMSG;

typedef DLGTEMPLATE *PDlgTemplate;

typedef DLGTEMPLATE  TDlgTemplate;

typedef DLGITEMTEMPLATE *PDlgItemTemplate;

typedef DLGITEMTEMPLATE  TDlgItemTemplate;

typedef Byte TKeyboardState[256];

typedef Byte *PKeyboardState;

typedef tagMOUSEINPUT *PMouseInput;

typedef tagMOUSEINPUT  TMouseInput;

typedef tagKEYBDINPUT *PKeybdInput;

typedef tagKEYBDINPUT  TKeybdInput;

typedef tagHARDWAREINPUT *PHardwareInput;

typedef tagHARDWAREINPUT  THardwareInput;

typedef tagINPUT *PInput;

typedef tagINPUT  TInput;

typedef tagLASTINPUTINFO *PLastInputInfo;

typedef tagLASTINPUTINFO  TLastInputInfo;

typedef tagTPMPARAMS *PTPMParams;

typedef tagTPMPARAMS  TTPMParams;

typedef tagMENUITEMINFOA *PMenuItemInfoA;

typedef tagMENUITEMINFOW *PMenuItemInfoW;

typedef tagMENUITEMINFOA *PMenuItemInfo;

typedef tagMENUITEMINFOA  TMenuItemInfoA;

typedef tagMENUITEMINFOW  TMenuItemInfoW;

typedef tagMENUITEMINFOA  TMenuItemInfo;

typedef tagDROPSTRUCT *PDropStruct;

typedef tagDROPSTRUCT  TDropStruct;

typedef tagDRAWTEXTPARAMS *PDrawTextParams;

typedef tagDRAWTEXTPARAMS  TDrawTextParams;

typedef tagHELPINFO *PHelpInfo;

typedef tagHELPINFO  THelpInfo;

typedef void __fastcall (*TPRMsgBoxCallback)(tagHELPINFO &lpHelpInfo);

typedef tagMSGBOXPARAMSA *PMsgBoxParamsA;

typedef tagMSGBOXPARAMSW *PMsgBoxParamsW;

typedef tagMSGBOXPARAMSA *PMsgBoxParams;

typedef tagMSGBOXPARAMSA  TMsgBoxParamsA;

typedef tagMSGBOXPARAMSW  TMsgBoxParamsW;

typedef tagMSGBOXPARAMSA  TMsgBoxParams;

typedef MENUITEMTEMPLATEHEADER *PMenuItemTemplateHeader;

typedef MENUITEMTEMPLATEHEADER  TMenuItemTemplateHeader;

typedef MENUITEMTEMPLATE *PMenuItemTemplate;

typedef MENUITEMTEMPLATE  TMenuItemTemplate;

typedef _ICONINFO *PIconInfo;

typedef _ICONINFO  TIconInfo;

typedef tagCURSORSHAPE *PCursorShape;

typedef tagCURSORSHAPE  TCursorShape;

typedef tagSCROLLINFO *PScrollInfo;

typedef tagSCROLLINFO  TScrollInfo;

typedef tagMDICREATESTRUCTA *PMDICreateStructA;

typedef tagMDICREATESTRUCTW *PMDICreateStructW;

typedef tagMDICREATESTRUCTA *PMDICreateStruct;

typedef tagMDICREATESTRUCTA  TMDICreateStructA;

typedef tagMDICREATESTRUCTW  TMDICreateStructW;

typedef tagMDICREATESTRUCTA  TMDICreateStruct;

typedef tagCLIENTCREATESTRUCT *PClientCreateStruct;

typedef tagCLIENTCREATESTRUCT  TClientCreateStruct;

typedef tagMULTIKEYHELPA *PMultiKeyHelpA;

typedef tagMULTIKEYHELPW *PMultiKeyHelpW;

typedef tagMULTIKEYHELPA *PMultiKeyHelp;

typedef tagMULTIKEYHELPA  TMultiKeyHelpA;

typedef tagMULTIKEYHELPW  TMultiKeyHelpW;

typedef tagMULTIKEYHELPA  TMultiKeyHelp;

typedef tagHELPWININFOA *PHelpWinInfoA;

typedef tagHELPWININFOW *PHelpWinInfoW;

typedef tagHELPWININFOA *PHelpWinInfo;

typedef tagHELPWININFOA  THelpWinInfoA;

typedef tagHELPWININFOW  THelpWinInfoW;

typedef tagHELPWININFOA  THelpWinInfo;

typedef tagNONCLIENTMETRICSA *PNonClientMetricsA;

typedef tagNONCLIENTMETRICSW *PNonClientMetricsW;

typedef tagNONCLIENTMETRICSA *PNonClientMetrics;

typedef tagNONCLIENTMETRICSA  TNonClientMetricsA;

typedef tagNONCLIENTMETRICSW  TNonClientMetricsW;

typedef tagNONCLIENTMETRICSA  TNonClientMetrics;

typedef tagMINIMIZEDMETRICS *PMinimizedMetrics;

typedef tagMINIMIZEDMETRICS  TMinimizedMetrics;

typedef tagICONMETRICSA *PIconMetricsA;

typedef tagICONMETRICSW *PIconMetricsW;

typedef tagICONMETRICSA *PIconMetrics;

typedef tagICONMETRICSA  TIconMetricsA;

typedef tagICONMETRICSW  TIconMetricsW;

typedef tagICONMETRICSA  TIconMetrics;

typedef tagANIMATIONINFO *PAnimationInfo;

typedef tagANIMATIONINFO  TAnimationInfo;

typedef tagSERIALKEYSA *PSerialKeysA;

typedef tagSERIALKEYSW *PSerialKeysW;

typedef tagSERIALKEYSA *PSerialKeys;

typedef tagSERIALKEYSA  TSerialKeysA;

typedef tagSERIALKEYSW  TSerialKeysW;

typedef tagSERIALKEYSA  TSerialKeys;

typedef tagHIGHCONTRASTA *PHighContrastA;

typedef tagHIGHCONTRASTW *PHighContrastW;

typedef tagHIGHCONTRASTA *PHighContrast;

typedef tagHIGHCONTRASTA  THighContrastA;

typedef tagHIGHCONTRASTW  THighContrastW;

typedef tagHIGHCONTRASTA  THighContrast;

typedef tagFILTERKEYS *PFilterKeys;

typedef tagFILTERKEYS  TFilterKeys;

typedef tagSTICKYKEYS *PStickyKeys;

typedef tagSTICKYKEYS  TStickyKeys;

typedef tagMOUSEKEYS *PMouseKeys;

typedef tagMOUSEKEYS  TMouseKeys;

typedef tagACCESSTIMEOUT *PAccessTimeout;

typedef tagACCESSTIMEOUT  TAccessTimeout;

typedef tagSOUNDSENTRYA *PSoundsEntryA;

typedef tagSOUNDSENTRYW *PSoundsEntryW;

typedef tagSOUNDSENTRYA *PSoundsEntry;

typedef tagSOUNDSENTRYA  TSoundsEntryA;

typedef tagSOUNDSENTRYW  TSoundsEntryW;

typedef tagSOUNDSENTRYA  TSoundsEntry;

typedef tagTOGGLEKEYS *PToggleKeys;

typedef tagTOGGLEKEYS  TToggleKeys;

typedef _cpinfo *PCPInfo;

typedef _cpinfo  TCPInfo;

typedef _numberfmtA *PNumberFmtA;

typedef _numberfmtW *PNumberFmtW;

typedef _numberfmtA *PNumberFmt;

typedef _numberfmtA  TNumberFmtA;

typedef _numberfmtW  TNumberFmtW;

typedef _numberfmtA  TNumberFmt;

typedef _currencyfmtA *PCurrencyFmtA;

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

typedef _COORD *PCoord;

typedef _COORD  TCoord;

typedef _SMALL_RECT *PSmallRect;

typedef _SMALL_RECT  TSmallRect;

typedef _KEY_EVENT_RECORD *PKeyEventRecord;

typedef _KEY_EVENT_RECORD  TKeyEventRecord;

typedef _MOUSE_EVENT_RECORD *PMouseEventRecord;

typedef _MOUSE_EVENT_RECORD  TMouseEventRecord;

typedef _WINDOW_BUFFER_SIZE_RECORD *PWindowBufferSizeRecord;

typedef _WINDOW_BUFFER_SIZE_RECORD  TWindowBufferSizeRecord;

typedef _MENU_EVENT_RECORD *PMenuEventRecord;

typedef _MENU_EVENT_RECORD  TMenuEventRecord;

typedef _FOCUS_EVENT_RECORD *PFocusEventRecord;

typedef _FOCUS_EVENT_RECORD  TFocusEventRecord;

typedef _INPUT_RECORD *PInputRecord;

#pragma pack(push, 1)
struct Windows__2
{
	
	union
	{
		struct 
		{
			_FOCUS_EVENT_RECORD FocusEvent;
			
		};
		struct 
		{
			_MENU_EVENT_RECORD MenuEvent;
			
		};
		struct 
		{
			_WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
			
		};
		struct 
		{
			_MOUSE_EVENT_RECORD MouseEvent;
			
		};
		struct 
		{
			_KEY_EVENT_RECORD KeyEvent;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef _INPUT_RECORD  TInputRecord;

typedef _CHAR_INFO *PCharInfo;

typedef _CHAR_INFO  TCharInfo;

typedef _CONSOLE_SCREEN_BUFFER_INFO *PConsoleScreenBufferInfo;

typedef _CONSOLE_SCREEN_BUFFER_INFO  TConsoleScreenBufferInfo;

typedef _CONSOLE_CURSOR_INFO *PConsoleCursorInfo;

typedef _CONSOLE_CURSOR_INFO  TConsoleCursorInfo;

typedef void *TFNHandlerRoutine;

typedef tagVS_FIXEDFILEINFO *PVSFixedFileInfo;

typedef tagVS_FIXEDFILEINFO  TVSFixedFileInfo;

typedef HKEY *PHKEY;

typedef val_context *PValContext;

typedef val_context  TValContext;

typedef pvalueA *PPValueA;

typedef pvalueW *PPValueW;

typedef pvalueA *PPValue;

typedef pvalueA  TPValueA;

typedef pvalueW  TPValueW;

typedef pvalueA  TPValue;

typedef void *TFNQueryHandler;

typedef void * *PFNQueryHandler;

typedef provider_info *PProviderInfo;

typedef provider_info  TProviderInfo;

typedef provider_info  TRegProvider;

typedef provider_info *PProvider;

typedef value_entA *PValueEntA;

typedef value_entW *PValueEntW;

typedef value_entA *PValueEnt;

typedef value_entA  TValueEntA;

typedef value_entW  TValueEntW;

typedef value_entA  TValueEnt;

typedef value_entA  TValEnt;

typedef value_entA *PValEnt;

typedef _NETRESOURCEA *PNetResourceA;

typedef _NETRESOURCEW *PNetResourceW;

typedef _NETRESOURCEA *PNetResource;

typedef _NETRESOURCEA  TNetResourceA;

typedef _NETRESOURCEW  TNetResourceW;

typedef _NETRESOURCEA  TNetResource;

typedef _CONNECTDLGSTRUCTA *PConnectDlgStruct;

typedef _CONNECTDLGSTRUCTA  TConnectDlgStruct;

typedef _DISCDLGSTRUCTA *PDiscDlgStructA;

typedef _DISCDLGSTRUCTW *PDiscDlgStructW;

typedef _DISCDLGSTRUCTA *PDiscDlgStruct;

typedef _DISCDLGSTRUCTA  TDiscDlgStructA;

typedef _DISCDLGSTRUCTW  TDiscDlgStructW;

typedef _DISCDLGSTRUCTA  TDiscDlgStruct;

typedef _UNIVERSAL_NAME_INFOA *PUniversalNameInfoA;

typedef _UNIVERSAL_NAME_INFOW *PUniversalNameInfoW;

typedef _UNIVERSAL_NAME_INFOA *PUniversalNameInfo;

typedef _UNIVERSAL_NAME_INFOA  TUniversalNameInfoA;

typedef _UNIVERSAL_NAME_INFOW  TUniversalNameInfoW;

typedef _UNIVERSAL_NAME_INFOA  TUniversalNameInfo;

typedef _REMOTE_NAME_INFOA *PRemoteNameInfoA;

typedef _REMOTE_NAME_INFOW *PRemoteNameInfoW;

typedef _REMOTE_NAME_INFOA *PRemoteNameInfo;

typedef _REMOTE_NAME_INFOA  TRemoteNameInfoA;

typedef _REMOTE_NAME_INFOW  TRemoteNameInfoW;

typedef _REMOTE_NAME_INFOA  TRemoteNameInfo;

typedef _NETINFOSTRUCT *PNetInfoStruct;

typedef _NETINFOSTRUCT  TNetInfoStruct;

typedef void *TFNGetProfilePath;

typedef void *TFNReconcileProfile;

typedef void *TFNProcessPolicies;

typedef _NETCONNECTINFOSTRUCT *PNetConnectInfoStruct;

typedef _NETCONNECTINFOSTRUCT  TNetConnectInfoStruct;

typedef DDEACK *PDDEAck;

typedef DDEACK  TDDEAck;

typedef DDEADVISE *PDDEAdvise;

typedef DDEADVISE  TDDEAdvise;

typedef DDEDATA *PDDEData;

typedef DDEDATA  TDDEData;

typedef DDEPOKE *PDDEPoke;

typedef DDEPOKE  TDDEPoke;

//-- var, const, procedure ---------------------------------------------------
static const unsigned LDTF_BASEMID = 0xff000000;
static const int LDTF_TYPE_8 = 0xf80000;
static const int LDTF_DPL = 0x60000;
static const int LDTF_PRES = 0x10000;
static const Word LDTF_LIMITHI = 0xf000;
static const Word LDTF_SYS = 0x800;
static const Word LDTF_RESERVED_0 = 0x400;
static const Word LDTF_DEFAULT_BIG = 0x200;
static const Word LDTF_GRANULARITY = 0x100;
static const Byte LDTF_BASEHI = 0xff;
static const int _DELETE = 0x10000;
static const Shortint _ABORTDOC = 0x2;
static const Shortint _SETABORTPROC = 0x9;
static const Shortint _STARTDOC = 0xa;
static const Shortint _ENDDOC = 0xb;
static const Shortint _SETMITERLIMIT = 0x17;
static const Word _EXTTEXTOUT = 0x200;
static const Word _STRETCHBLT = 0x800;
static const Byte GCP_GLYPHINDEXING = 0x80;
static const int GCP_NODIACRITICS = 0x20000;
static const Word wnd_Broadcast = 0xffff;
static const Shortint wnd_Message = 0xfffffffd;
static const Shortint COLOR_ENDCOLORS = 0x1e;
static const Shortint ID_OK = 0x1;
static const Shortint ID_CANCEL = 0x2;
static const Shortint ID_ABORT = 0x3;
static const Shortint ID_RETRY = 0x4;
static const Shortint ID_IGNORE = 0x5;
static const Shortint ID_YES = 0x6;
static const Shortint ID_NO = 0x7;
static const Shortint ID_CLOSE = 0x8;
static const Shortint ID_HELP = 0x9;
static const Shortint _MOUSE_EVENT = 0x2;
static const Byte dde_AppReturnCode = 0xff;
static const Word dde_Busy = 0x4000;
static const Word dde_Ack = 0x8000;
static const Word dde_DeferUpd = 0x4000;
static const Word dde_AckReq = 0x8000;
static const Word dde_Response = 0x1000;
static const Word dde_Release = 0x2000;
#define advapi32 "advapi32.dll"
#define kernel32 "kernel32.dll"
#define mpr "mpr.dll"
#define comctl32 "comctl32.dll"
#define gdi32 "gdi32.dll"
#define opengl32 "opengl32.dll"
#define user32 "user32.dll"
#define wintrust "wintrust.dll"
#define msimg32 "msimg32.dll"
extern PACKAGE int __fastcall HResultCode(HRESULT hr);
extern PACKAGE int __fastcall HResultFacility(HRESULT hr);
extern PACKAGE int __fastcall HResultSeverity(HRESULT hr);
extern PACKAGE HRESULT __fastcall HResultFromWin32(int x);
extern PACKAGE HRESULT __fastcall HResultFromNT(int x);

}	/* namespace Windows */
using namespace Windows;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Windows
