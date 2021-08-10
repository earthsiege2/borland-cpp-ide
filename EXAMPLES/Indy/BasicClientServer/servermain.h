//---------------------------------------------------------------------------

#ifndef ServerMainH
#define ServerMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPServer.hpp>
//---------------------------------------------------------------------------
class TfrmServer : public TForm
{
__published:	// IDE-managed Components
        TIdTCPServer *TCPServer;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TCPServerExecute(TIdPeerThread *AThread);
private:	// User declarations
public:		// User declarations
        __fastcall TfrmServer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmServer *frmServer;
//---------------------------------------------------------------------------
#endif
