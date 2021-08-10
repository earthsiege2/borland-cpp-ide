// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'ActiveX.pas' rev: 5.00

#ifndef ActiveXHPP
#define ActiveXHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Messages.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
//---------------------------------------------------------------------------
// if compilation errors occur while attempting to access structs, unions, or enums
// define NO_WIN32_LEAN_AND_MEAN so that the appropriate windows headers are included.
//---------------------------------------------------------------------------

#if defined(NO_WIN32_LEAN_AND_MEAN)
#include <olectl.h>
#include <docobj.H>
#endif
#include <oleauto.h>
#if defined(NO_WIN32_LEAN_AND_MEAN)
#include <propidl.h>
#endif

#if !defined(NO_WIN32_LEAN_AND_MEAN)
//---------------------------------------------------------------------------
// forward struct declarations
//---------------------------------------------------------------------------
struct _COSERVERINFO;
struct tagSAFEARRAYBOUND;
struct tagSAFEARRAY;
struct tagPOINTF;
struct tagPOINTF;
struct tagCONTROLINFO;
struct tagCONTROLINFO;
struct tagBIND_OPTS;
struct tagBIND_OPTS;
struct tagSTATSTG;
struct tagSTATSTG;
struct tagDVTARGETDEVICE;
struct tagFORMATETC;
struct tagFORMATETC;
struct tagSTATDATA;
struct tagSTATDATA;
struct tagRemSTGMEDIUM;
struct tagRemSTGMEDIUM;
struct tagSTGMEDIUM;
struct tagSTGMEDIUM;
struct tagINTERFACEINFO;
struct tagINTERFACEINFO;
struct tagRPCOLEMESSAGE;
struct tagRPCOLEMESSAGE;
struct tagDEC;
struct tagCLIPDATA;
struct tagCLIPDATA;
struct tagPROPVARIANT;
struct tagCAUB;
struct tagCAUB;
struct tagCAI;
struct tagCAI;
struct tagCAUI;
struct tagCAUI;
struct tagCAL;
struct tagCAL;
struct tagCAUL;
struct tagCAUL;
struct tagCAFLT;
struct tagCAFLT;
struct tagCADBL;
struct tagCADBL;
struct tagCACY;
struct tagCACY;
struct tagCADATE;
struct tagCADATE;
struct tagCABSTR;
struct tagCABSTR;
struct tagCABOOL;
struct tagCABOOL;
struct tagCASCODE;
struct tagCASCODE;
struct tagCAPROPVARIANT;
struct tagCAPROPVARIANT;
struct tagCAH;
struct tagCAH;
struct tagCAUH;
struct tagCAUH;
struct tagCALPSTR;
struct tagCALPSTR;
struct tagCALPWSTR;
struct tagCALPWSTR;
struct tagCAFILETIME;
struct tagCAFILETIME;
struct tagCACLIPDATA;
struct tagCACLIPDATA;
struct tagCACLSID;
struct tagCACLSID;
struct tagPROPVARIANT;
struct tagPROPSPEC;
struct tagPROPSPEC;
struct tagSTATPROPSTG;
struct tagSTATPROPSTG;
struct tagSTATPROPSETSTG;
struct tagSTATPROPSETSTG;
struct tagARRAYDESC;
struct tagTYPEDESC;
struct tagTYPEDESC;
struct tagARRAYDESC;
struct tagIDLDESC;
struct tagIDLDESC;
struct tagPARAMDESCEX;
struct tagPARAMDESCEX;
struct tagPARAMDESC;
struct tagPARAMDESC;
struct tagELEMDESC;
struct tagELEMDESC;
struct tagELEMDESC;
struct tagELEMDESC;
struct tagTYPEATTR;
struct tagTYPEATTR;
struct tagDISPPARAMS;
struct tagDISPPARAMS;
struct tagEXCEPINFO;
struct tagEXCEPINFO;
struct tagFUNCDESC;
struct tagVARDESC;
union  tagBINDPTR;
struct tagTLIBATTR;
struct tagCUSTDATAITEM;
struct tagCUSTDATA;
struct tagPARAMDATA;
struct tagMETHODDATA;
struct tagINTERFACEDATA;
enum   tagREGKIND;
struct tagOBJECTDESCRIPTOR;
struct tagOIFI;
struct tagOleMenuGroupWidths;
struct tagOLEVERB;
struct tagCONNECTDATA;
struct tagLICINFO;
struct tagCAUUID;
struct tagCALPOLESTR;
struct tagCADWORD;
struct tagOCPFIPARAMS;
struct tagPROPPAGEINFO;
struct tagFONTDESC;
struct tagPICTDESC;
struct tagPAGERANGE;
struct tagPAGESET;
struct _tagOLECMD;
struct _tagOLECMDTEXT;
struct tagQACONTAINER;
struct tagQACONTROL;
struct tagMULTI_QI;
#endif

namespace Activex
{
//-- type declarations -------------------------------------------------------
typedef unsigned *PPropID;

typedef unsigned TPropID;

typedef Windows::TRect *PBorderWidths;

typedef Windows::TRect  TBorderWidths;

typedef HRESULT *PHResult;

typedef HRESULT TResultList[65536];

typedef HRESULT *PResultList;

typedef _di_IUnknown TUnknownList[65536];

typedef _di_IUnknown *PUnknownList;

typedef wchar_t TOleChar;

typedef wchar_t *POleStr;

typedef wchar_t * *PPOleStr;

typedef wchar_t *TOleStrList[65536];

typedef wchar_t * *POleStrList;

typedef GUID *PIID;

typedef GUID  TIID;

typedef GUID *PCLSID;

typedef GUID  TCLSID;

typedef _OBJECTID *PObjectID;

typedef _OBJECTID  TObjectID;

typedef unsigned TLCID;

typedef GUID *PFmtID;

typedef GUID  TFmtID;

typedef tagTEXTMETRICW *PTextMetricOle;

typedef tagTEXTMETRICW  TTextMetricOle;

typedef unsigned TOleColor;

typedef _COSERVERINFO *PCoServerInfo;

typedef _COSERVERINFO  TCoServerInfo;

typedef tagMULTI_QI *PMultiQI;

typedef tagMULTI_QI  TMultiQI;

typedef tagMULTI_QI TMultiQIArray[65536];

typedef tagMULTI_QI *PMultiQIArray;

typedef tagSAFEARRAYBOUND *PSafeArrayBound;

typedef tagSAFEARRAYBOUND  TSafeArrayBound;

typedef tagSAFEARRAY *PSafeArray;

typedef tagSAFEARRAY  TSafeArray;

typedef double *POleDate;

typedef Word *POleBool;

typedef int TOleEnum;

typedef tagPOINTF *PPointF;

typedef tagPOINTF  TPointF;

typedef tagCONTROLINFO *PControlInfo;

typedef tagCONTROLINFO  TControlInfo;

typedef tagBIND_OPTS *PBindOpts;

typedef tagBIND_OPTS  TBindOpts;

typedef tagSTATSTG *PStatStg;

typedef tagSTATSTG  TStatStg;

typedef wchar_t * *TSNB;

typedef tagDVTARGETDEVICE *PDVTargetDevice;

#pragma pack(push, 1)
struct ActiveX__1
{
	
} ;
#pragma pack(pop)

typedef tagDVTARGETDEVICE  TDVTargetDevice;

typedef tagFORMATETC *PFormatEtc;

typedef tagFORMATETC  TFormatEtc;

typedef tagSTATDATA *PStatData;

typedef tagSTATDATA  TStatData;

typedef tagRemSTGMEDIUM *PRemStgMedium;

#pragma pack(push, 1)
struct ActiveX__2
{
	
} ;
#pragma pack(pop)

typedef tagRemSTGMEDIUM  TRemStgMedium;

typedef tagSTGMEDIUM *PStgMedium;

typedef tagSTGMEDIUM  TStgMedium;

typedef tagINTERFACEINFO *PInterfaceInfo;

typedef tagINTERFACEINFO  TInterfaceInfo;

typedef unsigned TRpcOleDataRep;

typedef tagRPCOLEMESSAGE *PRpcOleMessage;

typedef tagRPCOLEMESSAGE  TRpcOleMessage;

typedef wchar_t * *PBStr;

typedef wchar_t *TBStr;

typedef wchar_t *TBStrList[65536];

typedef wchar_t * *PBStrList;

typedef System::Comp *PComp;

typedef tagDEC *PDecimal;

typedef tagDEC  TDecimal;

typedef tagCLIPDATA *PClipData;

typedef tagCLIPDATA  TClipData;

typedef tagPROPVARIANT *PPropVariant;

typedef tagCAUB *PCAUB;

typedef tagCAUB  TCAUB;

typedef tagCAI *PCAI;

typedef tagCAI  TCAI;

typedef tagCAUI *PCAUI;

typedef tagCAUI  TCAUI;

typedef tagCAL *PCAL;

typedef tagCAL  TCAL;

typedef tagCAUL *PCAUL;

typedef tagCAUL  TCAUL;

typedef tagCAFLT *PCAFLT;

typedef tagCAFLT  TCAFLT;

typedef tagCADBL *PCADBL;

typedef tagCADBL  TCADBL;

typedef tagCACY *PCACY;

typedef tagCACY  TCACY;

typedef tagCADATE *PCADATE;

typedef tagCADATE  TCADATE;

typedef tagCABSTR *PCABSTR;

typedef tagCABSTR  TCABSTR;

typedef tagCABOOL *PCABOOL;

typedef tagCABOOL  TCABOOL;

typedef tagCASCODE *PCASCODE;

typedef tagCASCODE  TCASCODE;

typedef tagCAPROPVARIANT *PCAPROPVARIANT;

typedef tagCAPROPVARIANT  TCAPROPVARIANT;

typedef tagCAH *PCAH;

typedef tagCAH  TCAH;

typedef tagCAUH *PCAUH;

typedef tagCAUH  TCAUH;

typedef tagCALPSTR *PCALPSTR;

typedef tagCALPSTR  TCALPSTR;

typedef tagCALPWSTR *PCALPWSTR;

typedef tagCALPWSTR  TCALPWSTR;

typedef tagCAFILETIME *PCAFILETIME;

typedef tagCAFILETIME  TCAFILETIME;

typedef tagCACLIPDATA *PCACLIPDATA;

typedef tagCACLIPDATA  TCACLIPDATA;

typedef tagCACLSID *PCACLSID;

typedef tagCACLSID  TCACLSID;

typedef tagPROPVARIANT  TPropVariant;

typedef tagPROPSPEC *PPropSpec;

typedef tagPROPSPEC  TPropSpec;

typedef tagSTATPROPSTG *PStatPropStg;

typedef tagSTATPROPSTG  TStatPropStg;

typedef tagSTATPROPSETSTG *PStatPropSetStg;

typedef tagSTATPROPSETSTG  TStatPropSetStg;

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

typedef unsigned HRefType;

typedef unsigned TTypeKind;

typedef tagARRAYDESC *PArrayDesc;

typedef tagTYPEDESC *PTypeDesc;

typedef tagTYPEDESC  TTypeDesc;

typedef tagARRAYDESC  TArrayDesc;

typedef tagIDLDESC *PIDLDesc;

typedef tagIDLDESC  TIDLDesc;

typedef tagPARAMDESCEX *PParamDescEx;

typedef tagPARAMDESCEX  TParamDescEx;

typedef tagPARAMDESC *PParamDesc;

typedef tagPARAMDESC  TParamDesc;

typedef tagELEMDESC *PElemDesc;

typedef tagELEMDESC  TElemDesc;

typedef tagELEMDESC TElemDescList[65536];

typedef tagELEMDESC *PElemDescList;

typedef tagTYPEATTR *PTypeAttr;

typedef tagTYPEATTR  TTypeAttr;

typedef tagDISPPARAMS *PDispParams;

typedef tagDISPPARAMS  TDispParams;

typedef tagEXCEPINFO *PExcepInfo;

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

typedef _di_ITypeInfo TTypeInfoList[65536];

typedef _di_ITypeInfo *PTypeInfoList;

typedef tagCUSTDATAITEM *PCustDataItem;

typedef tagCUSTDATAITEM  TCustDataItem;

typedef tagCUSTDATAITEM TCustDataItemList[65536];

typedef tagCUSTDATAITEM *PCustDataItemList;

typedef tagCUSTDATA *PCustData;

typedef tagCUSTDATA  TCustData;

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

typedef tagREGKIND TRegKind;

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

typedef tagCONNECTDATA *PConnectData;

typedef tagCONNECTDATA  TConnectData;

typedef tagLICINFO *PLicInfo;

typedef tagLICINFO  TLicInfo;

typedef GUID TGUIDList[65536];

typedef GUID *PGUIDList;

typedef tagCAUUID *PCAGUID;

typedef tagCAUUID  TCAGUID;

typedef tagCALPOLESTR *PCAPOleStr;

typedef tagCALPOLESTR  TCAPOleStr;

typedef int TLongintList[65536];

typedef int *PLongintList;

typedef tagCADWORD *PCALongint;

typedef tagCADWORD  TCALongint;

typedef tagOCPFIPARAMS *POCPFIParams;

typedef tagOCPFIPARAMS  TOCPFIParams;

typedef tagPROPPAGEINFO *PPropPageInfo;

typedef tagPROPPAGEINFO  TPropPageInfo;

typedef tagFONTDESC *PFontDesc;

typedef tagFONTDESC  TFontDesc;

typedef tagPICTDESC *PPictDesc;

typedef tagPICTDESC  TPictDesc;

typedef tagPAGERANGE *PPageRange;

typedef tagPAGERANGE  TPageRange;

typedef tagPAGESET *PPageSet;

typedef tagPAGESET  TPageSet;

typedef _tagOLECMD *POleCmd;

typedef _tagOLECMD  TOleCmd;

typedef _tagOLECMDTEXT *POleCmdText;

typedef _tagOLECMDTEXT  TOleCmdText;

typedef tagQACONTAINER *PQaContainer;

typedef tagQACONTAINER  TQaContainer;

typedef tagQACONTROL *PQaControl;

typedef tagQACONTROL  TQaControl;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID CLSID_StdComponentCategoryMgr;

}	/* namespace Activex */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Activex;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// ActiveX
