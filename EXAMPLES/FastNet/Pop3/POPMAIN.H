//---------------------------------------------------------------------------
#ifndef popmainH
#define popmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <NMpop3.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button1;
	TButton *Button2;
	TTabSheet *TabSheet3;
	TLabel *Label11;
	TMemo *Memo3;
	TButton *Button4;
	TButton *Button5;
	TTabSheet *TabSheet2;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label12;
	TLabel *Label13;
	TMemo *Memo1;
	TPanel *Panel1;
	TLabel *Label5;
	TLabel *Label10;
	TButton *Button3;
	TEdit *Edit5;
	TButton *Button6;
	TButton *Button7;
	TMemo *Memo2;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TStatusBar *StatusBar1;
        TNMPOP3 *NMPOP31;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall NMPOP31Connect(TObject *Sender);
	void __fastcall NMPOP31ConnectionFailed(TObject *Sender);
	void __fastcall NMPOP31ConnectionRequired(bool &handled);
	void __fastcall NMPOP31Disconnect(TObject *Sender);
	void __fastcall NMPOP31Failure(TObject *Sender);
	void __fastcall NMPOP31HostResolved(TComponent *Sender);
	void __fastcall NMPOP31InvalidHost(bool &handled);
	void __fastcall NMPOP31List(int Msg, int Size);
	void __fastcall NMPOP31PacketRecvd(TObject *Sender);
	void __fastcall NMPOP31Reset(TObject *Sender);
	void __fastcall NMPOP31RetrieveEnd(TObject *Sender);
	void __fastcall NMPOP31RetrieveStart(TObject *Sender);
	void __fastcall NMPOP31Status(TComponent *Sender, AnsiString Status);
	void __fastcall NMPOP31Success(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
