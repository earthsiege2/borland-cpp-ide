//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <printers.hpp>

#include "graphwin.h"
#include "bmpdlg.h"
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFormMain* FormMain;
//---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner)
  : TForm(Owner)
{
 Image->Canvas->MoveTo(0,0);
}
//---------------------------------------------------------------------------
void __fastcall TFormMain::LineButtonClick(TObject *Sender)
{
  DrawingTool = dtLine;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::RectangleButtonClick(TObject *Sender)
{
  DrawingTool = dtRectangle;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::EllipseButtonClick(TObject *Sender)
{
  DrawingTool = dtEllipse;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::RoundRectButtonClick(TObject *Sender)
{
  DrawingTool = dtRoundRect;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::PenButtonClick(TObject *Sender)
{
  PenBar->Visible = PenButton->Down;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::BrushButtonClick(TObject *Sender)
{
  BrushBar->Visible = BrushButton->Down;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::SetPenStyle(TObject *Sender)
{
    if (Sender == SolidPen){
       Image->Canvas->Pen->Style = psSolid;
    }
    else if (Sender == DashPen){
            Image->Canvas->Pen->Style = psDash;
    }
    else if (Sender == DotPen){
         Image->Canvas->Pen->Style = psDot;
    }
    else if (Sender == DashDotPen){
         Image->Canvas->Pen->Style = psDashDot;
    }
    else if (Sender == DashDotDotPen){
         Image->Canvas->Pen->Style = psDashDotDot;
    }
    else if (Sender == ClearPen){
         Image->Canvas->Pen->Style = psClear;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::PenColorClick(TObject *Sender)
{
  ColorDialog1->Color = Image->Canvas->Pen->Color;
  if (ColorDialog1->Execute()){
    Image->Canvas->Pen->Color = ColorDialog1->Color;
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::PenSizeChange(TObject *Sender)
{
  Image->Canvas->Pen->Width = PenWidth->Position;
}
//---------------------------------------------------------------------
void __fastcall TFormMain::SetBrushStyle(TObject *Sender)
{
    if (Sender == SolidBrush){
       Image->Canvas->Brush->Style = bsSolid;
    }
    else if (Sender == ClearBrush){
         Image->Canvas->Brush->Style = bsClear;
    }
    else if (Sender == HorizontalBrush){
         Image->Canvas->Brush->Style = bsHorizontal;
    }
    else if (Sender == VerticalBrush){
         Image->Canvas->Brush->Style = bsVertical;
    }
    else if (Sender == FDiagonalBrush){
         Image->Canvas->Brush->Style = bsFDiagonal;
    }
    else if (Sender == BDiagonalBrush){
         Image->Canvas->Brush->Style = bsBDiagonal;
    }
    else if (Sender == CrossBrush){
         Image->Canvas->Brush->Style = bsCross;
    }
    else if (Sender == DiagCrossBrush){
         Image->Canvas->Brush->Style = bsDiagCross;
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::BrushColorClick(TObject *Sender)
{
  ColorDialog1->Color = Image->Canvas->Brush->Color;
  if (ColorDialog1->Execute()){
    Image->Canvas->Brush->Color = ColorDialog1->Color;
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  Drawing = True;
  Image->Canvas->MoveTo(X, Y);
  Origin = Point(X, Y);
  MovePt = Origin;

  TVarRec tempvar[2] = {X, Y};
  StatusBar1->Panels->Items[0]->Text = Format("Origin: (%d, %d)", tempvar, 2);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  if (Drawing){
    DrawShape(Origin, MovePt, pmNotXor);
    MovePt = Point(X, Y);
    DrawShape(Origin, MovePt, pmNotXor);
  }

  TVarRec tempvar[2] = {X, Y};
  StatusBar1->Panels->Items[1]->Text = Format("Current: (%d, %d)", tempvar, 2);
}
//---------------------------------------------------------------------
void __fastcall TFormMain::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  if (Drawing){
    DrawShape(Origin, Point(X, Y), pmCopy);
    Drawing = False;
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::New1Click(TObject *Sender)
{
     Graphics::TBitmap *Bitmap;

     NewBMPForm->ActiveControl = NewBMPForm->WidthEdit;
     NewBMPForm->WidthEdit->Text = IntToStr(Image->Picture->Graphic->Width);
     NewBMPForm->HeightEdit->Text = IntToStr(Image->Picture->Graphic->Height);
//     if (ShowModal() != idCancel){
     if (NewBMPForm->ShowModal() != IDCANCEL){
        Bitmap = new Graphics::TBitmap();
//        Bitmap->Create();
        Bitmap->Width = StrToInt(NewBMPForm->WidthEdit->Text);
        Bitmap->Height = StrToInt(NewBMPForm->HeightEdit->Text);
        Image->Picture->Graphic = Bitmap;
        CurrentFile = EmptyStr;
     }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Open1Click(TObject *Sender)
{
  if (OpenDialog1->Execute()){
    CurrentFile = OpenDialog1->FileName;
    Image->Picture->LoadFromFile(CurrentFile);
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Save1Click(TObject *Sender)
{
  if (CurrentFile != EmptyStr){
    Image->Picture->SaveToFile(CurrentFile);
  }
  else{
   SaveAs1Click(Sender);
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::SaveAs1Click(TObject *Sender)
{
  if (SaveDialog1->Execute()){
    CurrentFile = SaveDialog1->FileName;
    Save1Click(Sender);
  }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Exit1Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Cut1Click(TObject *Sender)
{
 TRect ARect;

 Copy1Click(Sender);

 Image->Canvas->CopyMode = cmWhiteness;
 ARect = Rect(0, 0, Image->Width, Image->Height);
 Image->Canvas->CopyRect(ARect, Image->Canvas, ARect);
 Image->Canvas->CopyMode = cmSrcCopy;
}

//---------------------------------------------------------------------
void __fastcall TFormMain::Copy1Click(TObject *Sender)
{
  Clipboard()->Assign(Image->Picture);
}

//---------------------------------------------------------------------
void __fastcall TFormMain::Paste1Click(TObject *Sender)
{

  Graphics::TBitmap *Bitmap;

  if (Clipboard()->HasFormat(CF_BITMAP)){
    Bitmap = new Graphics::TBitmap();
    try{
      Bitmap->Assign(Clipboard());
      Image->Canvas->Draw(0, 0, Bitmap);
      delete Bitmap;
    }
    catch(...){
      delete Bitmap;
    }
  }
}

//---------------------------------------------------------------------
void __fastcall TFormMain::DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode){
    Image->Canvas->Pen->Mode = AMode;

    switch (DrawingTool){
           case dtLine : {
                Image->Canvas->MoveTo(TopLeft.x, TopLeft.y);
                Image->Canvas->LineTo(BottomRight.x, BottomRight.y);
                break;
           }

           case dtRectangle : {
                Image->Canvas->Rectangle(TopLeft.x, TopLeft.y, BottomRight.x, BottomRight.y);
                break;
           }

           case dtEllipse : {
                Image->Canvas->Ellipse(TopLeft.x, TopLeft.y, BottomRight.x, BottomRight.y);
                break;
           }

           case dtRoundRect : {
                Image->Canvas->RoundRect(TopLeft.x, TopLeft.y, BottomRight.x, BottomRight.y, (TopLeft.x - BottomRight.x)/2, (TopLeft.y - BottomRight.y)/2);
                break;
           }
    }
}
//---------------------------------------------------------------------
void __fastcall TFormMain::Print1Click(TObject *Sender)
{
    unsigned int BitmapInfoSize, BitmapImageSize;
    long DIBWidth, DIBHeight;
    PChar BitmapImage;
    Windows::PBitmapInfo BitmapInfo;
    Graphics::TBitmap *Bitmap;

    Printer()->BeginDoc();
    Bitmap = new Graphics::TBitmap();
    Bitmap->Assign(Image->Picture);
    GetDIBSizes(Bitmap->Handle, BitmapInfoSize, BitmapImageSize);
    BitmapInfo  = (PBitmapInfo) new char[BitmapInfoSize];
    BitmapImage = (PChar) new char [BitmapImageSize];
    GetDIB(Bitmap->Handle, 0, BitmapInfo, BitmapImage);
    DIBWidth  = BitmapInfo->bmiHeader.biWidth;
    DIBHeight = BitmapInfo->bmiHeader.biHeight;
    StretchDIBits(Printer()->Canvas->Handle,
                0, 0, DIBWidth, DIBHeight,
                0, 0, DIBWidth, DIBHeight,
                BitmapImage, BitmapInfo,
                DIB_RGB_COLORS, SRCCOPY);
    delete [] BitmapImage;
    delete [] BitmapInfo;
    delete Bitmap;

    Printer()->EndDoc();
}
//---------------------------------------------------------------------
