// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DSIntf.pas' rev: 5.00

#ifndef DSIntfHPP
#define DSIntfHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <DBCommon.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dsintf
{
//-- type declarations -------------------------------------------------------
typedef Word DBResult;

#pragma option push -b
enum DBSearchCond { keySEARCHEQ, keySEARCHGT, keySEARCHGEQ };
#pragma option pop

typedef char MIDASNAME[32];

typedef char MIDASPATH[261];

typedef tagSAFEARRAY *TDataPacket;

typedef Byte DSAttr;

typedef DSAttr *pDSAttr;

typedef void *hDSFilter;

typedef hDSFilter *phDSFilter;

#pragma option push -b
enum GROUPSTATE { grSTATEMIDDLE, grSTATEFIRST, grSTATELAST, grSTATEFIRSTLAST };
#pragma option pop

typedef int hDSAggregate;

typedef hDSAggregate *phDSAggregate;

#pragma option push -b
enum AGGSTATE { aggSTATEUNDEF, aggSTATEOK, aggSTATEBLANK, aggSTATEERROR };
#pragma option pop

#pragma pack(push, 1)
struct DSIntf__1
{
	
} ;
#pragma pack(pop)

#pragma pack(push, 1)
struct AGGVALUE
{
	int iCnt;
	AGGSTATE eAggState;
	DSIntf__1 Value;
} ;
#pragma pack(pop)

struct DSBOOKMRK;
typedef DSBOOKMRK *pDSBOOKMRK;

#pragma pack(push, 1)
struct DSBOOKMRK
{
	int iPos;
	int iState;
	int iRecNo;
	int iSeqNo;
	int iOrderID;
} ;
#pragma pack(pop)

typedef int SAVEPOINT;

typedef SAVEPOINT *pSAVEPOINT;

typedef int DSKEY[16];

typedef BOOL DSKEYBOOL[16];

#pragma option push -b
enum DSProp { dspropLOGCHANGES, dspropREADONLY, dspropNOOFCHANGES, dspropCONSTRAINTS_DISABLED, dspropDSISPARTIAL, 
	dspropRECORDSINDS, dspropAUTOINC_DISABLED, dspropISDELTA, dspropDONTINCLMETADATA, dspropINCLBLOBSINDELTA, 
	dspropGETSAVEPOINT, dspropCOMPRESSARRAYS, dspropMD_SEMANTICS, dspropFIELD_FULLNAME, dspropFIELDID_FORNAME, 
	dspropFIELDID_FORPARENT, dspropCHANGEINDEX_VIEW, dspropGETUNIQUEINDEX, dspropREMOTE_UPDATEMODE, dspropXML_STREAMMODE 
	};
#pragma option pop

#pragma option push -b
enum CURProp { curpropCONSTRAINT_ERROR_MESSAGE, curpropDSBASE, curpropSETCRACK, curpropGETORG_RECBUF 
	};
#pragma option pop

struct DSProps;
typedef DSProps *pDSProps;

#pragma pack(push, 1)
struct DSProps
{
	char szName[261];
	int iFields;
	int iRecBufSize;
	int iBookMarkSize;
	BOOL bReadOnly;
	int iIndexes;
	int iOptParams;
	BOOL bDelta;
	int iLCID;
	int iUnused[8];
} ;
#pragma pack(pop)

struct DSFLDDesc;
typedef DSFLDDesc *pDSFLDDesc;

#pragma pack(push, 1)
struct DSFLDDesc
{
	char szName[32];
	int iFldType;
	int iFldSubType;
	int iUnits1;
	int iUnits2;
	int iFldLen;
	int iFldOffsInRec;
	int iNullOffsInRec;
	Word iFieldID;
	Word iFieldIDParent;
	BOOL bCalculated;
	int iFldAttr;
	int iOptParameters;
} ;
#pragma pack(pop)

struct DSIDXDesc;
typedef DSIDXDesc *pDSIDXDesc;

#pragma pack(push, 1)
struct DSIDXDesc
{
	char szName[32];
	int iFields;
	int iKeyFields[16];
	int iKeyLen;
	BOOL bUnique;
	BOOL bDescending[16];
	BOOL bCaseInsensitive[16];
} ;
#pragma pack(pop)

typedef void __stdcall (*pfCHANGECallBack)(int iClientData);

typedef BOOL __stdcall (*pfDSFilter)(int iClientData, void * pRecBuf);

typedef Word __stdcall (*pfDSCalcField)(int iClientData, void * pRecBuf);

typedef int dsCBRType;

typedef int *pdsCBRType;

typedef int __stdcall (*pfDSReconcile)(int iClientData, int iRslt, DSAttr iAction, int iResponse, int 
	iErrCode, char * pErrMessage, char * pErrContext, void * pRecUpd, void * pRecOrg, void * pRecConflict
	);

typedef int __fastcall (*pfDSReconcile_MD)(int iClientData, int iRslt, DSAttr iAction, int iErrResponse
	, int iErrCode, char * pErrMessage, char * pErrContext, Windows::PByte pRecUpd, Windows::PByte pRecOrg
	, Windows::PByte pRecConflict, int iLevels, Windows::PInteger piFieldIDs);

typedef int __fastcall (*pfFLDComp)(int iClientData, void * pVal1, void * pVal2);

#pragma option push -b
enum TPcktAttrArea { fldAttrArea, pcktAttrArea };
#pragma option pop

#pragma option push -b
enum TPcktFldStatus { fldIsChanged, fldIsNull, fldIsUnChanged };
#pragma option pop

#pragma pack(push, 1)
struct TDSDataPacketFldDesc
{
	char szFieldName[32];
	int iFieldType;
	Word iAttributes;
} ;
#pragma pack(pop)

typedef TDSDataPacketFldDesc *PDSDataPacketFldDesc;

__interface IDSBase;
typedef System::DelphiInterface<IDSBase> _di_IDSBase;
__interface INTERFACE_UUID("{9E8D2FA2-591C-11D0-BF52-0020AF32BD64}") IDSBase  : public IUnknown 
{
	
public:
	virtual Word __stdcall Create(unsigned iFields, pDSFLDDesc pFldDes, char * pszName) = 0 ;
	virtual Word __stdcall AddField(pDSFLDDesc pFldDes) = 0 ;
	virtual Word __stdcall AppendData(Activex::PSafeArray Packet, BOOL bEof) = 0 ;
	virtual Word __stdcall GetOptParameter(unsigned iNo, unsigned iFldNo, void * &ppName, unsigned &piType
		, unsigned &piLen, void * &ppValue) = 0 ;
	virtual Word __stdcall AddOptParameter(unsigned iFldNo, char * pszAttr, unsigned iType, unsigned iLen
		, void * pValue) = 0 ;
	virtual Word __stdcall GetProps(DSProps &Prop) = 0 ;
	virtual Word __stdcall GetFieldDescs(pDSFLDDesc Fields) = 0 ;
	virtual Word __stdcall GetIndexDescs(pDSIDXDesc p1) = 0 ;
	virtual Word __stdcall GetDelta(/* out */ _di_IDSBase &DsDelta) = 0 ;
	virtual Word __stdcall StreamDS(/* out */ Activex::PSafeArray &Packet) = 0 ;
	virtual Word __stdcall AcceptChanges(void) = 0 ;
	virtual Word __stdcall PutBlank(void * pRecBuf, unsigned iRecNo, unsigned iFldNo, unsigned iBlankValue
		) = 0 ;
	virtual Word __stdcall CreateIndex(const DSIDXDesc &IdxDesc) = 0 ;
	virtual Word __stdcall RemoveIndex(char * pszName) = 0 ;
	virtual Word __stdcall GetErrorString(Word iErrCode, char * pString) = 0 ;
	virtual int __stdcall FldCmp(unsigned iFldType, void * pFld1, void * pFld2, unsigned iUnits1, unsigned 
		iUnits2) = 0 ;
	virtual Word __stdcall GetProp(DSProp eProp, void * piPropValue) = 0 ;
	virtual Word __stdcall SetProp(DSProp eProp, unsigned iPropValue) = 0 ;
	virtual Word __stdcall SetFieldCalculation(unsigned iClientData, pfDSCalcField pfCalc) = 0 ;
	virtual Word __stdcall Reconcile(Activex::PSafeArray DeltaPacket, Activex::PSafeArray ErrorPacket, 
		unsigned iClientData, pfDSReconcile pfReconcile) = 0 ;
	virtual Word __stdcall Reserved1(void * Input) = 0 ;
	virtual Word __stdcall Reserved2(void * Input) = 0 ;
	virtual Word __stdcall Reserved3(void * Input) = 0 ;
	virtual Word __stdcall Refresh(Activex::PSafeArray NewPacket, unsigned iClientData, pfDSReconcile pfReconcile
		) = 0 ;
	virtual Word __stdcall Reset(void) = 0 ;
	virtual Word __stdcall RollBack(SAVEPOINT iSavePoint) = 0 ;
	virtual Word __stdcall GetEmbeddedDS(unsigned iFieldID, /* out */ _di_IDSBase &DsDet) = 0 ;
	virtual Word __stdcall MakeEmbedded(_di_IDSBase DsDet, unsigned iFieldsLink, PDWORD piFieldsM, PDWORD 
		piFieldsD, char * pMasterFieldName, char * pDetailFieldName) = 0 ;
	virtual Word __stdcall RefreshRecords(Activex::PSafeArray NewDataPacket, unsigned iRecNo, unsigned 
		iClientData, pfDSReconcile pfReconcile) = 0 ;
	virtual Word __stdcall ReleaseBlobs(unsigned iBlobId) = 0 ;
	virtual Word __stdcall Clone(unsigned iPType, BOOL bRecurse, BOOL bCloneOptParams, _di_IDSBase &DataSet
		) = 0 ;
	virtual Word __stdcall Reconcile_MD(_di_IDSBase pDsRec, Activex::PSafeArray pDeltaPacket, Activex::PSafeArray 
		pErrorPacket, unsigned iClientData, pfDSReconcile_MD pfReconcile_MD) = 0 ;
	virtual Word __stdcall DropOptParameter(unsigned iFldNo, char * pName) = 0 ;
};

__interface IDSCursor;
typedef System::DelphiInterface<IDSCursor> _di_IDSCursor;
__interface INTERFACE_UUID("{9E8D2FA4-591C-11D0-BF52-0020AF32BD64}") IDSCursor  : public IUnknown 
{
	
public:
	virtual Word __stdcall InitCursor(_di_IDSBase DataSet) = 0 ;
	virtual Word __stdcall CloneCursor(_di_IDSCursor Cursor) = 0 ;
	virtual Word __stdcall GetCursorProps(DSProps &p1) = 0 ;
	virtual Word __stdcall GetIndexDescs(BOOL bCurrentOnly, DSIDXDesc &IdxDesc) = 0 ;
	virtual Word __stdcall GetFieldDescs(pDSFLDDesc p1) = 0 ;
	virtual Word __stdcall GetCurrentRecord(void * pRecBuf) = 0 ;
	virtual Word __stdcall GetRecordBlock(PDWORD piRecs, void * pRecBuf) = 0 ;
	virtual Word __stdcall GetCurrentBookMark(void * pBookMark) = 0 ;
	virtual Word __stdcall GetSequenceNumber(unsigned &iSeq) = 0 ;
	virtual Word __stdcall GetRecordAttribute(DSAttr &Attr) = 0 ;
	virtual Word __stdcall GetRecordCount(int &iRecs) = 0 ;
	virtual Word __stdcall MoveToBOF(void) = 0 ;
	virtual Word __stdcall MoveToEOF(void) = 0 ;
	virtual Word __stdcall MoveRelative(int i) = 0 ;
	virtual Word __stdcall MoveToSeqNo(unsigned i) = 0 ;
	virtual Word __stdcall MoveToBookMark(void * pBookMark) = 0 ;
	virtual Word __stdcall MoveToKey(DBSearchCond SearchCond, unsigned iFields, unsigned iPartLen, void * 
		pRecBuf) = 0 ;
	virtual Word __stdcall CompareBookMarks(void * pBookMark1, void * pBookMark2, int &iCmp) = 0 ;
	virtual Word __stdcall ExtractKey(void * pRecBuf, void * pKeyBuf) = 0 ;
	virtual Word __stdcall GetRecordForKey(unsigned iFields, unsigned iPartLen, void * pKey, void * pRecBuf
		) = 0 ;
	virtual Word __stdcall GetField(void * pRecBuf, unsigned iFieldNo, void * pFldBuf, BOOL &bBlank) = 0 
		;
	virtual Word __stdcall PutField(void * pRecBuf, unsigned iFieldNo, void * pFldBuf) = 0 ;
	virtual Word __stdcall GetBlobLen(void * pRecBuf, unsigned iFieldNo, unsigned &iLength) = 0 ;
	virtual Word __stdcall GetBlob(void * pRecBuf, unsigned iFieldNo, unsigned iOffSet, void * pBuf, unsigned 
		&iLength) = 0 ;
	virtual Word __stdcall PutBlob(void * pRecBuf, unsigned iFieldNo, unsigned iOffSet, void * pBuf, unsigned 
		iLength) = 0 ;
	virtual Word __stdcall InitRecord(void * pRecBuf) = 0 ;
	virtual Word __stdcall DeleteRecord(void) = 0 ;
	virtual Word __stdcall ModifyRecord(void * pRecBuf) = 0 ;
	virtual Word __stdcall InsertRecord(void * pRecBuf) = 0 ;
	virtual Word __stdcall UndoLastChange(BOOL bFollowChange) = 0 ;
	virtual Word __stdcall AddFilter(void * pcanExpr, unsigned iLen, hDSFilter &hFilter) = 0 ;
	virtual Word __stdcall DropFilter(hDSFilter hFilter) = 0 ;
	virtual Word __stdcall SetRange(unsigned iFields, void * pKey1, BOOL bKey1Incl, void * pKey2, BOOL 
		bKey2Incl) = 0 ;
	virtual Word __stdcall DropRange(void) = 0 ;
	virtual Word __stdcall SortOnFields(unsigned iFields, PDWORD piFields, PBOOL pDescending, PBOOL pCaseInsensitive
		) = 0 ;
	virtual Word __stdcall UseIndexOrder(char * pszName) = 0 ;
	virtual Word __stdcall SetNotifyCallBack(unsigned iClientData, pfCHANGECallBack pfCallBack) = 0 ;
	virtual Word __stdcall AddFilterCallBack(unsigned iClientData, pfDSFilter pfFilter, hDSFilter &hFilter
		) = 0 ;
	virtual Word __stdcall VerifyField(unsigned iFieldNo, void * pFldBuf) = 0 ;
	virtual Word __stdcall GetProp(CURProp eProp, void * piPropValue) = 0 ;
	virtual Word __stdcall RevertRecord(void) = 0 ;
	virtual Word __stdcall LocateWithFilter(void * pCanExpr, unsigned iLen) = 0 ;
	virtual Word __stdcall AddAggregate(unsigned iFlds, unsigned iCanLen, void * pCanExpr, hDSAggregate 
		&hAgg) = 0 ;
	virtual Word __stdcall DropAggregate(hDSAggregate hAgg) = 0 ;
	virtual Word __stdcall GetAggregateValue(hDSAggregate hAgg, void * pValue, BOOL &bBlank) = 0 ;
	virtual Word __stdcall GetAggregateDesc(hDSAggregate hAgg, DSFLDDesc &Desc) = 0 ;
	virtual Word __stdcall MoveToNextSubGroup(unsigned iFields) = 0 ;
	virtual Word __stdcall GetSubGroupState(unsigned iFields, GROUPSTATE &iSubGroupState) = 0 ;
	virtual Word __stdcall LinkCursors(unsigned iFieldsM, PDWORD piFieldsM, PDWORD piFieldsD, _di_IDSCursor 
		hCurDet) = 0 ;
	virtual Word __stdcall ResyncWithMaster(void) = 0 ;
	virtual Word __stdcall SetProp(CURProp eProp, unsigned iPropValue) = 0 ;
	virtual Word __stdcall GetRecordNumber(unsigned &iRecNo) = 0 ;
	virtual Word __stdcall GetRowRequestPacket(BOOL bKeysOnly, BOOL bFetchAllBlobs, BOOL bFetchAllDetails
		, BOOL bInclMetaData, /* out */ Activex::PSafeArray &Packet) = 0 ;
	virtual Word __stdcall RefreshRecord(Activex::PSafeArray Packet) = 0 ;
};

__interface IDSWriter;
typedef System::DelphiInterface<IDSWriter> _di_IDSWriter;
__interface INTERFACE_UUID("{9E8D2FA6-591C-11D0-BF52-0020AF32BD64}") IDSWriter  : public IUnknown 
{
	
public:
	virtual Word __stdcall Init_Sequential(unsigned Version, Word Columns) = 0 ;
	virtual Word __stdcall Init(unsigned Version, Word Columns, PDSDataPacketFldDesc FieldDesc) = 0 ;
	virtual Word __stdcall AddAttribute(TPcktAttrArea AttrArea, char * Attr, unsigned AttrType, unsigned 
		Len, void * Value) = 0 ;
	virtual Word __stdcall GetDataPacket(Activex::PSafeArray &SA) = 0 ;
	virtual Word __stdcall GetSize(unsigned &DataPacketSize) = 0 ;
	virtual Word __stdcall PutField(TPcktFldStatus FldStatus, unsigned Len, void * Src) = 0 ;
	virtual Word __stdcall AddColumnDesc(const TDSDataPacketFldDesc &FldDes) = 0 ;
	virtual Word __stdcall Reset(void) = 0 ;
	virtual Word __stdcall GetColumnCount(unsigned &Count) = 0 ;
	virtual Word __stdcall GetColumnDescs(PDSDataPacketFldDesc FieldDes) = 0 ;
	virtual Word __stdcall GetErrorString(Word iErrCode, char * pString) = 0 ;
	virtual Word __stdcall EndOfNestedRows(void) = 0 ;
	virtual Word __stdcall SetXMLMode(int iMode) = 0 ;
	virtual unsigned __stdcall GetXMLMode(void) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
static const Shortint dsRecUnmodified = 0x0;
static const Shortint dsRecOrg = 0x1;
static const Shortint dsRecDeleted = 0x2;
static const Shortint dsRecNew = 0x4;
static const Shortint dsRecModified = 0x8;
static const Shortint dsUnused = 0x20;
static const Shortint dsDetUpd = 0x40;
static const Shortint dsIsNotVisible = 0x23;
static const Shortint dsIsVisible = 0xffffffdc;
static const Shortint fldAttrHIDDEN = 0x1;
static const Shortint fldAttrREADONLY = 0x2;
static const Shortint fldAttrREQUIRED = 0x4;
static const Shortint fldAttrLINK = 0x8;
static const Shortint BLANK_NULL = 0x1;
static const Shortint BLANK_NOTCHANGED = 0x2;
static const Shortint MAXKEYFIELDS = 0x10;
static const Shortint mdCASCADEDEL = 0x4;
static const Shortint mdCASCADEMOD = 0x8;
static const Shortint mdALLOWLINKCHANGE = 0x10;
static const Shortint dscbrSKIP = 0x1;
static const Shortint dscbrABORT = 0x2;
static const Shortint dscbrMERGE = 0x3;
static const Shortint dscbrAPPLY = 0x4;
static const Shortint dscbrIGNORE = 0x5;
static const Shortint dscbrCORRECT = 0x4;
static const Shortint dscbrCANCEL = 0x5;
static const Shortint dscbrREFRESH = 0x6;
static const Shortint xmlUNTYPED = 0x1;
static const Shortint xmlXMLDATATYPED = 0x2;
static const Shortint xmlXMLSCHEMA = 0x4;
static const Shortint xmlON = 0x5;
static const Shortint xmlOFF = 0x0;
#define szUNIQUE_KEY "UNIQUE_KEY"
#define szPRIMARY_KEY "PRIMARY_KEY"
#define szDEFAULT_ORDER "DEFAULT_ORDER"
#define szCHANGEINDEX "CHANGEINDEX"
#define szCHANGE_LOG "CHANGE_LOG"
#define szSERVER_COL "SERVER_COL"
#define szCONSTRAINTS "CONSTRAINTS"
#define szDATASET_CONTEXT "DATASET_CONTEXT"
#define szDATASET_DELTA "DATASET_DELTA"
#define szREADONLY "READONLY"
#define szSUBTYPE "SUBTYPE"
#define szDECIMALS "DECIMALS"
#define szWIDTH "WIDTH"
#define szLCID "LCID"
#define szBDEDOMX "BDEDOMAIN_X"
#define szBDERECX "BDERECORD_X"
#define szBDEDEFX "BDEDEFAULT_X"
#define szAUTOINCVALUE "AUTOINCVALUE"
#define szELEMENTS "ELEMENTS"
#define szTABLE_NAME "TABLE_NAME"
#define szMD_FIELDLINKS "MD_FIELDLINKS"
#define szTYPENAME "TYPENAME"
#define szUPDATEMODE "UPDATEMODE"
#define szFIELDPROPS "FIELDPROPS"
#define szPROVFLAGS "PROVFLAGS"
#define szORIGIN "ORIGIN"
#define szMD_SEMANTICS "MD_SEMANTICS"
#define szSERVERCALC "SERVER_CALC"
#define szBDEDOMCL "BDEDOMAIN_CL"
#define szBDERECCL "BDERECORD_CL"
#define szBDEDEFCL "BDEDEFAULT_CL"
#define szDISABLE_INSERTS "DISABLE_INSERTS"
#define szDISABLE_DELETES "DISABLE_DELETES"
#define szDISABLE_EDITS "DISABLE_EDITS"
#define szNO_RESET_CALL "NO_RESET_CALL"
#define szMINVALUE "MINVALUE"
#define szMAXVALUE "MAXVALUE"
#define szstMEMO "Text"
#define szstBINARY "Binary"
#define szstFMTMEMO "Formatted"
#define szstOLEOBJ "Ole"
#define szstGRAPHIC "Graphics"
#define szstDBSOLEOBJ "dBASEOle"
#define szstTYPEDBINARY "TypedBinary"
#define szstMONEY "Money"
#define szstAUTOINC "Autoinc"
#define szstADTNESTEDTABLE "ADTNestedTable"
#define szstFIXEDCHAR "FixedChar"
#define szstREFNESTEDTABLE "Reference"
#define szstGUID "Guid"
#define szstACCOLEOBJ "AccessOle"
#define szstHMEMO "HMemo"
#define szstHBINARY "HBinary"
static const Shortint fldstReference = 0x46;
static const Shortint dsfldUNKNOWN = 0x0;
static const Shortint dsfldINT = 0x1;
static const Shortint dsfldUINT = 0x2;
static const Shortint dsfldBOOL = 0x3;
static const Shortint dsfldFLOATIEEE = 0x4;
static const Shortint dsfldBCD = 0x5;
static const Shortint dsfldDATE = 0x6;
static const Shortint dsfldTIME = 0x7;
static const Shortint dsfldTIMESTAMP = 0x8;
static const Shortint dsfldZSTRING = 0x9;
static const Shortint dsfldUNICODE = 0xa;
static const Shortint dsfldBYTES = 0xb;
static const Shortint dsfldADT = 0xc;
static const Shortint dsfldARRAY = 0xd;
static const Shortint dsfldEMBEDDEDTBL = 0xe;
static const Shortint dsfldREF = 0xf;
static const Shortint dsSizeBitsLen = 0x10;
static const Word dsSizeBitsMask = 0xffff;
static const int dsTypeBitsMask = 0x3f0000;
static const int dsVaryingFldType = 0x400000;
static const int dsArrayFldType = 0x800000;
static const int dsPseudoFldType = 0x1000000;
static const int dsCompArrayFldType = 0x2000000;
static const int dsEmbeddedFldType = 0x4000000;
static const unsigned dsIncInDelta = 0x80000000;
static const Word dskeyCASEINSENSITIVE = 0x4000;
static const Word dskeyDESCENDING = 0x8000;
static const unsigned dsDELAYEDBIT = 0x80000000;
static const Shortint PACKETVERSION_1 = 0x1;
static const Shortint PACKETVERSION_2 = 0x2;
static const Shortint dsCASCADEDELETES = 0x1;
static const Shortint dsCASCADEUPDATES = 0x2;
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
static const Shortint MAXLOGFLDTYPES = 0x18;
static const Word fldUNICODE = 0x1007;
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
static const Shortint fldstGUID = 0x26;
static const Shortint fldstAUTOINC = 0x1d;
extern PACKAGE Byte FieldTypeMap[36];
extern PACKAGE Word FldSubTypeMap[36];
extern PACKAGE Db::TFieldType DataTypeMap[24];
extern PACKAGE Db::TFieldType BlobTypeMap[15];
static const Shortint DBERR_NONE = 0x0;
static const Word DBERR_BOF = 0x2201;
static const Word DBERR_EOF = 0x2202;
static const Word DBERR_NOSUCHINDEX = 0x270d;
static const Shortint ERRCAT_ALC = 0x40;
static const Word ERRBASE_ALC = 0x4000;
static const Shortint ERRCODE_DELTAISEMPTY = 0x1;
static const Shortint ERRCODE_NOTHINGTOUNDO = 0x2;
static const Shortint ERRCODE_NOMETADATA = 0x3;
static const Shortint ERRCODE_CANNOTAPPEND = 0x4;
static const Shortint ERRCODE_DATAPACKETMISMATCH = 0x5;
static const Shortint ERRCODE_ABORTED = 0x6;
static const Shortint ERRCODE_CANCELLED = 0x7;
static const Shortint ERRCODE_NEWERVERSIONREQ = 0x8;
static const Shortint ERRCODE_BLOBNOTFETCHED = 0x9;
static const Shortint ERRCODE_DETAILSNOTFETCHED = 0xa;
static const Shortint ERRCODE_NOMASTERRECORD = 0xb;
static const Shortint ERRCODE_LINKFIELDSNOTUNIQUE = 0xc;
static const Shortint ERRCODE_FLYAWAY_WRONGORDER = 0xd;
static const Shortint ERRCODE_NOCASCADEDUPDATES = 0xe;
static const Word DBERR_DELTAISEMPTY = 0x4001;
static const Word DBERR_NOTHINGTOUNDO = 0x4002;
static const Word DBERR_NOMETADATA = 0x4003;
static const Word DBERR_CANNOTAPPEND = 0x4004;
static const Word DBERR_DATAPACKETMISMATCH = 0x4005;
static const Word DBERR_ABORTED = 0x4006;
static const Word DBERR_CANCELLED = 0x4007;
static const Word DBERR_NEWERVERSIONREQ = 0x4008;
static const Word DBERR_BLOBNOTFETCHED = 0x4009;
static const Word DBERR_DETAILSNOTFETCHED = 0x400a;
static const Word DBERR_NOMASTERRECORD = 0x400b;
static const Word DBERR_LINKFIELDSNOTUNIQUE = 0x400c;
static const Word DBERR_FLYAWAY_WRONGORDER = 0x400d;
static const Word DBERR_NOCASCADEDUPDATES = 0x400e;
extern PACKAGE GUID CLSID_DSBase;
extern PACKAGE GUID CLSID_DSCursor;
extern PACKAGE GUID CLSID_DSWriter;
extern PACKAGE void __fastcall CreateDbClientObject(const GUID &CLSID, const GUID &IID, /* out */ void 
	*Obj);
extern PACKAGE void __fastcall FreeDataPacket(Activex::PSafeArray &DataPacket);
extern PACKAGE Activex::PSafeArray __fastcall VarToDataPacket(const OleVariant &V);
extern PACKAGE int __fastcall DataPacketSize(const Activex::PSafeArray DataPacket);
extern PACKAGE void __fastcall DataPacketToVariant(const Activex::PSafeArray DataPacket, OleVariant 
	&V);
extern PACKAGE AnsiString __fastcall VariantArrayToString(const OleVariant &V);
extern PACKAGE OleVariant __fastcall StringToVariantArray(const AnsiString S);

}	/* namespace Dsintf */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Dsintf;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DSIntf
