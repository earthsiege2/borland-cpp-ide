//---------------------------------------------------------------------------

#ifndef FormMainH
#define FormMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *QueryCount;
        TLabel *ClientCount;
private:	// User declarations
        int FQueryCount;
        int FClientCount;
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        void __fastcall DecClientCount(void);
        void __fastcall IncClientCount(void);
        void __fastcall DecQueryCount(void);
        void __fastcall IncQueryCount(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
