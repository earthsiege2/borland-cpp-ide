//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef menuH
#define menuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Quickrpt.hpp>
#include <quickrpt.hpp>
#include <Graphics.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TImage *Image2;
	TGroupBox *GroupBox1;
	TRadioButton *SimpleList;
	TRadioButton *GroupedList;
	TRadioButton *MasterDetail;
	TRadioButton *SQLMasterDetail;
	TMemo *Description;
   TRadioButton *Composite;
	TButton *Preview;
	TButton *Print;
	TButton *Exit;
	TQuickRep *CompositeReport;
	TQRCompositeReport *QRCompositeReport1;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall SimpleListClick(TObject *Sender);
	void __fastcall GroupedListClick(TObject *Sender);
	void __fastcall MasterDetailClick(TObject *Sender);
	void __fastcall SQLMasterDetailClick(TObject *Sender);
	void __fastcall CompositeClick(TObject *Sender);
	void __fastcall QRCompositeReport1AddReports(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall PrintClick(TObject *Sender);
	void __fastcall PreviewClick(TObject *Sender);
   
private:	// User declarations
   TQuickRep * FReport;
	void SetReport(TQuickRep *);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
   __property TQuickRep * Report = {read = FReport, write = SetReport};
};
//---------------------------------------------------------------------------
extern TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
