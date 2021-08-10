// Borland C++ Builder
// Copyright (c) 1995, 2002 by Borland Software Corporation
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DBAdaptImg.pas' rev: 6.00

#ifndef DBAdaptImgHPP
#define DBAdaptImgHPP

#pragma delphiheader begin
#pragma option push -w-
#pragma option push -Vx
#include <AdaptReq.hpp>	// Pascal unit
#include <DBAdapt.hpp>	// Pascal unit
#include <WebAdapt.hpp>	// Pascal unit
#include <WebContnrs.hpp>	// Pascal unit
#include <SysUtils.hpp>	// Pascal unit
#include <SiteComp.hpp>	// Pascal unit
#include <DB.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Messages.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dbadaptimg
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TImageDataSetFieldGetImageEvent)(System::TObject* Sender, AnsiString &MimeType, Classes::TStream* &Image, bool &Owned);

class DELPHICLASS TCustomDataSetAdapterImageField;
class PASCALIMPLEMENTATION TCustomDataSetAdapterImageField : public Dbadapt::TBaseDataSetAdapterImageField 
{
	typedef Dbadapt::TBaseDataSetAdapterImageField inherited;
	
private:
	Webadapt::TImageFieldGetHREFEvent FOnGetHREF;
	TImageDataSetFieldGetImageEvent FOnGetImage;
	
protected:
	bool __fastcall CheckOrUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex, bool AUpdate);
	virtual Variant __fastcall GetDataSetFieldValue(Db::TField* Field);
	virtual bool __fastcall ImplWebImageHREF(AnsiString &AHREF);
	bool __fastcall WebImageHREF(AnsiString &AHREF);
	void __fastcall CreateRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	void __fastcall ImplCreateRequestContext(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	bool __fastcall HandleRequest(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	virtual bool __fastcall ImplHandleRequest(Sitecomp::_di_IAdapterDispatchParams DispatchParams);
	virtual bool __fastcall ImplCheckValueChange(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual void __fastcall ImplUpdateValue(Adaptreq::_di_IActionRequest AActionRequest, int AFieldIndex);
	virtual Sitecomp::TAdapterDisplayHTMLElementType __fastcall GetDisplayStyleType(const AnsiString AAdapterMode);
	virtual Sitecomp::TAdapterInputHTMLElementType __fastcall GetInputStyleType(const AnsiString AAdapterMode);
	System::_di_IInterface __fastcall GetAdapterImage();
	void __fastcall RenderAdapterImage(Adaptreq::_di_IImageRequest ARequest, Adaptreq::_di_IImageResponse AResponse);
	void __fastcall GetAdapterItemRequestParams(AnsiString &AIdentifier, Sitecomp::_di_IAdapterItemRequestParams AParams);
	
public:
	__fastcall virtual TCustomDataSetAdapterImageField(Classes::TComponent* AOwner);
	__property TImageDataSetFieldGetImageEvent OnGetImage = {read=FOnGetImage, write=FOnGetImage};
	__property Webadapt::TImageFieldGetHREFEvent OnGetHREF = {read=FOnGetHREF, write=FOnGetHREF};
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TCustomDataSetAdapterImageField(void) { }
	#pragma option pop
	
private:
	void *__IGetAdapterImage;	/* Sitecomp::IGetAdapterImage */
	void *__IGetAdapterItemRequestParams;	/* Sitecomp::IGetAdapterItemRequestParams */
	void *__IAdapterRequestHandler;	/* Sitecomp::IAdapterRequestHandler */
	void *__IWebImageHREF;	/* Sitecomp::IWebImageHREF */
	
public:
	operator IWebImageHREF*(void) { return (IWebImageHREF*)&__IWebImageHREF; }
	operator IAdapterRequestHandler*(void) { return (IAdapterRequestHandler*)&__IAdapterRequestHandler; }
	operator IGetAdapterItemRequestParams*(void) { return (IGetAdapterItemRequestParams*)&__IGetAdapterItemRequestParams; }
	operator IGetAdapterImage*(void) { return (IGetAdapterImage*)&__IGetAdapterImage; }
	
};


class DELPHICLASS TDataSetAdapterImageField;
class PASCALIMPLEMENTATION TDataSetAdapterImageField : public TCustomDataSetAdapterImageField 
{
	typedef TCustomDataSetAdapterImageField inherited;
	
__published:
	__property DataSetField ;
	__property ViewAccess ;
	__property ModifyAccess ;
	__property OnGetImage ;
	__property OnGetHREF ;
	__property FieldModes  = {default=15};
public:
	#pragma option push -w-inl
	/* TCustomDataSetAdapterImageField.Create */ inline __fastcall virtual TDataSetAdapterImageField(Classes::TComponent* AOwner) : TCustomDataSetAdapterImageField(AOwner) { }
	#pragma option pop
	
public:
	#pragma option push -w-inl
	/* TWebContainedComponent.Destroy */ inline __fastcall virtual ~TDataSetAdapterImageField(void) { }
	#pragma option pop
	
};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Dbadaptimg */
using namespace Dbadaptimg;
#pragma option pop	// -w-
#pragma option pop	// -Vx

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DBAdaptImg
