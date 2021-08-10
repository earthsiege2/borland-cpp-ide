// Borland C++ Builder
// Copyright (c) 1995, 1999 by Borland International
// All rights reserved

// (DO NOT EDIT: machine generated header) 'OLEDB.pas' rev: 5.00

#ifndef OLEDBHPP
#define OLEDBHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <ActiveX.hpp>	// Pascal unit
#include <Windows.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <transact.h>
#include <oledb.h>
#include <comsvcs.h>
typedef System::DelphiInterface<ITransaction> _di_ITransaction;

namespace Oledb
{
//-- type declarations -------------------------------------------------------
typedef int TOleEnum;

typedef _di_IUnknown *PIUnknown;

typedef Shortint SBYTE;

typedef unsigned TUintArray[65536];

typedef unsigned *PUintArray;

typedef Windows::PByte *PPByte;

typedef Byte *TPByteArray[65536];

typedef Windows::PByte *PPByteArray;

typedef unsigned *PDBASYNCHPHASE;

typedef unsigned *PDBSORT;

typedef unsigned *PDBCOMPAREOP;

typedef unsigned *PHACCESSOR;

typedef Word *PHSOURCE;

typedef unsigned PHCHAPTER;

typedef unsigned *PHROW;

typedef PHROW *PPHROW;

typedef unsigned *PDBROWSTATUS;

typedef PDBROWSTATUS *PPDBROWSTATUS;

typedef unsigned *PDBPENDINGSTATUS;

typedef PDBPENDINGSTATUS *PPDBPENDINGSTATUS;

typedef unsigned *PDBROWOPTIONS;

typedef unsigned *PDBSOURCETYPE;

typedef BOID *PBoid;

typedef BOID  TBoid;

typedef XACTTRANSINFO *PXactTransInfo;

typedef XACTTRANSINFO  TXactTransInfo;

typedef XACTOPT *PXactOpt;

typedef XACTOPT  TXActOpt;

typedef XACTSTATS *PXactStats;

typedef XACTSTATS  TXactStats;

typedef DBBINDEXT *PDBBindExt;

typedef DBBINDEXT  TDBBindExt;

typedef DBOBJECT *PDBObject;

typedef DBOBJECT  TDBObject;

typedef DBBINDING *PDBBinding;

typedef DBBINDING  TDBBinding;

typedef DBBINDING TDBBindingArray[65536];

typedef DBBINDING *PDBBindingArray;

struct DBIDNAME;
typedef DBIDNAME *PDBIDName;

struct DBIDNAME
{
	
	union
	{
		struct 
		{
			unsigned ulPropid;
			
		};
		struct 
		{
			wchar_t *pwszName;
			
		};
		
	};
} ;

typedef DBIDNAME  TDBIDName;

struct DBIDGUID;
typedef DBIDGUID *PDBIDGuid;

struct DBIDGUID
{
	
	union
	{
		struct 
		{
			GUID *pguid;
			
		};
		struct 
		{
			GUID guid;
			
		};
		
	};
} ;

typedef DBIDGUID  TDBIDGuid;

typedef unsigned *PDBPROPID;

typedef unsigned TDBPropIDArray[65536];

typedef unsigned *PDBPropIDArray;

typedef DBID *PDBID;

typedef PDBID *PPDBID;

typedef DBID  TDBID;

typedef DBID TDBIDArray[65536];

typedef DBID *PDBIDArray;

typedef DBPROPIDSET *PDBPropIDSet;

typedef DBPROPIDSET  TDBPropIDSet;

typedef DBPROPIDSET TDBPropIDSetArray[65536];

typedef DBPROPIDSET *PDBPropIDSetArray;

typedef DBPROP *PDBProp;

typedef DBPROP  TDBProp;

typedef DBPROP TDBPropArray[65536];

typedef DBPROP *PDBPropArray;

typedef DBPROPSET *PDBPropSet;

typedef PDBPropSet *PPDBPropSet;

typedef DBPROPSET  TDBPropSet;

typedef DBPROPSET TDBPropSetArray[65536];

typedef DBPROPSET *PDBPropSetArray;

typedef DBPROPINFO *PDBPropInfo;

typedef DBPROPINFO  TDBPropInfo;

typedef DBPROPINFO TDBPropInfoArray[65536];

typedef DBPROPINFO *PDBPropInfoArray;

typedef DBPROPINFOSET *PDBPropInfoSet;

typedef DBPROPINFOSET  TDBPropInfoSet;

typedef DBPROPINFOSET TDBPropInfoSetArray[65536];

typedef DBPROPINFOSET *PDBPropInfoSetArray;

typedef DBINDEXCOLUMNDESC *PDBIndexColumnDesc;

typedef DBINDEXCOLUMNDESC  TDBIndexColumnDesc;

typedef DBINDEXCOLUMNDESC TDBIndexColumnDescArray[65536];

typedef DBINDEXCOLUMNDESC *PDBIndexColumnDescArray;

typedef DBPARAMS *PDBParams;

typedef DBPARAMS  TDBParams;

typedef DBCOLUMNINFO *PDBColumnInfo;

typedef DBCOLUMNINFO  TDBColumnInfo;

typedef DBCOLUMNINFO TDBColumnInfoArray[4097];

typedef DBCOLUMNINFO *PDBColumnInfoArray;

typedef DBLITERALINFO *PDBLiteralInfo;

typedef DBLITERALINFO  TDBLiteralInfo;

typedef DBLITERALINFO TDBLiteralInfoArray[65536];

typedef DBLITERALINFO *PDBLiteralInfoArray;

typedef DBCOLUMNDESC *PDBColumnDesc;

typedef DBCOLUMNDESC  TDBColumnDesc;

typedef DBCOLUMNDESC TDBColumnDescArray[65536];

typedef DBCOLUMNDESC *PDBColumnDescArray;

typedef SEC_OBJECT_ELEMENT *PSecObjectElement;

typedef SEC_OBJECT_ELEMENT  TSecObjectElement;

typedef SEC_OBJECT_ELEMENT TSecObjectElementArray[65536];

typedef SEC_OBJECT_ELEMENT *PSecObjectElementArray;

typedef SEC_OBJECT *PSecObject;

typedef SEC_OBJECT  TSecObject;

typedef TRUSTEE_W *TTrusteeW;

typedef TTrusteeW *PTrusteeW;

typedef PTrusteeW *PPTrusteeW;

typedef DBPARAMINFO *PDBParamInfo;

typedef DBPARAMINFO  TDBParamInfo;

typedef DBPARAMINFO TDBParamInfoArray[65536];

typedef DBPARAMINFO *PDBParamInfoArray;

typedef DB_NUMERIC *PDBNumeric;

typedef DB_NUMERIC  TDBNumeric;

typedef DBVECTOR *PDBVector;

typedef DBVECTOR  TDBVector;

typedef DBDATE *PDBDate;

typedef DBDATE  TDBDate;

typedef DBTIME *PDBTime;

typedef DBTIME  TDBTime;

typedef DBTIMESTAMP *PDBTimeStamp;

typedef DBTIMESTAMP  TDBTimeStamp;

#pragma pack(push, 1)
struct DBFILETIME
{
	unsigned dwLowDateTime;
	unsigned dwHighDateTime;
} ;
#pragma pack(pop)

typedef DBFILETIME *PDBFileTime;

typedef DBFILETIME  TDBFileTime;

typedef DB_VARNUMERIC *PDBVarNumeric;

typedef DB_VARNUMERIC  TDBVarNumeric;

typedef DBFAILUREINFO *PDBFailureInfo;

typedef DBFAILUREINFO  TDBFailureInfo;

typedef MDAXISINFO *PMDAxisInfo;

typedef MDAXISINFO  TMDAxisInfo;

typedef DBPARAMBINDINFO *PDBParamBindInfo;

typedef DBPARAMBINDINFO  TDBParamBindInfo;

typedef DBPARAMBINDINFO TDBParamBindInfoArray[65536];

typedef DBPARAMBINDINFO *PDBParamBindInfoArray;

typedef ERRORINFO *PErrorInfo;

typedef ERRORINFO  TErrorInfo;

typedef EXPLICIT_ACCESS_W *PExplicitAccessW;

typedef PExplicitAccessW *PPExplicitAccessW;

typedef EXPLICIT_ACCESS_W  TExplicitAccessW;

__interface ITransactionOptions;
typedef System::DelphiInterface<ITransactionOptions> _di_ITransactionOptions;
__interface INTERFACE_UUID("{3A6AD9E0-23B9-11CF-AD60-00AA00A74CCD}") ITransactionOptions  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall SetOptions(XACTOPT &pOptions) = 0 ;
	virtual HRESULT __stdcall GetOptions(XACTOPT &pOptions) = 0 ;
};

__interface ITransactionOptionsSC;
typedef System::DelphiInterface<ITransactionOptionsSC> _di_ITransactionOptionsSC;
__interface INTERFACE_UUID("{3A6AD9E0-23B9-11CF-AD60-00AA00A74CCD}") ITransactionOptionsSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall SetOptions(XACTOPT &pOptions) = 0 ;
	virtual HRESULT __safecall GetOptions(XACTOPT &pOptions) = 0 ;
};

__interface ITransactionDispenser;
typedef System::DelphiInterface<ITransactionDispenser> _di_ITransactionDispenser;
__interface INTERFACE_UUID("{3A6AD9E1-23B9-11CF-AD60-00AA00A74CCD}") ITransactionDispenser  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetOptionsObject(/* out */ _di_ITransactionOptions &ppOptions) = 0 ;
	virtual HRESULT __stdcall BeginTransaction(const _di_IUnknown punkOuter, int isoLevel, unsigned isoFlags
		, const _di_ITransactionOptions pOptions, /* out */ _di_ITransaction &ppTransaction) = 0 ;
};

__interface ITransactionDispenserSC;
typedef System::DelphiInterface<ITransactionDispenserSC> _di_ITransactionDispenserSC;
__interface INTERFACE_UUID("{3A6AD9E1-23B9-11CF-AD60-00AA00A74CCD}") ITransactionDispenserSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetOptionsObject(/* out */ _di_ITransactionOptions &ppOptions) = 0 ;
	virtual HRESULT __safecall BeginTransaction(const _di_IUnknown punkOuter, int isoLevel, unsigned isoFlags
		, const _di_ITransactionOptions pOptions, /* out */ _di_ITransaction &ppTransaction) = 0 ;
};

__interface ITransactionOutcomeEvents;
typedef System::DelphiInterface<ITransactionOutcomeEvents> _di_ITransactionOutcomeEvents;
__interface INTERFACE_UUID("{3A6AD9E2-23B9-11CF-AD60-00AA00A74CCD}") ITransactionOutcomeEvents  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Committed(BOOL fRetaining, PBoid pNewUOW, HRESULT hr) = 0 ;
	virtual HRESULT __stdcall Aborted(PBoid pboidReason, BOOL fRetaining, PBoid pNewUOW, HRESULT hr) = 0 
		;
	virtual HRESULT __stdcall HeuristicDecision(unsigned dwDecision, PBoid pboidReason, HRESULT hr) = 0 
		;
	virtual HRESULT __stdcall Indoubt(void) = 0 ;
};

__interface ITransactionOutcomeEventsSC;
typedef System::DelphiInterface<ITransactionOutcomeEventsSC> _di_ITransactionOutcomeEventsSC;
__interface INTERFACE_UUID("{3A6AD9E2-23B9-11CF-AD60-00AA00A74CCD}") ITransactionOutcomeEventsSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall Committed(BOOL fRetaining, PBoid pNewUOW, HRESULT hr) = 0 ;
	virtual HRESULT __safecall Aborted(PBoid pboidReason, BOOL fRetaining, PBoid pNewUOW, HRESULT hr) = 0 
		;
	virtual HRESULT __safecall HeuristicDecision(unsigned dwDecision, PBoid pboidReason, HRESULT hr) = 0 
		;
	virtual HRESULT __stdcall Indoubt(void) = 0 ;
};

__interface IAccessor;
typedef System::DelphiInterface<IAccessor> _di_IAccessor;
__interface INTERFACE_UUID("{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}") IAccessor  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall AddRefAccessor(unsigned HACCESSOR, PUINT pcRefCount) = 0 ;
	virtual HRESULT __stdcall CreateAccessor(unsigned dwAccessorFlags, unsigned cBindings, PDBBindingArray 
		rgBindings, unsigned cbRowSize, unsigned &phAccessor, PUintArray rgStatus) = 0 ;
	virtual HRESULT __stdcall GetBindings(unsigned HACCESSOR, PUINT pdwAccessorFlags, unsigned &pcBindings
		, /* out */ PDBBinding &prgBindings) = 0 ;
	virtual HRESULT __stdcall ReleaseAccessor(unsigned HACCESSOR, PUINT pcRefCount) = 0 ;
};

__interface IAccessorSC;
typedef System::DelphiInterface<IAccessorSC> _di_IAccessorSC;
__interface INTERFACE_UUID("{0C733A8C-2A1C-11CE-ADE5-00AA0044773D}") IAccessorSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall AddRefAccessor(unsigned HACCESSOR, PUINT pcRefCount) = 0 ;
	virtual HRESULT __safecall CreateAccessor(unsigned dwAccessorFlags, unsigned cBindings, PDBBindingArray 
		rgBindings, unsigned cbRowSize, unsigned &phAccessor, PUintArray rgStatus) = 0 ;
	virtual HRESULT __safecall GetBindings(unsigned HACCESSOR, PUINT pdwAccessorFlags, unsigned &pcBindings
		, /* out */ PDBBinding &prgBindings) = 0 ;
	virtual HRESULT __safecall ReleaseAccessor(unsigned HACCESSOR, PUINT pcRefCount) = 0 ;
};

__interface IRowset;
typedef System::DelphiInterface<IRowset> _di_IRowset;
__interface INTERFACE_UUID("{0C733A7C-2A1C-11CE-ADE5-00AA0044773D}") IRowset  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall AddRefRows(unsigned cRows, PUintArray rghRows, PUintArray rgRefCounts, PUintArray 
		rgRowStatus) = 0 ;
	virtual HRESULT __stdcall GetData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
	virtual HRESULT __stdcall GetNextRows(unsigned hReserved, int lRowsOffset, int cRows, /* out */ unsigned 
		&pcRowsObtained, PUintArray &prghRows) = 0 ;
	virtual HRESULT __stdcall ReleaseRows(unsigned cRows, PUintArray rghRows, PUintArray rgRowOptions, 
		PUintArray rgRefCounts, PUintArray rgRowStatus) = 0 ;
	virtual HRESULT __stdcall RestartPosition(unsigned hReserved) = 0 ;
};

__interface IRowsetSC;
typedef System::DelphiInterface<IRowsetSC> _di_IRowsetSC;
__interface INTERFACE_UUID("{0C733A7C-2A1C-11CE-ADE5-00AA0044773D}") IRowsetSC  : public IUnknown 
{
	
public:
	virtual HRESULT __safecall AddRefRows(unsigned cRows, PUintArray rghRows, PUintArray rgRefCounts, PUintArray 
		rgRowStatus) = 0 ;
	virtual HRESULT __safecall GetData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
	virtual HRESULT __safecall GetNextRows(unsigned hReserved, int lRowsOffset, int cRows, /* out */ unsigned 
		&pcRowsObtained, PUintArray &prghRows) = 0 ;
	virtual HRESULT __safecall ReleaseRows(unsigned cRows, PUintArray rghRows, PUintArray rgRowOptions, 
		PUintArray rgRefCounts, PUintArray rgRowStatus) = 0 ;
	virtual HRESULT __safecall RestartPosition(unsigned hReserved) = 0 ;
};

__interface IRowsetInfo;
typedef System::DelphiInterface<IRowsetInfo> _di_IRowsetInfo;
__interface INTERFACE_UUID("{0C733A55-2A1C-11CE-ADE5-00AA0044773D}") IRowsetInfo  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, /* out */ unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __stdcall GetReferencedRowset(unsigned iOrdinal, const GUID &riid, /* out */ _di_IUnknown 
		&ppReferencedRowset) = 0 ;
	virtual HRESULT __stdcall GetSpecification(const GUID &riid, /* out */ _di_IUnknown &ppSpecification
		) = 0 ;
};

__interface IRowsetInfoSC;
typedef System::DelphiInterface<IRowsetInfoSC> _di_IRowsetInfoSC;
__interface INTERFACE_UUID("{0C733A55-2A1C-11CE-ADE5-00AA0044773D}") IRowsetInfoSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, /* out */ unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __safecall GetReferencedRowset(unsigned iOrdinal, const GUID &riid, /* out */ _di_IUnknown 
		&ppReferencedRowset) = 0 ;
	virtual HRESULT __safecall GetSpecification(const GUID &riid, /* out */ _di_IUnknown &ppSpecification
		) = 0 ;
};

__interface IRowsetLocate;
typedef System::DelphiInterface<IRowsetLocate> _di_IRowsetLocate;
__interface INTERFACE_UUID("{0C733A7D-2A1C-11CE-ADE5-00AA0044773D}") IRowsetLocate  : public IRowset 
	
{
	
public:
	virtual HRESULT __stdcall Compare(unsigned hReserved, unsigned cbBookmark1, Windows::PByte pBookmark1
		, unsigned cbBookmark2, Windows::PByte pBookmark2, /* out */ unsigned &pComparison) = 0 ;
	virtual HRESULT __stdcall GetRowsAt(unsigned hReserved1, unsigned hReserved2, unsigned cbBookmark, 
		Windows::PByte pBookmark, int lRowsOffset, int cRows, /* out */ unsigned &pcRowsObtained, /* out */ 
		PHROW &prghRows) = 0 ;
	virtual HRESULT __stdcall GetRowsByBookmark(unsigned hReserved, unsigned cRows, PUintArray rgcbBookmarks
		, PPByteArray rgpBookmarks, PUintArray rghRows, PUintArray rgRowStatus) = 0 ;
	virtual HRESULT __stdcall Hash(unsigned hReserved, unsigned cBookmarks, PUintArray rgcbBookmarks, PPByteArray 
		rgpBookmarks, PUintArray rgHashedValues, PUintArray rgBookmarkStatus) = 0 ;
};

__interface IRowsetLocateSC;
typedef System::DelphiInterface<IRowsetLocateSC> _di_IRowsetLocateSC;
__interface INTERFACE_UUID("{0C733A7D-2A1C-11CE-ADE5-00AA0044773D}") IRowsetLocateSC  : public IRowset 
	
{
	
public:
	virtual HRESULT __safecall Compare(unsigned hReserved, unsigned cbBookmark1, Windows::PByte pBookmark1
		, unsigned cbBookmark2, Windows::PByte pBookmark2, /* out */ unsigned &pComparison) = 0 ;
	virtual HRESULT __safecall GetRowsAt(unsigned hReserved1, unsigned hReserved2, unsigned cbBookmark, 
		Windows::PByte pBookmark, int lRowsOffset, int cRows, /* out */ unsigned &pcRowsObtained, /* out */ 
		PHROW &prghRows) = 0 ;
	virtual HRESULT __safecall GetRowsByBookmark(unsigned hReserved, unsigned cRows, PUintArray rgcbBookmarks
		, PPByteArray rgpBookmarks, PUintArray rghRows, PUintArray rgRowStatus) = 0 ;
	virtual HRESULT __safecall Hash(unsigned hReserved, unsigned cBookmarks, PUintArray rgcbBookmarks, 
		PPByteArray rgpBookmarks, PUintArray rgHashedValues, PUintArray rgBookmarkStatus) = 0 ;
};

__interface IRowsetResynch;
typedef System::DelphiInterface<IRowsetResynch> _di_IRowsetResynch;
__interface INTERFACE_UUID("{0C733A84-2A1C-11CE-ADE5-00AA0044773D}") IRowsetResynch  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetVisibleData(unsigned HROW, unsigned HACCESSOR, /* out */ void * &pData
		) = 0 ;
	virtual HRESULT __stdcall ResynchRows(unsigned cRows, PUintArray rghRows, PUINT pcRowsResynched, /* out */ 
		PHROW &prghRowsResynched, PPDBROWSTATUS prgRowStatus) = 0 ;
};

__interface IRowsetResynchSC;
typedef System::DelphiInterface<IRowsetResynchSC> _di_IRowsetResynchSC;
__interface INTERFACE_UUID("{0C733A84-2A1C-11CE-ADE5-00AA0044773D}") IRowsetResynchSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetVisibleData(unsigned HROW, unsigned HACCESSOR, /* out */ void * &pData
		) = 0 ;
	virtual HRESULT __safecall ResynchRows(unsigned cRows, PUintArray rghRows, PUINT pcRowsResynched, /* out */ 
		PHROW &prghRowsResynched, PPDBROWSTATUS prgRowStatus) = 0 ;
};

__interface IRowsetScroll;
typedef System::DelphiInterface<IRowsetScroll> _di_IRowsetScroll;
__interface INTERFACE_UUID("{0C733A7E-2A1C-11CE-ADE5-00AA0044773D}") IRowsetScroll  : public IRowsetLocate 
	
{
	
public:
	virtual HRESULT __stdcall GetApproximatePosition(unsigned hReserved, unsigned cbBookmark, Windows::PByte 
		pBookmark, PUINT pulPosition, PUINT pcRows) = 0 ;
	virtual HRESULT __stdcall GetRowsAtRatio(unsigned hReserved1, unsigned hReserved2, unsigned ulNumerator
		, unsigned ulDenominator, int cRows, /* out */ unsigned &pcRowsObtained, PHROW &prghRows) = 0 ;
};

__interface IRowsetScrollSC;
typedef System::DelphiInterface<IRowsetScrollSC> _di_IRowsetScrollSC;
__interface INTERFACE_UUID("{0C733A7E-2A1C-11CE-ADE5-00AA0044773D}") IRowsetScrollSC  : public IRowsetLocate 
	
{
	
public:
	virtual HRESULT __safecall GetApproximatePosition(unsigned hReserved, unsigned cbBookmark, Windows::PByte 
		pBookmark, PUINT pulPosition, PUINT pcRows) = 0 ;
	virtual HRESULT __safecall GetRowsAtRatio(unsigned hReserved1, unsigned hReserved2, unsigned ulNumerator
		, unsigned ulDenominator, int cRows, /* out */ unsigned &pcRowsObtained, PHROW &prghRows) = 0 ;
};

__interface IRowsetChange;
typedef System::DelphiInterface<IRowsetChange> _di_IRowsetChange;
__interface INTERFACE_UUID("{0C733A05-2A1C-11CE-ADE5-00AA0044773D}") IRowsetChange  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall DeleteRows(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUintArray 
		rgRowStatus) = 0 ;
	virtual HRESULT __stdcall SetData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
	virtual HRESULT __stdcall InsertRow(unsigned hReserved, unsigned HACCESSOR, void * pData, PHROW phRow
		) = 0 ;
};

__interface IRowsetChangeSC;
typedef System::DelphiInterface<IRowsetChangeSC> _di_IRowsetChangeSC;
__interface INTERFACE_UUID("{0C733A05-2A1C-11CE-ADE5-00AA0044773D}") IRowsetChangeSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall DeleteRows(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUintArray 
		rgRowStatus) = 0 ;
	virtual HRESULT __safecall SetData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
	virtual HRESULT __safecall InsertRow(unsigned hReserved, unsigned HACCESSOR, void * pData, PHROW phRow
		) = 0 ;
};

__interface IRowsetUpdate;
typedef System::DelphiInterface<IRowsetUpdate> _di_IRowsetUpdate;
__interface INTERFACE_UUID("{0C733A6D-2A1C-11CE-ADE5-00AA0044773D}") IRowsetUpdate  : public IRowsetChange 
	
{
	
public:
	virtual HRESULT __stdcall GetOriginalData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
	virtual HRESULT __stdcall GetPendingRows(unsigned hReserved, unsigned dwRowStatus, PUINT pcPendingRows
		, PPHROW prgPendingRows, PPDBPENDINGSTATUS prgPendingStatus) = 0 ;
	virtual HRESULT __stdcall GetRowStatus(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUintArray 
		rgPendingStatus) = 0 ;
	virtual HRESULT __stdcall Undo(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUINT pcRowsUndone
		, PPHROW prgRowsUndone, PPDBROWSTATUS prgRowStatus) = 0 ;
	virtual HRESULT __stdcall Update(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUINT pcRows
		, PPHROW prgRows, PPDBROWSTATUS prgRowStatus) = 0 ;
};

__interface IRowsetUpdateSC;
typedef System::DelphiInterface<IRowsetUpdateSC> _di_IRowsetUpdateSC;
__interface INTERFACE_UUID("{0C733A6D-2A1C-11CE-ADE5-00AA0044773D}") IRowsetUpdateSC  : public IRowsetChange 
	
{
	
public:
	virtual HRESULT __safecall GetOriginalData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
	virtual HRESULT __safecall GetPendingRows(unsigned hReserved, unsigned dwRowStatus, PUINT pcPendingRows
		, PPHROW prgPendingRows, PPDBPENDINGSTATUS prgPendingStatus) = 0 ;
	virtual HRESULT __safecall GetRowStatus(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUintArray 
		rgPendingStatus) = 0 ;
	virtual HRESULT __safecall Undo(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUINT pcRowsUndone
		, PPHROW prgRowsUndone, PPDBROWSTATUS prgRowStatus) = 0 ;
	virtual HRESULT __safecall Update(unsigned hReserved, unsigned cRows, PUintArray rghRows, PUINT pcRows
		, PPHROW prgRows, PPDBROWSTATUS prgRowStatus) = 0 ;
};

__interface IRowsetIndex;
typedef System::DelphiInterface<IRowsetIndex> _di_IRowsetIndex;
__interface INTERFACE_UUID("{0C733A82-2A1C-11CE-ADE5-00AA0044773D}") IRowsetIndex  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetIndexInfo(unsigned &pcKeyColumns, /* out */ PDBIndexColumnDesc &prgIndexColumnDesc
		, unsigned &pcIndexProperties, /* out */ PDBPropSet &prgIndexProperties) = 0 ;
	virtual HRESULT __stdcall Seek(unsigned HACCESSOR, unsigned cKeyValues, void * pData, unsigned dwSeekOptions
		) = 0 ;
	virtual HRESULT __stdcall SetRange(unsigned HACCESSOR, unsigned cStartKeyColumns, void * pStartData
		, unsigned cEndKeyColumns, void * pEndData, unsigned dwRangeOptions) = 0 ;
};

__interface IRowsetIndexSC;
typedef System::DelphiInterface<IRowsetIndexSC> _di_IRowsetIndexSC;
__interface INTERFACE_UUID("{0C733A82-2A1C-11CE-ADE5-00AA0044773D}") IRowsetIndexSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetIndexInfo(unsigned &pcKeyColumns, /* out */ PDBIndexColumnDesc &prgIndexColumnDesc
		, unsigned &pcIndexProperties, /* out */ PDBPropSet &prgIndexProperties) = 0 ;
	virtual HRESULT __safecall Seek(unsigned HACCESSOR, unsigned cKeyValues, void * pData, unsigned dwSeekOptions
		) = 0 ;
	virtual HRESULT __safecall SetRange(unsigned HACCESSOR, unsigned cStartKeyColumns, void * pStartData
		, unsigned cEndKeyColumns, void * pEndData, unsigned dwRangeOptions) = 0 ;
};

__interface IMultipleResults;
typedef System::DelphiInterface<IMultipleResults> _di_IMultipleResults;
__interface INTERFACE_UUID("{0C733A90-2A1C-11CE-ADE5-00AA0044773D}") IMultipleResults  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetResult(const _di_IUnknown punkOuter, int reserved, const GUID &riid, Windows::PInteger 
		pcRowsAffected, PIUnknown ppRowset) = 0 ;
};

__interface IMultipleResultsSC;
typedef System::DelphiInterface<IMultipleResultsSC> _di_IMultipleResultsSC;
__interface INTERFACE_UUID("{0C733A90-2A1C-11CE-ADE5-00AA0044773D}") IMultipleResultsSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetResult(const _di_IUnknown punkOuter, int reserved, const GUID &riid, 
		Windows::PInteger pcRowsAffected, PIUnknown ppRowset) = 0 ;
};

__interface IConvertType;
typedef System::DelphiInterface<IConvertType> _di_IConvertType;
__interface INTERFACE_UUID("{0C733A88-2A1C-11CE-ADE5-00AA0044773D}") IConvertType  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CanConvert(Word wFromType, Word wToType, unsigned dwConvertFlags) = 0 ;
};

__interface IConvertTypeSC;
typedef System::DelphiInterface<IConvertTypeSC> _di_IConvertTypeSC;
__interface INTERFACE_UUID("{0C733A88-2A1C-11CE-ADE5-00AA0044773D}") IConvertTypeSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CanConvert(Word wFromType, Word wToType, unsigned dwConvertFlags) = 0 ;
};

__interface ICommandPrepare;
typedef System::DelphiInterface<ICommandPrepare> _di_ICommandPrepare;
__interface INTERFACE_UUID("{0C733A26-2A1C-11CE-ADE5-00AA0044773D}") ICommandPrepare  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Prepare(unsigned cExpectedRuns) = 0 ;
	virtual HRESULT __stdcall Unprepare(void) = 0 ;
};

__interface ICommandPrepareSC;
typedef System::DelphiInterface<ICommandPrepareSC> _di_ICommandPrepareSC;
__interface INTERFACE_UUID("{0C733A26-2A1C-11CE-ADE5-00AA0044773D}") ICommandPrepareSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall Prepare(unsigned cExpectedRuns) = 0 ;
	virtual HRESULT __safecall Unprepare(void) = 0 ;
};

__interface ICommandProperties;
typedef System::DelphiInterface<ICommandProperties> _di_ICommandProperties;
__interface INTERFACE_UUID("{0C733A79-2A1C-11CE-ADE5-00AA0044773D}") ICommandProperties  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __stdcall SetProperties(unsigned cPropertySets, PDBPropSetArray rgPropertySets) = 0 
		;
};

__interface ICommandPropertiesSC;
typedef System::DelphiInterface<ICommandPropertiesSC> _di_ICommandPropertiesSC;
__interface INTERFACE_UUID("{0C733A79-2A1C-11CE-ADE5-00AA0044773D}") ICommandPropertiesSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __safecall SetProperties(unsigned cPropertySets, PDBPropSetArray rgPropertySets) = 0 
		;
};

__interface ICommand;
typedef System::DelphiInterface<ICommand> _di_ICommand;
__interface INTERFACE_UUID("{0C733A63-2A1C-11CE-ADE5-00AA0044773D}") ICommand  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall Cancel(void) = 0 ;
	virtual HRESULT __stdcall Execute(const _di_IUnknown punkOuter, const GUID &riid, DBPARAMS &pParams
		, Windows::PInteger pcRowsAffected, PIUnknown ppRowset) = 0 ;
	virtual HRESULT __stdcall GetDBSession(const GUID &riid, /* out */ _di_IUnknown &ppSession) = 0 ;
};

__interface ICommandSC;
typedef System::DelphiInterface<ICommandSC> _di_ICommandSC;
__interface INTERFACE_UUID("{0C733A63-2A1C-11CE-ADE5-00AA0044773D}") ICommandSC  : public IUnknown 
{
	
public:
	virtual HRESULT __safecall Cancel(void) = 0 ;
	virtual HRESULT __safecall Execute(const _di_IUnknown punkOuter, const GUID &riid, DBPARAMS &pParams
		, Windows::PInteger pcRowsAffected, PIUnknown ppRowset) = 0 ;
	virtual HRESULT __safecall GetDBSession(const GUID &riid, /* out */ _di_IUnknown &ppSession) = 0 ;
};

__interface ICommandWithParameters;
typedef System::DelphiInterface<ICommandWithParameters> _di_ICommandWithParameters;
__interface INTERFACE_UUID("{0C733A64-2A1C-11CE-ADE5-00AA0044773D}") ICommandWithParameters  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetParameterInfo(unsigned &pcParams, /* out */ PDBParamInfo &prgParamInfo
		, Activex::PPOleStr ppNamesBuffer) = 0 ;
	virtual HRESULT __stdcall MapParameterNames(unsigned cParamNames, Activex::POleStrList rgParamNames
		, PUintArray rgParamOrdinals) = 0 ;
	virtual HRESULT __stdcall SetParameterInfo(unsigned cParams, PUintArray rgParamOrdinals, PDBParamBindInfoArray 
		rgParamBindInfo) = 0 ;
};

__interface ICommandWithParametersSC;
typedef System::DelphiInterface<ICommandWithParametersSC> _di_ICommandWithParametersSC;
__interface INTERFACE_UUID("{0C733A64-2A1C-11CE-ADE5-00AA0044773D}") ICommandWithParametersSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetParameterInfo(unsigned &pcParams, /* out */ PDBParamInfo &prgParamInfo
		, Activex::PPOleStr ppNamesBuffer) = 0 ;
	virtual HRESULT __safecall MapParameterNames(unsigned cParamNames, Activex::POleStrList rgParamNames
		, PUintArray rgParamOrdinals) = 0 ;
	virtual HRESULT __safecall SetParameterInfo(unsigned cParams, PUintArray rgParamOrdinals, PDBParamBindInfoArray 
		rgParamBindInfo) = 0 ;
};

__interface ICommandText;
typedef System::DelphiInterface<ICommandText> _di_ICommandText;
__interface INTERFACE_UUID("{0C733A27-2A1C-11CE-ADE5-00AA0044773D}") ICommandText  : public ICommand 
	
{
	
public:
	virtual HRESULT __stdcall GetCommandText(GUID &pguidDialect, /* out */ wchar_t * &ppwszCommand) = 0 
		;
	virtual HRESULT __stdcall SetCommandText(System::PGUID rguidDialect, wchar_t * pwszCommand) = 0 ;
};

__interface ICommandTextSC;
typedef System::DelphiInterface<ICommandTextSC> _di_ICommandTextSC;
__interface INTERFACE_UUID("{0C733A27-2A1C-11CE-ADE5-00AA0044773D}") ICommandTextSC  : public ICommand 
	
{
	
public:
	virtual HRESULT __safecall GetCommandText(GUID &pguidDialect, /* out */ wchar_t * &ppwszCommand) = 0 
		;
	virtual HRESULT __safecall SetCommandText(System::PGUID rguidDialect, wchar_t * pwszCommand) = 0 ;
};

__interface IColumnsRowset;
typedef System::DelphiInterface<IColumnsRowset> _di_IColumnsRowset;
__interface INTERFACE_UUID("{0C733A10-2A1C-11CE-ADE5-00AA0044773D}") IColumnsRowset  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetAvailableColumns(unsigned &pcOptColumns, PDBID &prgOptColumns) = 0 ;
	virtual HRESULT __stdcall GetColumnsRowset(const _di_IUnknown punkOuter, unsigned cOptColumns, PDBIDArray 
		rgOptColumns, const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets, /* out */ 
		_di_IUnknown &pColRowset) = 0 ;
};

__interface IColumnsRowsetSC;
typedef System::DelphiInterface<IColumnsRowsetSC> _di_IColumnsRowsetSC;
__interface INTERFACE_UUID("{0C733A10-2A1C-11CE-ADE5-00AA0044773D}") IColumnsRowsetSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetAvailableColumns(unsigned &pcOptColumns, PDBID &prgOptColumns) = 0 ;
	virtual HRESULT __safecall GetColumnsRowset(const _di_IUnknown punkOuter, unsigned cOptColumns, PDBIDArray 
		rgOptColumns, const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets, /* out */ 
		_di_IUnknown &pColRowset) = 0 ;
};

__interface IColumnsInfo;
typedef System::DelphiInterface<IColumnsInfo> _di_IColumnsInfo;
__interface INTERFACE_UUID("{0C733A11-2A1C-11CE-ADE5-00AA0044773D}") IColumnsInfo  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetColumnInfo(unsigned &pcColumns, /* out */ PDBColumnInfo &prgInfo, /* out */ 
		wchar_t * &ppStringsBuffer) = 0 ;
	virtual HRESULT __stdcall MapColumnIDs(unsigned cColumnIDs, PDBIDArray rgColumnIDs, PUintArray rgColumns
		) = 0 ;
};

__interface IColumnsInfoSC;
typedef System::DelphiInterface<IColumnsInfoSC> _di_IColumnsInfoSC;
__interface INTERFACE_UUID("{0C733A11-2A1C-11CE-ADE5-00AA0044773D}") IColumnsInfoSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetColumnInfo(unsigned &pcColumns, /* out */ PDBColumnInfo &prgInfo, /* out */ 
		wchar_t * &ppStringsBuffer) = 0 ;
	virtual HRESULT __safecall MapColumnIDs(unsigned cColumnIDs, PDBIDArray rgColumnIDs, PUintArray rgColumns
		) = 0 ;
};

__interface IDBCreateCommand;
typedef System::DelphiInterface<IDBCreateCommand> _di_IDBCreateCommand;
__interface INTERFACE_UUID("{0C733A1D-2A1C-11CE-ADE5-00AA0044773D}") IDBCreateCommand  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateCommand(const _di_IUnknown punkOuter, const GUID &riid, /* out */ _di_IUnknown 
		&ppCommand) = 0 ;
};

__interface IDBCreateCommandSC;
typedef System::DelphiInterface<IDBCreateCommandSC> _di_IDBCreateCommandSC;
__interface INTERFACE_UUID("{0C733A1D-2A1C-11CE-ADE5-00AA0044773D}") IDBCreateCommandSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CreateCommand(const _di_IUnknown punkOuter, const GUID &riid, /* out */ 
		_di_IUnknown &ppCommand) = 0 ;
};

__interface IDBCreateSession;
typedef System::DelphiInterface<IDBCreateSession> _di_IDBCreateSession;
__interface INTERFACE_UUID("{0C733A5D-2A1C-11CE-ADE5-00AA0044773D}") IDBCreateSession  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateSession(const _di_IUnknown punkOuter, const GUID &riid, /* out */ _di_IUnknown 
		&ppDBSession) = 0 ;
};

__interface IDBCreateSessionSC;
typedef System::DelphiInterface<IDBCreateSessionSC> _di_IDBCreateSessionSC;
__interface INTERFACE_UUID("{0C733A5D-2A1C-11CE-ADE5-00AA0044773D}") IDBCreateSessionSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CreateSession(const _di_IUnknown punkOuter, const GUID &riid, /* out */ 
		_di_IUnknown &ppDBSession) = 0 ;
};

__interface ISourcesRowset;
typedef System::DelphiInterface<ISourcesRowset> _di_ISourcesRowset;
__interface INTERFACE_UUID("{0C733A1E-2A1C-11CE-ADE5-00AA0044773D}") ISourcesRowset  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetSourcesRowset(const _di_IUnknown punkOuter, const GUID &riid, unsigned 
		cPropertySets, PDBPropSetArray rgProperties, /* out */ _di_IUnknown &ppSourcesRowset) = 0 ;
};

__interface ISourcesRowsetSC;
typedef System::DelphiInterface<ISourcesRowsetSC> _di_ISourcesRowsetSC;
__interface INTERFACE_UUID("{0C733A1E-2A1C-11CE-ADE5-00AA0044773D}") ISourcesRowsetSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetSourcesRowset(const _di_IUnknown punkOuter, const GUID &riid, unsigned 
		cPropertySets, PDBPropSetArray rgProperties, /* out */ _di_IUnknown &ppSourcesRowset) = 0 ;
};

__interface IDBProperties;
typedef System::DelphiInterface<IDBProperties> _di_IDBProperties;
__interface INTERFACE_UUID("{0C733A8A-2A1C-11CE-ADE5-00AA0044773D}") IDBProperties  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __stdcall GetPropertyInfo(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertyInfoSets, /* out */ PDBPropInfoSet &prgPropertyInfoSets, Activex::PPOleStr ppDescBuffer
		) = 0 ;
	virtual HRESULT __stdcall SetProperties(unsigned cPropertySets, PDBPropSetArray rgPropertySets) = 0 
		;
};

__interface IDBPropertiesSC;
typedef System::DelphiInterface<IDBPropertiesSC> _di_IDBPropertiesSC;
__interface INTERFACE_UUID("{0C733A8A-2A1C-11CE-ADE5-00AA0044773D}") IDBPropertiesSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __safecall GetPropertyInfo(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertyInfoSets, /* out */ PDBPropInfoSet &prgPropertyInfoSets, Activex::PPOleStr ppDescBuffer
		) = 0 ;
	virtual HRESULT __safecall SetProperties(unsigned cPropertySets, PDBPropSet rgPropertySets) = 0 ;
};

__interface IDBInitialize;
typedef System::DelphiInterface<IDBInitialize> _di_IDBInitialize;
__interface INTERFACE_UUID("{0C733A8B-2A1C-11CE-ADE5-00AA0044773D}") IDBInitialize  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Initialize(void) = 0 ;
	virtual HRESULT __stdcall Uninitialize(void) = 0 ;
};

__interface IDBInitializeSC;
typedef System::DelphiInterface<IDBInitializeSC> _di_IDBInitializeSC;
__interface INTERFACE_UUID("{0C733A8B-2A1C-11CE-ADE5-00AA0044773D}") IDBInitializeSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall Initialize(void) = 0 ;
	virtual HRESULT __safecall Uninitialize(void) = 0 ;
};

__interface IDBInfo;
typedef System::DelphiInterface<IDBInfo> _di_IDBInfo;
__interface INTERFACE_UUID("{0C733A89-2A1C-11CE-ADE5-00AA0044773D}") IDBInfo  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall GetKeywords(/* out */ wchar_t * &ppwszKeywords) = 0 ;
	virtual HRESULT __stdcall GetLiteralInfo(unsigned cLiterals, PUintArray rgLiterals, unsigned &pcLiteralInfo
		, /* out */ PDBLiteralInfo &prgLiteralInfo, /* out */ wchar_t * &ppCharBuffer) = 0 ;
};

__interface IDBInfoSC;
typedef System::DelphiInterface<IDBInfoSC> _di_IDBInfoSC;
__interface INTERFACE_UUID("{0C733A89-2A1C-11CE-ADE5-00AA0044773D}") IDBInfoSC  : public IUnknown 
{
	
public:
	virtual HRESULT __safecall GetKeywords(/* out */ wchar_t * &ppwszKeywords) = 0 ;
	virtual HRESULT __safecall GetLiteralInfo(unsigned cLiterals, PUintArray rgLiterals, unsigned &pcLiteralInfo
		, /* out */ PDBLiteralInfo &prgLiteralInfo, /* out */ wchar_t * &ppCharBuffer) = 0 ;
};

__interface IDBDataSourceAdmin;
typedef System::DelphiInterface<IDBDataSourceAdmin> _di_IDBDataSourceAdmin;
__interface INTERFACE_UUID("{0C733A7A-2A1C-11CE-ADE5-00AA0044773D}") IDBDataSourceAdmin  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateDataSource(unsigned cPropertySets, PDBPropSetArray rgPropertySets, 
		const _di_IUnknown punkOuter, const GUID &riid, /* out */ _di_IUnknown &ppDBSession) = 0 ;
	virtual HRESULT __stdcall DestroyDataSource(void) = 0 ;
	virtual HRESULT __stdcall GetCreationProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, PUINT pcPropertyInfoSets, /* out */ PDBPropInfoSet &prgPropertyInfoSets, Activex::PPOleStr ppDescBuffer
		) = 0 ;
	virtual HRESULT __stdcall ModifyDataSource(unsigned cPropertySets, PDBPropSetArray rgPropertySets) = 0 
		;
};

__interface IDBDataSourceAdminSC;
typedef System::DelphiInterface<IDBDataSourceAdminSC> _di_IDBDataSourceAdminSC;
__interface INTERFACE_UUID("{0C733A7A-2A1C-11CE-ADE5-00AA0044773D}") IDBDataSourceAdminSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CreateDataSource(unsigned cPropertySets, PDBPropSetArray rgPropertySets, 
		const _di_IUnknown punkOuter, const GUID &riid, /* out */ _di_IUnknown &ppDBSession) = 0 ;
	virtual HRESULT __safecall DestroyDataSource(void) = 0 ;
	virtual HRESULT __safecall GetCreationProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, PUINT pcPropertyInfoSets, /* out */ PDBPropInfoSet &prgPropertyInfoSets, Activex::PPOleStr ppDescBuffer
		) = 0 ;
	virtual HRESULT __safecall ModifyDataSource(unsigned cPropertySets, PDBPropSetArray rgPropertySets)
		 = 0 ;
};

__interface ISessionProperties;
typedef System::DelphiInterface<ISessionProperties> _di_ISessionProperties;
__interface INTERFACE_UUID("{0C733A85-2A1C-11CE-ADE5-00AA0044773D}") ISessionProperties  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __stdcall SetProperties(unsigned cPropertySets, PDBPropSetArray rgPropertySets) = 0 
		;
};

__interface ISessionPropertiesSC;
typedef System::DelphiInterface<ISessionPropertiesSC> _di_ISessionPropertiesSC;
__interface INTERFACE_UUID("{0C733A85-2A1C-11CE-ADE5-00AA0044773D}") ISessionPropertiesSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetProperties(unsigned cPropertyIDSets, PDBPropIDSetArray rgPropertyIDSets
		, unsigned &pcPropertySets, /* out */ PDBPropSet &prgPropertySets) = 0 ;
	virtual HRESULT __safecall SetProperties(unsigned cPropertySets, PDBPropSetArray rgPropertySets) = 0 
		;
};

__interface IIndexDefinition;
typedef System::DelphiInterface<IIndexDefinition> _di_IIndexDefinition;
__interface INTERFACE_UUID("{0C733A68-2A1C-11CE-ADE5-00AA0044773D}") IIndexDefinition  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateIndex(DBID &pTableID, PDBID pIndexID, unsigned cIndexColumnDescs, PDBIndexColumnDescArray 
		rgIndexColumnDescs, unsigned cPropertySets, PDBPropSetArray rgPropertySets, PPDBID ppIndexID) = 0 
		;
	virtual HRESULT __stdcall DropIndex(DBID &TableID, PDBID pIndexID) = 0 ;
};

__interface IIndexDefinitionSC;
typedef System::DelphiInterface<IIndexDefinitionSC> _di_IIndexDefinitionSC;
__interface INTERFACE_UUID("{0C733A68-2A1C-11CE-ADE5-00AA0044773D}") IIndexDefinitionSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CreateIndex(DBID &pTableID, PDBID pIndexID, unsigned cIndexColumnDescs, 
		PDBIndexColumnDescArray rgIndexColumnDescs, unsigned cPropertySets, PDBPropSetArray rgPropertySets
		, PPDBID ppIndexID) = 0 ;
	virtual HRESULT __safecall DropIndex(DBID &TableID, PDBID pIndexID) = 0 ;
};

__interface ITableDefinition;
typedef System::DelphiInterface<ITableDefinition> _di_ITableDefinition;
__interface INTERFACE_UUID("{0C733A86-2A1C-11CE-ADE5-00AA0044773D}") ITableDefinition  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateTable(const _di_IUnknown punkOuter, PDBID pTableID, unsigned cColumnDescs
		, PDBColumnDescArray rgColumnDescs, const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets
		, PPDBID ppTableID, PIUnknown ppRowset) = 0 ;
	virtual HRESULT __stdcall DropTable(DBID &pTableID) = 0 ;
	virtual HRESULT __stdcall AddColumn(DBID &pTableID, DBCOLUMNDESC &pColumnDesc, PPDBID ppColumnID) = 0 
		;
	virtual HRESULT __stdcall DropColumn(DBID &pTableID, DBID &pColumnID) = 0 ;
};

__interface ITableDefinitionSC;
typedef System::DelphiInterface<ITableDefinitionSC> _di_ITableDefinitionSC;
__interface INTERFACE_UUID("{0C733A86-2A1C-11CE-ADE5-00AA0044773D}") ITableDefinitionSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CreateTable(const _di_IUnknown punkOuter, PDBID pTableID, unsigned cColumnDescs
		, PDBColumnDescArray rgColumnDescs, const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets
		, PPDBID ppTableID, PIUnknown ppRowset) = 0 ;
	virtual HRESULT __safecall DropTable(DBID &pTableID) = 0 ;
	virtual HRESULT __safecall AddColumn(DBID &pTableID, DBCOLUMNDESC &pColumnDesc, PPDBID ppColumnID) = 0 
		;
	virtual HRESULT __safecall DropColumn(DBID &pTableID, DBID &pColumnID) = 0 ;
};

__interface IOpenRowset;
typedef System::DelphiInterface<IOpenRowset> _di_IOpenRowset;
__interface INTERFACE_UUID("{0C733A69-2A1C-11CE-ADE5-00AA0044773D}") IOpenRowset  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall OpenRowset(const _di_IUnknown punkOuter, PDBID pTableID, PDBID pIndexID, 
		const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets, PIUnknown ppRowset) = 0 
		;
};

__interface IOpenRowsetSC;
typedef System::DelphiInterface<IOpenRowsetSC> _di_IOpenRowsetSC;
__interface INTERFACE_UUID("{0C733A69-2A1C-11CE-ADE5-00AA0044773D}") IOpenRowsetSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall OpenRowset(const _di_IUnknown punkOuter, PDBID pTableID, PDBID pIndexID, 
		const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets, PIUnknown ppRowset) = 0 
		;
};

__interface IErrorLookup;
typedef System::DelphiInterface<IErrorLookup> _di_IErrorLookup;
__interface INTERFACE_UUID("{0C733A66-2A1C-11CE-ADE5-00AA0044773D}") IErrorLookup  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetErrorDescription(HRESULT hrError, unsigned dwLookupID, Activex::PDispParams 
		pdispparams, unsigned lcid, /* out */ WideString &pbstrSource, /* out */ WideString &pbstrDescription
		) = 0 ;
	virtual HRESULT __stdcall GetHelpInfo(HRESULT hrError, unsigned dwLookupID, unsigned lcid, /* out */ 
		WideString &pbstrHelpFile, /* out */ unsigned &pdwHelpContext) = 0 ;
	virtual HRESULT __stdcall ReleaseErrors(unsigned dwDynamicErrorID) = 0 ;
};

__interface IErrorLookupSC;
typedef System::DelphiInterface<IErrorLookupSC> _di_IErrorLookupSC;
__interface INTERFACE_UUID("{0C733A66-2A1C-11CE-ADE5-00AA0044773D}") IErrorLookupSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetErrorDescription(HRESULT hrError, unsigned dwLookupID, Activex::PDispParams 
		pdispparams, unsigned lcid, /* out */ WideString &pbstrSource, /* out */ WideString &pbstrDescription
		) = 0 ;
	virtual HRESULT __safecall GetHelpInfo(HRESULT hrError, unsigned dwLookupID, unsigned lcid, /* out */ 
		WideString &pbstrHelpFile, /* out */ unsigned &pdwHelpContext) = 0 ;
	virtual HRESULT __safecall ReleaseErrors(unsigned dwDynamicErrorID) = 0 ;
};

__interface ISQLErrorInfo;
typedef System::DelphiInterface<ISQLErrorInfo> _di_ISQLErrorInfo;
__interface INTERFACE_UUID("{0C733A74-2A1C-11CE-ADE5-00AA0044773D}") ISQLErrorInfo  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetSQLInfo(/* out */ WideString &pbstrSQLState, /* out */ int &plNativeError
		) = 0 ;
};

__interface ISQLErrorInfoSC;
typedef System::DelphiInterface<ISQLErrorInfoSC> _di_ISQLErrorInfoSC;
__interface INTERFACE_UUID("{0C733A74-2A1C-11CE-ADE5-00AA0044773D}") ISQLErrorInfoSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetSQLInfo(/* out */ WideString &pbstrSQLState, /* out */ int &plNativeError
		) = 0 ;
};

__interface IGetDataSource;
typedef System::DelphiInterface<IGetDataSource> _di_IGetDataSource;
__interface INTERFACE_UUID("{0C733A75-2A1C-11CE-ADE5-00AA0044773D}") IGetDataSource  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetDataSource(const GUID &riid, /* out */ _di_IUnknown &ppDataSource) = 0 
		;
};

__interface IGetDataSourceSC;
typedef System::DelphiInterface<IGetDataSourceSC> _di_IGetDataSourceSC;
__interface INTERFACE_UUID("{0C733A75-2A1C-11CE-ADE5-00AA0044773D}") IGetDataSourceSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetDataSource(const GUID &riid, /* out */ _di_IUnknown &ppDataSource) = 0 
		;
};

__interface ITransactionLocal;
typedef System::DelphiInterface<ITransactionLocal> _di_ITransactionLocal;
__interface INTERFACE_UUID("{0C733A5F-2A1C-11CE-ADE5-00AA0044773D}") ITransactionLocal  : public ITransaction 
	
{
	
public:
	virtual HRESULT __stdcall GetOptionsObject(/* out */ _di_ITransactionOptions &ppOptions) = 0 ;
	virtual HRESULT __stdcall StartTransaction(int isoLevel, unsigned isoFlags, const _di_ITransactionOptions 
		pOtherOptions, PUINT pulTransactionLevel) = 0 ;
};

__interface ITransactionLocalSC;
typedef System::DelphiInterface<ITransactionLocalSC> _di_ITransactionLocalSC;
__interface INTERFACE_UUID("{0C733A5F-2A1C-11CE-ADE5-00AA0044773D}") ITransactionLocalSC  : public ITransaction 
	
{
	
public:
	virtual HRESULT __safecall GetOptionsObject(/* out */ _di_ITransactionOptions &ppOptions) = 0 ;
	virtual HRESULT __safecall StartTransaction(int isoLevel, unsigned isoFlags, const _di_ITransactionOptions 
		pOtherOptions, PUINT pulTransactionLevel) = 0 ;
};

__interface ITransactionJoin;
typedef System::DelphiInterface<ITransactionJoin> _di_ITransactionJoin;
__interface INTERFACE_UUID("{0C733A5E-2A1C-11CE-ADE5-00AA0044773D}") ITransactionJoin  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetOptionsObject(/* out */ _di_ITransactionOptions &ppOptions) = 0 ;
	virtual HRESULT __stdcall JoinTransaction(const _di_IUnknown punkTransactionCoord, int isoLevel, unsigned 
		isoFlags, const _di_ITransactionOptions pOtherOptions) = 0 ;
};

__interface ITransactionJoinSC;
typedef System::DelphiInterface<ITransactionJoinSC> _di_ITransactionJoinSC;
__interface INTERFACE_UUID("{0C733A5E-2A1C-11CE-ADE5-00AA0044773D}") ITransactionJoinSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetOptionsObject(/* out */ _di_ITransactionOptions &ppOptions) = 0 ;
	virtual HRESULT __safecall JoinTransaction(const _di_IUnknown punkTransactionCoord, int isoLevel, unsigned 
		isoFlags, const _di_ITransactionOptions pOtherOptions) = 0 ;
};

__interface ITransactionObject;
typedef System::DelphiInterface<ITransactionObject> _di_ITransactionObject;
__interface INTERFACE_UUID("{0C733A60-2A1C-11CE-ADE5-00AA0044773D}") ITransactionObject  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetTransactionObject(unsigned ulTransactionLevel, /* out */ _di_ITransaction 
		&ppTransactionObject) = 0 ;
};

__interface ITransactionObjectSC;
typedef System::DelphiInterface<ITransactionObjectSC> _di_ITransactionObjectSC;
__interface INTERFACE_UUID("{0C733A60-2A1C-11CE-ADE5-00AA0044773D}") ITransactionObjectSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetTransactionObject(unsigned ulTransactionLevel, /* out */ _di_ITransaction 
		&ppTransactionObject) = 0 ;
};

__interface IDBAsynchStatus;
typedef System::DelphiInterface<IDBAsynchStatus> _di_IDBAsynchStatus;
__interface INTERFACE_UUID("{0C733A95-2A1C-11CE-ADE5-00AA0044773D}") IDBAsynchStatus  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall Abort(unsigned HCHAPTER, unsigned eOperation) = 0 ;
	virtual HRESULT __stdcall GetStatus(unsigned HCHAPTER, unsigned eOperation, PUINT pulProgress, PUINT 
		pulProgressMax, PDBASYNCHPHASE peAsynchPhase, Activex::PPOleStr ppwszStatusText) = 0 ;
};

__interface IDBAsynchStatusSC;
typedef System::DelphiInterface<IDBAsynchStatusSC> _di_IDBAsynchStatusSC;
__interface INTERFACE_UUID("{0C733A95-2A1C-11CE-ADE5-00AA0044773D}") IDBAsynchStatusSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall Abort(unsigned HCHAPTER, unsigned eOperation) = 0 ;
	virtual HRESULT __safecall GetStatus(unsigned HCHAPTER, unsigned eOperation, PUINT pulProgress, PUINT 
		pulProgressMax, PDBASYNCHPHASE peAsynchPhase, Activex::PPOleStr ppwszStatusText) = 0 ;
};

__interface IRowsetFind;
typedef System::DelphiInterface<IRowsetFind> _di_IRowsetFind;
__interface INTERFACE_UUID("{0C733A9D-2A1C-11CE-ADE5-00AA0044773D}") IRowsetFind  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall FindNextRow(unsigned HCHAPTER, unsigned HACCESSOR, void * pFindValue, unsigned 
		CompareOp, unsigned cbBookmark, Windows::PByte pBookmark, int lRowsOffset, int cRows, unsigned &pcRowsObtained
		, /* out */ PHROW &prghRows) = 0 ;
};

__interface IRowsetFindSC;
typedef System::DelphiInterface<IRowsetFindSC> _di_IRowsetFindSC;
__interface INTERFACE_UUID("{0C733A9D-2A1C-11CE-ADE5-00AA0044773D}") IRowsetFindSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall FindNextRow(unsigned HCHAPTER, unsigned HACCESSOR, void * pFindValue, unsigned 
		CompareOp, unsigned cbBookmark, Windows::PByte pBookmark, int lRowsOffset, int cRows, unsigned &pcRowsObtained
		, /* out */ PHROW &prghRows) = 0 ;
};

__interface IRowPosition;
typedef System::DelphiInterface<IRowPosition> _di_IRowPosition;
__interface INTERFACE_UUID("{0C733A94-2A1C-11CE-ADE5-00AA0044773D}") IRowPosition  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall ClearRowPosition(void) = 0 ;
	virtual HRESULT __stdcall GetRowPosition(/* out */ unsigned &phChapter, /* out */ unsigned &phRow, 
		/* out */ unsigned &pdwPositionFlags) = 0 ;
	virtual HRESULT __stdcall GetRowset(const GUID &riid, /* out */ _di_IUnknown &ppRowset) = 0 ;
	virtual HRESULT __stdcall Initialize(const _di_IUnknown pRowset) = 0 ;
	virtual HRESULT __stdcall SetRowPosition(unsigned HCHAPTER, unsigned HROW, unsigned dwPositionFlags
		) = 0 ;
};

__interface IRowPositionSC;
typedef System::DelphiInterface<IRowPositionSC> _di_IRowPositionSC;
__interface INTERFACE_UUID("{0C733A94-2A1C-11CE-ADE5-00AA0044773D}") IRowPositionSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall ClearRowPosition(void) = 0 ;
	virtual HRESULT __safecall GetRowPosition(/* out */ unsigned &phChapter, /* out */ unsigned &phRow, 
		/* out */ unsigned &pdwPositionFlags) = 0 ;
	virtual HRESULT __safecall GetRowset(const GUID &riid, /* out */ _di_IUnknown &ppRowset) = 0 ;
	virtual HRESULT __safecall Initialize(const _di_IUnknown pRowset) = 0 ;
	virtual HRESULT __safecall SetRowPosition(unsigned HCHAPTER, unsigned HROW, unsigned dwPositionFlags
		) = 0 ;
};

__interface IRowPositionChange;
typedef System::DelphiInterface<IRowPositionChange> _di_IRowPositionChange;
__interface INTERFACE_UUID("{0997A571-126E-11D0-9F8A-00A0C9A0631E}") IRowPositionChange  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall OnRowPositionChange(unsigned eReason, unsigned ePhase, BOOL fCantDeny) = 0 
		;
};

__interface IRowPositionChangeSC;
typedef System::DelphiInterface<IRowPositionChangeSC> _di_IRowPositionChangeSC;
__interface INTERFACE_UUID("{0997A571-126E-11D0-9F8A-00A0C9A0631E}") IRowPositionChangeSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall OnRowPositionChange(unsigned eReason, unsigned ePhase, BOOL fCantDeny) = 0 
		;
};

__interface IViewRowset;
typedef System::DelphiInterface<IViewRowset> _di_IViewRowset;
__interface INTERFACE_UUID("{0C733A97-2A1C-11CE-ADE5-00AA0044773D}") IViewRowset  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetSpecification(const GUID &riid, /* out */ _di_IUnknown &ppObject) = 0 
		;
	virtual HRESULT __stdcall OpenViewRowset(const _di_IUnknown punkOuter, const GUID &riid, /* out */ 
		_di_IUnknown &ppRowset) = 0 ;
};

__interface IViewRowsetSC;
typedef System::DelphiInterface<IViewRowsetSC> _di_IViewRowsetSC;
__interface INTERFACE_UUID("{0C733A97-2A1C-11CE-ADE5-00AA0044773D}") IViewRowsetSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetSpecification(const GUID &riid, /* out */ _di_IUnknown &ppObject) = 0 
		;
	virtual HRESULT __safecall OpenViewRowset(const _di_IUnknown punkOuter, const GUID &riid, /* out */ 
		_di_IUnknown &ppRowset) = 0 ;
};

__interface IViewChapter;
typedef System::DelphiInterface<IViewChapter> _di_IViewChapter;
__interface INTERFACE_UUID("{0C733A98-2A1C-11CE-ADE5-00AA0044773D}") IViewChapter  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetSpecification(const GUID &riid, /* out */ _di_IUnknown &ppRowset) = 0 
		;
	virtual HRESULT __stdcall OpenViewChapter(unsigned hSource, /* out */ unsigned &phViewChapter) = 0 
		;
};

__interface IViewChapterSC;
typedef System::DelphiInterface<IViewChapterSC> _di_IViewChapterSC;
__interface INTERFACE_UUID("{0C733A98-2A1C-11CE-ADE5-00AA0044773D}") IViewChapterSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetSpecification(const GUID &riid, /* out */ _di_IUnknown &ppRowset) = 0 
		;
	virtual HRESULT __safecall OpenViewChapter(unsigned hSource, /* out */ unsigned &phViewChapter) = 0 
		;
};

__interface IViewSort;
typedef System::DelphiInterface<IViewSort> _di_IViewSort;
__interface INTERFACE_UUID("{0C733A9A-2A1C-11CE-ADE5-00AA0044773D}") IViewSort  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall GetSortOrder(/* out */ unsigned &pcValues, /* out */ PUintArray &prgColumns
		, /* out */ PUintArray &prgOrders) = 0 ;
	virtual HRESULT __stdcall SetSortOrder(unsigned cValues, PUintArray rgColumns, PUintArray rgOrders)
		 = 0 ;
};

__interface IViewSortSC;
typedef System::DelphiInterface<IViewSortSC> _di_IViewSortSC;
__interface INTERFACE_UUID("{0C733A9A-2A1C-11CE-ADE5-00AA0044773D}") IViewSortSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetSortOrder(/* out */ unsigned &pcValues, /* out */ PUintArray &prgColumns
		, /* out */ PUintArray &prgOrders) = 0 ;
	virtual HRESULT __safecall SetSortOrder(unsigned cValues, PUintArray rgColumns, PUintArray rgOrders
		) = 0 ;
};

__interface IViewFilter;
typedef System::DelphiInterface<IViewFilter> _di_IViewFilter;
__interface INTERFACE_UUID("{0C733A9B-2A1C-11CE-ADE5-00AA0044773D}") IViewFilter  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetFilter(unsigned HACCESSOR, /* out */ unsigned &pcRows, /* out */ PDBCOMPAREOP 
		&pCompareOps, void * pCriteriaData) = 0 ;
	virtual HRESULT __stdcall GetFilterBindings(/* out */ unsigned &pcBindings, /* out */ PDBBinding &prgBindings
		) = 0 ;
	virtual HRESULT __stdcall SetFilter(unsigned HACCESSOR, unsigned cRows, unsigned &CompareOps, void * 
		pCriteriaData) = 0 ;
};

__interface IViewFilterSC;
typedef System::DelphiInterface<IViewFilterSC> _di_IViewFilterSC;
__interface INTERFACE_UUID("{0C733A9B-2A1C-11CE-ADE5-00AA0044773D}") IViewFilterSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetFilter(unsigned HACCESSOR, /* out */ unsigned &pcRows, /* out */ PDBCOMPAREOP 
		&pCompareOps, void * pCriteriaData) = 0 ;
	virtual HRESULT __safecall GetFilterBindings(/* out */ unsigned &pcBindings, /* out */ PDBBinding &
		prgBindings) = 0 ;
	virtual HRESULT __safecall SetFilter(unsigned HACCESSOR, unsigned cRows, unsigned &CompareOps, void * 
		pCriteriaData) = 0 ;
};

__interface IRowsetView;
typedef System::DelphiInterface<IRowsetView> _di_IRowsetView;
__interface INTERFACE_UUID("{0C733A99-2A1C-11CE-ADE5-00AA0044773D}") IRowsetView  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall CreateView(const _di_IUnknown punkOuter, const GUID &riid, /* out */ _di_IUnknown 
		&ppView) = 0 ;
	virtual HRESULT __stdcall GetView(unsigned HCHAPTER, const GUID &riid, /* out */ unsigned &phChapterSource
		, /* out */ _di_IUnknown &ppView) = 0 ;
};

__interface IRowsetViewSC;
typedef System::DelphiInterface<IRowsetViewSC> _di_IRowsetViewSC;
__interface INTERFACE_UUID("{0C733A99-2A1C-11CE-ADE5-00AA0044773D}") IRowsetViewSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall CreateView(const _di_IUnknown punkOuter, const GUID &riid, /* out */ _di_IUnknown 
		&ppView) = 0 ;
	virtual HRESULT __safecall GetView(unsigned HCHAPTER, const GUID &riid, /* out */ unsigned &phChapterSource
		, /* out */ _di_IUnknown &ppView) = 0 ;
};

__interface IMDFind;
typedef System::DelphiInterface<IMDFind> _di_IMDFind;
__interface INTERFACE_UUID("{A07CCCD2-8148-11D0-87BB-00C04FC33942}") IMDFind  : public IUnknown 
{
	
public:
	virtual HRESULT __stdcall FindCell(unsigned ulStartingOrdinal, unsigned cMembers, Activex::PPOleStr 
		rgpwszMember, /* out */ unsigned &pulCellOrdinal) = 0 ;
	virtual HRESULT __stdcall FindTuple(unsigned ulAxisIdentifier, unsigned ulStartingOrdinal, unsigned 
		cMembers, Activex::PPOleStr rgpwszMember, /* out */ unsigned &pulTupleOrdinal) = 0 ;
};

__interface IMDFindSC;
typedef System::DelphiInterface<IMDFindSC> _di_IMDFindSC;
__interface INTERFACE_UUID("{A07CCCD2-8148-11D0-87BB-00C04FC33942}") IMDFindSC  : public IUnknown 
{
	
public:
	virtual HRESULT __safecall FindCell(unsigned ulStartingOrdinal, unsigned cMembers, Activex::PPOleStr 
		rgpwszMember, /* out */ unsigned &pulCellOrdinal) = 0 ;
	virtual HRESULT __safecall FindTuple(unsigned ulAxisIdentifier, unsigned ulStartingOrdinal, unsigned 
		cMembers, Activex::PPOleStr rgpwszMember, /* out */ unsigned &pulTupleOrdinal) = 0 ;
};

__interface IMDRangeRowset;
typedef System::DelphiInterface<IMDRangeRowset> _di_IMDRangeRowset;
__interface INTERFACE_UUID("{0C733AA0-2A1C-11CE-ADE5-00AA0044773D}") IMDRangeRowset  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetRangeRowset(const _di_IUnknown punkOuter, unsigned ulStartCell, unsigned 
		ulEndCell, const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets, /* out */ _di_IUnknown 
		&ppRowset) = 0 ;
};

__interface IMDRangeRowsetSC;
typedef System::DelphiInterface<IMDRangeRowsetSC> _di_IMDRangeRowsetSC;
__interface INTERFACE_UUID("{0C733AA0-2A1C-11CE-ADE5-00AA0044773D}") IMDRangeRowsetSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetRangeRowset(const _di_IUnknown punkOuter, unsigned ulStartCell, unsigned 
		ulEndCell, const GUID &riid, unsigned cPropertySets, PDBPropSetArray rgPropertySets, /* out */ _di_IUnknown 
		&ppRowset) = 0 ;
};

__interface IAlterTable;
typedef System::DelphiInterface<IAlterTable> _di_IAlterTable;
__interface INTERFACE_UUID("{0C733AA5-2A1C-11CE-ADE5-00AA0044773D}") IAlterTable  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall AlterColumn(DBID &pTableID, DBID &pColumnID, unsigned ColumnDescFlags, DBCOLUMNDESC 
		&pColumnDesc) = 0 ;
	virtual HRESULT __stdcall AlterTable(DBID &pTableID, PDBID pNewTableId, unsigned cPropertySets, PDBPropSetArray 
		rgPropertySets) = 0 ;
};

__interface IAlterTableSC;
typedef System::DelphiInterface<IAlterTableSC> _di_IAlterTableSC;
__interface INTERFACE_UUID("{0C733AA5-2A1C-11CE-ADE5-00AA0044773D}") IAlterTableSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall AlterColumn(DBID &pTableID, DBID &pColumnID, unsigned ColumnDescFlags, DBCOLUMNDESC 
		&pColumnDesc) = 0 ;
	virtual HRESULT __safecall AlterTable(DBID &pTableID, PDBID pNewTableId, unsigned cPropertySets, PDBPropSetArray 
		rgPropertySets) = 0 ;
};

__interface IAlterIndex;
typedef System::DelphiInterface<IAlterIndex> _di_IAlterIndex;
__interface INTERFACE_UUID("{0C733AA6-2A1C-11CE-ADE5-00AA0044773D}") IAlterIndex  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall AlterIndex(DBID &pTableID, DBID &pIndexID, PDBID pNewIndexId, unsigned cPropertySets
		, PDBPropSetArray rgPropertySet) = 0 ;
};

__interface IAlterIndexSC;
typedef System::DelphiInterface<IAlterIndexSC> _di_IAlterIndexSC;
__interface INTERFACE_UUID("{0C733AA6-2A1C-11CE-ADE5-00AA0044773D}") IAlterIndexSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall AlterIndex(DBID &pTableID, DBID &pIndexID, PDBID pNewIndexId, unsigned cPropertySets
		, PDBPropSetArray rgPropertySet) = 0 ;
};

__interface ICommandPersist;
typedef System::DelphiInterface<ICommandPersist> _di_ICommandPersist;
__interface INTERFACE_UUID("{0C733AA7-2A1C-11CE-ADE5-00AA0044773D}") ICommandPersist  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall DeleteCommand(DBID &pCommandID) = 0 ;
	virtual HRESULT __stdcall GetCurrentCommand(/* out */ PDBID &ppCommandID) = 0 ;
	virtual HRESULT __stdcall LoadCommand(DBID &pCommandID, unsigned dwFlags) = 0 ;
	virtual HRESULT __stdcall SaveCommand(DBID &pCommandID, unsigned dwFlags) = 0 ;
};

__interface ICommandPersistSC;
typedef System::DelphiInterface<ICommandPersistSC> _di_ICommandPersistSC;
__interface INTERFACE_UUID("{0C733AA7-2A1C-11CE-ADE5-00AA0044773D}") ICommandPersistSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall DeleteCommand(DBID &pCommandID) = 0 ;
	virtual HRESULT __safecall GetCurrentCommand(/* out */ PDBID &ppCommandID) = 0 ;
	virtual HRESULT __safecall LoadCommand(DBID &pCommandID, unsigned dwFlags) = 0 ;
	virtual HRESULT __safecall SaveCommand(DBID &pCommandID, unsigned dwFlags) = 0 ;
};

__interface IRowsetChapterMember;
typedef System::DelphiInterface<IRowsetChapterMember> _di_IRowsetChapterMember;
__interface INTERFACE_UUID("{0C733AA8-2A1C-11CE-ADE5-00AA0044773D}") IRowsetChapterMember  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall IsRowInChapter(unsigned HCHAPTER, unsigned HROW) = 0 ;
};

__interface IRowsetChapterMemberSC;
typedef System::DelphiInterface<IRowsetChapterMemberSC> _di_IRowsetChapterMemberSC;
__interface INTERFACE_UUID("{0C733AA8-2A1C-11CE-ADE5-00AA0044773D}") IRowsetChapterMemberSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall IsRowInChapter(unsigned HCHAPTER, unsigned HROW) = 0 ;
};

__interface IRowsetRefresh;
typedef System::DelphiInterface<IRowsetRefresh> _di_IRowsetRefresh;
__interface INTERFACE_UUID("{0C733AA9-2A1C-11CE-ADE5-00AA0044773D}") IRowsetRefresh  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall RefreshVisibleData(unsigned HCHAPTER, unsigned cRows, PUintArray rghRows, 
		BOOL fOverWrite, PUINT pcRowsRefreshed, /* out */ PHROW &prghRowsRefreshed, PPDBROWSTATUS prgRowStatus
		) = 0 ;
	virtual HRESULT __stdcall GetLastVisibleData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 ;
		
};

__interface IRowsetRefreshSC;
typedef System::DelphiInterface<IRowsetRefreshSC> _di_IRowsetRefreshSC;
__interface INTERFACE_UUID("{0C733AA9-2A1C-11CE-ADE5-00AA0044773D}") IRowsetRefreshSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall RefreshVisibleData(unsigned HCHAPTER, unsigned cRows, PUintArray rghRows
		, BOOL fOverWrite, PUINT pcRowsRefreshed, /* out */ PHROW &prghRowsRefreshed, PPDBROWSTATUS prgRowStatus
		) = 0 ;
	virtual HRESULT __safecall GetLastVisibleData(unsigned HROW, unsigned HACCESSOR, void * pData) = 0 
		;
};

__interface IParentRowset;
typedef System::DelphiInterface<IParentRowset> _di_IParentRowset;
__interface INTERFACE_UUID("{0C733AAA-2A1C-11CE-ADE5-00AA0044773D}") IParentRowset  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetChildRowset(const _di_IUnknown punkOuter, unsigned iOrdinal, const GUID 
		&riid, /* out */ _di_IUnknown &ppRowset) = 0 ;
};

__interface IParentRowsetSC;
typedef System::DelphiInterface<IParentRowsetSC> _di_IParentRowsetSC;
__interface INTERFACE_UUID("{0C733AAA-2A1C-11CE-ADE5-00AA0044773D}") IParentRowsetSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetChildRowset(const _di_IUnknown punkOuter, unsigned iOrdinal, const GUID 
		&riid, /* out */ _di_IUnknown &ppRowset) = 0 ;
};

__interface ITrusteeGroupAdmin;
typedef System::DelphiInterface<ITrusteeGroupAdmin> _di_ITrusteeGroupAdmin;
__interface INTERFACE_UUID("{0C733AA2-2A1C-11CE-ADE5-00AA0044773D}") ITrusteeGroupAdmin  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall AddMember(PTrusteeW pMembershipTrustee, PTrusteeW pMemberTrustee) = 0 ;
	virtual HRESULT __stdcall DeleteMember(PTrusteeW pMembershipTrustee, PTrusteeW pMemberTrustee) = 0 
		;
	virtual HRESULT __stdcall IsMember(PTrusteeW pMembershipTrustee, PTrusteeW pMemberTrustee, /* out */ 
		BOOL &pfStatus) = 0 ;
	virtual HRESULT __stdcall GetMembers(PTrusteeW pMembershipTrustee, PUINT pcMembers, /* out */ PTrusteeW 
		&prgMembers) = 0 ;
	virtual HRESULT __stdcall GetMemberships(PTrusteeW pTrustee, PUINT pcMemberships, /* out */ PTrusteeW 
		&prgMemberships) = 0 ;
};

__interface ITrusteeGroupAdminSC;
typedef System::DelphiInterface<ITrusteeGroupAdminSC> _di_ITrusteeGroupAdminSC;
__interface INTERFACE_UUID("{0C733AA2-2A1C-11CE-ADE5-00AA0044773D}") ITrusteeGroupAdminSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall AddMember(PTrusteeW pMembershipTrustee, PTrusteeW pMemberTrustee) = 0 ;
	virtual HRESULT __safecall DeleteMember(PTrusteeW pMembershipTrustee, PTrusteeW pMemberTrustee) = 0 
		;
	virtual HRESULT __safecall IsMember(PTrusteeW pMembershipTrustee, PTrusteeW pMemberTrustee, /* out */ 
		BOOL &pfStatus) = 0 ;
	virtual HRESULT __safecall GetMembers(PTrusteeW pMembershipTrustee, PUINT pcMembers, /* out */ PTrusteeW 
		&prgMembers) = 0 ;
	virtual HRESULT __safecall GetMemberships(PTrusteeW pTrustee, PUINT pcMemberships, /* out */ PTrusteeW 
		&prgMemberships) = 0 ;
};

__interface IObjectAccessControl;
typedef System::DelphiInterface<IObjectAccessControl> _di_IObjectAccessControl;
__interface INTERFACE_UUID("{0C733AA3-2A1C-11CE-ADE5-00AA0044773D}") IObjectAccessControl  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetObjectAccessRights(PSecObject pObject, PUINT pcAccessEntries, PExplicitAccessW 
		prgAccessEntries) = 0 ;
	virtual HRESULT __stdcall GetObjectOwner(PSecObject pObject, PPTrusteeW ppOwner) = 0 ;
	virtual HRESULT __stdcall IsObjectAccessAllowed(PSecObject pObject, PExplicitAccessW pAccessEntry, 
		PBOOL pfResult) = 0 ;
	virtual HRESULT __stdcall SetObjectAccessRights(PSecObject pObject, unsigned cAccessEntries, PExplicitAccessW 
		prgAccessEntries) = 0 ;
	virtual HRESULT __stdcall SetObjectOwner(PSecObject pObject, PTrusteeW pOwner) = 0 ;
};

__interface IObjectAccessControlSC;
typedef System::DelphiInterface<IObjectAccessControlSC> _di_IObjectAccessControlSC;
__interface INTERFACE_UUID("{0C733AA3-2A1C-11CE-ADE5-00AA0044773D}") IObjectAccessControlSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetObjectAccessRights(PSecObject pObject, PUINT pcAccessEntries, PExplicitAccessW 
		prgAccessEntries) = 0 ;
	virtual HRESULT __safecall GetObjectOwner(PSecObject pObject, PPTrusteeW ppOwner) = 0 ;
	virtual HRESULT __safecall IsObjectAccessAllowed(PSecObject pObject, PExplicitAccessW pAccessEntry, 
		PBOOL pfResult) = 0 ;
	virtual HRESULT __safecall SetObjectAccessRights(PSecObject pObject, unsigned cAccessEntries, PExplicitAccessW 
		prgAccessEntries) = 0 ;
	virtual HRESULT __safecall SetObjectOwner(PSecObject pObject, PTrusteeW pOwner) = 0 ;
};

__interface ISecurityInfo;
typedef System::DelphiInterface<ISecurityInfo> _di_ISecurityInfo;
__interface INTERFACE_UUID("{0C733AA4-2A1C-11CE-ADE5-00AA0044773D}") ISecurityInfo  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetCurrentTrustee(PPTrusteeW ppTrustee) = 0 ;
	virtual HRESULT __stdcall GetObjectTypes(/* out */ unsigned &cObjectTypes, /* out */ System::PGUID 
		&rgObjectTypes) = 0 ;
	virtual HRESULT __stdcall GetPermissions(const GUID ObjectType, /* out */ unsigned &pPermissions) = 0 
		;
};

__interface ISecurityInfoSC;
typedef System::DelphiInterface<ISecurityInfoSC> _di_ISecurityInfoSC;
__interface INTERFACE_UUID("{0C733AA4-2A1C-11CE-ADE5-00AA0044773D}") ISecurityInfoSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetCurrentTrustee(PPTrusteeW ppTrustee) = 0 ;
	virtual HRESULT __safecall GetObjectTypes(/* out */ unsigned &cObjectTypes, /* out */ System::PGUID 
		&rgObjectTypes) = 0 ;
	virtual HRESULT __safecall GetPermissions(const GUID ObjectType, /* out */ unsigned &pPermissions) = 0 
		;
};

__interface IDBPromptInitialize;
typedef System::DelphiInterface<IDBPromptInitialize> _di_IDBPromptInitialize;
__interface INTERFACE_UUID("{2206CCB0-19C1-11D1-89E0-00C04FD7A829}") IDBPromptInitialize  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall PromptDataSource(const _di_IUnknown pUnkOuter, HWND hWndParent, int dwPromptOptions
		, unsigned cSourceTypeFilter, PDBSOURCETYPE rgSourceTypeFilter, wchar_t * pszProviderFilter, const 
		GUID &riid, _di_IUnknown &DataSource) = 0 ;
	virtual HRESULT __stdcall PromptFileName(HWND hWndParent, int dwPromptOptions, wchar_t * pwszInitialDirectory
		, wchar_t * pwszInitialFile, wchar_t * &ppwszSelectedFile) = 0 ;
};

__interface IDBPromptInitializeSC;
typedef System::DelphiInterface<IDBPromptInitializeSC> _di_IDBPromptInitializeSC;
__interface INTERFACE_UUID("{2206CCB0-19C1-11D1-89E0-00C04FD7A829}") IDBPromptInitializeSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall PromptDataSource(const _di_IUnknown pUnkOuter, HWND hWndParent, int dwPromptOptions
		, unsigned cSourceTypeFilter, PDBSOURCETYPE rgSourceTypeFilter, wchar_t * pszProviderFilter, const 
		GUID &riid, _di_IUnknown &DataSource) = 0 ;
	virtual HRESULT __safecall PromptFileName(HWND hWndParent, int dwPromptOptions, wchar_t * pwszInitialDirectory
		, wchar_t * pwszInitialFile, wchar_t * &ppwszSelectedFile) = 0 ;
};

__interface IDataInitialize;
typedef System::DelphiInterface<IDataInitialize> _di_IDataInitialize;
__interface INTERFACE_UUID("{2206CCB1-19C1-11D1-89E0-00C04FD7A829}") IDataInitialize  : public IUnknown 
	
{
	
public:
	virtual HRESULT __stdcall GetDataSource(const _di_IUnknown pUnkOuter, unsigned dwClsCtx, wchar_t * 
		pwszInitializationString, const GUID &riid, _di_IUnknown &DataSource) = 0 ;
	virtual HRESULT __stdcall GetInitializationString(const _di_IUnknown DataSource, bool fIncludePassword
		, /* out */ wchar_t * &pwszInitString) = 0 ;
	virtual HRESULT __stdcall CreateDBInstance(const GUID &clsidProvider, const _di_IUnknown pUnkOuter, 
		unsigned dwClsCtx, wchar_t * pwszReserved, const GUID riid, _di_IUnknown &DataSource) = 0 ;
	virtual HRESULT __stdcall CreateDBInstanceEx(const GUID &clsidProvider, const _di_IUnknown pUnkOuter
		, unsigned dwClsCtx, wchar_t * pwszReserved, Activex::PCoServerInfo pServerInfo, unsigned cmq, Activex::PMultiQI 
		rgmqResults) = 0 ;
	virtual HRESULT __stdcall LoadStringFromStorage(wchar_t * pwszFileName, /* out */ wchar_t * &pwszInitializationString
		) = 0 ;
	virtual HRESULT __stdcall WriteStringToStorage(wchar_t * pwszFileName, wchar_t * pwszInitializationString
		, unsigned dwCreationDisposition) = 0 ;
};

__interface IDataInitializeSC;
typedef System::DelphiInterface<IDataInitializeSC> _di_IDataInitializeSC;
__interface INTERFACE_UUID("{2206CCB1-19C1-11D1-89E0-00C04FD7A829}") IDataInitializeSC  : public IUnknown 
	
{
	
public:
	virtual HRESULT __safecall GetDataSource(const _di_IUnknown pUnkOuter, unsigned dwClsCtx, wchar_t * 
		pwszInitializationString, const GUID &riid, _di_IUnknown &DataSource) = 0 ;
	virtual HRESULT __safecall GetInitializationString(const _di_IUnknown DataSource, bool fIncludePassword
		, /* out */ wchar_t * &pwszInitString) = 0 ;
	virtual HRESULT __safecall CreateDBInstance(const GUID &clsidProvider, const _di_IUnknown pUnkOuter
		, unsigned dwClsCtx, wchar_t * pwszReserved, const GUID riid, _di_IUnknown &DataSource) = 0 ;
	virtual HRESULT __safecall CreateDBInstanceEx(const GUID &clsidProvider, const _di_IUnknown pUnkOuter
		, unsigned dwClsCtx, wchar_t * pwszReserved, Activex::PCoServerInfo pServerInfo, unsigned cmq, Activex::PMultiQI 
		rgmqResults) = 0 ;
	virtual HRESULT __safecall LoadStringFromStorage(wchar_t * pwszFileName, /* out */ wchar_t * &pwszInitializationString
		) = 0 ;
	virtual HRESULT __safecall WriteStringToStorage(wchar_t * pwszFileName, wchar_t * pwszInitializationString
		, unsigned dwCreationDisposition) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE GUID CLSID_OLEDB_ENUMERATOR;
extern PACKAGE GUID CLSID_EXTENDEDERRORINFO;
extern PACKAGE GUID CLSID_MSDAVTM;
extern PACKAGE GUID CLSID_OLEDB_CONVERSIONLIBRARY;
extern PACKAGE GUID CLSID_OLEDB_ROWPOSITIONLIBRARY;
extern PACKAGE GUID CLSID_DATALINKS;
extern PACKAGE GUID IID_ITransactionOptions;
extern PACKAGE GUID IID_ITransactionDispenser;
extern PACKAGE GUID IID_ITransactionOutcomeEvents;
extern PACKAGE GUID IID_IAccessor;
extern PACKAGE GUID IID_IRowset;
extern PACKAGE GUID IID_IRowsetInfo;
extern PACKAGE GUID IID_IRowsetLocate;
extern PACKAGE GUID IID_IRowsetResynch;
extern PACKAGE GUID IID_IRowsetScroll;
extern PACKAGE GUID IID_IRowsetChange;
extern PACKAGE GUID IID_IRowsetUpdate;
extern PACKAGE GUID IID_IRowsetIndex;
extern PACKAGE GUID IID_IMultipleResults;
extern PACKAGE GUID IID_IConvertType;
extern PACKAGE GUID IID_ICommandPrepare;
extern PACKAGE GUID IID_ICommandProperties;
extern PACKAGE GUID IID_ICommand;
extern PACKAGE GUID IID_ICommandWithParameters;
extern PACKAGE GUID IID_ICommandText;
extern PACKAGE GUID IID_IColumnsRowset;
extern PACKAGE GUID IID_IColumnsInfo;
extern PACKAGE GUID IID_IDBCreateCommand;
extern PACKAGE GUID IID_IDBCreateSession;
extern PACKAGE GUID IID_ISourcesRowset;
extern PACKAGE GUID IID_IDBProperties;
extern PACKAGE GUID IID_IDBInitialize;
extern PACKAGE GUID IID_IDBInfo;
extern PACKAGE GUID IID_IDBDataSourceAdmin;
extern PACKAGE GUID IID_ISessionProperties;
extern PACKAGE GUID IID_IIndexDefinition;
extern PACKAGE GUID IID_ITableDefinition;
extern PACKAGE GUID IID_IOpenRowset;
extern PACKAGE GUID IID_IErrorLookup;
extern PACKAGE GUID IID_ISQLErrorInfo;
extern PACKAGE GUID IID_IGetDataSource;
extern PACKAGE GUID IID_ITransactionLocal;
extern PACKAGE GUID IID_ITransactionJoin;
extern PACKAGE GUID IID_ITransactionObject;
extern PACKAGE GUID IID_IDBAsynchStatus;
extern PACKAGE GUID IID_IRowsetFind;
extern PACKAGE GUID IID_IRowPosition;
extern PACKAGE GUID IID_IRowPositionChange;
extern PACKAGE GUID IID_IViewRowset;
extern PACKAGE GUID IID_IViewChapter;
extern PACKAGE GUID IID_IViewSort;
extern PACKAGE GUID IID_IViewFilter;
extern PACKAGE GUID IID_IRowsetView;
extern PACKAGE GUID IID_IMDFind;
extern PACKAGE GUID IID_IMDRangeRowset;
extern PACKAGE GUID IID_IAlterTable;
extern PACKAGE GUID IID_IAlterIndex;
extern PACKAGE GUID IID_ICommandPersist;
extern PACKAGE GUID IID_IRowsetChapterMember;
extern PACKAGE GUID IID_IRowsetRefresh;
extern PACKAGE GUID IID_IParentRowset;
extern PACKAGE GUID IID_ITrusteeGroupAdmin;
extern PACKAGE GUID IID_IObjectAccessControl;
extern PACKAGE GUID IID_ISecurityInfo;
extern PACKAGE GUID IID_IDBPromptInitialize;
extern PACKAGE GUID IID_IDataInitialize;
extern PACKAGE GUID DBSCHEMA_TABLES_INFO;
extern PACKAGE GUID MDGUID_MDX;
extern PACKAGE GUID DBGUID_MDX;
extern PACKAGE GUID MDSCHEMA_CUBES;
extern PACKAGE GUID MDSCHEMA_DIMENSIONS;
extern PACKAGE GUID MDSCHEMA_HIERARCHIES;
extern PACKAGE GUID MDSCHEMA_LEVELS;
extern PACKAGE GUID MDSCHEMA_MEASURES;
extern PACKAGE GUID MDSCHEMA_PROPERTIES;
extern PACKAGE GUID MDSCHEMA_MEMBERS;
extern PACKAGE GUID DBPROPSET_TRUSTEE;
extern PACKAGE GUID DBOBJECT_TABLE;
extern PACKAGE GUID DBOBJECT_COLUMN;
extern PACKAGE GUID DBOBJECT_DATABASE;
extern PACKAGE GUID DBOBJECT_PROCEDURE;
extern PACKAGE GUID DBOBJECT_VIEW;
extern PACKAGE GUID DBOBJECT_SCHEMA;
extern PACKAGE GUID DBOBJECT_DOMAIN;
extern PACKAGE GUID DBOBJECT_COLLATION;
extern PACKAGE GUID DBOBJECT_TRUSTEE;
extern PACKAGE GUID DBOBJECT_SCHEMAROWSET;
extern PACKAGE GUID DBOBJECT_CHARACTERSET;
extern PACKAGE GUID DBOBJECT_TRANSLATION;
extern PACKAGE GUID DB_PROPERTY_CHECK_OPTION;
extern PACKAGE GUID DB_PROPERTY_CONSTRAINT_CHECK_DEFERRED;
extern PACKAGE GUID DB_PROPERTY_DROP_CASCADE;
extern PACKAGE GUID DB_PROPERTY_UNIQUE;
extern PACKAGE GUID DB_PROPERTY_ON_COMMIT_PRESERVE_ROWS;
extern PACKAGE GUID DB_PROPERTY_PRIMARY;
extern PACKAGE GUID DB_PROPERTY_CLUSTERED;
extern PACKAGE GUID DB_PROPERTY_NONCLUSTERED;
extern PACKAGE GUID DB_PROPERTY_BTREE;
extern PACKAGE GUID DB_PROPERTY_HASH;
extern PACKAGE GUID DB_PROPERTY_FILLFACTOR;
extern PACKAGE GUID DB_PROPERTY_INITIALSIZE;
extern PACKAGE GUID DB_PROPERTY_DISALLOWNULL;
extern PACKAGE GUID DB_PROPERTY_IGNORENULL;
extern PACKAGE GUID DB_PROPERTY_IGNOREANYNULL;
extern PACKAGE GUID DB_PROPERTY_SORTBOOKMARKS;
extern PACKAGE GUID DB_PROPERTY_AUTOMATICUPDATE;
extern PACKAGE GUID DB_PROPERTY_EXPLICITUPDATE;
extern PACKAGE GUID DBGUID_LIKE_SQL;
extern PACKAGE GUID DBGUID_LIKE_DOS;
extern PACKAGE GUID DBGUID_LIKE_OFS;
extern PACKAGE GUID DBGUID_LIKE_MAPI;
extern PACKAGE GUID DBSCHEMA_ASSERTIONS;
extern PACKAGE GUID DBSCHEMA_CATALOGS;
extern PACKAGE GUID DBSCHEMA_CHARACTER_SETS;
extern PACKAGE GUID DBSCHEMA_COLLATIONS;
extern PACKAGE GUID DBSCHEMA_COLUMNS;
extern PACKAGE GUID DBSCHEMA_CHECK_CONSTRAINTS;
extern PACKAGE GUID DBSCHEMA_CONSTRAINT_COLUMN_USAGE;
extern PACKAGE GUID DBSCHEMA_CONSTRAINT_TABLE_USAGE;
extern PACKAGE GUID DBSCHEMA_KEY_COLUMN_USAGE;
extern PACKAGE GUID DBSCHEMA_REFERENTIAL_CONSTRAINTS;
extern PACKAGE GUID DBSCHEMA_TABLE_CONSTRAINTS;
extern PACKAGE GUID DBSCHEMA_COLUMN_DOMAIN_USAGE;
extern PACKAGE GUID DBSCHEMA_INDEXES;
extern PACKAGE GUID DBSCHEMA_COLUMN_PRIVILEGES;
extern PACKAGE GUID DBSCHEMA_TABLE_PRIVILEGES;
extern PACKAGE GUID DBSCHEMA_USAGE_PRIVILEGES;
extern PACKAGE GUID DBSCHEMA_PROCEDURES;
extern PACKAGE GUID DBSCHEMA_SCHEMATA;
extern PACKAGE GUID DBSCHEMA_SQL_LANGUAGES;
extern PACKAGE GUID DBSCHEMA_STATISTICS;
extern PACKAGE GUID DBSCHEMA_TABLES;
extern PACKAGE GUID DBSCHEMA_TRANSLATIONS;
extern PACKAGE GUID DBSCHEMA_PROVIDER_TYPES;
extern PACKAGE GUID DBSCHEMA_VIEWS;
extern PACKAGE GUID DBSCHEMA_VIEW_COLUMN_USAGE;
extern PACKAGE GUID DBSCHEMA_VIEW_TABLE_USAGE;
extern PACKAGE GUID DBSCHEMA_PROCEDURE_PARAMETERS;
extern PACKAGE GUID DBSCHEMA_FOREIGN_KEYS;
extern PACKAGE GUID DBSCHEMA_PRIMARY_KEYS;
extern PACKAGE GUID DBSCHEMA_PROCEDURE_COLUMNS;
extern PACKAGE GUID DBCOL_SELFCOLUMNS;
extern PACKAGE GUID DBCOL_SPECIALCOL;
extern PACKAGE GUID PSGUID_QUERY;
extern PACKAGE GUID DBPROPSET_COLUMN;
extern PACKAGE GUID DBPROPSET_DATASOURCE;
extern PACKAGE GUID DBPROPSET_DATASOURCEINFO;
extern PACKAGE GUID DBPROPSET_INDEX;
extern PACKAGE GUID DBPROPSET_DBINIT;
extern PACKAGE GUID DBPROPSET_ROWSET;
extern PACKAGE GUID DBPROPSET_SESSION;
extern PACKAGE GUID DBPROPSET_TABLE;
extern PACKAGE GUID DBPROPSET_PROPERTIESINERROR;
extern PACKAGE GUID DBPROPSET_VIEW;
#define DBPROPSET_COLUMNALL "{C8B522F0-5CF3-11CE-ADE5-00AA0044773D}"
#define DBPROPSET_CONSTRAINTALL "{C8B522FA-5CF3-11CE-ADE5-00AA0044773D}"
extern PACKAGE GUID DBPROPSET_DATASOURCEALL;
extern PACKAGE GUID DBPROPSET_DATASOURCEINFOALL;
extern PACKAGE GUID DBPROPSET_DBINITALL;
#define DBPROPSET_INDEXALL "{C8B522F1-5CF3-11CE-ADE5-00AA0044773D}"
extern PACKAGE GUID DBPROPSET_ROWSETALL;
extern PACKAGE GUID DBPROPSET_SESSIONALL;
#define DBPROPSET_TABLEALL "{C8B522F2-5CF3-11CE-ADE5-00AA0044773D}"
#define DBPROPSET_TRUSTEEALL "{C8B522F3-5CF3-11CE-ADE5-00AA0044773D}"
extern PACKAGE GUID DBGUID_DEFAULT;
extern PACKAGE GUID DBGUID_SQL;
static const Word MAXCOLS = 0x1000;
static const Word MAXBOUND = 0xffff;
static const Shortint ISOFLAG_RETAIN_DONTCARE = 0x5;

}	/* namespace Oledb */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Oledb;
#endif
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// OLEDB
