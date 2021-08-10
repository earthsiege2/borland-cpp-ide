//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1997-2002 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
// ibevnts.cpp
// This file is #included in IBREG.CPP which #includes IBREG.H which
// in turn #includes INEVNTS.H.  Hence #including IBEVNTS.H here is redundant with
// no ramifications (there are sentries in the header file) but has been done
// just to clarify that the function and class implementations in this file are
// prototyped in INEVNTS.H
#include <memory>     //for STL auto_ptr
#if !defined (REGISTER_ALL_CONTROLS)
  #include  "ibevnts.h"
#else
  #include "source\ibevnts.h"
#endif
#pragma resource "*.dfm"
#pragma package(smart_init)

#include "ibctrls.h"

bool __fastcall Ibevnts::EditAlerterEvents(Classes::TStrings *Events)
{
  bool result = false;
  std::auto_ptr<TIBEAEventsEditor> EEditor(new TIBEAEventsEditor(Application));
  for(int i=0; i < Events->Count ;i++) //
  {
    EEditor->cEvents->Cells[1][i] = Events->Strings[i];
  }
  if( EEditor->ShowModal() == IDOK )
  {
    result = true;
    Events->Clear();
    for(int i=0; i < MaxEvents ;i++)
    {
      if ((EEditor->cEvents->Cells[1][i].Length()) != 0)
        Events->Add( EEditor->cEvents->Cells[1][i]);
    }
  }
  return result;
}

void __fastcall TIBEAEventsEditor::FormCreate(TObject *Sender)
{
  for(int i=1; i < MaxEvents; i++ ) 
      cEvents->Cells[0][i-1] = AnsiString(i);
  RequestedEvents->Caption = LoadStr(57810);
  bOK->Caption = LoadStr(57811);
  bCancel->Caption = LoadStr(57812);
}
