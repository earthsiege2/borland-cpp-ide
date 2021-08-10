//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1993, 1995 by Borland International, All Rights Reserved
//
//   Provides templates and DLL access to TEditView and TListView
//----------------------------------------------------------------------------
#include <owl/pch.h>
#include <owl/listview.h>
#include <owl/editview.h>
#include <owl/filedoc.h>
#include <owl/docmanag.h>

DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TListView, ListTemplate);
DEFINE_DOC_TEMPLATE_CLASS(TFileDocument, TEditView, EditTemplate);

_OWLLINK(rTListView); // force TListView::Streamer to be linked in
_OWLLINK(rTEditView); // force TEditView::Streamer to be linked in

EditTemplate atpl("Text files, EditView", "*.txt", 0, "TXT", dtAutoDelete|dtUpdateDir);
ListTemplate btpl("Text files, ListView", "*.txt", 0, "TXT", dtAutoDelete|dtUpdateDir);
ListTemplate ctpl("Batch files, ListView", "*.bat", 0, "BAT", dtAutoDelete|dtUpdateDir);
EditTemplate dtpl("Source files, EditView", "*.cpp;*.h",0,0,dtAutoDelete|dtUpdateDir);
