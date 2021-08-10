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
#include <IdEcho.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TformEchoTest : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblTextToEcho;
        TLabel *lblTotalTime;
        TLabel *lblEchoServer;
        TLabel *lblReceivedText;
        TLabel *lablTime;
        TLabel *lablReceived;
        TEdit *edtSendText;
        TEdit *edtEchoServer;
        TButton *btnConnect;
        TButton *btnDisconnect;
        TButton *Button1;
        TIdEcho *IdEcoTestConnection;
        void __fastcall btnConnectClick(TObject *Sender);
        void __fastcall btnDisconnectClick(TObject *Sender);
        void __fastcall edtEchoServerChange(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
private:	// User declarations
public:		// User declarations
        __fastcall TformEchoTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformEchoTest *formEchoTest;
//---------------------------------------------------------------------------
#endif
