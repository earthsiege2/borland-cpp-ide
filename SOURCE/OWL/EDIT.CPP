//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\edit.cpp
//   Implementation of class TEdit.  This defines the basic behavior
//   of all edit controls.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\edit.h>
#include <owl\validate.h>
#include <dos.h>
#include <string.h>
#include <ctype.h>

#if !defined(SECTION) || SECTION == 1

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
// constructor for a TEdit object
//
// by default, edit control has a border and its text is left-justified
//
// multiline edit control has horizontal vertical scroll bars
//
TEdit::TEdit(TWindow*        parent,
             int             id,
             const char far* text,
             int x, int y, int w, int h,
             UINT            textLen,
             BOOL            multiline,
             TModule*        module)
  : TStatic(parent, id, text, x, y, w, h, textLen, module)
{
  //
  // undo the styles set by TStatic, & addin edit styles
  //
  Attr.Style &= ~SS_LEFT;
  Attr.Style |= ES_LEFT | ES_AUTOHSCROLL | WS_BORDER | WS_TABSTOP;

  if (multiline)
    Attr.Style |= ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL | WS_HSCROLL;
  Validator = 0;
}

//
// constructor for TEdit associated with a MS-Windows interface element
// created by MS-Windows from a resource definition
//
// by default, data transfer is enabled
//
TEdit::TEdit(TWindow*   parent,
             int        resourceId,
             UINT       textLen,
             TModule*   module)
  : TStatic(parent, resourceId, textLen, module)
{
  EnableTransfer();
  Validator = 0;
}

TEdit::~TEdit()
{
  delete (TStreamableBase*)Validator;
}

//
// beeps when edit control runs out of space
//
void
TEdit::ENErrSpace()
{
  MessageBeep(0);

  DefaultProcessing();  // give parent a chance to process
}

//
// Responds to the GetDlgCode query according to the
// current state of the control.  If the edit control
// contains valid input, then TABs are allowed for
// changing focus.  Otherwise, requests that TABs be
// sent to Self, where we will generate the Invalid
// message (See WMKeyDown below).
//
UINT
TEdit::EvGetDlgCode(MSG far* msg)
{
  UINT retVal = (UINT)TStatic::EvGetDlgCode(msg);
  if (!IsValid(FALSE))
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
TEdit::EvChar(UINT key, UINT repeatCount, UINT flags)
{
  if (Validator && key != VK_BACK) {
    int oldBuffLen = GetTextLen();
    char far* oldBuff = new char[oldBuffLen+1];
    GetText(oldBuff, oldBuffLen+1);
    
    UINT   startSel, endSel;
    GetSelection(startSel, endSel);
    BOOL wasAppending = endSel == oldBuffLen;

    TStatic::EvChar(key, repeatCount, flags);      // Process the new char...

    GetSelection(startSel, endSel);
    int buffLen = GetTextLen();
    char far* buff = (oldBuffLen > buffLen) ? LockBuffer(oldBuffLen+1) :
                                              LockBuffer();

    //
    // Run the result of the edit through the validator.  If incorrect,
    // then restore the original text.  Otherwise, set the (possibly)
    // modified result of the validation back into the edit control,
    // so the results of the auto-fill (if any) can be viewed.
    //
    if (!Validator->HasOption(voOnAppend) || wasAppending && endSel == buffLen) {
      if (!Validator->IsValidInput(buff, FALSE)) {
        strcpy(buff, oldBuff);
      } else {
        if (startSel >= oldBuffLen && buffLen > oldBuffLen)
          startSel = buffLen;
        if (endSel >= oldBuffLen && buffLen > oldBuffLen)
          endSel = buffLen;
      }
      UnlockBuffer(buff, TRUE);
      SetSelection(startSel, endSel);

    } else {
      if (endSel == buffLen && !Validator->IsValidInput(buff, FALSE))
        Validator->Error();
      UnlockBuffer(buff);
    }
    delete oldBuff;

  } else
    TStatic::EvChar(key, repeatCount, flags);
}

//
// If the TAB key is sent to the Edit Control, check
// the validity before allowing the focus to change.
// The control will only get a TAB if WMGetDlgCode(above)
// allows it, which is done when the control contains
// invalid input (we re-validate here just for completeness,
// in case descendants redefine any of this behavior).
//
// We need to validate on TAB focus-changes because there
// is a case not handled by WMKillFocus: when focus is
// lost to an OK or CANCEL button by tabbing.
//
void
TEdit::EvKeyDown(UINT key, UINT /*repeatCount*/, UINT /*flags*/)
{
  if (key == VK_TAB && !IsValid(TRUE))
    return;
  if (Validator && Validator->HasOption(voOnAppend)) {
    UINT  startSel, endSel;
    GetSelection(startSel, endSel);
    
    int buffLen = GetTextLen(); // get new length of buffer
    BOOL  wasAppending = endSel == buffLen;

    DefaultProcessing();

    if (!wasAppending) {
      GetSelection(startSel, endSel);
      char far* buff = LockBuffer();
      if (endSel == strlen(buff) && !Validator->IsValidInput(buff, FALSE))
        Validator->Error();
      UnlockBuffer(buff);
    }

  } else
    DefaultProcessing();
}
 
//
// Validates this whenever the focus is about to be lost.
// Holds onto the focus if this is not valid.  Checks first
// to make sure that the focus is not being taken by either
// (a) another app, or (b) a Cancel button, or (c) an OK
// button (in which case CanClose will validate); in each case,
// we don't want to validate.
//
void
TEdit::EvKillFocus(HWND hWndGetFocus)
{
  //
  // If another validator is attempting to regain focus, then let it
  //
  if (Validator && !ValidatorReFocus) {
    // The window belongs to us if any of the window handles has an object
    // attached
    //
    HWND hWnd = hWndGetFocus;
    while (hWnd && !GetWindowPtr(hWnd))
      hWnd = ::GetParent(hWnd);

    if (hWnd) {
      int btnId = ::GetDlgCtrlID(hWndGetFocus);

      // Note that we do not allow IsValid to post the message
      // box, since the change of focus resulting from that message
      // will interfere with the change we are in the process of
      // completing.  Instead, post a message to the Parent informing
      // it of the validation failure, and providing it with a handle
      // to us.
      //
      if (btnId != IDCANCEL && btnId != IDOK && !IsValid(FALSE)) {
        ValidatorReFocus = this;
        Parent->PostMessage(WM_CHILDINVALID, WPARAM(HWindow));
      }
    }
  }
  TControl::EvKillFocus(hWndGetFocus);
}

//
// We need to make sure the anti-oscillation flag is cleared
//
void
TEdit::EvSetFocus(HWND hWndLostFocus)
{
  // If we're getting focus back because of invalid input, then clear the
  // anti-oscillation flag
  //
  if (ValidatorReFocus == this)
    ValidatorReFocus = 0;

  TControl::EvSetFocus(hWndLostFocus);
}


//
// handler for input validation message sent by parent
//
void
TEdit::EvChildInvalid(HWND)
{
  ValidatorError();
}


void
TEdit::ValidatorError()
{
  if (Validator) {
    SetFocus();
    Validator->Error();
  }
}

void
TEdit::Clear()
{
  DeleteSubText(0, UINT(-1));
}

BOOL
TEdit::CanClose()
{
  BOOL okToClose = TStatic::CanClose();
  if (okToClose)
    if (IsWindowEnabled() && !IsValid(TRUE)) {
      ValidatorReFocus = this;
      SetFocus();
      return FALSE;
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
  UINT sPos, ePos;

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
  TClipboard& clipboard = OpenClipboard();
  commandHandler.Enable(clipboard.IsClipboardFormatAvailable(CF_TEXT));
    clipboard.CloseClipboard();
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
// returns the length of line number "LineNumber"
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
  return (int)CONST_CAST(TEdit*,this)->HandleMessage(EM_LINELENGTH,
                                         (lineNumber > -1) ? 
                                            GetLineIndex(lineNumber) : -1);
}

//
// returns the text of line number "lineNumber" (0-terminated)
// returns FALSE if an error occurs or if the text doesn't fit in "TextString"
//
BOOL
TEdit::GetLine(char far* textString, int strSize, int lineNumber) const
{
  if (strSize <= 0)
    return FALSE;

  BOOL success = strSize >= GetLineLength(lineNumber) + 1;

  if (strSize < sizeof(int)) {
    textString[0] = 0;
    return success;
  }
  ((int far*)textString)[0] = strSize;

  int bytesCopied = (int)CONST_CAST(TEdit*,this)->
                      HandleMessage(EM_GETLINE, lineNumber, (LPARAM)textString);

  textString[bytesCopied] = '\0'; // Windows returns non-0 terminated string

  if (bytesCopied != (int)CONST_CAST(TEdit*,this)->HandleMessage(EM_LINELENGTH,GetLineIndex(lineNumber)))
    return FALSE;
  return success;
}

//
// Lock the edit control's buffer, optionally resizing it first, and return
// a far pointer to the beginning of it, or 0 if failure.
// Must call UnlockBuffer when finished with buffer.
//
char far*
TEdit::LockBuffer(UINT newSize)
{
  // make a copy if can't get handle. Single line edit controls or Win32s will
  // fail the GetHandle(), so do it the hard way.
  //
  if (!(GetWindowLong(GWL_STYLE)&ES_MULTILINE)
#if defined(__WIN32__)
       || (HIWORD(::GetVersion())&0x8000)
#endif
  ) {
    if (!newSize)
      newSize = GetTextLen()+1;
    char* buffer = new char[newSize];
    GetText(buffer, newSize);
    return buffer;
  }

  HLOCAL  hBuffer = GetHandle();

  #if defined(__WIN32__)
    if (newSize) {
      hBuffer = LocalReAlloc(hBuffer, newSize, LHND);
      if (!hBuffer)
        return 0;
    }
    return (char*)LocalLock(hBuffer);
  #else
    WORD editDS = FP_SEG(GlobalLock((HINSTANCE)GetWindowWord(GWW_HINSTANCE)));
    asm push DS;
    _DS = editDS;

    if (newSize) {
      hBuffer = LocalReAlloc(hBuffer, newSize, LHND);
      if (!hBuffer) {
        asm pop DS;
        return 0;
      }
    }
    char far* returnValue = (char far*)MK_FP(_DS,LocalLock(hBuffer));
    asm pop DS;
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
TEdit::UnlockBuffer(const char far* buffer, BOOL updateHandle)
{
  if (!buffer)
    return;

  // if a copy was made on lock, copy it back if requested & free buffer
  //
  if (!(GetWindowLong(GWL_STYLE)&ES_MULTILINE)
#if defined(__WIN32__)
       || (HIWORD(::GetVersion())&0x8000)
#endif
   ) {
    if (updateHandle)
      SetText(buffer);
    delete(char*)buffer;
    return;
  }

  #if defined(__WIN32__)
    HLOCAL  hBuffer = LocalHandle((LPVOID)buffer);
    LocalUnlock(hBuffer);
  #else
    WORD editDS = FP_SEG(buffer);
    asm push DS;
    _DS = editDS;

    HLOCAL  hBuffer = LocalHandle((void near*)FP_OFF(buffer));
    LocalUnlock(hBuffer);

    asm pop DS;
    GlobalUnlock((HGLOBAL)GlobalHandle(editDS));   // unlock LockBuffer's lock
  #endif

  //
  // handle may have moved or buffer contents written on
  //
  if (updateHandle)
    SetHandle(hBuffer);
}

//
// Similar to strstr(), but is case sensitive or insensitive, uses Windows
// string functions to work with different language drivers
//
static const char far*
strstrcd(const char far* str1, const char far* str2, BOOL caseSens)
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
      p++;
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
      p++;
    }
  return 0;
}

//
// Similar to strstrcd(), but searches backwards. Needs the length of str1
// to know where to start.
//
static const char far*
strrstrcd(const char far* str1, UINT len1, const char far* str2,
           BOOL caseSens)
{
  PRECONDITION(str1 && str2);
  int len2 = strlen(str2);
  char far* p = (char far*)(str1 + len1 - len2);

  if (caseSens)
    while (p >= str1) {
      char c = p[len2];            // must term p to match str2 len
      p[len2] = 0;                 // for strcmp to work.
      if (strcmp(p, str2) == 0) {
        p[len2] = c;
        return p;
      }
      p[len2] = c;
      p--;
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
      p--;
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
TEdit::Search(UINT startPos, const char far* text, BOOL caseSensitive,
              BOOL wholeWord, BOOL up)
{
  if (!text || !text[0])
    return -1;

  if (startPos == (UINT)-1) {
    UINT sBeg, sEnd;
    GetSelection(sBeg, sEnd);
    startPos = up ? sBeg : sEnd;
  }
  int textLen = strlen(text);

  //
  // Lock the text buffer to get the pointer, and search thru it for the text
  //
  const char far* buffer = LockBuffer();
  const char far* pos;
  for (;;) {
    if (up)
      pos = strrstrcd(buffer, startPos, text, caseSensitive);
    else
      pos = strstrcd(buffer+startPos, text, caseSensitive);

    //
    // If whole-word matching is enabled and we have a match so far, then make
    // sure the match is on word boundaries.
    //
    if (wholeWord && pos) {
      if (pos > buffer && isalnum(pos[-1]) || // Match is in preceding word
          textLen < strlen(pos) && isalnum(pos[textLen])) {
        startPos = (UINT)(pos-buffer) + !up;
        continue;  // Skip this match and keep searching
      }
    }
    break;  // Out of for loop
  }

  // If we've got a match, select that text, cleanup & return.
  //
  if (pos) {
    UINT sBeg = (UINT)(pos - buffer);
    UnlockBuffer(buffer);
    SetSelection(sBeg, sBeg + textLen);
#if defined(__WIN32__)
    HandleMessage(WM_KEYDOWN, VK_RIGHT);
    SetSelection(sBeg, sBeg + textLen);
#endif

    return sBeg;
  }
  UnlockBuffer(buffer);
  return -1;
}


//
// deletes the selected text; returns FALSE if no text is selected
//
BOOL
TEdit::DeleteSelection()
{
  UINT  startPos, endPos;

  GetSelection(startPos, endPos);

  if (startPos != endPos) {
    HandleMessage(WM_CLEAR);
    return TRUE;
  }
  return FALSE;
}

//
// deletes text in the range "startPos .. endPos"
//
// returns FALSE if an error occurs
//
BOOL
TEdit::DeleteSubText(UINT startPos, UINT endPos)
{
  if (SetSelection(startPos, endPos))
    return DeleteSelection();

  else
    return FALSE;
}

//
// deletes the text at line number "lineNumber" (deletes the line containing
// the caret if "lineNumber" is -1
//
// returns FALSE if "lineNumber" is greater than the number of lines
//
BOOL
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
      return TRUE;

    } else {
      return DeleteSubText(firstPos, lastPos);
    }
  }

  return FALSE;
}

//
// retrieves the text of the associated edit control between the passed
// positions
//
void
TEdit::GetSubText(char far* textString, UINT startPos, UINT endPos) const
{
  int  tempIndex = 0;

  if (endPos >= startPos) {
    BOOL  okToContinue = TRUE;
    int   startLine = GetLineFromPos(startPos);
    int   endLine = GetLineFromPos(endPos);
    int   startChar = startPos - GetLineIndex(startLine);
    int   endChar = endPos - GetLineIndex(endLine);

    for (int tempLine = startLine; tempLine <= endLine && okToContinue; tempLine++) {
      int    tempLineLength = GetLineLength(tempLine);
      char*  line = new char [tempLineLength+1];
      int    tempStart = tempLine == startLine ? startChar : 0;
      int    tempEnd;

      if (tempLine == endLine)
        tempEnd = (endChar > tempLineLength) ? tempLineLength : endChar;

      else
        tempEnd = tempLineLength;

      int  tempSize = tempEnd - tempStart;

      if (GetLine(line, tempLineLength + 1, tempLine)) {
        //
        // can happen if we're indexing the CR/LF
        //
        if (tempSize > 0) {
          memcpy(&textString[tempIndex], &line[tempStart], tempSize);
          tempIndex += tempSize;
        }

        if (tempLine != endLine) {
          textString[tempIndex++] = 0x0d;  // CR
          textString[tempIndex++] = 0x0a;  // LF
        }

      } else
        okToContinue = FALSE;

      delete line;
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
// TextLen
//
void
TEdit::SetupWindow()
{
  TStatic::SetupWindow();

  if (TextLen != 0)
    HandleMessage(EM_LIMITTEXT, TextLen - 1);
}

BOOL
TEdit::IsValid(BOOL reportError)
{
  if (Validator) {
    char far* buffer = LockBuffer();
    BOOL valid = reportError ? Validator->Valid(buffer) : 
                               Validator->IsValid(buffer);
    UnlockBuffer(buffer);
    return valid;
  }
  return TRUE;
}

void
TEdit::SetValidator(TValidator* validator)
{
  delete Validator;
  Validator = validator;
}

//
// transfers state information for TEdit controls
//
// delegates to the Validator if there is one & it has the transfer option set,
// allowing the Validator to convert the text to/from the appropriate type.
// else passes to base, TStatic.
//
// the return value is the size (in bytes) of the transfer data
//
UINT
TEdit::Transfer(void* buffer, TTransferDirection direction)
{
  if (Validator && Validator->HasOption(voTransfer) && GetNumLines() <= 1) {
    CHECK(GetWindowTextLength() < TextLen);
    char* text = new char[TextLen];
    GetText(text, TextLen);
    UINT result = Validator->Transfer(text, buffer, direction);
    if (result == 0)
      result = TStatic::Transfer(buffer, direction);
    else if (direction == tdSetData)
      SetText(text);
    delete text;
    return result;
  }
  return TStatic::Transfer(buffer, direction);
}

#endif

#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TEdit, TStatic);

//
// reads an instance of TEdit from the passed ipstream
//
void*
TEdit::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TStatic*)GetObject(), is);
  is >> GetObject()->Validator;
  return GetObject();
}

//
// writes the TEdit to the passed opstream
//
void
TEdit::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TStatic*)GetObject(), os);
  os << GetObject()->Validator;
}

#endif
