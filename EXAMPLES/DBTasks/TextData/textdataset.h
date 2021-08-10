//---------------------------------------------------------------------------
#ifndef TextDataSetH
#define TextDataSetH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Controls.hpp>
#include <Classes.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <dbtables.hpp>
//---------------------------------------------------------------------------

const int MaxStrLen = 240;
AnsiString tmp;

typedef struct
{
  int Bookmark;
  TBookmarkFlag BookmarkFlag;
} TRecInfo, *PRecInfo;


class PACKAGE TTextDataSet : public TDataSet
{
private:
  TStringList *FData;
  int FRecBufSize;
  int FRecInfoOfs;
  int FCurRec;
  AnsiString FFileName;
  int FLastBookmark;
  bool FSaveChanges;
  bool before;
protected:
  virtual void __fastcall BeforeDestruction();
  virtual char * __fastcall AllocRecordBuffer();
  virtual void __fastcall FreeRecordBuffer(char *&Buffer);
  virtual void __fastcall GetBookmarkData(char *Buffer, void *Data);
  virtual TBookmarkFlag __fastcall GetBookmarkFlag(char *Buffer);
  virtual TGetResult __fastcall GetRecord(char *Buffer, TGetMode GetMode, bool DoCheck);
  virtual Word __fastcall GetRecordSize();
  virtual void __fastcall InternalAddRecord(void *Buffer, bool Append);
  virtual void __fastcall InternalClose();
  virtual void __fastcall InternalDelete();
  virtual void __fastcall InternalFirst();
  virtual void __fastcall InternalGotoBookmark(void *Bookmark);
  virtual void __fastcall InternalHandleException();
  virtual void __fastcall InternalInitFieldDefs();
  virtual void __fastcall InternalInitRecord(char *Buffer);
  virtual void __fastcall InternalLast();
  virtual void __fastcall InternalOpen();
  virtual void __fastcall InternalPost();
  virtual void __fastcall InternalSetToRecord(char *Buffer);
  virtual bool __fastcall IsCursorOpen();
  virtual void __fastcall SetBookmarkFlag(char *Buffer, TBookmarkFlag Value);
  virtual void __fastcall SetBookmarkData(char *Buffer, void *Data);
  virtual void __fastcall SetFieldData(TField *Field, void *Buffer);
protected:
    //Additional overrides (optional)
  virtual int __fastcall GetRecordCount();
  virtual int __fastcall GetRecNo();
  virtual void __fastcall SetRecNo(int Value);
public:
  __fastcall TTextDataSet(TComponent* Owner);
  virtual bool __fastcall GetFieldData(Db::TField *Field, void *Buffer);
  virtual bool __fastcall GetFieldData(int FieldNo, void *Buffer);
__published:
  __property AnsiString FileName = {read=FFileName, write=FFileName};
  __property Active;
};
//---------------------------------------------------------------------------
#endif
