
//**************************************************************************
//
// BOleHelp.cpp -- Implements message hooks for catching F1 in the dialogs
//
// Copyright (c) 1993,94 by Borland International, Inc. All rights reserved
//
//**************************************************************************

#include "BOle.h"
#include "BOleSvc.h"
extern "C" {
#include "Ole2UI.h"
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
		::PostMessage (w, RegisterWindowMessage(HELPMSGSTRING), 0, 0);
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
void _IFUNC BOleService::EnterBOleDialog (BOOL fEnter, HHOOK& hHook, HTASK& hTask)
{
	// If we're closing this dialog box, remove the Windows hook 
	//
	if (!fEnter) {
		::UnhookWindowsHook (WH_MSGFILTER, MyHookProc);

		OnModalDialog (FALSE);
		return;
	}

	BOOL fHookSuccess = TRUE;

	// Find the address of the callback for the Windows hook
	//
	HOOKPROC hookProc = (HOOKPROC)MyHookProc; //!::GetProcAddress (boleInst, "MYHOOKPROC");
	if (!hookProc) 
		fHookSuccess = FALSE;

	// Install the Windows hook
	//
	if (fHookSuccess) {
#ifndef WIN32
		hHook = ::SetWindowsHook (WH_MSGFILTER, hookProc);

#else
		hHook = ::SetWindowsHookEx (WH_MSGFILTER, hookProc, NULL, GetCurrentThreadId() );
#endif
		if (!hHook) 
			fHookSuccess = FALSE;

		// Pass back the current "task"
		//
#ifndef	WIN32
		hTask = GetCurrentTask();
#else
		hTask = (HTASK)GetCurrentThread();
#endif
	}

	// Use the same thing Bolero clients do to en/disable modeless dialogs
	//
	OnModalDialog (TRUE);
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


