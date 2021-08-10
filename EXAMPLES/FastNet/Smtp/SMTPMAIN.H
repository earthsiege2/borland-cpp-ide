//---------------------------------------------------------------------------
#ifndef smtpmainH
#define smtpmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <NMsmtp.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit4;
	TGroupBox *GroupBox1;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit5;
	TEdit *Edit6;
	TTabSheet *TabSheet2;
	TLabel *Label11;
	TMemo *Memo1;
	TPanel *Panel1;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TListBox *ListBox1;
	TButton *Button4;
	TButton *Button5;
	TEdit *Edit10;
	TButton *Button6;
	TTabSheet *TabSheet3;
	TLabel *Label3;
	TEdit *Edit3;
	TButton *Button3;
	TTabSheet *TabSheet4;
	TLabel *Label12;
	TLabel *Label13;
	TEdit *Edit11;
	TMemo *Memo2;
	TButton *Button7;
	TStatusBar *StatusBar1;
	TOpenDialog *OpenDialog1;
        TNMSMTP *NMSMTP1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall NMSMTP1Connect(TObject *Sender);
	void __fastcall NMSMTP1ConnectionFailed(TObject *Sender);
	void __fastcall NMSMTP1ConnectionRequired(bool &handled);
	void __fastcall NMSMTP1Disconnect(TObject *Sender);
	void __fastcall NMSMTP1EncodeEnd(AnsiString Filename);
	void __fastcall NMSMTP1EncodeStart(AnsiString Filename);
	void __fastcall NMSMTP1Failure(TObject *Sender);
	
	void __fastcall NMSMTP1HostResolved(TComponent *Sender);
	void __fastcall NMSMTP1InvalidHost(bool &handled);
	void __fastcall NMSMTP1MailListReturn(AnsiString MailAddress);
	void __fastcall NMSMTP1PacketSent(TObject *Sender);
	void __fastcall NMSMTP1RecipientNotFound(AnsiString Recipient);
	void __fastcall NMSMTP1SendStart(TObject *Sender);
	void __fastcall NMSMTP1Status(TComponent *Sender, AnsiString Status);
	void __fastcall NMSMTP1Success(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
