//----------------------------------------------------------------------------
// ObjectWindows
// Copyright (c) 1995, 1997 by Borland International, All Rights Reserved
//
//$Revision:   10.17  $
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

#if defined(BI_NAMESPACE)
namespace OWL {
#endif

// Generic definitions/compiler options (eg. alignment) preceeding the
// definition of classes
#include <services/preclass.h>

class _OWLCLASS TTreeItem;
class _OWLCLASS TTreeNode;
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
    void   SetText(const char far*, int len = 0);
    void   GetText(char far*, int len = 0) const;

    // Manipulate the extra data
    //
    void   SetItemData(uint32 data);
    uint32 GetItemData(void) const;

    TTreeItem operator =(const TTreeItem&);

  private:
    void Init();

    char far* Text;
    int       Length;
    uint32    ItemData;

  friend class TTreeLink;
  friend class TTreeWindow;
  friend class TTreeNode;
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

#pragma warn -cln               // constant is long
    enum THowToInsert {
      First = TVI_FIRST,
      Last  = TVI_LAST,
      Sort  = TVI_SORT
    };
#pragma warn .cln

    // Constructors and destructor
    //
    TTreeNode(void) : TreeView(0) {}
    TTreeNode(TTreeWindow& tree, char far* text);
    TTreeNode(TTreeWindow& tree);
    TTreeNode(const TTreeNode&);
    TTreeNode(const TTreeNode&, uint32);
    TTreeNode(TTreeLink&);

    // The next two constructors are for creating new nodes.  Both create only
    // the C++ TTreeNode object.  Call SetItem to make the new node appear in
    // the treeview control.
    //
    TTreeNode(TTreeWindow& tw, const char far* text);
    TTreeNode(TTreeWindow& tw, const char far* text, int index, int selIndex);

    // The next two constructors create a node object to represent a node
    // that already exists.

    // Use this constructor in event handlers. The event message carries
    // a TTwNotify structure.
    //
    TTreeNode(TTreeWindow& tw, TV_ITEM item);

    // This constructor is useful for enumerating nodes on a tree.
    // Passing just the first parameter creates the node object for
    // the tree's root, a good starting point.
    //
#pragma warn -cln               // constant is long
    TTreeNode(TTreeWindow& tw, HTREEITEM hItem = TVI_ROOT);
#pragma warn .cln

    // Tell the node which TTreeWindow it belongs to. Used with the default
    // constructor.
    //
    void AttachToTree(TTreeWindow* tw);

   ~TTreeNode();

    // Navigation
    //
    TTreeNode GetParent() const;
    TTreeNode GetChild() const;
    TTreeNode GetNextSibling() const;
    TTreeNode GetPrevSibling() const;
    TTreeNode GetNextItem(uint32 flag) const;

    // Adding and deleting items from the tree
    //
    TTreeNode AddChild(const TTreeNode& node) const;
    TTreeNode AddSibling(const TTreeNode& node) const;
    TTreeNode InsertChild(const TTreeNode& node, uint32 how) const;
    TTreeNode InsertItem(const TTreeNode& node) const;
    bool      Delete();

    // These older add/delete methods use TTreeItem.  They have
    // been replaced by the versions that operate on the node
    // itself.  They are retained for backward compatibility.
    //
    TTreeNode AddChild(const TTreeItem&) const;         // add item at end
    TTreeNode AddSibling(const TTreeItem&) const;
    TTreeNode InsertChild(const TTreeItem&, uint32) const;
    TTreeNode InsertItem(const TTreeItem&) const;

    // Operations on the node
    //
    bool      ExpandItem(uint32 flag);

    // Set/GetText store the text in the node's internal buffer so the
    // caller doesn't have to worry about string length and buffer
    // ownership.
    //
    bool       SetText(const char far* text, bool sendNow = true);
    bool       GetText(char far*& text, bool getNew = false);
    char far*  GetText(bool getNew = false);

    // These operations send messages to the control.  The message delivery
    // might fail, so they return bool.
    //
    bool       SetItemData(uint32 data, bool sendNow = true);
    bool       GetItemData(uint32& data, bool getNew = true);

    // The Set/Get accessors for individual node attributes send a message
    // to send data to or receive data from the treeview control.  You can
    // minimize the number of messages sent by using the sendNow or getNew
    // parameters to prevent the message from being sent.  Then follow up
    // with a single call to SetItem or GetItem.  This packages all pending
    // business in a single message call.
    //
    //    SetText("MyText", false);     // these two send no message
    //    SetItemData(1, false);
    //    SetItem();                    // one msg is sent with both attributes
    //
    bool       GetItem(void);
    bool       SetItem(void);

    bool       GetItem(TTreeItem* item);    // preserved for compatibility


    TTreeNode operator=(const TTreeNode&);

    operator bool() const;

    TTreeLink* Link;

    // Codes for TTreeNode (TExpandCode, TNextCode)
    //
    // Retained for compatiblity, but no longer recommended.
    // Use the TVE_ and TVGN_ constants directly instead of
    // these enums.

    enum TExpandCode {
      Collapse      = TVE_COLLAPSE,
      Expand        = TVE_EXPAND,
      Toggle        = TVE_TOGGLE,
      CollapseReset = TVE_COLLAPSERESET // ignored in 16-bit
    };

    enum TNextCode {
      Root     = TVGN_ROOT,
      Next     = TVGN_NEXT,
      Previous = TVGN_PREVIOUS,
      Parent   = TVGN_PARENT,
      Child    = TVGN_CHILD,
      Caret    = TVGN_CARET,

      FirstVisible    = TVGN_FIRSTVISIBLE, // these 4 are ignore in 16-bit
      NextVisible     = TVGN_NEXTVISIBLE,
      PreviousVisible = TVGN_PREVIOUSVISIBLE,
      DropHilite      = TVGN_DROPHILITE
    };

  protected:
    TTreeItem ItemStruct;             // contains a TV_ITEM with HTREEITEM
    TTreeWindow* TreeView;            // wrapper for item of this tree

  private:
    TAPointer<char> CacheText;        // buffer for node text
    static uint NodeTextCacheSize;    // size of text caching buffer

    // Used by copy constructor and assignment operator
    //
    TTreeNode& TTreeNode::CopyNode(const TTreeNode& ti);
};

//
// class TTreeWindow
// ~~~~~ ~~~~~~~~~~~
// Simulates the common control.
//
// Inheritance from TListBox is merely an implementation convenience.
// TTreeWindow is not meant to use the TListBox interface.
//
class _OWLCLASS TTreeWindow : public TListBox {
  public:

    // Constructors and destructor
    //
    TTreeWindow(TWindow* parent, int id, int x, int y, int w, int h,
                uint32 style = 0, TModule* module = 0);
    TTreeWindow(TWindow* parent, int resourceId, TModule* module = 0);
   ~TTreeWindow();

    // Set the styles
    //
    void SetStyle(uint32 style);
    bool HasStyle(uint32 style);

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

    // enum retained for compatiblity, but no longer recommended.
    // Use the TVS_* style constants directly instead of this enum.
    //
    enum TStyle {
      twsNone       = 0x0000,
      twsHasLines   = TVS_HASLINES,
      twsHasButtons = TVS_LINESATROOT,

      twsEditLabels      = TVS_EDITLABELS,      // ignored in 16-bit
      twsDisableDragDrop = TVS_DISABLEDRAGDROP, // ignored in 16-bit
      twsShowSelAlways   = TVS_SHOWSELALWAYS    // ignored in 16-bit
    };

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
    uint32 Style;

  private:
    void Init();

    TTreeLink* RootLink;
    uint       IndentUnits;

    // Hidden to prevent accidental copying or assignment
    //
    TTreeWindow(const TTreeWindow&);
    TTreeWindow& operator=(const TTreeWindow&);

    // Used when painting
    //
    static const int ButtonHeight;
    static const int ButtonWidth;

  friend class TTreeNode;

  DECLARE_RESPONSE_TABLE(TTreeWindow);
};

// Generic definitions/compiler options (eg. alignment) following the
// definition of classes
#include <services/posclass.h>

#if defined(BI_NAMESPACE)
} // namespace OWL
#endif

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
TTreeItem::GetItemData() const
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
  return ParentLink == 0;
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
  return FirstChild != 0 && LastChild != 0;
}


//----------------------------------------------------------------------------
// TTreeNode
//

//
inline TTreeNode
TTreeNode::GetParent() const
{
  return GetNextItem(Parent);
}

//
inline TTreeNode
TTreeNode::GetChild() const
{
  return GetNextItem(Child);
}

//
inline TTreeNode
TTreeNode::GetNextSibling() const
{
  return GetNextItem(Next);
}

//
inline TTreeNode
TTreeNode::GetPrevSibling() const
{
  return GetNextItem(Previous);
}

//
inline TTreeNode
TTreeNode::AddChild(const TTreeItem& item) const
{
  return TTreeNode(*Link->AddLastChild(item));
}

//
inline TTreeNode
TTreeNode::AddChild(const TTreeNode& node) const
{
  return TTreeNode(*Link->AddLastChild(node.ItemStruct));
}

//
inline TTreeNode
TTreeNode::AddSibling(const TTreeNode& node) const
{
  return TTreeNode(*Link->AddAtTail(node.ItemStruct));
}

inline TTreeNode
TTreeNode::InsertChild(const TTreeNode& node, uint32 how) const
{
  return InsertChild(node.ItemStruct, how);
}

inline TTreeNode
TTreeNode::InsertItem(const TTreeNode& node) const
{
  return TTreeNode(*(Link->AddAfter(node.ItemStruct)));
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

