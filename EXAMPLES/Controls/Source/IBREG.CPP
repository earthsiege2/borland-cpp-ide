//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
#pragma hdrstop
#include <dsgnintf.hpp>
#include <memory>       //for STL auto_ptr
#include "ibreg.h"
#include "samp.h"

#pragma package(smart_init)

#pragma resource "*.res"  

__fastcall TIBEventListProperty::TIBEventListProperty(_di_IFormDesigner ADesigner, int APropCount)
                                : TClassProperty(ADesigner, APropCount) { } 
__fastcall TIBEventListProperty::~TIBEventListProperty(void){}

 TPropertyAttributes __fastcall TIBEventListProperty::GetAttributes()
{
  return  (TClassProperty::GetAttributes() << paDialog ) >> paSubProperties;
}

void __fastcall TIBEventListProperty::Edit()
{
  std::auto_ptr<TStringList> Events(new TStringList());
  Events->Assign((TStrings*)GetOrdValue());
  if(Ibevnts::EditAlerterEvents(Events.get()))
    SetOrdValue(long(Events.get()));
}

namespace Ibsmp50
{
void __fastcall PACKAGE Register()
{
  TComponentClass classes[1] = {__classid(TIBEventAlerter)};
  RegisterComponents(LoadStr(Tab_101), classes, 0);
  RegisterPropertyEditor(__typeinfo(TStrings),
                         __classid(TIBEventAlerter),
                         "Events",
                         __classid(TIBEventListProperty));
}
}       /* namespace Ibreg */


