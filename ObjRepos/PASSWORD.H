//----------------------------------------------------------------------------
#ifndef PassWordH
#define PassWordH
//----------------------------------------------------------------------------
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
//----------------------------------------------------------------------------
class TPasswordDlg : public TForm
{
__published:
	TLabel *Label1;
	TEdit *Password;
	TButton *OKBtn;
	TButton *CancelBtn;
private:
public:
	virtual __fastcall TPasswordDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TPasswordDlg *PasswordDlg;
//----------------------------------------------------------------------------
#endif    
