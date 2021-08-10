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
class TformMain : public TForm
{
__published:	// IDE-managed Components
        TIdTCPServer *IdTCPServer1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall IdTCPServer1Connect(TIdPeerThread *AThread);
        void __fastcall IdTCPServer1Execute(TIdPeerThread *AThread);
private:	// User declarations
        TStrings *ZipCodeList;
public:		// User declarations
        __fastcall TformMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TformMain *formMain;
//---------------------------------------------------------------------------
#endif
