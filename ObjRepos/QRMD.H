//----------------------------------------------------------------------------
#ifndef QRMDH
#define QRMDH
//----------------------------------------------------------------------------
#include <vcl\ExtCtrls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Quickrpt.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
//----------------------------------------------------------------------------
class TQRMDForm : public TForm
{
__published:
        TQuickRep *QuickRep1;
	TTable *MasterTable; 
	TQRBand *DetailBand1;
	TQRBand *PageFooterBand1;
	TQRBand *TitleBand1;
	TQRBand * ColumnHeaderBand1;
	TQRSysData *QRSysData1;
	TQRLabel *QRLabel1;
	TQRLabel *QRLabel2;
	TQRSysData *QRSysData2;
	TTable *DetailTable;
	TQRSubDetail *QRSubDetail1;  
	TDataSource *MasterDS;
private:
public:
	virtual __fastcall TQRMDForm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TQRMDForm *QRMDForm;
//----------------------------------------------------------------------------
#endif    
