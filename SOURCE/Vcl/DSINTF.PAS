
{*******************************************************}
{                                                       }
{       Borland Delphi Visual Component Library         }
{       DBClient Interface                              }
{                                                       }
{       Copyright (c) 1997,99 Inprise Corporation       }
{                                                       }
{*******************************************************}

unit DSIntf;

{$MINENUMSIZE 4}
{$T-,H+,X+}

interface

uses Windows, ActiveX, DB, DBCommon;

const

{ Record attributes }

  dsRecUnmodified    = $0000;       { Unmodified record }
  dsRecOrg           = $0001;       { Original record (was changed) }
  dsRecDeleted       = $0002;       { Record was deleted }
  dsRecNew           = $0004;       { Record was inserted }
  dsRecModified      = $0008;       { Record was changed }
  dsUnused           = $0020;       { Record not used anymore (hole) }
  dsDetUpd           = $0040;       { Detail modification  Ins/Del/Mod. }
                                    { Can be combined with other status. }
  dsIsNotVisible     = dsRecDeleted or dsRecOrg or dsUnused;
  dsIsVisible        = not (dsRecDeleted or dsRecOrg or dsUnused);

{ Field attributes }

  fldAttrHIDDEN      = $0001;       { Field is hidden }
  fldAttrREADONLY    = $0002;       { Field is readonly }
  fldAttrREQUIRED    = $0004;       { Field value required }
  fldAttrLINK        = $0008;       { Linking field }

  BLANK_NULL         = 1;           { 'real' NULL }
  BLANK_NOTCHANGED   = 2;           { Not changed , compared to original value }

  MAXKEYFIELDS       = 16;

{ Master Detail Semantics DSBase.SetProp(dspropMD_SEMANTICS, Value) }

  mdCASCADEDEL       = $0004;
  mdCASCADEMOD       = $0008;  { Allow master link field to be changed (cascade change to details) }
  mdALLOWLINKCHANGE  = $0010;  { Allow detail linkfields to be changed (fly-away) }

type
  DBResult          = Word;         { Function result }

  DBSearchCond = (                     { Search condition for keys }
    keySEARCHEQ,                          { = }
    keySEARCHGT,                          { > }
    keySEARCHGEQ                          { >= }
  );

  MIDASNAME            = packed array [0..31] of Char; { holds a name }
  MIDASPATH            = packed array [0..260] of Char; { holds a DOS path }

{ Native Types }

  TDataPacket = PSafeArray;

  pDSAttr = ^DSAttr;
  DSAttr = type Byte;

  phDSFilter = ^hDSFilter;
  hDSFilter = type Pointer;

  GROUPSTATE = (
    grSTATEMIDDLE,                  { Record is neither the first or the last in the group }
    grSTATEFIRST,                   { Record is the first in the group }
    grSTATELAST,                    { Record is the last in the group }
    grSTATEFIRSTLAST
  );

  phDSAggregate = ^hDSAggregate;
  hDSAggregate = type Integer;

  AGGSTATE = (
    aggSTATEUNDEF,                  { State is undefined. Needs recalc. }
    aggSTATEOK,
    aggSTATEBLANK,                  { This is a blank value }
    aggSTATEERROR                   { An error occurred previously }
  );

  AGGVALUE = packed record
    iCnt      : Integer;            { Count of records in each }
    eAggState : AGGSTATE;           { State of value }
    Value     : record end;         { First byte of value }
  end;

  pDSBOOKMRK = ^DSBOOKMRK;
  DSBOOKMRK = packed record
    iPos   : Integer;               { Position in given order }
    iState : Integer;               { State of cursor }
    iRecNo : Integer;               { Record number }
    iSeqNo : Integer;               { Version number of order }
    iOrderID : Integer;             { Defines Order }
  end;

  pSAVEPOINT = ^SAVEPOINT;
  SAVEPOINT = type Integer;

  DSKEY = packed array[0..MAXKEYFIELDS-1] of Integer;
  DSKEYBOOL = packed array[0..MAXKEYFIELDS-1] of Bool;

{ Dataset and Cursor Properties }

  DSProp = (
    dspropLOGCHANGES,               { rw BOOL,   Log changes for undo/delta }
    dspropREADONLY,                 { rw BOOL,   Disable dataset updates }
    dspropNOOFCHANGES,              { r  UINT32, Number of changes }
    dspropCONSTRAINTS_DISABLED,     { rw BOOL,   Disable constraints }
    dspropDSISPARTIAL,              { rw BOOL,   Dataset is parital }
    dspropRECORDSINDS,              { r  UINT32, Records in dataset }
    dspropAUTOINC_DISABLED,         { rw BOOL,   Autoinc disabled }
    dspropISDELTA,                  { r  BOOL,   Dataset is a delta }
    dspropDONTINCLMETADATA,         { rw BOOL,   Exclude metadata in StreamDS }
    dspropINCLBLOBSINDELTA,         { rw UINT32, include blobs with lengths <= than }
                                    { this value in delta for 'original' record }
    dspropGETSAVEPOINT,             { r  SAVEPOINT, return savepoint for current update state. }
    dspropCOMPRESSARRAYS,           { rw BOOL(TRUE), if true expands fielddescriptors for arrays }
    dspropMD_SEMANTICS,             { rw UINT32(0), Master/detail semantics }
    dspropFIELD_FULLNAME,           { r  in: UINT32 (FieldID), out: zstring (full name) }
    dspropFIELDID_FORNAME,          { r  in: zstring(full name), out:UINT32 (fieldid) }
    dspropFIELDID_FORPARENT,        { r  in: UINT32 (FieldID), out: UINT32 (FieldID) }
    dspropCHANGEINDEX_VIEW,         { rw DSAttr (UINT32) (update attributes), any combination, 0->show all }
    dspropGETUNIQUEINDEX,           { r  DSIDX, internal use, returns first unique index, if any }
    dspropREMOTE_UPDATEMODE,        { rw UINT32, 0: where key, 1: where all, 3: where ch }
    dspropXML_STREAMMODE
  );

  CURProp = (
    curpropCONSTRAINT_ERROR_MESSAGE,{ r pCHAR,   Constraint Error Message }
    curpropDSBASE,                  { r pDSBASE, Underlying DSBASE) }
    curpropSETCRACK,                { w Sets crack-value to supplied value (DBERR_NOCURRREC) }
    curpropGETORG_RECBUF            { r returns recordbuffer for original record, error if none }
  );

  pDSProps = ^DSProps;
  DSProps = packed record
    szName           : MIDASPATH;      { Name, if any }
    iFields          : Integer;      { Number of columns }
    iRecBufSize      : Integer;      { Size of record buffer }
    iBookMarkSize    : Integer;      { Size of bookmark }
    bReadOnly        : Bool;         { Dataset is not updateable }
    iIndexes         : Integer;      { Number of indexes on dataset }
    iOptParams       : Integer;      { Number of optional parameters }
    bDelta           : Bool;         { This is a delta dataset }
    iLCID            : Integer;      { Language used }
    iUnused          : packed array[0..7] of Integer; { Reserved }
  end;

{ Field Descriptor }

  pDSFLDDesc = ^DSFLDDesc;
  DSFLDDesc = packed record
    szName          : MIDASNAME;      { Field name }
    iFldType        : Integer;      { Field type }
    iFldSubType     : Integer;      { Field subtype (if applicable) }
    iUnits1         : Integer;      { Number of Chars, precision etc }
    iUnits2         : Integer;      { Decimal places etc. }
    iFldLen         : Integer;      { Length in bytes (computed) }
    iFldOffsInRec   : Integer;      { Offset to field  in record buffer }
    iNullOffsInRec  : Integer;      { Offset to null flag (1byte) in record buffer }
    iFieldID        : Word;         { FieldID of this field }
    iFieldIDParent  : Word;         { FieldID of parent, if any (part of ADT or ARRAY) }
    bCalculated     : Bool;         { Field is Calculated }
    iFldAttr        : Integer;      { Field attributes }
    iOptParameters  : Integer;      { Number of optional parameters for field }
  end;

{  Index descriptor }

  pDSIDXDesc = ^DSIDXDesc;
  DSIDXDesc = packed record
    szName    : MIDASNAME;            { IndexName }
    iFields   : Integer;            { Number of fields in order (0 -> base order) }
    iKeyFields: DSKEY;              { FieldNumbers }
    iKeyLen   : Integer;            { Total length of key (computed) }
    bUnique   : Bool;
    bDescending  : DSKEYBOOL;       { TRUE ->Descending }
    bCaseInsensitive : DSKEYBOOL;
  end;

{ Callbacks }

  pfCHANGECallBack = procedure(     { Change Notification callback }
    iClientData  : Integer          { Client data }
  ); stdcall;

  pfDSFilter = function(            { Filter callback }
    iClientData  : Integer;         { Client data }
    pRecBuf      : Pointer            { Record buffer }
  ): Bool; stdcall;

  pfDSCalcField = function(         { Calculated field callback }
    iClientData  : Integer;         { Client data }
    pRecBuf      : Pointer          { Current record-buffer }
  ): DBResult; stdcall;

  dsCBRType = Integer;              { Return value for reconcile callback }
  pdsCBRType = ^dsCBRType;

  pfDSReconcile = function(         { Reconcile callback }
    iClientData   : Integer;        { Client data }
    iRslt         : Integer;        { Result of previous callback }
    iAction       : DSAttr;         { Update request Insert/Modify/Delete }
    iResponse     : dsCBRType;      { Resolver response }
    iErrCode      : Integer;        { Native error-code }
    pErrMessage   : PChar;          { Native errormessage if any }
    pErrContext   : PChar;          { 1-level error context, if any }
    pRecUpd       : Pointer;        { Record that failed update }
    pRecOrg       : Pointer;        { Original record, if any }
    pRecConflict  : Pointer         { Conflicting record, if any }
  ): dsCBRType; stdcall;

  pfDSReconcile_MD = function(
    iClientData   : Integer;
    iRslt         : Integer;  { Result of previous callback. If set, the previuos parameters are repeated. }
    iAction       : DSAttr;   { Update request Insert/Modify/Delete }
    iErrResponse  : dsCBRType; { Resolver response }
    iErrCode      : Integer;  { Native error-code, (BDE or ..) }
    pErrMessage   : PChar;    { Native errormessage, if any (otherwise NULL) }
    pErrContext   : PChar;    { 1-level error context, if any (otherwise NULL) }
    pRecUpd       : PByte;    { Record that failed update }
    pRecOrg       : PByte;    { Original record, if any }
    pRecConflict  : PByte;    { Conflicting error, if any }
    iLevels       : Integer;  { Number of levels to error0level }
    piFieldIDs    : PInteger  { Array of fieldIDS to navigate to error-dataset }
): dsCBRType;

  pfFLDComp = function(             { Field compare callback }
    iClientData  : Integer;         { Client callback data }
    pVal1        : Pointer;         { Fieldvalue 1 (NULL if blank) }
    pVal2        : Pointer          { Fieldvalue 2 (NULL if blank) }
  ): Integer;                       { returns -1 if pVal1 < pVal2, }
                                    { 0 if equal, +1 if pVal1 > pVal2 }

{ Resolver & Reconcile callback return values }

const
  dscbrSKIP          = 1;   { Skip this operation (resolver : report error) }
  dscbrABORT         = 2;   { Abort the callback session (reconcile or resolve) }
                            { (resolver : undo all changes). }
  dscbrMERGE         = 3;   { Merge the changes  (resolver : 'simple' merge) }
                            { (reconcile : update original. Keep change). }
  { Resolving only }
  dscbrAPPLY         = 4;   { Overwrite the current record with new values. }
  dscbrIGNORE        = 5;   { Ignore the update request. Don't report error. }

  { Reconcile only }
  dscbrCORRECT       = 4;   { Overwrite change with new values. }
  dscbrCANCEL        = 5;   { Cancel change (remove from delta). }
  dscbrREFRESH       = 6;   { Update original record. Cancel change. }

{ Defines for SetXmlMode/GetXmlMode }

  xmlUNTYPED         =  1;  { Forces XML Data }
  xmlXMLDATATYPED    =  2;  { Not used }
  xmlXMLSCHEMA       =  4;  { Get XML Meta Data }

  xmlON              = xmlXMLSCHEMA or xmlUNTYPED;
  xmlOFF             =  0;      


{ Packet Creation }

type
  TPcktAttrArea = (fldAttrArea, pcktAttrArea);
  TPcktFldStatus = (fldIsChanged, fldIsNull, fldIsUnChanged);

  PDSDataPacketFldDesc = ^TDSDataPacketFldDesc;
  TDSDataPacketFldDesc = packed record
    szFieldName: MIDASNAME;           { Column Name }
    iFieldType: Integer;            { Column Type }
    iAttributes: Word;              { Column attributes }
  end;

const
{Do not localize }
  szUNIQUE_KEY       = 'UNIQUE_KEY';  { Series of unique keys to enforce on the client }
  szPRIMARY_KEY      = 'PRIMARY_KEY'; { Primary key used in RowRequest and for key information }
  szDEFAULT_ORDER    = 'DEFAULT_ORDER'; { Index used for the default ordering of the dataset }
  szCHANGEINDEX      = 'CHANGEINDEX';
  szCHANGE_LOG       = 'CHANGE_LOG';
  szSERVER_COL       = 'SERVER_COL';
  szCONSTRAINTS      = 'CONSTRAINTS';
  szDATASET_CONTEXT  = 'DATASET_CONTEXT';
  szDATASET_DELTA    = 'DATASET_DELTA';
  szREADONLY         = 'READONLY'; { Specifies the packet is read only }
  szSUBTYPE          = 'SUBTYPE'; { Field Subtype }
  szDECIMALS         = 'DECIMALS'; { Field decimal precision }
  szWIDTH            = 'WIDTH'; { Field width }
  szLCID             = 'LCID'; { Locale ID that the packet comes from }
  szBDEDOMX          = 'BDEDOMAIN_X'; { Server side field constraints }
  szBDERECX          = 'BDERECORD_X'; { Server side record constraints }
  szBDEDEFX          = 'BDEDEFAULT_X'; { Server side default values }
  szAUTOINCVALUE     = 'AUTOINCVALUE';
  szELEMENTS         = 'ELEMENTS';
  szTABLE_NAME       = 'TABLE_NAME'; { Table name used for resolving the packet - deprecated}
  szMD_FIELDLINKS    = 'MD_FIELDLINKS'; { Master detail field relationships }
  szTYPENAME         = 'TYPENAME'; { Field type name.  Used for object fields }
  szUPDATEMODE       = 'UPDATEMODE'; { Update mode }
  szFIELDPROPS       = 'FIELDPROPS'; { Delphi transferable field properties }
  szPROVFLAGS        = 'PROVFLAGS'; { Provider flags }
  szORIGIN           = 'ORIGIN'; { Field origin }
  szMD_SEMANTICS     = 'MD_SEMANTICS'; { Master detail semantic properties }
  szSERVERCALC       = 'SERVER_CALC'; { A server side calculated field }
  szBDEDOMCL         = 'BDEDOMAIN_CL'; { Client side field constraints }
  szBDERECCL         = 'BDERECORD_CL'; { Client side record constraints }
  szBDEDEFCL         = 'BDEDEFAULT_CL'; { Client side default values }
  szDISABLE_INSERTS  = 'DISABLE_INSERTS'; { Disable inserting records }
  szDISABLE_DELETES  = 'DISABLE_DELETES'; { Disable deleting records }
  szDISABLE_EDITS    = 'DISABLE_EDITS'; { Disable editing records }
  szNO_RESET_CALL    = 'NO_RESET_CALL'; { Specifies not to call reset when the client closes the data }
  szMINVALUE         = 'MINVALUE'; { Minimum value for the field }
  szMAXVALUE         = 'MAXVALUE'; { Maximum value for the field }

  szstMEMO           = 'Text';
  szstBINARY         = 'Binary';
  szstFMTMEMO        = 'Formatted';
  szstOLEOBJ         = 'Ole';
  szstGRAPHIC        = 'Graphics';
  szstDBSOLEOBJ      = 'dBASEOle';
  szstTYPEDBINARY    = 'TypedBinary';
  szstMONEY          = 'Money';
  szstAUTOINC        = 'Autoinc';
  szstADTNESTEDTABLE = 'ADTNestedTable';
  szstFIXEDCHAR      = 'FixedChar';
  szstREFNESTEDTABLE = 'Reference';
  szstGUID           = 'Guid';
  szstACCOLEOBJ      = 'AccessOle';
  szstHMEMO          = 'HMemo';
  szstHBINARY        = 'HBinary';

  fldstReference     = 70;

  dsfldUNKNOWN       = 0;           { Unknown }
  dsfldINT           = 1;           { signed integer }
  dsfldUINT          = 2;           { Unsigned integer }
  dsfldBOOL          = 3;           { Boolean }
  dsfldFLOATIEEE     = 4;           { IEEE float }
  dsfldBCD           = 5;           { BCD }
  dsfldDATE          = 6;           { Date     (32 bit) }
  dsfldTIME          = 7;           { Time     (32 bit) }
  dsfldTIMESTAMP     = 8;           { Time-stamp  (64 bit) }
  dsfldZSTRING       = 9;           { Multi-byte string }
  dsfldUNICODE       = 10;          { unicode string }
  dsfldBYTES         = 11;          { bytes }
  dsfldADT           = 12;          { ADT (Abstract Data Type) }
  dsfldARRAY         = 13;          { Array type (not attribute) }
  dsfldEMBEDDEDTBL   = 14;          { Embedded (nested table type) }
  dsfldREF           = 15;          { Reference }

  dsSizeBitsLen      = 16;          { no. bits indicating fld size }
  dsSizeBitsMask     = $0000FFFF;   { mask to retrieve fld size }
  dsTypeBitsMask     = $003F0000;   { mask to retrieve Type info }
  dsVaryingFldType   = $00400000;   { Varying attribute type. }
  dsArrayFldType     = $00800000;   { Array attribute type. }

  dsPseudoFldType    = $01000000;   {Composite. Bits 1..15 gives number of elements }
  dsCompArrayFldType = $02000000;   { Compressed array }
  dsEmbeddedFldType  = $04000000;   { Embedded table }
  dsIncInDelta       = $80000000;   { For optional parameters only:include parameter in delta }

  dskeyCASEINSENSITIVE  = $4000;
  dskeyDESCENDING       = $8000;

  dsDELAYEDBIT       = $80000000;   { Length/number is not present }

  PACKETVERSION_1     = 1;
  PACKETVERSION_2     = 2;

  dsCASCADEDELETES   = 1;
  dsCASCADEUPDATES   = 2;

{ Field Types (Logical) - Originally from BDE.PAS }

  fldUNKNOWN         = 0;
  fldZSTRING         = 1;               { Null terminated string }
  fldDATE            = 2;               { Date     (32 bit) }
  fldBLOB            = 3;               { Blob }
  fldBOOL            = 4;               { Boolean  (16 bit) }
  fldINT16           = 5;               { 16 bit signed number }
  fldINT32           = 6;               { 32 bit signed number }
  fldFLOAT           = 7;               { 64 bit floating point }
  fldBCD             = 8;               { BCD }
  fldBYTES           = 9;               { Fixed number of bytes }
  fldTIME            = 10;              { Time        (32 bit) }
  fldTIMESTAMP       = 11;              { Time-stamp  (64 bit) }
  fldUINT16          = 12;              { Unsigned 16 bit integer }
  fldUINT32          = 13;              { Unsigned 32 bit integer }
  fldFLOATIEEE       = 14;              { 80-bit IEEE float }
  fldVARBYTES        = 15;              { Length prefixed var bytes }
  fldLOCKINFO        = 16;              { Look for LOCKINFO typedef }
  fldCURSOR          = 17;              { For Oracle Cursor type }
  fldINT64           = 18;              { 64 bit signed number }
  fldUINT64          = 19;              { Unsigned 64 bit integer }
  fldADT             = 20;              { Abstract datatype (structure) }
  fldARRAY           = 21;              { Array field type }
  fldREF             = 22;              { Reference to ADT }
  fldTABLE           = 23;              { Nested table (reference) }

  MAXLOGFLDTYPES     = 24;              { Number of logical fieldtypes }

{ Additional (non-BDE fieldtypes }
  fldUNICODE          = $1007;          { Unicode }

{ Sub Types (Logical) }

{ fldFLOAT subtype }

  fldstMONEY         = 21;              { Money }

{ fldBLOB subtypes }

  fldstMEMO          = 22;              { Text Memo }
  fldstBINARY        = 23;              { Binary data }
  fldstFMTMEMO       = 24;              { Formatted Text }
  fldstOLEOBJ        = 25;              { OLE object (Paradox) }
  fldstGRAPHIC       = 26;              { Graphics object }
  fldstDBSOLEOBJ     = 27;              { dBASE OLE object }
  fldstTYPEDBINARY   = 28;              { Typed Binary data }
  fldstACCOLEOBJ     = 30;              { Access OLE object }
  fldstHMEMO         = 33;              { CLOB }
  fldstHBINARY       = 34;              { BLOB }
  fldstBFILE         = 36;              { BFILE }

{ fldZSTRING subtype }

  fldstPASSWORD      = 1;               { Password }
  fldstFIXED         = 31;              { CHAR type }
  fldstUNICODE       = 32;              { Unicode }
  fldstGUID          = 38;              { GUID }

{ fldINT32 subtype }

  fldstAUTOINC       = 29;

const
  FieldTypeMap: TFieldMap = (
    fldUNKNOWN, fldZSTRING, fldINT16, fldINT32, fldUINT16, fldBOOL,
    fldFLOAT, fldFLOAT, fldBCD, fldDATE, fldTIME, fldTIMESTAMP, fldBYTES,
    fldVARBYTES, fldINT32, fldBLOB, fldBLOB, fldBLOB, fldBLOB, fldBLOB,
    fldBLOB, fldBLOB, fldCURSOR, fldZSTRING, fldZSTRING, fldINT64, fldADT,
    fldArray, fldREF, fldTABLE, fldBLOB, fldBLOB, fldUNKNOWN, fldUNKNOWN,
    fldUNKNOWN, fldZSTRING);

  FldSubTypeMap: array[TFieldType] of Word = (
    0, 0, 0, 0, 0, 0, 0, fldstMONEY, 0, 0, 0, 0, 0, 0, fldstAUTOINC,
    fldstBINARY, fldstMEMO, fldstGRAPHIC, fldstFMTMEMO, fldstOLEOBJ,
    fldstDBSOLEOBJ, fldstTYPEDBINARY, 0, fldstFIXED, fldstUNICODE,
    0, 0, 0, 0, 0, fldstHBINARY, fldstHMEMO, 0, 0, 0, fldstGUID);

  DataTypeMap: array[0..MAXLOGFLDTYPES - 1] of TFieldType = (
    ftUnknown, ftString, ftDate, ftBlob, ftBoolean, ftSmallint,
    ftInteger, ftFloat, ftBCD, ftBytes, ftTime, ftDateTime,
    ftWord, ftInteger, ftUnknown, ftVarBytes, ftUnknown, ftUnknown,
    ftLargeInt, ftLargeInt, ftADT, ftArray, ftReference, ftDataSet);

  BlobTypeMap: array[fldstMEMO..fldstBFILE] of TFieldType = (
    ftMemo, ftBlob, ftFmtMemo, ftParadoxOle, ftGraphic, ftDBaseOle,
    ftTypedBinary, ftBlob, ftBlob, ftBlob, ftBlob, ftOraClob,
    ftOraBlob, ftBlob, ftBlob);

{ Error Codes }

const

  DBERR_NONE                   = 0;
  DBERR_BOF                    = $2201;
  DBERR_EOF                    = $2202;
  DBERR_NOSUCHINDEX            = $270D;

  ERRCAT_ALC  = $40;
  ERRBASE_ALC = $4000;

  ERRCODE_DELTAISEMPTY       = 1;   { Delta is empty }
  ERRCODE_NOTHINGTOUNDO      = 2;   { Nothing to undo }
  ERRCODE_NOMETADATA         = 3;   { Datapacket contains no meta data }
  ERRCODE_CANNOTAPPEND       = 4;   { Trying to append data to a non-partial }
  ERRCODE_DATAPACKETMISMATCH = 5;   { Mismatch in datapacket }
  ERRCODE_ABORTED            = 6;   { Operation was aborted }
  ERRCODE_CANCELLED          = 7;   { Operation was cancelled }
  ERRCODE_NEWERVERSIONREQ    = 8;   { Newer version required }
  ERRCODE_BLOBNOTFETCHED     = 9;   { Blob has not been fetched }
  ERRCODE_DETAILSNOTFETCHED  = 10;  { Details has not been fetched }
  ERRCODE_NOMASTERRECORD     = 11;  { no corresponding master record found }
  ERRCODE_LINKFIELDSNOTUNIQUE= 12;  { Linkfields must be unique }
  ERRCODE_FLYAWAY_WRONGORDER = 13;  { Special case: wrong order of updates for fly-away }
  ERRCODE_NOCASCADEDUPDATES  = 14;  { Cascaded updates is not enabled }

  DBERR_DELTAISEMPTY        = ERRBASE_ALC + ERRCODE_DELTAISEMPTY;
  DBERR_NOTHINGTOUNDO       = ERRBASE_ALC + ERRCODE_NOTHINGTOUNDO;
  DBERR_NOMETADATA          = ERRBASE_ALC + ERRCODE_NOMETADATA;
  DBERR_CANNOTAPPEND        = ERRBASE_ALC + ERRCODE_CANNOTAPPEND;
  DBERR_DATAPACKETMISMATCH  = ERRBASE_ALC + ERRCODE_DATAPACKETMISMATCH;
  DBERR_ABORTED             = ERRBASE_ALC + ERRCODE_ABORTED;
  DBERR_CANCELLED           = ERRBASE_ALC + ERRCODE_CANCELLED;
  DBERR_NEWERVERSIONREQ     = ERRBASE_ALC + ERRCODE_NEWERVERSIONREQ;
  DBERR_BLOBNOTFETCHED      = ERRBASE_ALC + ERRCODE_BLOBNOTFETCHED;
  DBERR_DETAILSNOTFETCHED   = ERRBASE_ALC + ERRCODE_DETAILSNOTFETCHED;
  DBERR_NOMASTERRECORD      = ERRBASE_ALC + ERRCODE_NOMASTERRECORD;
  DBERR_LINKFIELDSNOTUNIQUE = ERRBASE_ALC + ERRCODE_LINKFIELDSNOTUNIQUE;
  DBERR_FLYAWAY_WRONGORDER  = ERRBASE_ALC + ERRCODE_FLYAWAY_WRONGORDER;
  DBERR_NOCASCADEDUPDATES   = ERRBASE_ALC + ERRCODE_NOCASCADEDUPDATES;

{ IDSBase }

type

  IDSBase = interface(IUnknown)
    ['{9E8D2FA2-591C-11D0-BF52-0020AF32BD64}']

    function Create(                { Create empty dataset }
        iFields  : DWord;           { Number of fields }
        pFldDes  : pDSFLDDesc;      { Array of field descriptors }
        pszName  : PChar            { Name (optional) }
    ): DBResult; stdcall;

    function AddField(              { Add a field to the dataset }
        pFldDes  : pDSFLDDesc       { Field descriptor }
    ): DBResult; stdcall;

    function AppendData(            { Appends data packet to dataset. }
        Packet   : PSafeArray;      { Data packet }
        bEof     : Bool             { If True, this is last packet }
    ): DBResult; stdcall;

    function GetOptParameter(       { Returns optional parameter (unknown to dataset) }
        iNo      : DWord;           { Number 1..iOptAttr }
        iFldNo   : DWord;           { 0 if not field attribute }
    var ppName   : Pointer;         { returns ptr to name }
    var piType   : DWord;           { returns type }
    var piLen    : DWord;           { returns length }
    var ppValue  : Pointer          { returns ptr to value }
    ): DBResult; stdcall;

    function AddOptParameter(       { Adds optional parameter to dataset }
        iFldNo   : DWord;           { 0 if not field attribute }
        pszAttr  : PChar;           { ptr to name }
        iType    : DWord;           { type }
        iLen     : DWord;           { length }
        pValue   : Pointer          { ptr to value }
    ): DBResult; stdcall;

    function GetProps(              { Get dataset properties }
    var Prop : DSProps
    ): DBResult; stdcall;

    function GetFieldDescs(         { Get field descriptors }
        Fields  : pDSFLDDesc        { Array of fields descriptors (output) }
    ): DBResult; stdcall;

    function GetIndexDescs(         { Get index descriptors }
        p1: PDSIDXDesc              { Array of index descriptors (output) }
    ): DBResult; stdcall;

    function GetDelta(              { Extract delta from dataset }
    out DsDelta: IDSBase            { Delta in a dataset }
    ): DBResult; stdcall;

    function StreamDS(              { Create data packet from the dataset }
    out Packet  : PSafeArray        { Return data packet }
    ): DBResult; stdcall;

    function AcceptChanges: DBResult; stdcall; { Accept all current changes }

    function PutBlank(              { Put blank value }
        pRecBuf      : Pointer;     { RecBuf OR }
        iRecNo       : DWord;       { iRecNo }
        iFldNo       : DWord;
        iBlankValue  : DWord
    ): DBResult; stdcall;

    function CreateIndex(           { Create, and add an index }
    const IdxDesc  : DSIDXDesc
    ): DBResult; stdcall;

    function RemoveIndex(           { Remove index of given name }
        pszName  : PChar
    ): DBResult; stdcall;

    function GetErrorString(        { Retrieve error string }
        iErrCode  : DBResult;
        pString   : PChar
    ): DBResult; stdcall;

    function FldCmp(                { Compare field values returns 0 if equal }
        iFldType  : DWord;          { Fieldtype }
        pFld1     : Pointer;        { NULL if blank }
        pFld2     : Pointer;        { NULL if blank }
        iUnits1   : DWord;
        iUnits2   : DWord
    ): Integer; stdcall;

    function GetProp(               { Get property }
        eProp       : DSProp;
        piPropValue : Pointer
    ): DBResult; stdcall;

    function SetProp(               { Set property }
        eProp      : DSProp;
        iPropValue : DWord
    ): DBResult; stdcall;

    function SetFieldCalculation(   { Register fieldcalculation on this field }
        iClientData  : DWord;       { Client data }
        pfCalc       : pfDSCalcField { Callback function, NULL to remove }
    ): DBResult; stdcall;

    function Reconcile(             { Reconcile update errors }
        DeltaPacket   : PSafeArray; { Delta data packet }
        ErrorPacket   : PSafeArray; { NULL if all changes accepted }
        iClientData   : DWord;
        pfReconcile   : pfDSReconcile { Callback-fn (called for each error) }
    ): DBResult; stdcall;

    { Place Holders for aggregate functions that were moved into DSCursor }
    function Reserved1(Input: Pointer): DBResult; stdcall;
    function Reserved2(Input: Pointer): DBResult; stdcall;
    function Reserved3(Input: Pointer): DBResult; stdcall;

    function Refresh(               { Refresh dataset }
        NewPacket    : PSafeArray;  { New updated packet }
        iClientData  : DWord;       { Client data }
        pfReconcile  : pfDSReconcile { Callback for resolving conflicts }
    ): DBResult; stdcall;

    function Reset: DBResult; stdcall; { Remove all data from dataset }

    function RollBack(              { Rollback changes to this savepoint }
        iSavePoint  : SAVEPOINT
    ): DBResult; stdcall;

    function GetEmbeddedDS(
        iFieldID  : DWord;          { FieldID of embedded table (0 : get the first one) }
    out DsDet     : IDSBase         { Returns the ds of the embedded table }
    ): DBResult; stdcall;

    function MakeEmbedded(
        DsDet             : IDSBase;  { Embed this dataset }
        iFieldsLink       : DWord;
        piFieldsM         : PDWord;   { Fields in Master }
        piFieldsD         : PDWord;   { Fields in Detail }
        pMasterFieldName  : PChar;    { Name of new link field in master, NULL if using default name }
        pDetailFieldName  : PChar     { Name of new link field in detail, NULL if using defaultname }
    ): DBResult; stdcall;

    function RefreshRecords(            { Refresh specific records }
        NewDataPacket   : PSafeArray;   { Datapacket containing refreshed records }
        iRecNo          : DWord;        { Refresh this specific record (0 if more than one.Unique key req.) }
        iClientData     : DWord;
        pfReconcile     : pfDSReconcile { (NULL) Callback for resolving conflicts }
    ): DBResult; stdcall;

    function ReleaseBlobs(          { Release all uncommitted blobs }
        iBlobId  : DWord            { 0: all uncommitted blobs, otherwise : specific blob }
    ): DBResult; stdcall;

    function Clone(                 { Clones the structure of the dsbase, including details if any }
         iPType : DWord;            { 0:normal-ds, 1:delta-ds, 2:error-ds }
         bRecurse : Bool;           { TRUE:create complete tree-structure }
         bCloneOptParams: Bool;     { TRUE:clone all optional parameters (normal only) }
         var DataSet: IDSBase       { Returned dsbase }
    ): DBResult; stdcall;

    function Reconcile_MD(
        pDsRec          : IDSBase;           { Ds for info }
        pDeltaPacket    : PSafeArray;        { Delta pickle }
        pErrorPacket    : PSafeArray;        { NULL if all changes accepted }
        iClientData     : DWord;
        pfReconcile_MD  : pfDSReconcile_MD   { Callback-fn (called for each error) }
    ): DBResult; stdcall;

   function DropOptParameter(
           iFldNo: DWord;    { 0 if not field attribute }
           pName: PChar      { Name of attribute to delete }
        ): DBResult; stdcall;
  end;

{ IDSCursor }

  IDSCursor = interface(IUnknown)
    ['{9E8D2FA4-591C-11D0-BF52-0020AF32BD64}']

    function InitCursor(            { Associate Cursor with a DataSet }
       DataSet: IDSBase
    ): DBResult; stdcall;

    function CloneCursor(           { Clone cursor from cursor }
       Cursor: IDSCursor
    ): DBResult; stdcall;

    function GetCursorProps(        { Get cursor properties }
    var p1: DSProps
    ): DBResult; stdcall;

    function GetIndexDescs(         { Get index descriptors }
        bCurrentOnly  : Bool;       { Only return 'current' indexdesc, otherwise all }
    var IdxDesc       : DSIDXDesc
    ): DBResult; stdcall;

    function GetFieldDescs(         { Get field descriptors }
        p1  : pDSFLDDesc
    ): DBResult; stdcall;

    function GetCurrentRecord(      { Return record at current cursorposition }
        pRecBuf  : Pointer
    ): DBResult; stdcall;

    function GetRecordBlock(        { Return block of records }
        piRecs   : PDWord;
        pRecBuf  : Pointer
    ): DBResult; stdcall;

    function GetCurrentBookMark(    { Get bookmark for current position }
        pBookMark  : Pointer
    ): DBResult; stdcall;

    function GetSequenceNumber(     { Get Sequence number of current position }
    var iSeq  : DWord
    ): DBResult; stdcall;

    function GetRecordAttribute(    { Get record attribute of current position }
    var Attr  : DSAttr
    ): DBResult; stdcall;

    function GetRecordCount(        { Number of records in active view }
    var iRecs  : Integer
    ): DBResult; stdcall;

    function MoveToBOF: DBResult; stdcall; { Set to beginning of table (BOF) }

    function MoveToEOF: DBResult; stdcall; { Set to end of table (EOF) }

    function MoveRelative(i: Integer): DBResult; stdcall;

    function MoveToSeqNo(i: DWord): DBResult; stdcall;

    function MoveToBookMark(        { Goto bookmark }
      pBookMark: Pointer
    ): DBResult; stdcall;

    function MoveToKey(             { Goto key }
        SearchCond  : DBSearchCond;
        iFields     : DWord;
        iPartLen    : DWord;
        pRecBuf     : Pointer
    ): DBResult; stdcall;


    function CompareBookMarks(      { Compare two bookmark (positions) -1, 0, 1 }
        pBookMark1  : Pointer;
        pBookMark2  : Pointer;
    var iCmp        : Integer
    ): DBResult; stdcall;

    function ExtractKey(            { Extract key from record }
        pRecBuf  : Pointer;
        pKeyBuf  : Pointer
    ): DBResult; stdcall;

    function GetRecordForKey(       { Return (first) record with given key }
        iFields   : DWord;
        iPartLen  : DWord;
        pKey      : Pointer;
        pRecBuf   : Pointer
    ): DBResult; stdcall;

    function GetField(              { Extract field value from record buffer }
        pRecBuf   : Pointer;
        iFieldNo  : DWord;
        pFldBuf   : Pointer;
    var bBlank    : Bool            { Returns TRUE/FALSE if blank }
    ): DBResult; stdcall;

    function PutField(              { Put field value into record buffer }
        pRecBuf   : Pointer;
        iFieldNo  : DWord;
        pFldBuf   : Pointer         { If NULL, adds a blank value }
    ): DBResult; stdcall;

    { Blob functions }

    function GetBlobLen(            { Return length of blob }
        pRecBuf   : Pointer;
        iFieldNo  : DWord;
    var iLength   : DWord
    ): DBResult; stdcall;

    function GetBlob(               { Return blob }
        pRecBuf   : Pointer;
        iFieldNo  : DWord;
        iOffSet   : DWord;          { Starting position }
        pBuf      : Pointer;
    var iLength   : DWord          { No of bytes to be read/ returns number read }
    ): DBResult; stdcall;

    function PutBlob(               { Write blob data }
        pRecBuf   : Pointer;
        iFieldNo  : DWord;
        iOffSet   : DWord;          { Starting position }
        pBuf      : Pointer;
        iLength   : DWord
    ): DBResult; stdcall;

    function InitRecord(            { Initialize record buffer (for insertion) }
        pRecBuf  : Pointer
    ): DBResult; stdcall;

    function DeleteRecord: DBResult; stdcall; { Delete current record }

    function ModifyRecord(          { Modify current record }
        pRecBuf  : Pointer
    ): DBResult; stdcall;

    function InsertRecord(          { Insert new record }
        pRecBuf  : Pointer
    ): DBResult; stdcall;

    function UndoLastChange(        { Undo last update }
        bFollowChange  : Bool
    ): DBResult; stdcall;

    function AddFilter(             { Add a canexpr-filter to this cursor }
        pcanExpr  : Pointer;        { Can expr }
        iLen      : DWord;          { Length of canexpr }
    var hFilter   : hDSFilter
    ): DBResult; stdcall;

    function DropFilter(            { Drop a filter }
       hFilter  : hDSFilter
    ): DBResult; stdcall;

    function SetRange(              { Set a range on a cursor }
        iFields    : DWord;
        pKey1      : Pointer;
        bKey1Incl  : Bool;
        pKey2      : Pointer;
        bKey2Incl  : Bool
    ): DBResult; stdcall;

    function DropRange: DBResult; stdcall; { Remove current range }

    function SortOnFields(          { Sort on fields }
        iFields    : DWord;
        piFields   : PDWord;        { NULL -> all fields }
        pDescending: PBool;         { NULL -> all ascending }
        pCaseInsensitive: PBool     { NULL -> all case-sensitive }
    ): DBResult; stdcall;

    function UseIndexOrder(         { Switch to index order }
        pszName  : PChar
    ): DBResult; stdcall;

    function SetNotifyCallBack(     { Called when posting changes to dataset }
        iClientData  : DWord;
        pfCallBack   : pfCHANGECallBack   { Call back fn being registered }
    ): DBResult; stdcall;

    function AddFilterCallBack(     { Add a canexpr-filter to this cursor }
        iClientData  : DWord;     { Client supplied data }
        pfFilter     : pfDSFilter;  { ptr to filter function }
    var hFilter      : hDSFilter
    ): DBResult; stdcall;

    function VerifyField(           { Verify if field value is valid }
        iFieldNo  : DWord;
        pFldBuf   : Pointer
    ): DBResult; stdcall;

    function GetProp(               { Get property }
        eProp        : CURProp;
        piPropValue  : Pointer
    ): DBResult; stdcall;

    function RevertRecord: DBResult; stdcall; { Restore current record }

    function LocateWithFilter(
        pCanExpr  : Pointer;        { NULL -> use previous }
        iLen      : DWord           { Length of canexpr }
    ): DBResult; stdcall;

    function AddAggregate(
        iFlds     : DWord;          { Defines grouping  (0 if global) }
        iCanLen   : DWord;          { Length of canexpr (0 if grouping only) }
        pCanExpr  : Pointer;        { Canexpression for aggregate }
    var hAgg      : hDSAggregate    { returns aggregate handle }
    ): DBResult; stdcall;

    function DropAggregate(
        hAgg  : hDSAggregate
    ): DBResult; stdcall;

    function GetAggregateValue(
        hAgg     : hDSAggregate;
        pValue   : Pointer;
    var bBlank   : Bool
    ): DBResult; stdcall;

    function GetAggregateDesc(
        hAgg   : hDSAggregate;
    var Desc   : DSFLDDesc
    ): DBResult; stdcall;

    function MoveToNextSubGroup(
        iFields  : DWord
    ): DBResult; stdcall;

    function GetSubGroupState(
        iFields        : DWord;
    var iSubGroupState : GROUPSTATE
    ): DBResult; stdcall;

    function LinkCursors(
        iFieldsM   : DWord;
        piFieldsM  : PDWord;         { Fields in Master }
        piFieldsD  : PDWord;         { Fields in Detail }
        hCurDet    : IDSCursor       { Detail cursor to link }
    ): DBResult; stdcall;

    function ResyncWithMaster: DBResult; stdcall; { If this is a detail, reset range }

    function SetProp(               { Set property }
        eProp       : CURProp;      { Property to set }
        iPropValue  : DWord         { Property value (or pointer to value) }
    ): DBResult; stdcall;

   function GetRecordNumber(  { Return record number of current record, if any }
        var iRecNo: DWord
    ): DBResult; stdcall;


    function GetRowRequestPacket(   { Get packet describing the curent 'path',
                                      for delayed fetching/refreshing }
        bKeysOnly       : Bool;     { Only include unique keys in packet }
        bFetchAllBlobs  : Bool;     { fetch all blobs for 'current'record }
        bFetchAllDetails: Bool;     { fetch all details for 'current' record }
        bInclMetaData   : Bool;     { Include metadata in packet }
        out Packet      : PSafeArray{ returns datapacket with row description }
    ): DBResult; stdcall;

   function RefreshRecord( { Refresh details/blobs for this record, and all
                             'current' records above, if any }
        Packet  : PSafeArray        { New updated pickle }
    ): DBResult; stdcall;

  end;

{ IDSWriter }

  IDSWriter = interface(IUnknown)
    ['{9E8D2FA6-591C-11D0-BF52-0020AF32BD64}']

    function Init_Sequential(   { Initialze by sequentially adding columns }
        Version: DWord;
        Columns: Word
    ): DBResult; stdcall;

    function Init(
        Version: DWord;
        Columns: Word;
        FieldDesc: PDSDataPacketFldDesc
    ): DBResult; stdcall;

    function AddAttribute(      { Add an optional parameter }
        AttrArea: TPcktAttrArea;
        Attr: PChar;
        AttrType: DWord;
        Len: DWord;
        Value: Pointer
    ): DBResult; stdcall;

    function GetDataPacket(     { Return pointer to the finished 'safearray' }
    var SA: PSafeArray
    ): DBResult; stdcall;


    function GetSize(           { Get the size of the safearray. }
    var DataPacketSize: DWord
    ): DBResult; stdcall;


    function PutField(          { Add this field to the data stream. }
        FldStatus: TPcktFldStatus;
        Len: DWord;
        Src: Pointer
    ): DBResult; stdcall;

    function AddColumnDesc(     { Add a column descriptor. }
      const FldDes: TDSDataPacketFldDesc
    ): DBResult; stdcall;

    { Reset all data (in order to create partial data).  Datapackets will not
      contain meta-info. Last created datapacket must be released by caller. }
    function Reset: DBResult; stdcall;

    { Return number of fielddescriptors, including embedded tables etc. }

    function GetColumnCount(var Count: DWord): DBResult; stdcall;


    function GetColumnDescs(    { Return all fielddescriptors }
        FieldDes: PDSDataPacketFldDesc
    ): DBResult; stdcall;

    function GetErrorString(        { Retrieve error string }
        iErrCode  : DBResult;
        pString   : PChar
    ): DBResult; stdcall;

   { Signals last row for a nested table, in case rowcount was not known
     in advance }
   function EndOfNestedRows: DBResult; stdcall;

   function SetXMLMode(iMode: Integer): DBResult; stdcall;

   function GetXMLMode: DWord; stdcall;

  end;

const
  CLSID_DSBase: TGUID   = '{9E8D2FA1-591C-11D0-BF52-0020AF32BD64}';
  CLSID_DSCursor: TGUID = '{9E8D2FA3-591C-11D0-BF52-0020AF32BD64}';
  CLSID_DSWriter: TGUID = '{9E8D2FA5-591C-11D0-BF52-0020AF32BD64}';

{ Utility Routines }

procedure FreeDataPacket(var DataPacket: TDataPacket);
function VarToDataPacket(const V: OleVariant): TDataPacket;
function DataPacketSize(const DataPacket: TDataPacket): Integer;
procedure DataPacketToVariant(const DataPacket: TDataPacket; var V: OleVariant);
procedure CreateDbClientObject(const CLSID, IID: TGUID; out Obj);
function VariantArrayToString(const V: OleVariant): string;
function StringToVariantArray(const S: string): OleVariant;

implementation

uses ComObj, MidConst, SysUtils;

{ Utility Routines }

var
  DbClientHandle: THandle = 0;
  DllGetClassObject: function(const CLSID, IID: TGUID; var Obj): HResult; stdcall;
  Loading: TRTLCriticalSection;

procedure CheckDbClient(const CLSID: TGUID);
var
  Size: Integer;
  FileName: string;
begin
  if DbClientHandle = 0 then
  begin
    EnterCriticalSection(Loading);
    try
      if DbClientHandle = 0 then
      begin
        Size := 256;
        SetLength(FileName, Size);
        if RegQueryValue(HKEY_CLASSES_ROOT, PChar(Format('CLSID\%s\InProcServer32',
          [GUIDToString(CLSID)])), PChar(FileName), Size) = ERROR_SUCCESS then
          SetLength(FileName, Size) else
        begin
          FileName := MIDAS_DLL;
          try
            RegisterComServer(FileName);
          except
          end;
        end;
        DbClientHandle := LoadLibrary(PChar(FileName));
        if DbClientHandle = 0 then
          raise Exception.CreateRes(@SErrorLoadingMidas);
        DllGetClassObject := GetProcAddress(DbClientHandle, 'DllGetClassObject');
      end;
    finally
      LeaveCriticalSection(Loading);
    end;
  end;
end;

procedure CreateDbClientObject(const CLSID, IID: TGUID; out Obj);
var
  Factory: IClassFactory;
begin
  CheckDbClient(CLSID);
  OleCheck(DllGetClassObject(CLSID, IClassFactory, Factory));
  OleCheck(Factory.CreateInstance(nil, IID, Obj));
end;

procedure FreeDataPacket(var DataPacket: TDataPacket);
begin
  if Assigned(DataPacket) then
  begin
    SafeArrayDestroy(DataPacket);
    DataPacket := nil;
  end;
end;

function VarToDataPacket(const V: OleVariant): TDataPacket;
begin
  if VarIsNull(V) then Result := nil else
  begin
    if not (VarIsArray(V) and (VarArrayHighBound(V, 1) > 20)) then
      DatabaseError(SInvalidDataPacket);
    Result := tagVARIANT(V).PArray;
  end;
end;

function DataPacketSize(const DataPacket: TDataPacket): Integer;
begin
  OleCheck(SafeArrayGetUBound(DataPacket, 1, Result));
  Inc(Result);
end;

procedure DataPacketToVariant(const DataPacket: TDataPacket; var V: OleVariant);
begin
  if Assigned(DataPacket) then
  begin
    VarClear(V);
    tagVariant(V).vt := varByte or varArray;
    tagVariant(V).PArray := DataPacket;
  end else
    V := NULL;
end;

function VariantArrayToString(const V: OleVariant): string;
var
  P: Pointer;
  Size: Integer;
begin
  Result := '';
  if VarIsArray(V) and (VarType(V) and varTypeMask = varByte) then
  begin
    Size := VarArrayHighBound(V, 1) - VarArrayLowBound(V, 1) + 1;
    if Size > 0 then
    begin
      SetLength(Result, Size);
      P := VarArrayLock(V);
      try
        Move(P^, Result[1], Size);
      finally
        VarArrayUnlock(V);
      end;
    end;
  end;
end;

function StringToVariantArray(const S: string): OleVariant;
var
  P: Pointer;
begin
  Result := NULL;
  if Length(S) > 0 then
  begin
    Result := VarArrayCreate([0, Length(S) - 1], varByte);
    P := VarArrayLock(Result);
    try
      Move(S[1], P^, Length(S));
    finally
      VarArrayUnlock(Result);
    end;
  end;
end;

initialization
  InitializeCriticalSection(Loading);
finalization
  if DbClientHandle > 32 then FreeLibrary(DbClientHandle);
  DeleteCriticalSection(Loading);
end.
