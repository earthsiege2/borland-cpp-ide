//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   source\owl\menu.cpp
//   Implementation of Window Menu encapsulation class
//----------------------------------------------------------------------------
#include <owl\owlpch.h>
#include <owl\menu.h>

DIAG_DECLARE_GROUP(OwlWin);        // General window diagnostic group

TMenu::TMenu(TAutoDelete autoDelete)
  : Handle(::CreateMenu()), ShouldDelete(autoDelete)
{
}

TMenu::TMenu(HMENU handle, TAutoDelete autoDelete)
  : Handle(handle), ShouldDelete(autoDelete)
{
}

TMenu::TMenu(HWND hWnd, TAutoDelete autoDelete)
  : Handle(::GetMenu(hWnd)), ShouldDelete(autoDelete)
{
}

TMenu::TMenu(LPCVOID* menuTemplate) {
  Handle = ::LoadMenuIndirect(menuTemplate);
  WARNX(OwlWin, !Handle, 0, "Cannot Load Menu Indirect " << hex << menuTemplate);
  CheckValid();
  ShouldDelete = TRUE;
}

TMenu::TMenu(HINSTANCE resInstance, TResId resId)
{
  Handle = ::LoadMenu(resInstance, resId);
  WARNX(OwlWin, !Handle, 0, "Cannot Load Menu " << hex << (UINT)resInstance <<
                            " " << resId);
  CheckValid();
  ShouldDelete = TRUE;
}

TMenu::~TMenu()
{
  if (ShouldDelete)
    if (Handle)
      ::DestroyMenu(Handle);
}
//resId is never used in small model
#pragma warn -par
void
TMenu::CheckValid(UINT resId)
{

  if (!Handle)
    THROW( TXMenu(resId) );
}
#pragma warn .par //Restore

void
TMenu::MeasureItem(MEASUREITEMSTRUCT far&)
{
}

void
TMenu::DrawItem(DRAWITEMSTRUCT far&)
{
}

TSystemMenu::TSystemMenu(HWND wnd, BOOL revert)
  : TMenu(HMENU(0), NoAutoDelete)
{
  Handle = ::GetSystemMenu(wnd, revert);
}

TPopupMenu::TPopupMenu(TAutoDelete autoDelete)
  : TMenu(HMENU(0), autoDelete)
{
  Handle = ::CreatePopupMenu();
}

TPopupMenu::TPopupMenu(HMENU handle, TAutoDelete autoDelete)
  : TMenu(handle, autoDelete)
{
}

TMenu::TXMenu::TXMenu(unsigned resId) : TXOwl(resId)
{
}

TXOwl*
TMenu::TXMenu::Clone()
{
  return new TXMenu(*this);
}

void
TMenu::TXMenu::Throw()
{
  THROW( *this );
}
