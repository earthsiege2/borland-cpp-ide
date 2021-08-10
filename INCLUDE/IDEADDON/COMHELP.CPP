/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  comhelp.cpp
  Created: 10/20/95
  Copyright (c) 1995, Borland International
  $Revision:   1.15  $

  Helper Functions
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  

#include <assert.h>

#include <ideaddon\comhelp.h>

static IIdeServer * g_IdeServer = NULL;

//.............................................................................
void SetIdeServer( IIdeServer * pIdeServer )
  {
  g_IdeServer = pIdeServer;
  }

//.............................................................................
IIdeServer * GetIdeServer()
  {
  if ( g_IdeServer )
    {
    g_IdeServer->AddRef();
    } 
  return g_IdeServer;
  }

//.............................................................................
void ReleaseIdeServer()
  {
  if ( g_IdeServer )
    {
    g_IdeServer->Release();
    g_IdeServer = NULL;
    } 
  }

//.............................................................................
IUnknown * GetInterface ( REFCLSID rclsid )
  {
  IUnknown * pi = NULL;
  if ( g_IdeServer )
    {
    HRESULT hRes = g_IdeServer->QueryInterface( rclsid, (void **) &pi );
    if ( hRes != NOERROR )
      pi = NULL;
    }
  return pi;
  }

//.............................................................................
IPolyString * CreatePolyString()
  {
  IPolyString *polystr = NULL;
  IIdeServer * pIdeSrvr = ::GetIdeServer();
  if ( pIdeSrvr )
    {
    polystr = pIdeSrvr->CreatePolyString();
    pIdeSrvr->Release();
    }
  return polystr;
  }

//.............................................................................
IVirtualFile * CreateVirtualFile()
  {
  IVirtualFile *vfile = NULL;
  IIdeServer * pIdeSrvr = ::GetIdeServer();
  if ( pIdeSrvr )
    {
    vfile = pIdeSrvr->CreateVirtualFile();
    pIdeSrvr->Release();
    }
  return vfile;
  }

//.............................................................................
IViewType * CreateViewType()
  {
  IViewType *viewtype = NULL;
  IIdeServer * pIdeSrvr = ::GetIdeServer();
  if ( pIdeSrvr )
    {
    viewtype = pIdeSrvr->CreateViewType();
    pIdeSrvr->Release();
    }
  return viewtype;
  }

//.............................................................................
IPolyString *MakePolyString (const char *cstr)
  {
  IPolyString *polystr = ::CreatePolyString();
  if ( polystr != NULL )
    {
    polystr->SetCstr( cstr );
    } 
  return polystr;
  }

//.............................................................................
// Spit out a copy of the c string in a polystr. Release the polystr.
char *PolyCstrDup ( IPolyString *polystr )
  {
  char *newCstr = NULL;
  if ( polystr != NULL )
    {
    const char *oldCstr = polystr->GetCstr();
    if ( oldCstr != NULL )
      {
      newCstr = new char[ strlen( oldCstr ) + 1 ];
      if ( newCstr != NULL )
        {
        strcpy( newCstr, oldCstr );
        }
      }
    polystr->Release();
    }
  return newCstr;
  }
