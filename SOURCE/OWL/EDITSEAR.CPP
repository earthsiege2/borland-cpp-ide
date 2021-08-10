//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\editsear.cpp
//   Implementation of class TEditWindow, an edit control that responds to
//   Find, Replace and FindNext commands.
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\editsear.h>
#include <owl\applicat.h>
#include <owl\edit.h>
#include <owl\findrepl.h>
#include <cstring.h>

#if !defined(SECTION) || SECTION == 1

DEFINE_RESPONSE_TABLE1(TEditSearch, TEdit)
  EV_COMMAND(CM_EDITFIND, CmEditFind),
  EV_COMMAND(CM_EDITREPLACE, CmEditReplace),
  EV_COMMAND(CM_EDITFINDNEXT, CmEditFindNext),
  EV_REGISTERED(FINDMSGSTRING, EvFindMsg),
END_RESPONSE_TABLE;

//
// Construct a TEditSearch window given some initial text.
//
TEditSearch::TEditSearch(TWindow*        parent,
                         int             id,
                         const char far* text,
                         int x, int y, int w, int h,
                         TModule*        module)
  : TEdit(parent, id, text, x, y, w, h, 0, TRUE, module),
    SearchData(FR_DOWN)
{
  Attr.Style |= ES_NOHIDESEL;
  SearchDialog = 0;
  SearchCmd = 0;
}

TEditSearch::~TEditSearch()
{
  delete SearchDialog;
}

//
// Post a CM_EDITFIND or a CM_EDITREPLACE to re-open a previously open 
// find or replace modeless dialog
//
void
TEditSearch::SetupWindow()
{
  TEdit::SetupWindow();
  if (SearchCmd)
    PostMessage(WM_COMMAND, SearchCmd);
}

//
// Perform a search or replace operation based on information in SearchData
//
void
TEditSearch::DoSearch()
{
  do {
    if (Search(-1, SearchData.FindWhat, BOOL(SearchData.Flags&FR_MATCHCASE),
               BOOL(SearchData.Flags&FR_WHOLEWORD),
               !(SearchData.Flags&FR_DOWN)) >= 0) {
      if (SearchData.Flags & (FR_REPLACE|FR_REPLACEALL))
        Insert(SearchData.ReplaceWith);

    } else {
      if (SearchData.Flags & (FR_FINDNEXT|FR_REPLACE)) {
        string errTemplate(*GetModule(), IDS_CANNOTFIND);
        char  errMsg[81];
        wsprintf(errMsg, errTemplate.c_str(), (LPCSTR)SearchData.FindWhat);
        TWindow* w = SearchDialog ? (TWindow*)SearchDialog : (TWindow*)this;
        w->MessageBox(errMsg, GetApplication()->GetName(),
                      MB_OK | MB_ICONEXCLAMATION);

      } else if (SearchData.Flags & FR_REPLACEALL)
        break;
    }
  } while (SearchData.Flags & FR_REPLACEALL);
}

//
// Open the modeless Find commdlg
//
void
TEditSearch::CmEditFind()
{
  if (!SearchCmd) {
    SearchCmd = CM_EDITFIND;
    delete SearchDialog;
    SearchDialog = new TFindDialog(this, SearchData);
    SearchDialog->Create();
  }
}

//
// Open the modeless Replace commdlg
//
void
TEditSearch::CmEditReplace()
{
  if (!SearchCmd) {
    SearchCmd = CM_EDITREPLACE;
    delete SearchDialog;
    SearchDialog = new TReplaceDialog(this, SearchData);
    SearchDialog->Create();
  }
}

//
// Respond to the possible separate menu command to repeat the search
//
void
TEditSearch::CmEditFindNext()
{
  if (SearchDialog)
    SearchDialog->UpdateData();
  SearchData.Flags |= FR_FINDNEXT;
  DoSearch();
}

//
// Respond to the message sent by the modeless find/replace dialog by
// performing a search. Or, if the dialog has terminated, zero search command
//
LRESULT
TEditSearch::EvFindMsg(WPARAM, LPARAM lParam)
{
  PRECONDITION(SearchDialog);

  SearchDialog->UpdateData(lParam);
  if (SearchData.Flags & FR_DIALOGTERM)
    SearchCmd = 0;

  else
    DoSearch();
  return 0;
}


#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE1(TEditSearch, TEdit);

//
// reads an instance of TEditSearch from the passed ipstream.
// Re-opens the modeless find or replace dialog if one was up.
//
void*
TEditSearch::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  ReadBaseObject((TEdit*)GetObject(), is);

  GetObject()->SearchData.Read(is);
  is >> GetObject()->SearchCmd;
  GetObject()->SearchDialog = 0;
  return GetObject();
}

//
// writes the TEditSearch to the passed opstream
//
void
TEditSearch::Streamer::Write(opstream& os) const
{
  WriteBaseObject((TEdit*)GetObject(), os);

  GetObject()->SearchData.Write(os);
  os << GetObject()->SearchCmd;
}

#endif
