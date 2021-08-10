unit WebLib;

// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// PASTLWTR : $Revision:   1.9  $
// File generated on 5/16/2001 11:32:09 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: C:\tp\internet\WebLib.tlb (1)
// LIBID: {E72A0841-8C34-11D3-AAF7-A0AC2E78CD57}
// LCID: 0
// Helpfile: 
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINNT\System32\stdole2.tlb)
//   (2) v4.0 StdVCL, (C:\WINNT\System32\STDVCL40.DLL)
// ************************************************************************ //
{$TYPEDADDRESS OFF} // Unit must be compiled without type-checked pointers. 
{$WARN SYMBOL_PLATFORM OFF}
{$WRITEABLECONST ON}

interface

uses ActiveX, Classes, StdVCL, Variants, Windows;
  

// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:        
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLASS_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
const
  // TypeLibrary Major and minor versions
  WebLibMajorVersion = 1;
  WebLibMinorVersion = 0;

  LIBID_WebLib: TGUID = '{E72A0841-8C34-11D3-AAF7-A0AC2E78CD57}';

  IID_IWebBroker: TGUID = '{B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}';
  IID_IWebRequest: TGUID = '{E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}';
type

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                    
// *********************************************************************//
  IWebBroker = interface;
  IWebBrokerDisp = dispinterface;
  IWebRequest = interface;
  IWebRequestDisp = dispinterface;

// *********************************************************************//
// Interface: IWebBroker
// Flags:     (320) Dual OleAutomation
// GUID:      {B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}
// *********************************************************************//
  IWebBroker = interface(IUnknown)
    ['{B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}']
    procedure HandleRequest {Flags(1), (1/1) CC:0, INV:1, DBG:6}({VT_29:1}const Request: IWebRequest); safecall;
  end;

// *********************************************************************//
// DispIntf:  IWebBrokerDisp
// Flags:     (320) Dual OleAutomation
// GUID:      {B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}
// *********************************************************************//
  IWebBrokerDisp = dispinterface
    ['{B0A08BEE-8E23-11D3-B08A-00C04FB16EC3}']
    procedure HandleRequest {Flags(2), (1/1) CC:0, INV:1, DBG:4}({VT_29:1}const Request: IWebRequest); dispid 1;
  end;

// *********************************************************************//
// Interface: IWebRequest
// Flags:     (320) Dual OleAutomation
// GUID:      {E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}
// *********************************************************************//
  IWebRequest = interface(IUnknown)
    ['{E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}']
    function  GetFieldByName {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_8:0}const Name: WideString): WideString; safecall;
    function  ReadClient {Flags(1), (3/2) CC:0, INV:1, DBG:6}({VT_12:1}var Buffer: OleVariant; 
                                                              {VT_3:0}Count: Integer): Integer; safecall;
    function  TranslateURI {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_8:0}const Value: WideString): WideString; safecall;
    function  WriteClient {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_12:0}Buffer: OleVariant): Integer; safecall;
    function  GetStringVariable {Flags(1), (2/1) CC:0, INV:1, DBG:6}({VT_3:0}Index: Integer): OleVariant; safecall;
    function  WriteHeaders {Flags(1), (4/3) CC:0, INV:1, DBG:6}({VT_3:0}StatusCode: Integer; 
                                                                {VT_12:0}StatusText: OleVariant; 
                                                                {VT_12:0}Headers: OleVariant): WordBool; safecall;
    function  UsingStub {Flags(1), (1/0) CC:0, INV:1, DBG:6}: WordBool; safecall;
    function  ReadString {Flags(1), (3/2) CC:0, INV:1, DBG:6}({VT_12:1}var Buffer: OleVariant; 
                                                              {VT_3:0}Count: Integer): Integer; safecall;
  end;

// *********************************************************************//
// DispIntf:  IWebRequestDisp
// Flags:     (320) Dual OleAutomation
// GUID:      {E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}
// *********************************************************************//
  IWebRequestDisp = dispinterface
    ['{E72A0846-8C34-11D3-AAF7-A0AC2E78CD57}']
    function  GetFieldByName {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_8:0}const Name: WideString): WideString; dispid 1;
    function  ReadClient {Flags(2), (3/2) CC:0, INV:1, DBG:4}({VT_12:1}var Buffer: OleVariant; 
                                                              {VT_3:0}Count: Integer): Integer; dispid 2;
    function  TranslateURI {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_8:0}const Value: WideString): WideString; dispid 3;
    function  WriteClient {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_12:0}Buffer: OleVariant): Integer; dispid 4;
    function  GetStringVariable {Flags(2), (2/1) CC:0, INV:1, DBG:4}({VT_3:0}Index: Integer): OleVariant; dispid 5;
    function  WriteHeaders {Flags(2), (4/3) CC:0, INV:1, DBG:4}({VT_3:0}StatusCode: Integer; 
                                                                {VT_12:0}StatusText: OleVariant; 
                                                                {VT_12:0}Headers: OleVariant): WordBool; dispid 6;
    function  UsingStub {Flags(2), (1/0) CC:0, INV:1, DBG:4}: WordBool; dispid 7;
    function  ReadString {Flags(2), (3/2) CC:0, INV:1, DBG:4}({VT_12:1}var Buffer: OleVariant; 
                                                              {VT_3:0}Count: Integer): Integer; dispid 8;
  end;

implementation

uses ComObj;

end.
