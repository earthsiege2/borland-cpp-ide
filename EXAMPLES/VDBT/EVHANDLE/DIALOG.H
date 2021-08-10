//----------------------------------------------------------------------------
//  Project EVHANDLE
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    EVHANDLE Application
//  FILE:         DIALOG.H
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Class definition for TDlgClient (TDialog).
//
//----------------------------------------------------------------------------
#if !defined(dialog_h)              // Sentry, use file only if it's not already included.
#define dialog_h

#include "evhandle.rh"                  // Definition of all resources.
#include <vdbt\dbedit.h>
#include <vdbt\dbnvgtr.h>
#include <vdbt\dbradio.h>
#include "textwnd.h"

//
// derived class that contains all the VDBT controls
// must also be derived from TVbxEventHandler
//
class TDlgClient : public TDialog, public TVbxEventHandler
{
public:
    TDlgClient(TWindow* parent, TResId resId = IDD_CLIENT, TModule* module = 0);
    virtual ~TDlgClient();
    virtual void SetupWindow();

protected:
	TextWindow *OutputWin;  // helper window for msg strings
	TDBEdit *Edit1, *Edit2;
   TDBNavigator *Nav;
   TDBRadioGroup *RadioGroup;

   // event sinks for the TDBEdit class
   TDBEditNotifySink	OnEditFocus, OnEditDataChange, OnEditLoseFocus;
   // There are two OnKeyDown sinks, one for each TDBEdit control
   // They can both go to the same method handler but must have two
   // sinks.
   TDBEditKeySink 	OnEditKeyDownSink1, OnEditKeyDownSink2;

   // event sinks for the TDBNavigatorClass
   TDBNavigatorClickSink	OnNavBtnClick;

   // event sinks for the TDBRadioGroup class
   TDBRadioGroupNotifySink OnRadioChange,OnRadioGetFocus,
   	OnRadioLoseFocus;

   // event handler methods for the TDBEdit class
   void EditGetFocus(TDBEditNotifySink&, TDBEdit&);
   void EditLoseFocus(TDBEditNotifySink&, TDBEdit&);
   void EditDataChange(TDBEditNotifySink&, TDBEdit&);
   // one keydown handler for both TDBEdit controls
   void EditKeyDown(TDBEditKeySink&, TDBEdit&, SHORT *,TShiftState);

   // event handler methods for the TDBNavigator class
   void NavBtnClicked(TDBNavigatorClickSink&, TDBNavigator&,
   	TNavigateBtn);
   
   // event handler methods for the TDBRadioGroup class
   void RadioGroupChange(TDBRadioGroupNotifySink&, TDBRadioGroup&);
   void RadioGroupGetFocus(TDBRadioGroupNotifySink&, TDBRadioGroup&);
   void RadioGroupLoseFocus(TDBRadioGroupNotifySink&, TDBRadioGroup&);

   DECLARE_RESPONSE_TABLE(TDlgClient);

};   

#endif  // dialog_h sentry.
