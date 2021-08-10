//---------------------------------------------------------------------------
#ifndef msgmainH
#define msgmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <NMMSG.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TMemo *Memo1;
	TStatusBar *StatusBar1;
        TNMMSGServ *NMMSGServ1;
        TNMMsg *NMMsg1;
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall NMMSGServ1MSG(TComponent *Sender, const AnsiString sFrom,
	const AnsiString sMsg);
	void __fastcall NMMSGServ1ClientContact(TObject *Sender);
	void __fastcall NMMSGServ1Status(TComponent *Sender, AnsiString Status);
	void __fastcall NMMsg1Connect(TObject *Sender);
	void __fastcall NMMsg1ConnectionFailed(TObject *Sender);
	void __fastcall NMMsg1Status(TComponent *Sender, AnsiString Status);
	void __fastcall NMMsg1MessageSent(TObject *Sender);
	void __fastcall NMMsg1InvalidHost(bool &handled);
	void __fastcall NMMsg1HostResolved(TComponent *Sender);
	void __fastcall NMMsg1Disconnect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
