// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'Ole2.pas' rev: 6.00

#ifndef Ole2HPP
#define Ole2HPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <ole2.h>

namespace Ole2
{
//-- type declarations -------------------------------------------------------
typedef HRESULT TResultList[65536];

typedef HRESULT *PResultList;

typedef wchar_t TOleChar;

typedef wchar_t *POleStr;

typedef wchar_t *TOleStrList[65536];

typedef wchar_t * *POleStrList;

typedef System::Comp Largeint;

struct TGUID;
typedef GUID *PGUID;

#pragma pack(push, 4)
struct TGUID
{
	unsigned D1;
	Word D2;
	Word D3;
	Byte D4[8];
} ;
#pragma pack(pop)

typedef GUID *PIID;

typedef GUID  TIID;

typedef GUID *PCLSID;

typedef GUID  TCLSID;

typedef _OBJECTID *PObjectID;

typedef _OBJECTID  TObjectID;

typedef unsigned TLCID;

typedef tagBIND_OPTS *PBindOpts;

typedef tagBIND_OPTS  TBindOpts;

typedef tagSTATSTG *PStatStg;

typedef tagSTATSTG  TStatStg;

typedef wchar_t * *TSNB;

typedef tagDVTARGETDEVICE *PDVTargetDevice;

#pragma pack(push, 1)
struct Ole2__42
{
	
} ;
#pragma pack(pop)

typedef tagDVTARGETDEVICE  TDVTargetDevice;

typedef Word *PClipFormat;

typedef Word TClipFormat;

typedef tagFORMATETC *PFormatEtc;

typedef tagFORMATETC  TFormatEtc;

typedef tagSTATDATA *PStatData;

typedef tagSTATDATA  TStatData;

typedef tagRemSTGMEDIUM *PRemStgMedium;

#pragma pack(push, 1)
struct Ole2__82
{
	
} ;
#pragma pack(pop)

typedef tagRemSTGMEDIUM  TRemStgMedium;

typedef tagSTGMEDIUM *PStgMedium;

typedef tagSTGMEDIUM  TStgMedium;

typedef tagINTERFACEINFO *PInterfaceInfo;

typedef tagINTERFACEINFO  TInterfaceInfo;

typedef int TRpcOleDataRep;

typedef tagRPCOLEMESSAGE *PRpcOleMessage;

typedef tagRPCOLEMESSAGE  TRpcOleMessage;

typedef wchar_t * *PBStr;

typedef wchar_t *TBStr;

typedef wchar_t *TBStrList[65536];

typedef wchar_t * *PBStrList;

typedef tagBLOB *PBlob;

typedef tagCLIPDATA *PClipData;

typedef tagCLIPDATA  TClipData;

typedef tagSAFEARRAYBOUND *PSafeArrayBound;

typedef tagSAFEARRAYBOUND  TSafeArrayBound;

typedef tagSAFEARRAY *PSafeArray;

typedef tagSAFEARRAY  TSafeArray;

typedef double TOleDate;

typedef System::Comp TCurrency;

typedef Word TOleBool;

typedef Word TVarType;

typedef tagVARIANT *PVariantArg;

typedef tagVARIANT  TVariantArg;

typedef tagVARIANT TVariantArgList[65536];

typedef tagVARIANT *PVariantArgList;

typedef int TDispID;

typedef int TDispIDList[65536];

typedef int *PDispIDList;

typedef int TMemberID;

typedef int TMemberIDList[65536];

typedef int *PMemberIDList;

typedef int TPropID;

typedef int HRefType;

typedef int TTypeKind;

typedef tagARRAYDESC *PArrayDesc;

typedef tagTYPEDESC *PTypeDesc;

typedef tagTYPEDESC  TTypeDesc;

typedef tagARRAYDESC  TArrayDesc;

typedef tagIDLDESC *PIDLDesc;

typedef tagIDLDESC  TIDLDesc;

typedef tagELEMDESC *PElemDesc;

typedef tagELEMDESC  TElemDesc;

typedef tagELEMDESC TElemDescList[65536];

typedef tagELEMDESC *PElemDescList;

typedef tagTYPEATTR *PTypeAttr;

typedef tagTYPEATTR  TTypeAttr;

typedef tagDISPPARAMS *PDispParams;

typedef tagDISPPARAMS  TDispParams;

typedef tagEXCEPINFO *PExcepInfo;

typedef HRESULT __stdcall (*TFNDeferredFillIn)(PExcepInfo ExInfo);

typedef tagEXCEPINFO  TExcepInfo;

typedef int TFuncKind;

typedef int TInvokeKind;

typedef int TCallConv;

typedef tagFUNCDESC *PFuncDesc;

typedef tagFUNCDESC  TFuncDesc;

typedef int TVarKind;

typedef tagVARDESC *PVarDesc;

typedef tagVARDESC  TVarDesc;

typedef int TDescKind;

typedef tagBINDPTR *PBindPtr;

typedef tagBINDPTR  TBindPtr;

typedef int TSysKind;

typedef tagTLIBATTR *PTLibAttr;

typedef tagTLIBATTR  TTLibAttr;

typedef ITypeInfo* TTypeInfoList[65536];

typedef ITypeInfo* *PTypeInfoList;

typedef tagPARAMDATA *PParamData;

typedef tagPARAMDATA  TParamData;

typedef tagPARAMDATA TParamDataList[65536];

typedef tagPARAMDATA *PParamDataList;

typedef tagMETHODDATA *PMethodData;

typedef tagMETHODDATA  TMethodData;

typedef tagMETHODDATA TMethodDataList[65536];

typedef tagMETHODDATA *PMethodDataList;

typedef tagINTERFACEDATA *PInterfaceData;

typedef tagINTERFACEDATA  TInterfaceData;

typedef tagOBJECTDESCRIPTOR *PObjectDescriptor;

typedef tagOBJECTDESCRIPTOR  TObjectDescriptor;

typedef tagOBJECTDESCRIPTOR *PLinkSrcDescriptor;

typedef tagOBJECTDESCRIPTOR  TLinkSrcDescriptor;

typedef tagOIFI *POleInPlaceFrameInfo;

typedef tagOIFI  TOleInPlaceFrameInfo;

typedef tagOleMenuGroupWidths *POleMenuGroupWidths;

typedef tagOleMenuGroupWidths  TOleMenuGroupWidths;

typedef BOOL __stdcall (*TContinueFunc)(int dwContinue);

typedef tagOLEVERB *POleVerb;

typedef tagOLEVERB  TOleVerb;

typedef HRESULT __stdcall (*TDLLGetClassObject)(const GUID &clsid, const GUID &iid, void *pv);

typedef HRESULT __stdcall (*TDLLCanUnloadNow)(void);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall Succeeded(HRESULT Res);
extern PACKAGE bool __fastcall Failed(HRESULT Res);
extern PACKAGE int __fastcall ResultCode(HRESULT Res);
extern PACKAGE int __fastcall ResultFacility(HRESULT Res);
extern PACKAGE int __fastcall ResultSeverity(HRESULT Res);

}	/* namespace Ole2 */
using namespace Ole2;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Ole2
