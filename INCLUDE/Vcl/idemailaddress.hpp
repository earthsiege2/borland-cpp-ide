// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'IdEMailAddress.pas' rev: 6.00

#ifndef IdEMailAddressHPP
#define IdEMailAddressHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Idemailaddress
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TIdEMailAddressItem;
class PASCALIMPLEMENTATION TIdEMailAddressItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
protected:
	AnsiString FAddress;
	AnsiString FName;
	AnsiString __fastcall GetText();
	void __fastcall SetText(AnsiString AText);
	
public:
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	
__published:
	__property AnsiString Address = {read=FAddress, write=FAddress};
	__property AnsiString Name = {read=FName, write=FName};
	__property AnsiString Text = {read=GetText, write=SetText};
public:
	#pragma option push -w-inl
	/* TCollectionItem.Create */ inline __fastcall virtual TIdEMailAddressItem(Classes::TCollection* Collection) : Classes::TCollectionItem(Collection) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TIdEMailAddressItem(void) { }
	#pragma option pop
	
};


class DELPHICLASS TIdEMailAddressList;
class PASCALIMPLEMENTATION TIdEMailAddressList : public Classes::TOwnedCollection 
{
	typedef Classes::TOwnedCollection inherited;
	
public:
	TIdEMailAddressItem* operator[](int Index) { return Items[Index]; }
	
protected:
	HIDESBASE TIdEMailAddressItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, const TIdEMailAddressItem* Value);
	AnsiString __fastcall GetEMailAddresses();
	void __fastcall SetEMailAddresses(AnsiString AList);
	
public:
	__fastcall TIdEMailAddressList(Classes::TPersistent* AOwner);
	void __fastcall FillTStrings(Classes::TStrings* AStrings);
	HIDESBASE TIdEMailAddressItem* __fastcall Add(void);
	__property TIdEMailAddressItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property AnsiString EMailAddresses = {read=GetEMailAddresses, write=SetEMailAddresses};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TIdEMailAddressList(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Idemailaddress */
using namespace Idemailaddress;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// IdEMailAddress
