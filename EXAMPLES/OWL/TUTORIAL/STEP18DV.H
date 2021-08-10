//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1994 by Borland International
//   Tutorial application -- step18dv.h
//   Automation Container Server example
//----------------------------------------------------------------------------
#if !defined(STEP18DV_H)
#define STEP18DV_H

#if !defined(OCF_OCLINK_H)
# include <ocf/oclink.h>
#endif

#if !defined(OCF_OCCTRL_H)
# include <ocf/occtrl.h>
#endif

const int Margin  = 15;   // Margins used for copying selection

class _ICLASS TOcPart;
class _USERCLASS TDrawView;


typedef TArray<TPoint> TPoints;
typedef TArrayIterator<TPoint> TPointsIterator;

class TLine : public TPoints {
  public:
    // Constructor to allow construction from a color and a pen size.
    // Also serves as default constructor.
    TLine(const TColor& color = TColor(0), int penSize = 1) :
      TPoints(10, 0, 10), PenSize(penSize), Color(color), Bound(0, 0, 0, 0),
      Selected(false) {}

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

    // bound related functions
    void Invalidate(TDrawView& view);
    TPoint& GetPos()
    {
      return Bound.TopLeft();
    }

    TSize& GetSize()
    {
      return Bound.Size();
    }

    TRect& GetBound()
    {
      return Bound;
    }

    void UpdateBound();
    void UpdatePosition(TPoint&);
    void UpdateSize(TSize& newSize);

    // Selection
    bool IsSelected()
    {
      return Selected;
    }

    void Select(bool select = true)
    {
      Selected = select;
    }

    TUIHandle::TWhere Where;

  protected:
    int PenSize;
    TColor Color;
    TRect Bound;          // the enclosing rectangle for line
    bool Selected;
};

typedef TArray<TLine> TLines;
typedef TArrayIterator<TLine> TLinesIterator;

class _USERCLASS TMyOcxEvent : public TOcControlEvent {
  public:

    void       InitEventDispatch();

    long       SpinPositive();  // for spindial control test

  DECLARE_AUTOCLASS (TMyOcxEvent)
    AUTOFUNC0 (SpinPositive,  SpinPositive,  long,)
};


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
                                         
    // OCServer changes begin
    TDrawDocument(TDocument* parent = 0);
    // OCServer changes end

   ~TDrawDocument();

    // implement virtual methods of TDocument
    bool   Open(int mode, const char far* path=0);
    bool OpenSelection(int mode, const char far* path, TPoint far* where);
    bool   Close();
    bool   Commit(bool force = false);
    bool   CommitSelection(TOleWindow& oleWin, void* userData);

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

    TLine* GetLine(TString& moniker);
    int    AddLine(TLine& line);
    void   DeleteLine(uint index);
    void   ModifyLine(TLine& line, uint index);
    void   Clear();
    void   Undo();
    TSize& GetDocSize(){return DocSize;}

  protected:
    TLines* Lines;
    TLine*  UndoLine;
    int     UndoState;
    int     UndoIndex;
    string  FileInfo;
    TSize   DocSize;      // Document size in log unit

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


//=====================  TDrawLinkView  =======================================

class _ICLASS   TOcControl;
class _ICLASS   IDispatch;

class _USERCLASS TDrawLinkView : public TOleLinkView {
  public:
    TDrawLinkView(TDocument& doc, TOcLinkView& view);
   ~TDrawLinkView();

    bool VnModify(uint index);
    bool VnDelete(uint index);

    static const char far* StaticName()
    {
      return "Draw Link View";
    }

    const char far* GetViewName()
    {
      return StaticName();
    }

  protected:
    TDrawDocument* DrawDoc;

  DECLARE_RESPONSE_TABLE(TDrawLinkView);
};

class _USERCLASS TDrawView : public TOleView {
  public:
    TDrawView(TDrawDocument& doc, TWindow* parent = 0);
   ~TDrawView();

    static const char far* StaticName()
    {
      return "Draw View";
    }

    const char far* GetViewName()
    {
      return StaticName();
    }
    static void CleanUp(void* userData);

    void SetLineSelection(TLine* Line);
    void SetLineSelection(int index);
    TLine* HitTest(TPoint& pt);
    bool Select(uint modKeys, TPoint& point);
    void SetupWindow();
    TLine* GetSelected() {return Selected;}
    void SetStatusText (char far* text);

    bool EvOcViewSetLink(TOcLinkView& view);

    enum DRAWTOOL {
      DrawSelect = 0,
      DrawPen,
    };
    IDispatch *pIFont;
    long       backRGB;
    long       designMode;

  protected:
    // Message response functions
    void EvSize(uint sizeType, TSize& size);
    void EvLButtonDown(uint, TPoint&);
    void EvMouseMove(uint, TPoint&);
    void EvLButtonUp(uint, TPoint&);
    bool ShowCursor(HWND, uint, uint);
    bool EvOcViewPartSize(TOcPartSize far& ps);
    bool EvOcViewShowTools(TOcToolBarInfo far& tbi);
    bool EvOcViewGetItemName(TOcItemName& item);
    bool EvOcViewClipData(TOcFormatData far& format);

    bool EvOcAmbientGetBackColor(long* rgb);
    bool EvOcAmbientGetFont(IDispatch** font);
    bool EvOcAmbientGetUserMode(bool* mode);
    bool EvOcAmbientGetShowGrabHandles(bool* show);
    bool EvOcAmbientGetShowHatching(bool* show);
    bool EvOcAmbientGetDisplayAsDefault(bool* disp);
    bool EvOcAmbientGetTextAlign(short* align);

    bool EvOcCtrlClick(TCtrlEvent* pev);
    bool EvOcCtrlDblClick(TCtrlEvent* pev);
    bool EvOcCtrlCustomEvent(TCtrlCustomEvent* pev);

    // painting
    void Paint(TDC&, bool, TRect&);
    bool PaintSelection(TDC&, bool, TRect&, void* userData = 0);
    bool PaintLink(TDC& dc, bool erase, TRect& rect, TString& moniker);

    void CmPenSize();
    void CmPenColor();
    void CmClear();
    void CmUndo();
    void CmEditCut();
    void CmEditCopy();
    void CeEditCut(TCommandEnabler& ce);
    void CeEditCopy(TCommandEnabler& ce);

    void CePen(TCommandEnabler&);
    void CeSelect(TCommandEnabler&);
    void CeOrgSize(TCommandEnabler&);
    void CeDoubleSize(TCommandEnabler&);
    void CeHalfSize(TCommandEnabler&);
    void CeControlProps(TCommandEnabler&);
    void CeContainerMode(TCommandEnabler& ce);
    void CmControlProps();
    void CmControlFont ();
    void CmControlCaption ();
    void CmNewControl();
    void CmContainerMode ();
    void CmRegisterControl ();
    void CmUnregisterControl ();
    void CmPen();
    void CmSelect();
    void CmOrgSize();
    void CmDoubleSize();
    void CmHalfSize();

    // Document notifications
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnAppend(uint index);
    bool VnDelete(uint index);
    bool VnModify(uint index);

    TDrawDocument*    DrawDoc;  // same as Doc member, but cast to derived class
    TPen*             Pen;
    TLine*            Line;     // To hold a single line sent or received from document
    TLine*            Selected; // To hold a single selected line
    DRAWTOOL          Tool;     // current tool selected
    TControlBar*      ToolBar;

    // OC client changes end

  private:
    void InsertObject(TOcInitInfo &init);
    void AdjustScroller(); // scrolling support

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
    LRESULT EvOcEvent(WPARAM wParam, LPARAM lParam);
    uint32  EvOcViewPaint(void far*);

  DECLARE_RESPONSE_TABLE(TDrawListView);
};

const int vnDrawAppend     = vnCustomBase+0;
const int vnDrawDelete     = vnCustomBase+1;
const int vnDrawModify     = vnCustomBase+2;

NOTIFY_SIG(vnDrawAppend, uint)
NOTIFY_SIG(vnDrawDelete, uint)
NOTIFY_SIG(vnDrawModify, uint)

#define EV_VN_DRAWAPPEND  VN_DEFINE(vnDrawAppend,  VnAppend,   int)
#define EV_VN_DRAWDELETE  VN_DEFINE(vnDrawDelete,  VnDelete,   int)
#define EV_VN_DRAWMODIFY  VN_DEFINE(vnDrawModify,  VnModify,   int)

#endif // __STEP18DV_H
