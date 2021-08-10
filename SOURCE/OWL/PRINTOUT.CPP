//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1992, 1993 by Borland International
//   source\owl\printout.cpp
//----------------------------------------------------------------------------
#pragma hdrignore SECTION
#include <owl\owlpch.h>
#include <owl\printer.h>

#if !defined(SECTION) || SECTION == 1

TPrintout::TPrintout(const char far* title)
{
  Title = strnewdup(title);
  Banding = FALSE;
  ForceAllBands = TRUE;
}

TPrintout::~TPrintout()
{
  delete Title;
}

void
TPrintout::SetPrintParams(TPrintDC* dc, TSize pageSize)
{
  DC = dc;
  PageSize = pageSize;
}

void
TPrintout::GetDialogInfo(int& minPage, int& maxPage,
                         int& selFromPage, int& selToPage)
{
  minPage = 1;
  maxPage = INT_MAX;
  selFromPage = selToPage = 0;
}

void
TPrintout::BeginPrinting()
{
}

void
TPrintout::BeginDocument(int, int, unsigned)
{
}

BOOL
TPrintout::HasPage(int page)
{
  return page == 1;
}

void
TPrintout::PrintPage(int, TRect&, unsigned)
{
}

void
TPrintout::EndDocument()
{
}

void
TPrintout::EndPrinting()
{
}

#endif
#if !defined(SECTION) || SECTION == 2

IMPLEMENT_STREAMABLE(TPrintout);

void*
TPrintout::Streamer::Read(ipstream& is, uint32) const
{
  GetObject()->Title = is.freadString();
  is >> GetObject()->Banding;
  is >> GetObject()->ForceAllBands;
  return GetObject();
}

void
TPrintout::Streamer::Write(opstream& os) const
{
  os.fwriteString(GetObject()->Title);
  os << GetObject()->Banding;
  os << GetObject()->ForceAllBands;
}

#endif

