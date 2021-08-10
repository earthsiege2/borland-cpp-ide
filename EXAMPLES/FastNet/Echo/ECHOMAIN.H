//---------------------------------------------------------------------------
#ifndef echomainH
#define echomainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <NMEcho.hpp>
#include <Psock.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TLabel *Label5;
        TLabel *Label1;
        TPanel *Panel1;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button2;
        TButton *Button3;
        TEdit *Edit1;
        TEdit *Edit4;
        TButton *Button1;
        TButton *Button4;
        TStatusBar *StatusBar1;
        TNMEcho *NMEcho1;
        void __fastcall NMEcho1Connect(TObject *Sender);
        void __fastcall NMEcho1ConnectionFailed(TObject *Sender);
        void __fastcall NMEcho1ConnectionRequired(bool &handled);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall NMEcho1Disconnect(TObject *Sender);
        void __fastcall NMEcho1HostResolved(TComponent *Sender);
        void __fastcall NMEcho1InvalidHost(bool &handled);
        void __fastcall NMEcho1Status(TComponent *Sender,
      AnsiString Status);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
