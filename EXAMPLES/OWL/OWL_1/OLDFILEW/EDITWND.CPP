//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   Implementation of class TEditWindow.  This defines the OWL 1.0 compatible
//   TEditWindow, a text editor (cannot perform file I/O)).
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\module.h>
#include <owl\editsear.rh>
#include "owlrc.h"
#include "editwnd.h"

//__link(RegEdit)

TSearchDialog::TSearchDialog(TWindow*       parent,
                             int            resourceId,
                             TSearchStruct& searchStruct,
                             TModule*       module)
  : TWindow(parent, 0, module),
    TDialog(parent, resourceId, module)
{
  new TEdit(this, ID_SEARCHTEXT, sizeof(searchStruct.SearchText));
  new TCheckBox(this, ID_CASESENSITIVE);

  if (resourceId == SD_REPLACE) {
    new TEdit(this, ID_REPLACETEXT, sizeof(searchStruct.ReplaceText));
    new TCheckBox(this, ID_REPLACEALL);
    new TCheckBox(this, ID_PROMPTONREPLACE);
  }

  TransferBuffer = &searchStruct;
}

DEFINE_RESPONSE_TABLE1(TEditWindow, TWindow)
  EV_WM_SIZE,
  EV_WM_SETFOCUS,
  EV_COMMAND(CM_EDITFIND, CmEditFind),
  EV_COMMAND(CM_EDITFINDNEXT, CmEditFindNext),
  EV_COMMAND(CM_EDITREPLACE, CmEditReplace),
END_RESPONSE_TABLE;

IMPLEMENT_STREAMABLE1(TEditWindow, TWindow);

//
// constructor for a TEditWindow
//
// initializes its data fields using passed parameters and default values
// constructs its child edit control
//
TEditWindow::TEditWindow(TWindow*        parent,
                         const char far* title,
                         TModule*        module)
  : TWindow(parent, title, module)
{
  Editor = new TEdit(this, ID_EDITOR, 0, 0, 0, 0, 0, 0, TRUE, GetModule());
  Editor->Attr.Style |= ES_NOHIDESEL;
  IsReplaceOp = FALSE;
  memset(&SearchStruct, 0, sizeof(SearchStruct));
}

//
// responds to an incoming WM_SIZE message by resizing the child edit
// control according to the size of the TEditWindow's client area
//
void
TEditWindow::EvSize(UINT sizeType, TSize& size)
{
  TWindow::EvSize(sizeType, size);
  Editor->SetWindowPos(0, -1, -1, size.cx + 2, size.cy + 2, SWP_NOZORDER);
}

//
// responds to an incoming WM_SETFOCUS message by setting the focus to
// the child edit control
//
void
TEditWindow::EvSetFocus(HWND)
{
  Editor->SetFocus();
}

void
TEditWindow::DoSearch()
{
  int    rslt = 0;
  BOOL   textFoundSinceUserInput = FALSE;

  do {
    rslt = Editor->Search(-1, SearchStruct.SearchText, SearchStruct.CaseSensitive);

    if (rslt == -1) {
      if (!IsReplaceOp || !SearchStruct.ReplaceAll || !textFoundSinceUserInput) {
        char  err[81];

        wsprintf(err, "\"%0.60s\" not found.", SearchStruct.SearchText);
        MessageBox(err, "Find error", MB_OK | MB_ICONEXCLAMATION);
      }

    } else if (IsReplaceOp) {
      if (!SearchStruct.PromptOnReplace) {
        textFoundSinceUserInput = TRUE;
        Editor->Insert(SearchStruct.ReplaceText);

      } else {
        rslt = MessageBox("Replace this occurrence?", "Search/Replace",
                          MB_YESNOCANCEL | MB_ICONQUESTION);

        if (rslt == IDYES)
          Editor->Insert(SearchStruct.ReplaceText);

        else if (rslt == IDCANCEL)
          return;

        textFoundSinceUserInput = FALSE;
      }
    }
  } while (rslt != -1 && SearchStruct.ReplaceAll && IsReplaceOp);
}

void
TEditWindow::CmEditFind()
{
  if (TSearchDialog(this, SD_SEARCH, SearchStruct).Execute() == IDOK) {
    IsReplaceOp = FALSE;
    DoSearch();
  }
}

void
TEditWindow::CmEditFindNext()
{
  DoSearch();
}

void
TEditWindow::CmEditReplace()
{
  if (TSearchDialog(this, SD_REPLACE, SearchStruct).Execute() == IDOK) {
    IsReplaceOp = TRUE;
    DoSearch();
  }
}

//
// reads an instance of TEditWindow from the passed ipstream
//
void*
TEditWindow::Streamer::Read(ipstream& is, uint32 /*version*/) const
{
  TEditWindow* o = GetObject();
  ReadBaseObject((TWindow*)o, is);

  is >> o->Editor;

  is.readBytes(o->SearchStruct.SearchText, sizeof o->SearchStruct.SearchText);
  is >> o->SearchStruct.CaseSensitive;
  is.readBytes(o->SearchStruct.ReplaceText, sizeof o->SearchStruct.SearchText);
  is >> o->SearchStruct.ReplaceAll >> o->SearchStruct.PromptOnReplace;
  is >> o->IsReplaceOp;

  return o;
}

//
// writes the TEditWindow to the passed opstream
//
void
TEditWindow::Streamer::Write(opstream& os) const
{
  TEditWindow* o = GetObject();
  WriteBaseObject((TWindow*)o, os);
  os << o->Editor;

  os.writeBytes(o->SearchStruct.SearchText, sizeof o->SearchStruct.SearchText);
  os << o->SearchStruct.CaseSensitive;
  os.writeBytes(o->SearchStruct.ReplaceText, sizeof o->SearchStruct.SearchText);
  os << o->SearchStruct.ReplaceAll << o->SearchStruct.PromptOnReplace;
  os << o->IsReplaceOp;
}
