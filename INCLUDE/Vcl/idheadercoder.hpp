// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdHeaderCoder.pas' rev: 6.00

#ifndef IdHeaderCoderHPP
#define IdHeaderCoderHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <IdEMailAddress.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idheadercoder
{
//-- type declarations -------------------------------------------------------
#pragma option push -b-
enum TTransfer { bit7, bit8, iso2022jp };
#pragma option pop

typedef Set<char, 0, 255>  CSET;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE CSET csSPECIALS;
extern PACKAGE Word kana_tbl[63];
extern PACKAGE Word vkana_tbl[63];
extern PACKAGE Byte sj1_tbl[128];
extern PACKAGE Word sj2_tbl[256];
extern PACKAGE char base64_tbl[64];
extern PACKAGE AnsiString __fastcall DecodeHeader(AnsiString Header);
extern PACKAGE AnsiString __fastcall Decode2022JP(const AnsiString S);
extern PACKAGE void __fastcall InitializeMime(TTransfer &TransferHeader, char &HeaderEncoding, AnsiString &MimeCharSet);
extern PACKAGE void __fastcall DecodeAddress(Idemailaddress::TIdEMailAddressItem* EMailAddr);
extern PACKAGE void __fastcall DecodeAddresses(AnsiString AEMails, Idemailaddress::TIdEMailAddressList* EMailAddr);
extern PACKAGE AnsiString __fastcall EncodeAddressItem(Idemailaddress::TIdEMailAddressItem* EmailAddr, const char HeaderEncoding, TTransfer TransferHeader, AnsiString MimeCharSet);
extern PACKAGE AnsiString __fastcall EncodeAddress(Idemailaddress::TIdEMailAddressList* EmailAddr, const char HeaderEncoding, TTransfer TransferHeader, AnsiString MimeCharSet);
extern PACKAGE AnsiString __fastcall Encode2022JP(const AnsiString S);
extern PACKAGE AnsiString __fastcall EncodeHeader(const AnsiString Header, const CSET &specials, const char HeaderEncoding, TTransfer TransferHeader, AnsiString MimeCharSet);

}	/* namespace Idheadercoder */
using namespace Idheadercoder;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdHeaderCoder
