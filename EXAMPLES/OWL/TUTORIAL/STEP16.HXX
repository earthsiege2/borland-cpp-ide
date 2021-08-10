// Type Library: step16.olb  Drawing Pad Automated Server
// DrawPad.Application.16 1.0 {EB141FA1-8B8A-101B-A23B-CE4E85D07ED2}\409

#include <ocf/automacr.h>

class TDrawDoc;
class TDrawApp;

// TKIND_DISPATCH: TDrawDoc 1.0 {EB141FA2-8B8A-101B-A23B-CE4E85D07ED2}\409 Draw document class

class TDrawDoc : public TAutoProxy {
  public:
    TDrawDoc() : TAutoProxy(0x409) {}
    // Current pen size
    short GetPenSize();     // [id(1), prop r/w]
    void SetPenSize(short); // [id(1), prop r/w]
    // Current pen color
    long GetPenColor();     // [id(2), prop r/w]
    void SetPenColor(long); // [id(2), prop r/w]
    // Add a point to the current line
    void AddPoint(short X, short Y); // [id(3), method]
    // Add current line into drawing
    void AddLine(); // [id(4), method]
    // Erases current line
    void ClearLine(); // [id(5), method]
    // Application object
    void GetApplication(TDrawApp&); // [id(6), propget]
};

// TKIND_DISPATCH: TDrawApp 1.0 {EB141FA3-8B8A-101B-A23B-CE4E85D07ED2}\409 Application class

class TDrawApp : public TAutoProxy {
  public:
    TDrawApp() : TAutoProxy(0x409) {}
    // Main window shown
    bool GetVisible();     // [id(1), prop r/w]
    void SetVisible(bool); // [id(1), prop r/w]
    // Create new document
    void NewDocument(TDrawDoc&); // [id(2), method]
    // Open existing document
    void OpenDocument(TDrawDoc&, TAutoString Name); // [id(3), method]
    // Application name
    TAutoString GetName(); // [id(4), propget]
    // Complete path to application
    TAutoString GetFullName(); // [id(5), propget]
    // Application object
    void GetApplication(TDrawApp&); // [id(6), propget]
    // Shutdown application
    void Quit(); // [id(7), method]
};
