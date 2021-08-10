/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  option.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $
  
  Test the OptionSet server.
  See tests.h for a description of the TestObject class, which OptionSetTestA
  derives from.
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif

#pragma hdrstop

#include <ideaddon\ioption.h>
#include <ideaddon\iproj.h>
#include "option.h"

//.............................................................................
OptionSetTestA::OptionSetTestA() { 
  _optionSetServer = NULL; 
  _projectServer = NULL;
}
//.............................................................................
OptionSetTestA::~OptionSetTestA() {
  UnInit();
}

//.............................................................................
BOOL OptionSetTestA::Init() {
  //
  // The user has clicked the Init button while positioned on the OptionSet
  // Test A test.
  //
  OutStr( "OptionSetTestA::Init()" );
  if ( !_optionSetServer ) {
    _optionSetServer = GET_INTERFACE( IOptionSetServer );
  }
  if ( !_projectServer ) {
    _projectServer = GET_INTERFACE( IProjectServer );
  }   
  return ( _optionSetServer && _projectServer );
}
//.............................................................................
void OptionSetTestA::UnInit() {
  //
  // The user has clicked the UnInit button or our destructor has been 
  // called.
  //
  OutStr( "OptionSetTestA::UnInit()" );
  if ( _optionSetServer ) {
    _optionSetServer->Release();
    _optionSetServer = NULL;
  }
  if ( _projectServer ) {
    _projectServer->Release();
    _projectServer = NULL;
  }
}  
//.............................................................................
const char * OptionSetTestA::GetName() {
  //
  // Return a name to display in the list of tests.
  //
  return "OptionSet Test A";
}
//.............................................................................
const char * OptionSetTestA::GetTestDescription( int testNum ) {
  //
  // Return a description of each sub-test to display when the user presses
  // the '?' button next to a sub-test button.
  //
  switch ( testNum ) {
    case 1: 
      return "Sets the include path of the selected node(s) to something useless.";
    case 2:
      return "Show include path of the selected node(s)";
    case 3:
      return "Set a #define for the selected node(s)";
    case 4:
      return "removes *all* local overrides for the selected node(s)";
  }
  return "This test not implemented.";
}  
//.............................................................................
void OptionSetTestA::DoTest( int testNum ) {
  //
  // The user has clicked one of the test buttons.
  //
  int numNodes;
  ProjectNode * nodeArray;
  
  if ( !_optionSetServer || !_projectServer ) {
    //
    // We shouldn't ever get here.
    //
    OutStr( "OptionSet Server not initialized!" );
    return;
  }
  
  //
  // Get the currently selected project nodes, these tests will manipulate
  // options on the selected nodes.
  //
  nodeArray = _projectServer->QuerySelectedNodes( &numNodes );
  
  if ( !numNodes ) {
    OutStr( "No selected node(s) to work with" );
  }
  
  for ( int i = 0; i < numNodes; ++i ) {
    switch ( testNum ) {
      case 1: {
        //
        // We'll set the include path to something really funky, just to
        // show that it worked. 
        //
        OutStr( "Setting include path for node" );
        _optionSetServer->OptionApply(  nodeArray[i], 
                              OID_Include,
                              ::MakePolyString( "OptionSet Test A-1" )
                            );
        break;
      }       
      case 2: {
        OutStr( "Include path of node:" );
        IPolyString* pps = _optionSetServer->OptionGet( nodeArray[i], OID_Include );
        ShowPolyStr ( "", pps, TRUE );
        break;
      }
      case 3: { 
        OutStr( "Add Define \"HelloDefine\" to node" );
        IPolyString * name = ::MakePolyString( "HelloDefine" );
        _optionSetServer->OptionApply( nodeArray[i], OID_Defines, name );
        break;
      }
      case 4: {
        OutStr( "Remove local options from node" );
        _optionSetServer->OptionRemove( nodeArray[i], OID_RemoveAll );
        break;
      }
      default: {
        OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }
}




