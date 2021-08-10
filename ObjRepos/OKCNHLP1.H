//----------------------------------------------------------------------------
#ifndef OkCnHlp1H
#define OkCnHlp1H
//----------------------------------------------------------------------------
#include <OKCANCL1.h>
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
class TOKHelpBottomDlg : public TOKBottomDlg
{
__published:
	TButton *HelpBtn;
	void __fastcall HelpBtnClick(TObject *Sender);
private:
public:
	virtual __fastcall TOKHelpBottomDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKHelpBottomDlg *OKHelpBottomDlg;
//----------------------------------------------------------------------------
#endif    
