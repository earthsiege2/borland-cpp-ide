// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'BDE.pas' rev: 6.00

#ifndef BDEHPP
#define BDEHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Bde
{
//-- type declarations -------------------------------------------------------
typedef int DBIDATE;

typedef int TIME;

typedef double TIMESTAMP;

typedef Word DBIResult;

typedef int TypedEnum;

typedef void *PLocale;

#pragma pack(push, 1)
struct _hDBIObj
{
	
} ;
#pragma pack(pop)

typedef _hDBIObj *hDBIObj;

typedef _hDBIObj *hDBIDb;

typedef _hDBIObj *hDBIQry;

typedef _hDBIObj *hDBIStmt;

typedef _hDBIObj *hDBICur;

typedef _hDBIObj *hDBISes;

typedef _hDBIObj *hDBIXlt;

typedef _hDBIObj *hDBICfg;

typedef _hDBIObj *hDBIXact;

typedef _hDBIObj *hDBIFilter;

typedef _hDBIObj *hDBIDR;

typedef hDBIObj *phDBIObj;

typedef hDBIDb *phDBIDb;

typedef hDBIQry *phDBIQry;

typedef hDBIStmt *phDBIStmt;

typedef hDBICur *phDBICur;

typedef hDBISes *phDBISes;

typedef hDBIXlt *phDBIXlt;

typedef hDBICfg *phDBICfg;

typedef hDBIXact *phDBIXact;

typedef hDBIFilter *phDBIFilter;

typedef hDBIDR *phDBIDR;

typedef char DBIPATH[261];

typedef char DBINAME[32];

typedef char DBIEXT[4];

typedef char DBIDOTEXT[5];

typedef char DBIDRIVE[128];

typedef char DBITBLNAME[261];

typedef char DBISPNAME[65];

typedef char DBIUSERNAME[15];

typedef Word DBIKEY[16];

typedef char DBIKEYEXP[221];

typedef Byte DBIVCHK[256];

typedef char DBIPICT[176];

typedef char DBIMSG[128];

typedef char DBIDRTYPEDESC[128];

typedef char DBISQLSTR[8193];

struct DBIEnv;
typedef DBIEnv *pDBIEnv;

#pragma pack(push, 1)
struct DBIEnv
{
	char szWorkDir[261];
	char szIniFile[261];
	Word bForceLocalInit;
	char szLang[32];
	char szClientName[32];
} ;
#pragma pack(pop)

struct SYSVersion;
typedef SYSVersion *pSYSVersion;

#pragma pack(push, 1)
struct SYSVersion
{
	Word iVersion;
	Word iIntfLevel;
	int dateVer;
	int timeVer;
	char szVersion[20];
} ;
#pragma pack(pop)

struct SYSConfig;
typedef SYSConfig *pSYSConfig;

#pragma pack(push, 1)
struct SYSConfig
{
	Word bLocalShare;
	Word iNetProtocol;
	Word bNetShare;
	char szNetType[32];
	char szUserName[15];
	char szIniFile[261];
	char szLangDriver[32];
} ;
#pragma pack(pop)

struct SYSInfo;
typedef SYSInfo *pSYSInfo;

#pragma pack(push, 1)
struct SYSInfo
{
	Word iBufferSpace;
	Word iHeapSpace;
	Word iDrivers;
	Word iClients;
	Word iSessions;
	Word iDatabases;
	Word iCursors;
} ;
#pragma pack(pop)

struct CLIENTInfo;
typedef CLIENTInfo *pCLIENTInfo;

#pragma pack(push, 1)
struct CLIENTInfo
{
	char szName[32];
	Word iSessions;
	char szWorkDir[261];
	char szLang[32];
} ;
#pragma pack(pop)

struct SESInfo;
typedef SESInfo *pSESInfo;

#pragma pack(push, 1)
struct SESInfo
{
	Word iSession;
	char szName[32];
	Word iDatabases;
	Word iCursors;
	short iLockWait;
	char szNetDir[261];
	char szPrivDir[261];
} ;
#pragma pack(pop)

#pragma option push -b
enum FLDVchk { fldvNOCHECKS, fldvHASCHECKS, fldvUNKNOWN };
#pragma option pop

#pragma option push -b
enum FLDRights { fldrREADWRITE, fldrREADONLY, fldrNONE, fldrUNKNOWN };
#pragma option pop

struct FLDDesc;
typedef FLDDesc *pFLDDesc;

#pragma pack(push, 1)
struct FLDDesc
{
	Word iFldNum;
	char szName[32];
	Word iFldType;
	Word iSubType;
	short iUnits1;
	short iUnits2;
	Word iOffset;
	Word iLen;
	Word iNullOffset;
	FLDVchk efldvVchk;
	FLDRights efldrRights;
	Word bCalcField;
	Word iUnUsed[2];
} ;
#pragma pack(pop)

struct BLOBParamDesc;
typedef BLOBParamDesc *pBLOBParamDesc;

#pragma pack(push, 1)
struct BLOBParamDesc
{
	void *pBlobBuffer;
	int ulBlobLen;
	Word iUnUsed[4];
} ;
#pragma pack(pop)

struct IDXDesc;
typedef IDXDesc *pIDXDesc;

#pragma pack(push, 1)
struct IDXDesc
{
	char szName[261];
	Word iIndexId;
	char szTagName[32];
	char szFormat[32];
	Word bPrimary;
	Word bUnique;
	Word bDescending;
	Word bMaintained;
	Word bSubset;
	Word bExpIdx;
	Word iCost;
	Word iFldsInKey;
	Word iKeyLen;
	Word bOutofDate;
	Word iKeyExpType;
	Word aiKeyFld[16];
	char szKeyExp[221];
	char szKeyCond[221];
	Word bCaseInsensitive;
	Word iBlockSize;
	Word iRestrNum;
	Word abDescending[16];
	Word iUnUsed[16];
} ;
#pragma pack(pop)

#pragma option push -b
enum LKUPType { lkupNONE, lkupPRIVATE, lkupALLCORRESP, lkupHELP, lkupALLCORRESPHELP };
#pragma option pop

struct VCHKDesc;
typedef VCHKDesc *pVCHKDesc;

#pragma pack(push, 1)
struct VCHKDesc
{
	Word iFldNum;
	Word bRequired;
	Word bHasMinVal;
	Word bHasMaxVal;
	Word bHasDefVal;
	Byte aMinVal[256];
	Byte aMaxVal[256];
	Byte aDefVal[256];
	char szPict[176];
	LKUPType elkupType;
	char szLkupTblName[261];
} ;
#pragma pack(pop)

#pragma option push -b
enum RINTType { rintMASTER, rintDEPENDENT };
#pragma option pop

#pragma option push -b
enum RINTQual { rintRESTRICT, rintCASCADE };
#pragma option pop

struct RINTDesc;
typedef RINTDesc *pRINTDesc;

#pragma pack(push, 1)
struct RINTDesc
{
	Word iRintNum;
	char szRintName[32];
	RINTType eType;
	char szTblName[261];
	RINTQual eModOp;
	RINTQual eDelOp;
	Word iFldCount;
	Word aiThisTabFld[16];
	Word aiOthTabFld[16];
} ;
#pragma pack(pop)

typedef int PRVType;

struct SECDesc;
typedef SECDesc *pSECDesc;

#pragma pack(push, 1)
struct SECDesc
{
	Word iSecNum;
	int eprvTable;
	Word iFamRights;
	char szPassword[32];
	int aprvFld[256];
} ;
#pragma pack(pop)

#pragma option push -b
enum DBIOBJType { objFILLER, objSYSTEM, objSESSION, objDRIVER, objDATABASE, objCURSOR, objSTATEMENT, objCLIENT, objDBSEC, objREPOSITORY };
#pragma option pop

struct ObjAttrDesc;
typedef ObjAttrDesc *pObjAttrDesc;

#pragma pack(push, 1)
struct ObjAttrDesc
{
	Word iFldNum;
	char *pszAttributeName;
} ;
#pragma pack(pop)

struct ObjTypeDesc;
typedef ObjTypeDesc *pObjTypeDesc;

#pragma pack(push, 1)
struct ObjTypeDesc
{
	Word iFldNum;
	char szTypeName[32];
} ;
#pragma pack(pop)

struct ObjParentDesc;
typedef ObjParentDesc *pObjParentDesc;

#pragma pack(push, 1)
struct ObjParentDesc
{
	Word iFldNum;
	Word iParentFldNum;
} ;
#pragma pack(pop)

#pragma option push -b
enum DBIShareMode { dbiOPENSHARED, dbiOPENEXCL };
#pragma option pop

#pragma option push -b
enum DBIOpenMode { dbiREADWRITE, dbiREADONLY };
#pragma option pop

#pragma option push -b
enum DBILockType { dbiNOLOCK, dbiWRITELOCK, dbiREADLOCK };
#pragma option pop

#pragma option push -b
enum XLTMode { xltNONE, xltRECORD, xltFIELD };
#pragma option pop

#pragma option push -b
enum UPDLockMode { updWHEREALL, updWHEREKEYCHG, updWHEREKEY };
#pragma option pop

#pragma option push -b
enum TEXACTRECCNTExpensive { exactRecCntINEXPENSIVE, exactRecCntEXPENSIVE, exactRecCntUNKNOWN };
#pragma option pop

struct ServerColDesc;
typedef ServerColDesc *pServerColDesc;

#pragma pack(push, 1)
struct ServerColDesc
{
	Word iFldNum;
	Word bServerCol;
} ;
#pragma pack(pop)

struct CURProps;
typedef CURProps *pCURProps;

#pragma pack(push, 1)
struct CURProps
{
	char szName[261];
	Word iFNameSize;
	char szTableType[32];
	Word iFields;
	Word iRecSize;
	Word iRecBufSize;
	Word iKeySize;
	Word iIndexes;
	Word iValChecks;
	Word iRefIntChecks;
	Word iBookMarkSize;
	Word bBookMarkStable;
	DBIOpenMode eOpenMode;
	DBIShareMode eShareMode;
	Word bIndexed;
	short iSeqNums;
	Word bSoftDeletes;
	Word bDeletedOn;
	Word iRefRange;
	XLTMode exltMode;
	Word iRestrVersion;
	Word bUniDirectional;
	Word eprvRights;
	Word Dummy4;
	Word iFmlRights;
	Word iPasswords;
	Word iCodePage;
	Word bProtected;
	Word iTblLevel;
	char szLangDriver[32];
	Word bFieldMap;
	Word iBlockSize;
	Word bStrictRefInt;
	Word iFilters;
	Word bTempTable;
	Word iUnUsed[16];
} ;
#pragma pack(pop)

#pragma option push -b
enum DBIDelayedUpdCmd { dbiDelayedUpdCommit, dbiDelayedUpdCancel, dbiDelayedUpdCancelCurrent, dbiDelayedUpdPrepare };
#pragma option pop

struct RECProps;
typedef RECProps *pRECProps;

#pragma pack(push, 1)
struct RECProps
{
	int iSeqNum;
	int iPhyRecNum;
	Word iRecStatus;
	Word bSeqNumChanged;
	Word bDeleteFlag;
} ;
#pragma pack(pop)

#pragma option push -b
enum eXILType { xilDIRTYREAD, xilREADCOMMITTED, xilREPEATABLEREAD };
#pragma option pop

#pragma option push -b
enum eXEnd { xendCOMMIT, xendCOMMITKEEP, xendABORT };
#pragma option pop

#pragma option push -b
enum eXState { xsINACTIVE, xsACTIVE };
#pragma option pop

struct XInfo;
typedef XInfo *pXInfo;

#pragma pack(push, 1)
struct XInfo
{
	eXState exState;
	eXILType eXIL;
	Word uNests;
} ;
#pragma pack(pop)

typedef int *PCMPBkMkRslt;

typedef int CMPBkMkRslt;

#pragma option push -b
enum DBISearchCond { keySEARCHEQ, keySEARCHGT, keySEARCHGEQ };
#pragma option pop

#pragma option push -b
enum CROpType { crNOOP, crADD, crCOPY, crMODIFY, crDROP, crREDO, crTABLE, crGROUP, crFAMILY, crDONE, crDROPADD };
#pragma option pop

typedef CROpType *pCROpType;

struct CRTblDesc;
typedef CRTblDesc *pCRTblDesc;

#pragma pack(push, 1)
struct CRTblDesc
{
	char szTblName[261];
	char szTblType[32];
	char szErrTblName[261];
	char szUserName[32];
	char szPassword[32];
	Word bProtected;
	Word bPack;
	Word iFldCount;
	CROpType *pecrFldOp;
	FLDDesc *pfldDesc;
	Word iIdxCount;
	CROpType *pecrIdxOp;
	IDXDesc *pidxDesc;
	Word iSecRecCount;
	CROpType *pecrSecOp;
	SECDesc *psecDesc;
	Word iValChkCount;
	CROpType *pecrValChkOp;
	VCHKDesc *pvchkDesc;
	Word iRintCount;
	CROpType *pecrRintOp;
	RINTDesc *printDesc;
	Word iOptParams;
	FLDDesc *pfldOptParams;
	void *pOptData;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct BATTblDesc
{
	_hDBIObj *hDb;
	char szTblName[261];
	char szTblType[32];
	char szUserName[32];
	char szPassword[32];
} ;
#pragma pack(pop)

typedef BATTblDesc *pBATTblDesc;

#pragma option push -b
enum eBATMode { batchAPPEND, batchUPDATE, batchAPPENDUPDATE, batchSUBTRACT, batchCOPY };
#pragma option pop

#pragma option push -b
enum SORTOrder { sortASCEND, sortDESCEND };
#pragma option pop

typedef SORTOrder *pSORTOrder;

typedef short __fastcall (*pfSORTCompFn)(void * &LdObj, void * &Value1, void * &Value2, short iLen);

typedef pfSORTCompFn *ppfSORTCompFn;

#pragma option push -b
enum DRVCat { drvFILLER, drvFILE, drvOTHERSERVER, drvSQLBASEDSERVER, drvOLEDBPROVIDER };
#pragma option pop

#pragma option push -b
enum OPType { opFILLER0, opFILLER1, opFILLER2, opDBCREATE, opDBOPEN, opTBLCREATE, opTBLOPEN };
#pragma option pop

struct DRVType;
typedef DRVType *pDRVType;

#pragma pack(push, 1)
struct DRVType
{
	char szType[32];
	char szText[32];
	DRVCat edrvCat;
	Word bTrueDb;
	char szDbType[32];
	Word bMultiUser;
	Word bReadWrite;
	Word bTrans;
	Word bPassThruSQL;
	Word bLogIn;
	Word bCreateDb;
	Word bDeleteDb;
	Word bCreateTable;
	Word bDeleteTable;
	Word bMultiplePWs;
	Word iDriverVersion;
	Word bSQLRowid;
	Word iUnUsed[15];
} ;
#pragma pack(pop)

struct TBLType;
typedef TBLType *pTBLType;

#pragma pack(push, 1)
struct TBLType
{
	Word iId;
	char szName[32];
	char szText[32];
	char szFormat[32];
	Word bReadWrite;
	Word bCreate;
	Word bRestructure;
	Word bValChecks;
	Word bSecurity;
	Word bRefIntegrity;
	Word bPrimaryKey;
	Word bIndexing;
	Word iFldTypes;
	Word iMaxRecSize;
	Word iMaxFldsInTable;
	Word iMaxFldNameLen;
	Word iTblLevel;
	Word iUnUsed[16];
} ;
#pragma pack(pop)

struct IDXType;
typedef IDXType *pIDXType;

#pragma pack(push, 1)
struct IDXType
{
	Word iId;
	char szName[32];
	char szText[32];
	char szFormat[32];
	Word bComposite;
	Word bPrimary;
	Word bUnique;
	Word bKeyDescending;
	Word bFldDescending;
	Word bMaintained;
	Word bSubset;
	Word bKeyExpr;
	Word bCaseInsensitive;
	Word iUnUsed[16];
} ;
#pragma pack(pop)

struct FLDType;
typedef FLDType *pFLDType;

#pragma pack(push, 1)
struct FLDType
{
	Word iId;
	char szName[32];
	char szText[32];
	Word iPhyType;
	Word iXltType;
	Word iXltSubType;
	Word iMaxUnits1;
	Word iMaxUnits2;
	Word iPhySize;
	Word bRequired;
	Word bDefaultVal;
	Word bMinVal;
	Word bMaxVal;
	Word bRefIntegrity;
	Word bOtherChecks;
	Word bKeyed;
	Word bMultiplePerTable;
	Word iMinUnits1;
	Word iMinUnits2;
	Word bCreateable;
	char szNativeName[32];
	Word iUnUsed[16];
} ;
#pragma pack(pop)

#pragma option push -b
enum PROPValid { epropINVALID, epropCANGET, epropCANSET };
#pragma option pop

#pragma option push -b
enum CBType { cbGENERAL, cbRESERVED1, cbRESERVED2, cbINPUTREQ, cbRESERVED4, cbRESERVED5, cbBATCHRESULT, cbRESERVED7, cbRESTRUCTURE, cbRESERVED9, cbRESERVED10, cbRESERVED11, cbRESERVED12, cbRESERVED13, cbRESERVED14, cbRESERVED15, cbRESERVED16, cbRESERVED17, cbTABLECHANGED, cbRESERVED19, cbCANCELQRY, cbSERVERCALL, cbRESERVED22, cbGENPROGRESS, cbDBASELOGIN, cbDELAYEDUPD, cbFIELDRECALC, cbTRACE, cbDBLOGIN, cbDETACHNOTIFY, cbNBROFCBS };
#pragma option pop

typedef CBType *pCBType;

#pragma option push -b
enum CBRType { cbrUSEDEF, cbrCONTINUE, cbrABORT, cbrCHKINPUT, cbrYES, cbrNO, cbrPARTIALASSIST, cbrSKIP, cbrRETRY };
#pragma option pop

typedef CBRType *pCBRType;

typedef CBRType __stdcall (*pfDBICallBack)(CBType ecbType, int iClientData, void * CbInfo);

typedef pfDBICallBack *ppfDBICallBack;

struct CBPROGRESSDesc;
typedef CBPROGRESSDesc *pCBPROGRESSDesc;

#pragma pack(push, 1)
struct CBPROGRESSDesc
{
	short iPercentDone;
	char szMsg[128];
} ;
#pragma pack(pop)

#pragma option push -b
enum DelayUpdErrOpType { delayupdNONE, delayupdMODIFY, delayupdINSERT, delayupdDELETE };
#pragma option pop

struct DELAYUPDCbDesc;
typedef DELAYUPDCbDesc *PDELAYUPDCbDesc;

#pragma pack(push, 1)
struct DELAYUPDCbDesc
{
	Word iErrCode;
	DelayUpdErrOpType eDelayUpdOpType;
	Word iRecBufSize;
	void *pNewRecBuf;
	void *pOldRecBuf;
} ;
#pragma pack(pop)

#pragma option push -b
enum RESTErrObjType { restrNONE, restrNEWFLD, restrOLDFLD, restrNEWINDEX, restrOLDINDEX, restrNEWVCHK, restrOLDVCHK, restrNEWRINT, restrOLDRINT, restrNEWSEC, restrOLDSEC, restrNEWTABLE };
#pragma option pop

struct TCBDBLogin;
typedef TCBDBLogin *pCBDBLogin;

#pragma pack(push, 1)
struct TCBDBLogin
{
	char szDbName[32];
	DBIOpenMode eOpenMode;
	DBIShareMode eShareMode;
	char szPassword[32];
	BOOL bCallbackToClose;
	_hDBIObj *hDb;
} ;
#pragma pack(pop)

typedef int *pTRACECat;

typedef int TRACECat;

struct TRACEDesc;
typedef TRACEDesc *pTRACEDesc;

#pragma pack(push, 1)
struct TRACEDesc
{
	int eTraceCat;
	Word uTotalMsgLen;
	char pszTrace[1];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TuObjDesc
{
	
	union
	{
		struct 
		{
			SECDesc secDesc;
			
		};
		struct 
		{
			RINTDesc rintDesc;
			
		};
		struct 
		{
			VCHKDesc vchkDesc;
			
		};
		struct 
		{
			IDXDesc idxDesc;
			
		};
		struct 
		{
			FLDDesc fldDesc;
			
		};
		
	};
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct RESTCbDesc
{
	Word iErrCode;
	Word iTblNum;
	Word iObjNum;
	RESTErrObjType eRestrObjType;
	TuObjDesc uObjDesc;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct CBEntry
{
	char szKeyWord[32];
	char szHelp[128];
} ;
#pragma pack(pop)

#pragma option push -b
enum CBInputId { cbiFILLER, cbiMDXMISSING, cbiPDXLOOKUP, cbiPDXBLOB, cbiDBTMISSING, cbiDRINPUT, cbiRINTMISSING };
#pragma option pop

struct CBInputDesc;
typedef CBInputDesc *PCBInputDesc;

#pragma pack(push, 1)
struct CBInputDesc
{
	CBInputId eCbInputId;
	short iCount;
	short iSelection;
	Word bSave;
	char szMsg[128];
	CBEntry acbEntry[4];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct CBLoginDesc
{
	char szUserName[32];
	char szGroupName[32];
	char szUserPassword[32];
} ;
#pragma pack(pop)

typedef CBLoginDesc *pCBLoginDesc;

#pragma option push -b
enum CBSCType { cbscRETURN, cbscSQL };
#pragma option pop

typedef CBSCType *PCBSCType;

#pragma option push -b
enum CBYieldStep { cbYieldFirst, cbYieldContinue, cbYieldLast };
#pragma option pop

typedef CBYieldStep *PCBYieldStep;

#pragma option push -b
enum DBIQryLang { qrylangUNKNOWN, qrylangQBE, qrylangSQL };
#pragma option pop

typedef int eINDValues;

#pragma option push -b
enum STMTParamType { paramUNKNOWN, paramIN, paramOUT, paramINOUT, paramRET };
#pragma option pop

#pragma option push -b
enum STMTParamFormat { paramfmtUNKNOWN, paramfmtNUMBER, paramfmtNAME };
#pragma option pop

struct FMTNumber;
typedef FMTNumber *pFMTNumber;

#pragma pack(push, 1)
struct FMTNumber
{
	char cDecimalSeparator;
	char cThousandSeparator;
	Byte iDecimalDigits;
	bool bLeadingZero;
} ;
#pragma pack(pop)

struct FMTDate;
typedef FMTDate *pFMTDate;

#pragma pack(push, 1)
struct FMTDate
{
	char szDateSeparator[4];
	Byte iDateMode;
	bool bFourDigitYear;
	bool bYearBiased;
	bool bMonthLeadingZero;
	bool bDayLeadingZero;
} ;
#pragma pack(pop)

struct FMTTime;
typedef FMTTime *pFMTTime;

#pragma pack(push, 1)
struct FMTTime
{
	char cTimeSeparator;
	bool bTwelveHour;
	char szAmString[6];
	char szPmString[6];
	bool bSeconds;
	bool bMilSeconds;
} ;
#pragma pack(pop)

struct FMTBcd;
typedef FMTBcd *pFMTBcd;

#pragma pack(push, 1)
struct FMTBcd
{
	Byte iPrecision;
	Byte iSignSpecialPlaces;
	Byte iFraction[32];
} ;
#pragma pack(pop)

struct DBIErrInfo;
typedef DBIErrInfo *pDBIErrInfo;

#pragma pack(push, 1)
struct DBIErrInfo
{
	Word iError;
	char szErrCode[128];
	char szContext[4][128];
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct DBDesc
{
	char szName[32];
	char szText[32];
	char szPhyName[261];
	char szDbType[32];
} ;
#pragma pack(pop)

typedef DBDesc *pDBDesc;

struct USERDesc;
typedef USERDesc *pUSERDesc;

#pragma pack(push, 1)
struct USERDesc
{
	char szUserName[15];
	Word iNetSession;
	Word iProductClass;
	char szSerialNum[22];
} ;
#pragma pack(pop)

struct TBLBaseDesc;
typedef TBLBaseDesc *pTBLBaseDesc;

#pragma pack(push, 1)
struct TBLBaseDesc
{
	char szName[261];
	char szFileName[261];
	char szExt[4];
	char szType[32];
	int dtDate;
	int tmTime;
	int iSize;
	Word bView;
	Word bSynonym;
} ;
#pragma pack(pop)

struct TBLExtDesc;
typedef TBLExtDesc *pTBLExtDesc;

#pragma pack(push, 1)
struct TBLExtDesc
{
	char szStruct[32];
	Word iRestrVersion;
	Word iRecSize;
	Word iFields;
	Word iIndexes;
	Word iValChecks;
	Word iRintChecks;
	int iRecords;
	Word bProtected;
	Word bValidInfo;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TBLFullDesc
{
	TBLBaseDesc tblBase;
	TBLExtDesc tblExt;
} ;
#pragma pack(pop)

typedef TBLFullDesc *pTBLFullDesc;

struct FILEDesc;
typedef FILEDesc *pFILEDesc;

#pragma pack(push, 1)
struct FILEDesc
{
	char szFileName[261];
	char szExt[4];
	Word bDir;
	int iSize;
	int dtDate;
	int tmTime;
} ;
#pragma pack(pop)

struct SPDesc;
typedef SPDesc *pSPDesc;

#pragma pack(push, 1)
struct SPDesc
{
	char szName[65];
	int dtDate;
	int tmTime;
} ;
#pragma pack(pop)

struct SPParamDesc;
typedef SPParamDesc *pSPParamDesc;

#pragma pack(push, 1)
struct SPParamDesc
{
	Word uParamNum;
	char szName[32];
	STMTParamType eParamType;
	Word uFldType;
	Word uSubType;
	short iUnits1;
	short iUnits2;
	Word uOffset;
	Word uLen;
	Word uNullOffset;
} ;
#pragma pack(pop)

#pragma option push -b
enum DBISTDFuncs { fnAVG, fnCOUNT, fnMIN, fnMAX, fnSUM, fnSTDDEV, fnVARIANCE, fnABS, fnCEIL, fnCOS, fnCOSH, fnEXP, fnFLOOR, fnLN, fnLOG, fnMOD, fnPOWER, fnROUND, fnSIGN, fnSIN, fnSINH, fnSQRT, fnTAN, fnTANH, fnTRUNC, fnCHR, fnCONCAT, fnINITCAP, fnLOWER, fnLPAD, fnLTRIM, fnNLS_INITCAP, fnNLS_LOWER, fnNLS_UPPER, fnREPLACE, fnRPAD, fnRTRIM, fnSOUNDEX, fnSUBSTR, fnSUBSTRB, fnTRANSLATE, fnUPPER, fnASCII, fnINSTR, fnINSTRB, fnLENGTH, fnLENGTHB, fnNLSSORT, fnADD_MONTHS, fnLAST_DAY, fnMONTHS_BETWEEN, fnNEW_TIME, fnNEXT_DAY, fnSYSDATE, fnCONVERT, fnTO_CHAR, fnTO_DATE, fnTO_MULTI_BYTE, fnTO_NUMBER, fnTO_SINGLE_BYTE, fnUID, fnUSER, fnORACLEMISC, fnACOS, fnASIN, fnATAN, fnATN2, fnCOT, fnDEGREES, fnLOG10, fnPI, fnRADIANS, fnRAND, fnTEXTPTR, fnTEXTVALID, fnCHARINDEX, fnDIFFERENCE, fnPATINDEX, fnREPLICATE, fnREVERSE, fnRIGHT, fnSPACE, fnSTR, fnSTUFF, fnCOL_NAME, fnCOL_LENGTH, fnDATALENGTH, fnDB_ID, fnDB_NAME, fnHOST_ID, fnHOST_NAME, fnINDEX_COL, fnOBJECT_ID, fnOBJECT_NAME, fnUSER_ID, fnUSER_NAME, fnLEFT, fnLOCATE
	, fnTRUNCATE, fnCURTIME, fnDAYNAME, fnDAYOFMONTH, fnDAYOFWEEK, fnDAYOFYEAR, fnHOUR, fnMINUTE, fnMONTH, fnMONTHNAME, fnNOW, fnQUARTER, fnSECOND, fnWEEK, fnYEAR, fnDAY, fnWEEKDAY, fnTODAY, fnDATE, fnINFMISC };
#pragma option pop

typedef int DBIFuncFlags;

#pragma option push -b
enum DBIFUNCOpts { fnDummy, fnListINCL_USER_DEF };
#pragma option pop

struct DBIFUNCDesc;
typedef DBIFUNCDesc *pDBIFUNCDesc;

#pragma pack(push, 1)
struct DBIFUNCDesc
{
	char szName[32];
	char szDesc[255];
	Word uOverload;
	DBISTDFuncs eStdFn;
} ;
#pragma pack(pop)

struct DBIFUNCArgDesc;
typedef DBIFUNCArgDesc *pDBIFUNCArgDesc;

#pragma pack(push, 1)
struct DBIFUNCArgDesc
{
	Word uArgNum;
	Word uFldType;
	Word uSubType;
	Word ufuncFlags;
} ;
#pragma pack(pop)

#pragma option push -b
enum CFGMode { cfgPersistent, cfgSession, cfgAll };
#pragma option pop

typedef int CFGMode2;

#pragma option push -b
enum CFGUpdate { cfgUpdateOn, cfgUpdateOff };
#pragma option pop

struct CFGDesc;
typedef CFGDesc *pCFGDesc;

#pragma pack(push, 1)
struct CFGDesc
{
	char szNodeName[32];
	char szDescription[128];
	Word iDataType;
	char szValue[128];
	Word bHasSubnodes;
} ;
#pragma pack(pop)

#pragma option push -b
enum FMLType { fmlUNKNOWN, fmlTABLE, fmlINDEX, fmlFORM, fmlREPORT, fmlVALCHECK, fmlSECINDEX, fmlSECINDEX2, fmlBLOBFILE };
#pragma option pop

typedef FMLType *pFMLType;

struct FMLDesc;
typedef FMLDesc *pFMLDesc;

#pragma pack(push, 1)
struct FMLDesc
{
	char szName[32];
	Word iId;
	FMLType eType;
	char szFileName[261];
} ;
#pragma pack(pop)

struct LDDesc;
typedef LDDesc *pLDDesc;

#pragma pack(push, 1)
struct LDDesc
{
	char szName[32];
	char szDesc[32];
	Word iCodePage;
	Word PrimaryCpPlatform;
	Word AlternateCpPlatform;
} ;
#pragma pack(pop)

struct LOCKDesc;
typedef LOCKDesc *pLOCKDesc;

#pragma pack(push, 1)
struct LOCKDesc
{
	Word iType;
	char szUserName[15];
	Word iNetSession;
	Word iSession;
	int iRecNum;
	Word iInfo;
} ;
#pragma pack(pop)

#pragma option push -b
enum CANOp { canNOTDEFINED, canISBLANK, canNOTBLANK, canEQ, canNE, canGT, canLT, canGE, canLE, canNOT, canAND, canOR, canTUPLE2, canFIELD2, canCONST2, canMINUS, canADD, canSUB, canMUL, canDIV, canMOD, canREM, canSUM, canCOUNT, canMIN, canMAX, canAVG, canCONT, canUDF2, canCONTINUE2, canLIKE, canIN, canLIST2, canUPPER, canLOWER, canFUNC2, canLISTELEM2, canASSIGN };
#pragma option pop

typedef CANOp *pCANOp;

#pragma option push -b
enum NODEClass { nodeNULL, nodeUNARY, nodeBINARY, nodeCOMPARE, nodeFIELD, nodeCONST, nodeTUPLE, nodeCONTINUE, nodeUDF, nodeLIST, nodeFUNC, nodeLISTELEM };
#pragma option pop

#pragma pack(push, 1)
struct CANHdr
{
	NODEClass nodeClass;
	CANOp canOp;
} ;
#pragma pack(pop)

typedef CANHdr *pCANHdr;

struct CANUnary;
typedef CANUnary *pCANUnary;

#pragma pack(push, 1)
struct CANUnary
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iOperand1;
} ;
#pragma pack(pop)

struct CANBinary;
typedef CANBinary *pCANBinary;

#pragma pack(push, 1)
struct CANBinary
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iOperand1;
	Word iOperand2;
} ;
#pragma pack(pop)

struct CANField;
typedef CANField *pCANField;

#pragma pack(push, 1)
struct CANField
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iFieldNum;
	Word iNameOffset;
} ;
#pragma pack(pop)

struct CANConst;
typedef CANConst *pCANConst;

#pragma pack(push, 1)
struct CANConst
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iType;
	Word iSize;
	Word iOffset;
} ;
#pragma pack(pop)

struct CANTuple;
typedef CANTuple *pCANTuple;

#pragma pack(push, 1)
struct CANTuple
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iSize;
} ;
#pragma pack(pop)

struct CANContinue;
typedef CANContinue *pCANContinue;

#pragma pack(push, 1)
struct CANContinue
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iContOperand;
} ;
#pragma pack(pop)

struct CANCompare;
typedef CANCompare *pCANCompare;

#pragma pack(push, 1)
struct CANCompare
{
	NODEClass nodeClass;
	CANOp canOp;
	Word bCaseInsensitive;
	Word iPartialLen;
	Word iOperand1;
	Word iOperand2;
} ;
#pragma pack(pop)

struct CANFunc;
typedef CANFunc *pCANFunc;

#pragma pack(push, 1)
struct CANFunc
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iNameOffset;
	Word iElemOffset;
} ;
#pragma pack(pop)

struct CANListElem;
typedef CANListElem *pCANListElem;

#pragma pack(push, 1)
struct CANListElem
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iOffset;
	Word iNextOffset;
} ;
#pragma pack(pop)

struct CANUdf;
typedef CANUdf *pCANUdf;

#pragma pack(push, 1)
struct CANUdf
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iOffSzFuncName;
	Word iOperands;
	Word iDrvDialect;
	Word iOffSzUDF;
} ;
#pragma pack(pop)

struct CANList;
typedef CANList *pCANList;

#pragma pack(push, 1)
struct CANList
{
	NODEClass nodeClass;
	CANOp canOp;
	Word iType;
	Word iTotalSize;
	Word iElemSize;
	Word iElems;
	Word iOffset;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct CANNode
{
	
	union
	{
		struct 
		{
			CANListElem canListElem;
			
		};
		struct 
		{
			CANFunc canFunc;
			
		};
		struct 
		{
			CANList canList;
			
		};
		struct 
		{
			CANCompare canCompare;
			
		};
		struct 
		{
			CANContinue canContinue;
			
		};
		struct 
		{
			CANTuple canTuple;
			
		};
		struct 
		{
			CANConst canConst;
			
		};
		struct 
		{
			CANField canField;
			
		};
		struct 
		{
			CANBinary canBinary;
			
		};
		struct 
		{
			CANUnary canUnary;
			
		};
		struct 
		{
			CANHdr canHdr;
			
		};
		
	};
} ;
#pragma pack(pop)

typedef CANNode *pCANNode;

struct CANExpr;
typedef CANExpr *pCANExpr;

typedef pCANExpr *ppCANExpr;

#pragma pack(push, 1)
struct CANExpr
{
	Word iVer;
	Word iTotalSize;
	Word iNodes;
	Word iNodeStart;
	Word iLiteralStart;
} ;
#pragma pack(pop)

typedef short __stdcall (*pfGENFilter)(int ulClientData, void * pRecBuf, int iPhyRecNum);

struct FILTERInfo;
typedef FILTERInfo *pFILTERInfo;

#pragma pack(push, 1)
struct FILTERInfo
{
	Word iFilterId;
	_hDBIObj *hFilter;
	int iClientData;
	Word iPriority;
	Word bCanAbort;
	pfGENFilter pfFilter;
	void *pCanExpr;
	Word bActive;
} ;
#pragma pack(pop)

struct DBIQryProp;
typedef DBIQryProp *pDBIQryProp;

#pragma pack(push, 1)
struct DBIQryProp
{
	char szQryName[32];
	DBIQryLang eLang;
	short iQryPrice;
	short iNumTables;
	Word bHasAnswer;
	Word bInsert;
	Word bDelete;
	Word bChange;
} ;
#pragma pack(pop)

#pragma option push -b
enum DBIQryType { dbiqryDEFAULT, dbiqryDIRTY, dbiqryCLEAN, dbiqryRESTART };
#pragma option pop

struct DBIQryProgress;
typedef DBIQryProgress *pDBIQryProgress;

#pragma pack(push, 1)
struct DBIQryProgress
{
	Word stepsInQry;
	Word stepsCompleted;
	int totElemInStep;
	int elemCompleted;
} ;
#pragma pack(pop)

#pragma option push -b
enum QryEvalMode { qryModeNONE, qryModeLOCAL, qryModeSERVER, qryModeEITHER, qryModeNOWLOCAL };
#pragma option pop

#pragma option push -b
enum LIVENESS { wantDEFAULT, wantLIVE, wantCANNED, wantSPEED };
#pragma option pop

struct QueryLowProps;
typedef QueryLowProps *pQueryLowProps;

#pragma pack(push, 1)
struct QueryLowProps
{
	short length;
	Word blankzeroes;
	FMTDate dateFormat;
	FMTNumber numberFormat;
	Word bNeedAuxTbls;
	QryEvalMode qryMode;
	Word perQrySqlMode;
	LIVENESS livenessDesired;
} ;
#pragma pack(pop)

typedef int SQLType;

typedef int REQType;

struct SQLObject;
typedef SQLObject *pSQLObject;

struct LIST;
typedef LIST *pLIST;

#pragma pack(push, 1)
struct LIST
{
	SQLObject *car;
	LIST *cdr;
} ;
#pragma pack(pop)

struct SQLRelation;
typedef SQLRelation *pSQLRelation;

#pragma pack(push, 1)
struct SQLRelation
{
	SQLType esType;
	int erType;
	char szRelName[261];
	BOOL bRelQuote;
	char szRelType[261];
	char szRelAlias[261];
	char szRelOwner[261];
	LIST *plCol;
	short iRowId;
	short iRowNo;
} ;
#pragma pack(pop)

#pragma option push -b
enum CHECKType { NOCHECK, chkCHECK, chkCHECKPLUS, chkCHECKDESC };
#pragma option pop

struct SQLColumn;
typedef SQLColumn *pSQLColumn;

#pragma pack(push, 1)
struct SQLColumn
{
	SQLType esType;
	char szColName[261];
	BOOL bColQuote;
	char szColAlias[261];
	BOOL bColAlQuote;
	char szColRelation[261];
	char szColOwner[261];
	CHECKType eCheck;
	Word *paiRowCheck;
	short iColAggr;
	int iColExmpl;
	LIST *plCell;
} ;
#pragma pack(pop)

struct SQLConstant;
typedef SQLConstant *pSQLConstant;

#pragma pack(push, 1)
struct SQLConstant
{
	SQLType esType;
	char szConstValue[261];
} ;
#pragma pack(pop)

#pragma option push -b
enum SQLOp { opUNKNOWNOP, opEQUAL, opNOTEQ, opLESSEQUAL, opGREQUAL, opLESS, opGREATER, opLIKE, opNOT, opPLUSX, opMINUSX, opTIMESX, opDIVX, opAND, opOR, opBLANK, opAS, opOUTERJOIN, opNOTLIKE, opCHANGETO, opUPPER, opLOWER, opTRIM, opSUBSTRING, opPAND, opPOR, opPNOT, opEXTRACT, opFULLOTRJOIN };
#pragma option pop

#pragma pack(push, 1)
struct SQLExpr
{
	SQLType esType;
	SQLOp eOp;
	LIST *plOperands;
} ;
#pragma pack(pop)

typedef SQLExpr *pSQLExpr;

struct SQLAggr;
typedef SQLAggr *pSQLAggr;

#pragma pack(push, 1)
struct SQLAggr
{
	SQLType esType;
	SQLColumn *pcolAggr;
	short iAggr;
	BOOL bProjAggr;
	SQLConstant *pAggrName;
} ;
#pragma pack(pop)

struct SQLCell;
typedef SQLCell *pSQLCell;

#pragma pack(push, 1)
struct SQLCell
{
	SQLType esType;
	char szCellValue[261];
	int iRow;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct SQLObject
{
	
	union
	{
		struct 
		{
			SQLCell pCell;
			
		};
		struct 
		{
			SQLAggr pAggr;
			
		};
		struct 
		{
			SQLExpr pExpr;
			
		};
		struct 
		{
			SQLConstant pConst;
			
		};
		struct 
		{
			SQLColumn pCol;
			
		};
		struct 
		{
			SQLRelation pRel;
			
		};
		struct 
		{
			SQLType esType;
			
		};
		
	};
} ;
#pragma pack(pop)

struct TSQLRequest;
typedef TSQLRequest *PSQLRequest;

#pragma pack(push, 1)
struct TSQLRequest
{
	Word iVersion;
	int iMemMark;
	_hDBIObj *hQry;
	int erType;
	_hDBIObj *hDb;
	_hDBIObj *hStmt;
	int iParams;
	int iOptions;
	int iDistinct;
	LIST *plRelation;
	LIST *plProject;
	LIST *plWhere;
	LIST *plOrder;
	LIST *plGroupBy;
	LIST *plHaving;
	LIST *plAlias;
} ;
#pragma pack(pop)

struct STMTBaseDesc;
typedef STMTBaseDesc *PSTMTBaseDesc;

#pragma pack(push, 1)
struct STMTBaseDesc
{
	char szDatabase[32];
	char szTableName[261];
	char szFieldName[32];
	BOOL bExpression;
	BOOL bAggregate;
	BOOL bConstant;
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct TOSBLObj
{
	short LangId;
	char LdName[20];
	char EnglishDesc[32];
	char LdDescriptor[20];
	void *LocaleHdl;
	short CodeSet;
	short LocaleType;
	short LanguageSortType;
	short LocaleCount;
	short PrimaryCpPlatform;
	Word PrimaryCodePageID;
	Word AlternateCodePageID;
	Word ProductID;
	BOOL NoConversions;
	int LdLCID;
} ;
#pragma pack(pop)

struct DRDesc;
typedef DRDesc *pDRDesc;

#pragma pack(push, 1)
struct DRDesc
{
	char szDRName[32];
	char szDRDescText[128];
	char szDRDbName[32];
	char szDRDbDir[261];
	char szDRTableName[32];
	char szLdName[32];
	int aulReserved[10];
} ;
#pragma pack(pop)

struct DROBJDesc;
typedef DROBJDesc *pDROBJDesc;

#pragma pack(push, 1)
struct DROBJDesc
{
	char szObjTypeName[32];
	char szObjRealName[32];
	int ulObjId;
	Word iVersion;
	int aulReserved[10];
} ;
#pragma pack(pop)

typedef DROBJDesc TDROBJDescList[1024];

typedef DROBJDesc *PDROBJDescList;

struct DRExportDesc;
typedef DRExportDesc *pDRExportDesc;

#pragma pack(push, 1)
struct DRExportDesc
{
	DROBJDesc objDesc;
	BOOL bInclRelated;
	int aulReserved[4];
} ;
#pragma pack(pop)

struct DROBJType;
typedef DROBJType *pDROBJType;

#pragma pack(push, 1)
struct DROBJType
{
	char szObjTypeName[32];
	Word iNumAttr;
	Word iNumRel;
	int ulObjFlag;
	char szObjTypeDesc[128];
	char szObjTypeDisplayName[32];
	int aulReserved[10];
} ;
#pragma pack(pop)

struct DBIEnumFld;
typedef DBIEnumFld *pDBIEnumFld;

#pragma pack(push, 1)
struct DBIEnumFld
{
	char szDisplayStr[32];
	Byte abVal[96];
	int aulReserved[10];
} ;
#pragma pack(pop)

struct DREnumAttrDomain;
typedef DREnumAttrDomain *pDREnumAttrDomain;

#pragma pack(push, 1)
struct DREnumAttrDomain
{
	char szEnumAttrDomainName[32];
	int ulEDProp;
	Word iNumVals;
	DBIEnumFld *padbiEnumFld;
	int aulReserved[10];
} ;
#pragma pack(pop)

struct DRATTRDesc;
typedef DRATTRDesc *pDRATTRDesc;

#pragma pack(push, 1)
struct DRATTRDesc
{
	char szAttrName[32];
	char szTypeName[32];
	char szAttrDomainName[32];
	Word iAttrType;
	Word iUnits1;
	Word iUnits2;
	Word bReqd;
	int ulAttrFlag;
	char szAttrDisplayName[32];
	char szAttrTypeDesc[128];
	Word iDisplayProp;
	Word iExtendedFlag;
	Word bReadOnly;
	Word iEditProp;
	int ulTag;
	int aulReserved[10];
} ;
#pragma pack(pop)

#pragma option push -b
enum eRELConstraint { eRelManyMany, eRelManyOne, eRelOneMany, eRelOneOne };
#pragma option pop

#pragma option push -b
enum eRELCategory { eRelGENERAL, eRelCONTAINS, eRelREFERS, eRelBASEDON };
#pragma option pop

struct DRRELType;
typedef DRRELType *pDRRELType;

#pragma pack(push, 1)
struct DRRELType
{
	char szRelTypeName[32];
	char szSrcObjTypeName[32];
	char szDestObjTypeName[32];
	char szRevRelTypeName[32];
	Word iNumAttr;
	eRELConstraint eRelConstraint;
	eRELCategory eRelCategory;
	char szRelTypeDisplayName[32];
	char szRevRelDisplayName[32];
	char szRelTypeDesc[128];
	int ulRelFlag;
	int aulReserved[10];
} ;
#pragma pack(pop)

struct DRObject;
typedef DRObject *pDRObject;

#pragma pack(push, 1)
struct DRObject
{
	int ulObjId;
	Word iVersion;
} ;
#pragma pack(pop)

struct DataSources;
typedef DataSources *pDataSources;

#pragma pack(push, 1)
struct DataSources
{
	Word iNumElem;
	char szDbName[32];
	char szTblName[261];
	char szSourceFldName[32];
	char szOrigFldName[32];
	char szSQLExprImport[8193];
	char szSQLExprCustom[8193];
	char szErrStrImport[128];
	char szErrStrCustom[128];
	BOOL bRequired;
} ;
#pragma pack(pop)

#pragma option push -b
enum DsInfoReq { dsNumSources, dsDefSources, dsSource, dsFieldSource, dsFieldDefault, dsFieldDomainExpr, dsTblConstraint, dsNumTblConstraint };
#pragma option pop

typedef Word __stdcall (*pfDataSourcesCallback)(int lUserVal, DsInfoReq Req, pDataSources pDsSources);

#pragma option push -b
enum EXPType { expDomain, expRecConstr, expDefault };
#pragma option pop

typedef char *NameList[4];

typedef char * *PNameList;

typedef System::TVarArray *PacketList[4];

typedef System::PVarArray *PPacketList;

typedef void *CBList[4];

typedef void * *PCBList;

typedef int IntList[4];

typedef int *PIntList;

//-- var, const, procedure ---------------------------------------------------
static const Word DBIINTFVER = 0x1f4;
static const Word DBIENGVERSION = 0x1f4;
static const Shortint DEBUGON = 0x1;
static const Shortint OUTPUTTOFILE = 0x2;
static const Shortint FLUSHEVERYOP = 0x8;
static const Shortint APPENDTOLOG = 0x10;
static const Shortint DBIMAXNAMELEN = 0x1f;
static const Shortint DBIMAXSPNAMELEN = 0x40;
static const Byte DBIMAXFUNCNAMELEN = 0xff;
static const Shortint DBIMAXFLDSINKEY = 0x10;
static const Byte DBIMAXKEYEXPLEN = 0xdc;
static const Shortint DBIMAXEXTLEN = 0x3;
static const Word DBIMAXTBLNAMELEN = 0x104;
static const Shortint DBIMAXDRIVELEN = 0x7f;
static const Word DBIMAXPATHLEN = 0x104;
static const Shortint DBIMAXMSGLEN = 0x7f;
static const Byte DBIMAXVCHKLEN = 0xff;
static const Byte DBIMAXPICTLEN = 0xaf;
static const Word DBIMAXFLDSINSEC = 0x100;
static const Shortint DBIMAXSCFIELDS = 0x28;
static const Byte DBIMAXSCFLDLEN = 0x80;
static const Word DBIMAXSCRECSIZE = 0x1400;
static const Shortint DBIMAXUSERNAMELEN = 0xe;
static const Shortint DBIMAXXBUSERNAMELEN = 0x10;
static const Word DBIMAXBOOKMARKLEN = 0x1008;
static const Word DBIMAXTRACELEN = 0x2000;
static const Shortint DBIMAXTYPEDESC = 0x7f;
static const Word DBIMAXDRSQLSTR = 0x2000;
static const Shortint DBIMAXOLEDBNAMELEN = 0x40;
#define szPARADOX "PARADOX"
#define szDBASE "DBASE"
#define szFOXPRO "FOXPRO"
#define szASCII "ASCIIDRV"
#define szOLEDB "OLEDBDRV"
#define szMSACCESS "MSACCESS"
static const Shortint fldUNKNOWN = 0x0;
static const Shortint fldZSTRING = 0x1;
static const Shortint fldDATE = 0x2;
static const Shortint fldBLOB = 0x3;
static const Shortint fldBOOL = 0x4;
static const Shortint fldINT16 = 0x5;
static const Shortint fldINT32 = 0x6;
static const Shortint fldFLOAT = 0x7;
static const Shortint fldBCD = 0x8;
static const Shortint fldBYTES = 0x9;
static const Shortint fldTIME = 0xa;
static const Shortint fldTIMESTAMP = 0xb;
static const Shortint fldUINT16 = 0xc;
static const Shortint fldUINT32 = 0xd;
static const Shortint fldFLOATIEEE = 0xe;
static const Shortint fldVARBYTES = 0xf;
static const Shortint fldLOCKINFO = 0x10;
static const Shortint fldCURSOR = 0x11;
static const Shortint fldINT64 = 0x12;
static const Shortint fldUINT64 = 0x13;
static const Shortint fldADT = 0x14;
static const Shortint fldARRAY = 0x15;
static const Shortint fldREF = 0x16;
static const Shortint fldTABLE = 0x17;
static const Shortint fldDATETIME = 0x18;
static const Shortint MAXLOGFLDTYPES = 0x19;
static const Shortint fldstMONEY = 0x15;
static const Shortint fldstMEMO = 0x16;
static const Shortint fldstBINARY = 0x17;
static const Shortint fldstFMTMEMO = 0x18;
static const Shortint fldstOLEOBJ = 0x19;
static const Shortint fldstGRAPHIC = 0x1a;
static const Shortint fldstDBSOLEOBJ = 0x1b;
static const Shortint fldstTYPEDBINARY = 0x1c;
static const Shortint fldstACCOLEOBJ = 0x1e;
static const Shortint fldstHMEMO = 0x21;
static const Shortint fldstHBINARY = 0x22;
static const Shortint fldstBFILE = 0x24;
static const Shortint fldstPASSWORD = 0x1;
static const Shortint fldstFIXED = 0x1f;
static const Shortint fldstUNICODE = 0x20;
static const Shortint fldstAUTOINC = 0x1d;
static const Shortint fldstADTNestedTable = 0x23;
static const Shortint fldstADTDATE = 0x25;
static const Shortint fldstGUID = 0x26;
static const Shortint fldstINT64 = 0x27;
static const Word fldPDXCHAR = 0x101;
static const Word fldPDXNUM = 0x102;
static const Word fldPDXMONEY = 0x103;
static const Word fldPDXDATE = 0x104;
static const Word fldPDXSHORT = 0x105;
static const Word fldPDXMEMO = 0x106;
static const Word fldPDXBINARYBLOB = 0x107;
static const Word fldPDXFMTMEMO = 0x108;
static const Word fldPDXOLEBLOB = 0x109;
static const Word fldPDXGRAPHIC = 0x10a;
static const Word fldPDXBLOB = 0x106;
static const Word fldPDXLONG = 0x10b;
static const Word fldPDXTIME = 0x10c;
static const Word fldPDXDATETIME = 0x10d;
static const Word fldPDXBOOL = 0x10e;
static const Word fldPDXAUTOINC = 0x10f;
static const Word fldPDXBYTES = 0x110;
static const Word fldPDXBCD = 0x111;
static const Word fldPDXUNICHAR = 0x112;
static const Word fldDBCHAR = 0x201;
static const Word fldDBNUM = 0x202;
static const Word fldDBMEMO = 0x203;
static const Word fldDBBOOL = 0x204;
static const Word fldDBDATE = 0x205;
static const Word fldDBFLOAT = 0x206;
static const Word fldDBLOCK = 0x207;
static const Word fldDBOLEBLOB = 0x208;
static const Word fldDBBINARY = 0x209;
static const Word fldDBBYTES = 0x20a;
static const Word fldDBLONG = 0x20b;
static const Word fldDBDATETIME = 0x20c;
static const Word fldDBDOUBLE = 0x20d;
static const Word fldDBAUTOINC = 0x20e;
static const Word fldDBKEYNUM = 0x210;
static const Word fldDBKEYBCD = 0x211;
static const Word fldASCCHAR = 0x301;
static const Word fldASCNUM = 0x302;
static const Word fldASCBOOL = 0x303;
static const Word fldASCDATE = 0x304;
static const Word fldASCFLOAT = 0x305;
static const Word fldASCLOCK = 0x306;
static const Word fldASCTIMESTAMP = 0x307;
static const Word fldASCTIME = 0x308;
static const Word fldASCLONG = 0x309;
static const Word fldASCMONEY = 0x30a;
static const Word fldACCCHAR = 0x701;
static const Word fldACCVARCHAR = 0x702;
static const Word fldACCDATETIME = 0x703;
static const Word fldACCBIT = 0x704;
static const Word fldACCMONEY = 0x705;
static const Word fldACCSHORT = 0x706;
static const Word fldACCLONG = 0x707;
static const Word fldACCFLOAT = 0x708;
static const Word fldACCLONGTEXT = 0x709;
static const Word fldACCLONGBINARY = 0x70a;
static const Word fldACCAUTOINC = 0x70b;
static const Word fldACCBYTE = 0x70c;
static const Word fldACCDOUBLE = 0x70d;
static const Word fldACCBINARY = 0x70e;
static const Word fldACCGUID = 0x70f;
static const Shortint mdxDISTINCT = 0x20;
static const Shortint TODAYVAL = 0x2;
static const Shortint NOWVAL = 0x3;
static const Shortint NOFAMRIGHTS = 0x0;
static const Shortint FORMRIGHTS = 0x1;
static const Shortint RPTRIGHTS = 0x2;
static const Shortint VALRIGHTS = 0x4;
static const Shortint SETRIGHTS = 0x8;
static const Shortint ALLFAMRIGHTS = 0xf;
static const Shortint prvNONE = 0x0;
static const Shortint prvREADONLY = 0x1;
static const Shortint prvMODIFY = 0x3;
static const Shortint prvINSERT = 0x7;
static const Shortint prvINSDEL = 0xf;
static const Shortint prvFULL = 0x1f;
static const Byte prvUNKNOWN = 0xff;
static const Word NODEFAULTINDEX = 0xffff;
static const Shortint TBLLEVEL3 = 0x3;
static const Shortint TBLLEVEL4 = 0x4;
static const Shortint TBLLEVEL5 = 0x5;
static const Shortint TBLLEVEL7 = 0x7;
static const Shortint FOXLEVEL25 = 0x19;
static const Shortint DBIDELAYUPD_SHOWMODIFYBIT = 0x1;
static const Shortint DBIDELAYUPD_SHOWINSERTBIT = 0x2;
static const Shortint DBIDELAYUPD_SHOWDELETEBIT = 0x4;
static const Shortint DBIDELAYUPD_SHOWNONMODIFYBIT = 0x8;
static const int curMAXPROPS = 0x50000;
static const int curTABLENAME = 0x50001;
static const int curTABLETYPE = 0x50002;
static const int curTABLELEVEL = 0x50003;
static const int curFILENAME = 0x50004;
static const int curXLTMODE = 0x50005;
static const int curSEQREADON = 0x50006;
static const int curONEPASSON = 0x50007;
static const int curUPDATETS = 0x50008;
static const int curSOFTDELETEON = 0x50009;
static const int curLANGDRVNAME = 0x5000a;
static const int curCURSORNAME = 0x5000b;
static const int curPESSIMISTICLOCKS = 0x5000c;
static const int curEXACTRECCNTEXPENSIVE = 0x5000d;
static const int curCOMPRESSARRAYFLDDESC = 0x5000e;
static const int curMAXFIELDID = 0x5000f;
static const int curFIELDFULLNAME = 0x50010;
static const int curFIELDTYPENAME = 0x50011;
static const int curFIELDIDFORNAME = 0x50012;
static const int curFIELDIDFORPARENT = 0x50013;
static const int curMAKECRACK = 0x50014;
static const int curFIELDISAUTOINCR = 0x50015;
static const int curFIELDISDEFAULT = 0x50016;
static const int curAUTOREFETCH = 0x50017;
static const Shortint maxcurPROPS = 0x17;
static const int curPDXMAXPROPS = 0x1050000;
static const Shortint maxcurPDXPROPS = 0x0;
static const int curDBMAXPROPS = 0x2050000;
static const int curINEXACTON = 0x2050001;
static const int curSHAREMODE = 0x2050002;
static const Shortint maxcurDBPROPS = 0x2;
static const int curDELIMITALLFLDS = 0x3050000;
static const int curUSESCHEMAFILE = 0x3050001;
static const int curUPDLOCKMODE = 0x4050000;
static const int curNATIVEHNDL = 0x4050001;
static const int curMAXROWS = 0x4050002;
static const int curGETEXTENDEDINFO = 0x4050003;
static const int curGETHIDDENCOLUMNS = 0x4050004;
static const int curAUTOFLUSHREF = 0x4050005;
static const int curREFINSERTTABLENAME = 0x4050006;
static const int curGETREF = 0x4050007;
static const int curCONSTSTATE = 0x405009b;
static const int curDELAYUPDRECSTATE = 0x5050001;
static const int curDELAYUPDABORTRESTORE = 0x5050002;
static const int curDELAYUPDDISPLAYOPT = 0x5050003;
static const int curDELAYUPDGETOLDRECORD = 0x5050004;
static const int curDELAYUPDNUMUPDATES = 0x5050005;
static const int curDELAYUPDUSECALLBACK = 0x5050006;
static const int drvMAXPROPS = 0x30000;
static const int drvDRIVERTYPE = 0x30002;
static const int drvDRIVERVERSION = 0x30003;
static const Shortint maxdrvPROPS = 0x2;
static const unsigned drvPSEUDOINDEX = 0xff030001;
static const int drvNATIVESQLCA = 0x30004;
static const int dbMAXPROPS = 0x40000;
static const int dbDATABASENAME = 0x40001;
static const int dbDATABASETYPE = 0x40002;
static const int dbDEFAULTDRIVER = 0x40003;
static const int dbPARAMFMTQMARK = 0x40004;
static const int dbUSESCHEMAFILE = 0x40005;
static const Shortint maxdbPROPS = 0x1b;
static const int dbASYNCSUPPORT = 0x4040000;
static const int dbPROCEDURES = 0x4040001;
static const int dbDEFAULTTXNISO = 0x4040002;
static const int dbNATIVEHNDL = 0x4040003;
static const int dbNATIVEPASSTHRUHNDL = 0x4040004;
static const int dbSERVERVERSION = 0x4040005;
static const int dbBATCHCOUNT = 0x4040006;
static const int dbTRACEMODE = 0x4040007;
static const int dbCURRENTUSERNAME = 0x4040008;
static const int dbOWNERQUALIFIED = 0x4040009;
static const int dbQUOTECHAR = 0x404000a;
static const int dbONLINE = 0x404000b;
static const int dbTRANALLOWED = 0x404000c;
static const int dbANSI = 0x404000d;
static const int dbDBMSNAME = 0x404000e;
static const int dbBLOBCOUNT = 0x404000f;
static const int dbBLOBSIZE = 0x4040010;
static const int dbCOMPRESSARRAYFLDDESC = 0x4040011;
static const int dbWAITONLOCK = 0x4040012;
static const int dbCOMMITRETAIN = 0x4040013;
static const int dbSCHEMACACHEENABLED = 0x4040099;
static const int dbBCDENABLED = 0x404009a;
static const int sesMAXPROPS = 0x20000;
static const int sesSESSIONNAME = 0x20001;
static const int sesNETFILE = 0x20002;
static const int sesCFGMODE = 0x20003;
static const int sesDEFAULTDRIVER = 0x20004;
static const int sesGROUPNAME = 0x20005;
static const int sesUSERNAME = 0x20006;
static const int sesUSERPASSWORD = 0x20007;
static const int sesSECFILENAME = 0x20008;
static const int sesDRNAME = 0x20009;
static const int sesCFGUPDATE = 0x2000a;
static const int sesCFGNAME = 0x2000b;
static const int sesCFGMODE2 = 0x2000c;
static const int sesCFGRefresh = 0x2000f;
static const Shortint maxsesPROPS = 0xd;
static const int sysMAXPROPS = 0x10000;
static const int sysLOWMEMUSAGE = 0x10001;
static const Shortint maxsysPROPS = 0x1;
static const int stmtMAXPROPS = 0x60001;
static const int stmtPARAMETERCOUNT = 0x60002;
static const int stmtPARAMETERDESCS = 0x60003;
static const int stmtLANGDRVNAME = 0x60004;
static const int stmtUNIDIRECTIONAL = 0x60010;
static const int stmtCURSORNAME = 0x60011;
static const int stmtNEWCONNECT = 0x60012;
static const int stmtNATIVEHNDL = 0x60013;
static const int stmtROWCOUNT = 0x60014;
static const int stmtEXECASCURSOR = 0x60015;
static const Shortint maxstmtPROPS = 0x20;
static const int stmtANSTYPE = 0x60020;
static const int stmtLIVENESS = 0x60021;
static const int stmtQRYMODE = 0x60022;
static const int stmtBLANKS = 0x60023;
static const int stmtDATEFORMAT = 0x60024;
static const int stmtNUMBERFORMAT = 0x60025;
static const int stmtAUXTBLS = 0x60026;
static const int stmtTBLVECTOR = 0x60027;
static const int stmtALLPROPS = 0x60028;
static const int stmtALLPROPSSIZE = 0x60029;
static const int stmtANSNAME = 0x60030;
static const int stmtCONSTRAINED = 0x60031;
static const int stmtFIELDDESCS = 0x60032;
static const int stmtCURPROPS = 0x60033;
static const int stmtDEFDBNAME = 0x60034;
static const int stmtXLTMODE = 0x60035;
static const int stmtINSTBLNAME = 0x60036;
static const int stmtINSERRTBLNAME = 0x60037;
static const int stmtUPDTBLNAME = 0x60038;
static const int stmtUPDERRTBLNAME = 0x60039;
static const int stmtDELTBLNAME = 0x60040;
static const int stmtDELERRTBLNAME = 0x60041;
static const int stmtCANNEDREADONLY = 0x60042;
static const Shortint CMPLess = 0xffffffff;
static const Shortint CMPEql = 0x0;
static const Shortint CMPGtr = 0x1;
static const Shortint CMPKeyEql = 0x2;
#define cbYIELDCLIENT (CBType)(20)
static const Shortint traceUNKNOWN = 0x0;
static const Shortint traceQPREPARE = 0x1;
static const Shortint traceQEXECUTE = 0x2;
static const Shortint traceERROR = 0x4;
static const Shortint traceSTMT = 0x8;
static const Shortint traceCONNECT = 0x10;
static const Shortint traceTRANSACT = 0x20;
static const Shortint traceBLOB = 0x40;
static const Byte traceMISC = 0x80;
static const Word traceVENDOR = 0x100;
static const Word traceDATAIN = 0x200;
static const Word traceDATAOUT = 0x400;
static const Shortint MAXCBENTRIES = 0x4;
static const Shortint indTRUNC = 0xfffffffe;
static const Shortint indNULL = 0xffffffff;
static const Shortint indVALUE = 0x1;
static const int INDLEN = 0x2;
static const Shortint qprepNONE = 0x0;
static const Shortint qprepFORUPDATE = 0x1;
static const Shortint ecTOKEN = 0x1;
static const Shortint ecTABLENAME = 0x3;
static const Shortint ecFIELDNAME = 0x4;
static const Shortint ecIMAGEROW = 0x5;
static const Shortint ecUSERNAME = 0x6;
static const Shortint ecFILENAME = 0x7;
static const Shortint ecINDEXNAME = 0x8;
static const Shortint ecDIRNAME = 0x9;
static const Shortint ecKEYNAME = 0xa;
static const Shortint ecALIAS = 0xb;
static const Shortint ecDRIVENAME = 0xc;
static const Shortint ecNATIVECODE = 0xd;
static const Shortint ecNATIVEMSG = 0xe;
static const Shortint ecLINENUMBER = 0xf;
static const Shortint ecCAPABILITY = 0x10;
static const Shortint ecCDRNAME = 0x11;
static const Shortint ecUSERERRMSG = 0x12;
static const Shortint ecDROBJNAME = 0x13;
static const Shortint ecINTERNALLIMIT = 0x14;
static const Shortint ecEXPRESSION = 0x15;
static const Shortint fnSCALARS_ALLOW_CONSTANTS = 0x1;
static const Shortint fnSCALARS_ALLOW_COLUMNS = 0x2;
static const Shortint fnSCALARS_ALLOW_PARAMETERS = 0x4;
static const Shortint fnSCALARS_ALLOW_FUNCTIONS = 0x8;
static const Shortint fnSCALARS_ALLOW_USER_DEFINED_FUNCS = 0x10;
static const Shortint fnSCALARS_ALLOW_SUBQUERIES = 0x20;
static const Shortint fnSCALARS_ALLOW_CORRELATION = 0x40;
static const Shortint cfgmNone = 0x0;
static const Shortint cfgmVirtual = 0x1;
static const Shortint cfgmPersistent = 0x2;
static const Shortint cfgmSession = 0x4;
static const Shortint cfgmAll = 0x7;
static const Shortint DBIOEM_CP = 0x1;
static const Shortint DBIANSI_CP = 0x2;
static const Shortint DBIOS2_CP = 0x3;
static const Shortint DBISUNOS_CP = 0x4;
static const Shortint DBIVMS_CP = 0x5;
static const Shortint DBIHPUX_CP = 0x6;
static const Shortint DBIULTRIX_CP = 0x7;
static const Shortint DBIAIX_CP = 0x8;
static const Shortint DBIAUX_CP = 0x9;
static const Shortint DBIXENIX_CP = 0xa;
static const Shortint DBIMAC_CP = 0xb;
static const Shortint DBINEXT_CP = 0xc;
static const Shortint DBIUNICODE_CP = 0xd;
static const Shortint DBIROMEN8_CP = 0xe;
static const Shortint DBIISO_CP = 0xf;
static const Shortint lckRECLOCK = 0x0;
static const Shortint lckRRECLOCK = 0x1;
static const Shortint lckGROUPLOCK = 0x2;
static const Shortint lckIMGAREA = 0x3;
static const Shortint lckTABLEREG = 0x4;
static const Shortint lckTABLEREAD = 0x5;
static const Shortint lckTABLEWRITE = 0x6;
static const Shortint lckTABLEEXCL = 0x7;
static const Shortint lckUNKNOWN = 0x9;
static const Shortint iLangSQL = 0x0;
static const Shortint iDbaseExpr = 0x2;
static const Shortint CANEXPRVERSION = 0x2;
static const Shortint ABORT = 0xfffffffe;
static const Word MAXQBEEXPRSIZE = 0x12c;
static const Shortint DBIQBE_ANSWERBIT = 0x1;
static const Shortint DBIQBE_INSERTEDBIT = 0x2;
static const Shortint DBIQBE_DELETEDBIT = 0x4;
static const Shortint DBIQBE_CHANGEDBIT = 0x8;
static const Shortint DBIQBE_ERRORINSBIT = 0x10;
static const Shortint DBIQBE_ERRORDELBIT = 0x20;
static const Shortint DBIQBE_ERRORCHGBIT = 0x40;
static const Shortint bAnsHasLiveFields = 0x1;
static const Shortint bAnsHasFilter = 0x2;
static const Shortint bAnsHasFieldMap = 0x4;
static const Shortint bAnsHasCalcField = 0x8;
static const Shortint bAnsHasLiveBlob = 0x10;
static const Shortint bIsAnsFieldLive = 0x1;
static const Word DBIMOD_BEGIN = 0x3f00;
static const Word DBIMOD_QBE = 0x3f01;
static const Word DBIMOD_SQLG = 0x3f02;
static const Word DBIMOD_LEGO = 0x3f03;
static const Word DBIMOD_LOCKMNGR = 0x3f04;
static const Word DBIMOD_SQLDRIVER = 0x3f05;
static const Word DBIMOD_OS = 0x3f06;
static const Word DBIMOD_DBASEDRV = 0x3f07;
static const Word DBIMOD_CDR = 0x3f08;
static const Word DBIMOD_END = 0x3f09;
static const Word DBISYM_BEGIN = 0x3f0a;
static const Word DBISYM_TOKEN = 0x3f0b;
static const Word DBISYM_TABLENAME = 0x3f0d;
static const Word DBISYM_FIELDNAME = 0x3f0e;
static const Word DBISYM_IMAGEROW = 0x3f0f;
static const Word DBISYM_USERNAME = 0x3f10;
static const Word DBISYM_FILENAME = 0x3f11;
static const Word DBISYM_INDEXNAME = 0x3f12;
static const Word DBISYM_DIRNAME = 0x3f13;
static const Word DBISYM_KEYNAME = 0x3f14;
static const Word DBISYM_ALIAS = 0x3f15;
static const Word DBISYM_DRIVENAME = 0x3f16;
static const Word DBISYM_NATIVECODE = 0x3f17;
static const Word DBISYM_NATIVEMSG = 0x3f18;
static const Word DBISYM_LINENUMBER = 0x3f19;
static const Word DBISYM_CAPABILITY = 0x3f1a;
static const Word DBISYM_CDRNAME = 0x3f1b;
static const Word DBISYM_USERERRMSG = 0x3f1c;
static const Word DBISYM_DROBJNAME = 0x3f1d;
static const Word DBISYM_INTERNALLIMIT = 0x3f1e;
static const Word DBISYM_EXPRESSION = 0x3f1f;
static const Word DBISYM_BASEEND = 0x3f6e;
static const Word DBISYM_MISC = 0x3f6f;
static const Word DBISYM_WORK = 0x3f70;
static const Word DBISYM_PRIV = 0x3f71;
static const Word DBISYM_COPY = 0x3f72;
static const Word DBISYM_APPEND = 0x3f73;
static const Word DBISYM_TXTPROBFLD1 = 0x3f74;
static const Word DBISYM_TXTPROBFLD2 = 0x3f75;
static const Word DBISYM_TXTPROBFLD3 = 0x3f76;
static const Word DBISYM_END = 0x7eff;
static const Shortint RELTYPE = 0x1;
static const Shortint COLTYPE = 0x2;
static const Shortint CONSTYPE = 0x3;
static const Shortint EXPRTYPE = 0x4;
static const Shortint AGGRTYPE = 0x5;
static const Shortint CELLTYPE = 0x6;
static const Shortint REQSELECT = 0x1;
static const Shortint REQSELECTALL = 0x2;
static const Shortint REQSELECTDIS = 0x3;
static const Shortint REQSELECTDEC = 0x4;
static const Shortint REQSELECTCOUNT = 0x5;
static const Shortint REQDDL = 0x6;
static const Shortint REQINSERT = 0x7;
static const Shortint REQUPDATE = 0x8;
static const Shortint REQDELETE = 0x9;
static const Word NAMELENGTH = 0x104;
static const Shortint REQVERSION = 0x3;
#define szCFGSYSTEM "SYSTEM"
#define szCFGDRIVER "DRIVERS"
#define szCFGDATABASE "DATABASES"
#define szCFGREPOSITORY "REPOSITORIES"
#define szCFGSYSVERSION "VERSION"
#define szCFGSYSNETTYPE "NET TYPE"
#define szCFGSYSNETDIR "NET DIR"
#define szCFGSYSLOCALSHARE "LOCAL SHARE"
#define szCFGSYSLANGDRV "LANGDRIVER"
#define szCFGSYSLANGDRVDIR "LANGDRVDIR"
#define szCFGSYSMINBUF "MINBUFSIZE"
#define szCFGSYSMAXBUF "MAXBUFSIZE"
#define szCFGSYSLOCKRETRY "LOCKRETRY"
#define szCFGSYSFLAGS "SYSFLAGS"
#define szCFGMAXFILEHANDLES "MAXFILEHANDLES"
#define szCFGSQLQRYMODE "SQLQRYMODE"
#define szCFGLOWMEMLIMIT "LOW MEMORY USAGE LIMIT"
#define szCFGSYSODBCCFGIMPORT "AUTO ODBC"
#define szCFGAUTOODBC "AUTO ODBC"
#define szCFGDEFDRV "DEFAULT DRIVER"
#define szCFGSYSLOCALREPOSITORY "DATA REPOSITORY"
#define szCFGSYSMEMSIZE "MEMSIZE"
#define szCFGSYSSHAREDMEMSIZE "SHAREDMEMSIZE"
#define szCFGSYSSHAREDMEMLOCATION "SHAREDMEMLOCATION"
#define szCFGSYSMTSPOOLING "MTS POOLING"
#define szCFGDRVVERSION "VERSION"
#define szCFGDRVTYPE "TYPE"
#define szCFGDRVDLL "DLL"
#define szCFGDRVDLL32 "DLL32"
#define szCFGDRVFLAGS "DRIVER FLAGS"
#define szCFGDRVLANGDRIVER "LANGDRIVER"
#define szCFGDRVFILLFACTOR "FILL FACTOR"
#define szCFGDRVBLOCKSIZE "BLOCK SIZE"
#define szCFGDRVLOCKPROTOCOL "LOCKPROTOCOL"
#define szCFGDRVLEVEL "LEVEL"
#define szCFGDRVVENDINIT "VENDOR INIT"
#define szCFGDRVTRACEMODE "TRACE MODE"
#define szCFGDRVMEMOBLOCKSIZE "MEMO FILE BLOCK SIZE"
#define szCFGDRVMDXBLOCKSIZE "MDX BLOCK SIZE"
#define szCFGDRVINIT "INIT"
#define szCFGDBCREATE "DB CREATE"
#define szCFGDBOPEN "DB OPEN"
#define szCFGTBLCREATE "TABLE CREATE"
#define szCFGTBLOPEN "TABLE OPEN"
#define szCFGDBINFO "DB INFO"
#define szCFGDBTYPE "TYPE"
#define szCFGDBPATH "PATH"
#define szCFGDBDEFAULTDRIVER "DEFAULT DRIVER"
#define szCFGDBENABLEBCD "ENABLE BCD"
#define szCFGINIT "INIT"
#define szTYPe "TYPE"
#define szCFGDBSTANDARD "STANDARD"
#define szCFGTRUE "TRUE"
#define szCFGFALSE "FALSE"
#define szOPENMODE "OPEN MODE"
#define szREADWRITE "READ/WRITE"
#define szREADONLy "READ ONLY"
#define szSHAREMODE "SHARE MODE"
#define szEXCLUSIVE "EXCLUSIVE"
#define szSHARED "SHARED"
#define szUSERNAME "USER NAME"
#define szPASSWORD "PASSWORD"
#define szSERVERNAME "SERVER NAME"
#define szDATABASENAME "DATABASE NAME"
#define szSCHEMASIZE "SCHEMA CACHE SIZE"
#define szCFGSTRICTINTEGRITY "STRICTINTEGRTY"
#define szSQLPASSMODE "SQLPASSTHRU MODE"
#define szNOTSHARED "NOT SHARED"
#define szSHAREDAUTOCOMMIT "SHARED AUTOCOMMIT"
#define szSHAREDNOAUTOCOMMIT "SHARED NOAUTOCOMMIT"
#define szSCHEMATIME "SCHEMA CACHE TIME"
#define szMAXQUERYTIME "MAX QUERY TIME"
#define szMAXROWS "MAX ROWS"
#define szLISTSYNONYMS "LIST SYNONYMS"
#define szSYNNONE "NONE"
#define szSYNALL "ALL"
#define szSYNPRIVATE "PRIVATE"
#define szBATCHCOUNT "BATCH COUNT"
#define szBLOBCOUNT "BLOBS TO CACHE"
#define szBLOBSIZE "BLOB SIZE"
#define szOBJECTMODE "OBJECT MODE"
#define szENABLESCHEMACACHE "ENABLE SCHEMA CACHE"
#define szSCHEMACACHEDIR "SCHEMA CACHE DIR"
#define szSYBLHOST "HOST NAME"
#define szSYBLAPP "APPLICATION NAME"
#define szSYBLNATLANG "NATIONAL LANG NAME"
#define szTDSPACKETSIZE "TDS PACKET SIZE"
#define szORAINTEGER "ENABLE INTEGERS"
#define szDBNLS "DBNLS"
#define szCOLLCHAR "COLLCHAR"
#define szROWSETSIZE "ROWSET SIZE"
#define szCFG30 "5.0"
#define szCFGSERVER "SERVER"
#define szCFGIDODBC01 "IDODBC01.DLL"
#define szCFGIDODBC32 "IDODBC32.DLL"
#define szCFGODBCDRIVER "ODBC DRIVER"
#define szCFGNULL ""
static const char szCFGZERO = '\x30';
#define szCFG20 "20"
#define szCFG64 "64"
#define szCFG32 "32"
#define szCFGODBCDSN "ODBC DSN"
#define szCFGTWOHUNDRED "200"
#define szCFGNEGONE "-1"
static const char szCFGEIGHT = '\x38';
#define szCLSID "CLSID"
#define szCFGSYSTEMDB "SYSTEM DATABASE"
#define szCFGOLEDBPROVIDER "OLE DB PROVIDER"
#define szCFGPERSISTFILE "DATA SOURCE FILE"
#define szCFGOBJECTMODE "OBJECT MODE"
#define szCFGDRDBNAME "DATABASE NAME"
#define szCFGDRTBLNAME "TABLE NAME"
#define szCFGDRLANGDRIVER "LANGUAGE DRIVER"
#define szCFGDRDESC "DESCRIPTION"
#define szCFGFORMAT "FORMATS"
#define szCFGDATE "DATE"
#define szCFGTIME "TIME"
#define szCFGNUMBER "NUMBER"
#define szCFGSEPARATOR "SEPARATOR"
#define szCFGMODE "MODE"
#define szCFGFOURDIGITYEAR "FOURDIGITYEAR"
#define szCFGYEARBIASED "YEARBIASED"
#define szCFGLEADINGZEROM "LEADINGZEROM"
#define szCFGLEADINGZEROD "LEADINGZEROD"
#define szCFGTWELVEHOUR "TWELVEHOUR"
#define szCFGAMSTRING "AMSTRING"
#define szCFGPMSTRING "PMSTRING"
#define szCFGSECONDS "SECONDS"
#define szCFGMILSECONDS "MILSECONDS"
#define szCFGDECIMALSEPARATOR "DECIMALSEPARATOR"
#define szCFGTHOUSANDSEPARATOR "THOUSANDSEPARATOR"
#define szCFGDECIMALDIGITS "DECIMALDIGITS"
#define szCFGLEADINGZERON "LEADINGZERON"
static const Word DBICFG_BASE = 0x3a00;
static const Word iCFGSYSTEM = 0x3a01;
static const Word iCFGDRIVER = 0x3a02;
static const Word iCFGDATABASE = 0x3a03;
static const Word iCFGREPOSITORY = 0x3ad2;
static const Word iCFGSYSVERSION = 0x3a05;
static const Word iCFGSYSNETTYPE = 0x3a06;
static const Word iCFGSYSNETDIR = 0x3a07;
static const Word iCFGSYSLOCALSHARE = 0x3a08;
static const Word iCFGSYSLANGDRV = 0x3a09;
static const Word iCFGSYSLANGDRVDIR = 0x3a0a;
static const Word iCFGSYSMINBUF = 0x3a0b;
static const Word iCFGSYSMAXBUF = 0x3a0c;
static const Word iCFGSYSLOCKRETRY = 0x3a0d;
static const Word iCFGSYSFLAGS = 0x3a0e;
static const Word iCFGMAXFILEHANDLES = 0x3a0f;
static const Word iCFGSQLQRYMODE = 0x3a10;
static const Word iCFGLOWMEMLIMIT = 0x3a11;
static const Word iCFGSYSODBCCFGIMPORT = 0x3a12;
static const Word iCFGSYSLOCALREPOSITORY = 0x3ad3;
static const Word iCFGSYSSHAREDMEMSIZE = 0x3afa;
static const Word iCFGSYSSHAREDMEMLOCATION = 0x3afb;
static const Word iCFGSYSMEMSIZE = 0x3a7d;
static const Word iCFGDRVVERSION = 0x3a14;
static const Word iCFGDRVTYPE = 0x3a15;
static const Word iCFGDRVLANGDRIVER = 0x3a16;
static const Word iCFGDRVFILLFACTOR = 0x3a17;
static const Word iCFGDRVBLOCKSIZE = 0x3a18;
static const Word iCFGDRVLOCKPROTOCOL = 0x3a19;
static const Word iCFGDRVLEVEL = 0x3a1a;
static const Word iCFGDRVFLAGS = 0x3a1b;
static const Word iCFGDRVTRACEMODE = 0x3a1c;
static const Word iCFGDRVDLL32 = 0x3a1d;
static const Word iCFGDRVMEMOBLOCKSIZE = 0x3a1e;
static const Word iCFGDRVMDXBLOCKSIZE = 0x3a1f;
static const Word iCFGDRVINIT = 0x3a28;
static const Word iCFGDBCREATE = 0x3a29;
static const Word iCFGDBOPEN = 0x3a2a;
static const Word iCFGTBLCREATE = 0x3a2b;
static const Word iCFGTBLOPEN = 0x3a2c;
static const Word iCFGDBINFO = 0x3a32;
static const Word iCFGDBTYPE = 0x3a3c;
static const Word iCFGDBPATH = 0x3a3d;
static const Word iCFGDBDEFAULTDRIVER = 0x3a3e;
static const Word iCFGDBENABLEBCD = 0x3a3f;
static const Word iCFGINIT = 0x3a46;
static const Word iTYPE = 0x3a47;
static const Word iCFGDBSTANDARD = 0x3a48;
static const Word iCFGTRUE = 0x3a49;
static const Word iCFGFALSE = 0x3a4a;
static const Word iOPENMODE = 0x3a4b;
static const Word iREADWRITE = 0x3a4c;
static const Word iREADONLY = 0x3a4d;
static const Word iSHAREMODE = 0x3a4e;
static const Word iEXCLUSIVE = 0x3a4f;
static const Word iSHARED = 0x3a50;
static const Word iUSERNAME = 0x3a51;
static const Word iSERVERNAME = 0x3a52;
static const Word iDATABASENAME = 0x3a53;
static const Word iSCHEMASIZE = 0x3a54;
static const Word iCFGSTRICTINTEGRITY = 0x3a55;
static const Word iTDSPACKETSIZE = 0x3a56;
static const Word iORAINTEGER = 0x3a57;
static const Word iDBNLS = 0x3a58;
static const Word iCOLLCHAR = 0x3a59;
static const Word iROWSETSIZE = 0x3a86;
static const Word iCFGOBJECTMODE = 0x3a87;
static const Word iCFGDRDBNAME = 0x3ad5;
static const Word iCFGDRTBLNAME = 0x3ad6;
static const Word iCFGDRDESC = 0x3ad7;
static const Word iCFGDRLANGDRIVER = 0x3ad4;
static const Word iCFGFORMAT = 0x3a82;
static const Word iCFGDATE = 0x3a83;
static const Word iCFGTIME = 0x3a84;
static const Word iCFGNUMBER = 0x3a85;
static const Word iCFGSEPARATOR = 0x3a8c;
static const Word iCFGMODE = 0x3a8d;
static const Word iCFGFOURDIGITYEAR = 0x3a8e;
static const Word iCFGYEARBIASED = 0x3a8f;
static const Word iCFGLEADINGZEROM = 0x3a90;
static const Word iCFGLEADINGZEROD = 0x3a91;
static const Word iCFGTWELVEHOUR = 0x3a92;
static const Word iCFGAMSTRING = 0x3a93;
static const Word iCFGPMSTRING = 0x3a94;
static const Word iCFGSECONDS = 0x3a95;
static const Word iCFGMILSECONDS = 0x3a96;
static const Word iCFGDECIMALSEPARATOR = 0x3aa0;
static const Word iCFGTHOUSANDSEPARATOR = 0x3aa1;
static const Word iCFGDECIMALDIGITS = 0x3aa2;
static const Word iCFGLEADINGZERON = 0x3aa3;
static const Word iCFGDEFLANGDRV = 0x3aa5;
static const Word iCFGDBASEDEFLANGDRV = 0x3aa6;
static const Word iCFGDEFSEPARATOR = 0x3aaa;
static const Word iCFGDEFMODE = 0x3aab;
static const Word iCFGDEFFOURDIGITYEAR = 0x3aac;
static const Word iCFGDEFYEARBIASED = 0x3aad;
static const Word iCFGDEFLEADINGZEROM = 0x3aae;
static const Word iCFGDEFLEADINGZEROD = 0x3aaf;
static const Word iCFGDEFTWELVEHOUR = 0x3ab0;
static const Word iCFGDEFAMSTRING = 0x3ab1;
static const Word iCFGDEFPMSTRING = 0x3ab2;
static const Word iCFGDEFSECONDS = 0x3ab3;
static const Word iCFGDEFMILSECONDS = 0x3ab4;
static const Word iCFGDEFDECIMALSEPARATOR = 0x3ab5;
static const Word iCFGDEFTHOUSANDSEPARATOR = 0x3ab6;
static const Word iCFGDEFLEADINGZERO = 0x3ab7;
static const Word iCFGDEFVERSION = 0x3ab8;
static const Word iCFGDEFLOCALSHARE = 0x3ab9;
static const Word iCFGDEFMINBUFSIZE = 0x3aba;
static const Word iCFGDEFMAXBUFSIZE = 0x3abb;
static const Word iCFGDEFMAXFILEHANDLES = 0x3abc;
static const Word iCFGDEFSYSFLAGS = 0x3abd;
static const Word iCFGDEFLOWMEM = 0x3abe;
static const Word iCFGDEFAUTOODBC = 0x3abf;
static const Word iCFGDEFDEFDRV = 0x3ac0;
static const Word iCFGDEFDECIMALDIGITS = 0x3ac1;
static const Word iCFGDEFLEADINGZERON = 0x3ac2;
static const Word iCFGDEFPDXTYPE = 0x3ac3;
static const Word iCFGDEFPDXNETDIR = 0x3ac4;
static const Word iCFGDEFPDXLANGDRV = 0x3ac5;
static const Word iCFGDEFPDXLEVEL = 0x3ac6;
static const Word iCFGDEFPDXBLOCKSIZE = 0x3ac7;
static const Word iCFGDEFPDXFILLFACTOR = 0x3ac8;
static const Word iCFGDEFPDXSTRICTINTEGRTY = 0x3ac9;
static const Word iCFGDEFDBASETYPE = 0x3aca;
static const Word iCFGDEFDBASELANGDRV = 0x3acb;
static const Word iCFGDEFDBASELEVEL = 0x3acc;
static const Word iCFGDEFDBASEMDXBLOCKSIZE = 0x3acd;
static const Word iCFGDEFDBASEMEMOBLOCKSIZE = 0x3ace;
static const Word iCFGAUTOODBC = 0x3acf;
static const Word iCFGDEFDRV = 0x3ad0;
static const Word iCFGENABLEBCD = 0x3ad1;
static const Word iCFGDEFSHAREDMEMSIZE = 0x3afc;
static const Word iCFGDEFSHAREDMEMLOCATION = 0x3afd;
static const Word iCFGDEFREPOSITORY = 0x3afe;
static const Word iCFGDEFSQLQRYMODE = 0x3aff;
static const Word iCFGDEFMEMSIZE = 0x3a7e;
static const Word iCFGDEFMSACCESSVER = 0x3adc;
static const Word iCFGDEFMSACCESSTYPE = 0x3add;
static const Word iCFGDEFMSACCESSDLL32 = 0x3ade;
static const Word iCFGDEFMSACCESSLANGDRV = 0x3adf;
static const Word iCFGDEFDATABASENAME = 0x3ae0;
static const Word iCFGDEFUSERNAME = 0x3ae1;
static const Word iCFGDEFTRACEMODE = 0x3ae2;
static const Word iCFGDEFDRVFLAGS = 0x3ae3;
static const Word iCFGCFGSYSTEMDB = 0x3ae7;
static const Word iCFGDEFFOXPROTYPE = 0x3ae4;
static const Word iCFGDEFFOXPROLANGDRV = 0x3ae5;
static const Word iCFGDEFFOXPROLEVEL = 0x3ae6;
static const Word CFGHLP_BASE = 0x3b00;
static const Word iCFGHLP_SYSNODE = 0x3b01;
static const Word iCFGHLP_SYSINITNODE = 0x3b02;
static const Word iCFGHLP_SYSVERSION = 0x3b03;
static const Word iCFGHLP_SYSLOCALSHARE = 0x3b04;
static const Word iCFGHLP_SYSMINBUFSIZE = 0x3b05;
static const Word iCFGHLP_SYSMAXBUFSIZE = 0x3b06;
static const Word iCFGHLP_SYSLANGDRIVER = 0x3b07;
static const Word iCFGHLP_SYSNETTYPE = 0x3b08;
static const Word iCFGHLP_SYSFLAGS = 0x3b09;
static const Word iCFGHLP_SYSMAXFILE = 0x3b0a;
static const Word iCFGHLP_SYSLOWMEM = 0x3b0b;
static const Word iCFGHLP_SYSAUTOODBC = 0x3b0c;
static const Word iCFGHLP_SYSDEFDRV = 0x3b0d;
static const Word iCFGHLP_SYSSQLQRYMODE = 0x3b0e;
static const Word iCFGHLP_SYSSQLPASSTHRU = 0x3b0f;
static const Word iCFGHLP_SYSFORMATNODE = 0x3b10;
static const Word iCFGHLP_DATENODE = 0x3b11;
static const Word iCFGHLP_DATESEPARATOR = 0x3b12;
static const Word iCFGHLP_DATEMODE = 0x3b13;
static const Word iCFGHLP_DATEFOURDIGIT = 0x3b14;
static const Word iCFGHLP_DATEYEARBIASED = 0x3b15;
static const Word iCFGHLP_DATEZEROM = 0x3b16;
static const Word iCFGHLP_DATEZEROD = 0x3b17;
static const Word iCFGHLP_TIMENODE = 0x3b18;
static const Word iCFGHLP_TIMETWELVEHOUR = 0x3b19;
static const Word iCFGHLP_TIMEAMSTRING = 0x3b1a;
static const Word iCFGHLP_TIMEPMSTRING = 0x3b1b;
static const Word iCFGHLP_TIMESECONDS = 0x3b1c;
static const Word iCFGHLP_TIMEMILSEC = 0x3b1d;
static const Word iCFGHLP_NUMNODE = 0x3b1e;
static const Word iCFGHLP_NUMDECIMALSEPARATOR = 0x3b1f;
static const Word iCFGHLP_NUMTHOUSANDSEPARATOR = 0x3b20;
static const Word iCFGHLP_NUMDECIMALDIGITS = 0x3b21;
static const Word iCFGHLP_NUMZERON = 0x3b22;
static const Word iCFGHLP_DRVNODE = 0x3b23;
static const Word iCFGHLP_PDXNODE = 0x3b24;
static const Word iCFGHLP_PDXINITNODE = 0x3b25;
static const Word iCFGHLP_DRVTYPE = 0x3b26;
static const Word iCFGHLP_PDXNETDIR = 0x3b27;
static const Word iCFGHLP_PDXTBLNODE = 0x3b28;
static const Word iCFGHLP_PDXLEVEL = 0x3b29;
static const Word iCFGHLP_PDXBLOCKSIZE = 0x3b2a;
static const Word iCFGHLP_PDXFILLFACTOR = 0x3b2b;
static const Word iCFGHLP_PDXSTRICT = 0x3b2c;
static const Word iCFGHLP_DBNODE = 0x3b2d;
static const Word iCFGHLP_DBINITNODE = 0x3b2e;
static const Word iCFGHLP_DBVERSION = 0x3b2f;
static const Word iCFGHLP_DBTBLNODE = 0x3b30;
static const Word iCFGHLP_DBLEVEL = 0x3b31;
static const Word iCFGHLP_DBMDXBLOCKSIZE = 0x3b32;
static const Word iCFGHLP_DBMEMOFILEBLOCKSIZE = 0x3b33;
static const Word iCFGHLP_INTNODE = 0x3b34;
static const Word iCFGHLP_INTINITNODE = 0x3b35;
static const Word iCFGHLP_INTVERSION = 0x3b36;
static const Word iCFGHLP_SQLDLL = 0x3b37;
static const Word iCFGHLP_SQLDLL32 = 0x3b38;
static const Word iCFGHLP_SQLDRIVERFLAGS = 0x3b39;
static const Word iCFGHLP_INTDBNODE = 0x3b3a;
static const Word iCFGHLP_SQLSERVER = 0x3b3b;
static const Word iCFGHLP_SQLUSER = 0x3b3c;
static const Word iCFGHLP_SQLOPENMODE = 0x3b3d;
static const Word iCFGHLP_SQLSCHEMASIZE = 0x3b3e;
static const Word iCFGHLP_SQLSCHEMATIME = 0x3b3f;
static const Word iCFGHLP_SYBNODE = 0x3b40;
static const Word iCFGHLP_SYBINITNODE = 0x3b41;
static const Word iCFGHLP_SYBVERSION = 0x3b42;
static const Word iCFGHLP_SQLCONNECT = 0x3b43;
static const Word iCFGHLP_SQLTIMEOUT = 0x3b44;
static const Word iCFGHLP_SYBDBNODE = 0x3b45;
static const Word iCFGHLP_SQLDATABASE = 0x3b46;
static const Word iCFGHLP_SQLBLOBEDIT = 0x3b47;
static const Word iCFGHLP_SQLMAXQUERY = 0x3b48;
static const Word iCFGHLP_ORANODE = 0x3b49;
static const Word iCFGHLP_ORAINITNODE = 0x3b4a;
static const Word iCFGHLP_ORAVERSION = 0x3b4b;
static const Word iCFGHLP_SQLVENDOR = 0x3b4c;
static const Word iCFGHLP_ORADBNODE = 0x3b4d;
static const Word iCFGHLP_SQLNETPROTOCOL = 0x3b4e;
static const Word iCFGHLP_MSSNODE = 0x3b4f;
static const Word iCFGHLP_MSSINITNODE = 0x3b50;
static const Word iCFGHLP_MSSVERSION = 0x3b51;
static const Word iCFGHLP_MSSDBNODE = 0x3b52;
static const Word iCFGHLP_INFNODE = 0x3b53;
static const Word iCFGHLP_INFINITNODE = 0x3b54;
static const Word iCFGHLP_INFVERSION = 0x3b55;
static const Word iCFGHLP_INFDBNODE = 0x3b56;
static const Word iCFGHLP_SQLLOCKMODE = 0x3b57;
static const Word iCFGHLP_SQLTRACEMODE = 0x3b58;
static const Word iCFGHLP_SQLMAXROWS = 0x3b59;
static const Word iCFGHLP_SQLBATCHCOUNT = 0x3b5a;
static const Word iCFGHLP_SYSSHAREDMEMSIZ = 0x3b5b;
static const Word iCFGHLP_SYSSHAREDMEMLOC = 0x3b5c;
static const Word iCFGHLP_SYSDATAREP = 0x3b5d;
static const Word iCFGHLP_ALIASTYPE = 0x3b5e;
static const Word iCFGHLP_ALIASPATH = 0x3b5f;
static const Word iCFGHLP_ALIASDEFDRV = 0x3b60;
static const Word iCFGHLP_ENABLESCHEMACACHE = 0x3b61;
static const Word iCFGHLP_SCHEMACACHEDIR = 0x3b62;
static const Word iCFGHLP_HOSTNAME = 0x3b63;
static const Word iCFGHLP_APPLICATIONNAME = 0x3b64;
static const Word iCFGHLP_NATIONALLANGNAME = 0x3b65;
static const Word iCFGHLP_ALIASENABLEBCD = 0x3b66;
static const Word iCFGHLP_TDSPACKETSIZE = 0x3b67;
static const Word iCFGHLP_ORAINTEGER = 0x3b68;
static const Word iCFGHLP_ORALISTSYNONYMS = 0x3b69;
static const Word iCFGHLP_ROWSETSIZE = 0x3b6a;
static const Word iCFGHLP_DB2DRIVER = 0x3b6b;
static const Word iCFGHLP_DB2DSN = 0x3b6c;
static const Word iCFGHLP_DB2NODE = 0x3b6d;
static const Word iCFGHLP_DB2INITNODE = 0x3b6e;
static const Word iCFGHLP_DB2VERSION = 0x3b6f;
static const Word iCFGHLP_DB2DBNODE = 0x3b70;
static const Word iCFGHLP_COLLCHAR = 0x3b71;
static const Word iCFGHLP_DBNLS = 0x3b72;
static const Word iCFGHLP_MSACCNODE = 0x3b73;
static const Word iCFGHLP_MSACCINITNODE = 0x3b74;
static const Word iCFGHLP_MSACCVERSION = 0x3b75;
static const Word iCFGHLP_MSACCDBNODE = 0x3b76;
static const Word iCFGHLP_ODBCDRIVER = 0x3b77;
static const Word iCFGHLP_ODBCVERSION = 0x3b78;
static const Word iCFGHLP_ODBCDSN = 0x3b79;
static const Word iCFGHLP_OLEVERSION = 0x3b7a;
static const Word iCFGHLP_OLECLSID = 0x3b7b;
static const Word iCFGHLP_BLOBSTOCACHE = 0x3b7c;
static const Word iCFGHLP_BLOBSIZE = 0x3b7d;
static const Word iCFGHLP_SYSMEMSIZE = 0x3b7e;
static const Word iCFGHLP_MAXDBPROCS = 0x3b7f;
static const Word iCFGHLP_FPNODE = 0x3b80;
static const Word iCFGHLP_FPINITNODE = 0x3b81;
static const Word iCFGHLP_FPVERSION = 0x3b82;
static const Word iCFGHLP_FPTBLNODE = 0x3b83;
static const Word iCFGHLP_FPLEVEL = 0x3b84;
static const Word iCFGHLP_FPMEMOFILEBLOCKSIZE = 0x3b85;
static const Word iCFGHLP_CFGSYSTEMDB = 0x3b86;
static const Word iCFGHLP_OBJECTMODE = 0x3b87;
static const Shortint ERRCAT_NONE = 0x0;
static const Shortint ERRCAT_SYSTEM = 0x21;
static const Shortint ERRCAT_NOTFOUND = 0x22;
static const Shortint ERRCAT_DATACORRUPT = 0x23;
static const Shortint ERRCAT_IO = 0x24;
static const Shortint ERRCAT_LIMIT = 0x25;
static const Shortint ERRCAT_INTEGRITY = 0x26;
static const Shortint ERRCAT_INVALIDREQ = 0x27;
static const Shortint ERRCAT_LOCKCONFLICT = 0x28;
static const Shortint ERRCAT_SECURITY = 0x29;
static const Shortint ERRCAT_INVALIDCONTEXT = 0x2a;
static const Shortint ERRCAT_OS = 0x2b;
static const Shortint ERRCAT_NETWORK = 0x2c;
static const Shortint ERRCAT_OPTPARAM = 0x2d;
static const Shortint ERRCAT_QUERY = 0x2e;
static const Shortint ERRCAT_VERSION = 0x2f;
static const Shortint ERRCAT_CAPABILITY = 0x30;
static const Shortint ERRCAT_CONFIG = 0x31;
static const Shortint ERRCAT_WARNING = 0x32;
static const Shortint ERRCAT_OTHER = 0x33;
static const Shortint ERRCAT_COMPATIBILITY = 0x34;
static const Shortint ERRCAT_REPOSITORY = 0x35;
static const Shortint ERRCAT_DRIVER = 0x3e;
static const Shortint ERRCAT_RC = 0x3f;
static const Shortint ERRBASE_NONE = 0x0;
static const Word ERRBASE_SYSTEM = 0x2100;
static const Word ERRBASE_NOTFOUND = 0x2200;
static const Word ERRBASE_DATACORRUPT = 0x2300;
static const Word ERRBASE_IO = 0x2400;
static const Word ERRBASE_LIMIT = 0x2500;
static const Word ERRBASE_INTEGRITY = 0x2600;
static const Word ERRBASE_INVALIDREQ = 0x2700;
static const Word ERRBASE_LOCKCONFLICT = 0x2800;
static const Word ERRBASE_SEC = 0x2900;
static const Word ERRBASE_IC = 0x2a00;
static const Word ERRBASE_OS = 0x2b00;
static const Word ERRBASE_NETWORK = 0x2c00;
static const Word ERRBASE_OPTPARAM = 0x2d00;
static const Word ERRBASE_QUERY = 0x2e00;
static const Word ERRBASE_VERSION = 0x2f00;
static const Word ERRBASE_CAPABILITY = 0x3000;
static const Word ERRBASE_CONFIG = 0x3100;
static const Word ERRBASE_WARNING = 0x3200;
static const Word ERRBASE_OTHER = 0x3300;
static const Word ERRBASE_COMPATIBILITY = 0x3400;
static const Word ERRBASE_REPOSITORY = 0x3500;
static const Word ERRBASE_DRIVER = 0x3e00;
static const Word ERRBASE_RC = 0x3f00;
static const Shortint ERRCODE_NONE = 0x0;
static const Shortint DBIERR_NONE = 0x0;
static const Shortint ERRCODE_SYSFILEOPEN = 0x1;
static const Shortint ERRCODE_SYSFILEIO = 0x2;
static const Shortint ERRCODE_SYSCORRUPT = 0x3;
static const Shortint ERRCODE_NOCONFIGFILE = 0x4;
static const Shortint ERRCODE_CFGCANNOTWRITE = 0x5;
static const Shortint ERRCODE_CFGMULTIFILE = 0x6;
static const Shortint ERRCODE_REENTERED = 0x7;
static const Shortint ERRCODE_CANTFINDIDAPI = 0x8;
static const Shortint ERRCODE_CANTLOADIDAPI = 0x9;
static const Shortint ERRCODE_CANTLOADLIBRARY = 0xa;
static const Shortint ERRCODE_TEMPFILEERR = 0xb;
static const Shortint ERRCODE_MULTIPLEIDAPI = 0xc;
static const Shortint ERRCODE_SHAREDMEMCONFLICT = 0xd;
static const Word DBIERR_SYSFILEOPEN = 0x2101;
static const Word DBIERR_SYSFILEIO = 0x2102;
static const Word DBIERR_SYSCORRUPT = 0x2103;
static const Word DBIERR_NOCONFIGFILE = 0x2104;
static const Word DBIERR_CFGCANNOTWRITE = 0x2105;
static const Word DBIERR_CFGMULTIFILE = 0x2106;
static const Word DBIERR_REENTERED = 0x2107;
static const Word DBIERR_CANTFINDIDAPI = 0x2108;
static const Word DBIERR_CANTLOADIDAPI = 0x2109;
static const Word DBIERR_CANTLOADLIBRARY = 0x210a;
static const Word DBIERR_TEMPFILEERR = 0x210b;
static const Word DBIERR_MULTIPLEIDAPI = 0x210c;
static const Word DBIERR_SHAREDMEMCONFLICT = 0x210d;
static const Word DBIERR_CANTFINDODAPI = 0x2108;
static const Word DBIERR_CANTLOADODAPI = 0x2109;
static const Shortint ERRCODE_BOF = 0x1;
static const Shortint ERRCODE_EOF = 0x2;
static const Shortint ERRCODE_RECMOVED = 0x3;
static const Shortint ERRCODE_KEYORRECDELETED = 0x4;
static const Shortint ERRCODE_NOCURRREC = 0x5;
static const Shortint ERRCODE_RECNOTFOUND = 0x6;
static const Shortint ERRCODE_ENDOFBLOB = 0x7;
static const Shortint ERRCODE_OBJNOTFOUND = 0x8;
static const Shortint ERRCODE_FMLMEMBERNOTFOUND = 0x9;
static const Shortint ERRCODE_BLOBFILEMISSING = 0xa;
static const Shortint ERRCODE_LDNOTFOUND = 0xb;
static const Word DBIERR_BOF = 0x2201;
static const Word DBIERR_EOF = 0x2202;
static const Word DBIERR_RECMOVED = 0x2203;
static const Word DBIERR_RECDELETED = 0x2204;
static const Word DBIERR_KEYORRECDELETED = 0x2204;
static const Word DBIERR_NOCURRREC = 0x2205;
static const Word DBIERR_RECNOTFOUND = 0x2206;
static const Word DBIERR_ENDOFBLOB = 0x2207;
static const Word DBIERR_OBJNOTFOUND = 0x2208;
static const Word DBIERR_FMLMEMBERNOTFOUND = 0x2209;
static const Word DBIERR_BLOBFILEMISSING = 0x220a;
static const Word DBIERR_LDNOTFOUND = 0x220b;
static const Shortint ERRCODE_HEADERCORRUPT = 0x1;
static const Shortint ERRCODE_FILECORRUPT = 0x2;
static const Shortint ERRCODE_MEMOCORRUPT = 0x3;
static const Shortint ERRCODE_BMPCORRUPT = 0x4;
static const Shortint ERRCODE_INDEXCORRUPT = 0x5;
static const Shortint ERRCODE_CORRUPTLOCKFILE = 0x6;
static const Shortint ERRCODE_FAMFILEINVALID = 0x7;
static const Shortint ERRCODE_VALFILECORRUPT = 0x8;
static const Shortint ERRCODE_FOREIGNINDEX = 0x9;
static const Word DBIERR_HEADERCORRUPT = 0x2301;
static const Word DBIERR_FILECORRUPT = 0x2302;
static const Word DBIERR_MEMOCORRUPT = 0x2303;
static const Word DBIERR_BMPCORRUPT = 0x2304;
static const Word DBIERR_INDEXCORRUPT = 0x2305;
static const Word DBIERR_CORRUPTLOCKFILE = 0x2306;
static const Word DBIERR_FAMFILEINVALID = 0x2307;
static const Word DBIERR_VALFILECORRUPT = 0x2308;
static const Word DBIERR_FOREIGNINDEX = 0x2309;
static const Shortint ERRCODE_READERR = 0x1;
static const Shortint ERRCODE_WRITEERR = 0x2;
static const Shortint ERRCODE_DIRNOACCESS = 0x3;
static const Shortint ERRCODE_FILEDELETEFAIL = 0x4;
static const Shortint ERRCODE_FILENOACCESS = 0x5;
static const Shortint ERRCODE_ACCESSDISABLED = 0x6;
static const Word DBIERR_READERR = 0x2401;
static const Word DBIERR_WRITEERR = 0x2402;
static const Word DBIERR_DIRNOACCESS = 0x2403;
static const Word DBIERR_FILEDELETEFAIL = 0x2404;
static const Word DBIERR_FILENOACCESS = 0x2405;
static const Word DBIERR_ACCESSDISABLED = 0x2406;
static const Shortint ERRCODE_NOMEMORY = 0x1;
static const Shortint ERRCODE_NOFILEHANDLES = 0x2;
static const Shortint ERRCODE_NODISKSPACE = 0x3;
static const Shortint ERRCODE_NOTEMPTBLSPACE = 0x4;
static const Shortint ERRCODE_RECTOOBIG = 0x5;
static const Shortint ERRCODE_CURSORLIMIT = 0x6;
static const Shortint ERRCODE_TABLEFULL = 0x7;
static const Shortint ERRCODE_WSSESLIMIT = 0x8;
static const Shortint ERRCODE_SERNUMLIMIT = 0x9;
static const Shortint ERRCODE_INTERNALLIMIT = 0xa;
static const Shortint ERRCODE_OPENTBLLIMIT = 0xb;
static const Shortint ERRCODE_TBLCURSORLIMIT = 0xc;
static const Shortint ERRCODE_RECLOCKLIMIT = 0xd;
static const Shortint ERRCODE_CLIENTSLIMIT = 0xe;
static const Shortint ERRCODE_INDEXLIMIT = 0xf;
static const Shortint ERRCODE_SESSIONSLIMIT = 0x10;
static const Shortint ERRCODE_DBLIMIT = 0x11;
static const Shortint ERRCODE_PASSWORDLIMIT = 0x12;
static const Shortint ERRCODE_DRIVERLIMIT = 0x13;
static const Shortint ERRCODE_FLDLIMIT = 0x14;
static const Shortint ERRCODE_TBLLOCKLIMIT = 0x15;
static const Shortint ERRCODE_OPENBLOBLIMIT = 0x16;
static const Shortint ERRCODE_LOCKFILELIMIT = 0x17;
static const Shortint ERRCODE_OPENQRYLIMIT = 0x18;
static const Shortint ERRCODE_THREADLIMIT = 0x19;
static const Shortint ERRCODE_BLOBLIMIT = 0x1a;
static const Shortint ERRCODE_PDX50NAMELIMIT = 0x1b;
static const Shortint ERRCODE_ROWFETCHLIMIT = 0x1c;
static const Shortint ERRCODE_LONGNAMENOTALLOWED = 0x1d;
static const Shortint ERRCODE_NOSHAREDMEMORY = 0x1e;
static const Word DBIERR_NOMEMORY = 0x2501;
static const Word DBIERR_NOFILEHANDLES = 0x2502;
static const Word DBIERR_NODISKSPACE = 0x2503;
static const Word DBIERR_NOTEMPTBLSPACE = 0x2504;
static const Word DBIERR_RECTOOBIG = 0x2505;
static const Word DBIERR_CURSORLIMIT = 0x2506;
static const Word DBIERR_TABLEFULL = 0x2507;
static const Word DBIERR_WSSESLIMIT = 0x2508;
static const Word DBIERR_SERNUMLIMIT = 0x2509;
static const Word DBIERR_INTERNALLIMIT = 0x250a;
static const Word DBIERR_OPENTBLLIMIT = 0x250b;
static const Word DBIERR_TBLCURSORLIMIT = 0x250c;
static const Word DBIERR_RECLOCKLIMIT = 0x250d;
static const Word DBIERR_CLIENTSLIMIT = 0x250e;
static const Word DBIERR_INDEXLIMIT = 0x250f;
static const Word DBIERR_SESSIONSLIMIT = 0x2510;
static const Word DBIERR_DBLIMIT = 0x2511;
static const Word DBIERR_PASSWORDLIMIT = 0x2512;
static const Word DBIERR_DRIVERLIMIT = 0x2513;
static const Word DBIERR_FLDLIMIT = 0x2514;
static const Word DBIERR_TBLLOCKLIMIT = 0x2515;
static const Word DBIERR_OPENBLOBLIMIT = 0x2516;
static const Word DBIERR_LOCKFILELIMIT = 0x2517;
static const Word DBIERR_OPENQRYLIMIT = 0x2518;
static const Word DBIERR_THREADLIMIT = 0x2519;
static const Word DBIERR_BLOBLIMIT = 0x251a;
static const Word DBIERR_PDX50NAMELIMIT = 0x251b;
static const Word DBIERR_ROWFETCHLIMIT = 0x251c;
static const Word DBIERR_LONGNAMENOTALLOWED = 0x251d;
static const Word DBIERR_NOSHAREDMEMORY = 0x251e;
static const Shortint ERRCODE_KEYVIOL = 0x1;
static const Shortint ERRCODE_MINVALERR = 0x2;
static const Shortint ERRCODE_MAXVALERR = 0x3;
static const Shortint ERRCODE_REQDERR = 0x4;
static const Shortint ERRCODE_FORIEGNKEYERR = 0x5;
static const Shortint ERRCODE_DETAILRECORDSEXIST = 0x6;
static const Shortint ERRCODE_MASTERTBLLEVEL = 0x7;
static const Shortint ERRCODE_LOOKUPTABLEERR = 0x8;
static const Shortint ERRCODE_LOOKUPTBLOPENERR = 0x9;
static const Shortint ERRCODE_DETAILTBLOPENERR = 0xa;
static const Shortint ERRCODE_MASTERTBLOPENERR = 0xb;
static const Shortint ERRCODE_FIELDISBLANK = 0xc;
static const Shortint ERRCODE_MASTEREXISTS = 0xd;
static const Shortint ERRCODE_MASTERTBLOPEN = 0xe;
static const Shortint ERRCODE_DETAILTABLESEXIST = 0xf;
static const Shortint ERRCODE_DETAILRECEXISTEMPTY = 0x10;
static const Shortint ERRCODE_MASTERREFERENCEERR = 0x11;
static const Shortint ERRCODE_DETAILTBLOPEN = 0x12;
static const Shortint ERRCODE_DEPENDENTSMUSTBEEMPTY = 0x13;
static const Shortint ERRCODE_RINTREQINDEX = 0x14;
static const Shortint ERRCODE_LINKEDTBLPROTECTED = 0x15;
static const Shortint ERRCODE_FIELDMULTILINKED = 0x16;
static const Shortint ERRCODE_EXPRVALERR = 0x17;
static const Word DBIERR_KEYVIOL = 0x2601;
static const Word DBIERR_MINVALERR = 0x2602;
static const Word DBIERR_MAXVALERR = 0x2603;
static const Word DBIERR_REQDERR = 0x2604;
static const Word DBIERR_FORIEGNKEYERR = 0x2605;
static const Word DBIERR_DETAILRECORDSEXIST = 0x2606;
static const Word DBIERR_MASTERTBLLEVEL = 0x2607;
static const Word DBIERR_LOOKUPTABLEERR = 0x2608;
static const Word DBIERR_LOOKUPTBLOPENERR = 0x2609;
static const Word DBIERR_DETAILTBLOPENERR = 0x260a;
static const Word DBIERR_MASTERTBLOPENERR = 0x260b;
static const Word DBIERR_FIELDISBLANK = 0x260c;
static const Word DBIERR_MASTEREXISTS = 0x260d;
static const Word DBIERR_MASTERTBLOPEN = 0x260e;
static const Word DBIERR_DETAILTABLESEXIST = 0x260f;
static const Word DBIERR_DETAILRECEXISTEMPTY = 0x2610;
static const Word DBIERR_MASTERREFERENCEERR = 0x2611;
static const Word DBIERR_DETAILTBLOPEN = 0x2612;
static const Word DBIERR_DEPENDENTSMUSTBEEMPTY = 0x2613;
static const Word DBIERR_RINTREQINDEX = 0x2614;
static const Word DBIERR_LINKEDTBLPROTECTED = 0x2615;
static const Word DBIERR_FIELDMULTILINKED = 0x2616;
static const Word DBIERR_EXPRVALERR = 0x2617;
static const Shortint ERRCODE_OUTOFRANGE = 0x1;
static const Shortint ERRCODE_INVALIDPARAM = 0x2;
static const Shortint ERRCODE_INVALIDFILENAME = 0x3;
static const Shortint ERRCODE_NOSUCHFILE = 0x4;
static const Shortint ERRCODE_INVALIDOPTION = 0x5;
static const Shortint ERRCODE_INVALIDHNDL = 0x6;
static const Shortint ERRCODE_UNKNOWNTBLTYPE = 0x7;
static const Shortint ERRCODE_UNKNOWNFILE = 0x8;
static const Shortint ERRCODE_PRIMARYKEYREDEFINE = 0x9;
static const Shortint ERRCODE_INVALIDRINTDESCNUM = 0xa;
static const Shortint ERRCODE_KEYFLDTYPEMISMATCH = 0xb;
static const Shortint ERRCODE_INVALIDMODIFYREQUEST = 0xc;
static const Shortint ERRCODE_NOSUCHINDEX = 0xd;
static const Shortint ERRCODE_INVALIDBLOBOFFSET = 0xe;
static const Shortint ERRCODE_INVALIDDESCNUM = 0xf;
static const Shortint ERRCODE_INVALIDFLDTYPE = 0x10;
static const Shortint ERRCODE_INVALIDFLDDESC = 0x11;
static const Shortint ERRCODE_INVALIDFLDXFORM = 0x12;
static const Shortint ERRCODE_INVALIDRECSTRUCT = 0x13;
static const Shortint ERRCODE_INVALIDDESC = 0x14;
static const Shortint ERRCODE_INVALIDINDEXSTRUCT = 0x15;
static const Shortint ERRCODE_INVALIDVCHKSTRUCT = 0x16;
static const Shortint ERRCODE_INVALIDRINTSTRUCT = 0x17;
static const Shortint ERRCODE_INVALIDRESTRTBLORDER = 0x18;
static const Shortint ERRCODE_NAMENOTUNIQUE = 0x19;
static const Shortint ERRCODE_INDEXNAMEREQUIRED = 0x1a;
static const Shortint ERRCODE_INVALIDSESHANDLE = 0x1b;
static const Shortint ERRCODE_INVALIDRESTROP = 0x1c;
static const Shortint ERRCODE_UNKNOWNDRIVER = 0x1d;
static const Shortint ERRCODE_UNKNOWNDB = 0x1e;
static const Shortint ERRCODE_INVALIDPASSWORD = 0x1f;
static const Shortint ERRCODE_NOCALLBACK = 0x20;
static const Shortint ERRCODE_INVALIDCALLBACKBUFLEN = 0x21;
static const Shortint ERRCODE_INVALIDDIR = 0x22;
static const Shortint ERRCODE_INVALIDXLATION = 0x23;
static const Shortint ERRCODE_DIFFERENTTABLES = 0x24;
static const Shortint ERRCODE_INVALIDBOOKMARK = 0x25;
static const Shortint ERRCODE_INVALIDINDEXNAME = 0x26;
static const Shortint ERRCODE_INVALIDIDXDESC = 0x27;
static const Shortint ERRCODE_NOSUCHTABLE = 0x28;
static const Shortint ERRCODE_USECOUNT = 0x29;
static const Shortint ERRCODE_INVALIDKEY = 0x2a;
static const Shortint ERRCODE_INDEXEXISTS = 0x2b;
static const Shortint ERRCODE_INDEXOPEN = 0x2c;
static const Shortint ERRCODE_INVALIDBLOBLEN = 0x2d;
static const Shortint ERRCODE_INVALIDBLOBHANDLE = 0x2e;
static const Shortint ERRCODE_TABLEOPEN = 0x2f;
static const Shortint ERRCODE_NEEDRESTRUCTURE = 0x30;
static const Shortint ERRCODE_INVALIDMODE = 0x31;
static const Shortint ERRCODE_CANNOTCLOSE = 0x32;
static const Shortint ERRCODE_ACTIVEINDEX = 0x33;
static const Shortint ERRCODE_INVALIDUSRPASS = 0x34;
static const Shortint ERRCODE_MULTILEVELCASCADE = 0x35;
static const Shortint ERRCODE_INVALIDFIELDNAME = 0x36;
static const Shortint ERRCODE_INVALIDTABLENAME = 0x37;
static const Shortint ERRCODE_INVALIDLINKEXPR = 0x38;
static const Shortint ERRCODE_NAMERESERVED = 0x39;
static const Shortint ERRCODE_INVALIDFILEEXTN = 0x3a;
static const Shortint ERRCODE_INVALIDLANGDRV = 0x3b;
static const Shortint ERRCODE_ALIASNOTOPEN = 0x3c;
static const Shortint ERRCODE_INCOMPATRECSTRUCTS = 0x3d;
static const Shortint ERRCODE_RESERVEDDOSNAME = 0x3e;
static const Shortint ERRCODE_DESTMUSTBEINDEXED = 0x3f;
static const Shortint ERRCODE_INVALIDINDEXTYPE = 0x40;
static const Shortint ERRCODE_LANGDRVMISMATCH = 0x41;
static const Shortint ERRCODE_NOSUCHFILTER = 0x42;
static const Shortint ERRCODE_INVALIDFILTER = 0x43;
static const Shortint ERRCODE_INVALIDTABLECREATE = 0x44;
static const Shortint ERRCODE_INVALIDTABLEDELETE = 0x45;
static const Shortint ERRCODE_INVALIDINDEXCREATE = 0x46;
static const Shortint ERRCODE_INVALIDINDEXDELETE = 0x47;
static const Shortint ERRCODE_INVALIDTABLE = 0x48;
static const Shortint ERRCODE_MULTIRESULTS = 0x49;
static const Shortint ERRCODE_INVALIDTIME = 0x4a;
static const Shortint ERRCODE_INVALIDDATE = 0x4b;
static const Shortint ERRCODE_INVALIDTIMESTAMP = 0x4c;
static const Shortint ERRCODE_DIFFERENTPATH = 0x4d;
static const Shortint ERRCODE_MISMATCHARGS = 0x4e;
static const Shortint ERRCODE_FUNCTIONNOTFOUND = 0x4f;
static const Shortint ERRCODE_MUSTUSEBASEORDER = 0x50;
static const Shortint ERRCODE_INVALIDPROCEDURENAME = 0x51;
static const Shortint ERRCODE_INVALIDFLDMAP = 0x52;
static const Word DBIERR_OUTOFRANGE = 0x2701;
static const Word DBIERR_INVALIDPARAM = 0x2702;
static const Word DBIERR_INVALIDFILENAME = 0x2703;
static const Word DBIERR_NOSUCHFILE = 0x2704;
static const Word DBIERR_INVALIDOPTION = 0x2705;
static const Word DBIERR_INVALIDHNDL = 0x2706;
static const Word DBIERR_UNKNOWNTBLTYPE = 0x2707;
static const Word DBIERR_UNKNOWNFILE = 0x2708;
static const Word DBIERR_PRIMARYKEYREDEFINE = 0x2709;
static const Word DBIERR_INVALIDRINTDESCNUM = 0x270a;
static const Word DBIERR_KEYFLDTYPEMISMATCH = 0x270b;
static const Word DBIERR_INVALIDMODIFYREQUEST = 0x270c;
static const Word DBIERR_NOSUCHINDEX = 0x270d;
static const Word DBIERR_INVALIDBLOBOFFSET = 0x270e;
static const Word DBIERR_INVALIDDESCNUM = 0x270f;
static const Word DBIERR_INVALIDFLDTYPE = 0x2710;
static const Word DBIERR_INVALIDFLDDESC = 0x2711;
static const Word DBIERR_INVALIDFLDXFORM = 0x2712;
static const Word DBIERR_INVALIDRECSTRUCT = 0x2713;
static const Word DBIERR_INVALIDDESC = 0x2714;
static const Word DBIERR_INVALIDINDEXSTRUCT = 0x2715;
static const Word DBIERR_INVALIDVCHKSTRUCT = 0x2716;
static const Word DBIERR_INVALIDRINTSTRUCT = 0x2717;
static const Word DBIERR_INVALIDRESTRTBLORDER = 0x2718;
static const Word DBIERR_NAMENOTUNIQUE = 0x2719;
static const Word DBIERR_INDEXNAMEREQUIRED = 0x271a;
static const Word DBIERR_INVALIDSESHANDLE = 0x271b;
static const Word DBIERR_INVALIDRESTROP = 0x271c;
static const Word DBIERR_UNKNOWNDRIVER = 0x271d;
static const Word DBIERR_UNKNOWNDB = 0x271e;
static const Word DBIERR_INVALIDPASSWORD = 0x271f;
static const Word DBIERR_NOCALLBACK = 0x2720;
static const Word DBIERR_INVALIDCALLBACKBUFLEN = 0x2721;
static const Word DBIERR_INVALIDDIR = 0x2722;
static const Word DBIERR_INVALIDXLATION = 0x2723;
static const Word DBIERR_DIFFERENTTABLES = 0x2724;
static const Word DBIERR_INVALIDBOOKMARK = 0x2725;
static const Word DBIERR_INVALIDINDEXNAME = 0x2726;
static const Word DBIERR_INVALIDIDXDESC = 0x2727;
static const Word DBIERR_NOSUCHTABLE = 0x2728;
static const Word DBIERR_USECOUNT = 0x2729;
static const Word DBIERR_INVALIDKEY = 0x272a;
static const Word DBIERR_INDEXEXISTS = 0x272b;
static const Word DBIERR_INDEXOPEN = 0x272c;
static const Word DBIERR_INVALIDBLOBLEN = 0x272d;
static const Word DBIERR_INVALIDBLOBHANDLE = 0x272e;
static const Word DBIERR_TABLEOPEN = 0x272f;
static const Word DBIERR_NEEDRESTRUCTURE = 0x2730;
static const Word DBIERR_INVALIDMODE = 0x2731;
static const Word DBIERR_CANNOTCLOSE = 0x2732;
static const Word DBIERR_ACTIVEINDEX = 0x2733;
static const Word DBIERR_INVALIDUSRPASS = 0x2734;
static const Word DBIERR_MULTILEVELCASCADE = 0x2735;
static const Word DBIERR_INVALIDFIELDNAME = 0x2736;
static const Word DBIERR_INVALIDTABLENAME = 0x2737;
static const Word DBIERR_INVALIDLINKEXPR = 0x2738;
static const Word DBIERR_NAMERESERVED = 0x2739;
static const Word DBIERR_INVALIDFILEEXTN = 0x273a;
static const Word DBIERR_INVALIDLANGDRV = 0x273b;
static const Word DBIERR_ALIASNOTOPEN = 0x273c;
static const Word DBIERR_INCOMPATRECSTRUCTS = 0x273d;
static const Word DBIERR_RESERVEDOSNAME = 0x273e;
static const Word DBIERR_DESTMUSTBEINDEXED = 0x273f;
static const Word DBIERR_INVALIDINDEXTYPE = 0x2740;
static const Word DBIERR_LANGDRVMISMATCH = 0x2741;
static const Word DBIERR_NOSUCHFILTER = 0x2742;
static const Word DBIERR_INVALIDFILTER = 0x2743;
static const Word DBIERR_INVALIDTABLECREATE = 0x2744;
static const Word DBIERR_INVALIDTABLEDELETE = 0x2745;
static const Word DBIERR_INVALIDINDEXCREATE = 0x2746;
static const Word DBIERR_INVALIDINDEXDELETE = 0x2747;
static const Word DBIERR_INVALIDTABLE = 0x2748;
static const Word DBIERR_MULTIRESULTS = 0x2749;
static const Word DBIERR_INVALIDTIME = 0x274a;
static const Word DBIERR_INVALIDDATE = 0x274b;
static const Word DBIERR_INVALIDTIMESTAMP = 0x274c;
static const Word DBIERR_DIFFERENTPATH = 0x274d;
static const Word DBIERR_MISMATCHARGS = 0x274e;
static const Word DBIERR_FUNCTIONNOTFOUND = 0x274f;
static const Word DBIERR_MUSTUSEBASEORDER = 0x2750;
static const Word DBIERR_INVALIDPROCEDURENAME = 0x2751;
static const Word DBIERR_INVALIDFLDMAP = 0x2752;
static const Shortint ERRCODE_LOCKED = 0x1;
static const Shortint ERRCODE_UNLOCKFAILED = 0x2;
static const Shortint ERRCODE_FILEBUSY = 0x3;
static const Shortint ERRCODE_DIRBUSY = 0x4;
static const Shortint ERRCODE_FILELOCKED = 0x5;
static const Shortint ERRCODE_DIRLOCKED = 0x6;
static const Shortint ERRCODE_ALREADYLOCKED = 0x7;
static const Shortint ERRCODE_NOTLOCKED = 0x8;
static const Shortint ERRCODE_LOCKTIMEOUT = 0x9;
static const Shortint ERRCODE_GROUPLOCKED = 0xa;
static const Shortint ERRCODE_LOSTTBLLOCK = 0xb;
static const Shortint ERRCODE_LOSTEXCLACCESS = 0xc;
static const Shortint ERRCODE_NEEDEXCLACCESS = 0xd;
static const Shortint ERRCODE_RECGROUPCONFLICT = 0xe;
static const Shortint ERRCODE_DEADLOCK = 0xf;
static const Shortint ERRCODE_ACTIVETRAN = 0x10;
static const Shortint ERRCODE_NOACTIVETRAN = 0x11;
static const Shortint ERRCODE_RECLOCKFAILED = 0x12;
static const Shortint ERRCODE_OPTRECLOCKFAILED = 0x13;
static const Shortint ERRCODE_OPTRECLOCKRECDEL = 0x14;
static const Shortint ERRCODE_LOCKEDRECS = 0x15;
static const Shortint ERRCODE_NEEDWRITELOCK = 0x16;
static const Shortint ERRCODE_ENLISTFAILED = 0x17;
static const Word DBIERR_LOCKED = 0x2801;
static const Word DBIERR_UNLOCKFAILED = 0x2802;
static const Word DBIERR_FILEBUSY = 0x2803;
static const Word DBIERR_DIRBUSY = 0x2804;
static const Word DBIERR_FILELOCKED = 0x2805;
static const Word DBIERR_DIRLOCKED = 0x2806;
static const Word DBIERR_ALREADYLOCKED = 0x2807;
static const Word DBIERR_NOTLOCKED = 0x2808;
static const Word DBIERR_LOCKTIMEOUT = 0x2809;
static const Word DBIERR_GROUPLOCKED = 0x280a;
static const Word DBIERR_LOSTTBLLOCK = 0x280b;
static const Word DBIERR_LOSTEXCLACCESS = 0x280c;
static const Word DBIERR_NEEDEXCLACCESS = 0x280d;
static const Word DBIERR_RECGROUPCONFLICT = 0x280e;
static const Word DBIERR_DEADLOCK = 0x280f;
static const Word DBIERR_ACTIVETRAN = 0x2810;
static const Word DBIERR_NOACTIVETRAN = 0x2811;
static const Word DBIERR_RECLOCKFAILED = 0x2812;
static const Word DBIERR_OPTRECLOCKFAILED = 0x2813;
static const Word DBIERR_OPTRECLOCKRECDEL = 0x2814;
static const Word DBIERR_ENLISTFAILED = 0x2817;
static const Shortint ERRCODE_NOTSUFFFIELDRIGHTS = 0x1;
static const Shortint ERRCODE_NOTSUFFTABLERIGHTS = 0x2;
static const Shortint ERRCODE_NOTSUFFFAMILYRIGHTS = 0x3;
static const Shortint ERRCODE_READONLYDIR = 0x4;
static const Shortint ERRCODE_READONLYDB = 0x5;
static const Shortint ERRCODE_READONLYFLD = 0x6;
static const Shortint ERRCODE_TBLENCRYPTED = 0x7;
static const Shortint ERRCODE_NOTSUFFSQLRIGHTS = 0x8;
static const Word DBIERR_NOTSUFFFIELDRIGHTS = 0x2901;
static const Word DBIERR_NOTSUFFTABLERIGHTS = 0x2902;
static const Word DBIERR_NOTSUFFFAMILYRIGHTS = 0x2903;
static const Word DBIERR_READONLYDIR = 0x2904;
static const Word DBIERR_READONLYDB = 0x2905;
static const Word DBIERR_READONLYFLD = 0x2906;
static const Word DBIERR_TBLENCRYPTED = 0x2907;
static const Word DBIERR_NOTSUFFSQLRIGHTS = 0x2908;
static const Shortint ERRCODE_NOTABLOB = 0x1;
static const Shortint ERRCODE_BLOBOPENED = 0x2;
static const Shortint ERRCODE_BLOBNOTOPENED = 0x3;
static const Shortint ERRCODE_NA = 0x4;
static const Shortint ERRCODE_NOTINDEXED = 0x5;
static const Shortint ERRCODE_NOTINITIALIZED = 0x6;
static const Shortint ERRCODE_MULTIPLEINIT = 0x7;
static const Shortint ERRCODE_NOTSAMESESSION = 0x8;
static const Shortint ERRCODE_PDXDRIVERNOTACTIVE = 0x9;
static const Shortint ERRCODE_DRIVERNOTLOADED = 0xa;
static const Shortint ERRCODE_TABLEREADONLY = 0xb;
static const Shortint ERRCODE_NOASSOCINDEX = 0xc;
static const Shortint ERRCODE_HASOPENCURSORS = 0xd;
static const Shortint ERRCODE_NOTABLESUPPORT = 0xe;
static const Shortint ERRCODE_INDEXREADONLY = 0xf;
static const Shortint ERRCODE_NOUNIQUERECS = 0x10;
static const Shortint ERRCODE_NOTCURSESSION = 0x11;
static const Shortint ERRCODE_INVALIDKEYWORD = 0x12;
static const Shortint ERRCODE_CONNECTINUSE = 0x13;
static const Shortint ERRCODE_CONNECTNOTSHARED = 0x14;
static const Word DBIERR_NOTABLOB = 0x2a01;
static const Word DBIERR_BLOBOPENED = 0x2a02;
static const Word DBIERR_BLOBNOTOPENED = 0x2a03;
static const Word DBIERR_NA = 0x2a04;
static const Word DBIERR_NOTINDEXED = 0x2a05;
static const Word DBIERR_NOTINITIALIZED = 0x2a06;
static const Word DBIERR_MULTIPLEINIT = 0x2a07;
static const Word DBIERR_NOTSAMESESSION = 0x2a08;
static const Word DBIERR_PDXDRIVERNOTACTIVE = 0x2a09;
static const Word DBIERR_DRIVERNOTLOADED = 0x2a0a;
static const Word DBIERR_TABLEREADONLY = 0x2a0b;
static const Word DBIERR_NOASSOCINDEX = 0x2a0c;
static const Word DBIERR_HASOPENCURSORS = 0x2a0d;
static const Word DBIERR_NOTABLESUPPORT = 0x2a0e;
static const Word DBIERR_INDEXREADONLY = 0x2a0f;
static const Word DBIERR_NOUNIQUERECS = 0x2a10;
static const Word DBIERR_NOTCURSESSION = 0x2a11;
static const Word DBIERR_INVALIDKEYWORD = 0x2a12;
static const Word DBIERR_CONNECTINUSE = 0x2a13;
static const Word DBIERR_CONNECTNOTSHARED = 0x2a14;
static const Shortint ERRCODE_OSEINVFNC = 0x1;
static const Shortint ERRCODE_OSENOENT = 0x2;
static const Shortint ERRCODE_OSENOPATH = 0x3;
static const Shortint ERRCODE_OSEMFILE = 0x4;
static const Shortint ERRCODE_OSEACCES = 0x5;
static const Shortint ERRCODE_OSEBADF = 0x6;
static const Shortint ERRCODE_OSECONTR = 0x7;
static const Shortint ERRCODE_OSENOMEM = 0x8;
static const Shortint ERRCODE_OSEINVMEM = 0x9;
static const Shortint ERRCODE_OSEINVENV = 0xa;
static const Shortint ERRCODE_OSEINVFMT = 0xb;
static const Shortint ERRCODE_OSEINVACC = 0xc;
static const Shortint ERRCODE_OSEINVDAT = 0xd;
static const Shortint ERRCODE_OSENODEV = 0xf;
static const Shortint ERRCODE_OSECURDIR = 0x10;
static const Shortint ERRCODE_OSENOTSAM = 0x11;
static const Shortint ERRCODE_OSENMFILE = 0x12;
static const Shortint ERRCODE_OSEINVAL = 0x13;
static const Shortint ERRCODE_OSE2BIG = 0x14;
static const Shortint ERRCODE_OSENOEXEC = 0x15;
static const Shortint ERRCODE_OSEXDEV = 0x16;
static const Shortint ERRCODE_OSEDOM = 0x21;
static const Shortint ERRCODE_OSERANGE = 0x22;
static const Shortint ERRCODE_OSEEXIST = 0x23;
static const Shortint ERRCODE_OSUNKNOWN = 0x27;
static const Shortint ERRCODE_OSSHAREVIOL = 0x32;
static const Shortint ERRCODE_OSLOCKVIOL = 0x33;
static const Shortint ERRCODE_OSINT24FAIL = 0x34;
static const Shortint ERRCODE_OSDRIVENOTREADY = 0x35;
static const Shortint ERRCODE_NOTEXACT = 0x64;
static const Shortint ERRCODE_OSNETERR = 0x65;
static const Shortint ERRCODE_OSUNKNOWNSRVERR = 0x66;
static const Shortint ERRCODE_SERVERNOMEMORY = 0x67;
static const Shortint ERRCODE_OSALREADYLOCKED = 0x68;
static const Shortint ERRCODE_OSNOTLOCKED = 0x69;
static const Shortint ERRCODE_NOSERVERSW = 0x6a;
static const Word DBIERR_OSEINVFNC = 0x2b01;
static const Word DBIERR_OSENOENT = 0x2b02;
static const Word DBIERR_OSENOPATH = 0x2b03;
static const Word DBIERR_OSEMFILE = 0x2b04;
static const Word DBIERR_OSEACCES = 0x2b05;
static const Word DBIERR_OSEBADF = 0x2b06;
static const Word DBIERR_OSECONTR = 0x2b07;
static const Word DBIERR_OSENOMEM = 0x2b08;
static const Word DBIERR_OSEINVMEM = 0x2b09;
static const Word DBIERR_OSEINVENV = 0x2b0a;
static const Word DBIERR_OSEINVFMT = 0x2b0b;
static const Word DBIERR_OSEINVACC = 0x2b0c;
static const Word DBIERR_OSEINVDAT = 0x2b0d;
static const Word DBIERR_OSENODEV = 0x2b0f;
static const Word DBIERR_OSECURDIR = 0x2b10;
static const Word DBIERR_OSENOTSAM = 0x2b11;
static const Word DBIERR_OSENMFILE = 0x2b12;
static const Word DBIERR_OSEINVAL = 0x2b13;
static const Word DBIERR_OSE2BIG = 0x2b14;
static const Word DBIERR_OSENOEXEC = 0x2b15;
static const Word DBIERR_OSEXDEV = 0x2b16;
static const Word DBIERR_OSEDOM = 0x2b21;
static const Word DBIERR_OSERANGE = 0x2b22;
static const Word DBIERR_OSEEXIST = 0x2b23;
static const Word DBIERR_OSUNKNOWN = 0x2b27;
static const Word DBIERR_OSSHAREVIOL = 0x2b32;
static const Word DBIERR_OSLOCKVIOL = 0x2b33;
static const Word DBIERR_OSNETERR = 0x2b65;
static const Word DBIERR_OSINT24FAIL = 0x2b34;
static const Word DBIERR_OSDRIVENOTREADY = 0x2b35;
static const Word DBIERR_NOTEXACT = 0x2b64;
static const Word DBIERR_OSUNKNOWNSRVERR = 0x2b66;
static const Word DBIERR_SERVERNOMEMORY = 0x2b67;
static const Word DBIERR_OSALREADYLOCKED = 0x2b68;
static const Word DBIERR_OSNOTLOCKED = 0x2b69;
static const Word DBIERR_NOSERVERSW = 0x2b6a;
static const Shortint ERRCODE_NETINITERR = 0x1;
static const Shortint ERRCODE_NETUSERLIMIT = 0x2;
static const Shortint ERRCODE_NETFILEVERSION = 0x3;
static const Shortint ERRCODE_NETFILELOCKED = 0x4;
static const Shortint ERRCODE_DIRNOTPRIVATE = 0x5;
static const Shortint ERRCODE_NETMULTIPLE = 0x6;
static const Shortint ERRCODE_NETUNKNOWN = 0x7;
static const Shortint ERRCODE_SHAREDFILE = 0x8;
static const Shortint ERRCODE_SHARENOTLOADED = 0x9;
static const Shortint ERRCODE_NOTONANETWORK = 0xa;
static const Shortint ERRCODE_SQLCOMMLOST = 0xb;
static const Shortint ERRCODE_SERVERCOMMLOST = 0xc;
static const Shortint ERRCODE_SQLSERVERNOTFOUND = 0xd;
static const Shortint ERRCODE_SERVERNOTFOUND = 0xe;
static const Word DBIERR_NETINITERR = 0x2c01;
static const Word DBIERR_NETUSERLIMIT = 0x2c02;
static const Word DBIERR_NETFILEVERSION = 0x2c03;
static const Word DBIERR_NETFILELOCKED = 0x2c04;
static const Word DBIERR_DIRNOTPRIVATE = 0x2c05;
static const Word DBIERR_NETMULTIPLE = 0x2c06;
static const Word DBIERR_NETUNKNOWN = 0x2c07;
static const Word DBIERR_SHAREDFILE = 0x2c08;
static const Word DBIERR_SHARENOTLOADED = 0x2c09;
static const Word DBIERR_NOTONANETWORK = 0x2c0a;
static const Word DBIERR_SQLCOMMLOST = 0x2c0b;
static const Word DBIERR_SERVERCOMMLOST = 0x2c0c;
static const Word DBIERR_SQLSERVERNOTFOUND = 0x2c0d;
static const Word DBIERR_SERVERNOTFOUND = 0x2c0e;
static const Shortint ERRCODE_WRONGDRVNAME = 0x1;
static const Shortint ERRCODE_WRONGSYSVER = 0x2;
static const Shortint ERRCODE_WRONGDRVVER = 0x3;
static const Shortint ERRCODE_WRONGDRVTYPE = 0x4;
static const Shortint ERRCODE_CANNOTLOADDRV = 0x5;
static const Shortint ERRCODE_CANNOTLOADLDDRV = 0x6;
static const Shortint ERRCODE_VENDINITFAIL = 0x7;
static const Shortint ERRCODE_DRIVERRESTRICTED = 0x8;
static const Word DBIERR_WRONGDRVNAME = 0x3e01;
static const Word DBIERR_WRONGSYSVER = 0x3e02;
static const Word DBIERR_WRONGDRVVER = 0x3e03;
static const Word DBIERR_WRONGDRVTYPE = 0x3e04;
static const Word DBIERR_CANNOTLOADDRV = 0x3e05;
static const Word DBIERR_CANNOTLOADLDDRV = 0x3e06;
static const Word DBIERR_VENDINITFAIL = 0x3e07;
static const Word DBIERR_DRIVERRESTRICTED = 0x3e08;
static const Shortint DBICODE_AMBJOASY = 0x1;
static const Shortint DBICODE_AMBJOSYM = 0x2;
static const Shortint DBICODE_AMBOUTEX = 0x3;
static const Shortint DBICODE_AMBOUTPR = 0x4;
static const Shortint DBICODE_AMBSYMAS = 0x5;
static const Shortint DBICODE_ASETOPER = 0x6;
static const Shortint DBICODE_AVENUMDA = 0x7;
static const Shortint DBICODE_BADEXPR1 = 0x8;
static const Shortint DBICODE_BADFLDOR = 0x9;
static const Shortint DBICODE_BADVNAME = 0xa;
static const Shortint DBICODE_BITMAPER = 0xb;
static const Shortint DBICODE_CALCBADR = 0xc;
static const Shortint DBICODE_CALCTYPE = 0xd;
static const Shortint DBICODE_CHGTO1TI = 0xe;
static const Shortint DBICODE_CHGTOCHG = 0xf;
static const Shortint DBICODE_CHGTOEXP = 0x10;
static const Shortint DBICODE_CHGTOINS = 0x11;
static const Shortint DBICODE_CHGTONEW = 0x12;
static const Shortint DBICODE_CHGTOVAL = 0x13;
static const Shortint DBICODE_CHKMRKFI = 0x14;
static const Shortint DBICODE_CHNAMBIG = 0x15;
static const Shortint DBICODE_CHUNKERR = 0x16;
static const Shortint DBICODE_COLUM255 = 0x17;
static const Shortint DBICODE_CONAFTAS = 0x18;
static const Shortint DBICODE_DEL1TIME = 0x19;
static const Shortint DBICODE_DELAMBIG = 0x1a;
static const Shortint DBICODE_DELFRDEL = 0x1b;
static const Shortint DBICODE_EGFLDTYP = 0x1c;
static const Shortint DBICODE_EXAMINOR = 0x1d;
static const Shortint DBICODE_EXPRTYPS = 0x1e;
static const Shortint DBICODE_EXTRACOM = 0x1f;
static const Shortint DBICODE_EXTRAORO = 0x20;
static const Shortint DBICODE_EXTRAQRO = 0x21;
static const Shortint DBICODE_FIND1ATT = 0x22;
static const Shortint DBICODE_FINDANST = 0x23;
static const Shortint DBICODE_GRPNOSET = 0x24;
static const Shortint DBICODE_GRPSTROW = 0x25;
static const Shortint DBICODE_IDFINLCO = 0x26;
static const Shortint DBICODE_IDFPERLI = 0x27;
static const Shortint DBICODE_INANEXPR = 0x28;
static const Shortint DBICODE_INS1TIME = 0x29;
static const Shortint DBICODE_INSAMBIG = 0x2a;
static const Shortint DBICODE_INSDELCH = 0x2b;
static const Shortint DBICODE_INSEXPRR = 0x2c;
static const Shortint DBICODE_INSTOINS = 0x2d;
static const Shortint DBICODE_ISARRAY = 0x2e;
static const Shortint DBICODE_LABELERR = 0x2f;
static const Shortint DBICODE_LINKCALC = 0x30;
static const Shortint DBICODE_LNGVNAME = 0x31;
static const Shortint DBICODE_LONGQURY = 0x32;
static const Shortint DBICODE_MEMVPROC = 0x33;
static const Shortint DBICODE_MISNGCOM = 0x34;
static const Shortint DBICODE_MISNGRPA = 0x35;
static const Shortint DBICODE_MISSRTQU = 0x36;
static const Shortint DBICODE_NAMTWICE = 0x37;
static const Shortint DBICODE_NOCHKMAR = 0x38;
static const Shortint DBICODE_NODEFOCC = 0x39;
static const Shortint DBICODE_NOGROUPS = 0x3a;
static const Shortint DBICODE_NONSENSE = 0x3b;
static const Shortint DBICODE_NOPATTER = 0x3c;
static const Shortint DBICODE_NOSUCHDA = 0x3d;
static const Shortint DBICODE_NOVALUE = 0x3e;
static const Shortint DBICODE_ONLYCONS = 0x3f;
static const Shortint DBICODE_ONLYSETR = 0x40;
static const Shortint DBICODE_OUTSENS1 = 0x41;
static const Shortint DBICODE_OUTTWIC1 = 0x42;
static const Shortint DBICODE_PAROWCNT = 0x43;
static const Shortint DBICODE_PERSEPAR = 0x44;
static const Shortint DBICODE_PROCPLSW = 0x45;
static const Shortint DBICODE_PWINSRTS = 0x46;
static const Shortint DBICODE_PWMODRTS = 0x47;
static const Shortint DBICODE_QBEFLDFOUND = 0x48;
static const Shortint DBICODE_QBENOFENCE = 0x49;
static const Shortint DBICODE_QBENOFENCET = 0x4a;
static const Shortint DBICODE_QBENOHEADERT = 0x4b;
static const Shortint DBICODE_QBENOTAB = 0x4c;
static const Shortint DBICODE_QBENUMCOLS = 0x4d;
static const Shortint DBICODE_QBEOPENTAB = 0x4e;
static const Shortint DBICODE_QBETWICE = 0x4f;
static const Shortint DBICODE_QRYNOANSWER = 0x50;
static const Shortint DBICODE_QRYNOTPREP = 0x51;
static const Shortint DBICODE_QUAINDEL = 0x52;
static const Shortint DBICODE_QUAININS = 0x53;
static const Shortint DBICODE_RAGININS = 0x54;
static const Shortint DBICODE_RAGINSET = 0x55;
static const Shortint DBICODE_ROWUSERR = 0x56;
static const Shortint DBICODE_SETEXPEC = 0x57;
static const Shortint DBICODE_SETVAMB1 = 0x58;
static const Shortint DBICODE_SETVBAD1 = 0x59;
static const Shortint DBICODE_SETVDEF1 = 0x5a;
static const Shortint DBICODE_SUMNUMBE = 0x5b;
static const Shortint DBICODE_TBLISWP3 = 0x5c;
static const Shortint DBICODE_TOKENNOT = 0x5d;
static const Shortint DBICODE_TWOOUTR1 = 0x5e;
static const Shortint DBICODE_TYPEMISM = 0x5f;
static const Shortint DBICODE_UNRELQ1 = 0x60;
static const Shortint DBICODE_UNUSEDST = 0x61;
static const Shortint DBICODE_USEINSDE = 0x62;
static const Shortint DBICODE_USEOFCHG = 0x63;
static const Shortint DBICODE_VARMUSTF = 0x64;
static const Shortint DBICODE_REGISTER = 0x65;
static const Shortint DBICODE_LONGEXPR = 0x66;
static const Shortint DBICODE_REFRESH = 0x67;
static const Shortint DBICODE_CANCEXCEPT = 0x68;
static const Shortint DBICODE_DBEXCEPT = 0x69;
static const Shortint DBICODE_MEMEXCEPT = 0x6a;
static const Shortint DBICODE_FATALEXCEPT = 0x6b;
static const Shortint DBICODE_QRYNIY = 0x6c;
static const Shortint DBICODE_BADFORMAT = 0x6d;
static const Shortint DBICODE_QRYEMPTY = 0x6e;
static const Shortint DBICODE_NOQRYTOPREP = 0x6f;
static const Shortint DBICODE_BUFFTOOSMALL = 0x70;
static const Shortint DBICODE_QRYNOTPARSE = 0x71;
static const Shortint DBICODE_NOTHANDLE = 0x72;
static const Shortint DBICODE_QRYSYNTERR = 0x73;
static const Shortint DBICODE_QXFLDCOUNT = 0x74;
static const Shortint DBICODE_QXFLDSYMNOTFOUND = 0x75;
static const Shortint DBICODE_QXTBLSYMNOTFOUND = 0x76;
static const Shortint DBICODE_BLOBTERM = 0x77;
static const Shortint DBICODE_BLOBERR = 0x78;
static const Shortint DBICODE_RESTARTQRY = 0x79;
static const Shortint DBICODE_UNKNOWNANSTYPE = 0x7a;
static const Shortint DBICODE_SQLG_MDIST = 0x7b;
static const Shortint DBICODE_SQLG_NOARI = 0x7c;
static const Shortint DBICODE_SQLG_LIKEN = 0x7d;
static const Shortint DBICODE_SQLG_ALPHO = 0x7e;
static const Shortint DBICODE_SQLG_DATEO = 0x7f;
static const Byte DBICODE_SQLG_RELOP = 0x80;
static const Byte DBICODE_SQLG_ONLYC = 0x81;
static const Byte DBICODE_SQLG_CNTLN = 0x82;
static const Byte DBICODE_SQLG_CHINI = 0x83;
static const Byte DBICODE_SQLG_UNION = 0x84;
static const Byte DBICODE_SQLG_SLFIN = 0x85;
static const Byte DBICODE_SQLG_OTJVR = 0x86;
static const Byte DBICODE_SQLG_STROW = 0x87;
static const Byte DBICODE_SQLG_QUANT = 0x88;
static const Byte DBICODE_SQLG_REGSO = 0x89;
static const Byte DBICODE_SQLG_COUNT = 0x8a;
static const Byte DBICODE_SQLG_AVERA = 0x8b;
static const Byte DBICODE_SQLG_DATEA = 0x8c;
static const Byte DBICODE_SQLG_BADPT = 0x8d;
static const Byte DBICODE_SQLG_RELPA = 0x8e;
static const Byte DBICODE_SQLG_PATRN = 0x8f;
static const Byte DBICODE_SQLG_FNDSU = 0x90;
static const Byte DBICODE_SQLG_IFDCS = 0x91;
static const Byte DBICODE_SQLG_IDCCO = 0x92;
static const Byte DBICODE_SQLG_ONLYI = 0x93;
static const Byte DBICODE_SQLG_SQLDIALECT = 0x94;
static const Byte DBICODE_SQLG_NOQUERY = 0x95;
static const Byte DBICODE_BLOBGROUP = 0x96;
static const Byte DBICODE_QRYNOPROP = 0x97;
static const Byte DBICODE_ANSTYPNOTSUP = 0x98;
static const Byte DBICODE_ANSALIASNOTSUP = 0x99;
static const Byte DBICODE_INSBLOBREQ = 0x9a;
static const Byte DBICODE_CHGUNIQUENDXREQ = 0x9b;
static const Byte DBICODE_DELUNIQUENDXREQ = 0x9c;
static const Byte DBICODE_SQLNOFULLUPDATE = 0x9d;
static const Byte DBICODE_CANTEXECREMOTE = 0x9e;
static const Byte DBICODE_UNEXPECTEDEOC = 0x9f;
static const Byte DBICODE_SQLPARAMNOTSET = 0xa0;
static const Byte DBICODE_QUERYTOOLONG = 0xa1;
static const Byte DBICODE_NOSUCHRELORALIAS = 0xaa;
static const Byte DBICODE_TYPEAMBIGUITY = 0xab;
static const Byte DBICODE_ORDERBYNOTAPROJ = 0xac;
static const Byte DBICODE_SQLPARSE = 0xad;
static const Byte DBICODE_CONSTRAINTFAILED = 0xae;
static const Byte DBICODE_NOTGROUPINGFIELD = 0xaf;
static const Byte DBICODE_UDFNOTDEFINED = 0xb0;
static const Byte DBICODE_UDFERROR = 0xb1;
static const Byte DBICODE_SINGLEROWERROR = 0xb2;
static const Byte DBICODE_GROUPEXPR = 0xb3;
static const Byte DBICODE_QUERYTEXT = 0xb4;
static const Byte DBICODE_ANSIJOINSUP = 0xb5;
static const Byte DBICODE_DISTUNION = 0xb6;
static const Byte DBICODE_GROUPBYREQ = 0xb7;
static const Byte DBICODE_INSUPDAUTOIC = 0xb8;
static const Byte DBICODE_UPDREFINTSINGLE = 0xb9;
static const Byte DBICODE_NOMSACCESS = 0xba;
static const Byte DBICODE_FIELDCONSTPREP = 0xbb;
static const Byte DBICODE_FIELDDEFPREP = 0xbc;
static const Byte DBICODE_RECCONSTPREP = 0xbd;
static const Byte DBICODE_TOOFEWSUBEXPR = 0xbe;
static const Byte DBICODE_TOOMANYSUBEXPR = 0xbf;
static const Byte DBICODE_INVALIDNODETYPE = 0xc0;
static const Byte DBICODE_BOOLEXPR = 0xc1;
static const Byte DBICODE_NONBOOLEXPR = 0xc2;
static const Byte DBICODE_NOOUTERJOIN = 0xc3;
static const Byte DBICODE_USERCONSTRERR = 0xc4;
static const Word DBIERR_AMBJOASY = 0x2e01;
static const Word DBIERR_AMBJOSYM = 0x2e02;
static const Word DBIERR_AMBOUTEX = 0x2e03;
static const Word DBIERR_AMBOUTPR = 0x2e04;
static const Word DBIERR_AMBSYMAS = 0x2e05;
static const Word DBIERR_ASETOPER = 0x2e06;
static const Word DBIERR_AVENUMDA = 0x2e07;
static const Word DBIERR_BADEXPR1 = 0x2e08;
static const Word DBIERR_BADFLDOR = 0x2e09;
static const Word DBIERR_BADVNAME = 0x2e0a;
static const Word DBIERR_BITMAPER = 0x2e0b;
static const Word DBIERR_CALCBADR = 0x2e0c;
static const Word DBIERR_CALCTYPE = 0x2e0d;
static const Word DBIERR_CHGTO1TI = 0x2e0e;
static const Word DBIERR_CHGTOCHG = 0x2e0f;
static const Word DBIERR_CHGTOEXP = 0x2e10;
static const Word DBIERR_CHGTOINS = 0x2e11;
static const Word DBIERR_CHGTONEW = 0x2e12;
static const Word DBIERR_CHGTOVAL = 0x2e13;
static const Word DBIERR_CHKMRKFI = 0x2e14;
static const Word DBIERR_CHNAMBIG = 0x2e15;
static const Word DBIERR_CHUNKERR = 0x2e16;
static const Word DBIERR_COLUM255 = 0x2e17;
static const Word DBIERR_CONAFTAS = 0x2e18;
static const Word DBIERR_DEL1TIME = 0x2e19;
static const Word DBIERR_DELAMBIG = 0x2e1a;
static const Word DBIERR_DELFRDEL = 0x2e1b;
static const Word DBIERR_EGFLDTYP = 0x2e1c;
static const Word DBIERR_EXAMINOR = 0x2e1d;
static const Word DBIERR_EXPRTYPS = 0x2e1e;
static const Word DBIERR_EXTRACOM = 0x2e1f;
static const Word DBIERR_EXTRAORO = 0x2e20;
static const Word DBIERR_EXTRAQRO = 0x2e21;
static const Word DBIERR_FIND1ATT = 0x2e22;
static const Word DBIERR_FINDANST = 0x2e23;
static const Word DBIERR_GRPNOSET = 0x2e24;
static const Word DBIERR_GRPSTROW = 0x2e25;
static const Word DBIERR_IDFINLCO = 0x2e26;
static const Word DBIERR_IDFPERLI = 0x2e27;
static const Word DBIERR_INANEXPR = 0x2e28;
static const Word DBIERR_INS1TIME = 0x2e29;
static const Word DBIERR_INSAMBIG = 0x2e2a;
static const Word DBIERR_INSDELCH = 0x2e2b;
static const Word DBIERR_INSEXPRR = 0x2e2c;
static const Word DBIERR_INSTOINS = 0x2e2d;
static const Word DBIERR_ISARRAY = 0x2e2e;
static const Word DBIERR_LABELERR = 0x2e2f;
static const Word DBIERR_LINKCALC = 0x2e30;
static const Word DBIERR_LNGVNAME = 0x2e31;
static const Word DBIERR_LONGQURY = 0x2e32;
static const Word DBIERR_MEMVPROC = 0x2e33;
static const Word DBIERR_MISNGCOM = 0x2e34;
static const Word DBIERR_MISNGRPA = 0x2e35;
static const Word DBIERR_MISSRTQU = 0x2e36;
static const Word DBIERR_NAMTWICE = 0x2e37;
static const Word DBIERR_NOCHKMAR = 0x2e38;
static const Word DBIERR_NODEFOCC = 0x2e39;
static const Word DBIERR_NOGROUPS = 0x2e3a;
static const Word DBIERR_NONSENSE = 0x2e3b;
static const Word DBIERR_NOPATTER = 0x2e3c;
static const Word DBIERR_NOSUCHDA = 0x2e3d;
static const Word DBIERR_NOVALUE = 0x2e3e;
static const Word DBIERR_ONLYCONS = 0x2e3f;
static const Word DBIERR_ONLYSETR = 0x2e40;
static const Word DBIERR_OUTSENS1 = 0x2e41;
static const Word DBIERR_OUTTWIC1 = 0x2e42;
static const Word DBIERR_PAROWCNT = 0x2e43;
static const Word DBIERR_PERSEPAR = 0x2e44;
static const Word DBIERR_PROCPLSW = 0x2e45;
static const Word DBIERR_PWINSRTS = 0x2e46;
static const Word DBIERR_PWMODRTS = 0x2e47;
static const Word DBIERR_QBEFLDFOUND = 0x2e48;
static const Word DBIERR_QBENOFENCE = 0x2e49;
static const Word DBIERR_QBENOFENCET = 0x2e4a;
static const Word DBIERR_QBENOHEADERT = 0x2e4b;
static const Word DBIERR_QBENOTAB = 0x2e4c;
static const Word DBIERR_QBENUMCOLS = 0x2e4d;
static const Word DBIERR_QBEOPENTAB = 0x2e4e;
static const Word DBIERR_QBETWICE = 0x2e4f;
static const Word DBIERR_QRYNOANSWER = 0x2e50;
static const Word DBIERR_QRYNOTPREP = 0x2e51;
static const Word DBIERR_QUAINDEL = 0x2e52;
static const Word DBIERR_QUAININS = 0x2e53;
static const Word DBIERR_RAGININS = 0x2e54;
static const Word DBIERR_RAGINSET = 0x2e55;
static const Word DBIERR_ROWUSERR = 0x2e56;
static const Word DBIERR_SETEXPEC = 0x2e57;
static const Word DBIERR_SETVAMB1 = 0x2e58;
static const Word DBIERR_SETVBAD1 = 0x2e59;
static const Word DBIERR_SETVDEF1 = 0x2e5a;
static const Word DBIERR_SUMNUMBE = 0x2e5b;
static const Word DBIERR_TBLISWP3 = 0x2e5c;
static const Word DBIERR_TOKENNOT = 0x2e5d;
static const Word DBIERR_TWOOUTR1 = 0x2e5e;
static const Word DBIERR_TYPEMISM = 0x2e5f;
static const Word DBIERR_UNRELQ1 = 0x2e60;
static const Word DBIERR_UNUSEDST = 0x2e61;
static const Word DBIERR_USEINSDE = 0x2e62;
static const Word DBIERR_USEOFCHG = 0x2e63;
static const Word DBIERR_VARMUSTF = 0x2e64;
static const Word DBIERR_REGISTER = 0x2e65;
static const Word DBIERR_LONGEXPR = 0x2e66;
static const Word DBIERR_REFRESH = 0x2e67;
static const Word DBIERR_CANCEXCEPT = 0x2e68;
static const Word DBIERR_DBEXCEPT = 0x2e69;
static const Word DBIERR_MEMEXCEPT = 0x2e6a;
static const Word DBIERR_FATALEXCEPT = 0x2e6b;
static const Word DBIERR_QRYNIY = 0x2e6c;
static const Word DBIERR_BADFORMAT = 0x2e6d;
static const Word DBIERR_QRYEMPTY = 0x2e6e;
static const Word DBIERR_NOQRYTOPREP = 0x2e6f;
static const Word DBIERR_BUFFTOOSMALL = 0x2e70;
static const Word DBIERR_QRYNOTPARSE = 0x2e71;
static const Word DBIERR_NOTHANDLE = 0x2e72;
static const Word DBIERR_QRYSYNTERR = 0x2e73;
static const Word DBIERR_QXFLDCOUNT = 0x2e74;
static const Word DBIERR_QXFLDSYMNOTFOUND = 0x2e75;
static const Word DBIERR_QXTBLSYMNOTFOUND = 0x2e76;
static const Word DBIERR_BLOBTERM = 0x2e77;
static const Word DBIERR_BLOBERR = 0x2e78;
static const Word DBIERR_RESTARTQRY = 0x2e79;
static const Word DBIERR_UNKNOWNANSTYPE = 0x2e7a;
static const Word DBIERR_SQLG_MDIST = 0x2e7b;
static const Word DBIERR_SQLG_NOARI = 0x2e7c;
static const Word DBIERR_SQLG_LIKEN = 0x2e7d;
static const Word DBIERR_SQLG_ALPHO = 0x2e7e;
static const Word DBIERR_SQLG_DATEO = 0x2e7f;
static const Word DBIERR_SQLG_RELOP = 0x2e80;
static const Word DBIERR_SQLG_ONLYC = 0x2e81;
static const Word DBIERR_SQLG_CNTLN = 0x2e82;
static const Word DBIERR_SQLG_CHINI = 0x2e83;
static const Word DBIERR_SQLG_UNION = 0x2e84;
static const Word DBIERR_SQLG_SLFIN = 0x2e85;
static const Word DBIERR_SQLG_OTJVR = 0x2e86;
static const Word DBIERR_SQLG_STROW = 0x2e87;
static const Word DBIERR_SQLG_QUANT = 0x2e88;
static const Word DBIERR_SQLG_REGSO = 0x2e89;
static const Word DBIERR_SQLG_COUNT = 0x2e8a;
static const Word DBIERR_SQLG_AVERA = 0x2e8b;
static const Word DBIERR_SQLG_DATEA = 0x2e8c;
static const Word DBIERR_SQLG_BADPT = 0x2e8d;
static const Word DBIERR_SQLG_RELPA = 0x2e8e;
static const Word DBIERR_SQLG_PATRN = 0x2e8f;
static const Word DBIERR_SQLG_FNDSU = 0x2e90;
static const Word DBIERR_SQLG_IFDCS = 0x2e91;
static const Word DBIERR_SQLG_IDCCO = 0x2e92;
static const Word DBIERR_SQLG_ONLYI = 0x2e93;
static const Word DBIERR_SQLG_SQLDIALECT = 0x2e94;
static const Word DBIERR_SQLG_NOQUERY = 0x2e95;
static const Word DBIERR_BLOBGROUP = 0x2e96;
static const Word DBIERR_QRYNOPROP = 0x2e97;
static const Word DBIERR_ANSTYPNOTSUP = 0x2e98;
static const Word DBIERR_ANSALIASNOTSUP = 0x2e99;
static const Word DBIERR_INSBLOBREQ = 0x2e9a;
static const Word DBIERR_CHGUNIQUENDXREQ = 0x2e9b;
static const Word DBIERR_DELUNIQUENDXREQ = 0x2e9c;
static const Word DBIERR_SQLNOFULLUPDATE = 0x2e9d;
static const Word DBIERR_CANTEXECREMOTE = 0x2e9e;
static const Word DBIERR_UNEXPECTEDEOC = 0x2e9f;
static const Word DBIERR_SQLPARAMNOTSET = 0x2ea0;
static const Word DBIERR_QUERYTOOLONG = 0x2ea1;
static const Word DBIERR_NOSUCHRELORALIAS = 0x2eaa;
static const Word DBIERR_TYPEAMBIGUITY = 0x2eab;
static const Word DBIERR_ORDERBYNOTAPROJ = 0x2eac;
static const Word DBIERR_SQLPARSE = 0x2ead;
static const Word DBIERR_CONSTRAINTFAILED = 0x2eae;
static const Word DBIERR_NOTGROUPINGFIELD = 0x2eaf;
static const Word DBIERR_UDFNOTDEFINED = 0x2eb0;
static const Word DBIERR_UDFERROR = 0x2eb1;
static const Word DBIERR_SINGLEROWERROR = 0x2eb2;
static const Word DBIERR_GROUPEXPR = 0x2eb3;
static const Word DBIERR_QUERYTEXT = 0x2eb4;
static const Word DBIERR_ANSIJOINSUP = 0x2eb5;
static const Word DBIERR_DISTUNION = 0x2eb6;
static const Word DBIERR_GROUPBYREQ = 0x2eb7;
static const Word DBIERR_INSUPDAUTOINC = 0x2eb8;
static const Word DBIERR_UPDREFINTSINGLE = 0x2eb9;
static const Word DBIERR_NOMSACCESS = 0x2eba;
static const Word DBIERR_FIELDCONSTPREP = 0x2ebb;
static const Word DBIERR_FIELDDEFPREP = 0x2ebc;
static const Word DBIERR_RECCONSTPREP = 0x2ebd;
static const Word DBIERR_TOOFEWSUBEXPR = 0x2ebe;
static const Word DBIERR_TOOMANYSUBEXPR = 0x2ebf;
static const Word DBIERR_INVALIDNODETYPE = 0x2ec0;
static const Word DBIERR_BOOLEXPR = 0x2ec1;
static const Word DBIERR_NONBOOLEXPR = 0x2ec2;
static const Word DBIERR_NOOUTERJOIN = 0x2ec3;
static const Word DBIERR_USERCONSTRERR = 0x2ec4;
static const Shortint ERRCODE_INTERFACEVER = 0x1;
static const Shortint ERRCODE_INDEXOUTOFDATE = 0x2;
static const Shortint ERRCODE_OLDVERSION = 0x3;
static const Shortint ERRCODE_VALFILEINVALID = 0x4;
static const Shortint ERRCODE_BLOBVERSION = 0x5;
static const Shortint ERRCODE_ENGQRYMISMATCH = 0x6;
static const Shortint ERRCODE_SERVERVERSION = 0x7;
static const Shortint ERRCODE_TABLELEVEL = 0x8;
static const Word DBIERR_INTERFACEVER = 0x2f01;
static const Word DBIERR_INDEXOUTOFDATE = 0x2f02;
static const Word DBIERR_OLDVERSION = 0x2f03;
static const Word DBIERR_VALFILEINVALID = 0x2f04;
static const Word DBIERR_BLOBVERSION = 0x2f05;
static const Word DBIERR_ENGQRYMISMATCH = 0x2f06;
static const Word DBIERR_SERVERVERSION = 0x2f07;
static const Word DBIERR_TABLELEVEL = 0x2f08;
static const Shortint ERRCODE_NOTSUPPORTED = 0x1;
static const Shortint ERRCODE_NIY = 0x2;
static const Shortint ERRCODE_TABLESQL = 0x3;
static const Shortint ERRCODE_SEARCHCOLREQD = 0x4;
static const Shortint ERRCODE_NOMULTCONNECT = 0x5;
static const Shortint ERRCODE_NODBASEEXPR = 0x6;
static const Shortint ERRCODE_NONESTEDTRAN = 0x7;
static const Word DBIERR_NOTSUPPORTED = 0x3001;
static const Word DBIERR_NIY = 0x3002;
static const Word DBIERR_TABLESQL = 0x3003;
static const Word DBIERR_SEARCHCOLREQD = 0x3004;
static const Word DBIERR_NOMULTCONNECT = 0x3005;
static const Word DBIERR_NODBASEEXPR = 0x3006;
static const Word DBIERR_NONESTEDTRAN = 0x3007;
static const Shortint ERRCODE_INVALIDDBSPEC = 0x1;
static const Shortint ERRCODE_UNKNOWNDBTYPE = 0x2;
static const Shortint ERRCODE_INVALIDSYSDATA = 0x3;
static const Shortint ERRCODE_UNKNOWNNETTYPE = 0x4;
static const Shortint ERRCODE_NOTONTHATNET = 0x5;
static const Shortint ERRCODE_INVALIDCFGPARAM = 0x6;
static const Word DBIERR_INVALIDDBSPEC = 0x3101;
static const Word DBIERR_UNKNOWNDBTYPE = 0x3102;
static const Word DBIERR_INVALIDSYSDATA = 0x3103;
static const Word DBIERR_UNKNOWNNETTYPE = 0x3104;
static const Word DBIERR_NOTONTHATNET = 0x3105;
static const Word DBIERR_INVALIDCFGPARAM = 0x3106;
static const Shortint ERRCODE_OBJIMPLICITLYDROPPED = 0x1;
static const Shortint ERRCODE_OBJMAYBETRUNCATED = 0x2;
static const Shortint ERRCODE_OBJIMPLICITLYMODIFIED = 0x3;
static const Shortint ERRCODE_VALIDATEDATA = 0x4;
static const Shortint ERRCODE_VALFIELDMODIFIED = 0x5;
static const Shortint ERRCODE_TABLELEVELCHANGED = 0x6;
static const Shortint ERRCODE_COPYLINKEDTABLES = 0x7;
static const Shortint ERRCODE_OTHERSERVERLOADED = 0x8;
static const Shortint ERRCODE_OBJIMPLICITLYTRUNCATED = 0x9;
static const Shortint ERRCODE_VCHKMAYNOTBEENFORCED = 0xa;
static const Shortint ERRCODE_MULTIPLEUNIQRECS = 0xb;
static const Shortint ERRCODE_FIELDMUSTBETRIMMED = 0xc;
static const Word DBIERR_OBJIMPLICITLYDROPPED = 0x3201;
static const Word DBIERR_OBJMAYBETRUNCATED = 0x3202;
static const Word DBIERR_OBJIMPLICITLYMODIFIED = 0x3203;
static const Word DBIERR_VALIDATEDATA = 0x3204;
static const Word DBIERR_VALFIELDMODIFIED = 0x3205;
static const Word DBIERR_TABLELEVELCHANGED = 0x3206;
static const Word DBIERR_COPYLINKEDTABLES = 0x3207;
static const Word DBIERR_OTHERSERVERLOADED = 0x3208;
static const Word DBIERR_OBJIMPLICITLYTRUNCATED = 0x3209;
static const Word DBIERR_VCHKMAYNOTBEENFORCED = 0x320a;
static const Word DBIERR_MULTIPLEUNIQRECS = 0x320b;
static const Word DBIERR_FIELDMUSTBETRIMMED = 0x320c;
static const Shortint ERRCODE_FILEEXISTS = 0x1;
static const Shortint ERRCODE_BLOBMODIFIED = 0x2;
static const Shortint ERRCODE_UNKNOWNSQL = 0x3;
static const Shortint ERRCODE_TABLEEXISTS = 0x4;
static const Shortint ERRCODE_PDX10TABLE = 0x5;
static const Shortint ERRCODE_UPDATEABORT = 0x6;
static const Word DBIERR_FILEEXISTS = 0x3301;
static const Word DBIERR_BLOBMODIFIED = 0x3302;
static const Word DBIERR_UNKNOWNSQL = 0x3303;
static const Word DBIERR_TABLEEXISTS = 0x3304;
static const Word DBIERR_PDX10TABLE = 0x3305;
static const Word DBIERR_UPDATEABORT = 0x3306;
static const Shortint ERRCODE_DIFFSORTORDER = 0x1;
static const Shortint ERRCODE_DIRINUSEBYOLDVER = 0x2;
static const Shortint ERRCODE_PDX35LDDRIVER = 0x3;
static const Word DBIERR_DIFFSORTORDER = 0x3401;
static const Word DBIERR_DIRINUSEBYOLDVER = 0x3402;
static const Word DBIERR_PDX35LDDRIVER = 0x3403;
static const Shortint ERRCODE_REQOPTPARAM = 0x1;
static const Shortint ERRCODE_INVALIDOPTPARAM = 0x2;
static const Word DBIERR_REQOPTPARAM = 0x2d01;
static const Word DBIERR_INVALIDOPTPARAM = 0x2d02;
static const Shortint ERRCODE_REPOSITORYCORRUPT = 0x1;
static const Shortint ERRCODE_INFOBLOBCORRUPT = 0x2;
static const Shortint ERRCODE_SCHEMACORRUPT = 0x3;
static const Shortint ERRCODE_ATTRTYPEEXISTS = 0x4;
static const Shortint ERRCODE_INVALIDOBJTYPE = 0x5;
static const Shortint ERRCODE_INVALIDRELATIONTYPE = 0x6;
static const Shortint ERRCODE_VIEWEXISTS = 0x7;
static const Shortint ERRCODE_NOSUCHVIEW = 0x8;
static const Shortint ERRCODE_INVALIDRECCONSTRAINT = 0x9;
static const Shortint ERRCODE_LDBCONNECTION = 0xa;
static const Shortint ERRCODE_REPOSITORYEXISTS = 0xb;
static const Shortint ERRCODE_NOSUCHREPOSITORY = 0xc;
static const Shortint ERRCODE_REPOSITORYDBMISSING = 0xd;
static const Shortint ERRCODE_REPOSITORYOUTOFDATE = 0xe;
static const Shortint ERRCODE_REPOSITORYVERSION = 0xf;
static const Shortint ERRCODE_REPOSITORYNAME = 0x10;
static const Shortint ERRCODE_DEPENDENTOBJECTS = 0x11;
static const Shortint ERRCODE_RELATIONLIMIT = 0x12;
static const Shortint ERRCODE_RELATIONSHIPSEXIST = 0x13;
static const Shortint ERRCODE_EXCHANGEFILECORRUPT = 0x14;
static const Shortint ERRCODE_EXCHANGEFILEVERSION = 0x15;
static const Shortint ERRCODE_TYPEMISMATCH = 0x16;
static const Shortint ERRCODE_OBJECTEXISTS = 0x17;
static const Shortint ERRCODE_REPOSITORYACCESS = 0x18;
static const Shortint ERRCODE_REPOSITORYCREATE = 0x19;
static const Shortint ERRCODE_DATABASEOPENFAILED = 0x1a;
static const Word DBIERR_REPOSITORYCORRUPT = 0x3501;
static const Word DBIERR_INFOBLOBCORRUPT = 0x3502;
static const Word DBIERR_SCHEMACORRUPT = 0x3503;
static const Word DBIERR_ATTRTYPEEXISTS = 0x3504;
static const Word DBIERR_INVALIDOBJTYPE = 0x3505;
static const Word DBIERR_INVALIDRELATIONTYPE = 0x3506;
static const Word DBIERR_VIEWEXISTS = 0x3507;
static const Word DBIERR_NOSUCHVIEW = 0x3508;
static const Word DBIERR_INVALIDRECCONSTRAINT = 0x3509;
static const Word DBIERR_LDBCONNECTION = 0x350a;
static const Word DBIERR_REPOSITORYEXISTS = 0x350b;
static const Word DBIERR_NOSUCHREPOSITORY = 0x350c;
static const Word DBIERR_REPOSITORYDBMISSING = 0x350d;
static const Word DBIERR_REPOSITORYOUTOFDATE = 0x350e;
static const Word DBIERR_REPOSITORYVERSION = 0x350f;
static const Word DBIERR_REPOSITORYNAME = 0x3510;
static const Word DBIERR_DEPENDENTOBJECTS = 0x3511;
static const Word DBIERR_RELATIONLIMIT = 0x3512;
static const Word DBIERR_RELATIONSHIPSEXIST = 0x3513;
static const Word DBIERR_EXCHANGEFILECORRUPT = 0x3514;
static const Word DBIERR_EXCHANGEFILEVERSION = 0x3515;
static const Word DBIERR_TYPEMISMATCH = 0x3516;
static const Word DBIERR_OBJECTEXISTS = 0x3517;
static const Word DBIERR_REPOSITORYACCESS = 0x3518;
static const Word DBIERR_REPOSITORYCREATE = 0x3519;
static const Word DBIERR_DATABASEOPENFAILED = 0x351a;
static const Shortint MAXLDNAME = 0x14;
static const Shortint MAX_LCNAME_LEN = 0x20;
static const Shortint DOS_CP = 0x1;
static const Shortint WIN_CP = 0x2;
static const Shortint UC_CP = 0xd;
static const Shortint SCHEMATYPE = 0x1;
static const Shortint CORETYPE = 0x2;
static const Shortint LOGICALMODELTYPE = 0x4;
static const Shortint PHYSICALMODELTYPE = 0x8;
static const Shortint NONDISPLAYTYPE = 0x10;
static const Shortint INTERNALTYPE = 0x20;
static const Shortint DBIMAXENUMFLDLEN = 0x5f;
static const Shortint DOMCLOSED = 0x1;
static const Shortint NODISPLAY = 0x0;
static const Shortint SUMMARYDISPLAY = 0x1;
static const Shortint DETAILDISPLAY = 0x2;
static const Shortint INDIVIDUALDISPLAY = 0x3;
static const Shortint iCOMMONATTR = 0x1;
static const Shortint iCOMMONUSERATTR = 0x2;
static const Shortint iEXTATTR = 0x3;
static const Shortint EDITNEW = 0x1;
static const Shortint EDITUNCHANGED = 0x2;
static const Shortint EDITMODIFIED = 0x4;
static const Shortint SCHEMAATTR = 0x1;
static const Shortint EXTENDEDATTR = 0x2;
static const Shortint UIATTR = 0x4;
static const Shortint LOGICALMODELATTR = 0x8;
static const Shortint PHYSICALMODELATTR = 0x10;
static const Shortint INTERNALATTR = 0x20;
#define szOBJID "OBJID"
#define szOBJVER "VERSION"
#define szALIASNAME "ALIASNAME"
#define szREALNAME "NAME"
#define szOUTOFDATE "OUTOFDATE"
#define szCREATEDATE "CREATEDATE"
#define szLASTUPDATE "LASTUPDATE"
#define szDATABLOB "DATABLOB"
#define szDATAREP "DATAREP"
#define szVERSIONNUM "VERSIONNUM"
#define szDB "DATABASE"
#define szDBPATH "DBPATH"
#define szDBTYPE "DBTYPE"
#define szTABLE "TABLE"
#define szPATH "PATH"
#define szTBLTYPE "DRIVERTYPE"
#define szISFILE "ISFILE"
#define szISVIEW "ISVIEW"
#define szISSYNONYM "ISSYNONYM"
#define szFIELD "FIELD"
#define szPHYTYPE "PHYTYPE"
#define szPHYSUBTYPE "PHYSUBTYPE"
#define szLOGTYPE "LOGTYPE"
#define szLOGSUBTYPE "LOGSUBTYPE"
#define szUNITS1 "UNITS1"
#define szUNITS2 "UNITS2"
#define szPOSITION "POSITION"
#define szDEFVAL "DEFVAL"
#define szMINVAL "MINVAL"
#define szMAXVAL "MAXVAL"
#define szREQUIRED "REQUIRED"
#define szFREADONLY "READONLY"
#define szCASTTYPE "CASTTYPE"
#define szCASTSUBTYPE "CASTSUBTYPE"
#define szDOMCONSTRAINT "CHECK"
#define szRECCONSTR "CONSTRAINT"
#define szSQLCONSTRAINT "SQLCONSTRAINT"
#define szSRVCONSTRAINT "SRVCHECK"
#define szLOCCONSTRAINT "LOCCHECK"
#define szSRVDEFAULT "DEFAULT"
#define szUSERERROR "ERRORSTR"
#define szEXTFIELD "EXTFIELD"
#define szFIELDCLASS "FIELDCLASS"
#define szCONTROLCLASS "CONTROLCLASS"
#define szALIGNMENT "ALIGNMENT"
#define szDISPLABEL "DISPLABEL"
#define szDISPWIDTH "DISPWIDTH"
#define szVISIBLE "VISIBLE"
#define szTRANSLITERATE "TRANSLITERATE"
#define szEDITMASK "EDITMASK"
#define szDISPFORMAT "DISPFORMAT"
#define szEDITFORMAT "EDITFORMAT"
#define szCURRENCY "CURRENCY"
#define szPRECISION "PRECISION"
#define szDISPLAYVALUES "DISPLAYVALUES"
#define szBLOBTYPE "BLOBTYPE"
#define szSRCOBJID "SRCOBJID"
#define szSRCOBJVER "SRCOBJVER"
#define szDESTOBJID "DESTOBJID"
#define szDESTOBJVER "DESTOBJVER"
#define szRIPOS "IPOS"
#define szRDRDATABASE "DRDATABASES"
#define szIRDBDR "DBDR"
#define szRDREXTFIELD "DREXTFIELD"
#define szIREXTFIELDDR "EXTFIELDDR"
#define szRDBTABLES "DBTABLES"
#define szIRTABLEDB "TBLDB"
#define szRTABLEFLDS "TABLEFLDS"
#define szIRFLDTABLE "FLDTABLE"
#define szRDBVIEWS "DBVIEWS"
#define szIRVIEWDB "VIEWDB"
#define szRTABLECONSTR "TABLECONSTRS"
#define szIRCONSTRTABLE "CONSTRTABLE"
#define szTABLETRIG "TABLETRIG"
#define szTRIGTABLE "TRIGTABLE"
#define szRFLDEXTFIELD "FLDEXTFIELD"
#define szIREXTFIELDFLDS "EXTFIELDFLDS"
#define szRPARENTEXTFIELD "PARENTEXTFIELD"
#define szIRCHILDEXTFIELD "CHILDEXTFIELD"
static const unsigned clSQLRESTRICT = 0xff070002;
static const Shortint MaxDS = 0x4;
#define szMTXCONTEXTOBJ "MTS CONTEXT OBJECT"
static const Shortint OPENMODEFLAG_DIRTYREAD = 0x0;
static const Word OPENMODEFLAG_READCOMMITTED = 0x100;
static const Word OPENMODEFLAG_REPEATABLEREAD = 0x200;
extern PACKAGE Word __fastcall ErrCat(Word rslt);
extern PACKAGE Word __fastcall ErrCode(Word rslt);
extern PACKAGE Word __stdcall DbiInit(pDBIEnv pEnv);
extern PACKAGE Word __fastcall DbiDatabaseFlush(hDBIDb hDb);
extern PACKAGE Word __stdcall DbiOpenRef(hDBICur hCursor, Word iFieldNo, BOOL bReadOnly, BOOL bUniDirectional, hDBICur &hRefCursor);
extern PACKAGE Word __stdcall DbiOpenNestedTable(hDBICur hCursor, Word iFieldNo, BOOL bReadOnly, BOOL bUniDirectional, hDBICur &hCursorNested);
extern PACKAGE Word __stdcall DbiCheckSQLExpression(hDBICur hCur, char * pszExpr, char * pszFldName, EXPType expType, pfDataSourcesCallback pDsCB, int iClientData);
extern PACKAGE Word __stdcall DbiEndConstraintLayer(hDBICur &hCur);
extern PACKAGE Word __stdcall DsResolver(int iNoOfDataSources, PPacketList Packets, hDBIDb hDb, char * szDbName, char * szDbType, char * szDbPassword, PNameList pszSqlStr, PNameList ppTableName, System::PInteger piClientData, PCBList ppfReconcile, PCBList ppDsCB, int ClientData, System::PInteger piMaxErrorRecords, PPacketList pppErrPacket);
extern PACKAGE Word __stdcall DsProviderGetDataPacket(hDBICur hCur, int eProvOptions, void * pDsCB, int iClientData, System::PInteger piMaxRecords, System::PVarArray &Packet, BOOL &pbEndOfData);
extern PACKAGE Word __stdcall DbiBeginConstraintLayer(hDBIDb hDb, hDBICur &hCur, pfDataSourcesCallback pDsCb, int lUserVal);
extern PACKAGE Word __stdcall DbiSQLTextToCanEx(hDBIStmt hStmt, char * pExprText, Word iFields, pFLDDesc pFlds, EXPType exType, char * pszFldName, char * pszSourceDb, Word &piCanSize, System::PByte pCanEx);
extern PACKAGE Word __stdcall DbiImportODBC(hDBICfg hCfg, BOOL bPersist);
extern PACKAGE Word __stdcall DbiDeleteDriver(hDBICfg hCfg, char * pszDriverName, BOOL bSave);
extern PACKAGE Word __stdcall DbiAddDriver(hDBICfg hCfg, char * pszDriverName, char * pszParams, BOOL bPersist);
extern PACKAGE Word __stdcall DbiSchemaCacheFlush(hDBIDb hDb, char * pszTableName);
extern PACKAGE Word __stdcall DbiDRDrop(char * pszDrName);
extern PACKAGE Word __stdcall DbiDRAdd(pDRDesc pdrdesc);
extern PACKAGE Word __stdcall DbiDRGetRelatedObject(hDBIDR hDataRepos, pDRObject pdrObjIDSrc, char * pszRelTypeName, pDRObject pdrObjIDDest);
extern PACKAGE Word __stdcall DbiOpenSessionRepository(hDBISes hSes, hDBIDR &hDataRepos);
extern PACKAGE Word __stdcall DbiGetDefaultRepository(char * pszDRName);
extern PACKAGE Word __stdcall DbiSetDefaultRepository(char * pszDRName);
extern PACKAGE Word __stdcall DbiOpenRepositoryList(hDBICur &hCur);
extern PACKAGE Word __stdcall DbiDRGetEnumAttrDomain(hDBIDR hDataRepos, Word iNumVals, pDREnumAttrDomain peAttrDomain);
extern PACKAGE Word __stdcall DbiDRDeleteEnumAttrDomain(hDBIDR hDataRepos, char * pszEnumAttrDomain);
extern PACKAGE Word __stdcall DbiDRModifyEnumAttrDomain(hDBIDR hDataRepos, pDREnumAttrDomain peAttrDomain);
extern PACKAGE Word __stdcall DbiDRCreateEnumAttrDomain(hDBIDR hDataRepos, pDREnumAttrDomain peAttrDomain);
extern PACKAGE Word __stdcall DbiDeleteAlias(hDBICfg hCfg, char * pszAliasName);
extern PACKAGE Word __stdcall DbiAddAlias(hDBICfg hCfg, char * pszAliasName, char * pszDriverType, char * pszParams, BOOL bPersist);
extern PACKAGE Word __stdcall DbiOpenFunctionArgList(hDBIDb hDb, char * pszFuncName, Word uOverload, phDBICur phCur);
extern PACKAGE Word __stdcall DbiOpenFunctionList(hDBIDb hDb, DBIFUNCOpts eoptBits, phDBICur phCur);
extern PACKAGE Word __stdcall DbiDRDelete(char * pszDrName);
extern PACKAGE Word __stdcall DbiDRCreate(pDRDesc pdrDesc, phDBIDR phDataRepos);
extern PACKAGE Word __stdcall DbiDRLoadDBObject(hDBIDR hDataRepos, hDBIDb hDb, char * pszDatabaseName, BOOL bSystemTables, int lNumObjs, pDROBJDesc paObjDesc);
extern PACKAGE Word __stdcall DbiDRSetToObjName(hDBICur hCurObj, char * pszName, BOOL bUseAliasName);
extern PACKAGE Word __stdcall DbiDRSetToObjID(hDBICur hCurObj, pDRObject pdrObjID);
extern PACKAGE Word __stdcall DbiDRGetObjID(hDBICur hCurObj, pDRObject pdrObjID);
extern PACKAGE Word __stdcall DbiDROpenRelSet(hDBIDR hDataRepos, char * pszRelTypeName, pDRObject pdrSrcObjID, pDRObject pdrDestObjID, char * pszCondList, hDBICur &hCurObj);
extern PACKAGE Word __stdcall DbiDROpenObjSet(hDBIDR hDataRepos, char * pszObjTypeName, pDRObject pdrSrcObjID, char * pszNavRelName, char * pszCondList, hDBICur &hCurObj);
extern PACKAGE Word __stdcall DbiDRGetRelTypeInfo(hDBIDR hDataRepos, char * pszRelTypeName, pDRRELType prelType);
extern PACKAGE Word __stdcall DbiDRGetAttrDescs(hDBIDR hDataRepos, char * pszTypeName, Word iNumAttr, pDRATTRDesc pattrDesc);
extern PACKAGE Word __stdcall DbiDRGetObjTypeInfo(hDBIDR hDataRepos, char * pszObjTypeName, pDROBJType pobjType);
extern PACKAGE Word __stdcall DbiDROpenRelTypeList(hDBIDR hDataRepos, char * pszObjTypeName, hDBICur &hRelTypeCur);
extern PACKAGE Word __stdcall DbiDROpenAttrTypeList(hDBIDR hDataRepos, char * pszTypeName, hDBICur &hAttrTypeCur);
extern PACKAGE Word __stdcall DbiDROpenObjectTypeList(hDBIDR hDataRepos, hDBICur &hObjTypeCur);
extern PACKAGE Word __stdcall DbiDRDeleteObjectType(hDBIDR hDataRepos, char * pszObjTypeName, BOOL bDeleteAssocRelTypes);
extern PACKAGE Word __stdcall DbiDRDeleteRelationType(hDBIDR hDataRepos, char * pszRelTypeName);
extern PACKAGE Word __stdcall DbiDRCreateRelationType(hDBIDR hDataRepos, pDRRELType prelType, pDRATTRDesc pattrDesc);
extern PACKAGE Word __stdcall DbiDRDropAttr(hDBIDR hDataRepos, char * pszTypeName, Word iAttr, pDRATTRDesc pattrDesc);
extern PACKAGE Word __stdcall DbiDRAddAttr(hDBIDR hDataRepos, char * pszTypeName, Word iAttr, pDRATTRDesc pattrDesc);
extern PACKAGE Word __stdcall DbiDRCreateObjectType(hDBIDR hDataRepos, pDROBJType pobjType, pDRATTRDesc pattrDesc);
extern PACKAGE Word __stdcall DbiDRExportToFile(hDBIDR hDataRepos, int ulNumObjs, pDRExportDesc padrExportDesc, char * pszExportFile);
extern PACKAGE Word __stdcall DbiDRImportFromFile(hDBIDR hDataRepos, int ulNumObjs, pDRExportDesc padrExportDesc, char * pszImportFile);
extern PACKAGE Word __stdcall DbiDRClose(phDBIDR phDataRepos);
extern PACKAGE Word __stdcall DbiDROpen(char * pszDrName, phDBIDR phDataRepos);
extern PACKAGE Word __stdcall DbiDRGetDesc(char * pszDrName, pDRDesc pdrDesc);
extern PACKAGE Word __stdcall DbiApplyDelayedUpdates(hDBICur hCursor, DBIDelayedUpdCmd eUpdCmd);
extern PACKAGE Word __stdcall DbiEndDelayedUpdates(hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiBeginDelayedUpdates(hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiFreeSQLRequest(PSQLRequest pReq);
extern PACKAGE Word __stdcall DbiGetSQLRequest(hDBIDb hDb, System::PByte pszSQLStmt, bool &bIsDDL, PSQLRequest &pReq);
extern PACKAGE Word __stdcall DbiQPrepareExt(hDBIDb hDb, DBIQryLang eQryLang, char * pszQuery, Word propBits, hDBIStmt &hStmt);
extern PACKAGE Word __stdcall DbiQExecProcDirect(hDBIDb hDb, char * pszProc, Word uParamDescs, pSPParamDesc paParamDescs, void * pRecBuff, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiQSetProcParams(hDBIStmt hStmt, Word uParamDescs, pSPParamDesc paParamDescs, void * pRecBuff);
extern PACKAGE Word __stdcall DbiQPrepareProc(hDBIDb hDb, char * pszProc, Word uParamDescs, pSPParamDesc paParamDescs, void * pRecBuff, hDBIStmt &hStmt);
extern PACKAGE Word __stdcall DbiOpenSPParamList(hDBIDb hDb, char * pszSPName, BOOL bPhyTypes, Word uOverload, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiOpenSPList(hDBIDb hDb, BOOL bExtended, BOOL bSystem, char * pszQual, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiGetRintDesc(hDBICur hCursor, Word iRintSeqNo, pRINTDesc printDesc);
extern PACKAGE Word __stdcall DbiGetVchkDesc(hDBICur hCursor, Word iValSeqNo, pVCHKDesc pvalDesc);
extern PACKAGE Word __stdcall DbiOpenFieldXlt(char * pszSrcTblType, char * pszSrcLangDrv, pFLDDesc pfldSrc, char * pszDestTblType, char * pszDstLangDrv, pFLDDesc pfldDest, BOOL &bDataLoss, hDBIXlt &hXlt);
extern PACKAGE Word __stdcall DbiValidateProp(hDBIObj hObj, int iProp, BOOL bSetting);
extern PACKAGE Word __stdcall DbiCloseFieldXlt(hDBIXlt hXlt);
extern PACKAGE Word __stdcall DbiTranslateField(hDBIXlt hXlt, void * pSrc, void * pDest);
extern PACKAGE Word __stdcall DbiTranslateRecordStructure(char * pszSrcDriverType, Word iFlds, pFLDDesc pfldsSrc, char * pszDstDriverType, char * pszLangDriver, pFLDDesc pfldsDst, BOOL bCreatable);
extern PACKAGE Word __stdcall DbiGetFilterInfo(hDBICur hCur, hDBIFilter hFilter, Word iFilterId, Word iFilterSeqNo, FILTERInfo &Filterinfo);
extern PACKAGE Word __stdcall DbiGetObjFromObj(hDBIObj hObj, DBIOBJType eObjType, hDBIObj &hObjOut);
extern PACKAGE Word __stdcall DbiBcdFromFloat(double &iVal, Word iPrecision, Word iPlaces, FMTBcd &Bcd);
extern PACKAGE Word __stdcall DbiBcdToFloat(FMTBcd &Bcd, double &iVal);
extern PACKAGE Word __stdcall DbiGetObjFromName(DBIOBJType eObjType, char * pszObjName, hDBIObj &hObj);
extern PACKAGE Word __stdcall DbiSetProp(hDBIObj hObj, int iProp, int iPropValue);
extern PACKAGE Word __stdcall DbiGetProp(hDBIObj hObj, int iProp, void * PropValue, Word iMaxLen, Word &iLen);
extern PACKAGE Word __stdcall DbiAnsiToNative(void * LdObj, char * pNativeStr, char * pAnsiStr, int iLen, BOOL &bDataLoss);
extern PACKAGE Word __stdcall DbiNativeToAnsi(void * LdObj, char * pAnsiStr, char * pNativeStr, int iLen, BOOL &bDataLoss);
extern PACKAGE Word __stdcall DbiMakePermanent(hDBICur hCursor, char * pszName, BOOL bOverWrite);
extern PACKAGE Word __stdcall DbiGetIndexDescs(hDBICur hCursor, pIDXDesc idxDesc);
extern PACKAGE Word __stdcall DbiCloseConfigFile(hDBICfg &hCfg, BOOL bSave, BOOL bDefault, BOOL bSaveAs16);
extern PACKAGE Word __stdcall DbiOpenConfigFile(char * pszDirPath, BOOL bCreate, hDBICfg &hCfg);
extern PACKAGE Word __stdcall DbiOpenCfgInfoList(hDBICfg hCfg, DBIOpenMode eOpenMode, CFGMode eConfigMode, char * pszCfgPath, hDBICur &hCur);
extern PACKAGE BOOL __stdcall OsLdBuildCharSetXform(char * pCharMap, void * pLdObjSrc, void * pLdObjDest, BOOL &DataLoss);
extern PACKAGE Shortint __stdcall OsLdStrnColli(void * pBlObj, char * str1, char * str2, Word iLen);
extern PACKAGE Shortint __stdcall OsLdStrnColl(void * pLdObj, System::PByte Str1, System::PByte Str2, Word Maxlen);
extern PACKAGE Shortint __stdcall OsLdExStrCmp(void * pLdObj, System::PByte Right, Shortint RightLen, System::PByte Left, Shortint LeftLen, BOOL Exact);
extern PACKAGE Word __stdcall OsLdLoadByDriverId(Word iDriverId, void * &pLdObj);
extern PACKAGE Word __stdcall OsLdGetDriverId(void * pLdObj, Word &DriverId);
extern PACKAGE Word __stdcall OsLdGetFuncAddrLdStrnCmpi_(void * &ppf);
extern PACKAGE Word __stdcall OsLdGetFuncAddrLdStrnColl_(void * &ppf);
extern PACKAGE Word __stdcall OsLdGetFuncAddrLdStrnColli_(void * &ppf);
extern PACKAGE Word __stdcall DbiGetExactRecordCount(hDBICur hCursor, int &iRecCount);
extern PACKAGE Word __stdcall DbiGetLdNameFromDb(hDBIDb hDb, char * DbName, char * pldName);
extern PACKAGE Word __stdcall DbiSortTable(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur hSrcCur, char * pszSortedName, phDBICur phSortedCur, hDBICur hDstCur, Word iSortFields, PWORD piFieldNum, PBOOL pbCaseInsensitive, pSORTOrder pSortOrder, ppfSORTCompFn ppfSortFn, BOOL bRemoveDups, hDBICur hDuplicatesCur, int &lRecsSort);
extern PACKAGE Word __stdcall DbiGetTranInfo(hDBIDb hDb, hDBIXact hXact, pXInfo pxInfo);
extern PACKAGE Word __stdcall DbiEndTran(hDBIDb hDb, hDBIXact hXact, eXEnd eEnd);
extern PACKAGE Word __stdcall DbiBeginTran(hDBIDb hDb, eXILType eXIL, hDBIXact &hXact);
extern PACKAGE Word __stdcall DbiBatchMove(pBATTblDesc pSrcTblDesc, hDBICur hSrcCur, pBATTblDesc pDstTblDesc, hDBICur hDstCur, eBATMode ebatMode, Word iFldCount, PWORD pSrcFldMap, char * pszIndexName, char * pszIndexTagName, Word iIndexId, char * pszKeyviolName, char * pszProblemsName, char * pszChangedName, PLongint lProbRecs, PLongint lKeyvRecs, PLongint lChangedRecs, BOOL bAbortOnFirstProb, BOOL bAbortOnFirstKeyviol, int &lRecsToMove, BOOL bTransliterate);
extern PACKAGE Word __stdcall DbiDeactivateFilter(hDBICur hCursor, hDBIFilter hFilter);
extern PACKAGE Word __stdcall DbiActivateFilter(hDBICur hCursor, hDBIFilter hFilter);
extern PACKAGE Word __stdcall DbiDropFilter(hDBICur hCursor, hDBIFilter hFilter);
extern PACKAGE Word __stdcall DbiAddFilter(hDBICur hCursor, int iClientData, Word iPriority, BOOL bCanAbort, pCANExpr pcanExpr, pfGENFilter pfFilter, hDBIFilter &hFilter);
extern PACKAGE Word __stdcall DbiGetLdName(char * pszDriver, char * pObjName, char * pLdName);
extern PACKAGE Word __stdcall DbiUndeleteRecord(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiGetClientInfo(CLIENTInfo &clientInfo);
extern PACKAGE Word __fastcall OsLdSetConvChars(Shortint o2a, Shortint a2o);
extern PACKAGE Word __stdcall OsLdGetMinMax(void * pLdObj, char * pcMin, char * pcMax);
extern PACKAGE Word __stdcall OsLdGetProductID(void * pLdObj, PWORD piProdID);
extern PACKAGE Word __stdcall OsLdSearchEnd(void * SHandle);
extern PACKAGE Word __fastcall OsLdLoadByLCID(int _lcid, void * &pLdObj);
extern PACKAGE Word __stdcall OsLdSearchNext(void * SHandle, void * &ppLdObj);
extern PACKAGE Word __stdcall OsLdSearchInit(void * &SHandle);
extern PACKAGE Word __stdcall OsLdGetDescName(void * pLdObj, System::PByte pDescName);
extern PACKAGE Byte __stdcall OsLdCharToLower(void * pLdObj, Byte ch);
extern PACKAGE Byte __stdcall OsLdCharToUpper(void * pLdObj, Byte ch);
extern PACKAGE BOOL __stdcall OsLdIsDigit(void * pLdObj, Byte ch);
extern PACKAGE BOOL __stdcall OsLdIsAlpha(void * pLdObj, Byte ch);
extern PACKAGE Word __stdcall OsLdUnloadObj(void * &pLdObj);
extern PACKAGE Byte __stdcall OsLdOemCharToAnsi(void * pLdObj, Byte ch);
extern PACKAGE Byte __stdcall OsLdAnsiCharToOem(void * pLdObj, Byte ch);
extern PACKAGE BOOL __stdcall OsLdIsOemCharInAnsiCp(void * pLdObj, char OemCh);
extern PACKAGE BOOL __stdcall OsLdIsAnsiCharInOemCp(void * pLdObj, char AnsiCh);
extern PACKAGE Word __stdcall OsLdOemToAnsi(void * pLdObj, char * AnsiStr, char * OemStr, Word Len, BOOL &DataLoss);
extern PACKAGE Word __stdcall OsLdAnsiToOem(void * pLdObj, char * OemStr, char * AnsiStr, Word Len, BOOL &DataLoss);
extern PACKAGE Word __stdcall OsLdGetFName(void * pLdObj, char * PName);
extern PACKAGE Word __stdcall OsLdGetCodePage(void * pLdObj, short &CodePage);
extern PACKAGE Word __stdcall OsLdGetSortsig(void * pLdObj, short &SortSig);
extern PACKAGE Word __stdcall OsLdGetSymbName(void * pLdObj, System::PByte pSymbName);
extern PACKAGE Word __stdcall OsLdStrnToUpper(void * pLdObj, System::PByte Str, Word Len);
extern PACKAGE Word __stdcall OsLdStrToUpper(void * pLdObj, System::PByte Str);
extern PACKAGE short __stdcall OsLdStrnCmpi(void * pLdObj, char * Str1, char * Str2, Word Len);
extern PACKAGE short __stdcall OsLdStrCmpi(void * pLdObj, char * str1, char * str2);
extern PACKAGE Word __stdcall OsLdStrnToLower(void * pLdObj, System::PByte Str, Word Len);
extern PACKAGE Word __stdcall OsLdStrToLower(void * pLdObj, System::PByte Str);
extern PACKAGE Word __stdcall OsLdStrCmp(void * pLdObj, char * Str1, char * Str2);
extern PACKAGE Word __stdcall OsLdStrnCmp(void * pLdObj, char * Str1, char * Str2, Word Len);
extern PACKAGE Word __stdcall OsLdLoadBySymbName(char * pSymbName, void * &pLdObj);
extern PACKAGE Word __stdcall OsLdLoadByFName(char * pFName, void * &pLdObj);
extern PACKAGE Word __stdcall OsLdLoadBySortSig(Word SortSig, Word CodePage, void * &pLdObj);
extern PACKAGE Word __stdcall OsLdExit(void);
extern PACKAGE Word __stdcall OsLdGetDefaultObj(void * &pLdObj);
extern PACKAGE Word __stdcall OsLdInit(char * pDefDir, char * pDefLangDr);
extern PACKAGE Word __stdcall DbiDebugLayerOptions(Word iOption, char * pDebugFile);
extern PACKAGE Word __stdcall DbiSetNumberFormat(FMTNumber &fmtNumber);
extern PACKAGE Word __stdcall DbiGetNumberFormat(FMTNumber &fmtNumber);
extern PACKAGE Word __stdcall DbiSetTimeFormat(FMTTime &fmtTime);
extern PACKAGE Word __stdcall DbiGetTimeFormat(FMTTime &fmtTime);
extern PACKAGE Word __stdcall DbiSetDateFormat(FMTDate &fmtDate);
extern PACKAGE Word __stdcall DbiGetDateFormat(FMTDate &fmtDate);
extern PACKAGE Word __stdcall DbiCfgMerge(hDBICfg hCfgDest, hDBICfg hCfgSrc, char * pszSrcPath);
extern PACKAGE Word __stdcall DbiCfgGetHelp(hDBICfg hCfg, char * pszConfigPath, char * pszFldName, char * pszHelpString);
extern PACKAGE Word __stdcall DbiCfgTranslate(hDBICfg hCfg, char * pszConfigPath, char * pszTrans, Word iFields, pFLDDesc pfldDesc, void * pRec);
extern PACKAGE Word __stdcall DbiCfgDropRecord(hDBICfg hCfg, char * pszCfgPath);
extern PACKAGE Word __stdcall DbiCfgModifyRecord(hDBICfg hCfg, char * pszCfgPath, Word iFields, pFLDDesc pfldDesc, void * pRec);
extern PACKAGE Word __stdcall DbiCfgAddRecord(hDBICfg hCfg, char * pszCfgPath, Word iFields, pFLDDesc pfldDesc, void * pRec);
extern PACKAGE Word __stdcall DbiCfgGetRecord(hDBICfg hCfg, char * pszCfgPath, Word &iFields, pFLDDesc pfldDesc, void * pRec);
extern PACKAGE Word __stdcall DbiCfgGetNextNode(hDBICfg hCfg, char * pszNodeName);
extern PACKAGE Word __stdcall DbiCfgPosition(hDBICfg hCfg, char * pszCfgPath);
extern PACKAGE Word __stdcall DbiCfgBuildPath(hDBICfg hCfg, char * pszCategory, char * pszGroup, char * pszSection, char * pszCfgPath);
extern PACKAGE Word __stdcall DbiCfgSave(hDBICfg hCfg, char * pszNewFile, BOOL bSaveAs16);
extern PACKAGE Word __stdcall DbiGetCallBack(hDBICur hCursor, CBType ecbType, PLongint piClientData, PWORD piCbBufLen, void * ppCbBuf, pfDBICallBack &pfCb);
extern PACKAGE Word __stdcall DbiCheckRefresh(void);
extern PACKAGE Word __stdcall DbiGetErrorEntry(Word uEntry, int &ulNativeError, char * pszError);
extern PACKAGE Word __stdcall DbiGetErrorContext(short eContext, char * pszContext);
extern PACKAGE Word __stdcall DbiGetErrorString(Word rslt, char * pszError);
extern PACKAGE Word __stdcall DbiFormFullName(hDBIDb hDb, char * pszTableName, char * pszDriverType, char * pszFullName);
extern PACKAGE Word __stdcall DbiCreateTempTable(hDBIDb hDb, CRTblDesc &crTblDsc, hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiUseIdleTime(void);
extern PACKAGE Word __stdcall DbiGetLdObj(hDBICur hCursor, void * &pLdObj);
extern PACKAGE Word __stdcall DbiGetErrorInfo(BOOL bFull, DBIErrInfo &ErrInfo);
extern PACKAGE Word __stdcall DbiSetFieldMap(hDBICur hCur, Word iFields, pFLDDesc pFldDesc);
extern PACKAGE Word __stdcall DbiGetRecordForKey(hDBICur hCursor, BOOL bDirectKey, Word iFields, Word iLen, void * pKey, void * pRecBuff);
extern PACKAGE Word __stdcall DbiCompareKeys(hDBICur hCursor, void * pKey1, void * pKey2, Word iFields, Word iLen, short &iResult);
extern PACKAGE Word __stdcall DbiAppendRecord(hDBICur hCursor, void * pRecBuff);
extern PACKAGE Word __stdcall DbiRegenIndexes(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiRegenIndex(hDBIDb hDb, hDBICur hCursor, char * pszTableName, char * pszDriverType, char * pszIndexName, char * pszIndexTagName, Word iIndexId);
extern PACKAGE Word __stdcall DbiEmptyTable(hDBIDb hDb, hDBICur hCursor, char * pszTableName, char * pszDriverType);
extern PACKAGE Word __stdcall DbiPackTable(hDBIDb hDb, hDBICur hCursor, char * pszTableName, char * pszDriverType, BOOL bRegenIdxs);
extern PACKAGE Word __stdcall DbiTimeStampDecode(double tsTS, int &dateD, int &timeT);
extern PACKAGE Word __stdcall DbiTimeStampEncode(int dateD, int timeT, double &tsTS);
extern PACKAGE Word __stdcall DbiTimeDecode(int timeT, Word &iHour, Word &iMin, Word &iMilSec);
extern PACKAGE Word __stdcall DbiTimeEncode(Word iHour, Word iMin, Word iMilSec, int &timeT);
extern PACKAGE Word __stdcall DbiDoRestructure(hDBIDb hDb, Word iTblDescCount, pCRTblDesc pTblDesc, char * pszSaveAs, char * pszKeyviolName, char * pszProblemsName, BOOL bAnalyzeOnly);
extern PACKAGE Word __stdcall DbiSetToRecordNo(hDBICur hCursor, int iRecNo);
extern PACKAGE Word __stdcall DbiGetIndexSeqNo(hDBICur hCursor, char * pszIndexName, char * pszTagName, Word iIndexId, Word &iIndexSeqNo);
extern PACKAGE Word __stdcall DbiGetIndexForField(hDBICur hCursor, Word iFld, BOOL bProdTagOnly, IDXDesc &idxDesc);
extern PACKAGE Word __stdcall DbiDeleteIndex(hDBIDb hDb, hDBICur hCursor, char * pszTableName, char * pszDriverType, char * pszIndexName, char * pszIndexTagName, Word iIndexId);
extern PACKAGE Word __stdcall DbiAddIndex(hDBIDb hDb, hDBICur hCursor, char * pszTableName, char * pszDriverType, IDXDesc &IdxDesc, char * pszKeyviolName);
extern PACKAGE Word __stdcall DbiDeleteTable(hDBIDb hDb, char * pszTableName, char * pszDriverType);
extern PACKAGE Word __stdcall DbiRenameTable(hDBIDb hDb, char * pszOldName, char * pszDriverType, char * pszNewName);
extern PACKAGE Word __stdcall DbiCopyTable(hDBIDb hDb, BOOL bOverWrite, char * pszSrcTableName, char * pszSrcDriverType, char * pszDestTableName);
extern PACKAGE Word __stdcall DbiCreateTable(hDBIDb hDb, BOOL bOverWrite, CRTblDesc &crTblDsc);
extern PACKAGE Word __stdcall DbiVerifyField(hDBICur hCursor, Word iField, void * pSrc, BOOL &bBlank);
extern PACKAGE Word __stdcall DbiSetToSeqNo(hDBICur hCursor, int iSeqNo);
extern PACKAGE Word __stdcall DbiInitRecord(hDBICur hCursor, void * pRecBuff);
extern PACKAGE Word __stdcall DbiCloneCursor(hDBICur hCurSrc, BOOL bReadOnly, BOOL bUniDirectional, hDBICur &hCurNew);
extern PACKAGE Word __stdcall DbiCompareBookMarks(hDBICur hCur, void * pBookMark1, void * pBookMark2, int &CmpBkmkResult);
extern PACKAGE Word __stdcall DbiSetToBookMark(hDBICur hCur, void * pBookMark);
extern PACKAGE Word __stdcall DbiGetBookMark(hDBICur hCur, void * pBookMark);
extern PACKAGE Word __stdcall DbiExtractKey(hDBICur hCursor, void * pRecBuf, void * pKeyBuf);
extern PACKAGE Word __stdcall DbiGetIndexDesc(hDBICur hCursor, Word iIndexSeqNo, IDXDesc &idxDesc);
extern PACKAGE Word __stdcall DbiSwitchToIndex(hDBICur &hCursor, char * pszIndexName, char * pszTagName, Word iIndexId, BOOL bCurrRec);
extern PACKAGE Word __stdcall DbiCloseIndex(hDBICur hCursor, char * pszIndexName, Word iIndexId);
extern PACKAGE Word __stdcall DbiOpenIndex(hDBICur hCursor, char * pszIndexName, Word iIndexId);
extern PACKAGE Word __stdcall DbiDateDecode(int dateD, Word &iMon, Word &iDay, short &iYear);
extern PACKAGE Word __stdcall DbiDateEncode(Word iMon, Word iDay, short iYear, int &dateD);
extern PACKAGE Word __stdcall DbiPutField(hDBICur hCursor, Word iField, void * pRecBuff, void * pSrc);
extern PACKAGE Word __stdcall DbiGetField(hDBICur hCursor, Word iField, void * pRecBuff, void * pDest, BOOL &bBlank);
extern PACKAGE Word __stdcall DbiRegisterCallBack(hDBICur hCursor, CBType ecbType, int iClientData, Word iCbBufLen, void * CbBuf, pfDBICallBack pfCb);
extern PACKAGE Word __stdcall DbiQGetBaseDescs(hDBIStmt hStmt, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiQAlloc(hDBIDb hDb, DBIQryLang eQryLang, hDBIStmt &hStmt);
extern PACKAGE Word __stdcall DbiQFree(hDBIStmt &hStmt);
extern PACKAGE Word __stdcall DbiQInstantiateAnswer(hDBIStmt hStmt, hDBICur hCur, char * pszAnswerName, char * pszAnswerType, BOOL bOverWrite, phDBICur phCur);
extern PACKAGE Word __stdcall DbiQSetParams(hDBIStmt hStmt, Word uFldDescs, pFLDDesc paFldDescs, void * pRecBuff);
extern PACKAGE Word __stdcall DbiQExec(hDBIStmt hStmt, phDBICur phCur);
extern PACKAGE Word __stdcall DbiQPrepare(hDBIStmt hStmt, char * pszQuery);
extern PACKAGE Word __stdcall DbiQExecDirect(hDBIDb hDb, DBIQryLang eQryLang, char * pszQuery, phDBICur phCur);
extern PACKAGE Word __stdcall DbiGetNetUserName(char * pszNetUserName);
extern PACKAGE Word __stdcall DbiGetSesInfo(SESInfo &sesInfo);
extern PACKAGE Word __stdcall DbiGetSysInfo(SYSInfo &sysInfo);
extern PACKAGE Word __stdcall DbiGetSysConfig(SYSConfig &sysConfig);
extern PACKAGE Word __stdcall DbiGetSysVersion(SYSVersion &sysVersion);
extern PACKAGE Word __stdcall DbiGetBlobHeading(hDBICur hCursor, Word iField, void * pRecBuf, void * pDest);
extern PACKAGE Word __stdcall DbiFreeBlob(hDBICur hCursor, void * pRecBuf, Word iField);
extern PACKAGE Word __stdcall DbiTruncateBlob(hDBICur hCursor, void * pRecBuf, Word iField, int iLen);
extern PACKAGE Word __stdcall DbiPutBlob(hDBICur hCursor, void * pRecBuf, Word iField, int iOffSet, int iLen, void * pSrc);
extern PACKAGE Word __stdcall DbiGetBlob(hDBICur hCursor, void * pRecBuf, Word iField, int iOffSet, int iLen, void * pDest, int &iRead);
extern PACKAGE Word __stdcall DbiGetBlobSize(hDBICur hCursor, void * pRecBuf, Word iField, int &iSize);
extern PACKAGE Word __stdcall DbiOpenBlob(hDBICur hCursor, void * pRecBuf, Word iField, DBIOpenMode eOpenMode);
extern PACKAGE Word __stdcall DbiGetTableOpenCount(hDBIDb hDb, char * pszTableName, char * pszDriverType, Word &iOpenCount);
extern PACKAGE Word __stdcall DbiLoadDriver(char * pszDriverType);
extern PACKAGE Word __stdcall DbiGetIndexTypeDesc(char * pszDriverType, char * pszIndexType, IDXType &idxType);
extern PACKAGE Word __stdcall DbiOpenIndexTypesList(char * pszDriverType, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiGetFieldTypeDesc(char * pszDriverType, char * pszTableType, char * pszFieldType, FLDType &fldType);
extern PACKAGE Word __stdcall DbiOpenFieldTypesList(char * pszDriverType, char * pszTblType, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiGetTableTypeDesc(char * pszDriverType, char * pszTableType, TBLType &tblType);
extern PACKAGE Word __stdcall DbiOpenTableTypesList(char * pszDriverType, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiGetDatabaseDesc(char * pszName, pDBDesc pdbDesc);
extern PACKAGE Word __stdcall DbiOpenDatabaseList(hDBICur &hCur);
extern PACKAGE Word __stdcall DbiGetDriverDesc(char * pszDriverType, DRVType &drvType);
extern PACKAGE Word __stdcall DbiOpenDriverList(hDBICur &hCur);
extern PACKAGE Word __stdcall DbiSetLockRetry(short iWait);
extern PACKAGE Word __stdcall DbiSetPrivateDir(char * pszDir);
extern PACKAGE Word __stdcall DbiOpenLockList(hDBICur hCursor, BOOL bAllUsers, BOOL bAllLockTypes, hDBICur &hLocks);
extern PACKAGE Word __stdcall DbiOpenUserList(hDBICur &hUsers);
extern PACKAGE Word __stdcall DbiDropPassword(char * pszPassword);
extern PACKAGE Word __stdcall DbiAddPassword(char * pszPassword);
extern PACKAGE Word __stdcall DbiCloseSession(hDBISes hSes);
extern PACKAGE Word __stdcall DbiGetCurrSession(hDBISes &hSes);
extern PACKAGE Word __stdcall DbiSetCurrSession(hDBISes hSes);
extern PACKAGE Word __stdcall DbiStartSession(char * pszName, hDBISes &hSes, char * pNetDir);
extern PACKAGE Word __stdcall DbiForceRecordReread(hDBICur hCursor, void * pRecBuff);
extern PACKAGE Word __stdcall DbiGetCursorForTable(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiForceReread(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiSaveChanges(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiRelPersistTableLock(hDBIDb hDb, char * pszTableName, char * pszDriverType);
extern PACKAGE Word __stdcall DbiAcqPersistTableLock(hDBIDb hDb, char * pszTableName, char * pszDriverType);
extern PACKAGE Word __stdcall DbiRelRecordLock(hDBICur hCursor, BOOL bAll);
extern PACKAGE Word __stdcall DbiRelTableLock(hDBICur hCursor, BOOL bAll, DBILockType eLockType);
extern PACKAGE Word __stdcall DbiAcqTableLock(hDBICur hCursor, DBILockType eLockType);
extern PACKAGE Word __stdcall DbiLinkDetailToExp(hDBICur hCursorMstr, hDBICur hCursorDetl, Word iKeyLen, char * pszMstrExp);
extern PACKAGE Word __stdcall DbiIsTableShared(hDBICur hCursor, BOOL &bShared);
extern PACKAGE Word __stdcall DbiIsTableLocked(hDBICur hCursor, DBILockType epdxLock, Word &iLocks);
extern PACKAGE Word __stdcall DbiIsRecordLocked(hDBICur hCursor, BOOL &bLocked);
extern PACKAGE Word __stdcall DbiGetLinkStatus(hDBICur hCursor, hDBICur &hCursorMstr, hDBICur &hCursorDet, hDBICur &hCursorSib);
extern PACKAGE Word __stdcall DbiUnlinkDetail(hDBICur hDetlCursor);
extern PACKAGE Word __stdcall DbiLinkDetail(hDBICur hMstrCursor, hDBICur hDetlCursor, Word iLnkFields, PWORD piMstrFields, PWORD piDetlFields);
extern PACKAGE Word __stdcall DbiEndLinkMode(hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiBeginLinkMode(hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiWriteBlock(hDBICur hCursor, int &iRecords, void * pBuf);
extern PACKAGE Word __stdcall DbiReadBlock(hDBICur hCursor, int &iRecords, void * pBuf);
extern PACKAGE Word __stdcall DbiCreateInMemTable(hDBIDb hDb, char * pszName, Word iFields, pFLDDesc pfldDesc, hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiOpenSecurityList(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur &hSecCur);
extern PACKAGE Word __stdcall DbiOpenFamilyList(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur &hFmlCur);
extern PACKAGE Word __stdcall DbiOpenRintList(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur &hChkCur);
extern PACKAGE Word __stdcall DbiOpenVchkList(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur &hChkCur);
extern PACKAGE Word __stdcall DbiOpenLdList(hDBICur &hCur);
extern PACKAGE Word __stdcall DbiOpenFieldList(hDBIDb hDb, char * pszTableName, char * pszDriverType, BOOL bPhyTypes, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiOpenIndexList(hDBIDb hDb, char * pszTableName, char * pszDriverType, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiOpenFileList(hDBIDb hDb, char * pszWild, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiOpenTableList(hDBIDb hDb, BOOL bExtended, BOOL bSystem, char * pszWild, hDBICur &hCur);
extern PACKAGE Word __stdcall DbiSetDirectory(hDBIDb hDb, char * pszDir);
extern PACKAGE Word __stdcall DbiGetDirectory(hDBIDb hDb, BOOL bDefault, char * pszDir);
extern PACKAGE Word __stdcall DbiSetToKey(hDBICur hCursor, DBISearchCond eSearchCond, BOOL bDirectKey, Word iFields, Word iLen, void * pBuff);
extern PACKAGE Word __stdcall DbiResetRange(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiSetRange(hDBICur hCursor, BOOL bKeyItself, Word iFields1, Word iLen1, void * pKey1, BOOL bKey1Incl, Word iFields2, Word iLen2, void * pKey2, BOOL bKey2Incl);
extern PACKAGE Word __stdcall DbiGetSeqNo(hDBICur hCursor, int &iSeqNo);
extern PACKAGE Word __stdcall DbiDeleteRecord(hDBICur hCursor, void * pRecBuf);
extern PACKAGE Word __stdcall DbiModifyRecord(hDBICur hCursor, void * pRecBuf, BOOL bFreeLock);
extern PACKAGE Word __stdcall DbiInsertRecord(hDBICur hCursor, DBILockType eLock, void * pRecBuff);
extern PACKAGE Word __stdcall DbiGetRecordCount(hDBICur hCursor, int &iRecCount);
extern PACKAGE Word __stdcall DbiGetRelativeRecord(hDBICur hCursor, int iPosOffset, DBILockType eLock, void * pRecBuff, pRECProps precProps);
extern PACKAGE Word __stdcall DbiGetRecord(hDBICur hCursor, DBILockType eLock, void * pRecBuff, pRECProps precProps);
extern PACKAGE Word __stdcall DbiGetPriorRecord(hDBICur hCursor, DBILockType eLock, void * pRecBuff, pRECProps precProps);
extern PACKAGE Word __stdcall DbiGetNextRecord(hDBICur hCursor, DBILockType eLock, void * pRecBuff, pRECProps precProps);
extern PACKAGE Word __stdcall DbiSetToCursor(hDBICur hDest, hDBICur hSrc);
extern PACKAGE Word __stdcall DbiSetToEnd(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiSetToBegin(hDBICur hCursor);
extern PACKAGE Word __stdcall DbiCloseCursor(hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiGetFieldDescs(hDBICur hCursor, pFLDDesc pfldDesc);
extern PACKAGE Word __stdcall DbiGetCursorProps(hDBICur hCursor, CURProps &curProps);
extern PACKAGE Word __stdcall DbiOpenTable(hDBIDb hDb, char * pszTableName, char * pszDriverType, char * pszIndexName, char * pszIndexTagName, Word iIndexId, DBIOpenMode eOpenMode, DBIShareMode eShareMode, XLTMode exltMode, BOOL bUniDirectional, void * pOptParams, hDBICur &hCursor);
extern PACKAGE Word __stdcall DbiCloseDatabase(hDBIDb &hDb);
extern PACKAGE Word __stdcall DbiOpenDatabase(char * pszDbName, char * pszDbType, DBIOpenMode eOpenMode, DBIShareMode eShareMode, char * pszPassword, Word iOptFlds, pFLDDesc pOptFldDesc, void * pOptParams, hDBIDb &hDb);
extern PACKAGE Word __stdcall DbiInitFn(Word iVer, pDBIEnv pEnv);
extern PACKAGE Word __stdcall DbiExit(void);
extern PACKAGE Word __stdcall DbiDLLExit(void);

}	/* namespace Bde */
using namespace Bde;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// BDE
