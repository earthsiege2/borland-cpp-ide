//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include "Trayicon.h"
#include "trayicon.h"
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
        TPopupMenu *PopupMenu1;
        TMenuItem *Restore1;
        TMenuItem *N1;
        TMenuItem *Exit1;
        TImageList *ImageList1;
        TCheckBox *VisibleCheck;
        TCheckBox *AnimateCheck;
        TCheckBox *HideCheck;
        TTrayIcon *TrayIcon1;
        TEdit *IntervalEdit;
        TUpDown *IntervalUpDown;
        void __fastcall HideCheckClick(TObject *Sender);
        void __fastcall VisibleCheckClick(TObject *Sender);
        void __fastcall Restore1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall AnimateCheckClick(TObject *Sender);
        void __fastcall IntervalEditChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
