//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef graphwinH
#define graphwinH
//---------------------------------------------------------------------------
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------

enum TDrawingTool {dtLine, dtRectangle, dtEllipse, dtRoundRect};

class TFormMain : public TForm
{
__published:
    TPanel *Panel1;
    TPanel *PenBar;
    TPanel *BrushBar;
    TScrollBox *ScrollBox1;
    TImage *Image;
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *New1;
    TMenuItem *Open1;
    TMenuItem *Save1;
    TMenuItem *Saveas1;
    TMenuItem *Print1;
    TMenuItem *N1;
    TMenuItem *Exit1;
    TMenuItem *Edit1;
    TMenuItem *Cut1;
    TMenuItem *Copy1;
    TMenuItem *Paste1;
    TOpenDialog *OpenDialog1;
    TColorDialog *ColorDialog1;
    TSaveDialog *SaveDialog1;
    TStatusBar *StatusBar1;
    TSpeedButton *LineButton;
    TSpeedButton *RectangleButton;
    TSpeedButton *EllipseButton;
    TSpeedButton *RoundRectButton;
    TSpeedButton *PenButton;
    TSpeedButton *BrushButton;
    TSpeedButton *SolidPen;
    TSpeedButton *DashPen;
    TSpeedButton *DotPen;
    TSpeedButton *DashDotPen;
    TSpeedButton *DashDotDotPen;
    TSpeedButton *ClearPen;
    TSpeedButton *PenColor;
    TEdit *PenSize;
    TUpDown *PenWidth;
    TSpeedButton *SolidBrush;
    TSpeedButton *ClearBrush;
    TSpeedButton *HorizontalBrush;
    TSpeedButton *VerticalBrush;
    TSpeedButton *FDiagonalBrush;
    TSpeedButton *BDiagonalBrush;
    TSpeedButton *CrossBrush;
    TSpeedButton *DiagCrossBrush;
    TSpeedButton *BrushColor;
    void __fastcall RectangleButtonClick(TObject *Sender);
    void __fastcall EllipseButtonClick(TObject *Sender);
    void __fastcall RoundRectButtonClick(TObject *Sender);
    void __fastcall PenButtonClick(TObject *Sender);
    void __fastcall BrushButtonClick(TObject *Sender);
    void __fastcall SetPenStyle(TObject *Sender);
    void __fastcall PenColorClick(TObject *Sender);
    void __fastcall PenSizeChange(TObject *Sender);
    void __fastcall SetBrushStyle(TObject *Sender);
    void __fastcall BrushColorClick(TObject *Sender);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y);
    void __fastcall New1Click(TObject *Sender);
    void __fastcall Open1Click(TObject *Sender);
    void __fastcall Save1Click(TObject *Sender);
    void __fastcall SaveAs1Click(TObject *Sender);
    void __fastcall Exit1Click(TObject *Sender);
    void __fastcall Cut1Click(TObject *Sender);
    void __fastcall Copy1Click(TObject *Sender);
    void __fastcall Paste1Click(TObject *Sender);
    
    void __fastcall LineButtonClick(TObject *Sender);
    void __fastcall Print1Click(TObject *Sender);
private:        // private user declarations
public:         // public user declarations
        bool Drawing;
        TPoint Origin, MovePt;
        TDrawingTool DrawingTool;
        AnsiString CurrentFile;

        void __fastcall DrawShape(TPoint TopLeft, TPoint BottomRight, TPenMode AMode);
        virtual __fastcall TFormMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
