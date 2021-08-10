//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- step16dv.h
//   Automation Server example
//----------------------------------------------------------------------------
#if !defined(STEP16DV_H)
#define STEP16DV_H

typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TLine : public TPoints {
  public:
    // Constructor to allow construction from a color and a pen size.
    // Also serves as default constructor.
    TLine(const TColor& color = TColor(0), int penSize = 1) :
      TPoints(10, 0, 10), PenSize(penSize), Color(color){}

    // Functions to modify and query pen attributes.
    int QueryPenSize() const
    {
      return PenSize;
    }

    const TColor& QueryColor() const
    {
      return Color;
    }

    void SetPen(TColor& newColor, int penSize = 0);
    void SetPen(int penSize);
    friend bool GetPenSize(TWindow* parent, TLine& line);
    friend bool GetPenColor(TWindow* parent, TLine& line);

    // TLine draws itself.  Returns true if everything went OK.
    virtual bool Draw(TDC&) const;
    void DrawSelection(TDC& dc);

    // The == operator must be defined for the container class, even if unused
    bool operator ==(const TLine& other) const
    {
      return &other == this;
    }

    friend ostream& operator <<(ostream& os, const TLine& line);
    friend istream& operator >>(istream& is, TLine& line);


  protected:
    int PenSize;
    TColor Color;
};

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class _USERCLASS TDrawDocument : public TOleDocument {
  public:
    enum {
      PrevProperty = TOleDocument::NextProperty-1,
      LineCount,
      Description,
      NextProperty,
    };

    enum {
      UndoNone,
      UndoDelete,
      UndoAppend,
      UndoModify
    };

    TDrawDocument(TDocument* parent = 0);
   ~TDrawDocument();

    // implement virtual methods of TDocument
    bool   Open(int mode, const char far* path=0);
    bool   Close();
    bool   Commit(bool force = false);

    int         FindProperty(const char far* name);  // return index
    int         PropertyFlags(int index);
    const char* PropertyName(int index);
    int         PropertyCount()
    {
      return NextProperty - 1;
    }

    int         GetProperty(int index, void far* dest, int textlen=0);

    // data access functions
    TLine* GetLine(uint index);
    TLines* GetLines()
    {
      return Lines;
    }

    int    AddLine(TLine& line);
    void   DeleteLine(uint index);
    void   ModifyLine(TLine& line, uint index);
    void   Clear();
    void   Undo();

  protected:
    TLines* Lines;
    TLine*  UndoLine;
    int     UndoState;
    int     UndoIndex;
    string  FileInfo;

  private:
    // To not interfere with normal mouse operations, the automation
    // entry points have their own lines with their own attributes.
    long GetPenColor()
    {
      return AutoPenColor;
    }

    void SetPenColor(long color)
    {
      AutoPenColor = color;
      AutoLine->SetPen(TColor(color));
    }

    short GetPenSize()
    {
      return AutoPenSize;
    }

    void SetPenSize(short penSize)
    {
      AutoPenSize = penSize;
      AutoLine->SetPen(penSize);
    }

    void AddPoint(short x, short y)
    {
      AutoLine->Add(TPoint(x,y));
    }

    void AddLine()
    {
      AddLine(*AutoLine);
      ClearLine();
    }

    void ClearLine()
    {
      delete AutoLine;
      AutoLine = new TLine(AutoPenColor, AutoPenSize);
    }

    TLine*  AutoLine;
    long    AutoPenColor;
    short   AutoPenSize;

  DECLARE_AUTOCLASS(TDrawDocument)
    AUTOPROP(PenSize,    GetPenSize,  SetPenSize,  short, )
    AUTOPROP(PenColor,   GetPenColor, SetPenColor, long, )
    AUTOFUNC2V(AddPoint, AddPoint, short, short, )
    AUTOFUNC0V(AddLine,  AddLine, )
    AUTOFUNC0V(ClearLine,ClearLine, )
};

class _USERCLASS TDrawView : public TOleView {
  public:
    TDrawView(TDrawDocument& doc, TWindow* parent = 0);
   ~TDrawView()
    {
      delete Line;
    }

    static const char far* StaticName()
    {
      return "Draw View";
    }

    const char far* GetViewName()
    {
      return StaticName();
    }

  protected:
    // Message response functions
    void EvLButtonDown(uint, TPoint&);
    void EvMouseMove(uint, TPoint&);
    void EvLButtonUp(uint, TPoint&);

    void Paint(TDC&, bool, TRect&);
    void CmPenSize();
    void CmPenColor();
    void CmClear();
    void CmUndo();

    void CmEditCut();
    void CmEditCopy();
    bool EvOcViewPartSize(TOcPartSize far& ps);
    bool EvOcViewShowTools(TOcToolBarInfo far& tbi);

    // Document notifications
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnAppend(uint index);
    bool VnDelete(uint index);
    bool VnModify(uint index);

    TDrawDocument* DrawDoc;  // same as Doc member, but cast to derived class
    TPen*          Pen;
    TLine*         Line;     // To hold a single line sent or received from document
    TControlBar*   ToolBar;

  DECLARE_RESPONSE_TABLE(TDrawView);
};


class _USERCLASS TDrawListView : public TListBox, public TView {
  public:
    TDrawListView(TDrawDocument& doc, TWindow* parent = 0);
   ~TDrawListView(){}
    static const char far* StaticName()
    {
      return "DrawList View";
    }

    int CurIndex;

    // Overridden virtuals from TView
    //
    const char far* GetViewName()
    {
      return StaticName();
    }

    TWindow* GetWindow()
    {
      return (TWindow*)this;
    }

    bool SetDocTitle(const char far* docname, int index)
    {
      return TListBox::SetDocTitle(docname, index);
    }

    // Overridden virtuals from TWindow
    //
    bool CanClose()
    {
      return TListBox::CanClose() && Doc->CanClose();
    }

    bool Create();

  protected:
    TDrawDocument* DrawDoc;  // same as Doc member, but cast to derived class
    void LoadData();
    void FormatData(const TLine* line, uint index);

    // Message response functions
    void CmPenSize();
    void CmPenColor();
    void CmClear();
    void CmUndo();
    void CmDelete();

    // Document notifications
    bool VnIsWindow(HWND hWnd)
    {
      return HWindow == hWnd;
    }

    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnAppend(uint index);
    bool VnDelete(uint index);
    bool VnModify(uint index);

    // OC server changes
    LRESULT   EvOcEvent(WPARAM wParam, LPARAM lParam);
    uint32    EvOcViewPaint(void far*);

    DECLARE_RESPONSE_TABLE(TDrawListView);
};

const int vnDrawAppend = vnCustomBase+0;
const int vnDrawDelete = vnCustomBase+1;
const int vnDrawModify = vnCustomBase+2;

NOTIFY_SIG(vnDrawAppend, uint)
NOTIFY_SIG(vnDrawDelete, uint)
NOTIFY_SIG(vnDrawModify, uint)

#define EV_VN_DRAWAPPEND  VN_DEFINE(vnDrawAppend,  VnAppend,  int)
#define EV_VN_DRAWDELETE  VN_DEFINE(vnDrawDelete,  VnDelete,  int)
#define EV_VN_DRAWMODIFY  VN_DEFINE(vnDrawModify,  VnModify,  int)


#endif // __STEP16DV_H
