//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.6  $
//
// Definition of class TCheckList, an ownerdrawn listbox to select multiple
// items
//----------------------------------------------------------------------------
#if !defined(OWL_CHECKLST_H)
#define OWL_CHECKLST_H

#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h>
#endif
#if !defined(OWL_CHECKBOX_H)
# include <owl/checkbox.h>
#endif

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

//
// class TCheckListItem
// ~~~~~ ~~~~~~~~~~~~~~
// Each item displayed and manipulated by TCheckList.
//
class _OWLCLASS TCheckListItem {
  public:
    TCheckListItem();
    TCheckListItem(const char far* text, uint state = BF_UNCHECKED);
   ~TCheckListItem();

    // State management
    //
    bool IsChecked() const;
    bool IsIndeterminate() const;
    void Toggle();
    void Check();
    void Uncheck();
    void SetIndeterminate();
    void SetThreeStates(bool);

    // Text management
    //
    void SetText(const char far* text);
    void GetText(char far* buffer, int len);

  private:
    char far* Text;
    uint      State;
    bool      HasThreeStates;

  friend class _OWLCLASS TCheckList;
};


//
// class TCheckList
// ~~~~~ ~~~~~~~~~~
// An owner drawn listbox to select multiple items.
//
class _OWLCLASS TCheckList : public TListBox {
  public:
    // The constructors expect to be passed an array of TCheckListItems.
    // The memory is owned by the callee.
    //
    TCheckList(TWindow* parent, int id, int x, int y, int w, int h,
               TCheckListItem* items, int numItems,
               TModule* module = 0);
    TCheckList(TWindow* parent, int resourceId,
               TCheckListItem* items, int numItems,
               TModule* module = 0);
   ~TCheckList();

  protected:
    void SetupWindow();

    // Owner draw messages
    //
    void ODAFocus(DRAWITEMSTRUCT far& drawInfo);
    void ODASelect(DRAWITEMSTRUCT far& drawInfo);
    void ODADrawEntire(DRAWITEMSTRUCT far& drawInfo);
    void PaintItem(DRAWITEMSTRUCT far& drawInfo);

    // Event handlers
    //
    void EvLButtonDown(uint modKeys, TPoint& point);
    void EvChar(uint key, uint repeatCount, uint flags);
    void Update();

    TCheckListItem* GetItemAtIndex(int index);

  private:
    TCheckListItem* Items;
    int             NumberOfItems;

  DECLARE_RESPONSE_TABLE(TCheckList);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

//----------------------------------------------------------------------------
// Inline Implementations
//

//
// Returns true if the item has been checked.
//
inline bool
TCheckListItem::IsChecked() const
{
  return ToBool(State == BF_CHECKED);
}

//
// Returns true if the item is in the indeterminate state.
//
inline bool
TCheckListItem::IsIndeterminate() const
{
  return ToBool(State == BF_GRAYED);
}

#endif  // OWL_CHECKLIST_H
