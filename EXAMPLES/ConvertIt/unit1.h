//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTabControl *ConvFamilies;
        TListBox *ConvTypes;
        TUpDown *ConvValueIncDec;
        TListBox *ConvResults;
        TEdit *ConvValue;
        TStatusBar *StatusBar1;
        TMainMenu *MainMenu1;
        TMenuItem *Exit1;
        TMenuItem *About1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall ConvTypesClick(TObject *Sender);
        void __fastcall ConvFamiliesChange(TObject *Sender);
        void __fastcall ConvValueChange(TObject *Sender);
        void __fastcall mnCloseClick(TObject *Sender);
        void __fastcall About1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
