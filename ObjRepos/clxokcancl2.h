//----------------------------------------------------------------------------
#ifndef ClxOkCancl2H
#define ClxOkCancl2H
//----------------------------------------------------------------------------
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
