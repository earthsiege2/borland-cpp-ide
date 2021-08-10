//----------------------------------------------------------------------------
#ifndef ClxOkCnHlp1H
#define ClxOkCnHlp1H
//----------------------------------------------------------------------------
#include <ClxOKCANCL1.h>
#include <Classes.hpp>
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
