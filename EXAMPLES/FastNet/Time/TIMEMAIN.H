//---------------------------------------------------------------------------
#ifndef timemainH
#define timemainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <NMTime.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TPanel *Panel1;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TStatusBar *StatusBar1;
        TNMTime *NMTime1;
	void __fastcall NMTime1Connect(TObject *Sender);
	void __fastcall NMTime1ConnectionFailed(TObject *Sender);
	void __fastcall NMTime1Disconnect(TObject *Sender);
	void __fastcall NMTime1HostResolved(TComponent *Sender);
	void __fastcall NMTime1Status(TComponent *Sender, AnsiString Status);
	void __fastcall NMTime1InvalidHost(bool &handled);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
