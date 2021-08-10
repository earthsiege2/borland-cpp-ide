//---------------------------------------------------------------------------
#ifndef CustDrawH
#define CustDrawH
//---------------------------------------------------------------------------

#include <Windows.hpp>
#include <Messages.hpp>
#include <SysUtils.hpp>
#include <ExtDlgs.hpp>
#include <ColorGrd.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>

//---------------------------------------------------------------------------
class TCustomDrawForm : public TForm
{
__published:	// IDE-managed Components
   TTreeView*     TV;
   TImageList*    ImageList;
   TMainMenu*     MainMenu1;
   TMenuItem*     Drawing1;
   TMenuItem*     Font1;
   TMenuItem*     Background1;
   TMenuItem*     Color1;
   TMenuItem*     Bitmap1;
   TMenuItem*     DefaultDrawing1;
   TMenuItem*     OnCustomDraw1;
   TMenuItem*     OnCustomDrawItem1;
   TMenuItem*     BrushStyle1;
   TMenuItem*     Solid1;
   TMenuItem*     Clear1;
   TMenuItem*     Horizontal1;
   TMenuItem*     Vertical1;
   TMenuItem*     FDiagonal1;
   TMenuItem*     BDiagonal1;
   TMenuItem*     Cross1;
   TMenuItem*     DiagCross1;
   TMenuItem*     File1;
   TMenuItem*     Exit1;
   TMenuItem*     N2;
   TFontDialog*   TVFontDialog;
   TMenuItem*     Tile1;
   TMenuItem*     Stretch1;
   TMenuItem*     None1;
   TMenuItem*     Selection1;
   TFontDialog*   SelectedFontDialog;
   TColorDialog*  BkgColorDialog;
   TColorDialog*  SelBkgColorDialog;
   TMenuItem*     SelectionBackground1;
   TMenuItem*     ButtonColor1;
   TMenuItem*     ButtonSize1;
   TColorDialog*  ButtonColorDialog;
   TImage*        Image1;
   TMenuItem*     TreeView1;
   TMenuItem*     Color2;
   TColorDialog*  TVColorDialog;
   TMenuItem*     CustomDraw1;
   TMenuItem*     Font2;
   void __fastcall FormCreate(TObject* Sender);
   void __fastcall TVCustomDraw(TCustomTreeView* Sender, const TRect& ARect, bool &DefaultDraw);
   void __fastcall TVCustomDrawItem(TCustomTreeView* Sender, TTreeNode* Node, TCustomDrawState State, bool &DefaultDraw);
   void __fastcall TVGetImageIndex(TObject* Sender, TTreeNode* Node);
   void __fastcall TVGetSelectedIndex(TObject* Sender, TTreeNode* Node);
   void __fastcall Exit1Click(TObject* Sender);
   void __fastcall Selection1Click(TObject* Sender);
   void __fastcall Color1Click(TObject* Sender);
   void __fastcall SelectionBackground1Click(TObject* Sender);
   void __fastcall Solid1Click(TObject* Sender);
   void __fastcall None1Click(TObject* Sender);
   void __fastcall OnCustomDraw1Click(TObject* Sender);
   void __fastcall OnCustomDrawItem1Click(TObject* Sender);
   void __fastcall TVExpanded(TObject* Sender, TTreeNode* Node);
   void __fastcall ButtonColor1Click(TObject* Sender);
   void __fastcall ButtonSize1Click(TObject* Sender);
   void __fastcall Drawing1Click(TObject* Sender);
   void __fastcall Color2Click(TObject* Sender);
   void __fastcall CustomDraw1Click(TObject* Sender);
   void __fastcall Font2Click(TObject* Sender);
private:	// User declarations
   int            FButtonSize;
   bool           FDefaultDraw;
   bool           FDefaultDrawItem;
   TColor         FBackgroundColor;
   TBrushStyle    FBrushStyle;
   void __fastcall DrawButton(TRect* ARect, TTreeNode* Node);
   void __fastcall DrawImage(TRect* NodeRect, int ImageIndex);
   void __fastcall SetCustomDraw(bool Value);
public:		// User declarations
   __fastcall TCustomDrawForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCustomDrawForm *CustomDrawForm;
//---------------------------------------------------------------------------

#endif

