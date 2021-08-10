//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#pragma hdrstop   
#include <SysUtils.hpp>

#define NO_IMPLICIT_NAMESPACE_USE
					
#include <activex.hpp>

#undef NO_IMPLICIT_NAMESPACE_USE


#include <memory>          //For use of auto_ptr
#include  "piereg.h"
#include "pies.cpp"
#include "samp.h"

#pragma resource "*.dfm"
#pragma resource "*.res"    
#pragma package(smart_init)

//---------------------------------------------------------------------------
namespace Piereg{
void __fastcall PACKAGE Register()
{
  TComponentClass classes[1] = {__classid(TPie)};
  RegisterComponents(LoadStr(Tab_101), classes, 0);
  RegisterComponentEditor(__classid(TPie), __classid(TPieEditor));
  RegisterPropertyEditor(__typeinfo(TAngles),
                         NULL,
                         "",
                         __classid(TAnglesProperty));
}
} //namespace

//---------------------------------------------------------------------------
String loadString(unsigned long id)
{
   unsigned long bufLen = 100;
   char * buf = new char[bufLen];
   String str;

   if(LoadString(HInstance, id, buf, bufLen) )
   {
   str = buf;
   }
   else
   {
   str = "";
   }

   delete buf;
   return str;

}
// TAngleEditorDlg

__fastcall TAngleEditorDlg::TAngleEditorDlg(TComponent* AOwner) : TForm(AOwner) { }
__fastcall TAngleEditorDlg::TAngleEditorDlg(TComponent* AOwner, int Dummy) : TForm(AOwner, Dummy) { }
__fastcall TAngleEditorDlg::TAngleEditorDlg(HWND ParentWindow) : TForm(ParentWindow) { }
__fastcall TAngleEditorDlg::~TAngleEditorDlg(void) { }

void __fastcall TAngleEditorDlg::STrackBarChange(TObject* /*Sender*/)
{
  SetStartAngle(STrackBar->Position);
}

void __fastcall TAngleEditorDlg::ETrackBarChange(TObject* /*Sender*/)
{
  SetEndAngle(ETrackBar->Position);
}

void __fastcall TAngleEditorDlg::SetStartAngle(Integer Value)
{
  STrackBar->Position = Value;
  SAngleLabel->Caption = loadString(StartAngle_RC) + String(Value);
  FAngles->StartAngle = Value;
}

void __fastcall TAngleEditorDlg::SetEndAngle(Integer Value)
{
  ETrackBar->Position = Value;
  EAngleLabel->Caption = loadString(EndAngle_RC) + String(Value);
  FAngles->EndAngle = Value;
}

void __fastcall TAngleEditorDlg::SetAngles(TAngles* Value)
{
  FAngles = Value;
  FOrigStart = Value->StartAngle;
  FOrigEnd = Value->EndAngle;
  SetStartAngle(Value->StartAngle);
  SetEndAngle(Value->EndAngle);
}

void __fastcall TAngleEditorDlg::CancelClick(TObject* /*Sender*/)
{
  SetStartAngle(FOrigStart);
  SetEndAngle(FOrigEnd);
}

//---------------------------------------------------------------------------
// TAnglesProperty

__fastcall TAnglesProperty::TAnglesProperty(const _di_IFormDesigner ADesigner, int APropCount) : TClassProperty(ADesigner, APropCount) { }
__fastcall TAnglesProperty::~TAnglesProperty(void) { }

void __fastcall TAnglesProperty::Edit()
{
  //We use the auto_ptr so that the object is destroyed automatically
  //on exit of the function.
  //  std::auto_ptr<TAngles> Angles(new TAngles());
  std::auto_ptr<TAngleEditorDlg> AngleEditor(new TAngleEditorDlg(Application));

  AngleEditor->EditorAngles = (TAngles*)GetOrdValue();
  AngleEditor->ShowModal();
}

TPropertyAttributes __fastcall TAnglesProperty::GetAttributes()
{
  return (TPropertyAttributes() << paDialog << paSubProperties);
}

//---------------------------------------------------------------------------
//TPieEditor
__fastcall TPieEditor::TPieEditor(TComponent* AComponent, _di_IFormDesigner ADesigner)
                      : TDefaultEditor(AComponent, ADesigner) { }
__fastcall TPieEditor::~TPieEditor(void) { }

void __fastcall TPieEditor::EditProperty(TPropertyEditor* PropertyEditor,
                                         bool& Continue,
                                         bool& /*FreeEditor*/)
{
  String PropName(PropertyEditor->GetName());
  if (strcmpi(PropName.c_str(),"ANGLES") == 0){
    PropertyEditor->Edit();
    Continue = false;
  }
}

int __fastcall TPieEditor::GetVerbCount()
{
  return 1;
}

String __fastcall TPieEditor::GetVerb(Integer Index)
{
  if (Index == 0)
     return loadString(EditAngle_RC);
  else
  return String("");
}

void __fastcall TPieEditor::ExecuteVerb(Integer Index)
{
  if (Index == 0) Edit();
}
//---------------------------------------------------------------------------
