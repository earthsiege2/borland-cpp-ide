//----------------------------------------------------------------------------
#ifndef ClxOkCancl1H
#define ClxOkCancl1H
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <QGraphics.hpp>
#include <QForms.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QButtons.hpp>
#include <QExtCtrls.hpp>
//----------------------------------------------------------------------------
class TOKBottomDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
private:
public:
	virtual __fastcall TOKBottomDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg *OKBottomDlg;
//----------------------------------------------------------------------------
#endif    
