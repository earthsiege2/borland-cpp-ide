
//---------------------------------------------------------------------------

#ifndef DisplayOptionsPgH
#define DisplayOptionsPgH
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
class TDisplayOptionsPage : public TWebPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
  TAdapter *DisplayOptions;
  TAdapterAction *SubmitOptions;
  TAdapterField *PreferredThumbWidth;
  TAdapterField *MaxPicsPerPage;
  TAdapterField *MaxPicsPerRow;
  void __fastcall PreferredThumbWidthGetValue(TObject *Sender,
          Variant &Value);
  void __fastcall MaxPicsPerPageGetValue(TObject *Sender, Variant &Value);
  void __fastcall MaxPicsPerRowGetValue(TObject *Sender, Variant &Value);
  void __fastcall PreferredThumbWidthValidateValue(TObject *Sender,
          IActionFieldValue *AValue, bool &Handled);
  void __fastcall MaxPicsPerPageValidateValue(TObject *Sender,
          IActionFieldValue *AValue, bool &Handled);
  void __fastcall SubmitOptionsExecute(TObject *Sender, TStrings *Params);
private:	// User declarations
public:		// User declarations
};

TDisplayOptionsPage *DisplayOptionsPage();

//---------------------------------------------------------------------------
extern PACKAGE TDisplayOptionsPage *DisplayOptionsPage();
//---------------------------------------------------------------------------
#endif

