//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1995 by Borland International, All Rights Reserved
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/applicat.h>
#include <owl/framewin.h>
#include <owl/static.h>
#include <owl/edit.h>
#include <owl/inputdia.h>
#include <owl/opensave.h>
#include <owl/validate.h>
#include <fstream.h>
#include <cstring.h>

#include "edit.rh"

// Control ids:
//
const int ID_EXAMPLE_EDIT       = 200;

// Message ids:
//
const int CN_UPDATE             = 300;

class TExampleEdit : public TEdit {
  public:
    TExampleEdit(TWindow*        parent,
                 int             id,
                 const char far* text,
                 int x, int y, int w, int h,
                 uint            textLen = EditTextLen + 1,
                 bool            multiline = true,
                 TModule*        module = 0 )
    :
      TEdit(parent, id, text, x, y, w, h, textLen, multiline, module)
    {
      LastCBOpStr = " ";
    }

    // override to setup 'FileData' structure.
    //
    void SetupWindow();

    // override to update text fields.
    //
    void    CmEditCut();                   // CM_EDITCUT
    void    CmEditCopy();                  // CM_EDITCOPY
    void    CmEditPaste();                 // CM_EDITPASTE
    void    CmEditDelete();                // CM_EDITDELETE
    void    CmEditClear();                 // CM_EDITCLEAR
    void    CmEditUndo();                  // CM_EDITUNDO
    void    EvKeyDown(uint key, uint repeatCount, uint flags);
    void    EvLButtonDown(uint modKeys, TPoint& point);

    // Newly defined functions (not defined by base classes):
    //
    void NotifyParent(int notification);
    void SaveText();
    void RestoreText();
    const string& GetLastCBOpStr() const {return LastCBOpStr;}

    string                  LastCBOpStr;   // string value of last CB operation.
    static const unsigned   EditTextLen;   // length of edit control text.

  private:
    TOpenSaveDialog::TData  FileData;      // save/restore info.

  DECLARE_RESPONSE_TABLE(TExampleEdit);
};

DEFINE_RESPONSE_TABLE1(TExampleEdit, TEdit)
  EV_COMMAND(CM_EDITCUT,     CmEditCut),
  EV_COMMAND(CM_EDITCOPY,    CmEditCopy),
  EV_COMMAND(CM_EDITPASTE,   CmEditPaste),
  EV_COMMAND(CM_EDITDELETE,  CmEditDelete),
  EV_COMMAND(CM_EDITCLEAR,   CmEditClear),
  EV_COMMAND(CM_EDITUNDO,    CmEditUndo),
  EV_WM_KEYDOWN,
  EV_WM_LBUTTONDOWN,
END_RESPONSE_TABLE;

const unsigned TExampleEdit::EditTextLen   = 1000;

void
TExampleEdit::SetupWindow()
{
  TEdit::SetupWindow();
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
  FileData.SetFilter("Text files (*.TXT)|*.TXT|AllFiles (*.*)|*.*|");
}

//
// The next function group simply notifies the app to update the text fields
// then calls the base class version to do the actual processing.
//

void
TExampleEdit::CmEditCut()
{
  LastCBOpStr = "Cut";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditCut();
  NotifyParent(CN_UPDATE);
  TEdit::CmEditCut();
}

void
TExampleEdit::CmEditCopy()
{
  LastCBOpStr = "Copy";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditCopy();
}

void
TExampleEdit::CmEditPaste()
{
  LastCBOpStr = "Paste";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditPaste();
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::CmEditDelete()
{
  LastCBOpStr = "Delete";
  NotifyParent(CN_UPDATE);
  TEdit::CmEditDelete();
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::CmEditClear()
{
  TEdit::CmEditClear();
  LastCBOpStr = "Clear";
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::CmEditUndo()
{
  TEdit::CmEditUndo();
  LastCBOpStr = "Undo";
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::EvKeyDown(uint key, uint repeatCount, uint flags)
{
  TEdit::EvKeyDown(key, repeatCount, flags);
  NotifyParent(CN_UPDATE);
}

void
TExampleEdit::EvLButtonDown(uint modKeys, TPoint& point)
{
  TEdit::EvLButtonDown(modKeys, point);
  NotifyParent(CN_UPDATE);
}

//
// NotifyParent(). 'easy' method of notifing the parent of an event.
// Notifies immediately
void
TExampleEdit::NotifyParent(int notification)
{
  Parent->SendNotification(Attr.Id, notification, HWindow);
}

//
// SaveText().  Save text portion of edit control to a file.
//
void
TExampleEdit::SaveText()
{
  if (TFileSaveDialog(GetApplication()->MainWindow, FileData).Execute() == IDOK) {
    ofstream    ofs(FileData.FileName, ios::out|ios::binary);
    unsigned    maxLen = EditTextLen;
    char far*   buffer = LockBuffer();
    unsigned    size = min(maxLen, strlen(buffer));

    for (unsigned i = 0; i < size && buffer[i]; i++)
      ofs.put(buffer[i]);
    UnlockBuffer(buffer);
  }
}

//
// RestoreText().  Restore or read in text from a file.  Uses the first
// 'EditTextLen' characters from file.
//
void
TExampleEdit::RestoreText()
{
  if (TFileOpenDialog(GetApplication()->MainWindow, FileData).Execute() == IDOK) {
    Clear();

    ifstream    ifs(FileData.FileName);
    char far*   buffer = LockBuffer(EditTextLen + 1);

    unsigned i;
    for (i = 0; i < EditTextLen && !ifs.eof(); i++) {
      buffer[i] = (char)ifs.get();
      if (buffer[i] == '\n' && ifs.peek() != '\r') {
        buffer[i] = '\r';
        buffer[++i] = '\n';
      }
    }
    if (i)
      buffer[i-1] = 0;
    UnlockBuffer(buffer, TRUE);
    NotifyParent(CN_UPDATE);
  }
}

//
// class TEditWindow
// ~~~~~ ~~~~~~~~~~~
class TEditWindow : public TWindow {
  public:
    TEditWindow();

    void SetupWindow();

    // message response functions
    //
    void CmUpdate() {UpdateTextFields();} // Edit control notification.
    void CmInsertText();                  // insert text at char pos.
    void CmDeleteSubText();               // delete subtext.
    void CmDeleteLine();                  // delete line of text.
    void CmSaveText();                    // save text in edit cntl.
    void CmRestoreText();                 // restore from file into edit cntl.

  private:
    TExampleEdit* EditCntl;               // edit control
    TStatic*      NbrLinesText;           // text of number of lines.
    TStatic*      CurLineNbrText;         // current line number.
    TStatic*      CurLineText;            // current line, 1st N chars.
    TStatic*      CurLineLenText;         // length of current line.
    TStatic*      FirstVisibleLineText;   // line # of 1st visible line.
    TStatic*      IsModifiedText;         // has edit control been modified.
    TStatic*      LastCBOpText;           // last clipboard operation.
    TStatic*      CurSelText;             // first N chars of selected text.

    static const unsigned InputTextLen;   // length of input text.
    static const unsigned FirstNChars;    // first n characters to display.

    void  ResetTextFields();              // reset text fields to init values.
    void  UpdateTextFields();             // updates from edit control

    int InputString(char* prompt, char* s);     // read string from user.
    int InputNumber(char* prompt, unsigned& n); // read number from user

  DECLARE_RESPONSE_TABLE(TEditWindow);
};

DEFINE_RESPONSE_TABLE1(TEditWindow, TWindow)
  EV_CHILD_NOTIFY(ID_EXAMPLE_EDIT, CN_UPDATE, CmUpdate),
  EV_EN_VSCROLL(ID_EXAMPLE_EDIT,     CmUpdate),
  EV_COMMAND(CM_INSERT_TEXT,         CmInsertText),
  EV_COMMAND(CM_DELETE_SUBTEXT,      CmDeleteSubText),
  EV_COMMAND(CM_DELETE_LINE,         CmDeleteLine),
  EV_COMMAND(CM_SAVE_TEXT,           CmSaveText),
  EV_COMMAND(CM_RESTORE_TEXT,        CmRestoreText),
END_RESPONSE_TABLE;

const unsigned TEditWindow::InputTextLen  = 51;
const unsigned TEditWindow::FirstNChars   = 20;

//
// Constructor.  Setup menu and text areas.
//
TEditWindow::TEditWindow()
:
  TWindow(0, 0, 0)
{
  const int labelStartX = 10,
            textStartY = 225,
            textHeight = 16,
            textStartX = labelStartX + 250;


  // Create Edit control.
  //
  EditCntl = new TExampleEdit(this, ID_EXAMPLE_EDIT, "", 10, 10, 500, 200);

  // setup static text areas.
  //
  new TStatic(this, -1, "Number of lines:",  labelStartX, textStartY,
              160, textHeight, 16);
  NbrLinesText = new TStatic(this, -1, "0",  textStartX, textStartY,
              50, textHeight, 5);
  new TStatic(this, -1, "current line number:",  labelStartX,
              textStartY + textHeight, 200, textHeight, 20);
  CurLineNbrText = new TStatic(this, -1, "0",  textStartX,
              textStartY + textHeight, 50, textHeight, 5);
  new TStatic(this, -1, "1st 20 chars of current line:",  labelStartX,
              textStartY + textHeight * 2, 290, textHeight, 29);
  CurLineText = new TStatic(this, -1, "",  textStartX,
              textStartY + textHeight * 2, FirstNChars * 10, textHeight,
              FirstNChars);
  new TStatic(this, -1, "length of current line:",  labelStartX,
              textStartY + textHeight * 3, 230, textHeight, 23);
  CurLineLenText = new TStatic(this, -1, "0",  textStartX,
              textStartY + textHeight * 3, 50, textHeight, 5);
  new TStatic(this, -1, "line number of 1st visible list:",  labelStartX,
              textStartY + textHeight * 4, 320, textHeight, 32);
  FirstVisibleLineText = new TStatic(this, -1, "0",  textStartX,
              textStartY + textHeight * 4, 50, textHeight, 5);
  new TStatic(this, -1, "has edit control been modified:",  labelStartX,
              textStartY + textHeight * 5, 310, textHeight, 31);
  IsModifiedText = new TStatic(this, -1, "No",  textStartX,
              textStartY + textHeight * 5, 50, textHeight, 5);
  new TStatic(this, -1, "last clipboard operation:",  labelStartX,
              textStartY + textHeight * 6, 250, textHeight, 25);
  LastCBOpText = new TStatic(this, -1, "",  textStartX,
              textStartY + textHeight * 6, 100, textHeight, 10);
  new TStatic(this, -1, "1st 20 chars of last selected text:",  labelStartX,
              textStartY + textHeight * 7, 350, textHeight, 35);
  CurSelText= new TStatic(this, -1, "",  textStartX,
              textStartY + textHeight * 7, FirstNChars * 10, textHeight,
              FirstNChars);
}

void
TEditWindow::SetupWindow()
{
  TWindow::SetupWindow();
  UpdateTextFields();
}

//
// CmInsertText(). Insert text at character position input be user. If pos
// is beyond end of edit buffer then the insert takes place at the end of
// buffer (append).
//
void
TEditWindow::CmInsertText()
{
  char     buf[InputTextLen] = "";
  unsigned pos;

  if (!InputNumber("Enter position:", pos))
    return;
  EditCntl->SetSelection(pos, pos);

  buf[0] = 0;
  if (!InputString("Enter string:", buf))
    return;
  EditCntl->Insert(buf);
  UpdateTextFields();
}

//
// CmDeleteSubText().  Delete characters between start position and end
// position (input by user).
//
void
TEditWindow::CmDeleteSubText()
{
  unsigned sPos, ePos;

  if (!InputNumber("Enter starting position", sPos))
    return;

  if (!InputNumber("Enter ending position", ePos))
    return;

  EditCntl->DeleteSubText(sPos, ePos);
  UpdateTextFields();
}

//
// CmDeleteLine().  Delete line of text.  Line number input by user.
//
void
TEditWindow::CmDeleteLine()
{
  unsigned line;

  if (!InputNumber("Enter line number:", line))
    return;
  EditCntl->DeleteLine(line);
  UpdateTextFields();
}

//
// SaveText().  Save text of edit control to a file.
//
void TEditWindow::CmSaveText()
{
  EditCntl->SaveText();
}

//
// RestoreText().  retore text of edit control from a file.
//
void TEditWindow::CmRestoreText()
{
  EditCntl->RestoreText();
  UpdateTextFields();
}

//
// UpdateTextFields(). Updates text fields that reflex the edit control's state.
//
void
TEditWindow::UpdateTextFields()
{
  char buf[FirstNChars+1] = "";
  uint sPos, ePos, curLine;

  // make sure all pending messages are processed first
  //
  GetApplication()->PumpWaitingMessages();

  // get the line that the caret is currently on.
  //
  EditCntl->GetSelection(sPos, ePos);
  curLine = EditCntl->GetLineFromPos(ePos);

  itoa(curLine, buf, 10);
  CurLineNbrText->SetText(buf);

  itoa(EditCntl->GetNumLines(), buf, 10);
  NbrLinesText->SetText(buf);

  EditCntl->GetLine(buf, FirstNChars, curLine);
  CurLineText->SetText(buf);

  itoa(EditCntl->GetLineLength(curLine), buf, 10);
  CurLineLenText->SetText(buf);

  itoa(EditCntl->GetFirstVisibleLine(), buf, 10);
  FirstVisibleLineText->SetText(buf);

  if (EditCntl->IsModified())
    IsModifiedText->SetText("Yes");
  else
    IsModifiedText->SetText("No");

  LastCBOpText->SetText(EditCntl->LastCBOpStr.c_str());

  EditCntl->GetSubText(buf, sPos, min(ePos, sPos+(unsigned)FirstNChars));
  if (buf[0])
    CurSelText->SetText(buf);
}

//
// ResetTextFields(). Reset text fields to blanks.
//
void
TEditWindow::ResetTextFields()
{
  NbrLinesText->SetText("0");
  CurLineNbrText->SetText("0");
  CurLineText->SetText("");
  CurLineLenText->SetText("0");
  FirstVisibleLineText->SetText("0");
  IsModifiedText->SetText("No");
  LastCBOpText->SetText("");
  CurSelText->SetText("");
}

//
// InputString(). Get string from user.  Return 1 if successful, 0 otherwise.
// assumes buffer size of InputTextLen.
//
int
TEditWindow::InputString(char* prompt, char* s)
{
  return TInputDialog(this, "String", prompt, s, InputTextLen).Execute() == IDOK;
}

//
// InputNumber(). Get number from user.  Return 1 if successful, 0 otherwise.
//
int
TEditWindow::InputNumber(char* prompt, unsigned& n)
{
  char buf[10] = "";
  int  ok = TInputDialog(this, "Number", prompt, buf, sizeof(buf), 0,
                         new TFilterValidator("0-9")).Execute() == IDOK;
  if (ok)
    n = atoi(buf);
  return ok;
}

//----------------------------------------------------------------------------

class TExampleEditApp : public TApplication {
  public:
    void InitMainWindow();
};

void
TExampleEditApp::InitMainWindow()
{
  TFrameWindow* frame = new TFrameWindow(0, "Edit Control Example",
    new TEditWindow);
  // setup menu
  //
  frame->AssignMenu(IDM_EXAMPLE_EDIT);
  SetMainWindow(frame);
}

int
OwlMain(int /*argc*/, char* /*argv*/ [])
{
  return TExampleEditApp().Run();
}
