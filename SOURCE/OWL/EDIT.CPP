//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.13  $
//
// Implementation of class TEdit.  This defines the basic behavior
// of all edit controls.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_VALIDATE_H)
# include <owl/validate.h>
#endif
#if !defined(OWL_UPDOWN_H)
# include <owl/updown.h>
#endif
#include <dos.h>
#include <string.h>
#include <ctype.h>

#if !defined(SECTION) || SECTION == 1

//
// Class pointer to an edit control that is trying to regain focus after losing
// it with invalid contents. Is 0 in all other conditions.
//
// Used to prevent 'oscillation' when a validated window with invalid
// input is losing focus to another validated window with invalid input
// Without this flag, the two windows will fight for focus
//
TEdit* TEdit::ValidatorReFocus = 0;

DEFINE_RESPONSE_TABLE1(TEdit, TStatic)
  EV_COMMAND(CM_EDITCUT, CmEditCut),
  EV_COMMAND(CM_EDITCOPY, CmEditCopy),
  EV_COMMAND(CM_EDITPASTE, CmEditPaste),
  EV_COMMAND(CM_EDITDELETE, CmEditDelete),
  EV_COMMAND(CM_EDITCLEAR, CmEditClear),
  EV_COMMAND(CM_EDITUNDO, CmEditUndo),
  EV_COMMAND_ENABLE(CM_EDITCUT, CmSelectEnable),
  EV_COMMAND_ENABLE(CM_EDITCOPY, CmSelectEnable),
  EV_COMMAND_ENABLE(CM_EDITDELETE, CmSelectEnable),
  EV_COMMAND_ENABLE(CM_EDITPASTE, CmPasteEnable),
  EV_COMMAND_ENABLE(CM_EDITCLEAR, CmCharsEnable),
  EV_COMMAND_ENABLE(CM_EDITUNDO, CmModEnable),
  EV_NOTIFY_AT_CHILD(EN_ERRSPACE, ENErrSpace),
  EV_WM_CHAR,
  EV_WM_KEYDOWN,
  EV_WM_GETDLGCODE,
  EV_WM_SETFOCUS,
  EV_WM_KILLFOCUS,
  EV_WM_CHILDINVALID,
END_RESPONSE_TABLE;

//
// Constructor for a TEdit object
//
// By default, edit control has a border and its text is left-justified
//
// Multiline edit control has horizontal vertical scroll bars
//
TEdit::TEdit(TWindow*        parent,
             int             id,
             const char far* text,
             int x, int y, int w, int h,
             uint            textLen,
             bool            multiline,
             TModule*        module)
:
  TStatic(parent, id, text, x, y, w, h, textLen, module)
{
  // Undo the styles set by TStatic, & add in edit styles
  //
  ModifyStyle(SS_LEFT, ES_LEFT | ES_AUTOHSCROLL |
                       WS_BORDER | WS_TABSTOP | WS_EX_CLIENTEDGE);
  if (multiline)
    Attr.Style |= ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | WS_HSCROLL;

  Validator = 0;
}

//
// Constructor for TEdit associated with a MS-Windows interface element
// created by MS-Windows from a resource definition
//
// By default, data transfer is enabled
//
TEdit::TEdit(TWindow*   parent,
             int        resourceId,
             uint       textLen,
             TModule*   module)
:
  TStatic(parent, resourceId, textLen, module)
{
  EnableTransfer();
  Validator = 0;
}

//
// Destructor for a TEdit control
//
TEdit::~TEdit()
{
  SetValidator(0);
}

//
// Beeps when edit control runs out of space
//
void
TEdit::ENErrSpace()
{
  MessageBeep(0);

  DefaultProcessing();  // give parent a chance to process
}

//
// Responds to the GetDlgCode query according to the current state of the
// control.  If the edit control contains valid input, then TABs are allowed
// for changing focus.  Otherwise, requests that TABs be sent to Self, where
// we will generate the Invalid message (See EvKeyDown below).
//
uint
TEdit::EvGetDlgCode(MSG far* msg)
{
  uint retVal = (uint)TStatic::EvGetDlgCode(msg);
  if (!IsValid(false))
    retVal |= DLGC_WANTTAB;
  return retVal;
}

//
// Validates Self whenever a character is entered.  Allows
// the character entry to be processed normally, then validates
// the result and restores Self's text to its original state
// if there is an incorrect entry.
//
// By default, the SupressFill parameter of the IsValidInput
// method call to the Validator is set to False, so that it
// is free to modify the string, if it is so configured.
//
void
TEdit::EvChar(uint key, uint repeatCount, uint flags)
{
  if (Validator && key != VK_BACK) {
    int oldBuffLen = GetTextLen();
    char far* oldBuff = new char[oldBuffLen+1];
    GetText(oldBuff, oldBuffLen+1);

    uint   startSel, endSel;
    GetSelection(startSel, endSel);
    bool wasAppending = endSel == oldBuffLen;

    bool preMsgModify = IsModified();             // Save (pre)  MODIFY flag

    TStatic::EvChar(key, repeatCount, flags);     // Process the new char...

    bool postMsgModify= IsModified();             // Save (post) MODIFY flag

    GetSelection(startSel, endSel);
    int buffLen = GetTextLen();
    char far* buff = LockBuffer(max((int)TextLimit,max(oldBuffLen,buffLen))+1);

    // Run the result of the edit through the validator.  If incorrect,
    // then restore the original text.  Otherwise, range check & position
    // the selection as needed.
    //
    if (!Validator->HasOption(voOnAppend) || wasAppending && endSel == buffLen) {
      if (!Validator->IsValidInput(buff, false)) {
        strcpy(buff, oldBuff);          // Restore old buffer
        postMsgModify = preMsgModify;   // Restore old modify state too!
      }
      else {
        if (wasAppending)
          startSel = endSel = strlen(buff); // may have autoFilled--move to end
      }
      UnlockBuffer(buff, true);
      SetSelection(startSel, endSel);
    }
    else {
      if (endSel == buffLen && !Validator->IsValidInput(buff, false))
        Validator->Error(this);
      UnlockBuffer(buff);
    }
    SendMessage(EM_SETMODIFY, (TParam1)postMsgModify);
    delete[] oldBuff;
  }
  else
    TStatic::EvChar(key, repeatCount, flags);
}

//
// If the TAB key is sent to the Edit Control, check the validity before
// allowing the focus to change. The control will only get a TAB if
// EvGetDlgCode(above) allows it, which is done when the control contains
// invalid input (we re-validate here just for completeness, in case
// descendants redefine any of this behavior).
//
// We need to validate on TAB focus-changes because there is a case not handled
// by EvKillFocus: when focus is lost to an OK or Cancel button by tabbing.
//
// Otherwise, for validators with the OnAppend option, perform an input
// validation if the selection moves to the end. i.e. it becomes appending.
//
void
TEdit::EvKeyDown(uint key, uint /*repeatCount*/, uint /*flags*/)
{
  if (key == VK_TAB && !IsValid(true))
    return;
  if (Validator && Validator->HasOption(voOnAppend)) {
    uint  startSel, endSel;
    GetSelection(startSel, endSel);

    int  buffLen = GetTextLen();   // length of buffer
    bool wasAppending = endSel == buffLen;

    DefaultProcessing();

    if (!wasAppending) {
      GetSelection(startSel, endSel);
      char far* buff = LockBuffer();
      bool err = endSel == strlen(buff) && !Validator->IsValidInput(buff, false);
      UnlockBuffer(buff);
      if (err)
        Validator->Error(this);
    }
  }
  else
    DefaultProcessing();
}

//
// Validates this whenever the focus is about to be lost.
//
// Holds onto the focus if this is not valid.  Checks first to make sure that
// the focus is not being taken by either (a) another app, or (b) a Cancel
// button, or (c) an OK button (in which case CanClose will validate); in each
// case, we don't want to validate.
//
void
TEdit::EvKillFocus(THandle hWndGetFocus)
{
  // If another validator is attempting to regain focus, then let it
  //
  if (Validator && !ValidatorReFocus) {
    // The window getting focus belongs to this app if any of the window
    // handles has an OWL object attached that we can get at.
    //
    THandle hWnd = hWndGetFocus;
    while (hWnd && !GetWindowPtr(hWnd))
      hWnd = ::GetParent(hWnd);

    if (hWnd) {
      int btnId = ::GetDlgCtrlID(hWndGetFocus);

      // Note that we do not allow IsValid to post the message box, since the
      // change of focus resulting from that message will interfere with the
      // change we are in the process of completing.  Instead, post a message
      // to the Parent informing it of the validation failure, and providing it
      // with a handle to us.
      //
      if (btnId != IDCANCEL && btnId != IDOK && !IsValid(false)) {
        ValidatorReFocus = this;
        Parent->PostMessage(WM_CHILDINVALID, TParam1(TWindow::GetHandle()));
      }
    }
  }
  TControl::EvKillFocus(hWndGetFocus);
}

//
// Handle the set focus message and make sure the anti-oscillation flag is cleared
//
void
TEdit::EvSetFocus(THandle hWndLostFocus)
{
  // If we're getting focus back because of invalid input, then clear the
  // anti-oscillation flag
  //
  if (ValidatorReFocus == this)
    ValidatorReFocus = 0;

  TControl::EvSetFocus(hWndLostFocus);
}



//
// Handle input validation message sent by parent
//
void
TEdit::EvChildInvalid(THandle)
{
  ValidatorError();
}

//
//
//
void
TEdit::ValidatorError()
{
  // Temporarily unset our validator & call its Error function directly. This
  // is to avoid and loops caused when we lose focus.
  //
  if (Validator) {
    SetFocus();
    TValidator* savedValidator = Validator;
    Validator = 0;
    savedValidator->Error(this);
    Validator = savedValidator;
  }
}

//
//
//
void
TEdit::Clear()
{
  DeleteSubText(0, uint(-1));
}

//
//
//
bool
TEdit::CanClose()
{
  bool okToClose = TStatic::CanClose();
  if (okToClose)
    if (IsWindowEnabled() && !IsValid(true)) {
      ValidatorReFocus = this;
      SetFocus();
      return false;
    }
  return okToClose;
}

//
// This function is called for Cut/Copy/Delete menu items to determine
// whether or not the item is enabled.
//
void
TEdit::CmSelectEnable(TCommandEnabler& commandHandler)
{
  uint sPos, ePos;

  GetSelection(sPos, ePos);
  commandHandler.Enable(sPos != ePos);
}

//
// This function is called for the Paste menu item to determine whether or
// not the item is enabled.
//
void
TEdit::CmPasteEnable(TCommandEnabler& commandHandler)
{
  TClipboard clipboard(*this);
  commandHandler.Enable(clipboard.IsClipboardFormatAvailable(CF_TEXT));
}

//
// This function is called for the Clear menu item to determine whether or
// not the item is enabled.
//
void
TEdit::CmCharsEnable(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(!(GetNumLines() == 1 && GetLineLength(0) == 0));
}

//
// This function is called for the Undo menu item to determine whether or
// not the item is enabled.
//
void
TEdit::CmModEnable(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(IsModified());
}

//
// Return the length of line number "LineNumber"
//
// if -1 is passed as the line number, the following applies:
//   - returns the length of the line upon which the caret is positioned
//   - if text is selected on the line, returns the line length minus the
//     number of selected characters
//   - if selected text spans more than one line, returns the length minus
//     the number of selected characters
//
int
TEdit::GetLineLength(int lineNumber) const
{
  return (int)CONST_CAST(TEdit*,this)->SendMessage(EM_LINELENGTH,
                                         (lineNumber > -1) ?
                                            GetLineIndex(lineNumber) : -1);
}

//
// Return the text of line number "lineNumber" (0-terminated)
// Return false if an error occurs or if the text doesn't fit in "TextString"
//
// Requires a buffer of at least 2 bytes, even when the line length is 1
//
bool
TEdit::GetLine(char far* textString, int strSize, int lineNumber) const
{
  if (strSize <= 0)
    return false;

  int lineLength = GetLineLength(lineNumber);
  bool success = strSize >= lineLength + 1;

  // The first 16bit word of the buffer is used by EM_GETLINE as the buffer
  // size. Always need a buffer of at least 2 bytes to pass this word.
  //
  if (strSize < sizeof(int16)) {
    textString[0] = 0;
    return lineLength == 0;  // If lineLen was 0, only then are we successful
  }
  ((int16 far*)textString)[0] = int16(strSize);

  int bytesCopied = (int)CONST_CAST(TEdit*,this)->
                      SendMessage(EM_GETLINE, lineNumber, TParam2(textString));

  textString[bytesCopied] = 0; // Windows returns non-0 terminated string

  if (bytesCopied != lineLength)
    return false;
  return success;
}

//
// Lock the edit control's buffer, optionally resizing it first, and return
// a far pointer to the beginning of it, or 0 if failure.
// Must call UnlockBuffer when finished with buffer.
//
char far*
TEdit::LockBuffer(uint newSize)
{
  // Make a copy if can't get handle. Single line edit controls or Win32s will
  // fail the GetMemHandle(), so do it the hard way.
  //
  if (!(GetWindowLong(GWL_STYLE)&ES_MULTILINE)
#if defined(BI_PLAT_WIN32)
       || TSystem::IsWin95() || TSystem::IsWin32s()  
#endif
  ) {
    if (!newSize)
      newSize = GetTextLen()+1;
    char* buffer = new char[newSize];
    GetText(buffer, newSize);
    return buffer;
  }

  HLOCAL  hBuffer = GetMemHandle();

#if defined(BI_PLAT_WIN32)
    if (newSize) {
      hBuffer = LocalReAlloc(hBuffer, newSize, LHND);
      if (!hBuffer)
        return 0;
    }
    return STATIC_CAST(char*,LocalLock(hBuffer));
#else
    uint16 editDS = FP_SEG(GlobalLock((HINSTANCE)GetWindowWord(GWW_HINSTANCE)));
    __emit__(0x1E);  // __asm push DS;
    _DS = editDS;

    if (newSize) {
      hBuffer = LocalReAlloc(hBuffer, newSize, LHND);
      if (!hBuffer) {
        __emit__(0x1F);  // __asm pop DS;
        GlobalUnlock((HGLOBAL)GlobalHandle(editDS));
        return 0;
      }
    }
    char far* returnValue = (char far*)MK_FP(_DS,LocalLock(hBuffer));
    __emit__(0x1F);  // __asm pop DS;
    return returnValue;
#endif
}

//
// Unlock the edit control's buffer locked by LockBuffer.
// Also informs control of new handle if indicated. Should update handle
// if buffer is resized or written to.
// Ignores call if buffer is 0
//
void
TEdit::UnlockBuffer(const char far* buffer, bool updateHandle)
{
  if (!buffer)
    return;

  // If a copy was made on lock, copy it back if requested & free buffer
  //
  if (!(GetWindowLong(GWL_STYLE)&ES_MULTILINE)
#if defined(BI_PLAT_WIN32)
       || TSystem::IsWin95() || TSystem::IsWin32s()
#endif
   ) {
    if (updateHandle)
      SetText(buffer);
    delete[] CONST_CAST(char far*,buffer);
    return;
  }

#if defined(BI_PLAT_WIN32)
    HLOCAL  hBuffer = LocalHandle((LPVOID)buffer);
    LocalUnlock(hBuffer);
#else
    uint16 editDS = FP_SEG(buffer);
    __emit__(0x1E);  // __asm push DS;
    _DS = editDS;

    HLOCAL  hBuffer = LocalHandle((void near*)FP_OFF(buffer));
    LocalUnlock(hBuffer);

    __emit__(0x1F);  // __asm pop DS;
    GlobalUnlock((HGLOBAL)GlobalHandle(editDS));   // unlock LockBuffer's lock
#endif

  // Handle may have moved or buffer contents written on
  //
  if (updateHandle)
    SetMemHandle(hBuffer);
}

//
// Similar to strstr(), but is case sensitive or insensitive, uses Windows
// string functions to work with different language drivers
//
static const char far*
strstrcd(const char far* str1, const char far* str2, bool caseSens)
{
  PRECONDITION(str1 && str2);
  int len2 = strlen(str2);
  char far* p = (char far*)str1;
  const char far* endp = str1 + strlen(str1) - len2 + 1;

  if (caseSens)
    while (p < endp) {
      char c = p[len2];            // must term p to match str2 len
      p[len2] = 0;                 // for strcmp to work.
      if (strcmp(p, str2) == 0) {
        p[len2] = c;
        return p;
      }
      p[len2] = c;
#if defined(BI_DBCS_SUPPORT)
      char far* p2 = ::AnsiNext(p);
      if (p2 <= p)
        break;
      p = p2;
#else
      p++;
#endif
    }
  else
    while (p < endp) {
      char c = p[len2];
      p[len2] = 0;
      if (strcmpi(p, str2) == 0) {
        p[len2] = c;
        return p;
      }
      p[len2] = c;
#if defined(BI_DBCS_SUPPORT)
      char far* p2 = ::AnsiNext(p);
      if (p2 <= p)
        break;
      p = p2;
#else
      p++;
#endif
    }
  return 0;
}

//
// Similar to strstrcd(), but searches backwards. Needs the length of str1
// to know where to start.
//
static const char far*
strrstrcd(const char far* str1, uint len1, const char far* str2,
           bool caseSens)
{
  PRECONDITION(str1 && str2);
  int len2 = strlen(str2);
  char far* p = (char far*)(str1 + len1 - len2);

#if defined(BI_DBCS_SUPPORT)
  if (p >= str1)
    p = ::AnsiPrev(str1, p+1);
#endif
  if (caseSens)
    while (p >= str1) {
      char c = p[len2];            // must term p to match str2 len
      p[len2] = 0;                 // for strcmp to work.
      if (strcmp(p, str2) == 0) {
        p[len2] = c;
        return p;
      }
      p[len2] = c;
#if defined(BI_DBCS_SUPPORT)
      char far* p2 = ::AnsiPrev(str1, p);
      if (p2 >= p)
        break;
      p = p2;
#else
      p--;
#endif
    }
  else
    while (p >= str1) {
      char c = p[len2];
      p[len2] = 0;
      if (strcmpi(p, str2) == 0) {
        p[len2] = c;
        return p;
      }
      p[len2] = c;
#if defined(BI_DBCS_SUPPORT)
      char far* p2 = ::AnsiPrev(str1, p);
      if (p2 >= p)
        break;
      p = p2;
#else
      p--;
#endif
    }
  return 0;
}

//
// searchs for and selects the given text and returns the offset of the text
// or -1 if the text is not found
//
// if "startPos" = -1 then it is assumed that the start pos is the
// end/beginning (depending on direction) of the current selection
//
int
TEdit::Search(uint startPos, const char far* text, bool caseSensitive,
              bool wholeWord, bool up)
{
  if (!text || !text[0])
    return -1;

  if (startPos == (uint)-1) {
    uint sBeg, sEnd;
    GetSelection(sBeg, sEnd);
    startPos = up ? sBeg : sEnd;
  }
  int textLen = strlen(text);

  // Lock the text buffer to get the pointer, and search thru it for the text
  //
  const char far* buffer = LockBuffer();
  const char far* pos;
  for (;;) {
    if (up)
      pos = strrstrcd(buffer, startPos, text, caseSensitive);
    else
      pos = strstrcd(buffer+startPos, text, caseSensitive);

    // If whole-word matching is enabled and we have a match so far, then make
    // sure the match is on word boundaries.
    //
    if (wholeWord && pos) {
#if defined(BI_DBCS_SUPPORT)
      char far *prevPos;
      if (pos > buffer)
         prevPos = ::AnsiPrev(buffer, pos);

      if (pos > buffer && isalnum((uchar)*prevPos) || // Match is in preceding word
          textLen < strlen(pos) && isalnum((uchar)pos[textLen])) {
        if (up)
          startPos = (uint)(prevPos - buffer) + strlen(text);
        else
          startPos = (uint)(::AnsiNext(pos) - buffer);
        continue;  // Skip this match and keep searching
      }
#else
      if (pos > buffer && isalnum(pos[-1]) || // Match is in preceding word
          textLen < strlen(pos) && isalnum(pos[textLen])) {
        startPos = (uint)(pos-buffer) + !up;
        continue;  // Skip this match and keep searching
      }
#endif
    }
    break;  // Out of for loop
  }

  // If we've got a match, select that text, cleanup & return.
  //
  if (pos) {
    uint sBeg = (uint)(pos - buffer);
    UnlockBuffer(buffer);
    SetSelection(sBeg, sBeg + textLen);
#if defined(BI_PLAT_WIN32)
    SendMessage(WM_KEYDOWN, VK_RIGHT);
    SetSelection(sBeg, sBeg + textLen);
#endif

    return sBeg;
  }
  UnlockBuffer(buffer);
  return -1;
}


//
// deletes the selected text; returns false if no text is selected
//
bool
TEdit::DeleteSelection()
{
  uint  startPos, endPos;

  GetSelection(startPos, endPos);

  if (startPos != endPos) {
    SendMessage(WM_CLEAR);
    return true;
  }
  return false;
}

//
// deletes text in the range "startPos .. endPos"
//
// returns false if an error occurs
//
bool
TEdit::DeleteSubText(uint startPos, uint endPos)
{
  if (SetSelection(startPos, endPos))
    return DeleteSelection();

  else
    return false;
}

//
// deletes the text at line number "lineNumber" (deletes the line containing
// the caret if "lineNumber" is -1
//
// returns false if "lineNumber" is greater than the number of lines
//
bool
TEdit::DeleteLine(int lineNumber)
{
  if (lineNumber == -1)
    lineNumber = GetLineFromPos(GetLineIndex(-1));

  int firstPos = GetLineIndex(lineNumber);

  if (firstPos != -1) {
    int  lastPos = GetLineIndex(lineNumber + 1);

    if (lastPos == -1)
      lastPos = firstPos + GetLineLength(lineNumber);

    if (firstPos == 0  && firstPos == lastPos) {
      SetText("");
      return true;
    }
    else {
      return DeleteSubText(firstPos, lastPos);
    }
  }

  return false;
}

//
// Retrieve the text of the associated edit control between the given
// positions
// Assumes that textString is large enough.
//
void
TEdit::GetSubText(char far* textString, uint startPos, uint endPos) const
{
  int  tempIndex = 0;

  if (endPos >= startPos) {
    bool  okToContinue = true;
    int   startLine = GetLineFromPos(startPos);
    int   endLine = GetLineFromPos(endPos);
    int   startChar = startPos - GetLineIndex(startLine);
    int   endChar = endPos - GetLineIndex(endLine);

    for (int tempLine = startLine; tempLine <= endLine && okToContinue; tempLine++) {
      int    tempLineLength = GetLineLength(tempLine);
      char*  lineBuff = new char [tempLineLength+2];  // 2 min for GetLine()
      int    tempStart = tempLine == startLine ? startChar : 0;
      int    tempEnd;

      if (tempLine == endLine)
        tempEnd = (endChar > tempLineLength) ? tempLineLength : endChar;

      else
        tempEnd = tempLineLength;

      int  tempSize = tempEnd - tempStart;

      if (GetLine(lineBuff, tempLineLength+2, tempLine)) {
        // Can happen if we're indexing the CR/LF
        //
        if (tempSize > 0) {
          memcpy(&textString[tempIndex], &lineBuff[tempStart], tempSize);
          tempIndex += tempSize;
        }
        if (tempLine != endLine) {
          textString[tempIndex++] = 0x0D;  // CR
          textString[tempIndex++] = 0x0A;  // LF
        }
      }
      else
        okToContinue = false;

      delete[] lineBuff;
    }
  }
  textString[tempIndex] = '\0';
}

//
// Return name of predefined Windows edit class
//
char far*
TEdit::GetClassName()
{
  return "EDIT";
}

//
// limits the amount of text that an edit control can have to the value of
// TextLimit
//
void
TEdit::SetupWindow()
{
  TStatic::SetupWindow();

  if (TextLimit != 0)
    LimitText(TextLimit - 1);
}

//
//
//
bool
TEdit::IsValid(bool reportError)
{
  if (Validator) {
    char far* buffer = LockBuffer();
    bool valid = reportError ? Validator->Valid(buffer, this) :
                               Validator->IsValid(buffer);
    UnlockBuffer(buffer);
    return valid;
  }
  return true;
}

//
// Sets a new validator for this control, can be 0. Cleans up the old validator
//
void
TEdit::SetValidator(TValidator* validator)
{
  delete (TStreamableBase*)Validator;  // upcast to avoid explicit call to dtor
  Validator = validator;
}

//
// Transfers state information for TEdit controls
//
// Delegates to the Validator if there is one & it has the transfer option set,
// allowing the Validator to convert the text to/from the appropriate type.
// Else passes to base, TStatic.
//
// The return value is the size (in bytes) of the transfer data
//
uint
TEdit::Transfer(void* buffer, TTransferDirection direction)
{
  if (Validator && Validator->HasOption(voTransfer) && GetNumLines() <= 1) {
    CHECK(GetWindowTextLength() < TextLimit);
    char* text = new char[TextLimit];
    GetText(text, TextLimit);
    uint result = Validator->Transfer(text, buffer, direction);
    if (result == 0)
      result = TStatic::Transfer(buffer, direction);
    else if (direction == tdSetData)
      SetText(text);
    delete[] text;
    return result;
  }
  return TStatic::Transfer(buffer, direction);
}

#endif

#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TEdit, TStatic);

#if !defined(BI_NO_OBJ_STREAMING)

//
// reads an instance of TEdit from the given ipstream
//
void*
TEdit::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TStatic*)GetObject(), is);
  is >> GetObject()->Validator;
  return GetObject();
}

//
// writes the TEdit to the given opstream
//
void
TEdit::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TStatic*)GetObject(), os);
  os << GetObject()->Validator;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
