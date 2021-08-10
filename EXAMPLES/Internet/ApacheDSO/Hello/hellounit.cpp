//---------------------------------------------------------------------------
#include "HelloUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TWebModule1::WebModule1waHelloAction(TObject *Sender,
      TWebRequest *Request, TWebResponse *Response, bool &Handled)
{
  Response->Content = "Hello, BCB Developer";
          
}
//---------------------------------------------------------------------------
