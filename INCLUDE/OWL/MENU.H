//----------------------------------------------------------------------------
// ObjectWindows - (C) Copyright 1991, 1993 by Borland International
//   include\owl\menu.h
//   Definition of Window Menu encapsulation class
//----------------------------------------------------------------------------
#if !defined(__OWL_MENU_H)
#define __OWL_MENU_H

#if !defined(__OWL_GDIOBJEC_H)
  #include <owl\gdiobjec.h>
#endif

class _OWLCLASS TMenu {
  public:
    TMenu(TAutoDelete autoDelete = AutoDelete);
    TMenu(HMENU handle, TAutoDelete autoDelete = NoAutoDelete);
    TMenu(HWND hWnd, TAutoDelete autoDelete = NoAutoDelete);
    TMenu(LPCVOID* menuTemplate);
    TMenu(HINSTANCE instance, TResId resId);
    virtual ~TMenu();

    class _OWLCLASS_RTL TXMenu : public TXOwl {
      public:
        TXMenu(unsigned resId = IDS_GDIFAILURE);
        TXOwl* Clone();
        void Throw();
    };
    void        CheckValid(UINT redId = IDS_MENUFAILURE);

    operator    UINT() {return (UINT)Handle;}
    operator    HMENU() {return Handle;}

    BOOL        IsOK() const {return Handle != 0;}

    //
    // HMENU encapsulated functions
    //
    BOOL        AppendMenu(UINT flags, UINT idNewItem=-1, const char far* newItem=0);
    BOOL        AppendMenu(UINT flags, UINT idNewItem, const TBitmap& newBmp);
    BOOL        CheckMenuItem(UINT idItem, UINT check);
    BOOL        DeleteMenu(UINT idItem, UINT flags);
    BOOL        EnableMenuItem(UINT idItem, UINT enable);
    UINT        GetMenuItemCount() const;
    UINT        GetMenuItemID(int posItem) const;
    UINT        GetMenuState(UINT idItem, UINT flags) const;
    UINT        GetMenuString(UINT idItem, char* str, int count, UINT flags) const;
    HMENU       GetSubMenu(int posItem) const;
    BOOL        InsertMenu(UINT idItem, UINT flags, UINT idNewItem=-1, const char far* newItem=0);
    BOOL        InsertMenu(UINT idItem, UINT flags, UINT idNewItem, const TBitmap& newBmp);
    BOOL        ModifyMenu(UINT idItem, UINT flags, UINT idNewItem=-1, const char far* newItem=0);
    BOOL        ModifyMenu(UINT idItem, UINT flags, UINT idNewItem, const TBitmap& newBmp);
    BOOL        RemoveMenu(UINT idItem, UINT flags);
    BOOL        SetMenuItemBitmaps(UINT idItem, UINT flags,
                                   const TBitmap* bmpUnchecked=0,
                                   const TBitmap* bmpChecked=0);
    static BOOL GetMenuCheckMarkDimensions(TSize& size);

    //
    // virtual menu functions
    //
    virtual void  MeasureItem(MEASUREITEMSTRUCT far& measureItem);
    virtual void  DrawItem(DRAWITEMSTRUCT far& drawItem);

  protected:
    HMENU       Handle;
    BOOL        ShouldDelete;   // Did C++ object create Menu?

  private:
    //
    // hidden to prevent accidental copying or assignment
    //
    TMenu(const TMenu&);
    TMenu& operator =(const TMenu&);
};

class _OWLCLASS TSystemMenu : public TMenu {
  public:
    TSystemMenu(HWND wnd, BOOL revert= FALSE);

  private:
    TSystemMenu();
    TSystemMenu(const TSystemMenu&);
};

class _OWLCLASS TPopupMenu : public TMenu {
  public:
    TPopupMenu(TAutoDelete autoDelete = AutoDelete);
    TPopupMenu(HMENU handle, TAutoDelete autoDelete = NoAutoDelete);

    BOOL        TrackPopupMenu(UINT flags, int x, int y, int rsvd, HWND wnd, TRect* rect=0);
    BOOL        TrackPopupMenu(UINT flags, TPoint& point, int rsvd, HWND wnd, TRect* rect=0);

  private:
    TPopupMenu(const TPopupMenu&);
};


//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline BOOL TMenu::AppendMenu(UINT flags, UINT idNewItem, const char far* newItem) {
  return ::AppendMenu(Handle, flags, idNewItem, newItem);
}

inline BOOL TMenu::AppendMenu(UINT flags, UINT idNewItem, const TBitmap& newBmp) {
  return ::AppendMenu(Handle, flags|MF_BITMAP, idNewItem,
         (const char far*)HBITMAP(newBmp));
}

inline BOOL TMenu::CheckMenuItem(UINT idItem, UINT check) {
  return ::CheckMenuItem(Handle, idItem, check);
}

inline BOOL TMenu::DeleteMenu(UINT idItem, UINT flags) {
  return ::DeleteMenu(Handle, idItem, flags);
}

inline BOOL TMenu::EnableMenuItem(UINT idItem, UINT enable) {
  return ::EnableMenuItem(Handle, idItem, enable);
}

inline UINT TMenu::GetMenuItemCount() const {
  return ::GetMenuItemCount(Handle);
}

inline UINT TMenu::GetMenuItemID(int PosItem) const {
  return ::GetMenuItemID(Handle, PosItem);
}

inline UINT TMenu::GetMenuState(UINT idItem, UINT flags) const {
  return ::GetMenuState(Handle, idItem, flags);
}

inline UINT TMenu::GetMenuString(UINT idItem, char* str, int count, UINT flags) const {
  return ::GetMenuString(Handle, idItem, str, count, flags);
}

inline HMENU TMenu::GetSubMenu(int posItem) const {
  return ::GetSubMenu(Handle, posItem);
}

inline BOOL TMenu::InsertMenu(UINT idItem, UINT flags, UINT idNewItem, const char far* newItem) {
  return ::InsertMenu(Handle, idItem, flags|MF_STRING, idNewItem, newItem);
}

inline BOOL TMenu::InsertMenu(UINT idItem, UINT flags, UINT idNewItem, const TBitmap& newBmp) {
  return ::InsertMenu(Handle, idItem, flags|MF_BITMAP, idNewItem,
         (const char far*)HBITMAP(newBmp));
}

inline BOOL TMenu::ModifyMenu(UINT idItem, UINT flags, UINT idNewItem, const char far* newItem) {
  return ::ModifyMenu(Handle, idItem, flags|MF_STRING, idNewItem, newItem);
}

inline BOOL TMenu::ModifyMenu(UINT idItem, UINT flags, UINT idNewItem, const TBitmap& newBmp) {
  return ::ModifyMenu(Handle, idItem, flags|MF_BITMAP, idNewItem,
         (const char far*)HBITMAP(newBmp));
}

inline BOOL TMenu::RemoveMenu(UINT idItem, UINT flags) {
  return ::RemoveMenu(Handle, idItem, flags);
}

inline BOOL TMenu::SetMenuItemBitmaps(UINT idItem, UINT flags,
                                      const TBitmap* bmpUnchecked,
                                      const TBitmap* bmpChecked) {
  return ::SetMenuItemBitmaps(Handle, idItem, flags,
  bmpUnchecked ? HBITMAP(*bmpUnchecked) : 0,
  bmpChecked ? HBITMAP(*bmpChecked) : 0);
}

inline BOOL TMenu::GetMenuCheckMarkDimensions(TSize& size) {
  size = ::GetMenuCheckMarkDimensions();
  return TRUE;
}

inline BOOL TPopupMenu::TrackPopupMenu(UINT flags, int x, int y, int rsvd, HWND wnd, TRect* rect) {
  return ::TrackPopupMenu(Handle, flags, x, y, rsvd, wnd, rect);
}

inline BOOL TPopupMenu::TrackPopupMenu(UINT flags, TPoint& point, int rsvd, HWND wnd, TRect* rect) {
  return ::TrackPopupMenu(Handle, flags, point.x, point.y, rsvd, wnd, rect);
}

#endif  // __OWL_MENU_H
