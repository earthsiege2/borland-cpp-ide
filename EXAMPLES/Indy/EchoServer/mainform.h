//---------------------------------------------------------------------------

#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdEchoServer.hpp>
#include <IdTCPServer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *lblStatus;
        TButton *btnExit;
        TIdECHOServer *IdECHOServer1;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall IdECHOServer1Connect(TIdPeerThread *AThread);
        void __fastcall IdECHOServer1Disconnect(TIdPeerThread *AThread);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
