//---------------------------------------------------------------------------

#ifndef ClientH
#define ClientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTelnet.hpp>
//---------------------------------------------------------------------------
class TTelnetForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblServer;
        TLabel *lblPort;
        TEdit *edtServer;
        TButton *btnConnect;
        TButton *btnDisconnect;
        TIdTelnet *IdTelnetDemo;
        TEdit *spnedtPort;
        TUpDown *UpDown1;
        TRichEdit *Memo1;
        TStatusBar *sbrStatus;
        void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btnConnectClick(TObject *Sender);
        void __fastcall btnDisconnectClick(TObject *Sender);
        void __fastcall Memo1KeyPress(TObject *Sender, char &Key);
        void __fastcall IdTelnetDemoDataAvailable(AnsiString Buffer);
        void __fastcall IdTelnetDemoConnected(TObject *Sender);
        void __fastcall IdTelnetDemoConnect();
private:	// User declarations
public:		// User declarations
        __fastcall TTelnetForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTelnetForm *TelnetForm;
//---------------------------------------------------------------------------
#endif
