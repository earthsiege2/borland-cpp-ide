//----------------------------------------------------------------------------
#ifndef OkCnHlp2H
#define OkCnHlp2H
//----------------------------------------------------------------------------
#include <OKCANCL2.h>
#include <vcl\ExtCtrls.hpp>
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
class TOKHelpRightDlg : public TOKRightDlg
{
__published:
	TButton *HelpBtn;
	void __fastcall HelpBtnClick(TObject *Sender);
private:
public:
	virtual __fastcall TOKHelpRightDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKHelpRightDlg *OKHelpRightDlg;
//----------------------------------------------------------------------------
#endif    
