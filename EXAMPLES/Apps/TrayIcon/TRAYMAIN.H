//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef traymainH
#define traymainH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Graphics.hpp>
#define MYWM_NOTIFY         (WM_APP+100)
#define IDC_MYICON                     1006
extern HINSTANCE g_hinst;
LRESULT IconDrawItem(LPDRAWITEMSTRUCT lpdi);
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:
    TButton *Button1;
    TCheckBox *CheckBox1;
    TRadioButton *RadioButton1;
    TRadioButton *RadioButton2;
    TEdit *Edit1;
    TEdit *Edit2;
    TImage *Image2;
    TImage *Image1;
    TLabel *Label1;
    TLabel *Label2;
    TPopupMenu *PopupMenu1;
    TMenuItem *Properties1;
    TMenuItem *ToggleState1;
    TMenuItem *Shutdown1;
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall CheckBox1Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall RadioButtonClick(TObject *Sender);
    void __fastcall EditKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall Properties1Click(TObject *Sender);
    void __fastcall ToggleState1Click(TObject *Sender);
    void __fastcall Shutdown1Click(TObject *Sender);
    
    
private:        // private user declarations
    void __fastcall DrawItem(TMessage& Msg);
    void __fastcall MyNotify(TMessage& Msg);
    bool __fastcall TrayMessage(DWORD dwMessage);
    HICON __fastcall IconHandle(void);
    void __fastcall ToggleState(void);
    PSTR __fastcall TipText(void);
public:         // public user declarations
    virtual __fastcall TFormMain(TComponent* Owner);
BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_DRAWITEM,TMessage,DrawItem)
MESSAGE_HANDLER(MYWM_NOTIFY,TMessage,MyNotify)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
