/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  testdlg.cpp
  Copyright (c) 1987, 1996 Borland International Inc.  All Rights Reserved.
  $Revision:   1.18  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif

#pragma hdrstop


#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windowsx.h>

#include "tests.hrc"
#include "tests.h"

//.............................................................................
class TestDlgOutput : public TestOutput {
 public:
  TestDlgOutput() { _hEditBox = NULL; } 
  virtual void Show( const char * str );
  void RegisterEditBox( HWND hEditBox ) { 
    _hEditBox = hEditBox; 
    SendMessage( _hEditBox, EM_LIMITTEXT, 0, 0 ); // don't limit text
  }
 protected:
  HWND _hEditBox; 
};
//.............................................................................
void TestDlgOutput::Show( const char * str ) {
  if ( _hEditBox ) {
    SendMessage( _hEditBox, EM_REPLACESEL, 0, (LPARAM) str );
    SendMessage( _hEditBox, EM_REPLACESEL, 0, (LPARAM) "\r\n" );
  }
}

//.............................................................................
class TestDlg {
 public:
  TestDlg();
  ~TestDlg() {}
  void InitDialog();
  void EnableTesting();
  BOOL FindTesterFromCurrentSelection();
  void DialogCommand( WORD wNotifyCode, WORD wID ); 
  long WndProc( HWND hwnd, UINT message, UINT wParam, LONG lParam );
  HWND Create( HINSTANCE hInstance );
  void Destroy();
  void Topmost();
  void Show();
 protected:
  HWND _hwnd;
  Tests * _tests;
  TestObject * _currentTestObj;
  BOOL _topmost;
  TestDlgOutput _testDlgOutput;
};
static TestDlg theTestDlg;

//.............................................................................
TestDlg::TestDlg() {
  _hwnd = NULL;
  _tests = NULL;
  _currentTestObj = NULL;
  _topmost = FALSE;
}  

//.............................................................................
void TestDlg::EnableTesting() {
  int fEnable = (_currentTestObj != NULL);
  EnableWindow(GetDlgItem(_hwnd, IDC_LIST1), !fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_INIT), !fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_UNINIT), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST1), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST2), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST3), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST4), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST1_HELP), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST2_HELP), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST3_HELP), fEnable);
  EnableWindow(GetDlgItem(_hwnd, IDC_TEST4_HELP), fEnable);
}
//.............................................................................
void TestDlg::InitDialog() {
  if ( !_tests ) {
    HWND hwndCtl = GetDlgItem(_hwnd, IDC_LIST1);
    _tests = Tests::GetTests();
    for ( int i = 0; i < _tests->NumTestObjects(); ++i ) {
      ListBox_AddString( hwndCtl, _tests->GetTestObject( i )->GetName() );
    } 
    _testDlgOutput.RegisterEditBox( GetDlgItem( _hwnd, IDC_OUTPUT ) );
    _tests->RegisterOutput( &_testDlgOutput );
    EnableTesting();
  }
}
//.............................................................................
BOOL TestDlg::FindTesterFromCurrentSelection() {
  char szBuffer[256];
  if ( _tests ) {
    HWND hwndCtl = GetDlgItem( _hwnd, IDC_LIST1);
    int index = ListBox_GetCurSel( hwndCtl );
    ListBox_GetText( hwndCtl, index, szBuffer );
    _currentTestObj = _tests->FindTestObject( szBuffer );
  }
  return _currentTestObj != NULL;
}
//.............................................................................
void TestDlg::DialogCommand( WORD wNotifyCode, WORD wID ) {
  switch (wNotifyCode) {
   case BN_CLICKED:
   {
    switch (wID)
    {
      case IDC_CLOSE:
        //.... simulate IDC_UNINIT command .....
        DialogCommand( BN_CLICKED, IDC_UNINIT );
        DestroyWindow( _hwnd );
        return;
      case IDC_INIT:
       if ( FindTesterFromCurrentSelection() ) {
        _currentTestObj->Init();
        EnableTesting();
       }
       break;
      case IDC_UNINIT:
       if ( _currentTestObj ) {
        _currentTestObj->UnInit();
        _currentTestObj = NULL;
        EnableTesting();
       }
       break;
      case IDC_TEST1:
       if ( _currentTestObj ) {
        _currentTestObj->DoTest( 1 );
       }
       break;
      case IDC_TEST2:
       if ( _currentTestObj ) {
        _currentTestObj->DoTest( 2 );
       }
       break;
      case IDC_TEST3:
       if ( _currentTestObj ) {
        _currentTestObj->DoTest( 3 );
       }
       break;
      case IDC_TEST4:
       if ( _currentTestObj ) {
        _currentTestObj->DoTest( 4 );
       }
       break;
    case IDC_TEST1_HELP:
      if ( _currentTestObj ) {
        MessageBox( _hwnd, _currentTestObj->GetTestDescription( 1 ), "Test 1", MB_OK );
      }
      break;
    case IDC_TEST2_HELP:
      if ( _currentTestObj ) {
        MessageBox( _hwnd, _currentTestObj->GetTestDescription( 2 ), "Test 2", MB_OK );
      }
      break;
    case IDC_TEST3_HELP:
      if ( _currentTestObj ) {
        MessageBox( _hwnd, _currentTestObj->GetTestDescription( 3 ), "Test 3", MB_OK );
      }
      break;
    case IDC_TEST4_HELP:
      if ( _currentTestObj ) {
        MessageBox( _hwnd, _currentTestObj->GetTestDescription( 4 ), "Test 4", MB_OK );
      }
      break;
    case IDC_TOPMOST:
      _topmost = IsDlgButtonChecked( _hwnd, IDC_TOPMOST );
      Show();
      break; 
    }
   };
   break;
   case LBN_DBLCLK:
   {
   }
   break;
  }
}
//.............................................................................
long CALLBACK __export theWndProc (HWND hwnd, UINT message, UINT wParam ,LONG lParam) {
  return theTestDlg.WndProc( hwnd, message, wParam, lParam );
}
//.............................................................................
long TestDlg::WndProc( HWND hwnd, UINT message, UINT wParam, LONG lParam ) {
  _hwnd = hwnd;
  switch (message) {
    case WM_SHOWWINDOW:
      Topmost();
      InitDialog();
      break;
    case WM_COMMAND: {
        WORD wNotifyCode = HIWORD(wParam); // notification code
        WORD wID = LOWORD(wParam);      // item, control, or accelerator identifier
        DialogCommand( wNotifyCode, wID );
        break;
    }
    case WM_CLOSE:
      //.... simulate IDC_UNINIT command .....
      DialogCommand( BN_CLICKED, IDC_UNINIT );
      DestroyWindow( _hwnd );
      _hwnd = NULL;
      break ;
  }
  return DefDlgProc( _hwnd, message, wParam, lParam );
}
//.............................................................................
HWND TestDlg::Create( HINSTANCE hInstance ) {
  WNDCLASS wndclass;
  wndclass.style       = CS_HREDRAW | CS_VREDRAW ;
  wndclass.lpfnWndProc   = theWndProc ;
  wndclass.cbClsExtra   = 0 ;
  wndclass.cbWndExtra   = DLGWINDOWEXTRA ;
  wndclass.hInstance    = hInstance ;
  wndclass.hIcon       = LoadIcon (hInstance, MAKEINTRESOURCE(IDI_ICON1)) ;
  wndclass.hCursor      = LoadCursor (NULL, IDC_ARROW) ;
  wndclass.hbrBackground  = (HBRUSH)(COLOR_BACKGROUND+1); // COLOR_BTNFACE
  wndclass.lpszMenuName = NULL ;
  wndclass.lpszClassName  = "AddOnTester";
  RegisterClass (&wndclass) ;

  _hwnd = CreateDialog( hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, NULL) ;
  Show();
  return _hwnd;
};
//.............................................................................
void TestDlg::Destroy() {
  DestroyWindow( _hwnd );
}
//.............................................................................
void TestDlg::Topmost() {
  if ( _hwnd ) {
    CheckDlgButton( _hwnd, IDC_TOPMOST, _topmost );
    SetWindowPos( _hwnd, _topmost? HWND_TOPMOST : HWND_NOTOPMOST, 
              0,0,0,0, SWP_NOMOVE | SWP_NOSIZE );
  }
}
  
//.............................................................................
void TestDlg::Show() {  
  Topmost();
  ShowWindow( _hwnd, SW_SHOW );
}
//.............................................................................
HWND CreateTestDialog(HINSTANCE hInstance) {
  return theTestDlg.Create( hInstance );
}
//.............................................................................
void DestroyTestDialog() {
  theTestDlg.Destroy();
}
