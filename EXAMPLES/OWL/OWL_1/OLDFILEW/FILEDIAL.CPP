//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TFileDialog.  This defines the basic
//   behavior of the OWL 1.0 compatible TFileDialog
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\edit.h>
#include <owl\listbox.h>
#include <string.h>
#include "owlrc.h"
#include "filedial.h"

DEFINE_RESPONSE_TABLE1(TFileDialog, TDialog)
  EV_EN_CHANGE(ID_FNAME, FNameChange),
  EV_LBN_SELCHANGE(ID_FLIST, FListChange),
  EV_LBN_DBLCLK(ID_FLIST, FListDblClk),
  EV_LBN_KILLFOCUS(ID_FLIST, FListKillFocus),
  EV_LBN_SELCHANGE(ID_DLIST, DListChange),
  EV_LBN_DBLCLK(ID_DLIST, DListDblClk),
  EV_LBN_KILLFOCUS(ID_DLIST, DListKillFocus),
END_RESPONSE_TABLE;

char far*
GetFileName(char far* filepath)
{
  char far*  p = strrchr(filepath, '\\');

  if (!p)
    p = strrchr(filepath, ':');

  return p ? p + 1 : filepath;
}

char far*
GetExtension(char far* filepath)
{
  char far*  p = strchr(GetFileName(filepath), '.');

  return p ? p : strchr(filepath, '\0');
}

BOOL
HasWildCards(char far* filepath)
{
  return strchr(filepath, '\*') || strchr(filepath, '\?');
}

//
// constructor for a TFileDialog. uses the contents of filepath as
// the initial mask (for example, "*.*") for the files to be listed
// in the file list box
//
// filepath is also used as a buffer in which the name of the file
// retrieved from the user is returned. the resource identifier is set
// to SD_FILESAVE or SD_FILEOPEN, which correspond to dialog resources
// in the OWL-supplied filedial.dlg file
//
// if the resource identifier is reset a matching resource with similar
// controls must be supplied
//
TFileDialog::TFileDialog(TWindow* parent,
                         int       resourceId,
                         char far* filepath,
                         TModule*  module)
  : TDialog(parent, resourceId, module)
{
  FilePath = filepath;
  *Extension = 0;
}

//
// returns TRUE if a valid file name has been retrieved from the user to
// indicate that the file dialog can then be closed
//
// retrieves the text of the edit control, and updates PathName
//
// calls UpdateListBoxes; returns FALSE if UpdateListBoxes returns TRUE.  if
// the edit control contains an invalid file name, also returns FALSE
//
BOOL
TFileDialog::CanClose()
{
  OFSTRUCT  ofstruct;

  GetDlgItemText(ID_FNAME, PathName, MAXPATH);

  if (strcmpi(&PathName[strlen(PathName) - 2], "..") == 0)
    strcat(PathName, "\\");  // otherwise OpenFile messes up

  if (OpenFile(PathName, &ofstruct, OF_PARSE) == -1) {
    MessageBeep(0);
    SelectFileName();
    return FALSE;
  }

  //
  // Note: szPathName initially uses OEM char set
  //
  OemToAnsi((char far*)ofstruct.szPathName, (char far*)ofstruct.szPathName);

  strncpy(PathName, (char far*)ofstruct.szPathName, MAXPATH);
  PathName[MAXPATH-1] = 0;

  WORD pathLen = strlen(PathName);
  if (PathName[pathLen - 1] == '\\' || HasWildCards(PathName) ||
      GetFocus() == GetDlgItem(ID_DLIST))
  {
    if (PathName[pathLen - 1] == '\\')
      strncat(PathName, FileSpec, (MAXPATH-1) - strlen(PathName));

    if (!UpdateListBoxes()) {
      MessageBeep(0);
      SelectFileName();
    }

    return FALSE;
  }

  strncat(PathName, "\\", (MAXPATH-1) - strlen(PathName));
  strncat(PathName, FileSpec, (MAXPATH-1) - strlen(PathName));

  if (UpdateListBoxes())
    return FALSE;

  PathName[pathLen] = '\0';

  if (GetExtension(PathName)[0] == '\0') {
    strncat(PathName, Extension, MAXPATH-1 - strlen(PathName));
    PathName[MAXPATH-1] = '\0';
  }

  AnsiLower(strcpy(FilePath, PathName));
  return TRUE;
}

//
// sets up the file dialog.  limits the number of characters which
// can be entered into the edit control to MAXPATH - 1
//
// calls UpdateListBoxes and SelectFileName
//
void
TFileDialog::SetupWindow()
{
  TDialog::SetupWindow();

  SendDlgItemMessage(ID_FNAME, EM_LIMITTEXT, MAXPATH-1, 0);

  strncpy(PathName, FilePath, MAXPATH);
  PathName[MAXPATH-1] = '\0';

  if (!UpdateListBoxes()) {
    strcpy(PathName, "*.*");
    UpdateListBoxes();
  }

  SelectFileName();
}

//
// responds to EN_CHANGE from edit control ID_FNAME by enabling the OK button
// if the edit control contains text
//
void
TFileDialog::FNameChange()
{
  if (::SendMessage(GetDlgItem(ID_FNAME), WM_GETTEXTLENGTH, 0, 0))
    ::EnableWindow(GetDlgItem(IDOK), TRUE);
}

//
// responds to LBN_SELCHANGE from the file list box by updating PathName with
// the name of the selected file and calling UpdateFileName()
//
void
TFileDialog::FListChange()
{
  DlgDirSelectEx(HWindow, PathName, sizeof PathName, ID_FLIST);
  UpdateFileName();
}

//
// responds to LBN_DBLCLK from the file list box by updating PathName with
// the name of the selected file, calling UpdateFileName(), and closing the
// list box
//
void
TFileDialog::FListDblClk()
{
  DlgDirSelectEx(HWindow, PathName, sizeof PathName, ID_FLIST);
  UpdateFileName();
  CloseWindow(IDOK);
}

//
// responds to LBN_KILLFOCUS from the file list box by clearing the selection
// in the list box
//
void
TFileDialog::FListKillFocus()
{
  ::SendMessage(GetDlgItem(ID_FLIST), LB_SETCURSEL, -1, 0);
}

//
// responds to LBN_SELCHANGE from the directory list box by updating PathName
// and calling UpdateFileName()
//
void
TFileDialog::DListChange()
{
  DlgDirSelectEx(HWindow, PathName, sizeof(PathName), ID_FLIST);
  strcat(PathName, FileSpec);
  UpdateFileName();
}

//
// responds to LBN_DBLCLK from the directory list box by updating PathName
// and calling UpdateListBoxes()
//
void
TFileDialog::DListDblClk()
{
  DlgDirSelectEx(HWindow, PathName, sizeof(PathName), ID_FLIST);
  strcat(PathName, FileSpec);
  UpdateListBoxes();
}

//
// responds to LBN_KILLFOCUS from the directory list box by clearing the
// selection in the list box
//
void
TFileDialog::DListKillFocus()
{
  ::SendMessage(GetDlgItem(ID_DLIST), LB_SETCURSEL, -1, 0);
}

inline static
void
SelectAllText(HWND hWindow, int dlgItem)
{
  #ifdef __WIN32__
    ::SendDlgItemMessage(hWindow, dlgItem, EM_SETSEL, 0, -1);
  #else
    ::SendDlgItemMessage(hWindow, dlgItem, EM_SETSEL, 0, 0x7FFF000L);
  #endif
}

//
// selects all the text in the edit control, and sets the focus to the
// edit control
//
void
TFileDialog::SelectFileName()
{
  SelectAllText(HWindow, ID_FNAME);
  ::SetFocus(GetDlgItem(ID_FNAME));
}

//
// sets the text of the edit control to PathName, and selects the text
//
void
TFileDialog::UpdateFileName()
{
  SetDlgItemText(ID_FNAME, AnsiLower(PathName));
  SelectAllText(HWindow, ID_FNAME);
}

//
// attempts to update the file and/or directory list boxes.  if updated,
// calls UpdateFileName and returns TRUE; otherwise returns FALSE
//
BOOL
TFileDialog::UpdateListBoxes()
{
  int   result;
  char  path[MAXPATH];

  *path = 0;

  if (GetDlgItem(ID_FLIST)) {
    strcpy(path, PathName);

    result = DlgDirList(HWindow, path, ID_FLIST, ID_FPATH, 0);

    if (result)
      DlgDirList(HWindow, "*.*", ID_DLIST, 0, 0xC010);

  } else {
    strncpy(path, PathName, MAXPATH);
    path[MAXPATH-1] = 0;
    strncat(path, "*.*", MAXPATH - 1 - strlen(path));
    result = DlgDirList(HWindow, path, ID_DLIST, ID_FPATH, 0xC010);
  }

  if (result) {
    strncpy(FileSpec, GetFileName(PathName), FILESPEC);
    FileSpec[FILESPEC-1] = 0;
    strcpy(PathName, FileSpec);
    UpdateFileName();
    return TRUE;
  }

  return FALSE;
}
