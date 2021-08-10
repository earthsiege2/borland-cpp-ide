//---------------------------------------------------------------------------
#ifndef conjoinhostH
#define conjoinhostH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TConjoinDockHost : public TForm
{
__published:	// IDE-managed Components
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
  void __fastcall FormDockDrop(TObject *Sender, TDragDockObject *Source,
          int X, int Y);
  void __fastcall FormDockOver(TObject *Sender, TDragDockObject *Source,
          int X, int Y, TDragState State, bool &Accept);
  void __fastcall FormGetSiteInfo(TObject *Sender, TControl *DockClient,
          TRect &InfluenceRect, TPoint &MousePos, bool &CanDock);
  void __fastcall FormUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
private:	// User declarations
  void DoFloat(TControl* AControl);
public:
  void UpdateCaption(TControl* Exclude);
public:		// User declarations
  __fastcall TConjoinDockHost(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConjoinDockHost *ConjoinDockHost;
//---------------------------------------------------------------------------
#endif
