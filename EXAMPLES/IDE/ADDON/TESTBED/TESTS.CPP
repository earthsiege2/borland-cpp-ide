/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  tests.cpp
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.15  $
  
  To add a new test:
  - Derive your test class from TestObject and implement pure virtual methods
    (see option.h and option.cpp for a simple example)
  - Include its header here
  - Add a new instance to the _testObjArray in Tests::setup(), 
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif

#pragma hdrstop

#include <string.h>   // strcmp()
#include <assert.h>

#include "tests.h"
#include "option.h"
#include "project.h"
#include "target.h"
#include "toolsrvr.h"
#include "script.h"
#include "testdlg.h"
#include "edittest.h"
#include "maketest.h"
#include "viewtest.h"
#include "filetest.h"
#include "mpdtest.h"
#include "cmdtest.h"
#include "menutest.h"
#include "tool2.h"
#include "edittool.h"
#include "msgtest.h"

//.............................................................................
void Tests::setup() {
  //
  // MAX_TESTS is currently set to 100 in tests.h.
  //
  if ( _setup ) {
    return;
  }
  AddTest( new MpdTest );
  AddTest( new OptionSetTestA );
  AddTest( new TargetTestA );
  AddTest( new ProjectTestA );
  AddTest( new ToolTestA );
  AddTest( new ScriptTestA );
  AddTest( new ToolTestB );
  AddTest( new EditTestA );
  AddTest( new MakeTestA );
  AddTest( new ViewTest );
  AddTest( new FileTestA );
  AddTest( new CmdTestA );
  AddTest( new MenuTestA );
  AddTest( new ToolTestC );
  AddTest( new EditToolTest );
  AddTest( new MsgSystemTest);
  AddTest( new EditTestB );
  AddTest( new MenuTestB );

  _setup = TRUE;
}
//.............................................................................
Tests::Tests() { 
  memset( _testObjArray, NULL, sizeof( _testObjArray ) );
  _setup = FALSE;
}
//.............................................................................
Tests::~Tests() {
  TestObject * * p = _testObjArray;
  for ( int i = 0; i < MAX_TESTS; ++i, ++p ) {
    if ( *p ) {
      delete (*p);
    }
  }
}  
//.............................................................................
Tests Tests::_theTests;

//.............................................................................
Tests * Tests::GetTests() {
  //
  // static method.
  //
  _theTests.setup();
  return &_theTests;  
}
//.............................................................................
void Tests::AddTest( TestObject * testObj ) {
  TestObject * * p = _testObjArray;
  for ( int i = 0; i < MAX_TESTS; ++i, ++p ) {
    if ( *p == NULL ) {
      *p = testObj;
      return;
    }
  }
  assert( 1 );    // TOO MANY TESTS!
}
//.............................................................................
void Tests::RegisterOutput( TestOutput * output ) {
  TestObject * * p = _testObjArray;
  for ( int i = 0; i < MAX_TESTS; ++i, ++p ) {
    if ( *p ) {
      (*p)->RegisterOutput( output );
    }
  }
}  
//.............................................................................
int Tests::NumTestObjects() { 
  int count = 0;
  TestObject * * p = _testObjArray;
  for ( int i = 0; i < MAX_TESTS; ++i, ++p ) {
    if ( *p ) {
      ++count;
    }
  }
  return count;
}
//.............................................................................
TestObject * Tests::GetTestObject( int testObjectNum ) {
  return _testObjArray[ testObjectNum ];
}
//.............................................................................
TestObject * Tests::FindTestObject( const char * name ) {
  TestObject * * p = _testObjArray;
  for ( int i = 0; i < MAX_TESTS; ++i, ++p ) {
    if ( *p ) {
      if ( 0 == strcmp( (*p)->GetName(), name ) ) {
        return *p;
      }
    }
  }
  return NULL;
}  
//.............................................................................
const char * TestObject::FormatStr( const char * fmt, ... ) {
  static char buf[ 1024 ];
  va_list va;
  va_start( va, fmt );
  wvsprintf( buf, fmt, va );
  va_end( va );
  return buf; 
}  
//.............................................................................
void TestObject::ShowPolyStr( const char * label, 
                    IPolyString * ps, 
                    BOOL release ) {
  if ( ps ) {
    OutStr( FormatStr( "%s: %s", label, ps->GetCstr() ) );
    if ( release ) {
      ps->Release();
    }
  }
}

extern HINSTANCE ghInst = NULL;
//.............................................................................
extern "C" void WINAPI __export
BcwAddOnEntry( IIdeServer * pIdeServer ) {
  if ( pIdeServer ) {       // startup time
    SetIdeServer( pIdeServer );
    CreateTestDialog( ghInst );
  }
  else {                // shutdown time
    DestroyTestDialog();
    ReleaseIdeServer();
  }
}
//.............................................................................
extern "C" BOOL WINAPI __export
DllEntryPoint(HINSTANCE hInst, DWORD fdwReason, LPVOID) {
  ghInst = hInst;
  static BOOL oleInit = FALSE;
  switch( fdwReason ) {
    case DLL_PROCESS_ATTACH: 
      if ( FAILED( OleInitialize(NULL) ) ) {
        return FALSE;
      }
      oleInit = TRUE;
      break;

    case DLL_PROCESS_DETACH:
      if ( oleInit ) {
        OleUninitialize();
      }
      break;
  }
  return TRUE;
}
  
