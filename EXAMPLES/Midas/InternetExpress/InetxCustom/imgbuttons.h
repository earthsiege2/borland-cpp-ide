//---------------------------------------------------------------------------

#ifndef ImgButtonsH
#define ImgButtonsH
//---------------------------------------------------------------------------

#include <MidItems.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#define __IXMLDocument_INTERFACE_DEFINED__
#include <XMLBrokr.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Imgbuttons
{
class PACKAGE TImgDataNavigator : public Miditems::TDataNavigator
{
	typedef Miditems::TDataNavigator inherited;
	
private:
	AnsiString FImagePathURL;
	void __fastcall SetImagePathURL(const AnsiString Value);
	
protected:
	virtual void __fastcall GetDefaultButtons(void);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	
__published:
	__property AnsiString ImagePathURL = {read=FImagePathURL, write=SetImagePathURL};
public:
	#pragma option push -w-inl
	inline __fastcall virtual TImgDataNavigator(Classes::TComponent* AOwner) : Miditems::TDataNavigator(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgDataNavigator(void) { }
	#pragma option pop

};

class PACKAGE TImgDataSetButton : public Miditems::TXMLDisplayReferenceButton
{
	typedef Miditems::TXMLDisplayReferenceButton inherited;
	friend class TImgDataNavigator;
private:
	AnsiString FSrc;
	AnsiString FAlt;
	bool FBorder;
	AnsiString FPathURL;
	
protected:
	AnsiString DefaultAlt;
	AnsiString DefaultSrc;
	AnsiString XMLMethodName;
	void __fastcall AddElements(_di_IAddScriptElements AddIntf);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
	void __fastcall SetPathURL(AnsiString APath);
	AnsiString __fastcall GetAlt();
	AnsiString __fastcall GetSrc();
	virtual AnsiString __fastcall GetMethodName();
	AnsiString __fastcall GetSrcUrl();
	
__published:
	__property XMLComponent ;
	__property XMLUseParent ;
	__property Style ;
	__property Custom ;
	__property AnsiString Alt = {read=GetAlt, write=FAlt};
	__property StyleRule ;
	__property AnsiString Src = {read=GetSrc, write=FSrc};
	__property bool Border = {read=FBorder, write=FBorder, nodefault};
public:
	#pragma option push -w-inl
	inline __fastcall virtual TImgDataSetButton(Classes::TComponent* AOwner) : Miditems::TXMLDisplayReferenceButton(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgDataSetButton(void) { }
	#pragma option pop

private:
	void *__IImgComponent;	/* Imgbuttons::IImgComponent */
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	
public:
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }

};

class PACKAGE TImgFirstButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgFirstButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgFirstButton(void) { }
	#pragma option pop

};

class PACKAGE TImgLastButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgLastButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgLastButton(void) { }
	#pragma option pop

};

class PACKAGE TImgPriorButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgPriorButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgPriorButton(void) { }
	#pragma option pop

};

class PACKAGE TImgNextButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgNextButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgNextButton(void) { }
	#pragma option pop

};

class PACKAGE TImgPriorPageButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgPriorPageButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgPriorPageButton(void) { }
	#pragma option pop

};

class PACKAGE TImgNextPageButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgNextPageButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgNextPageButton(void) { }
	#pragma option pop

};

class PACKAGE TImgUndoButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;

public:
	__fastcall virtual TImgUndoButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgUndoButton(void) { }
	#pragma option pop

};

class PACKAGE TImgDeleteButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgDeleteButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgDeleteButton(void) { }
	#pragma option pop

};

class PACKAGE TImgInsertButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;
	
public:
	__fastcall virtual TImgInsertButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgInsertButton(void) { }
	#pragma option pop

};


class PACKAGE TImgPostButton : public TImgDataSetButton
{
	typedef TImgDataSetButton inherited;

public:
	__fastcall virtual TImgPostButton(Classes::TComponent* AOwner);
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgPostButton(void) { }
	#pragma option pop

};

class PACKAGE TImgApplyUpdatesButton : public Miditems::TApplyUpdatesButton
{
	typedef Miditems::TApplyUpdatesButton inherited;
        friend class TImgDataNavigator;
	
private:
	AnsiString FPathURL;
	AnsiString FAlt;
	AnsiString FSrc;
	bool FBorder;
	AnsiString __fastcall GetAlt();
	AnsiString __fastcall GetSrc();
	
protected:
	AnsiString DefaultAlt;
	AnsiString DefaultSrc;
	AnsiString __fastcall GetSrcUrl();
	void __fastcall SetPathURL(AnsiString APath);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);

__published:
	__property AnsiString Alt = {read=GetAlt, write=FAlt};
	__property AnsiString Src = {read=GetSrc, write=FSrc};
	__property bool Border = {read=FBorder, write=FBorder, nodefault};
public:
	__fastcall virtual TImgApplyUpdatesButton(Classes::TComponent* AOwner);
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgApplyUpdatesButton(void) { }
	#pragma option pop

};


//-- var, const, procedure ---------------------------------------------------

}	/* namespace Imgbuttons */
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Imgbuttons;
#endif

//---------------------------------------------------------------------------
#endif
 