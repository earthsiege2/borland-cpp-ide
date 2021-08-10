//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\edit.h
//   Definition of class TEdit.  This defines the basic behavior
//   of all edit controls.
//----------------------------------------------------------------------------
#if !defined(__OWL_EDIT_H)
#define __OWL_EDIT_H

#if !defined(__OWL_STATIC_H)
  #include <owl\static.h>
#endif
#include <owl\edit.rh>

class _OWLCLASS TValidator;

//
//  class TEdit
//  ----- -----
//
class _OWLCLASS TEdit : public TStatic {
  public:
    TEdit(TWindow*        parent,
          int             id,
          const char far* text,
          int x, int y, int w, int h,
          UINT            textLen = 0,
          BOOL            multiline = FALSE,
          TModule*        module = 0);

    TEdit(TWindow*   parent,
          int        resourceId,
          UINT       textLen = 0,
          TModule*   module = 0);

   ~TEdit();

    //
    // Accessing
    //
    int     GetNumLines() const;
    int     GetLineLength(int lineNumber) const;
    BOOL    GetLine(char far* str, int strSize, int lineNumber) const;
    void    GetSubText(char far* str, UINT startPos, UINT endPos) const;
    void    GetSelection(UINT& startPos, UINT& endPos) const;

    BOOL    IsModified() const;
    void    ClearModify() {HandleMessage(EM_SETMODIFY);}

    int     GetLineFromPos(UINT charPos) const;
    UINT    GetLineIndex(int lineNumber) const;

    UINT    Transfer(void* buffer, TTransferDirection direction);

    //
    // Lock and unlock this edit control's buffer. Allows direct access to the
    // text in the edit control.
    //
    char far* LockBuffer(UINT newSize = 0);
    void    UnlockBuffer(const char far* buffer, BOOL updateHandle = FALSE);

    //
    // operations
    //
    BOOL    DeleteSubText(UINT startPos, UINT endPos);
    BOOL    DeleteLine(int lineNumber);
    BOOL    DeleteSelection();
    BOOL    SetSelection(UINT startPos, UINT endPos);

    void    Scroll(int horizontalUnit, int verticalUnit);
    void    Insert(const char far* str);
    int     Search(UINT startPos, const char far* text,
                   BOOL caseSensitive=FALSE, BOOL wholeWord=FALSE,
                   BOOL up=FALSE);

    void    GetRect(TRect& frmtRect) const;
    void    SetRect(const TRect& frmtRect);
    void    SetRectNP(const TRect& frmtRect);
    void    FormatLines(BOOL addEOL);
    void    SetTabStops(int numTabs, const int far* tabs);

    HLOCAL  GetHandle() const;
    void    SetHandle(HLOCAL localMem);

    void    SetPasswordChar(UINT ch) {HandleMessage(EM_SETPASSWORDCHAR, ch);}

    int     GetFirstVisibleLine() const;
    void    SetReadOnly(BOOL readOnly);
    UINT    GetPasswordChar() const;

    EDITWORDBREAKPROC GetWordBreakProc() const;
    void    SetWordBreakProc(EDITWORDBREAKPROC proc);

    //
    // clipboard operations
    //
    BOOL    CanUndo() const;
    void    EmptyUndoBuffer() {HandleMessage(EM_EMPTYUNDOBUFFER);}
    void    Undo() {HandleMessage(WM_UNDO);}
    void    Paste() {HandleMessage(WM_PASTE);}
    void    Copy() {HandleMessage(WM_COPY);}
    void    Cut() {HandleMessage(WM_CUT);}
    
    BOOL    IsValid(BOOL reportErr = FALSE);
    void    SetValidator(TValidator* validator);
    void    ValidatorError();

    //
    // Override TStatic virtual member functions
    //
    void Clear();

  protected:
    //
    // command response functions
    //
    void    CmEditCut() {Cut();}                  // CM_EDITCUT
    void    CmEditCopy() {Copy();}                // CM_EDITCOPY
    void    CmEditPaste() {Paste();}              // CM_EDITPASTE
    void    CmEditDelete() {DeleteSelection();}   // CM_EDITDELETE
    void    CmEditClear() {Clear();}              // CM_EDITCLEAR
    void    CmEditUndo() {Undo();}                // CM_EDITUNDO

    //
    // command enabler functions
    //
    void CmSelectEnable(TCommandEnabler& commandHandler);
    void CmPasteEnable(TCommandEnabler& commandHandler);
    void CmCharsEnable(TCommandEnabler& commandHandler);
    void CmModEnable(TCommandEnabler& commandHandler);

    //
    // child id notification handled at the child
    //
    void    ENErrSpace();  // EN_ERRSPACE

    //
    // Override TWindow virtual member functions
    //
    char far* GetClassName();
    void      SetupWindow();

    //
    // Input validation object
    //
    TValidator*  Validator;

    void         EvChar(UINT key, UINT repeatCount, UINT flags);
    void         EvKeyDown(UINT key, UINT repeatCount, UINT flags);
    UINT         EvGetDlgCode(MSG far*);
    void         EvSetFocus(HWND hWndLostFocus);
    void         EvKillFocus(HWND hWndGetFocus);
    BOOL         CanClose();

    //
    // handler for input validation message sent by parent
    //
    void         EvChildInvalid(HWND);

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TEdit(const TEdit&);
    TEdit& operator =(const TEdit&);


    // Used to prevent 'oscillation' when a validated window with invalid
    // input is losing focus to another validated window with invalid input
    // Without this flag, the two windows will fight for focus
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

//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

//
// returns the number of lines in the associated edit control
//
// note that GetNumLines returns 1 when the edit control has no text (i.e.
// it has one line with no text in it). Returns zero if an error occurs
//
inline int TEdit::GetNumLines() const {
  return (int)CONST_CAST(TEdit*,this)->HandleMessage(EM_GETLINECOUNT);
}

inline BOOL TEdit::IsModified() const {
  return (BOOL)CONST_CAST(TEdit*,this)->HandleMessage(EM_GETMODIFY);
}

//
// selects the characters in the range "startPos .. endPos"
//
inline BOOL TEdit::SetSelection(UINT startPos, UINT endPos) {
  #if defined(__WIN32__)
    return HandleMessage(EM_SETSEL, startPos, endPos) != 0;
  #else
    return HandleMessage(EM_SETSEL, 0, MAKELPARAM(startPos, endPos)) != 0;
  #endif
}

// returns the starting and ending positions of the selected text
//
inline void TEdit::GetSelection(UINT& startPos, UINT& endPos) const {
  #if defined(__WIN32__)
    CONST_CAST(TEdit*,this)->HandleMessage(EM_GETSEL, (WPARAM)&startPos, (LPARAM)&endPos);
  #else
    LRESULT  retValue = CONST_CAST(TEdit*,this)->HandleMessage(EM_GETSEL);
    startPos = LOWORD(retValue);
    endPos   = HIWORD(retValue);
  #endif
}

//
// returns the line number associated with character index "CharPos"
//
// if "CharPos" is greater than the number of characters, the last line is
// returned
// if "CharPos" is -1, the line containing the beginning of the selection (or
// the line containing the caret if no selection) is returned
//
inline int TEdit::GetLineFromPos(UINT charPos) const {
  return (int)CONST_CAST(TEdit*,this)->HandleMessage(EM_LINEFROMCHAR, charPos);
}

//
// returns the character index of line number "LineNumber" or -1 if
// "LineNumber" is greater than the number of lines
//
// if "LineNumber" is -1, the line containing the caret is used
//
inline UINT TEdit::GetLineIndex(int lineNumber) const {
  return (int)CONST_CAST(TEdit*,this)->HandleMessage(EM_LINEINDEX, lineNumber);
}

//
// scrolls the text by the specified horizontal and vertical amounts
//
inline void TEdit::Scroll(int horizUnit, int vertUnit) {
  #if defined(__WIN32__)
    HandleMessage(EM_LINESCROLL, horizUnit, vertUnit);
  #else
    HandleMessage(EM_LINESCROLL, 0, MAKELONG(vertUnit, horizUnit));
  #endif
}

//
// sets the selection to the "str" (does a "paste" type of action
// without affecting the clipboard)
//
inline void TEdit::Insert(const char far* str) {
  HandleMessage(EM_REPLACESEL, 0, (LPARAM)str);
}

inline void TEdit::GetRect(TRect& frmtRect) const {
  CONST_CAST(TEdit*,this)->HandleMessage(EM_GETRECT, 0, (LPARAM)(TRect FAR*)&frmtRect);
}

inline void TEdit::SetRect(const TRect& frmtRect) {
  HandleMessage(EM_SETRECT, 0, (LPARAM)(const TRect FAR*)&frmtRect);
}

inline void TEdit::SetRectNP(const TRect& frmtRect) {
  HandleMessage(EM_SETRECTNP, 0, (LPARAM)(const TRect FAR*)&frmtRect);
}

inline void TEdit::FormatLines(BOOL addEOL) {
  HandleMessage(EM_FMTLINES, addEOL);
}

inline void TEdit::SetTabStops(int numTabs, const int far* tabs) {
  HandleMessage(EM_SETTABSTOPS, numTabs, (LPARAM)tabs);
}

inline HLOCAL TEdit::GetHandle() const {
  return (HLOCAL)CONST_CAST(TEdit*,this)->HandleMessage(EM_GETHANDLE);
}

inline void TEdit::SetHandle(HLOCAL localMem) {
  HandleMessage(EM_SETHANDLE, (WPARAM)localMem);
}

inline int TEdit::GetFirstVisibleLine() const {
  return (int)CONST_CAST(TEdit*,this)->HandleMessage(EM_GETFIRSTVISIBLELINE);
}

inline void TEdit::SetReadOnly(BOOL readOnly) {
  HandleMessage(EM_SETREADONLY, readOnly);
}

inline UINT TEdit::GetPasswordChar() const {
  return (UINT)CONST_CAST(TEdit*,this)->HandleMessage(EM_GETPASSWORDCHAR);
}

inline EDITWORDBREAKPROC TEdit::GetWordBreakProc() const {
  return (EDITWORDBREAKPROC)CONST_CAST(TEdit*,this)->HandleMessage(EM_GETWORDBREAKPROC);
}

inline void TEdit::SetWordBreakProc(EDITWORDBREAKPROC proc) {
  HandleMessage(EM_SETWORDBREAKPROC, 0, (LPARAM)proc);
}

inline BOOL TEdit::CanUndo() const {
  return (BOOL)CONST_CAST(TEdit*,this)->HandleMessage(EM_CANUNDO);
}

#endif  // __OWL_EDIT_H
