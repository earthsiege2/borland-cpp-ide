//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <SOAPHTTPTrans.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *PanelTop;
        TPanel *PanelMid;
        TLabel *Label3;
        TMemo *Request;
        TMainMenu *MainMenu1;
        TMenuItem *File;
        TMenuItem *FileNew;
        TMenuItem *FileOpen;
        TMenuItem *FileSave;
        TMenuItem *FileExit;
        THTTPReqResp *HTTPReqResp1;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TButton *PostBtn;
        TLabel *Label1;
        TEdit *URL;
        TLabel *Label2;
        TEdit *SOAPAction;
        TPanel *PanelBottom;
        TLabel *Label4;
        TMemo *Response;
        TSplitter *Splitter1;
        TSplitter *Splitter2;
        void __fastcall FileNewClick(TObject *Sender);
        void __fastcall FileSaveClick(TObject *Sender);
        void __fastcall FileOpenClick(TObject *Sender);
  void __fastcall PostBtnClick(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FileExitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
