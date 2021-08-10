/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  filetest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:  
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "filetest.h"

//.............................................................................
FileTestA::FileTestA() 
  {
  _vFile = NULL;
  }
//.............................................................................
FileTestA::~FileTestA() 
  {
  UnInit();
  }
//.............................................................................
BOOL FileTestA::Init() 
  {
  OutStr( "FileTestA::Init()" );
  if ( !_vFile ) 
    {
    _vFile = ::CreateVirtualFile();
    }
  return ( _vFile != NULL );
  }
//.............................................................................
void FileTestA::UnInit() 
  {
  OutStr( "FileTestA::UnInit()" );
  if ( _vFile ) 
    {
    _vFile->Release();
    _vFile = NULL;
    }
  }
//.............................................................................
const char * FileTestA::GetName() 
  {
  return "File Test A";
  }
//.............................................................................
const char * FileTestA::GetTestDescription( int testNum ) 
  {
  switch ( testNum )
    {
    case 1:
      return "Make a new file called c:\\testfile.txt";
    }
  return "This test not implemented.";
  }  
//.............................................................................
void FileTestA::DoTest( int testNum ) 
  {
  if ( !_vFile ) 
    {
    OutStr( "Virtual file not initialized!" );
    return;
    }
  switch ( testNum ) 
    {  
    case 1:
      {
      OutStr ("Writing Hello World to file c:\\testfile.txt");
      IPolyString *name = ::MakePolyString ( "c:\\TestFile.txt" );
      if ( name )
        {
        _vFile->Init ( name );
        _vFile->Open ( VFOM_Create );
        if ( _vFile->Exists() )
          {
          _vFile->Write ( "Hello World", 11 );
          _vFile->Close ();
          OutStr ("Success!");
          }
        else
          {
          OutStr ("Couldn't create a new file for writing");
          }
        }
      else
        {
        OutStr ("Couldn't make a PolyString");
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
