//---------------------------------------------------------------------------
#ifndef dockformH
#define dockformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TDockableForm : public TForm
{
__published:	// IDE-managed Components
  TMemo *Memo1;
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
  void __fastcall FormShow(TObject *Sender);
private:	// User declarations
  TAlign ComputeDockingRect(TRect & DockRect, const TPoint & MousePos);

  void virtual __fastcall CMDockClient(TCMDockClient& Message);
  BEGIN_MESSAGE_MAP
  MESSAGE_HANDLER(CM_DOCKCLIENT, TCMDockClient, CMDockClient)
  // Add any number of additional message handlers here.
  END_MESSAGE_MAP(TForm)

public:		// User declarations
  __fastcall TDockableForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDockableForm *DockableForm;
//---------------------------------------------------------------------------
#endif
