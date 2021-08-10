//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TFileWindow.  This defines the OWL 1.0 compatible
//   file edit window, a text editor which can read and write to a file.
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\module.h>
#include <owl\editfile.rh>
#include "owlrc.h"
#include "filewnd.h"
#include <string.h>
#include <stdio.h>
#include <alloc.h>

DEFINE_RESPONSE_TABLE1(TFileWindow, TEditWindow)
  EV_COMMAND(CM_FILENEW, CmFileNew),
  EV_COMMAND(CM_FILEOPEN, CmFileOpen),
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
END_RESPONSE_TABLE;

IMPLEMENT_STREAMABLE1(TFileWindow, TEditWindow);

#define Min(a, b)    ((a) <(b) ?(a) :(b))

//
// constructor for a TFileWindow
//
// initializes its data members using passed parameters and default values
//
TFileWindow::TFileWindow(TWindow*        parent,
                          const char far* title,
                          const char far* fileName,
                          TModule*        module)
  : TEditWindow(parent, title, module)
{
  FileName = fileName ? strnewdup(fileName) : 0;
}

//
// dispose of the file name
//
TFileWindow::~TFileWindow()
{
  delete FileName;
}

//
// performs setup for a TFileWindow, appending 'Untitled' to its caption
//
void
TFileWindow::SetupWindow()
{
  TEditWindow::SetupWindow();
  SetFileName(FileName);

  if (FileName && !Read())
    SetFileName(0);
}

//
// sets the file name of the window and updates the caption
//
void
TFileWindow::SetFileName(const char far* fileName)
{
  if (FileName != fileName) {
    delete FileName;
    FileName = fileName ? strnewdup(fileName) : 0;
  }

  const char far* p = FileName ?(const char far*)FileName : "(Untitled)";

  if (!Title || !*Title)
    SetWindowText(p);

  else {
    char  newCaption[81];

    wsprintf(newCaption, "%s - %s", Title, p);
    SetWindowText(newCaption);
  }
}

//
// begins the edit of a new file, after determining that it is Ok to
// clear the TEdit's text
//
void
TFileWindow::NewFile()
{
  if (CanClear()) {
    Editor->Clear();
    Editor->Invalidate();
    Editor->ClearModify();
    SetFileName(0);
  }
}

//
// replaces the current file with the given file
//
void
TFileWindow::ReplaceWith(const char far* fileName)
{
  if (Read(fileName)) {
    Editor->Invalidate();
    SetFileName(fileName);
  }
}

//
// brings up a dialog allowing the user to open a file into this
// window
//
// same as selecting File|Open from the menus
//
void
TFileWindow::Open()
{
  char  tmpName[MAXPATH];

  if (CanClear() &&
      TFileDialog(this, SD_FILEOPEN, strcpy(tmpName, "*.*")).Execute() == IDOK)
    ReplaceWith(tmpName);
}

//
// reads the contents of a previously-specified file into the TEdit
// child control
//
BOOL
TFileWindow::Read(const char far* fileName)
{
  if (!fileName)
    if (FileName)
      fileName = FileName;
    else
      return FALSE;

  BOOL success = FALSE;
  int  file = _lopen(fileName, OF_READ);

  if (file != -1) {
    long  charsToRead = _llseek(file, 0, SEEK_END);
    _llseek(file, 0, SEEK_SET);

    if (charsToRead < INT_MAX && charsToRead > 0) {
      Editor->Clear();
      //
      // Lock and resize Editor's buffer to the size of the file
      // Then if OK, read the file into editBuffer
      //
      char far* editBuffer = Editor->LockBuffer(int(charsToRead)+1);
      if (editBuffer) {
        if (_lread(file, editBuffer, int(charsToRead)) == charsToRead) {
          //
          // 0 terminate Editor's buffer
          //
          editBuffer[(int)charsToRead] = 0;
          success = TRUE;
          Editor->ClearModify();
        }
        Editor->UnlockBuffer(editBuffer, TRUE);
      }
    }
    _lclose(file);
  }

  if (!success) {
    char  err[MAXPATH + 33];

    wsprintf(err, "Unable to read file \"%s\" from disk", FileName);
    MessageBox(err, GetModule()->GetName(), MB_ICONEXCLAMATION | MB_OK);
  }
  return success;
}

//
// saves the contents of the TEdit child control into the file currently
// being editted
//
// returns true if the file was saved or Editor->IsModified returns FALSE
//(contents already saved)
//
BOOL
TFileWindow::Save()
{
  if (Editor->IsModified())
    if (!FileName)
      return SaveAs();

    else
      return Write();

  else
    return TRUE;  // editor's contents haven't been changed
}

//
// saves the contents of the TEdit child control into a file whose name
// is retrieved from the user, through execution of a "Save" file dialog
//
// returns true if the file was saved
//
BOOL
TFileWindow::SaveAs()
{
  char      tmpName[MAXPATH];
  OFSTRUCT  ofstruct;

  if (FileName)
    strcpy(tmpName, FileName);

  else
    *tmpName = 0;

  if (TFileDialog(this, SD_FILESAVE, tmpName).Execute() == IDOK) {
    if (::OpenFile(tmpName, &ofstruct, OF_EXIST) != -1) {
      char   msg[MAXPATH+20];

      wsprintf(msg, "Replace Current \"%s\"?", (char far*)tmpName);

      if (MessageBox(msg, "File Changed", MB_YESNO|MB_ICONQUESTION) == IDNO)
        return FALSE;
    }

    if (Write(tmpName)) {
      SetFileName(tmpName);
      return TRUE;
    }
  }
  return FALSE;
}

//
// writes the contents of the TEdit child control to a previously-specified
// file
//
BOOL
TFileWindow::Write(const char far* fileName)
{
  if (!fileName)
    if (FileName)
      fileName = FileName;
    else
      return FALSE;

  int file = _lcreat(fileName, 0);
  if (file == -1) {
    char  msg[MAXPATH + 33];

    wsprintf(msg, "Unable to write file \"%s\" to disk", FileName);
    MessageBox(msg, GetModule()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    return FALSE;
  }

  BOOL success = FALSE;
  char far* editBuffer = Editor->LockBuffer();
  if (editBuffer) {
    success = _lwrite(file, editBuffer, strlen(editBuffer)) !=(WORD)-1;
    Editor->UnlockBuffer(editBuffer);
    if (success)
      Editor->ClearModify();
  }
  _lclose(file);

  return success;
}

//
// returns a BOOL value indicating whether or not it is Ok to clear
// the TEdit's text
//
// returns TRUE if the text has not been changed, or if the user Oks the
// clearing of the text
//
BOOL
TFileWindow::CanClear()
{
  if (Editor->IsModified()) {
    int   result;
    char  msg[MAXPATH+28];

    if (!FileName)
      strcpy(msg, "Untitled file has changed.  Save?");

    else
      wsprintf(msg, "File \"%s\" has changed.  Save?", FileName);

    result = MessageBox(msg, "File Changed", MB_YESNOCANCEL|MB_ICONQUESTION);

    return result == IDYES ? Save() : result != IDCANCEL;
  }
  return TRUE;
}

//
// reads an instance of TFileWindow from the passed ipstream
//
void*
TFileWindow::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TFileWindow* o = GetObject();
  ReadBaseObject((TEditWindow*)o, is);
  o->FileName = is.freadString();
  return o;
}

//
// writes the TFileWindow to the passed opstream
//
void
TFileWindow::Streamer::Write(opstream& os) const
{
  TFileWindow* o = GetObject();
  WriteBaseObject((TEditWindow*)o, os);
  os.fwriteString(o->FileName ? o->FileName : "");
}
