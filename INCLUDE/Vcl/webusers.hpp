// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'WebUsers.pas' rev: 6.00

#ifndef WebUsersHPP
#define WebUsersHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <SysUtils.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Webusers
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TWebUserItem;
class PASCALIMPLEMENTATION TWebUserItem : public Classes::TCollectionItem 
{
	typedef Classes::TCollectionItem inherited;
	
private:
	AnsiString FUserName;
	AnsiString FPassword;
	AnsiString FAccessRights;
	Classes::TStrings* FAccessRightsStrings;
	Variant __fastcall GetUserID();
	Classes::TStrings* __fastcall GetAccessRightsStrings(void);
	void __fastcall SetAccessRights(const AnsiString Value);
	
public:
	__fastcall virtual TWebUserItem(Classes::TCollection* Collection);
	__fastcall virtual ~TWebUserItem(void);
	virtual void __fastcall Assign(Classes::TPersistent* Source);
	__property Variant UserID = {read=GetUserID};
	bool __fastcall CheckRights(const AnsiString ARights);
	__property Classes::TStrings* AccessRightsStrings = {read=GetAccessRightsStrings};
	
__published:
	__property AnsiString UserName = {read=FUserName, write=FUserName};
	__property AnsiString Password = {read=FPassword, write=FPassword};
	__property AnsiString AccessRights = {read=FAccessRights, write=SetAccessRights};
};


class DELPHICLASS TWebUserItems;
class PASCALIMPLEMENTATION TWebUserItems : public Classes::TCollection 
{
	typedef Classes::TCollection inherited;
	
public:
	TWebUserItem* operator[](int Index) { return Items[Index]; }
	
private:
	Classes::TComponent* FOwner;
	TWebUserItem* __fastcall GetUserItem(int Index);
	void __fastcall SetUserItem(int Index, const TWebUserItem* Value);
	
protected:
	DYNAMIC int __fastcall GetAttrCount(void);
	DYNAMIC AnsiString __fastcall GetAttr(int Index);
	DYNAMIC AnsiString __fastcall GetItemAttr(int Index, int ItemIndex);
	DYNAMIC Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	TWebUserItem* __fastcall FindUserName(AnsiString AUserName);
	TWebUserItem* __fastcall FindUserID(const Variant &AUserID);
	__fastcall TWebUserItems(Classes::TComponent* AOwner, TMetaClass* ItemClass);
	__property TWebUserItem* Items[int Index] = {read=GetUserItem, write=SetUserItem/*, default*/};
public:
	#pragma option push -w-inl
	/* TCollection.Destroy */ inline __fastcall virtual ~TWebUserItems(void) { }
	#pragma option pop
	
};


#pragma option push -b-
enum TValidateUserError { vuBlankPassword, vuBlankUserName, vuUnknownUserName, vuUnknownPassword };
#pragma option pop

typedef void __fastcall (__closure *TCheckAccessRightsEvent)(const Variant &UserID, AnsiString Rights, bool &HasRight);

typedef void __fastcall (__closure *TCheckAccessRightsHandledEvent)(const Variant &UserID, AnsiString Rights, bool &HasRight, bool &Handled);

typedef void __fastcall (__closure *TValidateUserEvent)(Classes::TStrings* Strings, Variant &UserID);

typedef void __fastcall (__closure *TValidateUserHandledEvent)(Classes::TStrings* Strings, Variant &UserID, bool &Handled);

typedef void __fastcall (__closure *TValidateUserErrorEvent)(TValidateUserError Error, Classes::TStrings* Strings, Variant &UserID, bool &Handled);

class DELPHICLASS TCustomWebUserList;
class PASCALIMPLEMENTATION TCustomWebUserList : public Classes::TComponent 
{
	typedef Classes::TComponent inherited;
	
private:
	TWebUserItems* FItems;
	Sysutils::TMultiReadExclusiveWriteSynchronizer* FLock;
	TCheckAccessRightsEvent FOnAfterCheckAccessRights;
	TCheckAccessRightsHandledEvent FOnBeforeCheckAccessRights;
	TCheckAccessRightsHandledEvent FOnUserIDNotFound;
	TValidateUserEvent FOnAfterValidateUser;
	TValidateUserHandledEvent FOnBeforeValidateUser;
	TValidateUserErrorEvent FOnValidateUserError;
	void __fastcall SetItems(const TWebUserItems* Value);
	TWebUserItem* __fastcall GetItem(int I);
	
protected:
	Variant __fastcall ValidateUser(Classes::TStrings* Strings);
	bool __fastcall CheckAccessRights(const Variant &AUserID, AnsiString ARights);
	
public:
	__fastcall virtual TCustomWebUserList(Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomWebUserList(void);
	void __fastcall LoadFromFile(AnsiString FileName);
	void __fastcall SaveToFile(AnsiString FileName);
	__property TWebUserItems* UserItems = {read=FItems, write=SetItems};
	__property TWebUserItem* Users[int I] = {read=GetItem};
	__property TCheckAccessRightsHandledEvent OnBeforeCheckAccessRights = {read=FOnBeforeCheckAccessRights, write=FOnBeforeCheckAccessRights};
	__property TCheckAccessRightsEvent OnAfterCheckAccessRights = {read=FOnAfterCheckAccessRights, write=FOnAfterCheckAccessRights};
	__property TCheckAccessRightsHandledEvent OnUserIDNotFound = {read=FOnUserIDNotFound, write=FOnUserIDNotFound};
	__property TValidateUserHandledEvent OnBeforeValidateUser = {read=FOnBeforeValidateUser, write=FOnBeforeValidateUser};
	__property TValidateUserEvent OnAfterValidateUser = {read=FOnAfterValidateUser, write=FOnAfterValidateUser};
	__property TValidateUserErrorEvent OnValidateUserError = {read=FOnValidateUserError, write=FOnValidateUserError};
private:
	void *__IWebUserList;	/* Sitecomp::IWebUserList */
	
public:
	operator IWebUserList*(void) { return (IWebUserList*)&__IWebUserList; }
	
};


class DELPHICLASS TWebUserList;
class PASCALIMPLEMENTATION TWebUserList : public TCustomWebUserList 
{
	typedef TCustomWebUserList inherited;
	
__published:
	__property UserItems ;
	__property OnBeforeCheckAccessRights ;
	__property OnAfterCheckAccessRights ;
	__property OnUserIDNotFound ;
	__property OnBeforeValidateUser ;
	__property OnAfterValidateUser ;
	__property OnValidateUserError ;
public:
	#pragma option push -w-inl
	/* TCustomWebUserList.Create */ inline __fastcall virtual TWebUserList(Classes::TComponent* AOwner) : TCustomWebUserList(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	/* TCustomWebUserList.Destroy */ inline __fastcall virtual ~TWebUserList(void) { }
	#pragma option pop
	
};


class DELPHICLASS EWebUsersListException;
class PASCALIMPLEMENTATION EWebUsersListException : public Httpapp::EWebBrokerException 
{
	typedef Httpapp::EWebBrokerException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EWebUsersListException(const AnsiString Msg) : Httpapp::EWebBrokerException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EWebUsersListException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : Httpapp::EWebBrokerException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EWebUsersListException(int Ident)/* overload */ : Httpapp::EWebBrokerException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EWebUsersListException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : Httpapp::EWebBrokerException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EWebUsersListException(const AnsiString Msg, int AHelpContext) : Httpapp::EWebBrokerException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EWebUsersListException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : Httpapp::EWebBrokerException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EWebUsersListException(int Ident, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EWebUsersListException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : Httpapp::EWebBrokerException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EWebUsersListException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EUserIDNotFoundException;
class PASCALIMPLEMENTATION EUserIDNotFoundException : public EWebUsersListException 
{
	typedef EWebUsersListException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EUserIDNotFoundException(const AnsiString Msg) : EWebUsersListException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EUserIDNotFoundException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EWebUsersListException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EUserIDNotFoundException(int Ident)/* overload */ : EWebUsersListException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EUserIDNotFoundException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EWebUsersListException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EUserIDNotFoundException(const AnsiString Msg, int AHelpContext) : EWebUsersListException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EUserIDNotFoundException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EWebUsersListException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EUserIDNotFoundException(int Ident, int AHelpContext)/* overload */ : EWebUsersListException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EUserIDNotFoundException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EWebUsersListException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EUserIDNotFoundException(void) { }
	#pragma option pop
	
};


class DELPHICLASS EValidateUserException;
class PASCALIMPLEMENTATION EValidateUserException : public EWebUsersListException 
{
	typedef EWebUsersListException inherited;
	
public:
	#pragma option push -w-inl
	/* Exception.Create */ inline __fastcall EValidateUserException(const AnsiString Msg) : EWebUsersListException(Msg) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmt */ inline __fastcall EValidateUserException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size) : EWebUsersListException(Msg, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateRes */ inline __fastcall EValidateUserException(int Ident)/* overload */ : EWebUsersListException(Ident) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmt */ inline __fastcall EValidateUserException(int Ident, const System::TVarRec * Args, const int Args_Size)/* overload */ : EWebUsersListException(Ident, Args, Args_Size) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateHelp */ inline __fastcall EValidateUserException(const AnsiString Msg, int AHelpContext) : EWebUsersListException(Msg, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateFmtHelp */ inline __fastcall EValidateUserException(const AnsiString Msg, const System::TVarRec * Args, const int Args_Size, int AHelpContext) : EWebUsersListException(Msg, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResHelp */ inline __fastcall EValidateUserException(int Ident, int AHelpContext)/* overload */ : EWebUsersListException(Ident, AHelpContext) { }
	#pragma option pop
	#pragma option push -w-inl
	/* Exception.CreateResFmtHelp */ inline __fastcall EValidateUserException(System::PResStringRec ResStringRec, const System::TVarRec * Args, const int Args_Size, int AHelpContext)/* overload */ : EWebUsersListException(ResStringRec, Args, Args_Size, AHelpContext) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TObject.Destroy */ inline __fastcall virtual ~EValidateUserException(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Webusers */
using namespace Webusers;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// WebUsers
