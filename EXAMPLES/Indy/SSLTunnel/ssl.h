//---------------------------------------------------------------------------

#ifndef sslH
#define sslH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdCoder.hpp>
#include <IdCoderMessageDigest.hpp>
#include <IdCoderText.hpp>
#include <IdComponent.hpp>
#include <IdFingerServer.hpp>
#include <IdGopherServer.hpp>
#include <IdHTTPServer.hpp>
#include <IdIMAP4Server.hpp>
#include <IdIntercept.hpp>
#include <IdLogBase.hpp>
#include <IdLogDebug.hpp>
#include <IdTCPServer.hpp>
#include <IdTelnetServer.hpp>
#include <IdThreadMgr.hpp>
#include <IdThreadMgrPool.hpp>
#include <OleServer.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTelnet.hpp>
#include <IdMappedPortTCP.hpp>
#include <IdSSLOpenSSL.hpp>
//---------------------------------------------------------------------------
class TformMain : public TForm
{
__published:	// IDE-managed Components
        TLabel *lablLocal;
        TLabel *Label2;
        TLabel *lablHost;
        TLabel *Label1;
        TLabel *Label3;
        TIdMappedPortTCP *MappedPort;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall MappedPortBeforeClientConnect(TComponent *ASender,
          TIdPeerThread *AThread, TIdTCPClient *AClient);
        void __fastcall SSLInterceptGetPassword(AnsiString &Password);
private:	// User declarations
public:		// User declarations
        __fastcall TformMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformMain *formMain;
//---------------------------------------------------------------------------
#endif
