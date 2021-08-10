// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'xmlutil.pas' rev: 6.00

#ifndef xmlutilHPP
#define xmlutilHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <xmldom.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xmlutil
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS DomException;
class PASCALIMPLEMENTATION DomException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall DomException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall DomException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall DomException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall DomException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall DomException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall DomException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall DomException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall DomException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~DomException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SMissingSourceFile;
#define Xmlutil_SMissingSourceFile System::LoadResourceString(&Xmlutil::_SMissingSourceFile)
extern PACKAGE System::ResourceString _SMissingTransform;
#define Xmlutil_SMissingTransform System::LoadResourceString(&Xmlutil::_SMissingTransform)
extern PACKAGE System::ResourceString _SOldVersion;
#define Xmlutil_SOldVersion System::LoadResourceString(&Xmlutil::_SOldVersion)
extern PACKAGE System::ResourceString _sFileSaveError;
#define Xmlutil_sFileSaveError System::LoadResourceString(&Xmlutil::_sFileSaveError)
extern PACKAGE System::ResourceString _sFileOpenError;
#define Xmlutil_sFileOpenError System::LoadResourceString(&Xmlutil::_sFileOpenError)
extern PACKAGE System::ResourceString _sXMLFileOpenError;
#define Xmlutil_sXMLFileOpenError System::LoadResourceString(&Xmlutil::_sXMLFileOpenError)
extern PACKAGE System::ResourceString _sXMLLoadError;
#define Xmlutil_sXMLLoadError System::LoadResourceString(&Xmlutil::_sXMLLoadError)
extern PACKAGE System::ResourceString _sLinePosError;
#define Xmlutil_sLinePosError System::LoadResourceString(&Xmlutil::_sLinePosError)
extern PACKAGE System::ResourceString _sReason;
#define Xmlutil_sReason System::LoadResourceString(&Xmlutil::_sReason)
extern PACKAGE System::ResourceString _sParseError;
#define Xmlutil_sParseError System::LoadResourceString(&Xmlutil::_sParseError)
#define mx_Root "XmlTransformation"
#define mx_Transform "Transform"
#define mx_Skeleton "Skeleton"
#define mx_TranslateEach "SelectEach"
#define mx_Translate "Select"
#define mx_XmlSchema "XmlSchema"
#define mx_CdsSkeleton "CdsSkeleton"
#define mx_XmlSkeleton "XmlSkeleton"
#define mx_XSLTransform "XslTransform"
#define mx_Version "Version"
#define mx_CurrVersion "1.0"
#define mx_RootName "RootName"
#define mx_DataEncoding "DataEncoding"
#define mx_Direction "Direction"
#define mx_ToXml "ToXml"
#define mx_ToCds "ToCds"
#define mx_ID "id"
#define mx_DEFAULT "Default"
#define mx_VALUE "value"
#define mx_OPTIONS "Options"
#define mx_MAPVALUES "Map_Values"
#define mx_BOOLFORMAT "Format_Bool"
#define mx_OPTIONAL "Optional"
#define mx_DEST "dest"
#define mx_FROM "from"
#define mx_DATETIMEFORMAT "Format_DateTime"
#define mx_DATEFORMAT "Format_Date"
#define mx_TIMEFORMAT "Format_Time"
#define mx_Datapacket "DATAPACKET"
#define mx_ROWDATA "ROWDATA"
#define mx_ROW "ROW"
#define mx_RowState "RowState"
#define val_DateTimeDefault "Default Format"
extern PACKAGE Xmldom::_di_IDOMDocument __fastcall LoadDocFromFile(const AnsiString XMLFile);
extern PACKAGE Xmldom::_di_IDOMDocument __fastcall LoadDocFromString(const AnsiString XMLStr);
extern PACKAGE AnsiString __fastcall getIndex_Attrs(AnsiString tag, int &idx, AnsiString &Attrs);
extern PACKAGE Xmldom::_di_IDOMNode __fastcall FindNode(Xmldom::_di_IDOMNode CurrEl, int currtag, Classes::TStrings* tags);
extern PACKAGE Xmldom::_di_IDOMNode __fastcall NextCreateElement(Xmldom::_di_IDOMNode El, AnsiString tag, AnsiString &attr);
extern PACKAGE Xmldom::_di_IDOMNode __fastcall SelectCreateNode(Xmldom::_di_IDOMNode Node, AnsiString Path, AnsiString &attrs);
extern PACKAGE Xmldom::_di_IDOMNode __fastcall SelectNode(Xmldom::_di_IDOMNode Node, AnsiString Path);
extern PACKAGE Xmldom::_di_IDOMNode __fastcall SelectCreateSibling(Xmldom::_di_IDOMNode Node, Xmldom::_di_IDOMNode CloneNode);
extern PACKAGE void __fastcall PutValue(Xmldom::_di_IDOMNode Node, AnsiString Path, AnsiString value);
extern PACKAGE Xmldom::_di_IDOMDocument __fastcall CloneDoc(Xmldom::_di_IDOMDocument Doc);
extern PACKAGE Classes::TStringList* __fastcall Split0(AnsiString Str, const AnsiString substr);
extern PACKAGE AnsiString __fastcall Head(AnsiString s, const AnsiString subs, AnsiString &tail);
extern PACKAGE AnsiString __fastcall GetAttribute(Xmldom::_di_IDOMNode Node, const AnsiString name);
extern PACKAGE AnsiString __fastcall StrToXmlDate(const AnsiString DateStr, const AnsiString Format);
extern PACKAGE AnsiString __fastcall StrToXmlDateTime(const AnsiString DateStr, const AnsiString Format);
extern PACKAGE AnsiString __fastcall StrToXmlTime(const AnsiString TimeStr, const AnsiString Format);
extern PACKAGE AnsiString __fastcall XmlDateTimeToStr(const AnsiString XmlDateTime, const AnsiString Format);
extern PACKAGE AnsiString __fastcall XmlTimeToStr(const AnsiString XmlTime, const AnsiString Format);
extern PACKAGE AnsiString __fastcall MapDateTime(const AnsiString DateFormatType, AnsiString DateFormat, AnsiString Value, bool ToCds);
extern PACKAGE AnsiString __fastcall MakeValueMap(AnsiString Enumeration, bool ToCds);
extern PACKAGE AnsiString __fastcall MapValues(AnsiString Mapping, AnsiString Value);
extern PACKAGE AnsiString __fastcall GetEncoding(Xmldom::_di_IDOMDocument Doc);
extern PACKAGE void __fastcall SetEncoding(Xmldom::_di_IDOMDocument Doc, AnsiString Encoding, bool OverWrite);
extern PACKAGE void __fastcall SetStandalone(Xmldom::_di_IDOMDocument Doc, AnsiString value);
extern PACKAGE Xmldom::_di_IDOMNode __fastcall CloneNodeToDoc(const Xmldom::_di_IDOMNode SourceNode, const Xmldom::_di_IDOMDocument TargetDoc, bool Deep = true);

}	/* namespace Xmlutil */
using namespace Xmlutil;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// xmlutil
