/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  filetest.cpp
  Created: 10/24/95
  Copyright (c) 1995, Borland International
  $Revision:   1.18  $  
   
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/  
#ifndef __AOEXPCH_H
  #include "aoexpch.h"
#endif
#pragma hdrstop

#include "filetest.h"

//.............................................................................
FileTestA::FileTestA() {
  _vFile = NULL;
}
//.............................................................................
FileTestA::~FileTestA() {
  UnInit();
}
//.............................................................................
BOOL FileTestA::Init() {
  OutStr( "FileTestA::Init()" );
  if ( !_vFile ) {
    _vFile = ::CreateVirtualFile();
  }
  return ( _vFile != NULL );
}
//.............................................................................
void FileTestA::UnInit() {
  OutStr( "FileTestA::UnInit()" );
  if ( _vFile ) {
    _vFile->Release();
    _vFile = NULL;
  }
}
//.............................................................................
const char * FileTestA::GetName() {
  return "File Test A";
}
//.............................................................................
const char * FileTestA::GetTestDescription( int testNum ) {
  switch ( testNum ) {
    case 1:
      return "Make a new file called testfile.txt";
    case 2:
      return "Read \"paint.cpp\" (must live in bc5\\examples\\owl\\paint directory - can be in edit buffer)";
    case 3:
      return "Read/Write from/to testfile.txt";
  }
  return "This test not implemented.";
}  
//.............................................................................
IPolyString * FileTestA::getReadFilePath() {
  char buf[ 1000 ];
  IIdeServer * ide = GetIdeServer();
  IPolyString * rootDir = ide->ProductRootDirectory();
  wsprintf( buf, "%s\\examples\\owl\\apps\\paint\\paint.cpp", rootDir->GetCstr() );
  rootDir->Release();
  ide->Release();
  return ::MakePolyString( buf );
}
//.............................................................................
bool FileTestA::compareFiles( IVirtualFile * reader ) {
  bool ok = true;
  const int bufsize = 4048;
  OutStr( "Comaring files..." );
  IVirtualFile * reader2 = ::CreateVirtualFile();
  reader2->Init( MakePolyString( "filetest.txt" ) );
  char buf1[ bufsize ];
  char buf2[ bufsize ];
  reader->Seek( 0, FILE_BEGIN );
  if ( !reader2->Exists() || !reader2->Open( VFOM_Read ) ) {
    ok = false;
  }
  while ( ok ) {
    int num1 = reader->Read( buf1, bufsize );
    int num2 = reader2->Read( buf2, bufsize );
    if ( num1 != num2 ) {
      ok = false;
      break;
    }
    if ( 0 == num1 ) {
      break;
    }
    char * x = buf1;
    char * y = buf2;
    while ( num1-- ) {
      if ( *x != *y ) {
        ok = false;
        break;
      }
    }
  }
  OutStr( ok? "Compare OK." : "Compare failed!" );
  reader2->Release();
  return ok;
}
//.............................................................................
bool FileTestA::testReadWrite() {
  //
  // Requires that test2 has been succesfully run.
  //
  bool ok = true;
  IVirtualFile * file = ::CreateVirtualFile();
  if ( !file ) {
    return false;
  }
  file->Init( MakePolyString( "filetest.txt" ) );
  if ( !file->Exists() ) {
    ok = false;
    OutStr( "Couldn't find filetest.txt" );
  }
  if ( ok && !file->Open( VFOM_ReadWrite ) ) {
    ok = false;
    OutStr( "Couldn't open filetest.txt" );
  }
  if ( ok ) {
    char * buf2 = new char[ 10 ];
    while ( 1 ) {
      int numchars = file->Read( buf2, 10 );
      file->Write( buf2, numchars );
      if ( !numchars ) {
        break;
      }
    }
  }
  file->Release();
  return ok;
}   
//.............................................................................
bool FileTestA::testRead() {
  const int bufsize = 4048;
  bool ok = true;
  int count = 0;
  IVirtualFile * reader = ::CreateVirtualFile();
  if ( !reader ) {
    return false;
  }
  IVirtualFile * writer = ::CreateVirtualFile();
  if ( !writer ) {
    reader->Release();
    return false;
  }
  IPolyString * path = getReadFilePath();
  reader->Init( path );
  writer->Init( MakePolyString( "filetest.txt" ) );
  if ( !writer->Open( VFOM_Create ) ) {
    OutStr( "Couldn't create filetest.txt" );
    ok = false;
  }
  if ( ok && !reader->Exists() ) {
    OutStr( "Couldn't find paint.cpp" );
    ok = false;
  }
  if ( ok && !reader->Open( VFOM_Read ) ) {
    OutStr( "Couldn't open paint.cpp" );
    ok = false;
  }
  if ( ok ) {
    char * buf2 = new char[ bufsize ];
    while ( 1 ) {
      int numchars = reader->Read( buf2, bufsize );
      if ( numchars ) {
        count += numchars;
        writer->Write( buf2, numchars );
      }
      else {
        break;
      }
    }
    delete [] buf2;             
  }
  writer->Release();
  ok = compareFiles( reader );
  reader->Release();
  OutStr( FormatStr( "Test #2 %s. %d chars read", ok? "succeeded" : "failed", count ) );
  return ok;
}
//.............................................................................
void FileTestA::DoTest( int testNum ) {
  if ( !_vFile ) {
    OutStr( "Virtual file not initialized!" );
    return;
  }
  switch ( testNum ) { 
    case 1: {
      OutStr ("Writing Hello World to file c:\\testfile.txt");
      IPolyString *name = ::MakePolyString ( "c:\\TestFile.txt" );
      if ( name ) {
        _vFile->Init ( name );
        _vFile->Open ( VFOM_Create );
        if ( _vFile->Exists() ) {
          _vFile->Write ( "Hello World", 11 );
          _vFile->Close ();
          OutStr ("Success!");
        }
        else {
          OutStr ("Couldn't create a new file for writing");
        }
      }
      else {
        OutStr ("Couldn't make a PolyString");
      }
      break;
    }
    case 2:
      testRead();
      break;
      
    case 3:
      testReadWrite();
      break;

    default: {
      OutStr( FormatStr( "Test #%d Not Implemented!", testNum ) );
    }
  }
}
