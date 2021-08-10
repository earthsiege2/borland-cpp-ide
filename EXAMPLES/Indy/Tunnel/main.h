//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPServer.hpp>
#include <IdTunnelMaster.hpp>
#include <IdTunnelSlave.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TLabel *lblSlaves;
        TLabel *Label3;
        TLabel *lblServices;
        TLabel *Label4;
        TLabel *Label1;
        TPanel *Panel3;
        TLabel *lblClients;
        TLabel *Label5;
        TLabel *Label2;
        TPanel *Panel1;
        TBitBtn *btnStart;
        TBitBtn *btnStop;
        TTimer *tmrRefresh;
        TIdTunnelSlave *Slave;
        TIdTunnelMaster *Master;
        void __fastcall tmrRefreshTimer(TObject *Sender);
        void __fastcall btnStartClick(TObject *Sender);
        void __fastcall btnStopClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
