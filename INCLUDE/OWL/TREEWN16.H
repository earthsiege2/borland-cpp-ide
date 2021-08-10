//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1996 by Borland International, All Rights Reserved
//
//$Revision:   10.5  $
//
// Definition TTreeWindow class for Win16
//----------------------------------------------------------------------------
#if !defined(OWL_TREEWN16_H)
#define OWL_TREEWN16_H

#if defined(BI_PLAT_WIN32)
# error Use #include <owl/treewind.h> for Win32 instead.
#endif
#if !defined(OWL_LISTBOX_H)
# include <owl/listbox.h>
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the 
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TTreeItem;
class _OWLCLASS TTreeNode;  // Navigational class
class _OWLCLASS TTreeLink;
class _OWLCLASS TTreeWindow;

//
// class TTreeItem
// ~~~~~ ~~~~~~~~~
// Contains the information about the item.
//
class _OWLCLASS TTreeItem {
  public:
    // Constructor
    //
    TTreeItem();
    TTreeItem(const TTreeItem&);
    TTreeItem(char far*, int len = 0);
   ~TTreeItem();

    // Manipulate the text properties
    //
    void   SetText(char far*, int len = 0);
    void   GetText(char far*, int len = 0);

    // Manipulate the extra data
    //
    void   SetItemData(uint32);
    uint32 GetItemData();

    TTreeItem operator =(const TTreeItem&);

  private:
    void Init();

    char far* Text;
    int       Length;
    uint32    ItemData;

  friend class TTreeLink;
  friend class TTreeWindow;
};


//
// class TTreeLink
// ~~~~~ ~~~~~~~~~
// This is a private class.
//
// This class contains the pointers its relatives.
// It is used to maintain the information normally kept by the
// common control.
//
class _OWLCLASS TTreeLink {
  private:
    TTreeLink(TTreeWindow& window);
   ~TTreeLink();

    TTreeLink* AddAtHead(const TTreeItem& itemToAdd);
    TTreeLink* AddAtTail(const TTreeItem& itemToAdd);
    TTreeLink* AddAfter(const TTreeItem& itemToAdd);
    TTreeLink* AddFirstChild(const TTreeItem& itemToAdd);
    TTreeLink* AddLastChild(const TTreeItem& itemToAdd);
    bool Delete();

    void GetSize(TSize& size, TFont* font);

    // Query status
    //
    bool IsRoot();
    bool IsParent();
    bool IsLastChild();
    bool IsFirstChild();
    bool IsOpened();
    void ToggleOpened();

    // Indent level
    //
    int  GetIndentLevel();
    void SetIndentLevel(int indentLevel);

  private:
    bool Opened;
    int  IndentLevel;

    TTreeItem*   TreeItem;
    TTreeWindow& Window;

    // Links
    //
    TTreeLink* ParentLink;
    TTreeLink* FirstChild;
    TTreeLink* LastChild;
    TTreeLink* NextSibling;
    TTreeLink* PrevSibling;

  friend class TTreeNode;
  friend class TTreeWindow;
};


//
// class TTreeNode
// ~~~~~ ~~~~~~~~~
// Use this class to navigate the TTreeWindow.
// Each node conceptually contains a pointer to a TTreeItem.
//
class _OWLCLASS TTreeNode {
  public:
    enum TExpandCode {
      Collapse,
      Expand,
      Toggle,
    };

    enum TNextCode {
      Root,
      Next,
      Previous,
      Parent,
      Child,
      Caret,
    };

    enum THowToInsert {
      First,
      Last,
      Sort,
    };

    // Constructors and destructor
    //
    TTreeNode(TTreeWindow&);                // Initializer
    TTreeNode(const TTreeNode&);            // Copy
    TTreeNode(const TTreeNode&, TNextCode); // Navigational
    TTreeNode(TTreeLink&);
   ~TTreeNode();

    // Navigation
    //
    TTreeNode GetParent();
    TTreeNode GetChild();
    TTreeNode GetNextSibling();
    TTreeNode GetPrevSibling();
    TTreeNode GetNextItem(TNextCode flag);

    // Adding and deleting items from the tree
    //
    TTreeNode AddChild(TTreeItem&);         // add item at end
    TTreeNode AddSibling(TTreeItem&);
    TTreeNode InsertChild(TTreeItem&, THowToInsert);
    TTreeNode InsertItem(TTreeItem&);
    bool      Delete();

    // Operations on the node
    //
    bool      ExpandItem(TExpandCode flag);
    bool      GetItem(TTreeItem* item);

    TTreeNode operator=(const TTreeNode&);

    TTreeLink* Link;

  private:
};


//
// class TTreeWindow
// ~~~~~ ~~~~~~~~~~~
// Simulates the common control.
//
class _OWLCLASS TTreeWindow : public TListBox {
  public:
    enum TStyle {
      twsNone       = 0x0000,
      twsHasLines   = 0x0001,
      twsHasButtons = 0x0002,
    };

    // Constructors and destructor
    //
    TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                TStyle style = twsNone, TModule* module = 0);
    TTreeWindow(TWindow* parent, int resourceId, TModule* module = 0);
   ~TTreeWindow();

    // Set the styles
    //
    void SetStyle(TStyle style);
    bool HasStyle(TStyle style);

    // Return special nodes
    //
    TTreeNode GetRoot();
    TTreeNode GetSelection();

    // Indent level
    //
    uint GetIndent();
    void SetIndent(uint);

    TFont* GetFont();

    void Update();

  protected:
    TTreeLink* GetLinkAtIndex(int index);
    int        AddLinks(TTreeLink* parent, int indentLevel, int insertAfterIndex);
    void       OpenLink(TTreeLink* link, int index);
    void       CloseLink(TTreeLink* link, int index);

    // owner draw methods
    //
    void MeasureItem(MEASUREITEMSTRUCT far& measureItemInfo);
    void ODAFocus(DRAWITEMSTRUCT far& drawInfo);
    void ODASelect(DRAWITEMSTRUCT far& drawInfo);
    void ODADrawEntire(DRAWITEMSTRUCT far& drawInfo);
    void PaintLink(DRAWITEMSTRUCT far& drawInfo);

    void  EvChar(uint key, uint repeatCount, uint flags);
    void  EvLDblClk();
    void  EvSetFont(HFONT hFont, bool redraw);
    HFONT EvGetFont();

    TFont* Font;
    TStyle Style;

  private:
    void Init();

    TTreeLink* RootLink;
    uint       IndentUnits;

    // Hidden to prevent accidental copying or assignment
    //
    TTreeWindow(const TTreeWindow&);
    TTreeWindow& operator=(const TTreeWindow&);

  friend class TTreeNode;

  DECLARE_RESPONSE_TABLE(TTreeWindow);
};

// Generic definitions/compiler options (eg. alignment) following the 
// definition of classes
#include <services/posclass.h>

//----------------------------------------------------------------------------
// TTreeItem
//

//
inline void
TTreeItem::SetItemData(uint32 data)
{
  ItemData = data;
}

//
inline uint32
TTreeItem::GetItemData()
{
  return ItemData;
}


//----------------------------------------------------------------------------
// TTreeLink
//

//
inline bool
TTreeLink::IsRoot()
{
  return ToBool(ParentLink == 0);
}

//
inline bool
TTreeLink::IsOpened()
{
  return Opened;
}

//
inline int
TTreeLink::GetIndentLevel()
{
  return IndentLevel;
}

//
inline void
TTreeLink::SetIndentLevel(int indentLevel)
{
  IndentLevel = indentLevel;
}

//
inline bool
TTreeLink::IsParent()
{
  return ToBool(FirstChild != 0 && LastChild != 0);
}


//----------------------------------------------------------------------------
// TTreeNode
//

//
inline TTreeNode
TTreeNode::GetParent()
{
  return GetNextItem(Parent);
}

//
inline TTreeNode
TTreeNode::GetChild()
{
  return GetNextItem(Child);
}

//
inline TTreeNode
TTreeNode::GetNextSibling()
{
  return GetNextItem(Next);
}

//
inline TTreeNode
TTreeNode::GetPrevSibling()
{
  return GetNextItem(Previous);
}


//----------------------------------------------------------------------------
// TTreeWindow
//

//
inline TTreeNode
TTreeWindow::GetRoot()
{
  return TTreeNode(*RootLink);
}

//
inline uint
TTreeWindow::GetIndent()
{
  return IndentUnits;
}

//
inline TFont*
TTreeWindow::GetFont()
{
  return Font;
}

#endif  // OWL_TREEWN16_H

