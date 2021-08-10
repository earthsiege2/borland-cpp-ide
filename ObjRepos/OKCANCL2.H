//----------------------------------------------------------------------------
#ifndef OkCancl2H
#define OkCancl2H
//----------------------------------------------------------------------------
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
class TOKRightDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
private:
public:
	virtual __fastcall TOKRightDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKRightDlg *OKRightDlg;
//----------------------------------------------------------------------------
#endif    
