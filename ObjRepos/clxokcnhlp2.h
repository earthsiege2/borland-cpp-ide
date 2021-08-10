//----------------------------------------------------------------------------
#ifndef ClxOkCnHlp2H
#define ClxOkCnHlp2H
//----------------------------------------------------------------------------
#include <ClxOKCANCL2.h>
#include <SysUtils.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <QGraphics.hpp>
#include <QForms.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QButtons.hpp>
#include <QExtCtrls.hpp>
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
