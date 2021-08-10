//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- cntrller.cpp
//----------------------------------------------------------------------------
#include <ocf/automacr.h>
#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

// forward declarations
//
class TDrawAppProxy;

class TDrawDocProxy : public TAutoProxy {
  public:
    TDrawDocProxy() : TAutoProxy(DEFAULT_SYSTEM_LANGID) {}
    void SetPenColor(long color);
    long GetPenColor();
    void SetPenSize(int penSize);
    int  GetPenSize();
    void AddPoint(short x, short y);
    void AddLine();
    void ClearLine();
    void Application(TDrawAppProxy& a);
};

class TDrawAppProxy : public TAutoProxy {
	public:
    TDrawAppProxy() : TAutoProxy(DEFAULT_SYSTEM_LANGID) {}
    void Show(bool visible);
    void NewDocument();
    void Document(TDrawDocProxy& d);
};

long 
TDrawDocProxy::GetPenColor()
{
  AUTOCALL_PROPGET("PenColor");
}

void 
TDrawDocProxy::SetPenColor(long color) 
{
  AUTOCALL_PROPSET("PenColor", color);
}

void 
TDrawDocProxy::SetPenSize(int penSize) 
{
  AUTOCALL_PROPSET("PenSize", penSize);
}

int  
TDrawDocProxy::GetPenSize()            
{
  AUTOCALL_PROPGET("PenSize");
}

void 
TDrawDocProxy::AddPoint(short x, short y)
{
  AUTOCALL_METHOD2V("AddPoint", x, y);
}

void 
TDrawDocProxy::AddLine()
{
  AUTOCALL_METHOD0V("AddLine");
}

void 
TDrawDocProxy::ClearLine()
{
  AUTOCALL_METHOD0V("ClearLine");
}

void 
TDrawDocProxy::Application(TDrawAppProxy& a) 
{
  AUTOCALL_PROPREF("Application", a);
}

void 
TDrawAppProxy::Show(bool visible)      
{
  AUTOCALL_METHOD1V("Show", visible);
}      

void 
TDrawAppProxy::NewDocument()           
{
  AUTOCALL_METHOD0V("NewDocument");
}

void 
TDrawAppProxy::Document(TDrawDocProxy& d)    
{
  AUTOCALL_PROPREF("Document", d);
}

long Colors[] = {
  RGB(0x00, 0x00, 0x00),
  RGB(0xFF, 0x00, 0x00),
  RGB(0x00, 0xFF, 0x00),
  RGB(0x00, 0x00, 0xFF),
  RGB(0xFF, 0xFF, 0x00),
  RGB(0x00, 0xFF, 0xFF),
  RGB(0xFF, 0x00, 0xFF)
};

const int NumColors = sizeof(Colors)/sizeof(Colors[0]);

int
OwlMain(int argc, char *argv[])
{
  TOleAllocator allocator;      // OLE requirement
  TDrawAppProxy app;

  _InitEasyWin();

  try {
    app.Bind("AutoDrawingPad.Application.1");

    cout << "Starting the drawing." << endl;

    // if there's one argument on the command line,
    // don't display the frame window.
    if (argc == 2) {
      app.Show(false);
    }
    else {
      app.Show(true);
      app.NewDocument();
    }

    TDrawDocProxy doc;
    app.Document(doc);

    cout << "Current automated pen size: " << doc.GetPenSize() << endl;
    cout << "Current automated pen color: " << doc.GetPenColor() << endl;

    double startX   = 150;
    double startY   = 150;
    double radius   = 0;
    double theta    = 0;
    int colorIndex  = 0;
    int penSize     = 1;
    double x        = 0;
    double y        = 0;

    doc.AddPoint(startX, startY);
    for (int i=0; radius < 70; i++) {
      if (i % 10 == 0) {
        // use the next pen
        doc.AddLine();
        doc.AddPoint(startX+x, startY-y);
        doc.SetPenColor(Colors[colorIndex++]);
        doc.SetPenSize(penSize++);
        colorIndex %= NumColors;
      }
      radius += 0.2 * theta;
      x = 2 * radius * cos(theta);
      y = 2 * radius * sin(theta);
      doc.AddPoint(startX+x, startY-y);
      theta += 0.2;
    }
    doc.AddLine();

    cout << "Hit a key to quit the program." << endl;
    while (!kbhit()) {
    }

    cout << endl << "Quiting..." << endl;
    PostQuitMessage(0);
  }
  catch (TXBase& x) {
    cout << x.why() << endl;
  }
  return 0;
}

