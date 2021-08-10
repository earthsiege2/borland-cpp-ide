// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'xdom.pas' rev: 6.00

#ifndef xdomHPP
#define xdomHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <Math.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Xdom
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EDomException;
class PASCALIMPLEMENTATION EDomException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDomException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDomException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDomException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDomException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDomException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDomException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDomException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDomException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDomException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EIndex_Size_Err;
class PASCALIMPLEMENTATION EIndex_Size_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EIndex_Size_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EIndex_Size_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EIndex_Size_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EIndex_Size_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EIndex_Size_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EIndex_Size_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EIndex_Size_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EIndex_Size_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EIndex_Size_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EDomstring_Size_Err;
class PASCALIMPLEMENTATION EDomstring_Size_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EDomstring_Size_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EDomstring_Size_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EDomstring_Size_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EDomstring_Size_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EDomstring_Size_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EDomstring_Size_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EDomstring_Size_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EDomstring_Size_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EDomstring_Size_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EHierarchy_Request_Err;
class PASCALIMPLEMENTATION EHierarchy_Request_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EHierarchy_Request_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EHierarchy_Request_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EHierarchy_Request_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EHierarchy_Request_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EHierarchy_Request_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EHierarchy_Request_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EHierarchy_Request_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EHierarchy_Request_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EHierarchy_Request_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EWrong_Document_Err;
class PASCALIMPLEMENTATION EWrong_Document_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWrong_Document_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWrong_Document_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWrong_Document_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWrong_Document_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWrong_Document_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWrong_Document_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWrong_Document_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWrong_Document_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWrong_Document_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalid_Character_Err;
class PASCALIMPLEMENTATION EInvalid_Character_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalid_Character_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalid_Character_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalid_Character_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalid_Character_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalid_Character_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalid_Character_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalid_Character_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalid_Character_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalid_Character_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ENo_Data_Allowed_Err;
class PASCALIMPLEMENTATION ENo_Data_Allowed_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENo_Data_Allowed_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENo_Data_Allowed_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENo_Data_Allowed_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENo_Data_Allowed_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENo_Data_Allowed_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENo_Data_Allowed_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENo_Data_Allowed_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENo_Data_Allowed_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENo_Data_Allowed_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ENo_Modification_Allowed_Err;
class PASCALIMPLEMENTATION ENo_Modification_Allowed_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENo_Modification_Allowed_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENo_Modification_Allowed_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENo_Modification_Allowed_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENo_Modification_Allowed_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENo_Modification_Allowed_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENo_Modification_Allowed_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENo_Modification_Allowed_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENo_Modification_Allowed_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENo_Modification_Allowed_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ENot_Found_Err;
class PASCALIMPLEMENTATION ENot_Found_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENot_Found_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENot_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENot_Found_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENot_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENot_Found_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENot_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENot_Found_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENot_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENot_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ENot_Supported_Err;
class PASCALIMPLEMENTATION ENot_Supported_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENot_Supported_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENot_Supported_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENot_Supported_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENot_Supported_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENot_Supported_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENot_Supported_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENot_Supported_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENot_Supported_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENot_Supported_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInuse_Attribute_Err;
class PASCALIMPLEMENTATION EInuse_Attribute_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInuse_Attribute_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInuse_Attribute_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInuse_Attribute_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInuse_Attribute_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInuse_Attribute_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInuse_Attribute_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInuse_Attribute_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInuse_Attribute_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInuse_Attribute_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalid_State_Err;
class PASCALIMPLEMENTATION EInvalid_State_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalid_State_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalid_State_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalid_State_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalid_State_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalid_State_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalid_State_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalid_State_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalid_State_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalid_State_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ESyntax_Err;
class PASCALIMPLEMENTATION ESyntax_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ESyntax_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ESyntax_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ESyntax_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ESyntax_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ESyntax_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ESyntax_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ESyntax_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ESyntax_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ESyntax_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalid_Modification_Err;
class PASCALIMPLEMENTATION EInvalid_Modification_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalid_Modification_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalid_Modification_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalid_Modification_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalid_Modification_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalid_Modification_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalid_Modification_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalid_Modification_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalid_Modification_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalid_Modification_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ENamespace_Err;
class PASCALIMPLEMENTATION ENamespace_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENamespace_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENamespace_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENamespace_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENamespace_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENamespace_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENamespace_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENamespace_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENamespace_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENamespace_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalid_Access_Err;
class PASCALIMPLEMENTATION EInvalid_Access_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalid_Access_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalid_Access_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalid_Access_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalid_Access_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalid_Access_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalid_Access_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalid_Access_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalid_Access_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalid_Access_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInuse_Node_Err;
class PASCALIMPLEMENTATION EInuse_Node_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInuse_Node_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInuse_Node_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInuse_Node_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInuse_Node_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInuse_Node_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInuse_Node_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInuse_Node_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInuse_Node_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInuse_Node_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInuse_Content_Model_Err;
class PASCALIMPLEMENTATION EInuse_Content_Model_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInuse_Content_Model_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInuse_Content_Model_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInuse_Content_Model_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInuse_Content_Model_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInuse_Content_Model_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInuse_Content_Model_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInuse_Content_Model_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInuse_Content_Model_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInuse_Content_Model_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInuse_AttributeDefinition_Err;
class PASCALIMPLEMENTATION EInuse_AttributeDefinition_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInuse_AttributeDefinition_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInuse_AttributeDefinition_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInuse_AttributeDefinition_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInuse_AttributeDefinition_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInuse_AttributeDefinition_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInuse_AttributeDefinition_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInuse_AttributeDefinition_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInuse_AttributeDefinition_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInuse_AttributeDefinition_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS ENo_External_Entity_Allowed_Err;
class PASCALIMPLEMENTATION ENo_External_Entity_Allowed_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall ENo_External_Entity_Allowed_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall ENo_External_Entity_Allowed_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall ENo_External_Entity_Allowed_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall ENo_External_Entity_Allowed_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall ENo_External_Entity_Allowed_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall ENo_External_Entity_Allowed_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall ENo_External_Entity_Allowed_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall ENo_External_Entity_Allowed_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~ENo_External_Entity_Allowed_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInvalid_Entity_Reference_Err;
class PASCALIMPLEMENTATION EInvalid_Entity_Reference_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInvalid_Entity_Reference_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInvalid_Entity_Reference_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInvalid_Entity_Reference_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInvalid_Entity_Reference_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInvalid_Entity_Reference_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInvalid_Entity_Reference_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInvalid_Entity_Reference_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInvalid_Entity_Reference_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInvalid_Entity_Reference_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EUnknown_Document_Format_Err;
class PASCALIMPLEMENTATION EUnknown_Document_Format_Err : public EDomException 
{
	typedef EDomException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EUnknown_Document_Format_Err(const AnsiString Msg) : EDomException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUnknown_Document_Format_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EDomException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUnknown_Document_Format_Err(int Ident)/* overload */ : EDomException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUnknown_Document_Format_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EDomException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUnknown_Document_Format_Err(const AnsiString Msg, int AHelpContext) : EDomException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUnknown_Document_Format_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EDomException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUnknown_Document_Format_Err(int Ident, int AHelpContext)/* overload */ : EDomException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUnknown_Document_Format_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EDomException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EUnknown_Document_Format_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserException;
class PASCALIMPLEMENTATION EParserException : public Sysutils::Exception 
{
	typedef Sysutils::Exception inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserException(const AnsiString Msg) : Sysutils::Exception(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Sysutils::Exception(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserException(int Ident)/* overload */ : Sysutils::Exception(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Sysutils::Exception(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserException(const AnsiString Msg, int AHelpContext) : Sysutils::Exception(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserException(int Ident, int AHelpContext)/* overload */ : Sysutils::Exception(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EInternalParserException;
class PASCALIMPLEMENTATION EInternalParserException : public EParserException 
{
	typedef EParserException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EInternalParserException(const AnsiString Msg) : EParserException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EInternalParserException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EInternalParserException(int Ident)/* overload */ : EParserException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EInternalParserException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EInternalParserException(const AnsiString Msg, int AHelpContext) : EParserException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EInternalParserException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EInternalParserException(int Ident, int AHelpContext)/* overload */ : EParserException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EInternalParserException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EInternalParserException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserFatalError;
class PASCALIMPLEMENTATION EParserFatalError : public EParserException 
{
	typedef EParserException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserFatalError(const AnsiString Msg) : EParserException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserFatalError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserFatalError(int Ident)/* overload */ : EParserException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserFatalError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserFatalError(const AnsiString Msg, int AHelpContext) : EParserException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserFatalError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserFatalError(int Ident, int AHelpContext)/* overload */ : EParserException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserFatalError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserFatalError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserError;
class PASCALIMPLEMENTATION EParserError : public EParserException 
{
	typedef EParserException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserError(const AnsiString Msg) : EParserException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserError(int Ident)/* overload */ : EParserException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserError(const AnsiString Msg, int AHelpContext) : EParserException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserError(int Ident, int AHelpContext)/* overload */ : EParserException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserWarning;
class PASCALIMPLEMENTATION EParserWarning : public EParserException 
{
	typedef EParserException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserWarning(const AnsiString Msg) : EParserException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserWarning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserWarning(int Ident)/* overload */ : EParserException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserWarning(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserWarning(const AnsiString Msg, int AHelpContext) : EParserException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserWarning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserWarning(int Ident, int AHelpContext)/* overload */ : EParserException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserWarning(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserWarning(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserNamespaceFatalError;
class PASCALIMPLEMENTATION EParserNamespaceFatalError : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserNamespaceFatalError(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserNamespaceFatalError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserNamespaceFatalError(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserNamespaceFatalError(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserNamespaceFatalError(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserNamespaceFatalError(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserNamespaceFatalError(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserNamespaceFatalError(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserNamespaceFatalError(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserMissingWhiteSpace_Err;
class PASCALIMPLEMENTATION EParserMissingWhiteSpace_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserMissingWhiteSpace_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserMissingWhiteSpace_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserMissingWhiteSpace_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserMissingWhiteSpace_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserMissingWhiteSpace_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserMissingWhiteSpace_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserMissingWhiteSpace_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserMissingWhiteSpace_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserMissingWhiteSpace_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserMissingQuotationMark_Err;
class PASCALIMPLEMENTATION EParserMissingQuotationMark_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserMissingQuotationMark_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserMissingQuotationMark_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserMissingQuotationMark_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserMissingQuotationMark_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserMissingQuotationMark_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserMissingQuotationMark_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserMissingQuotationMark_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserMissingQuotationMark_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserMissingQuotationMark_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserMissingEqualitySign_Err;
class PASCALIMPLEMENTATION EParserMissingEqualitySign_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserMissingEqualitySign_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserMissingEqualitySign_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserMissingEqualitySign_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserMissingEqualitySign_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserMissingEqualitySign_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserMissingEqualitySign_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserMissingEqualitySign_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserMissingEqualitySign_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserMissingEqualitySign_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDoubleEqualitySign_Err;
class PASCALIMPLEMENTATION EParserDoubleEqualitySign_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDoubleEqualitySign_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDoubleEqualitySign_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDoubleEqualitySign_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDoubleEqualitySign_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDoubleEqualitySign_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDoubleEqualitySign_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDoubleEqualitySign_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDoubleEqualitySign_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDoubleEqualitySign_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidElementName_Err;
class PASCALIMPLEMENTATION EParserInvalidElementName_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidElementName_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidElementName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidElementName_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidElementName_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidElementName_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidElementName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidElementName_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidElementName_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidElementName_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidAttributeName_Err;
class PASCALIMPLEMENTATION EParserInvalidAttributeName_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidAttributeName_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidAttributeName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidAttributeName_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidAttributeName_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidAttributeName_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidAttributeName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidAttributeName_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidAttributeName_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidAttributeName_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidAttributeValue_Err;
class PASCALIMPLEMENTATION EParserInvalidAttributeValue_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidAttributeValue_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidAttributeValue_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidAttributeValue_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidAttributeValue_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidAttributeValue_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidAttributeValue_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidAttributeValue_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidAttributeValue_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidAttributeValue_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDoubleAttributeName_Err;
class PASCALIMPLEMENTATION EParserDoubleAttributeName_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDoubleAttributeName_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDoubleAttributeName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDoubleAttributeName_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDoubleAttributeName_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDoubleAttributeName_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDoubleAttributeName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDoubleAttributeName_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDoubleAttributeName_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDoubleAttributeName_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidEntityName_Err;
class PASCALIMPLEMENTATION EParserInvalidEntityName_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidEntityName_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidEntityName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidEntityName_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidEntityName_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidEntityName_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidEntityName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidEntityName_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidEntityName_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidEntityName_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidProcessingInstruction_Err;
class PASCALIMPLEMENTATION EParserInvalidProcessingInstruction_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidProcessingInstruction_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidProcessingInstruction_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidProcessingInstruction_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidProcessingInstruction_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidProcessingInstruction_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidProcessingInstruction_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidProcessingInstruction_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidProcessingInstruction_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidProcessingInstruction_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidXmlDeclaration_Err;
class PASCALIMPLEMENTATION EParserInvalidXmlDeclaration_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidXmlDeclaration_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidXmlDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidXmlDeclaration_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidXmlDeclaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidXmlDeclaration_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidXmlDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidXmlDeclaration_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidXmlDeclaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidXmlDeclaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidCharRef_Err;
class PASCALIMPLEMENTATION EParserInvalidCharRef_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidCharRef_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidCharRef_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidCharRef_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidCharRef_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidCharRef_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidCharRef_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidCharRef_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidCharRef_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidCharRef_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserMissingStartTag_Err;
class PASCALIMPLEMENTATION EParserMissingStartTag_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserMissingStartTag_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserMissingStartTag_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserMissingStartTag_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserMissingStartTag_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserMissingStartTag_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserMissingStartTag_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserMissingStartTag_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserMissingStartTag_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserMissingStartTag_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserMissingEndTag_Err;
class PASCALIMPLEMENTATION EParserMissingEndTag_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserMissingEndTag_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserMissingEndTag_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserMissingEndTag_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserMissingEndTag_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserMissingEndTag_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserMissingEndTag_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserMissingEndTag_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserMissingEndTag_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserMissingEndTag_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidEndTag_Err;
class PASCALIMPLEMENTATION EParserInvalidEndTag_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidEndTag_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidEndTag_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidEndTag_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidEndTag_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidEndTag_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidEndTag_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidEndTag_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidEndTag_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidEndTag_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidCharacter_Err;
class PASCALIMPLEMENTATION EParserInvalidCharacter_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidCharacter_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidCharacter_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidCharacter_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidCharacter_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidCharacter_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidCharacter_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidCharacter_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidCharacter_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidCharacter_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserNotInRoot_Err;
class PASCALIMPLEMENTATION EParserNotInRoot_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserNotInRoot_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserNotInRoot_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserNotInRoot_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserNotInRoot_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserNotInRoot_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserNotInRoot_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserNotInRoot_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserNotInRoot_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserNotInRoot_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDoubleRootElement_Err;
class PASCALIMPLEMENTATION EParserDoubleRootElement_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDoubleRootElement_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDoubleRootElement_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDoubleRootElement_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDoubleRootElement_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDoubleRootElement_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDoubleRootElement_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDoubleRootElement_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDoubleRootElement_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDoubleRootElement_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserRootNotFound_Err;
class PASCALIMPLEMENTATION EParserRootNotFound_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserRootNotFound_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserRootNotFound_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserRootNotFound_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserRootNotFound_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserRootNotFound_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserRootNotFound_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserRootNotFound_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserRootNotFound_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserRootNotFound_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserWrongOrder_Err;
class PASCALIMPLEMENTATION EParserWrongOrder_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserWrongOrder_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserWrongOrder_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserWrongOrder_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserWrongOrder_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserWrongOrder_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserWrongOrder_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserWrongOrder_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserWrongOrder_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserWrongOrder_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidDoctype_Err;
class PASCALIMPLEMENTATION EParserInvalidDoctype_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidDoctype_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidDoctype_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidDoctype_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidDoctype_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidDoctype_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidDoctype_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidDoctype_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidDoctype_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidDoctype_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidTextDeclaration_Err;
class PASCALIMPLEMENTATION EParserInvalidTextDeclaration_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidTextDeclaration_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidTextDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidTextDeclaration_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidTextDeclaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidTextDeclaration_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidTextDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidTextDeclaration_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidTextDeclaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidTextDeclaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserLtInAttributeValue_Err;
class PASCALIMPLEMENTATION EParserLtInAttributeValue_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserLtInAttributeValue_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserLtInAttributeValue_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserLtInAttributeValue_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserLtInAttributeValue_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserLtInAttributeValue_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserLtInAttributeValue_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserLtInAttributeValue_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserLtInAttributeValue_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserLtInAttributeValue_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserAttributeValueRefersToExternalEntity_Err;
class PASCALIMPLEMENTATION EParserAttributeValueRefersToExternalEntity_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserAttributeValueRefersToExternalEntity_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserAttributeValueRefersToExternalEntity_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserReferenceToUnparsedEntity_Err;
class PASCALIMPLEMENTATION EParserReferenceToUnparsedEntity_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserReferenceToUnparsedEntity_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserReferenceToUnparsedEntity_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserReferenceToUnparsedEntity_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserReferenceToUnparsedEntity_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserReferenceToUnparsedEntity_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserReferenceToUnparsedEntity_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserReferenceToUnparsedEntity_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserReferenceToUnparsedEntity_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserReferenceToUnparsedEntity_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserNoProperMarkupReferenced_Err;
class PASCALIMPLEMENTATION EParserNoProperMarkupReferenced_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserNoProperMarkupReferenced_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserNoProperMarkupReferenced_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserNoProperMarkupReferenced_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserNoProperMarkupReferenced_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserNoProperMarkupReferenced_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserNoProperMarkupReferenced_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserNoProperMarkupReferenced_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserNoProperMarkupReferenced_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserNoProperMarkupReferenced_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidComment_Err;
class PASCALIMPLEMENTATION EParserInvalidComment_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidComment_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidComment_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidComment_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidComment_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidComment_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidComment_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidComment_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidComment_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidComment_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidCDATASection_Err;
class PASCALIMPLEMENTATION EParserInvalidCDATASection_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidCDATASection_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidCDATASection_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidCDATASection_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidCDATASection_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidCDATASection_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidCDATASection_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidCDATASection_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidCDATASection_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidCDATASection_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidSystemLiteral_Err;
class PASCALIMPLEMENTATION EParserInvalidSystemLiteral_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidSystemLiteral_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidSystemLiteral_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidSystemLiteral_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidSystemLiteral_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidSystemLiteral_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidSystemLiteral_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidSystemLiteral_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidSystemLiteral_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidSystemLiteral_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidPubidLiteral_Err;
class PASCALIMPLEMENTATION EParserInvalidPubidLiteral_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidPubidLiteral_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidPubidLiteral_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidPubidLiteral_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidPubidLiteral_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidPubidLiteral_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidPubidLiteral_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidPubidLiteral_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidPubidLiteral_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidPubidLiteral_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidDoctypeName_Err;
class PASCALIMPLEMENTATION EParserInvalidDoctypeName_Err : public EParserFatalError 
{
	typedef EParserFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidDoctypeName_Err(const AnsiString Msg) : EParserFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidDoctypeName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidDoctypeName_Err(int Ident)/* overload */ : EParserFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidDoctypeName_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidDoctypeName_Err(const AnsiString Msg, int AHelpContext) : EParserFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidDoctypeName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidDoctypeName_Err(int Ident, int AHelpContext)/* overload */ : EParserFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidDoctypeName_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidDoctypeName_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidQualifiedName_Err;
class PASCALIMPLEMENTATION EParserInvalidQualifiedName_Err : public EParserNamespaceFatalError 
{
	typedef EParserNamespaceFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidQualifiedName_Err(const AnsiString Msg) : EParserNamespaceFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidQualifiedName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserNamespaceFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidQualifiedName_Err(int Ident)/* overload */ : EParserNamespaceFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidQualifiedName_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserNamespaceFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidQualifiedName_Err(const AnsiString Msg, int AHelpContext) : EParserNamespaceFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidQualifiedName_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserNamespaceFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidQualifiedName_Err(int Ident, int AHelpContext)/* overload */ : EParserNamespaceFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidQualifiedName_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserNamespaceFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidQualifiedName_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidPrefix_Err;
class PASCALIMPLEMENTATION EParserInvalidPrefix_Err : public EParserNamespaceFatalError 
{
	typedef EParserNamespaceFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidPrefix_Err(const AnsiString Msg) : EParserNamespaceFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidPrefix_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserNamespaceFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidPrefix_Err(int Ident)/* overload */ : EParserNamespaceFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidPrefix_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserNamespaceFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidPrefix_Err(const AnsiString Msg, int AHelpContext) : EParserNamespaceFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidPrefix_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserNamespaceFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidPrefix_Err(int Ident, int AHelpContext)/* overload */ : EParserNamespaceFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidPrefix_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserNamespaceFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidPrefix_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidNamespaceURI_Err;
class PASCALIMPLEMENTATION EParserInvalidNamespaceURI_Err : public EParserNamespaceFatalError 
{
	typedef EParserNamespaceFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidNamespaceURI_Err(const AnsiString Msg) : EParserNamespaceFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidNamespaceURI_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserNamespaceFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidNamespaceURI_Err(int Ident)/* overload */ : EParserNamespaceFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidNamespaceURI_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserNamespaceFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidNamespaceURI_Err(const AnsiString Msg, int AHelpContext) : EParserNamespaceFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidNamespaceURI_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserNamespaceFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidNamespaceURI_Err(int Ident, int AHelpContext)/* overload */ : EParserNamespaceFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidNamespaceURI_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserNamespaceFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidNamespaceURI_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserNamespaceURINotFound_Err;
class PASCALIMPLEMENTATION EParserNamespaceURINotFound_Err : public EParserNamespaceFatalError 
{
	typedef EParserNamespaceFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserNamespaceURINotFound_Err(const AnsiString Msg) : EParserNamespaceFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserNamespaceURINotFound_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserNamespaceFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserNamespaceURINotFound_Err(int Ident)/* overload */ : EParserNamespaceFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserNamespaceURINotFound_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserNamespaceFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserNamespaceURINotFound_Err(const AnsiString Msg, int AHelpContext) : EParserNamespaceFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserNamespaceURINotFound_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserNamespaceFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserNamespaceURINotFound_Err(int Ident, int AHelpContext)/* overload */ : EParserNamespaceFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserNamespaceURINotFound_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserNamespaceFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserNamespaceURINotFound_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserWrongPrefixMappingNesting_Err;
class PASCALIMPLEMENTATION EParserWrongPrefixMappingNesting_Err : public EParserNamespaceFatalError 
{
	typedef EParserNamespaceFatalError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserWrongPrefixMappingNesting_Err(const AnsiString Msg) : EParserNamespaceFatalError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserWrongPrefixMappingNesting_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserNamespaceFatalError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserWrongPrefixMappingNesting_Err(int Ident)/* overload */ : EParserNamespaceFatalError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserWrongPrefixMappingNesting_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserNamespaceFatalError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserWrongPrefixMappingNesting_Err(const AnsiString Msg, int AHelpContext) : EParserNamespaceFatalError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserWrongPrefixMappingNesting_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserNamespaceFatalError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserWrongPrefixMappingNesting_Err(int Ident, int AHelpContext)/* overload */ : EParserNamespaceFatalError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserWrongPrefixMappingNesting_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserNamespaceFatalError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserWrongPrefixMappingNesting_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDoubleDoctype_Err;
class PASCALIMPLEMENTATION EParserDoubleDoctype_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDoubleDoctype_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDoubleDoctype_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDoubleDoctype_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDoubleDoctype_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDoubleDoctype_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDoubleDoctype_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDoubleDoctype_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDoubleDoctype_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDoubleDoctype_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserUnknownDeclarationType_Err;
class PASCALIMPLEMENTATION EParserUnknownDeclarationType_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserUnknownDeclarationType_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserUnknownDeclarationType_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserUnknownDeclarationType_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserUnknownDeclarationType_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserUnknownDeclarationType_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserUnknownDeclarationType_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserUnknownDeclarationType_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserUnknownDeclarationType_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserUnknownDeclarationType_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidEntityDeclaration_Err;
class PASCALIMPLEMENTATION EParserInvalidEntityDeclaration_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidEntityDeclaration_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidEntityDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidEntityDeclaration_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidEntityDeclaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidEntityDeclaration_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidEntityDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidEntityDeclaration_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidEntityDeclaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidEntityDeclaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidElementDeclaration_Err;
class PASCALIMPLEMENTATION EParserInvalidElementDeclaration_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidElementDeclaration_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidElementDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidElementDeclaration_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidElementDeclaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidElementDeclaration_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidElementDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidElementDeclaration_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidElementDeclaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidElementDeclaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidAttributeDeclaration_Err;
class PASCALIMPLEMENTATION EParserInvalidAttributeDeclaration_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidAttributeDeclaration_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidAttributeDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidAttributeDeclaration_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidAttributeDeclaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidAttributeDeclaration_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidAttributeDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidAttributeDeclaration_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidAttributeDeclaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidAttributeDeclaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidNotationDeclaration_Err;
class PASCALIMPLEMENTATION EParserInvalidNotationDeclaration_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidNotationDeclaration_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidNotationDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidNotationDeclaration_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidNotationDeclaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidNotationDeclaration_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidNotationDeclaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidNotationDeclaration_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidNotationDeclaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidNotationDeclaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserInvalidConditionalSection_Err;
class PASCALIMPLEMENTATION EParserInvalidConditionalSection_Err : public EParserInvalidDoctype_Err 
{
	typedef EParserInvalidDoctype_Err inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserInvalidConditionalSection_Err(const AnsiString Msg) : EParserInvalidDoctype_Err(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserInvalidConditionalSection_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserInvalidDoctype_Err(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserInvalidConditionalSection_Err(int Ident)/* overload */ : EParserInvalidDoctype_Err(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserInvalidConditionalSection_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserInvalidDoctype_Err(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserInvalidConditionalSection_Err(const AnsiString Msg, int AHelpContext) : EParserInvalidDoctype_Err(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserInvalidConditionalSection_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserInvalidDoctype_Err(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserInvalidConditionalSection_Err(int Ident, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserInvalidConditionalSection_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserInvalidDoctype_Err(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserInvalidConditionalSection_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDouble_AttDef_Warning;
class PASCALIMPLEMENTATION EParserDouble_AttDef_Warning : public EParserWarning 
{
	typedef EParserWarning inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDouble_AttDef_Warning(const AnsiString Msg) : EParserWarning(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDouble_AttDef_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserWarning(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDouble_AttDef_Warning(int Ident)/* overload */ : EParserWarning(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDouble_AttDef_Warning(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserWarning(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDouble_AttDef_Warning(const AnsiString Msg, int AHelpContext) : EParserWarning(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDouble_AttDef_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserWarning(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDouble_AttDef_Warning(int Ident, int AHelpContext)/* overload */ : EParserWarning(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDouble_AttDef_Warning(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserWarning(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDouble_AttDef_Warning(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDouble_Entity_Decl_Warning;
class PASCALIMPLEMENTATION EParserDouble_Entity_Decl_Warning : public EParserWarning 
{
	typedef EParserWarning inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDouble_Entity_Decl_Warning(const AnsiString Msg) : EParserWarning(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDouble_Entity_Decl_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserWarning(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDouble_Entity_Decl_Warning(int Ident)/* overload */ : EParserWarning(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDouble_Entity_Decl_Warning(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserWarning(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDouble_Entity_Decl_Warning(const AnsiString Msg, int AHelpContext) : EParserWarning(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDouble_Entity_Decl_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserWarning(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDouble_Entity_Decl_Warning(int Ident, int AHelpContext)/* overload */ : EParserWarning(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDouble_Entity_Decl_Warning(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserWarning(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDouble_Entity_Decl_Warning(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDouble_Parameter_Entity_Decl_Warning;
class PASCALIMPLEMENTATION EParserDouble_Parameter_Entity_Decl_Warning : public EParserWarning 
{
	typedef EParserWarning inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(const AnsiString Msg) : EParserWarning(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserWarning(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(int Ident)/* overload */ : EParserWarning(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserWarning(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(const AnsiString Msg, int AHelpContext) : EParserWarning(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserWarning(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(int Ident, int AHelpContext)/* overload */ : EParserWarning(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDouble_Parameter_Entity_Decl_Warning(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserWarning(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDouble_Parameter_Entity_Decl_Warning(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserUnusable_Entity_Decl_Warning;
class PASCALIMPLEMENTATION EParserUnusable_Entity_Decl_Warning : public EParserWarning 
{
	typedef EParserWarning inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserUnusable_Entity_Decl_Warning(const AnsiString Msg) : EParserWarning(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserUnusable_Entity_Decl_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserWarning(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserUnusable_Entity_Decl_Warning(int Ident)/* overload */ : EParserWarning(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserUnusable_Entity_Decl_Warning(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserWarning(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserUnusable_Entity_Decl_Warning(const AnsiString Msg, int AHelpContext) : EParserWarning(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserUnusable_Entity_Decl_Warning(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserWarning(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserUnusable_Entity_Decl_Warning(int Ident, int AHelpContext)/* overload */ : EParserWarning(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserUnusable_Entity_Decl_Warning(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserWarning(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserUnusable_Entity_Decl_Warning(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserMissing_Entity_Declaration_Err;
class PASCALIMPLEMENTATION EParserMissing_Entity_Declaration_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserMissing_Entity_Declaration_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserMissing_Entity_Declaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserMissing_Entity_Declaration_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserMissing_Entity_Declaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserMissing_Entity_Declaration_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserMissing_Entity_Declaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserMissing_Entity_Declaration_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserMissing_Entity_Declaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserMissing_Entity_Declaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDouble_Element_Type_Declaration_Err;
class PASCALIMPLEMENTATION EParserDouble_Element_Type_Declaration_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDouble_Element_Type_Declaration_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDouble_Element_Type_Declaration_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_Name_In_Mixed_Content_Err;
class PASCALIMPLEMENTATION EParserDuplicate_Name_In_Mixed_Content_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_Name_In_Mixed_Content_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_Name_In_Mixed_Content_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_ID_On_Element_Type_Err;
class PASCALIMPLEMENTATION EParserDuplicate_ID_On_Element_Type_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_ID_On_Element_Type_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_ID_On_Element_Type_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserUndeclared_Notation_Name_Err;
class PASCALIMPLEMENTATION EParserUndeclared_Notation_Name_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserUndeclared_Notation_Name_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserUndeclared_Notation_Name_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserUndeclared_Notation_Name_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserUndeclared_Notation_Name_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserUndeclared_Notation_Name_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserUndeclared_Notation_Name_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserUndeclared_Notation_Name_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserUndeclared_Notation_Name_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserUndeclared_Notation_Name_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_Notation_On_Element_Type_Err;
class PASCALIMPLEMENTATION EParserDuplicate_Notation_On_Element_Type_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_Notation_On_Element_Type_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_Notation_On_Element_Type_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_Notation_Token_Err;
class PASCALIMPLEMENTATION EParserDuplicate_Notation_Token_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_Notation_Token_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_Notation_Token_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_Notation_Token_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_Notation_Token_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_Notation_Token_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_Notation_Token_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_Notation_Token_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_Notation_Token_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_Notation_Token_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserNotation_On_Empty_Element_Err;
class PASCALIMPLEMENTATION EParserNotation_On_Empty_Element_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserNotation_On_Empty_Element_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserNotation_On_Empty_Element_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserNotation_On_Empty_Element_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserNotation_On_Empty_Element_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserNotation_On_Empty_Element_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserNotation_On_Empty_Element_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserNotation_On_Empty_Element_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserNotation_On_Empty_Element_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserNotation_On_Empty_Element_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_Enumeration_Token_Err;
class PASCALIMPLEMENTATION EParserDuplicate_Enumeration_Token_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_Enumeration_Token_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_Enumeration_Token_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserAttribute_Type_Mismatch_Err;
class PASCALIMPLEMENTATION EParserAttribute_Type_Mismatch_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserAttribute_Type_Mismatch_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserAttribute_Type_Mismatch_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserAttribute_Type_Mismatch_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserAttribute_Type_Mismatch_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserAttribute_Type_Mismatch_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserAttribute_Type_Mismatch_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserAttribute_Type_Mismatch_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserAttribute_Type_Mismatch_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserAttribute_Type_Mismatch_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_Tokens_Err;
class PASCALIMPLEMENTATION EParserDuplicate_Tokens_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_Tokens_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_Tokens_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_Tokens_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_Tokens_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_Tokens_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_Tokens_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_Tokens_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_Tokens_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_Tokens_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserId_Neither_Implied_Nor_Required_Err;
class PASCALIMPLEMENTATION EParserId_Neither_Implied_Nor_Required_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserId_Neither_Implied_Nor_Required_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserId_Neither_Implied_Nor_Required_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserWrong_Root_Element_Type_Err;
class PASCALIMPLEMENTATION EParserWrong_Root_Element_Type_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserWrong_Root_Element_Type_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserWrong_Root_Element_Type_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserWrong_Root_Element_Type_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserWrong_Root_Element_Type_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserWrong_Root_Element_Type_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserWrong_Root_Element_Type_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserWrong_Root_Element_Type_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserWrong_Root_Element_Type_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserWrong_Root_Element_Type_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserElement_Type_Declaration_Not_Found_Err;
class PASCALIMPLEMENTATION EParserElement_Type_Declaration_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserElement_Type_Declaration_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserElement_Type_Declaration_Not_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserElement_Declared_Empty_Has_Content_Err;
class PASCALIMPLEMENTATION EParserElement_Declared_Empty_Has_Content_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserElement_Declared_Empty_Has_Content_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserElement_Declared_Empty_Has_Content_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserElement_With_Illegal_Mixed_Content_Err;
class PASCALIMPLEMENTATION EParserElement_With_Illegal_Mixed_Content_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserElement_With_Illegal_Mixed_Content_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserElement_With_Illegal_Mixed_Content_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserElement_With_Illegal_Element_Content_Err;
class PASCALIMPLEMENTATION EParserElement_With_Illegal_Element_Content_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserElement_With_Illegal_Element_Content_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserElement_With_Illegal_Element_Content_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserNondeterministic_Element_Content_Model_Err;
class PASCALIMPLEMENTATION EParserNondeterministic_Element_Content_Model_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserNondeterministic_Element_Content_Model_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserNondeterministic_Element_Content_Model_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_Notation_Decl_Err;
class PASCALIMPLEMENTATION EParserDuplicate_Notation_Decl_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_Notation_Decl_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_Notation_Decl_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_Notation_Decl_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_Notation_Decl_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_Notation_Decl_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_Notation_Decl_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_Notation_Decl_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_Notation_Decl_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_Notation_Decl_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserAttribute_Definition_Not_Found_Err;
class PASCALIMPLEMENTATION EParserAttribute_Definition_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserAttribute_Definition_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserAttribute_Definition_Not_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserRequired_Attribute_Not_Found_Err;
class PASCALIMPLEMENTATION EParserRequired_Attribute_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserRequired_Attribute_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserRequired_Attribute_Not_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserFixed_Attribute_Mismatch_Err;
class PASCALIMPLEMENTATION EParserFixed_Attribute_Mismatch_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserFixed_Attribute_Mismatch_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserFixed_Attribute_Mismatch_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserAttribute_Default_Type_Mismatch_Err;
class PASCALIMPLEMENTATION EParserAttribute_Default_Type_Mismatch_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserAttribute_Default_Type_Mismatch_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserAttribute_Default_Type_Mismatch_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserDuplicate_ID_Value_Err;
class PASCALIMPLEMENTATION EParserDuplicate_ID_Value_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserDuplicate_ID_Value_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserDuplicate_ID_Value_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserDuplicate_ID_Value_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserDuplicate_ID_Value_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserDuplicate_ID_Value_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserDuplicate_ID_Value_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserDuplicate_ID_Value_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserDuplicate_ID_Value_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserDuplicate_ID_Value_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserTarget_ID_Value_Not_Found_Err;
class PASCALIMPLEMENTATION EParserTarget_ID_Value_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserTarget_ID_Value_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserTarget_ID_Value_Not_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserTarget_Unparsed_Entity_Not_Found_Err;
class PASCALIMPLEMENTATION EParserTarget_Unparsed_Entity_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserTarget_Unparsed_Entity_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserTarget_Unparsed_Entity_Not_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserWrong_Declaration_Of_Predefined_Entity_Err;
class PASCALIMPLEMENTATION EParserWrong_Declaration_Of_Predefined_Entity_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserWrong_Declaration_Of_Predefined_Entity_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserWrong_Declaration_Of_Predefined_Entity_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserUnresolvable_Entity_Reference_Err;
class PASCALIMPLEMENTATION EParserUnresolvable_Entity_Reference_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserUnresolvable_Entity_Reference_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserUnresolvable_Entity_Reference_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserUnresolvable_Parameter_Entity_Reference_Err;
class PASCALIMPLEMENTATION EParserUnresolvable_Parameter_Entity_Reference_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserUnresolvable_Parameter_Entity_Reference_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserUnresolvable_Parameter_Entity_Reference_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserExternal_Subset_Not_Found_Err;
class PASCALIMPLEMENTATION EParserExternal_Subset_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserExternal_Subset_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserExternal_Subset_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserExternal_Subset_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserExternal_Subset_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserExternal_Subset_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserExternal_Subset_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserExternal_Subset_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserExternal_Subset_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserExternal_Subset_Not_Found_Err(void) { }
	#pragma option pop
	
};


class DELPHICLASS EParserExternal_Entity_Not_Found_Err;
class PASCALIMPLEMENTATION EParserExternal_Entity_Not_Found_Err : public EParserError 
{
	typedef EParserError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EParserExternal_Entity_Not_Found_Err(const AnsiString Msg) : EParserError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EParserExternal_Entity_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EParserError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EParserExternal_Entity_Not_Found_Err(int Ident)/* overload */ : EParserError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EParserExternal_Entity_Not_Found_Err(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EParserError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EParserExternal_Entity_Not_Found_Err(const AnsiString Msg, int AHelpContext) : EParserError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EParserExternal_Entity_Not_Found_Err(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EParserError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EParserExternal_Entity_Not_Found_Err(int Ident, int AHelpContext)/* overload */ : EParserError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EParserExternal_Entity_Not_Found_Err(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EParserError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EParserExternal_Entity_Not_Found_Err(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TdomNodeType { ntUnknown, ntElement_Node, ntAttribute_Node, ntText_Node, ntCDATA_Section_Node, ntEntity_Reference_Node, ntEntity_Node, ntProcessing_Instruction_Node, ntComment_Node, ntDocument_Node, ntDocument_Type_Node, ntDocument_Fragment_Node, ntNotation_Node };
#pragma option pop

typedef Set<TdomNodeType, ntUnknown, ntNotation_Node>  TdomWhatToShow;

typedef Set<TdomNodeType, ntUnknown, ntNotation_Node>  TdomNodeTypeSet;

#pragma option push -b-
enum TdomPieceType { xmlProcessingInstruction, xmlXmlDeclaration, xmlTextDeclaration, xmlComment, xmlCDATA, xmlPCDATA, xmlDoctype, xmlStartTag, xmlEndTag, xmlEmptyElementTag, xmlCharRef, xmlEntityRef, xmlParameterEntityRef, xmlEntityDecl, xmlElementDecl, xmlAttributeDecl, xmlNotationDecl, xmlCondSection, xmlUnknown };
#pragma option pop

#pragma option push -b-
enum TdomEntityResolveOption { erReplace, erExpand };
#pragma option pop

#pragma option push -b-
enum TdomContentspecType { ctEmpty, ctAny, ctMixed, ctChildren };
#pragma option pop

#pragma option push -b-
enum TdomEncodingType { etUTF8, etUTF16BE, etUTF16LE, etLatin1, etLatin2, etLatin3, etLatin4, etCyrillic, etArabic, etGreek, etHebrew, etLatin5, etLatin6, etLatin7, etLatin8, etLatin9, etKOI8R, etcp10000_MacRoman, etcp1250, etcp1251, etcp1252, etsystem };
#pragma option pop

#pragma option push -b-
enum TdomFilterResult { filter_accept, filter_reject, filter_skip };
#pragma option pop

typedef TMetaClass*TdomDocumentClass;

struct TdomDocumentFormat;
typedef TdomDocumentFormat *PdomDocumentFormat;

#pragma pack(push, 4)
struct TdomDocumentFormat
{
	TMetaClass*DocumentClass;
	WideString NamespaceUri;
	WideString QualifiedName;
	TdomDocumentFormat *next;
} ;
#pragma pack(pop)

class DELPHICLASS TdomNameValueList;
class PASCALIMPLEMENTATION TdomNameValueList : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	Classes::TStringList* FNames;
	Classes::TStringList* FValues;
	virtual int __fastcall getLength(void);
	virtual int __fastcall getCapacity(void);
	virtual WideString __fastcall getNames(int index);
	virtual WideString __fastcall getValues(int index);
	virtual void __fastcall setCapacity(const int value);
	
public:
	__fastcall TdomNameValueList(void);
	__fastcall virtual ~TdomNameValueList(void);
	virtual int __fastcall add(const WideString name, const WideString value);
	virtual void __fastcall clear(void);
	virtual void __fastcall Delete(const int item);
	virtual void __fastcall exchange(const int index1, const int index2);
	virtual int __fastcall indexOf(const WideString name, const WideString value);
	virtual int __fastcall indexOfName(const WideString name);
	virtual void __fastcall insert(const int index, const WideString name, const WideString value);
	__property int capacity = {read=getCapacity, write=setCapacity, nodefault};
	__property int length = {read=getLength, nodefault};
	__property WideString names[int index] = {read=getNames};
	__property WideString values[int index] = {read=getValues};
};


class DELPHICLASS TdomCustomStr;
class PASCALIMPLEMENTATION TdomCustomStr : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	wchar_t operator[](int indx) { return wideChars[indx]; }
	
private:
	int FActualLen;
	int FCapacity;
	WideString FContent;
	
protected:
	virtual wchar_t __fastcall getWideChars(int indx);
	virtual void __fastcall setWideChars(int indx, wchar_t ch);
	
public:
	__fastcall TdomCustomStr(void);
	virtual void __fastcall addWideChar(const wchar_t ch);
	virtual void __fastcall addWideString(const WideString s);
	virtual bool __fastcall endsWith(const WideString s);
	virtual bool __fastcall isEqual(const WideString s);
	virtual void __fastcall reset(void);
	virtual bool __fastcall startsWith(const WideString s);
	virtual WideString __fastcall value();
	__property int length = {read=FActualLen, nodefault};
	__property wchar_t wideChars[int indx] = {read=getWideChars, write=setWideChars/*, default*/};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomCustomStr(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomWideStringStream;
class PASCALIMPLEMENTATION TdomWideStringStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	char *FDataStringP;
	int FSize;
	int FCapacity;
	int FPosition;
	
protected:
	virtual void __fastcall setCapacity(int newCapacity);
	virtual void __fastcall setSize(int newSize)/* overload */;
	void __fastcall setStringPosition(int value);
	int __fastcall getStringPosition(void);
	void __fastcall setStringLength(int value);
	int __fastcall getStringLength(void);
	WideString __fastcall getDataString();
	
public:
	__fastcall TdomWideStringStream(const WideString aString);
	__fastcall virtual ~TdomWideStringStream(void);
	virtual int __fastcall read(void *buffer, int count);
	WideString __fastcall readString(int count);
	virtual int __fastcall seek(int offset, Word origin)/* overload */;
	virtual int __fastcall write(const void *buffer, int count);
	void __fastcall writeString(const WideString aString);
	__property int capacity = {read=FCapacity, write=setCapacity, nodefault};
	__property int stringLength = {read=getStringLength, write=setStringLength, nodefault};
	__property int stringPosition = {read=getStringPosition, write=setStringPosition, nodefault};
	__property WideString dataString = {read=getDataString};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomWideStringStream(void) : Classes::TStream() { }
	#pragma option pop
	
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  SetSize(const __int64 NewSize){ TStream::SetSize(NewSize); }
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS EConversionStream;
class PASCALIMPLEMENTATION EConversionStream : public Classes::EStreamError 
{
	typedef Classes::EStreamError inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EConversionStream(const AnsiString Msg) : Classes::EStreamError(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EConversionStream(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Classes::EStreamError(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EConversionStream(int Ident)/* overload */ : Classes::EStreamError(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EConversionStream(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Classes::EStreamError(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EConversionStream(const AnsiString Msg, int AHelpContext) : Classes::EStreamError(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EConversionStream(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Classes::EStreamError(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EConversionStream(int Ident, int AHelpContext)/* overload */ : Classes::EStreamError(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EConversionStream(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Classes::EStreamError(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EConversionStream(void) { }
	#pragma option pop
	
};


class DELPHICLASS TConversionStream;
class PASCALIMPLEMENTATION TConversionStream : public Classes::TStream 
{
	typedef Classes::TStream inherited;
	
private:
	Classes::TStream* FTarget;
	int FConvertCount;
	void *FConvertBufP;
	int FConvertBufSize;
	
protected:
	virtual int __fastcall convertReadBuffer(const void *buffer, int count);
	virtual int __fastcall convertWriteBuffer(const void *buffer, int count);
	virtual void __fastcall setConvertBufSize(int newSize);
	
public:
	__fastcall TConversionStream(Classes::TStream* target);
	__fastcall virtual ~TConversionStream(void);
	virtual int __fastcall read(void *buffer, int count);
	virtual int __fastcall write(const void *buffer, int count);
	virtual int __fastcall seek(int offset, Word origin)/* overload */;
	void __fastcall freeConvertBuffer(void);
	__property Classes::TStream* target = {read=FTarget};
	__property void * convertBufP = {read=FConvertBufP};
	__property int convertCount = {read=FConvertCount, nodefault};
	__property int convertBufSize = {read=FConvertBufSize, nodefault};
	
/* Hoisted overloads: */
	
public:
	inline __int64 __fastcall  Seek(const __int64 Offset, Classes::TSeekOrigin Origin){ return TStream::Seek(Offset, Origin); }
	
};


class DELPHICLASS TUTF16BEToUTF8Stream;
class PASCALIMPLEMENTATION TUTF16BEToUTF8Stream : public TConversionStream 
{
	typedef TConversionStream inherited;
	
private:
	bool FExpandLF;
	
protected:
	virtual int __fastcall convertWriteBuffer(const void *buffer, int count);
	
public:
	__property bool expandLF = {read=FExpandLF, write=FExpandLF, nodefault};
public:
	#pragma option push -w-inl
	/* TConversionStream.create */ inline __fastcall TUTF16BEToUTF8Stream(Classes::TStream* target) : TConversionStream(target) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TConversionStream.destroy */ inline __fastcall virtual ~TUTF16BEToUTF8Stream(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TXmlParserAction { paFail, paRetry, paOK };
#pragma option pop

typedef void __fastcall (__closure *TXmlParserEvent)(System::TObject* sender, const WideString parentSystemId, WideString &publicId, WideString &systemId, Classes::TStream* &stream, TXmlParserAction &action);

class DELPHICLASS TDomImplementation;
class DELPHICLASS TdomCMNodeList;
class DELPHICLASS TdomCMNode;
class PASCALIMPLEMENTATION TdomCMNodeList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FCMNodeList;
	virtual int __fastcall getLength(void);
	
protected:
	virtual int __fastcall indexOf(const TdomCMNode* node);
	
public:
	virtual TdomCMNode* __fastcall item(const int index);
	__fastcall TdomCMNodeList(const Classes::TList* CMNodeList);
	__property int length = {read=getLength, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomCMNodeList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomNodeList;
class DELPHICLASS TdomNode;
class PASCALIMPLEMENTATION TdomNodeList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TList* FNodeList;
	
protected:
	virtual int __fastcall getLength(void);
	virtual int __fastcall indexOf(const TdomNode* node);
	
public:
	__fastcall TdomNodeList(const Classes::TList* nodeList);
	virtual TdomNode* __fastcall item(const int index);
	__property int length = {read=getLength, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomNodeList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCMExternalObject;
class DELPHICLASS TdomCMInternalObject;
class DELPHICLASS TdomCMObject;
class DELPHICLASS TdomDocument;
class DELPHICLASS TdomDocumentType;
class PASCALIMPLEMENTATION TDomImplementation : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TdomCMNodeList* FCreatedCMExternalObjects;
	TdomCMNodeList* FCreatedCMInternalObjects;
	TdomCMNodeList* FCreatedCMObjects;
	TdomNodeList* FCreatedDocuments;
	TdomNodeList* FCreatedDocumentTypes;
	Classes::TList* FCreatedCMExternalObjectsListing;
	Classes::TList* FCreatedCMInternalObjectsListing;
	Classes::TList* FCreatedCMObjectsListing;
	Classes::TList* FCreatedDocumentsListing;
	Classes::TList* FCreatedDocumentTypesListing;
	TXmlParserEvent FOnExternalParsedEntity;
	virtual TdomCMNodeList* __fastcall getCMExternalObjects(void);
	virtual TdomCMNodeList* __fastcall getCMInternalObjects(void);
	virtual TdomCMNodeList* __fastcall getCMObjects(void);
	virtual TdomNodeList* __fastcall getDocuments(void);
	virtual TdomNodeList* __fastcall getDocumentTypes(void);
	
public:
	__fastcall virtual TDomImplementation(Classes::TComponent* aOwner);
	__fastcall virtual ~TDomImplementation(void);
	virtual void __fastcall clear(void);
	virtual void __fastcall freeCMExternalObject(TdomCMExternalObject* &arg);
	virtual void __fastcall freeCMInternalObject(TdomCMInternalObject* &arg);
	virtual void __fastcall freeCMObject(TdomCMObject* &arg);
	virtual void __fastcall freeDocument(TdomDocument* &doc);
	virtual void __fastcall freeDocumentType(TdomDocumentType* &docType);
	virtual bool __fastcall hasFeature(const WideString feature, const WideString version);
	virtual TdomCMExternalObject* __fastcall createCMExternalObject(const WideString pubId, const WideString sysId);
	virtual TdomCMInternalObject* __fastcall createCMInternalObject(const WideString pubId, const WideString sysId);
	virtual TdomCMObject* __fastcall createCMObject(void);
	virtual TdomDocument* __fastcall createDocument(const WideString name, TdomDocumentType* doctype);
	virtual TdomDocument* __fastcall createDocumentNS(const WideString namespaceURI, const WideString qualifiedName, TdomDocumentType* doctype);
	virtual TMetaClass* __fastcall getDocumentClass(const WideString aNamespaceUri, const WideString aQualifiedName);
	/* virtual class method */ virtual void __fastcall registerDocumentFormat(TMetaClass* vmt, const WideString aNamespaceUri, const WideString aQualifiedName, TMetaClass* aDocumentClass);
	virtual bool __fastcall supportsDocumentFormat(const WideString aNamespaceUri, const WideString aQualifiedName);
	/* virtual class method */ virtual void __fastcall unregisterDocumentClass(TMetaClass* vmt, const TMetaClass* aDocumentClass);
	__property TdomCMNodeList* cmExternalObjects = {read=getCMExternalObjects};
	__property TdomCMNodeList* cmInternalObjects = {read=getCMInternalObjects};
	__property TdomCMNodeList* cmObjects = {read=getCMObjects};
	__property TdomNodeList* documents = {read=getDocuments};
	__property TdomNodeList* documentTypes = {read=getDocumentTypes};
	
__published:
	__property TXmlParserEvent onExternalParsedEntity = {read=FOnExternalParsedEntity, write=FOnExternalParsedEntity};
};


class DELPHICLASS TdomNodeFilter;
class PASCALIMPLEMENTATION TdomNodeFilter : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual TdomFilterResult __fastcall acceptNode(const TdomNode* n) = 0 ;
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomNodeFilter(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomNodeFilter(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomTreeWalker;
class PASCALIMPLEMENTATION TdomTreeWalker : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomNode* FRoot;
	TdomNode* FCurrentNode;
	bool FExpandEntityReferences;
	TdomWhatToShow FWhatToShow;
	TdomNodeFilter* FFilter;
	
protected:
	virtual TdomNode* __fastcall getCurrentNode(void);
	virtual void __fastcall setCurrentNode(const TdomNode* node);
	virtual TdomNode* __fastcall findNextSibling(const TdomNode* oldNode);
	virtual TdomNode* __fastcall findPreviousSibling(const TdomNode* oldNode);
	virtual TdomNode* __fastcall findParentNode(const TdomNode* oldNode);
	virtual TdomNode* __fastcall findFirstChild(const TdomNode* oldNode);
	virtual TdomNode* __fastcall findLastChild(const TdomNode* oldNode);
	virtual TdomNode* __fastcall findNextNode(TdomNode* oldNode);
	virtual TdomNode* __fastcall findPreviousNode(const TdomNode* oldNode);
	
public:
	__fastcall virtual TdomTreeWalker(const TdomNode* root, const TdomWhatToShow whatToShow, const TdomNodeFilter* nodeFilter, const bool entityReferenceExpansion);
	virtual TdomNode* __fastcall parentNode(void);
	virtual TdomNode* __fastcall firstChild(void);
	virtual TdomNode* __fastcall lastChild(void);
	virtual TdomNode* __fastcall previousSibling(void);
	virtual TdomNode* __fastcall nextSibling(void);
	virtual TdomNode* __fastcall nextNode(void);
	virtual TdomNode* __fastcall previousNode(void);
	__property TdomNode* currentNode = {read=getCurrentNode, write=setCurrentNode};
	__property bool expandEntityReferences = {read=FExpandEntityReferences, nodefault};
	__property TdomNodeFilter* filter = {read=FFilter};
	__property TdomNode* root = {read=FRoot};
	__property TdomWhatToShow whatToShow = {read=FWhatToShow, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomTreeWalker(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TdomPosition { posBefore, posAfter };
#pragma option pop

class DELPHICLASS TdomNodeIterator;
class PASCALIMPLEMENTATION TdomNodeIterator : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomNode* FRoot;
	TdomNode* FReferenceNode;
	TdomPosition FPosition;
	TdomWhatToShow FWhatToShow;
	bool FExpandEntityReferences;
	TdomNodeFilter* FFilter;
	bool FInvalid;
	
protected:
	virtual void __fastcall findNewReferenceNode(const TdomNode* nodeToRemove);
	virtual TdomNode* __fastcall findNextNode(TdomNode* oldNode);
	virtual TdomNode* __fastcall findPreviousNode(const TdomNode* oldNode);
	
public:
	__fastcall virtual TdomNodeIterator(const TdomNode* root, const TdomWhatToShow whatToShow, const TdomNodeFilter* nodeFilter, const bool entityReferenceExpansion);
	virtual void __fastcall detach(void);
	virtual TdomNode* __fastcall nextNode(void);
	virtual TdomNode* __fastcall previousNode(void);
	__property bool expandEntityReferences = {read=FExpandEntityReferences, nodefault};
	__property TdomNodeFilter* filter = {read=FFilter};
	__property TdomNode* root = {read=FRoot};
	__property TdomWhatToShow whatToShow = {read=FWhatToShow, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomNodeIterator(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomElementsNodeList;
class PASCALIMPLEMENTATION TdomElementsNodeList : public TdomNodeList 
{
	typedef TdomNodeList inherited;
	
private:
	WideString FQueryName;
	TdomNode* FStartElement;
	
protected:
	virtual int __fastcall getLength(void);
	
public:
	virtual int __fastcall indexOf(const TdomNode* node);
	virtual TdomNode* __fastcall item(const int index);
	__fastcall virtual TdomElementsNodeList(const WideString queryName, const TdomNode* startElement);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomElementsNodeList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomElementsNodeListNS;
class PASCALIMPLEMENTATION TdomElementsNodeListNS : public TdomNodeList 
{
	typedef TdomNodeList inherited;
	
private:
	WideString FQueryNamespaceURI;
	WideString FQueryLocalName;
	TdomNode* FStartElement;
	
protected:
	virtual int __fastcall getLength(void);
	
public:
	virtual int __fastcall indexOf(const TdomNode* node);
	virtual TdomNode* __fastcall item(const int index);
	__fastcall virtual TdomElementsNodeListNS(const WideString queryNamespaceURI, const WideString queryLocalName, const TdomNode* startElement);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomElementsNodeListNS(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomSpecialNodeList;
class PASCALIMPLEMENTATION TdomSpecialNodeList : public TdomNodeList 
{
	typedef TdomNodeList inherited;
	
protected:
	TdomNodeTypeSet FAllowedNodeTypes;
	virtual int __fastcall getLength(void);
	virtual int __fastcall getNamedIndex(const WideString name);
	virtual TdomNode* __fastcall getNamedItem(const WideString name);
	
public:
	virtual int __fastcall indexOf(const TdomNode* node);
	virtual TdomNode* __fastcall item(const int index);
	__fastcall virtual TdomSpecialNodeList(const Classes::TList* nodeList, const TdomNodeTypeSet allowedNTs);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomSpecialNodeList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomNamedNodeMap;
class PASCALIMPLEMENTATION TdomNamedNodeMap : public TdomNodeList 
{
	typedef TdomNodeList inherited;
	
private:
	TdomNode* FOwner;
	TdomNode* FOwnerNode;
	bool FNamespaceAware;
	bool FIsReadonly;
	virtual TdomNode* __fastcall getOwnerNode(void);
	virtual bool __fastcall getNamespaceAware(void);
	virtual void __fastcall setNamespaceAware(const bool value);
	
protected:
	TdomNodeTypeSet FAllowedNodeTypes;
	virtual int __fastcall getNamedIndex(const WideString name);
	virtual TdomNode* __fastcall removeItem(const TdomNode* arg);
	virtual void __fastcall setIsReadonly(const bool value);
	
public:
	__fastcall virtual TdomNamedNodeMap(const TdomNode* aOwner, const TdomNode* aOwnerNode, const Classes::TList* nodeList, const TdomNodeTypeSet allowedNTs);
	virtual TdomNode* __fastcall getNamedItem(const WideString name);
	virtual TdomNode* __fastcall setNamedItem(const TdomNode* arg);
	virtual TdomNode* __fastcall removeNamedItem(const WideString name);
	virtual TdomNode* __fastcall getNamedItemNS(const WideString namespaceURI, const WideString localName);
	virtual TdomNode* __fastcall setNamedItemNS(const TdomNode* arg);
	virtual TdomNode* __fastcall removeNamedItemNS(const WideString namespaceURI, const WideString localName);
	__property bool isReadonly = {read=FIsReadonly, nodefault};
	__property bool namespaceAware = {read=getNamespaceAware, write=setNamespaceAware, nodefault};
	__property TdomNode* ownerNode = {read=getOwnerNode};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomNamedNodeMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomEntitiesNamedNodeMap;
class DELPHICLASS TdomEntity;
class PASCALIMPLEMENTATION TdomEntitiesNamedNodeMap : public TdomNamedNodeMap 
{
	typedef TdomNamedNodeMap inherited;
	
private:
	virtual void __fastcall resolveAfterAddition(const TdomEntity* addedEntity);
	virtual void __fastcall resolveAfterRemoval(const TdomEntity* removedEntity);
	
public:
	virtual TdomNode* __fastcall setNamedItem(const TdomNode* arg);
	virtual TdomNode* __fastcall removeNamedItem(const WideString name);
	virtual TdomNode* __fastcall setNamedItemNS(const TdomNode* arg);
	virtual TdomNode* __fastcall removeNamedItemNS(const WideString namespaceURI, const WideString localName);
public:
	#pragma option push -w-inl
	/* TdomNamedNodeMap.create */ inline __fastcall virtual TdomEntitiesNamedNodeMap(const TdomNode* aOwner, const TdomNode* aOwnerNode, const Classes::TList* nodeList, const TdomNodeTypeSet allowedNTs) : TdomNamedNodeMap(aOwner, aOwnerNode, nodeList, allowedNTs) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomEntitiesNamedNodeMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCustomErrorHandler;
class DELPHICLASS TdomElement;
class PASCALIMPLEMENTATION TdomNode : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	WideString FNodeName;
	WideString FNodeValue;
	TdomNodeType FNodeType;
	TdomNodeList* FNodeList;
	Classes::TList* FNodeListing;
	TdomDocument* FDocument;
	TdomNode* FParentNode;
	bool FIsReadonly;
	virtual void __fastcall makeChildrenReadonly(void);
	virtual bool __fastcall refersToExternalEntity(void);
	virtual bool __fastcall refersToUnparsedEntity(void);
	virtual bool __fastcall hasEntRef(const WideString entName);
	virtual void __fastcall addEntRefSubtree(const WideString entName);
	virtual void __fastcall removeEntRefSubtree(const WideString entName);
	virtual WideString __fastcall getNodeName();
	virtual WideString __fastcall getNodeValue();
	virtual void __fastcall setNodeValue(const WideString value);
	virtual TdomNodeType __fastcall getNodeType(void);
	virtual TdomNamedNodeMap* __fastcall getAttributes(void);
	virtual TdomNode* __fastcall getParentNode(void);
	virtual TdomNodeList* __fastcall getChildNodes(void);
	virtual TdomNode* __fastcall getFirstChild(void);
	virtual TdomNode* __fastcall getLastChild(void);
	virtual TdomNode* __fastcall getPreviousSibling(void);
	virtual TdomNode* __fastcall getNextSibling(void);
	virtual TdomDocument* __fastcall getDocument(void);
	virtual WideString __fastcall getCode();
	virtual WideString __fastcall getTextContent();
	
protected:
	System::Set<TdomNodeType, ntUnknown, ntNotation_Node>  FAllowedChildTypes;
	WideString FLocalName;
	WideString FNamespaceURI;
	WideString FPrefix;
	virtual void __fastcall setIsReadonly(const bool value);
	virtual void __fastcall setPrefix(const WideString value);
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	virtual bool __fastcall validateIDREFS(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall TdomNode(const TdomDocument* aOwner);
	__fastcall virtual ~TdomNode(void);
	virtual TdomNode* __fastcall appendChild(const TdomNode* newChild);
	virtual void __fastcall clear(void);
	virtual TdomNode* __fastcall cloneNode(const bool deep);
	virtual TdomElement* __fastcall getFirstChildElement(const WideString name);
	virtual TdomElement* __fastcall getFirstChildElementNS(const WideString namespaceURI, const WideString localName);
	virtual TdomElement* __fastcall getLastChildElement(const WideString name);
	virtual TdomElement* __fastcall getLastChildElementNS(const WideString namespaceURI, const WideString localName);
	virtual TdomElement* __fastcall getNextSiblingElement(const WideString name);
	virtual TdomElement* __fastcall getNextSiblingElementNS(const WideString namespaceURI, const WideString localName);
	virtual TdomElement* __fastcall getParentElement(const WideString name);
	virtual TdomElement* __fastcall getParentElementNS(const WideString namespaceURI, const WideString localName);
	virtual TdomElement* __fastcall getPreviousSiblingElement(const WideString name);
	virtual TdomElement* __fastcall getPreviousSiblingElementNS(const WideString namespaceURI, const WideString localName);
	virtual bool __fastcall hasChildNodes(void);
	virtual TdomNode* __fastcall insertBefore(const TdomNode* newChild, const TdomNode* refChild);
	virtual bool __fastcall isAncestor(const TdomNode* AncestorNode);
	virtual void __fastcall normalize(void);
	virtual TdomNode* __fastcall removeChild(const TdomNode* oldChild);
	virtual TdomNode* __fastcall replaceChild(const TdomNode* newChild, const TdomNode* oldChild);
	virtual bool __fastcall resolveEntityReferences(const TdomEntityResolveOption opt);
	virtual bool __fastcall supports(const WideString feature, const WideString version);
	virtual void __fastcall writeCode(Classes::TStream* Stream);
	__property TdomNamedNodeMap* attributes = {read=getAttributes};
	__property TdomNodeList* childNodes = {read=getChildNodes};
	__property WideString code = {read=getCode};
	__property TdomNode* firstChild = {read=getFirstChild};
	__property bool isReadonly = {read=FIsReadonly, nodefault};
	__property TdomNode* lastChild = {read=getLastChild};
	__property WideString localName = {read=FLocalName};
	__property WideString namespaceURI = {read=FNamespaceURI};
	__property TdomNode* nextSibling = {read=getNextSibling};
	__property WideString nodeName = {read=getNodeName};
	__property TdomNodeType nodeType = {read=getNodeType, nodefault};
	__property WideString nodeValue = {read=getNodeValue, write=setNodeValue};
	__property TdomDocument* ownerDocument = {read=getDocument};
	__property TdomNode* parentNode = {read=getParentNode};
	__property TdomNode* previousSibling = {read=getPreviousSibling};
	__property WideString prefix = {read=FPrefix, write=setPrefix};
	__property WideString textContent = {read=getTextContent};
};


class DELPHICLASS TdomCharacterData;
class PASCALIMPLEMENTATION TdomCharacterData : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	virtual WideString __fastcall getData();
	virtual void __fastcall setData(const WideString Value);
	virtual int __fastcall getLength(void);
	
public:
	__fastcall virtual TdomCharacterData(const TdomDocument* aOwner);
	virtual WideString __fastcall substringData(const int offset, const int count);
	virtual void __fastcall appendData(const WideString arg);
	virtual void __fastcall insertData(const int offset, const WideString arg);
	virtual void __fastcall deleteData(const int offset, const int count);
	virtual void __fastcall replaceData(const int offset, const int count, const WideString arg);
	__property WideString data = {read=getData, write=setData};
	__property int length = {read=getLength, nodefault};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomCharacterData(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomAttr;
class PASCALIMPLEMENTATION TdomAttr : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	TdomElement* FOwnerElement;
	bool FSpecified;
	virtual WideString __fastcall getName();
	virtual bool __fastcall getSpecified(void);
	virtual WideString __fastcall getNodeValue();
	virtual void __fastcall setNodeValue(const WideString value);
	virtual WideString __fastcall getValue();
	virtual void __fastcall setValue(const WideString value);
	virtual TdomElement* __fastcall getOwnerElement(void);
	virtual TdomNode* __fastcall getParentNode(void);
	virtual TdomNode* __fastcall getPreviousSibling(void);
	virtual TdomNode* __fastcall getNextSibling(void);
	virtual WideString __fastcall getLiteralValue();
	
protected:
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	virtual bool __fastcall validateIDREFS(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall TdomAttr(const TdomDocument* aOwner, const WideString name, const bool spcfd);
	__fastcall TdomAttr(const TdomDocument* aOwner, const WideString namespaceURI, const WideString qualifiedName, const bool spcfd);
	virtual void __fastcall normalize(void);
	virtual bool __fastcall resolveEntityReferences(const TdomEntityResolveOption opt);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property WideString literalValue = {read=getLiteralValue};
	__property WideString name = {read=getName};
	__property TdomElement* ownerElement = {read=getOwnerElement};
	__property bool specified = {read=getSpecified, nodefault};
	__property WideString value = {read=getValue, write=setValue};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomAttr(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomElement : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	Classes::TList* FCreatedElementsNodeLists;
	Classes::TList* FCreatedElementsNodeListNSs;
	Classes::TList* FAttributeListing;
	TdomNamedNodeMap* FAttributeList;
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual void __fastcall setIsReadonly(const bool value);
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	virtual bool __fastcall validateIDREFS(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall TdomElement(const TdomDocument* aOwner, const WideString tagName);
	__fastcall TdomElement(const TdomDocument* aOwner, const WideString namespaceURI, const WideString qualifiedName);
	__fastcall virtual ~TdomElement(void);
	virtual WideString __fastcall getTagName();
	virtual TdomNamedNodeMap* __fastcall getAttributes(void);
	virtual WideString __fastcall getAttribute(const WideString name);
	virtual TdomAttr* __fastcall setAttribute(const WideString name, const WideString value);
	virtual TdomAttr* __fastcall removeAttribute(const WideString name);
	virtual TdomAttr* __fastcall getAttributeNode(const WideString name);
	virtual TdomAttr* __fastcall setAttributeNode(const TdomAttr* newAttr);
	virtual TdomAttr* __fastcall removeAttributeNode(const TdomAttr* oldAttr);
	virtual bool __fastcall resolveEntityReferences(const TdomEntityResolveOption opt);
	virtual TdomNodeList* __fastcall getElementsByTagName(const WideString name);
	virtual WideString __fastcall getAttributeNS(const WideString namespaceURI, const WideString localName);
	virtual TdomAttr* __fastcall setAttributeNS(const WideString namespaceURI, const WideString qualifiedName, const WideString value);
	virtual TdomAttr* __fastcall removeAttributeNS(const WideString namespaceURI, const WideString localName);
	virtual TdomAttr* __fastcall getAttributeNodeNS(const WideString namespaceURI, const WideString localName);
	virtual TdomAttr* __fastcall setAttributeNodeNS(const TdomAttr* newAttr);
	virtual TdomNodeList* __fastcall getElementsByTagNameNS(const WideString namespaceURI, const WideString localName);
	virtual bool __fastcall hasAttribute(const WideString name);
	virtual bool __fastcall hasAttributeNS(const WideString namespaceURI, const WideString localName);
	virtual void __fastcall normalize(void);
	virtual void __fastcall writeCode(Classes::TStream* Stream);
	__property WideString tagName = {read=getTagName};
};


class DELPHICLASS TdomText;
class PASCALIMPLEMENTATION TdomText : public TdomCharacterData 
{
	typedef TdomCharacterData inherited;
	
protected:
	virtual bool __fastcall getIsWhitespaceInElementContent(void);
	virtual WideString __fastcall getLiteralValue();
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomText(const TdomDocument* aOwner);
	virtual TdomText* __fastcall splitText(const int offset);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property bool isWhitespaceInElementContent = {read=getIsWhitespaceInElementContent, nodefault};
	__property WideString literalValue = {read=getLiteralValue};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomText(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomComment;
class PASCALIMPLEMENTATION TdomComment : public TdomCharacterData 
{
	typedef TdomCharacterData inherited;
	
protected:
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomComment(const TdomDocument* aOwner);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomComment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomProcessingInstruction;
class PASCALIMPLEMENTATION TdomProcessingInstruction : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	virtual WideString __fastcall getTarget();
	virtual WideString __fastcall getData();
	virtual void __fastcall setData(const WideString value);
	
protected:
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomProcessingInstruction(const TdomDocument* aOwner, const WideString targ);
	virtual void __fastcall writeCode(Classes::TStream* Stream);
	__property WideString target = {read=getTarget};
	__property WideString data = {read=getData, write=setData};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomProcessingInstruction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCDATASection;
class PASCALIMPLEMENTATION TdomCDATASection : public TdomText 
{
	typedef TdomText inherited;
	
protected:
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCDATASection(const TdomDocument* aOwner);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomCDATASection(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomDocumentType : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	WideString FInternalSubset;
	WideString FPublicId;
	WideString FSystemId;
	Classes::TList* FEntitiesListing;
	TdomEntitiesNamedNodeMap* FEntitiesList;
	Classes::TList* FNotationsListing;
	TdomNamedNodeMap* FNotationsList;
	virtual TdomEntitiesNamedNodeMap* __fastcall getEntities(void);
	virtual WideString __fastcall getInternalSubset();
	virtual WideString __fastcall getName();
	virtual TdomNamedNodeMap* __fastcall getNotations(void);
	virtual WideString __fastcall getPublicId();
	virtual WideString __fastcall getSystemId();
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomDocumentType(const TdomDocument* aOwner, const WideString name, const WideString pubId, const WideString sysId, const WideString intSubset);
	__fastcall virtual ~TdomDocumentType(void);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property TdomEntitiesNamedNodeMap* entities = {read=getEntities};
	__property WideString internalSubset = {read=getInternalSubset};
	__property WideString name = {read=getName};
	__property TdomNamedNodeMap* notations = {read=getNotations};
	__property WideString publicId = {read=getPublicId};
	__property WideString systemId = {read=getSystemId};
};


class DELPHICLASS TdomNotation;
class PASCALIMPLEMENTATION TdomNotation : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	WideString FPublicId;
	WideString FSystemId;
	virtual WideString __fastcall getPublicId();
	virtual WideString __fastcall getSystemId();
	virtual void __fastcall setNodeValue(const WideString value);
	
public:
	__fastcall virtual TdomNotation(const TdomDocument* aOwner, const WideString name, const WideString pubId, const WideString sysId);
	__property WideString publicId = {read=getPublicId};
	__property WideString systemId = {read=getSystemId};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomNotation(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomEntity : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	WideString FEncoding;
	bool FIsInternalEntity;
	bool FIsUnusable;
	WideString FNotationName;
	WideString FPublicId;
	WideString FSystemId;
	WideString FVersion;
	virtual WideString __fastcall getNotationName();
	virtual void __fastcall setNodeValue(const WideString value);
	
public:
	__fastcall virtual TdomEntity(const TdomDocument* aOwner, const WideString name, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual TdomNode* __fastcall insertBefore(const TdomNode* newChild, const TdomNode* refChild);
	virtual TdomNode* __fastcall replaceChild(const TdomNode* newChild, const TdomNode* oldChild);
	virtual TdomNode* __fastcall appendChild(const TdomNode* newChild);
	__property WideString encoding = {read=FEncoding, write=FEncoding};
	__property bool isInternalEntity = {read=FIsInternalEntity, nodefault};
	__property WideString notationName = {read=getNotationName};
	__property WideString publicId = {read=FPublicId};
	__property WideString systemId = {read=FSystemId};
	__property WideString version = {read=FVersion, write=FVersion};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomEntity(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomEntityReference;
class DELPHICLASS TdomCMEntity;
class PASCALIMPLEMENTATION TdomEntityReference : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	virtual bool __fastcall refersToUnparsedEntity(void);
	virtual TdomCMEntity* __fastcall getCorrespondingCMEntity(void);
	virtual bool __fastcall getRefersToPredefinedEntity(void);
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall expand(void);
	virtual bool __fastcall validate2(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomEntityReference(const TdomDocument* aOwner, const WideString name);
	virtual TdomNode* __fastcall cloneNode(const bool deep);
	virtual bool __fastcall resolveEntityReferences(const TdomEntityResolveOption opt);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property TdomCMEntity* correspondingCMEntity = {read=getCorrespondingCMEntity};
	__property bool refersToPredefinedEntity = {read=getRefersToPredefinedEntity, nodefault};
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomEntityReference(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomDocumentFragment;
class PASCALIMPLEMENTATION TdomDocumentFragment : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	virtual void __fastcall setNodeValue(const WideString value);
	
public:
	__fastcall virtual TdomDocumentFragment(const TdomDocument* aOwner);
public:
	#pragma option push -w-inl
	/* TdomNode.destroy */ inline __fastcall virtual ~TdomDocumentFragment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomAbstractView;
class PASCALIMPLEMENTATION TdomAbstractView : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomDocument* FDocument;
	
public:
	__property TdomDocument* document = {read=FDocument};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomAbstractView(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomAbstractView(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomDocument : public TdomNode 
{
	typedef TdomNode inherited;
	
private:
	Classes::TList* FCreatedNodes;
	Classes::TList* FCreatedNodeIterators;
	Classes::TList* FCreatedTreeWalkers;
	Classes::TList* FCreatedElementsNodeLists;
	Classes::TList* FCreatedElementsNodeListNSs;
	Classes::TStringList* FIDs;
	TdomCMObject* FCMInternal;
	WideString FSystemId;
	TdomAbstractView* FDefaultView;
	TDomImplementation* FDOMImpl;
	WideString FEncoding;
	WideString FStandalone;
	WideString FVersion;
	virtual bool __fastcall expandEntRef(const TdomEntityReference* node);
	virtual void __fastcall findNewReferenceNodes(const TdomNode* nodeToRemove);
	virtual AnsiString __fastcall getCodeAsString();
	virtual WideString __fastcall getCodeAsWideString();
	virtual TdomDocumentType* __fastcall getDoctype(void);
	virtual TdomElement* __fastcall getDocumentElement(void);
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual TdomEntity* __fastcall createEntity(const WideString name, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual TdomNotation* __fastcall createNotation(const WideString name, const WideString pubId, const WideString sysId);
	virtual TdomNode* __fastcall duplicateNode(const TdomNode* sourceNode, const bool deep);
	virtual void __fastcall initDoc(const WideString tagName);
	virtual void __fastcall initDocNS(const WideString namespaceURI, const WideString qualifiedName);
	virtual bool __fastcall validateIDREFS(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomDocument(const TDomImplementation* aOwner);
	__fastcall virtual ~TdomDocument(void);
	virtual void __fastcall clear(void);
	virtual void __fastcall clearInvalidNodeIterators(void);
	virtual TdomElement* __fastcall createElement(const WideString tagName);
	virtual TdomElement* __fastcall createElementNS(const WideString namespaceURI, const WideString qualifiedName);
	virtual TdomDocumentFragment* __fastcall createDocumentFragment(void);
	virtual TdomText* __fastcall createTextNode(const WideString data);
	virtual TdomComment* __fastcall createComment(const WideString data);
	virtual TdomCDATASection* __fastcall createCDATASection(const WideString data);
	virtual TdomProcessingInstruction* __fastcall createProcessingInstruction(const WideString targ, const WideString data);
	virtual TdomAttr* __fastcall createAttribute(const WideString name);
	virtual TdomAttr* __fastcall createAttributeNS(const WideString namespaceURI, const WideString qualifiedName);
	virtual TdomEntityReference* __fastcall createEntityReference(const WideString name);
	virtual TdomDocumentType* __fastcall createDocumentType(const WideString name, const WideString pubId, const WideString sysId, const WideString intSubset);
	virtual void __fastcall freeAllNodes(TdomNode* &node);
	virtual void __fastcall freeTreeWalker(TdomTreeWalker* &treeWalker);
	virtual TdomElement* __fastcall getElementById(const WideString elementId);
	virtual TdomNodeList* __fastcall getElementsByTagName(const WideString tagName);
	virtual TdomNodeList* __fastcall getElementsByTagNameNS(const WideString namespaceURI, const WideString localName);
	virtual TdomNode* __fastcall importNode(const TdomNode* importedNode, const bool deep);
	virtual TdomNode* __fastcall insertBefore(const TdomNode* newChild, const TdomNode* refChild);
	virtual TdomNode* __fastcall replaceChild(const TdomNode* newChild, const TdomNode* oldChild);
	virtual TdomNode* __fastcall appendChild(const TdomNode* newChild);
	virtual TdomNodeIterator* __fastcall createNodeIterator(const TdomNode* root, TdomWhatToShow whatToShow, TdomNodeFilter* nodeFilter, bool entityReferenceExpansion);
	virtual TdomTreeWalker* __fastcall createTreeWalker(const TdomNode* root, TdomWhatToShow whatToShow, TdomNodeFilter* nodeFilter, bool entityReferenceExpansion);
	virtual TdomCMObject* __fastcall removeContentModel(void);
	virtual TdomCMObject* __fastcall setContentModel(const TdomCMObject* arg);
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler, const TdomEntityResolveOption opt);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	virtual void __fastcall writeCodeAsUTF8(Classes::TStream* stream);
	virtual void __fastcall writeCodeAsUTF16(Classes::TStream* stream);
	__property AnsiString codeAsString = {read=getCodeAsString};
	__property WideString codeAsWideString = {read=getCodeAsWideString};
	__property TdomCMObject* contentModel = {read=FCMInternal};
	__property TdomAbstractView* defaultView = {read=FDefaultView};
	__property TdomDocumentType* doctype = {read=getDoctype};
	__property TdomElement* documentElement = {read=getDocumentElement};
	__property TDomImplementation* domImplementation = {read=FDOMImpl};
	__property WideString encoding = {read=FEncoding, write=FEncoding};
	__property Classes::TStringList* IDs = {read=FIDs};
	__property WideString standalone = {read=FStandalone, write=FStandalone};
	__property WideString systemId = {read=FSystemId, write=FSystemId};
	__property WideString version = {read=FVersion, write=FVersion};
};


#pragma option push -b-
enum TdomCMNodeType { ctUnknown, ctProcessingInstruction, ctComment, ctObject, ctFragment, ctExternalObject, ctInternalObject, ctAttribute, ctNotation, ctEntity, ctParameterEntity, ctParameterEntityReference, ctEntityDeclaration, ctParameterEntityDeclaration, ctElementTypeDeclaration, ctSequenceParticle, ctChoiceParticle, ctPcdataChoiceParticle, ctElementParticle, ctAttributeList, ctAttributeDefinition, ctNotationDeclaration, ctNameParticle, ctNmtokenParticle };
#pragma option pop

typedef Set<TdomCMNodeType, ctUnknown, ctNmtokenParticle>  TdomCMNodeTypeSet;

class DELPHICLASS TdomNamedCMNodeMap;
class PASCALIMPLEMENTATION TdomNamedCMNodeMap : public TdomCMNodeList 
{
	typedef TdomCMNodeList inherited;
	
private:
	TdomCMNode* FOwner;
	TdomCMNode* FOwnerNode;
	bool FIsReadonly;
	virtual TdomCMNode* __fastcall getOwnerNode(void);
	
protected:
	TdomCMNodeTypeSet FAllowedNodeTypes;
	virtual int __fastcall getNamedIndex(const WideString name);
	virtual TdomCMNode* __fastcall removeItem(const TdomCMNode* arg);
	virtual void __fastcall setIsReadonly(const bool value);
	
public:
	__fastcall virtual TdomNamedCMNodeMap(const TdomCMNode* aOwner, const TdomCMNode* aOwnerNode, const Classes::TList* nodeList, const TdomCMNodeTypeSet allowedNTs);
	virtual TdomCMNode* __fastcall getNamedItem(const WideString name);
	virtual TdomCMNode* __fastcall setNamedItem(const TdomCMNode* arg);
	virtual TdomCMNode* __fastcall removeNamedItem(const WideString name);
	__property bool isReadonly = {read=FIsReadonly, nodefault};
	__property TdomCMNode* ownerNode = {read=getOwnerNode};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomNamedCMNodeMap(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomNamedCMAttributeMap;
class DELPHICLASS TdomCMAttribute;
class PASCALIMPLEMENTATION TdomNamedCMAttributeMap : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomCMObject* FOwner;
	Classes::TList* FCMAttributesList;
	virtual int __fastcall getLength(void);
	
public:
	__fastcall TdomNamedCMAttributeMap(const TdomCMObject* aOwner);
	__fastcall virtual ~TdomNamedCMAttributeMap(void);
	virtual TdomCMAttribute* __fastcall item(const int index);
	virtual TdomCMAttribute* __fastcall getNamedItem(const WideString elementName, const WideString attributeName);
	virtual bool __fastcall appendNamedItem(const TdomCMAttribute* arg);
	virtual TdomCMAttribute* __fastcall removeLastItem(void);
	__property int length = {read=getLength, nodefault};
	__property TdomCMObject* ownerContentModel = {read=FOwner};
};


class DELPHICLASS TdomNamedCMEntityMap;
class PASCALIMPLEMENTATION TdomNamedCMEntityMap : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomCMObject* FOwner;
	Classes::TList* FCMEntitiesList;
	virtual int __fastcall getLength(void);
	
public:
	__fastcall TdomNamedCMEntityMap(const TdomCMObject* aOwner);
	__fastcall virtual ~TdomNamedCMEntityMap(void);
	virtual TdomCMEntity* __fastcall item(const int index);
	virtual TdomCMEntity* __fastcall getNamedItem(const WideString name);
	virtual bool __fastcall appendNamedItem(const TdomCMEntity* arg);
	virtual TdomCMEntity* __fastcall removeLastItem(void);
	__property int length = {read=getLength, nodefault};
	__property TdomCMObject* ownerContentModel = {read=FOwner};
};


class DELPHICLASS TdomCustomCMObject;
class PASCALIMPLEMENTATION TdomCMNode : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	WideString FNodeName;
	WideString FNodeValue;
	TdomCMNodeType FNodeType;
	TdomCMNodeList* FCMNodeList;
	Classes::TList* FCMNodeListing;
	TdomCustomCMObject* FCMObject;
	TdomCMNode* FParentNode;
	bool FIsReadonly;
	virtual void __fastcall makeChildrenReadonly(void);
	virtual WideString __fastcall getNodeName();
	virtual WideString __fastcall getNodeValue();
	virtual void __fastcall setNodeValue(const WideString value);
	virtual TdomCMNodeType __fastcall getCMNodeType(void);
	virtual TdomCMNode* __fastcall getParentNode(void);
	virtual TdomCMNodeList* __fastcall getChildNodes(void);
	virtual TdomCMNode* __fastcall getFirstChild(void);
	virtual TdomCMNode* __fastcall getLastChild(void);
	virtual TdomCMNode* __fastcall getPreviousSibling(void);
	virtual TdomCMNode* __fastcall getNextSibling(void);
	virtual TdomCustomCMObject* __fastcall getCMObject(void);
	virtual WideString __fastcall getCode();
	
protected:
	System::Set<TdomCMNodeType, ctUnknown, ctNmtokenParticle>  FAllowedChildTypes;
	virtual void __fastcall setIsReadonly(const bool value);
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall TdomCMNode(const TdomCustomCMObject* aOwner);
	__fastcall virtual ~TdomCMNode(void);
	virtual void __fastcall clear(void);
	virtual TdomCMNode* __fastcall insertBefore(const TdomCMNode* newChild, const TdomCMNode* refChild);
	virtual TdomCMNode* __fastcall replaceChild(const TdomCMNode* newChild, const TdomCMNode* oldChild);
	virtual TdomCMNode* __fastcall removeChild(const TdomCMNode* oldChild);
	virtual TdomCMNode* __fastcall appendChild(const TdomCMNode* newChild);
	virtual bool __fastcall hasChildNodes(void);
	virtual TdomCMNode* __fastcall cloneNode(const bool deep);
	virtual bool __fastcall isAncestor(const TdomCMNode* ancestorNode);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property TdomCMNodeList* childNodes = {read=getChildNodes};
	__property WideString code = {read=getCode};
	__property TdomCMNode* firstChild = {read=getFirstChild};
	__property bool isReadonly = {read=FIsReadonly, nodefault};
	__property TdomCMNode* lastChild = {read=getLastChild};
	__property TdomCMNode* nextSibling = {read=getNextSibling};
	__property WideString nodeName = {read=getNodeName};
	__property TdomCMNodeType nodeType = {read=getCMNodeType, nodefault};
	__property WideString nodeValue = {read=getNodeValue, write=setNodeValue};
	__property TdomCustomCMObject* ownerCMObject = {read=getCMObject};
	__property TdomCMNode* parentNode = {read=getParentNode};
	__property TdomCMNode* previousSibling = {read=getPreviousSibling};
};


class DELPHICLASS TdomCMAttrDefinition;
class DELPHICLASS TdomCMAttrList;
class DELPHICLASS TdomCMChoiceParticle;
class DELPHICLASS TdomCMComment;
class DELPHICLASS TdomCMElementParticle;
class DELPHICLASS TdomCMElementTypeDeclaration;
class DELPHICLASS TdomCMEntityDeclaration;
class DELPHICLASS TdomCMFragment;
class DELPHICLASS TdomCMNameParticle;
class DELPHICLASS TdomCMNmtokenParticle;
class DELPHICLASS TdomCMNotationDeclaration;
class DELPHICLASS TdomCMParameterEntityDeclaration;
class DELPHICLASS TdomCMParameterEntityReference;
class DELPHICLASS TdomCMPcdataChoiceParticle;
class DELPHICLASS TdomCMProcessingInstruction;
class DELPHICLASS TdomCMSequenceParticle;
class PASCALIMPLEMENTATION TdomCustomCMObject : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	Classes::TList* FCreatedNodes;
	TDomImplementation* FDomImpl;
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual TdomCMNode* __fastcall duplicateCMNode(const TdomCMNode* node);
	
public:
	__fastcall TdomCustomCMObject(const TDomImplementation* aOwner);
	__fastcall virtual ~TdomCustomCMObject(void);
	virtual TdomCMAttrDefinition* __fastcall createCMAttributeDefinition(const WideString name, const WideString attType, const WideString defaultDecl, const WideString attValue);
	virtual TdomCMAttrList* __fastcall createCMAttributeList(const WideString name);
	virtual TdomCMChoiceParticle* __fastcall createCMChoiceParticle(const WideString freq);
	virtual TdomCMComment* __fastcall createCMComment(const WideString data);
	virtual TdomCMElementParticle* __fastcall createCMElementParticle(const WideString name, const WideString freq);
	virtual TdomCMElementTypeDeclaration* __fastcall createCMElementTypeDeclaration(const WideString name, const TdomContentspecType ContspecType);
	virtual TdomCMEntityDeclaration* __fastcall createCMEntityDeclaration(const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual TdomCMFragment* __fastcall createCMFragment(void);
	virtual TdomCMNameParticle* __fastcall createCMNameParticle(const WideString name);
	virtual TdomCMNmtokenParticle* __fastcall createCMNmtokenParticle(const WideString name);
	virtual TdomCMNotationDeclaration* __fastcall createCMNotationDeclaration(const WideString name, const WideString pubId, const WideString sysId);
	virtual TdomCMParameterEntityDeclaration* __fastcall createCMParameterEntityDeclaration(const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId);
	virtual TdomCMParameterEntityReference* __fastcall createCMParameterEntityReference(const WideString name);
	virtual TdomCMPcdataChoiceParticle* __fastcall createCMPcdataChoiceParticle(void);
	virtual TdomCMProcessingInstruction* __fastcall createCMProcessingInstruction(const WideString targ, const WideString data);
	virtual TdomCMSequenceParticle* __fastcall createCMSequenceParticle(const WideString freq);
	virtual void __fastcall freeAllCMNodes(TdomCMNode* &CMNode);
	__property TDomImplementation* domImplementation = {read=FDomImpl};
};



class PASCALIMPLEMENTATION TdomCMComment : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	virtual WideString __fastcall getData();
	virtual void __fastcall setData(const WideString value);
	virtual int __fastcall getLength(void);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMComment(const TdomCustomCMObject* aOwner);
	virtual WideString __fastcall substringData(const int offset, const int count);
	virtual void __fastcall appendData(const WideString arg);
	virtual void __fastcall insertData(const int offset, const WideString arg);
	virtual void __fastcall deleteData(const int offset, const int count);
	virtual void __fastcall replaceData(const int offset, const int count, const WideString arg);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property WideString data = {read=getData, write=setData};
	__property int length = {read=getLength, nodefault};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMComment(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMProcessingInstruction : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	virtual WideString __fastcall getTarget();
	virtual WideString __fastcall getData();
	virtual void __fastcall setData(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMProcessingInstruction(const TdomCustomCMObject* aOwner, const WideString targ);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property WideString target = {read=getTarget};
	__property WideString data = {read=getData, write=setData};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMProcessingInstruction(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCMNotation;
class DELPHICLASS TdomCMParameterEntity;
class PASCALIMPLEMENTATION TdomCMObject : public TdomCustomCMObject 
{
	typedef TdomCustomCMObject inherited;
	
private:
	TdomDocument* FAssociatedDocument;
	TdomNamedCMAttributeMap* FAttributesList;
	TdomCMExternalObject* FCMExternal;
	TdomCMInternalObject* FCMInternal;
	TdomNamedCMEntityMap* FEntitiesList;
	TdomNamedCMNodeMap* FParameterEntitiesList;
	Classes::TList* FParameterEntitiesListing;
	TdomNamedCMNodeMap* FNotationsList;
	Classes::TList* FNotationsListing;
	TdomNamedCMNodeMap* FElementTypesList;
	Classes::TList* FElementTypesListing;
	void __fastcall clearAttributes(void);
	void __fastcall clearElementTypes(void);
	void __fastcall clearEntities(void);
	void __fastcall clearNotations(void);
	void __fastcall clearParameterEntities(void);
	
protected:
	virtual void __fastcall prepareCM(const TdomCustomErrorHandler* errorHandler);
	virtual TdomCMNode* __fastcall duplicateCMNode(const TdomCMNode* node);
	virtual TdomCMAttribute* __fastcall createCMAttribute(const WideString elementName, const WideString attributeName, const WideString attType, const WideString defaultDecl, const WideString attValue);
	virtual TdomCMEntity* __fastcall createCMEntity(const WideString name, const WideString literalValue, const WideString pubId, const WideString sysId, const WideString versionNumber, const WideString notaName);
	virtual TdomCMNotation* __fastcall createCMNotation(const WideString name, const WideString pubId, const WideString sysId);
	TdomCMParameterEntity* __fastcall createCMParameterEntity(const WideString name, const WideString value, const WideString pubId, const WideString sysId, const WideString versionNumber);
	virtual bool __fastcall setPredefinedEntities(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMObject(const TDomImplementation* aOwner);
	__fastcall virtual ~TdomCMObject(void);
	virtual void __fastcall clear(void);
	virtual void __fastcall prepare(void);
	virtual TdomCMExternalObject* __fastcall removeExternalCM(void);
	virtual TdomCMInternalObject* __fastcall removeInternalCM(void);
	virtual TdomCMExternalObject* __fastcall setExternalCM(const TdomCMExternalObject* arg);
	virtual TdomCMInternalObject* __fastcall setInternalCM(const TdomCMInternalObject* arg);
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	__property TdomDocument* associatedDocument = {read=FAssociatedDocument};
	__property TdomNamedCMAttributeMap* attributes = {read=FAttributesList};
	__property TdomNamedCMNodeMap* elementTypes = {read=FElementTypesList};
	__property TdomNamedCMEntityMap* entities = {read=FEntitiesList};
	__property TdomNamedCMNodeMap* notations = {read=FNotationsList};
	__property TdomNamedCMNodeMap* parameterEntities = {read=FParameterEntitiesList};
	__property TdomCMExternalObject* externalCM = {read=FCMExternal};
	__property TdomCMInternalObject* internalCM = {read=FCMInternal};
};


class DELPHICLASS TdomCustomCMIEObject;
class PASCALIMPLEMENTATION TdomCustomCMIEObject : public TdomCustomCMObject 
{
	typedef TdomCustomCMObject inherited;
	
protected:
	TdomCMObject* FAssociatedContentModel;
	WideString FPublicId;
	WideString FSystemId;
	TdomNameValueList* FParameterEntitiesList;
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall TdomCustomCMIEObject(const TDomImplementation* aOwner, const WideString pubId, const WideString sysId);
	__fastcall virtual ~TdomCustomCMIEObject(void);
	__property TdomCMObject* associatedContentModel = {read=FAssociatedContentModel};
	__property WideString publicId = {read=FPublicId};
	__property WideString systemId = {read=FSystemId};
};


class PASCALIMPLEMENTATION TdomCMInternalObject : public TdomCustomCMIEObject 
{
	typedef TdomCustomCMIEObject inherited;
	
public:
	__fastcall TdomCMInternalObject(const TDomImplementation* aOwner, const WideString pubId, const WideString sysId);
public:
	#pragma option push -w-inl
	/* TdomCustomCMIEObject.destroy */ inline __fastcall virtual ~TdomCMInternalObject(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMExternalObject : public TdomCustomCMIEObject 
{
	typedef TdomCustomCMIEObject inherited;
	
protected:
	WideString FEncoding;
	WideString FVersion;
	
public:
	__fastcall TdomCMExternalObject(const TDomImplementation* aOwner, const WideString pubId, const WideString sysId);
	__property WideString encoding = {read=FEncoding, write=FEncoding};
	__property WideString version = {read=FVersion, write=FVersion};
public:
	#pragma option push -w-inl
	/* TdomCustomCMIEObject.destroy */ inline __fastcall virtual ~TdomCMExternalObject(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMNotationDeclaration : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FPublicId;
	WideString FSystemId;
	virtual WideString __fastcall getPublicId();
	virtual WideString __fastcall getSystemId();
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMNotationDeclaration(const TdomCustomCMObject* aOwner, const WideString name, const WideString pubId, const WideString sysId);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property WideString publicId = {read=getPublicId};
	__property WideString systemId = {read=getSystemId};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMNotationDeclaration(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMElementTypeDeclaration : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	TdomContentspecType FContentspec;
	virtual WideString __fastcall getContentspec();
	virtual TdomContentspecType __fastcall getContentspecType(void);
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	virtual void __fastcall writeContentspec(Classes::TStream* stream);
	
public:
	__fastcall virtual TdomCMElementTypeDeclaration(const TdomCustomCMObject* aOwner, const WideString name, const TdomContentspecType contspecType);
	virtual TdomCMNode* __fastcall appendChild(const TdomCMNode* newChild);
	virtual TdomCMNode* __fastcall insertBefore(const TdomCMNode* newChild, const TdomCMNode* refChild);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property WideString contentspec = {read=getContentspec};
	__property TdomContentspecType contentspecType = {read=getContentspecType, nodefault};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMElementTypeDeclaration(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMAttrList : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMAttrList(const TdomCustomCMObject* aOwner, const WideString name);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMAttrList(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMAttrDefinition : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FAttributeType;
	WideString FDefaultDeclaration;
	TdomCMAttrList* FParentAttributeList;
	virtual WideString __fastcall getAttributeType();
	virtual WideString __fastcall getDefaultDeclaration();
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMAttrDefinition(const TdomCustomCMObject* aOwner, const WideString name, const WideString attType, const WideString defaultDecl, const WideString attValue);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property WideString attributeType = {read=getAttributeType};
	__property WideString defaultDeclaration = {read=getDefaultDeclaration};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMAttrDefinition(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCMParticle;
class PASCALIMPLEMENTATION TdomCMParticle : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FFrequency;
	virtual bool __fastcall contentModelTest2(const Classes::TStringList* source, const Classes::TStringList* rest, const WideString freq);
	virtual bool __fastcall contentModelTest(const Classes::TStringList* source, const Classes::TStringList* rest);
	virtual WideString __fastcall getFrequency();
	virtual void __fastcall setFrequency(const WideString freq);
	virtual void __fastcall setNodeValue(const WideString value);
	
public:
	__fastcall TdomCMParticle(const TdomCustomCMObject* aOwner, const WideString freq);
	__property WideString frequency = {read=getFrequency};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMSequenceParticle : public TdomCMParticle 
{
	typedef TdomCMParticle inherited;
	
private:
	virtual bool __fastcall contentModelTest2(const Classes::TStringList* source, const Classes::TStringList* rest, const WideString freq);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMSequenceParticle(const TdomCustomCMObject* aOwner, const WideString freq);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMSequenceParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMChoiceParticle : public TdomCMParticle 
{
	typedef TdomCMParticle inherited;
	
private:
	virtual bool __fastcall contentModelTest2(const Classes::TStringList* source, const Classes::TStringList* rest, const WideString freq);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMChoiceParticle(const TdomCustomCMObject* aOwner, const WideString freq);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMChoiceParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMPcdataChoiceParticle : public TdomCMParticle 
{
	typedef TdomCMParticle inherited;
	
private:
	virtual bool __fastcall contentModelTest(const Classes::TStringList* source, const Classes::TStringList* rest);
	virtual void __fastcall setFrequency(const WideString freq);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMPcdataChoiceParticle(const TdomCustomCMObject* aOwner, const WideString freq);
	bool __fastcall elementDefined(const WideString elementName);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMPcdataChoiceParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMElementParticle : public TdomCMParticle 
{
	typedef TdomCMParticle inherited;
	
private:
	virtual bool __fastcall contentModelTest2(const Classes::TStringList* source, const Classes::TStringList* rest, const WideString freq);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMElementParticle(const TdomCustomCMObject* aOwner, const WideString name, const WideString freq);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMElementParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMNameParticle : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMNameParticle(const TdomCustomCMObject* aOwner, const WideString name);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMNameParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMNmtokenParticle : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMNmtokenParticle(const TdomCustomCMObject* aOwner, const WideString name);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMNmtokenParticle(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMAttribute : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FAttributeName;
	WideString FAttributeType;
	WideString FDefaultDeclaration;
	WideString FElementName;
	virtual void __fastcall setNodeValue(const WideString value);
	
public:
	__fastcall virtual TdomCMAttribute(const TdomCustomCMObject* aOwner, const WideString elementName, const WideString attributeName, const WideString attType, const WideString defaultDecl, const WideString attValue);
	__property WideString attributeName = {read=FAttributeName};
	__property WideString attributeType = {read=FAttributeType};
	__property WideString defaultDeclaration = {read=FDefaultDeclaration};
	__property WideString elementName = {read=FElementName};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMAttribute(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMNotation : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FPublicId;
	WideString FSystemId;
	
public:
	__fastcall virtual TdomCMNotation(const TdomCustomCMObject* aOwner, const WideString name, const WideString pubId, const WideString sysId);
	__property WideString publicId = {read=FPublicId};
	__property WideString systemId = {read=FSystemId};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMNotation(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMEntity : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FEncoding;
	bool FIsInternalEntity;
	bool FIsParsedEntity;
	bool FIsUnusable;
	WideString FLiteralValue;
	WideString FNotationName;
	WideString FPublicId;
	WideString FReplacementText;
	WideString FSystemId;
	WideString FVersion;
	virtual WideString __fastcall calculateReplacementText(WideString S);
	virtual bool __fastcall getIsUnusable(void);
	virtual WideString __fastcall getNormalizedValue();
	virtual WideString __fastcall getResolvedValue();
	bool __fastcall refersToXyz(const bool allowUnresolvableEntities, const Classes::TStringList* previousEntities, const int whatToTest);
	virtual void __fastcall setIsUnusable(const bool value);
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall refersToExternalEntity(const bool allowUnresolvableEntities);
	virtual bool __fastcall refersToUnparsedEntity(const bool allowUnresolvableEntities);
	virtual bool __fastcall refersToUnusableEntity(const bool allowUnresolvableEntities);
	virtual void __fastcall testForCircularReference(const bool allowUnresolvableEntities);
	
public:
	__fastcall virtual TdomCMEntity(const TdomCustomCMObject* aOwner, const WideString name, const WideString literalValue, const WideString pubId, const WideString sysId, const WideString versionNumber, const WideString notaName);
	__property WideString encoding = {read=FEncoding, write=FEncoding};
	__property bool isInternalEntity = {read=FIsInternalEntity, nodefault};
	__property bool isParsedEntity = {read=FIsParsedEntity, nodefault};
	__property bool isUnusable = {read=getIsUnusable, write=setIsUnusable, default=0};
	__property WideString literalValue = {read=FLiteralValue};
	__property WideString normalizedValue = {read=getNormalizedValue};
	__property WideString notationName = {read=FNotationName};
	__property WideString publicId = {read=FPublicId};
	__property WideString replacementText = {read=FReplacementText};
	__property WideString resolvedValue = {read=getResolvedValue};
	__property WideString systemId = {read=FSystemId};
	__property WideString version = {read=FVersion};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMEntity(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMParameterEntity : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FEncoding;
	bool FIsInternalEntity;
	bool FIsUnusable;
	WideString FPublicId;
	WideString FSystemId;
	WideString FVersion;
	
protected:
	virtual bool __fastcall getIsUnusable(void);
	virtual void __fastcall setIsUnusable(const bool value);
	
public:
	__fastcall virtual TdomCMParameterEntity(const TdomCustomCMObject* aOwner, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId, const WideString versionNumber);
	__property WideString encoding = {read=FEncoding, write=FEncoding};
	__property bool isInternalEntity = {read=FIsInternalEntity, nodefault};
	__property bool isUnusable = {read=getIsUnusable, default=0};
	__property WideString publicId = {read=FPublicId};
	__property WideString systemId = {read=FSystemId};
	__property WideString version = {read=FVersion};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMParameterEntity(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCustomCMEntDecl;
class PASCALIMPLEMENTATION TdomCustomCMEntDecl : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	WideString FPublicId;
	WideString FSystemId;
	bool FIsInternalEntity;
	virtual bool __fastcall getIsInternalEntity(void);
	virtual WideString __fastcall getPublicId();
	virtual WideString __fastcall getSystemId();
	
public:
	__fastcall TdomCustomCMEntDecl(const TdomCustomCMObject* aOwner, const WideString name, const WideString pubId, const WideString sysId);
	virtual TdomCMNode* __fastcall insertBefore(const TdomCMNode* newChild, const TdomCMNode* refChild);
	virtual TdomCMNode* __fastcall replaceChild(const TdomCMNode* newChild, const TdomCMNode* oldChild);
	virtual TdomCMNode* __fastcall appendChild(const TdomCMNode* newChild);
	__property WideString publicId = {read=getPublicId};
	__property WideString systemId = {read=getSystemId};
	__property bool isInternalEntity = {read=getIsInternalEntity, nodefault};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCustomCMEntDecl(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMEntityDeclaration : public TdomCustomCMEntDecl 
{
	typedef TdomCustomCMEntDecl inherited;
	
private:
	bool FIsParsedEntity;
	WideString FNotationName;
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMEntityDeclaration(const TdomCustomCMObject* aOwner, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual void __fastcall writeCode(Classes::TStream* stream);
	__property bool isParsedEntity = {read=FIsParsedEntity, nodefault};
	__property WideString notationName = {read=FNotationName};
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMEntityDeclaration(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMParameterEntityDeclaration : public TdomCustomCMEntDecl 
{
	typedef TdomCustomCMEntDecl inherited;
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMParameterEntityDeclaration(const TdomCustomCMObject* aOwner, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMParameterEntityDeclaration(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMParameterEntityReference : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	virtual void __fastcall setNodeValue(const WideString value);
	
protected:
	virtual bool __fastcall validate(const TdomCustomErrorHandler* errorHandler);
	
public:
	__fastcall virtual TdomCMParameterEntityReference(const TdomCustomCMObject* aOwner, const WideString name);
	virtual void __fastcall writeCode(Classes::TStream* stream);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMParameterEntityReference(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCMFragment : public TdomCMNode 
{
	typedef TdomCMNode inherited;
	
private:
	virtual void __fastcall setNodeValue(const WideString value);
	
public:
	__fastcall virtual TdomCMFragment(const TdomCustomCMObject* aOwner);
public:
	#pragma option push -w-inl
	/* TdomCMNode.destroy */ inline __fastcall virtual ~TdomCMFragment(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStyleSheet;
class DELPHICLASS TdomMediaList;
class PASCALIMPLEMENTATION TdomStyleSheet : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	virtual WideString __fastcall getStyleSheetType(void) = 0 ;
	virtual bool __fastcall getDisabled(void) = 0 ;
	virtual void __fastcall setDisabled(const bool value) = 0 ;
	virtual TdomNode* __fastcall getOwnerNode(void) = 0 ;
	virtual TdomStyleSheet* __fastcall getParentStyleSheet(void) = 0 ;
	virtual WideString __fastcall getHref(void) = 0 ;
	virtual WideString __fastcall getTitle(void) = 0 ;
	virtual TdomMediaList* __fastcall getMedia(void) = 0 ;
	
public:
	__property WideString styleSheetType = {read=getStyleSheetType};
	__property bool disabled = {read=getDisabled, write=setDisabled, nodefault};
	__property TdomNode* ownerNode = {read=getOwnerNode};
	__property TdomStyleSheet* parentStyleSheet = {read=getParentStyleSheet};
	__property WideString href = {read=getHref};
	__property WideString title = {read=getTitle};
	__property TdomMediaList* media = {read=getMedia};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomStyleSheet(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStyleSheet(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomMediaList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	virtual WideString __fastcall getCssText(void) = 0 ;
	virtual void __fastcall setCssText(const WideString value) = 0 ;
	virtual int __fastcall getLength(void) = 0 ;
	
public:
	virtual TdomStyleSheet* __fastcall item(const int index) = 0 ;
	virtual void __fastcall Delete(const WideString oldMedium) = 0 ;
	virtual void __fastcall append(const WideString newMedium) = 0 ;
	__property int length = {read=getLength, nodefault};
	__property WideString cssText = {read=getCssText, write=setCssText};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomMediaList(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomMediaList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStyleSheetList;
class PASCALIMPLEMENTATION TdomStyleSheetList : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	virtual int __fastcall getLength(void) = 0 ;
	
public:
	virtual TdomStyleSheet* __fastcall item(const int index) = 0 ;
	__property int length = {read=getLength, nodefault};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomStyleSheetList(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStyleSheetList(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomDocumentStyle;
class PASCALIMPLEMENTATION TdomDocumentStyle : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	virtual TdomStyleSheetList* __fastcall getStyleSheets(void) = 0 ;
	
public:
	__property TdomStyleSheetList* styleSheets = {read=getStyleSheets};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomDocumentStyle(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomDocumentStyle(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlSourceCode;
class DELPHICLASS TXmlSourceCodePiece;
class PASCALIMPLEMENTATION TXmlSourceCode : public Classes::TList 
{
	typedef Classes::TList inherited;
	
private:
	virtual void __fastcall calculatePieceOffset(const int startItem);
	virtual WideString __fastcall getNameOfFirstTag();
	
public:
	HIDESBASE int __fastcall add(void * Item);
	virtual void __fastcall clear(void);
	virtual void __fastcall clearAndFree(void);
	HIDESBASE void __fastcall Delete(int index);
	HIDESBASE void __fastcall exchange(int index1, int index2);
	TXmlSourceCodePiece* __fastcall getPieceAtPos(int pos);
	HIDESBASE void __fastcall insert(int index, void * item);
	HIDESBASE void __fastcall move(int curIndex, int newIndex);
	HIDESBASE void __fastcall pack(void);
	HIDESBASE int __fastcall remove(void * Item);
	HIDESBASE void __fastcall sort(Classes::TListSortCompare Compare);
	__property WideString nameOfFirstTag = {read=getNameOfFirstTag};
public:
	#pragma option push -w-inl
	/* TList.Destroy */ inline __fastcall virtual ~TXmlSourceCode(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXmlSourceCode(void) : Classes::TList() { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXmlSourceCodePiece : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomPieceType FPieceType;
	WideString FText;
	int FOffset;
	TXmlSourceCode* FOwner;
	
public:
	__fastcall virtual TXmlSourceCodePiece(const TdomPieceType pt);
	__property TdomPieceType pieceType = {read=FPieceType, nodefault};
	__property WideString text = {read=FText, write=FText};
	__property int offset = {read=FOffset, nodefault};
	__property TXmlSourceCode* ownerSourceCode = {read=FOwner};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXmlSourceCodePiece(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TXmlParserLanguage { iso639_de, iso639_en, iso639_es, iso639_fr, iso639_it, iso639_nl, iso639_pl };
#pragma option pop

class DELPHICLASS TXmlMemoryStream;
class PASCALIMPLEMENTATION TXmlMemoryStream : public Classes::TMemoryStream 
{
	typedef Classes::TMemoryStream inherited;
	
public:
	HIDESBASE void __fastcall setPointer(void * Ptr, int Size);
public:
	#pragma option push -w-inl
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TXmlMemoryStream(void) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TXmlMemoryStream(void) : Classes::TMemoryStream() { }
	#pragma option pop
	
};


class DELPHICLASS TXmlInputSource;
class DELPHICLASS TdomStandardLocator;
class PASCALIMPLEMENTATION TdomStandardLocator : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	int FColumnNumber;
	TXmlInputSource* FInputSource;
	int FStartColumnNumber;
	int FStartLineNumber;
	bool FLastWCharWasLF;
	int FLineNumber;
	bool FPieceEndSet;
	virtual WideString __fastcall getPublicId();
	virtual WideString __fastcall getSystemId();
	virtual void __fastcall evaluate(const wchar_t s);
	
public:
	__fastcall virtual TdomStandardLocator(const TXmlInputSource* inputSource);
	virtual void __fastcall pieceEnd(void);
	virtual void __fastcall pieceStart(void);
	virtual void __fastcall reset(void);
	__property int columnNumber = {read=FColumnNumber, nodefault};
	__property int lineNumber = {read=FLineNumber, nodefault};
	__property WideString publicId = {read=getPublicId};
	__property int startColumnNumber = {read=FStartColumnNumber, nodefault};
	__property int startLineNumber = {read=FStartLineNumber, nodefault};
	__property WideString systemId = {read=getSystemId};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardLocator(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXmlInputSource : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	Classes::TStream* FStream;
	TdomEncodingType FEncoding;
	int FLastUcs4;
	bool FLastCharWasCR;
	TdomStandardLocator* FLocator;
	WideString FPublicId;
	WideString FSystemId;
	WideString FRootName;
	
protected:
	virtual TdomEncodingType __fastcall getEncodingType(void);
	virtual WideString __fastcall getRootName();
	virtual WideString __fastcall getStreamAsWideString();
	virtual void __fastcall skipTextDecl(const TdomStandardLocator* locator);
	virtual bool __fastcall getNextWideChar2(wchar_t &dest, const TdomStandardLocator* locator);
	virtual void __fastcall reset2(const TdomStandardLocator* locator);
	
public:
	__fastcall virtual TXmlInputSource(const Classes::TStream* stream, const WideString publicId, const WideString systemId);
	__fastcall virtual ~TXmlInputSource(void);
	virtual bool __fastcall getNextWideChar(wchar_t &dest);
	virtual void __fastcall reset(void);
	__property TdomEncodingType encoding = {read=FEncoding, nodefault};
	__property TdomStandardLocator* locator = {read=FLocator};
	__property WideString publicId = {read=FPublicId};
	__property WideString rootName = {read=FRootName};
	__property Classes::TStream* stream = {read=FStream};
	__property WideString streamAsWideString = {read=getStreamAsWideString};
	__property WideString systemId = {read=FSystemId};
};


#pragma option push -b-
enum TXmlErrorType { xetFatalError, xetError, xetWarning };
#pragma option pop

class DELPHICLASS TXmlParserError;
class PASCALIMPLEMENTATION TXmlParserError : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	WideString FCode;
	int FEndColumn;
	int FEndLine;
	AnsiString FErrorClass;
	TXmlErrorType FErrorType;
	WideString FPubId;
	int FStartColumn;
	int FStartLine;
	WideString FSysId;
	
protected:
	WideString __fastcall getDutchErrorStr();
	WideString __fastcall getEnglishErrorStr();
	WideString __fastcall getFrenchErrorStr();
	WideString __fastcall getGermanErrorStr();
	WideString __fastcall getItalianErrorStr();
	WideString __fastcall getPolishErrorStr();
	WideString __fastcall getSpanishErrorStr();
	
public:
	__fastcall virtual TXmlParserError(const EParserException* e, const int startLine, const int startColumn, const int endLine, const int endColumn, const WideString pubId, const WideString sysId, const WideString code);
	virtual WideString __fastcall getErrorStr(const TXmlParserLanguage lang);
	__property WideString code = {read=FCode};
	__property int endColumn = {read=FEndColumn, nodefault};
	__property int endLine = {read=FEndLine, nodefault};
	__property AnsiString errorClass = {read=FErrorClass};
	__property TXmlErrorType errorType = {read=FErrorType, nodefault};
	__property WideString publicId = {read=FPubId};
	__property int startColumn = {read=FStartColumn, nodefault};
	__property int startLine = {read=FStartLine, nodefault};
	__property WideString systemId = {read=FSysId};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TXmlParserError(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlCustomProcessorAgent;
class PASCALIMPLEMENTATION TXmlCustomProcessorAgent : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlCustomProcessorAgent(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlCustomProcessorAgent(void) { }
	#pragma option pop
	
};


typedef void __fastcall (__closure *TXmlProcessorErrorEvent)(TXmlCustomProcessorAgent* processorAgent, TXmlParserError* e);

typedef void __fastcall (__closure *TXmlProcessorEvent1)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator);

typedef void __fastcall (__closure *TXmlProcessorEvent2)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &data);

typedef void __fastcall (__closure *TXmlProcessorEvent3)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &targ, WideString &data);

typedef void __fastcall (__closure *TXmlProcessorEvent4)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &namespaceURI, WideString &tagName);

typedef void __fastcall (__closure *TXmlProcessorEvent5)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &namespaceURI, WideString &tagName, TdomNameValueList* attributes);

typedef void __fastcall (__closure *TXmlProcessorEvent6)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &name, WideString &pubId, WideString &sysId, WideString &data);

typedef void __fastcall (__closure *TXmlProcessorEvent7)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &prefix, WideString &uri);

typedef void __fastcall (__closure *TXmlProcessorEvent8)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &version, WideString &encDl, WideString &sdDl);

typedef void __fastcall (__closure *TXmlProcessorEvent9)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &name, WideString &attType, WideString &bracket, WideString &defaultDecl, WideString &attValue);

typedef void __fastcall (__closure *TXmlProcessorEvent10)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &includeStmt, WideString &data);

typedef void __fastcall (__closure *TXmlProcessorEvent11)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &name, WideString &data);

typedef void __fastcall (__closure *TXmlProcessorEvent12)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &name, WideString &entityValue, WideString &pubId, WideString &sysId, WideString &notaName);

typedef void __fastcall (__closure *TXmlProcessorEvent13)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &name, WideString &pubId, WideString &sysId);

typedef void __fastcall (__closure *TXmlProcessorEvent14)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &name, WideString &entityValue, WideString &pubId, WideString &sysId);

typedef void __fastcall (__closure *TXmlProcessorEvent15)(TXmlCustomProcessorAgent* processorAgent, WideString &pubId, WideString &sysId);

typedef void __fastcall (__closure *TXmlProcessorEvent16)(TXmlCustomProcessorAgent* processorAgent, TdomStandardLocator* locator, WideString &version, WideString &encDl);

class DELPHICLASS TXmlStandardProcessorAgent;
class DELPHICLASS TXmlStandardDocReader;
class DELPHICLASS TXmlCustomReader;
class DELPHICLASS TXmlStandardHandler;
class DELPHICLASS TXmlCustomHandler;
class PASCALIMPLEMENTATION TXmlCustomHandler : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	TXmlProcessorErrorEvent FOnError;
	TXmlProcessorErrorEvent FOnFatalError;
	TXmlProcessorErrorEvent FOnWarning;
	TXmlProcessorEvent2 FOnComment;
	TXmlProcessorEvent2 FOnCDATA;
	TXmlProcessorEvent2 FOnCharRef;
	TXmlProcessorEvent6 FOnDoctype;
	TXmlProcessorEvent1 FOnEndDocument;
	TXmlProcessorEvent4 FOnEndElement;
	TXmlProcessorEvent2 FOnEndPrefixMapping;
	TXmlProcessorEvent2 FOnEntityRef;
	TXmlProcessorEvent2 FOnPCDATA;
	TXmlProcessorEvent3 FOnProcessingInstruction;
	TXmlProcessorEvent2 FOnSkippedEntity;
	TXmlProcessorEvent2 FOnStartDocument;
	TXmlProcessorEvent5 FOnStartElement;
	TXmlProcessorEvent7 FOnStartPrefixMapping;
	TXmlProcessorEvent8 FOnXmlDeclaration;
	TXmlProcessorEvent9 FOnAttributeDefinition;
	TXmlProcessorEvent10 FOnConditionalSection;
	TXmlProcessorEvent2 FOnDtdComment;
	TXmlProcessorEvent3 FOnDtdProcessingInstruction;
	TXmlProcessorEvent11 FOnElementTypeDeclaration;
	TXmlProcessorEvent1 FOnEndAttListDeclaration;
	TXmlProcessorEvent1 FOnEndDtd;
	TXmlProcessorEvent12 FOnEntityDeclaration;
	TXmlProcessorEvent13 FOnNotationDeclaration;
	TXmlProcessorEvent14 FOnParameterEntityDeclaration;
	TXmlProcessorEvent2 FOnParameterEntityRef;
	TXmlProcessorEvent2 FOnStartAttListDeclaration;
	TXmlProcessorEvent15 FOnStartDtd;
	TXmlProcessorEvent16 FOnTextDeclaration;
	virtual void __fastcall sendErrorNotification(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	virtual void __fastcall error(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	virtual void __fastcall fatalError(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	virtual void __fastcall warning(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	
public:
	virtual TXmlParserError* __fastcall CDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall charRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall comment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall doctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall endDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator) = 0 ;
	virtual TXmlParserError* __fastcall endElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName) = 0 ;
	virtual TXmlParserError* __fastcall endPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix) = 0 ;
	virtual TXmlParserError* __fastcall entityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name) = 0 ;
	virtual TXmlParserError* __fastcall PCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall processingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall skippedEntity(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name) = 0 ;
	virtual TXmlParserError* __fastcall startDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString defaultRoot) = 0 ;
	virtual TXmlParserError* __fastcall startElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName, TdomNameValueList* attributes) = 0 ;
	virtual TXmlParserError* __fastcall startPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri) = 0 ;
	virtual TXmlParserError* __fastcall xmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl, WideString sdDl) = 0 ;
	virtual TXmlParserError* __fastcall attributeDefinition(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString attType, WideString bracket, WideString defaultDecl, WideString attValue) = 0 ;
	virtual TXmlParserError* __fastcall conditionalSection(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString includeStmt, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall DTDcomment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall DTDprocessingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall elementTypeDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString data) = 0 ;
	virtual TXmlParserError* __fastcall endAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator) = 0 ;
	virtual TXmlParserError* __fastcall endDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator) = 0 ;
	virtual TXmlParserError* __fastcall entityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId, WideString notaName) = 0 ;
	virtual TXmlParserError* __fastcall notationDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId) = 0 ;
	virtual TXmlParserError* __fastcall parameterEntityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId) = 0 ;
	virtual TXmlParserError* __fastcall parameterEntityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name) = 0 ;
	virtual TXmlParserError* __fastcall startAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name) = 0 ;
	virtual TXmlParserError* __fastcall startDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString pubId, WideString sysId) = 0 ;
	virtual TXmlParserError* __fastcall textDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl) = 0 ;
	
__published:
	__property TXmlProcessorEvent9 OnAttributeDefinition = {read=FOnAttributeDefinition, write=FOnAttributeDefinition};
	__property TXmlProcessorEvent2 OnCDATA = {read=FOnCDATA, write=FOnCDATA};
	__property TXmlProcessorEvent2 OnCharRef = {read=FOnCharRef, write=FOnCharRef};
	__property TXmlProcessorEvent2 OnComment = {read=FOnComment, write=FOnComment};
	__property TXmlProcessorEvent10 OnConditionalSection = {read=FOnConditionalSection, write=FOnConditionalSection};
	__property TXmlProcessorEvent6 OnDoctype = {read=FOnDoctype, write=FOnDoctype};
	__property TXmlProcessorEvent2 OnDtdComment = {read=FOnDtdComment, write=FOnDtdComment};
	__property TXmlProcessorEvent3 OnDtdProcessingInstruction = {read=FOnDtdProcessingInstruction, write=FOnDtdProcessingInstruction};
	__property TXmlProcessorEvent11 OnElementTypeDeclaration = {read=FOnElementTypeDeclaration, write=FOnElementTypeDeclaration};
	__property TXmlProcessorEvent1 OnEndAttListDeclaration = {read=FOnEndAttListDeclaration, write=FOnEndAttListDeclaration};
	__property TXmlProcessorEvent1 OnEndDtd = {read=FOnEndDtd, write=FOnEndDtd};
	__property TXmlProcessorEvent1 OnEndDocument = {read=FOnEndDocument, write=FOnEndDocument};
	__property TXmlProcessorEvent4 OnEndElement = {read=FOnEndElement, write=FOnEndElement};
	__property TXmlProcessorEvent2 OnEndPrefixMapping = {read=FOnEndPrefixMapping, write=FOnEndPrefixMapping};
	__property TXmlProcessorEvent12 OnEntityDeclaration = {read=FOnEntityDeclaration, write=FOnEntityDeclaration};
	__property TXmlProcessorEvent2 OnEntityRef = {read=FOnEntityRef, write=FOnEntityRef};
	__property TXmlProcessorErrorEvent OnError = {read=FOnError, write=FOnError};
	__property TXmlProcessorErrorEvent OnFatalError = {read=FOnFatalError, write=FOnFatalError};
	__property TXmlProcessorEvent13 OnNotationDeclaration = {read=FOnNotationDeclaration, write=FOnNotationDeclaration};
	__property TXmlProcessorEvent14 OnParameterEntityDeclaration = {read=FOnParameterEntityDeclaration, write=FOnParameterEntityDeclaration};
	__property TXmlProcessorEvent2 OnParameterEntityRef = {read=FOnParameterEntityRef, write=FOnParameterEntityRef};
	__property TXmlProcessorEvent2 OnPCDATA = {read=FOnPCDATA, write=FOnPCDATA};
	__property TXmlProcessorEvent3 OnProcessingInstruction = {read=FOnProcessingInstruction, write=FOnProcessingInstruction};
	__property TXmlProcessorEvent2 OnSkippedEntity = {read=FOnSkippedEntity, write=FOnSkippedEntity};
	__property TXmlProcessorEvent2 OnStartAttListDeclaration = {read=FOnStartAttListDeclaration, write=FOnStartAttListDeclaration};
	__property TXmlProcessorEvent2 OnStartDocument = {read=FOnStartDocument, write=FOnStartDocument};
	__property TXmlProcessorEvent15 OnStartDtd = {read=FOnStartDtd, write=FOnStartDtd};
	__property TXmlProcessorEvent5 OnStartElement = {read=FOnStartElement, write=FOnStartElement};
	__property TXmlProcessorEvent7 OnStartPrefixMapping = {read=FOnStartPrefixMapping, write=FOnStartPrefixMapping};
	__property TXmlProcessorEvent16 OnTextDeclaration = {read=FOnTextDeclaration, write=FOnTextDeclaration};
	__property TXmlProcessorErrorEvent OnWarning = {read=FOnWarning, write=FOnWarning};
	__property TXmlProcessorEvent8 OnXmlDeclaration = {read=FOnXmlDeclaration, write=FOnXmlDeclaration};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlCustomHandler(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlCustomHandler(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXmlStandardHandler : public TXmlCustomHandler 
{
	typedef TXmlCustomHandler inherited;
	
protected:
	TXmlCustomHandler* FNextHandler;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual TXmlParserError* __fastcall CDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall charRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall comment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall doctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId, WideString data);
	virtual TXmlParserError* __fastcall endDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName);
	virtual TXmlParserError* __fastcall endPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix);
	virtual TXmlParserError* __fastcall entityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall PCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall processingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall skippedEntity(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual TXmlParserError* __fastcall startElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName, TdomNameValueList* attributes);
	virtual TXmlParserError* __fastcall startPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri);
	virtual TXmlParserError* __fastcall xmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl, WideString sdDl);
	virtual TXmlParserError* __fastcall attributeDefinition(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString attType, WideString bracket, WideString defaultDecl, WideString attValue);
	virtual TXmlParserError* __fastcall conditionalSection(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString includeStmt, WideString data);
	virtual TXmlParserError* __fastcall DTDcomment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall DTDprocessingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall elementTypeDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString data);
	virtual TXmlParserError* __fastcall endAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall entityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId, WideString notaName);
	virtual TXmlParserError* __fastcall notationDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall parameterEntityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall parameterEntityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall textDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl);
	
__published:
	__property TXmlCustomHandler* NextHandler = {read=FNextHandler, write=FNextHandler};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlStandardHandler(Classes::TComponent* AOwner) : TXmlCustomHandler(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlStandardHandler(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXmlCustomReader : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
protected:
	TXmlStandardHandler* FNextHandler;
	TXmlProcessorErrorEvent FOnError;
	TXmlProcessorErrorEvent FOnFatalError;
	TXmlProcessorErrorEvent FOnWarning;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall sendErrorNotification(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	virtual TXmlParserError* __fastcall parserErrorFactory(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	virtual void __fastcall error(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	virtual void __fastcall fatalError(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	virtual void __fastcall warning(const TXmlCustomProcessorAgent* sender, TXmlParserError* &e);
	
__published:
	__property TXmlStandardHandler* NextHandler = {read=FNextHandler, write=FNextHandler};
	__property TXmlProcessorErrorEvent OnError = {read=FOnError, write=FOnError};
	__property TXmlProcessorErrorEvent OnFatalError = {read=FOnFatalError, write=FOnFatalError};
	__property TXmlProcessorErrorEvent OnWarning = {read=FOnWarning, write=FOnWarning};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlCustomReader(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlCustomReader(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXmlStandardDocReader : public TXmlCustomReader 
{
	typedef TXmlCustomReader inherited;
	
protected:
	virtual TXmlParserError* __fastcall writeXmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeProcessingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeComment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writePCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeStartElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeEndElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeEmptyElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeCharRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeEntityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeDoctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	
public:
	virtual bool __fastcall parse(const TXmlCustomProcessorAgent* sender, const TXmlInputSource* inputSource);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlStandardDocReader(Classes::TComponent* AOwner) : TXmlCustomReader(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlStandardDocReader(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TXmlStandardProcessorAgent : public TXmlCustomProcessorAgent 
{
	typedef TXmlCustomProcessorAgent inherited;
	
protected:
	TXmlStandardDocReader* FReader;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	
public:
	virtual bool __fastcall processFile(const WideString pubId, const WideString sysId);
	virtual bool __fastcall processMemory(const void * ptr, const int size, const WideString pubId, const WideString sysId);
	virtual bool __fastcall processSourceCode(const TXmlSourceCode* intDtdSourceCode, const WideString pubId, const WideString sysId);
	virtual bool __fastcall processStream(const Classes::TStream* stream, const WideString pubId, const WideString sysId);
	virtual bool __fastcall processString(const AnsiString str, const WideString pubId, const WideString sysId);
	virtual bool __fastcall processWideString(WideString str, const WideString pubId, const WideString sysId);
	
__published:
	__property TXmlStandardDocReader* Reader = {read=FReader, write=FReader};
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlStandardProcessorAgent(Classes::TComponent* AOwner) : TXmlCustomProcessorAgent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlStandardProcessorAgent(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlHandlerItem;
class PASCALIMPLEMENTATION TXmlHandlerItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	TXmlCustomHandler* FXmlHandler;
	TXmlCustomHandler* __fastcall getXmlHandler(void);
	void __fastcall setXmlHandler(TXmlCustomHandler* Value);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property TXmlCustomHandler* XmlHandler = {read=getXmlHandler, write=setXmlHandler};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TXmlHandlerItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TXmlHandlerItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlHandlers;
class DELPHICLASS TXmlDistributor;
class PASCALIMPLEMENTATION TXmlDistributor : public TXmlCustomHandler 
{
	typedef TXmlCustomHandler inherited;
	
private:
	void __fastcall readData(Classes::TReader* Reader);
	void __fastcall writeData(Classes::TWriter* Writer);
	
protected:
	TXmlHandlers* FNextHandlers;
	virtual void __fastcall DefineProperties(Classes::TFiler* Filer);
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	void __fastcall setNextHandlers(const TXmlHandlers* value);
	
public:
	__fastcall virtual TXmlDistributor(Classes::TComponent* AOwner);
	__fastcall virtual ~TXmlDistributor(void);
	virtual TXmlParserError* __fastcall CDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall charRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall comment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall doctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId, WideString data);
	virtual TXmlParserError* __fastcall endDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName);
	virtual TXmlParserError* __fastcall endPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix);
	virtual TXmlParserError* __fastcall entityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall PCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall processingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall skippedEntity(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual TXmlParserError* __fastcall startElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName, TdomNameValueList* attributes);
	virtual TXmlParserError* __fastcall startPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri);
	virtual TXmlParserError* __fastcall xmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl, WideString sdDl);
	virtual TXmlParserError* __fastcall attributeDefinition(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString attType, WideString bracket, WideString defaultDecl, WideString attValue);
	virtual TXmlParserError* __fastcall conditionalSection(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString includeStmt, WideString data);
	virtual TXmlParserError* __fastcall DTDcomment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall DTDprocessingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall elementTypeDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString data);
	virtual TXmlParserError* __fastcall endAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall entityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId, WideString notaName);
	virtual TXmlParserError* __fastcall notationDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall parameterEntityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall parameterEntityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall textDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl);
	
__published:
	__property TXmlHandlers* NextHandlers = {read=FNextHandlers, write=setNextHandlers};
};


class PASCALIMPLEMENTATION TXmlHandlers : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TXmlHandlerItem* operator[](int Index) { return Items[Index]; }
	
private:
	TXmlDistributor* FDistributor;
	
protected:
	HIDESBASE virtual TXmlHandlerItem* __fastcall GetItem(int Index);
	HIDESBASE virtual void __fastcall SetItem(int Index, TXmlHandlerItem* Value);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TXmlHandlers(TXmlDistributor* Distributor);
	HIDESBASE TXmlHandlerItem* __fastcall Add(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	TXmlHandlerItem* __fastcall FindHandlerItem(TXmlCustomHandler* AHandler);
	__property TXmlDistributor* Distributor = {read=FDistributor};
	__property TXmlHandlerItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TXmlHandlers(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlCustomDTDHandler;
class PASCALIMPLEMENTATION TXmlCustomDTDHandler : public TXmlStandardHandler 
{
	typedef TXmlStandardHandler inherited;
	
protected:
	virtual TXmlParserError* __fastcall parserErrorFactory(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	
public:
	virtual TXmlParserError* __fastcall CDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall charRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall comment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall doctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId, WideString data);
	virtual TXmlParserError* __fastcall endDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName);
	virtual TXmlParserError* __fastcall endPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix);
	virtual TXmlParserError* __fastcall entityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall PCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall processingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall skippedEntity(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual TXmlParserError* __fastcall startElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName, TdomNameValueList* attributes);
	virtual TXmlParserError* __fastcall startPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri);
	virtual TXmlParserError* __fastcall xmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl, WideString sdDl);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlCustomDTDHandler(Classes::TComponent* AOwner) : TXmlStandardHandler(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlCustomDTDHandler(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlCustomContentHandler;
class PASCALIMPLEMENTATION TXmlCustomContentHandler : public TXmlStandardHandler 
{
	typedef TXmlStandardHandler inherited;
	
protected:
	virtual TXmlParserError* __fastcall parserErrorFactory(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	
public:
	virtual TXmlParserError* __fastcall attributeDefinition(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString attType, WideString bracket, WideString defaultDecl, WideString attValue);
	virtual TXmlParserError* __fastcall conditionalSection(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString includeStmt, WideString data);
	virtual TXmlParserError* __fastcall DTDcomment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall DTDprocessingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall elementTypeDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString data);
	virtual TXmlParserError* __fastcall endAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall entityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId, WideString notaName);
	virtual TXmlParserError* __fastcall notationDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall parameterEntityDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString entityValue, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall parameterEntityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startAttListDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDtd(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString pubId, WideString sysId);
	virtual TXmlParserError* __fastcall textDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl);
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TXmlCustomContentHandler(Classes::TComponent* AOwner) : TXmlStandardHandler(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlCustomContentHandler(void) { }
	#pragma option pop
	
};


class DELPHICLASS TXmlWFTestContentHandler;
class PASCALIMPLEMENTATION TXmlWFTestContentHandler : public TXmlCustomContentHandler 
{
	typedef TXmlCustomContentHandler inherited;
	
protected:
	bool FIsActive;
	bool FDoctypeFound;
	bool FRootFound;
	bool FXMLDeclarationAllowed;
	Classes::TStringList* FTagStack;
	
public:
	__fastcall virtual TXmlWFTestContentHandler(Classes::TComponent* AOwner);
	__fastcall virtual ~TXmlWFTestContentHandler(void);
	virtual TXmlParserError* __fastcall CDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall charRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall comment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall doctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId, WideString data);
	virtual TXmlParserError* __fastcall endDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName);
	virtual TXmlParserError* __fastcall endPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix);
	virtual TXmlParserError* __fastcall entityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall PCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall processingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall skippedEntity(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual TXmlParserError* __fastcall startElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName, TdomNameValueList* attributes);
	virtual TXmlParserError* __fastcall startPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri);
	virtual TXmlParserError* __fastcall xmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl, WideString sdDl);
	__property bool isActive = {read=FIsActive, nodefault};
};


class DELPHICLASS TXmlDocBuilder;
class PASCALIMPLEMENTATION TXmlDocBuilder : public TXmlCustomContentHandler 
{
	typedef TXmlCustomContentHandler inherited;
	
private:
	bool FBuildNamespaceTree;
	bool FPreserveWhitespace;
	
protected:
	TdomNode* FRefNode;
	TdomNameValueList* FPrefixUriList;
	
public:
	__fastcall virtual TXmlDocBuilder(Classes::TComponent* AOwner);
	__fastcall virtual ~TXmlDocBuilder(void);
	virtual TXmlParserError* __fastcall CDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall charRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall comment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall doctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name, WideString pubId, WideString sysId, WideString data);
	virtual TXmlParserError* __fastcall endDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator);
	virtual TXmlParserError* __fastcall endElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName);
	virtual TXmlParserError* __fastcall endPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix);
	virtual TXmlParserError* __fastcall entityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall PCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString data);
	virtual TXmlParserError* __fastcall processingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString targ, WideString data);
	virtual TXmlParserError* __fastcall skippedEntity(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString name);
	virtual TXmlParserError* __fastcall startDocument(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual TXmlParserError* __fastcall startElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString namespaceURI, WideString tagName, TdomNameValueList* attributes);
	virtual TXmlParserError* __fastcall startPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri);
	virtual TXmlParserError* __fastcall xmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString version, WideString encDl, WideString sdDl);
	__property TdomNode* referenceNode = {read=FRefNode, write=FRefNode};
	__property bool preserveWhitespace = {read=FPreserveWhitespace, write=FPreserveWhitespace, nodefault};
	
__published:
	__property bool BuildNamespaceTree = {read=FBuildNamespaceTree, write=FBuildNamespaceTree, default=0};
};


class DELPHICLASS TXmlStandardDomReader;
class PASCALIMPLEMENTATION TXmlStandardDomReader : public TXmlCustomReader 
{
	typedef TXmlCustomReader inherited;
	
private:
	bool FPrefixMapping;
	bool FSuppressXmlns;
	
protected:
	virtual TXmlParserError* __fastcall writeXmlDeclaration(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl, const WideString sdDl);
	virtual TXmlParserError* __fastcall writeProcessingInstruction(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString targ, const WideString attribSequence);
	virtual TXmlParserError* __fastcall writeComment(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writePCDATA(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeStartElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString tagName, const TdomNameValueList* attributeList);
	virtual TXmlParserError* __fastcall writeEndElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString tagName);
	virtual TXmlParserError* __fastcall writeEmptyElement(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString tagName, const TdomNameValueList* attributeList);
	virtual TXmlParserError* __fastcall writeStartPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix, WideString uri);
	virtual TXmlParserError* __fastcall writeEndPrefixMapping(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, WideString prefix);
	virtual TXmlParserError* __fastcall writeCharRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString content);
	virtual TXmlParserError* __fastcall writeEntityRef(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString entityName);
	virtual TXmlParserError* __fastcall writeDoctype(const TXmlCustomProcessorAgent* sender, const TdomStandardLocator* locator, const WideString name, const WideString publicId, const WideString systemId, const WideString intSubset);
	virtual TXmlParserError* __fastcall parseloop(const TXmlCustomProcessorAgent* sender, const TdomNode* sourceNode);
	
public:
	__fastcall virtual TXmlStandardDomReader(Classes::TComponent* AOwner);
	virtual bool __fastcall parse(const TXmlCustomProcessorAgent* sender, const TdomNode* sourceNode);
	
__published:
	__property bool PrefixMapping = {read=FPrefixMapping, write=FPrefixMapping, default=0};
	__property bool SuppressXmlns = {read=FSuppressXmlns, write=FSuppressXmlns, default=0};
public:
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TXmlStandardDomReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCustomContentHandler;
class DELPHICLASS TdomCustomParser;
class PASCALIMPLEMENTATION TdomCustomContentHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall CDATA(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall charRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall comment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall doctype(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString pubId, const WideString sysId, const WideString data);
	virtual void __fastcall endDocument(const TdomCustomParser* sender);
	virtual void __fastcall endElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString namespaceURI, const WideString localName, const WideString tagName);
	virtual void __fastcall endPrefixMapping(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString prefix);
	virtual void __fastcall entityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall PCDATA(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall processingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString targ, const WideString data);
	virtual void __fastcall skippedEntity(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall startDocument(const TdomCustomParser* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual void __fastcall startElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString namespaceURI, const WideString localName, const WideString tagName, TdomNameValueList* attributes);
	virtual void __fastcall startPrefixMapping(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString prefix, const WideString uri);
	virtual void __fastcall xmlDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl, const WideString sdDl);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomCustomContentHandler(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomCustomContentHandler(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCustomDTDHandler;
class PASCALIMPLEMENTATION TdomCustomDTDHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
protected:
	virtual WideString __fastcall getPEFromCurrentCMObject(const WideString PEReferenceName);
	
public:
	virtual void __fastcall attributeDefinition(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString attType, const WideString bracket, const WideString defaultDecl, const WideString attValue);
	virtual void __fastcall comment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall conditionalSection(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString includeStmt, const WideString data);
	virtual void __fastcall elementTypeDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString data);
	virtual void __fastcall endAttListDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator);
	virtual void __fastcall endDtd(const TdomCustomParser* sender);
	virtual void __fastcall entityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual void __fastcall notationDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString pubId, const WideString sysId);
	virtual void __fastcall parameterEntityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId);
	virtual void __fastcall parameterEntityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall processingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString targ, const WideString data);
	virtual void __fastcall startAttListDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall startDtd(const TdomCustomParser* sender, const WideString pubId, const WideString sysId);
	virtual void __fastcall textDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomCustomDTDHandler(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomCustomDTDHandler(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCustomErrorHandler : public System::TObject 
{
	typedef System::TObject inherited;
	
public:
	virtual void __fastcall error(const TdomCustomParser* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	virtual void __fastcall fatalError(const TdomCustomParser* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	virtual void __fastcall warning(const TdomCustomParser* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomCustomErrorHandler(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomCustomErrorHandler(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardContentModelReader;
class PASCALIMPLEMENTATION TdomStandardContentModelReader : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomCustomErrorHandler* FErrorHandler;
	
public:
	virtual bool __fastcall parse(const TdomCustomParser* sender, const TdomCustomCMIEObject* source);
	__property TdomCustomErrorHandler* errorHandler = {read=FErrorHandler, write=FErrorHandler};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomStandardContentModelReader(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardContentModelReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomCustomXMLReader;
class PASCALIMPLEMENTATION TdomCustomXMLReader : public System::TObject 
{
	typedef System::TObject inherited;
	
private:
	TdomCustomContentHandler* FContentHandler;
	TdomCustomDTDHandler* FDTDHandler;
	TdomCustomErrorHandler* FErrorHandler;
	TdomStandardLocator* FLocator;
	
public:
	virtual bool __fastcall parse(const TdomCustomParser* sender, const TXmlInputSource* inputSource);
	__property TdomCustomContentHandler* contentHandler = {read=FContentHandler, write=FContentHandler};
	__property TdomCustomDTDHandler* dtdHandler = {read=FDTDHandler, write=FDTDHandler};
	__property TdomCustomErrorHandler* errorHandler = {read=FErrorHandler, write=FErrorHandler};
	__property TdomStandardLocator* locator = {read=FLocator};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomCustomXMLReader(void) : System::TObject() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomCustomXMLReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardDocXMLReader;
class PASCALIMPLEMENTATION TdomStandardDocXMLReader : public TdomCustomXMLReader 
{
	typedef TdomCustomXMLReader inherited;
	
protected:
	virtual void __fastcall writeXmlDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeProcessingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeComment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeCDATA(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writePCDATA(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeStartElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeEndElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeEmptyElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeCharRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeEntityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeDoctype(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	
public:
	virtual bool __fastcall parse(const TdomCustomParser* sender, const TXmlInputSource* inputSource);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomStandardDocXMLReader(void) : TdomCustomXMLReader() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardDocXMLReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardIntSubsetXMLReader;
class PASCALIMPLEMENTATION TdomStandardIntSubsetXMLReader : public TdomCustomXMLReader 
{
	typedef TdomCustomXMLReader inherited;
	
private:
	void __fastcall FindNextAttDef(const WideString Decl, WideString &name, WideString &attType, WideString &Bracket, WideString &defaultDecl, WideString &attValue, WideString &Rest);
	
protected:
	virtual void __fastcall writeProcessingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeComment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeParameterEntityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeEntityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeElementDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeAttributeDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeNotationDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	
public:
	virtual bool __fastcall parse(const TdomCustomParser* sender, const TXmlInputSource* inputSource);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomStandardIntSubsetXMLReader(void) : TdomCustomXMLReader() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardIntSubsetXMLReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardExtSubsetXMLReader;
class PASCALIMPLEMENTATION TdomStandardExtSubsetXMLReader : public TdomStandardIntSubsetXMLReader 
{
	typedef TdomStandardIntSubsetXMLReader inherited;
	
protected:
	virtual WideString __fastcall includeAsPE(const TdomCustomParser* sender, const TdomStandardLocator* locator, const TXmlInputSource* inputSource);
	virtual WideString __fastcall includeInLiteral(const TdomCustomParser* sender, const TdomStandardLocator* locator, const TXmlInputSource* inputSource);
	virtual void __fastcall writeTextDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	virtual void __fastcall writeConditionalSection(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString content);
	
public:
	virtual bool __fastcall parse(const TdomCustomParser* sender, const TXmlInputSource* inputSource);
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomStandardExtSubsetXMLReader(void) : TdomStandardIntSubsetXMLReader() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardExtSubsetXMLReader(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardErrorHandler;
class PASCALIMPLEMENTATION TdomStandardErrorHandler : public TdomCustomErrorHandler 
{
	typedef TdomCustomErrorHandler inherited;
	
protected:
	Classes::TList* FErrorList;
	
public:
	__fastcall TdomStandardErrorHandler(void);
	__fastcall virtual ~TdomStandardErrorHandler(void);
	virtual void __fastcall clearErrorList(void);
	virtual void __fastcall error(const TdomCustomParser* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	virtual void __fastcall fatalError(const TdomCustomParser* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	virtual void __fastcall warning(const TdomCustomParser* sender, const TdomStandardLocator* locator, const EParserException* e, const WideString code);
	__property Classes::TList* errorList = {read=FErrorList};
};


class DELPHICLASS TdomStandardDocBuilder;
class PASCALIMPLEMENTATION TdomStandardDocBuilder : public TdomCustomContentHandler 
{
	typedef TdomCustomContentHandler inherited;
	
protected:
	TdomNode* FReferenceNode;
	TdomNode* FRefNode;
	TdomDocument* FRefDocument;
	bool FXMLDeclarationAllowed;
	
public:
	__fastcall TdomStandardDocBuilder(void);
	virtual void __fastcall comment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall CDATA(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall charRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall doctype(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString pubId, const WideString sysId, const WideString data);
	virtual void __fastcall endDocument(const TdomCustomParser* sender);
	virtual void __fastcall endElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString namespaceURI, const WideString localName, const WideString tagName);
	virtual void __fastcall endPrefixMapping(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString prefix);
	virtual void __fastcall entityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall PCDATA(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall processingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString targ, const WideString data);
	virtual void __fastcall skippedEntity(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall startDocument(const TdomCustomParser* sender, const TdomStandardLocator* locator, WideString defaultRoot);
	virtual void __fastcall startElement(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString namespaceURI, const WideString localName, const WideString tagName, TdomNameValueList* attributes);
	virtual void __fastcall startPrefixMapping(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString prefix, const WideString uri);
	virtual void __fastcall xmlDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl, const WideString sdDl);
	__property TdomDocument* ReferenceDocument = {read=FRefDocument};
	__property TdomNode* ReferenceNode = {read=FReferenceNode, write=FReferenceNode};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardDocBuilder(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomDTDContentModelHandler;
class PASCALIMPLEMENTATION TdomDTDContentModelHandler : public TdomCustomDTDHandler 
{
	typedef TdomCustomDTDHandler inherited;
	
protected:
	WideString FCurrentAttListName;
	virtual void __fastcall insertMixedContent(const TdomCustomParser* sender, const TdomCMNode* refNode, const WideString contSpec);
	virtual void __fastcall insertChildrenContent(const TdomCustomParser* sender, const TdomCMNode* refNode, const WideString contSpec);
	virtual void __fastcall insertNotationOrEnumerationContent(const TdomCustomParser* sender, const TdomCMAttribute* refCMAttribute, const WideString contSpec);
	TdomCMObject* FContentModel;
	virtual void __fastcall ResolveCharRefsAndPERefs(const WideString s, WideString &result, bool &error);
	virtual void __fastcall CDataNormalization(const WideString s, WideString &result, bool &error);
	
public:
	virtual void __fastcall attributeDefinition(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString attType, const WideString bracket, const WideString defaultDecl, const WideString attValue);
	virtual void __fastcall comment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall conditionalSection(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString includeStmt, const WideString data);
	virtual void __fastcall elementTypeDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString data);
	virtual void __fastcall endAttListDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator);
	virtual void __fastcall endDtd(const TdomCustomParser* sender);
	virtual void __fastcall entityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual void __fastcall notationDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString pubId, const WideString sysId);
	virtual void __fastcall parameterEntityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId);
	virtual void __fastcall parameterEntityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall processingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString targ, const WideString data);
	virtual void __fastcall startAttListDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall startDtd(const TdomCustomParser* sender, const WideString pubId, const WideString sysId);
	virtual void __fastcall textDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl);
	__property TdomCMObject* contentModel = {read=FContentModel};
public:
	#pragma option push -w-inl
	/* TObject.Create */ inline __fastcall TdomDTDContentModelHandler(void) : TdomCustomDTDHandler() { }
	#pragma option pop
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomDTDContentModelHandler(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardIntSubsetBuilder;
class PASCALIMPLEMENTATION TdomStandardIntSubsetBuilder : public TdomCustomDTDHandler 
{
	typedef TdomCustomDTDHandler inherited;
	
private:
	TdomCMNode* FReferenceNode;
	
protected:
	TdomCMNode* FRefNode;
	virtual WideString __fastcall getPEFromCurrentCMObject(const WideString PEReferenceName);
	virtual void __fastcall resolveCharRefsAndPERefs(const WideString s, WideString &result, bool &error);
	virtual void __fastcall insertMixedContent(const TdomCustomParser* sender, const TdomCMNode* refNode, const WideString contSpec);
	virtual void __fastcall insertChildrenContent(const TdomCustomParser* sender, const TdomCMNode* refNode, const WideString contSpec);
	virtual void __fastcall insertNotationOrEnumerationContent(const TdomCustomParser* sender, const TdomCMAttrDefinition* refCMAttrDefinition, const WideString contSpec);
	virtual void __fastcall setReferenceNode(const TdomCMNode* node);
	
public:
	__fastcall virtual TdomStandardIntSubsetBuilder(void);
	virtual void __fastcall attributeDefinition(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString attType, const WideString bracket, const WideString defaultDecl, const WideString attValue);
	virtual void __fastcall comment(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString data);
	virtual void __fastcall conditionalSection(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString includeStmt, const WideString data);
	virtual void __fastcall elementTypeDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString data);
	virtual void __fastcall endAttListDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator);
	virtual void __fastcall endDtd(const TdomCustomParser* sender);
	virtual void __fastcall entityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId, const WideString notaName);
	virtual void __fastcall notationDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString pubId, const WideString sysId);
	virtual void __fastcall parameterEntityDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name, const WideString entityValue, const WideString pubId, const WideString sysId);
	virtual void __fastcall parameterEntityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall processingInstruction(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString targ, const WideString data);
	virtual void __fastcall startAttListDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall startDtd(const TdomCustomParser* sender, const WideString pubId, const WideString sysId);
	virtual void __fastcall textDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl);
	__property TdomCMNode* referenceNode = {read=FReferenceNode, write=setReferenceNode};
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardIntSubsetBuilder(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomStandardExtSubsetBuilder;
class PASCALIMPLEMENTATION TdomStandardExtSubsetBuilder : public TdomStandardIntSubsetBuilder 
{
	typedef TdomStandardIntSubsetBuilder inherited;
	
protected:
	bool FTextDeclarationAllowed;
	virtual WideString __fastcall getPEFromCurrentCMObject(const WideString PEReferenceName);
	virtual void __fastcall setReferenceNode(const TdomCMNode* node);
	
public:
	__fastcall virtual TdomStandardExtSubsetBuilder(void);
	virtual void __fastcall conditionalSection(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString includeStmt, const WideString data);
	virtual void __fastcall parameterEntityRef(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString name);
	virtual void __fastcall startDtd(const TdomCustomParser* sender, const WideString pubId, const WideString sysId);
	virtual void __fastcall textDeclaration(const TdomCustomParser* sender, const TdomStandardLocator* locator, const WideString version, const WideString encDl);
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~TdomStandardExtSubsetBuilder(void) { }
	#pragma option pop
	
};


class PASCALIMPLEMENTATION TdomCustomParser : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
public:
	#pragma option push -w-inl
	/* TComponent.Create */ inline __fastcall virtual TdomCustomParser(Classes::TComponent* AOwner) : Classes::TComponent(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TComponent.Destroy */ inline __fastcall virtual ~TdomCustomParser(void) { }
	#pragma option pop
	
};


class DELPHICLASS TdomDtdAnalyzer;
class PASCALIMPLEMENTATION TdomDtdAnalyzer : public TdomCustomParser 
{
	typedef TdomCustomParser inherited;
	
private:
	TdomCustomErrorHandler* FErrorHandler;
	TdomDTDContentModelHandler* FDtdHandler;
	TdomStandardContentModelReader* FDtdReader;
	TdomStandardIntSubsetXMLReader* FIntDtdReader;
	
public:
	__fastcall virtual TdomDtdAnalyzer(Classes::TComponent* aOwner);
	__fastcall virtual ~TdomDtdAnalyzer(void);
	virtual void __fastcall analyzeCM(const TdomCustomCMIEObject* source, const TdomCMObject* contentModel);
	virtual void __fastcall analyzeIntDTDStr(WideString str, const TdomCMObject* contentModel);
	__property TdomDTDContentModelHandler* dtdHandler = {read=FDtdHandler};
	__property TdomStandardContentModelReader* dtdReader = {read=FDtdReader};
	__property TdomCustomErrorHandler* errorHandler = {read=FErrorHandler, write=FErrorHandler};
	__property TdomStandardIntSubsetXMLReader* intDtdReader = {read=FIntDtdReader};
};


class DELPHICLASS TXmlToDomParser;
class PASCALIMPLEMENTATION TXmlToDomParser : public TdomCustomParser 
{
	typedef TdomCustomParser inherited;
	
private:
	TDomImplementation* FDOMImpl;
	TXmlParserEvent FOnExternalSubset;
	virtual void __fastcall setDomImpl(const TDomImplementation* impl);
	virtual TDomImplementation* __fastcall getDomImpl(void);
	
protected:
	TdomStandardDocBuilder* FDocBuilder;
	TdomStandardDocXMLReader* FDocXMLReader;
	TdomStandardErrorHandler* FErrorHandler;
	TdomStandardExtSubsetBuilder* FExtDtdBuilder;
	TdomStandardExtSubsetXMLReader* FExtDtdReader;
	TdomStandardIntSubsetBuilder* FIntDtdBuilder;
	TdomStandardIntSubsetXMLReader* FIntDtdReader;
	virtual void __fastcall Notification(Classes::TComponent* AComponent, Classes::TOperation Operation);
	virtual void __fastcall parseDtd(const TdomStandardLocator* locator, const WideString name, const WideString pubId, const WideString sysId, const WideString data, const bool standalone);
	
public:
	__fastcall virtual TXmlToDomParser(Classes::TComponent* aOwner);
	__fastcall virtual ~TXmlToDomParser(void);
	virtual void __fastcall docMemoryToDom(const void * ptr, const int size, const WideString pubId, const WideString sysId, const TdomNode* refNode);
	virtual void __fastcall docSourceCodeToDom(const TXmlSourceCode* docSourceCode, const WideString pubId, const WideString sysId, const TdomNode* refNode);
	virtual void __fastcall docStreamToDom(const Classes::TStream* stream, const WideString pubId, const WideString sysId, const TdomNode* refNode);
	virtual void __fastcall docStringToDom(const AnsiString Str, const WideString pubId, const WideString sysId, const TdomNode* refNode);
	virtual void __fastcall docWideStringToDom(WideString str, const WideString pubId, const WideString sysId, const TdomNode* refNode);
	virtual void __fastcall extDtdMemoryToDom(const void * ptr, const int size, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall extDtdSourceCodeToDom(const TXmlSourceCode* ExtDtdSourceCode, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall extDtdStreamToDom(const Classes::TStream* stream, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall extDtdStringToDom(const AnsiString str, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall extDtdWideStringToDom(WideString str, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall intDtdMemoryToDom(const void * ptr, const int size, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall intDtdSourceCodeToDom(const TXmlSourceCode* IntDtdSourceCode, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall intDtdStreamToDom(const Classes::TStream* stream, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall intDtdStringToDom(const AnsiString str, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual void __fastcall intDtdWideStringToDom(WideString str, const WideString pubId, const WideString sysId, const TdomCMNode* refNode);
	virtual TdomDocument* __fastcall fileToDom(const AnsiString filename);
	virtual TdomDocument* __fastcall memoryToDom(const void * ptr, const int size);
	virtual TdomDocument* __fastcall sourceCodeToDom(const TXmlSourceCode* intDtdSourceCode);
	virtual TdomDocument* __fastcall streamToDom(const Classes::TStream* stream);
	virtual TdomDocument* __fastcall stringToDom(const AnsiString str);
	virtual TdomDocument* __fastcall wideStringToDom(WideString str);
	__property TdomStandardDocBuilder* docBuilder = {read=FDocBuilder};
	__property TdomStandardDocXMLReader* docXMLReader = {read=FDocXMLReader};
	__property TdomStandardErrorHandler* errorHandler = {read=FErrorHandler};
	__property TdomStandardExtSubsetBuilder* extDtdBuilder = {read=FExtDtdBuilder};
	__property TdomStandardExtSubsetXMLReader* extDtdReader = {read=FExtDtdReader};
	__property TdomStandardIntSubsetBuilder* intDtdBuilder = {read=FIntDtdBuilder};
	__property TdomStandardIntSubsetXMLReader* intDtdReader = {read=FIntDtdReader};
	
__published:
	__property TDomImplementation* DOMImpl = {read=getDomImpl, write=setDomImpl};
	__property TXmlParserEvent onExternalSubset = {read=FOnExternalSubset, write=FOnExternalSubset};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SCannotReadOddPos;
#define Xdom_SCannotReadOddPos System::LoadResourceString(&Xdom::_SCannotReadOddPos)
extern PACKAGE System::ResourceString _SCannotWriteOddPos;
#define Xdom_SCannotWriteOddPos System::LoadResourceString(&Xdom::_SCannotWriteOddPos)
extern PACKAGE System::ResourceString _SOddSizeInvalid;
#define Xdom_SOddSizeInvalid System::LoadResourceString(&Xdom::_SOddSizeInvalid)
extern PACKAGE System::ResourceString _SNegativeSizeInvalid;
#define Xdom_SNegativeSizeInvalid System::LoadResourceString(&Xdom::_SNegativeSizeInvalid)
extern PACKAGE System::ResourceString _SOddPosInvalid;
#define Xdom_SOddPosInvalid System::LoadResourceString(&Xdom::_SOddPosInvalid)
extern PACKAGE System::ResourceString _SCapacityLessSize;
#define Xdom_SCapacityLessSize System::LoadResourceString(&Xdom::_SCapacityLessSize)
extern PACKAGE System::ResourceString _STargetNil;
#define Xdom_STargetNil System::LoadResourceString(&Xdom::_STargetNil)
extern PACKAGE TdomWhatToShow show_all;
extern PACKAGE TdomDocumentFormat *domDocumentFormatList;
extern PACKAGE void __fastcall Register(void);
extern PACKAGE WideString __fastcall xmlNormalizeLineBreaks(const WideString source);
extern PACKAGE void __fastcall xmlAnalysePCDATA(WideString source, Classes::TStringList* &lines);
extern PACKAGE void __fastcall xmlAnalyseElement(const WideString source, WideString &tagName, TdomNameValueList* attributes);
extern PACKAGE void __fastcall xmlAnalyseTag(const WideString source, WideString &tagName, WideString &attribSequence);
extern PACKAGE void __fastcall xmlAnalyseEntityDef(WideString source, WideString &entityValue, WideString &systemLiteral, WideString &pubidLiteral, WideString &nDataName, bool &error);
extern PACKAGE void __fastcall xmlAnalyseNotationDecl(const WideString decl, WideString &systemLiteral, WideString &pubidLiteral, bool &error);
extern PACKAGE WideString __fastcall xmlReplaceQuotes(const WideString source);
extern PACKAGE WideString __fastcall xmlTrunc(const WideString source);
extern PACKAGE void __fastcall xmlTruncAngularBrackets(const WideString source, WideString &content, bool &error);
extern PACKAGE void __fastcall xmlTruncRoundBrackets(const WideString source, WideString &content, bool &error);
extern PACKAGE void __fastcall xmlIsolateQuote(WideString source, WideString &content, WideString &rest, wchar_t &quoteType, bool &error);
extern PACKAGE WideString __fastcall xmlAnalysePubSysId(const WideString publicId, const WideString systemId, const WideString notaName);
extern PACKAGE WideString __fastcall xmlExtractPrefix(const WideString qualifiedName);
extern PACKAGE WideString __fastcall xmlExtractLocalName(const WideString qualifiedName);
extern PACKAGE bool __fastcall isXmlChar(const wchar_t S);
extern PACKAGE bool __fastcall isXmlWhiteSpace(const wchar_t S);
extern PACKAGE bool __fastcall isXmlLetter(const wchar_t S);
extern PACKAGE bool __fastcall isXmlBaseChar(const wchar_t S);
extern PACKAGE bool __fastcall isXmlIdeographic(const wchar_t S);
extern PACKAGE bool __fastcall isXmlCombiningChar(const wchar_t S);
extern PACKAGE bool __fastcall isXmlDigit(const wchar_t S);
extern PACKAGE bool __fastcall isXmlExtender(const wchar_t S);
extern PACKAGE bool __fastcall isXmlNameChar(const wchar_t S);
extern PACKAGE bool __fastcall isXmlPubidChar(const wchar_t S);
extern PACKAGE bool __fastcall isXmlChars(const WideString S);
extern PACKAGE bool __fastcall isXmlS(const WideString S);
extern PACKAGE bool __fastcall isXmlName(const WideString S);
extern PACKAGE bool __fastcall isXmlNames(const WideString S);
extern PACKAGE bool __fastcall isXmlNmtoken(const WideString S);
extern PACKAGE bool __fastcall isXmlNmtokens(const WideString S);
extern PACKAGE bool __fastcall isXmlCharRef(const WideString S);
extern PACKAGE bool __fastcall isXmlEntityRef(const WideString S);
extern PACKAGE bool __fastcall isXmlPEReference(const WideString S);
extern PACKAGE bool __fastcall isXmlReference(const WideString S);
extern PACKAGE bool __fastcall isXmlEntityValue(const WideString S);
extern PACKAGE bool __fastcall isXmlAttValue(const WideString S);
extern PACKAGE bool __fastcall isXmlSystemLiteral(const WideString S);
extern PACKAGE bool __fastcall isXmlPubidLiteral(const WideString S);
extern PACKAGE bool __fastcall isXmlComment(const WideString S);
extern PACKAGE bool __fastcall isXmlCData(const WideString S);
extern PACKAGE bool __fastcall isXmlCharData(const WideString S);
extern PACKAGE bool __fastcall isXmlPITarget(const WideString S);
extern PACKAGE bool __fastcall isXmlVersionNum(const WideString S);
extern PACKAGE bool __fastcall isXmlEncName(const WideString S);
extern PACKAGE bool __fastcall isXmlStringType(const WideString S);
extern PACKAGE bool __fastcall isXmlTokenizedType(const WideString S);
extern PACKAGE bool __fastcall isXmlNCNameChar(const wchar_t s);
extern PACKAGE bool __fastcall isXmlNCName(const WideString S);
extern PACKAGE bool __fastcall isXmlDefaultAttName(const WideString S);
extern PACKAGE bool __fastcall isXmlPrefixedAttName(const WideString S);
extern PACKAGE bool __fastcall isXmlNSAttName(const WideString S);
extern PACKAGE bool __fastcall isXmlLocalPart(const WideString S);
extern PACKAGE bool __fastcall isXmlPrefix(const WideString S);
extern PACKAGE bool __fastcall isXmlQName(const WideString S);
extern PACKAGE WideString __fastcall resolveCharRefs(const WideString S);
extern PACKAGE WideString __fastcall xmlIntToCharRef(const int value);
extern PACKAGE int __fastcall xmlCharRefToInt(const WideString S);
extern PACKAGE WideString __fastcall xmlCharRefToStr(const WideString S);
extern PACKAGE WideString __fastcall xmlStrToCharRef(const WideString S);
extern PACKAGE wchar_t __fastcall Iso8859_1ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_2ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_3ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_4ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_5ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_6ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_7ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_8ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_9ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_10ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_13ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_14ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall Iso8859_15ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall KOI8_RToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall cp10000_MacRomanToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall cp1250ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall cp1251ToUTF16Char(const char P);
extern PACKAGE wchar_t __fastcall cp1252ToUTF16Char(const char P);
extern PACKAGE WideString __fastcall Iso8859_1ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_2ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_3ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_4ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_5ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_6ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_7ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_8ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_9ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_10ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_13ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_14ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall Iso8859_15ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall KOI8_RToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall cp10000_MacRomanToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall cp1250ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall cp1251ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall cp1252ToUTF16Str(const AnsiString S);
extern PACKAGE WideString __fastcall UTF8ToUTF16BEStr(const AnsiString S);
extern PACKAGE AnsiString __fastcall UTF16BEToUTF8Str(const WideString ws, const bool expandLF);
extern PACKAGE wchar_t __fastcall UTF16HighSurrogate(const int value);
extern PACKAGE wchar_t __fastcall UTF16LowSurrogate(const int value);
extern PACKAGE int __fastcall UTF16SurrogateToInt(const wchar_t highSurrogate, const wchar_t lowSurrogate);
extern PACKAGE bool __fastcall IsUTF16HighSurrogate(const wchar_t S);
extern PACKAGE bool __fastcall IsUTF16LowSurrogate(const wchar_t S);
extern PACKAGE void __fastcall writeWideString(Classes::TStream* stream, const WideString xmlStrg);
extern PACKAGE void __fastcall writeWideChars(Classes::TStream* stream, const wchar_t * xmlChars, const int xmlChars_Size);
extern PACKAGE void __fastcall writeWideStrings(Classes::TStream* stream, const WideString * xmlStrgs, const int xmlStrgs_Size);

}	/* namespace Xdom */
using namespace Xdom;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// xdom
