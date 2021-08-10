//---------------------------------------------------------------------------

#ifndef ParserH
#define ParserH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdURI.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *lblProtocol;
        TLabel *lblHost;
        TLabel *lblPort;
        TLabel *lblPath;
        TLabel *lblDocument;
        TLabel *lblURI;
        TLabel *lblInstructions;
        TEdit *edtURI;
        TEdit *edtProtocol;
        TEdit *edtHost;
        TEdit *edtPort;
        TEdit *edtPath;
        TEdit *edtDocument;
        TButton *btnDoIt;
        void __fastcall btnDoItClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
