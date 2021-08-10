//----------------------------------------------------------------------------
//  Project EVHANDLE
//  
//  Copyright © 1996. All Rights Reserved.
//
//  SUBSYSTEM:    EVHANDLE Application
//  FILE:         DIALOG.CPP
//  AUTHOR:       
//
//  OVERVIEW
//  ~~~~~~~~
//  Source file for implementation of TDlgClient (TDialog).
//
//----------------------------------------------------------------------------

#include <owl/pch.h>

#include "evhandle.h"
#include "dialog.h"



DEFINE_RESPONSE_TABLE2(TDlgClient,TDialog,TVbxEventHandler)
END_RESPONSE_TABLE;

//--------------------------------------------------------
// TDlgClient
// ~~~~~~~~~~
// Construction/Destruction handling.
//
TDlgClient::TDlgClient(TWindow* parent, TResId resId, TModule* module)
:
  TDialog(parent, resId, module),
// init all of the sinks, contecting them to the handler methods
  OnEditFocus(TDBEditNotify_MFUNCTOR(*this, &TDlgClient::EditGetFocus)),
  OnEditDataChange(TDBEditNotify_MFUNCTOR(*this, &TDlgClient::EditDataChange)),
  OnEditLoseFocus(TDBEditNotify_MFUNCTOR(*this, &TDlgClient::EditLoseFocus)),
  OnNavBtnClick(TDBNavigatorClick_MFUNCTOR(*this, &TDlgClient::NavBtnClicked)),
  OnRadioChange(TDBRadioGroupNotify_MFUNCTOR(*this, &TDlgClient::RadioGroupChange)),
  OnRadioGetFocus(TDBRadioGroupNotify_MFUNCTOR(*this, &TDlgClient::RadioGroupGetFocus)),
  OnRadioLoseFocus(TDBRadioGroupNotify_MFUNCTOR(*this, &TDlgClient::RadioGroupLoseFocus)),
// init both of the TDBEdit keydown sinks to the same handler method
  OnEditKeyDownSink1(TDBEditKey_MFUNCTOR(*this, &TDlgClient::EditKeyDown)),
  OnEditKeyDownSink2(TDBEditKey_MFUNCTOR(*this, &TDlgClient::EditKeyDown))
{
        OutputWin= new TextWindow(NULL,"Events List");
        Edit1 = new TDBEdit(this,IDC_DBEDIT1);
        Edit2= new TDBEdit(this,IDC_DBEDIT2);
        Nav= new TDBNavigator(this,IDC_DBNAV1);
        RadioGroup= new TDBRadioGroup(this, IDC_DBRADIOG1);
}


TDlgClient::~TDlgClient()
{
  Destroy();
}

void TDlgClient::SetupWindow()
{
  TDialog::SetupWindow();
  // create and show the helper window
  OutputWin->Create();
  OutputWin->Show(SW_SHOW);

  // connect the sources to the sinks
  Edit2->OnEnterSource += OnEditFocus;
  Edit2->OnExitSource += OnEditLoseFocus;
  Edit2->OnChangeSource += OnEditDataChange;
  // the two TDBEdit OnKeyDownSource need two different
  // sinks to connect to
  Edit1->OnKeyDownSource += OnEditKeyDownSink1;
  Edit2->OnKeyDownSource += OnEditKeyDownSink2;
  Nav->OnClickSource += OnNavBtnClick;
  RadioGroup->OnChangeSource += OnRadioChange;
  RadioGroup->OnEnterSource += OnRadioGetFocus;
  RadioGroup->OnExitSource += OnRadioLoseFocus;
}

// TDBEdit OnKeyDown event handler method, check which TDBEdit control
// the event is for, TDBEdit1 is read only
void TDlgClient::EditKeyDown(TDBEditKeySink&, TDBEdit& edit, SHORT *,TShiftState)
{
   if (edit.HWindow == Edit1->HWindow)
	{
      // make sure the helper window has not been closed by the user
   	if (OutputWin->HWindow)
			OutputWin->OutputString("TDBEdit1 Key Down, Read Only TDBEdit");
   }
   else if (edit.HWindow == Edit2->HWindow)
   {
      // make sure the helper window has not been closed by the user
   	if (OutputWin->HWindow)
   		OutputWin->OutputString("TDBEdit2 Key Down");
   }
}

// TDBEdit OnEnter event handler method
void TDlgClient::EditGetFocus(TDBEditNotifySink&, TDBEdit&)
{
   // make sure the helper window has not been closed by the user
   if (OutputWin->HWindow)
   	OutputWin->OutputString("TDBEdit2 Get Focus");
}

// TDBEdit OnExit event handler method
void TDlgClient::EditLoseFocus(TDBEditNotifySink&, TDBEdit&)
{
   // make sure the helper window has not been closed by the user
	if (OutputWin->HWindow)
 		OutputWin->OutputString("TDBEdit2 Lose Focus");
}

// TDBEdit OnChange event handler method
void TDlgClient::EditDataChange(TDBEditNotifySink&, TDBEdit&)
{
   // make sure the helper window has not been closed by the user
	if (OutputWin->HWindow)
  		OutputWin->OutputString("TDBEdit2 Data Change");
}

// TDBRadioGroup OnChange event handler method
void TDlgClient::RadioGroupChange(TDBRadioGroupNotifySink&, TDBRadioGroup&)
{
   // make sure the helper window has not been closed by the user
   if (OutputWin->HWindow)
		OutputWin->OutputString("TDBRadioGroup Data Change");
}

// TDBRadioGroup OnEnter event handler method
void TDlgClient::RadioGroupGetFocus(TDBRadioGroupNotifySink&, TDBRadioGroup&)
{
   // make sure the helper window has not been closed by the user
   if (OutputWin->HWindow)
		OutputWin->OutputString("TDBRadioGroup Get Focus");
}

// TDBRadioGroup OnExit event handler method
void TDlgClient::RadioGroupLoseFocus(TDBRadioGroupNotifySink&, TDBRadioGroup&)
{
   // make sure the helper window has not been closed by the user
   if (OutputWin->HWindow)
		OutputWin->OutputString("TDBRadioGroup Lose Focus");
}


// TDBNavigator OnClick event handler method, check which btn was clicked
void TDlgClient::NavBtnClicked(TDBNavigatorClickSink&, TDBNavigator&,
	TNavigateBtn navBtn)
{
  	char buf[50];
   switch(navBtn)
   {
   	case nbFirst:
   		wsprintf(buf,"Nav Click Event, First btn");
      	break;
   	case nbPrior:
   		wsprintf(buf,"Nav Click Event, Prior btn");
      	break;
   	case nbNext:
   		wsprintf(buf,"Nav Click Event,Next btn");
      	break;
   	case nbLast:
   		wsprintf(buf,"Nav Click Event, Last btn");
      	break;
   	case nbInsert:
   		wsprintf(buf,"Nav Click Event, Insert btn");
      	break;
   	case nbDelete:
   		wsprintf(buf,"Nav Click Event, Delete btn");
      	break;
   	case nbEdit:
   		wsprintf(buf,"Nav Click Event, Edit btn");
      	break;
   	case nbPost:
   		wsprintf(buf,"Nav Click Event, Post btn");
      	break;
   	case nbCancel:
   		wsprintf(buf,"Nav Click Event, Cancel btn");
      	break;
   	case nbRefresh:
   		wsprintf(buf,"Nav Click Event, Refresh btn");
      	break;
   	default:
   		wsprintf(buf,"Nav Click Event");
   }
   // make sure the helper window has not been closed by the user
   if (OutputWin->HWindow)
   	OutputWin->OutputString(buf);
}

