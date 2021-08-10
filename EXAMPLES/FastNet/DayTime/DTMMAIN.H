//---------------------------------------------------------------------------
#ifndef dtmmainH
#define dtmmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <NMDayTim.hpp>
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
	TButton *Button1;
	TLabel *Label3;
	TStatusBar *StatusBar1;
        TNMDayTime *NMDayTime1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall NMDayTime1Connect(TObject *Sender);
	void __fastcall NMDayTime1ConnectionFailed(TObject *Sender);
	void __fastcall NMDayTime1Disconnect(TObject *Sender);
	void __fastcall NMDayTime1HostResolved(TComponent *Sender);
	void __fastcall NMDayTime1InvalidHost(bool &handled);
	void __fastcall NMDayTime1Status(TComponent *Sender, AnsiString Status);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
 