/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  toolsrvr.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.19  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "toolsrvr.h"

//.............................................................................
ToolTestA::ToolTestA() 
  {
  _toolServer = NULL;
  }
//.............................................................................
ToolTestA::~ToolTestA() 
  {
  UnInit();
  }
//.............................................................................
BOOL ToolTestA::Init() 
  {
  if ( !_toolServer ) 
    {
    OutStr( "ToolTestA::Init()" );
    _toolServer = GET_INTERFACE(IToolServer);
    if ( _toolServer == NULL ) 
      {
      return FALSE;
      }
    }
  return TRUE;
}
//.............................................................................
void ToolTestA::UnInit() 
  {
  OutStr( "ToolTestA::UnInit()" );
  if ( _toolServer ) 
    {
    _toolServer->Release();
    _toolServer = NULL;
    }
  }
//.............................................................................
const char * ToolTestA::GetName() 
  {
  return "Tool Test A";
  }
//.............................................................................
const char * ToolTestA::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "Returns info about the WinSight tool.";
    case 2: 
      return "resource compiles the currently selected .rc node.";
    case 3: 
      return "Grep currently selected nodes.";
    case 4: 
      return "Dump some lines from autoexec.bat to msg window.";
    }
  return "This test not implemented.";
  }  
//.............................................................................
void ToolTestA::DoTest( int testNum ) 
  {
  char buf[ 500 ];
  if ( !_toolServer ) 
    {
    OutStr( "Tool Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1: 
      {
      ToolObj toolObj = _toolServer->ToolFind( ::MakePolyString ( "WinSight" ) );
      if ( toolObj ) 
        {
        IToolInfo * pToolInfo = _toolServer->QueryToolInfo ( toolObj );
        if ( pToolInfo != NULL )
          {
          ConcatPolyStr ( "Name = ", pToolInfo->GetName(), buf, 255, TRUE );
          ConcatPolyStr ( "Menu Name = ", pToolInfo->GetMenuName(), buf, 255, TRUE );
          ConcatPolyStr ( "Help Hint = ", pToolInfo->GetHelpHint(), buf, 255, TRUE );
          ConcatPolyStr ( "Path = ", pToolInfo->GetPath(), buf, 255, TRUE );
          ConcatPolyStr ( "Cmd Line = ", pToolInfo->GetDefCmdLine(), buf, 255, TRUE );
          ConcatPolyStr ( "Supported Types = ", pToolInfo->GetSupportedTypes(), buf, 255, TRUE );
          ConcatPolyStr ( "DefForTypes = ", pToolInfo->GetDefaultForTypes(), buf, 255, TRUE );
          ConcatPolyStr ( "TranslateTo = ", pToolInfo->GetTranslateTo(), buf, 255, TRUE );
 
          pToolInfo->Release();
          }
        } 
      else 
        {
        OutStr( FormatStr( "Couldn't find tool named %s.", "WinSight" ) );
        }
      break;
      }

    case 2:  // cpp compile the currently selected node.
      {
      OutStr( "Invoking the resource compiler..." );
      ToolObj toolObj = _toolServer->ToolFind( 
        ::MakePolyString ( "CompileResources" ) 
        );
      if ( toolObj ) 
        {
        ToolReturn tr = _toolServer->ToolInvoke( toolObj );
        OutStr( FormatStr( "ToolReturn = %d", tr ) );
        }
      else
        {
        OutStr( "CompileResources not found" );
        }
      break;
      }

    case 3:  // grep selected nodes.
      {
      OutStr( "Invoking GrepFiles tool..." );
      ToolObj toolObj = _toolServer->ToolFind( 
        ::MakePolyString ( "GrepFiles" )
        );
      if ( toolObj ) 
        {
        ToolReturn tr = _toolServer->ToolInvoke( toolObj );
        OutStr( FormatStr( "ToolReturn = %d", tr ) );
        }
      else
        {
        OutStr( "GrepFiles not found" );
        }
      break;
      }

    case 4:  // search for path in autoexec.bat
      {
      OutStr( "Invoking GrepFiles tool..." );
      ToolObj toolObj = _toolServer->ToolFind(
        ::MakePolyString ( "GrepFiles" ) 
        );
      if ( toolObj ) 
        {
        ToolReturn tr = _toolServer->ToolInvokeName(
          toolObj,
          ::MakePolyString ( "" ),
          ::MakePolyString ( 
            "-r+ [A-Za-z] c:\\autoexec.bat $NOSWAP$CAP MSG(GREP2MSG)" )
          );
        OutStr( FormatStr( "ToolReturn = %d", tr ) );
        }
      else
        {
        OutStr( "GrepFiles not found" );
        }
      break;
      }

    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }

void ToolTestA::ConcatPolyStr (const char *startStr,
              IPolyString *pPoly, char *buf, int max, bool OutIt )
  {
  strncpy ( buf, startStr, max );
  if ( pPoly != NULL )
    {  
    const char *cstr = pPoly->GetCstr();
    if ( cstr != NULL )
      {
      strncat ( buf, cstr, max );
      }
    pPoly->Release();
    }
  if ( OutIt )
    {
    OutStr( buf );
    }
  }

///////////////////////////////////////////////////////////////////////////////
//
//  Tool Implementors - Callbacks for TestTool1
//
///////////////////////////////////////////////////////////////////////////////
class TestToolImplOne : public IUnknownImp<IToolImplementor>
{

 public:
  TestToolImplOne () : IUNKNOWNIMPL_INIT( IToolImplementor ) {}

  virtual ToolReturn Execute( IPolyString * cmdLine, 
                      ProjectNode * nodeArray, 
                      int numNodes );
};

ToolReturn TestToolImplOne::Execute( IPolyString *, ProjectNode *, int)
  {
  ::MessageBox(NULL, "Cool Tool", "Addon Message", MB_OK);
  return TR_Success;
  }

class TestToolImplTwo : public IUnknownImp<IToolImplementor>
{

 public:
  TestToolImplTwo () : IUNKNOWNIMPL_INIT( IToolImplementor ) {}

  virtual ToolReturn Execute( IPolyString * cmdLine, 
                      ProjectNode * nodeArray, 
                      int numNodes );
};

ToolReturn TestToolImplTwo::Execute( IPolyString *, ProjectNode *, int)
  {
  ::MessageBox(NULL, "Cool Tool 2", "Addon Message", MB_OK);
  return TR_Success;
  }


/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  ProjectClientImpl 
  
  Add a tool when a project opens
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
void ProjectToolClient::OpenNotify( IPolyString * projectName ) 
  {
  if ( _currentProject )
    _currentProject->Release();
  
  _currentProject = projectName;

  if ( _currentProject )
    _toolTestB->AddTool();
  }

void ProjectToolClient::CloseNotify() 
  {
  if ( _currentProject )
    {
    _currentProject->Release();
    _currentProject = NULL;
//
//     It turns out that this is a bad place to remove tools. In earlier
//     versions of BCW, this event was being fired off too early, when a 
//     project close could still be aborted by the user. Now, removing 
//     the tool here has no effect, since it's too late for the toolset
//     to be updated. Also, this wouldn't prevent the tools from being
//     saved with the project if the user explicitly performs a project
//     save without a project close. So, we use a new interface, 
//     IProjectSaveClient to trigger the tool remove.
//
//     _toolTestB->RemoveTool();
    }
  }
  
void ToolTestB::BeforeSaveNotify() {
  //
  // Don't let the add-on tool be saved with the project.
  //
  RemoveTool();
}
void ToolTestB::AfterSaveNotify() {
  //
  // Put it back, since the project doesn't always close after a save.
  //
  AddTool();
}
  

///////////////////////////////////////////////////////////////////////////////
//
//  ToolTestB
//
///////////////////////////////////////////////////////////////////////////////

//.............................................................................
// Make a project client so we can add a tool when a project opens.
//
ToolTestB::ToolTestB() : IUNKNOWNIMPL_INIT( IProjectSaveClient ) {
  _toolServer = NULL;
  _projectClient = NULL;
  _projectServer = NULL;

  _toolServer = GET_INTERFACE(IToolServer);
  if ( _toolServer ) {
    _projectServer = GET_INTERFACE( IProjectServer );
    if ( _projectServer ) {
      _projectClient = new ProjectToolClient( this );
      if ( _projectClient ) {
        _projectClient->AddRef();
        _projectServer->RegisterProjectClient( _projectClient );
      }
      IProjectServer2 * ps2 = GET_INTERFACE( IProjectServer2 );
      if ( ps2 ) {  // this interface not availabe in BCW versions < 5.01
        AddRef();
        ps2->RegisterProjectSaveClient( this );
        ps2->Release();
      }
    }
  }
}

//.............................................................................
ToolTestB::~ToolTestB() {
  if ( _projectClient ) {
    if ( _projectServer ) {
      _projectClient->AddRef();
      _projectServer->UnregisterProjectClient( _projectClient );
      IProjectServer2 * ps2 = GET_INTERFACE( IProjectServer2 );
      if ( ps2 ) {  // this interface not availabe in BCW versions < 5.01
        AddRef();
        ps2->UnregisterProjectSaveClient( this );
        ps2->Release();
      }
    }
    _projectClient->Release();
    _projectClient = 0;
  }

  if ( _projectServer ) {
    _projectServer->Release();
  }

  if ( _toolServer ) {
    _toolServer->Release();
  }
}
//.............................................................................
BOOL ToolTestB::Init() 
  {
  if ( _toolServer && _projectServer && _projectClient ) 
    {
    OutStr( "Init was done at startup (Success)" );
    return TRUE;
    }
  else
    {
    OutStr( "Init was done at startup (Failed)" );
    return FALSE;
    }
  }

//.............................................................................
void ToolTestB::UnInit() 
  {
  OutStr( "UnInit will be done at shutdown" );
  }
//.............................................................................
const char * ToolTestB::GetName() 
  {
  return "Test Tool Implementor";
  }
//.............................................................................
const char * ToolTestB::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "invoke the tool called TestTool1";
    case 2: 
      return "Update TestTool1 with a new callback";
    case 3:
      return "Update TestTool1 so it has no callback";
    }
  return "This test not implemented.";
  }  
//.............................................................................
//
// The tool is added at contructor time. These 2 tests just use it. The first
// invokes it. The second gives it a new implementor.
//
void ToolTestB::DoTest( int testNum ) 
  {
  if ( !_toolServer ) 
    {
    OutStr( "Tool Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1:
      {
      OutStr( "Invoking TestTool1" );
      ToolObj toolObj = _toolServer->ToolFind( ::MakePolyString ( "TestTool1" ) );
      if ( toolObj ) 
        {
        ToolReturn tr = _toolServer->ToolInvoke( toolObj );
        OutStr( FormatStr( "ToolReturn = %d", tr ) );
        }
      else
        {
        OutStr( "TestTool1 not found" );
        }
      }
      break;

    case 2:
      {
      OutStr( "Update TestTool1 with a new callback" );
      IToolInfo * ti = _toolServer->CreateToolInfoInstance();
      if ( ti )
        {
        TestToolImplTwo *testtool = new TestToolImplTwo();
        if ( testtool )
          {
          ti->SetImplementor( testtool );
          ti->SetName ( ::MakePolyString( "TestTool1" ) );
          if ( _toolServer->ToolAdd( ti ) ) // will Release the old implementor
            OutStr( "Add Succeeded" );
          else
            OutStr( "Add Failed" );
          }
        else
          {
          OutStr( "Memory Error" );
          }
        ti->Release();
        }
      else
        {
        OutStr( "Memory Error" );
        }
      }
      break;

    case 3:
      {
      OutStr( "Update TestTool1 so it has no callback" );
      IToolInfo * ti = _toolServer->CreateToolInfoInstance();
      if ( ti )
        {
        ti->SetImplementor( NULL );
        ti->SetName ( ::MakePolyString( "TestTool1" ) );
        if ( _toolServer->ToolAdd( ti ) ) // will Release the old implementor
          OutStr( "Add Succeeded" );
        else
          OutStr( "Add Failed" );
        ti->Release();
        }
      else
        {
        OutStr( "Memory Error" );
        }
      }
      break;

    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }

//.............................................................................
// Called by the project client to add a tool when the project opens
//
void ToolTestB::AddTool()
  { 
  // Add the tool to _toolProjectName project and no other
  OutStr( "Adding a tool called TestTool1" );
  ToolObj toolObj = _toolServer->ToolFind( ::MakePolyString ( "TestTool1" ) );
  if ( toolObj )
    {
    OutStr( "TestTool1 already exists!. Removing it first." );
    _toolServer->ToolRemove( toolObj );
    }
  IToolInfo * ti = _toolServer->CreateToolInfoInstance();
  if ( ti )
    {
    TestToolImplOne *testtool = new TestToolImplOne();
    if ( testtool )
      {
      ti->SetImplementor( testtool );
      ti->SetName ( ::MakePolyString( "TestTool1" ) );
      if ( _toolServer->ToolAdd( ti ) )
        OutStr( "Add Succeeded" );
      else
        OutStr( "Add Failed" );
      }
    else
      {
      OutStr( "Memory Error" );
      }
    ti->Release();
    }
  else
    {
    OutStr( "Memory Error" );
    }
  }

//.............................................................................
// Called by the project client to remove a tool when the project closes
//
void ToolTestB::RemoveTool()
  { 
  OutStr( "Removing ToolTest1" );
  ToolObj toolObj = _toolServer->ToolFind( ::MakePolyString ( "TestTool1" ) );
  if ( toolObj ) 
    {
    _toolServer->ToolRemove( toolObj );
    }
  else
    {
    OutStr( "TestTool1 not found" );
    }
  }
