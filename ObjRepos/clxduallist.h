//----------------------------------------------------------------------------
#ifndef ClxDualListH
#define ClxDualListH
//----------------------------------------------------------------------------
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <QGraphics.hpp>
#include <QForms.hpp>
#include <QControls.hpp>
#include <QStdCtrls.hpp>
#include <QButtons.hpp>
#include <QExtCtrls.hpp>
//----------------------------------------------------------------------------
class TDualListDlg : public TForm
{
__published:
	TButton *OKBtn;
	TButton *CancelBtn;
	TButton *HelpBtn;
	TListBox *SrcList;
	TListBox *DstList;
	TLabel *SrcLabel;
	TLabel *DstLabel;
	TSpeedButton *IncludeBtn;
	TSpeedButton *IncAllBtn;
	TSpeedButton *ExcludeBtn;
	TSpeedButton *ExAllBtn;
	void __fastcall IncludeBtnClick(TObject *Sender);
	void __fastcall ExcludeBtnClick(TObject *Sender);
	void __fastcall IncAllBtnClick(TObject *Sender);
	void __fastcall ExcAllBtnClick(TObject *Sender);
	void __fastcall MoveSelected(TCustomListBox *List, TStrings *Items);
	void __fastcall SetItem(TListBox *List, int Index);
	Integer __fastcall GetFirstSelection(TCustomListBox *List);
	void __fastcall SetButtons();
private:
public:
	virtual __fastcall TDualListDlg(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TDualListDlg *DualListDlg;
//----------------------------------------------------------------------------
#endif
