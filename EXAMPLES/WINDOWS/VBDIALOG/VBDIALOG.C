// Borland C++ - (C) Copyright 1993 by Borland International
//
//  Windows VBX Example - C/C++ Version
//
#include <windows.h>
#include <windowsx.h>
#pragma hdrstop
#include <bivbx.h>
#include "vbdialog.h"

// some useful macros for working with VBX controls
#define VBXGetDlgItem(w,i)          VBXGetHctl(GetDlgItem(w,i))


static HINSTANCE hInst;

void SamplesEvent( VBXEVENT FAR * lpEvent )
{
  LONG val;
  switch( lpEvent->ID )
  {
    case IDC_BIPICT3:
      if( ! lstrcmpi( lpEvent->EventName, "DragDrop" ) )
	if( VBXGetPropByName(VBX_EVENTARGNUM(lpEvent,HCTL,0),"Picture",&val) )
	  VBXSetPropByName( lpEvent->Control, "Picture", val );
      break;
    case IDC_BIPICT1:
    case IDC_BIPICT2:
      if( ! lstrcmpi( lpEvent->EventName, "DragDrop" ) )
	MessageBeep(0);
      break;
  }
}

void SamplesTimer( HWND hWnd, int iSwitch, int iGauge )
{
  HCTL hCtlSwitch = VBXGetDlgItem(hWnd,iSwitch);
  HCTL hCtlGauge  = VBXGetDlgItem(hWnd,iGauge);

  LONG on  = 0;
  LONG val = 0;

  if( VBXGetPropByName( hCtlSwitch, "On", &on ) && on )
    if( VBXGetPropByName( hCtlGauge, "Value", &val ) )
      VBXSetPropByName( hCtlGauge, "Value", (LONG) ( val + 5 ) % 100 );
}

LONG FAR PASCAL SamplesDialog
(
HWND hWnd,
WORD wMsg,
WORD wParam,
LONG lParam
)
{
  // process the message
  switch( wMsg )
  {
    // process command from one of the child controls
    case WM_COMMAND:
      switch( GET_WM_COMMAND_ID(wParam,lParam) )
      {
	// ok or cancel, so end the dialog
	case IDOK:
	case IDCANCEL:
	  EndDialog( hWnd, 0 );
	  break;
      }
      break;

    // process VBX event
    case WM_VBXFIREEVENT:
      SamplesEvent( (VBXEVENT FAR *)lParam );
      break;
      
    // initialize the dialog
    case WM_INITDIALOG:
      VBXInitDialog( hWnd, hInst, "Samples" );
      SetTimer( hWnd, 0, 0, 0 );
      return FALSE;

    // timer tick
    case WM_TIMER:
      SamplesTimer( hWnd, IDC_BISWITCH1, IDC_BIGAUGE1 );
      SamplesTimer( hWnd, IDC_BISWITCH2, IDC_BIGAUGE2 );
      SamplesTimer( hWnd, IDC_BISWITCH3, IDC_BIGAUGE3 );
      SamplesTimer( hWnd, IDC_BISWITCH4, IDC_BIGAUGE4 );
      break;
  }
  return FALSE;
}

// Turn off warning: Parameter * is never used in function WinMain...
#pragma argsused

int PASCAL WinMain
(
HINSTANCE hInstance,
HINSTANCE hPrevInstance,
LPSTR     lpszCmdLine,
int       nCmdShow
)
{
  // save the instance
  hInst = hInstance;

  // initialize the VBX library
  if( ! VBXInit( hInstance, "Thunder" ) )
  {
    MessageBox( NULL, "Can't init VBX library!\n", NULL, MB_OK | MB_APPLMODAL );
    return 0;
  }
  
  // load the samples dialog box
  if( DialogBox( hInstance, "Samples", NULL, (FARPROC)SamplesDialog ) == -1 )
    MessageBox( NULL, "Can't load dialog box!\n", NULL, MB_OK | MB_APPLMODAL );

  // terminate the VBX library
  VBXTerm();
  
  // end of program
  return 0;
}

