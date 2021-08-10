/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  Created: 1/1/96
  Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
  $Revision:   1.10  $

:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __ITX_H
#define __ITX_H

#include <ideaddon\common.h>
#include <ideaddon\IPolyStr.h>
#include <ideaddon\itx.uid>

/******************************************************************************
*
* ITargetType:
*
* This implementation only supports TargetType that has one platform.
* i.e. Addon target can't create a target type like Application [.exe] that
*     supports Win32 and Win 3.1. The workaround is to create a Win32
*     Application [.exe] and Win 3.1 Application [.exe].
*
* This simplification greatly reduces the complexity of the interfaces being
* exposed here.
*
******************************************************************************/
struct ITargetType : IUnknown {
  //
  // IsTargetable() returns 1 if fileExt matches the target's file extension.
  //
  virtual BOOL      IsTargetable(IPolyString* fileExt) = 0;
  //
  // ConvertNodeToTarget() converts any project node to a target
  //
  virtual ProjectNode  ConvertNodeToTarget(ProjectNode node, IPolyString* name) = 0;
  //
  // ConvertTargetToNode() converts targeg back to a node
  //
  virtual STDMETHODIMP ConvertTargetToNode(ProjectNode node) = 0;

  //
  //  GetClassID() returns the class id of the target
  //
  //Pointer to CLSID of component object
  //
  virtual HRESULT GetClassID(CLSID *pClassID) = 0;
};

/******************************************************************************
*
* ITargetManager
*
******************************************************************************/

DECLARE_HANDLE  (HTARGET);

struct ITargetManager : IUnknown {
  //
  // An target object calls AddTargetType to notify target manager about its 
  // existence
  //
  virtual HTARGET  AddTargetType( ITargetType* targetType
                      , IPolyString* description
                      , HINSTANCE hInst
                      , UINT dlgId) = 0;
  virtual void    TreatAsTarget( ITargetType* targetType
                      , ProjectNode targetNode) = 0;
};

//
// data format string of target property
//
#define CF_TARGETPROPERTY "TargetProperty"

/******************************************************************************
*
* ITargetManagerDialogControl is the interface used to access the window
* in TargetExpert dialog
*
******************************************************************************/
struct ITargetManagerDialogControl : IUnknown {
  //
  // Enable() enable or disable a control
  //
  virtual STDMETHODIMP Enable(BOOL fEnable) = 0;
};
/******************************************************************************
*
* ITargetManagerDialogList is the interface to access the combobox and listbox
* control in TargetExpert dialog
*
******************************************************************************/
struct ITargetManagerDialogList : ITargetManagerDialogControl {
  //
  // Add() add str to the list and return an interger id that identifies
  //  the added string
  //
  virtual STDMETHODIMP_(UINT) Add(IPolyString* str, HTARGET htarget) = 0;
  //
  // Select() selects the item the contains str
  //
  virtual STDMETHODIMP      Select(IPolyString* str) = 0;
  //
  // Clear() clears the content of the listbox or combobox
  //
  virtual STDMETHODIMP      Clear() = 0;
};

/******************************************************************************
*
* ITargetManagerPropertyDialog is the interface to access TargetExpert dialog
*
******************************************************************************/
struct ITargetManagerPropertyDialog : IUnknown {
  //
  // GetTargetTypeList() returns the target type listbox in TargetExpert dialog
  //
  virtual ITargetManagerDialogList*  GetTargetTypeList() = 0;
  // 
  // GetPlatformList() returns the platform combobox in TargetExpert dialog
  //
  virtual ITargetManagerDialogList*  GetPlatformList() = 0;
  // 
  // GetImageList() returns the model combobox in TargetExpert dialog
  //
  virtual ITargetManagerDialogList*  GetImageList() = 0;
  // 
  // GetAdvanceButton() returns the advance button in TargetExpert dialog
  //
  virtual ITargetManagerDialogControl* GetAdvancedButton() = 0;
  // 
  // GetControlWindow() returns the widnow handle of control id
  //  in TargetExpert dialog
  //
  virtual HWND                 GetControlWindow(UINT id) = 0;
};

/******************************************************************************
*
* ITargetPropertyPage : A target type implements this interface to display
* UI in TargetExpert dialog
*
******************************************************************************/
struct ITargetPropertyPage : IUnknown {
  //
  //
  // PlatformSelectionChangeNotification() is called when the supported
  // platform is selected
  //
  virtual void       PlatformSelectionChangeNotification(UINT id) = 0;
  //
  // AdvancedDialog() is called when advance button is clicked
  //
  virtual void       AdvancedDialog(HWND hwndParent) = 0;
  //
  // Setup() is called on the selected target type when the TargetExpert dialog
  //  is displayed initially.
  //
  //
  virtual void       Setup(ProjectNode) = 0;
  //
  // OnCommand() is called to process WM_COMMAD message
  //
  virtual void       OnCommand(UINT id) = 0;
  //
  // MakeTarget() is called when user client Ok in TargetExpert dialog
  //
  //virtual ProjectNode MakeTarget(ProjectNode node, IPolyString* name) = 0;
  //
  // GetDlgItems() is called to retrieve the control values
  //
  virtual void       GetDlgItems() = 0;
  //
  // SetDlgItems() is called to set the control values
  //
  virtual void       SetDlgItems() = 0;
};

#endif // __ITX_H
