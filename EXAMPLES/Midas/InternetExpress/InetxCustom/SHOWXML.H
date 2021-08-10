//---------------------------------------------------------------------------

#ifndef showxmlH
#define showxmlH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <MidItems.hpp>
#include <XMLBrokr.hpp>
#include <WebComp.hpp>
//---------------------------------------------------------------------------

namespace Showxml
{

class PACKAGE TCustomShowXMLButton : public Miditems::TDataSetButton
{
	typedef Miditems::TDataSetButton inherited;

protected:
	AnsiString XMLMethodName;
	virtual void __fastcall ImplAddElements(_di_IAddScriptElements AddIntf);
	virtual AnsiString __fastcall ImplContent(Webcomp::TWebContentOptions* Options, System::TObject* ParentLayout);
public:
	#pragma option push -w-inl
	inline __fastcall virtual TCustomShowXMLButton(Classes::TComponent* AOwner) : Miditems::TDataSetButton(AOwner) { }
	#pragma option pop
	#pragma option push -w-inl
	inline __fastcall virtual ~TCustomShowXMLButton(void) { }
	#pragma option pop

private:
	void *__IScriptComponent;	/* Webcomp::IScriptComponent */
	
public:
	operator IScriptComponent*(void) { return (IScriptComponent*)&__IScriptComponent; }
	
};


class PACKAGE TShowXMLButton : public TCustomShowXMLButton
{
	typedef TCustomShowXMLButton inherited;
	
public:
	__fastcall virtual TShowXMLButton(Classes::TComponent* AOwner);
	
__published:
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TShowXMLButton(void) { }
	#pragma option pop

};


class PACKAGE TShowDeltaButton : public TCustomShowXMLButton
{
	typedef TCustomShowXMLButton inherited;

public:
	__fastcall virtual TShowDeltaButton(Classes::TComponent* AOwner);
	
__published:
public:
	#pragma option push -w-inl
	inline __fastcall virtual ~TShowDeltaButton(void) { }
	#pragma option pop

};

}; // namespace

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Showxml;
#endif

//---------------------------------------------------------------------------
#endif
