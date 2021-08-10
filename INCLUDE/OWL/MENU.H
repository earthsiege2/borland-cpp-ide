//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1991, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.10  $
//
// Definition of Window Menu encapsulation class
//----------------------------------------------------------------------------
#if !defined(OWL_MENU_H)
#define OWL_MENU_H

#if !defined(OWL_GDIOBJEC_H)
# include <owl/gdiobjec.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS_RTL TXMenu;
class _OWLCLASS     TMenu;

#if 0  
//
// class TMenuItem
// ~~~~~ ~~~~~~~~~
// Representation of a menu item which can be a uint Id/position or a popup
// menu handle.
//
class TMenuItem {
  public:
    TMenuItem(uint id) {Item = id;}
    TMenuItem(HMENU popup) {Item = reinterpret_cast<uint>(popup);}
    operator uint() {return Item;}

  private:
    uint Item;
};
#else
// Alias of an unsigned integer which identifies a menu item.
//
typedef uint TMenuItem;
#endif

#if defined(BI_PLAT_WIN32)

// All-including mask for MENUITEMINFO
//
#if !defined(MIIM_ALL)
# define MIIM_ALL  (MIIM_CHECKMARKS|MIIM_DATA|MIIM_ID|MIIM_STATE|MIIM_SUBMENU|MIIM_TYPE)
#endif

//
// class TMenuItemInfo
// ~~~~~ ~~~~~~~~~~~~~
class _OWLCLASS TMenuItemInfo : public MENUITEMINFO {
  public:
    TMenuItemInfo(uint msk = 0);

    // Construct MENUITEMINFO from a specific item of a menu object.
    // Defaults to retrieving all information except for the type, which
    // require a destination buffer.
    //
    TMenuItemInfo(TMenu& menu, uint posOrId, bool isPos, 
                  uint msk = MIIM_CHECKMARKS|MIIM_DATA|
                             MIIM_ID|MIIM_STATE|MIIM_SUBMENU);

    // Construct MENUITEMINFO from a specific item of a menu object.
    // Similar to prior except that it also retrieves the type data.
    //
    TMenuItemInfo(TMenu& menu, uint posOrId, bool isPos, void* buffer, 
                  uint size, uint msk = MIIM_ALL);
};

#endif  

//
// class TMenu
// ~~~~~ ~~~~~
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

    void        CheckValid(uint redId = IDS_MENUFAILURE);
    virtual HMENU GetHandle() const;

    operator    uint() const;
    operator    HMENU() const;

    bool        IsOK() const;

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
    int         GetMenuString(TMenuItem item, char* str, int count, uint flags) const;
    HMENU       GetSubMenu(int posItem) const;
    bool        InsertMenu(TMenuItem item, uint flags, TMenuItem newItem=-1, const char far* newStr=0);
    bool        InsertMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp);
    bool        ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem=-1, const char far* newStr=0);
    bool        ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp);
    bool        RemoveMenu(TMenuItem item, uint flags);
    bool        SetMenuItemBitmaps(TMenuItem item, uint flags,
                                   const TBitmap* bmpUnchecked=0,
                                   const TBitmap* bmpChecked=0);

    // Encapsulation of new functionality introduced with Win95
    // (Emulated when running on earlier versions of Windows)
    //
    uint        GetDefaultItem(bool getPos, uint flags) const;
    bool        SetDefaultItem(uint posOrId, bool isPos);
    bool        CheckRadioItem(uint first, uint last, uint check, uint flags);

#if defined(BI_PLAT_WIN32)

    // MENUITEMINFO related API
    //
    bool        GetMenuItemInfo(uint posOrId, bool isPos, TMenuItemInfo& mi) const;
    bool        SetMenuItemInfo(uint posOrId, bool isPos, TMenuItemInfo& mi);
    bool        InsertMenuItem(uint posOrId, bool isPos, TMenuItemInfo& mi);
#endif

    static bool  GetMenuCheckMarkDimensions(TSize& size);
    static TSize GetMenuCheckMarkDimensions();

    // Virtual menu functions
    //
    virtual void  MeasureItem(MEASUREITEMSTRUCT far& measureItem);
    virtual void  DrawItem(DRAWITEMSTRUCT far& drawItem);

#if defined(OWL2_COMPAT)
    typedef ::TXMenu TXMenu;  // Exceptions moved to global scope
#endif

  protected:
    static void DeepCopy(TMenu& dest, const TMenu& source, int offset = 0, int count = -1);
    static void DeepCopy(TMenu& dst, int dstOff, const TMenu& src, int srcOff = 0, int count = -1);

  protected_data:
    HMENU       Handle;
    bool        ShouldDelete;   // Should this object destroy Menu?
};

//
// class TXMenu
// ~~~~~ ~~~~~~
class _OWLCLASS_RTL TXMenu : public TXOwl {
  public:
    TXMenu(uint resId = IDS_MENUFAILURE);

#if defined(BI_NO_COVAR_RET)
    TXBase* Clone();
#else
    TXMenu* Clone();
#endif
    void Throw();

    static void Raise(uint resId = IDS_MENUFAILURE);
};

//
// class TSystemMenu
// ~~~~~ ~~~~~~~~~~~
class _OWLCLASS TSystemMenu : public TMenu {
  public:
    TSystemMenu(HWND wnd, bool revert= false);

  private:
    TSystemMenu();
    TSystemMenu(const TSystemMenu&);
};

//
// class TPopupMenu
// ~~~~~ ~~~~~~~~~~
class _OWLCLASS TPopupMenu : public TMenu {
  public:
    TPopupMenu(TAutoDelete autoDelete = AutoDelete);
    TPopupMenu(HMENU handle, TAutoDelete autoDelete = NoAutoDelete);
    TPopupMenu(const TMenu& menu, TAutoDelete autoDelete = AutoDelete);
    bool        TrackPopupMenu(uint flags, int x, int y, int rsvd, HWND wnd,
                               const TRect* rect=0);
    bool        TrackPopupMenu(uint flags, const TPoint& point, int rsvd,
                               HWND wnd, const TRect* rect=0);

  private:
    TPopupMenu(const TPopupMenu&);
};

//
// class TMenuDescr
// ~~~~~ ~~~~~~~~~~
// Menu with information used to allow merging
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

    HMENU    GetHandle() const;
    TModule* GetModule() const;
    void     SetModule(TModule* module);
    TResId   GetId() const;
    int      GetGroupCount(int group) const;
    void     ClearServerGroupCount();
    void     ClearContainerGroupCount();

    bool     Merge(const TMenuDescr& sourceMenuDescr);
    bool     Merge(const TMenuDescr& sourceMenuDescr, TMenu& destMenu);

  protected:
    bool     ExtractGroups();

  protected_data:
    TModule* Module;       // module where menu lives
    TResId   Id;           // resource id of menu
    int      GroupCount[NumGroups];

  friend ipstream& operator >>(ipstream& is, TMenuDescr& m);
  friend opstream& operator <<(opstream& os, const TMenuDescr& m);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline implementations
//

//
inline HMENU TMenuDescr::GetHandle() const
{
  return Handle;
}

//
inline TModule* TMenuDescr::GetModule() const
{
  return Module;
}

//
inline void TMenuDescr::SetModule(TModule* module)
{
  Module = module;
}

//
inline TResId TMenuDescr::GetId() const
{
  return Id;
}

//
inline int TMenuDescr::GetGroupCount(int group) const
{
  return GroupCount[group];
}

//
inline HMENU TMenu::GetHandle() const
{
  return Handle;
}

//
inline TMenu::operator uint() const
{
  return uint(GetHandle());
}

//
inline TMenu::operator HMENU() const
{
  return GetHandle();
}

//
inline bool TMenu::IsOK() const
{
  return GetHandle() != 0;
}

//
inline bool TMenu::AppendMenu(uint flags, TMenuItem newItem, const char far* newStr)
{
  PRECONDITION(Handle);
  return ::AppendMenu(Handle, flags, newItem, newStr);
}

//
inline bool TMenu::AppendMenu(uint flags, TMenuItem newItem, const TBitmap& newBmp)
{
  PRECONDITION(Handle);
  return ::AppendMenu(Handle, flags|MF_BITMAP, newItem,
         (const char far*)HBITMAP(newBmp));
}

//
inline bool TMenu::CheckMenuItem(TMenuItem item, uint check)
{
  PRECONDITION(Handle);
  return ::CheckMenuItem(Handle, item, check);
}

//
inline bool TMenu::DeleteMenu(TMenuItem item, uint flags)
{
  PRECONDITION(Handle);
  return ::DeleteMenu(Handle, item, flags);
}

//
inline bool TMenu::EnableMenuItem(TMenuItem item, uint enable)
{
  PRECONDITION(Handle);
  return ::EnableMenuItem(Handle, item, enable);
}

//
inline uint TMenu::GetMenuItemCount() const
{
  PRECONDITION(Handle);
  return ::GetMenuItemCount(Handle);
}

//
inline uint TMenu::GetMenuState(TMenuItem item, uint flags) const
{
  PRECONDITION(Handle);
  return ::GetMenuState(Handle, item, flags);
}

//
inline int TMenu::GetMenuString(TMenuItem item, char* str, int count, uint flags) const
{
  PRECONDITION(Handle);
  return ::GetMenuString(Handle, item, str, count, flags);
}

//
inline HMENU TMenu::GetSubMenu(int posItem) const
{
  PRECONDITION(Handle);
  return ::GetSubMenu(Handle, posItem);
}

//
inline bool TMenu::InsertMenu(TMenuItem item, uint flags, TMenuItem newItem, const char far* newStr)
{
  PRECONDITION(Handle);
  return ::InsertMenu(Handle, item, flags|MF_STRING, newItem, newStr);
}

//
inline bool TMenu::InsertMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp)
{
  return ::InsertMenu(Handle, item, flags|MF_BITMAP, newItem,
         (const char far*)HBITMAP(newBmp));
}

//
inline bool TMenu::ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem, const char far* newStr)
{
  PRECONDITION(Handle);
  return ::ModifyMenu(Handle, item, flags|MF_STRING, newItem, newStr);
}

//
inline bool TMenu::ModifyMenu(TMenuItem item, uint flags, TMenuItem newItem, const TBitmap& newBmp)
{
  PRECONDITION(Handle);
  return ::ModifyMenu(Handle, item, flags|MF_BITMAP, newItem,
         (const char far*)HBITMAP(newBmp));
}

//
inline bool TMenu::RemoveMenu(TMenuItem item, uint flags)
{
  PRECONDITION(Handle);
  return ::RemoveMenu(Handle, item, flags);
}

//
inline bool TMenu::SetMenuItemBitmaps(TMenuItem item, uint flags,
                                      const TBitmap* bmpUnchecked,
                                      const TBitmap* bmpChecked)
{
  PRECONDITION(Handle);
  return ::SetMenuItemBitmaps(Handle, item, flags,
                              bmpUnchecked ? HBITMAP(*bmpUnchecked) : 0,
                              bmpChecked ? HBITMAP(*bmpChecked) : 0);
}

//
// Returns true always.
// The size reference will store the dimensions of the check mark bitmaps.
//
inline bool TMenu::GetMenuCheckMarkDimensions(TSize& size)
{
  size = ::GetMenuCheckMarkDimensions();
  return true;
}

//
// Return the dimensions of the check mark bitmaps.
//
inline TSize TMenu::GetMenuCheckMarkDimensions()
{
  return ::GetMenuCheckMarkDimensions();
}

//
inline bool TPopupMenu::TrackPopupMenu(uint flags, int x, int y, int rsvd,
                                       HWND wnd, const TRect* rect)
{
  PRECONDITION(Handle);
  return ::TrackPopupMenu(Handle, flags, x, y, rsvd, wnd, rect);
}

//
inline bool TPopupMenu::TrackPopupMenu(uint flags, const TPoint& point,
                                       int rsvd, HWND wnd, const TRect* rect)
{
  PRECONDITION(Handle);
  return ::TrackPopupMenu(Handle, flags, point.x, point.y, rsvd, wnd, rect);
}

#endif  // OWL_MENU_H
