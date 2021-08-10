//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.9  $
//
// Definition of class TEdit.  This defines the basic behavior of all edit
// controls.
//----------------------------------------------------------------------------
#if !defined(OWL_EDIT_H)
#define OWL_EDIT_H

#if !defined(OWL_STATIC_H)
# include <owl/static.h>
#endif
#include <owl/edit.rh>

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

class _OWLCLASS TValidator;

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

//
// class TEdit
// ~~~~~ ~~~~~
class _OWLCLASS TEdit : public TStatic {
  public:
    TEdit(TWindow*        parent,
          int             id,
          const char far* text,
          int x, int y, int w, int h,
          uint            textLimit = 0,
          bool            multiline = false,
          TModule*        module = 0);

    TEdit(TWindow*   parent,
          int        resourceId,
          uint       textLimit = 0,
          TModule*   module = 0);

   ~TEdit();

    // Accessors
    //
    int     GetNumLines() const;
    int     GetLineLength(int lineNumber) const;
    bool    GetLine(char far* str, int strSize, int lineNumber) const;
    virtual void GetSubText(char far* str, uint startPos, uint endPos) const;
    virtual void GetSelection(uint& startPos, uint& endPos) const;
    virtual uint GetCurrentPosition() const;

    bool    IsModified() const;
    void    ClearModify();

    int     GetLineFromPos(uint charPos) const;
    uint    GetLineIndex(int lineNumber) const;

    uint    Transfer(void* buffer, TTransferDirection direction);

    // Lock and unlock this edit control's buffer. Allows direct access to the
    // text in the edit control.
    //
    char far* LockBuffer(uint newSize = 0);
    void    UnlockBuffer(const char far* buffer, bool updateHandle = false);

    // Operations
    //
    bool    DeleteSubText(uint startPos, uint endPos);
    bool    DeleteLine(int lineNumber);
    bool    DeleteSelection();
    virtual bool SetSelection(uint startPos, uint endPos);

    void    Scroll(int horizontalUnit, int verticalUnit);

    void    Insert(const char far* str);
    virtual int Search(uint startPos, const char far* text,
                       bool caseSensitive=false, bool wholeWord=false,
                       bool up=false);

    void    GetRect(TRect& frmtRect) const;
    void    SetRect(const TRect& frmtRect);
    void    SetRectNP(const TRect& frmtRect);
    void    FormatLines(bool addEOL);
    void    SetTabStops(int numTabs, const int far* tabs);
    void    LimitText(uint);
#if defined(BI_PLAT_WIN32)
    uint    GetLimitText() const;
#endif

    HLOCAL  GetMemHandle() const;
    void    SetMemHandle(HLOCAL localMem);
#if defined(OWL2_COMPAT)
    HLOCAL  GetHandle() const;
    void    SetHandle(HLOCAL localMem);
#endif

    void    SetPasswordChar(uint ch);

    int     GetFirstVisibleLine() const;
    void    SetReadOnly(bool readOnly);
    uint    GetPasswordChar() const;

    EDITWORDBREAKPROC GetWordBreakProc() const;
    void    SetWordBreakProc(EDITWORDBREAKPROC proc);

    // Clipboard operations
    //
    bool    CanUndo() const;
    void    EmptyUndoBuffer();
    void    Undo();
    virtual void Paste();
    void    Copy();
    void    Cut();

    // Validator functions
    //
    bool    IsValid(bool reportErr = false);
    TValidator*  GetValidator();
    void    SetValidator(TValidator* validator);
    void    ValidatorError();
    bool    IsRefocusing() const;

#if defined(BI_PLAT_WIN32)
    // Margin functions
    //
    void    SetLeftMargin(uint16 margin);
    void    SetRightMargin(uint16 margin);
    void    SetMarginUseFontInfo();
    uint32  GetMargins() const;

    // Position and character functions
    //
    uint32  CharFromPos(int16 x, int16 y);
    uint32  PosFromChar(uint charIndex);
#endif

    // Override TStatic virtual member functions
    //
    void Clear();

  protected:
    // Command response functions for edit menu items
    //
    void    CmEditCut();      // CM_EDITCUT
    void    CmEditCopy();     // CM_EDITCOPY
    void    CmEditPaste();    // CM_EDITPASTE
    void    CmEditDelete();   // CM_EDITDELETE
    void    CmEditClear();    // CM_EDITCLEAR
    void    CmEditUndo();     // CM_EDITUNDO

    // Command enabler functions for edit menu items
    //
    void CmSelectEnable(TCommandEnabler& commandHandler);
    void CmPasteEnable(TCommandEnabler& commandHandler);
    void CmCharsEnable(TCommandEnabler& commandHandler);
    void CmModEnable(TCommandEnabler& commandHandler);

    // Child id notification handled at the child
    //
    void    ENErrSpace();  // EN_ERRSPACE

    // Override TWindow virtual member functions
    //
    char far* GetClassName();
    void      SetupWindow();

    void         EvChar(uint key, uint repeatCount, uint flags);
    void         EvKeyDown(uint key, uint repeatCount, uint flags);
    uint         EvGetDlgCode(MSG far*);
    void         EvSetFocus(HWND hWndLostFocus);
    void         EvKillFocus(HWND hWndGetFocus);
    bool         CanClose();

    // Handler for input validation message sent by parent
    //
    void         EvChildInvalid(HWND);

  protected_data:
    // Input validation object
    //
    TValidator*  Validator;

  private:
    // Hidden to prevent accidental copying or assignment
    //
    TEdit(const TEdit&);
    TEdit& operator =(const TEdit&);

    static TEdit* ValidatorReFocus;

  DECLARE_RESPONSE_TABLE(TEdit);
  DECLARE_STREAMABLE(_OWLCLASS, TEdit, 1);
};

//
// edit control notification macros. methods are: void method()
//
// EV_EN_CHANGE(id, method)
// EV_EN_ERRSPACE(id, method)
// EV_EN_HSCROLL(id, method)
// EV_EN_KILLFOCUS(id, method)
// EV_EN_MAXTEXT(id, method)
// EV_EN_SETFOCUS(id, method)
// EV_EN_UPDATE(id, method)
// EV_EN_VSCROLL(id, method)

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline void TEdit::ClearModify()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETMODIFY);
}

#if defined(OWL2_COMPAT)
//
inline HLOCAL TEdit::GetHandle() const
{
  return GetMemHandle();
}

//
inline void TEdit::SetHandle(HLOCAL localMem)
{
  SetMemHandle(localMem);
}
#endif

//
inline void TEdit::SetPasswordChar(uint ch)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETPASSWORDCHAR, ch);
}

//
inline void TEdit::EmptyUndoBuffer()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_EMPTYUNDOBUFFER);
}

//
inline void TEdit::Undo()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(WM_UNDO);
}

//
inline void TEdit::Paste()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(WM_PASTE);
}

//
inline void TEdit::Copy()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(WM_COPY);
}

//
inline void TEdit::Cut()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(WM_CUT);
}

//
// Return the validator associated with this edit control.
//
inline TValidator* TEdit::GetValidator()
{
  return Validator;
}

//
// Return true when this edit control is attempting to regain focus after an
// EvKillFocus with invalid contents
//
inline bool TEdit::IsRefocusing() const
{
  return ValidatorReFocus == this;
}

//
inline void TEdit::CmEditCut()
{
  Cut();
}

//
inline void TEdit::CmEditCopy()
{
  Copy();
}

//
inline void TEdit::CmEditPaste()
{
  Paste();
}

//
inline void TEdit::CmEditDelete()
{
  DeleteSelection();
}

//
inline void TEdit::CmEditClear()
{
  Clear();
}

//
inline void TEdit::CmEditUndo()
{
  Undo();
}

//
// Return the number of lines in the associated edit control
//
// Note: return 1 when the edit control has no text (i.e. it has one line
// with no text in it). Return zero if an error occurs
//
inline int TEdit::GetNumLines() const
{
  PRECONDITION(TWindow::GetHandle());
  return (int)CONST_CAST(TEdit*,this)->SendMessage(EM_GETLINECOUNT);
}

//
inline bool TEdit::IsModified() const
{
  PRECONDITION(TWindow::GetHandle());
  return (bool)CONST_CAST(TEdit*,this)->SendMessage(EM_GETMODIFY);
}

//
// Select the characters in the range "startPos .. endPos"
//
inline bool TEdit::SetSelection(uint startPos, uint endPos)
{
  PRECONDITION(TWindow::GetHandle());
#if defined(BI_PLAT_WIN32)
  return SendMessage(EM_SETSEL, startPos, endPos) != 0;
#else
  return SendMessage(EM_SETSEL, 0, MAKELPARAM(startPos, endPos)) != 0;
#endif
}

//
// Return the starting and ending positions of the selected text
//
inline void TEdit::GetSelection(uint& startPos, uint& endPos) const
{
  PRECONDITION(TWindow::GetHandle());
#if defined(BI_PLAT_WIN32)
  CONST_CAST(TEdit*,this)->SendMessage(EM_GETSEL, TParam1(&startPos), TParam2(&endPos));
#else
  TResult  retValue = CONST_CAST(TEdit*,this)->SendMessage(EM_GETSEL);
  startPos = LoUint16(retValue);
  endPos   = HiUint16(retValue);
#endif
}


//
// Return the current caret position.
//
inline uint TEdit::GetCurrentPosition() const
{
  PRECONDITION(TWindow::GetHandle());
  uint CurPos = 0;
  GetSelection(CurPos, CurPos);
  return CurPos;
}


//
// Return the line number associated with character index "CharPos"
//
// If "CharPos" is greater than the number of characters, the last line is
// returned
// If "CharPos" is -1, the line containing the beginning of the selection (or
// the line containing the caret if no selection) is returned
//
inline int TEdit::GetLineFromPos(uint charPos) const
{
  PRECONDITION(TWindow::GetHandle());
  return (int)CONST_CAST(TEdit*,this)->SendMessage(EM_LINEFROMCHAR, charPos);
}

//
// Return the character index of line number "LineNumber" or -1 if
// "LineNumber" is greater than the number of lines
//
// If "LineNumber" is -1, the line containing the caret is used
//
inline uint TEdit::GetLineIndex(int lineNumber) const
{
  PRECONDITION(TWindow::GetHandle());
  return (int)CONST_CAST(TEdit*,this)->SendMessage(EM_LINEINDEX, lineNumber);
}

//
// Scroll the text by the specified horizontal and vertical amounts
//
inline void TEdit::Scroll(int horizUnit, int vertUnit)
{
  PRECONDITION(TWindow::GetHandle());
#if defined(BI_PLAT_WIN32)
  SendMessage(EM_LINESCROLL, horizUnit, vertUnit);
#else
  SendMessage(EM_LINESCROLL, 0, MAKELONG(vertUnit, horizUnit));
#endif
}

//
// Sets the selection to the "str" (does a "paste" type of action without
// affecting the clipboard)
//
inline void TEdit::Insert(const char far* str)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_REPLACESEL, 0, TParam2(str));
}

//
inline void TEdit::GetRect(TRect& frmtRect) const
{
  PRECONDITION(TWindow::GetHandle());
  CONST_CAST(TEdit*,this)->SendMessage(EM_GETRECT, 0, TParam2((TRect FAR*)&frmtRect));
}

//
inline void TEdit::SetRect(const TRect& frmtRect)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETRECT, 0, TParam2((const TRect FAR*)&frmtRect));
}

//
inline void TEdit::SetRectNP(const TRect& frmtRect)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETRECTNP, 0, TParam2((const TRect FAR*)&frmtRect));
}

//
inline void TEdit::FormatLines(bool addEOL)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_FMTLINES, addEOL);
}

//
inline void TEdit::SetTabStops(int numTabs, const int far* tabs)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETTABSTOPS, numTabs, TParam2(tabs));
}

//
// Limit the amount of new text that can be entered in the edit control.
//
inline void TEdit::LimitText(uint txtLen)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_LIMITTEXT, TParam1(txtLen));
}

//
// Return the memory handle for the edit control's buffer.
//
inline HLOCAL TEdit::GetMemHandle() const
{
  PRECONDITION(TWindow::GetHandle());
  return (HLOCAL)CONST_CAST(TEdit*,this)->SendMessage(EM_GETHANDLE);
}

//
// Sets the memory handle for the edit control's buffer.
//
inline void TEdit::SetMemHandle(HLOCAL localMem)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETHANDLE, TParam1(localMem));
}

//
inline int TEdit::GetFirstVisibleLine() const
{
  PRECONDITION(TWindow::GetHandle());
  return (int)CONST_CAST(TEdit*,this)->SendMessage(EM_GETFIRSTVISIBLELINE);
}

//
inline void TEdit::SetReadOnly(bool readOnly)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETREADONLY, readOnly);
}

//
inline uint TEdit::GetPasswordChar() const
{
  PRECONDITION(TWindow::GetHandle());
  return (uint)CONST_CAST(TEdit*,this)->SendMessage(EM_GETPASSWORDCHAR);
}

//
inline EDITWORDBREAKPROC TEdit::GetWordBreakProc() const
{
  PRECONDITION(TWindow::GetHandle());
  return (EDITWORDBREAKPROC)CONST_CAST(TEdit*,this)->SendMessage(EM_GETWORDBREAKPROC);
}

//
inline void TEdit::SetWordBreakProc(EDITWORDBREAKPROC proc)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETWORDBREAKPROC, 0, TParam2(proc));
}

//
inline bool TEdit::CanUndo() const
{
  PRECONDITION(TWindow::GetHandle());
  return (bool)CONST_CAST(TEdit*,this)->SendMessage(EM_CANUNDO);
}

#if defined(BI_PLAT_WIN32)
//
inline void TEdit::SetLeftMargin(uint16 margin)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETMARGINS, EC_LEFTMARGIN, MkUint32(0, margin));
}

//
inline void TEdit::SetRightMargin(uint16 margin)
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETMARGINS, EC_RIGHTMARGIN, MkUint32(margin, 0));
}

//
inline void TEdit::SetMarginUseFontInfo()
{
  PRECONDITION(TWindow::GetHandle());
  SendMessage(EM_SETMARGINS, EC_USEFONTINFO, 0);
}

//
inline uint32 TEdit::GetMargins() const
{
  PRECONDITION(TWindow::GetHandle());
  return (uint32)CONST_CAST(TEdit*,this)->SendMessage(EM_GETMARGINS);
}

//
inline uint TEdit::GetLimitText() const
{
  PRECONDITION(TWindow::GetHandle());
  return (uint)CONST_CAST(TEdit*,this)->SendMessage(EM_GETLIMITTEXT);
}

//
inline uint32 TEdit::CharFromPos(int16 x, int16 y) {
  PRECONDITION(TWindow::GetHandle());
  // y is the high-order word of lParam
  // x is the low-order word of lParam
  //
  return (uint32)SendMessage(EM_CHARFROMPOS, 0, MkUint32(y, x));
}

//
inline uint32 TEdit::PosFromChar(uint charIndex) {
  PRECONDITION(TWindow::GetHandle());
  return (uint32)SendMessage(EM_POSFROMCHAR, charIndex);
}
#endif  // BI_PLAT_WIN32

#endif  // OWL_EDIT_H
