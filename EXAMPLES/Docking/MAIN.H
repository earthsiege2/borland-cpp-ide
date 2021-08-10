//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
  TCoolBar *CoolBar1;
  TToolBar *ToolBar1;
  TToolButton *ToolButton13;
  TToolButton *ToolButton16;
  TToolButton *tbToolBar1;
  TToolButton *tbToolBar2;
  TToolBar *ToolBar2;
  TToolButton *tbWhite;
  TToolButton *tbBlue;
  TToolButton *tbGreen;
  TToolButton *tbLime;
  TToolButton *tbPurple;
  TToolButton *tbRed;
  TToolButton *tbTeal;
  TActionList *ActionList1;
  TAction *ViewToolBar1;
  TAction *ViewToolBar2;
  TAction *ViewWhiteWindow;
  TAction *ExitAction;
  TAction *ViewBlueWindow;
  TAction *ViewGreenWindow;
  TAction *ViewRedWindow;
  TAction *ViewTealWindow;
  TAction *ViewPurpleWindow;
  TAction *ViewLimeWindow;
  TMainMenu *MainMenu1;
  TMenuItem *File2;
  TMenuItem *Exit2;
  TMenuItem *View2;
  TMenuItem *ToolBar11;
  TMenuItem *ToolBar21;
  TMenuItem *N2;
  TMenuItem *mnuWhite;
  TMenuItem *mnuBlue;
  TMenuItem *mnuGreen;
  TMenuItem *mnuLime;
  TMenuItem *mnuPurple;
  TMenuItem *mnuRed;
  TMenuItem *mnuTeal;
  TSplitter *VSplitter;
  TSplitter *HSplitter;
  TPanel *LeftDockPanel;
  TPanel *BottomDockPanel;
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall CoolBar1DockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
  void __fastcall ExitActionExecute(TObject *Sender);
  void __fastcall ViewToolBar1Execute(TObject *Sender);
  void __fastcall ViewToolBar2Execute(TObject *Sender);
  void __fastcall GenericViewWindowExecute(TObject *Sender);
  void __fastcall LeftDockPanelDockDrop(TObject *Sender,
          TDragDockObject *Source, int X, int Y);
  void __fastcall LeftDockPanelDockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
  void __fastcall LeftDockPanelGetSiteInfo(TObject *Sender,
          TControl *DockClient, TRect &InfluenceRect, TPoint &MousePos,
          bool &CanDock);
  void __fastcall LeftDockPanelUnDock(TObject *Sender, TControl *Client,
          TWinControl *NewTarget, bool &Allow);
  void __fastcall BottomDockPanelDockOver(TObject *Sender,
          TDragDockObject *Source, int X, int Y, TDragState State,
          bool &Accept);
private:	// User declarations
  void CreateDockableWindows();
public:
  void ShowDockPanel(TPanel* APanel, bool MakeVisible, TControl* Client);
public:		// User declarations
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------

int VisibleDockClientCount(TWinControl* Control);


#endif
