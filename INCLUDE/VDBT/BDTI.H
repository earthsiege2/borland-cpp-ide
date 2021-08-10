//--------------------------------------------------------------------------
// Visual Database Tools
// Copyright (c) 1995, 1995 by Borland International, All Rights Reserved
//
//   Definitions of database access COM interfaces.
//--------------------------------------------------------------------------

#ifndef BDTI_H
#define BDTI_H

DEFINE_GUID(LIBID_BDT50,0x2647E000,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);







#ifndef DBI_H

typedef unsigned long hDBIObj;

typedef hDBIObj hDBISes;

typedef hDBIObj hDBIDb;

typedef hDBIObj hDBICur;

typedef hDBIObj hDBIStmt;

typedef LPVOID pFLDDesc;

#endif // DBI_H

typedef enum {
    dupIgnore,
    dupAccept,
    dupError
} TDuplicates;

typedef LPVOID TLocale;

typedef enum {
    tiDirtyRead,
    tiReadCommitted,
    tiRepeatableRead
} TTransIsolation;

typedef enum {
    ftUnknown,
    ftString,
    ftSmallint,
    ftInteger,
    ftWord,
    ftBoolean,
    ftFloat,
    ftCurrency,
    ftBCD,
    ftDate,
    ftTime,
    ftDateTime,
    ftBytes,
    ftVarBytes,
#ifdef __FLAT__
    ftAutoInc,
#endif // __FLAT__
    ftBlob,
    ftMemo,
    ftGraphic,
#ifdef __FLAT__
    ftFmtMemo,
    ftParadoxOle,
    ftDBaseOle,
    ftTypedBinary
#endif // __FLAT__
} TFieldType;

typedef enum {
    dsInactive,
    dsBrowse,
    dsEdit,
    dsInsert,
    dsSetKey,
    dsCalcFields,
#ifdef __FLAT__
    dsUpdateNew,
    dsUpdateOld,
    dsFilter
#endif // __FLAT__
} TDataSetState;

typedef enum {
    rmExact = 1,
    rmCenter = 2
} TResyncMode;

typedef LPVOID TBookmark;

typedef enum {
    ixPrimary = 1,
    ixUnique = 2,
    ixDescending = 4,
    ixCaseInsensitive = 8,
    ixExpression = 16
} TIndexOptions;

typedef enum {
    ttDefault,
    ttParadox,
    ttDBase,
    ttASCII
} TTableType;

typedef enum {
    upWhereAll,
    upWhereChanged,
    upWhereKeyOnly
} TUpdateMode;

typedef enum {
    batAppend,
    batUpdate,
    batAppendUpdate,
    batDelete,
    batCopy
} TBatchMode;

typedef enum {
    ltReadLock,
    ltWriteLock
} TLockType;

typedef enum {
    ptUnknown,
    ptInput,
    ptOutput,
    ptInputOutput,
    ptResult
} TParamType;

typedef enum {
    pbByName,
    pbByNumber
} TParamBindMode;

typedef enum {
    soFromBeginning,
    soFromCurrent,
    soFromEnd
} TSeekOrigin;

interface ITBDTObject;

interface DTBDTObject;

interface ITBDTComponent;

interface DTBDTComponent;

interface ITDataSource;

interface DTDataSource;

interface ITDataSet;

interface DTDataSet;

interface ITDBDataSet;

interface DTDBDataSet;

interface ITTable;

interface DTTable;

interface ITQuery;

interface DTQuery;

interface ITStoredProc;

interface DTStoredProc;

interface ITDatabase;

interface DTDatabase;

interface ITBatchMove;

interface DTBatchMove;

interface ITSession;

interface DTSession;

interface ITField;

interface DTField;

interface ITFieldDef;

interface DTFieldDef;

interface ITFieldDefs;

interface DTFieldDefs;

interface ITIndexDef;

interface DTIndexDef;

interface ITIndexDefs;

interface DTIndexDefs;

interface ITParam;

interface DTParam;

interface ITParams;

interface DTParams;

interface ITStrings;

interface DTStrings;

interface ITMemoryStream;

interface DTMemoryStream;

interface ITAnyString;

interface DTAnyString;

typedef void (STDAPICALLTYPE* NEDatabaseErrorHandler)( IUnknown* Sender, LPCSTR Message, WORD BDEErrorCode, ULONG NativeErrorCode );

typedef void (STDAPICALLTYPE* NEListErrorHandler)( IUnknown* Sender, LPCSTR Message );

typedef void (STDAPICALLTYPE* NErrorHandler)( IUnknown* Sender, LPCSTR Message );

typedef void (STDAPICALLTYPE* NStringsNotifyEvent)( long Data, ITStrings FAR* Sender );

typedef void (STDAPICALLTYPE* NPasswordEvent)( long Data, ITSession FAR* Sender, VARIANT_BOOL FAR* Continue );

typedef void (STDAPICALLTYPE* NLoginEvent)( long Data, ITDatabase FAR* Database, ITStrings FAR* LoginParams );

typedef void (STDAPICALLTYPE* NDataSetNotifyEvent)( long Data, ITDataSet FAR* DataSet );

typedef void (STDAPICALLTYPE* NDataSourceNotifyEvent)( long Data, ITDataSource FAR* Sender );

typedef void (STDAPICALLTYPE* NDataChangeEvent)( long Data, ITDataSource FAR* Sender, ITField FAR* Field );

typedef void (STDAPICALLTYPE* NFieldNotifyEvent)( long Data, ITField FAR* Sender );

typedef void (STDAPICALLTYPE* NFieldGetTextEvent)( long Data, ITField FAR* Sender, ITAnyString FAR* Text, VARIANT_BOOL DisplayText );

typedef void (STDAPICALLTYPE* NFieldSetTextEvent)( long Data, ITField FAR* Sender, ITAnyString FAR* Text );

DEFINE_GUID(IID_IBDT50,0x2647E001,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: IBDT50 */
DECLARE_INTERFACE_(IBDT50, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IBDT50 methods */
    STDMETHOD_(void, EasterEgg)(THIS) PURE;
    STDMETHOD_(void, SetErrorHandlers)(THIS_ NEDatabaseErrorHandler dbcb, NEListErrorHandler listcb, NErrorHandler genericcb) PURE;
    STDMETHOD_(VARIANT_BOOL, get_ShowErrors)(THIS) PURE;
    STDMETHOD_(void, put_ShowErrors)(THIS_ VARIANT_BOOL s) PURE;
};

DEFINE_GUID(DIID_DBDT50,0x2647E002,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DBDT50 */
DECLARE_INTERFACE_(DBDT50, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface IBDT50 */
};

DEFINE_GUID(CLSID_BDT50,0x2647E003,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITBDTObject,0x2647E004,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITBDTObject */
DECLARE_INTERFACE_(ITBDTObject, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;
};

DEFINE_GUID(DIID_DTBDTObject,0x2647E005,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTBDTObject */
DECLARE_INTERFACE_(DTBDTObject, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITBDTObject */
};

DEFINE_GUID(IID_ITBDTComponent,0x2647E006,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITBDTComponent */
DECLARE_INTERFACE_(ITBDTComponent, ITBDTObject)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;
#endif

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
};

DEFINE_GUID(DIID_DTBDTComponent,0x2647E007,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTBDTComponent */
DECLARE_INTERFACE_(DTBDTComponent, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITBDTComponent */
};

DEFINE_GUID(IID_ITDataSource,0x2647E011,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITDataSource */
DECLARE_INTERFACE_(ITDataSource, ITBDTComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITDataSource methods */
    STDMETHOD_(void, Edit)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedTo)(THIS_ ITDataSet FAR* dataset) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedToDispatch)(THIS_ DTDataSet FAR* dataset) PURE;
    STDMETHOD_(TDataSetState, get_State)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AutoEdit)(THIS) PURE;
    STDMETHOD_(void, put_AutoEdit)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(ITDataSet FAR*, get_DataSet)(THIS) PURE;
    STDMETHOD_(DTDataSet FAR*, get_DataSetDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DataSet)(THIS_ ITDataSet FAR* dataset) PURE;
    STDMETHOD_(void, put_DataSetDispatch)(THIS_ DTDataSet FAR* dataset) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Enabled)(THIS) PURE;
    STDMETHOD_(void, put_Enabled)(THIS_ VARIANT_BOOL en) PURE;
    STDMETHOD_(void, AttachOnStateChange)(THIS_ NDataSourceNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnStateChange)(THIS_ NDataSourceNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnDataChange)(THIS_ NDataChangeEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnDataChange)(THIS_ NDataChangeEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnUpdateData)(THIS_ NDataSourceNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnUpdateData)(THIS_ NDataSourceNotifyEvent Callback, long Data) PURE;
};

DEFINE_GUID(DIID_DTDataSource,0x2647E012,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTDataSource */
DECLARE_INTERFACE_(DTDataSource, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITDataSource */
};

DEFINE_GUID(CLSID_TDataSource,0x2647E013,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITDataSet,0x2647E021,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITDataSet */
DECLARE_INTERFACE_(ITDataSet, ITBDTComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITDataSet methods */
    STDMETHOD_(LPSTR, ActiveBuffer)(THIS) PURE;
    STDMETHOD_(void, Append)(THIS) PURE;
    STDMETHOD_(void, AppendRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, AppendRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, Cancel)(THIS) PURE;
    STDMETHOD_(void, CheckBrowseMode)(THIS) PURE;
    STDMETHOD_(void, ClearFields)(THIS) PURE;
    STDMETHOD_(void, Close)(THIS) PURE;
    STDMETHOD_(void, CursorPosChanged)(THIS) PURE;
    STDMETHOD_(void, Delete)(THIS) PURE;
    STDMETHOD_(void, DisableControls)(THIS) PURE;
    STDMETHOD_(void, Edit)(THIS) PURE;
    STDMETHOD_(void, EnableControls)(THIS) PURE;
    STDMETHOD_(ITField FAR*, FieldByName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FieldByNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITField FAR*, FindField)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FindFieldDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, First)(THIS) PURE;
    STDMETHOD_(void, FreeBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(TBookmark, GetBookmark)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, GetCurrentRecord)(THIS_ LPSTR buffer) PURE;
    STDMETHOD_(void, GetFieldNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetFieldNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GotoBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(void, Insert)(THIS) PURE;
    STDMETHOD_(void, InsertRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, InsertRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedTo)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedToDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(void, Last)(THIS) PURE;
    STDMETHOD_(void, MoveBy)(THIS_ int o) PURE;
    STDMETHOD_(void, Next)(THIS) PURE;
    STDMETHOD_(void, Open)(THIS) PURE;
    STDMETHOD_(void, Post)(THIS) PURE;
    STDMETHOD_(void, Prior)(THIS) PURE;
    STDMETHOD_(void, Refresh)(THIS) PURE;
    STDMETHOD_(void, Resync)(THIS_ TResyncMode mode) PURE;
    STDMETHOD_(void, SetFields)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, SetFieldsSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, UpdateCursorPos)(THIS) PURE;
    STDMETHOD_(void, UpdateRecord)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtBOF)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_CanModify)(THIS) PURE;
    STDMETHOD_(ITDataSource FAR*, get_DataSource)(THIS) PURE;
    STDMETHOD_(DTDataSource FAR*, get_DataSourceDispatch)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_DefaultFields)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtEOF)(THIS) PURE;
    STDMETHOD_(int, get_FieldCount)(THIS) PURE;
    STDMETHOD_(ITFieldDefs FAR*, get_FieldDefs)(THIS) PURE;
    STDMETHOD_(DTFieldDefs FAR*, get_FieldDefsDispatch)(THIS) PURE;
    STDMETHOD_(ITField FAR*, get_Fields)(THIS_ int i) PURE;
    STDMETHOD_(DTField FAR*, get_FieldsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBICur, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Modified)(THIS) PURE;
    STDMETHOD_(long, get_RecordCount)(THIS) PURE;
    STDMETHOD_(WORD, get_RecordSize)(THIS) PURE;
    STDMETHOD_(TDataSetState, get_State)(THIS) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Active)(THIS) PURE;
    STDMETHOD_(void, put_Active)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AutoCalcFields)(THIS) PURE;
    STDMETHOD_(void, put_AutoCalcFields)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(void, AttachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
};

DEFINE_GUID(DIID_DTDataSet,0x2647E022,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTDataSet */
DECLARE_INTERFACE_(DTDataSet, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITDataSet */
};

DEFINE_GUID(IID_ITDBDataSet,0x2647E031,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITDBDataSet */
DECLARE_INTERFACE_(ITDBDataSet, ITDataSet)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;

    /* ITDataSet methods */
    STDMETHOD_(LPSTR, ActiveBuffer)(THIS) PURE;
    STDMETHOD_(void, Append)(THIS) PURE;
    STDMETHOD_(void, AppendRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, AppendRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, Cancel)(THIS) PURE;
    STDMETHOD_(void, CheckBrowseMode)(THIS) PURE;
    STDMETHOD_(void, ClearFields)(THIS) PURE;
    STDMETHOD_(void, Close)(THIS) PURE;
    STDMETHOD_(void, CursorPosChanged)(THIS) PURE;
    STDMETHOD_(void, Delete)(THIS) PURE;
    STDMETHOD_(void, DisableControls)(THIS) PURE;
    STDMETHOD_(void, Edit)(THIS) PURE;
    STDMETHOD_(void, EnableControls)(THIS) PURE;
    STDMETHOD_(ITField FAR*, FieldByName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FieldByNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITField FAR*, FindField)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FindFieldDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, First)(THIS) PURE;
    STDMETHOD_(void, FreeBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(TBookmark, GetBookmark)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, GetCurrentRecord)(THIS_ LPSTR buffer) PURE;
    STDMETHOD_(void, GetFieldNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetFieldNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GotoBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(void, Insert)(THIS) PURE;
    STDMETHOD_(void, InsertRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, InsertRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedTo)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedToDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(void, Last)(THIS) PURE;
    STDMETHOD_(void, MoveBy)(THIS_ int o) PURE;
    STDMETHOD_(void, Next)(THIS) PURE;
    STDMETHOD_(void, Open)(THIS) PURE;
    STDMETHOD_(void, Post)(THIS) PURE;
    STDMETHOD_(void, Prior)(THIS) PURE;
    STDMETHOD_(void, Refresh)(THIS) PURE;
    STDMETHOD_(void, Resync)(THIS_ TResyncMode mode) PURE;
    STDMETHOD_(void, SetFields)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, SetFieldsSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, UpdateCursorPos)(THIS) PURE;
    STDMETHOD_(void, UpdateRecord)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtBOF)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_CanModify)(THIS) PURE;
    STDMETHOD_(ITDataSource FAR*, get_DataSource)(THIS) PURE;
    STDMETHOD_(DTDataSource FAR*, get_DataSourceDispatch)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_DefaultFields)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtEOF)(THIS) PURE;
    STDMETHOD_(int, get_FieldCount)(THIS) PURE;
    STDMETHOD_(ITFieldDefs FAR*, get_FieldDefs)(THIS) PURE;
    STDMETHOD_(DTFieldDefs FAR*, get_FieldDefsDispatch)(THIS) PURE;
    STDMETHOD_(ITField FAR*, get_Fields)(THIS_ int i) PURE;
    STDMETHOD_(DTField FAR*, get_FieldsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBICur, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Modified)(THIS) PURE;
    STDMETHOD_(long, get_RecordCount)(THIS) PURE;
    STDMETHOD_(WORD, get_RecordSize)(THIS) PURE;
    STDMETHOD_(TDataSetState, get_State)(THIS) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Active)(THIS) PURE;
    STDMETHOD_(void, put_Active)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AutoCalcFields)(THIS) PURE;
    STDMETHOD_(void, put_AutoCalcFields)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(void, AttachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
#endif

    /* ITDBDataSet methods */
    STDMETHOD_(ITDatabase FAR*, get_Database)(THIS) PURE;
    STDMETHOD_(DTDatabase FAR*, get_DatabaseDispatch)(THIS) PURE;
    STDMETHOD_(hDBIDb, get_DBHandle)(THIS) PURE;
    STDMETHOD_(TLocale, get_DBLocale)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DatabaseName)(THIS) PURE;
    STDMETHOD_(BSTR, get_DatabaseNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DatabaseName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_DatabaseNameDispatch)(THIS_ BSTR n) PURE;
};

DEFINE_GUID(DIID_DTDBDataSet,0x2647E032,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTDBDataSet */
DECLARE_INTERFACE_(DTDBDataSet, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITDBDataSet */
};

DEFINE_GUID(IID_ITTable,0x2647E041,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITTable */
DECLARE_INTERFACE_(ITTable, ITDBDataSet)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;

    /* ITDataSet methods */
    STDMETHOD_(LPSTR, ActiveBuffer)(THIS) PURE;
    STDMETHOD_(void, Append)(THIS) PURE;
    STDMETHOD_(void, AppendRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, AppendRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, Cancel)(THIS) PURE;
    STDMETHOD_(void, CheckBrowseMode)(THIS) PURE;
    STDMETHOD_(void, ClearFields)(THIS) PURE;
    STDMETHOD_(void, Close)(THIS) PURE;
    STDMETHOD_(void, CursorPosChanged)(THIS) PURE;
    STDMETHOD_(void, Delete)(THIS) PURE;
    STDMETHOD_(void, DisableControls)(THIS) PURE;
    STDMETHOD_(void, Edit)(THIS) PURE;
    STDMETHOD_(void, EnableControls)(THIS) PURE;
    STDMETHOD_(ITField FAR*, FieldByName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FieldByNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITField FAR*, FindField)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FindFieldDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, First)(THIS) PURE;
    STDMETHOD_(void, FreeBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(TBookmark, GetBookmark)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, GetCurrentRecord)(THIS_ LPSTR buffer) PURE;
    STDMETHOD_(void, GetFieldNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetFieldNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GotoBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(void, Insert)(THIS) PURE;
    STDMETHOD_(void, InsertRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, InsertRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedTo)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedToDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(void, Last)(THIS) PURE;
    STDMETHOD_(void, MoveBy)(THIS_ int o) PURE;
    STDMETHOD_(void, Next)(THIS) PURE;
    STDMETHOD_(void, Open)(THIS) PURE;
    STDMETHOD_(void, Post)(THIS) PURE;
    STDMETHOD_(void, Prior)(THIS) PURE;
    STDMETHOD_(void, Refresh)(THIS) PURE;
    STDMETHOD_(void, Resync)(THIS_ TResyncMode mode) PURE;
    STDMETHOD_(void, SetFields)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, SetFieldsSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, UpdateCursorPos)(THIS) PURE;
    STDMETHOD_(void, UpdateRecord)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtBOF)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_CanModify)(THIS) PURE;
    STDMETHOD_(ITDataSource FAR*, get_DataSource)(THIS) PURE;
    STDMETHOD_(DTDataSource FAR*, get_DataSourceDispatch)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_DefaultFields)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtEOF)(THIS) PURE;
    STDMETHOD_(int, get_FieldCount)(THIS) PURE;
    STDMETHOD_(ITFieldDefs FAR*, get_FieldDefs)(THIS) PURE;
    STDMETHOD_(DTFieldDefs FAR*, get_FieldDefsDispatch)(THIS) PURE;
    STDMETHOD_(ITField FAR*, get_Fields)(THIS_ int i) PURE;
    STDMETHOD_(DTField FAR*, get_FieldsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBICur, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Modified)(THIS) PURE;
    STDMETHOD_(long, get_RecordCount)(THIS) PURE;
    STDMETHOD_(WORD, get_RecordSize)(THIS) PURE;
    STDMETHOD_(TDataSetState, get_State)(THIS) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Active)(THIS) PURE;
    STDMETHOD_(void, put_Active)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AutoCalcFields)(THIS) PURE;
    STDMETHOD_(void, put_AutoCalcFields)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(void, AttachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;

    /* ITDBDataSet methods */
    STDMETHOD_(ITDatabase FAR*, get_Database)(THIS) PURE;
    STDMETHOD_(DTDatabase FAR*, get_DatabaseDispatch)(THIS) PURE;
    STDMETHOD_(hDBIDb, get_DBHandle)(THIS) PURE;
    STDMETHOD_(TLocale, get_DBLocale)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DatabaseName)(THIS) PURE;
    STDMETHOD_(BSTR, get_DatabaseNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DatabaseName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_DatabaseNameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITTable methods */
    STDMETHOD_(long, BatchMove)(THIS_ ITDataSet FAR* dataset, TBatchMode m) PURE;
    STDMETHOD_(long, BatchMoveDispatch)(THIS_ DTDataSet FAR* dataset, TBatchMode m) PURE;
    STDMETHOD_(void, AddIndex)(THIS_ ITAnyString FAR* name, ITAnyString FAR* fields, TIndexOptions options) PURE;
    STDMETHOD_(void, AddIndexDispatch)(THIS_ BSTR name, BSTR fields, TIndexOptions options) PURE;
    STDMETHOD_(void, ApplyRange)(THIS) PURE;
    STDMETHOD_(void, CancelRange)(THIS) PURE;
    STDMETHOD_(void, CreateTable)(THIS) PURE;
    STDMETHOD_(void, DeleteIndex)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, DeleteIndexDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, DeleteTable)(THIS) PURE;
    STDMETHOD_(void, EditKey)(THIS) PURE;
    STDMETHOD_(void, EditRangeEnd)(THIS) PURE;
    STDMETHOD_(void, EditRangeStart)(THIS) PURE;
    STDMETHOD_(void, EmptyTable)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, FindKey)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(VARIANT_BOOL, FindKeySafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, FindNearest)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, FindNearestSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, GetIndexNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetIndexNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GotoCurrent)(THIS_ ITTable FAR* table) PURE;
    STDMETHOD_(void, GotoCurrentDispatch)(THIS_ DTTable FAR* table) PURE;
    STDMETHOD_(VARIANT_BOOL, GotoKey)(THIS) PURE;
    STDMETHOD_(void, GotoNearest)(THIS) PURE;
    STDMETHOD_(void, LockTable)(THIS_ TLockType t) PURE;
    STDMETHOD_(void, RenameTable)(THIS_ ITAnyString FAR* newname) PURE;
    STDMETHOD_(void, RenameTableDispatch)(THIS_ BSTR newname) PURE;
    STDMETHOD_(void, SetKey)(THIS) PURE;
    STDMETHOD_(void, SetRange)(THIS_ int startCount, VARIANT FAR* startValues, int endCount, VARIANT FAR* endValues) PURE;
    STDMETHOD_(void, SetRangeSafe)(THIS_ SAFEARRAY FAR* psaStart, SAFEARRAY FAR* psaEnd) PURE;
    STDMETHOD_(void, SetRangeEnd)(THIS) PURE;
    STDMETHOD_(void, SetRangeStart)(THIS) PURE;
    STDMETHOD_(void, UnlockTable)(THIS_ TLockType t) PURE;
    STDMETHOD_(ITIndexDefs FAR*, get_IndexDefs)(THIS) PURE;
    STDMETHOD_(DTIndexDefs FAR*, get_IndexDefsDispatch)(THIS) PURE;
    STDMETHOD_(int, get_IndexFieldCount)(THIS) PURE;
    STDMETHOD_(ITField FAR*, get_IndexFields)(THIS_ int i) PURE;
    STDMETHOD_(DTField FAR*, get_IndexFieldsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(VARIANT_BOOL, get_KeyExclusive)(THIS) PURE;
    STDMETHOD_(void, put_KeyExclusive)(THIS_ VARIANT_BOOL k) PURE;
    STDMETHOD_(int, get_KeyFieldCount)(THIS) PURE;
    STDMETHOD_(void, put_KeyFieldCount)(THIS_ int c) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Exclusive)(THIS) PURE;
    STDMETHOD_(void, put_Exclusive)(THIS_ VARIANT_BOOL ex) PURE;
    STDMETHOD_(ITAnyString FAR*, get_IndexFieldNames)(THIS) PURE;
    STDMETHOD_(BSTR, get_IndexFieldNamesDispatch)(THIS) PURE;
    STDMETHOD_(void, put_IndexFieldNames)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_IndexFieldNamesDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITAnyString FAR*, get_IndexName)(THIS) PURE;
    STDMETHOD_(BSTR, get_IndexNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_IndexName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_IndexNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITAnyString FAR*, get_MasterFields)(THIS) PURE;
    STDMETHOD_(BSTR, get_MasterFieldsDispatch)(THIS) PURE;
    STDMETHOD_(void, put_MasterFields)(THIS_ ITAnyString FAR* m) PURE;
    STDMETHOD_(void, put_MasterFieldsDispatch)(THIS_ BSTR m) PURE;
    STDMETHOD_(ITDataSource FAR*, get_MasterSource)(THIS) PURE;
    STDMETHOD_(DTDataSource FAR*, get_MasterSourceDispatch)(THIS) PURE;
    STDMETHOD_(void, put_MasterSource)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(void, put_MasterSourceDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, get_ReadOnly)(THIS) PURE;
    STDMETHOD_(void, put_ReadOnly)(THIS_ VARIANT_BOOL r) PURE;
    STDMETHOD_(ITAnyString FAR*, get_TableName)(THIS) PURE;
    STDMETHOD_(BSTR, get_TableNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_TableName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_TableNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(TTableType, get_TableType)(THIS) PURE;
    STDMETHOD_(void, put_TableType)(THIS_ TTableType t) PURE;
    STDMETHOD_(TUpdateMode, get_UpdateMode)(THIS) PURE;
    STDMETHOD_(void, put_UpdateMode)(THIS_ TUpdateMode u) PURE;
};

DEFINE_GUID(DIID_DTTable,0x2647E042,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTTable */
DECLARE_INTERFACE_(DTTable, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITTable */
};

DEFINE_GUID(CLSID_TTable,0x2647E043,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITQuery,0x2647E051,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITQuery */
DECLARE_INTERFACE_(ITQuery, ITDBDataSet)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;

    /* ITDataSet methods */
    STDMETHOD_(LPSTR, ActiveBuffer)(THIS) PURE;
    STDMETHOD_(void, Append)(THIS) PURE;
    STDMETHOD_(void, AppendRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, AppendRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, Cancel)(THIS) PURE;
    STDMETHOD_(void, CheckBrowseMode)(THIS) PURE;
    STDMETHOD_(void, ClearFields)(THIS) PURE;
    STDMETHOD_(void, Close)(THIS) PURE;
    STDMETHOD_(void, CursorPosChanged)(THIS) PURE;
    STDMETHOD_(void, Delete)(THIS) PURE;
    STDMETHOD_(void, DisableControls)(THIS) PURE;
    STDMETHOD_(void, Edit)(THIS) PURE;
    STDMETHOD_(void, EnableControls)(THIS) PURE;
    STDMETHOD_(ITField FAR*, FieldByName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FieldByNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITField FAR*, FindField)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FindFieldDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, First)(THIS) PURE;
    STDMETHOD_(void, FreeBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(TBookmark, GetBookmark)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, GetCurrentRecord)(THIS_ LPSTR buffer) PURE;
    STDMETHOD_(void, GetFieldNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetFieldNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GotoBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(void, Insert)(THIS) PURE;
    STDMETHOD_(void, InsertRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, InsertRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedTo)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedToDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(void, Last)(THIS) PURE;
    STDMETHOD_(void, MoveBy)(THIS_ int o) PURE;
    STDMETHOD_(void, Next)(THIS) PURE;
    STDMETHOD_(void, Open)(THIS) PURE;
    STDMETHOD_(void, Post)(THIS) PURE;
    STDMETHOD_(void, Prior)(THIS) PURE;
    STDMETHOD_(void, Refresh)(THIS) PURE;
    STDMETHOD_(void, Resync)(THIS_ TResyncMode mode) PURE;
    STDMETHOD_(void, SetFields)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, SetFieldsSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, UpdateCursorPos)(THIS) PURE;
    STDMETHOD_(void, UpdateRecord)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtBOF)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_CanModify)(THIS) PURE;
    STDMETHOD_(ITDataSource FAR*, get_DataSource)(THIS) PURE;
    STDMETHOD_(DTDataSource FAR*, get_DataSourceDispatch)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_DefaultFields)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtEOF)(THIS) PURE;
    STDMETHOD_(int, get_FieldCount)(THIS) PURE;
    STDMETHOD_(ITFieldDefs FAR*, get_FieldDefs)(THIS) PURE;
    STDMETHOD_(DTFieldDefs FAR*, get_FieldDefsDispatch)(THIS) PURE;
    STDMETHOD_(ITField FAR*, get_Fields)(THIS_ int i) PURE;
    STDMETHOD_(DTField FAR*, get_FieldsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBICur, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Modified)(THIS) PURE;
    STDMETHOD_(long, get_RecordCount)(THIS) PURE;
    STDMETHOD_(WORD, get_RecordSize)(THIS) PURE;
    STDMETHOD_(TDataSetState, get_State)(THIS) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Active)(THIS) PURE;
    STDMETHOD_(void, put_Active)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AutoCalcFields)(THIS) PURE;
    STDMETHOD_(void, put_AutoCalcFields)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(void, AttachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;

    /* ITDBDataSet methods */
    STDMETHOD_(ITDatabase FAR*, get_Database)(THIS) PURE;
    STDMETHOD_(DTDatabase FAR*, get_DatabaseDispatch)(THIS) PURE;
    STDMETHOD_(hDBIDb, get_DBHandle)(THIS) PURE;
    STDMETHOD_(TLocale, get_DBLocale)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DatabaseName)(THIS) PURE;
    STDMETHOD_(BSTR, get_DatabaseNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DatabaseName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_DatabaseNameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITQuery methods */
    STDMETHOD_(void, ExecSQL)(THIS) PURE;
    STDMETHOD_(ITParam FAR*, ParamByName)(THIS_ ITAnyString FAR* value) PURE;
    STDMETHOD_(DTParam FAR*, ParamByNameDispatch)(THIS_ BSTR value) PURE;
    STDMETHOD_(void, Prepare)(THIS) PURE;
    STDMETHOD_(void, UnPrepare)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Prepared)(THIS) PURE;
    STDMETHOD_(void, put_Prepared)(THIS_ VARIANT_BOOL p) PURE;
    STDMETHOD_(WORD, get_ParamCount)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Local)(THIS) PURE;
    STDMETHOD_(hDBIStmt, get_StmtHandle)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Text)(THIS) PURE;
    STDMETHOD_(BSTR, get_TextDispatch)(THIS) PURE;
    STDMETHOD_(ITStrings FAR*, get_SQL)(THIS) PURE;
    STDMETHOD_(DTStrings FAR*, get_SQLDispatch)(THIS) PURE;
    STDMETHOD_(void, put_SQL)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, put_SQLDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, put_DataSource)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(void, put_DataSourceDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, get_UniDirectional)(THIS) PURE;
    STDMETHOD_(void, put_UniDirectional)(THIS_ VARIANT_BOOL u) PURE;
    STDMETHOD_(VARIANT_BOOL, get_RequestLive)(THIS) PURE;
    STDMETHOD_(void, put_RequestLive)(THIS_ VARIANT_BOOL r) PURE;
    STDMETHOD_(ITParams FAR*, get_Params)(THIS) PURE;
    STDMETHOD_(DTParams FAR*, get_ParamsDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Params)(THIS_ ITParams FAR* params) PURE;
    STDMETHOD_(void, put_ParamsDispatch)(THIS_ DTParams FAR* params) PURE;
    STDMETHOD_(TUpdateMode, get_UpdateMode)(THIS) PURE;
    STDMETHOD_(void, put_UpdateMode)(THIS_ TUpdateMode u) PURE;
};

DEFINE_GUID(DIID_DTQuery,0x2647E052,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTQuery */
DECLARE_INTERFACE_(DTQuery, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITQuery */
};

DEFINE_GUID(CLSID_TQuery,0x2647E053,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITStoredProc,0x2647E061,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITStoredProc */
DECLARE_INTERFACE_(ITStoredProc, ITDBDataSet)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;

    /* ITDataSet methods */
    STDMETHOD_(LPSTR, ActiveBuffer)(THIS) PURE;
    STDMETHOD_(void, Append)(THIS) PURE;
    STDMETHOD_(void, AppendRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, AppendRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, Cancel)(THIS) PURE;
    STDMETHOD_(void, CheckBrowseMode)(THIS) PURE;
    STDMETHOD_(void, ClearFields)(THIS) PURE;
    STDMETHOD_(void, Close)(THIS) PURE;
    STDMETHOD_(void, CursorPosChanged)(THIS) PURE;
    STDMETHOD_(void, Delete)(THIS) PURE;
    STDMETHOD_(void, DisableControls)(THIS) PURE;
    STDMETHOD_(void, Edit)(THIS) PURE;
    STDMETHOD_(void, EnableControls)(THIS) PURE;
    STDMETHOD_(ITField FAR*, FieldByName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FieldByNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITField FAR*, FindField)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTField FAR*, FindFieldDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, First)(THIS) PURE;
    STDMETHOD_(void, FreeBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(TBookmark, GetBookmark)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, GetCurrentRecord)(THIS_ LPSTR buffer) PURE;
    STDMETHOD_(void, GetFieldNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetFieldNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GotoBookmark)(THIS_ TBookmark bm) PURE;
    STDMETHOD_(void, Insert)(THIS) PURE;
    STDMETHOD_(void, InsertRecord)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, InsertRecordSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedTo)(THIS_ ITDataSource FAR* datasource) PURE;
    STDMETHOD_(VARIANT_BOOL, IsLinkedToDispatch)(THIS_ DTDataSource FAR* datasource) PURE;
    STDMETHOD_(void, Last)(THIS) PURE;
    STDMETHOD_(void, MoveBy)(THIS_ int o) PURE;
    STDMETHOD_(void, Next)(THIS) PURE;
    STDMETHOD_(void, Open)(THIS) PURE;
    STDMETHOD_(void, Post)(THIS) PURE;
    STDMETHOD_(void, Prior)(THIS) PURE;
    STDMETHOD_(void, Refresh)(THIS) PURE;
    STDMETHOD_(void, Resync)(THIS_ TResyncMode mode) PURE;
    STDMETHOD_(void, SetFields)(THIS_ int count, VARIANT FAR* values) PURE;
    STDMETHOD_(void, SetFieldsSafe)(THIS_ SAFEARRAY FAR* psa) PURE;
    STDMETHOD_(void, UpdateCursorPos)(THIS) PURE;
    STDMETHOD_(void, UpdateRecord)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtBOF)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_CanModify)(THIS) PURE;
    STDMETHOD_(ITDataSource FAR*, get_DataSource)(THIS) PURE;
    STDMETHOD_(DTDataSource FAR*, get_DataSourceDispatch)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_DefaultFields)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AtEOF)(THIS) PURE;
    STDMETHOD_(int, get_FieldCount)(THIS) PURE;
    STDMETHOD_(ITFieldDefs FAR*, get_FieldDefs)(THIS) PURE;
    STDMETHOD_(DTFieldDefs FAR*, get_FieldDefsDispatch)(THIS) PURE;
    STDMETHOD_(ITField FAR*, get_Fields)(THIS_ int i) PURE;
    STDMETHOD_(DTField FAR*, get_FieldsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBICur, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Modified)(THIS) PURE;
    STDMETHOD_(long, get_RecordCount)(THIS) PURE;
    STDMETHOD_(WORD, get_RecordSize)(THIS) PURE;
    STDMETHOD_(TDataSetState, get_State)(THIS) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Active)(THIS) PURE;
    STDMETHOD_(void, put_Active)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AutoCalcFields)(THIS) PURE;
    STDMETHOD_(void, put_AutoCalcFields)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(void, AttachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterOpen)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterClose)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterInsert)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterEdit)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPost)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterCancel)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterDelete)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnNewRecord)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnCalcFields)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterFirst)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterGotoBookmark)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterLast)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterMoveBy)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforeNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterNext)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachBeforePrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachAfterPrior)(THIS_ NDataSetNotifyEvent Callback, long Data) PURE;

    /* ITDBDataSet methods */
    STDMETHOD_(ITDatabase FAR*, get_Database)(THIS) PURE;
    STDMETHOD_(DTDatabase FAR*, get_DatabaseDispatch)(THIS) PURE;
    STDMETHOD_(hDBIDb, get_DBHandle)(THIS) PURE;
    STDMETHOD_(TLocale, get_DBLocale)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DatabaseName)(THIS) PURE;
    STDMETHOD_(BSTR, get_DatabaseNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DatabaseName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_DatabaseNameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITStoredProc methods */
    STDMETHOD_(void, CopyParams)(THIS_ ITParams FAR* params) PURE;
    STDMETHOD_(void, CopyParamsDispatch)(THIS_ DTParams FAR* params) PURE;
    STDMETHOD_(VARIANT_BOOL, get_DescriptionsAvailable)(THIS) PURE;
    STDMETHOD_(void, ExecProc)(THIS) PURE;
    STDMETHOD_(ITParam FAR*, ParamByName)(THIS_ ITAnyString FAR* value) PURE;
    STDMETHOD_(DTParam FAR*, ParamByNameDispatch)(THIS_ BSTR value) PURE;
    STDMETHOD_(void, Prepare)(THIS) PURE;
    STDMETHOD_(void, GetResults)(THIS) PURE;
    STDMETHOD_(void, UnPrepare)(THIS) PURE;
    STDMETHOD_(WORD, get_ParamCount)(THIS) PURE;
    STDMETHOD_(hDBIStmt, get_StmtHandle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Prepared)(THIS) PURE;
    STDMETHOD_(void, put_Prepared)(THIS_ VARIANT_BOOL p) PURE;
    STDMETHOD_(ITAnyString FAR*, get_StoredProcName)(THIS) PURE;
    STDMETHOD_(BSTR, get_StoredProcNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_StoredProcName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_StoredProcNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(WORD, get_Overload)(THIS) PURE;
    STDMETHOD_(void, put_Overload)(THIS_ WORD o) PURE;
    STDMETHOD_(ITParams FAR*, get_Params)(THIS) PURE;
    STDMETHOD_(DTParams FAR*, get_ParamsDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Params)(THIS_ ITParams FAR* params) PURE;
    STDMETHOD_(void, put_ParamsDispatch)(THIS_ DTParams FAR* params) PURE;
    STDMETHOD_(TParamBindMode, get_ParamBindMode)(THIS) PURE;
    STDMETHOD_(void, put_ParamBindMode)(THIS_ TParamBindMode m) PURE;
};

DEFINE_GUID(DIID_DTStoredProc,0x2647E062,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTStoredProc */
DECLARE_INTERFACE_(DTStoredProc, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITStoredProc */
};

DEFINE_GUID(CLSID_TStoredProc,0x2647E063,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITDatabase,0x2647E071,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITDatabase */
DECLARE_INTERFACE_(ITDatabase, ITBDTComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITDatabase methods */
    STDMETHOD_(void, Close)(THIS) PURE;
    STDMETHOD_(void, CloseDatasets)(THIS) PURE;
    STDMETHOD_(void, Commit)(THIS) PURE;
    STDMETHOD_(void, Open)(THIS) PURE;
    STDMETHOD_(void, Rollback)(THIS) PURE;
    STDMETHOD_(void, StartTransaction)(THIS) PURE;
    STDMETHOD_(void, ValidateName)(THIS_ ITAnyString FAR* name) PURE;
    STDMETHOD_(void, ValidateNameDispatch)(THIS_ BSTR name) PURE;
    STDMETHOD_(int, get_DatasetCount)(THIS) PURE;
    STDMETHOD_(ITDBDataSet FAR*, get_Datasets)(THIS_ int i) PURE;
    STDMETHOD_(DTDBDataSet FAR*, get_DatasetsDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBIDb, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_IsSQLBased)(THIS) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Temporary)(THIS) PURE;
    STDMETHOD_(void, put_Temporary)(THIS_ VARIANT_BOOL t) PURE;
    STDMETHOD_(ITAnyString FAR*, get_AliasName)(THIS) PURE;
    STDMETHOD_(BSTR, get_AliasNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_AliasName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_AliasNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Connected)(THIS) PURE;
    STDMETHOD_(void, put_Connected)(THIS_ VARIANT_BOOL c) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DatabaseName)(THIS) PURE;
    STDMETHOD_(BSTR, get_DatabaseNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DatabaseName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_DatabaseNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DriverName)(THIS) PURE;
    STDMETHOD_(BSTR, get_DriverNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DriverName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_DriverNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(VARIANT_BOOL, get_KeepConnection)(THIS) PURE;
    STDMETHOD_(void, put_KeepConnection)(THIS_ VARIANT_BOOL k) PURE;
    STDMETHOD_(VARIANT_BOOL, get_LoginPrompt)(THIS) PURE;
    STDMETHOD_(void, put_LoginPrompt)(THIS_ VARIANT_BOOL l) PURE;
    STDMETHOD_(ITStrings FAR*, get_Params)(THIS) PURE;
    STDMETHOD_(DTStrings FAR*, get_ParamsDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Params)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, put_ParamsDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(TTransIsolation, get_TransIsolation)(THIS) PURE;
    STDMETHOD_(void, put_TransIsolation)(THIS_ TTransIsolation t) PURE;
    STDMETHOD_(void, AttachOnLogin)(THIS_ NLoginEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnLogin)(THIS_ NLoginEvent Callback, long Data) PURE;
};

DEFINE_GUID(DIID_DTDatabase,0x2647E072,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTDatabase */
DECLARE_INTERFACE_(DTDatabase, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITDatabase */
};

DEFINE_GUID(CLSID_TDatabase,0x2647E073,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITBatchMove,0x2647E081,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITBatchMove */
DECLARE_INTERFACE_(ITBatchMove, ITBDTComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITBatchMove methods */
    STDMETHOD_(void, Execute)(THIS) PURE;
    STDMETHOD_(long, get_ChangedCount)(THIS) PURE;
    STDMETHOD_(long, get_KeyViolCount)(THIS) PURE;
    STDMETHOD_(long, get_MovedCount)(THIS) PURE;
    STDMETHOD_(long, get_ProblemCount)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AbortOnKeyViol)(THIS) PURE;
    STDMETHOD_(void, put_AbortOnKeyViol)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AbortOnProblem)(THIS) PURE;
    STDMETHOD_(void, put_AbortOnProblem)(THIS_ VARIANT_BOOL a) PURE;
    STDMETHOD_(ITAnyString FAR*, get_ChangedTableName)(THIS) PURE;
    STDMETHOD_(BSTR, get_ChangedTableNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_ChangedTableName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_ChangedTableNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITTable FAR*, get_Destination)(THIS) PURE;
    STDMETHOD_(DTTable FAR*, get_DestinationDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Destination)(THIS_ ITTable FAR* table) PURE;
    STDMETHOD_(void, put_DestinationDispatch)(THIS_ DTTable FAR* table) PURE;
    STDMETHOD_(ITAnyString FAR*, get_KeyViolTableName)(THIS) PURE;
    STDMETHOD_(BSTR, get_KeyViolTableNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_KeyViolTableName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_KeyViolTableNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(ITStrings FAR*, get_Mappings)(THIS) PURE;
    STDMETHOD_(DTStrings FAR*, get_MappingsDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Mappings)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, put_MappingsDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(TBatchMode, get_Mode)(THIS) PURE;
    STDMETHOD_(void, put_Mode)(THIS_ TBatchMode m) PURE;
    STDMETHOD_(ITAnyString FAR*, get_ProblemTableName)(THIS) PURE;
    STDMETHOD_(BSTR, get_ProblemTableNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_ProblemTableName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_ProblemTableNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(long, get_RecordCount)(THIS) PURE;
    STDMETHOD_(void, put_RecordCount)(THIS_ long c) PURE;
    STDMETHOD_(ITDataSet FAR*, get_Source)(THIS) PURE;
    STDMETHOD_(DTDataSet FAR*, get_SourceDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Source)(THIS_ ITDataSet FAR* dataset) PURE;
    STDMETHOD_(void, put_SourceDispatch)(THIS_ DTDataSet FAR* dataset) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Transliterate)(THIS) PURE;
    STDMETHOD_(void, put_Transliterate)(THIS_ VARIANT_BOOL t) PURE;
};

DEFINE_GUID(DIID_DTBatchMove,0x2647E082,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTBatchMove */
DECLARE_INTERFACE_(DTBatchMove, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITBatchMove */
};

DEFINE_GUID(CLSID_TBatchMove,0x2647E083,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITSession,0x2647E0A1,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITSession */
DECLARE_INTERFACE_(ITSession, ITBDTComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITSession methods */
    STDMETHOD_(void, AddPassword)(THIS_ ITAnyString FAR* p) PURE;
    STDMETHOD_(void, AddPasswordDispatch)(THIS_ BSTR p) PURE;
    STDMETHOD_(void, CloseDatabase)(THIS_ ITDatabase FAR* d) PURE;
    STDMETHOD_(void, CloseDatabaseDispatch)(THIS_ DTDatabase FAR* d) PURE;
    STDMETHOD_(void, DropConnections)(THIS) PURE;
    STDMETHOD_(ITDatabase FAR*, FindDatabase)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTDatabase FAR*, FindDatabaseDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, GetAliasNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetAliasNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GetAliasParams)(THIS_ ITAnyString FAR* alias, ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetAliasParamsDispatch)(THIS_ BSTR alias, DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GetDatabaseNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetDatabaseNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GetDriverNames)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetDriverNamesDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GetDriverParams)(THIS_ ITAnyString FAR* n, ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetDriverParamsDispatch)(THIS_ BSTR n, DTStrings FAR* strings) PURE;
    STDMETHOD_(VARIANT_BOOL, GetPassword)(THIS) PURE;
    STDMETHOD_(void, GetTableNames)(THIS_ ITAnyString FAR* DatabaseName, ITAnyString FAR* Pattern, VARIANT_BOOL Extensions, VARIANT_BOOL SystemTables, ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetTableNamesDispatch)(THIS_ BSTR DatabaseName, BSTR Pattern, VARIANT_BOOL Extensions, VARIANT_BOOL SystemTables, DTStrings FAR* strings) PURE;
    STDMETHOD_(void, GetStoredProcNames)(THIS_ ITAnyString FAR* DatabaseName, ITStrings FAR* strings) PURE;
    STDMETHOD_(void, GetStoredProcNamesDispatch)(THIS_ BSTR DatabaseName, DTStrings FAR* strings) PURE;
    STDMETHOD_(ITDatabase FAR*, OpenDatabase)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTDatabase FAR*, OpenDatabaseDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, RemoveAllPasswords)(THIS) PURE;
    STDMETHOD_(void, RemovePassword)(THIS_ ITAnyString FAR* p) PURE;
    STDMETHOD_(void, RemovePasswordDispatch)(THIS_ BSTR p) PURE;
    STDMETHOD_(int, get_DatabaseCount)(THIS) PURE;
    STDMETHOD_(ITDatabase FAR*, get_Databases)(THIS_ int i) PURE;
    STDMETHOD_(DTDatabase FAR*, get_DatabasesDispatch)(THIS_ int i) PURE;
    STDMETHOD_(hDBISes, get_Handle)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_KeepConnections)(THIS) PURE;
    STDMETHOD_(void, put_KeepConnections)(THIS_ VARIANT_BOOL k) PURE;
    STDMETHOD_(TLocale, get_Locale)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_NetFileDir)(THIS) PURE;
    STDMETHOD_(BSTR, get_NetFileDirDispatch)(THIS) PURE;
    STDMETHOD_(void, put_NetFileDir)(THIS_ ITAnyString FAR* d) PURE;
    STDMETHOD_(void, put_NetFileDirDispatch)(THIS_ BSTR d) PURE;
    STDMETHOD_(ITAnyString FAR*, get_PrivateDir)(THIS) PURE;
    STDMETHOD_(BSTR, get_PrivateDirDispatch)(THIS) PURE;
    STDMETHOD_(void, put_PrivateDir)(THIS_ ITAnyString FAR* d) PURE;
    STDMETHOD_(void, put_PrivateDirDispatch)(THIS_ BSTR d) PURE;
    STDMETHOD_(void, AttachOnPassword)(THIS_ NPasswordEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnPassword)(THIS_ NPasswordEvent Callback, long Data) PURE;
};

DEFINE_GUID(DIID_DTSession,0x2647E0A2,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTSession */
DECLARE_INTERFACE_(DTSession, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITSession */
};

DEFINE_GUID(CLSID_TSession,0x2647E0A3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITField,0x2647E0B1,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITField */
DECLARE_INTERFACE_(ITField, ITBDTComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;

    /* ITBDTComponent methods */
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
#endif

    /* ITField methods */
    STDMETHOD_(void, AssignValue)(THIS_ VARIANT FAR* v) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, GetData)(THIS_ LPVOID buffer) PURE;
    STDMETHOD_(void, SetData)(THIS_ LPVOID buffer) PURE;
    STDMETHOD_(VARIANT_BOOL, IsValidChar)(THIS_ char c) PURE;
    STDMETHOD_(void, LoadFromFile)(THIS_ ITAnyString FAR* filename) PURE;
    STDMETHOD_(void, LoadFromFileDispatch)(THIS_ BSTR filename) PURE;
    STDMETHOD_(void, LoadFromStream)(THIS_ ITMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, LoadFromStreamDispatch)(THIS_ DTMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, SaveToFile)(THIS_ ITAnyString FAR* filename) PURE;
    STDMETHOD_(void, SaveToFileDispatch)(THIS_ BSTR filename) PURE;
    STDMETHOD_(void, SaveToStream)(THIS_ ITMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, SaveToStreamDispatch)(THIS_ DTMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, SaveToBitmap)(THIS_ HBITMAP FAR* hb, HPALETTE FAR* hp) PURE;
    STDMETHOD_(void, LoadFromBitmap)(THIS_ HBITMAP hb, HPALETTE hp) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AsBoolean)(THIS) PURE;
    STDMETHOD_(void, put_AsBoolean)(THIS_ VARIANT_BOOL b) PURE;
    STDMETHOD_(DATE, get_AsDateTime)(THIS) PURE;
    STDMETHOD_(void, put_AsDateTime)(THIS_ DATE d) PURE;
    STDMETHOD_(double, get_AsFloat)(THIS) PURE;
    STDMETHOD_(void, put_AsFloat)(THIS_ double d) PURE;
    STDMETHOD_(long, get_AsInteger)(THIS) PURE;
    STDMETHOD_(void, put_AsInteger)(THIS_ long l) PURE;
    STDMETHOD_(ITAnyString FAR*, get_AsString)(THIS) PURE;
    STDMETHOD_(BSTR, get_AsStringDispatch)(THIS) PURE;
    STDMETHOD_(void, put_AsString)(THIS_ ITAnyString FAR* s) PURE;
    STDMETHOD_(void, put_AsStringDispatch)(THIS_ BSTR s) PURE;
    STDMETHOD_(VARIANT_BOOL, get_CanModify)(THIS) PURE;
    STDMETHOD_(ITDataSet FAR*, get_DataSet)(THIS) PURE;
    STDMETHOD_(DTDataSet FAR*, get_DataSetDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DataSet)(THIS_ ITDataSet FAR* dataset) PURE;
    STDMETHOD_(void, put_DataSetDispatch)(THIS_ DTDataSet FAR* dataset) PURE;
    STDMETHOD_(int, get_DataSize)(THIS) PURE;
    STDMETHOD_(TFieldType, get_DataType)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DisplayText)(THIS) PURE;
    STDMETHOD_(BSTR, get_DisplayTextDispatch)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_EditMask)(THIS) PURE;
    STDMETHOD_(BSTR, get_EditMaskDispatch)(THIS) PURE;
    STDMETHOD_(void, put_EditMask)(THIS_ ITAnyString FAR* m) PURE;
    STDMETHOD_(void, put_EditMaskDispatch)(THIS_ BSTR m) PURE;
    STDMETHOD_(int, get_FieldNo)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_IsIndexField)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_IsNull)(THIS) PURE;
    STDMETHOD_(WORD, get_Size)(THIS) PURE;
    STDMETHOD_(void, put_Size)(THIS_ WORD s) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Text)(THIS) PURE;
    STDMETHOD_(BSTR, get_TextDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Text)(THIS_ ITAnyString FAR* t) PURE;
    STDMETHOD_(void, put_TextDispatch)(THIS_ BSTR t) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Calculated)(THIS) PURE;
    STDMETHOD_(void, put_Calculated)(THIS_ VARIANT_BOOL c) PURE;
    STDMETHOD_(ITAnyString FAR*, get_FieldName)(THIS) PURE;
    STDMETHOD_(BSTR, get_FieldNameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_FieldName)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_FieldNameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(int, get_Index)(THIS) PURE;
    STDMETHOD_(void, put_Index)(THIS_ int i) PURE;
    STDMETHOD_(VARIANT_BOOL, get_ReadOnly)(THIS) PURE;
    STDMETHOD_(void, put_ReadOnly)(THIS_ VARIANT_BOOL r) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Required)(THIS) PURE;
    STDMETHOD_(void, put_Required)(THIS_ VARIANT_BOOL r) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Visible)(THIS) PURE;
    STDMETHOD_(void, put_Visible)(THIS_ VARIANT_BOOL v) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Transliterate)(THIS) PURE;
    STDMETHOD_(void, put_Transliterate)(THIS_ VARIANT_BOOL t) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DisplayFormat)(THIS) PURE;
    STDMETHOD_(BSTR, get_DisplayFormatDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DisplayFormat)(THIS_ ITAnyString FAR* f) PURE;
    STDMETHOD_(void, put_DisplayFormatDispatch)(THIS_ BSTR f) PURE;
    STDMETHOD_(ITAnyString FAR*, get_EditFormat)(THIS) PURE;
    STDMETHOD_(BSTR, get_EditFormatDispatch)(THIS) PURE;
    STDMETHOD_(void, put_EditFormat)(THIS_ ITAnyString FAR* f) PURE;
    STDMETHOD_(void, put_EditFormatDispatch)(THIS_ BSTR f) PURE;
    STDMETHOD_(long, get_MaxValueAsInteger)(THIS) PURE;
    STDMETHOD_(void, put_MaxValueAsInteger)(THIS_ long l) PURE;
    STDMETHOD_(long, get_MinValueAsInteger)(THIS) PURE;
    STDMETHOD_(void, put_MinValueAsInteger)(THIS_ long l) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Currency)(THIS) PURE;
    STDMETHOD_(void, put_Currency)(THIS_ VARIANT_BOOL c) PURE;
    STDMETHOD_(double, get_MaxValueAsFloat)(THIS) PURE;
    STDMETHOD_(void, put_MaxValueAsFloat)(THIS_ double d) PURE;
    STDMETHOD_(double, get_MinValueAsFloat)(THIS) PURE;
    STDMETHOD_(void, put_MinValueAsFloat)(THIS_ double d) PURE;
    STDMETHOD_(int, get_Precision)(THIS) PURE;
    STDMETHOD_(void, put_Precision)(THIS_ int p) PURE;
    STDMETHOD_(ITAnyString FAR*, get_DisplayValues)(THIS) PURE;
    STDMETHOD_(BSTR, get_DisplayValuesDispatch)(THIS) PURE;
    STDMETHOD_(void, put_DisplayValues)(THIS_ ITAnyString FAR* d) PURE;
    STDMETHOD_(void, put_DisplayValuesDispatch)(THIS_ BSTR d) PURE;
    STDMETHOD_(void, AttachOnChange)(THIS_ NFieldNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnChange)(THIS_ NFieldNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnGetText)(THIS_ NFieldGetTextEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnGetText)(THIS_ NFieldGetTextEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnSetText)(THIS_ NFieldSetTextEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnSetText)(THIS_ NFieldSetTextEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnValidate)(THIS_ NFieldNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnValidate)(THIS_ NFieldNotifyEvent Callback, long Data) PURE;
};

DEFINE_GUID(DIID_DTField,0x2647E0B2,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTField */
DECLARE_INTERFACE_(DTField, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITField */
};

DEFINE_GUID(CLSID_TField,0x2647E0B3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITFieldDef,0x2647E0D1,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITFieldDef */
DECLARE_INTERFACE_(ITFieldDef, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITFieldDef methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(ITField FAR*, CreateField)(THIS_ ITBDTComponent FAR* Owner) PURE;
    STDMETHOD_(DTField FAR*, CreateFieldDispatch)(THIS_ DTBDTComponent FAR* Owner) PURE;
    STDMETHOD_(TFieldType, get_DataType)(THIS) PURE;
    STDMETHOD_(int, get_FieldNo)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Required)(THIS) PURE;
    STDMETHOD_(WORD, get_Size)(THIS) PURE;
};

DEFINE_GUID(DIID_DTFieldDef,0x2647E0D2,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTFieldDef */
DECLARE_INTERFACE_(DTFieldDef, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITFieldDef */
};

DEFINE_GUID(CLSID_TFieldDef,0x2647E0D3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITFieldDefs,0x2647E0E1,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITFieldDefs */
DECLARE_INTERFACE_(ITFieldDefs, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITFieldDefs methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Add)(THIS_ ITAnyString FAR* Name, TFieldType DataType, WORD Size, VARIANT_BOOL Required) PURE;
    STDMETHOD_(void, AddDispatch)(THIS_ BSTR Name, TFieldType DataType, WORD Size, VARIANT_BOOL Required) PURE;
    STDMETHOD_(void, AddFieldDesc)(THIS_ pFLDDesc desc, VARIANT_BOOL Required, WORD fieldNo) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITFieldDefs FAR* fieldDefs) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTFieldDefs FAR* fieldDefs) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
    STDMETHOD_(ITFieldDef FAR*, Find)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(DTFieldDef FAR*, FindDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(int, IndexOf)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(int, IndexOfDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, Update)(THIS) PURE;
    STDMETHOD_(int, get_Count)(THIS) PURE;
    STDMETHOD_(ITFieldDef FAR*, get_Items)(THIS_ int i) PURE;
    STDMETHOD_(DTFieldDef FAR*, get_ItemsDispatch)(THIS_ int i) PURE;
};

DEFINE_GUID(DIID_DTFieldDefs,0x2647E0E2,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTFieldDefs */
DECLARE_INTERFACE_(DTFieldDefs, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITFieldDefs */
};

DEFINE_GUID(CLSID_TFieldDefs,0x2647E0E3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITIndexDef,0x2647E0F1,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITIndexDef */
DECLARE_INTERFACE_(ITIndexDef, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITIndexDef methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Expression)(THIS) PURE;
    STDMETHOD_(BSTR, get_ExpressionDispatch)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Fields)(THIS) PURE;
    STDMETHOD_(BSTR, get_FieldsDispatch)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(TIndexOptions, get_Options)(THIS) PURE;
};

DEFINE_GUID(DIID_DTIndexDef,0x2647E0F2,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTIndexDef */
DECLARE_INTERFACE_(DTIndexDef, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITIndexDef */
};

DEFINE_GUID(CLSID_TIndexDef,0x2647E0F3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITIndexDefs,0x2647E101,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITIndexDefs */
DECLARE_INTERFACE_(ITIndexDefs, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITIndexDefs methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Add)(THIS_ ITAnyString FAR* name, ITAnyString FAR* fields, TIndexOptions options) PURE;
    STDMETHOD_(void, AddDispatch)(THIS_ BSTR name, BSTR fields, TIndexOptions options) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITIndexDefs FAR* indexDefs) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTIndexDefs FAR* indexDefs) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
    STDMETHOD_(ITIndexDef FAR*, FindIndexForFields)(THIS_ ITAnyString FAR* fields) PURE;
    STDMETHOD_(DTIndexDef FAR*, FindIndexForFieldsDispatch)(THIS_ BSTR fields) PURE;
    STDMETHOD_(int, IndexOf)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(int, IndexOfDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(void, Update)(THIS) PURE;
    STDMETHOD_(int, get_Count)(THIS) PURE;
    STDMETHOD_(ITIndexDef FAR*, get_Items)(THIS_ int i) PURE;
    STDMETHOD_(DTIndexDef FAR*, get_ItemsDispatch)(THIS_ int i) PURE;
};

DEFINE_GUID(DIID_DTIndexDefs,0x2647E102,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTIndexDefs */
DECLARE_INTERFACE_(DTIndexDefs, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITIndexDefs */
};

DEFINE_GUID(CLSID_TIndexDefs,0x2647E103,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITParam,0x2647E111,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITParam */
DECLARE_INTERFACE_(ITParam, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITParam methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITParam FAR* param) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTParam FAR* param) PURE;
    STDMETHOD_(void, AssignField)(THIS_ ITField FAR* field) PURE;
    STDMETHOD_(void, AssignFieldDispatch)(THIS_ DTField FAR* field) PURE;
    STDMETHOD_(void, GetData)(THIS_ LPVOID buffer) PURE;
    STDMETHOD_(WORD, GetDataSize)(THIS) PURE;
    STDMETHOD_(void, SetData)(THIS_ LPVOID buffer) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Name)(THIS) PURE;
    STDMETHOD_(BSTR, get_NameDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Name)(THIS_ ITAnyString FAR* n) PURE;
    STDMETHOD_(void, put_NameDispatch)(THIS_ BSTR n) PURE;
    STDMETHOD_(TFieldType, get_DataType)(THIS) PURE;
    STDMETHOD_(void, put_DataType)(THIS_ TFieldType t) PURE;
    STDMETHOD_(VARIANT_BOOL, get_AsBoolean)(THIS) PURE;
    STDMETHOD_(void, put_AsBoolean)(THIS_ VARIANT_BOOL b) PURE;
    STDMETHOD_(double, get_AsFloat)(THIS) PURE;
    STDMETHOD_(void, put_AsFloat)(THIS_ double d) PURE;
    STDMETHOD_(long, get_AsInteger)(THIS) PURE;
    STDMETHOD_(void, put_AsInteger)(THIS_ long l) PURE;
    STDMETHOD_(ITAnyString FAR*, get_AsString)(THIS) PURE;
    STDMETHOD_(BSTR, get_AsStringDispatch)(THIS) PURE;
    STDMETHOD_(void, put_AsString)(THIS_ ITAnyString FAR* s) PURE;
    STDMETHOD_(void, put_AsStringDispatch)(THIS_ BSTR s) PURE;
    STDMETHOD_(DATE, get_AsDate)(THIS) PURE;
    STDMETHOD_(void, put_AsDate)(THIS_ DATE d) PURE;
    STDMETHOD_(DATE, get_AsTime)(THIS) PURE;
    STDMETHOD_(void, put_AsTime)(THIS_ DATE d) PURE;
    STDMETHOD_(DATE, get_AsDateTime)(THIS) PURE;
    STDMETHOD_(void, put_AsDateTime)(THIS_ DATE d) PURE;
    STDMETHOD_(long, get_AsSmallInt)(THIS) PURE;
    STDMETHOD_(void, put_AsSmallInt)(THIS_ long l) PURE;
    STDMETHOD_(long, get_AsWord)(THIS) PURE;
    STDMETHOD_(void, put_AsWord)(THIS_ long l) PURE;
    STDMETHOD_(double, get_AsCurrency)(THIS) PURE;
    STDMETHOD_(void, put_AsCurrency)(THIS_ double d) PURE;
    STDMETHOD_(double, get_AsBCD)(THIS) PURE;
    STDMETHOD_(void, put_AsBCD)(THIS_ double d) PURE;
    STDMETHOD_(VARIANT_BOOL, get_IsNull)(THIS) PURE;
    STDMETHOD_(TParamType, get_ParamType)(THIS) PURE;
    STDMETHOD_(void, put_ParamType)(THIS_ TParamType t) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Bound)(THIS) PURE;
    STDMETHOD_(void, put_Bound)(THIS_ VARIANT_BOOL b) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Text)(THIS) PURE;
    STDMETHOD_(BSTR, get_TextDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Text)(THIS_ ITAnyString FAR* t) PURE;
    STDMETHOD_(void, put_TextDispatch)(THIS_ BSTR t) PURE;
};

DEFINE_GUID(DIID_DTParam,0x2647E112,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTParam */
DECLARE_INTERFACE_(DTParam, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITParam */
};

DEFINE_GUID(CLSID_TParam,0x2647E113,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITParams,0x2647E121,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITParams */
DECLARE_INTERFACE_(ITParams, ITBDTObject)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;
#endif

    /* ITParams methods */
    STDMETHOD_(void, AssignValues)(THIS_ ITParams FAR* params) PURE;
    STDMETHOD_(void, AssignValuesDispatch)(THIS_ DTParams FAR* params) PURE;
    STDMETHOD_(void, AddParam)(THIS_ ITParam FAR* param) PURE;
    STDMETHOD_(void, AddParamDispatch)(THIS_ DTParam FAR* param) PURE;
    STDMETHOD_(void, RemoveParam)(THIS_ ITParam FAR* param) PURE;
    STDMETHOD_(void, RemoveParamDispatch)(THIS_ DTParam FAR* param) PURE;
    STDMETHOD_(ITParam FAR*, CreateParam)(THIS_ TFieldType fldType, ITAnyString FAR* name, TParamType paramType) PURE;
    STDMETHOD_(DTParam FAR*, CreateParamDispatch)(THIS_ TFieldType fldType, BSTR name, TParamType paramType) PURE;
    STDMETHOD_(int, get_Count)(THIS) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
    STDMETHOD_(ITParam FAR*, ParamByName)(THIS_ ITAnyString FAR* value) PURE;
    STDMETHOD_(DTParam FAR*, ParamByNameDispatch)(THIS_ BSTR value) PURE;
    STDMETHOD_(ITParam FAR*, get_Items)(THIS_ WORD i) PURE;
    STDMETHOD_(DTParam FAR*, get_ItemsDispatch)(THIS_ WORD i) PURE;
};

DEFINE_GUID(DIID_DTParams,0x2647E122,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTParams */
DECLARE_INTERFACE_(DTParams, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITParams */
};

DEFINE_GUID(CLSID_TParams,0x2647E123,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITStrings,0x2647E131,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITStrings */
DECLARE_INTERFACE_(ITStrings, ITBDTObject)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ITBDTObject methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(void, Assign)(THIS_ ITBDTObject FAR* source) PURE;
    STDMETHOD_(void, AssignDispatch)(THIS_ DTBDTObject FAR* source) PURE;
#endif

    /* ITStrings methods */
    STDMETHOD_(int, Add)(THIS_ ITAnyString FAR* s) PURE;
    STDMETHOD_(int, AddDispatch)(THIS_ BSTR s) PURE;
    STDMETHOD_(int, AddObject)(THIS_ ITAnyString FAR* s, LPVOID obj) PURE;
    STDMETHOD_(int, AddObjectDispatch)(THIS_ BSTR s, LPVOID obj) PURE;
    STDMETHOD_(void, AddStrings)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(void, AddStringsDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, BeginUpdate)(THIS) PURE;
    STDMETHOD_(void, Clear)(THIS) PURE;
    STDMETHOD_(void, Delete)(THIS_ int index) PURE;
    STDMETHOD_(void, EndUpdate)(THIS) PURE;
    STDMETHOD_(VARIANT_BOOL, Equals)(THIS_ ITStrings FAR* strings) PURE;
    STDMETHOD_(VARIANT_BOOL, EqualsDispatch)(THIS_ DTStrings FAR* strings) PURE;
    STDMETHOD_(void, Exchange)(THIS_ int index1, int index2) PURE;
    STDMETHOD_(VARIANT_BOOL, Find)(THIS_ ITAnyString FAR* s, int FAR* index) PURE;
    STDMETHOD_(VARIANT_BOOL, FindDispatch)(THIS_ BSTR s, int FAR* index) PURE;
    STDMETHOD_(int, IndexOf)(THIS_ ITAnyString FAR* s) PURE;
    STDMETHOD_(int, IndexOfDispatch)(THIS_ BSTR s) PURE;
    STDMETHOD_(int, IndexOfObject)(THIS_ LPVOID obj) PURE;
    STDMETHOD_(void, Insert)(THIS_ int index, ITAnyString FAR* s) PURE;
    STDMETHOD_(void, InsertDispatch)(THIS_ int index, BSTR s) PURE;
    STDMETHOD_(void, InsertObject)(THIS_ int index, ITAnyString FAR* s, LPVOID obj) PURE;
    STDMETHOD_(void, InsertObjectDispatch)(THIS_ int index, BSTR s, LPVOID obj) PURE;
    STDMETHOD_(void, LoadFromFile)(THIS_ ITAnyString FAR* filename) PURE;
    STDMETHOD_(void, LoadFromFileDispatch)(THIS_ BSTR filename) PURE;
    STDMETHOD_(void, LoadFromStream)(THIS_ ITMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, LoadFromStreamDispatch)(THIS_ DTMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, Move)(THIS_ int curIndex, int newIndex) PURE;
    STDMETHOD_(void, SaveToFile)(THIS_ ITAnyString FAR* filename) PURE;
    STDMETHOD_(void, SaveToFileDispatch)(THIS_ BSTR filename) PURE;
    STDMETHOD_(void, SaveToStream)(THIS_ ITMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, SaveToStreamDispatch)(THIS_ DTMemoryStream FAR* stream) PURE;
    STDMETHOD_(void, Sort)(THIS) PURE;
    STDMETHOD_(int, get_Count)(THIS) PURE;
    STDMETHOD_(LPVOID, get_Objects)(THIS_ int index) PURE;
    STDMETHOD_(void, put_Objects)(THIS_ int index, LPVOID obj) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Values)(THIS_ ITAnyString FAR* name) PURE;
    STDMETHOD_(BSTR, get_ValuesDispatch)(THIS_ BSTR name) PURE;
    STDMETHOD_(void, put_Values)(THIS_ ITAnyString FAR* name, ITAnyString FAR* value) PURE;
    STDMETHOD_(void, put_ValuesDispatch)(THIS_ BSTR name, BSTR value) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Strings)(THIS_ int index) PURE;
    STDMETHOD_(BSTR, get_StringsDispatch)(THIS_ int index) PURE;
    STDMETHOD_(void, put_Strings)(THIS_ int index, ITAnyString FAR* s) PURE;
    STDMETHOD_(void, put_StringsDispatch)(THIS_ int index, BSTR s) PURE;
    STDMETHOD_(ITAnyString FAR*, get_Text)(THIS) PURE;
    STDMETHOD_(BSTR, get_TextDispatch)(THIS) PURE;
    STDMETHOD_(void, put_Text)(THIS_ ITAnyString FAR* t) PURE;
    STDMETHOD_(void, put_TextDispatch)(THIS_ BSTR t) PURE;
    STDMETHOD_(TDuplicates, get_Duplicates)(THIS) PURE;
    STDMETHOD_(void, put_Duplicates)(THIS_ TDuplicates d) PURE;
    STDMETHOD_(VARIANT_BOOL, get_Sorted)(THIS) PURE;
    STDMETHOD_(void, put_Sorted)(THIS_ VARIANT_BOOL s) PURE;
    STDMETHOD_(void, AttachOnChange)(THIS_ NStringsNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnChange)(THIS_ NStringsNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, AttachOnChanging)(THIS_ NStringsNotifyEvent Callback, long Data) PURE;
    STDMETHOD_(void, DetachOnChanging)(THIS_ NStringsNotifyEvent Callback, long Data) PURE;
};

DEFINE_GUID(DIID_DTStrings,0x2647E132,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTStrings */
DECLARE_INTERFACE_(DTStrings, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITStrings */
};

DEFINE_GUID(CLSID_TStrings,0x2647E133,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITMemoryStream,0x2647E141,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITMemoryStream */
DECLARE_INTERFACE_(ITMemoryStream, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITMemoryStream methods */
    STDMETHOD_(void, Detach)(THIS) PURE;
    STDMETHOD_(long, Read)(THIS_ LPVOID Buffer, long Count) PURE;
    STDMETHOD_(long, Write)(THIS_ LPVOID Buffer, long Count) PURE;
    STDMETHOD_(long, Seek)(THIS_ long Offset, TSeekOrigin Origin) PURE;
    STDMETHOD_(void, ReadBuffer)(THIS_ LPVOID Buffer, long Count) PURE;
    STDMETHOD_(void, WriteBuffer)(THIS_ LPVOID Buffer, long Count) PURE;
    STDMETHOD_(long, CopyFrom)(THIS_ ITMemoryStream FAR* stream, long Count) PURE;
    STDMETHOD_(long, CopyFromDispatch)(THIS_ DTMemoryStream FAR* stream, long Count) PURE;
    STDMETHOD_(long, get_Position)(THIS) PURE;
    STDMETHOD_(void, put_Position)(THIS_ long p) PURE;
    STDMETHOD_(long, get_Size)(THIS) PURE;
};

DEFINE_GUID(DIID_DTMemoryStream,0x2647E142,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTMemoryStream */
DECLARE_INTERFACE_(DTMemoryStream, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITMemoryStream */
};

DEFINE_GUID(CLSID_TMemoryStream,0x2647E143,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(IID_ITAnyString,0x2647E151,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of interface: ITAnyString */
DECLARE_INTERFACE_(ITAnyString, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ITAnyString methods */
    STDMETHOD_(BSTR, get_AsBSTR)(THIS) PURE;
    STDMETHOD_(void, put_AsBSTR)(THIS_ BSTR s) PURE;
    STDMETHOD_(void, get_AsStringBuf)(THIS_ LPSTR s, int max) PURE;
    STDMETHOD_(void, put_AsStringBuf)(THIS_ LPCSTR s) PURE;
    STDMETHOD_(int, get_Length)(THIS) PURE;
    STDMETHOD_(LPCSTR, get_Buffer)(THIS) PURE;
};

DEFINE_GUID(DIID_DTAnyString,0x2647E152,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);

/* Definition of dispatch interface: DTAnyString */
DECLARE_INTERFACE_(DTAnyString, IDispatch)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD(GetTypeInfoCount)(THIS_ UINT FAR* pctinfo) PURE;

    STDMETHOD(GetTypeInfo)(
      THIS_
      UINT itinfo,
      LCID lcid,
      ITypeInfo FAR* FAR* pptinfo) PURE;

    STDMETHOD(GetIDsOfNames)(
      THIS_
      REFIID riid,
      OLECHAR FAR* FAR* rgszNames,
      UINT cNames,
      LCID lcid,
      DISPID FAR* rgdispid) PURE;

    STDMETHOD(Invoke)(
      THIS_
      DISPID dispidMember,
      REFIID riid,
      LCID lcid,
      WORD wFlags,
      DISPPARAMS FAR* pdispparams,
      VARIANT FAR* pvarResult,
      EXCEPINFO FAR* pexcepinfo,
      UINT FAR* puArgErr) PURE;
#endif

/* Capable of dispatching all the methods of interface ITAnyString */
};

DEFINE_GUID(CLSID_TAnyString,0x2647E153,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TStringField,0x2647E163,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TSmallintField,0x2647E173,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TIntegerField,0x2647E183,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TWordField,0x2647E193,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TBooleanField,0x2647E1A3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TNumericField,0x2647E1B3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TFloatField,0x2647E1C3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TCurrencyField,0x2647E1D3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TBCDField,0x2647E1E3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TDateField,0x2647E1F3,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TTimeField,0x2647E203,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TDateTimeField,0x2647E213,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TBytesField,0x2647E223,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TVarBytesField,0x2647E233,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TBlobField,0x2647E243,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TMemoField,0x2647E253,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


DEFINE_GUID(CLSID_TGraphicField,0x2647E263,0x91D6,0x11CE,0x88,0x57,0x00,0x20,0xAF,0x05,0xB1,0x9B);


#endif
