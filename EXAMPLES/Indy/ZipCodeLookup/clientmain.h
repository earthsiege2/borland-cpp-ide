//---------------------------------------------------------------------------

#ifndef ClientMainH
#define ClientMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <IdAntiFreeze.hpp>
#include <IdAntiFreezeBase.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TformMain : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TMemo *memoInput;
        TPanel *Panel2;
        TListBox *lboxResults;
        TPanel *Panel3;
        TLabel *Label1;
        TButton *butnLookup;
        TButton *butnClear;
        TIdTCPClient *Client;
        TIdAntiFreeze *IdAntiFreeze1;
        void __fastcall butnClearClick(TObject *Sender);
        void __fastcall butnLookupClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TformMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformMain *formMain;
//---------------------------------------------------------------------------
#endif
