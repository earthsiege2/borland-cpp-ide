//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
// ResltFrm.hpp - dcc32 generated hdr (DO NOT EDIT) rev: 0
// From: ResltFrm.pas
//----------------------------------------------------------------------------
#ifndef ResltFrmHPP
#define ResltFrmHPP
//----------------------------------------------------------------------------
#include <StdCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Graphics.hpp>
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <System.hpp>
#include <Db.hpp>

//-- type declarations -------------------------------------------------------
class TQueryForm : public TForm
{
__published:
	TLabel* QueryLabel;
	TDBGrid* DBGrid1;
	TDataSource* DataSource;
	TQuery* Query;
	TSession *BKSession;
	TLabel* StatusLine;
	TDatabase *BKDatabase;
public:
	/* TForm.Create */ __fastcall virtual TQueryForm(TComponent* AOwner);
	/* TForm.CreateNew */ __fastcall TQueryForm(TComponent* AOwner, int Dummy);
    /* TWinControl.CreateParented */ __fastcall TQueryForm(HWND ParentWindow);
	/* TForm.Destroy */ __fastcall virtual ~TQueryForm(void);

};

class TQueryThread : public TThread
{
private:
	TQueryForm* QueryForm;
	AnsiString MessageText;
	void __fastcall ConnectQuery(void);
	void __fastcall DisplayMessage(void);

protected:
	virtual void __fastcall Execute(void);

public:
	__fastcall TQueryThread(TQueryForm* AQueryForm);
	__fastcall virtual ~TQueryThread(void);
};

//-- var, const, procedure ---------------------------------------------------
extern void __fastcall BackgroundQuery(const AnsiString QueryName, const AnsiString Alias, const AnsiString
	User, const AnsiString Password, const AnsiString QueryText);
//-- end unit ----------------------------------------------------------------
#endif	// ResltFrm
