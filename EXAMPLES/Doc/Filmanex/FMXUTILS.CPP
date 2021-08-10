//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1998-2002 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include <shellapi.h>
#include <stdio.h>
#include "FmxUtils.h"
//---------------------------------------------------------------------------
TDateTime __fastcall FileDateTime(const AnsiString FileName)
{
  return (FileDateToDateTime(FileAge(FileName)));
}

// GetFileSize function
//
//  Returns the size of the named file without opening the file.  If the file
//  doesn't exist, returns -1.
//
long __fastcall GetFileSize(const AnsiString FileName)
{
  TSearchRec SearchRec;
    if(FindFirst(ExpandFileName(FileName), faAnyFile, SearchRec)==0)
      return SearchRec.Size;
    else
      return -1;
}

// MoveFile procedure
//
//  Moves the file passed in FileName to the directory specified in DestDir.
//  Tries to just rename the file.  If that fails, try to copy the file and
//  delete the original.
//
//  Throws an exception if the source file is read-only, and therefore cannot
//  be deleted/moved.
//
void __fastcall MoveFile(const AnsiString FileName,const AnsiString DestName)
{
  AnsiString Destination;
  char FName[255];
  bool ckmove;

  Destination=ExpandFileName(DestName);
  GetFileTitle(FileName.c_str(),FName,255);

  if(HasAttr(FileName, faReadOnly)) {
      char buffer[255];
      sprintf(buffer,
              "Error: Can not move the file '%s'.",
              FileName.c_str());

      throw EFCantMove(buffer);
  }

  if (HasAttr(Destination,faDirectory))
      Destination=Destination+AnsiString(FName);

  ckmove= MoveFile(FileName.c_str(), Destination.c_str());

  if(!ckmove)
    ShowMessage("Please give the destination filename");
}

void __fastcall CopyFile(AnsiString FileName,AnsiString DestName)
{
  bool   ckcopy;
  AnsiString Destination;
  char   FName[255];

  GetFileTitle(FileName.c_str(),FName,255);
  Destination = ExpandFileName(DestName);

  if(HasAttr(Destination,faDirectory))
    Destination=Destination+FName;

  ckcopy= CopyFile(FileName.c_str(),Destination.c_str(),false);

  if(!ckcopy)
    ShowMessage("Please give the destination filename");

}
//---------------------------------------------------------------------------
bool __fastcall HasAttr(const AnsiString FileName,const unsigned short Attr)
{
  int attribtest;

  attribtest=FileGetAttr(FileName);

  if(attribtest & Attr)
    return true;
  else
    return false;
}

//---------------------------------------------------------------------------
int __fastcall ExecuteFile(const AnsiString FileName,
                           const AnsiString Params,
                           const AnsiString DefaultDir,
                           int ShowCmd)
{

  char zFileName[79], zParams[79], zDir[79];
  return (int) ShellExecute(Application->MainForm->Handle,
                            NULL,
                            strcpy(zFileName,
                                   FileName.c_str()),
                            strcpy(zParams,
                                   Params.c_str()),
                            strcpy(zDir,
                                   DefaultDir.c_str()),
                            ShowCmd);
}
