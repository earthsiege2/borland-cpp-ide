/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  maketest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include <ideaddon\IProj.h>
#include "maketest.h"

//.............................................................................
class ProjectNodeResponder : public IProjectClient
{
  ULONG   m_RefCount;
  MakeTestA *_pMakeTest;
  IMakeServer *_pMakeSrvr;

 public:
  ProjectNodeResponder( MakeTestA * pMakeTestA, IMakeServer *pMakeSrvr  ) 
      : m_RefCount( 1 ), _pMakeTest( pMakeTestA ), _pMakeSrvr( pMakeSrvr )  {}

  // IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *)
      { return ResultFromScode(E_NOINTERFACE); }
  STDMETHODIMP_(ULONG) AddRef  (THIS) { return m_RefCount++; }
  STDMETHODIMP_(ULONG) Release (THIS) 
      {return --m_RefCount == 0 ? (delete this, 0) : m_RefCount; }

  virtual void OpenNotify( IPolyString * projectName ) {}
  virtual void CloseNotify() {}
  virtual void NodeDeleteNotify( ProjectNode node ) {}
  virtual void NodeAddNotify( ProjectNode node ) {}
  virtual void NodeCopyNotify( ProjectNode, ProjectNode, BOOL ) {}
  virtual void NodeMoveNotify( ProjectNode, ProjectNode ) {}
  virtual void NodeChangeNotify( ProjectNode ) {}
  virtual void DependencyQueryResponder( ProjectNode node, 
                            IPolyString * outputName );
  virtual BOOL HandleAddNodeUI() { return FALSE; }
                            
};

void ProjectNodeResponder::DependencyQueryResponder( ProjectNode node, 
                            IPolyString * outputName )
  {
  if ( node )
    {
    char *name;
    if ( outputName && ( name = (char *)outputName->GetCstr() ) != NULL )
      {
      long inputAge = _pMakeSrvr->NodeInputAge( node );
      long outputAge = _pMakeSrvr->NodeOutputAge( node );
      _pMakeTest->OutStr( name );
      _pMakeTest->OutStr( _pMakeTest->FormatStr( "Input Age = %u, Output Age = %u", inputAge, outputAge ) );
      }
    else
      {
      _pMakeTest->OutStr ("Invalid project node name");
      }
    }
  else
    {
    _pMakeTest->OutStr ("Invalid project node value");
    }
  }

//.............................................................................
class MakeClientA : public IMakeClient
{
  ULONG m_RefCount;
  MakeTestA *_pOwner;

 public:
  MakeClientA(MakeTestA * pMakeTestA) : m_RefCount( 1 ), _pOwner( pMakeTestA )  {}

  // IUnknown members
  STDMETHODIMP QueryInterface (THIS_ REFIID, LPVOID FAR *)
      { return ResultFromScode(E_NOINTERFACE); }
  STDMETHODIMP_(ULONG) AddRef  (THIS) { return m_RefCount++; }
  STDMETHODIMP_(ULONG) Release (THIS) 
      {return --m_RefCount == 0 ? (delete this, 0) : m_RefCount; }

  virtual void MakeBeginNotify()
      { _pOwner->OutStr( "MakeClientA::MakeBeginNotify()" ); }
  virtual void MakeEndNotify()
      { _pOwner->OutStr( "MakeClientA::MakeEndNotify()" ); }
};

//.............................................................................
MakeTestA::MakeTestA() 
  {
  _makeServer = NULL;
  _makeClient = NULL;
  }
//.............................................................................
MakeTestA::~MakeTestA() 
  {
  UnInit();
  }
//.............................................................................
BOOL MakeTestA::Init() 
  {
  if ( !_makeServer ) 
    {
    OutStr( "MakeTestA::Init()" );
    _makeServer = GET_INTERFACE(IMakeServer);
    if ( _makeServer == NULL ) 
      {
      return FALSE;
      }
    }
  return TRUE;
}
//.............................................................................
void MakeTestA::UnInit() 
  {
  OutStr( "MakeTestA::UnInit()" );
  if ( _makeClient )
    {
    if ( _makeServer )
      {
    _makeClient->AddRef();
      _makeServer->UnRegisterMakeClient( _makeClient );
      }
    _makeClient->Release();
    _makeClient = NULL;
    }
  if ( _makeServer ) 
    {
    _makeServer->Release();
    _makeServer = NULL;
    }
  }
//.............................................................................
const char * MakeTestA::GetName() 
  {
  return "MakeTestA";
  }
//.............................................................................
const char * MakeTestA::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "Register MakeClientA";
    case 2: 
      return "Unregister MakeClientA";
    case 3: 
      return "Make the top node";
    case 4:
      return "Show input and output ages of dependent nodes";
    }
  return "This test not implemented";
  }  
//.............................................................................
void MakeTestA::DoTest( int testNum ) 
  {
  if ( !_makeServer ) 
    {
    OutStr( "Make Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1: 
      {
      if ( _makeClient )
        {
        OutStr( "MakeClientA is already registered");
        }
      else
        {
        _makeClient = new MakeClientA( this );
        if ( _makeClient )
          {
        _makeClient->AddRef();
          _makeServer->RegisterMakeClient( _makeClient );
          OutStr( "Registered MakeClientA");
          }
        else
          {
          OutStr( "Creation of MakeClientA failed");
          }
        }
      }
      break;

    case 2: 
      {
      if ( _makeClient )
        {
       _makeClient->AddRef();
        _makeServer->UnRegisterMakeClient( _makeClient );

        _makeClient->Release();
        _makeClient = NULL;
        OutStr( "Unregistered MakeClientA");
        }
      else
        {
        OutStr( "MakeClientA is already unregistered");
        }
      }
      break;

    case 3:
      {
      IProjectServer *pProject = GET_INTERFACE(IProjectServer);
      if ( pProject == NULL ) 
        {
        OutStr( "Couldn't make a project server");
        }
      else
        {
        OutStr( "Make the top node");
        ProjectNode node = pProject->QueryTopNode();
        ProjectNode nodes[1];
        nodes[0] = (ProjectNode)node;
        _makeServer->MakeNodes( MM_Make, // Build, Translate
                        nodes,
                        sizeof(nodes)/sizeof(nodes[0]));
        pProject->Release();
        }
      }
      break;


    case 4:
      {
      IProjectServer *pProject = GET_INTERFACE(IProjectServer);
      if ( pProject == NULL ) 
        {
        OutStr( "Couldn't make a project server");
        }
      else
        {
        ProjectNode * nodeArray;
        int numNodes;
        OutStr( "Ages of dependent nodes of top selected node:" );
        nodeArray = pProject->QuerySelectedNodes( &numNodes );
        if ( numNodes )
          {
          ProjectNodeResponder * nodeResp = new ProjectNodeResponder( this, _makeServer );
          if ( nodeResp )
            {
            pProject->QueryDependencies( nodeArray[0], nodeResp ); 
            }
          else
            {
            OutStr( "Couldn't make a project client" );
            }
          }
        else
          {
          OutStr( "There is no selected node");
          }
        pProject->Release();
        }
      }
      break;

    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }


