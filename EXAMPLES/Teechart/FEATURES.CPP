//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Features.h"
#include "UColor.h"
#include "UAniZoom.h"
#include "UBitmap.h"
#include "UDraw.h"
#include "UClick.h"
#include "ULegend.h"
#include "UMain.h"
#include "UOverbar.h"
#include "UAxisLab.h"
#include "UScroll.h"
#include "UShapes.h"
#include "UScrollB.h"
#include "LastValu.h"
#include "UCrossH.h"
#include "UKBoar.h"
#include "UPrint.h"
#include "LogLab.h"
#include "UPages.h"
#include "UMetafil.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFeaturesForm *FeaturesForm;
//---------------------------------------------------------------------------
__fastcall TFeaturesForm::TFeaturesForm(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFeaturesForm::BitBtn17Click(TObject *Sender)
{
  TColoredForm* form = new TColoredForm(this);
  form->ShowModal();
  delete form;  
}
//---------------------------------------------------------------------------
void __fastcall TFeaturesForm::BitBtn4Click(TObject *Sender)
{
  TFormAnimatedZoom* form = new TFormAnimatedZoom(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn6Click(TObject *Sender)
{
  TBitmapForm* form = new TBitmapForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------


void __fastcall TFeaturesForm::BitBtn7Click(TObject *Sender)
{
  TDrawForm* form = new TDrawForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn5Click(TObject *Sender)
{
  TClickingForm* form = new TClickingForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn3Click(TObject *Sender)
{
  TMiniForm* form = new TMiniForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn9Click(TObject *Sender)
{
  TOverBarForm* form = new TOverBarForm(this);
  form->ShowModal();
  delete form;  
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn13Click(TObject *Sender)
{
  TLegendForm* form = new TLegendForm(this);
  form->ShowModal();
  delete form;  
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn12Click(TObject *Sender)
{
  TAxisLabelsForm* form = new TAxisLabelsForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------



void __fastcall TFeaturesForm::BitBtn2Click(TObject *Sender)
{
  TScrollForm* form = new TScrollForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn8Click(TObject *Sender)
{
  TShapesForm* form = new TShapesForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn18Click(TObject *Sender)
{
  TScrollBarForm* form = new TScrollBarForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn14Click(TObject *Sender)
{
  TDigitalForm* form = new TDigitalForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn19Click(TObject *Sender)
{
  TCrossHairForm* form = new TCrossHairForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn20Click(TObject *Sender)
{
  TKeyboardForm* form = new TKeyboardForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn10Click(TObject *Sender)
{
  TPrintForm* form = new TPrintForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn21Click(TObject *Sender)
{
  TCustomLabelsForm* form = new TCustomLabelsForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn11Click(TObject *Sender)
{
  TPagesForm* form = new TPagesForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------

void __fastcall TFeaturesForm::BitBtn15Click(TObject *Sender)
{
  TMetafileForm* form = new TMetafileForm(this);
  form->ShowModal();
  delete form;
}
//---------------------------------------------------------------------------



