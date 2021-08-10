/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  edittest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.16  $
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "edittest.h"

//.............................................................................
EditTestA::EditTestA() 
  {
  _editServer = NULL;
  }
//.............................................................................
EditTestA::~EditTestA() 
  {
  UnInit();
  }
//.............................................................................
BOOL EditTestA::Init() 
  {
  if ( !_editServer ) 
    {
    OutStr( "EditTestA::Init()" );
    _editServer = GET_INTERFACE(IEditorServer);
    if ( _editServer == NULL ) 
      {
      return FALSE;
      }
    }
  return TRUE;
}
//.............................................................................
void EditTestA::UnInit() 
  {
  OutStr( "EditTestA::UnInit()" );
  if ( _editServer ) 
    {
    _editServer->Release();
    _editServer = NULL;
    }
  }
//.............................................................................
const char * EditTestA::GetName() 
  {
  return "Editor server tests";
  }
//.............................................................................
const char * EditTestA::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "Comment the current line.";
    case 2: 
      return "Return the length of the current line.";
    case 3: 
      return "Convert the current line to upper case.";
    case 4: 
      return "Return info about the current buffer.";
    }
  return "This test not implemented.";
  }  
//.............................................................................
void EditTestA::DoTest( int testNum ) 
  {
  if ( !_editServer ) 
    {
    OutStr( "Editor Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1: 
      {
      IPolyString *comment = ::MakePolyString ("//");
      if (comment != NULL)
        {
        _editServer->begin_edit();
        BufferId bid = _editServer->inq_buffer();
        if ( bid )
          {
          _editServer->beginning_of_line();
          _editServer->insert( comment );
          _editServer->down();
          }
        _editServer->end_edit();
        }
      else 
        {
        OutStr( FormatStr( "Failure to make a polystr." ) );
        }
      }
      break;

    case 2: 
      {
      _editServer->begin_edit();
      BufferId bid = _editServer->inq_buffer();
      if ( bid )
        {
        OutStr( FormatStr( "Line length = %d", _editServer->inq_line_length() ) );
        }
      _editServer->end_edit();
      }
      break;

    case 3: 
      {
      _editServer->begin_edit();
      BufferId bid = _editServer->inq_buffer();
      if ( bid )
        {
        _editServer->beginning_of_line();
        IPolyString *chars = _editServer->read();
        if ( chars )
          {
          _editServer->delete_line();
          int len = strlen( chars->GetCstr() );
          char *newchars = new char[len + 1]; 
          if ( newchars )
            {
            strcpy ( newchars, chars->GetCstr() );
            strupr ( newchars );
            IPolyString *poly = ::MakePolyString (newchars);
            if (poly != NULL)
              {
              _editServer->insert( poly );
              }
            delete[] newchars;
            }
          chars->Release();
          }
        }
      _editServer->end_edit();
      }
      break;

    case 4: 
      {
      _editServer->begin_edit();
      BufferId bid = _editServer->inq_buffer();
      if ( bid )
        {
        IPolyString *name = NULL;
        IPolyString *ext = NULL;
        IPolyString *bufname = NULL;

        _editServer->inq_names( &name, &ext, &bufname );

        if ( name )
          ShowPolyStr ("File name = ", name, TRUE);
        if ( ext )
          ShowPolyStr ("Extension = ", ext, TRUE);
        if ( bufname )
          ShowPolyStr ("Buffer name = ", bufname, TRUE);
        }
      _editServer->end_edit();
      }
      break;

    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }



//////////////////////////////////////////////////////////////////////////////
//
//  Edit Test B
//
//////////////////////////////////////////////////////////////////////////////


//.............................................................................
EditTestB::EditTestB() 
  {
  _editServer = NULL;
  }
//.............................................................................
EditTestB::~EditTestB() 
  {
  UnInit();
  }
//.............................................................................
BOOL EditTestB::Init() 
  {
  if ( !_editServer ) 
    {
    OutStr( "EditTestB::Init()" );
    _editServer = GET_INTERFACE(IEditorServer);
    if ( _editServer == NULL ) 
      {
      return FALSE;
      }
    }
  return TRUE;
}
//.............................................................................
void EditTestB::UnInit() 
  {
  OutStr( "EditTestB::UnInit()" );
  if ( _editServer ) 
    {
    _editServer->Release();
    _editServer = NULL;
    }
  }
//.............................................................................
const char * EditTestB::GetName() 
  {
  return "Editor undo/redo";
  }
//.............................................................................
const char * EditTestB::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1: 
      return "Is undo Available?";
    case 2: 
      return "Perform the undo.";
    case 3: 
      return "Is redo Available?";
    case 4: 
      return "Perform the redo.";
    }
  return "This test not implemented.";
  }  
//.............................................................................
void EditTestB::DoTest( int testNum ) 
  {
  if ( !_editServer ) 
    {
    OutStr( "Editor Server not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1: 
      if ( _editServer->undo_available() )
        OutStr( "Undo is available.");
      else
        OutStr( "Undo is not available.");
      break;

    case 2: 
      _editServer->begin_edit();
      _editServer->undo();
      _editServer->end_edit();
      break;

    case 3: 
      if ( _editServer->redo_available() )
        OutStr( "Redo is available.");
      else
        OutStr( "Redo is not available.");
      break;

    case 4: 
      _editServer->begin_edit();
      _editServer->redo();
      _editServer->end_edit();
      break;

    default: 
      {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
      }
    }
  }
