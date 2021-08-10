
//---------------------------------------------------------------------------

#ifndef ErrorPgH
#define ErrorPgH
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>

//---------------------------------------------------------------------------
class TErrorPage : public TWebPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
  TAdapter *ErrorAdapter;
  TAdapterField *ErrorMessageField;
  void __fastcall ErrorMessageFieldGetValue(TObject *Sender,
          Variant &Value);
private:	// User declarations
public:		// User declarations
  AnsiString ErrorMessage;
};

TErrorPage *ErrorPage();

//---------------------------------------------------------------------------
extern PACKAGE TErrorPage *ErrorPage();
//---------------------------------------------------------------------------
#endif

