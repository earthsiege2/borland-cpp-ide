/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  tests.h
  Created: 10/24/95
  Copyright (c) 1995, 1996 Borland International
  $Revision:   1.15  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#ifndef __TESTS_H
#define __TESTS_H

#include <ideaddon\ipolystr.h>

#define MAX_TESTS  100

extern HINSTANCE ghInst;

//.............................................................................
class TestOutput {
  //
  // The output implementation will be supplied by the dialog box object
  // through the TestObject::RegisterOutput() method.
  //
 public: 
  virtual void Show( const char * str ) = 0;
};

//.............................................................................
//
// A TestObject represents a group of related tests. Many TestObject's can be
// registered to appear in the test dialog box (see tests.cpp for where this
// is done).
// 
// Anything that you need to do at IDE startup time can be done inside a 
// TestObject constructors (see BcwAddOnInit() in tests.cpp to step through
// what happens).
//
// AddOn's should never call CoCreateInstance() inside
// DllEntryPoint on a PROCESS_ATTACH as this will crash under NT. Instead
// do this type of initialization inside BcwAddOnInit().
//
//
class TestObject {
 public:
  //.... interface .....
  //
  // Init() and UnInit() are called when a user clicks the corresponding buttons
  // in the test dialog box.
  //
  virtual BOOL Init() = 0;
  virtual void UnInit() = 0; 
  //
  // GetName() is called by the dialog box to display each test objects name
  // in a list box.
  //
  virtual const char * GetName() = 0;
  //
  // GetTestDescription() is called by the dialog box to get the description
  // of each sub-test of the test object when the user clicks the '?' button
  // next to each test button.
  //
  virtual const char * GetTestDescription( int testNum ) = 0;
  //
  // When the user clicks one of the test buttons, DoTest() is called with
  // the sub-test number.
  //
  virtual void DoTest( int testNum ) = 0;

  //.... implementation ....
  TestObject() { _output = NULL; }
  //
  // OutStr() calls the registered TestOutput Show() method, which is
  // responsible for displaying the string in the dialog box output window.
  //
  virtual void OutStr( const char * str ) { if ( _output ) _output->Show( str ); }
  //
  // FormatStr is a helper function which does printf style formatting. This 
  // can be called with OutStr, eg. OutStr( FormatStr( ... ) ); It uses a 
  // static char buffer good up to 1024 chars.
  //
  virtual const char * FormatStr( const char * fmt, ... ); 
  //
  // Another output helper function, ShowPolyStr() will display a label
  // followed by a PolyString (see ipolystr.h!). If 'release' is TRUE, 
  // the PolyString object will be released after it is displayed - which 
  // means you better not try and use it again!
  //
  virtual void ShowPolyStr( const char * label, IPolyString * ps, BOOL release = FALSE );
  //
  // This is called by the Tests object to pass in the TestOutput object
  // supplied by the dialog box object.
  //
  virtual void RegisterOutput( TestOutput * output ) { _output = output; }

 protected:
  TestOutput * _output;
};

//.............................................................................
//
// This object represents the test suite. New tests shouldn't need to know
// anything about this, except how to get registered, which is described
// in test.cpp.
//
class Tests {
 public:
  Tests();
  ~Tests();
  int NumTestObjects();
  TestObject * GetTestObject( int testObjectNum );
  TestObject * FindTestObject( const char * name );
  void RegisterOutput( TestOutput * output );
  static Tests * GetTests();
 protected:
  void setup();
  void AddTest( TestObject * testObj );
  static Tests _theTests;
  TestObject * _testObjArray[ MAX_TESTS ];
  BOOL _setup;
};


#endif    // __TESTS_H


