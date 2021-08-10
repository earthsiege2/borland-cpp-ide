//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
#ifndef CustViewHPP
#define CustViewHPP
//----------------------------------------------------------------------------
#ifndef MenusHPP
#include <Menus.hpp>
#include <StdCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#endif

#ifndef ButtonsHPP
#include <Buttons.hpp>
#endif

#ifndef MaskHPP
#include <Mask.hpp>
#endif

#ifndef StdCtrlsHPP
#include <StdCtrls.hpp>
#endif

#ifndef ComCtrlsHPP
#include <ComCtrls.hpp>
#endif

#ifndef DBGridsHPP
#include <DBGrids.hpp>
#endif

#ifndef GridsHPP
#include <Grids.hpp>
#endif

#ifndef DBCtrlsHPP
#include <DBCtrls.hpp>
#endif

#ifndef ExtCtrlsHPP
#include <ExtCtrls.hpp>
#endif

#ifndef DialogsHPP
#include <Dialogs.hpp>
#endif

#ifndef FormsHPP
#include <Forms.hpp>
#endif

#ifndef ControlsHPP
#include <Controls.hpp>
#endif

#ifndef GraphicsHPP
#include <Graphics.hpp>
#endif

#ifndef ClassesHPP
#include <Classes.hpp>
#endif

#ifndef SysUtilsHPP
#include <SysUtils.hpp>
#endif

#ifndef MessagesHPP
#include <Messages.hpp>
#endif

#ifndef WindowsHPP
#include <Windows.hpp>
#endif

#ifndef SystemHPP
#include <System.hpp>
#endif

//-- type declarations -------------------------------------------------------
class __declspec(delphiclass) TfmCustView;
class TfmCustView : public TForm
{
	typedef TfmCustView ThisClass;
	typedef TForm inherited;
	
__published:
	TStatusBar *StatusBar1;
	TDBGrid *DBGrid2;
	TLabel *Label3;
	TMainMenu *MainMenu1;
	TMenuItem *About1;
	TDBNavigator *DBNavigator1;
	TLabel *Label2;
	TRadioGroup *rgDataSet;
	TSpeedButton *SpeedButton1;
	TDBGrid *DBGrid1;
	TGroupBox *GroupBox1;
	TCheckBox *cbFilterOrders;
	TLabel *Label1;
	TEdit *Edit1;
	void __fastcall rgDataSetClick(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall cbFilterOrdersClick(TObject *Sender);
	void __fastcall About1Click(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall DBGrid1Enter(TObject *Sender);
	void __fastcall DBGrid2Enter(TObject *Sender);

public:
	__fastcall virtual TfmCustView(TComponent *);
};

//-- var, const, procedure ---------------------------------------------------
extern TfmCustView *fmCustView;
//-- end unit ----------------------------------------------------------------
#endif	// CustView
