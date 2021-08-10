//---------------------------------------------------------------------------
#ifndef tabhostH
#define tabhostH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TTabDockHost : public TForm
{
__published:	// IDE-managed Components
  TPageControl *PageControl1;
  void __fastcall PageControl1DockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
  void __fastcall PageControl1GetSiteInfo(TObject *Sender,
          TControl *DockClient, TRect &InfluenceRect, TPoint &MousePos,
          bool &CanDock);
  void __fastcall PageControl1UnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  __fastcall TTabDockHost(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TTabDockHost *TabDockHost;
//---------------------------------------------------------------------------
#endif
