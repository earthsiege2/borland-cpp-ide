//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\editfile.cpp
//   Implementation of class TEditFile, a text edit which can find/replace
//   and read/write from/to a file.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\editfile.h>
#include <owl\applicat.h>
#include <string.h>
#include <dir.h>
#include <limits.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TEditFile, TEditSearch)
  EV_COMMAND(CM_FILESAVE, CmFileSave),
  EV_COMMAND(CM_FILESAVEAS, CmFileSaveAs),
  EV_COMMAND_ENABLE(CM_FILESAVE, CmSaveEnable),
END_RESPONSE_TABLE;

//
// constructor for a TEditFile
//
// initializes its data members using passed parameters and default values
//
TEditFile::TEditFile(TWindow*        parent,
                     int             id,
                     const char far* text,
                     int x, int y, int w, int h,
                     const char far* fileName,
                     TModule*        module)
  : TEditSearch(parent, id, text, x, y, w, h, module)
{
  FileName = fileName ? strnewdup(fileName) : 0;
}

//
// dispose of the file name
//
TEditFile::~TEditFile()
{
  delete FileName;
}

//
// performs setup for a TEditFile
//
void
TEditFile::SetupWindow()
{
  TEditSearch::SetupWindow();
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;
  FileData.SetFilter(string(*GetModule(), IDS_FILEFILTER).c_str());

  SetFileName(FileName);
  if (FileName && !Read()) {
    string msgTemplate(*GetModule(), IDS_UNABLEREAD);
    char*  msg = new char[MAXPATH + msgTemplate.length()];
    wsprintf(msg, msgTemplate.c_str(), FileName);
    MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    delete msg;
    SetFileName(0);
  }
}

//
// sets the file name of the window and updates the caption
// replacing an empty name with 'Untitled' in its caption
//
void
TEditFile::SetFileName(const char far* fileName)
{
  if (fileName != FileName) {
    delete FileName;
    FileName = fileName ? strnewdup(fileName) : 0;
  }

  string untitled(*GetModule(), IDS_UNTITLEDFILE);
  const char far* p = FileName ? (const char far*)FileName : untitled.c_str();

  if (!Parent->Title || !*Parent->Title)
    Parent->SetWindowText(p);

  else {
    const char frmt[] = "%s - %s";
    char* newCaption = new char[strlen(Parent->Title)+3+strlen(p)+1];
    wsprintf(newCaption, frmt, p, Parent->Title);
    Parent->SetWindowText(newCaption);
    delete newCaption;
  }
}

//
// begins the edit of a new file, after determining that it is Ok to
// clear the TEdit's text
//
void
TEditFile::NewFile()
{
  if (CanClear()) {
    Clear();
    Invalidate();
    ClearModify();
    SetFileName(0);
  }
}

//
// replaces the current file with the given file
//
void
TEditFile::ReplaceWith(const char far* fileName)
{
  if (Read(fileName)) {
    Invalidate();
    SetFileName(fileName);

  } else {
    string msgTemplate(*GetModule(), IDS_UNABLEREAD);
    char*  msg = new char[MAXPATH + msgTemplate.length()];
    wsprintf(msg, msgTemplate.c_str(), fileName);
    MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    delete msg;
  }
}

//
// brings up a dialog allowing the user to open a file into this
// window
//
// same as selecting File|Open from the menus
//
void
TEditFile::Open()
{
  if (CanClear()) {
    *FileData.FileName = 0;
    if ((new TFileOpenDialog(this, FileData))->Execute() == IDOK)
      ReplaceWith(FileData.FileName);
  }
}

//
// reads the contents of a  specified file, or the previously-specified file
// if no name passed, into the TEdit control
// The caller is responsible for any error UI
//
BOOL
TEditFile::Read(const char far* fileName)
{
  if (!fileName)
    if (FileName)
      fileName = FileName;
    else
      return FALSE;

  BOOL   success = FALSE;
  HFILE  file = _lopen(fileName, OF_READ);

  if (file != HFILE_ERROR) {
    long  charsToRead = _llseek(file, 0, SEEK_END);
    _llseek(file, 0, SEEK_SET);

    if (charsToRead >= 0
      #if !defined(__WIN32__)
        && charsToRead < UINT_MAX     // limit 16bit edit ctrls to 1 segment
      #endif
      ) {
      Clear();

      // Lock and resize Editor's buffer to the size of the file
      // Then if OK, read the file into editBuffer
      //
      char far* editBuffer = LockBuffer(UINT(charsToRead+1));
      if (editBuffer) {
        if (_lread(file, editBuffer, UINT(charsToRead)) == charsToRead) {

          // 0 terminate Editor's buffer
          //
          editBuffer[int(charsToRead)] = 0;
          success = TRUE;
          ClearModify();
        }
        UnlockBuffer(editBuffer, TRUE);
      }
    }
    _lclose(file);
  }

  return success;
}

//
// saves the contents of the TEdit child control into the file currently
// being editted
//
// returns true if the file was saved or IsModified returns FALSE
//(contents already saved)
//
BOOL
TEditFile::Save()
{
  if (IsModified()) {
    if (!FileName)
      return SaveAs();

    if (!Write()) {
      string msgTemplate(*GetModule(), IDS_UNABLEWRITE);
      char*  msg = new char[MAXPATH + msgTemplate.length()];
      wsprintf(msg, msgTemplate.c_str(), FileName);
      MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
      delete msg;
      return FALSE;
    }
  }
  return TRUE;  // editor's contents haven't been changed
}

//
// saves the contents of the TEdit child control into a file whose name
// is retrieved from the user, through execution of a "Save" file dialog
//
// returns true if the file was saved
//
BOOL
TEditFile::SaveAs()
{
  if (FileName)
    strcpy(FileData.FileName, FileName);

  else
    *FileData.FileName = 0;

  if ((new TFileSaveDialog(this, FileData))->Execute() == IDOK) {
    if (Write(FileData.FileName)) {
      SetFileName(FileData.FileName);
      return TRUE;
    }
    string msgTemplate(*GetModule(), IDS_UNABLEWRITE);
    char*  msg = new char[MAXPATH + msgTemplate.length()];
    wsprintf(msg, msgTemplate.c_str(), FileName);
    MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    delete msg;
  }
  return FALSE;
}

//
// Enables save command only if text is modified
//
void
TEditFile::CmSaveEnable(TCommandEnabler& commandHandler)
{
  commandHandler.Enable(IsModified());
}

//
// writes the contents of the TEdit child control to a specified file, or
// the previously-specified file if none passed.
// The caller is responsible for any error UI
//
BOOL
TEditFile::Write(const char far* fileName)
{
  if (!fileName)
    if (FileName)
      fileName = FileName;
    else
      return FALSE;

  int file = _lcreat(fileName, 0);
  if (file == -1) {
    return FALSE;
  }

  BOOL success = FALSE;
  char far* editBuffer = LockBuffer();
  if (editBuffer) {
    success = _lwrite(file, editBuffer, strlen(editBuffer)) != (WORD)-1;
    UnlockBuffer(editBuffer);
    if (success)
      ClearModify();
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
TEditFile::CanClear()
{
  if (IsModified()) {
    string msgTemplate(*GetModule(), IDS_FILECHANGED);
    string untitled(*GetModule(), IDS_UNTITLEDFILE);
    char*  msg = new char[MAXPATH+msgTemplate.length()];

    wsprintf(msg, msgTemplate.c_str(),
             FileName ? (const char far*)FileName : untitled.c_str());

    int result = MessageBox(msg, GetApplication()->GetName(), MB_YESNOCANCEL|MB_ICONQUESTION);
    delete msg;
    return result==IDYES ? Save() : result != IDCANCEL;
  }
  return TRUE;
}

BOOL
TEditFile::CanClose()
{
  return CanClear();
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_STREAMABLE1(TEditFile, TEditSearch);

//
// reads an instance of TEditFile from the passed ipstream
//
void*
TEditFile::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TEditFile* o = GetObject();
  ReadBaseObject((TEditSearch*)o, is);

  o->FileName = is.freadString();
  if (!*o->FileName) {
    delete o->FileName;
    o->FileName = 0;
  }
  return o;
}

//
// writes the TEditFile to the passed opstream
//
void
TEditFile::Streamer::Write(opstream& os) const
{
  TEditFile* o = GetObject();
  WriteBaseObject((TEditSearch*)o, os);
  os.fwriteString(o->FileName ? o->FileName : "");
}

#endif

