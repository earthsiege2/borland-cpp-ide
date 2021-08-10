//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1992, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl/pch.h>
#if !defined(OWL_PRINTER_H)
# include <owl/printer.h>
#endif

#if !defined(SECTION) || SECTION == 1

//
//
//
TPrintout::TPrintout(const char far* title)
:
  Title(strnewdup(title)),
  Banding(false),
  ForceAllBands(true),
  DC(0),
  PageSize(0)
{
}

//
//
//
TPrintout::~TPrintout()
{
  delete[] Title;
}

//
//
//
void
TPrintout::SetPrintParams(TPrintDC* dc, TSize pageSize)
{
  SetPrintDC(dc);
  SetPageSize(pageSize);
}

//
//
//
void
TPrintout::GetDialogInfo(int& minPage, int& maxPage,
                         int& selFromPage, int& selToPage)
{
  minPage = 1;
  maxPage = INT_MAX;
  selFromPage = selToPage = 0;
}

//
//
//
void
TPrintout::BeginPrinting()
{
}

//
//
//
void
TPrintout::BeginDocument(int, int, unsigned)
{
}

//
//
//
bool
TPrintout::HasPage(int page)
{
  return page == 1;
}

//
//
//
void
TPrintout::PrintPage(int, TRect&, unsigned)
{
}

//
//
//
void
TPrintout::EndDocument()
{
}

//
//
//
void
TPrintout::EndPrinting()
{
}

//
// Set a new title for this printout. The passed title string is copied.
//
void
TPrintout::SetTitle(const char far* title)
{
  delete[] Title;
  Title = strnewdup(title);
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TPrintout);

#if !defined(BI_NO_OBJ_STREAMING)

//
//
//
void*
TPrintout::Streamer::Read(ipstream& is, uint32) const
{
  GetObject()->Title = is.freadString();
  is >> GetObject()->Banding;
  is >> GetObject()->ForceAllBands;
  return GetObject();
}

//
//
//
void
TPrintout::Streamer::Write(opstream& os) const
{
  os.fwriteString(GetObject()->Title);
  os << GetObject()->Banding;
  os << GetObject()->ForceAllBands;
}

#endif  // if !defined(BI_NO_OBJ_STREAMING)

#endif
