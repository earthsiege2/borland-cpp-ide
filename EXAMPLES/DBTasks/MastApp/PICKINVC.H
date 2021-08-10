//---------------------------------------------------------------------------
#ifndef pickinvcH
#define pickinvcH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
//---------------------------------------------------------------------------
class TPickOrderNoDlg : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TButton *CancelBtn;
	TButton *OKBtn;
	TDBLookupListBox *DBLookupListBox1;
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPickOrderNoDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TPickOrderNoDlg *PickOrderNoDlg;
//---------------------------------------------------------------------------
#endif
