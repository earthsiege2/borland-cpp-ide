//---------------------------------------------------------------------------
#ifndef nntpmainH
#define nntpmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <NMNNTP.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit5;
	TEdit *Edit6;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TCheckBox *CheckBox1;
	TListBox *ListBox1;
	TTabSheet *TabSheet4;
	TPanel *Panel1;
	TButton *Button3;
	TButton *Button4;
	TEdit *Edit7;
	TMemo *Memo4;
	TTabSheet *TabSheet1;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TMemo *Memo1;
	TMemo *Memo2;
	TMemo *Memo3;
	TTabSheet *TabSheet2;
	TLabel *Label11;
	TLabel *Label12;
	TPanel *Panel2;
	TListBox *ListBox2;
	TButton *Button5;
	TButton *Button6;
	TMemo *Memo5;
	TPanel *Panel3;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TButton *Button7;
	TStatusBar *StatusBar1;
	TOpenDialog *OpenDialog1;
        TNMNNTP *NMNNTP1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall ListBox2DblClick(TObject *Sender);
	void __fastcall NMNNTP1Abort(TObject *Sender);
	void __fastcall NMNNTP1Article(TObject *Sender);
	void __fastcall NMNNTP1ArticleCacheUpdate(bool &Handled, int IdNo,
	AnsiString From, AnsiString Subject, AnsiString MsgId, AnsiString Date,
	int ArticleNo);
	void __fastcall NMNNTP1Body(TObject *Sender);
	void __fastcall NMNNTP1BodyCacheUpdate(bool &handled);
	void __fastcall NMNNTP1Connect(TObject *Sender);
	void __fastcall NMNNTP1ConnectionFailed(TObject *Sender);
	void __fastcall NMNNTP1ConnectionRequired(bool &handled);
	void __fastcall NMNNTP1Disconnect(TObject *Sender);
	void __fastcall NMNNTP1GroupListCacheUpdate(bool &Handled, AnsiString Name,
	int FirstArticle, int LastArticle, bool Posting);
	void __fastcall NMNNTP1GroupListUpdate(AnsiString Name, int FirstArticle,
	int LastArticle, bool Posting);
	void __fastcall NMNNTP1GroupSelect(TObject *Sender);
	void __fastcall NMNNTP1GroupSelectRequired(bool &handled);
	void __fastcall NMNNTP1Header(TObject *Sender);
	void __fastcall NMNNTP1HeaderCacheUpdate(bool &Handled, int IdNo,
	AnsiString From, AnsiString Subject, AnsiString MsgId, AnsiString Date,
	int ArticleNo);
	void __fastcall NMNNTP1HeaderList(TObject *Sender);
	void __fastcall NMNNTP1HeaderListCacheUpdate(bool &handled);
	void __fastcall NMNNTP1HostResolved(TComponent *Sender);
	void __fastcall NMNNTP1InvalidArticle(TObject *Sender);
	void __fastcall NMNNTP1InvalidHost(bool &handled);
	void __fastcall NMNNTP1Posted(TObject *Sender);
	void __fastcall NMNNTP1PostFailed(TComponent *Sender, WORD Errno,
	AnsiString Errmsg);
	void __fastcall NMNNTP1Status(TComponent *Sender, AnsiString Status);
	
private:	// User declarations
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
