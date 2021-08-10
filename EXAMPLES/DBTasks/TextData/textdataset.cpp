//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 2000-2002 Borland Corporation.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "TextDataSet.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
// ValidCtrCheck is used to assure that the components created do not have
// any pure virtual functions.
//

static inline void ValidCtrCheck(TTextDataSet *)
{
  new TTextDataSet(NULL);
}
//---------------------------------------------------------------------------
__fastcall TTextDataSet::TTextDataSet(TComponent* Owner)
  : TDataSet(Owner)
{
  before=false;
}
//---------------------------------------------------------------------------
void __fastcall TTextDataSet::BeforeDestruction()
{
  tmp = FFileName;
  before=true;
}
//This method is called by TDataSet.Open and also when FieldDefs need to
//be updated (usually by the DataSet designer).  Everything which is
//allocated or initialized in this method should also be freed or
//uninitialized in the InternalClose method.
void __fastcall TTextDataSet::InternalOpen()
{
  int i;

  //Load the textfile into a StringList
  FData = new TStringList();
  FData->LoadFromFile(FFileName);

  //Fabricate integral bookmark values
  for (i=0; i<FData->Count; i++)
    FData->Objects[i] = (TObject *)i;
  FLastBookmark = FData->Count;

  //Initialize our internal position, use -1 to indicate the "crack"
  //before the first record
  FCurRec = -1;

  //Indicate an offset value to find the TRecInfo structure in each buffer
  FRecInfoOfs = MaxStrLen;

  //Calculate the size of the record buffers.
  //Note: This is NOT the same as the RecordSize property which
  //only gets the size of the data in the record buffer
  FRecBufSize = FRecInfoOfs + sizeof(::TRecInfo);

  //Tell TDataSet how big our Bookmarks are (REQUIRED)
  BookmarkSize = sizeof(int);

  //Initialize the FieldDefs
  InternalInitFieldDefs();

  //Create TField components when no persistent fields have been created
  if (DefaultFields) CreateFields();

  //Bind the TField components to the physical fields
  BindFields(true);
}
//---------------------------------------------------------------------------
void __fastcall TTextDataSet::InternalClose()
{
  //Write any edits to disk and free the managing string list
  if (FSaveChanges)
  {
    if (before) FData->SaveToFile(tmp);
    else FData->SaveToFile(FFileName);
  }
  delete FData;
  FData = NULL;

  //Destroy the TField components if no persistent fields
  if (DefaultFields) DestroyFields();

  //Reset these internal flags
  FLastBookmark = 0;
  FCurRec = -1;
}
//---------------------------------------------------------------------------
//This property is used while opening the dataset.
//It indicates if data is available even though the
//current state is still dsInActive.
bool __fastcall TTextDataSet::IsCursorOpen()
{
  return (FData != NULL);
}
//---------------------------------------------------------------------------
//For this simple example we just create one FieldDef, but a more complete
//TDataSet implementation would create multiple FieldDefs based on the
//actual data.
void __fastcall TTextDataSet::InternalInitFieldDefs()
{
  FieldDefs->Clear();
  FieldDefs->Add("Line",ftString,MaxStrLen,false);
}
//---------------------------------------------------------------------------
//This is the exception handler which is called if an exception is raised
//while the component is being stream in or streamed out.  In most cases this
//should be implemented useing the application exception handler as follows.
void __fastcall TTextDataSet::InternalHandleException()
{
  Application->HandleException(this);
}
//---------------------------------------------------------------------------
//In this sample the bookmarks are stored in the Object property of the
//TStringList holding the data.  Positioning to a bookmark just requires
//finding the offset of the bookmark in the TStrings->Objects and using that

//value as the new current record pointer.
void __fastcall TTextDataSet::InternalGotoBookmark(void *Bookmark)
{
  int index;
  index = FData->IndexOfObject((TObject *)Bookmark);
  if (index != -1)
    FCurRec = index;
  else
    DatabaseError("Bookmark not found",this);
}
//---------------------------------------------------------------------------
//This function does the same thing as InternalGotoBookmark, but it takes
//a record buffer as a parameter instead
void __fastcall TTextDataSet::InternalSetToRecord(char *Buffer)
{
  InternalGotoBookmark((void *)((::PRecInfo)(Buffer+FRecInfoOfs))->Bookmark);
}
//---------------------------------------------------------------------------
//Bookmark flags are used to indicate if a particular record is the first
//or last record in the dataset.  This is necessary for "crack" handling.
//If the bookmark flag is bfBOF or bfEOF then the bookmark is not actually
//used; InternalFirst, or InternalLast are called instead by TDataSet.
TBookmarkFlag __fastcall TTextDataSet::GetBookmarkFlag(char *Buffer)
{
  return ((::PRecInfo)(Buffer+FRecInfoOfs))->BookmarkFlag;
}
//---------------------------------------------------------------------------
void __fastcall TTextDataSet::SetBookmarkFlag(char *Buffer, TBookmarkFlag val)
{
  ((::PRecInfo)(Buffer+FRecInfoOfs))->BookmarkFlag = val;
}
//---------------------------------------------------------------------------
//These methods provide a way to read and write bookmark data into the
//record buffer without actually repositioning the current record
void __fastcall TTextDataSet::GetBookmarkData(char *Buffer, void *Data)
{
  *(int *)Data = ((::PRecInfo)(Buffer+FRecInfoOfs))->Bookmark;
}
//---------------------------------------------------------------------------
void __fastcall TTextDataSet::SetBookmarkData(char *Buffer, void *Data)
{
  ((::PRecInfo)(Buffer+FRecInfoOfs))->Bookmark = *(int *)Data;

}
//---------------------------------------------------------------------------
//                      Record / Field Access
//---------------------------------------------------------------------------
//This method returns the size of just the data in the record buffer.
//Do not confuse this with RecBufSize which also includes any additonal
//structures stored in the record buffer (such as TRecInfo).
Word __fastcall TTextDataSet::GetRecordSize()
{
  return MaxStrLen;
}
//---------------------------------------------------------------------------
//TDataSet calls this method to allocate the record buffer.  Here we use
//FRecBufSize which is equal to the size of the data plus the size of the
//TRecInfo structure.
char * __fastcall TTextDataSet::AllocRecordBuffer()
{
  //char *ptr;
  //ptr = new char[FRecBufSize];
  //return ptr;
  return (char *)AllocMem(FRecBufSize);
}
//---------------------------------------------------------------------------
//Again, TDataSet calls this method to free the record buffer.
//Note: Make sure the value of FRecBufSize does not change before all
//allocated buffers are freed.
void __fastcall TTextDataSet::FreeRecordBuffer(char *&Buffer)
{
  SysFreeMem(Buffer);
}
//---------------------------------------------------------------------------
//This multi-purpose function does 3 jobs.  It retrieves data for either
//the current, the prior, or the next record.  It must return the status
//(TGetResult), and raise an exception if DoCheck is True.
TGetResult __fastcall TTextDataSet::GetRecord(char *Buffer, TGetMode GetMode,
                        bool DoCheck)
{
  TGetResult ret;
  if (FData->Count < 1)
    return grEOF;
  else {
    ret = grOK;
    switch (GetMode)
    {
      case gmNext:
        if (FCurRec >= (RecordCount-1)) ret = grEOF;
        else FCurRec++;
        break;
      case gmPrior:
        if (FCurRec <= 0) ret = grBOF;
        else FCurRec--;
        break;
      case gmCurrent:
        if ((FCurRec < 0) || (FCurRec >= RecordCount))
          ret = grError;
        break;
    }
    if (ret == grOK)
    {
      StrLCopy(Buffer,FData->Strings[FCurRec].c_str(),MaxStrLen);
      ((::PRecInfo)(Buffer+FRecInfoOfs))->BookmarkFlag = bfCurrent;
      ((::PRecInfo)(Buffer+FRecInfoOfs))->Bookmark =
                                        (int)FData->Objects[FCurRec];
    }
    else
        if ((ret == grError) && DoCheck) DatabaseError("No Records",this);
  }
  return ret;
}
//---------------------------------------------------------------------------
//This routine is called to initialize a record buffer.  In this sample,
//we fill the buffer with zero values, but we might have code to initialize
//default values or do other things as well.
void __fastcall TTextDataSet::InternalInitRecord(char *Buffer)
{
  ZeroMemory(Buffer,RecordSize);
}
//---------------------------------------------------------------------------
//Here we copy the data from the record buffer into a field's buffer.
//This function, and SetFieldData, are more complex when supporting
//calculated fields, filters, and other more advanced features.
//See TBDEDataSet for a more complete example.
bool __fastcall TTextDataSet::GetFieldData(TField *Field, void *Buffer)
{
  StrLCopy((char *)Buffer,ActiveBuffer(),Field->Size);
  return (*(char *)Buffer != '\0');
}
//---------------------------------------------------------------------------
bool __fastcall TTextDataSet::GetFieldData(int FieldNo, void *Buffer)
{
  StrLCopy((char *)Buffer,ActiveBuffer(),MaxStrLen);
  return (*(char *)Buffer != '\0');
}
//---------------------------------------------------------------------------
void __fastcall TTextDataSet::SetFieldData(TField *Field, void *Buffer)
{
  StrLCopy(ActiveBuffer(),(char *)Buffer,Field->Size);
  DataEvent(deFieldChange,(int)Field);
}
//---------------------------------------------------------------------------
//              Record Navigation / Editing
//---------------------------------------------------------------------------
//This method is called by TDataSet.First.  Crack behavior is required.
//That is we must position to a special place *before* the first record.
//Otherwise, we will actually end up on the second record after Resync
//is called.
void __fastcall TTextDataSet::InternalFirst()
{
  FCurRec = -1;
}
//---------------------------------------------------------------------------
//Again, we position to the crack *after* the last record here.
void __fastcall TTextDataSet::InternalLast()
{
  FCurRec = FData->Count;
}
//---------------------------------------------------------------------------
//This method is called by TDataSet.Post.  Most implmentations would write
//the changes directly to the associated datasource, but here we simply set
//a flag to write the changes when we close the dateset.
void __fastcall TTextDataSet::InternalPost()
{
  FSaveChanges = true;
  //For inserts, just update the data in the string list
  if (State == dsEdit) FData->Strings[FCurRec] = ActiveBuffer();
  else {
    //If inserting (or appending), increment the bookmark counter and
    //store the data
    FLastBookmark++;
    FData->InsertObject(FCurRec,AnsiString(ActiveBuffer()),(TObject *)FLastBookmark);
  }
}
//---------------------------------------------------------------------------
//This method is similar to InternalPost above, but the operation is always
//an insert or append and takes a pointer to a record buffer as well.
void __fastcall TTextDataSet::InternalAddRecord(void *Buffer, bool Append)
{
  FSaveChanges = true;
  FLastBookmark++;
  if (Append)  InternalLast();
  FData->InsertObject(FCurRec,(char *)Buffer,(TObject *)FLastBookmark);
}
//---------------------------------------------------------------------------
//This method is called by TDataSet.Delete to delete the current record
void __fastcall TTextDataSet::InternalDelete()
{
  FSaveChanges = true;
  FData->Delete(FCurRec);
  if (FCurRec >= FData->Count)
    FCurRec--;
}
//---------------------------------------------------------------------------
/*Optional Methods
  ================

  The following methods are optional.  When provided they will allow the
  DBGrid and other data aware controls to track the current cursor postion
  relative to the number of records in the dataset.  Because we are dealing
  with a small, static data store (a stringlist), these are very easy to
  implement.  However, for many data sources (SQL servers), the concept of
  record numbers and record counts do not really apply */

int __fastcall TTextDataSet::GetRecordCount()
{
  return FData->Count;
}
//---------------------------------------------------------------------------
int __fastcall TTextDataSet::GetRecNo()
{
  UpdateCursorPos();
  if ((FCurRec == -1) && (RecordCount > 0))
    return 1;
  else
    return (FCurRec+1);
}
//---------------------------------------------------------------------------
void __fastcall TTextDataSet::SetRecNo(int Value)
{
  if ((Value >= 0) && (Value < FData->Count))
  {
    FCurRec = Value - 1;
    Resync(TResyncMode());
  }
}
//---------------------------------------------------------------------------

namespace Textdataset
{
  void __fastcall PACKAGE Register()
  {
     TComponentClass classes[1] = {__classid(TTextDataSet)};
     RegisterComponents("Data Access", classes, 0);
  }
}
//---------------------------------------------------------------------------
