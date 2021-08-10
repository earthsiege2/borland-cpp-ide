//---------------------------------------------------------------------------
#ifndef SimpleEcho_uH
#define SimpleEcho_uH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <SOAPHTTPDisp.hpp>
#include <SOAPHTTPPasInv.hpp>
#include <SOAPPasInv.hpp>
#include <WebBrokerSOAP.hpp>
#include <WSDLPub.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        THTTPSoapDispatcher *HTTPSoapDispatcher1;
        THTTPSoapCppInvoker *HTTPSoapCppInvoker1;
        TWSDLHTMLPublish *WSDLHTMLPublish1;
        void __fastcall WebModule1DefaultHandlerAction(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif

