//---------------------------------------------------------------------------
#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TPackageForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TListBox *ListBox1;
        TListBox *ListBox2;
        TCheckBox *CheckBox1;
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TPackageForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
#endif
