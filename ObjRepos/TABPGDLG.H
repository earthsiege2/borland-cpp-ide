//----------------------------------------------------------------------------
#ifndef TabPgDlgH
#define TabPgDlgH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\ComCtrls.hpp>
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
class TPagesDlg : public TForm
{
__published:
	TPanel *Panel1;
	TPanel *Panel2;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TButton *OKBtn;
	TButton *CancelBtn;
	TButton *HelpBtn;
private:
public:
	virtual __fastcall TPagesDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TPagesDlg *PagesDlg;
//----------------------------------------------------------------------------
#endif    
