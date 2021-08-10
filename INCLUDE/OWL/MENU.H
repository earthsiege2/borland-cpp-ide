//----------------------------------------------------------------------------
// ObjectWindows
// (C) Copyright 1991, 1994 by Borland International, All Rights Reserved
//
//   Definition of Window Menu encapsulation class
//----------------------------------------------------------------------------
#if !defined(OWL_MENU_H)
#define OWL_MENU_H

#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

//
//  class TMenuItem
//  ----- ---------
//  Representation of a menu item which can be a uint Id/position or a popup
//  menu handle.
//
#if 0  //!CQ A nice idea, but has a couple of snags yet
class TMenuItem {
  public:
    TMenuItem(uint id) {Item = id;}
    TMenuItem(HMENU popup) {Item = reinterpret_cast<uint>(popup);}
    operator uint() {return Item;}

  private:
    uint Item;
};
#else
typedef uint TMenuItem;
#endif

//
//  class TMenu
//  ----- -----
//
class _OWLCLASS TMenu {
  public:
    TMenu(TAutoDelete autoDelete = AutoDelete);
    TMenu(const TMenu& original, TAutoDelete autoDelete = AutoDelete);
    TMenu(HMENU handle, TAutoDelete autoDelete = NoAutoDelete);
    TMenu(HWND hWnd, TAutoDelete autoDelete = NoAutoDelete);
    TMenu(const void far* menuTemplate);
    TMenu(HINSTANCE instance, TResId resId);
    virtual ~TMenu();

    TMenu& operator =(const TMenu&);
    
    class _OWLCLASS_RTL TXMenu : public TXOwl {
      public:
        TXMenu(unsigned resId = IDS_GDIFAILURE);
        TXOwl* Clone();
        void Throw();
    };
    void        CheckValid(uint redId = IDS_MENUFAILURE);
    virtual HMENU GetHandle() const {return Handle;}

    operator    uint() const {return reinterpret_cast<uint>(GetHandle());}
    operator    HMENU() const {return GetHandle();}

    bool        IsOK() const {return GetHandle() != 0;}

    //
    // HMENU encapsulated functions
    //
    bool        AppendMenu(uint flags, TMenuItem newItem=-1, const char far* newStr=0);
    bool        AppendMenu(uint flags, TMenuItem newitem, const TBitmap& newBmp);
    bool        CheckMenuItem(TMenuItem item, uint check);
    bool        DeleteMenu(TMenuItem item, uint flags);
    bool        EnableMenuItem(TMenuItem item, uint enable);
    uint        GetMenuItemCount() const;
    uint        GetMenuItemID(int posItem) const;
    uint        GetMenuState(TMenuItem item, uint flags) const;
    uint        GetMenuString(TMenuItem item, char* str, int count, uint flags) const;
    HMENU       GetSubMenu(int posItem) const;
    bool        InsertMenu(TMenuItem item, uint flags, TMenuItem newItem=-1, const char far* newStr=0);
    bool        InsertMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp);
    bool        ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem=-1, const char far* newStr=0);
    bool        ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp);
    bool        RemoveMenu(TMenuItem item, uint flags);
    bool        SetMenuItemBitmaps(TMenuItem item, uint flags,
                                   const TBitmap* bmpUnchecked=0,
                                   const TBitmap* bmpChecked=0);

    static bool  GetMenuCheckMarkDimensions(TSize& size);
    static TSize GetMenuCheckMarkDimensions();

    //
    // virtual menu functions
    //
    virtual void  MeasureItem(MEASUREITEMSTRUCT far& measureItem);
    virtual void  DrawItem(DRAWITEMSTRUCT far& drawItem);

  protected:
    HMENU       Handle;
    bool        ShouldDelete;   // Should this object destroy Menu?

    static void DeepCopy(TMenu& dest, const TMenu& source, int offset = 0, int count = -1);
    static void DeepCopy(TMenu& dst, int dstOff, const TMenu& src, int srcOff = 0, int count = -1);

  private:
};

//
//  class TSystemMenu
//  ----- -----------
//
class _OWLCLASS TSystemMenu : public TMenu {
  public:
    TSystemMenu(HWND wnd, bool revert= false);

  private:
    TSystemMenu();
    TSystemMenu(const TSystemMenu&);
};

//
//  class TPopupMenu
//  ----- ----------
//
class _OWLCLASS TPopupMenu : public TMenu {
  public:
    TPopupMenu(TAutoDelete autoDelete = AutoDelete);
    TPopupMenu(HMENU handle, TAutoDelete autoDelete = NoAutoDelete);

    bool        TrackPopupMenu(uint flags, int x, int y, int rsvd, HWND wnd,
                               const TRect* rect=0);
    bool        TrackPopupMenu(uint flags, const TPoint& point, int rsvd,
                               HWND wnd, const TRect* rect=0);

  private:
    TPopupMenu(const TPopupMenu&);
};

//
//  class TMenuDescr
//  ----- ----------
//
//  Menu information used to allow merging of two menus
//
class _OWLCLASS TMenuDescr : public TMenu {
  public:
    enum TGroup {
      FileGroup,
      EditGroup,
      ContainerGroup,
      ObjectGroup,
      WindowGroup,
      HelpGroup,
      NumGroups
    };
    TMenuDescr();
    TMenuDescr(const TMenuDescr& original);
    TMenuDescr(TResId id, int fg, int eg, int cg, int og, int wg, int hg,
               TModule* module = ::Module);
    TMenuDescr(TResId id, TModule* module = ::Module);
    TMenuDescr(HMENU hMenu, int fg, int eg, int cg, int og, int wg, int hg,
               TModule* module = ::Module);
   ~TMenuDescr();

    TMenuDescr& operator =(const TMenuDescr& original);

    HMENU    GetHandle() const {return Handle;}
    TModule* GetModule() const {return Module;}
    void     SetModule(TModule* module) {Module = module;}
    TResId   GetId() const {return Id;}
    int      GetGroupCount(int group) const {return GroupCount[group];}
    void     ClearServerGroupCount();
    void     ClearContainerGroupCount();

    bool     Merge(const TMenuDescr& sourceMenuDescr);
    bool     Merge(const TMenuDescr& sourceMenuDescr, TMenu& destMenu);

  protected:
    TModule* Module;       // module where menu lives
    TResId   Id;           // resource id of menu
    int      GroupCount[NumGroups];

    bool     ExtractGroups();

  friend ipstream& operator >>(ipstream& is, TMenuDescr& m);
  friend opstream& operator <<(opstream& os, const TMenuDescr& m);
};


//----------------------------------------------------------------------------
// Inlines
//----------------------------------------------------------------------------

inline bool TMenu::AppendMenu(uint flags, TMenuItem newItem, const char far* newStr) {
  return ::AppendMenu(Handle, flags, newItem, newStr);
}

inline bool TMenu::AppendMenu(uint flags, TMenuItem newItem, const TBitmap& newBmp) {
  return ::AppendMenu(Handle, flags|MF_BITMAP, newItem,
         (const char far*)HBITMAP(newBmp));
}

inline bool TMenu::CheckMenuItem(TMenuItem item, uint check) {
  return ::CheckMenuItem(Handle, item, check);
}

inline bool TMenu::DeleteMenu(TMenuItem item, uint flags) {
  return ::DeleteMenu(Handle, item, flags);
}

inline bool TMenu::EnableMenuItem(TMenuItem item, uint enable) {
  return ::EnableMenuItem(Handle, item, enable);
}

inline uint TMenu::GetMenuItemCount() const {
  return ::GetMenuItemCount(Handle);
}

inline uint TMenu::GetMenuState(TMenuItem item, uint flags) const {
  return ::GetMenuState(Handle, item, flags);
}

inline uint TMenu::GetMenuString(TMenuItem item, char* str, int count, uint flags) const {
  return ::GetMenuString(Handle, item, str, count, flags);
}

inline HMENU TMenu::GetSubMenu(int posItem) const {
  return ::GetSubMenu(Handle, posItem);
}

inline bool TMenu::InsertMenu(TMenuItem item, uint flags, TMenuItem newItem, const char far* newStr) {
  return ::InsertMenu(Handle, item, flags|MF_STRING, newItem, newStr);
}

inline bool TMenu::InsertMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp) {
  return ::InsertMenu(Handle, item, flags|MF_BITMAP, newItem,
         (const char far*)HBITMAP(newBmp));
}

inline bool TMenu::ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem, const char far* newStr) {
  return ::ModifyMenu(Handle, item, flags|MF_STRING, newItem, newStr);
}

inline bool TMenu::ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp) {
  return ::ModifyMenu(Handle, item, flags|MF_BITMAP, newItem,
         (const char far*)HBITMAP(newBmp));
}

inline bool TMenu::RemoveMenu(TMenuItem item, uint flags) {
  return ::RemoveMenu(Handle, item, flags);
}

inline bool TMenu::SetMenuItemBitmaps(TMenuItem item, uint flags,
                                      const TBitmap* bmpUnchecked,
                                      const TBitmap* bmpChecked) {
  return ::SetMenuItemBitmaps(Handle, item, flags,
  bmpUnchecked ? HBITMAP(*bmpUnchecked) : 0,
  bmpChecked ? HBITMAP(*bmpChecked) : 0);
}

inline bool TMenu::GetMenuCheckMarkDimensions(TSize& size) {
  size = ::GetMenuCheckMarkDimensions();
  return true;
}

inline TSize TMenu::GetMenuCheckMarkDimensions() {
  return ::GetMenuCheckMarkDimensions();
}

inline bool TPopupMenu::TrackPopupMenu(uint flags, int x, int y, int rsvd,
                                       HWND wnd, const TRect* rect) {
  return ::TrackPopupMenu(Handle, flags, x, y, rsvd, wnd, rect);
}

inline bool TPopupMenu::TrackPopupMenu(uint flags, const TPoint& point,
                                       int rsvd, HWND wnd, const TRect* rect) {
  return ::TrackPopupMenu(Handle, flags, point.x, point.y, rsvd, wnd, rect);
}

#endif  // OWL_MENU_H
