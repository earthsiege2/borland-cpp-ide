//---------------------------------------------------------------------------
#ifndef pickrepH
#define pickrepH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TPickRpt : public TForm
{
__published:	// IDE-managed Components
	TButton *OKBtn;
	TButton *CloseBtn;
	TButton *ViewBtn;
	TRadioGroup *ReportType;
	void __fastcall OKBtnClick(TObject *Sender);
	void __fastcall ViewBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPickRpt(TComponent* Owner);
    bool Preview;
};
//---------------------------------------------------------------------------
extern TPickRpt *PickRpt;
//---------------------------------------------------------------------------
#endif
