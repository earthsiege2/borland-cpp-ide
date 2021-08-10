//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdIcmpClient.hpp>
#include <IdRawBase.hpp>
#include <IdRawClient.hpp>
//---------------------------------------------------------------------------
class TTfrmPing : public TForm
{
__published:	// IDE-managed Components
        TListBox *lstReplies;
        TPanel *Panel1;
        TButton *btnPing;
        TEdit *edtHost;
        TIdIcmpClient *ICMP;
        void __fastcall btnPingClick(TObject *Sender);
        void __fastcall ICMPReply(TComponent *ASender,
          const TReplyStatus &AReplyStatus);
private:	// User declarations
public:		// User declarations
        __fastcall TTfrmPing(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTfrmPing *TfrmPing;
//---------------------------------------------------------------------------
#endif
