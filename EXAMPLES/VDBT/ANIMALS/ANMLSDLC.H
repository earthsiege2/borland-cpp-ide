//----------------------------------------------------------------------------
//  Project Animals
//  Borland International
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    Animals Application
//  FILE:         AnmlsDlC.h
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TAnimalsDlgClient (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(anmlsdlc_h)              // Sentry, use file only if it's not already included.
#define anmlsdlc_h

#include <owl\pch.h>
#pragma hdrstop
#include <owl\vbxctl.h>
#include "BeastWin.rh"                  // Definition of all resources.


//{{TDialog = TAnimalsDlgClient}}
class TAnimalsDlgClient : public TDialog, public TVbxEventHandler {
  public:
    TAnimalsDlgClient(TWindow* parent, TResId resId = IDD_ANIMALS, TModule* module = 0);
    virtual ~TAnimalsDlgClient();

DECLARE_RESPONSE_TABLE(TAnimalsDlgClient);

};    //{{TAnimalsDlgClient}}


#endif  // anmlsdlc_h sentry.
