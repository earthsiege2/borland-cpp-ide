//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1994 by Borland International, All Rights Reserved
//
//   Implementation of class TDocTemplate
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/owlpch.h>
#include <owl/owldefs.h>
#include <owl/doctpl.h>

//#define TemplatesSeized ((TDocTemplate*)1)  // template list taken by doc mgr

#if !defined(SECTION) || SECTION == 1

TDocTemplate::TDocTemplate(TRegList& regList, TModule*& module,
                           TDocTemplate*& rptpl)
:
  TRegLink(regList, (TRegLink*&)rptpl),
  Directory(0),
  ModulePtr(&module)
{
  RefCnt = module ? 1 : 0x8001;  // static if contructed before Module
  Flags = atol((*RegList)["docflags"]);
}

void TDocTemplate::SetFlag(long flag)
{
  Flags = GetFlags() | flag;
}

void TDocTemplate::ClearFlag(long flag)
{
  Flags = GetFlags() & ~flag;
}

const char far* TDocTemplate::GetFileFilter() const
{
  return (*RegList)["docfilter"];
}

const char far* TDocTemplate::GetDescription() const
{
  return (*RegList)["description"];
}

const char far* TDocTemplate::GetDefaultExt() const
{
  return (*RegList)["extension"];
}

const char far* TDocTemplate::GetDirectory() const
{
  if (Directory)
    return Directory;
  return (*RegList)["directory"];
}

void TDocTemplate::SetDirectory(const char far* txt)
{
  delete [] Directory;
  Directory = 0;
  if (txt)
    Directory = strnewdup(txt);
}

void TDocTemplate::SetDirectory(const char far* txt, int len)
{
  delete [] Directory;
  Directory = 0;
  if (txt && len > 0) {
    Directory = strnewdup(txt, len);
    Directory[len] = 0;
  }
}

//
// Called only when RefCnt goes to 0
//
TDocTemplate::~TDocTemplate()
{
  if (GetFlags() & dtDynRegInfo) {
    delete RegList;
    RegList = 0;
  }
  delete [] Directory;
}

//----------------------------------------------------------------------------
// Backward compatibility with old style doc templates
//
// The following three function vectors get reset by TDocManager constructor
//
static bool       SelectSaveX(TDocTemplate*, TDocument&) {return false;}
static TView*     InitViewX(TView*) {return 0;}
static TDocument* InitDocX(TDocTemplate&, TDocument*, const char far*, long)
                                    {return 0;}

bool       (*TDocTemplate::SelectSave_)(TDocTemplate*,TDocument&) = SelectSaveX;
TView*     (*TDocTemplate::InitView_)(TView*) = InitViewX;
TDocument* (*TDocTemplate::InitDoc_)(TDocTemplate&, TDocument*,
                                     const char far*, long) = InitDocX;

//
// private class for backward compatibility
//
class TRegListOldDocTemplate : public TRegList {
  public:
    TRegListOldDocTemplate(const char* desc, const char* filt,
                           const char* dir,  const char* ext, long flags);
    TRegItem List[6];  // 4 strings, flags, terminator
    char FlagBuf[12];  // for string representation of doc template flags
};

TRegListOldDocTemplate::TRegListOldDocTemplate(const char* desc,
                                               const char* filt,
                                               const char* dir,
                                               const char* ext,
                                               long        flags)
:
  TRegList(List)
{
  wsprintf(FlagBuf,"0x%lX",flags);
  List[0].Key = "description";
  List[0].Value = desc;
  List[1].Key = "docfilter";
  List[1].Value = filt;
  List[2].Key = "directory";
  List[2].Value = dir;
  List[3].Key = "extension";
  List[3].Value = ext;
  List[4].Key = "docflags";
  List[4].Value = FlagBuf;
  List[5].Key = 0;
}

TDocTemplate::TDocTemplate(const char* desc, const char* filt,
                           const char* dir, const char* ext,
                           long flags, TModule*& module,
                           TDocTemplate*& rphead)
:
  TRegLink(),
  ModulePtr(&module),
  Flags(flags | dtDynRegInfo)
{
  AddLink((TRegLink*&)rphead, *this);
  RefCnt = module ? 1 : 0x8001;  // static if contructed before Module
//  NextTemplate = 0;
  RegList = new TRegListOldDocTemplate(desc, filt, dir, ext, flags);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_ABSTRACT_STREAMABLE(TDocTemplate);

void*
TDocTemplate::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TDocTemplate* o = GetObject();
  bool wasStatic = o->IsStatic();  // test in case dummy template passed
  is >> o->RefCnt;  // need to set back to 1 if doc attach increments!!?
  is >> o->Flags;
  if (o->IsStatic()) {
    delete [] o->Directory;
  }
  o->Directory   = is.freadString();
  if (o->IsStatic() && !wasStatic) {  // dummy template passed as sink
    delete [] o->Directory;
  }
  return o;
  //!JD need to link up reg info table!!
}

void
TDocTemplate::Streamer::Write(opstream& os) const
{
  TDocTemplate* o = GetObject();
  os << o->RefCnt;
  os << o->GetFlags();
  os.fwriteString(o->Directory);
}

#endif
