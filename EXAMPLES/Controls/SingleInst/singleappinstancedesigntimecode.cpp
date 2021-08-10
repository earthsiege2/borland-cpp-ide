//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "SingleAppInstance.h"
#include "SingleAppInstanceDesignTimeCode.h"
#include "SingleAppInstanceDesignMarkerForm.h"

#include <TypInfo.Hpp>

#define NDEBUG
#include <cassert>

#pragma package(smart_init)


void __fastcall TSingleInstanceMarkerPropertyEditor::Edit(void)
{
  TfrmMarkerPropertyEditor* MarkerForm;

  MarkerForm = new TfrmMarkerPropertyEditor(NULL);
  try
  {
    MarkerForm->MarkerText = this->GetStrValue();

    if (MarkerForm->ShowModal() == mrOk)
    {
      SetValue(MarkerForm->MarkerText);
    }
  }
  __finally
  {
    delete MarkerForm;
  }
}

TPropertyAttributes __fastcall TSingleInstanceMarkerPropertyEditor::GetAttributes(void)
{
  return (TPropertyAttributes() << paDialog);
}

AnsiString __fastcall TSingleInstanceMarkerPropertyEditor::GetValue(void)
{
  return inherited::GetValue();
}

void __fastcall TSingleInstanceMarkerPropertyEditor::SetValue(const AnsiString Value)
{
  // Note the Windows API documentation:
  // "The name can contain any character except the backslash character (\)"
  TSingleAppInstance::AssertValidMarkerText(Value);

  inherited::SetValue(Value);
}

//---------------------------------------------------------------------------

PTypeInfo AnsiStringTypeInfo(void)
{
  PPTypeInfo Temp;

  Temp = GetPropInfo(__typeinfo(TSingleAppInstance), "Marker")->PropType;
  assert(Temp != NULL);

  return *Temp;
}


namespace Singleappinstancedesigntimecode
{
  void __fastcall PACKAGE Register()
  {
    //
    // Register the component on the component palette
    //
    TComponentClass classes[1] = {__classid(TSingleAppInstance)};
    RegisterComponents("Samples", classes, 0);

    //
    // Register an AnsiString property editor for the Marker property
    //
    RegisterPropertyEditor( AnsiStringTypeInfo(), __classid(TSingleAppInstance),
                            "Marker", __classid(TSingleInstanceMarkerPropertyEditor) );

  }
}


