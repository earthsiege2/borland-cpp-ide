//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TeeBasic.h"
#include <stdlib.h>
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDemoForm *DemoForm;
//---------------------------------------------------------------------------
__fastcall TDemoForm::TDemoForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
TChart* TDemoForm::TheChart()
{
  String S = Notebook1->Pages->Strings[0];
  TPage* page = static_cast<TPage*>(Notebook1->Pages->Objects[Notebook1->PageIndex]);
  return dynamic_cast<TChart*>(page->Controls[0]);
}

void TDemoForm::HorizScroll(const double Percent)
{
  ScrollAxis(TheChart()->TopAxis,Percent);
  ScrollAxis(TheChart()->BottomAxis,Percent);
  Button3->Enabled=true;
}

void TDemoForm::VertScroll(const double Percent)
{
  ScrollAxis(TheChart()->LeftAxis,Percent);
  ScrollAxis(TheChart()->RightAxis,Percent);
  Button3->Enabled=true;
}

void TDemoForm::ScrollAxis(TChartAxis* Axis, const double Percent)
{
  double Amount = -((Axis->Maximum-Axis->Minimum)/(100.0/Percent));
  Axis->SetMinMax(Axis->Minimum-Amount,Axis->Maximum-Amount);
}

void __fastcall TDemoForm::ListBox1Click(TObject *Sender)
{
  Notebook1->PageIndex=ListBox1->ItemIndex;
  tmpTimes=-1;
  TheChart()->AnimatedZoom=true;
  TheChart()->AnimatedZoomSteps=4;
  for (int t=0;t<TheChart()->SeriesCount();t++)
    TheChart()->Series[t]->FillSampleValues(
      TheChart()->Series[t]->NumSampleValues());
  TheChart()->UndoZoom();
  CheckBox1->Checked  =TheChart()->View3D;
  ScrollBar2->Enabled =TheChart()->View3D;
  ScrollBar2->Position=TheChart()->Chart3DPercent;
  if (dynamic_cast<TPieSeries*>(TheChart()->Series[0]))
     ScrollBar3->Position=TheChart()->View3DOptions->Elevation;
  else
     ScrollBar3->Position=TheChart()->View3DOptions->Rotation;
  ScrollBar4->Position=TheChart()->View3DOptions->Elevation;
  ScrollBar3->Enabled=TheChart()->View3D;
  ScrollBar4->Enabled=TheChart()->View3D;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::FormCreate(TObject *Sender)
{
  tmpTimes=-1;
  ScrollBar1->Position=Timer1->Interval;
  ComboBox1->ItemIndex=0;
  ComboBox2->ItemIndex=0;
  ListBox1->ItemIndex =0;
  ListBox1Click(this);
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::CheckBox1Click(TObject *Sender)
{
  TheChart()->View3D=CheckBox1->Checked;
  ScrollBar2->Enabled=TheChart()->View3D;
  ScrollBar3->Enabled=TheChart()->View3D;
  ScrollBar4->Enabled=TheChart()->View3D;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::CheckBox2Click(TObject *Sender)
{
  Timer1->Enabled=CheckBox2->Checked;
  ScrollBar1->Enabled=Timer1->Enabled;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ScrollBar1Change(TObject *Sender)
{
  Timer1->Interval=ScrollBar1->Position;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::Timer1Timer(TObject *Sender)
{
  double tmpX;
  switch (Notebook1->PageIndex) {
    case 0 :
    case 3 :
    case 4 :
    case 6 : {
      for (int t=0;t<TheChart()->SeriesCount();t++) {
        tmpX=TheChart()->Series[t]->XValues->Value[1]-
          TheChart()->Series[t]->XValues->Value[0];
        TheChart()->Series[t]->Delete(0);
        TheChart()->Series[t]->AddXY(
          TheChart()->Series[t]->XValues->Last()+tmpX,
          TheChart()->Series[t]->YValues->Last()+random(100)-50,"",clTeeColor);
      }
      break;
    }
    case 1 :
    case 2 :
    case 8 : {
      if (tmpTimes==-1) {
        tmpSeries=random(TheChart()->SeriesCount());
        tmpIndex =random(TheChart()->Series[tmpSeries]->Count());
        tmpTimes =random(10);
        tmpRandom=2*floor((random(50)-25.0) + .5);
      }
      if (tmpSeries != -1) {
        if (Notebook1->PageIndex == 8) {
          TBubbleSeries* s =
            dynamic_cast<TBubbleSeries*>(TheChart()->Series[tmpSeries]);
          tmpX=s->RadiusValues->Value[tmpIndex]+tmpRandom;
          if (tmpX>=2) {
            s->RadiusValues->Value[tmpIndex]=tmpX;
            if (tmpRandom>0)
              tmpX=s->XValues->Value[tmpIndex]+1;
            else
              tmpX=s->XValues->Value[tmpIndex]-1;
            s->XValues->Value[tmpIndex]=tmpX;
            if (random(10)<5)
              tmpX=s->YValues->Value[tmpIndex]+50;
            else
              tmpX=s->YValues->Value[tmpIndex]-50;
            s->YValues->Value[tmpIndex]=tmpX;
          }
          else tmpTimes=0;
        }
        else
          TheChart()->Series[tmpSeries]->MandatoryValueList()->Value[tmpIndex] =
            TheChart()->Series[tmpSeries]->MandatoryValueList()->Value[tmpIndex]+tmpRandom;
        tmpTimes--;
        TheChart()->Repaint();
      }
      break;
    }
    case 5: {
      TPieSeries* s = dynamic_cast<TPieSeries*>(TheChart()->Series[0]);
      s->Rotate(358);
      break;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::Button2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::BitBtn1Click(TObject *Sender)
{
  TheChart()->ZoomPercent(120);
  Button3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::BitBtn2Click(TObject *Sender)
{
  TheChart()->ZoomPercent(80);
  Button3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::SpeedButton1Click(TObject *Sender)
{
  HorizScroll(10);
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::SpeedButton4Click(TObject *Sender)
{
  HorizScroll(-10);
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::SpeedButton2Click(TObject *Sender)
{
  VertScroll(-10);
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::SpeedButton3Click(TObject *Sender)
{
  VertScroll(10);
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::CheckBox3Click(TObject *Sender)
{
  TPieSeries* s = dynamic_cast<TPieSeries*>(TheChart()->Series[0]);
  s->Circled=CheckBox3->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ComboBox1Click(TObject *Sender)
{
  TCustomBarSeries* s = dynamic_cast<TCustomBarSeries*>(TheChart()->Series[0]);
  TComboBox* cb = dynamic_cast<TComboBox*>(Sender);
    s->MultiBar=TMultiBar(cb->ItemIndex);
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ScrollBar2Change(TObject *Sender)
{
  TheChart()->Chart3DPercent=ScrollBar2->Position;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::Series28GetMarkText(TChartSeries *Sender,
      int ValueIndex, AnsiString &MarkText)
{
   if (ValueIndex==3)
     MarkText="USA";
   else if (ValueIndex==5)
     MarkText="UK";
   else if (ValueIndex==7)
     MarkText="Germany";
   else
     MarkText="";
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::Button3Click(TObject *Sender)
{
  TheChart()->UndoZoom();
  Button3->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::CheckBox4Click(TObject *Sender)
{
  Series11->Stairs=CheckBox4->Checked;
  Series12->Stairs=CheckBox4->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::FormShow(TObject *Sender)
{
  Timer1->Enabled=true;  // <-- start animation
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ScrollBar3Change(TObject *Sender)
{
  if (ScrollBar3->Enabled ) 
  TheChart()->View3DOptions->Orthogonal=false;
  if (dynamic_cast<TPieSeries*>(TheChart()->Series[0]))
    TheChart()->View3DOptions->Elevation=ScrollBar3->Position;
  else
    TheChart()->View3DOptions->Rotation=ScrollBar3->Position;
}
//---------------------------------------------------------------------------
void __fastcall TDemoForm::ScrollBar4Change(TObject *Sender)
{
  if (ScrollBar4->Enabled) {
    TheChart()->View3DOptions->Orthogonal=false;
    TheChart()->View3DOptions->Elevation=ScrollBar4->Position;
  }
}
//---------------------------------------------------------------------------

