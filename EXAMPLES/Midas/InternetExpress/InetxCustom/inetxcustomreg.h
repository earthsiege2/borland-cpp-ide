//---------------------------------------------------------------------------

#ifndef inetxcustomregH
#define inetxcustomregH
//---------------------------------------------------------------------------
#include <MidItems.hpp>	// Pascal unit
#include <PagItems.hpp>	// Pascal unit
#include <WebComp.hpp>	// Pascal unit
#include <XMLBrokr.hpp>	// Pascal unit
#include <Midas.hpp>	// Pascal unit
#include <DBClient.hpp>	// Pascal unit
#include <Db.hpp>	// Pascal unit
#include <HTTPApp.hpp>	// Pascal unit
#include <Classes.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.hpp>	// Pascal unit

#include "ShowXML.h"
#include "WebComp.hpp"
#include "ReconcileProd.h"
#include "ImgButtons.h"


namespace Inetxcustomreg
{
class PACKAGE TImgButtonsEditorHelper : public TWebComponentsEditorHelper
{
	typedef TWebComponentsEditorHelper inherited;

protected:
	bool __fastcall ImplCanAddClassHelper(Classes::TComponent* AEditor, Classes::TComponent* AParent, TMetaClass* AClass);

public:
	#pragma option push -w-inl
	inline __fastcall TImgButtonsEditorHelper(void) : TWebComponentsEditorHelper() { }
	#pragma option pop
	#pragma option push -w-inl
	inline __fastcall virtual ~TImgButtonsEditorHelper(void) { }
	#pragma option pop

};
};  // namespace
#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using namespace Inetxcustomreg;
#endif

#endif
