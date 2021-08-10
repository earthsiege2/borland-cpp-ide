//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1993 by Borland International
//   Provides TModuleDoc class to dynamically load new document/view classes
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\docmanag.h>
#include "dvloader.rc"

class TModuleDocument : public TDocument {
  public:
    TModuleDocument(TDocument* parent=0) : TDocument(parent), Module(0) {}
   ~TModuleDocument() { Close(); }
    BOOL   Open(int mode, const char far* path=0);
    BOOL   Close();
    BOOL   IsOpen() { return Module != 0; }
  protected:
    TModule* Module;

  DECLARE_STREAMABLE(, TModuleDocument,1);
};

class TModuleView : public TView {
  public:
    TModuleView(TDocument& doc, TWindow* parent = 0) : TView(doc) {
      doc.GetDocManager().PostDocError(doc, IDS_DVLOADED);
      NotOK();
    }
    static LPCSTR StaticName() {return "Module View";}
    LPCSTR GetViewName() {return StaticName();}
};

BOOL TModuleDocument::Open(int /*mode*/, const char far* path)
{
  if (IsOpen())
    return TRUE;
  if (path)
    SetDocPath(path);
  if (!GetDocPath())
    return FALSE;
  try {
    Module = new TModule(GetDocPath());
  }
  catch(TXOwl&) {
    return FALSE;
  }
  TDocTemplate** tplhead;
  TDocTemplate** PASCAL(*entry)(int version);
  (FARPROC)entry = Module->GetProcAddress("GetDocTemplateHead");
  if (!entry || (tplhead = entry(OWLVersion)) == 0) {
    delete Module;
    Module = 0;
    return FALSE;
  }
  TDocTemplate* tpl = *tplhead;
  for (; tpl; tpl = GetDocManager().GetNextTemplate(tpl)) 
    tpl->Clone(Module)->SetDocManager(&GetDocManager());
  return TRUE;
}

BOOL TModuleDocument::Close()
{
  if (!IsOpen())
    return TRUE;
  TDocTemplate* tpl;
  TDocTemplate* next;
  for (tpl = GetDocManager().GetNextTemplate(0); tpl; tpl = next) {
    next = GetDocManager().GetNextTemplate(tpl);
    if (*tpl->GetModule() == *Module) {
      // must remove any remaining associated documents before freeing module
      TDocument* doc;
      TDocument* next;
      for (doc = GetDocManager().DocList.Next(0); doc; doc = next) {
        next = GetDocManager().DocList.Next(doc);
        if (doc->GetTemplate() == tpl){
          doc->Close();
          delete doc;
        }
      }
      GetDocManager().DeleteTemplate(*tpl);  // RefCnt should go to 0 now
    }
  }
  delete Module;
  Module = 0;
  return TRUE;  
}

IMPLEMENT_STREAMABLE1(TModuleDocument, TDocument);

void*
TModuleDocument::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TDocument*)GetObject(), is);
  is >> GetObject()->Module;
  return GetObject();
}

void
TModuleDocument::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TDocument*)GetObject(), os);
  os << GetObject()->Module;
}

DEFINE_DOC_TEMPLATE_CLASS(TModuleDocument, TModuleView, LoadTemplate);
LoadTemplate loadTpl("DocView Components (*.DVC)","*.dvc",0,0,
                     dtAutoOpen|dtUpdateDir|dtReadOnly|dtHideReadOnly);


