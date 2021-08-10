#include "step16.HXX"

// TKIND_DISPATCH: TDrawDoc 1.0 {EB141FA2-8B8A-101B-A23B-CE4E85D07ED2}\409 Draw document class

short TDrawDoc::GetPenSize()     
{
  AUTONAMES0("PenSize")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TDrawDoc::SetPenSize(short val) 
{
  AUTONAMES0("PenSize")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

long TDrawDoc::GetPenColor()     
{
  AUTONAMES0("PenColor")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TDrawDoc::SetPenColor(long val) 
{
  AUTONAMES0("PenColor")
  AUTOARGS0()
  AUTOCALL_PROP_SET(val)
}

void TDrawDoc::AddPoint(short X, short Y) 
{
  AUTONAMES0("AddPoint")
  AUTOARGS2(X, Y)
  AUTOCALL_METHOD_VOID
}

void TDrawDoc::AddLine() 
{
  AUTONAMES0("AddLine")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void TDrawDoc::ClearLine() 
{
  AUTONAMES0("ClearLine")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

void TDrawDoc::GetApplication(TDrawApp& obj) 
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_PROP_REF(obj)
}


// TKIND_DISPATCH: TDrawApp 1.0 {EB141FA3-8B8A-101B-A23B-CE4E85D07ED2}\409 Application class

bool TDrawApp::GetVisible()     
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_CONV(TBool)
}

void TDrawApp::SetVisible(bool val) 
{
  AUTONAMES0("Visible")
  AUTOARGS0()
  AUTOCALL_PROP_SET(TBool(val))
}

void TDrawApp::NewDocument(TDrawDoc& obj) 
{
  AUTONAMES0("NewDocument")
  AUTOARGS0()
  AUTOCALL_METHOD_REF(obj)
}

void TDrawApp::OpenDocument(TDrawDoc& obj, TAutoString Name) 
{
  AUTONAMES0("OpenDocument")
  AUTOARGS1(Name)
  AUTOCALL_METHOD_REF(obj)
}

TAutoString TDrawApp::GetName() 
{
  AUTONAMES0("Name")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

TAutoString TDrawApp::GetFullName() 
{
  AUTONAMES0("FullName")
  AUTOARGS0()
  AUTOCALL_PROP_GET
}

void TDrawApp::GetApplication(TDrawApp& obj) 
{
  AUTONAMES0("Application")
  AUTOARGS0()
  AUTOCALL_PROP_REF(obj)
}

void TDrawApp::Quit() 
{
  AUTONAMES0("Quit")
  AUTOARGS0()
  AUTOCALL_METHOD_VOID
}

