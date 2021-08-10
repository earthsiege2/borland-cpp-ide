//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1993, 1995 by Borland International, All Rights Reserved
//
//   Definition of class TDumpView
//----------------------------------------------------------------------------
#if !defined(OWL_DUMPVIEW_H)
#define OWL_DUMPVIEW_H

#if !defined(OWL_DOCVIEW_H)
# include <owl/docview.h>
#endif
#if !defined(OWL_LISTBOXW_H)
# include <owl/listbox.h>
#endif

struct TDumpData;

class _DOCVIEWCLASS TDumpView : public TListBox, public TView {
  public:
    TDumpView(TDocument& doc, TWindow* parent = 0);
   ~TDumpView();
    static const char far* StaticName() {return "Dump View";}

    // Overridden virtuals from TView
    //
    const char far*   GetViewName(){return StaticName();}
    TWindow* GetWindow()  {return (TWindow*)this;}
    bool     SetDocTitle(const char far* docname, int index)
                          {return TListBox::SetDocTitle(docname, index);}

    // Overridden virtuals from TWindow
    //
    bool     Create();
    bool     CanClose()   {return TListBox::CanClose() && Doc->CanClose();}

    int      MaxWidth;    // maximum horizontal extent

  protected:
    void Init();
    bool LoadData(int top, int sel);
    void FormatLine(int index, TDumpData* data);
    bool NewEditLine(int line, int byte);
    void EndEditLine();
    void KillChanges();

    long Origin;
    long FileSize;
    int  UpdateMode; // 0=NotEditing, 1=HighNibble, 2=LowNibble, -1=Flushing
    int  CharWidth;
    int  CharHeight;
    int  EditByte;
    int  EditLine;
    TDumpData* Changes;

  private:
    // Message response functions
    //
    bool VnCommit(bool force);
    bool VnRevert(bool clear);
    bool VnIsWindow(HWND hWnd) {return HWindow == hWnd;}
    bool VnIsDirty();
    bool VnDocClosed(int omode);
    void CmEditUndo();
    void CmEditItem();
    void EvPaint();
    void EvKeyDown(uint key, uint repeatCount, uint flags);
    void EvLButtonDown(uint modKeys, TPoint& point);
    void EvLButtonDblClk(uint modKeys, TPoint& point);
    void CmSelChange() {} // to prevent interpreting as unprocessed accelerator

  DECLARE_RESPONSE_TABLE(TDumpView);
  DECLARE_STREAMABLE(,TDumpView,1);
};

#endif  // OWL_DUMPVIEW_H
