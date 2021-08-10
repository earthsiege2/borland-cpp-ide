//---------------------------------------------------------------------------
#ifndef ftpmainH
#define ftpmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <NMFtp.hpp>
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
        TLabel *Label16;
        TLabel *Label17;
        TEdit *HostTxt;
        TEdit *PortTxt;
        TButton *Button1;
        TButton *Button2;
        TEdit *UserTxt;
        TEdit *PassTxt;
        TCheckBox *CheckBox1;
        TEdit *Edit6;
        TEdit *Edit7;
        TTabSheet *TabSheet2;
        TMemo *Memo1;
        TButton *Button3;
        TButton *Button4;
        TTabSheet *TabSheet3;
        TLabel *Label6;
        TEdit *DirTxt;
        TButton *Button5;
        TTabSheet *TabSheet4;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *RemoteTxt;
        TEdit *LocalTxt;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TTabSheet *TabSheet6;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label9;
        TEdit *Edit3;
        TEdit *Edit4;
        TButton *Button10;
        TButton *Button11;
        TButton *Button9;
        TButton *Button12;
        TButton *Button13;
        TEdit *PosTxt;
        TTabSheet *TabSheet5;
        TLabel *Label10;
        TLabel *Label13;
        TEdit *Edit1;
        TEdit *Edit2;
        TButton *Button14;
        TButton *Button15;
        TTabSheet *TabSheet7;
        TLabel *Label14;
        TEdit *Edit5;
        TButton *Button16;
        TTabSheet *TabSheet8;
        TLabel *Label15;
        TButton *Button17;
        TTabSheet *Tabsheet9;
        TLabel *Label18;
        TLabel *Label19;
        TEdit *Edit8;
        TEdit *Edit9;
        TButton *Button18;
        TStatusBar *StatusBar1;
        TNMFTP *NMFTP1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall NMFTP1Connect(TObject *Sender);
        void __fastcall NMFTP1ConnectionFailed(TObject *Sender);
        void __fastcall NMFTP1Disconnect(TObject *Sender);
        void __fastcall NMFTP1Error(TComponent *Sender, WORD Errno,
      AnsiString Errmsg);
        void __fastcall NMFTP1Failure(bool &handled, TCmdType Trans_Type);
        void __fastcall NMFTP1HostResolved(TComponent *Sender);
        void __fastcall NMFTP1InvalidHost(bool &handled);
        void __fastcall NMFTP1ListItem(AnsiString Listing);
        void __fastcall NMFTP1PacketRecvd(TObject *Sender);
        void __fastcall NMFTP1PacketSent(TObject *Sender);
        void __fastcall NMFTP1Status(TComponent *Sender,
      AnsiString Status);
        void __fastcall NMFTP1Success(TCmdType Trans_Type);
        void __fastcall NMFTP1TransactionStart(TObject *Sender);
        void __fastcall NMFTP1TransactionStop(TObject *Sender);
        void __fastcall NMFTP1UnSupportedFunction(TCmdType Trans_Type);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
