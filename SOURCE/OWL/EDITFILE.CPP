//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.4  $
//
// Implementation of class TEditFile, a text edit which can find/replace and
// read/write from/to a file.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_WINDOW_H)
# include <owl/window.h>
#endif
#if !defined(OWL_CONTROL_H)
# include <owl/control.h>
#endif
#if !defined(OWL_EDIT_H)
# include <owl/edit.h>
#endif
#if !defined(OWL_EDITSEAR_H)
# include <owl/editsear.h>
#endif
#if !defined(OWL_EDITFILE_H)
# include <owl/editfile.h>
#endif
#if !defined(OWL_APPLICAT_H)
# include <owl/applicat.h>
#endif
#if !defined(WINSYS_SYSTEM_H)
# include <winsys/system.h>
#endif
#include <string.h>
#include <limits.h>
#include <stdio.h>

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
:
  TEditSearch(parent, id, text, x, y, w, h, module)
{
  FileName = fileName ? strnewdup(fileName) : 0;
}

//
// dispose of the file name
//
TEditFile::~TEditFile()
{
  delete[] FileName;
}

//
// performs setup for a TEditFile
//
void
TEditFile::SetupWindow()
{
  TEditSearch::SetupWindow();
  FileData.Flags = OFN_FILEMUSTEXIST|OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT;

#if defined(BI_PLAT_WIN32)
  FileData.Flags |= OFN_LONGNAMES;
  //
  // We currently cannot mix OFN_ENABLEHOOK & OFN_EXPLORER
  // when running under NT 3.51[no new shell]
  //
  if (TSystem::IsWin95())
    FileData.Flags |= OFN_EXPLORER;
#endif

  FileData.SetFilter(GetModule()->LoadString(IDS_FILEFILTER).c_str());

  SetFileName(FileName);
  if (FileName && !Read()) {
    string msgTemplate(GetModule()->LoadString(IDS_UNABLEREAD));
    char*  msg = new char[_MAX_PATH + msgTemplate.length()];
    sprintf(msg, msgTemplate.c_str(), FileName);
    MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    delete[] msg;
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
    delete[] FileName;
    FileName = fileName ? strnewdup(fileName) : 0;
  }
  string untitled(GetModule()->LoadString(IDS_UNTITLEDFILE));
  SetDocTitle(FileName ? (const char far*)FileName : untitled.c_str(), 0);
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
  }
  else {
    string msgTemplate(GetModule()->LoadString(IDS_UNABLEREAD));
    char*  msg = new char[_MAX_PATH + msgTemplate.length()];
    sprintf(msg, msgTemplate.c_str(), fileName);
    MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    delete[] msg;
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
    if (TFileOpenDialog(this, FileData).Execute() == IDOK)
      ReplaceWith(FileData.FileName);
  }
}

//
// reads the contents of a  specified file, or the previously-specified file
// if no name passed, into the TEdit control
// The caller is responsible for any error UI
//
bool
TEditFile::Read(const char far* fileName)
{
  if (!fileName)
    if (FileName)
      fileName = FileName;
    else
      return false;

  bool   success = false;
  HFILE  file = _lopen(fileName, OF_READ);

  if (file != HFILE_ERROR) {
    long  charsToRead = _llseek(file, 0, SEEK_END);
    _llseek(file, 0, SEEK_SET);

    if (charsToRead >= 0
#if !defined(BI_PLAT_WIN32)
        && charsToRead < UINT_MAX     // limit 16bit edit ctrls to 1 segment
#endif
      ) {
      Clear();

      // Lock and resize Editor's buffer to the size of the file
      // Then if OK, read the file into editBuffer
      //
      char far* editBuffer = LockBuffer(uint(charsToRead+1));
      if (editBuffer) {
        if (_lread(file, editBuffer, uint(charsToRead)) == uint(charsToRead)) {

          // 0 terminate Editor's buffer
          //
          editBuffer[int(charsToRead)] = 0;
          success = true;
          ClearModify();
        }
        UnlockBuffer(editBuffer, true);
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
// returns true if the file was saved or IsModified returns false
//(contents already saved)
//
bool
TEditFile::Save()
{
  if (IsModified()) {
    if (!FileName)
      return SaveAs();

    if (!Write()) {
      string msgTemplate(GetModule()->LoadString(IDS_UNABLEWRITE));
      char*  msg = new char[_MAX_PATH + msgTemplate.length()];
      sprintf(msg, msgTemplate.c_str(), FileName);
      MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
      delete[] msg;
      return false;
    }
  }
  return true;  // editor's contents haven't been changed
}

//
// saves the contents of the TEdit child control into a file whose name
// is retrieved from the user, through execution of a "Save" file dialog
//
// returns true if the file was saved
//
bool
TEditFile::SaveAs()
{
  if (FileName)
    strcpy(FileData.FileName, FileName);

  else
    *FileData.FileName = 0;

  if (TFileSaveDialog(this, FileData).Execute() == IDOK) {
    if (Write(FileData.FileName)) {
      SetFileName(FileData.FileName);
      return true;
    }
    string msgTemplate(GetModule()->LoadString(IDS_UNABLEWRITE));
    char*  msg = new char[_MAX_PATH + msgTemplate.length()];
    sprintf(msg, msgTemplate.c_str(), FileName);
    MessageBox(msg, GetApplication()->GetName(), MB_ICONEXCLAMATION | MB_OK);
    delete[] msg;
  }
  return false;
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
bool
TEditFile::Write(const char far* fileName)
{
  if (!fileName)
    if (FileName)
      fileName = FileName;
    else
      return false;

  int file = _lcreat(fileName, 0);
  if (file == -1) {
    return false;
  }

  bool success = false;
  char far* editBuffer = LockBuffer();
  if (editBuffer) {
    success = ToBool(_lwrite(file, editBuffer, strlen(editBuffer)) != (uint16)-1);
    UnlockBuffer(editBuffer);
    if (success)
      ClearModify();
  }
  _lclose(file);

  return success;
}

//
// returns a bool value indicating whether or not it is Ok to clear
// the TEdit's text
//
// returns true if the text has not been changed, or if the user Oks the
// clearing of the text
//
bool
TEditFile::CanClear()
{
  if (IsModified()) {
    string msgTemplate(GetModule()->LoadString(IDS_FILECHANGED));
    string untitled(GetModule()->LoadString(IDS_UNTITLEDFILE));
    char*  msg = new char[_MAX_PATH+msgTemplate.length()];

    sprintf(msg, msgTemplate.c_str(),
             FileName ? (const char far*)FileName : untitled.c_str());

    int result = MessageBox(msg, GetApplication()->GetName(), MB_YESNOCANCEL|MB_ICONQUESTION);
    delete[] msg;
    return result==IDYES ? Save() : result != IDCANCEL;
  }
  return true;
}

//
//
//
bool
TEditFile::CanClose()
{
  return CanClear();
}

#endif
#if !defined(SECTION) || SECTION == 2


IMPLEMENT_STREAMABLE1(TEditFile, TEditSearch);

#if !defined(BI_NO_OBJ_STREAMING)

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

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif

