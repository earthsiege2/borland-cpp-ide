//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdQotd.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TfrmQuoteOfTheDayDemo : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblServer;
        TLabel *lblQuote;
        TMemo *mmoQuoteOfTheDay;
        TEdit *edtQuoteDayServer;
        TButton *btnQuote;
        TIdQOTD *IdQtdDemo;
        void __fastcall btnQuoteClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmQuoteOfTheDayDemo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmQuoteOfTheDayDemo *frmQuoteOfTheDayDemo;
//---------------------------------------------------------------------------
#endif
