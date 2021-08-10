//---------------------------------------------------------------------------
#ifndef fngrmainH
#define fngrmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <NMFngr.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label4;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TMemo *Memo1;
	TStatusBar *StatusBar1;
        TNMFinger *NMFinger1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall NMFinger1Connect(TObject *Sender);
	void __fastcall NMFinger1ConnectionFailed(TObject *Sender);
	void __fastcall NMFinger1Disconnect(TObject *Sender);
	void __fastcall NMFinger1HostResolved(TComponent *Sender);
	void __fastcall NMFinger1Status(TComponent *Sender, AnsiString Status);
	void __fastcall NMFinger1InvalidHost(bool &handled);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
