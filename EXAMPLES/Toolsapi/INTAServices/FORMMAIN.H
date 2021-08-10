//---------------------------------------------------------------------------
#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
//---------------------------------------------------------------------------
class TDisplayForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TComboBox *ComboBox1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TButton *Button1;
        TImage *Image1;
        TOpenPictureDialog *OpenPictureDialog1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TDisplayForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
