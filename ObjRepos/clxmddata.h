//----------------------------------------------------------------------------
#ifndef ClxMdDataH
#define ClxMdDataH
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
class TMDDataForm : public TForm
{
__published:
    TPanel *MasterPanel;
    TPanel *DetailPanel;
    TDBNavigator *MasterNav;
    TDBNavigator *DetailNav;
    TDBGrid *MasterGrid;
    TDBGrid *DetailGrid;
    TDataSource *MasterSource;
    TDataSource *DetailSource;
private:
public:
	virtual __fastcall TMDDataForm(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TMDDataForm *MDDataForm;
//----------------------------------------------------------------------------
#endif