//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000-2002 Borland Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "CustDraw.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TCustomDrawForm *CustomDrawForm;

//---------------------------------------------------------------------------
__fastcall TCustomDrawForm::TCustomDrawForm(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::FormCreate(TObject* Sender)
{
  FBackgroundColor = clWindow;
  FDefaultDraw = true;
  FDefaultDrawItem = true;
  FBrushStyle = bsSolid;
  FButtonSize = 5;
  BkgColorDialog -> Color = clWindow;
  SelBkgColorDialog -> Color = clHighlight;
  TVFontDialog -> Font -> Assign(TV -> Font);
  SelectedFontDialog -> Font -> Assign(TV -> Font);
  SelectedFontDialog -> Font -> Color = clHighlightText;
  SelBkgColorDialog -> Color = clHighlight;
  TVColorDialog -> Color = TV -> Color;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//This event should be used to draw any background colors or images.
//ARect represents the entire client area of the TreeView.
//Use the TreeView's canvas to do the drawing.
//Note that drawing a background bitmap is not really supported by CustomDraw,
//so scrolling can get messy. Best to subclass the TreeView and handle scrolling
//messages.
void __fastcall TCustomDrawForm::TVCustomDraw(TCustomTreeView* Sender, const TRect& ARect,
  bool &DefaultDraw)
{
   if (None1 -> Checked) {    // no picture
      TV -> Canvas -> Brush -> Color = BkgColorDialog -> Color;
      TV -> Canvas -> Brush -> Style = FBrushStyle;
      TV -> Canvas -> FillRect(ARect);
   }
   else {
      if (Tile1 -> Checked) {    // tile bitmap
         TV -> Canvas -> Brush -> Bitmap = Image1 -> Picture -> Bitmap;
         TV -> Canvas -> FillRect(ARect);
      }
      else     // Stretch across the canvas.
         TV -> Canvas -> StretchDraw(ARect, Image1 -> Picture -> Bitmap);
   }
   // setting DefaultDraw to false here prevents all calls to OnCustomDrawItem.
   DefaultDraw = FDefaultDraw;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::DrawButton(TRect* ARect, TTreeNode* Node)
{
   int cx, cy;
   cx = ARect -> Left + (TV -> Indent) / 2;
   cy = ARect -> Top + (ARect -> Bottom - ARect -> Top) / 2;
   TV -> Canvas -> Pen -> Color = ButtonColorDialog -> Color;
   // draw horizontal line.
   if (Node -> HasChildren) {
      TV -> Canvas -> PenPos = Point(cx + FButtonSize, cy);
      TV -> Canvas -> LineTo(ARect -> Left + TV -> Indent + FButtonSize, cy);
   }
   else {
      TV -> Canvas -> PenPos = Point(cx, cy);
      TV -> Canvas -> LineTo(ARect -> Left + TV -> Indent + FButtonSize, cy);
   }
   // draw half vertical line, top portion.
   TV -> Canvas -> PenPos = Point(cx, cy);
   TV -> Canvas -> LineTo(cx, (ARect -> Top) - 1);
   if ( ((Node -> GetNextVisible() != NULL) && (Node -> GetNextVisible() -> Level == Node -> Level))
      || (Node -> getNextSibling() != NULL) ) {
      // draw bottom portion of half vertical line.
      TV -> Canvas -> PenPos = Point(cx, cy);
      TV -> Canvas -> LineTo(cx, ARect -> Bottom + 1);
   }
   if (Node -> HasChildren) {
      // Let's try a circular button instead
      TV -> Canvas -> Ellipse(cx - FButtonSize, cy - FButtonSize, cx + FButtonSize, cy + FButtonSize);
      // draw the horizontal indicator.
      TV -> Canvas -> PenPos = Point(cx - FButtonSize + 2, cy);
      TV -> Canvas -> LineTo(cx + FButtonSize - 2, cy);
   }
   // draw the vertical indicator if the node is collapsed
   if ( !(Node -> Expanded) ) {
      TV -> Canvas -> PenPos = Point(cx, cy - FButtonSize + 2);
      TV -> Canvas -> LineTo(cx, cy + FButtonSize - 2);
      // now connect vertical lines of higher level nodes.
      Node = Node -> Parent;
   }
   while (Node != NULL) {
      cx -= TV -> Indent;
      if (Node -> getNextSibling() != NULL) {
         TV -> Canvas -> PenPos = Point(cx, ARect -> Top);
         TV -> Canvas -> LineTo(cx, ARect -> Bottom);
      }
      Node = Node -> Parent;
   }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::DrawImage(TRect* NodeRect, int ImageIndex)
{
   int cy;
   cy = NodeRect -> Top + (NodeRect -> Bottom - NodeRect -> Top)  / 2;
   // center image in NodeRect.
   ImageList -> Draw(TV -> Canvas, NodeRect -> Left, cy - TV -> Images -> Height / 2, ImageIndex, true);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::TVCustomDrawItem(TCustomTreeView* Sender, TTreeNode* Node,
   TCustomDrawState State, bool &DefaultDraw)
{
   TRect NodeRect;
   // If DefaultDraw it is true, any of the node's font properties can be
   // changed. Note also that when DefaultDraw = True, Windows draws the
   // buttons and ignores our font background colors, using instead the
   // TreeView's Color property.
   if (State.Contains(cdsSelected)) { // in State then
      TV -> Canvas -> Font -> Assign(SelectedFontDialog -> Font);
      TV -> Canvas -> Brush -> Color = SelBkgColorDialog -> Color;
   }
   DefaultDraw = FDefaultDrawItem;
   // DefaultDraw = False means you have to handle all the item drawing yourself,
   // including the buttons, lines, images, and text.
   if ( !DefaultDraw ) {
      // draw the selection rect.
      if (State.Contains(cdsSelected)) { // in State then
         NodeRect = Node -> DisplayRect(true);
         TV -> Canvas -> FillRect(NodeRect);
      }
      NodeRect = Node -> DisplayRect(false);
      if ( None1 -> Checked ) {
         // no bitmap, so paint in the background color.
         TV -> Canvas -> Brush -> Color = BkgColorDialog -> Color;
         TV -> Canvas -> Brush -> Style = FBrushStyle;
         TV -> Canvas -> FillRect(NodeRect);
      }
      else
         //don't paint over the background bitmap.
         Brush -> Style = bsClear;

      NodeRect.Left = NodeRect.Left + ((Node -> Level) * (TV -> Indent));
      // NodeRect.Left now represents the left-most portion of the expand button
      DrawButton(&NodeRect, Node);
      NodeRect.Left = NodeRect.Left + TV -> Indent + FButtonSize;
      // NodeRect.Left is now the leftmost portion of the image.
      DrawImage(&NodeRect, Node -> ImageIndex);
      NodeRect.Left = NodeRect.Left + ImageList -> Width;
      // Now we are finally in a position to draw the text.
      TV -> Canvas -> TextOut(NodeRect.Left,  NodeRect.Top, Node -> Text);
   }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::TVGetImageIndex(TObject* Sender, TTreeNode* Node)
{
  if (Node -> HasChildren) {
    if (Node -> Expanded)
      Node -> ImageIndex = 3;
    else
      Node -> ImageIndex = 0;
  }
  else
    Node -> ImageIndex = 1;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::TVGetSelectedIndex(TObject* Sender, TTreeNode* Node)
{
   Node -> SelectedIndex = Node -> ImageIndex;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Exit1Click(TObject* Sender)
{
   Close();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Selection1Click(TObject* Sender)
{
   if ( SelectedFontDialog -> Execute() )
      TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Color1Click(TObject* Sender)
{
   if ( BkgColorDialog -> Execute() )
      TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::SelectionBackground1Click(TObject* Sender)
{
   if ( SelBkgColorDialog -> Execute() )
      TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Solid1Click(TObject* Sender)
{
   FBrushStyle = TBrushStyle(Tag);
   ( (TMenuItem*)Sender ) -> Checked = true;
   TV->Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::None1Click(TObject* Sender)
{
  ((TMenuItem*)Sender) -> Checked = true;
  TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::OnCustomDraw1Click(TObject* Sender)
{
   FDefaultDraw = !(FDefaultDraw);
   OnCustomDraw1 -> Checked = FDefaultDraw;
   TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::OnCustomDrawItem1Click(TObject* Sender)
{
   FDefaultDrawItem = !(FDefaultDrawItem);
   OnCustomDrawItem1 -> Checked = FDefaultDrawItem;
   TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::TVExpanded(TObject* Sender, TTreeNode* Node)
{
   TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::ButtonColor1Click(TObject* Sender)
{
   if ( ButtonColorDialog -> Execute() )
      TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::ButtonSize1Click(TObject* Sender)
{
   AnsiString S;
   S = IntToStr(FButtonSize);
   if ( InputQuery("Change button size", "Enter new size", S) )
      FButtonSize = StrToInt(S);
   TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Drawing1Click(TObject* Sender)
{
   ButtonColor1 -> Enabled = !(OnCustomDrawItem1 -> Checked);
   ButtonSize1 -> Enabled = ButtonColor1 -> Enabled;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Color2Click(TObject* Sender)
{
   if ( TVColorDialog -> Execute() ) {
      TV -> Color = TVColorDialog -> Color;
      TV -> Repaint();
   }
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::SetCustomDraw(bool Value)
{
   if (!Value) {
      TV -> OnCustomDraw = NULL;
      TV -> OnCustomDrawItem = NULL;
   }
   else {
      TV -> OnCustomDraw = this -> TVCustomDraw;
      TV -> OnCustomDrawItem = this -> TVCustomDrawItem;
   }
  Drawing1 -> Enabled = Value;
  TV -> Repaint();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::CustomDraw1Click(TObject* Sender)
{
   CustomDraw1 -> Checked = !(CustomDraw1 -> Checked);
   SetCustomDraw(CustomDraw1 -> Checked);
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TCustomDrawForm::Font2Click(TObject* Sender)
{
   if ( TVFontDialog -> Execute() )
      TV -> Font -> Assign(TVFontDialog -> Font);
}
//---------------------------------------------------------------------------

