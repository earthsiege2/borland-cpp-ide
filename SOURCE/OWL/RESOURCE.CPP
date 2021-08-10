//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.2  $
//
// Implementation classes handling Windows resources
//----------------------------------------------------------------------------
#include <owl/pch.h>
#if !defined(OWL_RESOURCE_H) 
# include <owl/resource.h>
#endif
#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif
#if !defined(OWL_GADGETWI_H)
# include <owl/gadgetwi.h>
#endif
#if !defined(OWL_BUTTONGA_H)
# include <owl/buttonga.h>
#endif
#if !defined(OWL_CELARRAY_H)
# include <owl/celarray.h>
#endif

//
//
//
TDialogRes::TDialogRes(HINSTANCE hInst, TResId id) 
           : OldResource(0)
#if defined(BI_PLAT_WIN32)
           , NewResource(0)
#endif
{
#if defined(BI_PLAT_WIN32)
  // In 32-bit, favour the new dialog resource over the old one
  //
  NewResource = new TResource<DLGTEMPLATEEX, RT_NEWDIALOG>(hInst, id);
  if (!NewResource->IsOK()) 
#endif
    // In 16-bit (or when the new resource cannot be found in 32-bit), try
    // the old DLGTEMPLATE resource
    //
    OldResource = new TResource<DLGTEMPLATE, RT_DIALOG>(hInst, id);
}

//
//
//
#if defined(BI_PLAT_WIN32)
TDialogRes::TDialogRes(HINSTANCE hInst, TResId id, LANGID langid)
           :OldResource(0)
#if defined(BI_PLAT_WIN32)
          , NewResource(0)
#endif
{
  NewResource = new TResource<DLGTEMPLATEEX, RT_NEWDIALOG>(hInst, id, langid);
  if (!NewResource->IsOK())
    OldResource = new TResource<DLGTEMPLATE, RT_DIALOG>(hInst, id, langid);
}
#endif

//
//
//
TDialogRes::~TDialogRes()
{
  delete OldResource;
#if defined(BI_PLAT_WIN32)
  delete NewResource;
#endif
}


//
//
//
bool
TDialogRes::IsOK() const
{
#if   defined(BI_PLAT_WIN16)
  return OldResource && OldResource->IsOK();
#elif defined(BI_PLAT_WIN32)
  return (NewResource && NewResource->IsOK()) || 
         (OldResource && OldResource->IsOK());
#endif
}


//
//
//
#if defined(BI_PLAT_WIN32)
bool      
TDialogRes::IsDialogEx() const 
{
  PRECONDITION(IsOK());
  return (!OldResource || !OldResource->IsOK()) && 
         ( NewResource &&  NewResource->IsOK());
}

DLGTEMPLATEEX*
TDialogRes::GetTemplateEx() const
{
  PRECONDITION(IsDialogEx());
  return NewResource->operator DLGTEMPLATEEX*();
}
#endif

DLGTEMPLATE*
TDialogRes::GetTemplate() const
{
#if defined(BI_PLAT_WIN32)
  PRECONDITION(!IsDialogEx());
#endif
  return  OldResource->operator DLGTEMPLATE*();
}

void      
TDialogRes::GetRect(TRect& rect) const
{
#if defined(BI_PLAT_WIN32)
  if (!IsDialogEx()) {
#endif
    DLGTEMPLATE* dlgTemplate = GetTemplate();
    rect.left  = dlgTemplate->x;
    rect.right = dlgTemplate->x + dlgTemplate->cx;
    rect.top   = dlgTemplate->y;
    rect.bottom= dlgTemplate->y + dlgTemplate->cy;
#if defined(BI_PLAT_WIN32)
  } else {
    DLGTEMPLATEEX* dlgTemplate = GetTemplateEx();
    rect.left  = dlgTemplate->x;
    rect.right = dlgTemplate->x + dlgTemplate->cx;
    rect.top   = dlgTemplate->y;
    rect.bottom= dlgTemplate->y + dlgTemplate->cy;
  }
#endif 
}

int
TDialogRes::GetText(char far* buffer, int size, TDlgResText which) const
{
#if   defined(BI_PLAT_WIN16)
  DLGTEMPLATE* dlgTemplate = GetTemplate();
  char far* p = (char far*)(dlgTemplate+1);
  char far* pMenu  = p;
  char far* pClass = pMenu + lstrlen(pMenu) + 1;
  char far* pCaption = pClass + lstrlen(pMenu) + 1;

  switch (which) {
    case drtMenuName:   p = pMenu;    break;
    case drtClassName:  p = pClass;   break;
    case drtCaption:    p = pCaption; break;
    default:
      return 0;
  };
  return ((p = lstrcpyn(buffer, p, size))) ? lstrlen(p) : 0;

#elif defined(BI_PLAT_WIN32)
  
  LPCWSTR p, pMenu, pClass, pCaption;

  if (!IsDialogEx()) {
    DLGTEMPLATE* dlgTemplate = GetTemplate();
    p = (LPCWSTR)(dlgTemplate+1);
    pMenu = p;
    pClass = pMenu + ((*pMenu == 0xffff) ? 2 : lstrlenW(pMenu)+1);
    pCaption = pClass + ((*pClass == 0xffff) ? 2 : lstrlenW(pClass)+1);
  } else {
    DLGTEMPLATEEX* dlgTemplateEx = GetTemplateEx();
  }

  switch (which) {
    case drtMenuName:   p = pMenu;    break;
    case drtClassName:  p = pClass;   break;
    case drtCaption:    p = pCaption; break;
    default:
      return 0;
  };

  return WideCharToMultiByte(CP_ACP, 0, p, (*p == 0xfff) ? 2 : lstrlenW(p), 
                             buffer, size, 0, 0);
#endif 
}

#if defined(BI_PLAT_WIN32)
//
//
//
TToolbarRes::TToolbarRes(HINSTANCE hInst, TResId id, TAutoDelete autoDelete)
            :TResource<TOOLBARTEMPLATE, RT_TOOLBAR>(hInst, id), ToolbarBitmap(0)
{
  ShouldDelete  = (autoDelete == AutoDelete);

  // Following will throw exception in case of failure
  //
  ToolbarBitmap = new TBitmap(hInst, id);
}

//
//
//
TToolbarRes::~TToolbarRes()
{
  if (ShouldDelete)
    delete ToolbarBitmap;
}

//
//
//
TOOLBARTEMPLATE&
TToolbarRes::TBInfo() const {
  PRECONDITION(IsOK());
  return *(CONST_CAST(TToolbarRes*, this)->operator TOOLBARTEMPLATE*());
}

//
//
//
TBitmap&
TToolbarRes::GetBitmap() {
  PRECONDITION(IsOK());
  PRECONDITION(ToolbarBitmap && ToolbarBitmap->GetHandle());
  return *ToolbarBitmap;
}

//
//
//
int
TToolbarRes::GetCount() const {
  PRECONDITION(IsOK());
  return TBInfo().count;    
}

//
//
//
ushort*
TToolbarRes::GetIds() const {
  PRECONDITION(IsOK());
  return TBInfo().ids;
}

//
//
//
int
TToolbarRes::GetWidth() const {
  PRECONDITION(IsOK());
  return TBInfo().width;
}

//
//
//
int
TToolbarRes::GetHeight() const {
  PRECONDITION(IsOK());
  return TBInfo().height;
}


//
//
TToolbarBldr::TToolbarBldr(TGadgetWindow& win, TResId id, HINSTANCE hinst)
             :Win(win), TbarRes(0), Id(id), Hinst(hinst)
{ 
}

//
//
//
TToolbarBldr::~TToolbarBldr()
{
  delete TbarRes;
}

//
// Populate the gadgetwindow with button gadgets and separators using a
// bitmap and toolbar resource pair. Returns true if the resource was
// successfully loaded and the gadgets created and false otherwise.
//
void
TToolbarBldr::Build()
{
  // Default to window's module if none was specified
  //
  if (!Hinst)
    Hinst = *(Win.GetModule());

  // NOTE: Don't let the TToolbarRes instance own the bitmap, we'll hand
  //       it to the celarray instead.
  //
  TbarRes = new TToolbarRes(Hinst, Id, NoAutoDelete);

  CHECK(TbarRes->IsOK());
  TCelArray* celArray = new TCelArray(&TbarRes->GetBitmap(), 
                                      TbarRes->GetCount(),
                                      TSize(TbarRes->GetWidth(), 
                                            TbarRes->GetHeight()));
  // Hand celarray to gadgetwindow
  // NOTE: Nice enhancement would be to add/merge toolbar resources using
  //       TCelArray's Add(TCelArray& src, index) method if the window
  //       already has a celarray. Unfortunately, the tbar resource does 
  //       provide a method to specify insertion indices to make this
  //       approach usable. So we'll wipe out the previous celarray.
  //
  Win.SetCelArray(celArray);

  // Create gadgets based on resource information
  //
  for (int i=0, j=0; i<TbarRes->GetCount(); i++) {
    if (TbarRes->GetIds()[i] == 0)
      Win.Insert(*new TSeparatorGadget(6));
    else {
      Win.Insert(*new TButtonGadget(j++, TbarRes->GetIds()[i], 
                                    TButtonGadget::Command, false, 
                                    TButtonGadget::Up, true));
    }
  }
}
#endif  //  BI_PLAT_WIN32
