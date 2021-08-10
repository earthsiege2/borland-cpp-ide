//----------------------------------------------------------------------------
#ifndef servnameH
#define servnameH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
//----------------------------------------------------------------------------
class TServerNameDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
        TLabel *Label1;
        TLabel *ServerNameLabel;
        TEdit *ServerNameEdit;
        TLabel *Label2;
        TButton *ConnectButton;
        TLabel *Label3;
        TLabel *CountLabel;
        TLabel *ResultLabel;
        void __fastcall FormShow(TObject/* */ *Sender);
        void __fastcall ConnectButtonClick(TObject/* */ *Sender);
        void __fastcall OKBtnClick(TObject/* */ *Sender);
private:
public:
	virtual __fastcall TServerNameDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TServerNameDlg *ServerNameDlg;
//----------------------------------------------------------------------------
#endif    
