//----------------------------------------------------------------------------
// ObjectComponents
// Copyright (c) 1994, 1996 by Borland International, All Rights Reserved
//
// $Revision:   2.5  $
//
// Implements message hooks for catching F1 in the dialogs
//----------------------------------------------------------------------------
#include "BOle.h"
#include "BOleSvc.h"

extern "C" {
  #include "Ole2UI.h"
}


// BOleHelpNotify is a C function which is exposed to the OLE2UI dialog
// boxes (but not to other DLLs) for them to call back to get help from 
// the application.
//
// 2 minor hacks are used here to solve the language differences between
// the Bolero header files (C++ only) and OLE2UI (C, and I don't have the 
// time to convert it to C++)
//
// 1. We're using the resource IDs of the dialog boxes to identify which 
//    dialog box to provide help on since OLE2UI can't compile the 
//    BOleDialogHelp enum.
//
// 2. The pCastToApp parameter is used because OLE2UI can't compile the
//    class definition for IBApplication.
//
extern "C" void BOleHelpNotify (DWORD pCastToApp, int dialogResId)
{
	BOleDialogHelp helpCode;
	switch (dialogResId) {
		case IDD_INSERTCONTROL: helpCode = BOLE_HELP_BROWSECONTROL;   break;
		case IDD_INSERTOBJECT : helpCode = BOLE_HELP_BROWSE;          break;
		case IDD_PASTESPECIAL : helpCode = BOLE_HELP_BROWSECLIPBOARD; break;
		case IDD_CONVERT      : helpCode = BOLE_HELP_CONVERT;         break;
		case IDD_EDITLINKS    : helpCode = BOLE_HELP_BROWSELINKS;     break;
		case IDD_CHANGEICON   : helpCode = BOLE_HELP_CHANGEICON;      break;
		case IDD_INSERTFILEBROWSE
		                      : helpCode = BOLE_HELP_FILEOPEN;        break;
		case IDD_CHANGESOURCE : helpCode = BOLE_HELP_SOURCESET;       break;
		case IDD_CHANGEICONBROWSE
		                      : helpCode = BOLE_HELP_ICONFILEOPEN;    break;
		default               : return;
	}

	PIBApplication pIApp = (PIBApplication) pCastToApp;
	pIApp->DialogHelpNotify (helpCode);
}


#ifndef WIN32    // help for old nonMS OLEUI  (MS_OLEUI_DEF)

extern "C" {
  #include "Common.h"
}

// GetBOleHook -- Examine the parameters to our hook proc and determine if 
//                it's a message we should handle. If so, return the hook 
//                out of the window properties
//
HHOOK GetBOleHook (int code, WPARAM wParam, LPARAM lParam)
{
	HHOOK hHook = NULL;

	// Make sure the message is one we should handle
	//
	if (code != MSGF_DIALOGBOX                 || 
		((LPMSG) lParam)->message != WM_KEYDOWN ||
		((LPMSG) lParam)->wParam != VK_F1)
		 return hHook; 

	// The window property "Structure" contains the private part of the
	// dialog struct (INSERTOBJECT is private, OLEUIINSERTOBJECT is public)
	//
	HWND hwnd = GetParent (((LPMSG) lParam)->hwnd);
	HANDLE hOleUIStd = GetProp (hwnd, TEXT(STRUCTUREPROP));
	if (!hOleUIStd)
		return hHook;

	// The data model in OLE2UI is limiting here. If we want to get the
	// pointer to the public part of a dialog struct, there's nothing to
	// cast this pointer to. OleUIStandard doesn't have the pointer in the
	// beginning like the private declarations of the dialog box structs!
	//
	LPOLEUISTANDARD pOleUIStd = (LPOLEUISTANDARD) ((LPLONG) GlobalLock (hOleUIStd))[0];
	if (!pOleUIStd)
		return hHook;

	// If we're a system-wide hook, make sure this hook was installed in
	// this task before returning it.
	//

	hHook = pOleUIStd->hHook;
	
	GlobalUnlock (hOleUIStd);
	return hHook;
}

// MyHookProc is a MessageProc callback for SetWindowsHookEx which allows
// us to catch messages during our dialog boxes. We're looking for F1
// keystrokes which would otherwise be eaten by the control with focus.
//
extern "C" LRESULT _loadds CALLBACK MyHookProc (int code, WPARAM wParam, LPARAM lParam)
{
	HHOOK hHook = GetBOleHook (code, wParam, lParam);
	if (hHook) {

		// The window which really gets the message is the control, so the
		// dialog is its parent
		//
		HWND w = GetParent (((LPMSG) lParam)->hwnd);
		::PostMessage(w, RegisterWindowMessage(HELPMSGSTRING), 0, 0);
		return ::CallNextHookEx (hHook, code, wParam, lParam);
	}
	return 0; 
}

// EnterBOleDialog has two basic jobs:
// 1. Install and remove the Windows hook which allows us to catch
//    F1 keystrokes while we're running a BOleUI dialog box.
// 2. Make sure we do the right enabling of modeless dialogs around
//    the system
//
void BOleService::ExitBOleDialog ()
{
	// If we're closing this dialog box, remove the Windows hook 
	::UnhookWindowsHook (WH_MSGFILTER, MyHookProc);
	OnModalDialog (FALSE);
	return;
}

void BOleService::EnterBOleDialog (HWND hwndOwner, HHOOK *hHook, HTASK *hTask)
{
	BOOL  fHookSuccess = TRUE;
  HHOOK hook;

	// Find the address of the callback for the Windows hook
	//
	HOOKPROC hookProc = (HOOKPROC)MyHookProc; 
	if (!hookProc) 
		fHookSuccess = FALSE;

	// Install the Windows hook
	//
	if (fHookSuccess) {
		hook = ::SetWindowsHook (WH_MSGFILTER, hookProc);
		if (!(hook)) 
			fHookSuccess = FALSE;

    if (fHookSuccess && hHook)
      *hHook = hook;

		// Pass back the current "task"
		//
    if (hTask)
  		*hTask = GetCurrentTask();
	}

	// Use the same thing Bolero clients do to en/disable modeless dialogs
	//
	OnModalDialog (TRUE);
}


#else  // WIN32   HELP for OLEUI standard dlgs


const TCHAR selectorPtr[] = TEXT("UnlikelyNameClash_HelpSelectorPtr");
const TCHAR offsetPtr[] = TEXT("UnlikelyNameClash_HelpOffsetPtr");


BOOL GetBOleHook (UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == RegisterWindowMessage (SZOLEUI_MSG_HELP)) {
		 return TRUE; 
  } else 
     return FALSE;
}

// MyWndProc is a MessageProc callback for hWndOwner to monitor for
// help messages for OleUI dialogs.
//
extern "C" LRESULT _loadds CALLBACK MyWndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	WORD sel = (WORD)GetProp (hwnd, selectorPtr);
	WORD off = (WORD)GetProp (hwnd, offsetPtr);
	BOleService *pSvc = (BOleService *) MAKELONG(off,sel);

	if (GetBOleHook (msg, wParam, lParam)) 
    BOleHelpNotify ((DWORD) pSvc->GetApplication(), lParam);

  return ::CallWindowProc(pSvc->lpfnHelpWndProc, hwnd, msg, wParam, lParam);
}

// EnterBOleDialog has two basic jobs:
// 1. Install and remove the Windows hook which allows us to catch
//    F1 keystrokes while we're running a BOleUI dialog box.
// 2. Make sure we do the right enabling of modeless dialogs around
//    the system
//
void BOleService::ExitBOleDialog ()
{
	// If we're closing this dialog box, remove the Windows hook 

  SetWindowLong (helpWnd, GWL_WNDPROC, (LONG)lpfnHelpWndProc);
	RemoveProp (helpWnd, selectorPtr);
	RemoveProp (helpWnd, offsetPtr);
  lpfnHelpWndProc = NULL;
  helpWnd = NULL;
	OnModalDialog (FALSE);
	return;
}

void BOleService::EnterBOleDialog (HWND hwndOwner, HHOOK *hHook, HTASK *hTask)
{
  if (lpfnHelpWndProc == NULL) {
  	 UINT    helpMsg = RegisterWindowMessage(SZOLEUI_MSG_HELP);
     WNDPROC wndProc = (WNDPROC)MyWndProc; 
     helpWnd = hwndOwner;

     SetProp (helpWnd, selectorPtr, (HANDLE)HIWORD((DWORD)this)); 	//SELECTOROF(this));
     SetProp (helpWnd, offsetPtr, (HANDLE)LOWORD((DWORD)this));		//OFFSETOF(this));

     lpfnHelpWndProc =  (WNDPROC)GetWindowLong (helpWnd, GWL_WNDPROC);
     SetWindowLong (helpWnd, GWL_WNDPROC, (LONG)wndProc);
  }

	// Use the same thing Bolero clients do to en/disable modeless dialogs
	//
	OnModalDialog (TRUE);
}
#endif  // WIN32

