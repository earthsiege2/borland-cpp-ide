//---------------------------------------------------------------------------
#ifndef httpmainH
#define httpmainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <NMHttp.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet4;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TCheckBox *CheckBox1;
        TEdit *Edit11;
        TEdit *Edit12;
        TTabSheet *TabSheet1;
        TLabel *Label2;
        TLabel *Label3;
        TPanel *Panel1;
        TLabel *Label1;
        TSpeedButton *SpeedButton1;
        TLabel *Label8;
        TEdit *Edit1;
        TButton *Button1;
        TButton *Button4;
        TMemo *Memo1;
        TMemo *Memo2;
        TTabSheet *TabSheet2;
        TLabel *Label6;
        TLabel *Label7;
        TPanel *Panel2;
        TLabel *Label4;
        TLabel *Label5;
        TSpeedButton *SpeedButton2;
        TLabel *Label9;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button2;
        TMemo *Memo3;
        TMemo *Memo4;
        TTabSheet *TabSheet3;
        TLabel *Label12;
        TPanel *Panel3;
        TLabel *Label10;
        TSpeedButton *SpeedButton3;
        TLabel *Label11;
        TEdit *Edit4;
        TButton *Button3;
        TMemo *Memo5;
        TStatusBar *StatusBar1;
        TNMHTTP *NMHTTP1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall NMHTTP1Connect(TObject *Sender);
        void __fastcall NMHTTP1ConnectionFailed(TObject *Sender);
        void __fastcall NMHTTP1Disconnect(TObject *Sender);
        void __fastcall NMHTTP1Failure(CmdType Cmd);
        void __fastcall NMHTTP1HostResolved(TComponent *Sender);
        void __fastcall NMHTTP1InvalidHost(bool &handled);
        void __fastcall NMHTTP1PacketRecvd(TObject *Sender);
        void __fastcall NMHTTP1PacketSent(TObject *Sender);
        void __fastcall NMHTTP1Status(TComponent *Sender,
      AnsiString Status);
        void __fastcall NMHTTP1Success(CmdType Cmd);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
